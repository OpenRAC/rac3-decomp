#!/usr/bin/env python3
"""gp.py: each program's $gp, read from the retail programs (docs/GLOBALS.md).

    python3 tools/gp.py              # prints every program's $gp and where it was read
    python3 tools/gp.py --write      # writes config/gp.tsv from the dumps of both discs
    python3 tools/gp.py --check      # config/gp.tsv against the dumps (exit 1 on a difference)

A program's $gp is the value its linker gave `_gp`. Two places in the retail bytes hold it:

  - boot_elf's .reginfo section (ri_gp_value, the word at +0x14);
  - the ThreadParam of the program's own CreateThread call, whose gpReg (the word at +0x10)
    the code loads with `la $r, _gp` (lui + addiu) and stores beside the entry (+0x4), the
    stack (+0x8) and the stack size (+0xC). The front end's copy of that function is in
    frontbin, in boot_elf's front end and in every level.

Of the CreateThread values, $gp is the one in the program's small-data window: within 64 KB
above the start of its first data section (.lit). PAL and NTSC-U agree for the core and
levels 1-36 (0x1DC8B0, the "story" $gp); the multiplayer levels 39-53 (and NTSC-U's 54 and 55)
have their own, 0x247FC0 on PAL and 0x248140 on NTSC-U. i5bootn never reads $gp (its
.reginfo says 0x8CCCF0); it has no row and builds with gp 0.

config/gp.tsv is committed so that the tools need no game data to know a program's $gp
(tools/targets.py reads it); tests/check_repository.py checks its shape and, where the dumps
are present, this tool's --check compares it with them.

A name for a $gp-relative global that code in programs with different $gp reads is the slot's
address under the story $gp with the suffix `_sda` (D_XXXXXXXX_sda, sda_value()).
"""
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

TABLE = os.path.join(ROOT, "config", "gp.tsv")
# the $gp of boot_elf (its .reginfo), frontbin and levels 1-36, on both discs
STORY_GP = 0x1DC8B0
SHT_MIPS_REGINFO = 0x70000006
SDA_NAME = re.compile(r"^D_([0-9A-F]{8})_sda$")


def _sext(v):
    return v - 0x10000 if v & 0x8000 else v


def from_elf(path):
    """(gp, where) of one retail ELF: its .reginfo's ri_gp_value when non-zero, else the
    `la _gp` its CreateThread stores as ThreadParam.gpReg inside its small-data window.
    (None, why) when neither is there."""
    import levels
    _, secs = levels.read_elf(open(path, "rb").read())
    for a, n, kind, b in secs:
        if kind == SHT_MIPS_REGINFO and len(b) >= 24 and a == 0x100000:
            v = struct.unpack_from("<I", b, 20)[0]
            if v:
                return v, ".reginfo ri_gp_value"
    data = [a for a, n, kind, b in secs if kind in (1, 8) and a >= 0x100000]
    lit = min(data) if data else 0
    found = {}
    for a, n, kind, b in secs:
        if kind != 1 or len(b) < 8:
            continue
        w = struct.unpack("<%dI" % (len(b) // 4), b[:len(b) // 4 * 4])
        for i, lui in enumerate(w):
            if lui >> 26 != 0x0F:
                continue
            r = (lui >> 16) & 31
            j = next((j for j in range(i + 1, min(i + 8, len(w)))
                      if w[j] >> 26 == 0x09 and (w[j] >> 21) & 31 == r and (w[j] >> 16) & 31 == r), None)
            if j is None:
                continue
            value = (((lui & 0xFFFF) << 16) + _sext(w[j] & 0xFFFF)) & 0xFFFFFFFF
            store = next((m for m in range(j + 1, min(j + 10, len(w)))
                          if w[m] >> 26 == 0x2B and (w[m] >> 16) & 31 == r and w[m] & 0xFFFF == 0x10), None)
            if store is None:
                continue
            base = (w[store] >> 21) & 31
            near = {w[q] & 0xFFFF for q in range(max(0, i - 12), min(len(w), store + 12))
                    if w[q] >> 26 == 0x2B and (w[q] >> 21) & 31 == base}
            if {0x4, 0x8, 0xC} <= near and lit <= value < lit + 0x10000:
                found.setdefault(value, a + 4 * i)
    if len(found) == 1:
        (v, at), = found.items()
        return v, "CreateThread gpReg (la _gp at 0x%08X)" % at
    if not found:
        return None, "no .reginfo and no CreateThread gpReg in its small-data window"
    return None, "two values: %s" % ", ".join("0x%08X" % v for v in sorted(found))


def programs(version):
    """[(program, retail ELF)] of one disc: frontbin, boot_elf and its levels."""
    import levels
    base = os.path.join(ROOT, "baserom") if version == "pal" else os.path.join(ROOT, "baserom", "us")
    out = [("frontbin", os.path.join(base, "frontbin.elf")), ("boot_elf", os.path.join(base, "boot_elf.elf"))]
    table = os.path.join(ROOT, "config", "levels" if version == "pal" else "us/levels", "levels.tsv")
    for row in levels.read_table(table):
        out.append((levels.target_name(row["number"]), os.path.join(base, "levels", row["dir"] + ".elf")))
    return out


def read_table(path=TABLE):
    """{(version, program): gp} of config/gp.tsv."""
    out = {}
    if os.path.exists(path):
        for line in open(path):
            if line.strip() and not line.startswith("#"):
                f = line.rstrip("\n").split("\t")
                out[(f[0], f[1])] = int(f[2], 16)
    return out


_TABLE = None


def gp_of(program, version="pal"):
    """A program's $gp (config/gp.tsv); the story $gp for a program the table does not list
    (i5bootn, which never reads $gp, and the US-only levels before the table has them)."""
    global _TABLE
    if _TABLE is None:
        _TABLE = read_table()
    return _TABLE.get((version, program), STORY_GP)


def sda_value(name, gp):
    """The value of an sda name D_XXXXXXXX_sda in a program whose $gp is GP: the slot
    XXXXXXXX - STORY_GP from $gp. None for another name."""
    m = SDA_NAME.match(name)
    if not m:
        return None
    return (gp + int(m.group(1), 16) - STORY_GP) & 0xFFFFFFFF


def derive_all():
    rows, errors = [], []
    for version in ("pal", "us"):
        for program, path in programs(version):
            if not os.path.exists(path):
                errors.append("%s %s: %s is missing" % (version, program, os.path.relpath(path, ROOT)))
                continue
            gp, where = from_elf(path)
            if gp is None:
                errors.append("%s %s: %s" % (version, program, where))
                continue
            rows.append((version, program, gp, where))
    return rows, errors


HEADER = ("# Each program's $gp, read from the retail programs by tools/gp.py --write (docs/GLOBALS.md):\n"
          "# version, program (tools/targets.py), $gp, where the bytes give it. Generated; never edit.\n")


def main():
    args = sys.argv[1:]
    rows, errors = derive_all()
    if "--write" in args:
        if errors:
            sys.exit("gp.py: cannot write config/gp.tsv:\n  " + "\n  ".join(errors))
        open(TABLE, "w", newline="\n").write(HEADER + "".join(
            "%s\t%s\t0x%08X\t%s\n" % r for r in rows))
        print("config/gp.tsv: %d programs" % len(rows))
        return
    if "--check" in args:
        have = read_table()
        bad = list(errors)
        for version, program, gp, where in rows:
            if have.get((version, program)) != gp:
                bad.append("%s %s: the disc gives 0x%08X (%s), config/gp.tsv %s" % (
                    version, program, gp, where,
                    "0x%08X" % have[(version, program)] if (version, program) in have else "has no row"))
        extra = set(have) - {(v, p) for v, p, _, _ in rows}
        bad += ["%s %s: in config/gp.tsv, not on the disc" % k for k in sorted(extra)]
        if bad:
            sys.exit("gp.py --check:\n  " + "\n  ".join(bad))
        print("config/gp.tsv: %d programs agree with the discs" % len(rows))
        return
    for version, program, gp, where in rows:
        print("%-3s %-9s 0x%08X  %s" % (version, program, gp, where))
    for e in errors:
        print("?   " + e)


if __name__ == "__main__":
    main()
