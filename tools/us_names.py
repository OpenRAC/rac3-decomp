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

Columns: program (frontbin, boot_elf, i5bootn), the name as the C writes it, its NTSC-U value.
A name has one value per program. Functions are in config/us/map.tsv (PAL name, NTSC-U name and
place); a name the C uses that is in neither (it is only in C the NTSC-U build leaves as
assembly) has no NTSC-U value yet.
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "config", "us", "names.tsv")
PROGRAMS = ("frontbin", "boot_elf", "i5bootn")
LINE = re.compile(r"^([A-Za-z_]\w*) = 0x([0-9A-Fa-f]+);$")

HEADER = """\
# The NTSC-U value of every name the core programs' C uses, from the NTSC-U build's linker
# scripts (tools/us_names.py --write; docs/versions.md): program, name (as src/ writes it), value.
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


def table():
    return "".join("%s\t%s\t%08X\n" % (p, name, value)
                   for p in PROGRAMS for name, value in sorted(read(p).items()))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="write config/us/names.tsv")
    ap.add_argument("--check", action="store_true", help="fail when config/us/names.tsv differs from the build's")
    a = ap.parse_args()
    text = HEADER + table()
    if a.write:
        open(OUT, "w").write(text)
        print("%s: %d names" % (os.path.relpath(OUT, ROOT), text.count("\n") - HEADER.count("\n")))
    elif a.check:
        if not os.path.exists(OUT) or open(OUT).read() != text:
            sys.exit("config/us/names.tsv is behind the build: run tools/us_names.py --write")
        print("config/us/names.tsv: up to date")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main()
