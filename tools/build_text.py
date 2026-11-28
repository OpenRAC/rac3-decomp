#!/usr/bin/env python3
"""Build frontbin's .text from the per-file sources in src/frontbin/.

The sources are one C file per original source file, listed in link order in
config/frontbin/src_files.txt (see tools/srcfiles.py). Compiler and assembler flags come
from config/frontbin/text_parts.txt, by function address.

  * A file whose functions all use the same flags is compiled as it is, once.
  * A file that mixes flags (some functions only match with a different
    assembler or address mode) is compiled in slices, one per run of equal
    flags. Each slice is the file's own prelude (includes and its
    declarations from other files) plus the declarations of the file's
    earlier functions, then the slice's functions, with #line directives so
    errors point at the real file. Nothing from other files is replayed.

Every object goes through tools/asm_filter.py between gcc -S and the
assembler (retail's short-loop and div.s padding). An object with protected
DNAS blocks (level 39's Sony library, include/dnas.h) then goes through
tools/dnas.py, which writes the version's random words into the blocks'
stubs and encrypts them, as Sony's tool did to its objects. Each source file ends up
as <workdir>/<file>.o (objdiff compares these, one unit per file; slice
objects are kept apart in <workdir>/slices/), and all of them are linked into
one relocatable object (ld -r) for the linker script.

Unchanged work is reused (since 2026-11-28, tools/objcache.py): each compile's assembly, each
asm_filter.py pass, each assembled object and each slice join is kept in build/objcache/ under a
key of everything that can change it (the C or assembly it reads with every header and `.include`
it can reach, the exact command, the filter's tables, the toolchain's bytes, the tools of this
build), so a run after a one-file change compiles only that file. --no-cache (or UYA_NO_CACHE=1)
builds everything again; the output is the same either way.

Usage (from the repo root, normally via the Makefile):
  python tools/build_text.py --cc CC --ld LD --cflags "..." -o build/src/text.c.o [--base]
"""
import argparse
import os
import re
import shlex
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_filter  # noqa: E402
import dnas  # noqa: E402
import ee29  # noqa: E402
import ee296  # noqa: E402
import eeas  # noqa: E402
import objcache  # noqa: E402
import srcfiles as sf  # noqa: E402
import targets  # noqa: E402
from srcfiles import strip_comments, declarations_only, EXTERN_HINT_RE  # noqa: E402,F401

FUNC_RE = re.compile(r'func_([0-9A-Fa-f]{8})')
_EXTERN_HINT_RE = EXTERN_HINT_RE


def read_parts(path):
    parts = []
    with open(path) as fh:
        for line in fh:
            line = line.split('#', 1)[0].strip()
            if not line:
                continue
            fields = line.split()
            parts.append((int(fields[0], 16), fields[1:]))
    parts.sort()
    if not parts:
        sys.exit(f"{path}: no parts defined")
    return parts


def expand_flags(flags, cc):
    """Expand text_parts.txt pseudo-flags that depend on the toolchain path.

    @ps2as  assemble with SN's own assembler (ee/bin/Ps2EeAs.exe) instead of
            the default bin/ee-as.exe. gcc looks for "<prefix>as.exe"; Windows
            file names are case-insensitive, so the prefix ".../ee/bin/Ps2Ee"
            finds Ps2EeAs.exe. gcc uses the last -B, so these are placed after
            the Makefile's CFLAGS.
    @newas  use ee/bin/as.exe (May 2001), the one gcc picks without any -B.
    @ee29   compile with Sony's ee-gcc 2.9-ee-991111 instead of SN's compiler
            (tools/ee29.py); it is dropped here, compile_one() handles it.
    @ee296  the same with Sony's ee-gcc 2.96-ee-001003-1 (tools/ee296.py).
    @eeas   assemble with Sony's ee-as 2.10-ee-001003-1 instead of the driver's
            assembler (tools/eeas.py); it is dropped here, compile_one() handles it."""
    root = os.path.dirname(os.path.dirname(os.path.abspath(cc)))
    out = []
    for f in flags:
        if f in (ee29.FLAG, ee296.FLAG, eeas.FLAG):
            continue
        if f == '@ps2as':
            out.append('-B' + os.path.join(root, 'ee', 'bin', 'Ps2Ee'))
            out.append('-DNO_MACRO_INC')  # Ps2EeAs can't read include/macro.inc
        elif f == '@newas':
            out.append('-B' + os.path.join(root, 'ee', 'bin') + os.sep)
        else:
            out.append(f)
    return out


def part_index(parts, addr):
    idx = 0
    for i, (start, _) in enumerate(parts):
        if addr >= start:
            idx = i
    return idx


def flags_for(parts, addr):
    return parts[part_index(parts, addr)][1]


_TYPEDEF_NAME_RE = re.compile(r'\btypedef\b[^;{]*?(?:\{(?:[^{}]|\{[^{}]*\})*\})?[^;{]*?\b(\w+)\s*(?:\[[^\]]*\])?(?:\s*__attribute__\s*\(\((?:[^()]|\((?:[^()]|\([^()]*\))*\))*\)\))?\s*;', re.S)


def typedef_names(src):
    """Names of the typedefs a piece of C defines."""
    return set(_TYPEDEF_NAME_RE.findall(strip_comments(src)))


def drop_repeated_typedefs(context, src):
    """`src` without the typedefs that `context` already defines identically
    (C forbids defining one twice). A typedef with the same name but a
    different body is left in: that is a real conflict."""
    norm = lambda t: re.sub(r'\s+', ' ', strip_comments(t)).strip()
    have = {m.group(1): norm(m.group(0)) for m in _TYPEDEF_NAME_RE.finditer(strip_comments(context))}
    return _TYPEDEF_NAME_RE.sub(
        lambda m: '' if have.get(m.group(1)) == norm(m.group(0)) else m.group(0), src)


ASM_ONLY_DROP = ("@ps2as",)


def asm_addrs(chunks):
    """Addresses whose block is assembly (INCLUDE_ASM, ASM_FUNC, LINKER_REMNANT), not C."""
    c = {a for a, _, b in chunks if "localdecomp:start" in b}
    return {a for a, _, b in chunks
            if re.match(r"\s*(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(", b)} - c


def file_slices(chunks, parts):
    """[(flags, [chunk indices])]: runs of consecutive chunks with equal flags.

    Flags are per file (one line per file in text_parts.txt). The one exception is not a
    compiler flag: a block that is assembly already (INCLUDE_ASM, ASM_FUNC, LINKER_REMNANT)
    has nothing to compile, and SN's Ps2EeAs cannot read the GNU assembler macros its .s
    uses, so in an @ps2as file such blocks are assembled as their own slice with GNU as
    (@ps2as dropped). The bytes are the .s file's either way."""
    asm = asm_addrs(chunks)
    out = []
    for i, (addr, _, _) in enumerate(chunks):
        fl = flags_for(parts, addr)
        if addr in asm and any(f in fl for f in ASM_ONLY_DROP):
            fl = [f for f in fl if f not in ASM_ONLY_DROP]
        if out and out[-1][0] == fl:
            out[-1][1].append(i)
        else:
            out.append((fl, [i]))
    return out


def prelude_lines(prelude):
    return prelude.count('\n')


def slice_source(rel, prelude, chunks, idxs, decls=None):
    """C text for one slice of a mixed-flag file. DECLS: declarations_only() of each chunk, when
    the caller has them already (a file's slices all need those of the chunks before them)."""
    path = rel.replace('\\', '/')
    out = ['#line 1 "%s"\n' % path, prelude]
    first = idxs[0]
    for n, (addr, line, body) in enumerate(chunks[:first]):
        decl = declarations_only(body) if decls is None else decls[n]
        if decl:
            out.append('#line %d "%s"\n%s\n' % (line, path, decl))
    for i in idxs:
        addr, line, body = chunks[i]
        out.append('#line %d "%s"\n%s' % (line, path, body))
    return ''.join(out)


def function_context(text_unused, parts, name, drop_typedefs=(), own_src=None):
    """What the build compiles in front of function `name`, minus code: the
    file's prelude (includes, declarations from other files), the
    declarations of the file's earlier functions, and the top-level `.extern`
    size hints of earlier functions compiled in the same slice (they change
    which globals Ps2EeAs reaches through $gp). localdecomp and
    tools/try_func.py compile a function after this, so a single-function
    build sees what the real build sees.

    Typedefs named in `drop_typedefs` are removed (the function's own block
    defines them; C forbids repeating a typedef). The first argument is
    ignored (it used to be the text of src/text.c).

    With `own_src` (the code about to be tested), declarations from earlier
    files that it needs and its file doesn't have yet are added after the
    prelude, as `tools/split_text.py --refresh` will add them on save."""
    files = sf.read_file_list()
    found = sf.find_function(name, files)
    if not found:
        return ''
    rel, text, _, _ = found
    prelude, _, chunks = sf.split_file(text)
    target = None
    for n, (addr, line, body) in enumerate(chunks):
        if sf.is_own_chunk(body, name):
            target = n
            break
    if target is None:
        return ''
    own = flags_for(parts, chunks[target][0])
    same = True
    out = [strip_comments(prelude)]
    if own_src:
        import split_text
        out.extend(split_text.extra_declarations(rel, own_src, files))
    # walk back to see which earlier chunks share this function's slice
    in_slice = [False] * target
    for n in range(target - 1, -1, -1):
        if flags_for(parts, chunks[n][0]) != own:
            break
        in_slice[n] = True
    for n, (addr, line, body) in enumerate(chunks[:target]):
        decl = declarations_only(body)
        if decl:
            out.append(decl)
        if in_slice[n]:
            out.extend(m.group(0).strip() for m in EXTERN_HINT_RE.finditer(strip_comments(body)))
    ctx = '\n'.join(out) + '\n'
    drop = set(drop_typedefs)
    if drop:
        ctx = _TYPEDEF_NAME_RE.sub(lambda m: '' if m.group(1) in drop else m.group(0), ctx)
    return ctx


def compile_errors(rel, text, parts, gcc_cmd, cflags, tmpdir):
    """Compile every slice of one source file to assembly, the way main()
    does, without assembling or keeping the output, and return the compiler's
    error lines ([] if it compiles). `text` is the file's content (it may
    differ from the file on disk), `gcc_cmd` the compiler command as a list
    (runner + gcc). Used by pr_check.py and try_in_context.py to catch
    conflicting declarations before a full build does."""
    import tempfile
    prelude, _, chunks = sf.split_file(text)
    slices = file_slices(chunks, parts)
    root = os.path.dirname(os.path.dirname(os.path.abspath(gcc_cmd[-1])))
    errors = []
    for k, (fl, idxs) in enumerate(slices):
        src = text if len(slices) == 1 else slice_source(rel, prelude, chunks, idxs)
        if len(slices) == 1:
            src = '#line 1 "%s"\n' % rel.replace('\\', '/') + src
        fd, cpath = tempfile.mkstemp(suffix='.c', dir=tmpdir)
        with os.fdopen(fd, 'w', newline='\n') as f:
            f.write(src)
        spath = cpath[:-2] + '.s'
        pflags = [f for f in expand_flags(fl, os.path.join(root, 'bin', 'x')) if not f.startswith('-B')]
        pc = [f for f in cflags if not f.startswith('-Wa,')]
        if ee29.wanted(fl):
            # Sony's 2.9-ee compiler for this range; gcc_cmd[0] is the runner (wibo) if there is one
            runner = gcc_cmd[0] if len(gcc_cmd) > 1 else None
            r = ee29.to_asm(fl, pc, cpath, spath, runner=runner, capture=True)
        elif ee296.wanted(fl):
            r = ee296.to_asm(fl, pc, cpath, spath, capture=True)
        else:
            r = subprocess.run(gcc_cmd + ['-S'] + pflags + pc + ['-o', spath, cpath],
                               capture_output=True, text=True)
        for p in (cpath, spath):
            try:
                os.remove(p)
            except OSError:
                pass
        if r.returncode:
            lines = [l for l in (r.stdout + r.stderr).splitlines()
                     if l.strip() and 'never used' not in l and 'warning' not in l]
            where = rel if len(slices) == 1 else '%s (slice %d)' % (rel, k)
            errors.append((where, lines or ['compiler failed with no message']))
    return errors


SCRIPT = os.path.abspath(__file__)
# the reuse of unchanged work (tools/objcache.py); main() sets it (off: --no-cache)
CACHE = objcache.Cache(enabled=False)
# the toolchain folder the --cc / --ld wrappers run (--toolchain; default: the folder above --cc's)
TOOLCHAIN = None


def _sn_tools(key, cc, options):
    """SN's toolchain into KEY: the --cc and --ld programs (or wrappers) and the folders they run
    from, every -B folder, the runner."""
    key.tree('cc', cc)
    if LD:
        key.tree('ld', LD)
    key.tree('toolchain', TOOLCHAIN or os.path.dirname(os.path.dirname(os.path.abspath(cc))))
    for o in options:
        if o.startswith('-B'):
            key.tree('-B', os.path.dirname(o[2:]) or '.')
    if RUNNER:
        key.tree('runner', objcache.which(RUNNER))


def _system_dirs():
    """The compilers' own folders, for the header scan (tools/includes.py)."""
    return [TOOLCHAIN or os.path.dirname(os.path.dirname(os.path.abspath(CC))) if CC else None,
            ee29.root(EE29), ee296.root(EE296)]


def compile_key(cc, flags, pcflags, pflags, asflags, cpath, spath):
    """The key of compiling CPATH to the assembly SPATH (tools/objcache.py, step 1), or None."""
    if not CACHE.enabled or not objcache.standard_includes(list(flags) + list(pcflags)):
        return None
    key = objcache.Key('compile').common([SCRIPT])
    if ee29.wanted(flags):
        key.text('compiler', ('ee29', ee29.root(EE29), RUNNER))
        key.tree('ee29', ee29.root(EE29))
        if RUNNER or os.name != 'nt':
            key.tree('runner', objcache.which(RUNNER or os.environ.get('UYA_RUNNER') or 'wibo'))
        key.text('command', (list(flags), list(pcflags), cpath, spath))
    elif ee296.wanted(flags):
        key.text('compiler', ('ee296', ee296.root(EE296)))
        key.tree('ee296', ee296.root(EE296))
        key.text('command', (list(flags), list(pcflags), cpath, spath))
    else:
        cmd = [cc, '-S'] + pflags + pcflags + asflags + ['-o', spath, cpath]
        key.text('compiler', 'sn')
        _sn_tools(key, cc, cmd)
        key.text('command', cmd)
    key.file('source', cpath)
    with open(cpath, 'rb') as f:
        text = f.read().decode('latin-1')
    objcache.add_headers(key, text, os.path.dirname(os.path.abspath(cpath)), _system_dirs())
    return key


def assemble_key(cc, flags, pcflags, pflags, asflags, spath, opath):
    """The key of assembling SPATH (as tools/asm_filter.py left it) into OPATH (step 3), or None."""
    if not CACHE.enabled or not objcache.standard_includes(list(pcflags)):
        return None
    key = objcache.Key('assemble').common([SCRIPT])
    if eeas.wanted(flags):
        try:
            program = eeas.program(EEAS)
        except FileNotFoundError:
            return None              # _assemble() says what is missing
        key.text('assembler', ('eeas', EEAS))
        key.tree('eeas', program)
        key.text('command', (list(flags), list(pcflags), spath, opath))
    else:
        cmd = [cc, '-c'] + pflags + pcflags + asflags + ['-o', opath, spath]
        key.text('assembler', 'sn')
        _sn_tools(key, cc, cmd)
        key.text('command', cmd)
    with open(spath, 'rb') as f:
        data = f.read()
    key.text('assembly', data)
    if not objcache.add_asm_includes(key, data, os.path.dirname(os.path.abspath(spath))):
        return None
    return key


def link_key(ld, opath, sobjs):
    """The key of joining a file's slice objects SOBJS into OPATH with ld -r, or None."""
    if not CACHE.enabled:
        return None
    key = objcache.Key('link').common([SCRIPT])
    _sn_tools(key, CC or ld, [])
    key.tree('ld', ld)
    key.text('command', [ld, '-r', '-o', opath] + list(sobjs))
    for p in sobjs:
        key.file('object', p)
    return key


class NeedsBuild(Exception):
    """A step of a file has nothing to reuse (raised in main()'s first pass, which only reuses)."""


def _reused(key, dest, reuse_only):
    """True when KEY's kept output was put at DEST. With REUSE_ONLY, NeedsBuild instead of
    False (main()'s first pass leaves the file to the -j workers)."""
    if key is not None and (not reuse_only or CACHE.has(key.hexdigest())) and CACHE.fetch(key.hexdigest(), dest):
        return True
    if reuse_only:
        raise NeedsBuild()
    return False


def _keep(key, path):
    """Keep PATH as KEY's output, unless an input changed while the step ran."""
    if key is not None and not key.changed():
        CACHE.store(key.hexdigest(), path)


def compile_one(cc, flags, cflags, cpath, spath, opath, label, reuse_only=False):
    """Compile CPATH to the object OPATH (through the assembly SPATH), each step reused when its
    inputs are those of an earlier run (tools/objcache.py). REUSE_ONLY: NeedsBuild when a
    compiler or assembler would have to run."""
    try:
        eeas.check_flags(flags)
    except ValueError as e:
        raise SystemExit(f'build_text: {label}: {e}')
    pflags = expand_flags(flags, cc)
    asflags = [f for f in pflags if f.startswith('-B')]
    pflags = [f for f in pflags if not f.startswith('-B')]
    pcflags = cflags
    if '@ps2as' in flags:
        # Ps2EeAs rejects the GNU as options (-mips3, -mcpu=5900, ...)
        pcflags = [f for f in cflags if not f.startswith('-Wa,')]
    key = compile_key(cc, flags, pcflags, pflags, asflags, cpath, spath)
    if not _reused(key, spath, reuse_only):
        _compile(cc, flags, pflags, pcflags, asflags, cpath, spath, label)
        _keep(key, spath)
    stext = _filter(flags, spath)
    key = assemble_key(cc, flags, pcflags, pflags, asflags, spath, opath)
    if not _reused(key, opath, reuse_only):
        _assemble(cc, flags, pflags, pcflags, asflags, spath, opath, label)
        _keep(key, opath)
    _protect(stext, opath, label)


def _compile(cc, flags, pflags, pcflags, asflags, cpath, spath, label):
    """C to assembly: SN's ee-gcc -S, or Sony's 2.9-ee / 2.96-ee."""
    if ee29.wanted(flags):
        # compile with Sony's 2.9-ee driver, assemble below as usual
        if ee29.to_asm(flags, pcflags, cpath, spath, path=EE29, runner=RUNNER).returncode != 0:
            raise SystemExit(f'build_text: {label} failed to compile (2.9-ee)')
    elif ee296.wanted(flags):
        # Sony's 2.96-ee cpp0 and cc1 (tools/ee296.py), assembled below as usual
        if ee296.to_asm(flags, pcflags, cpath, spath, path=EE296).returncode != 0:
            raise SystemExit(f'build_text: {label} failed to compile (2.96-ee)')
    else:
        cmd = [cc, '-S'] + pflags + pcflags + asflags + ['-o', spath, cpath]
        print(' '.join(cmd), flush=True)
        if subprocess.run(cmd).returncode != 0:
            raise SystemExit(f'build_text: {label} failed to compile')


def filter_key(flags, spath):
    """The key of tools/asm_filter.py's pass over the compiler's assembly SPATH (step 2): its
    bytes, the kind of range, the tables the filter reads (the program's or level's and
    config/levels/ divs_nops.txt and sq_ra_funcs.txt) and the tools; None when off."""
    if not CACHE.enabled:
        return None
    key = objcache.Key('filter').common([SCRIPT])
    key.text('ps2as', '@ps2as' in flags)
    for path in (asm_filter._divs_file(), asm_filter.LEVEL_DIVS, asm_filter._sq_ra_file(), asm_filter.LEVEL_SQ_RA):
        key.file('table', path)
    with open(spath, 'rb') as f:
        key.text('assembly', f.read())
    return key


def _filter(flags, spath):
    """tools/asm_filter.py over the compiler's assembly, in place; returns the assembly as the
    compiler wrote it."""
    with open(spath, newline='') as f:
        stext = f.read()
    # retail's short-loop padding is SN's assembler's; Sony's 2.9-ee and
    # 2.96-ee library objects (@ee29, @ee296) and Sony's assembler (@eeas)
    # don't have it (tools/ee29.py, tools/eeas.py)
    library = ee29.wanted(flags) or ee296.wanted(flags) or eeas.wanted(flags)
    key = None if library else filter_key(flags, spath)
    if key is not None and CACHE.fetch(key.hexdigest(), spath):
        return stext
    with open(spath, 'w', newline='') as f:
        f.write(stext if library else asm_filter.filter_asm(stext, '@ps2as' in flags))
    _keep(key, spath)
    return stext


def _assemble(cc, flags, pflags, pcflags, asflags, spath, opath, label):
    """Assembly to an object: the driver's -c, or Sony's ee-as."""
    if eeas.wanted(flags):
        # Sony's ee-as 2.10-ee instead of the driver's -c step (tools/eeas.py)
        try:
            ok = eeas.assemble(flags, pcflags, spath, opath, path=EEAS).returncode == 0
        except FileNotFoundError as e:
            raise SystemExit(f'build_text: {label}: {e}')
        if not ok:
            raise SystemExit(f'build_text: {label} failed to assemble (ee-as 2.10-ee)')
    else:
        cmd = [cc, '-c'] + pflags + pcflags + asflags + ['-o', opath, spath]
        print(' '.join(cmd), flush=True)
        if subprocess.run(cmd).returncode != 0:
            raise SystemExit(f'build_text: {label} failed to assemble')


def _protect(stext, opath, label):
    """Level 39's DNAS blocks, protected on the object (tools/dnas.py); every time, also on a
    reused object (the cache keeps it as the assembler wrote it)."""
    if dnas.has_blocks(stext):
        # level 39's protected DNAS blocks: the version's random words and the encryption, on
        # the object, before anything links it (tools/dnas.py)
        try:
            for function, number, row in dnas.protect_object(opath):
                print(f'dnas: {label}: {function} block {number} protected', flush=True)
        except dnas.DnasError as e:
            raise SystemExit(f'build_text: {label}: {e}')


# @ee29 ranges (tools/ee29.py): the 2.9-ee folder and the runner for its
# Windows driver on Linux/macOS; main() sets them from --ee29 / --runner.
# @ee296 ranges (tools/ee296.py): the 2.96-ee folder, from --ee296.
# @eeas ranges (tools/eeas.py): Sony's ee-as program, from --eeas (else env UYA_EEAS)
EE29 = None
RUNNER = None
EE296 = None
EEAS = None
CC = None
LD = None


def main():
    global EE29, RUNNER, EE296, EEAS, CC, LD, CACHE, TOOLCHAIN
    T = targets.from_argv()
    ap = argparse.ArgumentParser()
    ap.add_argument('--files', default=None, help="file list (default: the target's)")
    ap.add_argument('--parts', default=None, help="flags table (default: the target's)")
    ap.add_argument('--unit', default=None,
                    help="code section to build (boot_elf: core or text); needed when the target has several")
    ap.add_argument('--cc', required=True)
    ap.add_argument('--ld', required=True)
    ap.add_argument('--cflags', default='')
    ap.add_argument('--base', action='store_true', help='objdiff base build (-DOBJDIFF_BASE)')
    ap.add_argument('--workdir', default=None)
    ap.add_argument('--ee29', default=None,
                    help="Sony 2.9-ee-991111 folder for @ee29 ranges (default: env UYA_EE29, else %s)"
                    % ee29.DEFAULT_ROOT)
    ap.add_argument('--ee296', default=None,
                    help="Sony 2.96-ee-001003-1 folder for @ee296 ranges (default: env UYA_EE296, else %s)"
                    % ee296.DEFAULT_ROOT)
    ap.add_argument('--eeas', default=None,
                    help="Sony's ee-as 2.10-ee-001003-1 program for @eeas ranges (default: env UYA_EEAS)")
    ap.add_argument('--runner', default=None,
                    help='runs the Windows 2.9-ee driver on Linux/macOS (default: env UYA_RUNNER, else wibo)')
    ap.add_argument('-j', '--jobs', type=int, default=int(os.environ.get('UYA_JOBS', '1')),
                    help='files compiled at a time (default: env UYA_JOBS, else 1)')
    ap.add_argument('--toolchain', default=None,
                    help="the toolchain folder --cc and --ld run, for the reuse key (default: the folder "
                         "above --cc's)")
    ap.add_argument('--no-cache', action='store_true',
                    help='compile and assemble everything again, reusing nothing (tools/objcache.py); '
                         'also env UYA_NO_CACHE=1')
    ap.add_argument('-o', '--output', required=True)
    a = ap.parse_args()
    EE29, RUNNER, EE296, EEAS = a.ee29 or None, a.runner or None, a.ee296 or None, a.eeas or None
    CC, LD, TOOLCHAIN = a.cc, a.ld, a.toolchain
    CACHE = objcache.Cache(enabled=not a.no_cache)

    parts = read_parts(a.parts or T.path('parts'))
    files = sf.read_file_list(a.files or T.path('files'))
    if a.unit:
        unit = T.unit(a.unit)
    elif len(T.units) == 1:
        unit = T.units[0]
    else:
        sys.exit('build_text: %s has several code sections; pass --unit (%s)'
                 % (T.name, ', '.join(u.name for u in T.units)))
    files = [(rel, start) for rel, start in files if unit.contains(start)]
    if not files:
        sys.exit('build_text: no source files for %s %s' % (T.name, unit.name))
    if a.workdir:
        workdir = a.workdir
    elif a.base:
        # objdiff base build: per-file objects next to the output
        # (build/objdiff/base/frontbin/, build/objdiff/base/boot_elf/core/, ...),
        # never over the real build's
        workdir = os.path.join(os.path.dirname(a.output) or '.', unit.objdir)
    else:
        # build/src/frontbin/, build/boot_elf/src/core/, ...
        workdir = T.workdir(unit)
    os.makedirs(workdir, exist_ok=True)
    cflags = shlex.split(a.cflags, posix=False)
    if a.base:
        cflags.append('-DOBJDIFF_BASE')
    def build_file(rel, start, reuse_only=False):
        text = sf.read_source(rel)
        prelude, _, chunks = sf.split_file(text)
        stem = os.path.splitext(os.path.basename(rel))[0]
        # a chunk whose address the splitter could not read (0) is in this file's part,
        # not the first part's
        chunks = [(c[0] or start,) + tuple(c[1:]) for c in chunks]
        slices = file_slices(chunks, parts)
        if len(slices) == 1:
            # the file as it is, once
            spath = os.path.join(workdir, stem + '.s')
            opath = os.path.join(workdir, stem + '.o')
            compile_one(a.cc, slices[0][0], cflags, rel, spath, opath, rel, reuse_only)
            return opath
        sobjs = []
        # slices go in their own folder, so workdir holds one .o per file
        sdir = os.path.join(workdir, 'slices')
        os.makedirs(sdir, exist_ok=True)
        # the declarations of the chunks before the last slice, each taken once
        decls = [declarations_only(body) for _, _, body in chunks[:slices[-1][1][0]]]
        for k, (fl, idxs) in enumerate(slices):
            cpath = os.path.join(sdir, '%s.%d.c' % (stem, k))
            spath = os.path.join(sdir, '%s.%d.s' % (stem, k))
            opath = os.path.join(sdir, '%s.%d.o' % (stem, k))
            with open(cpath, 'w', newline='\n') as f:
                f.write(slice_source(rel, prelude, chunks, idxs, decls))
            compile_one(a.cc, fl, cflags, cpath, spath, opath, '%s (slice %d)' % (rel, k), reuse_only)
            sobjs.append(opath)
        # one object per source file (objdiff compares file by file)
        opath = os.path.join(workdir, stem + '.o')
        key = link_key(a.ld, opath, sobjs)
        if not _reused(key, opath, reuse_only):
            if subprocess.run([a.ld, '-r', '-o', opath] + sobjs).returncode != 0:
                raise SystemExit(f'build_text: ld -r of {rel} failed')
            _keep(key, opath)
        return opath

    # first, in this thread, every file whose steps can all be reused (the work is Python's,
    # which threads would only slow down); the rest compile independently: -j N runs N at a
    # time; the link order stays the list's
    done, todo = {}, []
    for n, (rel, start) in enumerate(files):
        if not CACHE.enabled:
            todo.append(n)
            continue
        try:
            done[n] = build_file(rel, start, reuse_only=True)
        except (NeedsBuild, SystemExit):
            todo.append(n)
    from concurrent.futures import ThreadPoolExecutor
    with ThreadPoolExecutor(max_workers=max(1, a.jobs)) as pool:
        futures = [(n, pool.submit(build_file, *files[n])) for n in todo]
        errors = []
        for n, fu in futures:
            try:
                done[n] = fu.result()
            except SystemExit as e:
                errors.append(str(e))
        if errors:
            sys.exit('\n'.join(errors))
    objs = [done[n] for n in range(len(files))]
    cmd = [a.ld, '-r', '-o', a.output] + objs
    print(CACHE.summary(), flush=True)
    print('%s -r -o %s (%d objects)' % (a.ld, a.output, len(objs)), flush=True)
    if subprocess.run(cmd).returncode != 0:
        sys.exit('build_text: ld -r failed')


if __name__ == '__main__':
    main()
