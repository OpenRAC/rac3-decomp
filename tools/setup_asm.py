#!/usr/bin/env python3
"""setup_asm.py: generate a target's asm/ files from YOUR copy of its ELF.

asm/ is gitignored (it is the game's code, so it can't be shipped). A fresh clone
therefore has no asm/ at all and `make` stops with
"No rule to make target `asm/header.s'". Run this once after cloning, from anywhere:

    python tools/setup_asm.py                    # frontbin.elf  -> asm/
    python tools/setup_asm.py --target boot_elf  # boot_elf.elf  -> asm/boot_elf/
    python tools/setup_asm.py --target i5bootn   # i5bootn.elf   -> asm/i5bootn/
    python tools/setup_asm.py --target all       # every target whose ELF is in baserom/

then build (`make` on Windows, `python3 tools/build.py` on Linux/macOS). Re-run it
after pulling if the build says an asm/ file is missing; it is safe to repeat.
The targets and their folders are listed in tools/targets.py.

What it does, in order (a plain `splat split` is NOT enough, see 3 and 6):

  1. checks the ELF's sha1;
  2. writes one temporary C file per code section for splat (src/text.c for
     frontbin; src/boot_elf/core.c and text.c for boot_elf), each holding all of
     that section's source files concatenated, and saves the target's splat side
     files (undefined_funcs_auto / undefined_syms_auto), which splat overwrites;
  3. splat only writes a .s for functions that are INCLUDE_ASM in those files, so it
     temporarily turns the ASM_FUNC / LINKER_REMNANT entries back into INCLUDE_ASM
     (those are final source, but their .s still has to come from somewhere), and lists the
     functions that are already C the same way so localdecomp sees all of them;
  4. python -m splat split (with every func_<address> of the sources added as a function
     symbol so the function boundaries are exactly the sources'; for a level, an address
     that a call word reaches inside a row of config/levels/functions.tsv is added as a
     branch label, so spimdisasm does not start a function there: level_inner_calls()),
     then puts the saved files back;
  5. the ee-as fixups: fix_reg_names.py, fix_quadword_ops.py, fix_short_loops.py,
     and extract_header.py (the raw header bytes and, for boot_elf, the section-header
     table at the end of the file);
  6. the same post-processing the project applied when asm/ was committed:
       - moves the ASM_FUNC / LINKER_REMNANT .s files to the handwritten and remnants
         folders and comments out their `nonmatching` marker (it would make objdiff count
         them as unmatched);
       - trailing_padding.py --apply (cuts extra trailing nops; the sources are unchanged);
       - cuts the switch jump tables out of each data segment that holds them into
         <section>/rodata/jtbl_*.s and splits the segment into <name>_a.data.s /
         <name>_b.data.s (the steps of tools/migrate_jtbls.py that touch asm/).

For a level (since 2026-11-16) the setup is skipped when nothing it reads has changed: a full
setup keeps a copy of everything it wrote (build/setup_asm/level_NN/: outputs.zip, stamp.json
with the key and each file's SHA-1), and a later run whose key is the same puts back any of those
files that is missing or differs (tools/levels.py tree --fill, run after the setup, edits some
.s files every time), deletes files of the level's asm/ folder the setup did not write, and runs
tools/trailing_padding.py --apply, the one step of the setup that writes into the level's tree;
the files are then those a full setup writes. --force runs the full setup. The key covers:
the ELF's bytes and expected SHA-1; the splat configuration (config/splat/levels/NN_name.yaml and
the temporary one made from it) and the symbol files it lists (the tree's symbol_addrs.txt); the
temporary symbol file (every function start of the tree, and the branch labels from
config/levels/functions.tsv, level_inner_calls()); what splat reads from each temporary C file
(its INCLUDE_ASM and INCLUDE_RODATA macros and the functions it takes for defined in C, not their
code, and not a catalogue name func_LNN_XXXXXXXX that no symbol file gives: splat has no symbol of
that name, so a function matched or unmatched changes nothing it reads); the ASM_FUNC / LINKER_REMNANT files it moves; config/levels/levels.tsv, config/gp.tsv and
frontbin's symbol files (fix_reg_names.py's defaults); this tool, the tools it runs and every module
of tools/ they import; Python and the installed splat, spimdisasm and rabbitizer. Besides the key,
the functions whose trailing nops the setup cuts (trailing_padding.py, which looks at the tree's
INCLUDE_ASM entries) must be the same as when the copy was made, and a splat side file
(undefined_*_auto.txt) that is missing is only put back if the setup that made the copy wrote it.

Needs: the ELF in baserom/, `pip install -r tools/requirements.txt` and splat
(`pip install splat64`).
"""
import hashlib, json, os, re, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles  # noqa: E402


def run(*args):
    print("+", " ".join(args), flush=True)
    r = subprocess.run(list(args), cwd=ROOT)
    if r.returncode != 0:
        sys.exit("failed: %s" % " ".join(args))


def rd(p):
    return open(p, "rb").read()


def wr(p, b):
    open(p, "wb").write(b)


def yaml_option(yml, key, default):
    m = re.search(r"^\s*%s:\s*(\S+)" % key, yml, re.M)
    return m.group(1) if m else default


def asm_paths(t):
    """The target's asm folder, without other targets' folders nested inside it
    (frontbin's asm/ holds asm/boot_elf/)."""
    root = t.path("asm_root")
    others = {os.path.normpath(o.path("asm_root")) for o in targets.ALL.values() if o is not t}
    # the other versions' assembly (asm/us/, tools/asm_build.py --version us) is not this target's either
    import version
    others |= {os.path.normpath(version.asm(v=v)) for v in version.VERSIONS if v != "pal"}
    if not any(o.startswith(os.path.normpath(root) + os.sep) for o in others):
        return [root]
    if not os.path.isdir(root):
        return []
    # an entry that is another target's folder, or holds one (asm/levels/), is not this one's
    keep = lambda p: p not in others and not any(o.startswith(p + os.sep) for o in others)
    return [os.path.join(root, e) for e in sorted(os.listdir(root))
            if keep(os.path.normpath(os.path.join(root, e)))]


def clear_asm(t):
    for p in asm_paths(t):
        if os.path.isdir(p):
            shutil.rmtree(p)
        elif os.path.exists(p):
            os.remove(p)


def normalize_data_words(t):
    """splat symbolizes data words that point at functions; the project's data .s files use literals."""
    ddir = os.path.join(t.path("asm_root"), "data")
    rx = re.compile(r"\.word func_([0-9A-F]{8})\b")
    for f in os.listdir(ddir):
        if not f.endswith(".s"):
            continue
        p = os.path.join(ddir, f)
        txt = open(p, newline="").read()
        t2 = rx.sub(lambda m: ".word 0x" + m.group(1), txt)
        t2 = re.sub(r"\.word func_0(?=\s|$)", ".word 0x00000000", t2, flags=re.M)
        if targets.is_level(t):
            # floats as their bit patterns: the assembler does not keep a denormal's bits (the
            # levels' data has many, the core programs' none)
            t2 = re.sub(r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/) \.float \S+",
                        lambda m: "%s .word 0x%08X" % (m.group(1), int.from_bytes(bytes.fromhex(m.group(2)), "little")),
                        t2, flags=re.M)
            t2 = re.sub(r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{16}) \*/) \.double \S+",
                        lambda m: "%s .word 0x%08X, 0x%08X" % (m.group(1),
                                                               int.from_bytes(bytes.fromhex(m.group(2)[:8]), "little"),
                                                               int.from_bytes(bytes.fromhex(m.group(2)[8:]), "little")),
                        t2, flags=re.M)
        if t2 != txt:
            open(p, "w", newline="").write(t2)


def split_data(t, seg, unit):
    """The asm/ half of tools/migrate_jtbls.py (steps 1 and 2) for one data segment."""
    data = os.path.join(t.path("asm_root"), "data", seg + ".data.s")
    rodir = os.path.join(ROOT, unit.asm_dir, "rodata")
    if not os.path.exists(data):
        print("%s not there, data split skipped (already done?)" % os.path.relpath(data, ROOT))
        return
    lines = open(data).read().split("\n")
    starts = [i for i, l in enumerate(lines) if l.startswith("nonmatching ")]
    header = lines[:starts[0]]
    blocks = []
    for k, i in enumerate(starts):
        j = starts[k + 1] if k + 1 < len(starts) else len(lines)
        blocks.append((lines[i].split()[1].rstrip(","), lines[i:j]))
    jt = [k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_")]
    if not jt:
        print("%s: no jump tables" % seg)
        return
    first, last = jt[0], jt[-1]
    # A D_XXXXXXXX block among the jump tables is the tail of the table before it that no code
    # refers to, named in config/<program>/symbol_addrs.txt so that it gets its own
    # rodata/<name>.s: the table's function can then be C (gcc emits the table) while an
    # INCLUDE_RODATA after it keeps the tail in place.
    tails = {n for n, _ in blocks[first:last + 1] if re.match(r"D_[0-9A-Fa-f]{8}$", n)}
    if any(not n.startswith("jtbl_") and n not in tails for n, _ in blocks[first:last + 1]):
        sys.exit("%s: non-jtbl data inside the jump table block; aborting" % seg)
    # Target.rodata_cut[seg] = ADDR: the blocks from ADDR up to the jump tables are
    # the code's own read-only data too (strings and literals of functions that sit
    # before the jump tables' functions), so they go to the source side as well:
    # one rodata/<name>.s each, for INCLUDE_RODATA or for C that emits them.
    cut_from = getattr(t, "rodata_cut", {}).get(seg)
    lead = []
    if cut_from is not None:
        addr = lambda n: int(n.split("_")[1], 16) if re.match(r"D_[0-9A-Fa-f]{8}$", n) else None
        lead = [k for k in range(first) if addr(blocks[k][0]) is not None and addr(blocks[k][0]) >= cut_from]
        if lead and lead != list(range(lead[0], first)):
            sys.exit("%s: unnamed data between 0x%X and the jump tables; aborting" % (seg, cut_from))
    name, body = blocks[last]
    cut = next((i for i, l in enumerate(body) if "0xCDCDCDCD" in l), None)
    tail = []
    if cut is not None:
        tail = ["", "/* linker fill after .rdata (0xCD) */"] + body[cut:]
        blocks[last] = (name, body[:cut])
    os.makedirs(rodir, exist_ok=True)
    for name, body in blocks[lead[0]:first] if lead else []:
        open(os.path.join(rodir, name + ".s"), "w").write(
            "\n".join([".align 3", ""] + [l.rstrip() for l in body]).rstrip() + "\n")
    for name, body in blocks[first:last + 1]:
        out = [".align 2" if name in tails else ".align 4", ""]
        for l in body:
            l = l.replace(".word func_0 ", ".word 0x00000000 ").rstrip()
            if l.rstrip().endswith(".word func_0"):
                l = l.replace(".word func_0", ".word 0x00000000")
            out.append(l)
        open(os.path.join(rodir, name + ".s"), "w").write("\n".join(out).rstrip() + "\n")

    def write(path, blks, extra=()):
        text = "\n".join(header) + "\n"
        text += "\n".join("\n".join(b) for _, b in blks)
        text += "\n".join(extra)
        open(path, "w").write(text.rstrip() + "\n")

    d = os.path.dirname(data)
    write(os.path.join(d, seg + "_a.data.s"), blocks[:lead[0] if lead else first])
    write(os.path.join(d, seg + "_b.data.s"), [],
          extra=tail + [""] + ["\n".join(b) for _, b in blocks[last + 1:]])
    os.replace(data, data + ".premigrate")
    print("split %s.data.s into %s_a / %s_b and wrote %d jump tables" % (seg, seg, seg, last - first + 1)
          + (" and %d data blocks from 0x%X" % (len(lead), cut_from) if lead else ""))


def fix_alignment(t):
    """splat starts every function's .s with `.align 3` (gcc aligns functions to 8 bytes).
    Some of boot_elf's core functions (Sony libraries, hand-written code) start on a
    4-byte boundary; for those the .s must say `.align 2`, or the assembler inserts a
    word and every later function moves. frontbin has none."""
    dirs = [u.asm_dir for u in t.units] + [t.handwritten, t.remnants]
    n = 0
    for d in dirs:
        d = os.path.join(ROOT, d)
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            m = re.match(r"func_([0-9A-F]{8})\.s$", f)
            if not m or int(m.group(1), 16) % 8 == 0:
                continue
            p = os.path.join(d, f)
            txt = open(p, newline="").read()
            new = re.sub(r"^\.align 3", ".align 2", txt, count=1, flags=re.M)
            if new != txt:
                open(p, "w", newline="").write(new)
                n += 1
    if n:
        print("%d functions start on a 4-byte boundary: .align 2" % n)


def is_call(x):
    """jal, or a branch that links (bal, bgezal, bltzal and their likely forms): spimdisasm takes
    the target of every such word in a code section for a function start."""
    return x >> 26 == 3 or (x >> 26 == 1 and (x >> 16) & 0x1F in (0x10, 0x11, 0x12, 0x13))


def calls_inside(words, base, spans):
    """The addresses that a call word anywhere in WORDS (the section at BASE) reaches and that lie
    strictly inside one of SPANS ((start, end) pairs, not overlapping), sorted."""
    import bisect
    spans = sorted(spans)
    starts = [a for a, _ in spans]
    out = set()
    for i, x in enumerate(words):
        if not is_call(x):
            continue
        at = base + 4 * i
        if x >> 26 == 3:
            to = ((at + 4) & 0xF0000000) | ((x & 0x3FFFFFF) << 2)
        else:
            off = x & 0xFFFF
            to = at + 4 + 4 * (off - 0x10000 if off & 0x8000 else off)
        k = bisect.bisect_right(starts, to) - 1
        if k >= 0 and spans[k][0] < to < spans[k][1]:
            out.add(to)
    return sorted(out)


def level_inner_calls(t):
    """A level's addresses that a call word reaches inside a row of config/levels/functions.tsv.

    The catalogue decides where a level's functions start. Its rules make every call target a start,
    so such an address exists only where a boundaries.tsv line joins over one: level 39's DNAS
    library keeps encrypted blocks in .text, and a word of a block that decodes as a jal is no
    call. spimdisasm would still end the function there, and the rest of the row would reach the
    build as words without labels (tools/level_tree.py fill_gaps), so a branch into it would not
    assemble. setup_symbols() hands these addresses to splat as branch labels instead."""
    import struct
    import levels
    import level_catalogue as lc
    _, secs = levels.read_elf(rd(t.path("elf")))
    base, size, _, text = secs[-1]
    spans = [(a, a + n) for _, _, n, _, _, places in lc.read_catalogue() for lv, a in places if lv == t.level]
    return calls_inside(struct.unpack("<%dI" % (size // 4), text[:size - size % 4]), base, spans)


def setup_symbols(names, taken, labels=()):
    """The temporary symbol file's lines: every source start as a function, every address of LABELS
    as a branch label (`type:label`): a symbol the user declares as a label is never a function start
    for spimdisasm, though a call word reaches it, and it is written as the local label `.LXXXXXXXX:`
    inside its function, where branches to it can use it."""
    out = ["func_%08X = 0x%08X;\n" % (a, a) for a in sorted(names) if a not in taken]
    out += [".L%08X = 0x%08X; // type:label\n" % (a, a) for a in sorted(labels) if a not in taken and a not in names]
    return "".join(out)


# --- skipping a level's setup when nothing it reads has changed (see the docstring) ---------

STAMP_VERSION = "setup_asm skip 2"
# the tools main() runs after splat
RUN_SCRIPTS = ("fix_reg_names.py", "fix_quadword_ops.py", "fix_short_loops.py", "extract_header.py",
               "trailing_padding.py")


def stamp_dir(t):
    return os.path.join(ROOT, "build", "setup_asm", t.name)


def rel(p):
    return os.path.relpath(p, ROOT).replace(os.sep, "/")


CATALOGUE_NAME = re.compile(r"^func_L\d+_[0-9A-Fa-f]{8}$")


def symbol_names(text):
    """The names a symbol file's text gives (`name = 0x...;`)."""
    return set(re.findall(r"(?m)^\s*([.\w]+)\s*=", text))


def splat_names(body, known=None):
    """What splat reads from a temporary C file (splat/segtypes/common/c.py, scan()): the text of
    its INCLUDE_ASM and INCLUDE_RODATA macros, and the functions it takes for defined in C, less the
    names those macros carry (a C function has its INCLUDE_ASM stub here: marked defined either way).

    splat marks a symbol defined by its name (util/symbols.py, mark_c_funcs_as_defined()), and a
    level's symbols have its own names (func_XXXXXXXX), while a level's C function carries its
    catalogue name (func_LNN_XXXXXXXX) beside the INCLUDE_ASM of its own name. So with KNOWN (the
    names of the symbol files splat is given), a catalogue name that is not one of them is left
    out: no symbol has it, and a function matched or unmatched changes nothing splat reads. (For a
    function that returns a pointer splat's pattern takes the `*` into the name: `*func_LNN_...`.)"""
    from splat.segtypes.common.c import C_FUNC_RE, CommonSegC
    text = CommonSegC.strip_c_comments(body.decode("utf-8", "surrogateescape"))
    macros = []
    for macro in ("INCLUDE_ASM", "INCLUDE_RODATA"):
        found = []
        for pos in CommonSegC.find_all_instances(text, macro + "("):
            found.append(text[pos:CommonSegC.get_close_parenthesis(text, pos + len(macro) + 1)])
        macros.append(sorted(found))
    tokens = {x.strip(" )") for m in macros[0] + macros[1] for x in m.split(",")}
    defined = {m.group(1) for m in C_FUNC_RE.finditer(text)} - tokens
    if known is not None:
        defined = {n for n in defined if n in known or not CATALOGUE_NAME.match(n.lstrip("*"))}
    return macros[0], macros[1], sorted(defined)


def yaml_paths(yml):
    """The symbol files a splat configuration lists."""
    m = re.search(r"symbol_addrs_path:\s*\n((?:[ \t]*-[ \t]*\S+[ \t]*\n)+)", yml)
    return [os.path.join(ROOT, p) for p in (re.findall(r"-\s*(\S+)", m.group(1)) if m else [])]


def setup_key(t, yml, yml2, extra_text, temps, final_src, side):
    """The key of a level's setup: everything main() reads, as the docstring lists it."""
    import stamps
    import version
    h = hashlib.sha1(STAMP_VERSION.encode() + b"\0")
    h.update(("python %s %s\0" % (sys.executable, sys.version)).encode())
    scripts = [os.path.abspath(__file__)] + [os.path.join(ROOT, "tools", s) for s in RUN_SCRIPTS]
    stamps.update(h, stamps.tool_closure(scripts))
    stamps.update(h, stamps.package_files(["splat", "spimdisasm", "rabbitizer"]))
    stamps.update(h, [t.path("elf"), t.path("yaml"), version.cfg("levels", "levels.tsv", v="pal"),
                      os.path.join(ROOT, "config", "gp.tsv"),
                      os.path.join(ROOT, "config", "frontbin", "symbol_addrs.txt"),
                      os.path.join(ROOT, "config", "frontbin", "symbol_addrs_resolved.txt")] + yaml_paths(yml))
    h.update(("%s %s\0" % (t.name, t.sha1)).encode())
    h.update(yml2.encode() + b"\0" + extra_text.encode() + b"\0")
    known = symbol_names(extra_text)
    for sf in yaml_paths(yml):
        if os.path.isfile(sf):
            with open(sf, errors="replace") as f:
                known |= symbol_names(f.read())
    for p, body in temps:
        h.update(("%s\0%r\0" % (rel(p), splat_names(body, known))).encode())
    h.update(repr(sorted(final_src)).encode() + b"\0" + repr(side).encode())
    return h.hexdigest()


def output_files(t, yml):
    """The files a level's setup writes, but the splat side files and the tree's sources: its asm/
    folder, splat's linker script and assets, nohalt.py."""
    import stamps
    out = []
    for p in asm_paths(t):
        out += stamps.files_under(p)
    ld = yaml_option(yml, "ld_script_path", None)
    if ld:
        out.append(os.path.join(ROOT, ld))
    assets = yaml_option(yml, "asset_path", None)
    if assets:
        out += stamps.files_under(os.path.join(ROOT, assets))
    out.append(os.path.join(ROOT, t.build_dir, "nohalt.py"))
    return [p for p in out if os.path.isfile(p)]


def padding_cuts(read=None):
    """[(function, folder, words)] whose trailing nops trailing_padding.py --apply cuts, for the
    current tree (READ: where the .s files are read from)."""
    import trailing_padding as tp
    return sorted([n, f, x] for n, f, x, *_ in tp.scan(srcfiles.read_all(ROOT), read))


def write_stamp(t, key, yml, side, from_splat):
    """After a full setup: the copy of its outputs, and stamp.json."""
    import stamps
    import zipfile
    d = stamp_dir(t)
    tmp = d + ".tmp"
    shutil.rmtree(tmp, ignore_errors=True)
    os.makedirs(tmp)
    files = output_files(t, yml) + [os.path.join(ROOT, s) for s in side if s in from_splat
                                    and os.path.isfile(os.path.join(ROOT, s))]
    manifest = []
    with zipfile.ZipFile(os.path.join(tmp, "outputs.zip"), "w", zipfile.ZIP_DEFLATED, compresslevel=1) as z:
        for p in files:
            z.write(p, rel(p))
            manifest.append([rel(p), stamps.file_sha1(p)])
    meta = {"key": key, "cuts": padding_cuts(), "from_splat": sorted(from_splat), "files": manifest}
    with open(os.path.join(tmp, "stamp.json"), "w", newline="\n") as f:
        json.dump(meta, f, indent=0)
    shutil.rmtree(d, ignore_errors=True)
    os.replace(tmp, d)


def skip_reason(meta, key, cuts, side_missing):
    """None when a level's setup can be skipped: its stamp META is for KEY, the CUTS
    (padding_cuts() against the stored files) are the stored ones and every splat side file in
    SIDE_MISSING (missing now) was written by that setup; else why not."""
    if meta is None:
        return "no stored setup"
    if meta.get("key") != key:
        return "its inputs changed"
    if cuts != meta.get("cuts"):
        return "the functions whose trailing nops it cuts changed"
    lost = [s for s in side_missing if s not in meta.get("from_splat", [])]
    if lost:
        return "%s is missing" % ", ".join(lost)
    return None


def try_skip(t, key, yml, side):
    """Put back a level's stored setup when nothing it reads has changed. True when done."""
    import stamps
    import zipfile
    d = stamp_dir(t)
    try:
        meta = json.load(open(os.path.join(d, "stamp.json")))
        z = zipfile.ZipFile(os.path.join(d, "outputs.zip"))
    except (OSError, ValueError, zipfile.BadZipFile):
        meta, z = None, None
    why = skip_reason(meta, key, None, []) if meta is None or meta.get("key") != key else None
    if why is None:
        try:
            cuts = padding_cuts(lambda p: z.read(rel(p)).decode("utf-8", "replace"))
        except KeyError:
            cuts = None
        why = skip_reason(meta, key, cuts, [s for s in side if not os.path.exists(os.path.join(ROOT, s))])
    if why:
        print("full setup: %s" % why, flush=True)
        return False
    want = dict(meta["files"])
    put, gone = 0, 0
    for r, sha in sorted(want.items()):
        p = os.path.join(ROOT, r)
        if stamps.file_sha1(p) != sha:
            os.makedirs(os.path.dirname(p), exist_ok=True)
            with open(p, "wb") as f:
                f.write(z.read(r))
            if stamps.file_sha1(p) != sha:
                raise OSError("%s: the stored copy is damaged" % r)
            put += 1
    for root in asm_paths(t):
        for p in stamps.files_under(root):
            if rel(p) not in want:
                os.remove(p)
                gone += 1
    print("setup skipped: nothing it reads has changed (%s); %d of its %d files put back, %d removed"
          % (os.path.relpath(d, ROOT), put, len(want), gone), flush=True)
    run(sys.executable, "tools/trailing_padding.py", "--apply", "--target", t.name)
    return True


def main():
    # --force: the full setup even when nothing it reads has changed (a level's; see the docstring)
    force = "--force" in sys.argv
    t = targets.from_argv(allow_all="elf")
    elf = t.path("elf")
    if not os.path.exists(elf):
        sys.exit("%s not found (put your own copy in baserom/; see docs/wiki/Setup.md, step 2)" % t.elf)
    h = hashlib.sha1(rd(elf)).hexdigest()
    if h != t.sha1:
        sys.exit("%s has sha1 %s, expected %s (PAL, SCES-52456)" % (t.elf, h, t.sha1))

    yml = open(t.path("yaml")).read()
    side = [yaml_option(yml, "undefined_funcs_auto_path", "undefined_funcs_auto.txt"),
            yaml_option(yml, "undefined_syms_auto_path", "undefined_syms_auto.txt")]
    saved = {n: rd(os.path.join(ROOT, n)) for n in side if os.path.exists(os.path.join(ROOT, n))}

    files = srcfiles.read_file_list()
    temps, final_src, names, c_count = [], [], set(), 0
    for u in t.units:
        text = srcfiles.read_all(ROOT, [(r, s) for r, s in files if u.contains(s)]).encode("utf-8", "surrogateescape")
        final_src += re.findall(rb'(?:ASM_FUNC|LINKER_REMNANT)\("([^"]+)",\s*(func_[0-9A-Fa-f]{8})\)', text)
        # Functions already written as C have no INCLUDE_ASM, so splat would skip them.
        # localdecomp builds its function list (and the progress numbers) from the .s
        # files, so list them in the temporary file too: every function gets its .s.
        have = set(re.findall(rb'(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]+",\s*(func_[0-9A-Fa-f]{8})\)', text))
        c_names = set(re.findall(rb"localdecomp:start (func_[0-9A-F]{8})", text))
        c_names |= set(re.findall(rb"(?m)^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]{8})\s*\([^;{]*\)[^;{]*\{", text))
        c_names = {n for n in c_names - have if u.contains(int(n[5:], 16))}
        c_count += len(c_names)
        stubs = b"".join(b'\nINCLUDE_ASM("%s", %s);' % (u.asm_dir.encode(), n) for n in sorted(c_names)) + b"\n"
        # Function boundaries: the names in the sources (func_<address>) are the project's
        # units, and every .s must end exactly where the next one starts. A name that is
        # only called, declared extern or mentioned in a comment isn't a boundary: it can
        # be another target's function or a label inside a function.
        names |= {int(n[5:], 16) for n in have | c_names if u.contains(int(n[5:], 16))}
        body = re.sub(rb'(?:ASM_FUNC|LINKER_REMNANT)\("[^"]+",', b'INCLUDE_ASM("%s",' % u.asm_dir.encode(), text)
        temps.append((os.path.join(ROOT, t.splat_src, u.name + ".c"), body + stubs))
    print("%d functions are already C; adding temporary stubs so each gets a .s" % c_count)

    m = re.search(r"symbol_addrs_path:\s*\n((?:[ \t]*-[ \t]*\S+[ \t]*\n)+)", yml)
    taken = set()
    for sf in (re.findall(r"-\s*(\S+)", m.group(1)) if m else []):
        p = os.path.join(ROOT, sf)
        if os.path.exists(p):
            taken |= {int(a, 16) for a in re.findall(rb"=\s*0x0*([0-9A-Fa-f]+)", rd(p))}
    # Hand splat those addresses as function symbols through a temporary extra symbol
    # file and a temporary yaml.
    extra = os.path.join(ROOT, "symbol_addrs_setup.txt" if t.name == "frontbin" else "symbol_addrs_setup_%s.txt" % t.name)
    # next to the real yaml, so its base_path (the repo root, relative to the yaml) holds
    tmp_yaml = os.path.join(os.path.dirname(t.path("yaml")), "%s.setup.yaml" % t.name)
    labels = level_inner_calls(t) if targets.is_level(t) else []
    if labels:
        print("%d addresses a call word reaches inside a catalogue row: branch labels, not function starts"
              % len(labels))
    extra_text = setup_symbols(names, taken, labels)
    yml2 = re.sub(r"(symbol_addrs_path:\s*\n(\s*)- \S+)", r"\1\n\2- %s" % os.path.basename(extra), yml, count=1)
    key = None
    if targets.is_level(t):
        key = setup_key(t, yml, yml2, extra_text, temps, final_src, side)
        if not force:
            try:
                if try_skip(t, key, yml, side):
                    return
            except (OSError, KeyError, ValueError) as e:
                print("full setup: the stored setup cannot be put back (%s)" % e, flush=True)
        shutil.rmtree(stamp_dir(t), ignore_errors=True)
    from_splat = [n for n in side if n not in saved]
    with open(extra, "w") as f:
        f.write(extra_text)
    open(tmp_yaml, "w").write(yml2)
    for p, _ in temps:
        if os.path.exists(p):
            sys.exit("%s exists; the sources live in per-file folders now (remove the stale file first)"
                     % os.path.relpath(p, ROOT))
    clear_asm(t)
    try:
        for p, body in temps:
            os.makedirs(os.path.dirname(p), exist_ok=True)
            wr(p, body)
        if targets.is_level(t):
            # A level's .text holds data among its code (the multiplayer menu's most of all), which
            # makes spimdisasm's "halt function search" stop splitting functions; with the
            # function starts given, it is not needed (tools/objdiff/gen_level_targets.py, NOHALT).
            nohalt = os.path.join(ROOT, t.build_dir, "nohalt.py")
            sys.path.insert(0, os.path.join(ROOT, "tools", "objdiff"))
            from gen_level_targets import NOHALT
            open(nohalt, "w").write(NOHALT)
            run(sys.executable, nohalt, "split", os.path.relpath(tmp_yaml, ROOT))
        else:
            run(sys.executable, "-m", "splat", "split", os.path.relpath(tmp_yaml, ROOT))
    finally:
        for p, _ in temps:
            if os.path.exists(p):
                os.remove(p)
        for n, b in saved.items():
            wr(os.path.join(ROOT, n), b)
        for f in (extra, tmp_yaml):
            if os.path.exists(f):
                os.remove(f)

    py = sys.executable
    paths = [os.path.relpath(p, ROOT) for p in asm_paths(t)]
    run(py, "tools/fix_reg_names.py", "--gp-value", "0x%08X" % t.gp, *paths)
    run(py, "tools/fix_quadword_ops.py", "--gp-value", "0x%08X" % t.gp, *paths)
    run(py, "tools/fix_short_loops.py", *paths)
    run(py, "tools/extract_header.py", "--target", t.name)

    n = 0
    for folder, func in final_src:
        folder, func = folder.decode(), func.decode()
        unit = t.unit_for(int(func[5:], 16))
        os.makedirs(os.path.join(ROOT, folder), exist_ok=True)
        s = os.path.join(ROOT, unit.asm_dir, func + ".s")
        if not os.path.exists(s):
            sys.exit("missing %s (did splat finish?)" % s)
        dest = os.path.join(ROOT, folder, func + ".s")
        shutil.move(s, dest)
        # splat's `nonmatching` line defines NAME.NON_MATCHING, which makes objdiff (and
        # decomp.dev) count the function as not matching. This .s is final source, so turn
        # that line into a comment, as tools/migrate_asm_sources.py did.
        txt = open(dest, newline="").read()
        txt = re.sub(r"^nonmatching (func_[0-9A-Fa-f]{8})(, *0x[0-9A-Fa-f]+)?[ \t]*(\r?)$",
                     r"/* nonmatching \1\2 -- marker removed: final source */\3", txt, flags=re.M)
        open(dest, "w", newline="").write(txt)
        n += 1
    print("moved %d ASM_FUNC / LINKER_REMNANT sources" % n)

    fix_alignment(t)
    run(py, "tools/trailing_padding.py", "--apply", "--target", t.name)
    normalize_data_words(t)
    for seg, unit in t.jtbl_segments.items():
        split_data(t, seg, t.unit(unit))
    if key is not None:
        write_stamp(t, key, yml, side, from_splat)
    print("done. Now build: make (Windows) or python3 tools/build.py%s (Linux/macOS)."
          % ("" if t.name == targets.DEFAULT else " --target " + t.name))


if __name__ == "__main__":
    main()
