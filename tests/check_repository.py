#!/usr/bin/env python3
"""Toolchain-free repository checks (no game data needed).

  python3 tests/check_repository.py                     # every program, no toolchain needed
  python3 tests/check_repository.py --target boot_elf   # one program
  python3 tests/check_repository.py --compile           # also compile every file and slice
                                                        # (UYA_TOOLCHAIN / UYA_RUNNER, as pr_check)

This is the main pre-commit check; tools/pr_check.py is the per-program engine behind it and
keeps working on its own (`--obj`, `--no-git`, ...).

1. Every program's source checks: tools/pr_check.py --target NAME --no-compile --no-git
   for frontbin, boot_elf and i5bootn (files, markers, duplicates, extern-only variables,
   typedefs, aliases, jump tables, @ps2as ranges). With the retail ELF present it also runs
   the sq_ra check; without it (CI) that check is skipped by pr_check itself.
2. Every path tools/targets.py names for a program's tables exists, and the flag tables parse.
3. progress/report.json and the README table are current (tools/progress.py --check), and
   every draft in nonmatching/ has its row in nonmatching/README.md.
4. The level code: every level has its configuration, and src/levels/ holds every shared and
   level-specific function of config/levels/functions.tsv once, each file with its flags line.
5. No game data or build output is tracked: no ELF, flat binary, object, disc image or
   archive of game files, nothing under asm/, build/, baserom/ or a toolchain folder, no
   file that starts with an ELF header, and no file over 2.5 MB except the progress report.

Exits nonzero, listing every problem, on failure.
"""
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import targets  # noqa: E402

# Tracked files that look like game data by name but are not (checked by hand).
KNOWN: set = set()
BIG_OK = {"progress/report.json", "config/levels/functions.tsv"}
MAX_BYTES = 2_500_000
DATA_SUFFIXES = (".elf", ".bin", ".o", ".a", ".iso", ".wad", ".irx", ".7z", ".zip", ".gz")
DATA_DIRS = ("asm/", "build/", "baserom/", "toolchain/", "toolchains/", ".localdecomp_work/")


def tracked_files():
    out = subprocess.run(["git", "ls-files", "-z"], cwd=ROOT, capture_output=True, text=True)
    if out.returncode == 0 and out.stdout:
        return [f for f in out.stdout.split("\0") if f]
    # not a git checkout: look at the tree, minus what is ignored anyway
    return [p.relative_to(ROOT).as_posix() for p in ROOT.rglob("*")
            if p.is_file() and not p.relative_to(ROOT).as_posix().startswith((".git/",) + DATA_DIRS)]


def check_game_data(errors):
    for f in tracked_files():
        path = ROOT / f
        if not path.is_file():          # deleted in the working tree, not yet committed
            continue
        low = f.lower()
        if f in KNOWN:
            continue
        if low.endswith(DATA_SUFFIXES):
            errors.append(f"{f}: no {Path(f).suffix} files in the repository (game data or build output)")
        if low.startswith(DATA_DIRS):
            errors.append(f"{f}: this folder holds game data, generated assembly or build output; never commit it")
        with open(path, "rb") as fh:
            if fh.read(4) == b"\x7fELF":
                errors.append(f"{f}: an ELF file (game executables and objects stay local)")
        size = path.stat().st_size
        if size > MAX_BYTES and f not in BIG_OK:
            errors.append(f"{f}: {size} bytes; generated data and game files stay out of git")


def check_tables(errors):
    for t in targets.TARGETS.values():
        for attr in ("files", "parts", "divs_nops", "sq_ra_funcs", "symbol_addrs",
                     "symbols_resolved", "yaml", "ld"):
            rel = getattr(t, attr)
            if not (ROOT / rel).is_file():
                errors.append(f"{t.name}: {attr} {rel} (tools/targets.py) does not exist")
        parts = ROOT / t.parts
        if parts.is_file():
            for n, line in enumerate(parts.read_text().splitlines(), 1):
                f = line.split("#", 1)[0].split()
                if not f:
                    continue
                if not re.fullmatch(r"(0x)?[0-9A-Fa-f]+", f[0]):
                    errors.append(f"{t.parts}:{n}: {f[0]!r} is not an address")
        files = ROOT / t.files
        if files.is_file():
            for n, line in enumerate(files.read_text().splitlines(), 1):
                f = line.split("#", 1)[0].split()
                if f and not (ROOT / f[0]).is_file():
                    errors.append(f"{t.files}:{n}: {f[0]} does not exist")


def check_levels(errors):
    """The level code (docs/levels.md): every level of config/levels/levels.tsv has its splat
    configuration and linker script; every shared and level-specific function of the catalogue is
    in src/levels/ exactly once, under its own folder, and nothing else is; every src/levels/ file
    has its one line in config/levels/text_parts.txt."""
    import level_catalogue as lc
    import level_tree
    import levels
    for row in levels.read_table():
        for rel in ("config/splat/levels/%s.yaml" % row["dir"], "linker_scripts/levels/%s.ld" % row["dir"]):
            if not (ROOT / rel).is_file():
                errors.append(f"{rel} is missing (python3 tools/levels.py config)")
    seen = {}
    for path in sorted((ROOT / "src" / "levels").rglob("*.c")):
        rel = path.relative_to(ROOT).as_posix()
        for name, _, _ in level_tree.parse_source(rel)[1]:
            if name in seen:
                errors.append(f"{rel}: {name} is also in {seen[name]}")
            seen[name] = rel
    want = {}
    for name, kind, _, _, _, places in lc.read_catalogue():
        if kind in ("shared", "level"):
            want[name] = "shared" if kind == "shared" else levels.dirname(places[0][0])
    for name, folder in want.items():
        if name not in seen:
            errors.append(f"{name} (config/levels/functions.tsv) is not in src/levels/")
        elif seen[name].split("/")[2] != folder:
            errors.append(f"{seen[name]}: {name} belongs in src/levels/{folder}/")
    for name in sorted(set(seen) - set(want)):
        errors.append(f"{seen[name]}: {name} is not a shared or level function of config/levels/functions.tsv")
    parts = level_tree.read_parts()
    files = {p for p in seen.values()}
    for rel in sorted(files - set(parts)):
        errors.append(f"{rel} has no line in config/levels/text_parts.txt")
    for rel in sorted(set(parts) - files):
        errors.append(f"config/levels/text_parts.txt: {rel} is not a source file of src/levels/")


def check_sources(errors, names=None, compile_=False):
    for name in names or targets.TARGETS:
        r = subprocess.run([sys.executable, str(ROOT / "tools" / "pr_check.py"), "--target", name, "--no-git"]
                           + ([] if compile_ else ["--no-compile"]), cwd=ROOT, capture_output=True, text=True)
        lines = (r.stdout + r.stderr).splitlines()
        summary = next((l for l in reversed(lines) if "functions in C" in l), "")
        print(f"{name}: {summary or 'no summary'}")
        if r.returncode:
            errors.extend(f"{name}: {l[len('error: '):]}" for l in lines if l.startswith("error: "))
            if not any(l.startswith("error: ") for l in lines):
                errors.append(f"{name}: tools/pr_check.py failed:\n" + "\n".join(lines[-20:]))


def check_progress(errors):
    """progress/report.json and the README table are what tools/progress.py makes from src/."""
    r = subprocess.run([sys.executable, str(ROOT / "tools" / "progress.py"), "--check"], cwd=ROOT,
                       capture_output=True, text=True)
    if r.returncode:
        errors.extend(l[len("error: "):] for l in (r.stdout + r.stderr).splitlines() if l.startswith("error: "))


def check_nonmatching(errors):
    """Every draft in nonmatching/<program>/ has a row in nonmatching/README.md."""
    readme = (ROOT / "nonmatching" / "README.md").read_text()
    for p in sorted((ROOT / "nonmatching").glob("*/*.c")):
        if f"`{p.stem}`" not in readme:
            errors.append(f"nonmatching/{p.parent.name}/{p.name}: no row in nonmatching/README.md")


def main() -> int:
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--target", choices=list(targets.TARGETS) + ["all"], default="all")
    ap.add_argument("--compile", action="store_true", help="also compile every file (needs the toolchain)")
    a = ap.parse_args()
    errors: list = []
    check_game_data(errors)
    check_tables(errors)
    check_levels(errors)
    check_progress(errors)
    check_nonmatching(errors)
    check_sources(errors, None if a.target == "all" else [a.target], a.compile)
    if errors:
        print(f"\n{len(errors)} problem(s):", file=sys.stderr)
        for e in errors[:200]:
            print("  " + e, file=sys.stderr)
        return 1
    print("repository checks passed")
    return 0


if __name__ == "__main__":
    os.chdir(ROOT)
    sys.exit(main())
