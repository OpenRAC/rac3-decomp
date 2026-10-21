#!/usr/bin/env python3
"""progress.py: how much of the game is final source; progress/report.json and the README table.

    python3 tools/progress.py            # print the counts
    python3 tools/progress.py --write    # rewrite progress/report.json and the README table
    python3 tools/progress.py --check    # the committed report and table agree with src/ (CI)

It needs no game data or toolchain: everything comes from src/ and three committed tables made
from the binaries:

  config/inventory.tsv          every function of the core programs (tools/inventory.py)
  config/frontend_pairs.tsv     boot_elf's front-end functions that are frontbin's (tools/level_catalogue.py)
  config/levels/functions.tsv   every distinct level function and its places (tools/level_catalogue.py)

Counted once, as rac1-decomp and rac2-decomp count them:
  - a core program's functions are the inventory's (rac1-decomp's way of finding them, from the
    binary: docs/levels.md, "Counting functions"), each in the source file that holds its start;
    a function is final when every source entry it covers is final source (C, hand-written
    assembly ASM_FUNC, or LINKER_REMNANT); a linker remnant is final as it is;
  - boot_elf's .text is frontbin's front end linked a second time: a pair of
    config/frontend_pairs.tsv is one function, counted in frontbin's unit (in boot_elf's when
    only boot_elf's copy is final);
  - a level function counts once however many levels have it: one with frontbin's code is
    frontbin's function; the others are in "Shared level code" (in two or more levels) or in
    their level's unit.
src/ holds only C that builds byte-identical (near misses are in nonmatching/), so a counted
function is one the full build proves. Nothing partly matched is built or counted, so each
function's fuzzy match is 100 or 0 and the fuzzy totals equal the exact ones; they are computed
apart all the same (from the functions' fuzzy_match_percent and from their final state).

Units and categories are rac1-decomp's: one unit per source file of the core programs
("frontbin/381080", "boot_elf/core/116F80"), one "Shared level code" unit and one unit per level
("Level 01: Veldin") with that level's own functions. Categories: "core" and each core program
and code section; "level_code", "common" (shared), "levels" (level-specific) and level_NN.
.github/workflows/progress.yml uploads the report to ByteMatch on every push to master.
"""
import argparse
import collections
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import srcfiles as sf  # noqa: E402
import targets  # noqa: E402

REPORT = os.path.join(ROOT, "progress", "report.json")
README = os.path.join(ROOT, "README.md")
BEGIN, END = "<!-- progress:begin (tools/progress.py --write) -->", "<!-- progress:end -->"
BEGIN_US, END_US = "<!-- progress-us:begin (tools/progress.py --version us --write) -->", "<!-- progress-us:end -->"
KIND = re.compile(r'^\s*(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(')


def entries(t):
    """[(rel, unit, addr, kind)] for one program, in address order (kind: C, ASM_FUNC,
    LINKER_REMNANT or INCLUDE_ASM)."""
    out = []
    for rel, _ in sf.read_file_list(t.path("files")):
        _, _, chunks = sf.split_file(sf.read_source(rel))
        kinds = {}
        for addr, _, body in chunks:
            if "localdecomp:start func_%08X" % addr in body:
                kinds[addr] = "C"
            else:
                m = KIND.match(body)
                if m and addr not in kinds:
                    kinds[addr] = m.group(1)
        for addr, kind in kinds.items():
            out.append((rel, t.unit_for(addr), addr, kind))
    out.sort(key=lambda e: e[2])
    return out


def measures(fns):
    """objdiff's code measures for a list of functions ({"size", "done"}). Nothing here is
    partly matched (src/ holds only C that builds byte-identical; near misses are in
    nonmatching/ and not built), so the fuzzy match is the exact match. complete_code is the
    code of the units (source files) with nothing left to decompile."""
    total = sum(f["size"] for f in fns)
    done = sum(f["size"] for f in fns if f["done"])
    fuzzy = sum(f["size"] * f.get("fuzzy", 100.0 if f["done"] else 0.0) / 100.0 for f in fns)
    n, nd = len(fns), sum(1 for f in fns if f["done"])
    pct = lambda a, b: round(100.0 * a / b, 6) if b else 100.0
    return {"fuzzy_match_percent": pct(fuzzy, total), "total_code": str(total), "matched_code": str(done),
            "matched_code_percent": pct(done, total), "total_functions": n, "matched_functions": nd,
            "matched_functions_percent": pct(nd, n)}


def summed(units):
    """Measures of several units: their functions' measures, plus the complete code and units."""
    m = measures([f for u in units for f in u["_fns"]])
    complete = sum(int(u["measures"]["total_code"]) for u in units if u["metadata"]["complete"])
    total = int(m["total_code"])
    m.update({"complete_code": str(complete),
              "complete_code_percent": round(100.0 * complete / total, 6) if total else 100.0,
              "total_units": len(units), "complete_units": sum(1 for u in units if u["metadata"]["complete"])})
    return m


def unit_measures(fns):
    m = measures(fns)
    complete = bool(fns) and all(f["done"] for f in fns)
    m.update({"complete_code": m["total_code"] if complete else "0",
              "complete_code_percent": 100.0 if complete else 0.0, "total_units": 1,
              "complete_units": int(complete)})
    return m, complete


def make_unit(name, fns, source, cats):
    fns = sorted(fns, key=lambda f: f["addr"])
    m, complete = unit_measures(fns)
    base = fns[0]["addr"]
    return {"name": name, "measures": m,
            "functions": [{"name": f["name"], "size": str(f["size"]),
                           "fuzzy_match_percent": 100.0 if f["done"] else 0.0,
                           "address": str(f["addr"] - base),
                           "metadata": {"virtual_address": str(f["addr"])}} for f in fns],
            "metadata": {"complete": complete, "source_path": source, "progress_categories": cats},
            "_fns": fns}


def core_functions(t, inv):
    """{source file: (unit, [function])} of one core program: the inventory's functions, each
    with the state of the source entries it covers."""
    es = entries(t)
    starts = [e[2] for e in es]
    import bisect
    out = {}
    for sec, a, n, kind in inv[t.name]:
        i = bisect.bisect_right(starts, a) - 1
        if i < 0:
            continue
        rel, u = es[i][0], es[i][1]
        j = bisect.bisect_left(starts, a + n)
        kinds = {e[3] for e in es[i:j]}
        if kind == "remnant":
            k = "LINKER_REMNANT"
        elif "INCLUDE_ASM" in kinds:
            k = "INCLUDE_ASM"
        elif kinds == {"C"}:
            k = "C"
        elif "ASM_FUNC" in kinds:
            k = "ASM_FUNC"
        else:
            k = "C" if "C" in kinds else "LINKER_REMNANT"
        out.setdefault(rel, (u, []))[1].append(
            {"name": "func_%08X" % a, "addr": a, "size": n, "kind": k, "done": k != "INCLUDE_ASM"})
    return out


def level_functions():
    """[(unit name, source path, categories, [function])] of the level code."""
    import level_catalogue as lc
    import level_tree
    import levels
    sources = level_tree.source_entries()
    shared, own = [], collections.defaultdict(list)
    for name, kind, size, _, remnant, places in lc.read_catalogue():
        if kind not in ("shared", "level"):
            continue          # frontbin's (or boot_elf's) function: counted with it
        k = sources.get(name, (None, "INCLUDE_ASM"))[1]
        k = "LINKER_REMNANT" if remnant and k == "INCLUDE_ASM" else k
        f = {"name": name, "addr": places[0][1], "size": size, "kind": k, "done": k != "INCLUDE_ASM"}
        (shared if kind == "shared" else own[places[0][0]]).append(f)
    out = [("Shared level code", "src/levels/shared", ["level_code", "common"], shared)]
    for n in sorted(own):
        out.append((levels.title(n), "src/levels/" + levels.dirname(n), ["level_code", "levels", "level_%02d" % n],
                    own[n]))
    return out


def report():
    import inventory
    import level_catalogue as lc
    import levels
    inv = inventory.read_inventory()
    pairs = lc.read_pairs()
    per = {name: core_functions(t, inv) for name, t in targets.TARGETS.items()}
    # the front end's pairs: one function, in frontbin's unit unless only boot_elf's copy is final
    fb_done = {f["name"]: f["done"] for _, fns in per["frontbin"].values() for f in fns}
    drop = {"frontbin": set(), "boot_elf": set()}
    be_done = {f["name"]: f["done"] for _, fns in per["boot_elf"].values() for f in fns}
    for be_name, fb_name in pairs.items():
        if be_name in be_done and fb_name in fb_done:
            if be_done[be_name] and not fb_done[fb_name]:
                drop["frontbin"].add(fb_name)
            else:
                drop["boot_elf"].add(be_name)
    units, cats, table = [], [], []
    for name, t in targets.TARGETS.items():
        program = []
        for rel, (u, fns) in per[name].items():
            fns = [f for f in fns if f["name"] not in drop.get(name, ())]
            if not fns:
                continue
            stem = os.path.splitext(os.path.relpath(rel, u.src_dir))[0].replace(os.sep, "/")
            uname = "%s/%s/%s" % (name, u.name, stem) if len(t.units) > 1 else "%s/%s" % (name, stem)
            x = make_unit(uname, fns, rel.replace(os.sep, "/"), ["core", name, "%s_%s" % (name, u.name)])
            x["_unit"] = u
            program.append(x)
        cats.append({"id": name, "name": t.label, "measures": summed(program)})
        for u in t.units:
            cats.append({"id": "%s_%s" % (name, u.name), "name": "%s %s" % (name, u.section),
                         "measures": summed([x for x in program if x["_unit"] is u])})
        kinds = [f["kind"] for x in program for f in x["_fns"]]
        table.append((name, {k: kinds.count(k) for k in KINDS}))
        units += program
    core = list(units)
    level_units = [make_unit(n, fns, src, c) for n, src, c, fns in level_functions() if fns]
    for label, cat in (("Shared level code", "common"), ("Level-specific code", "levels")):
        kinds = [f["kind"] for x in level_units if cat in x["metadata"]["progress_categories"] for f in x["_fns"]]
        table.append((label, {k: kinds.count(k) for k in KINDS}))
    units += level_units
    cats.insert(0, {"id": "core", "name": "Core programs", "measures": summed(core)})
    has = lambda c: [x for x in level_units if c in x["metadata"]["progress_categories"]]
    cats.append({"id": "level_code", "name": "Level code", "measures": summed(level_units)})
    cats.append({"id": "common", "name": "Shared level code", "measures": summed(has("common"))})
    cats.append({"id": "levels", "name": "Level-specific code", "measures": summed(has("levels"))})
    for x in has("levels"):
        cid = next(c for c in x["metadata"]["progress_categories"] if c.startswith("level_") and c != "level_code")
        cats.append({"id": cid, "name": x["name"], "measures": summed([x])})
    top = summed(units)
    for u in units:
        u.pop("_fns", None)
        u.pop("_unit", None)
    return {"version": 2, "measures": top, "categories": cats, "units": units}, table


KINDS = ("C", "ASM_FUNC", "LINKER_REMNANT", "INCLUDE_ASM")


# --- the NTSC-U report (--version us; docs/versions.md) -----------------------------------------

def report_us():
    """The NTSC-U disc's report, from its own function tables (config/us/inventory.tsv,
    frontend_pairs.tsv, levels/functions.tsv) and config/us/map.tsv (tools/version_map.py): a
    function is final when PAL's source for its twin checks MATCH there (or it is a linker
    remnant); its fuzzy match is the closeness its twin's C or near miss checks to there. Exact
    and fuzzy are counted apart: a near miss raises only the fuzzy figure."""
    import inventory
    import level_catalogue as lc
    import levels
    import version
    import version_map
    import c_objects
    m = version_map.Map()
    built = c_objects.read_built()
    inv = inventory.read_inventory(version.cfg("inventory.tsv", v="us"))
    pairs = lc.read_pairs(version.cfg("frontend_pairs.tsv", v="us"))
    best = {}                      # (program, NTSC-U name) -> (done, fuzzy, kind, PAL file stem)
    pal_files = {}
    for name, t in targets.TARGETS.items():
        for rel, u, a, k in entries(t):
            pal_files[(name, a)] = (rel, u)
    for r in m.rows:
        if r["us"] == "-" or r["status"] in ("none", "asm"):
            continue
        key = (r["program"], r["us"])
        done = r["status"] == "match"
        if done and r["state"] == "C" and built is not None:
            # C counts when every NTSC-U program that has it builds it from C (config/us/built.tsv)
            b = built.get((r["program"], r["pal"] if r["pal"] != "-" else version_map.native_name(r["us"])))
            done = bool(b and b[0] and not b[1])
        kind = r["state"] if done else "INCLUDE_ASM"
        old = best.get(key)
        fuzzy = r["closeness"]
        if old is None or (done, fuzzy) > (old[0], old[1]):
            best[key] = (done, fuzzy, kind if done else "INCLUDE_ASM", r["pal"] if r["pal"] != "-" else None)
    units, cats, table = [], [], []
    per = {}
    for name, t in targets.TARGETS.items():
        files = sorted((a, rel, u) for (p, a), (rel, u) in pal_files.items() if p == name)
        starts = [f[0] for f in files]
        fns = {}
        for sec, a, n, kind in inv.get(name, []):
            fname = "func_%08X" % a
            done, fuzzy, k, pal = best.get((name, fname), (False, 0.0, "INCLUDE_ASM", None))
            if kind == "remnant":
                done, fuzzy, k = True, 100.0, "LINKER_REMNANT"
            if pal:          # the unit of its twin's PAL source file
                import bisect
                i = bisect.bisect_right(starts, int(pal[5:], 16)) - 1
                rel, u = files[i][1], files[i][2]
                stem = os.path.splitext(os.path.relpath(rel, u.src_dir))[0].replace(os.sep, "/")
                uname = "%s/%s/%s" % (name, u.name, stem) if len(t.units) > 1 else "%s/%s" % (name, stem)
                src = rel
            else:
                sec_name = {"core.text": "core", ".text": "text"}[sec]
                uname = "%s/%s/ntsc_only" % (name, sec_name) if len(t.units) > 1 else "%s/ntsc_only" % name
                src = "src/us/%s" % name
            sec_unit = {"core.text": "core", ".text": "text"}[sec]
            fns.setdefault((uname, src, sec_unit), []).append(
                {"name": fname, "addr": a, "size": n, "kind": k, "done": done, "fuzzy": 100.0 if done else fuzzy})
        per[name] = fns
    # boot_elf's front end is frontbin's: a pair counts once (in frontbin's unit unless only boot_elf's is final)
    fb = {f["name"]: f for fs in per["frontbin"].values() for f in fs}
    be = {f["name"]: f for fs in per["boot_elf"].values() for f in fs}
    drop = {"frontbin": set(), "boot_elf": set()}
    for be_name, fb_name in pairs.items():
        if be_name in be and fb_name in fb:
            if be[be_name]["done"] and not fb[fb_name]["done"]:
                drop["frontbin"].add(fb_name)
            else:
                drop["boot_elf"].add(be_name)
    for name, t in targets.TARGETS.items():
        program = []
        for (uname, src, sec_unit), fns in sorted(per[name].items()):
            fns = [f for f in fns if f["name"] not in drop.get(name, ())]
            if not fns:
                continue
            x = make_unit(uname, fns, src, ["core", name, "%s_%s" % (name, sec_unit)])
            x["_sec"] = sec_unit
            program.append(x)
        cats.append({"id": name, "name": t.label, "measures": summed(program)})
        for u in t.units:
            cats.append({"id": "%s_%s" % (name, u.name), "name": "%s %s" % (name, u.section),
                         "measures": summed([x for x in program if x["_sec"] == u.name])})
        kinds = [f["kind"] for x in program for f in x["_fns"]]
        table.append((name, {k: kinds.count(k) for k in KINDS}))
        units += program
    core = list(units)
    shared, own = [], collections.defaultdict(list)
    for name, kind, size, _, remnant, places in lc.read_catalogue(version.cfg("levels", "functions.tsv", v="us")):
        if kind not in ("shared", "level"):
            continue
        done, fuzzy, k, pal = best.get(("levels", name), (False, 0.0, "INCLUDE_ASM", None))
        if remnant:
            done, fuzzy, k = True, 100.0, "LINKER_REMNANT"
        f = {"name": name, "addr": places[0][1], "size": size, "kind": k, "done": done,
             "fuzzy": 100.0 if done else fuzzy}
        (shared if kind == "shared" else own[places[0][0]]).append(f)
    lf = [("Shared level code", "src/levels/shared", ["level_code", "common"], shared)]
    for n in sorted(own):
        lf.append((levels.title(n), "src/levels/" + levels.dirname(n), ["level_code", "levels", "level_%02d" % n], own[n]))
    level_units = [make_unit(n, fns, src, c) for n, src, c, fns in lf if fns]
    for label, cat in (("Shared level code", "common"), ("Level-specific code", "levels")):
        kinds = [f["kind"] for x in level_units if cat in x["metadata"]["progress_categories"] for f in x["_fns"]]
        table.append((label, {k: kinds.count(k) for k in KINDS}))
    units += level_units
    cats.insert(0, {"id": "core", "name": "Core programs", "measures": summed(core)})
    has = lambda c: [x for x in level_units if c in x["metadata"]["progress_categories"]]
    cats.append({"id": "level_code", "name": "Level code", "measures": summed(level_units)})
    cats.append({"id": "common", "name": "Shared level code", "measures": summed(has("common"))})
    cats.append({"id": "levels", "name": "Level-specific code", "measures": summed(has("levels"))})
    for x in has("levels"):
        cid = next(c for c in x["metadata"]["progress_categories"] if c.startswith("level_") and c != "level_code")
        cats.append({"id": cid, "name": x["name"], "measures": summed([x])})
    top = summed(units)
    for u in units:
        for f, g in zip(u["functions"], u["_fns"]):
            f["fuzzy_match_percent"] = g["fuzzy"]
        u.pop("_fns", None)
        u.pop("_sec", None)
    return {"version": 2, "measures": top, "categories": cats, "units": units}, table


def text_table(rows):
    lines = ["| Program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |",
             "| --- | ---: | ---: | ---: | ---: | ---: | ---: |"]
    for name, c in rows:
        total = sum(c.values())
        done = total - c["INCLUDE_ASM"]
        lines.append("| %s | %d | %d (%.1f%%) | %d | %d | %d | %d |" % (
            name, total, done, 100.0 * done / total if total else 0, c["C"], c["ASM_FUNC"],
            c["LINKER_REMNANT"], c["INCLUDE_ASM"]))
    return "\n".join(lines)


def readme_with(table_text, begin=BEGIN, end=END):
    readme = open(README, encoding="utf-8").read()
    if begin not in readme or end not in readme:
        sys.exit("README.md has no %s ... %s block" % (begin, end))
    head, rest = readme.split(begin, 1)
    _, tail = rest.split(end, 1)
    return readme, head + begin + "\n" + table_text + "\n" + end + tail


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="rewrite progress/report.json and the README table")
    ap.add_argument("--check", action="store_true", help="fail if either is out of date")
    a = ap.parse_args()
    import version
    us = version.is_us()
    rep, rows = report_us() if us else report()
    report_path = version.progress("report.json")
    begin, end = (BEGIN_US, END_US) if us else (BEGIN, END)
    m = rep["measures"]
    cat = {c["id"]: c["measures"] for c in rep["categories"]}
    line = lambda label, x: "| %s | %s of %s | %s of %s bytes (%.2f%%) | %.2f%% |" % (
        label, format(x["matched_functions"], ","), format(x["total_functions"], ","),
        format(int(x["matched_code"]), ","), format(int(x["total_code"]), ","), x["matched_code_percent"],
        x["fuzzy_match_percent"])
    text = text_table(rows) + "\n\n" + "\n".join([
        "| | Functions (exact) | Code (exact) | Fuzzy |", "| --- | ---: | ---: | ---: |",
        line("Core programs", cat["core"]), line("Shared level code", cat["common"]),
        line("Level-specific code", cat["levels"]), line("**Total**", m)]) + "\n\n" + (
        "Each distinct function counts once: boot_elf's copy of the front end is frontbin's, and a "
        "level function counts once however many of the %d levels have it. %s bytes (%.2f%%) are in "
        "source files with nothing left to decompile." % (
            len(__import__("levels").NAMES), format(int(m["complete_code"]), ","), m["complete_code_percent"]))
    if us:
        text = text.replace("| Program | Functions | Final source |", "| NTSC-U program | Functions | Final source |", 1)
        text = text.rsplit("\n\n", 1)[0] + "\n\n" + (
            "Counted from the NTSC-U disc's own function tables; a function is final when PAL's source for "
            "the function with its code checks MATCH there (config/us/map.tsv, tools/version_map.py), and "
            "the fuzzy figure adds what the near misses and the C that does not check yet reach there "
            "(docs/versions.md). %d levels; each distinct function counts once." % len(__import__("levels").NAMES))
    body = json.dumps(rep, indent=1) + "\n"
    print(text)
    print("\nall programs: %d of %d functions final (%.2f%% of the code)"
          % (m["matched_functions"], m["total_functions"], m["matched_code_percent"]))
    old_readme, new_readme = readme_with(text, begin, end)
    rel = os.path.relpath(report_path, ROOT)
    cmd = "python3 tools/progress.py%s --write" % (" --version us" if us else "")
    if a.write:
        os.makedirs(os.path.dirname(report_path), exist_ok=True)
        open(report_path, "w", encoding="utf-8", newline="\n").write(body)
        open(README, "w", encoding="utf-8", newline="\n").write(new_readme)
        print("wrote %s and the README table" % rel)
    if a.check:
        problems = []
        if not os.path.exists(report_path) or open(report_path, encoding="utf-8").read() != body:
            problems.append("%s is out of date (%s)" % (rel, cmd))
        if old_readme != new_readme:
            problems.append("the README table is out of date (%s)" % cmd)
        # the two versions stay in step: shared code is one source, matches carry across
        import version_map
        problems += ["versions out of step (python3 tools/version_map.py --write): " + p
                     for p in version_map.check()]
        for p in problems:
            print("error:", p)
        sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
