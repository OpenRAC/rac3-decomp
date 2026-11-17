#!/usr/bin/env python3
"""c_objects.py: the shared C compiled for the NTSC-U build (tools/asm_build.py --version us --c).

    python3 tools/c_objects.py -j 32 --toolchain DIR --runner WIBO --ee29 DIR [--ee296 DIR] [--eeas PROGRAM] [TARGET ...]

For every function of src/ (and src/us/) that checks MATCH on NTSC-U (config/us/map.tsv), one
object holding that function alone: its block compiled with its own file's flags and context by
tools/check.py --version us, exactly as the check compiles it (the block in its file's context, or
from its marker only when the text before it is that context already), kept only when that very
compile gives MATCH. build/us/cobj/<program>/<name>.o and build/us/cobj/index.tsv (program,
name, NTSC-U places, object). A shared object with data of its own is left out unless its
whole PAL file can be carried. Native core objects with data are carried whole through
files.tsv; their code and data must both survive the full-program retail comparison.

tools/asm_build.py --c then links each object at its NTSC-U places in place of the function's
assembly; the values of the names it uses are read from the disc's bytes and checked
(tools/level_symbols.py's derive(), as PAL's level build does).

Checks (since 2026-11-17) run in -j long-lived workers (tools/check_batch.py), each of which runs
check after check exactly as `python3 tools/check.py --version us ...` would and keeps the tables
every check reads (tools/memo.py); a check that takes longer than CHECK_TIMEOUT seconds has its
worker killed (with every process it started) and replaced, as does a worker that dies. --no-batch
starts tools/check.py once per check instead, as before; the results are the same.

Reuse (since 2026-11-16): each function's result (object or "-", and the SHA-1 of the object file
as the check left it) is stored in build/us/cobj_reuse/results.tsv under a key, and a later run
takes it instead of running the check again when the key is the same and the object file is still
the one stored. --no-reuse runs every check again (and stores the new results). The key covers:

- everything the check reads that is not one function's: the files of tools/ the result comes
  from (check_tools(): this script, tools/check.py and tools/check_batch.py with every module of
  tools/ they import, also inside functions), config/ (both versions; all but config/us/map.tsv,
  which is covered as below, and config/us/built.tsv, which this tool's --collect writes), the
  dumps of both discs (baserom/*.elf, baserom/levels/, the same under baserom/us/), Python's
  version and those of pyelftools and capstone;
  - of config/us/map.tsv the columns the check reads for the names a function uses (PAL name,
    program, NTSC-U name and place, size, whether the row is a near miss), and the address of
    every source entry of the core programs (a function split in src/ is checked at its offset);
- the toolchain: --toolchain, --runner, --ee29, --ee296, --eeas as given, the bytes of every file
  in those folders and of those programs, and every UYA_* environment variable;
- the function's own: its row of config/us/map.tsv, its program, name, NTSC-U places, source file
  and whether it is src/us/ C; the bytes of its whole source file (its block, its prelude, its
  includes' names and the declarations of the functions before it); for a core function also the
  declaration statements of every file before its own in the program's link order (what
  tools/split_text.py's extra_declarations() puts in front of it); the headers its compile can
  include (since 2026-11-17, FileInputs.header_paths(), tools/includes.py: every #include of its
  file, and for a core function of the files before it, followed through every folder the
  compilers search (the toolchains' own too: a header found there is followed as well), in every
  spelling a compiler opens, whatever #if stands around it, with the common.h the check adds and
  the assembler's .include files; every header when an #include names a macro).

A result is not stored when a check timed out or was killed. With CHECK_BATCH_VERIFY=1 the workers
check after every check that it changed none of the tables they keep (tools/memo.py); when one did,
the run stops (exit status 1, naming the check and the table) without storing that check's result
or starting another, and leaves index.tsv as it was. Editing a tool of check_tools() or a
table therefore redoes every function, a header the functions whose compile can include it (all of
them for common.h and what it includes), a source file the functions of that file (and of the
later files of its core program when the declarations or includes it exports change); another
tool, or a header no compile includes (include/names.h), none.
"""
import argparse
import hashlib
import os
import re
import subprocess
import sys
import tempfile
import threading
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402

OUT = version.build("cobj", v="us")
INDEX = os.path.join(OUT, "index.tsv")
CORE = ("frontbin", "boot_elf", "i5bootn")
REUSE = version.build("cobj_reuse", v="us")
RESULTS = os.path.join(REUSE, "results.tsv")
KEY_VERSION = "c_objects reuse 2"


def placements():
    """[(program, name, [(target, NTSC-U address)], source file, native)] of everything that
    checks MATCH on NTSC-U and is C."""
    import level_catalogue as lc
    import levels
    import version_map as vm
    m = vm.Map()
    states = vm.pal_states()
    us_cat = {r[0]: r for r in lc.read_catalogue(vm.cat_path("us"))}
    native = vm.us_sources()
    out = []
    for r in m.rows:
        if r["state"] != "C" or r["status"] != "match":
            continue
        if r["pal"] == "-":
            rel, nat = native.get((r["program"], vm.native_name(r["us"]))), True
        else:
            rel, nat = states[(r["program"], r["pal"])][1], False
        name = vm.native_name(r["us"]) if nat else r["pal"]
        if r["program"] == "levels":
            row = us_cat.get(r["us"])
            if row is None:
                continue
            places = [(levels.target_name(n), a) for n, a in row[5]]
        else:
            places = [(r["program"], int(r["place"], 16))]
        out.append((r["program"], name, places, rel, nat))
    return out


FILES = os.path.join(OUT, "files.tsv")


def rebase_code_words(path, start, end, delta):
    """Moves the object at PATH's own code pointers by DELTA: in its allocated data sections, each
    aligned word without a relocation whose value is an address in [START, END) (the file's PAL
    code) gets DELTA added. Ps2EeAs (@ps2as files) fills a jump table with the labels' absolute
    PAL addresses and leaves no relocation for them, so linked whole at the NTSC-U place the
    table would still point at PAL's code. Returns the number of words changed."""
    import struct
    if not delta:
        return 0
    with open(path, "rb") as f:
        d = bytearray(f.read())
    if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:     # ELF32, little-endian
        return 0
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    shentsize, shnum = struct.unpack_from("<HH", d, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + shentsize * i) for i in range(shnum)]
    relocated = {}
    for s in secs:
        if s[1] in (4, 9) and s[9]:                       # SHT_RELA, SHT_REL: r_offset first
            relocated.setdefault(s[7], set()).update(
                struct.unpack_from("<I", d, s[4] + k)[0] for k in range(0, s[5], s[9]))
    changed = 0
    for i, s in enumerate(secs):
        # SHT_PROGBITS, SHF_ALLOC and not SHF_EXECINSTR: .rodata, .data, .sdata, ...
        if s[1] != 1 or not s[2] & 2 or s[2] & 4:
            continue
        done = relocated.get(i, set())
        for k in range(0, s[5] - 3, 4):
            v = struct.unpack_from("<I", d, s[4] + k)[0]
            if k not in done and start <= v < end and v % 4 == 0:
                struct.pack_into("<I", d, s[4] + k, (v + delta) & 0xFFFFFFFF)
                changed += 1
    if changed:
        with open(path, "wb") as f:
            f.write(bytes(d))
    return changed


def file_pieces(write=True):
    """Whole PAL source files for the NTSC-U build, as PAL's build compiles them: a core file
    holding a C function that does not reproduce alone (a block of several functions, an @ps2as
    file's slices, data of its own) is linked whole when every function of it has its NTSC-U
    twin at one and the same distance from its PAL place. The object is the PAL build's own
    (build/.../src/<unit>/<file>.o), its absolute code pointers moved by that distance
    (rebase_code_words); build/us/cobj/files.tsv: program, file, PAL start, NTSC-U
    start, object, the C functions it carries. Native core functions with compiler-generated
    data use the same whole-object path at their native address, after a stock compile MATCH;
    the full program build must reproduce their data as well as their code."""
    import shutil
    import srcfiles as sf
    import targets
    import version_map as vm
    import level_symbols as ls
    m = vm.Map()
    built = read_index()
    states = vm.pal_states()
    rows = []
    for program in CORE:
        t = targets.TARGETS[program]
        fl = sf.read_file_list(t.path("files"))
        starts = [x for _, x in fl]
        want = {st[1] for (p, n), st in states.items() if p == program and st[0] == "C"
                and (p, n) not in built and m.by_pal.get((p, n), {}).get("status") == "match"}
        for i, (rel, s0) in enumerate(fl):
            if rel not in want:
                continue
            u = t.unit_for(s0)
            end = starts[i + 1] if i + 1 < len(starts) and t.unit_for(starts[i + 1]) is u else u.end
            inside = [r for r in m.rows if r["program"] == program and r["pal"] != "-" and r["state"] != "near"
                      and s0 <= int(r["pal"][5:], 16) < end]
            deltas = {int(r["place"], 16) - int(r["pal"][5:], 16) if r["status"] in ("match", "asm") else None
                      for r in inside}
            if len(deltas) != 1 or None in deltas or not inside:
                continue
            delta = deltas.pop()
            src = os.path.join(ROOT, t.workdir(u), os.path.splitext(os.path.basename(rel))[0] + ".o")
            if not os.path.exists(src):
                continue
            obj = os.path.join(OUT, "files", program, os.path.splitext(os.path.basename(rel))[0] + ".o")
            if write:
                os.makedirs(os.path.dirname(obj), exist_ok=True)
                shutil.copy(src, obj)
                rebase_code_words(obj, s0, end, delta)
            names = [r["pal"] for r in inside if r["state"] == "C"]
            rows.append((program, rel, s0, s0 + delta, os.path.relpath(obj, ROOT), names))
    for (program, name), rel in sorted(vm.us_sources().items()):
        obj = built.get((program, name))
        if program not in CORE or obj is None:
            continue
        native = ls.read_object(os.path.join(ROOT, obj))
        if not native["extra"] or native["defined"].get(name) != 0:
            continue
        start = int(vm.us_name(name)[5:], 16)
        rows.append((program, rel, start, start, obj, [name]))
    if write:
        with open(FILES, "w") as f:
            for program, rel, s0, us0, obj, names in rows:
                f.write("%s\t%s\t%08X\t%08X\t%s\t%s\n" % (program, rel, s0, us0, obj, ",".join(names)))
    return rows


def read_files():
    """[(program, file, PAL start, NTSC-U start, object, [C functions])] of build/us/cobj/files.tsv"""
    out = []
    if os.path.exists(FILES):
        for line in open(FILES):
            f = line.rstrip("\n").split("\t")
            out.append((f[0], f[1], int(f[2], 16), int(f[3], 16), f[4], f[5].split(",") if f[5] else []))
    return out


def read_index():
    """{(program, name): object path} of what compiled to MATCH."""
    out = {}
    if os.path.exists(INDEX):
        for line in open(INDEX):
            f = line.rstrip("\n").split("\t")
            if len(f) == 3 and f[2] != "-":
                out[(f[0], f[1])] = f[2]
    return out


CHECK_TIMEOUT = 600


def check_process(args, timeout=CHECK_TIMEOUT):
    """(exit status, standard output) of `python3 tools/check.py ARGS` in a process of its own (the
    way before 2026-11-17, --no-batch); subprocess.TimeoutExpired when it takes longer than TIMEOUT."""
    p = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "check.py")] + list(args), cwd=ROOT,
                       capture_output=True, text=True, timeout=timeout, env=dict(os.environ, UYA_VERSION="us"))
    return getattr(p, "returncode", 0), p.stdout


def compile_one(item, a, tmp, notes=None, run=check_process):
    """(item, object or "-", why). NOTES, a dict, gets "transient" when a check timed out or was
    killed, or its worker ended during it: such a result is not stored for reuse, and NOTES["lost"]
    lists why. RUN(args) runs one check: check_process(), or a tools/check_batch.py worker's."""
    import check_batch
    import version_map as vm
    program, name, places, rel, nat = item
    obj = os.path.join(OUT, program, name + ".o")
    if nat:
        variants = [(os.path.join(ROOT, rel), ["--native"])]
    else:
        variants = []
        for block_only in (False, True):
            p = os.path.join(tmp, "%s_%s%s.c" % (program, name, "_b" if block_only else ""))
            open(p, "w").write(vm.chunk_text(program, rel, name, block_only=block_only))
            variants.append((p, []))
    check_target = program if program in CORE else places[0][0] if nat and program == "levels" else None
    for path, extra in variants:
        args = ["--version", "us", path, name, "--quiet",
                "--keep-object", obj, "--toolchain", a.toolchain] + (["--runner", a.runner] if a.runner else []) + \
            (["--ee29", a.ee29] if a.ee29 else []) + (["--ee296", a.ee296] if a.ee296 else []) + \
            (["--eeas", a.eeas] if getattr(a, "eeas", None) else []) + extra + \
            (["--target", check_target] if check_target else [])
        try:
            returncode, stdout = run(args)
        except (subprocess.TimeoutExpired, check_batch.WorkerDied) as e:
            if notes is not None:
                notes["transient"] = True
                notes.setdefault("lost", []).append("%s: %s" % (os.path.basename(path), str(e)[-200:]))
            continue
        if notes is not None and (returncode or 0) < 0:   # killed by a signal
            notes["transient"] = True
            notes.setdefault("lost", []).append("%s: killed by signal %d" % (os.path.basename(path), -returncode))
        if re.search(r"^%s: MATCH" % re.escape(name), stdout, re.M) and os.path.exists(obj):
            import level_symbols
            if nat and program == "levels" and any(address % 8 == 4 for _, address in places):
                if any(address % 8 != 4 for _, address in places):
                    return item, "-", "the C object's 4-mod-8 placements differ across levels"
                import c_text_align
                import level_catalogue as lc

                row = next((row for row in lc.read_catalogue(vm.cat_path("us")) if row[0] == name), None)
                if row is None:
                    return item, "-", "native function missing from the level catalogue"
                try:
                    c_text_align.trim_four_aligned_function(obj, name, row[2])
                except (OSError, ValueError) as error:
                    return item, "-", "cannot place C at 4 mod 8: %s" % error
            o = level_symbols.read_object(obj)
            # a level function's switch jump tables go where its code reads them (asm_build.py);
            # a core function's read-only data only with its whole file (files.tsv)
            extra = [x for x in o["extra"] if program != "levels" or x not in level_symbols.RODATA]
            if extra and not (nat and program in CORE):
                return item, "-", "data of its own (%s)" % ", ".join(extra)
            return item, obj, "ok"
    if os.path.exists(obj):
        os.remove(obj)
    return item, "-", "no compile of the block alone gives MATCH"


# --- reuse: a stored result per function, keyed by everything that can change it -------------

# the tables a check reads by function or by file: hashed per function (they change with most
# matches), never in global_key()
PER_FUNCTION_TABLES = ("text_parts.txt", "divs_nops.txt", "sq_ra_funcs.txt")
# the scripts a result comes from: this one (which decides it from the check's output and the
# object), the check, and the worker that runs checks; with every module of tools/ they import
# (check_tools())
CHECK_SCRIPTS = ("c_objects.py", "check.py", "check_batch.py")


def check_tools():
    import stamps
    return stamps.tool_closure([os.path.join(ROOT, "tools", s) for s in CHECK_SCRIPTS])


def per_function_table(path):
    return os.path.basename(path) in PER_FUNCTION_TABLES


def map_projection(rows):
    """Of config/us/map.tsv's rows (version_map.Map().rows) the columns the check reads for the names
    a function uses (version_map.UsNames, Map.us_place): not the state, status, closeness or hash a
    match changes, except whether a row is a near miss."""
    return "".join("%s\t%s\t%s\t%s\t%d\t%d\n" % (r["pal"], r["program"], r["us"], r["place"], r["size"],
                                                 r["state"] == "near") for r in rows).encode()


def global_key(a):
    """The part of every function's key that is no one function's (see the docstring)."""
    import progress
    import stamps
    import targets
    import version_map as vm
    h = hashlib.sha1(KEY_VERSION.encode() + b"\0")
    h.update(("python %s %s\0" % (sys.executable, sys.version)).encode())
    for mod in ("elftools", "capstone"):
        try:
            m = __import__(mod)
            h.update(("%s %s\0" % (mod, getattr(m, "__version__", "?"))).encode())
        except ImportError:
            h.update(("%s missing\0" % mod).encode())
    stamps.update(h, check_tools())
    config = os.path.join(ROOT, "config")
    stamps.update(h, [config], exclude=[vm.MAP, BUILT] + [p for p in stamps.files_under(config)
                                                          if per_function_table(p)])
    dumps = []
    for v in ("pal", "us"):
        dumps += [version.baserom(p + ".elf", v=v) for p in CORE] + [version.baserom("levels", v=v)]
    stamps.update(h, dumps)
    h.update(map_projection(vm.Map().rows))
    # the source entries of the core programs (version_map.covered())
    for program in CORE:
        h.update(("entries %s\0" % program).encode())
        h.update(",".join("%X" % e[2] for e in progress.entries(targets.TARGETS[program])).encode())
    # the toolchain
    for flag in ("toolchain", "runner", "ee29", "ee296", "eeas"):
        value = getattr(a, flag, None)
        h.update(("--%s %s\0" % (flag, value)).encode())
        if value:
            stamps.update(h, [os.path.abspath(value)])
    for k in sorted(os.environ):
        if k.startswith("UYA_"):
            h.update(("env %s=%s\0" % (k, os.environ[k])).encode())
    return h.hexdigest()


class FileInputs:
    """What a function's key takes from its source file and the per-function tables, computed once
    per file: the file's bytes, its flags (config/<program>/text_parts.txt's lines that govern a
    core file, config/levels/text_parts.txt's or config/us/text_parts.txt's line of the file), the
    divs_nops.txt / sq_ra_funcs.txt rows (config/, and the level trees' under build/levels/) of the
    names the file mentions, and for a core file the declarations of the files before it."""

    def __init__(self, root=ROOT, system=()):
        import glob
        import level_tree
        import srcfiles as sf
        import stamps
        import targets
        import version_map as vm
        self.root, self.cache = root, {}
        self.level_parts, self.us_parts = level_tree.read_parts(), vm.us_parts()
        self.core_parts, self.core_files, self.earlier = {}, {}, {}
        for program in CORE:
            t = targets.TARGETS[program]
            lines = []
            for line in open(os.path.join(root, t.path("parts")) if not os.path.isabs(t.path("parts"))
                             else t.path("parts")):
                if line.strip() and not line.startswith("#"):
                    lines.append((int(line.split()[0], 16), line.rstrip("\n")))
            self.core_parts[program] = sorted(lines)
            files = sf.read_file_list(t.path("files"))
            for i, (rel, start) in enumerate(files):
                nxt = files[i + 1][1] if i + 1 < len(files) else 1 << 32
                self.core_files[(program, rel)] = (start, nxt)
        self.all_parts = stamps.of(sorted(p for p in stamps.files_under(os.path.join(root, "config"))
                                          if os.path.basename(p) == "text_parts.txt"))
        self.rows = {}
        tables = [p for p in stamps.files_under(os.path.join(root, "config")) if per_function_table(p)
                  and os.path.basename(p) != "text_parts.txt"]
        tables += sorted(glob.glob(os.path.join(root, "build", "levels", "*", "divs_nops.txt")) +
                         glob.glob(os.path.join(root, "build", "levels", "*", "sq_ra_funcs.txt")))
        for path in tables:
            for line in open(path, errors="replace"):
                words = line.split("#")[0].split()
                if words:
                    self.rows.setdefault(words[0], []).append("%s: %s" % (os.path.relpath(path, root),
                                                                          line.rstrip("\n")))
        self._earlier = None
        self._earlier_includes, self._header_sums = None, {}
        import includes
        self.scanner = includes.Scanner(root, system)

    def earlier_declarations(self, program, rel):
        """SHA-1 of the declaration statements of the files before REL in PROGRAM's link order
        (tools/split_text.py's earlier_statements())."""
        if self._earlier is None:
            import split_text
            import srcfiles as sf
            import targets
            self._earlier = {}
            for p in CORE:
                h = hashlib.sha1()
                for r, _ in sf.read_file_list(targets.TARGETS[p].path("files")):
                    self._earlier[(p, r)] = h.copy().hexdigest()
                    if os.path.exists(os.path.join(self.root, r)):
                        _, _, chunks = sf.split_file(sf.read_source(r, self.root))
                        for st, declared, used in split_text.statements_of(chunks):
                            h.update(repr((st, sorted(declared), sorted(used))).encode() + b"\n")
                    else:
                        h.update(b"<missing>\n")
        return self._earlier.get((program, rel), "<none>")

    def earlier_includes(self, program, rel):
        """The includes (tools/includes.py) of every file before REL in PROGRAM's link order: their
        declarations, preprocessor lines among them, can be put in front of a function of REL."""
        if self._earlier_includes is None:
            import includes
            import srcfiles as sf
            import targets
            self._earlier_includes = {}
            for p in CORE:
                found = frozenset()
                for r, _ in sf.read_file_list(targets.TARGETS[p].path("files")):
                    self._earlier_includes[(p, r)] = found
                    path = os.path.join(self.root, r)
                    if os.path.isfile(path):
                        with open(path, "rb") as f:
                            found = found | includes.includes_of(f.read().decode("latin-1"))
        return self._earlier_includes.get((program, rel), frozenset())

    def header_paths(self, program, rel, nat, data):
        """((path, exists), ...) of the files the function's compile can include
        (tools/includes.py): through its source file's includes (DATA: its bytes), the common.h
        the check adds when the text lacks it, and in a core program those of the files before
        it (earlier_includes()). None when an include cannot be followed."""
        import includes
        found = includes.includes_of('#include "common.h"\n')
        if data is not None:
            found |= includes.includes_of(data.decode("latin-1"))
        if program in CORE and not nat:
            found |= self.earlier_includes(program, rel)
        return self.scanner.resolve(frozenset(found))

    def headers(self, program, rel, nat, data):
        """SHA-1 of header_paths()' files; when it is None, of every header (include/, src/'s)."""
        import stamps
        got = self.header_paths(program, rel, nat, data)
        if got in self._header_sums:
            return self._header_sums[got]
        h = hashlib.sha1()
        if got is None:
            h.update(b"every header\0")
            src = [p for p in stamps.files_under(os.path.join(self.root, "src")) if not p.endswith(".c")]
            stamps.update(h, [os.path.join(self.root, "include")] + src, root=self.root)
        for path, exists in got or ():
            h.update(os.path.relpath(path, self.root).replace(os.sep, "/").encode() + b"\0")
            if exists:
                with open(path, "rb") as f:
                    h.update(f.read())
            else:
                h.update(b"<missing>")
            h.update(b"\0")
        self._header_sums[got] = h.hexdigest()
        return self._header_sums[got]

    def flags(self, program, rel, nat):
        if nat:
            line = self.us_parts.get(rel)
            # without a line of its own, its counterpart's (version_map.counterpart_flags): any table
            return ("us", line) if line is not None else ("any", self.all_parts)
        if program == "levels":
            return ("level", self.level_parts.get(rel))
        start, nxt = self.core_files.get((program, rel), (None, None))
        if start is None:
            return ("any", self.all_parts)
        lines = self.core_parts[program]
        before = [l for a, l in lines if a <= start]
        return ("core", before[-1:] + [l for a, l in lines if start < a < nxt])

    def of(self, program, rel, nat):
        k = (program, rel, bool(nat))
        if k not in self.cache:
            h = hashlib.sha1()
            path = os.path.join(self.root, rel) if rel else None
            data = open(path, "rb").read() if path and os.path.isfile(path) else None
            h.update(repr(rel).encode() + b"\0")
            h.update(data if data is not None else b"<missing>")
            h.update(b"\0" + repr(self.flags(program, rel, nat)).encode() + b"\0")
            names = set(re.findall(r"\w+", data.decode("latin-1"))) if data else set()
            for n in sorted(names & set(self.rows)):
                h.update(("\n".join(self.rows[n]) + "\n").encode())
            if program in CORE and not nat:
                h.update(("earlier %s\0" % self.earlier_declarations(program, rel)).encode())
            h.update(("headers %s\0" % self.headers(program, rel, nat, data)).encode())
            self.cache[k] = h.hexdigest()
        return self.cache[k]


def map_rows():
    """{(program, name as placements() gives it): its config/us/map.tsv row}"""
    import version_map as vm
    out = {}
    for r in vm.Map().rows:
        name = vm.native_name(r["us"]) if r["pal"] == "-" else r["pal"]
        out[(r["program"], name)] = r
    return out


def item_key(item, gkey, rows, files):
    """The key of one function's result: GKEY (global_key()), its map row (ROWS: map_rows()), its
    placement, and what FILES (a FileInputs) takes from its source file."""
    program, name, places, rel, nat = item
    h = hashlib.sha1(gkey.encode() + b"\0")
    h.update(repr((program, name, [(t, int(x)) for t, x in places], rel, bool(nat))).encode() + b"\0")
    r = rows.get((program, name))
    h.update(repr(sorted(r.items()) if r else None).encode() + b"\0")
    h.update(files.of(program, rel, nat).encode())
    return h.hexdigest()


def read_results(path=RESULTS):
    """{(program, name): (key, object or "-", SHA-1 of the object file or "-", why)}; the last line
    of a name wins."""
    out = {}
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            f = line.rstrip("\n").split("\t")
            if len(f) == 6:
                out[(f[0], f[1])] = (f[2], f[3], f[4], f[5])
    return out


def write_results(results, path=RESULTS):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + ".tmp"
    with open(tmp, "w", encoding="utf-8", newline="\n") as f:
        for k in sorted(results):
            f.write("\t".join(k + tuple(results[k])) + "\n")
    os.replace(tmp, path)


def object_path(item):
    return os.path.join(OUT, item[0], item[1] + ".o")


def reusable(stored, key, obj_path):
    """The stored (object, why) when STORED ((key, object, SHA-1, why) or None) is for KEY and the
    object file at OBJ_PATH is still the one the check left (or still absent); else None."""
    if stored is None or stored[0] != key:
        return None
    import stamps
    if stamps.file_sha1(obj_path) != stored[2]:
        return None
    return stored[1], stored[3]


BUILT = version.cfg("built.tsv", v="us")
BUILT_HEAD = """# The C linked into the NTSC-U programs (tools/asm_build.py --version us --c, then
# tools/c_objects.py --collect): program, name (src/'s; NTSC-U's own for src/us/), the programs
# whose build has it from C, and where it stays assembly and why. The NTSC-U report counts a C
# function as final only when every program that has it builds it from C.
"""


def collect(dirs):
    """config/us/built.tsv from the builds' c_functions.txt (in build/us/ or in DIRS, other
    machines' build/us/ copies)."""
    items = placements()
    want = {}
    for program, name, places, rel, nat in items:
        want[(program, name)] = {t for t, a in places}
    got = {k: set() for k in want}
    left = {k: {} for k in want}
    built = read_index()
    seen = set()
    for d in [version.build(v="us")] + list(dirs):
        if not os.path.isdir(d):
            continue
        for t in os.listdir(d):
            f = os.path.join(d, t, "c_functions.txt")
            if not os.path.exists(f) or t in seen:
                continue
            seen.add(t)
            program = "levels" if t.startswith("level_") else t
            for line in open(f):
                m = re.match(r"^# left as assembly: [0-9A-F]{8} (\S+): (.*)$", line.rstrip("\n"))
                if m:
                    left.setdefault((program, m.group(1)), {})[t] = m.group(2)
                elif line.strip():
                    got.setdefault((program, line.split()[1]), set()).add(t)
    lines = [BUILT_HEAD.rstrip("\n")]
    for k in sorted(want):
        why = dict(left.get(k, {}))
        for t in want[k] - got.get(k, set()) - set(why):
            why[t] = "no object of the block alone checks MATCH" if k not in built else \
                ("not built" if t in seen else "not built here (no build of %s)" % t)
        lines.append("\t".join([k[0], k[1], str(len(got.get(k, ()))),
                                 ";".join("%s: %s" % (t, why[t]) for t in sorted(why)) or "-"]))
    open(BUILT, "w", newline="\n").write("\n".join(lines) + "\n")
    full = sum(1 for l in lines[1:] if l.endswith("\t-"))
    print("wrote %s: %d of %d C functions built from C wherever they are" % (os.path.relpath(BUILT, ROOT), full,
                                                                            len(lines) - 1))


def read_built():
    """{(program, name): (programs built, problems or '')} of config/us/built.tsv (None: no table)."""
    if not os.path.exists(BUILT):
        return None
    out = {}
    for line in open(BUILT, encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        prog, name, n, why = line.rstrip("\n").split("\t", 3)
        out[(prog, name)] = (int(n), "" if why == "-" else why)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("targets", nargs="*", help="only what these targets need (default: everything)")
    ap.add_argument("--collect", nargs="*", metavar="DIR",
                    help="write config/us/built.tsv from the builds (build/us/, and other machines' copies in DIR)")
    ap.add_argument("-j", "--jobs", type=int, default=8,
                    help="checks at once, each in a worker of about 210 MB for the whole run (default 8)")
    ap.add_argument("-v", "--verbose", action="store_true", help="name each function whose check is run")
    ap.add_argument("--no-reuse", action="store_true",
                    help="run every function's check again instead of reusing stored results (see above)")
    ap.add_argument("--no-batch", action="store_true",
                    help="start tools/check.py once per check, as before 2026-11-17, instead of in -j long-lived "
                    "workers (tools/check_batch.py); the results are the same")
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"))
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--ee29", default=os.environ.get("UYA_EE29"))
    ap.add_argument("--ee296", default=os.environ.get("UYA_EE296"))
    ap.add_argument("--eeas", default=os.environ.get("UYA_EEAS"))
    a = ap.parse_args()
    if a.collect is not None:
        collect(a.collect)
        return
    if not a.toolchain:
        sys.exit("--toolchain is needed to compile")
    items = placements()
    if a.targets:
        want = set(a.targets)
        items = [i for i in items if any(t in want for t, _ in i[2])]
    for p in CORE + ("levels",):
        os.makedirs(os.path.join(OUT, p), exist_ok=True)
    tmp = tempfile.mkdtemp(prefix="c_objects_")
    rows, bad = {}, []
    if os.path.exists(INDEX):
        for line in open(INDEX):
            f = line.rstrip("\n").split("\t")
            rows[(f[0], f[1])] = f
    import check_batch
    import stamps
    import includes
    # the compilers' own folders: a toolchain header's includes look in include/ and the root first
    system = includes.toolchain_dirs([a.toolchain, a.ee29, a.ee296])
    gkey, mrows, files = global_key(a), map_rows(), FileInputs(system=system)
    keys = {(i[0], i[1]): item_key(i, gkey, mrows, files) for i in items}
    stored = read_results(RESULTS)
    lock, counts = threading.Lock(), {"reused": 0, "checked": 0, "stored": 0}
    os.makedirs(REUSE, exist_ok=True)
    log = open(RESULTS, "a", encoding="utf-8", newline="\n")
    # one tools/check_batch.py worker per thread (-j of them), started at its first check
    local, workers = threading.local(), []
    worker_env = dict(os.environ, UYA_VERSION="us")

    def run(args):
        if a.no_batch:
            return check_process(args)
        if not hasattr(local, "worker"):
            with lock:
                local.worker = check_batch.Worker(env=worker_env, log=os.path.join(tmp, "worker_%d.log" % len(workers)))
                workers.append(local.worker)
        returncode, stdout, _ = local.worker.run(args, timeout=CHECK_TIMEOUT)
        return returncode, stdout

    # a worker in verify mode (CHECK_BATCH_VERIFY=1) found that a check changed a table it keeps
    # (check_batch.KeptTableChanged): the run stops, see below
    stop, stopped = threading.Event(), []

    def one(item):
        k, obj_path = keys[(item[0], item[1])], object_path(item)
        got = None if a.no_reuse else reusable(stored.get((item[0], item[1])), k, obj_path)
        if got is not None:
            with lock:
                counts["reused"] += 1
            return item, os.path.join(ROOT, got[0]) if got[0] != "-" else "-", got[1]
        if stop.is_set():
            return item, None, "not checked: the run stopped"
        notes = {}
        try:
            item, obj, why = compile_one(item, a, tmp, notes, run)
        except check_batch.KeptTableChanged as e:
            stop.set()
            with lock:
                stopped.append("%s %s: %s" % (item[0], item[1], e))
            return item, None, "not checked: the run stopped"
        if a.verbose or notes.get("lost"):
            print("checked %s %s: %s%s" % (item[0], item[1], why, "".join(
                "; not stored: " + x for x in notes.get("lost", []))), flush=True)
        rel = os.path.relpath(obj, ROOT) if obj != "-" else "-"
        with lock:
            counts["checked"] += 1
            if not notes.get("transient"):
                rec = (k, rel, stamps.file_sha1(obj_path), why.replace("\t", " ").replace("\n", " "))
                stored[(item[0], item[1])] = rec
                counts["stored"] += 1
                log.write("\t".join((item[0], item[1]) + rec) + "\n")
                log.flush()
        return item, obj, why
    try:
        with ThreadPoolExecutor(a.jobs) as ex:
            for item, obj, why in ex.map(one, items):
                if obj is None:
                    continue
                rows[(item[0], item[1])] = [item[0], item[1], os.path.relpath(obj, ROOT) if obj != "-" else "-"]
                if obj == "-":
                    bad.append((item[0], item[1], why))
    finally:
        for w in workers:
            w.close()
    log.close()
    write_results(stored, RESULTS)
    if stopped:
        # Not stored: the check that changed a table, and every check not yet started (a later check
        # of that worker could have read the changed table). Kept: every result stored before, of
        # that worker and of the others: a worker in verify mode compares its tables after each
        # check, so each earlier check of it began and ended with them as their loaders read them.
        # index.tsv stays as it was: this run did not finish.
        import shutil
        shutil.rmtree(tmp, ignore_errors=True)
        sys.exit("c_objects.py: stopped: %s\nThat check's result is not stored, and no check was started after it; "
                 "the %d results this run stored before it are kept (each worker verifies its tables after every check). "
                 "index.tsv is unchanged. A caller of a kept loader (tools/memo.py) changes what it was given: "
                 "it must copy it first." % ("; ".join(stopped), counts["stored"]))
    with open(INDEX, "w") as f:
        for k in sorted(rows):
            f.write("\t".join(rows[k]) + "\n")
    print("%d results reused, %d checks run%s%s" % (counts["reused"], counts["checked"],
                                                   " (--no-reuse)" if a.no_reuse else "",
                                                   " (--no-batch)" if a.no_batch else
                                                   " in %d workers" % sum(w.started for w in workers)))
    # the whole files, where the PAL build's objects are here (its core programs built)
    if not a.targets or set(a.targets) & set(CORE):
        fp = file_pieces()
        print("%d whole files for the functions that do not reproduce alone" % len(fp))
    import shutil
    shutil.rmtree(tmp, ignore_errors=True)
    print("%d objects, %d functions left as assembly" % (len(items) - len(bad), len(bad)))
    for p, n, why in bad:
        print("  %s %s: %s" % (p, n, why))


if __name__ == "__main__":
    main()
