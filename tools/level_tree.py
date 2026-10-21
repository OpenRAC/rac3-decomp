#!/usr/bin/env python3
"""level_tree.py: the level code's sources, and each level's build tree made from them.

    python3 tools/levels.py tree --bootstrap   # src/levels/ and config/levels/text_parts.txt (one-time)
    python3 tools/levels.py tree 01 [16 ...]   # build/levels/<NN_name>/ for those levels
    python3 tools/levels.py tree all
    python3 tools/levels.py tree --fill NN     # after tools/setup_asm.py --target level_NN

## src/levels/ (committed)

As in rac1-decomp and rac2-decomp, every distinct level function of config/levels/functions.tsv
is in src/levels/ once, under its catalogue name:

  - src/levels/shared/LNN_XXXXXXXX.c: the functions in two or more levels (kind `shared`), in the
    order of their canonical level;
  - src/levels/<NN_name>/LNN_XXXXXXXX.c: those of one level only (kind `level`);
  - a level's copy of a front-end function (kind `frontbin` or `boot_elf`) has no source here:
    it is that function, counted once with its program.

A file runs while its functions follow each other in their canonical level, with nothing of
another kind between them, up to about 32 KB; it starts at a function that is 8-aligned in every
level that has it (an object's .text is 8-aligned). The boundaries are estimates, as frontbin's
are, until C shows them. config/levels/text_parts.txt holds each file's flags, one line per file.

## build/levels/<NN_name>/ (generated)

A level's build is a target like frontbin's (tools/targets.py, level_NN), whose sources are made
here: the level's functions in address order, each from the src/levels/ file that holds it,
with its catalogue name replaced by its address in this level (func_XXXXXXXX), as
tools/build_text.py and splat name functions. A run of functions from one source file becomes
one file; a run that starts on a 4-mod-8 address joins the run before it (only assembly is
joined so: a run with C must start 8-aligned). The tree, its file list (src_files.txt), flags
(text_parts.txt) and tables are generated, never committed.

## C in level code

A function written as C stays in its src/levels/ file between `/* localdecomp:start
func_LNN_XXXXXXXX */` and `/* localdecomp:end func_LNN_XXXXXXXX */`, with its catalogue name, and
is compiled into every level that has it. A run of functions from a file with C becomes a file
of its own in each level: the source file's prelude, the declarations of its functions this
run does not have, then the run's functions in this level's order (C as written, the markers
renamed to this level's address). A C function followed by more zero words than gcc's
alignment gets TEXT_PADDING(N) here, per level. Names of front-end functions (catalogue kind
`frontbin` or `boot_elf`) are written `fe_func_XXXXXXXX` in the tree: in a level they are the
level's copy, somewhere else. What the names the C uses stand for in each level is read from
the level's own bytes after compiling (tools/level_symbols.py).
"""
import collections
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import level_catalogue as lc  # noqa: E402
import levels  # noqa: E402

SRC = os.path.join(ROOT, "src", "levels")
PARTS = os.path.join(ROOT, "config", "levels", "text_parts.txt")
ASM = "asm/levels"            # the INCLUDE_ASM folder in src/levels/; a level's build puts its own there
BASE_FLAGS = "-O2 -G8 -fopt-stack -mno-check-zero-division"
FILE_BYTES = 0x8000
NL = "\r\n"                   # the repo's sources are CRLF
MARKER = re.compile(r'^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]*",\s*(func_\w+)\);', re.M)


def stem(name):
    return name[5:]          # func_L01_002F9520 -> L01_002F9520


def bootstrap():
    rows = lc.read_catalogue()
    for d in os.listdir(SRC) if os.path.isdir(SRC) else []:
        p = os.path.join(SRC, d)
        for f in os.listdir(p):
            if f.endswith(".c") and "localdecomp:start" in open(os.path.join(p, f), errors="replace").read():
                sys.exit("%s has C in it; refusing to rebuild src/levels/" % os.path.join(p, f))
    if os.path.isdir(SRC):
        shutil.rmtree(SRC)
    # every level's places in address order, to see what follows what
    by_level = collections.defaultdict(list)
    for r in rows:
        for n, a in r[5]:
            by_level[n].append((a, r))
    nxt = {}
    for n, ps in by_level.items():
        ps.sort(key=lambda p: p[0])
        for (a, r), (b, s) in zip(ps, ps[1:]):
            nxt[(n, r[0])] = s[0]
    files = []                                  # (folder, [rows])
    cur, cur_bytes, folder = None, 0, None
    own = [r for r in rows if r[1] in ("shared", "level")]
    own.sort(key=lambda r: (r[5][0][0], r[5][0][1]))
    for r in own:
        n0, a0 = r[5][0]
        f = "shared" if r[1] == "shared" else levels.dirname(n0)
        aligned = all(a % 8 == 0 for _, a in r[5])
        same = cur is not None and folder == f and cur[-1][5][0][0] == n0
        follows = same and nxt.get((n0, cur[-1][0])) == r[0]
        if follows and (cur_bytes + r[2] <= FILE_BYTES or not aligned) or same and not aligned:
            cur.append(r)
            cur_bytes += r[2]
            continue
        cur, cur_bytes, folder = [r], r[2], f
        files.append((f, cur))
    lines = ["# Compiler flags of the level code's source files (src/levels/), one line per file: the",
             "# file and its flags. Estimates (tools/level_tree.py) until a file has C. No per-function",
             "# flags (docs/BUILD_FIDELITY.md)."]
    for f, rs in files:
        d = os.path.join(SRC, f)
        os.makedirs(d, exist_ok=True)
        rel = "src/levels/%s/%s.c" % (f, stem(rs[0][0]))
        body = ['#include "common.h"', ""]
        for r in rs:
            kind = "LINKER_REMNANT" if r[4] else "INCLUDE_ASM"
            body += ['%s("%s", %s);' % (kind, ASM, r[0]), ""]
        open(os.path.join(ROOT, rel), "w", newline="").write(NL.join(body))
        lines.append("%s\t%s" % (rel, BASE_FLAGS))
    open(PARTS, "w", newline="\n").write("\n".join(lines) + "\n")
    print("src/levels/: %d files, %d functions (%d shared, %d level-specific)" % (
        len(files), len(own), sum(1 for r in own if r[1] == "shared"), sum(1 for r in own if r[1] == "level")))


def read_parts():
    out = {}
    for line in open(PARTS):
        if line.startswith("#") or not line.strip():
            continue
        rel, flags = line.rstrip("\n").split("\t", 1)
        out[rel] = flags
    return out


BLOCK = re.compile(
    r"(/\* localdecomp:start (func_\w+) \*/.*?/\* localdecomp:end \2 \*/[^\n]*\n?)"
    r"|(^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(\"[^\"]*\",\s*(func_\w+)\);[^\n]*\n?)", re.S | re.M)
FRONT_END = re.compile(r"\b(func_[0-9A-F]{8})(?:_[A-Za-z0-9]+)*\b")


def parse_source(rel):
    """(prelude, [(name, kind, text)]) of a src/levels/ file: the text before its first function,
    then each function's block (kind C, INCLUDE_ASM, ASM_FUNC or LINKER_REMNANT) with the free
    text before it; the text after the last block goes with it."""
    text = open(os.path.join(ROOT, rel), newline="").read()
    prelude, out, pos = None, [], 0
    for m in BLOCK.finditer(text):
        free = text[pos:m.start()]
        if prelude is None:
            prelude, free = free, ""
        if m.group(2):
            out.append([m.group(2), "C", free + m.group(1)])
        else:
            out.append([m.group(5), m.group(4), free + m.group(3)])
        pos = m.end()
    if out:
        out[-1][2] += text[pos:]
    return (prelude if prelude is not None else text), [tuple(c) for c in out]


def front_end_names(rows):
    """The catalogue's front-end functions (kind frontbin or boot_elf): in a level their names
    stand for the level's copy, which is somewhere else."""
    return {r[0] for r in rows if r[1] in ("frontbin", "boot_elf")}


def level_names(text, fe):
    """C text as a level's tree has it: front-end function names become fe_func_XXXXXXXX."""
    return FRONT_END.sub(lambda m: "fe_" + m.group(0) if m.group(1) in fe else m.group(0), text)


def function_context(name, own_src="", rows=None):
    """(flags, context): the flags of the src/levels/ file that holds `name` and what that file
    puts in front of the function in a level's tree (its prelude and the declarations of the
    functions before it), for tools/check.py."""
    import srcfiles as sf
    entry = source_entries().get(name)
    if entry is None:
        return None, ""
    rel = entry[0]
    prelude, chunks = parse_source(rel)
    out = [prelude]
    for n, _, body in chunks:
        if n == name:
            break
        decl = sf.declarations_only(body)
        if decl:
            out.append(decl + "\n")
    fe = front_end_names(rows or lc.read_catalogue())
    return read_parts().get(rel, BASE_FLAGS).split(), level_names("".join(out), fe)


def source_entries():
    """{catalogue name: (file, kind, chunk)} from src/levels/: kind INCLUDE_ASM, ASM_FUNC,
    LINKER_REMNANT or C."""
    out = {}
    for d, _, fs in os.walk(SRC):
        for f in sorted(fs):
            if not f.endswith(".c"):
                continue
            rel = os.path.relpath(os.path.join(d, f), ROOT).replace(os.sep, "/")
            text = open(os.path.join(d, f), errors="replace").read()
            for m in MARKER.finditer(text):
                out.setdefault(m.group(2), (rel, m.group(1)))
            for name in re.findall(r"localdecomp:start (func_\w+)", text):
                out[name] = (rel, "C")
    return out


def build_tree(number, rows=None, sources=None, parts=None):
    import targets
    rows = rows or lc.read_catalogue()
    sources = sources if sources is not None else source_entries()
    parts = parts if parts is not None else read_parts()
    d = levels.dirname(number)
    b = os.path.join(ROOT, "build", "levels", d)
    src = os.path.join(b, "src")
    if os.path.isdir(src):
        shutil.rmtree(src)
    os.makedirs(src)
    places = sorted((a, r) for r in rows for n, a in r[5] if n == number)
    text_end = targets.LEVELS[levels.target_name(number)].units[0].end
    asm_text = "asm/levels/%s/nonmatchings/text" % d
    remnants = "asm/levels/%s/remnants" % d
    with_c = {rel for rel, kind in sources.values() if kind == "C"}
    runs = []                                 # [owner file, start, [(address, kind, row, next address)]]
    for i, (a, r) in enumerate(places):
        nxt = places[i + 1][0] if i + 1 < len(places) else text_end
        if r[1] in ("frontbin", "boot_elf"):
            owner, kind = "front end", "LINKER_REMNANT" if r[4] else "INCLUDE_ASM"
        else:
            if r[0] not in sources:
                sys.exit("%s (level %02d, 0x%08X) is in the catalogue but not in src/levels/" % (r[0], number, a))
            owner, kind = sources[r[0]]
        if runs and (runs[-1][0] == owner or a % 8):
            if kind == "C" and runs[-1][0] != owner:
                sys.exit("%s has C but starts on a 4-mod-8 address in level %02d (0x%08X), after a function "
                         "of another file: C starts 8-aligned" % (r[0], number, a))
            runs[-1][2].append((a, kind, r, nxt))
        else:
            runs.append([owner, a, [(a, kind, r, nxt)]])
    fe = front_end_names(rows) if with_c else set()
    parsed = {rel: parse_source(rel) for rel in with_c}
    files, flags = [], []
    for owner, start, fns in runs:
        rel = "build/levels/%s/src/%06X.c" % (d, start)
        if owner in with_c:
            text = c_run(owner, parsed[owner], fns, fe, number, asm_text, remnants)
        else:
            lines = ['#include "common.h"', ""]
            for a, kind, _, _ in fns:
                folder = remnants if kind == "LINKER_REMNANT" else asm_text
                lines += ['%s("%s", func_%08X);' % (kind, folder, a), ""]
            text = NL.join(lines)
        open(os.path.join(ROOT, rel), "w", newline="").write(text)
        files.append("%s %08X" % (rel, start))
        flags.append("0x%08X     %s" % (start, parts.get(owner, BASE_FLAGS)))
    head = "# %s's source files in link order (tools/level_tree.py; generated, never committed)." % d
    open(os.path.join(b, "src_files.txt"), "w", newline="").write(NL.join([head] + files) + NL)
    open(os.path.join(b, "text_parts.txt"), "w", newline="").write(
        NL.join(["# %s's flags per source file (tools/level_tree.py, from config/levels/text_parts.txt)." % d] + flags) + NL)
    for name in ("divs_nops.txt", "sq_ra_funcs.txt", "localdecomp_flags.txt"):
        if not os.path.exists(os.path.join(b, name)):
            open(os.path.join(b, name), "w").write("")
    if not os.path.exists(os.path.join(b, "symbol_addrs.txt")):
        open(os.path.join(b, "symbol_addrs.txt"), "w", newline="").write("// %s: named symbols for splat%s" % (d, NL))
    return len(files), len(places)


def code_size(number, address, size):
    """`size` (the catalogue's, without the zero words after the function) plus the last jump's
    delay slot when that is a zero word (a nop): gcc emits it as part of the function."""
    global _RETAIL
    if number not in _RETAIL:
        import level_symbols
        import targets
        _RETAIL[number] = level_symbols.retail_text(targets.get(levels.target_name(number)))
    base, text = _RETAIL[number]
    at = address - base + size - 4
    if 0 <= at and at + 8 <= len(text):
        w = int.from_bytes(text[at:at + 4], "little")
        op = w >> 26
        jump = (op == 0 and w & 0x3F in (8, 9)) or op in (1, 2, 3, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17)
        if jump and text[at + 4:at + 8] == b"\0\0\0\0":
            return size + 4
    return size


_RETAIL = {}


def text_padding(address, size, nxt):
    """N of TEXT_PADDING(N) after a C function at `address` of `size` bytes when the next
    function is at `nxt`: the zero words between them that gcc's .align 3 does not give."""
    end = address + size
    aligned = (end + 7) & ~7 if nxt % 8 == 0 else end
    return max(0, (nxt - aligned) // 4)


def c_run(owner, source, fns, fe, number, asm_text, remnants):
    """A level's file for a run of functions from `owner`, a src/levels/ file with C: its prelude,
    the declarations of its functions this run does not have, then the run's functions in the
    level's order, with this level's names."""
    import srcfiles as sf
    prelude, chunks = source
    index = {name: i for i, (name, _, _) in enumerate(chunks)}
    mine = {r[0] for _, _, r, _ in fns}
    last = max(index.get(r[0], -1) for _, _, r, _ in fns)
    out = [level_names(prelude.rstrip("\r\n"), fe) + NL + NL]
    decl = [sf.declarations_only(body) for name, _, body in chunks[:last + 1] if name not in mine]
    decl = [x for x in decl if x]
    if decl:
        out.append("/* declarations of %s's other functions */%s%s%s%s" % (
            owner, NL, level_names(NL.join(x.replace("\n", NL) for x in decl), fe), NL, NL))
    for a, kind, r, nxt in fns:
        if r[0] in index and kind == "C":
            body = level_names(chunks[index[r[0]]][2], fe)
            body = body.replace("localdecomp:start %s " % r[0], "localdecomp:start func_%08X " % a)
            body = body.replace("localdecomp:end %s " % r[0], "localdecomp:end func_%08X " % a)
            out.append(body.rstrip("\r\n") + NL)
            pad = text_padding(a, code_size(number, a, r[2]), nxt)
            if pad:
                out.append("TEXT_PADDING(%d);  /* level %02d (tools/level_tree.py) */%s" % (pad, number, NL))
            out.append(NL)
        else:
            if r[0] in index:
                free = BLOCK.split(chunks[index[r[0]]][2])[0]
                if free.strip():
                    out.append(level_names(free, fe))
            folder = remnants if kind == "LINKER_REMNANT" else asm_text
            out.append('%s("%s", func_%08X);%s%s' % (kind, folder, a, NL, NL))
    return "".join(out)


ADDR_LINE = re.compile(r"^\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/")
WORD_LINE = re.compile(r"^\s*\.word\s")
SIZE_LINE = re.compile(r"(nonmatching (func_[0-9A-F]{8}), )0x([0-9A-Fa-f]+)")


def covered_end(text):
    """One past the last byte a function's .s emits: its instruction lines carry their address;
    a `.word` line without one (tools/fix_quadword_ops.py) is the next word."""
    end = None
    for line in text.splitlines():
        m = ADDR_LINE.match(line)
        if m:
            end = int(m.group(1), 16) + 4
        elif WORD_LINE.match(line) and end is not None:
            end += 4
    return end


# opcodes the R5900 does not have, which data decodes to; the assembler refuses or asserts on them
# (rac3-uya-decomp's tools/objdiff/gen_level_targets.py writes them as words the same way)
NOT_EE = {"sdc1", "ldc1", "sdc2", "ldc2", "lwc2", "swc2", "sc", "ll", "lld", "scd"}
INSN_LINE = re.compile(r"^(\s*/\*\s*[0-9A-F]+\s+[0-9A-F]{8}\s+([0-9A-F]{8})\s*\*/)( +)([a-z][\w.]*)(.*)$")
LOCAL_LABEL = re.compile(r"^\s*(\.L[0-9A-F]+):", re.M)


def raw_branches(text):
    """Data among a level's code (the multiplayer menu has much) disassembles to branches that
    leave their function, jumps in delay slots and opcodes the R5900 lacks, which the assembler
    refuses or asserts on.
    Such an instruction is written as the word retail has (rac1-decomp writes branches out of a
    function the same way). Returns the new text and how many lines changed."""
    defined = set(LOCAL_LABEL.findall(text))
    out, n = [], 0
    for line in text.split("\n"):
        m = INSN_LINE.match(line.rstrip("\r"))
        if m:
            op, args, slot = m.group(4), m.group(5), len(m.group(3)) > 2
            branch = op[0] in "bj" and op not in ("break",)
            away = any(l not in defined for l in re.findall(r"\.L[0-9A-F]+", args))
            if branch and (slot or away) or op in NOT_EE:
                word = int.from_bytes(bytes.fromhex(m.group(2)), "little")
                cr = "\r" if line.endswith("\r") else ""
                line = "%s  .word 0x%08X /* %s%s */%s" % (m.group(1), word, op, args.replace("*/", ""), cr)
                n += 1
        out.append(line)
    return "\n".join(out), n


def fill_gaps(number):
    """After tools/setup_asm.py: where splat cut a function's .s short of the next function (it
    splits hand-written code and the linker's 0xCDCDCDCD fill on its own), the missing words go at
    the end of that .s as `.word`s, so the function ends where the catalogue says. Words that
    are all zero are left to TEXT_PADDING (tools/trailing_padding.py)."""
    import struct
    import targets
    t = targets.LEVELS[levels.target_name(number)]
    data = open(t.path("elf"), "rb").read()
    _, secs = levels.read_elf(data)
    base, size, _, text = secs[-1]
    # every function of the tree, C too (a C function's place ends the .s before it)
    rx = re.compile(r'(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("([^"]+)",\s*(func_[0-9A-F]{8})\);'
                    r'|/\* localdecomp:start ()(func_[0-9A-F]{8}) \*/')
    order = []
    for line in open(t.path("files")):
        if line.startswith("#") or not line.strip():
            continue
        rel = line.split()[0]
        order += [(m[0] or m[2], m[1] or m[3]) for m in rx.findall(open(os.path.join(ROOT, rel)).read())]
    fixed, raw = 0, 0
    for i, (folder, name) in enumerate(order):
        if not folder:
            continue
        nxt = int(order[i + 1][1][5:], 16) if i + 1 < len(order) else base + size
        path = os.path.join(ROOT, folder, name + ".s")
        src = open(path, newline="").read()
        src2, k = raw_branches(src)
        if k:
            open(path, "w", newline="").write(src2)
            src, raw = src2, raw + k
        end = covered_end(src)
        if end is None or end >= nxt:
            continue
        gap = text[end - base:nxt - base]
        ws = struct.unpack("<%dI" % (len(gap) // 4), gap)
        if not any(ws):
            continue
        nl = "\r\n" if "\r\n" in src else "\n"
        src = src.rstrip("\r\n") + nl + "    /* the rest up to the next function (tools/level_tree.py fill_gaps) */" + nl
        src += "".join("    /* %06X %08X %08X */ .word 0x%08X%s" % (0, end + 4 * k, w, w, nl) for k, w in enumerate(ws))
        start = int(name[5:], 16)
        src = SIZE_LINE.sub(lambda m: m.group(1) + "0x%X" % (nxt - start), src, count=1)
        open(path, "w", newline="").write(src)
        fixed += 1
    print("%s: %d functions' assembly completed up to the next function, %d branches written as words"
          % (levels.dirname(number), fixed, raw))


def main(argv):
    if argv[:1] == ["--bootstrap"]:
        bootstrap()
        return
    if argv[:1] == ["--fill"]:
        for n in (sorted(levels.NAMES) if argv[1:] == ["all"] else [int(x) for x in argv[1:]]):
            fill_gaps(n)
        return
    if not argv:
        sys.exit(__doc__)
    numbers = sorted(levels.NAMES) if argv == ["all"] else [int(x) for x in argv]
    rows, sources, parts = lc.read_catalogue(), source_entries(), read_parts()
    for n in numbers:
        nf, np = build_tree(n, rows, sources, parts)
        print("%s: %d functions in %d files" % (levels.dirname(n), np, nf))


if __name__ == "__main__":
    main(sys.argv[1:])
