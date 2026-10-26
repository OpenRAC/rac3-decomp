#!/usr/bin/env python3
"""asm_build.py: build a disc's programs from their assembly alone, and check each against the disc.

    python3 tools/asm_build.py --version us [-P 8] [--rounds 3] [TARGET ...]   # every program without names
    python3 tools/asm_build.py --version us --list

This is how the second version (NTSC-U, docs/versions.md) is built until C is built into its
programs: rac-deadlocked-decomp's tools/asm_programs.py and build_levels.py, applied to this game.
The PAL build (tools/build.py, tools/build_levels.py) is not this: it builds src/'s C with splat's
assembly. `--version pal` works too, as a check of PAL's dumps and tables.

Targets: `frontbin`, `boot_elf`, `i5bootn` and `level_NN` for each level of the version
(config/us/levels/levels.tsv). For each one:

  1. its assembly, from the dump (tools/levels.py dump) and the committed function tables
     (config/us/inventory.tsv for the core programs, config/us/levels/functions.tsv for the
     levels): asm/us/<target>/<section>/func_XXXXXXXX.s, one per function. The instructions
     come from rabbitizer (R5900, no pseudo-instructions); branch targets are local labels, calls
     to a function of the same program use its name, the rest are addresses. A word that is not
     an instruction the assembler gives back as it is (VU0 macro instructions, COP0 moves,
     ldc1/sdc1, data among code, branches between parts) is a `.word` with its disassembly in a
     comment; asm/us/<target>/words.txt lists the ones the build found (--rounds). .vutext (VU
     microcode) and the data sections are `.word` lines.
  2. a code section is assembled in parts of about 8 KB that no branch crosses (the old
     assembler takes time quadratic in a file's size), each with binutils 2.10-ee's ee-as (SN
     ProDG 2.4's `sn-prodg-24-ee`, run natively on Linux; --bin);
  3. ee-ld links every section at its address (build/us/<target>/<target>.ld); the linked
     sections are written back into the dump's ELF layout and into the disc's program format
     (tools/levels.py), and the target prints `MATCH` when both SHA-1s are the dump's
     (config/us/programs.tsv, config/us/levels/levels.tsv).

When words differ, the first differing word of each section is added to words.txt and the target
is rebuilt, up to --rounds times. A watchdog (--timeout) stops an assembler that hangs.

asm/ holds the disc's bytes in another form: it is never committed (.gitignore).
"""
import argparse
import bisect
import functools
import hashlib
import os
import re
import struct
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor

import rabbitizer

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402
import inventory as inv  # noqa: E402
import levels  # noqa: E402

rabbitizer.config.pseudos_enablePseudos = False
rabbitizer.config.misc_expandJalr = True
R5900 = rabbitizer.InstrCategory.R5900

# binutils 2.10-ee exists only as i386 Linux programs: a Mac runs them in a linux/386 container,
# through the mac-bin wrappers (docs/versions.md, Machines)
BIN = os.path.expanduser(os.environ.get("UYA_BINUTILS", "~/Projects/RAC/rac3-toolchains/" + (
    "mac-bin" if sys.platform == "darwin" else "sn-prodg-24-ee/gcc/bin")))
ASFLAGS = ["-EL", "-mips3", "-mcpu=r5900"]
CODE = {".text", "core.text"}            # EE code; .vutext is VU microcode, written as words
# instructions binutils 2.10-ee's assembler has no R5900 encoding for: written as .word
NO_R5900 = {"ldc1", "sdc1", "mfc0", "mtc0", "ll", "sc", "lld", "scd"}
CHUNK_WORDS = 2048
PRELUDE = """.set noreorder
.set noat
.set nomacro
.macro glabel label
    .global \\label
    .type \\label, @function
    \\label:
.endm
"""
GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
REG = re.compile(r"\$(%s)\b" % "|".join(GPR))
INCLUDE = re.compile(r'^\.include "([^"]+)"$', re.M)
ERROR = re.compile(r"^(\S+?):(\d+): (?:Error|Warning):", re.M)
ADDR = re.compile(r"^/\* ([0-9A-F]{6,8}) [0-9A-F]{8} \*/")


# --- the programs ---------------------------------------------------------------------

def targets():
    """{target: (kind, dump path, ELF SHA-1, disc program SHA-1 or None)}"""
    out = {}
    if version.is_us():
        for name, row in levels.read_programs_table().items():
            out[name] = ("core", os.path.join(ROOT, row["path"]), row["elf_sha1"], row["disc_sha1"])
    else:
        import targets as tg
        for name, t in tg.TARGETS.items():
            out[name] = ("core", t.path("elf"), t.sha1, None)
    for row in levels.read_table():
        out[levels.target_name(row["number"])] = ("level", levels.elf_path(row["number"]), row["elf_sha1"],
                                                  row["overlay_sha1"])
    return out


def generic_sections(data):
    """[(name, address, size, type, bytes)] of every allocated section of an ELF, from its headers."""
    shoff = struct.unpack_from("<I", data, 0x20)[0]
    shnum, shstr = struct.unpack_from("<HH", data, 0x30)
    sh = [struct.unpack_from("<10I", data, shoff + 40 * i) for i in range(shnum)]
    st = sh[shstr][4]
    out = []
    for s in sh[1:]:
        name = data[st + s[0]:data.index(b"\0", st + s[0])].decode()
        if s[1] == 3 or not s[5]:
            continue
        out.append((name, s[3], s[5], s[1], bytes(s[5]) if s[1] == 8 else data[s[4]:s[4] + s[5]]))
    return out


def sections_of(target, path):
    """(entry, [(name, address, size, type, bytes)]) of a program's dump, in its file's order."""
    data = open(path, "rb").read()
    entry = struct.unpack_from("<I", data, 0x18)[0]
    if target == "boot_elf":
        _, secs = levels.read_core_elf(data)
        return entry, [(n[0], a, sz, k, b) for n, (a, sz, k, b) in zip(levels.BOOT_SECTIONS, secs)]
    if target == "i5bootn":
        return entry, generic_sections(data)
    _, secs = levels.read_elf(data)
    return entry, [(n[0], a, sz, k, b if k != 8 else bytes(sz)) for n, (a, sz, k, b) in zip(levels.SECTIONS, secs)]


def rebuilt(target, path, entry, secs):
    """(ELF bytes, disc program bytes) for built sections, in the dump's layouts (tools/levels.py)."""
    four = [(a, n, k, b) for _, a, n, k, b in secs]
    if target == "boot_elf":
        return levels.boot_elf_image(entry, four), levels.records(entry, four)
    if target == "i5bootn":
        data = bytearray(open(path, "rb").read())
        shoff = struct.unpack_from("<I", data, 0x20)[0]
        shnum = struct.unpack_from("<H", data, 0x30)[0]
        by_addr = {(s[0], s[1]): s[4] for s in secs}
        for i in range(1, shnum):
            sh = struct.unpack_from("<10I", data, shoff + 40 * i)
            if sh[1] in (3, 8) or not sh[5]:
                continue
            for (name, a), b in by_addr.items():
                if a == sh[3] and len(b) == sh[5]:
                    data[sh[4]:sh[4] + sh[5]] = b
        return bytes(data), bytes(data)
    elf = levels.write_elf(entry, four, lead_zero=(target == "frontbin"))
    return elf, levels.records(entry, four)


def function_starts(target, base, size):
    """{address: name} of a code section's functions (the committed tables)."""
    out = {}
    if target in levels.CORE_PROGRAMS:
        for sec, a, n, kind in inv.read_inventory().get(target, []):
            if base <= a < base + size:
                out[a] = "f_%08X" % a
        return out
    import level_catalogue as lc
    n = int(target.split("_")[1])
    for name, kind, sz, fp, rem, places in lc.read_catalogue():
        for lv, a in places:
            if lv == n and base <= a < base + size:
                out[a] = "f_%08X" % a
    return out


# --- assembly ---------------------------------------------------------------------------

def asm_root():
    return version.asm()


def build_root():
    return version.build()


def read_words_txt(target):
    p = os.path.join(asm_root(), target, "words.txt")
    if not os.path.exists(p):
        return set()
    return {int(l.split()[0], 16) for l in open(p) if l.strip() and not l.startswith("#")}


def chunks_of(ins, base, order):
    """Where a code section is cut into parts: at a 16-aligned function start no branch crosses,
    every CHUNK_WORDS words or more (each part a multiple of 16 bytes, so they link back to back)."""
    n = len(ins)
    cover = [0] * (n + 2)
    for i, x in enumerate(ins):
        if x.isValid() and x.isBranch():
            t = (x.getBranchVramGeneric() - base) // 4
            lo, hi = min(i, t), max(i, t)
            if 0 <= lo and hi < n:
                cover[lo + 1] += 1
                cover[hi + 1] -= 1
    crossed, c = [False] * (n + 1), 0
    for k in range(n + 1):
        c += cover[k]
        crossed[k] = c > 0
    cuts, last = [base], base
    for a in order[1:]:
        k = (a - base) // 4
        if a % 16 == 0 and not crossed[k] and (a - last) // 4 >= CHUNK_WORDS:
            cuts.append(a)
            last = a
    return cuts


def code_section(base, data, starts, as_words, extra_cuts=()):
    """([(name, start, text)], [part starts]) of a code section. EXTRA_CUTS: function starts that
    also start a part (a C function's place, and the function after it)."""
    w = inv.words(data)
    n = len(w)
    ins = [rabbitizer.Instruction(x, base + 4 * i, category=R5900) for i, x in enumerate(w)]
    order = sorted(a for a in starts if base <= a < base + 4 * n)
    if not order or order[0] != base:
        order.insert(0, base)
    cuts = sorted(set(chunks_of(ins, base, order)) | (set(extra_cuts) & set(order)))
    part = lambda addr: bisect.bisect_right(cuts, addr)
    labels = set()
    for i, x in enumerate(ins):
        if x.isValid() and (x.isBranch() or (x.isJump() and not x.isJrRa() and x.isJType())):
            t = x.getBranchVramGeneric() if x.isBranch() else x.getInstrIndexAsVram()
            if base <= t < base + 4 * n and not (x.isJType() and t in starts) and part(t) == part(base + 4 * i):
                labels.add(t)
    names = dict(starts)
    names.setdefault(base, "pad_%08X" % base)
    out = []
    for k, a in enumerate(order):
        end = order[k + 1] if k + 1 < len(order) else base + 4 * n
        lines = ["glabel %s" % names[a]]
        for addr in range(a, end, 4):
            i = (addr - base) // 4
            x = ins[i]
            if addr in labels:
                lines.append(".L%08X:" % addr)
            word = w[i]
            text = None
            if addr not in as_words and x.isValid() and x.isImplemented() and not x.isDouble() \
                    and x.getOpcodeName() not in NO_R5900:
                try:
                    if x.isBranch():
                        t = x.getBranchVramGeneric()
                        text = x.disassemble(immOverride=".L%08X" % t) if t in labels else None
                    elif x.isJType():
                        t = x.getInstrIndexAsVram()
                        if t in starts:
                            text = x.disassemble(immOverride=starts[t])
                        elif t in labels and part(t) == part(addr):
                            text = x.disassemble(immOverride=".L%08X" % t)
                        else:
                            text = x.disassemble(immOverride="0x%X" % t)
                    else:
                        text = x.disassemble()
                except Exception:
                    text = None
            if text is None or "\n" in text:
                dis = x.disassemble() if x.isValid() else "?"
                lines.append("/* %06X %08X */ .word 0x%08X  /* %s */" % (addr, word, word, dis.replace("*/", "* /")))
            else:
                lines.append("/* %06X %08X */ %s" % (addr, word, text))
        out.append((names[a], a, "\n".join(lines) + "\n"))
    return out, cuts


def data_text(data):
    w = inv.words(data)
    out = []
    for i in range(0, len(w), 4):
        out.append(".word " + ", ".join("0x%08X" % x for x in w[i:i + 4]))
    tail = data[len(w) * 4:]
    if tail:
        out.append(".byte " + ", ".join("0x%02X" % b for b in tail))
    return "\n".join(out) + "\n"


def safe(name):
    return name.lstrip(".").replace(".", "_")


def write_target(target, path, with_c=False):
    """asm/<version>/<target>/ and build/<version>/<target>/<target>.ld, objects.txt. WITH_C: the
    functions of tools/c_objects.py's objects are linked from them (c_pieces())."""
    entry, secs = sections_of(target, path)
    cpieces, symbols, dropped = c_pieces(target, secs) if with_c else ({}, {}, [])
    as_words = read_words_txt(target)
    root = os.path.join(asm_root(), target)
    os.makedirs(root, exist_ok=True)
    paths = {}
    for i, (name, a, n, kind, b) in enumerate(secs):
        if kind == 8:
            continue                      # .bss: zeros, no bytes to build
        key = "%d_%s" % (i, safe(name))
        if name in CODE:
            d = os.path.join(root, key)
            pd = os.path.join(root, key + ".parts")
            os.makedirs(d, exist_ok=True)
            os.makedirs(pd, exist_ok=True)
            starts = function_starts(target, a, n)
            order = sorted(starts)
            cs = {x: v for x, v in cpieces.items() if a <= x < a + n}
            nxt = {x: next((y for y in order if y >= x + max(4, v[2])), a + n) for x, v in cs.items()}
            within = lambda fa: any(x < fa < x + v[2] for x, v in cs.items())
            funcs, cuts = code_section(a, b, starts, as_words, set(cs) | set(nxt.values()))
            parts = [[] for _ in cuts]
            for fname, fa, text in funcs:
                if fa in cs:
                    # the C object, then the zero words after it up to the next function
                    obj, size = cs[fa][0], cs[fa][2]
                    pad = b[fa - a + size:nxt[fa] - a]
                    parts[bisect.bisect_right(cuts, fa) - 1].append(("C", obj, pad, fa + size))
                    continue
                if within(fa):
                    continue                  # inside a whole file's object
                fp = os.path.join(d, fname + ".s")
                body = "/* %s %s 0x%08X */\n%s" % (target, name, fa, text)
                if not os.path.exists(fp) or open(fp).read() != body:
                    open(fp, "w").write(body)
                parts[bisect.bisect_right(cuts, fa) - 1].append('.include "%s"' % os.path.relpath(fp, ROOT))
            files = []
            for k, incs in enumerate(parts):
                if incs and isinstance(incs[0], tuple):
                    _, obj, pad, at = incs[0]
                    files.append(("C", obj))
                    if pad:
                        fp = os.path.join(pd, "%08X.s" % at)
                        open(fp, "w").write(PRELUDE + ".text\n" + data_text(pad))
                        files.append(fp)
                    continue
                fp = os.path.join(pd, "%08X.s" % cuts[k])
                open(fp, "w").write(PRELUDE + ".text\n" + "\n".join(incs) + "\n")
                files.append(fp)
            paths[i] = files
        else:
            ins = sorted((at, obj, sname) for _, p in cpieces.items() if len(p) > 4
                         for sname, at in p[4] for obj in [p[0]] if a <= at < a + n)
            if not ins:
                p = os.path.join(root, key + ".s")
                open(p, "w").write(".text\n" + data_text(b))
                paths[i] = [p]
                continue
            # a whole file's data, linked at the place its code reads it; the rest as words
            import level_symbols as ls
            files, at0 = [], a
            for at, obj, sname in ins:
                size = ls.section_size(obj, sname)
                if at > at0:
                    p = os.path.join(root, "%s_%08X.s" % (key, at0))
                    open(p, "w").write(".text\n" + data_text(b[at0 - a:at - a]))
                    files.append(p)
                files.append(("D", obj, sname))
                at0 = at + size
            if at0 < a + n:
                p = os.path.join(root, "%s_%08X.s" % (key, at0))
                open(p, "w").write(".text\n" + data_text(b[at0 - a:]))
                files.append(p)
            paths[i] = files
    d = os.path.join(build_root(), target)
    os.makedirs(d, exist_ok=True)
    lines = ["/* %s (%s): tools/asm_build.py; every section at its address. */" % (target, version.disc_id())]
    if cpieces:
        lines.append("/* the names the C uses, read from the disc's bytes (tools/level_symbols.py derive()) */")
        lines.append("_gp = 0x%X;" % GP)
        lines += ["%s = 0x%08X;" % (k, v) for k, v in sorted(symbols.items())]
    lines += ["SECTIONS", "{"]
    on = lambda p: os.path.relpath(p[1], ROOT) if isinstance(p, tuple) else obj_name(target, p)
    sec_of = lambda p: p[2] if isinstance(p, tuple) and p[0] == "D" else ".text"
    # output sections named by position (sec.0, sec.1, ...): ld treats a .reginfo by its name
    for i, (name, a, n, kind, b) in enumerate(secs):
        if i in paths:
            objs = " ".join("%s(%s)" % (on(p), sec_of(p)) for p in paths[i])
            lines.append("    sec.%d 0x%X : { %s }  /* %s */" % (i, a, objs, name))
    lines += ["    /DISCARD/ : { *(*) }", "}"]
    open(os.path.join(d, target + ".ld"), "w").write("\n".join(lines) + "\n")
    open(os.path.join(d, "objects.txt"), "w").write(
        "".join("%s\t%s\t%d\n" % ("-" if isinstance(p, tuple) else os.path.relpath(p, ROOT), on(p), i)
                for i in sorted(paths) for p in paths[i]))
    open(os.path.join(d, "c_functions.txt"), "w").write(
        "".join("%08X\t%s\n" % (x, v[1]) for x, v in sorted(cpieces.items()) if len(v) == 3) +
        "".join("%08X\t%s\n" % (x, n) for x, v in sorted(cpieces.items()) if len(v) > 3 for n in v[3]) +
        "".join("# left as assembly: %08X %s: %s\n" % x for x in dropped))


def obj_name(target, src):
    rel = os.path.relpath(src, asm_root()).replace(os.sep, "_").replace(".parts", "")
    return os.path.relpath(os.path.join(build_root(), target, "obj", rel[:-2] + ".o"), ROOT)


# --- C (--c) -----------------------------------------------------------------------------

GP = 0x1DC8B0


def c_pieces(target, secs):
    """({address: (object, name, size)}, {name: value}, [(address, name, why)]) of the C linked
    into one NTSC-U program: tools/c_objects.py's objects at their places here. Each object is laid
    over the disc's bytes at its place (level_symbols.derive(): the words without relocations
    must be the disc's, each relocation gives its name's value); a name gets one value in the
    program, a function's name the address its twin has here (version_map.UsNames), a name an
    object defines that object's place. A function that disagrees stays assembly."""
    import c_objects
    import level_symbols as ls
    import version_map as vm
    m = vm.Map()
    built = c_objects.read_index()
    code = {name: (a, b) for name, a, n, k, b in secs if name in CODE}
    level = int(target.split("_")[1]) if target.startswith("level_") else None
    program = "levels" if level is not None else target
    known = vm.UsNames(m, program, level)
    cand, dropped = [], []
    for prog, name, places, rel, nat in c_objects.placements():
        if (prog, name) not in built:
            continue
        for t, addr in places:
            if t != target:
                continue
            if addr % 8:
                # an object's code starts 8-aligned (gcc's .align 3), as C does in PAL's build
                dropped.append((addr, name, "starts on a 4-mod-8 address here; C starts 8-aligned"))
            else:
                cand.append((addr, name, os.path.join(ROOT, built[(prog, name)]), nat))
    pieces, values, where = {}, {}, {}
    for addr, name, obj, native in sorted(cand):
        sec = next(((base, data) for base, data in code.values() if base <= addr < base + len(data)), None)
        o = ls.read_object(obj)
        if o["extra"]:
            continue
        if sec is None or name not in o["defined"]:
            dropped.append((addr, name, "not in a code section, or the object does not define it"))
            continue
        base, data = sec
        try:
            v = ls.derive(o["text"], data[addr - base:addr - base + len(o["text"])], o["relocs"], addr, GP)
        except ls.Differ as e:
            dropped.append((addr, name, "+0x%X: %s" % (e.offset, e.why)))
            continue
        mine = {k: x for k, x in v.items() if not k.startswith("\u00a7")}
        own = {k: addr + off for k, off in o["defined"].items() if k in o["exported"]}
        bad = None
        for k, x in mine.items():
            exp = (vm.NativeNames(level) if native else known).expected(k) if k not in own else own[k]
            if k in values and values[k] != x:
                bad = "%s is 0x%08X here, 0x%08X for %s" % (k, x, values[k], where[k])
            elif exp is not None and exp != x:
                bad = "%s should be 0x%08X, the bytes make it 0x%08X" % (k, exp, x)
            if bad:
                break
        if bad is None:
            for k, x in own.items():
                if values.get(k, x) != x:
                    bad = "%s is defined at 0x%08X but used as 0x%08X" % (k, x, values[k])
        if bad:
            dropped.append((addr, name, bad))
            continue
        for k, x in mine.items():
            values.setdefault(k, x)
            where.setdefault(k, name)
        for k, x in own.items():
            values[k] = x
            where[k] = name
        pieces[addr] = (obj, name, len(o["text"]))
    # whole PAL files (c_objects.file_pieces()): one object over several functions, its data
    # sections linked where its code reads them
    for prog, rel, s0, us0, rel_obj, names in (c_objects.read_files() if level is None else []):
        if prog != target:
            continue
        obj = os.path.join(ROOT, rel_obj)
        resolver = vm.NativeNames(None) if rel.startswith("src/us/") else known
        o = ls.read_object(obj)
        sec = next(((base, data) for base, data in code.values() if base <= us0 < base + len(data)), None)
        if sec is None or us0 % 8:
            dropped.append((us0, rel, "not 8-aligned in a code section"))
            continue
        base, data = sec
        try:
            v = ls.derive(o["text"], data[us0 - base:us0 - base + len(o["text"])], o["relocs"], us0, GP)
        except ls.Differ as e:
            dropped.append((us0, rel, "+0x%X: %s" % (e.offset, e.why)))
            continue
        own = {k: us0 + off for k, off in o["defined"].items() if k in o["exported"]}
        mine = {k: x for k, x in v.items() if not k.startswith("\u00a7")}
        bad = None
        for k, x in list(mine.items()) + list(own.items()):
            exp = own.get(k) if k in own else resolver.expected(k)
            if exp is not None and exp != x or k in values and values[k] != x:
                bad = "%s: 0x%08X against 0x%08X" % (k, x, exp if exp is not None else values[k])
                break
        datas = []
        for sname in o["extra"]:
            at = v.get("\u00a7" + sname) or find_data(obj, sname, secs)
            if at is None:
                bad = "its %s is neither read from its code nor found once in the disc's data" % sname
                break
            datas.append((sname, at))
        if bad:
            dropped.append((us0, rel, bad))
            continue
        end = us0 + len(o["text"])
        for x in [x for x in pieces if us0 <= x < end]:
            del pieces[x]
        pieces[us0] = (obj, rel, len(o["text"]), names, datas)
        for k, x in mine.items():
            values.setdefault(k, x)
            where.setdefault(k, rel)
        for k, x in own.items():
            values[k] = x
    defined = {k for _, p in pieces.items() for k in ls.read_object(p[0])["exported"]}
    out = {k: x for k, x in values.items() if k not in defined}
    # the assembly's own label for a function that is C now (its calls from the assembly)
    out.update({"f_%08X" % x: x for x in pieces})
    # and of every function inside a whole file's object
    for x, p in pieces.items():
        if len(p) > 3:
            for name, a, n, k, b in secs:
                if name in CODE and a <= x < a + n:
                    out.update({"f_%08X" % y: y for y in function_starts(target, x, p[2])})
    return pieces, out, dropped


def find_data(obj, sname, secs):
    """The one place in the program's data sections whose bytes are the object's section SNAME,
    its relocated words left out; None when it is not exactly one."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    with open(obj, "rb") as f:
        e = ELFFile(f)
        sec = e.get_section_by_name(sname)
        data = sec.data()
        idx = [i for i, s in enumerate(e.iter_sections()) if s.name == sname][0]
        rel = {r["r_offset"] for s in e.iter_sections() if isinstance(s, RelocationSection) and s["sh_info"] == idx
               for r in s.iter_relocations()}
    if len(data) < 16:
        return None
    # the longest run of words without a relocation is the anchor
    best, cur = (0, 0), None
    for o in range(0, len(data) - 3, 4):
        if o in rel:
            cur = None
            continue
        cur = cur if cur is not None else o
        if o + 4 - cur > best[1] - best[0]:
            best = (cur, o + 4)
    anchor = data[best[0]:best[1]]
    if len(anchor) < 16:
        return None
    hits = []
    for name, a, n, k, b in secs:
        if name in CODE or k == 8:
            continue
        i = b.find(anchor)
        while i >= 0:
            j = i - best[0]
            if j >= 0 and j % 4 == 0 and j + len(data) <= len(b) and all(
                    b[j + o:j + o + 4] == data[o:o + 4] for o in range(0, len(data) - 3, 4) if o not in rel):
                hits.append(a + j)
            i = b.find(anchor, i + 1)
    return hits[0] if len(hits) == 1 else None


# --- the build --------------------------------------------------------------------------

def flatten(src, dst):
    """The part's .s with its .include lines expanded and the registers' ABI names as numbers
    (binutils 2.10-ee's assembler knows only $sp, $ra, $gp, $fp and $at by name)."""
    text = open(os.path.join(ROOT, src)).read()
    text = INCLUDE.sub(lambda m: open(os.path.join(ROOT, m.group(1))).read(), text)
    text = REG.sub(lambda m: "$%d" % GPR.index(m.group(1)), text)
    os.makedirs(os.path.dirname(os.path.join(ROOT, dst)), exist_ok=True)
    open(os.path.join(ROOT, dst), "w").write(text)


def as_errors(flat, log_text):
    lines = open(os.path.join(ROOT, flat)).read().split("\n")
    out = set()
    for f, n in ERROR.findall(log_text):
        if os.path.normpath(f) == os.path.normpath(flat):
            m = ADDR.match(lines[int(n) - 1])
            if m:
                out.add(int(m.group(1), 16))
    return out


def build(target, info, a, log):
    """Assemble and link one target. Returns (ok, message, {section index: addresses to make .word})."""
    kind, path, elf_sha1, prog_sha1 = info
    d = os.path.join(build_root(), target)
    objs = [l.rstrip("\n").split("\t") for l in open(os.path.join(d, "objects.txt"))]
    refused = {}
    for src, obj, sec in objs:
        if src == "-":
            continue                      # a C function's object (tools/c_objects.py)
        flat = obj[:-2] + ".s"
        flatten(src, flat)
        cmd = [os.path.join(a.bin, "ee-as")] + ASFLAGS + ["-o", os.path.join(ROOT, obj), flat]
        try:
            r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=a.timeout)
        except subprocess.TimeoutExpired:
            return False, "ee-as hung on %s (watchdog: %d s)" % (src, a.timeout), {}
        log.write("+ %s\n%s%s" % (" ".join(cmd), r.stdout, r.stderr[-20000:]))
        if r.returncode:
            bad = as_errors(flat, r.stderr)
            refused.setdefault(int(sec), set()).update(bad)
            if not bad:
                return False, "ee-as failed on %s" % src, {}
    if refused:
        return False, "ee-as refused %d instructions" % sum(len(v) for v in refused.values()), refused
    out = os.path.join(d, target + ".elf")
    cmd = [os.path.join(a.bin, "ee-ld"), "-T", os.path.join(d, target + ".ld"), "-o", out]
    log.write("+ %s\n" % " ".join(cmd))
    log.flush()
    if subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, timeout=a.timeout).returncode:
        return False, "ee-ld failed", {}
    got = {name: b for name, _, _, _, b in generic_sections(open(out, "rb").read())}
    entry, want = sections_of(target, path)
    built, diffs, where = [], {}, []
    for i, (name, addr, n, k, b) in enumerate(want):
        g = b if k == 8 else got.get("sec.%d" % i, b"")
        if g != b:
            off = next((j for j in range(0, min(len(g), len(b)), 4) if g[j:j + 4] != b[j:j + 4]), min(len(g), len(b)))
            diffs[i] = {addr + off}
            where.append("%s at 0x%X (size 0x%X, disc 0x%X)" % (name, addr + off, len(g), len(b)))
        built.append((name, addr, n, k, g))
    if diffs:
        return False, "differs: " + ", ".join(where), diffs
    elf, prog = rebuilt(target, path, entry, built)
    he, hp = hashlib.sha1(elf).hexdigest(), hashlib.sha1(prog).hexdigest()
    if he != elf_sha1 or (prog_sha1 and hp != prog_sha1):
        return False, "the SHA-1s are %s (ELF) and %s (program), the dump's %s and %s" % (he, hp, elf_sha1, prog_sha1), {}
    cf = os.path.join(d, "c_functions.txt")
    nc = sum(1 for l in open(cf) if not l.startswith("#")) if os.path.exists(cf) else 0
    nd = sum(1 for l in open(cf) if l.startswith("#")) if os.path.exists(cf) else 0
    return True, "MATCH: ELF sha1 %s; as the disc stores it sha1 %s%s" % (
        he, hp, "; %d functions from C (%d left as assembly)" % (nc, nd) if nc or nd else ""), {}


def one(target, table, a):
    info = table[target]
    d = os.path.join(build_root(), target)
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "build.log"), "w") as log:
        for rnd in range(a.rounds + 1):
            if a.asm or a.c or rnd or not os.path.exists(os.path.join(d, "objects.txt")):
                write_target(target, info[1], with_c=a.c)
            ok, msg, fix = build(target, info, a, log)
            log.write("round %d: %s\n" % (rnd, msg))
            if ok or not fix or rnd == a.rounds:
                return target, ok, msg + ("" if not rnd else " (after %d rounds)" % rnd)
            with open(os.path.join(asm_root(), target, "words.txt"), "a") as f:
                f.write("".join("%08X %s\n" % (x, sec) for sec, addrs in sorted(fix.items()) for x in sorted(addrs)))
            log.flush()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("targets", nargs="*")
    ap.add_argument("--asm", action="store_true", help="rewrite each target's assembly first (else only when missing)")
    ap.add_argument("-P", "--parallel", type=int, default=4)
    ap.add_argument("--rounds", type=int, default=3, help="rebuilds with differing words as .word")
    ap.add_argument("--timeout", type=int, default=900, help="watchdog: seconds an assembler or linker may take")
    ap.add_argument("--bin", default=BIN, help="folder with binutils 2.10-ee's ee-as and ee-ld")
    ap.add_argument("--list", action="store_true", help="print the targets and exit")
    ap.add_argument("--c", action="store_true",
                    help="link the C of tools/c_objects.py's objects in place of those functions' assembly")
    a = ap.parse_args()
    table = targets()
    if a.list:
        print(" ".join(table))
        return
    names = a.targets or list(table)
    bad = 0
    with ProcessPoolExecutor(a.parallel) as ex:
        for t, ok, msg in ex.map(functools.partial(one, table=table, a=a), names):
            print("%s: %s" % (t, msg), flush=True)
            bad += not ok
    print("%s: %d of %d targets match" % (version.disc_id(), len(names) - bad, len(names)))
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
