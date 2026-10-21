#!/usr/bin/env python3
"""build_levels.py: build the level programs, several at a time, and check each against the disc.

    python3 tools/build_levels.py [--setup] [-P 8] [-j 4] [NN ...] --toolchain DIR --runner WIBO --ee29 DIR

For each level (all 49 without NN): its build tree from src/levels/ (tools/levels.py tree),
with --setup its assembly first (tools/setup_asm.py, then tools/resolve_symbols.py), then
tools/build.py --target level_NN, which prints MATCH when the built ELF is baserom/levels/'s byte
for byte. Then the built program is converted back to the disc's format and its SHA-1 checked
against config/levels/levels.tsv's overlay_sha1: the disc's own bytes. -P levels run at once,
each compiling -j files at a time. Each level's log is build/levels/<NN_name>/build.log.
"""
import argparse
import hashlib
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import levels  # noqa: E402
import targets  # noqa: E402


def one(n, a):
    t = targets.LEVELS[levels.target_name(n)]
    log_path = os.path.join(ROOT, t.build_dir, "build.log")
    os.makedirs(os.path.dirname(log_path), exist_ok=True)
    py = sys.executable
    tree = [py, "tools/levels.py", "tree", str(n)]
    steps = [tree]
    if a.setup:
        steps += [[py, "tools/setup_asm.py", "--target", t.name], [py, "tools/levels.py", "tree", "--fill", str(n)],
                  [py, "tools/resolve_symbols.py", "--target", t.name], tree]
    # the tree is new: put back the TEXT_PADDING lines tools/trailing_padding.py writes
    steps.append([py, "tools/trailing_padding.py", "--apply", "--target", t.name])
    steps.append([py, "tools/build.py", "--target", t.name, "-j", str(a.jobs), "--toolchain", a.toolchain,
                  "--runner", a.runner] + (["--ee29", a.ee29] if a.ee29 else []))
    with open(log_path, "w") as log:
        for cmd in steps:
            log.write("+ %s\n" % " ".join(cmd))
            log.flush()
            r = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
            if r.returncode:
                return n, False, "%s failed (see %s)" % (os.path.basename(cmd[1]), os.path.relpath(log_path, ROOT))
    built = open(os.path.join(ROOT, t.build_dir, t.bin_name), "rb").read()
    h = hashlib.sha1(levels.program_of_elf(built)).hexdigest()
    if h != t.overlay_sha1:
        return n, False, "the built program's SHA-1 is %s, the disc's %s" % (h, t.overlay_sha1)
    return n, True, "MATCH: %s sha1 %s; as the disc stores it: sha1 %s" % (
        t.bin_name, hashlib.sha1(built).hexdigest(), h)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("levels", nargs="*", type=int)
    ap.add_argument("--setup", action="store_true", help="generate each level's assembly first")
    ap.add_argument("-P", "--parallel", type=int, default=4)
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"), required="UYA_TOOLCHAIN" not in os.environ)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER", "wibo"))
    ap.add_argument("--ee29", default=os.environ.get("UYA_EE29"))
    a = ap.parse_args()
    numbers = a.levels or sorted(levels.NAMES)
    bad = 0
    with ThreadPoolExecutor(a.parallel) as ex:
        for n, ok, msg in ex.map(lambda n: one(n, a), numbers):
            print("%s: %s" % (levels.dirname(n), msg), flush=True)
            bad += not ok
    print("%d of %d levels match" % (len(numbers) - bad, len(numbers)))
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
