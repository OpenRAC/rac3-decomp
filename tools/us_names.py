#!/usr/bin/env python3
"""us_names.py: the NTSC-U value of every name the core programs' C uses.

The C in src/ names globals and functions by their PAL addresses (D_001DBC58, func_0039B470, the
aliases D_00142430_0039B470 and the short D_142430). The NTSC-U build reads each name's value
from the disc's bytes (tools/asm_build.py --version us --c, tools/level_symbols.py derive()) and
writes them into its linker scripts, build/us/<program>/<program>.ld. This keeps them in
config/us/names.tsv, so a tool that reads the C for NTSC-U without building it (OpenRAC's port)
knows them too:

    python3 tools/asm_build.py --version us --c -P 16     # after tools/c_objects.py
    python3 tools/us_names.py --write
    python3 tools/us_names.py --candidates     # nonmatching/functional.tsv

Columns: program (frontbin, boot_elf, i5bootn), the name as the C writes it, its NTSC-U value,
and where the value comes from:

- `build`: the NTSC-U build read it from the disc's bytes (the C that uses it builds there);
- `pair`: a global only C the build leaves as assembly uses (a near miss in nonmatching/, a
  function that differs): every twin function (config/us/map.tsv, the same code on both discs)
  that reaches its PAL address (a lui and its low half, or a $gp offset) reaches this NTSC-U
  address at the same instruction;
- `shift`: no twin reaches it, but the paired addresses nearest below and above it, in the same
  program, are both moved by this one distance.

`--candidates` writes nonmatching/functional.tsv (name, file): the drafts in nonmatching/ that are
C the NTSC-U decompilation this project started from matched on NTSC-U (`/* US draft`; most with
flags of their own for the one function, which this repository does not allow), for a function
NTSC-U has (config/us/map.tsv) and src/us/ gives no C for. The port reads them in place of the
assembly (OpenRAC's hostgen "candidates"); the matching build never does.

A name has one value per program. Functions are in config/us/map.tsv (PAL name, NTSC-U name and
place); a global none of these place has no NTSC-U value yet.
"""
import argparse
import bisect
import os
import re
import struct
import sys
from collections import Counter, defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import inventory  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "config", "us", "names.tsv")
PROGRAMS = ("frontbin", "boot_elf", "i5bootn")
LINE = re.compile(r"^([A-Za-z_]\w*) = 0x([0-9A-Fa-f]+);$")
GLOBAL = re.compile(r"\bD_([0-9A-F]{8})\b")
GP = 0x1DC8B0  # both discs' $gp in every core program (config/gp.tsv)
STORE_OR_LOAD = inventory.MEM | {0x09}  # loads, stores and addiu: base + offset

HEADER = """\
# The NTSC-U value of every name the core programs' C uses (tools/us_names.py --write;
# docs/build/versions.md): program, name (as src/ and nonmatching/ write it), value, from where (build:
# the NTSC-U build's linker script; pair: twin functions reach it; shift: its paired neighbours).
"""


def read(program):
    path = os.path.join(ROOT, "build", "us", program, program + ".ld")
    if not os.path.exists(path):
        sys.exit("%s: missing; build NTSC-U with C first (tools/asm_build.py --version us --c)" % path)
    out = {}
    for line in open(path):
        m = LINE.match(line.strip())
        if m and m.group(1) != "_gp":
            out[m.group(1)] = int(m.group(2), 16)
    return out


def image(path):
    """address -> bytes of each section of an ELF."""
    return [(a, b) for _name, a, b, _flags in inventory.elf_sections(path)]


def at(img, address, size):
    for a, b in img:
        if a <= address and address + size <= a + len(b):
            return b[address - a:address - a + size]
    return None


def reached(b, start):
    """(instruction index, address) of every address a function's lui/low-half pairs and $gp
    offsets reach."""
    out, hi = [], {}
    for k, (x,) in enumerate(struct.iter_unpack("<I", b)):
        op, rs, rt, imm = x >> 26, (x >> 21) & 31, (x >> 16) & 31, x & 0xFFFF
        low = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:
            hi[rt] = imm << 16
            continue
        if op in STORE_OR_LOAD:
            if rs == 28:
                out.append((k, GP + low))
            elif rs in hi:
                out.append((k, (hi[rs] + low) & 0xFFFFFFFF))
        # a register written by anything else no longer holds a high half
        if op in (0x09, 0x0D, 0x0A, 0x0B, 0x0C, 0x0E) or (op in inventory.MEM and op < 0x28):
            hi.pop(rt, None)
        elif op == 0:
            hi.pop((x >> 11) & 31, None)
    return out


def pairs(program):
    """PAL address -> NTSC-U address, from every twin function of PROGRAM (map.tsv)."""
    pal = image(os.path.join(ROOT, "baserom", program + ".elf"))
    us = image(os.path.join(ROOT, "baserom", "us", program + ".elf"))
    votes = defaultdict(Counter)
    for line in open(os.path.join(ROOT, "config", "us", "map.tsv")):
        c = line.rstrip("\n").split("\t")
        if line.startswith("#") or len(c) < 7 or c[1] != program or c[3] == "-" or c[6] in ("differs", "none"):
            continue
        m = re.match(r"func_([0-9A-F]{8})$", c[0])
        if not m:
            continue
        size = int(c[4])
        a, b = at(pal, int(m.group(1), 16), size), at(us, int(c[3], 16), size)
        if a is None or b is None or inventory.identity(a) != inventory.identity(b):
            continue
        ra, rb = reached(a, 0), reached(b, 0)
        if [k for k, _ in ra] != [k for k, _ in rb]:
            continue
        for (_, p), (_, u) in zip(ra, rb):
            if p >= inventory.RESIDENT_END:
                votes[p][u] += 1
    return {p: c.most_common(1)[0][0] for p, c in votes.items() if len(c) == 1}


def used(program):
    """The plain global names (D_XXXXXXXX, past the resident core) PROGRAM's C uses, in src/ and
    in the drafts in nonmatching/."""
    roots = [os.path.join("src", program), os.path.join("nonmatching", program)]
    out = set()
    for root in roots:
        for d, _, files in os.walk(os.path.join(ROOT, root)):
            for f in files:
                if f.endswith(".c"):
                    for m in GLOBAL.finditer(open(os.path.join(d, f), errors="replace").read()):
                        if int(m.group(1), 16) >= inventory.RESIDENT_END:
                            out.add(m.group(0))
    return out


def values(program):
    """name -> (value, from where)."""
    out = {name: (v, "build") for name, v in read(program).items()}
    missing = sorted(n for n in used(program) if n not in out)
    if not missing:
        return out
    pair = pairs(program)
    keys = sorted(pair)
    for name in missing:
        p = int(name[2:], 16)
        if p in pair:
            out[name] = (pair[p], "pair")
            continue
        i = bisect.bisect_left(keys, p)
        if 0 < i < len(keys):
            lo, hi = keys[i - 1], keys[i]
            if pair[lo] - lo == pair[hi] - hi and hi - lo <= 0x1000:
                out[name] = (p + pair[lo] - lo, "shift")
    return out


def table():
    rows = []
    for p in PROGRAMS:
        for name, (value, how) in sorted(values(p).items()):
            rows.append("%s\t%s\t%08X\t%s\n" % (p, name, value, how))
    return "".join(rows)


def candidates():
    us_own = set()
    for program in PROGRAMS:
        d = os.path.join(ROOT, "src", "us", program)
        us_own.update((program, os.path.splitext(f)[0]) for f in (os.listdir(d) if os.path.isdir(d) else ())
                      if f.endswith(".c"))
    twins = {}
    for line in open(os.path.join(ROOT, "config", "us", "map.tsv")):
        c = line.rstrip("\n").split("\t")
        if not line.startswith("#") and len(c) >= 7 and c[1] in PROGRAMS and c[2] != "-":
            twins.setdefault((c[1], c[0]), c[3])
    rows = []
    for program in PROGRAMS:
        d = os.path.join(ROOT, "nonmatching", program)
        for f in sorted(os.listdir(d)) if os.path.isdir(d) else ():
            name = os.path.splitext(f)[0]
            if not f.endswith(".c") or not open(os.path.join(d, f)).read(12).startswith("/* US draft"):
                continue
            place = twins.get((program, name))
            if place is None or (program, place.upper()) in us_own:
                continue
            rows.append("%s\tnonmatching/%s/%s\n" % (name, program, f))
    return ("# C for functions the matching build still has as assembly, for OpenRAC's native port of NTSC-U\n"
            "# (hostgen.json \"candidates\"): the US drafts in nonmatching/ (tools/us_names.py --candidates).\n"
            "# name\tfile\n" + "".join(rows))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="write config/us/names.tsv")
    ap.add_argument("--check", action="store_true", help="fail when config/us/names.tsv differs from the build's")
    ap.add_argument("--candidates", action="store_true", help="write nonmatching/functional.tsv")
    a = ap.parse_args()
    if a.candidates:
        text = candidates()
        open(os.path.join(ROOT, "nonmatching", "functional.tsv"), "w").write(text)
        print("nonmatching/functional.tsv: %d drafts" % (text.count("\n") - 3))
        return
    text = HEADER + table()
    if a.write:
        open(OUT, "w", newline="\n").write(text)
        print("%s: %d names" % (os.path.relpath(OUT, ROOT), text.count("\n") - HEADER.count("\n")))
    elif a.check:
        if not os.path.exists(OUT) or open(OUT).read() != text:
            sys.exit("config/us/names.tsv is behind the build: run tools/us_names.py --write")
        print("config/us/names.tsv: up to date")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main()
