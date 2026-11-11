#!/usr/bin/env python3
"""level_globals.py: the value every name of the level C has in each level, after a level build.

    python3 tools/level_globals.py [--copies]     # writes build/levels/globals.tsv

Reads each built level's build/levels/<NN_name>/symbol_addrs_derived.txt (tools/level_symbols.py:
the values read from the level's bytes) and symbol_addrs_resolved.txt (tools/resolve_symbols.py:
the names that state their address), and writes one line per data name (D_...) the C uses:

    name    kind    NN=0xADDRESS NN=0xADDRESS ...

`kind` is how its value is known (docs/build/globals.md): `core` (D_XXXXXXXX, its address), `sda`
(D_XXXXXXXX_sda, the $gp slot), `level` (D_LNN_XXXXXXXX, read from the bytes outside level NN),
`alias` (a name with a suffix). A name whose value differs between levels is that level's own
copy (rac2-decomp's data_copies); --copies prints only those. Nothing here is committed: run it
after tools/build_levels.py.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
VALUE = re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", re.M)


def kind(name):
    if re.fullmatch(r"D_[0-9A-F]{8}_sda", name):
        return "sda"
    if re.fullmatch(r"D_L\d\d_[0-9A-F]{8}", name):
        return "level"
    if re.fullmatch(r"D_[0-9A-F]{8}", name):
        return "core"
    return "alias"


def collect():
    """{name: {level number: value}} over every built level."""
    import targets
    out = {}
    for t in targets.LEVELS.values():
        derived = os.path.join(ROOT, t.build_dir, "symbol_addrs_derived.txt")
        if not os.path.exists(derived):
            continue
        for path in (t.path("symbols_resolved"), derived):
            if not os.path.exists(path):
                continue
            for m in VALUE.finditer(open(path).read()):
                if m.group(1).startswith("D_"):
                    out.setdefault(m.group(1), {})[t.level] = int(m.group(2), 16)
    return out


def main():
    copies = "--copies" in sys.argv[1:]
    names = collect()
    if not names:
        sys.exit("level_globals.py: no level is built (tools/build_levels.py first)")
    lines = []
    for name, by_level in sorted(names.items()):
        if copies and len(set(by_level.values())) < 2:
            continue
        lines.append("%s\t%s\t%s" % (name, kind(name), " ".join(
            "%02d=0x%08X" % (n, v) for n, v in sorted(by_level.items()))))
    if copies:
        print("\n".join(lines))
        return
    path = os.path.join(ROOT, "build", "levels", "globals.tsv")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, "w", newline="\n").write(
        "# name, kind (docs/build/globals.md), its value in each built level (tools/level_globals.py)\n"
        + "\n".join(lines) + "\n")
    differ = sum(1 for v in names.values() if len(set(v.values())) > 1)
    print("build/levels/globals.tsv: %d names, %d with a value of their own in some level" % (len(names), differ))


if __name__ == "__main__":
    main()
