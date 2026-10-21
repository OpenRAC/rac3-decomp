#!/usr/bin/env python3
"""level_catalogue.py: every distinct function of the levels once, and the front end's pairs.

    python3 tools/levels.py catalogue

Writes, from baserom/ (the core programs and tools/levels.py dump's ELFs):

  config/levels/functions.tsv   name, kind, size, fingerprint, remnant, levels, places
  config/frontend_pairs.tsv     boot_elf .text function -> the frontbin function with its code

rac1-decomp's and rac2-decomp's catalogue (tools/overlays.py catalogue there):

1. Each level's .text is cut into functions by tools/inventory.py (call targets, returns,
   tail calls, padding, joined pieces, linker remnants), plus the starts and ends of frontbin's
   functions wherever their code (address fields masked) is found in the level, as rac1-decomp
   adds the executable's functions it finds in each level.
2. Two places are one function when their instructions are equal apart from what linking
   changes (inventory.identity(): jump targets and address halves are masked, except those
   into the resident engine core; constants, stack slots and field offsets are compared) and
   their sizes are equal. Two places in one level are always two functions: the k-th copy of
   identical code in each level, by address, is one function.
3. A function frontbin has too (one copy in frontbin, one in each level that has it) keeps
   frontbin's name and kind `frontbin`: it is counted once, with frontbin. One that only
   boot_elf's front end has is `boot_elf`. Any other is `shared` (in two or more levels) or
   `level` (in one), named func_LNN_XXXXXXXX: its address in the lowest-numbered level that has
   it, its canonical level.

The front end's pairs: boot_elf's .text is frontbin's front end linked a second time. Each
boot_elf .text function (config/inventory.tsv) whose identity and size are one frontbin
function's is paired with it: the two sequences are aligned in address order (align(): equal
code, the longest common runs first), so identical code that occurs several times is paired copy
by copy in order, even where one program has more copies than the other; code left over on both
sides is paired copy by copy wherever it moved. The report counts a pair once (tools/progress.py).

The catalogue and the pairs hold names, addresses, sizes and fingerprints, never bytes.
"""
import bisect
import collections
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import inventory as inv  # noqa: E402
import levels  # noqa: E402

import version  # noqa: E402
PAIRS = version.cfg("frontend_pairs.tsv")


def mask(w):
    """rac1-decomp's mask(): every link-dependent field and every immediate, to find a function's
    copies in another program's code."""
    op, rs = w >> 26, (w >> 21) & 31
    if op in (2, 3):
        return w & 0xFC000000
    if op == 0x0F or rs == 28 and op >= 8:
        return w & 0xFFFF0000
    if (op in inv.MEM or op in (0x09, 0x0D, 0x19)) and rs != 29:
        return w & 0xFFFF0000
    return w


def core_functions(program, section):
    """[(address, bytes, kind)] of a core program's code section, as config/inventory.tsv cuts it
    (kind: function or remnant)."""
    s = inv.program_sections(program, levels.core_elf_path(program), [section])[0]
    data = struct.pack("<%dI" % len(s.w), *s.w)
    return [(a, data[a - s.base:a - s.base + n], k) for sec, a, n, k in inv.read_inventory()[program]
            if sec == section]


def key(body, address):
    return inv.fingerprint(body, address), len(body)


def pair_in_order(a_items, b_items):
    """Pairs (a, b) of equal keys: unique keys first (the anchors), then repeated keys copy by
    copy, each kept only if it falls between the anchors around it in both programs."""
    ka, kb = collections.defaultdict(list), collections.defaultdict(list)
    for addr, k in a_items:
        ka[k].append(addr)
    for addr, k in b_items:
        kb[k].append(addr)
    anchors = sorted((v[0], kb[k][0]) for k, v in ka.items() if len(v) == 1 and len(kb.get(k, ())) == 1)
    # the anchors must be in the same order in both programs
    good = set(lis(anchors))
    pairs = dict(good)
    sa = sorted(good)
    for k, v in ka.items():
        w = kb.get(k, [])
        if len(v) == 1 and len(w) == 1 or not w or len(v) != len(w):
            continue
        for a, b in zip(sorted(v), sorted(w)):
            i = bisect.bisect_left(sa, (a, -1))
            lo = sa[i - 1][1] if i else -1
            hi = sa[i][1] if i < len(sa) else 1 << 32
            if lo < b < hi:
                pairs[a] = b
    return pairs


def align(a_items, b_items):
    """{a address: b address} of two code sections' functions [(address, key)]: the two sequences
    of code aligned in address order (equal code, the longest common runs first), then code left
    on both sides, copy by copy, wherever it moved. Unlike pair_in_order() it pairs repeated code
    whose number of copies differs between the two (NTSC-U's front ends have more such code)."""
    import difflib
    pa, ua = sorted(a_items), sorted(b_items)
    sm = difflib.SequenceMatcher(None, [k for _, k in pa], [k for _, k in ua], autojunk=False)
    out = {}
    for i, j, size in sm.get_matching_blocks():
        for t in range(size):
            out[pa[i + t][0]] = ua[j + t][0]
    taken = set(out.values())
    pk, uk = collections.defaultdict(list), collections.defaultdict(list)
    for a, k in pa:
        pk[k].append(a)
    for a, k in ua:
        uk[k].append(a)
    for k, v in pk.items():
        left = [a for a in v if a not in out]
        free = [a for a in uk.get(k, ()) if a not in taken]
        for a, b in zip(left, free):
            out[a] = b
            taken.add(b)
    return out


def lis(pairs):
    """The longest subsequence of PAIRS (sorted by a) increasing in b."""
    import bisect as bs
    tails, idx, prev = [], [], [None] * len(pairs)
    for i, (_, b) in enumerate(pairs):
        j = bs.bisect_left(tails, b)
        if j == len(tails):
            tails.append(b)
            idx.append(i)
        else:
            tails[j] = b
            idx[j] = i
        prev[i] = idx[j - 1] if j else None
    out, i = [], idx[-1] if idx else None
    while i is not None:
        out.append(pairs[i])
        i = prev[i]
    return out[::-1]


def frontend_pairs(fb, be):
    pairs = align([(a, key(b, a)) for a, b, _ in fb], [(a, key(b, a)) for a, b, _ in be])
    lines = ["# boot_elf .text function\tthe frontbin function with its code (tools/level_catalogue.py)"]
    for a, b in sorted(pairs.items(), key=lambda p: p[1]):
        lines.append("func_%08X\tfunc_%08X" % (b, a))
    open(PAIRS, "w", newline="\n").write("\n".join(lines) + "\n")
    return pairs


def level_places(number, fb_masked):
    """[(address, bytes, remnant)] of one level's functions."""
    sec = inv.program_sections(levels.dirname(number), levels.elf_path(number), [".text"])[0]
    base, w = sec.base, sec.w
    # frontbin's functions found in the level: their starts and ends become boundaries
    m = struct.pack("<%dI" % len(w), *map(mask, w))
    extra = set()
    for size, fm in fb_masked:
        i = m.find(fm)
        while i >= 0 and i % 4:
            i = m.find(fm, i + 1)
        if i >= 0:
            extra |= {base + i, base + i + size}
    entries = sec.entries(extra)
    data = struct.pack("<%dI" % len(w), *w)
    return [(a, data[a - base:a - base + n], k == "remnant") for a, n, k in entries]


def main(argv=()):
    fb = core_functions("frontbin", ".text")
    be = core_functions("boot_elf", ".text")
    pairs = frontend_pairs(fb, be)
    print("front end: %d of boot_elf's %d .text functions paired with frontbin's %d (%d bytes)"
          % (len(pairs), len(be), len(fb), sum(len(b) for a, b, _ in fb if a in pairs)))
    fb_key = collections.defaultdict(list)
    for a, b, k in fb:
        fb_key[key(b, a)].append(a)
    be_key = collections.defaultdict(list)
    paired_be = set(pairs.values())
    for a, b, k in be:
        if a not in paired_be:
            be_key[key(b, a)].append(a)
    fb_masked = [(len(b), struct.pack("<%dI" % (len(b) // 4), *map(mask, inv.words(b))))
                 for a, b, k in fb if len(b) >= 32 and k != "remnant"]
    found = {}
    for number in sorted(levels.NAMES):
        for a, body, remnant in level_places(number, fb_masked):
            e = found.setdefault(key(body, a), {"size": len(body), "remnant": remnant, "places": []})
            e["places"].append((number, a))
        print("level %02d: %d distinct so far" % (number, len(found)), flush=True)
    rows = []
    for k, e in found.items():
        per = collections.defaultdict(list)
        for number, a in sorted(e["places"]):
            per[number].append(a)
        copies = max(len(v) for v in per.values())
        for c in range(copies):
            places = [(n, v[c]) for n, v in sorted(per.items()) if len(v) > c]
            if copies == 1 and len(fb_key.get(k, ())) == 1:
                name, kind = "func_%08X" % fb_key[k][0], "frontbin"
            elif copies == 1 and len(be_key.get(k, ())) == 1:
                name, kind = "func_%08X" % be_key[k][0], "boot_elf"
            else:
                n0, a0 = places[0]
                name = "func_L%02d_%08X" % (n0, a0)
                kind = "level" if len({p[0] for p in places}) == 1 else "shared"
            rows.append((name, kind, e["size"], k[0], e["remnant"], places))
    rows.sort(key=lambda r: r[5][0])
    lines = ["# name\tkind\tsize\tfingerprint\tremnant\tlevels\tplaces (level:address) -- tools/level_catalogue.py"]
    for name, kind, size, fp, remnant, places in rows:
        lines.append("%s\t%s\t%d\t%s\t%d\t%d\t%s" % (name, kind, size, fp, int(remnant), len({p[0] for p in places}),
                                                     ",".join("%02d:%08X" % p for p in places)))
    open(levels.CATALOGUE, "w", newline="\n").write("\n".join(lines) + "\n")
    count = collections.Counter(r[1] for r in rows)
    size = collections.Counter()
    for r in rows:
        size[r[1]] += r[2]
    print("%d placements, %d distinct functions: %s" % (
        sum(len(r[5]) for r in rows), len(rows),
        ", ".join("%d %s (%d bytes)" % (count[k], k, size[k]) for k in ("frontbin", "boot_elf", "shared", "level"))))


def read_catalogue(path=None):
    """[(name, kind, size, fingerprint, remnant, [(level, address)])]"""
    out = []
    for line in open(path or levels.CATALOGUE):
        if line.startswith("#"):
            continue
        name, kind, size, fp, rem, _, places = line.rstrip("\n").split("\t")
        out.append((name, kind, int(size), fp, rem == "1",
                    [(int(p[:2]), int(p[3:], 16)) for p in places.split(",")]))
    return out


def read_pairs(path=PAIRS):
    """{boot_elf function name: frontbin function name}"""
    out = {}
    if os.path.exists(path):
        for line in open(path):
            if not line.startswith("#") and line.strip():
                b, f = line.split()
                out[b] = f
    return out


if __name__ == "__main__":
    main(sys.argv[1:])
