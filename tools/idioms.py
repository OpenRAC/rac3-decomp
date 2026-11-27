#!/usr/bin/env python3
"""idioms.py: the idiom cookbook, which C gives which assembly shape, mined from the matched C.

    python3 tools/idioms.py build [-j N] [--shard I/N] [--compile-only] [--files REL ...]
    python3 tools/idioms.py mine                      # build/idioms/raw/ -> build/idioms/db.json.gz
    python3 tools/idioms.py query FILE.s|FUNCTION [--top 3]
    python3 tools/idioms.py query --snippet "sltu $2,$4,$5; movn $2,$6,$3"
    python3 tools/idioms.py report [--out docs/matching/IDIOMS.md]

Every function of src/ that is C (a localdecomp block) and matches retail has already been worked
out once; this tool keeps what was learnt. `build` compiles each source file the way the check
does (its own flags, tools/asm_filter.py between gcc -S and the assembler) with -g added, turns
gcc's stabs line markers (`.stabn 68,0,LINE,$LMn`) into labels the object keeps, and so knows for
every instruction the C line (or the line of an inline helper in a header, include/vu0.h) it came
from. A function is used only when its -g object equals retail word for word outside relocated
fields (jal targets, %hi/%lo and $gp offsets): -g itself leaves almost every function's code alone,
and a function it does change is skipped, never mined. Sony's library files (@ee29, @ee296, @eeas)
are not compiled. One JSON file per source file goes to build/idioms/raw/ (`--compile-only` stops
there: `build` on several machines with --shard, then copy raw/ together and run `mine`).

`mine` cuts each function into fragments: the instructions of one C statement (a line, with the
lines a statement continues on while its parentheses are open) in retail's order, and for code
inlined from a header the instructions of one helper call. Each fragment is normalised: on the
assembly side registers become classes numbered in order of appearance (t1, t2, a1, s1, v1, f*,
vf*; $zero, $sp, $gp, $ra stay), immediates go into buckets (0, 1, -1, small, power of two,
16-bit, negative), relocated operands become %hi/%lo/%gp and F (a jal target), branches Lf/Lb
(forward, backward); on the C side identifiers become v (a local or parameter), G (a D_ global),
F (a called function), m (a member), numbers 0, 1, N or Nf, and keywords, types, operators and
the shape of the statement stay. A shape is a normalised instruction sequence; for each one the
database keeps the C forms that gave it, with counts and up to three real examples (function,
file, line, the C as written). Shapes are also sorted into families, the patterns matching keeps
running into (FAMILIES below: movn/movz, sltu/sltiu, branch-likely delay slots, $gp against
lui/addiu, data at an offset, div.s padding, the mtc1 hazard nop, VU0, jump tables, cross-jumped
tails, 128-bit copies, float arguments, loops, inline helpers, ...).

`query` reads an unmatched function (its asm/ .s file, or its name, or a snippet), cuts it into
blocks at labels and after branches, and for each block lists the known shapes that cover it
(longest first) with the C that produced them, plus the families its instructions belong to.
`report` writes docs/matching/IDIOMS.md, the human-readable cookbook (committed).

Needs the toolchain as tools/check.py does (UYA_TOOLCHAIN, UYA_RUNNER) and the retail programs in
baserom/ for `build`; `mine`, `query` and `report` need only build/idioms/.
"""
import argparse
import collections
import gzip
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

OUT = os.path.join(ROOT, "build", "idioms")
RAW = os.path.join(OUT, "raw")
DB = os.path.join(OUT, "db.json.gz")
REPORT = os.path.join(ROOT, "docs", "matching", "IDIOMS.md")
CORE = ("frontbin", "boot_elf", "i5bootn")
LIBRARY_FLAGS = ("@ee29", "@ee296", "@eeas")
MAX_EXAMPLES = 3

# --------------------------------------------------------------------------------------------
# Disassembly and normalisation (no game data, no toolchain)
# --------------------------------------------------------------------------------------------

REGN = ("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 "
        "s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra").split()
REGNUM = {**{n: i for i, n in enumerate(REGN)}, "s8": 30, **{str(i): i for i in range(32)}}

# VU0 macro mode (COP2 with bit 25 set): funct < 0x3C is the first table, 0x3C-0x3F the second,
# indexed by (bits 6-10) << 2 | (funct & 3). "bc" forms take the broadcast field from funct & 3.
VU_SPECIAL1 = {
    0x00: "vaddbc", 0x04: "vsubbc", 0x08: "vmaddbc", 0x0C: "vmsubbc", 0x10: "vmaxbc", 0x14: "vminibc",
    0x18: "vmulbc", 0x1C: "vmulq", 0x1D: "vmaxi", 0x1E: "vmuli", 0x1F: "vminii", 0x20: "vaddq",
    0x21: "vmaddq", 0x22: "vaddi", 0x23: "vmaddi", 0x24: "vsubq", 0x25: "vmsubq", 0x26: "vsubi",
    0x27: "vmsubi", 0x28: "vadd", 0x29: "vmadd", 0x2A: "vmul", 0x2B: "vmax", 0x2C: "vsub",
    0x2D: "vmsub", 0x2E: "vopmsub", 0x2F: "vmini", 0x30: "viadd", 0x31: "visub", 0x32: "viaddi",
    0x34: "viand", 0x35: "vior", 0x38: "vcallms", 0x39: "vcallmsr"}
VU_SPECIAL2 = {
    0x00: "vaddabc", 0x04: "vsubabc", 0x08: "vmaddabc", 0x0C: "vmsubabc", 0x10: "vitof0", 0x11: "vitof4",
    0x12: "vitof12", 0x13: "vitof15", 0x14: "vftoi0", 0x15: "vftoi4", 0x16: "vftoi12", 0x17: "vftoi15",
    0x18: "vmulabc", 0x1C: "vmulaq", 0x1D: "vabs", 0x1E: "vmulai", 0x1F: "vclipw", 0x20: "vaddaq",
    0x21: "vmaddaq", 0x22: "vaddai", 0x23: "vmaddai", 0x24: "vsubaq", 0x25: "vmsubaq", 0x26: "vsubai",
    0x27: "vmsubai", 0x28: "vadda", 0x29: "vmadda", 0x2A: "vmula", 0x2C: "vsuba", 0x2D: "vmsuba",
    0x2E: "vopmula", 0x2F: "vnop", 0x30: "vmove", 0x31: "vmr32", 0x34: "vlqi", 0x35: "vsqi",
    0x36: "vlqd", 0x37: "vsqd", 0x38: "vdiv", 0x39: "vsqrt", 0x3A: "vrsqrt", 0x3B: "vwaitq",
    0x3C: "vmtir", 0x3D: "vmfir", 0x3E: "vilwr", 0x3F: "viswr", 0x40: "vrnext", 0x41: "vrget",
    0x42: "vrinit", 0x43: "vrxor"}
BC = "xyzw"


def vu0_text(word):
    """Text for a COP2 (VU0) word or lqc2/sqc2, or None."""
    op = word >> 26
    rs, rt, rd = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31
    if op in (0x36, 0x3E):
        imm = word & 0xFFFF
        imm = imm - 0x10000 if imm & 0x8000 else imm
        return "%s $vf%d, %s($%s)" % ("lqc2" if op == 0x36 else "sqc2", rt, hex(imm), REGN[rs])
    if op != 0x12:
        return None
    if not word & (1 << 25):
        name = {1: "qmfc2", 2: "cfc2", 5: "qmtc2", 6: "ctc2"}.get(rs)
        if name is None:
            return None
        if name in ("qmfc2", "qmtc2"):
            return "%s $%s, $vf%d" % (name, REGN[rt], rd)
        return "%s $%s, $vi%d" % (name, REGN[rt], rd)
    dest = "".join(c for i, c in enumerate(BC) if word & (1 << (24 - i)))
    fn = word & 0x3F
    sa = (word >> 6) & 31
    if fn < 0x3C:
        base = fn & ~3 if fn < 0x1C else fn
        name = VU_SPECIAL1.get(base)
        if name and name.endswith("bc"):
            name = name[:-2] + BC[fn & 3]
        return ("%s.%s $vf%d, $vf%d, $vf%d" % (name, dest, sa, rd, rt)) if name else "vu0.%02x" % fn
    code = (sa << 2) | (fn & 3)
    base = code & ~3 if code < 0x10 or 0x18 <= code < 0x1C else code
    name = VU_SPECIAL2.get(base)
    if name and name.endswith("bc"):
        name = name[:-2] + BC[code & 3]
    return ("%s.%s $vf%d, $vf%d" % (name, dest, rd, rt)) if name else "vu0.%03x" % code


_MD = None


def dis(word):
    """One instruction's text, capstone's spelling, with the R5900's own instructions too."""
    global _MD
    t = vu0_text(word)
    if t:
        return t
    import check
    return check.dis(word)


BRANCH_OPS = {0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
LIKELY = {"beql", "bnel", "blezl", "bgtzl", "bltzl", "bgezl", "beqzl", "bnezl", "bc1tl", "bc1fl"}


def branch_offset(word):
    """The branch's offset in words, or None when the word is not a conditional/relative branch."""
    op = word >> 26
    if op in BRANCH_OPS or (op == 1 and ((word >> 16) & 31) in (0, 1, 2, 3, 0x10, 0x11, 0x12, 0x13)) \
            or (op == 0x11 and ((word >> 21) & 31) == 8):
        imm = word & 0xFFFF
        return imm - 0x10000 if imm & 0x8000 else imm
    return None


def is_jump(word):
    op = word >> 26
    return op in (2, 3) or (op == 0 and (word & 0x3F) in (8, 9))


def has_delay(word):
    return is_jump(word) or branch_offset(word) is not None


OPERAND_RE = re.compile(r"^(?P<off>[-+]?(?:0x[0-9a-fA-F]+|\d+)|%\w+\([^)]*\))?\((?P<base>\$\w+)\)$")
REG_RE = re.compile(r"^\$(\w+)$")
IMM_RE = re.compile(r"^[-+]?(?:0x[0-9a-fA-F]+|\d+)$")
SHIFTS = {"sll", "srl", "sra", "dsll", "dsrl", "dsra", "dsll32", "dsrl32", "dsra32"}


def reg_class(name):
    """A register's class: what a register's job is, not which one it is."""
    n = name.lower()
    if n.startswith("vf"):
        return "vf0" if n == "vf0" else "vf"
    if n.startswith("vi"):
        return "vi"
    if re.match(r"^f\d+$", n):
        k = int(n[1:])
        return "fv" if k < 4 else "fa" if 12 <= k <= 19 else "fs" if k >= 20 else "ft"
    k = REGNUM.get(n)
    if k is None:
        return n
    if k == 0:
        return "zero"
    if k in (28, 29, 31):
        return {28: "gp", 29: "sp", 31: "ra"}[k]
    if k == 1:
        return "at"
    if k in (2, 3):
        return "v"
    if 4 <= k <= 7:
        return "a"
    if 16 <= k <= 23 or k == 30:
        return "s"
    if k in (26, 27):
        return "k"
    return "t"


def imm_bucket(v):
    if v == 0:
        return "0"
    if v == 1:
        return "1"
    if v == -1:
        return "-1"
    if v < 0:
        return "neg"
    if v <= 16:
        return "s"
    if v & (v - 1) == 0:
        return "p2"
    return "i16" if v < 0x8000 else "big"


def parse_int(s):
    return int(s, 0)


def normalise(insns):
    """insns: [(text, reloc)] where reloc is None, 'hi', 'lo', 'gp', '26' (a jal or j target) or
    'lo+'/'gp+'/'hi+' (a named symbol at an offset). Returns (fine, coarse): tuples of tokens,
    fine with registers numbered per class in order of appearance, coarse with only the mnemonic
    and the relocation kind."""
    seen = {}
    fine, coarse = [], []

    def reg(name):
        c = reg_class(name)
        if c in ("zero", "gp", "sp", "ra", "at", "vf0", "k"):
            return c
        key = name.lower()
        if key not in seen:
            seen[key] = "%s%d" % (c, 1 + sum(1 for v in seen.values() if re.sub(r"\d+$", "", v) == c))
        return seen[key]

    for text, rel in insns:
        text = text.strip()
        parts = text.split(None, 1)
        if not parts:
            continue
        mn = parts[0].lower()
        ops = [o.strip() for o in parts[1].split(",")] if len(parts) > 1 else []
        if mn == "nop" or text.startswith(".word 0x00000000"):
            fine.append("nop")
            coarse.append("nop")
            continue
        kind = (rel or "").rstrip("+")
        toks = []
        for i, o in enumerate(ops):
            m = OPERAND_RE.match(o)
            if m:
                base = m.group("base")
                off = m.group("off") or "0"
                bc = reg_class(base[1:])
                if off.startswith("%"):
                    k = re.match(r"%(\w+)", off).group(1)
                    o_tok = {"gp_rel": "%gp", "lo": "%lo", "hi": "%hi"}.get(k, "%" + k)
                elif bc == "gp" or kind == "gp":
                    o_tok = "%gp"
                elif kind == "lo":
                    o_tok = "%lo"
                else:
                    o_tok = imm_bucket(parse_int(off))
                if rel and rel.endswith("+"):
                    o_tok += "+"
                toks.append("%s(%s)" % (o_tok, reg(base[1:])))
                continue
            m = REG_RE.match(o)
            if m:
                toks.append(reg(m.group(1)))
                continue
            if o.startswith("%hi(") or (kind == "hi" and IMM_RE.match(o)):
                toks.append("%hi" + ("+" if rel and rel.endswith("+") else ""))
                continue
            if o.startswith("%lo(") or (kind == "lo" and IMM_RE.match(o)):
                toks.append("%lo" + ("+" if rel and rel.endswith("+") else ""))
                continue
            if o.startswith("%gp_rel(") or (kind == "gp" and IMM_RE.match(o)):
                toks.append("%gp")
                continue
            if IMM_RE.match(o):
                v = parse_int(o)
                if mn in ("j", "jal") or kind == "26":
                    toks.append("F")
                elif mn.startswith("b") and i == len(ops) - 1:
                    toks.append("Lb" if v < 0 else "Lf")
                elif mn in SHIFTS:
                    toks.append(str(v) if v in (1, 2, 3, 4, 8, 16, 24, 31) else imm_bucket(v))
                elif mn == "lui":
                    toks.append("hi")
                else:
                    toks.append(imm_bucket(v))
                continue
            if mn.startswith("b") and i == len(ops) - 1:
                toks.append(o if o in ("Lf", "Lb") else "L")
                continue
            if mn in ("j", "jal"):
                toks.append("F")
                continue
            toks.append("sym")
        fine.append(mn + (" " + ",".join(toks) if toks else ""))
        rk = ""
        if kind in ("hi", "lo", "gp"):
            rk = "@" + kind
        elif any(t.startswith("%gp") for t in toks):
            rk = "@gp"
        elif any(t.startswith("%lo") for t in toks):
            rk = "@lo"
        elif any(t.startswith("%hi") for t in toks):
            rk = "@hi"
        elif any("(sp)" in t for t in toks):
            rk = "@sp"
        coarse.append(mn + rk)
    return tuple(fine), tuple(coarse)


C_KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register return short signed sizeof static struct switch typedef union unsigned void
volatile while __inline__ __asm__ asm __attribute__ s8 u8 s16 u16 s32 u32 s64 u64 f32 f64 u128 s128
u128_t vu0_q vu0_v4 Vec4 NULL""".split())
C_TOKEN_RE = re.compile(r"""\s*(?:(?P<num>0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][-+]?\d+)?[fF]?|\d*\.\d+(?:[eE][-+]?\d+)?[fF]?|\d+[fF]|\d+[uUlL]*)
    |(?P<id>[A-Za-z_]\w*)|(?P<str>"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')
    |(?P<op>->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|[-+*/%&|^~!<>=?:;,.(){}\[\]]))""", re.X)


def strip_c_comments(s):
    s = re.sub(r"/\*.*?\*/", " ", s, flags=re.S)
    s = re.sub(r"/\*.*$", " ", s)
    s = re.sub(r"^.*?\*/", " ", s) if "*/" in s and "/*" not in s else s
    return re.sub(r"//.*$", "", s)


STRUCTURAL = re.compile(r"^(?:[{}]|else|do|break|continue|return|;|\s)*$")


def structural(c_norm):
    """A C form that is only braces and control words (`} else {`, `break ;`, `}`): the code gcc
    puts at such lines is a jump or a loop's branch, not the statement's own work."""
    return bool(STRUCTURAL.match(c_norm))


def normalise_c(text, helpers=frozenset()):
    """C text with the names taken out: v (a variable), G (a D_ global), F (a called function),
    m (a member); numbers 0, 1, N, Nf. Keywords, types, helper names (include/vu0.h), operators
    and the statement's shape stay."""
    out = []
    pos = 0
    text = strip_c_comments(text)
    asm = "__asm__" in text or re.search(r"\basm\b", text) is not None
    prev = None
    toks = []
    while pos < len(text):
        m = C_TOKEN_RE.match(text, pos)
        if not m or m.end() == pos:
            pos += 1
            continue
        pos = m.end()
        toks.append((m.lastgroup, m.group(m.lastgroup)))
    for i, (kind, t) in enumerate(toks):
        nxt = toks[i + 1][1] if i + 1 < len(toks) else ""
        if kind == "num":
            if re.search(r"[.eEfF]", t) and not t.lower().startswith("0x"):
                out.append("Nf")
            else:
                v = int(re.sub(r"[uUlL]+$", "", t), 0)
                out.append("0" if v == 0 else "1" if v == 1 else "N")
        elif kind == "id":
            if t in C_KEYWORDS or t in helpers:
                out.append(t)
            elif prev in (".", "->"):
                out.append("m")
            elif nxt == "(":
                out.append("F")
            elif re.match(r"^D_", t):
                out.append("G")
            elif re.match(r"^(func_|fe_func_)", t):
                out.append("F")
            else:
                out.append("v")
        elif kind == "str":
            out.append(t if asm else '"s"')
        else:
            out.append(t)
        prev = t
    return " ".join(out)


# --------------------------------------------------------------------------------------------
# build: compile with -g, read the line labels, keep what matches retail
# --------------------------------------------------------------------------------------------

ASM_BLOCK_RE = re.compile(r"^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(.*\);[^\n]*$", re.M)
C_BLOCK_RE = re.compile(r"/\* localdecomp:start (func_\w+) \*/")
STABN_RE = re.compile(r"^\s*\.stabn\s+68,0,(\d+),\$LM(\d+)\s*$")
STABS_FILE_RE = re.compile(r'^\s*\.stabs\s+"((?:\\.|[^"\\])*)",(100|132),')
LM_RE = re.compile(r"^\$LM(\d+):", re.M)
IDL_RE = re.compile(r"^__idl_(\d+)_(\d+)_(\d+)$")


def lines_to_labels(text):
    """gcc -g output with the stabs taken out and each line marker's $LMn label renamed
    __idl_<n>_<line>_<file index>, a label the object keeps. Returns (assembly, files)."""
    files, cur, marks, out = [], None, {}, []
    for line in text.splitlines(True):
        m = STABS_FILE_RE.match(line)
        if m:
            name = m.group(1).replace("\\\\", "\\")
            if not name.endswith(("/", "\\")):
                if name not in files:
                    files.append(name)
                cur = files.index(name)
            continue
        m = STABN_RE.match(line)
        if m:
            marks[m.group(2)] = (int(m.group(1)), cur if cur is not None else 0)
            continue
        s = line.strip()
        if s.startswith((".stabs", ".stabn", ".stabd")) or s == "#@stabs":
            continue
        out.append(line)
    asm = "".join(out)
    asm = LM_RE.sub(lambda m: ("__idl_%s_%d_%d:" % ((m.group(1),) + marks[m.group(1)]))
                    if m.group(1) in marks else m.group(0), asm)
    return asm, files


def file_table():
    """[(rel, program, flags)] of every source file with C: the core programs' (their
    src_files.txt and text_parts.txt) and the levels' (config/levels/text_parts.txt)."""
    import build_text
    import level_tree
    out, seen = [], set()
    for prog in CORE:
        sfp = os.path.join(ROOT, "config", prog, "src_files.txt")
        parts = build_text.read_parts(os.path.join(ROOT, "config", prog, "text_parts.txt"))
        for line in open(sfp):
            f = line.split("#", 1)[0].split()
            if len(f) < 2 or f[0] in seen:
                continue
            seen.add(f[0])
            out.append((f[0], prog, build_text.flags_for(parts, int(f[1], 16))))
    lparts = level_tree.read_parts()
    for dirpath, _, names in os.walk(os.path.join(ROOT, "src", "levels")):
        for n in sorted(names):
            if n.endswith(".c"):
                rel = os.path.relpath(os.path.join(dirpath, n), ROOT)
                out.append((rel, "levels", lparts.get(rel, level_tree.BASE_FLAGS).split()))
    return [r for r in sorted(out) if os.path.exists(os.path.join(ROOT, r[0]))
            and "localdecomp:start" in open(os.path.join(ROOT, r[0]), errors="replace").read()]


_RETAIL = {}


def retail_words(program, name, size):
    """Retail's words of a function: a core one at its address in its program, a level one
    (func_LNN_XXXXXXXX) at XXXXXXXX in level NN."""
    import check
    import levels
    import targets
    m = re.match(r"^func_L(\d\d)_([0-9A-F]{8})$", name)
    if m:
        path, addr = levels.elf_path(int(m.group(1))), int(m.group(2), 16)
    else:
        m = re.match(r"^func_([0-9A-Fa-f]{8})$", name)
        if not m or program not in CORE:
            return None
        path, addr = targets.get(program).path("elf"), int(m.group(1), 16)
    if path not in _RETAIL:
        _RETAIL[path] = check.Retail(path) if os.path.exists(path) else None
    r = _RETAIL[path]
    data = r.read(addr, size) if r else b""
    return list(struct.unpack("<%dI" % (len(data) // 4), data)) if len(data) == size else None


RELOC_MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}
RELOC_KIND = {4: "26", 5: "hi", 6: "lo", 7: "gp"}


def read_object(path):
    """(functions {name: (offset, size)}, labels [(offset, line, file)], text bytes,
    relocations {offset: (kind, symbol name or '', type)})."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        text_sec = elf.get_section_by_name(".text")
        text = text_sec.data()
        tidx = elf.get_section_index(".text")
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        funcs, labels = {}, []
        for s in syms:
            if s["st_shndx"] != tidx:
                continue
            if s["st_info"]["type"] == "STT_FUNC":
                funcs[s.name] = (s["st_value"], s["st_size"])
            m = IDL_RE.match(s.name)
            if m:
                labels.append((s["st_value"], int(m.group(2)), int(m.group(3)), int(m.group(1))))
        relocs = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection) and sec.name in (".rel.text", ".rela.text"):
                for r in sec.iter_relocations():
                    s = syms[r["r_info_sym"]]
                    name = s.name if s["st_info"]["type"] != "STT_SECTION" else ""
                    relocs[r["r_offset"]] = (RELOC_KIND.get(r["r_info_type"]), name, r["r_info_type"])
    labels.sort(key=lambda x: (x[0], x[3]))
    return funcs, labels, text, relocs


def env_toolchain():
    tc = os.environ.get("UYA_TOOLCHAIN")
    if not tc:
        sys.exit("set UYA_TOOLCHAIN (and UYA_RUNNER off Windows), as for tools/check.py")
    return tc, os.environ.get("UYA_RUNNER")


def compile_file(rel, program, flags, tmproot):
    """One source file's raw record: per C function its words, relocations, line per word and
    whether it equals retail."""
    import asm_filter
    import check
    tc, runner = env_toolchain()
    rec = {"rel": rel, "program": program, "flags": flags, "files": [], "functions": [], "error": None}
    src = open(os.path.join(ROOT, rel), errors="replace").read()
    names = C_BLOCK_RE.findall(src)
    rec["c_functions"] = len(names)
    if any(f in flags for f in LIBRARY_FLAGS):
        rec["error"] = "library flags"
        return rec
    tmp = tempfile.mkdtemp(prefix="idioms_", dir=tmproot)
    env = dict(os.environ, LC_ALL="C")
    os.environ["UYA_TARGET"] = env["UYA_TARGET"] = program if program in CORE else "frontbin"
    gcc = os.path.join(tc, "bin", "ee-gcc2953.exe")
    base = ([runner] if runner else []) + [gcc, "-I", "include", "-I", "."] + check.expand(flags, tc)
    head = 2 if runner else 1
    c_path, s_path, o_path = (os.path.join(tmp, "t." + e) for e in "cso")

    def run(text):
        """Compile C text with -g: (files, object) or an error string."""
        for p_ in (s_path, o_path):
            if os.path.exists(p_):
                os.remove(p_)
        if "common.h" not in text:
            text = '#include "common.h"\n' + text
        with open(c_path, "w") as fh:
            fh.write(text)
        p = subprocess.run(base[:head] + ["-S", "-g"] + base[head:] + ["-o", s_path, c_path],
                           capture_output=True, text=True, cwd=ROOT, env=env, timeout=300)
        if p.returncode or not os.path.exists(s_path):
            return "compile: " + "\n".join(l for l in (p.stdout + p.stderr).splitlines()
                                            if "warning:" not in l and "never used" not in l)[-400:]
        asm, files = lines_to_labels(open(s_path, errors="replace").read())
        asm = asm_filter.filter_asm(asm, "@ps2as" in flags)
        with open(s_path, "w") as fh:
            fh.write(asm)
        p = subprocess.run(base[:head] + ["-c"] + base[head:] + ["-o", o_path, s_path],
                           capture_output=True, text=True, cwd=ROOT, env=env, timeout=300)
        if p.returncode or not os.path.exists(o_path):
            return "assemble: " + (p.stdout + p.stderr)[-400:]
        return files, read_object(o_path)

    try:
        # the whole file, its assembly blocks taken out (their lines stay, empty, so line numbers hold)
        got = run('#line 1 "%s"\n' % rel + ASM_BLOCK_RE.sub("", src))
        if isinstance(got, str):
            # a file that only compiles in pieces (two blocks declaring one name differently): each
            # function in its own context, as tools/check.py compiles it (the prelude and the
            # declarations of the functions before it), at its own line numbers
            import level_tree
            import srcfiles as sf
            rec["error"] = "compiled in pieces: " + got
            prelude, chunks = level_tree.parse_source(rel)
            pos, decls, pieces = len(prelude), [], {}
            for name, kind, body in chunks:
                start = src.index(body, pos) if body else pos
                pos = start + len(body)
                if kind == "C":
                    line = src.count("\n", 0, start) + 1
                    pieces[name] = ('#line 1 "%s"\n%s\n%s\n#line %d "%s"\n%s' % (
                        rel, prelude, "\n".join(decls), line, rel, body))
                d = sf.declarations_only(body)
                if d:
                    decls.append(d)
            for name in names:
                if name not in pieces:
                    rec["functions"].append({"name": name, "status": "missing"})
                    continue
                one = run(pieces[name])
                if isinstance(one, str):
                    rec["functions"].append({"name": name, "status": "error"})
                    continue
                add_function(rec, name, program, one[0], one[1])
        else:
            for name in names:
                add_function(rec, name, program, got[0], got[1])
        return rec
    except subprocess.TimeoutExpired:
        rec["error"] = "timeout"
        return rec
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


def add_function(rec, name, program, files, obj):
    """Append one function of a compiled object to the record."""
    funcs, labels, text, relocs = obj
    rel = rec["rel"]
    if not rec["files"]:
        rec["files"] = files
    if files != rec["files"]:
        # file indices are the record's: map this object's onto them
        for f in files:
            if f not in rec["files"]:
                rec["files"].append(f)
        remap = {i: rec["files"].index(f) for i, f in enumerate(files)}
        labels = [(o, ln, remap.get(fi, fi), k) for o, ln, fi, k in labels]
    files = rec["files"]
    if name not in funcs:
        rec["functions"].append({"name": name, "status": "missing"})
        return
    off, size = funcs[name]
    words = list(struct.unpack("<%dI" % (size // 4), text[off:off + size]))
    retail = retail_words(program, name, size)
    rel_of = {}
    status = "ok" if retail is not None else "no retail"
    for i, w in enumerate(words):
        r = relocs.get(off + 4 * i)
        if r:
            kind, sym, rtype = r
            plus = "+" if sym and kind in ("gp", "lo") and (w & 0xFFFF) else ""
            rel_of[i] = [kind or "?", sym, plus]
        if retail is not None:
            mask = RELOC_MASK.get(r[2], 0) if r else 0xFFFFFFFF
            if (w & mask) != (retail[i] & mask):
                status = "differs"
    lines, li, cur = [], 0, None
    for i in range(len(words)):
        a = off + 4 * i
        while li < len(labels) and labels[li][0] <= a:
            cur = labels[li][1:3]
            li += 1
        lines.append(list(cur) if cur else None)
    # the main-file line in effect when an inline helper's code starts: its caller
    caller, callers = None, []
    for ln in lines:
        if ln and ln[1] < len(files) and files[ln[1]] == rel:
            caller = ln[0]
        callers.append(caller)
    rec["functions"].append({"name": name, "status": status, "words": words,
                             "relocs": {str(k): v for k, v in rel_of.items()},
                             "lines": lines, "callers": callers})


def raw_path(rel):
    return os.path.join(RAW, rel.replace("/", "__") + ".json")


def _build_one(item):
    rel, program, flags, tmproot = item
    try:
        rec = compile_file(rel, program, flags, tmproot)
    except Exception as e:  # noqa: BLE001  (one bad file must not stop the run)
        rec = {"rel": rel, "program": program, "flags": flags, "functions": [], "error": "crash: %r" % e}
    with open(raw_path(rel), "w") as fh:
        json.dump(rec, fh, separators=(",", ":"))
    ok = sum(1 for f in rec["functions"] if f.get("status") == "ok")
    return rel, ok, len(rec["functions"]), rec.get("error")


def cmd_build(a):
    import multiprocessing
    os.makedirs(RAW, exist_ok=True)
    tmproot = os.path.join(OUT, "tmp")
    os.makedirs(tmproot, exist_ok=True)
    table = file_table()
    if a.files:
        want = set(a.files)
        table = [t for t in table if t[0] in want]
    if a.shard:
        mine, n = a.shard.split("/")
        mine, n = {int(x) for x in mine.split(",")}, int(n)
        table = [t for k, t in enumerate(table) if k % n in mine]
    if not a.force:
        table = [t for t in table if not os.path.exists(raw_path(t[0]))]
    print("idioms build: %d source files to compile, -j %d" % (len(table), a.jobs), flush=True)
    done = ok = total = 0
    with multiprocessing.Pool(a.jobs) as pool:
        for rel, k, n, err in pool.imap_unordered(_build_one, [t + (tmproot,) for t in table]):
            done += 1
            ok += k
            total += n
            if err and err != "library flags":
                print("  %s: %s" % (rel, err.splitlines()[0][:200]), flush=True)
            if done % 200 == 0:
                print("  %d/%d files, %d of %d functions usable" % (done, len(table), ok, total), flush=True)
    shutil.rmtree(tmproot, ignore_errors=True)
    print("idioms build: %d files, %d of %d C functions match retail with -g" % (done, ok, total))
    if not a.compile_only:
        cmd_mine(a)


# --------------------------------------------------------------------------------------------
# mine: fragments, shapes, families
# --------------------------------------------------------------------------------------------

FAMILIES = [
    # (key, title, what it is)
    ("movn_movz", "movn / movz (conditional moves)",
     "A select without a branch: `x = c ? a : b`, `if (c) x = a;` on a value already computed, min/max."),
    ("set_less", "slt / sltu / slti / sltiu",
     "A comparison kept as a value: `(a < b)`, `x != 0` as `sltu x, $0, x`, bounds checks `(u32)i < n`."),
    ("branch_likely", "Branch-likely with a filled delay slot",
     "beql/bnel/...: the delay slot runs only when the branch is taken. gcc uses them when it moves "
     "the first instruction of the branch target into the slot."),
    ("gp_access", "$gp-relative small data",
     "A global of 8 bytes or less (with -G8) read or written through $gp, one instruction."),
    ("hilo_access", "lui / %lo absolute access",
     "A global gcc does not know to be small (an array, an extern without a size, a struct) "
     "reached with lui and a %lo offset."),
    ("data_offset", "Data at an offset from its symbol",
     "`%gp_rel(sym+N)` or `%lo(sym+N)`: a member or element of a named global at a fixed offset "
     "(docs/build/globals.md)."),
    ("divs_nops", "div.s / sqrt.s and their nops",
     "Retail pads most div.s/sqrt.s with 0-3 nops (config/*/divs_nops.txt, tools/asm_filter.py); "
     "the C around them."),
    ("mtc1_nop", "mtc1 followed by a nop",
     "The FPU move hazard: an int or a constant moved to the FPU and used at once."),
    ("vu0", "VU0 macro code (lqc2/sqc2, vadd, vmul, qmfc2...)",
     "include/vu0.h's helpers and inline asm for COP2 instructions."),
    ("jump_table", "Jump tables",
     "A `switch` dense enough for a table: sltiu bound check, sll by 2, lw from a jtbl_, jr."),
    ("cross_jump", "Cross-jumped shared tails",
     "An unconditional branch into the middle of another statement's code: gcc merged identical "
     "tails (two `return f(x);` or the same assignment at the end of both arms)."),
    ("quad_copy", "128-bit lq / sq copies",
     "A 16-byte copy through a general register, `*(u128 *)d = *(u128 *)s` or a struct assignment."),
    ("float_call", "Float arguments to a call",
     "mov.s/mtc1/lwc1 into $f12-$f19 before a jal: float arguments, in the order gcc set them up."),
    ("loop", "Loops (the backward branch)",
     "The statement whose code holds the loop's closing branch: `for`, `while`, `do ... while`."),
    ("inline_helper", "Inline helpers from headers",
     "Code inlined from a `static __inline__` helper in include/ (include/vu0.h): the helper and "
     "the call that used it."),
    ("bitfield", "Bit tests and masks",
     "andi/ori/xori with masks, shifts by constants: flags and bit-fields."),
    ("float_cmp", "Float compares (c.lt.s, c.eq.s, bc1t/bc1f)",
     "Float conditions and the branch that tests them."),
    ("float_const", "Float constants",
     "A float constant built with lui (+ori) and mtc1, or loaded from the literal pool with lwc1."),
    ("call", "Calls", "Statements whose code holds a jal: argument set-up and the call."),
]
FAMILY_TITLE = {k: t for k, t, _ in FAMILIES}


def tag_families(fine, coarse, extra):
    """The families one fragment belongs to (FAMILIES)."""
    mns = [c.split("@")[0] for c in coarse]
    tags = set()
    if any(m in ("movn", "movz") for m in mns):
        tags.add("movn_movz")
    if any(m in ("slt", "sltu", "slti", "sltiu") for m in mns):
        tags.add("set_less")
    if any(m in LIKELY for m in mns):
        tags.add("branch_likely")
    if any(c.endswith("@gp") for c in coarse):
        tags.add("gp_access")
    if any(c.endswith("@hi") for c in coarse) and any(c.endswith("@lo") for c in coarse):
        tags.add("hilo_access")
    if any("+" in f for f in fine):
        tags.add("data_offset")
    if any(m in ("div.s", "sqrt.s") for m in mns):
        tags.add("divs_nops")
    for i, m in enumerate(mns[:-1]):
        if m == "mtc1" and mns[i + 1] == "nop":
            tags.add("mtc1_nop")
    if any(m in ("lqc2", "sqc2", "qmfc2", "qmtc2", "cfc2", "ctc2") or re.match(r"^v[a-z]", m) for m in mns):
        tags.add("vu0")
    if extra.get("jump_table"):
        tags.add("jump_table")
    if extra.get("cross_jump"):
        tags.add("cross_jump")
    if any(re.match(r"^(lq|sq) ", f) and "(sp)" not in f for f in fine):
        tags.add("quad_copy")
    if "jal" in mns and any(re.match(r"^(mov\.s|mtc1|lwc1) .*\bfa\d", f) for f in fine):
        tags.add("float_call")
    if extra.get("loop"):
        tags.add("loop")
    if extra.get("inline"):
        tags.add("inline_helper")
    for i, m in enumerate(mns):
        if m in ("andi", "xori", "and", "nor", "xor") or (m in ("srl", "sra", "dsrl", "dsra", "dsrl32", "dsra32")):
            tags.add("bitfield")
        elif m == "ori" and not (i and mns[i - 1] == "lui"):
            tags.add("bitfield")
        elif m in ("sll", "dsll", "dsll32") and not (i + 1 < len(mns) and mns[i + 1] in ("addu", "daddu")):
            tags.add("bitfield")
    if any(m.startswith("c.") for m in mns):
        tags.add("float_cmp")
    if ("mtc1" in mns and "lui" in mns) or any(c == "lwc1@gp" or c == "lwc1@lo" for c in coarse):
        tags.add("float_const")
    if "jal" in mns:
        tags.add("call")
    return tags


class Source:
    """The lines of the repository's C files and headers, read once each."""

    def __init__(self):
        self.cache = {}

    def lines(self, rel):
        if rel not in self.cache:
            p = os.path.join(ROOT, rel)
            try:
                with open(p, errors="replace") as fh:
                    self.cache[rel] = fh.read().split("\n")
            except OSError:
                self.cache[rel] = []
        return self.cache[rel]

    def statement(self, rel, line):
        """The C statement starting at `line` (1-based): the line, and the lines after it while its
        parentheses are open (at most 6)."""
        ls = self.lines(rel)
        if not 0 < line <= len(ls):
            return ""
        out, depth = [], 0
        for k in range(line - 1, min(len(ls), line + 5)):
            s = strip_c_comments(ls[k]).strip()
            out.append(s)
            depth += s.count("(") - s.count(")")
            if depth <= 0:
                break
        return " ".join(x for x in out if x)

    def helper_name(self, rel, line):
        """The inline helper of a header that holds `line`."""
        ls = self.lines(rel)
        for k in range(min(line, len(ls)) - 1, -1, -1):
            m = re.search(r"\b(\w+)\s*\([^;]*\)\s*\{?\s*$", ls[k])
            if m and ("inline" in ls[k] or "__inline__" in ls[k]):
                return m.group(1)
            if k < line - 80:
                break
        return None


def header_helpers():
    """Names of the static inline helpers in include/ (kept as they are in normalised C)."""
    out = set()
    for dirpath, _, names in os.walk(os.path.join(ROOT, "include")):
        for n in names:
            if n.endswith(".h"):
                txt = open(os.path.join(dirpath, n), errors="replace").read()
                out |= set(re.findall(r"static\s+__inline__[^(;{]*?\b(\w+)\s*\(", txt))
                out |= set(re.findall(r"static\s+inline[^(;{]*?\b(\w+)\s*\(", txt))
    return out


def reloc_of(fn, i):
    r = fn["relocs"].get(str(i))
    if not r:
        return None
    kind, sym, plus = r
    if kind in ("hi", "lo", "gp") and sym:
        return kind + plus
    return kind


def insn_texts(fn):
    """The function's instructions as text, with their relocation kinds."""
    out = []
    for i, w in enumerate(fn["words"]):
        out.append((dis(w), reloc_of(fn, i)))
    return out


def fragments_of(fn, rec, src, helpers):
    """[(fine, coarse, c_norm, example, tags)] for one function."""
    words = fn["words"]
    files = rec.get("files") or []
    texts = insn_texts(fn)
    groups = collections.OrderedDict()       # (file index, line) -> [instruction indices]
    for i, ln in enumerate(fn["lines"]):
        if ln is None:
            continue
        groups.setdefault(tuple(ln), []).append(i)
    line_of = [tuple(ln) if ln else None for ln in fn["lines"]]
    # loops and cross jumps: from the branches
    loop_at, cross_at, jtbl_at = set(), {}, set()
    for i, w in enumerate(words):
        off = branch_offset(w)
        if off is not None:
            tgt = i + 1 + off
            if off < 0:
                loop_at.add(i)
            if w >> 16 == 0x1000 and 0 <= tgt < len(words) and line_of[i] and line_of[tgt]:
                # `b` into straight-line code (the word before the target is not a jump's delay
                # slot): a tail shared with the code that falls into it
                prev2 = words[tgt - 2] if tgt >= 2 else None
                prev1 = words[tgt - 1] if tgt >= 1 else None
                falls = prev1 is not None and not has_delay(prev1) and not (
                    prev2 is not None and (is_jump(prev2) or prev2 >> 16 == 0x1000))
                if falls and line_of[tgt] != line_of[i]:
                    a = src.statement(files[line_of[i][1]], line_of[i][0]) if line_of[i][1] < len(files) else ""
                    b = src.statement(files[line_of[tgt][1]], line_of[tgt][0]) if line_of[tgt][1] < len(files) else ""
                    head = [k for k in range(max(0, i - 3), i) if line_of[k] == line_of[tgt]]
                    if head or (a and normalise_c(a) == normalise_c(b)) or (line_of[i][0] > line_of[tgt][0]):
                        cross_at[i] = b
        if w & 0xFC00003F == 0x00000008 and ((w >> 21) & 31) != 31:
            jtbl_at.add(i)
    main = lambda f: f < len(files) and files[f] == rec["rel"]
    main_lines = [l for l, f in groups if main(f)]
    first_line = min(main_lines) if main_lines else None
    # code inlined from a header: one fragment per helper call, the run of its instructions
    # (other code may be scheduled in between, up to 3 instructions), named by the call
    units = [((line, fidx), idx) for (line, fidx), idx in groups.items() if main(fidx)]
    run, last, runs = None, -10, []
    for i, ln in enumerate(fn["lines"]):
        if ln is None or main(ln[1]):
            continue
        rel = files[ln[1]] if ln[1] < len(files) else "?"
        name = src.helper_name(rel, ln[0]) or "?"
        if run is None or run[0] != name or i - last > 4:
            run = [name, rel, ln[0], []]
            runs.append(run)
        run[3].append(i)
        last = i
    body = src.lines(rec["rel"])
    lo, hi = (min(main_lines), max(main_lines)) if main_lines else (0, -1)
    for name, rel, hline, idx in runs:
        near = fn["callers"][idx[0]] or lo
        calls = [k + 1 for k in range(max(0, lo - 1), min(len(body), hi)) if re.search(r"\b%s\s*\(" % re.escape(name), body[k])]
        units.append((("inline", name, rel, hline, min(calls, key=lambda k: abs(k - near)) if calls else None), idx))
    out = []
    for key, idx in units:
        inline = key[0] == "inline"
        if inline:
            _, name, rel, hline, line = key
            c_raw = src.statement(rec["rel"], line) if line else ""
            c_norm = ("inline %s: " % name) + (normalise_c(c_raw, helpers) if c_raw else "(%s)" % name)
            c_raw = "%s  [inline %s, %s:%d]" % (c_raw, name, rel, hline)
            line = line or 0
        else:
            line, fidx = key
            rel = files[fidx] if fidx < len(files) else rec["rel"]
            c_raw = src.statement(rel, line)
            c_norm = normalise_c(c_raw, helpers)
        if not c_norm.strip():
            continue
        fine, coarse = normalise([texts[i] for i in idx])
        extra = {"loop": any(i in loop_at for i in idx), "cross_jump": any(i in cross_at for i in idx),
                 "inline": inline,
                 "jump_table": any(i in jtbl_at for i in idx) and any(
                     (fn["relocs"].get(str(k)) or ["", ""])[1].startswith("jtbl")
                     or (fn["relocs"].get(str(k)) or ["", "x"])[1] == "" and reloc_of(fn, k) == "lo"
                     for k in idx)}
        tags = tag_families(fine, coarse, extra)
        if not inline and line == first_line and fn["name"] in c_raw:
            tags.add("prologue")            # the function's own line: its frame and argument moves
        contiguous = idx == list(range(idx[0], idx[-1] + 1))
        example = {"fn": fn["name"], "file": rec["rel"], "line": line, "c": c_raw[:200],
                   "asm": [texts[i][0] for i in idx][:24], "contiguous": contiguous}
        tails = [cross_at[i] for i in idx if i in cross_at]
        if tails:
            example["tail"] = tails[0][:160]
        out.append((fine, coarse, c_norm, example, tags))
    return out


def function_fingerprint(fn):
    """A function's code with its relocated fields masked: copies of one routine (the same C in
    several files, a level's own copy) give the same fingerprint and are mined once."""
    out = []
    for i, w in enumerate(fn["words"]):
        r = fn["relocs"].get(str(i))
        out.append(w & ({"26": 0xFC000000}.get(r[0], 0xFFFF0000) if r else 0xFFFFFFFF))
    return struct.pack("<%dI" % len(out), *out)


def cmd_mine(a):
    src = Source()
    helpers = header_helpers()
    shapes = {}
    nfiles = nfunc = nfrag = skipped = 0
    statuses = collections.Counter()
    seen_code, copies, library = set(), 0, 0
    for n in sorted(os.listdir(RAW)) if os.path.isdir(RAW) else []:
        if not n.endswith(".json"):
            continue
        with open(os.path.join(RAW, n)) as fh:
            rec = json.load(fh)
        nfiles += 1
        if rec.get("error") == "library flags":
            library += rec.get("c_functions", 0)
        for fn in rec.get("functions", []):
            statuses[fn.get("status")] += 1
            if fn.get("status") != "ok":
                skipped += 1
                continue
            fp = function_fingerprint(fn)
            if fp in seen_code:
                copies += 1
                continue
            seen_code.add(fp)
            nfunc += 1
            for fine, coarse, c_norm, ex, tags in fragments_of(fn, rec, src, helpers):
                nfrag += 1
                key = " ; ".join(fine)
                s = shapes.get(key)
                if s is None:
                    s = shapes[key] = {"fine": list(fine), "coarse": list(coarse), "count": 0,
                                       "tags": sorted(tags), "c": {}}
                s["count"] += 1
                s["tags"] = sorted(set(s["tags"]) | tags)
                c = s["c"].setdefault(c_norm, {"count": 0, "examples": [], "tags": {}})
                c["count"] += 1
                for t in tags:
                    c["tags"][t] = c["tags"].get(t, 0) + 1
                if len(c["examples"]) < MAX_EXAMPLES and all(e["fn"] != ex["fn"] for e in c["examples"]):
                    c["examples"].append(ex)
    db = {"functions": nfunc, "fragments": nfrag, "files": nfiles, "skipped": skipped, "copies": copies, "library": library,
          "statuses": dict(statuses), "shapes": shapes}
    os.makedirs(OUT, exist_ok=True)
    with gzip.open(DB, "wt") as fh:
        json.dump(db, fh, separators=(",", ":"))
    print("idioms mine: %d files, %d functions mined, %d copies of one already mined left out (%s), "
          "%d fragments, %d shapes -> %s" % (nfiles, nfunc, copies, ", ".join("%s %d" % kv for kv in sorted(statuses.items(), key=str)), nfrag,
        len(shapes), os.path.relpath(DB, ROOT)))


def load_db(path=DB):
    if not os.path.exists(path):
        sys.exit("%s not found: run python3 tools/idioms.py build (or mine) first" % os.path.relpath(path, ROOT))
    with gzip.open(path, "rt") as fh:
        return json.load(fh)


# --------------------------------------------------------------------------------------------
# query
# --------------------------------------------------------------------------------------------

SPLAT_LINE = re.compile(r"^\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/\s*(.*)$")
LABEL_LINE = re.compile(r"^\s*(\.?L[0-9A-Fa-f_]+|\w+):\s*$")


def parse_asm(text):
    """[(text, reloc, word or None, label before it)] from a splat .s or a snippet (one
    instruction per line or ';'-separated). The relocation kind is read from %hi/%lo/%gp_rel and
    from $gp bases; with the word given (splat's comment) the text is the disassembler's, so it
    normalises the way the mined code does."""
    out, label = [], False
    lines = []
    for raw in text.split("\n"):
        lines += raw.split(";") if not SPLAT_LINE.match(raw) else [raw]
    for raw in lines:
        s = raw.strip()
        if not s or s.startswith(("glabel", "endlabel", "nonmatching", ".align", ".set", "#", "//", ".size",
                                  ".ent", ".end", ".type", ".globl", "jlabel", "dlabel")):
            m = re.match(r"^\s*jlabel\s+(\S+)", raw)
            if m:
                label = True
            continue
        if LABEL_LINE.match(s):
            label = True
            continue
        m = SPLAT_LINE.match(raw)
        word = None
        wm = re.match(r"^\s*\.word\s+(0x[0-9A-Fa-f]{1,8})\b", raw)
        if not m and wm:
            # a raw word (fix_quadword_ops.py's lq/sq/lqc2/sqc2, a padded div.s): its value as is
            word = int(wm.group(1), 16)
            txt = ".word"
            out.append((dis(word), None, word, label))
            label = False
            continue
        if m:
            word = int(m.group(1), 16)
            word = struct.unpack("<I", struct.pack(">I", word))[0]   # splat prints the bytes
            txt = m.group(2)
        else:
            txt = s
        txt = re.sub(r"\s+#.*$", "", txt).strip()
        rel = None
        if "%hi(" in txt:
            rel = "hi"
        elif "%lo(" in txt:
            rel = "lo"
        elif "%gp_rel(" in txt or re.search(r"\(\$(gp|28)\)", txt):
            rel = "gp"
        mn = txt.split(None, 1)[0] if txt else ""
        if mn in ("jal", "j") and not re.search(r"\b0x[0-9a-fA-F]+\b", txt):
            rel = "26"
        if word is not None:
            d = dis(word)
            if mn.startswith("b") and not d.split()[0].startswith("b"):
                d = txt
            # keep the symbolic operand kinds of the listing; branch targets from the word
            if rel in ("hi", "lo", "gp") or d.startswith(".word"):
                d = txt if d.startswith(".word") else d
            off = branch_offset(word)
            if off is not None:
                d = re.sub(r"[^,\s]+$", "Lb" if off < 0 else "Lf", d)
            txt = d
        out.append((txt, rel, word, label))
        label = False
    return out


def blocks_of(insns):
    """Basic blocks: split at labels and after a branch's or jump's delay slot."""
    blocks, cur, pending = [], [], False
    for i, (txt, rel, word, label) in enumerate(insns):
        if label and cur:
            blocks.append(cur)
            cur = []
        cur.append(i)
        if pending:
            blocks.append(cur)
            cur, pending = [], False
            continue
        mn = txt.split(None, 1)[0] if txt else ""
        if (word is not None and has_delay(word)) or (word is None and (mn.startswith("b") or mn in ("j", "jal", "jr", "jalr"))):
            pending = True
    if cur:
        blocks.append(cur)
    return blocks


class Index:
    """The shapes by their instruction sequence (coarse), by the multiset of their instructions
    (the same instructions scheduled in another order) and by their signature instructions."""

    def __init__(self, db):
        self.db = db
        self.by_coarse = collections.defaultdict(list)
        self.by_bag = collections.defaultdict(list)
        self.by_sig = collections.defaultdict(list)
        for key, s in db["shapes"].items():
            co = tuple(s["coarse"])
            self.by_coarse[co].append(key)
            self.by_bag[tuple(sorted(co))].append(key)
            if len(co) <= 12:
                bag = collections.Counter(co)
                for m in set(c for c in co if SIGNATURE.match(c.split("@")[0])):
                    self.by_sig[m].append((bag, key))

    def ranked(self, keys, fine):
        f = " ; ".join(fine)
        scored = []
        for k in keys:
            s = self.db["shapes"][k]
            d = 0 if k == f else token_distance(fine, s["fine"])
            scored.append((d, -s["count"], k))
        scored.sort()
        return scored

    def lookup(self, fine, coarse):
        """(how, [(distance, -count, key)]): 'exact' (the same instruction sequence), 'reordered'
        (the same instructions in another order) or 'part' (known shapes inside it that hold its
        signature instructions)."""
        keys = self.by_coarse.get(tuple(coarse))
        if keys:
            return "exact", self.ranked(keys, fine)
        keys = self.by_bag.get(tuple(sorted(coarse)))
        if keys:
            mine = collections.Counter(fine)
            scored = []
            for k in keys:
                s = self.db["shapes"][k]
                common = sum((mine & collections.Counter(s["fine"])).values())
                scored.append((len(fine) - common, -s["count"], k))
            return "reordered", sorted(scored)
        bag = collections.Counter(coarse)
        mine = collections.Counter(fine)
        best = {}
        sigs = sorted(set(c for c in coarse if SIGNATURE.match(c.split("@")[0])), key=sig_rank)
        for m in sigs:
            for sbag, k in self.by_sig.get(m, ()):
                if len(sbag) > 1 or sum(sbag.values()) > 1:
                    if all(bag[x] >= n for x, n in sbag.items()):
                        s = self.db["shapes"][k]
                        common = sum((mine & collections.Counter(s["fine"])).values())
                        best[k] = (-sum(sbag.values()) - common, -s["count"], k)
            if best:
                break                       # the most telling signature that has known parts
        return "part", sorted(best.values())


SIG_ORDER = ["movn", "movz", "beql", "bnel", "beqzl", "bnezl", "blezl", "bgtzl", "bltzl", "bgezl", "bc1tl",
             "bc1fl", "div.s", "sqrt.s", "sltu", "sltiu", "slt", "slti", "qmfc2", "qmtc2", "lq", "sq", "cvt",
             "c.", "lqc2", "sqc2", "mtc1"]


def sig_rank(c):
    """How telling a signature instruction is (lower: rarer, more telling)."""
    m = c.split("@")[0]
    for i, p in enumerate(SIG_ORDER):
        if m == p or (p.endswith(".") and m.startswith(p)) or (p == "cvt" and m.startswith("cvt")):
            return i
    return len(SIG_ORDER)


def token_distance(a, b):
    """Edit distance between two instruction lists, counting operand differences as 1/2."""
    n, m = len(a), len(b)
    prev = list(range(m + 1))
    for i in range(1, n + 1):
        cur = [i] + [0] * m
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                c = 0
            elif a[i - 1].split()[0] == b[j - 1].split()[0]:
                c = 0.5
            else:
                c = 1
            cur[j] = min(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + c)
        prev = cur
    return prev[m]


STORES = {"sb", "sh", "sw", "sd", "sq", "swc1", "sdc1", "sqc2", "swl", "swr", "sdl", "sdr", "usw"}
DEST_SECOND = {"mtc1", "dmtc1", "ctc1", "qmtc2", "ctc2"}
ARG_REGS = ["r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"] + ["f%d" % k for k in range(12, 20)]
CALL_DEFS = ["r2", "r3", "f0", "f1"]
IGNORED = {"r0", "r28", "r29"}


def canon_reg(name):
    n = name.lstrip("$").lower()
    if n.startswith(("vf", "vi")) or re.match(r"^f\d+$", n):
        return n
    k = REGNUM.get(n)
    return "r%d" % k if k is not None else n


def defs_uses(text):
    """The registers an instruction writes and reads (with 'hilo', 'fcc', 'acc' for the
    multiplier, the FPU condition and the VU0 accumulator)."""
    parts = text.split(None, 1)
    if not parts:
        return set(), set()
    mn = parts[0].lower()
    ops = [o.strip() for o in parts[1].split(",")] if len(parts) > 1 else []
    regs, mem = [], set()
    for o in ops:
        m = OPERAND_RE.match(o)
        if m:
            mem.add(canon_reg(m.group("base")))
            regs.append(None)
        elif REG_RE.match(o):
            regs.append(canon_reg(o))
        else:
            regs.append(None)
    rr = [r for r in regs if r]
    d, u = set(), set(mem)
    if mn in STORES or mn.startswith("b") or mn == "jr":
        u |= set(rr)
        if mn.startswith("bc1"):
            u.add("fcc")
    elif mn == "jal" or mn == "jalr":
        u |= set(rr) | set(ARG_REGS)
        d |= set(CALL_DEFS) | {"r31"}
    elif mn in DEST_SECOND:
        if len(regs) > 1 and regs[1]:
            d.add(regs[1])
        if regs and regs[0]:
            u.add(regs[0])
    elif mn.startswith("c.") or mn in ("mult", "multu", "div", "divu", "dmult", "dmultu", "mult1", "multu1",
                                         "div1", "divu1", "madd", "maddu", "mthi", "mtlo"):
        u |= set(rr[1:] if mn in ("mult", "multu", "div", "divu") and len(rr) == 3 else rr)
        d.add("fcc" if mn.startswith("c.") else "hilo")
        if mn in ("mult", "multu") and len(rr) == 3 and rr[0] != "r0":
            d.add(rr[0])
        if mn.startswith("madd"):
            u.add("hilo")
    elif mn in ("mfhi", "mflo", "mfhi1", "mflo1"):
        d |= set(rr[:1])
        u.add("hilo")
    elif mn.startswith("v"):
        base = mn.split(".")[0]
        if base.startswith(("vmula", "vmadda", "vadda", "vsuba", "vmsuba", "vopmula")):
            d.add("acc")
            u |= set(rr)
        else:
            d |= set(rr[:1])
            u |= set(rr[1:])
        if base.startswith(("vmadd", "vmsub", "vopmsub")) and "a" not in base[5:6]:
            u.add("acc")
    else:
        d |= set(rr[:1])
        u |= set(rr[1:])
        if mn in ("movn", "movz", "movt", "movf") or mn.startswith(("ins", "dins")):
            u |= set(rr[:1])
    return d - IGNORED, u - IGNORED


def components(texts):
    """Groups of a block's instructions joined by their data flow (a value made by one and read
    by another): the query's stand-in for C statements, whose code gcc schedules together.
    texts: [instruction text]; returns lists of indices into it, in order of their first one."""
    parent = list(range(len(texts)))

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    order = list(range(len(texts)))
    for k in range(len(texts) - 1):
        mn = texts[order[k]].split()[:1]
        if mn and (mn[0].startswith("b") or mn[0] in ("j", "jal", "jr", "jalr")):
            order[k], order[k + 1] = order[k + 1], order[k]   # the delay slot runs first
    last_def = {}
    for i in order:
        t = texts[i]
        if t.split()[:1] == ["nop"]:
            continue
        d, u = defs_uses(t)
        for r in u:
            if r in last_def:
                parent[find(i)] = find(last_def[r])
        for r in d:
            last_def[r] = i
    # a branch-likely's delay slot runs only on the branch: it belongs to the branch's statement
    for k in range(len(texts) - 1):
        mn = texts[k].split()[:1]
        if mn and mn[0] in LIKELY and texts[k + 1].split()[:1] != ["nop"]:
            parent[find(k + 1)] = find(k)
    groups = collections.OrderedDict()
    prev = None
    for i, t in enumerate(texts):
        if t.split()[:1] == ["nop"]:
            nxt = next((k for k in range(i + 1, len(texts)) if texts[k].split()[:1] != ["nop"]), None)
            if nxt is not None and texts[nxt].split()[0] in ("div.s", "sqrt.s"):
                groups.setdefault(find(nxt), []).append(i)   # retail's padding before a div.s
            elif prev is not None:            # a hazard nop goes with the instruction before it
                groups.setdefault(find(prev), []).append(i)
            continue
        groups.setdefault(find(i), []).append(i)
        prev = i
    return sorted((sorted(g) for g in groups.values()), key=lambda g: g[0])


SIGNATURE = re.compile(r"^(movn|movz|sltu|sltiu|slt|slti|beql|bnel|beqzl|bnezl|blezl|bgtzl|bltzl|bgezl|"
                       r"div\.s|sqrt\.s|lqc2|sqc2|qmfc2|qmtc2|lq|sq|c\.\w+\.s|bc1tl|bc1fl|mtc1|cvt\.\w\.\w)$")


def family_hints(db, coarse):
    """Families whose signature instructions the block has: [(family, [(count, c_norm, example)])]."""
    tags = tag_families(tuple(c.split("@")[0] for c in coarse), tuple(coarse), {})
    return sorted(tags & set(FAMILY_TITLE) - {"call", "bitfield"})


def shape_text(fine):
    return " ; ".join(fine)


def top_forms(shape, n=3):
    forms = sorted(shape["c"].items(), key=lambda kv: (structural(kv[0]), -kv[1]["count"]))
    return forms[:n]


def cmd_query(a):
    db = load_db(a.db)
    index = Index(db)
    if a.snippet:
        text = a.snippet
    elif os.path.exists(a.input):
        text = open(a.input, errors="replace").read()
    else:
        path = find_asm(a.input)
        if not path:
            sys.exit("%s: no such file, and no asm/ file for a function of that name" % a.input)
        text = open(path, errors="replace").read()
    for line in query_lines(db, index, text, a.top):
        print(line)


def find_asm(name):
    """The asm/ file of a function: a level one (func_LNN_XXXXXXXX) in level NN's folder."""
    m = re.match(r"^func_L(\d\d)_([0-9A-F]{8})$", name)
    if m:
        import glob
        hits = glob.glob(os.path.join(ROOT, "asm", "levels", m.group(1) + "_*", "nonmatchings", "text",
                                      "func_%s.s" % m.group(2)))
        if hits:
            return hits[0]
    for dirpath, _, names in os.walk(os.path.join(ROOT, "asm")):
        if name + ".s" in names:
            return os.path.join(dirpath, name + ".s")
    return None


def query_lines(db, index, text, top=3, shapes=2):
    """The query's report: for each block its instructions, its families, and for each data-flow
    group in it the known shapes (exact, reordered, or the known parts that hold its signature
    instructions) and the C forms behind them."""
    insns = parse_asm(text)
    out = []
    if not insns:
        return ["no instructions found"]
    for bno, blk in enumerate(blocks_of(insns)):
        texts = [insns[i][0] for i in blk]
        fine, coarse = normalise([(insns[i][0], insns[i][1]) for i in blk])
        out.append("== block %d (%d instructions)" % (bno, len(blk)))
        for k, i in enumerate(blk):
            out.append("   %2d  %s" % (k, insns[i][0]))
        fams = family_hints(db, coarse)
        if fams:
            out.append("   families: " + ", ".join(FAMILY_TITLE[f] for f in fams))
        for comp in components(texts):
            if len(comp) == 1 and not SIGNATURE.match(texts[comp[0]].split()[0]):
                continue
            cf, cc = normalise([(insns[blk[k]][0], insns[blk[k]][1]) for k in comp])
            how, cands = index.lookup(cf, cc)
            if not cands:
                continue
            out.append("  {%s}  %s" % (",".join(str(k) for k in comp), shape_text(cf)))
            for d, negc, key in cands[:shapes if how != "exact" else 1]:
                s = db["shapes"][key]
                note = {"exact": "exact" if d == 0 else "same instructions, distance %g" % d,
                        "reordered": "same instructions in another order (%d operands differ)" % d,
                        "part": "a known part"}[how]
                out.append("     %s: %s  (seen %d times)" % (note, shape_text(s["fine"]) if how != "exact" or d else "",
                                                          s["count"]))
                for c_norm, c in top_forms(s, top):
                    ex = c["examples"][0]
                    out.append("      %4d x  %s" % (c["count"], c_norm))
                    out.append("             e.g. %s  (%s, %s:%d)" % (ex["c"][:140], ex["fn"], ex["file"], ex["line"]))
    return out


# --------------------------------------------------------------------------------------------
# report
# --------------------------------------------------------------------------------------------

KEEP_STRUCTURAL = {"loop", "cross_jump"}


def form_in_family(c_norm, c, fam):
    """How many of this C form's fragments of the shape count for the family (0: none)."""
    if fam in KEEP_STRUCTURAL or not structural(c_norm):
        return max(0, c["tags"].get(fam, 0) - c["tags"].get("prologue", 0))
    return 0


def family_example(c, fam):
    """An example of the C form for the family: for a cross jump one that names its tail."""
    if fam == "cross_jump":
        for e in c["examples"]:
            if e.get("tail"):
                return e
    return c["examples"][0]


def family_shapes(db, fam, n):
    """The shapes most often seen in a family: [(count of its fragments in the family, key)]."""
    rows = []
    for k, s in db["shapes"].items():
        if fam not in s["tags"]:
            continue
        cnt = sum(form_in_family(cn, c, fam) for cn, c in s["c"].items())
        if cnt:
            rows.append((cnt, k))
    rows.sort(key=lambda r: (-r[0], r[1]))
    return rows[:n]


def family_forms(db, fam, n):
    """The C forms most often behind a family, over all its shapes: [(count, c_norm, example, shape)]."""
    agg = {}
    for k, s in db["shapes"].items():
        if fam not in s["tags"]:
            continue
        for c_norm, c in s["c"].items():
            n_ = form_in_family(c_norm, c, fam)
            if not n_:
                continue
            e = agg.setdefault(c_norm, [0, c["examples"][0], k, 0])
            e[0] += n_
            if n_ > e[3]:
                e[1], e[2], e[3] = family_example(c, fam), k, n_
    rows = sorted(((v[0], c, v[1], v[2]) for c, v in agg.items()), key=lambda r: (-r[0], r[1]))
    return rows[:n]


def md_escape(s):
    return s.replace("|", "\\|").replace("`", "'")


def report_text(db, per_family=8):
    fam_count = collections.Counter()
    fam_shapes = collections.Counter()
    for s in db["shapes"].values():
        fams = set()
        for cn, c in s["c"].items():
            for t in c["tags"]:
                n_ = form_in_family(cn, c, t) if t in FAMILY_TITLE else 0
                if n_:
                    fam_count[t] += n_
                    fams.add(t)
        for t in fams:
            fam_shapes[t] += 1
    L = []
    L.append("# Idiom cookbook: which C gives which assembly")
    L.append("")
    L.append("Generated by `python3 tools/idioms.py report` from `build/idioms/db.json.gz` "
             "(`tools/idioms.py build` makes it; see the tool's docstring). Do not edit by hand.")
    L.append("")
    L.append("Mined from **%d** functions that are C in `src/` and compile with `-g` to retail's code "
             "(another %d are copies of one of them, the same code in another file or level, and count once; "
             "%d were left out because `-g` changes their code; the %d C functions of Sony's library files, "
             "built with other compilers, are not compiled), cut into **%d** fragments (one C statement and "
             "the instructions gcc made for it, or one inline helper call) of **%d** distinct shapes." % (
                 db["functions"], db.get("copies", 0), db["skipped"], db.get("library", 0), db["fragments"],
                 len(db["shapes"])))
    L.append("")
    L.append("How to read it: an assembly shape has registers as classes numbered in order of "
             "appearance (`t1`, `a1`, `v1`, `s1`, `fa1` = $f12-$f19, `fv1` = $f0-$f3, `vf1`), immediates in "
             "buckets (`0`, `1`, `s` small, `p2` a power of two, `i16`, `neg`), `%gp`/`%hi`/`%lo` for "
             "relocated operands (`+` when the symbol has an offset), `F` a call target, `Lf`/`Lb` a "
             "forward/backward branch. A C form has `v` for a local or parameter, `G` a `D_` global, `F` a "
             "function, `m` a member, `N`/`Nf` a number. To ask for a block of an unmatched function: "
             "`python3 tools/idioms.py query asm/.../func_X.s`.")
    L.append("")
    L.append("| Family | Fragments | Shapes |")
    L.append("| --- | ---: | ---: |")
    for key, title, _ in FAMILIES:
        L.append("| [%s](#%s) | %d | %d |" % (title, key.replace("_", "-"), fam_count[key], fam_shapes[key]))
    L.append("")
    for key, title, what in FAMILIES:
        L.append('<a id="%s"></a>' % key.replace("_", "-"))
        L.append("## %s" % title)
        L.append("")
        L.append(what)
        L.append("")
        forms = family_forms(db, key, per_family)
        if not forms:
            L.append("(none found)")
            L.append("")
            continue
        L.append("Most frequent C forms:")
        L.append("")
        L.append("| Count | C form | Example |")
        L.append("| ---: | --- | --- |")
        for cnt, c_norm, ex, _ in forms:
            tail = (" -> tail `%s`" % md_escape(ex["tail"])[:80]) if ex.get("tail") else ""
            L.append("| %d | `%s` | `%s`%s (%s, %s:%d) |" % (cnt, md_escape(c_norm)[:110], md_escape(ex["c"])[:110],
                                                         tail, ex["fn"], ex["file"], ex["line"]))
        L.append("")
        L.append("Most frequent shapes and the C behind them:")
        L.append("")
        for cnt, k in family_shapes(db, key, max(3, per_family // 2)):
            s = db["shapes"][k]
            L.append("- **%d x** `%s`" % (cnt, md_escape(shape_text(s["fine"]))[:300]))
            forms = sorted(((form_in_family(cn, c, key), cn, c) for cn, c in s["c"].items()
                            if form_in_family(cn, c, key)), key=lambda r: (-r[0], r[1]))
            for n_, c_norm, c in forms[:3]:
                ex = family_example(c, key)
                L.append("  - %d x `%s`, e.g. `%s` (%s, %s:%d)" % (
                    n_, md_escape(c_norm)[:120], md_escape(ex["c"])[:120], ex["fn"], ex["file"], ex["line"]))
        L.append("")
    return "\n".join(L) + "\n"


def cmd_report(a):
    db = load_db(a.db)
    text = report_text(db, a.per_family)
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    with open(a.out, "w") as fh:
        fh.write(text)
    print("idioms report: %s (%d lines)" % (os.path.relpath(a.out, ROOT), text.count("\n")))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("build", help="compile with -g and mine")
    b.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4)
    b.add_argument("--shard", help="I/N or I,J,.../N: only the files whose index mod N is one of these (for several machines)")
    b.add_argument("--compile-only", action="store_true", help="stop after build/idioms/raw/")
    b.add_argument("--force", action="store_true", help="compile files whose raw record exists too")
    b.add_argument("--files", nargs="*", help="only these source files (paths from the repo root)")
    sub.add_parser("mine", help="build/idioms/raw/ -> build/idioms/db.json.gz")
    q = sub.add_parser("query", help="the closest known shapes for each block of an unmatched function")
    q.add_argument("input", nargs="?", default="", help="a .s file, or a function name (its asm/ file)")
    q.add_argument("--snippet", help="assembly text instead of a file (';' or newlines between instructions)")
    q.add_argument("--top", type=int, default=3)
    q.add_argument("--db", default=DB)
    r = sub.add_parser("report", help="write docs/matching/IDIOMS.md")
    r.add_argument("--out", default=REPORT)
    r.add_argument("--per-family", type=int, default=8)
    r.add_argument("--db", default=DB)
    a = ap.parse_args(argv)
    {"build": cmd_build, "mine": cmd_mine, "query": cmd_query, "report": cmd_report}[a.cmd](a)


if __name__ == "__main__":
    main()
