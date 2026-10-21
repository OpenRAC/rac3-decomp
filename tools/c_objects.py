#!/usr/bin/env python3
"""c_objects.py: the shared C compiled for the NTSC-U build (tools/asm_build.py --version us --c).

    python3 tools/c_objects.py -j 32 --toolchain DIR --runner WIBO --ee29 DIR [TARGET ...]

For every function of src/ (and src/us/) that checks MATCH on NTSC-U (config/us/map.tsv), one
object holding that function alone: its block compiled with its own file's flags and context by
tools/check.py --version us, exactly as the check compiles it (the block in its file's context, or
from its marker only when the text before it is that context already), kept only when that very
compile gives MATCH. build/us/cobj/<program>/<name>.o and build/us/cobj/index.tsv (program,
name, NTSC-U places, object). An object with data of its own (.rodata, .data, literal pools) is
left out: the program's data is its assembly's, as in PAL's levels (docs/levels.md).

tools/asm_build.py --c then links each object at its NTSC-U places in place of the function's
assembly; the values of the names it uses are read from the disc's bytes and checked
(tools/level_symbols.py's derive(), as PAL's level build does).
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402

OUT = version.build("cobj", v="us")
INDEX = os.path.join(OUT, "index.tsv")
CORE = ("frontbin", "boot_elf", "i5bootn")


def placements():
    """[(program, name, [(target, NTSC-U address)], source file, native)] of everything that
    checks MATCH on NTSC-U and is C."""
    import level_catalogue as lc
    import levels
    import version_map as vm
    m = vm.Map()
    states = vm.pal_states()
    us_cat = {r[0]: r for r in lc.read_catalogue(vm.cat_path("us"))}
    native = vm.us_sources()
    out = []
    for r in m.rows:
        if r["state"] != "C" or r["status"] != "match":
            continue
        if r["pal"] == "-":
            rel, nat = native.get((r["program"], vm.native_name(r["us"]))), True
        else:
            rel, nat = states[(r["program"], r["pal"])][1], False
        name = vm.native_name(r["us"]) if nat else r["pal"]
        if r["program"] == "levels":
            row = us_cat.get(r["us"])
            if row is None:
                continue
            places = [(levels.target_name(n), a) for n, a in row[5]]
        else:
            places = [(r["program"], int(r["place"], 16))]
        out.append((r["program"], name, places, rel, nat))
    return out


def read_index():
    """{(program, name): object path} of what compiled to MATCH."""
    out = {}
    if os.path.exists(INDEX):
        for line in open(INDEX):
            f = line.rstrip("\n").split("\t")
            if len(f) == 3 and f[2] != "-":
                out[(f[0], f[1])] = f[2]
    return out


def compile_one(item, a, tmp):
    import version_map as vm
    program, name, places, rel, nat = item
    obj = os.path.join(OUT, program, name + ".o")
    if nat:
        variants = [(os.path.join(ROOT, rel), ["--native"])]
    else:
        variants = []
        for block_only in (False, True):
            p = os.path.join(tmp, "%s_%s%s.c" % (program, name, "_b" if block_only else ""))
            open(p, "w").write(vm.chunk_text(program, rel, name, block_only=block_only))
            variants.append((p, []))
    for path, extra in variants:
        cmd = [sys.executable, os.path.join(ROOT, "tools", "check.py"), "--version", "us", path, name, "--quiet",
               "--keep-object", obj, "--toolchain", a.toolchain] + (["--runner", a.runner] if a.runner else []) + \
            (["--ee29", a.ee29] if a.ee29 else []) + extra + (["--target", program] if program in CORE else [])
        try:
            p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=600,
                               env=dict(os.environ, UYA_VERSION="us"))
        except subprocess.TimeoutExpired:
            continue
        if re.search(r"^%s: MATCH" % re.escape(name), p.stdout, re.M) and os.path.exists(obj):
            import level_symbols
            o = level_symbols.read_object(obj)
            if o["extra"]:
                return item, "-", "data of its own (%s)" % ", ".join(o["extra"])
            return item, obj, "ok"
    if os.path.exists(obj):
        os.remove(obj)
    return item, "-", "no compile of the block alone gives MATCH"


BUILT = version.cfg("built.tsv", v="us")
BUILT_HEAD = """# The C linked into the NTSC-U programs (tools/asm_build.py --version us --c, then
# tools/c_objects.py --collect): program, name (src/'s; NTSC-U's own for src/us/), the programs
# whose build has it from C, and where it stays assembly and why. The NTSC-U report counts a C
# function as final only when every program that has it builds it from C.
"""


def collect(dirs):
    """config/us/built.tsv from the builds' c_functions.txt (in build/us/ or in DIRS, other
    machines' build/us/ copies)."""
    items = placements()
    want = {}
    for program, name, places, rel, nat in items:
        want[(program, name)] = {t for t, a in places}
    got = {k: set() for k in want}
    left = {k: {} for k in want}
    built = read_index()
    seen = set()
    for d in [version.build(v="us")] + list(dirs):
        if not os.path.isdir(d):
            continue
        for t in os.listdir(d):
            f = os.path.join(d, t, "c_functions.txt")
            if not os.path.exists(f) or t in seen:
                continue
            seen.add(t)
            program = "levels" if t.startswith("level_") else t
            for line in open(f):
                m = re.match(r"^# left as assembly: [0-9A-F]{8} (\S+): (.*)$", line.rstrip("\n"))
                if m:
                    left.setdefault((program, m.group(1)), {})[t] = m.group(2)
                elif line.strip():
                    got.setdefault((program, line.split()[1]), set()).add(t)
    lines = [BUILT_HEAD.rstrip("\n")]
    for k in sorted(want):
        why = dict(left.get(k, {}))
        for t in want[k] - got.get(k, set()) - set(why):
            why[t] = "no object of the block alone checks MATCH" if k not in built else \
                ("not built" if t in seen else "not built here (no build of %s)" % t)
        lines.append("\t".join([k[0], k[1], str(len(got.get(k, ()))),
                                 ";".join("%s: %s" % (t, why[t]) for t in sorted(why)) or "-"]))
    open(BUILT, "w", newline="\n").write("\n".join(lines) + "\n")
    full = sum(1 for l in lines[1:] if l.endswith("\t-"))
    print("wrote %s: %d of %d C functions built from C wherever they are" % (os.path.relpath(BUILT, ROOT), full,
                                                                            len(lines) - 1))


def read_built():
    """{(program, name): (programs built, problems or '')} of config/us/built.tsv (None: no table)."""
    if not os.path.exists(BUILT):
        return None
    out = {}
    for line in open(BUILT, encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        prog, name, n, why = line.rstrip("\n").split("\t", 3)
        out[(prog, name)] = (int(n), "" if why == "-" else why)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("targets", nargs="*", help="only what these targets need (default: everything)")
    ap.add_argument("--collect", nargs="*", metavar="DIR",
                    help="write config/us/built.tsv from the builds (build/us/, and other machines' copies in DIR)")
    ap.add_argument("-j", "--jobs", type=int, default=8)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"))
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--ee29", default=os.environ.get("UYA_EE29"))
    a = ap.parse_args()
    if a.collect is not None:
        collect(a.collect)
        return
    if not a.toolchain:
        sys.exit("--toolchain is needed to compile")
    items = placements()
    if a.targets:
        want = set(a.targets)
        items = [i for i in items if any(t in want for t, _ in i[2])]
    for p in CORE + ("levels",):
        os.makedirs(os.path.join(OUT, p), exist_ok=True)
    tmp = tempfile.mkdtemp(prefix="c_objects_")
    rows, bad = {}, []
    if os.path.exists(INDEX):
        for line in open(INDEX):
            f = line.rstrip("\n").split("\t")
            rows[(f[0], f[1])] = f
    with ThreadPoolExecutor(a.jobs) as ex:
        for item, obj, why in ex.map(lambda i: compile_one(i, a, tmp), items):
            rows[(item[0], item[1])] = [item[0], item[1], os.path.relpath(obj, ROOT) if obj != "-" else "-"]
            if obj == "-":
                bad.append((item[0], item[1], why))
    with open(INDEX, "w") as f:
        for k in sorted(rows):
            f.write("\t".join(rows[k]) + "\n")
    import shutil
    shutil.rmtree(tmp, ignore_errors=True)
    print("%d objects, %d functions left as assembly" % (len(items) - len(bad), len(bad)))
    for p, n, why in bad:
        print("  %s %s: %s" % (p, n, why))


if __name__ == "__main__":
    main()
