#!/usr/bin/env python3
"""dnas_blocks.py: the tables of the protected DNAS blocks' random words, from your own disc.

    python3 tools/dnas_blocks.py [--version us] --write      # config/[us/]levels/dnas_blocks.tsv
    python3 tools/dnas_blocks.py [--version us] --check      # the committed table is your disc's
    python3 tools/dnas_blocks.py [--version us] --list       # every block: function, number, place, length
    python3 tools/dnas_blocks.py [--version us] --show func_L39_004B4620
                                                             # a function with its blocks decrypted

tools/dnas.py has the layout of a block and the cipher; docs/build/dnas.md the whole story. This
tool reads the level programs of baserom/levels/ (or baserom/us/levels/), finds every block from
its stubs and records, and keeps, per block, what a build cannot compute: k2, k3 and the twelve
filler words, under the catalogue name of the function the block is in and its number there
(address order, from 0). Before a table is written or passed, every block is checked against
the disc:

  - both records are what tools/dnas.py computes from k2, k3 and the length (k1, k2e, k3e, k1e);
  - k3 is a key of the driver's key table when the block has words left alone, and 0 when not;
  - decrypting the block and encrypting it again, with the words the key table lists left
    alone, gives the stored words;
  - the block lies inside one function of the catalogue.

--show prints what a function is once its blocks are decrypted: what the C must compile to
before the build step protects it (docs/build/dnas.md, "Writing a protected function"). The
plaintext is printed, never written to the repository.

The key table (in `.text`, one per library; plain data that stays assembly) is found from the
driver each block's stub calls: `driver -> key lookup -> lui/addiu of the table`. It is
`{count, count x {idword, rel}, entries}`; the entry of the first `idword >> 1 == k3 >> 1` is at
`table + 4 + 8 * count + rel` and is `{obj_off, n, n x offset}`: the block's word at
`block - obj_off + offset` is left alone. The offsets are those of the relocations the library's
objects had: the build step takes them from our object's own relocations instead.
"""
import argparse
import bisect
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402
import dnas  # noqa: E402


class Program:
    """A level program's .text as words."""

    def __init__(self, number):
        import levels
        self.number = number
        path = levels.elf_path(number)
        if not os.path.exists(path):
            sys.exit("%s not found: python3 tools/levels.py%s dump" % (os.path.relpath(path, ROOT),
                                                                      " --version us" if version.is_us() else ""))
        _, secs = levels.read_elf(open(path, "rb").read())
        self.base, _, _, self.data = secs[-1]
        self.words = struct.unpack("<%dI" % (len(self.data) // 4), self.data[:len(self.data) & ~3])

    def index(self, address):
        return (address - self.base) // 4

    def address(self, index):
        return self.base + 4 * index

    def has(self, address):
        return self.base <= address < self.base + 4 * len(self.words) and not address % 4

    def blocks(self):
        """Every dnas.Block of the program (word indices), in address order."""
        out, at, stub = [], 0, struct.pack("<II", dnas.B_BLOCK, 0)
        while True:
            at = self.data.find(stub, at)
            if at < 0:
                return out
            b = dnas.block_at(self.words, at // 4) if at % 4 == 0 else None
            if b:
                out.append(b)
                at = 4 * (b.end + dnas.AFTER)
            else:
                at += 1


def driver_of(p, b):
    """The driver a block's stub calls: the last `jal` in the eight words before its `b`."""
    for i in range(b.stub - 1, max(b.stub - 9, -1), -1):
        if p.words[i] >> 26 == 3:
            return (p.address(i) & 0xF0000000) | ((p.words[i] & 0x3FFFFFF) << 2)
    return None


def key_table(p, driver):
    """{key id: (obj_off, [offsets])} of the key table a driver reads, or None when the driver
    is not the code this was written from (its first call is the key lookup, which loads the
    table's address into $v1 with lui/addiu as its third and fourth instructions)."""
    if driver is None or not p.has(driver):
        return None
    d = p.index(driver)
    calls = [(driver & 0xF0000000) | ((w & 0x3FFFFFF) << 2) for w in p.words[d:d + 0x36] if w >> 26 == 3]
    if not calls or not p.has(calls[0]):
        return None
    k = p.index(calls[0])
    hi, lo = p.words[k + 2], p.words[k + 3]
    if hi >> 16 != 0x3C03 or lo >> 16 != 0x2463:
        return None
    table = ((hi & 0xFFFF) << 16) + ((lo & 0xFFFF) ^ 0x8000) - 0x8000
    if not p.has(table):
        return None
    t = p.index(table)
    count = p.words[t]
    if not 0 < count < 0x1000:
        return None
    keys = {}
    for i in range(count):
        idword, rel = p.words[t + 1 + 2 * i], p.words[t + 2 + 2 * i]
        e = t + 1 + 2 * count + rel // 4
        if rel % 4 or e + 2 > len(p.words) or p.words[e + 1] > 0x4000:
            return None
        keys.setdefault(idword >> 1, (p.words[e], list(p.words[e + 2:e + 2 + p.words[e + 1]])))
    return keys


def skipped(p, b, tables):
    """(the word numbers in a block that the driver leaves alone, problem or None)"""
    if not b.k3:
        return [], None
    driver = driver_of(p, b)
    if driver not in tables:
        tables[driver] = key_table(p, driver)
    keys = tables[driver]
    if keys is None:
        return [], "its stub's driver (%s) has no key table this tool can read" % (
            "0x%08X" % driver if driver is not None else "not found")
    if b.k3 >> 1 not in keys:
        return [], "its key %08X is not in the driver's key table" % (b.k3 >> 1)
    obj_off, offsets = keys[b.k3 >> 1]
    length = 4 * (b.end - b.start)
    return sorted((o - obj_off) // 4 for o in offsets if 0 <= o - obj_off < length and not (o - obj_off) % 4), None


def problems_of(p, b, skip):
    """What is not as tools/dnas.py computes it for one block of a program."""
    w, out = p.words, []
    length = 4 * (b.end - b.start)
    r1, r2 = dnas.records(b.k2, b.k3, length)
    if list(w[b.stub + 8:b.stub + 13]) != r1:
        out.append("record 1 is not {0, k2, k3, k2 ^ len, 0}")
    if list(w[b.end + 8:b.end + 12]) != r2:
        out.append("record 2 is not {k2e, k3 | 1, k2e ^ len, 0} with k2e = second_k2(k2)")
    if bool(b.k3) != bool(skip):
        out.append("k3 is %08X but %d of its words are left alone" % (b.k3, len(skip)))
    stored = list(w[b.start:b.end])
    if dnas.encrypt(dnas.decrypt(stored, b.k2, skip), r2[0], skip) != stored:
        out.append("decrypting and encrypting again does not give the stored words")
    return out


def catalogue():
    import level_catalogue as lc
    return [r for r in lc.read_catalogue(version.cfg("levels", "functions.tsv"))]


def scan(numbers=None, rows=None):
    """([(Row, level, block address, [skipped word numbers])], [problem]) of every block in the
    version's level programs, each under the catalogue row it is in."""
    import levels
    rows = rows or catalogue()
    out, problems, seen = [], [], {}
    for lv in levels.read_table():
        n = lv["number"]
        if numbers and n not in numbers:
            continue
        p = Program(n)
        blocks = p.blocks()
        if not blocks:
            continue
        places = sorted((a, r) for r in rows for m, a in r[5] if m == n)
        starts = [a for a, _ in places]
        tables, count = {}, {}
        for b in blocks:
            where = "level %02d, block 0x%08X" % (n, p.address(b.start))
            i = bisect.bisect_right(starts, p.address(b.stub)) - 1
            if i < 0:
                problems.append("%s: before the first function" % where)
                continue
            start, r = places[i]
            if p.address(b.end + dnas.AFTER) > start + r[2]:
                problems.append("%s: runs past %s (0x%08X, %d bytes): the catalogue cuts a function inside "
                                "the block (config/%slevels/boundaries.tsv)" % (
                                    where, r[0], start, r[2], "us/" if version.is_us() else ""))
            skip, why = skipped(p, b, tables)
            problems += ["%s: %s" % (where, x) for x in ([why] if why else []) + problems_of(p, b, skip)]
            number = count.get(start, 0)
            count[start] = number + 1
            row = dnas.Row(r[0], number, p.address(b.start) - start, 4 * (b.end - b.start), b.k2, b.k3,
                           b.before, b.after)
            key = (row.function, row.block)
            if key in seen and seen[key][0] != row:
                problems.append("%s: %s block %d has other words in level %02d" % (where, r[0], number, seen[key][1]))
                continue
            if key not in seen:
                seen[key] = (row, n)
                out.append((row, n, p.address(b.start), skip))
    return out, problems


_PROGRAMS = {}


def plain_words(number, address, size):
    """(words, [(Block, [skipped word numbers])]) of `size` bytes at `address` in level `number`'s
    program, with every protected block that starts in them decrypted (Block's indices are the
    program's; Program.index(address) is the first word's). ValueError when a block's key
    cannot be read."""
    if number not in _PROGRAMS:
        _PROGRAMS[number] = (Program(number), {})
        _PROGRAMS[number] += (_PROGRAMS[number][0].blocks(),)
    p, tables, blocks = _PROGRAMS[number]
    s, e = p.index(address), p.index(address + size)
    plain, found = list(p.words[s:e]), []
    for b in blocks:
        if not s <= b.stub < e:
            continue
        skip, why = skipped(p, b, tables)
        if why:
            raise ValueError("the block at 0x%08X: %s" % (p.address(b.start), why))
        text = dnas.decrypt(p.words[b.start:b.end], b.k2, skip)
        plain[b.start - s:b.end - s] = text[:max(0, e - b.start)]
        found.append((b, skip))
    return plain, found


def show(name):
    """Print a function with its blocks decrypted."""
    import check
    rows = catalogue()
    r = next((r for r in rows if r[0] == name), None)
    if r is None:
        sys.exit("%s is not in %s" % (name, os.path.relpath(version.cfg("levels", "functions.tsv"), ROOT)))
    n, start = r[5][0]
    try:
        plain, found = plain_words(n, start, r[2])
    except ValueError as err:
        sys.exit("%s: %s" % (name, err))
    p = _PROGRAMS[n][0]
    s, e = p.index(start), p.index(start + r[2])
    notes = {}
    number = 0
    for b, skip in found:
        notes[b.stub] = "DNAS_BEGIN(%s, %d, ...): b to the block, nop" % (name, number)
        for i in range(b.stub + 2, b.stub + 8):
            notes[i] = "filler"
        notes[b.stub + 8] = "record 1: flag, k2, k3, k1, 0 (len 0x%X, steps %s)" % (
            4 * (b.end - b.start), "".join("%d" % t for t in dnas.schedule(b.k2)))
        for i in range(b.stub + 9, b.stub + 13):
            notes[i] = "record 1"
        for i in range(b.start, b.end):
            notes[i] = "block %d, relocated: stored as it is" % number if i - b.start in skip else "block %d" % number
        notes[b.end] = "DNAS_END(%s, %d, ...): b over the record, nop" % (name, number)
        for i in range(b.end + 2, b.end + 8):
            notes[i] = "filler"
        for i in range(b.end + 8, b.end + 12):
            notes[i] = "record 2: k2e, k3e, k1e, 0"
        number += 1
    print("%s: level %02d, 0x%08X, %d bytes, %d block(s); decrypted words are marked `block`" % (
        name, n, start, r[2], number))
    for i in range(s, e):
        note = notes.get(i, "")
        data = note.startswith(("filler", "record"))
        text = ".word 0x%08X" % plain[i - s] if data else check.dis(plain[i - s])
        print("+%04X %08X  %08X  %-40s%s" % (4 * (i - s), p.address(i), plain[i - s], text,
                                           "  # " + note if note else ""))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--write", action="store_true", help="write the version's table from the disc")
    g.add_argument("--check", action="store_true", help="the committed table is what the disc gives")
    g.add_argument("--list", action="store_true", help="every block of the disc")
    g.add_argument("--show", metavar="FUNCTION", help="print a function with its blocks decrypted")
    a = ap.parse_args()
    if a.show:
        show(a.show)
        return
    found, problems = scan()
    path = dnas.table_path()
    rel = os.path.relpath(path, ROOT)
    if a.list:
        for row, n, address, skip in found:
            print("%s\t%d\t%02d:%08X\t0x%X\tsteps %s\t%d relocated" % (
                row.function, row.block, n, address, row.length,
                "".join("%d" % t for t in dnas.schedule(row.k2)), len(skip)))
    if problems:
        sys.exit("%d problem(s) with the disc's blocks:\n  %s" % (len(problems), "\n  ".join(problems)))
    text = dnas.format_table([f[0] for f in found], version.V)
    functions = len({f[0].function for f in found})
    if a.write:
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, "w", newline="\n", encoding="utf-8").write(text)
        print("wrote %s: %d blocks in %d functions" % (rel, len(found), functions))
    elif a.check:
        have = open(path, encoding="utf-8").read() if os.path.exists(path) else ""
        if have != text:
            old = dnas.parse_table(have, rel) if have else {}
            new = {(f[0].function, f[0].block): f[0] for f in found}
            diff = sorted(k for k in set(old) | set(new) if old.get(k) != new.get(k))
            sys.exit("%s is not what the disc gives: %d row(s) differ (%s%s); python3 tools/dnas_blocks.py%s --write"
                     % (rel, len(diff), ", ".join("%s %d" % k for k in diff[:5]), ", ..." if len(diff) > 5 else "",
                        " --version us" if version.is_us() else ""))
        print("%s: %d blocks in %d functions, as the disc has them" % (rel, len(found), functions))
    else:
        print("%d blocks in %d functions" % (len(found), functions))


if __name__ == "__main__":
    main()
