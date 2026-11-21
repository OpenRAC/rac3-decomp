#!/usr/bin/env python3
"""level_catalogue.py: every distinct function of the levels once, and the front end's pairs.

    python3 tools/levels.py catalogue

Writes, from baserom/ (the core programs and tools/levels.py dump's ELFs):

  config/levels/functions.tsv   name, kind, size, fingerprint, remnant, levels, places
                                (after the exceptions of config/levels/boundaries.tsv, apply_boundaries())
  config/frontend_pairs.tsv     boot_elf .text function -> the frontbin function with its code

rac1-decomp's and rac2-decomp's catalogue (tools/overlays.py catalogue there):

1. Each level's .text is cut into functions by tools/inventory.py (call targets, returns,
   tail calls, padding, joined pieces, linker remnants), plus the starts and ends of frontbin's
   functions wherever their code (address fields masked) is found in the level, as rac1-decomp
   adds the executable's functions it finds in each level.
2. Two places are one function when their instructions are equal apart from what linking
   changes (inventory.identity(): jump targets and address halves are masked, except those
   into the resident engine core; constants, stack slots and field offsets are compared) and
   their sizes are equal. Two places in one level are always two functions: the copies of
   identical code are matched across levels by their neighbours (copy_groups(): the code that is
   once in its level before and after each copy), else the k-th copy in each level by address.
   A false fold, places that identity() calls equal although their code differs (a field
   offset on a register that held an address earlier in the function, which identity() masks
   because its address tracking is not flow-sensitive), is split by config/levels/
   split_places.tsv (rac1-decomp's split_places.tsv): each line is one group of places that
   leaves its row and becomes a function of its own (named after its first place).
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
import memo  # noqa: E402

import version  # noqa: E402
PAIRS = version.cfg("frontend_pairs.tsv")
BOUNDARIES = version.cfg("levels", "boundaries.tsv")
EDITS = ("start", "split", "join", "size", "variant", "cut")
SPLITS = version.cfg("levels", "split_places.tsv")


def read_splits(path=SPLITS):
    """{(level, address): group} from split_places.tsv: per line, a row name (for the reader),
    then the places (NN:XXXXXXXX, comma-separated) that form one function of their own."""
    out = {}
    if os.path.exists(path):
        for i, line in enumerate(open(path)):
            f = line.split("#")[0].split()
            if len(f) < 2:
                continue
            for p in f[1].split(","):
                out[(int(p[:2]), int(p[3:], 16))] = i
    return out


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


def read_boundaries(path=None):
    """[(name, edit, argument, line)] of config/levels/boundaries.tsv, or under --version us of
    config/us/levels/boundaries.tsv (the same edits in NTSC-U names; see apply_boundaries())."""
    path = path or BOUNDARIES
    out = []
    if not os.path.exists(path):
        return out
    with open(path) as f:
        lines = f.readlines()
    for n, line in enumerate(lines, 1):
        if line.startswith("#") or not line.strip():
            continue
        f = line.rstrip("\n").split("\t")
        if len(f) < 4 or not f[0].startswith("func_") or f[1] not in EDITS or not f[3].strip():
            sys.exit("%s:%d: want name, edit (%s), argument, evidence" % (path, n, "|".join(EDITS)))
        out.append((f[0], f[1], f[2], n))
    return out


def apply_boundaries(per_level, data, rows, edits, fb_key, be_key):
    """The catalogue's exceptions (config/levels/boundaries.tsv): functions whose boundaries the
    rules above get wrong, each with retail's evidence. An edit names a row of the catalogue the
    rules give and applies at every one of its places:

      start  +N    the function starts N bytes later: the words before it are a linker remnant
                   (the last word and alignment nop of stripped functions) of their own
      split  +N    two functions: the second starts N bytes in
      join   K     one function with the K entries after it (its own delay slot, or code it
                   branches or jumps to that the rules cut off)
      size   N     the function is N bytes (the rest of the entry is the linker's fill)
      variant LL,..  the places in these levels are a function of their own (code the identity
                   cannot tell apart, but that differs: one C body cannot give both)
      cut  [K/]+A:N[r][o],..  the entry, with the K entries after it, is these pieces: each starts
                   A bytes in and is N bytes, `r` for a linker remnant; the words no piece takes are
                   padding, fill or data (where the rules cut several functions wrongly at once:
                   level 39's .text holds encrypted blocks whose words decode as branches). `o`: the
                   piece is a function of its own though its code equals another level's (a
                   library's wrapper that calls something else: the identity masks jump targets)

    The other rows keep their places, but for the entries a join takes in. A piece an edit makes
    is grouped with the other pieces as the rules group places; a group goes to the row the
    rules give its code (the first copy) when no row of that code has a place in its levels, as
    the rules would count it, and is a row of its own otherwise, so that no other row's copies
    move. PER_LEVEL: {level: [(address, bytes, remnant, tag)]}; DATA: {level: (base, .text
    bytes)}; ROWS: the rows the rules give. Returns the new rows and {name: places edited}."""
    by_name = {r[0]: r for r in rows}
    todo = {}
    for name, edit, arg, line in edits:
        if name not in by_name:
            sys.exit("%s:%d: %s is not a row of the catalogue the rules give" % (BOUNDARIES, line, name))
        for place in by_name[name][5]:
            if place in todo:
                sys.exit("%s:%d: %s has a second edit" % (BOUNDARIES, line, name))
            todo[place] = (name, edit, arg)
    done = collections.Counter()
    pieces, taken = collections.defaultdict(list), set()
    for number, entries in per_level.items():
        base, text = data[number]
        i = 0
        while i < len(entries):
            a, body, remnant, tag = entries[i]
            e = todo.get((number, a))
            i += 1
            if e is None:
                continue
            name, edit, arg = e
            done[name] += 1
            out = pieces[number]
            tag = name
            if edit in ("start", "split"):
                n = int(arg, 0)
                assert 0 < n < len(body) and n % 4 == 0, (name, number, a)
                head = inv.words(body[:n])
                k = inv.code_words_plain(head) if edit == "start" else inv.code_words(head)
                out.append((a, body[:4 * k], edit == "start", tag))
                out.append((a + n, body[n:], False, tag))
            elif edit == "join":
                k = int(arg)
                last_a, last_body = entries[i + k - 1][0], entries[i + k - 1][1]
                ws = inv.words(text[a - base:last_a + len(last_body) - base])
                out.append((a, text[a - base:a - base + 4 * inv.code_words(ws)], False, tag))
                taken |= {(number, x[0]) for x in entries[i:i + k]}
                i += k
            elif edit == "size":
                n = int(arg, 0)
                assert 0 < n < len(body), (name, number, a)
                out.append((a, body[:n], remnant, tag))
            elif edit == "cut":
                k, cuts = parse_cut(arg)
                if i + k > len(entries):
                    sys.exit("%s: %s takes in %d entries after it; level %d has %d" % (BOUNDARIES, name, k, number,
                                                                                         len(entries) - i))
                limit = entries[i + k][0] if i + k < len(entries) else base + len(text)
                at = a
                for off, n, rem, own in cuts:
                    if a + off < at or a + off + n > limit:
                        sys.exit("%s: %s: the piece +%#x:%#x is not inside its entries in level %d (%#x to %#x)"
                                 % (BOUNDARIES, name, off, n, number, a, limit))
                    out.append((a + off, text[a + off - base:a + off + n - base], rem, "variant " + name if own else tag))
                    at = a + off + n
                taken |= {(number, x[0]) for x in entries[i:i + k]}
                i += k
            else:
                out.append((a, body, remnant, "variant " + name if number in {int(x) for x in arg.split(",")}
                            else tag))
    for name, edit, arg, line in edits:
        if done[name] != len(by_name[name][5]):
            sys.exit("%s:%d: %s: %d of its %d places edited" % (BOUNDARIES, line, name, done[name],
                                                                  len(by_name[name][5])))
    if set(todo) & taken:
        sys.exit("%s: a join takes in an entry another edit names" % BOUNDARIES)
    # the other rows, without the edited places and those the joins take in
    gone = set(todo) | taken
    kept = []
    for r in rows:
        places = [p for p in r[5] if p not in gone]
        if places == r[5]:
            kept.append(r)
        elif places:
            kept.append(renamed(r[:5] + (places,), r[5]))
    names = {r[0] for r in kept}
    first = {}                       # (fingerprint, size) -> index in kept of the rules' first copy
    levels_of = collections.defaultdict(set)
    for i, r in enumerate(kept):
        first.setdefault((r[3], r[2]), i)
        levels_of[(r[3], r[2])] |= {n for n, _ in r[5]}
    for r in catalogue_rows(pieces, fb_key, be_key, tagged_kind=True):
        name, kind, size, fp, remnant, places, tagged = r
        k = (fp, size)
        mine = {n for n, _ in places}
        if not tagged and k in first and not (levels_of[k] & mine) and kept[first[k]][4] == remnant:
            i = first[k]
            kept[i] = renamed(kept[i][:5] + (sorted(kept[i][5] + places),), kept[i][5])
            levels_of[k] |= mine
            continue
        if name in names:            # a front-end name another row has: a row of the level code
            n0, a0 = places[0]
            name = "func_L%02d_%08X" % (n0, a0)
            kind = "level" if len(mine) == 1 else "shared"
        names.add(name)
        kept.append((name, kind, size, fp, remnant, places))
    kept = [r[:2] + (r[2], r[3], r[4], sorted(r[5])) for r in kept]
    kept.sort(key=lambda r: r[5][0])
    return kept, done


def parse_cut(arg):
    """(K, [(offset, size, remnant, own row)]) of a cut's argument, `[K/]+A:N[r][o],...`: pieces in order,
    word-aligned."""
    k, _, rest = arg.rpartition("/")
    cuts = []
    for piece in rest.split(","):
        flags = piece[len(piece.rstrip("ro")):]
        rem, own = "r" in flags, "o" in flags
        off, _, n = piece.rstrip("ro").partition(":")
        if not off.startswith("+") or not n:
            sys.exit("%s: cut wants [K/]+A:N[r][o],... and has %r" % (BOUNDARIES, arg))
        off, n = int(off, 0), int(n, 0)
        if off % 4 or n % 4 or n <= 0 or (cuts and off < cuts[-1][0] + cuts[-1][1]):
            sys.exit("%s: cut %r: pieces are word-aligned, not empty and in order" % (BOUNDARIES, arg))
        cuts.append((off, n, rem, own))
    return (int(k) if k else 0), cuts


def renamed(row, before):
    """A level-code row whose places changed: its name and kind as the rules give them (the
    canonical place, one level or more); a front-end row keeps its name."""
    name, kind, size, fp, remnant, places = row
    if kind in ("shared", "level"):
        places = sorted(places)
        if places[0] != sorted(before)[0]:
            name = "func_L%02d_%08X" % places[0]
        kind = "level" if len({n for n, _ in places}) == 1 else "shared"
    return (name, kind, size, fp, remnant, places)


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
    return [(a, data[a - base:a - base + n], k == "remnant") for a, n, k in entries], (base, data)


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
    per_level, data = {}, {}
    splits = read_splits()
    for number in sorted(levels.NAMES):
        places, data[number] = level_places(number, fb_masked)
        # a false fold (split_places.tsv) is a group of its own: its places carry the line as a tag
        per_level[number] = [(a, body, remnant, "split %d" % splits[(number, a)] if (number, a) in splits else None)
                             for a, body, remnant in places]
        print("level %02d: %d functions" % (number, len(places)), flush=True)
    rows = catalogue_rows(per_level, fb_key, be_key)
    edits = read_boundaries()
    if edits:
        rows, done = apply_boundaries(per_level, data, rows, edits, fb_key, be_key)
        print("%s: %d edits at %d places" % (os.path.relpath(BOUNDARIES, ROOT), len(edits), sum(done.values())))
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


def copy_groups(per_level, found):
    """{key: [places of one function]}: code that occurs more than once in a level is one function
    per copy. Each row is named after its first place, the k-th copy (by address) in its lowest
    level, as before; another level's copies go to the rows by what shows which they are:

    1. calls: a function whose code is once in each level (the same row everywhere) that calls a
       copy (a jal) calls the same function in every level at that instruction, so the copies
       its levels call there are one function;
    2. neighbours, for copies no call places (a class's type getter, reached through its class's
       table): a copy goes to the row whose first place has the same anchor before it (the nearest
       code that is once in its level and in another, and how many copies lie between) or after it;
    3. order: what neither places keeps the k-th copy's row among the rows left.

    A function that steps 1 and 2 would move between src/levels/<level>/ and shared/ (one level or
    several) keeps the order. Matched by order alone, a level whose copies are not in the first
    level's order put them on each other's rows: the fifteen class type getters (jr $ra; lw $v0
    from $gp) sat one row along in 24 story levels, and Holostar's and Florana's GUI image widgets
    took another class's type and kept their defaults in the port."""
    keyed, count, levels_of, body_at = {}, {}, collections.defaultdict(set), {}
    for number, items in per_level.items():
        row = []
        for a, body, remnant, tag in items:
            kk = key(body, a) + ((tag,) if tag else ())
            row.append((a, kk))
            body_at[(number, a)] = body
        row.sort()
        keyed[number] = row
        c = collections.Counter(k for a, k in row)
        count[number] = c
        for k in c:
            levels_of[k].add(number)
    key_of = {(n, a): kk for n, row in keyed.items() for a, kk in row}
    repeated = {k for k, e in found.items() if any(count[n][k] > 1 for n in levels_of[k])}

    # a copy some code calls (jal) or takes the address of (lui and addiu/ori) is where that code's
    # C expects it (the build links each level's C to the copy of the name's row,
    # tools/level_symbols.py), so it keeps its order
    called = set()
    for number, row in keyed.items():
        for a, kk in row:
            hi = {}
            for i, w in enumerate(inv.words(body_at[(number, a)])):
                op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
                t = None
                if op == 3:                                   # jal
                    t = ((a + 4 * i + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                elif op == 15:                                # lui: an address's upper half
                    hi[rt] = (w & 0xFFFF) << 16
                elif op in (9, 13) and rs in hi:              # addiu / ori: its lower half
                    lo = w & 0xFFFF
                    t = (hi[rs] + (lo - 0x10000 if op == 9 and lo & 0x8000 else lo)) & 0xFFFFFFFF
                if t is not None and key_of.get((number, t)) in repeated:
                    called.add((number, t))

    def anchors(number, addrs):
        """{address: [before, after]} of one level's copies."""
        mine, out = set(addrs), {a: [None, None] for a in addrs}
        for side, seq in ((0, keyed[number]), (1, list(reversed(keyed[number])))):
            anchor, n = None, 0
            for a, kk in seq:
                if a in mine:
                    out[a][side] = (anchor, n) if anchor is not None else None
                    n += 1
                elif count[number][kk] == 1 and len(levels_of[kk]) > 1:
                    anchor, n = kk, 0
        return out

    out = {}
    for k, e in found.items():
        per = collections.defaultdict(list)
        for number, a in sorted(e["places"]):
            per[number].append(a)
        copies = max(len(v) for v in per.values())
        before = [[(n, v[c]) for n, v in sorted(per.items()) if len(v) > c] for c in range(copies)]
        if copies == 1:
            out[k] = before
            continue
        first = {}
        for c in range(copies):
            n = min(n for n, v in per.items() if len(v) > c)
            first[c] = (n, per[n][c])
        ref = {c: anchors(n, per[n])[a] for c, (n, a) in first.items()}
        rows = [[] for _ in range(copies)]
        for number, addrs in sorted(per.items()):
            placed, taken = {}, set()
            for c, p in first.items():                        # the places that name the rows
                if p[0] == number:
                    placed[p[1]] = c
                    taken.add(c)
            for c, a in enumerate(addrs):                     # the copies code calls or takes
                if (number, a) in called and a not in placed and c not in taken:
                    placed[a] = c
                    taken.add(c)
            mine = anchors(number, addrs)
            for side in (0, 1):                               # neighbours
                for a in addrs:
                    if a in placed or mine[a][side] is None:
                        continue
                    match = [c for c in range(copies) if c not in taken and ref[c][side] == mine[a][side]
                             and first[c][0] <= number]
                    if len(match) == 1:
                        placed[a] = match[0]
                        taken.add(match[0])
            free = [c for c in range(copies) if c not in taken]     # order
            for a in addrs:
                if a not in placed:
                    placed[a] = free.pop(0)
            for a, c in placed.items():
                rows[c].append((number, a))
        # a row keeps its kind (its source file's folder, src/levels/)
        kinds = lambda rs: [len({p[0] for p in r}) > 1 for r in rs]
        out[k] = [sorted(r) for r in rows] if kinds(rows) == kinds(before) else before
    return out


def catalogue_rows(per_level, fb_key, be_key, tagged_kind=False):
    """The catalogue's rows [(name, kind, size, fingerprint, remnant, places)] from every level's
    places {level: [(address, bytes, remnant, tag)]}: equal code (key()) and tag is one function,
    its copies matched across levels by copy_groups(). TAGGED_KIND: each row ends with whether its places
    have a tag."""
    found = {}
    for number in sorted(per_level):
        for a, body, remnant, tag in per_level[number]:
            k = key(body, a) + ((tag,) if tag else ())
            e = found.setdefault(k, {"size": len(body), "remnant": remnant, "places": []})
            e["places"].append((number, a))
    groups = copy_groups(per_level, found)
    rows = []
    for k, e in found.items():
        for places in groups[k]:
            copies = len(groups[k])
            plain = len(k) == 2 or not k[2].startswith(("variant", "split "))
            if copies == 1 and plain and len(fb_key.get(k[:2], ())) == 1:
                name, kind = "func_%08X" % fb_key[k[:2]][0], "frontbin"
            elif copies == 1 and plain and len(be_key.get(k[:2], ())) == 1:
                name, kind = "func_%08X" % be_key[k[:2]][0], "boot_elf"
            else:
                n0, a0 = places[0]
                name = "func_L%02d_%08X" % (n0, a0)
                kind = "level" if len({p[0] for p in places}) == 1 else "shared"
            if tagged_kind:
                rows.append((name, kind, e["size"], k[0], e["remnant"], places, not plain))
            else:
                rows.append((name, kind, e["size"], k[0], e["remnant"], places))
    rows.sort(key=lambda r: r[5][0])
    return rows


@memo.kept()
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
