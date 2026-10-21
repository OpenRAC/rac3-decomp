#!/usr/bin/env python3
"""version_map.py: every PAL function on the NTSC-U disc, and whether its source matches there.

    python3 tools/version_map.py --write -j 16 --toolchain DIR --runner WIBO   # config/us/map.tsv (dumps + toolchain)
    python3 tools/version_map.py --pairs-only                                  # only the twins (no checks)
    python3 tools/version_map.py --check                                       # the map is current (CI, no disc)

The two versions share one source tree (docs/versions.md). src/ is PAL's: its names are PAL
addresses and catalogue names. A function whose code is the same on both discs is the same C,
in the same file, compiled with that file's flags; it is never copied. C for NTSC-U alone, where
the bytes differ, is in src/us/ (config/us/text_parts.txt).

1. **Twins.** Each PAL function is paired with the NTSC-U function with the same code: equal
   inventory.identity() (only address fields masked: jump targets, address halves, $gp offsets;
   constants, stack slots and field offsets compared) and equal size. Core programs: per code
   section, the unique pairs first as anchors, then repeated code copy by copy between them
   (level_catalogue.pair_in_order(), as boot_elf's front end is paired with frontbin). Levels:
   catalogue row against catalogue row (config/levels/functions.tsv, config/us/levels/
   functions.tsv) with the same identity and size; copies in canonical order.
2. **Status on NTSC-U.** A PAL function with final source (C, ASM_FUNC, LINKER_REMNANT) and a
   twin is `match` when, for C, the stock checker gives MATCH at the twin's place
   (`tools/check.py --version us`: its file's flags, its file's context, the names as the NTSC-U
   disc has them; a name whose NTSC-U value is not known is masked). ASM_FUNC and LINKER_REMNANT
   are final source on both discs by their twin's code. A C function that does not check is
   `nomatch` (its diff count gives the closeness), a twin of INCLUDE_ASM is `asm`, a PAL function
   with no twin is `none` (its NTSC-U counterpart, if any, has other bytes: src/us/). A near
   miss of nonmatching/ with a twin is `near`, with the closeness it checks to there.
3. **Staying in step.** Every row keeps a hash of its source file and flags line. `--check`
   (run by tests/check_repository.py and CI, with no disc) fails when src/ changed since the map
   was written (a PAL change or match not carried), when a function final on one disc and
   identical on the other is not final there (`nomatch`), or when src/us/ has C for a function
   that has a PAL twin (shared code must be one source). `--write` carries every change: run it
   (with tools/progress.py --version us --write) before every push.

config/us/map.tsv holds names, addresses, sizes, statuses and hashes: no retail bytes.
"""
import argparse
import collections
import hashlib
import os
import re
import struct
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402

MAP = version.cfg("map.tsv", v="us")
CORE = ("frontbin", "boot_elf", "i5bootn")
FINAL = ("C", "ASM_FUNC", "LINKER_REMNANT")
HEAD = """# PAL's functions on the NTSC-U disc (tools/version_map.py --write; docs/versions.md): PAL name,
# program (frontbin, boot_elf, i5bootn or levels), NTSC-U name, NTSC-U place (level:address or
# address), size, PAL state, status on NTSC-U (match, nomatch, asm, near; differs: no function has
# the same code, the NTSC-U name is the function in its place, whose C goes in src/us/; none), closeness
# (percent), source hash (its file and flags line, for --check).
"""
RESIDENT_END = 0x1D5680          # below: the engine core, the same on both discs


# --- reading the tables ---------------------------------------------------------------------

def cat_path(v):
    return version.cfg("levels", "functions.tsv", v=v)


class Map:
    """config/us/map.tsv, with lookups."""

    def __init__(self, path=MAP):
        self.rows = []
        if os.path.exists(path):
            for line in open(path, encoding="utf-8"):
                if line.startswith("#") or not line.strip():
                    continue
                f = line.rstrip("\n").split("\t")
                self.rows.append({"pal": f[0], "program": f[1], "us": f[2], "place": f[3], "size": int(f[4]),
                                  "state": f[5], "status": f[6], "closeness": float(f[7]), "hash": f[8]})
        self.by_pal = {(r["program"], r["pal"]): r for r in self.rows if r["pal"] != "-"}
        self._us_levels = None

    def us_place(self, program, name):
        """(level number or None, NTSC-U address, size) of a PAL name's twin, or of an NTSC-U name."""
        r = self.by_pal.get((program, name))
        if r is None and program in CORE and re.match(r"^func_[0-9A-F]{8}$", name):
            # a later source entry of a function split in src/: at its offset in the twin
            a = int(name[5:], 16)
            for x in self.rows:
                if x["program"] == program and x["pal"] != "-" and x["state"] != "near" and x["us"] != "-" \
                        and ":" not in x["place"]:
                    pa = int(x["pal"][5:], 16)
                    if pa < a < pa + x["size"]:
                        for n, off, size in covered(program, pa, x["size"]):
                            if n == name:
                                return None, int(x["place"], 16) + off, size
        if r is None:
            r = next((x for x in self.rows if x["pal"] == "-" and x["us"] == name and x["program"] == program), None)
        if r is None or r["us"] == "-":
            return None
        if program in CORE and ":" not in r["place"] and r["pal"] != "-" and r["state"] != "near":
            parts = covered(program, int(r["pal"][5:], 16), r["size"])
            if len(parts) > 1 and parts[0][0] == name:
                return None, int(r["place"], 16), parts[0][2]
        if ":" in r["place"]:
            n, a = r["place"].split(":")
            return int(n), int(a, 16), r["size"]
        return None, int(r["place"], 16), r["size"]

    def us_level_rows(self):
        if self._us_levels is None:
            import level_catalogue as lc
            self._us_levels = lc.read_catalogue(cat_path("us"))
        return self._us_levels


def load():
    return Map()


class UsNames:
    """The NTSC-U value of each name PAL's C uses, where it is known (tools/check.py --version us):
    a function's name is its twin's address (in a level: the twin's place in that level, a
    front-end function the level's copy of its twin); a name in the resident engine core
    (below 0x1D5680, the same on both discs) its own address; anything else is unknown (masked)."""

    def __init__(self, m, program, number):
        self.m, self.program, self.number = m, program, number
        self.level_place = {}
        if number is not None:
            rows = m.us_level_rows()
            self.level_place = {r[0]: a for r in rows for n, a in r[5] if n == number}

    def expected(self, name):
        m = ALIAS.match(name)
        if m:
            # an alias (<name>_<caller>): another copy than the catalogue's; known only in the core
            a = int(m.group(3), 16) if m.group(2) != "func_L" else None
            return a if a is not None and a < RESIDENT_END else None
        fe = name.startswith("fe_")
        base = name[3:] if fe else name
        m = re.match(r"^(?:D|func|jtbl)_([0-9A-F]{8})$", base)
        if m and int(m.group(1), 16) < RESIDENT_END:
            return int(m.group(1), 16)
        if self.number is None:
            r = self.m.by_pal.get((self.program, base))
            return int(r["place"], 16) if r and r["us"] != "-" and ":" not in r["place"] else None
        if fe or re.match(r"^func_[0-9A-F]{8}$", base):
            r = self.m.by_pal.get(("frontbin", base))
            return self.level_place.get(r["us"]) if r and r["us"] != "-" else None
        r = self.m.by_pal.get(("levels", base))
        return self.level_place.get(r["us"]) if r and r["us"] != "-" else None


ALIAS = re.compile(r"^(fe_)?(D_|func_|jtbl_|func_L)(?:\d\d_)?([0-9A-F]{8})_[0-9A-Za-z]+$")


US_PARTS = version.cfg("text_parts.txt", v="us")
US_SRC = os.path.join(ROOT, "src", "us")


def us_parts():
    """{src/us/ file: flags} of config/us/text_parts.txt"""
    out = {}
    if os.path.exists(US_PARTS):
        for line in open(US_PARTS):
            if line.strip() and not line.startswith("#"):
                rel, flags = line.rstrip("\n").split("\t", 1)
                out[rel] = flags
    return out


def us_sources():
    """{(program, source name): src/us/ file} of the C written for NTSC-U alone:
    src/us/<frontbin|boot_elf|i5bootn>/*.c. Its names are NTSC-U's own, with their own prefix so
    they never meet src/'s PAL names in one build: func_U_XXXXXXXX, D_U_XXXXXXXX (NTSC-U
    addresses); a name in the resident engine core (below 0x1D5680, the same on both discs) is
    written plainly. native_name() / us_name() convert between func_U_ and the inventory's name."""
    out = {}
    for d, _, fs in os.walk(US_SRC):
        for f in sorted(fs):
            if not f.endswith(".c"):
                continue
            rel = os.path.relpath(os.path.join(d, f), ROOT).replace(os.sep, "/")
            program = rel.split("/")[2]
            for name in re.findall(r"localdecomp:start (func_\w+)", open(os.path.join(d, f)).read()):
                out[(program, name)] = rel
    return out


def native_name(us):
    """func_XXXXXXXX (an NTSC-U inventory name) -> func_U_XXXXXXXX (its src/us/ name)"""
    return "func_U_" + us[5:] if re.match(r"^func_[0-9A-F]{8}$", us) else us


def us_name(native):
    """func_U_XXXXXXXX -> func_XXXXXXXX"""
    return "func_" + native[7:] if native.startswith("func_U_") else native


class NativeNames:
    """NTSC-U C's names (src/us/): func_U_/D_U_XXXXXXXX are NTSC-U addresses, plain func_/D_ names
    the resident engine core's."""

    def __init__(self, number):
        self.number = number
        self.place = {}
        if number is not None:
            import level_catalogue as lc
            self.place = {r[0]: a for r in lc.read_catalogue(cat_path("us")) for n, a in r[5] if n == number}

    def expected(self, name):
        if ALIAS.match(name):
            return None
        if name in self.place:
            return self.place[name]
        m = re.match(r"^(?:D|func|jtbl)_L(\d\d)_([0-9A-F]{8})$", name)
        if m:
            return int(m.group(2), 16) if int(m.group(1)) == self.number else None
        m = re.match(r"^(?:D|func|jtbl)_U_([0-9A-F]{8})$", name)
        if m:
            return int(m.group(1), 16)
        m = re.match(r"^(?:D|func|jtbl)_([0-9A-F]{8})$", name)
        return int(m.group(1), 16) if m and int(m.group(1), 16) < RESIDENT_END else None


def native_function(names, t, path, us):
    """tools/check.py --version us --native: (flags, the NTSC-U dump) for NTSC-U names, placing them
    in US['places'] and the resolver in US['names']."""
    import inventory as inv
    import level_catalogue as lc
    import levels
    m = re.match(r"^func_L(\d\d)_", names[0])
    number = None
    if m:
        rows = {r[0]: r for r in lc.read_catalogue(cat_path("us"))}
        for n in names:
            if n not in rows:
                sys.exit("%s is not in config/us/levels/functions.tsv" % n)
            number = rows[n][5][0][0]
            us["places"][n] = (dict(rows[n][5])[number], rows[n][2])
        program = "levels"
    else:
        program = t.name
        sizes = {a: n for sec, a, n, k in inv.read_inventory(version.cfg("inventory.tsv", v="us"))[program]}
        for n in names:
            a = int(us_name(n)[5:], 16)
            if a not in sizes:
                sys.exit("%s is not a function of NTSC-U %s (config/us/inventory.tsv)" % (n, program))
            us["places"][n] = (a, sizes[a])
    for n in names:
        print("%s: NTSC-U %s at 0x%08X, %d bytes" % (n, "level %02d" % number if number else program, *us["places"][n]))
    us["names"] = NativeNames(number)
    rel = os.path.relpath(os.path.abspath(path), ROOT).replace(os.sep, "/")
    flags = us_parts().get(rel) or counterpart_flags(program, us_name(names[0]))
    if flags is None:
        sys.exit("%s: no flags (a src/us/ file needs its line in config/us/text_parts.txt)" % rel)
    return flags.split(), levels.elf_path(number) if number else levels.core_elf_path(program)


def counterpart_flags(program, us_name):
    """The flags of the PAL source file whose function stands where `us_name` does (its counterpart):
    the file an NTSC-U-only function belongs to."""
    r = next((x for x in Map().rows if x["program"] == program and x["us"] == us_name and x["pal"] != "-"), None)
    if r is None:
        return None
    if program == "levels":
        import level_tree
        e = level_tree.source_entries().get(r["pal"])
        return level_tree.read_parts().get(e[0]) if e else None
    import targets
    t = targets.TARGETS[program]
    best = None
    for line in open(t.path("parts")):
        f = line.split("#", 1)[0].split(None, 1)
        if len(f) == 2 and int(f[0], 16) <= int(r["pal"][5:], 16) and (best is None or int(f[0], 16) >= best[0]):
            best = (int(f[0], 16), f[1].strip())
    return best[1] if best else None


def proven(program):
    """{start: end} on NTSC-U of the twins of PAL C that checks MATCH (tools/inventory.py); and
    where NTSC-U's cut starts a counterpart on linker fill (0xCDCDCDCD) before code that is PAL's
    C function word for word, that function's start after the fill."""
    out = {}
    try:
        import struct
        import inventory as inv
        import levels
        secs = inv.elf_sections(levels.core_elf_path(program, v="us"))
        pal_secs = inv.elf_sections(levels.core_elf_path(program, v="pal"))
        states = pal_states()
    except Exception:
        secs = None
    if secs:
        def words(ss, a, n):
            for _, base, d, _ in ss:
                if base <= a and a + n <= base + len(d):
                    return d[a - base:a - base + n]
        for r in Map().rows:
            if r["program"] != program or r["status"] != "differs" or r["state"] != "C" or ":" in r["place"]:
                continue
            a = int(r["place"], 16)
            st = states.get((program, r["pal"]))
            head = words(secs, a, 4)
            if not st or head != b"\xcd\xcd\xcd\xcd":
                continue
            k = 4
            while words(secs, a + k, 4) == b"\xcd\xcd\xcd\xcd":
                k += 4
            if words(secs, a + k, st[2]) == words(pal_secs, st[3], st[2]):
                out[a + k] = a + k + st[2]
    for r in Map().rows:
        # a twin, or a counterpart PAL's C checks MATCH at (the inventory cut it otherwise)
        ok = r["status"] == "match" or r["status"] == "differs" and r["closeness"] == 100.0
        if r["program"] == program and ok and r["state"] == "C" and ":" not in r["place"]:
            a = int(r["place"], 16)
            out[a] = a + r["size"]
    return out


# --- PAL's state ----------------------------------------------------------------------------

def file_hashes():
    """{source file: hash of its text and its flags line}"""
    out = {}
    import level_tree
    parts = level_tree.read_parts()
    for root in ("src",):
        for d, _, fs in os.walk(os.path.join(ROOT, root)):
            for f in fs:
                if f.endswith(".c"):
                    rel = os.path.relpath(os.path.join(d, f), ROOT).replace(os.sep, "/")
                    h = hashlib.sha1(open(os.path.join(d, f), "rb").read())
                    h.update(parts.get(rel, "").encode())
                    h.update(us_parts().get(rel, "").encode())
                    out[rel] = h
    # a core file's flags are its text_parts.txt line at its start address
    import srcfiles as sf
    import targets
    for name in CORE:
        t = targets.TARGETS[name]
        flags = [l for l in open(t.path("parts")) if l.strip() and not l.startswith("#")]
        for rel, start in sf.read_file_list(t.path("files")):
            if rel in out:
                fl = [l for l in flags if int(l.split()[0], 16) == start]
                out[rel].update("".join(fl).encode())
    return {k: v.hexdigest()[:12] for k, v in out.items()}


def pal_states():
    """{(program, PAL name): (state, source file, size, address)} for the core inventory's
    functions and the level catalogue's shared and level functions."""
    import inventory
    import level_catalogue as lc
    import level_tree
    import progress
    import targets
    out = {}
    inv = inventory.read_inventory(version.cfg("inventory.tsv", v="pal"))
    for name in CORE:
        for rel, (u, fns) in progress.core_functions(targets.TARGETS[name], inv).items():
            for f in fns:
                out[(name, f["name"])] = (f["kind"], rel, f["size"], f["addr"])
    sources = level_tree.source_entries()
    for name, kind, size, _, remnant, places in lc.read_catalogue(cat_path("pal")):
        if kind not in ("shared", "level"):
            continue
        rel, k = sources.get(name, (None, "INCLUDE_ASM"))
        k = "LINKER_REMNANT" if remnant and k == "INCLUDE_ASM" else k
        out[("levels", name)] = (k, rel, size, places[0][1])
    return out



def entries_of(program):
    """[(address, kind, file)] of a core program's source entries, in address order (PAL)."""
    import progress
    import targets
    return [(a, k, rel) for rel, u, a, k in progress.entries(targets.TARGETS[program])]


def covered(program, addr, size, es=None):
    """[(entry name, offset, size)] of the source entries a PAL core function covers (a function can
    be split into several entries in src/: each is checked at its offset)."""
    import bisect
    es = es or entries_of(program)
    starts = [e[0] for e in es]
    i = max(0, bisect.bisect_right(starts, addr) - 1)
    out = []
    while i < len(es) and es[i][0] < addr + size:
        a = es[i][0]
        end = min(es[i + 1][0] if i + 1 < len(es) else addr + size, addr + size)
        if a >= addr:
            out.append(("func_%08X" % a, a - addr, end - a))
        i += 1
    return out



# --- twins (needs both discs' dumps) ----------------------------------------------------------

def section_items(program, section, v):
    import inventory as inv
    import levels
    secs = inv.elf_sections(levels.core_elf_path(program, v=v))
    base, data = next((a, d) for n, a, d, _ in secs if n == section)
    rows = inv.read_inventory(version.cfg("inventory.tsv", v=v))[program]
    out = []
    for sec, a, n, kind in rows:
        if sec == section:
            body = data[a - base:a - base + n]
            out.append((a, (inv.fingerprint(body, a), n)))
    return out


def core_twins():
    """{(program, PAL address): NTSC-U address}"""
    import inventory as inv
    import level_catalogue as lc
    out = {}
    for program in CORE:
        for section in inv.CORE[program]:
            pairs = align(section_items(program, section, "pal"), section_items(program, section, "us"))
            for a, b in pairs.items():
                out[(program, a)] = b
    return out


def level_twins():
    """{PAL catalogue name: NTSC-U catalogue row}: in each level, the two discs' places of equal code
    paired in order (unique code as anchors, copies between them: level_catalogue.pair_in_order());
    each PAL row takes the NTSC-U row most of its levels pair it with."""
    import level_catalogue as lc
    pal_rows = [r for r in lc.read_catalogue(cat_path("pal")) if r[1] in ("shared", "level")]
    us_rows = lc.read_catalogue(cat_path("us"))
    key = lambda r: (r[3], r[2])
    pal_lv, us_lv = collections.defaultdict(list), collections.defaultdict(list)
    for r in pal_rows:
        for n, a in r[5]:
            pal_lv[n].append((a, key(r), r[0]))
    us_name = {}
    for r in us_rows:
        for n, a in r[5]:
            us_lv[n].append((a, key(r), r[0]))
            us_name[(n, a)] = r[0]
    pal_name = {(n, a): nm for n, v in pal_lv.items() for a, _, nm in v}
    votes = collections.defaultdict(collections.Counter)
    import difflib
    for n in pal_lv:
        pa = sorted(pal_lv[n])
        ua = sorted(us_lv.get(n, []))
        # the two sequences of code aligned in order (equal code, the longest common runs first)
        sm = difflib.SequenceMatcher(None, [k for _, k, _ in pa], [k for _, k, _ in ua], autojunk=False)
        for i, j, size in sm.get_matching_blocks():
            for t in range(size):
                votes[pa[i + t][2]][ua[j + t][2]] += 1
    by = {r[0]: r for r in us_rows}
    out, taken = {}, set()
    for pn, c in sorted(votes.items(), key=lambda x: -max(x[1].values())):
        for un, _ in c.most_common():
            if un not in taken:
                out[pn] = by[un]
                taken.add(un)
                break
    # code unique on both discs that the alignment missed (moved far): paired by its code alone
    pk, uk = collections.defaultdict(list), collections.defaultdict(list)
    for r in pal_rows:
        pk[key(r)].append(r[0])
    for r in us_rows:
        uk[key(r)].append(r[0])
    for k, v in pk.items():
        if len(v) == 1 and len(uk.get(k, ())) == 1 and v[0] not in out and uk[k][0] not in taken:
            out[v[0]] = by[uk[k][0]]
            taken.add(uk[k][0])
    # copies left over on both sides: in canonical order
    canon = {r[0]: r[5][0] for r in pal_rows}
    ucanon = {r[0]: r[5][0] for r in us_rows}
    for k, v in pk.items():
        left = sorted((n for n in v if n not in out), key=canon.get)
        free = sorted((n for n in uk.get(k, ()) if n not in taken), key=ucanon.get)
        for pn, un in zip(left, free):
            out[pn] = by[un]
            taken.add(un)
    return out


def align(pal_items, us_items):
    """level_catalogue.align(): the two sequences of code aligned in order."""
    import level_catalogue as lc
    return lc.align(pal_items, us_items)


def gap_pairs(pal_order, us_order, twin):
    """Counterparts by position: PAL functions with no twin, between two PAL functions whose twins
    are in US_ORDER, against the NTSC-U functions between those twins, when there are as many of
    each. PAL_ORDER, US_ORDER: [name] in address order; TWIN: {PAL name: NTSC-U name}."""
    upos = {n: i for i, n in enumerate(us_order)}
    out = {}
    anchors = [(i, upos[twin[n]]) for i, n in enumerate(pal_order) if twin.get(n) in upos]
    for (i0, j0), (i1, j1) in zip(anchors, anchors[1:]):
        if i1 - i0 > 1 and j1 - j0 == i1 - i0 and j1 > j0:
            for k in range(1, i1 - i0):
                out[pal_order[i0 + k]] = us_order[j0 + k]
    return out


def counterparts(states, ct, lt):
    """{(program, PAL name): (NTSC-U name, place, size)} for PAL functions with no twin: the NTSC-U
    function in the same place between twinned neighbours (its code differs: 50 Hz against 60 Hz
    constants, a moved field, other code). Its NTSC-U C goes in src/us/."""
    import inventory as inv
    import level_catalogue as lc
    out = {}
    pal_inv = inv.read_inventory(version.cfg("inventory.tsv", v="pal"))
    us_inv = inv.read_inventory(version.cfg("inventory.tsv", v="us"))
    for program in CORE:
        for section in inv.CORE[program]:
            po = ["func_%08X" % a for sec, a, n, k in pal_inv[program] if sec == section]
            uo = ["func_%08X" % a for sec, a, n, k in us_inv[program] if sec == section]
            usize = {"func_%08X" % a: n for sec, a, n, k in us_inv[program] if sec == section}
            twin = {"func_%08X" % a: "func_%08X" % b for (p, a), b in ct.items() if p == program}
            for pn, un in gap_pairs(po, uo, twin).items():
                out[(program, pn)] = (un, un[5:], usize[un])
    pal_rows = lc.read_catalogue(cat_path("pal"))
    us_rows = lc.read_catalogue(cat_path("us"))
    us_by = {r[0]: r for r in us_rows}
    twin = {p: r[0] for p, r in lt.items()}
    pal_lv, us_lv = collections.defaultdict(list), collections.defaultdict(list)
    for r in pal_rows:
        for n, a in r[5]:
            pal_lv[n].append((a, r[0]))
    for r in us_rows:
        for n, a in r[5]:
            us_lv[n].append((a, r[0]))
    canon = {r[0]: r[5][0][0] for r in pal_rows if r[1] in ("shared", "level")}
    for n in pal_lv:
        po = [x for _, x in sorted(pal_lv[n])]
        uo = [x for _, x in sorted(us_lv.get(n, []))]
        for pn, un in gap_pairs(po, uo, twin).items():
            if canon.get(pn) == n and ("levels", pn) not in out and us_by[un][1] in ("shared", "level"):
                place = dict(us_by[un][5])[n]
                out[("levels", pn)] = (un, "%02d:%08X" % (n, place), us_by[un][2])
    return out


# --- checks ------------------------------------------------------------------------------------

def chunk_text(program, rel, name, block_only=False):
    """The block of `name` in its source file (its C and its own declarations); BLOCK_ONLY: only
    from its localdecomp:start marker (the text before it is its file's context already)."""
    if block_only:
        text = chunk_text(program, rel, name)
        i = text.find("/* localdecomp:start %s " % name)
        return text[i:] if i >= 0 else text
    if program == "levels":
        import level_tree
        _, chunks = level_tree.parse_source(rel)
        return next(body for n, _, body in chunks if n == name)
    import srcfiles as sf
    _, _, chunks = sf.split_file(sf.read_source(rel))
    addr = int(name[5:], 16)
    return "".join(body for a, _, body in chunks if a == addr)


RESULT = re.compile(r"^(func_\w+): (MATCH|(\d+) diff)", re.M)


def ps2as(program, rel):
    """True when the PAL core file `rel` is compiled with @ps2as (its text_parts.txt line)."""
    import srcfiles as sf
    import targets
    t = targets.TARGETS[program]
    start = dict(sf.read_file_list(t.path("files"))).get(rel)
    for line in open(t.path("parts")):
        f = line.split("#", 1)[0].split()
        if f and start is not None and int(f[0], 16) == start:
            return "@ps2as" in f
    return False


def run_check(program, names, path, a, extra=()):
    """{name: (MATCH?, diffs)} of functions on NTSC-U through tools/check.py --version us; a name
    with no result maps to (None, the output's tail)."""
    cmd = [sys.executable, os.path.join(ROOT, "tools", "check.py"), "--version", "us", path] + list(names) + \
        ["--quiet"] + list(extra) + ["--toolchain", a.toolchain] + (["--runner", a.runner] if a.runner else []) + \
        (["--ee29", a.ee29] if a.ee29 else [])
    if program != "levels":
        cmd += ["--target", program]
    env = dict(os.environ, UYA_VERSION="us")
    try:
        p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=600, env=env)
        out = p.stdout + p.stderr
    except subprocess.TimeoutExpired:
        out = "timeout"
    got = {x[0]: (x[1] == "MATCH", int(x[2] or 0)) for x in RESULT.findall(out if out != "timeout" else "")}
    return {n: got.get(n, (None, out[-300:])) for n in names}


def near_misses():
    """[(program, PAL name, path)] of nonmatching/<program>/func_*.c"""
    out = []
    for program in CORE:
        d = os.path.join(ROOT, "nonmatching", program)
        if os.path.isdir(d):
            for f in sorted(os.listdir(d)):
                if re.match(r"^func_[0-9A-F]{8}\.c$", f):
                    out.append((program, f[:-2], os.path.join(d, f)))
    return out


def write(a):
    old = Map()
    old_rows = {(r["program"], r["pal"] if r["pal"] != "-" else "us:" + r["us"], r["state"]): r for r in old.rows}
    states = pal_states()
    hashes = file_hashes()
    ct = core_twins()
    lt = level_twins()
    rows = []
    for (program, name), (state, rel, size, addr) in sorted(states.items()):
        if program == "levels":
            tw = lt.get(name)
            twin_name = tw[0] if tw else "-"
            place = "%02d:%08X" % tw[5][0] if tw else "-"
        else:
            b = ct.get((program, addr))
            twin_name = ("func_%08X" % b) if b is not None else "-"
            place = "%08X" % b if b is not None else "-"
        h = hashes.get(rel, "-") if state == "C" else "-"
        status = "none" if twin_name == "-" else ("match" if state in ("ASM_FUNC", "LINKER_REMNANT") else
                                               "asm" if state == "INCLUDE_ASM" else "check")
        rows.append({"pal": name, "program": program, "us": twin_name, "place": place, "size": size,
                     "state": state, "status": status, "closeness": 100.0 if status == "match" else 0.0,
                     "hash": h, "rel": rel})
    for program, name, path in near_misses():
        st = states.get((program, name))
        if st is None:
            continue
        b = ct.get((program, st[3]))
        h = hashlib.sha1(open(path, "rb").read()).hexdigest()[:12]
        rows.append({"pal": name, "program": program, "us": "func_%08X" % b if b is not None else "-",
                     "place": "%08X" % b if b is not None else "-", "size": st[2], "state": "near",
                     "status": "near" if b is not None else "none", "closeness": 0.0, "hash": h,
                     "rel": os.path.relpath(path, ROOT), "path": path})
    # NTSC-U's own C (src/us/), checked with --native
    import inventory as inv
    import level_catalogue as lc
    us_inv = inv.read_inventory(version.cfg("inventory.tsv", v="us"))
    us_cat = {r[0]: r for r in lc.read_catalogue(cat_path("us"))}
    for (program, src_name), rel in sorted(us_sources().items()):
        name = us_name(src_name)
        if program == "levels":
            r = us_cat.get(name)
            place, size = ("%02d:%08X" % r[5][0], r[2]) if r else ("-", 0)
        else:
            size = next((n for sec, a, n, k in us_inv.get(program, []) if "func_%08X" % a == name), 0)
            place = name[5:] if size else "-"
        rows.append({"pal": "-", "program": program, "us": name, "place": place, "size": size, "state": "C",
                     "status": "check", "closeness": 0.0, "hash": hashes.get(rel, "-"), "rel": rel, "native": True})
    # PAL functions with no twin: their NTSC-U counterpart, whose bytes differ (src/us/)
    cp = counterparts(states, ct, lt)
    for r in rows:
        if r["us"] == "-" and r["state"] != "near" and (r["program"], r["pal"]) in cp:
            r["us"], r["place"], _ = cp[(r["program"], r["pal"])]
            r["status"] = "differs"
    # checks: C with a twin, and near misses with one; unchanged rows keep their result
    jobs = []
    tmp = tempfile.mkdtemp(prefix="version_map_")
    whole = collections.defaultdict(list)       # (program, file) -> rows: PAL C checked in its whole file
    for r in rows:
        if r["status"] not in ("check", "near") and not (r["status"] == "differs" and r["state"] == "C"):
            continue
        prev = old_rows.get((r["program"], r["pal"] if r["pal"] != "-" else "us:" + r["us"], r["state"]))
        if prev and prev["hash"] == r["hash"] and prev["place"] == r["place"] and prev["status"] != "check" \
                and (prev["status"] == "match" or prev["status"] != "nomatch" and prev["closeness"] > 0) \
                and not a.recheck:
            # the earlier result, when it was a result of the same kind of check
            if r["status"] == "check" and prev["status"] in ("match", "nomatch") or prev["status"] == r["status"]:
                r["status"], r["closeness"] = prev["status"], prev["closeness"]
                continue
        if a.pairs_only:
            r["status"] = "nomatch" if r["state"] == "C" else "near"
            continue
        if r.get("native"):
            jobs.append(([r], r["program"], [native_name(r["us"])], os.path.join(ROOT, r["rel"]), ["--native"]))
        elif r["state"] == "near":
            jobs.append(([r], r["program"], [r["pal"]], r["path"], []))
        elif r["program"] != "levels" and not ps2as(r["program"], r["rel"]):
            # the way the build compiles it: the whole source file, alone, with its flags (not an
            # @ps2as file: the build assembles its INCLUDE_ASM blocks apart, Ps2EeAs cannot read them)
            whole[(r["program"], r["rel"])].append(r)
        elif r["program"] != "levels":
            path = os.path.join(tmp, "%s_%s.c" % (r["program"], r["pal"]))
            open(path, "w").write(chunk_text(r["program"], r["rel"], r["pal"], block_only=True))
            jobs.append(([r], r["program"], [r["pal"]], path, []))
        else:
            path = os.path.join(tmp, "%s_%s.c" % (r["program"], r["pal"]))
            open(path, "w").write(chunk_text(r["program"], r["rel"], r["pal"]))
            jobs.append(([r], r["program"], [r["pal"]], path, []))
    ents = {p: entries_of(p) for p in CORE}
    for (program, rel), rs in whole.items():
        names = []
        for r in rs:
            r["parts"] = [n for n, _, _ in covered(program, int(r["pal"][5:], 16), r["size"], ents[program])
                          if any(e[0] == int(n[5:], 16) and e[1] == "C" for e in ents[program])] or [r["pal"]]
            names += r["parts"]
        jobs.append((rs, program, list(dict.fromkeys(names)), os.path.join(ROOT, rel), ["--no-context"]))

    def apply(r, ok, diffs):
        words = max(1, r["size"] // 4)
        if ok is not None and r["hash"] == "unchecked":     # a later fallback got a result
            r["hash"] = hashes.get(r["rel"], "-")
        if ok is None:
            r["status"] = "nomatch" if r["state"] == "C" else "near"
            r["closeness"] = 0.0
            r["hash"] = "unchecked"           # checked again by the next --write
            print("%s %s: no result (%s)" % (r["program"], r["pal"], str(diffs).strip()[-200:]), flush=True)
        elif r["state"] == "near" or r["status"] == "differs":
            # a near miss, or PAL's C at the NTSC-U function with other bytes: a fuzzy figure only
            r["closeness"] = round(max(0.0, 100.0 * (1 - diffs / words)), 2) if not ok else 100.0
        else:
            r["status"] = "match" if ok else "nomatch"
            r["closeness"] = 100.0 if ok else round(max(0.0, 100.0 * (1 - diffs / words)), 2)

    # tools/check.py --version us reads the map: the twins and counterparts go to disk first
    save(rows)
    print("%d checks to run on NTSC-U (%d compiles)" % (sum(len(j[2]) for j in jobs), len(jobs)), flush=True)
    retry = []
    with ThreadPoolExecutor(a.jobs) as ex:
        for (rs, program, names, path, extra), res in zip(jobs, ex.map(lambda j: run_check(*j[1:4], a, j[4]), jobs)):
            for r in rs:
                if r.get("parts"):
                    got = [res[n] for n in r["parts"]]
                    ok = None if any(g[0] is None for g in got) else all(g[0] for g in got)
                    diffs = next((g[1] for g in got if g[0] is None), None) if ok is None else sum(g[1] for g in got)
                else:
                    ok, diffs = res[r["pal"] if not r.get("native") else native_name(r["us"])]
                if ok is None and "--no-context" in extra:
                    retry.append(r)          # then as a block in its file's context
                else:
                    apply(r, ok, diffs)
        rjobs = []
        for r in retry:
            path = os.path.join(tmp, "%s_%s.c" % (r["program"], r["pal"]))
            open(path, "w").write(chunk_text(r["program"], r["rel"], r["pal"]))
            rjobs.append((r, path))
        again = []
        for (r, path), res in zip(rjobs, ex.map(lambda j: run_check(j[0]["program"], [j[0]["pal"]], j[1], a), rjobs)):
            if res[r["pal"]][0] is None and "<source file context>" in str(res[r["pal"]][1]):
                p2 = path[:-2] + "_block.c"
                open(p2, "w").write(chunk_text(r["program"], r["rel"], r["pal"], block_only=True))
                again.append((r, p2))
            else:
                apply(r, *res[r["pal"]])
        for (r, path), res in zip(again, ex.map(lambda j: run_check(j[0]["program"], [j[0]["pal"]], j[1], a), again)):
            apply(r, *res[r["pal"]])
    # last resort for core C the checker could not reproduce in isolation (a file of several
    # functions in one entry, an @ps2as file's slices): the full build's own object of the file
    last = [r for r in rows if r["program"] in CORE and r["state"] == "C" and r["status"] == "nomatch"]
    if last and not a.pairs_only:
        import targets
        def obj(r):
            t = targets.TARGETS[r["program"]]
            u = t.unit_for(int(r["pal"][5:], 16))
            return os.path.join(ROOT, t.workdir(u), os.path.splitext(os.path.basename(r["rel"]))[0] + ".o")
        todo = [r for r in last if os.path.exists(obj(r))]
        with ThreadPoolExecutor(a.jobs) as ex:
            for r, res in zip(todo, ex.map(lambda r: run_check(r["program"], [r["pal"]], os.path.join(ROOT, r["rel"]), a,
                                                               ["--object", obj(r), "--no-context"]), todo)):
                if res[r["pal"]][0] is not None:
                    print("%s %s: checked in the build's object: %s" % (r["program"], r["pal"],
                          "MATCH" if res[r["pal"]][0] else "%d diff" % res[r["pal"]][1]), flush=True)
                    apply(r, *res[r["pal"]])
    save(rows)
    c = collections.Counter((r["state"] if r["state"] != "near" else "near", r["status"]) for r in rows)
    for k in sorted(c):
        print("%-16s %-8s %d" % (k[0], k[1], c[k]))
    print("wrote", os.path.relpath(MAP, ROOT))


def exceptions():
    """{(program, PAL name): why} of config/us/exceptions.tsv"""
    out = {}
    p = version.cfg("exceptions.tsv", v="us")
    if os.path.exists(p):
        for line in open(p, encoding="utf-8"):
            if line.strip() and not line.startswith("#"):
                prog, name, why = line.rstrip("\n").split("\t", 2)
                out[(prog, name)] = why
    return out


def save(rows):
    lines = [HEAD.rstrip("\n")]
    for r in rows:
        lines.append("\t".join([r["pal"], r["program"], r["us"], r["place"], str(r["size"]), r["state"],
                                r["status"], "%.2f" % r["closeness"], r["hash"]]))
    open(MAP, "w", newline="\n").write("\n".join(lines) + "\n")


def check():
    """The map agrees with src/ (no disc needed). Returns the problems."""
    m = Map()
    if not m.rows:
        return ["config/us/map.tsv is missing (python3 tools/version_map.py --write)"]
    states = pal_states()
    hashes = file_hashes()
    problems = []
    seen = set()
    exc = exceptions()
    import c_objects
    built = c_objects.read_built()
    for r in m.rows:
        if r["state"] == "near" or r["pal"] == "-":
            continue
        key = (r["program"], r["pal"])
        seen.add(key)
        st = states.get(key)
        if st is None:
            problems.append("%s %s is in config/us/map.tsv but no longer a PAL function" % key)
            continue
        if st[0] != r["state"]:
            problems.append("%s %s is %s in src/ but %s in config/us/map.tsv: not carried to NTSC-U"
                            % (key + (st[0], r["state"])))
            continue
        if st[0] == "C" and hashes.get(st[1], "-") != r["hash"]:
            problems.append("%s %s: %s changed since config/us/map.tsv was written: not carried to NTSC-U"
                            % (key + (st[1],)))
        if key in exc:
            if r["status"] == "match":
                problems.append("%s %s matches on NTSC-U now: remove its line from config/us/exceptions.tsv" % key)
            continue
        if st[0] == "C" and r["status"] == "match" and built is not None and key not in built:
            # every match is carried into the NTSC-U build; where it stays assembly,
            # config/us/built.tsv says why (and the NTSC-U report does not count it)
            problems.append("%s %s checks MATCH on NTSC-U but is not in config/us/built.tsv: not carried into "
                            "the NTSC-U build (tools/carry_us.sh)" % key)
        if st[0] in FINAL and r["us"] != "-" and r["status"] not in ("match", "differs"):
            problems.append("%s %s is final on PAL and its NTSC-U twin %s has the same code, but it is %s there"
                            % (key + (r["us"], r["status"])))
    for key, st in states.items():
        if key not in seen and st[0] in FINAL:
            problems.append("%s %s (%s) is not in config/us/map.tsv: not carried to NTSC-U" % (key + (st[0],)))
    native = {(r["program"], native_name(r["us"])): r for r in m.rows if r["pal"] == "-"}
    for key, rel in us_sources().items():
        r = native.get(key)
        if r is None:
            problems.append("%s %s (src/us/) is not in config/us/map.tsv" % key)
        elif r["hash"] != hashes.get(rel, "-"):
            problems.append("%s %s: %s changed since config/us/map.tsv was written" % (key + (rel,)))
        elif r["status"] != "match":
            problems.append("%s %s (src/us/) does not check MATCH on NTSC-U (%s): near misses go in nonmatching/"
                            % (key + (r["status"],)))
    twins = {(r["program"], r["us"]) for r in m.rows if r["us"] != "-" and r["pal"] != "-"
             and r["status"] not in ("differs", "near")}
    for r in m.rows:
        if r["pal"] == "-" and (r["program"], r["us"]) in twins:
            problems.append("src/us/ has C for %s %s, whose code is a PAL function's: shared code is one "
                            "source, in src/" % (r["program"], r["us"]))
    return problems


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--pairs-only", action="store_true", help="with --write: no checks (unchecked C is nomatch)")
    ap.add_argument("--recheck", action="store_true", help="with --write: check every function again")
    ap.add_argument("-j", "--jobs", type=int, default=8)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"))
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--ee29", default=os.environ.get("UYA_EE29"), help="Sony ee-gcc 2.9-ee folder (@ee29 files)")
    a = ap.parse_args()
    if a.write:
        if not a.pairs_only and not a.toolchain:
            sys.exit("--write needs --toolchain (and --runner) for the checks")
        write(a)
    if a.check or not a.write:
        problems = check()
        for p in problems[:50]:
            print("error:", p)
        if len(problems) > 50:
            print("... and %d more" % (len(problems) - 50))
        print("config/us/map.tsv: %s" % ("in step with src/" if not problems else "%d problems" % len(problems)))
        sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
