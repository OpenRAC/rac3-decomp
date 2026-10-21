#!/usr/bin/env python3
"""port_from_us.py: make PAL's source tree from the US decompilation (one-time; kept as the record).

This repository started from rac3-uya-decomp (the NTSC-U decompilation of the same three
programs; CREDITS.md and THIRD_PARTY_NOTICES.md give its provenance). Most of PAL's code is the
US code at other addresses, so the US sources say where PAL's functions and source files are and
give the C for the functions whose bytes did not change. This tool writes, per program:

  src/<program>/...            one file per source file, at PAL addresses
  config/<program>/src_files.txt, text_parts.txt (one flag line per file), sq_ra_funcs.txt
  build/port/<program>.json    the address maps and every function's verdict (not committed)

What it does:

 1. Function map. Each US function (the entries of the US sources) is looked for in PAL's code
    with the immediates of lui/addiu/ori/loads/stores and the targets of j/jal masked: first
    the long functions with a single exact candidate, kept only where they keep their order
    (longest increasing run), then neighbours by contiguity, then a unique candidate between
    two mapped neighbours. core.text and i5bootn's .text are at the same addresses in both
    versions; the front end moved (frontbin from 0x37D100, boot_elf's from 0x381180, both to
    0x381080 in PAL) and changed in places.
 2. PAL code no US function maps to (changed or new functions) gets INCLUDE_ASM entries at the
    function starts splat finds there (tools/objdiff/gen_exe_targets.py's discovery), plus
    `--extra` starts (pieces setup_asm.py split off; see --uncovered).
 3. Data map. The US and PAL addresses each mapped function's relocations reach (lui/%lo
    pairs, $gp offsets, jal targets) pair up the US and PAL data and function addresses. A US
    symbol no relocation reaches is placed by the nearest paired address below it in the same
    section, if the pairs around it agree on the shift.
 4. Source files and flags (one flag set per file: docs/BUILD_FIDELITY.md). The US flags table
    sets flags by address range and marks "single-function override" ranges. Here:
      - a run of Sony library functions (@ee29 ranges: Sony compiled them separately) is a
        file of its own with its own flags;
      - the other functions take the flags of the US non-override range they sit in, and a
        US file is split where those change (at the next 8-aligned function: an object's code
        is 8-aligned);
      - a function whose US flags were a single-function override does not keep its C: it is
        INCLUDE_ASM here, and its US C goes to nonmatching/<program>/ as a draft.
 5. C. A US function keeps its C when it mapped, its US flags equal its file's flags here, and
    every symbol its block names has a PAL address. Its names are rewritten to PAL addresses.
    With --asm-only every function is INCLUDE_ASM (the first, all-assembly milestone).
    --hold FILE lists functions (PAL names) to keep as INCLUDE_ASM: the ones the build showed
    to differ (tools/port_verify.py writes it).

    python3 tools/port_from_us.py --us-tree DIR --us-baserom DIR [--asm-only] [--hold FILE]
"""
import argparse, bisect, glob, importlib.util, json, os, re, struct, sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import srcfiles as sf  # noqa: E402
import targets  # noqa: E402

NL = "\n"
WORK = os.path.join(ROOT, "build", "port")
MASK_IMM = {0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x18, 0x19, 0x1e, 0x1f, 0x20, 0x21, 0x23, 0x24, 0x25,
            0x27, 0x28, 0x29, 0x2b, 0x31, 0x35, 0x37, 0x39, 0x3d, 0x3f}
LOADSTORE = {0x9, 0xd, 0x19, 0x1e, 0x1f, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2b, 0x31, 0x35,
             0x37, 0x39, 0x3d, 0x3f}
SYM_RE = re.compile(r"\b(func|D|jtbl)_([0-9A-Fa-f]{5,8})((?:_[A-Za-z0-9]+)*)\b")
# Below .lit (0x1D5680) the PAL main program is the US one: the engine core's code, data and
# .bss sit at the same addresses (docs/targets.md). frontbin reaches into them too.
SAME_BELOW = 0x1D5680
OVERRIDE = "single-function override"


# ------------------------------------------------------------------ ELF helpers
def sections(path):
    data = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    hdrs = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]
    stroff = hdrs[shstrndx][4]
    out = []
    for h in hdrs:
        name = data[stroff + h[0]:data.index(b"\0", stroff + h[0])].decode()
        out.append({"name": name, "type": h[1], "addr": h[3], "off": h[4], "size": h[5]})
    return data, out


def section(path, name):
    data, secs = sections(path)
    s = next(s for s in secs if s["name"] == name)
    return s["addr"], data[s["off"]:s["off"] + s["size"]]


def words(b):
    return list(struct.unpack_from("<%dI" % (len(b) // 4), b))


def mask(w):
    op = w >> 26
    if op in (2, 3):
        return w & 0xFC000000
    if op in MASK_IMM:
        return w & 0xFFFF0000
    return w


def sext(x):
    return x - 0x10000 if x & 0x8000 else x


def refs(ws, gp):
    """[(kind, index, address)] for the relocated fields of a function's words."""
    hi, out = {}, []
    for k, w in enumerate(ws):
        op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 0xf:
            hi[rt] = imm << 16
            continue
        if op in LOADSTORE:
            if rs in hi:
                out.append(("abs", k, (hi[rs] + (imm if op == 0xd else sext(imm))) & 0xFFFFFFFF))
            elif rs == 28 and gp:
                out.append(("gp", k, (gp + sext(imm)) & 0xFFFFFFFF))
        if op in (2, 3):
            out.append(("j", k, (w & 0x3FFFFFF) << 2))
    return out


def lis(items):
    """Indices of the longest strictly increasing subsequence of items' second fields."""
    tails, tidx, prev = [], [], [None] * len(items)
    for k, (_, j) in enumerate(items):
        p = bisect.bisect_left(tails, j)
        if p == len(tails):
            tails.append(j); tidx.append(k)
        else:
            tails[p] = j; tidx[p] = k
        prev[k] = tidx[p - 1] if p else None
    out, k = [], tidx[-1] if tidx else None
    while k is not None:
        out.append(k); k = prev[k]
    return set(out)


# ------------------------------------------------------------------ US side
def load_us_targets(us_tree):
    spec = importlib.util.spec_from_file_location("us_targets", os.path.join(us_tree, "tools", "targets.py"))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod.TARGETS


def read_parts(path):
    """[(start, flags tuple, is_override)] sorted."""
    out = []
    for line in open(path):
        body, _, comment = line.partition("#")
        body = body.strip()
        if not body:
            continue
        f = body.split()
        out.append((int(f[0], 16), tuple(f[1:]), OVERRIDE in comment))
    return sorted(out)


def norm(flags):
    return frozenset(flags)


def us_entries(us_tree, ut):
    """US functions of one target: [(addr, rel, kind, chunk texts)], in address order, and the
    files' preludes {rel: prelude}."""
    files = sf.read_file_list(os.path.join(us_tree, ut.files))
    out, preludes = [], {}
    for rel, _ in files:
        text = sf.read_source(rel, us_tree)
        prelude, _, chunks = sf.split_file(text)
        preludes[rel] = prelude
        by = {}
        order = []
        for addr, _, body in chunks:
            if addr not in by:
                by[addr] = []; order.append(addr)
            by[addr].append(body)
        for addr in order:
            own = next((b for b in by[addr] if sf.is_own_chunk(b, "func_%08X" % addr)), "")
            m = re.match(r'\s*(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("([^"]*)"', own)
            kind = m.group(1) if m else "C"
            out.append((addr, rel, kind, by[addr]))
    out.sort()
    return out, preludes, files


# ------------------------------------------------------------------ mapping
def map_unit(uw, ua, pw, pa, starts, end):
    um, pm = [mask(w) for w in uw], [mask(w) for w in pw]
    ends = starts[1:] + [end]
    fn = [((s - ua) // 4, (e - ua) // 4) for s, e in zip(starts, ends)]
    K = 6
    idx = defaultdict(list)
    for i in range(len(pm) - K + 1):
        idx[tuple(pm[i:i + K])].append(i)

    def eq(i0, i1, j):
        return 0 <= j and j + (i1 - i0) <= len(pm) and pm[j:j + (i1 - i0)] == um[i0:i1]

    mapped, anchors = {}, []
    for n, (i0, i1) in enumerate(fn):
        if i1 - i0 < 12:
            continue
        c = [j for j in idx.get(tuple(um[i0:i0 + K]), []) if eq(i0, i1, j)]
        if len(c) == 1:
            anchors.append((n, c[0]))
    keep = lis(anchors)
    for k, (n, j) in enumerate(anchors):
        if k in keep:
            mapped[n] = j
    changed = True
    while changed:
        changed = False
        for n in range(len(fn)):
            if n in mapped:
                continue
            i0, i1 = fn[n]
            if n - 1 in mapped:
                j = mapped[n - 1] + fn[n - 1][1] - fn[n - 1][0]
                if eq(i0, i1, j) and (n + 1 not in mapped or j + i1 - i0 <= mapped[n + 1]):
                    mapped[n] = j; changed = True; continue
            if n + 1 in mapped:
                j = mapped[n + 1] - (i1 - i0)
                if eq(i0, i1, j) and (n - 1 not in mapped or j >= mapped[n - 1] + fn[n - 1][1] - fn[n - 1][0]):
                    mapped[n] = j; changed = True
    keys = sorted(mapped)
    for n in range(len(fn)):
        if n in mapped:
            continue
        i0, i1 = fn[n]
        p = bisect.bisect_left(keys, n)
        lo = mapped[keys[p - 1]] + fn[keys[p - 1]][1] - fn[keys[p - 1]][0] if p else 0
        hi = mapped[keys[p]] if p < len(keys) else len(pm)
        if hi - lo > 20000:
            continue
        c = [j for j in range(lo, hi - (i1 - i0) + 1) if eq(i0, i1, j)]
        if len(c) == 1:
            mapped[n] = c[0]
            bisect.insort(keys, n)
    out = {starts[n]: pa + 4 * j for n, j in mapped.items()}
    assert len(set(out.values())) == len(out), "two US functions mapped to one PAL address"
    return out, {starts[n]: 4 * (fn[n][1] - fn[n][0]) for n in range(len(fn))}


def data_pairs(us_elf, pal_elf, units, fmap, sizes, gp):
    pairs = defaultdict(Counter)
    for sec in units:
        ua, ud = section(us_elf, sec)
        pa, pd = section(pal_elf, sec)
        uw, pw = words(ud), words(pd)
        for us, pal in fmap.items():
            if not (ua <= us < ua + len(ud)):
                continue
            n = sizes[us] // 4
            a = uw[(us - ua) // 4:(us - ua) // 4 + n]
            b = pw[(pal - pa) // 4:(pal - pa) // 4 + n]
            ra, rb = refs(a, gp), refs(b, gp)
            if len(ra) != len(rb):
                continue
            for x, y in zip(ra, rb):
                if x[:2] == y[:2]:
                    pairs[x[2]][y[2]] += 1
    return {u: c.most_common(1)[0][0] for u, c in pairs.items()}


class AddrMap:
    """US address -> PAL address, for one target."""

    def __init__(self, fmap, dpairs, us_secs, pal_secs):
        self.exact = dict(dpairs)
        self.exact.update(fmap)   # function starts: the function map wins
        self.funcs = fmap
        self.keys = sorted(self.exact)
        self.us_secs = [s for s in us_secs if s["addr"] and s["size"]]
        self.pal_names = {s["name"] for s in pal_secs}
        self.core_same = not any(s["addr"] >= 0x800000 for s in self.us_secs)   # not i5bootn

    def sec(self, a):
        return next((s["name"] for s in self.us_secs if s["addr"] <= a < s["addr"] + s["size"]), None)

    def get(self, a, kind):
        if kind == "func":
            if a in self.funcs:
                return self.funcs[a]
            return a if 0x100000 <= a < SAME_BELOW and self.core_same else None
        if a in self.exact:
            return self.exact[a]
        if 0x100000 <= a < SAME_BELOW and self.core_same:
            return a
        s = self.sec(a)
        if s is None or s.endswith("text"):
            return None
        p = bisect.bisect_left(self.keys, a)
        below = [k for k in self.keys[max(0, p - 3):p] if self.sec(k) == s]
        above = [k for k in self.keys[p:p + 3] if self.sec(k) == s]
        if not below or not above:
            return None
        d = {self.exact[k] - k for k in below[-1:] + above[:1]}
        return a + d.pop() if len(d) == 1 else None


# ------------------------------------------------------------------ rewriting
def rename(text, amap):
    """text with every func_/D_/jtbl_ name moved to its PAL address; (text, unmapped names).

    Names are an address in 8 hex digits (or fewer, as some US names are), optionally followed
    by suffixes: a letter or two for another C type at the same address (D_00143950_b,
    D_001DA050_g) and a function's address for a per-function alias (D_001DA0D0_003BDBA0),
    which moves with the function."""
    bad = set()

    def sub(m):
        kind, hx, suffix = m.group(1), m.group(2), m.group(3)
        a = int(hx, 16)
        p = amap.get(a, "func" if kind == "func" else "data")
        if p is None:
            bad.add(m.group(0))
            return m.group(0)
        parts = []
        for part in suffix.split("_")[1:]:
            if re.fullmatch(r"[0-9A-F]{8}", part):
                q = amap.get(int(part, 16), "func")
                part = "%08X" % q if q is not None else part
            parts.append(part)
        width = 8 if len(hx) == 8 else len("%X" % p)
        return "%s_%0*X%s" % (kind, width, p, "".join("_" + x for x in parts))

    return SYM_RE.sub(sub, text), bad


class Decls:
    """The top-level declarations of a piece of C (typedefs, externs, prototypes, structs),
    renamed, without the ones that name a symbol with no PAL address. Written out last, without
    the prototypes of functions the file defines in C (their definition is the prototype; the US
    build compiled such pieces in separate slices, where a differing prototype did not clash)."""

    def __init__(self, text, amap):
        self.stmts = []
        for stmt in sf.declaration_statements(text):
            new, bad = rename(stmt, amap)
            if not bad:
                self.stmts.append(new)

    def render(self, defined, have):
        """`have`: the normalized statements the file already has (its prelude, its C and the
        declarations rendered before this); a type is defined once per file."""
        keep = []
        for st in self.stmts:
            key = re.sub(r"\s+", " ", st).strip()
            is_type = st.startswith(("typedef", "struct", "union", "enum"))
            if key in have and (is_type or st.startswith("#")):
                continue
            if not is_type and not st.startswith("#") and sf.declared_names(st) & defined:
                continue
            have.add(key)
            keep.append(st)
        return "\n".join(keep)


def clean_prelude(prelude, amap):
    out = []
    for line in prelude.split("\n"):
        new, bad = rename(line, amap)
        if bad:
            continue
        out.append(new)
    return "\n".join(out)


# ------------------------------------------------------------------ after split_text.py --refresh
def dedupe_types():
    """A US file was compiled in slices, so a type its later block defined could also be used
    (and defined) earlier; as one translation unit it may be defined once. After
    tools/split_text.py --refresh has put such a type in a file's declarations from other files,
    the same definition further down is removed (a declaration, never code)."""
    n = 0
    for t in targets.TARGETS.values():
        for rel, _ in sf.read_file_list(t.path("files")):
            path = os.path.join(ROOT, rel)
            text = open(path).read()
            if sf.EXT_END not in text:
                continue
            head, tail = text.split(sf.EXT_END, 1)
            have = {re.sub(r"\s+", " ", st).strip() for st in sf.declaration_statements(head)
                    if st.startswith(("typedef", "struct", "union", "enum"))}
            if not have:
                continue
            new_tail = tail
            for st in sorted(have, key=len, reverse=True):
                pat = r"(?m)^" + r"\s+".join(re.escape(w) for w in st.split()) + r"[ \t]*\n"
                new_tail = re.sub(pat, "", new_tail)
            if new_tail != tail:
                open(path, "w", newline="\n").write(head + sf.EXT_END + new_tail)
                n += 1
    print("dedupe_types: %d files" % n)


# ------------------------------------------------------------------ main
def main():
    if sys.argv[1:] == ["--dedupe-types"]:
        dedupe_types()
        return
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--us-tree", required=True, help="a checkout of rac3-uya-decomp (cleanup/restructure, 13cf5c5)")
    ap.add_argument("--us-baserom", required=True, help="folder with the US frontbin.elf, boot_elf.elf, i5bootn.elf")
    ap.add_argument("--target", default="all")
    ap.add_argument("--asm-only", action="store_true")
    ap.add_argument("--hold", help="file of PAL function names to keep as INCLUDE_ASM")
    ap.add_argument("--extra", help="JSON {target: [addresses]} of extra PAL function starts")
    a = ap.parse_args()
    us_targets = load_us_targets(a.us_tree)
    hold = set()
    if a.hold and os.path.exists(a.hold):
        hold = {tuple(l.split()[:2]) for l in open(a.hold) if l.strip() and not l.startswith("#")}
    extra = json.load(open(a.extra)) if a.extra and os.path.exists(a.extra) else {}
    os.makedirs(WORK, exist_ok=True)
    names = list(targets.TARGETS) if a.target == "all" else [a.target]
    for name in names:
        port_target(name, targets.TARGETS[name], us_targets[name], a, hold,
                    [int(x) for x in extra.get(name, [])])


def discovered(T):
    cache = os.path.join(WORK, "found_%s.json" % T.name)
    if not os.path.exists(cache):
        sys.path.insert(0, os.path.join(ROOT, "tools", "objdiff"))
        from gen_exe_targets import find_functions
        json.dump(find_functions(T.path("elf"), os.path.join(WORK, "splat_" + T.name)), open(cache, "w"))
    found = json.load(open(cache))
    return sorted(a for u in T.units for a, _ in found.get(u.section, []))


def port_target(name, T, UT, a, hold, extra):
    us_elf = os.path.join(a.us_baserom, os.path.basename(UT.elf))
    pal_elf = T.path("elf")
    entries, preludes, us_files = us_entries(a.us_tree, UT)
    us_parts = read_parts(os.path.join(a.us_tree, UT.parts))

    # 1. function map, per code section
    fmap, sizes = {}, {}
    for uu in UT.units:
        pu = T.unit(uu.name)
        ua, ud = section(us_elf, uu.section)
        pa, pd = section(pal_elf, pu.section)
        starts = [e[0] for e in entries if uu.contains(e[0])]
        m, s = map_unit(words(ud), ua, words(pd), pa, starts, uu.end)
        fmap.update(m); sizes.update(s)
    _, us_secs = sections(us_elf)
    _, pal_secs = sections(pal_elf)
    dp = data_pairs(us_elf, pal_elf, [u.section for u in UT.units], fmap, sizes, UT.gp)
    amap = AddrMap(fmap, dp, us_secs, pal_secs)

    # 2. PAL entries: mapped US functions, plus discovered starts where nothing mapped
    disc = discovered(T)
    pal_entries = {}   # PAL addr -> US entry index or None
    for i, e in enumerate(entries):
        if e[0] in fmap:
            pal_entries[fmap[e[0]]] = i
    covered = []
    for us, pal in fmap.items():
        covered.append((pal, pal + sizes[us]))
    covered.sort()
    for u in T.units:
        cov = [c for c in covered if u.contains(c[0])]
        pos = u.start
        gaps = []
        for lo, hi in cov:
            if lo > pos:
                gaps.append((pos, lo))
            pos = max(pos, hi)
        if pos < u.end:
            gaps.append((pos, u.end))
        for lo, hi in gaps:
            for x in [lo] + [d for d in disc + extra if lo < d < hi]:
                pal_entries.setdefault(x, None)
    for x in extra:
        pal_entries.setdefault(x, None)
    # the US trailer bytes after the last function belong to the last function; drop gap
    # "functions" that are only the file's tail (past the code section)
    pal_code_end = {u.name: next(s["addr"] + s["size"] for s in pal_secs if s["name"] == u.section) for u in T.units}
    for x in list(pal_entries):
        u = T.unit_for(x)
        if pal_entries[x] is None and x >= pal_code_end[u.name]:
            del pal_entries[x]

    # 3. flags of each US function
    def us_flags(addr):
        p = [x for x in us_parts if x[0] <= addr]
        return p[-1] if p else (0, tuple(UT.base_flags.split()), False)

    # 4. files: walk PAL entries in order; a new file starts where the US file changes, where
    #    an @ee29 run starts or ends (or its flags change), or where the non-override flags change
    us_file_of = {}
    for i, e in enumerate(entries):
        us_file_of[i] = e[1]
    order = sorted(pal_entries)
    groups = []   # [(us_rel, flags tuple, [pal addrs])]
    cur_rel = None
    region = {}   # base flags per non-ee29 function: the US non-override range it sits in
    prev_x = order[0]
    for x in order:
        i = pal_entries[x]
        if i is not None:
            rel = us_file_of[i]
            start, flags, ovr = us_flags(entries[i][0])
            ee = "@ee29" in flags
            if ee:
                base = flags
            elif ovr:
                # the surrounding non-override range: the last one before it in its US file
                file_start = dict(sf.read_file_list(os.path.join(a.us_tree, UT.files)))[rel]
                prev = [p for p in us_parts if p[0] <= entries[i][0] and not p[2] and "@ee29" not in p[1]]
                base = prev[-1][1] if prev else tuple(UT.base_flags.split())
                if prev and prev[-1][0] < file_start:
                    # nothing in its own file before it: take the file's first non-override range
                    nxt = [p for p in us_parts if file_start <= p[0] and not p[2] and "@ee29" not in p[1]]
                    base = prev[-1][1] if not nxt else nxt[0][1]
            else:
                base = flags
        else:
            rel, base, ee = cur_rel, None, False
            if rel is None or T.unit_for(x) is not T.unit_for(prev_x):
                # unmapped code at the start of a section: the file of the next mapped function
                nxt = next(pal_entries[y] for y in order if y > x and pal_entries[y] is not None)
                rel = us_file_of[nxt]
        if base is None:
            base = groups[-1][1] if groups else tuple(T.base_flags.split())
            if groups and "@ee29" in groups[-1][1]:
                # unmapped code after a library run: back to the file's own flags
                base = next((g[1] for g in reversed(groups) if g[0] == rel and "@ee29" not in g[1]),
                            tuple(T.base_flags.split()))
        new = (not groups or rel != groups[-1][0] or norm(base) != norm(groups[-1][1])
               or T.unit_for(x) is not T.unit_for(groups[-1][2][0]))
        if new and groups and rel == groups[-1][0] and x % 8 and "@ee29" not in base and "@ee29" not in groups[-1][1]:
            new = False   # an object's code starts 8-aligned: not a file boundary
        if new:
            groups.append((rel, base, [x]))
        else:
            groups[-1][2].append(x)
        cur_rel, prev_x = rel, x
    # a one-function non-library group between two groups of the same file and flags is an
    # override in disguise: merge it into its neighbours
    merged = []
    for g in groups:
        if (len(merged) >= 2 and len(merged[-1][2]) == 1 and "@ee29" not in merged[-1][1]
                and merged[-2][0] == merged[-1][0] == g[0] and norm(merged[-2][1]) == norm(g[1])
                and "@ee29" not in g[1]):
            lone = merged.pop()
            merged[-1][2].extend(lone[2] + g[2])
            continue
        merged.append((g[0], g[1], list(g[2])))
    groups = merged
    # an object's code starts 8-aligned: a file that would start at a 4-mod-8 function takes
    # the unmapped (gap) functions before it back to an 8-aligned one, or else joins the file
    # before it
    fixed = []
    for g in groups:
        if fixed and g[2][0] % 8 and T.unit_for(g[2][0]) is T.unit_for(fixed[-1][2][0]):
            prev = fixed[-1][2]
            k = len(prev)
            while k > 1 and pal_entries[prev[k - 1]] is None:
                k -= 1
            ks = [j for j in range(k, len(prev)) if prev[j] % 8 == 0]
            if ks:
                moved = prev[max(ks):]
                del prev[max(ks):]
                fixed.append((g[0], g[1], moved + g[2]))
                continue
            fixed[-1][2].extend(g[2])
            continue
        fixed.append(g)
    groups = fixed

    # 5. write the tree. Read-only data that setup_asm.py cut out of the data segments (jump
    #    tables, and the rodata_cut blocks) belongs to the first function whose .s names it; an
    #    assembly function pulls it in with INCLUDE_RODATA, a C function emits its own.
    rodata_of = defaultdict(list)
    for u in T.units:
        rdir = os.path.join(ROOT, u.asm_dir, "rodata")
        blocks = {os.path.basename(p)[:-2] for p in glob.glob(os.path.join(rdir, "*.s"))}
        taken = set()
        for x in sorted(pal_entries):
            if not u.contains(x):
                continue
            for d in (u.asm_dir, T.handwritten, T.remnants):
                p = os.path.join(ROOT, d, "func_%08X.s" % x)
                if os.path.exists(p):
                    names = sorted(set(re.findall(r"\b((?:jtbl|D)_[0-9A-F]{8})\b", open(p, errors="ignore").read())) & blocks - taken)
                    rodata_of[x] = names
                    taken |= set(names)
                    break

    def rodata_lines(x):
        u = T.unit_for(x)
        return "".join('INCLUDE_RODATA("%s/rodata", %s);\n' % (u.asm_dir, n) for n in rodata_of.get(x, []))

    verdict = {}
    held_drafts = []
    src_dirs = {u.src_dir for u in T.units}
    # TEXT_PADDING lines tools/setup_asm.py (trailing_padding.py --apply) added to the current
    # sources: the .s it cut no longer has those nops, so they stay with their function
    old_pad = {}
    for d in src_dirs:
        for p in glob.glob(os.path.join(ROOT, d, "**", "*.c"), recursive=True):
            for m in re.finditer(r"(func_[0-9A-F]{8})\);[^\n]*\n(?:INCLUDE_RODATA[^\n]*\n)*(TEXT_PADDING\(\w+\);[^\n]*\n)",
                                 open(p).read()):
                old_pad[m.group(1)] = m.group(2)
    for d in src_dirs:
        for p in glob.glob(os.path.join(ROOT, d, "**", "*.c"), recursive=True):
            os.remove(p)
    file_rows, part_rows = [], []
    c_until = 0
    seen_chunks = defaultdict(list)
    last_mapped = [-1]
    used_paths = set()
    for rel, flags, addrs in groups:
        start = addrs[0]
        u = T.unit_for(start)
        us_dir = os.path.dirname(rel)
        us_base = os.path.basename(rel)
        sub = os.path.relpath(us_dir, UT.unit(u.name).src_dir) if us_dir.startswith(UT.unit(u.name).src_dir) else ""
        sub = "" if sub == "." else sub
        if re.match(r"^[0-9A-F]{6}\.c$", us_base) or "@ee29" in flags and not sub:
            fname = "%06X.c" % start
        else:
            fname = us_base if (os.path.join(sub, us_base)) not in used_paths else "%06X.c" % start
        prel = os.path.join(u.src_dir, sub, fname).replace(os.sep, "/")
        if prel in used_paths:
            prel = os.path.join(u.src_dir, sub, "%06X.c" % start).replace(os.sep, "/")
        used_paths.add(prel)
        used_paths.add(os.path.join(sub, fname))
        body = []
        prelude = preludes.get(rel, '#include "common.h"\n')
        if a.asm_only:
            prelude = '#include "common.h"\n'
        else:
            prelude = clean_prelude(prelude, amap)
        body.append(prelude.rstrip("\n") + "\n\n")
        if not a.asm_only and seen_chunks.get(rel):
            # the part of a US file that became a file of its own sees the declarations of the
            # US file's earlier blocks, as it did in the US build
            d = Decls("".join(seen_chunks[rel]), amap)
            if d.stmts:
                body.append("/* declarations of %s's earlier functions (tools/port_from_us.py) */\n" % os.path.basename(rel))
                body.append(d)
                body.append("\n\n")
        for x in addrs:
            i = pal_entries[x]
            pname = "func_%08X" % x
            us_name = "func_%08X" % entries[i][0] if i is not None else None
            if i is None and x < c_until:
                continue   # a piece splat cut off a function that is C here: the C covers it
            if i is None:
                verdict[pname] = {"us": None, "status": "new"}
                body.append('INCLUDE_ASM("%s", %s);\n' % (u.asm_dir, pname) + rodata_lines(x) + old_pad.get(pname, "") + "\n")
                continue
            us_addr, _, kind, chunks = entries[i]
            fl = us_flags(us_addr)
            lost = [e for e in entries[last_mapped[0] + 1:i] if e[0] not in fmap] if not a.asm_only else []
            last_mapped[0] = i
            if lost:
                # US functions PAL changed: their code is gone, their declarations are not
                body.append(Decls("".join(c for e in lost for c in e[3]), amap))
                body.append("\n")
            if kind in ("ASM_FUNC", "LINKER_REMNANT"):
                text, bad = rename("".join(chunks), amap)
                text = text.replace(UT.handwritten, T.handwritten).replace(UT.remnants, T.remnants)
                if bad:
                    text = '%s("%s", %s);\n' % (kind, T.handwritten if kind == "ASM_FUNC" else T.remnants, pname)
                body.append(text.rstrip("\n") + "\n\n")
                verdict[pname] = {"us": us_name, "status": kind}
                continue
            reason = None
            if kind != "C":
                reason = "asm in US"
            elif a.asm_only:
                reason = "asm-only"
            elif norm(fl[1]) != norm(flags):
                plus = " ".join("`%s`" % f for f in fl[1] if f not in flags)
                minus = " ".join("`%s`" % f for f in flags if f not in fl[1])
                reason = "flags: the US matched it with %s%s%s (a %s)" % (
                    plus, " and without " if plus and minus else ("without " if minus else ""), minus,
                    "single-function override" if fl[2] else "flag range the PAL file does not have")
            elif (pname, name) in hold or (pname, "?") in hold:
                reason = "differs: did not build, or built to other bytes, in PAL"
            text = None
            if reason is None:
                text, bad = rename("".join(chunks), amap)
                if bad:
                    reason = "unmapped symbols: " + " ".join(sorted(bad))
            if reason is None:
                body.append(text.rstrip("\n") + "\n\n")
                verdict[pname] = {"us": us_name, "status": "C"}
                c_until = x + sizes[us_addr]
                continue
            # keep the TEXT_PADDING line that belongs to the function, then INCLUDE_ASM
            pad = "".join(re.findall(r"^TEXT_PADDING\(\w+\);[^\n]*\n", "".join(chunks), re.M)) or old_pad.get(pname, "")
            if kind == "C" and not a.asm_only:
                body.append(Decls("".join(chunks), amap))
                body.append("\n")
            body.append('INCLUDE_ASM("%s", %s);\n' % (u.asm_dir, pname) + rodata_lines(x) + pad + "\n")
            verdict[pname] = {"us": us_name, "status": "asm", "reason": reason}
            if kind == "C" and reason not in ("asm-only",):
                held_drafts.append((pname, us_name, reason, "".join(chunks)))
        for x in addrs:
            if pal_entries[x] is not None:
                seen_chunks[rel].extend(entries[pal_entries[x]][3])
        defined = {"func_%08X" % x for x in addrs if verdict.get("func_%08X" % x, {}).get("status") == "C"}
        have = {re.sub(r"\s+", " ", st).strip()
                for b in body if isinstance(b, str) for st in sf.declaration_statements(b)}
        text = "".join(b.render(defined, have) if isinstance(b, Decls) else b for b in body)
        text = re.sub(r"\n{3,}", "\n\n", text)
        os.makedirs(os.path.dirname(os.path.join(ROOT, prel)), exist_ok=True)
        open(os.path.join(ROOT, prel), "w", newline="\n").write(text.rstrip("\n") + "\n")
        file_rows.append("%s %08X" % (prel, start))
        part_rows.append("0x%08X     %s" % (start, " ".join(flags)))

    hdr = ["# %s source files in link order: path and the address of its first function." % T.name,
           "# Made from the US decompilation's files by tools/port_from_us.py; the boundaries are",
           "# estimates (a file may be split or joined), except that a file has one flag set."]
    open(T.path("files"), "w", newline="\n").write(NL.join(hdr + file_rows) + NL)
    phdr = ["# Compiler flags, one line per source file (config/%s/src_files.txt): the line's" % T.name,
            "# address is the file's first function. No per-function flags (docs/BUILD_FIDELITY.md).",
            "# @ee29: Sony library code, built with Sony's ee-gcc 2.9-ee-991111 (tools/ee29.py);",
            "# @ps2as: assembled with SN's Ps2EeAs; @newas: with ee/bin/as.exe."]
    open(T.path("parts"), "w", newline="\n").write(NL.join(phdr + part_rows) + NL)

    # side tables keyed by function name
    def remap_list(path, keep_cols=False):
        p = os.path.join(a.us_tree, path)
        if not os.path.exists(p):
            return []
        out = []
        for line in open(p):
            s = line.rstrip("\n")
            if not s.strip() or s.lstrip().startswith(("#", "//")):
                out.append(s); continue
            new, bad = rename(s, amap)
            if not bad:
                n = new.split()[0]
                if verdict.get(n, {}).get("status") == "C":
                    out.append(new)
        return out
    open(T.path("sq_ra_funcs"), "w", newline="\n").write(NL.join(remap_list(UT.sq_ra_funcs)) + NL)
    open(T.path("localdecomp_flags"), "w", newline="\n").write(
        "# localdecomp-only flag overrides (func_XXXXXXXX <flags...>). None: one flag set per file.\n")
    sym = [l.rstrip("\n") for l in open(os.path.join(a.us_tree, UT.symbol_addrs))]
    out = []
    for s in sym:
        new, bad = rename(s, amap)
        if bad:
            continue
        new = re.sub(r"= 0x([0-9A-F]{8})", lambda m: "= 0x%s" % (re.search(r"_([0-9A-F]{8})", new).group(1)), new)
        out.append(new)
    open(T.path("symbol_addrs"), "w", newline="\n").write(NL.join(out) + NL)

    # nonmatching drafts for the C that was held back
    nd = os.path.join(ROOT, "nonmatching", name)
    for p in glob.glob(os.path.join(nd, "*.c")):
        if open(p).read().startswith("/* US draft"):
            os.remove(p)
    if not a.asm_only:
        os.makedirs(nd, exist_ok=True)
        for pname, us_name, reason, text in held_drafts:
            new, bad = rename(text, amap)
            open(os.path.join(nd, pname + ".c"), "w", newline="\n").write(
                "/* US draft of %s (rac3-uya-decomp %s, commit 13cf5c5), names moved to PAL addresses\n"
                "   where known. Not carried: %s. */\n\n%s" % (pname, us_name, reason, new.rstrip("\n") + "\n"))
    # named symbols the US kept by hand in its resolved file (libgcc's entry points), moved
    named = []
    for line in open(os.path.join(a.us_tree, UT.symbols_resolved)):
        m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+);", line)
        if not m or re.match(r"(func|D|jtbl)_[0-9A-Fa-f]", m.group(1)):
            continue
        us = int(m.group(2), 16)
        p = amap.get(us, "func") or amap.get(us, "data")
        if p is not None:
            named.append("%s = 0x%08X;" % (m.group(1), p))
    path = T.path("symbols_resolved")
    import resolve_symbols as rs
    old = open(path).read() if os.path.exists(path) else ""
    head = old.split(rs.NAMED, 1)[0].rstrip("\n") if old else ""
    open(path, "w", newline="\n").write((head + "\n\n" if head else "") + rs.NAMED + "\n" + NL.join(named) + NL)
    # their rows in nonmatching/README.md (rows of other near misses are kept)
    readme = os.path.join(ROOT, "nonmatching", "README.md")
    text = open(readme).read()
    head, sep, rows = text.partition("| --- | --- | --- | --- |\n")
    keep = [r for r in rows.splitlines() if r.strip() and not (r.split("|")[2].strip() == name and "US draft" in r)]
    short = {"flags": "flags", "differs": "differs", "unmapped symbols": "symbols"}
    new_rows = ["| `%s` | %s | US draft of `%s` | %s |" % (
        pname, name, us_name, short.get(reason.split(":")[0], reason.split(":")[0]) + ": "
        + reason.split(":", 1)[1].strip().replace("|", "/") if ":" in reason else reason)
        for pname, us_name, reason, _ in held_drafts] if not a.asm_only else []
    allrows = keep + new_rows
    allrows.sort(key=lambda r: (r.split("|")[2].strip(), r.split("|")[1].strip()))
    open(readme, "w", newline="\n").write(head + sep + "".join(r + "\n" for r in allrows))
    json.dump({"fmap": {"%08X" % k: "%08X" % v for k, v in sorted(fmap.items())},
               "data": {"%08X" % k: "%08X" % v for k, v in sorted(dp.items())},
               "verdict": verdict}, open(os.path.join(WORK, name + ".json"), "w"), indent=0)
    c = Counter(v["status"] for v in verdict.values())
    r = Counter(v.get("reason", "").split(":")[0] for v in verdict.values() if v["status"] == "asm")
    print("%s: %d US functions, %d mapped; %d PAL entries in %d files; %s; held back: %s"
          % (name, len(entries), len(fmap), len(pal_entries), len(groups), dict(c), dict(r)))


if __name__ == "__main__":
    main()
