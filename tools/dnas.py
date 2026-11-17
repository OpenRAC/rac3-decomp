#!/usr/bin/env python3
"""dnas.py: the protected blocks of level 39's DNAS client code, and the build step that makes them.

Level 39 (the multiplayer menu) links Sony's DNAS client library. 112 runs of its code are stored
encrypted in `.text`, each inside a function, between a stub that decrypts it when the function
is entered and (for 94 of them) one that encrypts it again before the function returns. The
functions were C (docs/build/dnas.md has the evidence): Sony's tool worked on the compiled
objects, before linking. This module is that step for our build.

    python3 tools/dnas.py protect FILE.o [--version us]   # the step, on one object, in place
    python3 tools/dnas.py blocks FILE.o                   # the blocks an object holds

What is in the program, per block (word offsets from the stub's `b`):

     0  b +0xC; nop              jumps over the next eleven words, to the block
     2  six filler words         random, never read
     8  record 1: 0, k2, k3, k1, 0     (the first word is a flag the driver sets at run time)
    13  the block, len bytes     encrypted
        b +0xB; nop              jumps over the next ten words
        six filler words
        record 2: k2e, k3e, k1e, 0

`len = k1 ^ k2`. The driver (func_L39_004BD350 for the first library, func_L39_004F7890 for the
second; `driver(block, k1, k2, k3)`) decrypts `[block, block + len)` when `k3 & 1` is 0 and
encrypts `[block - len, block)` when it is 1. `k3 >> 1` names a list of the block's words it
leaves alone: the words the linker relocates (`jal`, `%hi`, `%lo`).

The cipher, as the level's own routines run it:

  * schedule(k2): `(k2 >> 28) & 7` steps, 5 when that is 0; step i applies transform
    `(k2 >> 4i) & 7` to every word of the block that is not left alone;
  * eight transforms of one 32-bit word, from two constants, two rotations and one byte
    permutation (E below; D is their inverses);
  * decrypting and encrypting both run their steps first to last, so the record that encrypts
    a block again holds the schedule of the record that decrypts it, reversed (second_k2()).

All of this was read from the retail programs' own code and bytes (the level's driver, key
lookup, schedule and transform routines) and checked on every block of both discs:
encrypt(decrypt(block)) is the stored block, 112 of 112. No Sony source, header or sample was
used.

What a build cannot compute is fifteen words per block that Sony's tool drew at random when it
ran: k2, k3 (a key id) and the twelve filler words. They differ between the PAL and NTSC-U
builds of identical code, so each version has a table of them (TABLE, read_table();
tools/dnas_blocks.py writes and checks it from a disc). Everything else follows:
k1 = k2 ^ len, k2e = second_k2(k2), k3e = k3 | 1, k1e = k2e ^ len.

## The build step (protect_object())

The C marks a block with DNAS_BEGIN(function, n, driver) and DNAS_END(function, n, driver)
(include/dnas.h). Compiled, that is the layout above with zero for the fifteen words (a record
of key 0) and the labels `dnas_blk_<function>_<n>` and so on. On the assembled object, before
anything links it, the step:

  1. finds every block from its stub and its two records (find_blocks()) and names it from its
     label (a block without a label is a function still in assembly, with retail's words: it
     is left alone);
  2. takes the block's row from the version's table and writes the filler and both records;
  3. encrypts every word of the block that carries no relocation, with k2e (what the driver's
     encrypt direction does).

tools/build_text.py runs it on every object it assembles, tools/check.py on the object it
compares (so a single function is compared with retail's stored bytes), and through check.py
tools/c_objects.py for the NTSC-U build.
"""
import collections
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

M = 0xFFFFFFFF
X0, X1 = 0x09F8ED17, 0xA95128C3


class DnasError(ValueError):
    pass


# --- the cipher -------------------------------------------------------------------------------

def rotl(v, n):
    return ((v << n) | (v >> (32 - n))) & M


def rotr(v, n):
    return ((v >> n) | (v << (32 - n))) & M


def perm(v):
    """bytes (b3 b2 b1 b0) -> (b2 b0 b3 b1)"""
    return ((v << 8) & 0xFF000000) | ((v << 16) & 0x00FF0000) | ((v >> 16) & 0x0000FF00) | ((v >> 8) & 0xFF)


def iperm(v):
    """perm()'s inverse: bytes (b3 b2 b1 b0) -> (b1 b3 b0 b2)"""
    return ((v << 16) & 0xFF000000) | ((v >> 8) & 0x00FF0000) | ((v << 8) & 0x0000FF00) | ((v >> 16) & 0xFF)


E = (
    lambda v: v ^ X0,
    lambda v: v ^ X1,
    lambda v: rotl(v, 13),
    lambda v: rotl(v, 8),
    perm,
    lambda v: rotl(v, 13) ^ X0,
    lambda v: perm(rotl(v, 8) ^ X1),
    lambda v: rotl(rotl(perm(v), 13), 8) ^ X0,
)
D = (
    lambda v: v ^ X0,
    lambda v: v ^ X1,
    lambda v: rotr(v, 13),
    lambda v: rotr(v, 8),
    iperm,
    lambda v: rotr(v ^ X0, 13),
    lambda v: rotr(iperm(v) ^ X1, 8),
    lambda v: iperm(rotr(rotr(v ^ X0, 8), 13)),
)


def schedule(k2):
    """The transform numbers a record's k2 selects, in the order they are applied."""
    steps = (k2 >> 28) & 7 or 5
    return [(k2 >> (4 * i)) & 7 for i in range(steps)]


def second_k2(k2):
    """The k2 of the record after the block: k2 with its schedule nibbles (the low `steps`
    nibbles) in reverse order and every other bit kept."""
    n = len(schedule(k2))
    out = k2 & ~((1 << (4 * n)) - 1)
    for i in range(n):
        out |= ((k2 >> (4 * (n - 1 - i))) & 0xF) << (4 * i)
    return out & M


def crypt(words, steps, table, skip=()):
    """`words` with each step's transform applied to every word whose index is not in `skip`."""
    out = list(words)
    skip = set(skip)
    for t in steps:
        f = table[t]
        for i, v in enumerate(out):
            if i not in skip:
                out[i] = f(v)
    return out


def encrypt(words, k2, skip=()):
    return crypt(words, schedule(k2), E, skip)


def decrypt(words, k2, skip=()):
    return crypt(words, schedule(k2), D, skip)


# --- a block's stubs and records ----------------------------------------------------------------

B_BLOCK, B_AFTER = 0x1000000C, 0x1000000B     # `b +0xC`, `b +0xB`
BEFORE, AFTER = 13, 12                        # words from each `b` to what follows its record
MAX_LENGTH = 0x4000                           # the largest block on the discs is 0x7DC bytes

Block = collections.namedtuple("Block", "stub start end k2 k3 before after")
Block.__doc__ = """One block in a list of words: `stub` the index of its `b +0xC`, `start` and `end` the
block's word range, k2 and k3 as record 1 has them, `before` and `after` the six filler words
of each group."""


def records(k2, k3, length):
    """(record 1, record 2) of a block of `length` bytes: [0, k2, k3, k1, 0] and
    [k2e, k3e, k1e, 0]."""
    k2e = second_k2(k2)
    return [0, k2, k3, k2 ^ length, 0], [k2e, k3 | 1, k2e ^ length, 0]


def block_at(words, i):
    """The Block whose `b +0xC` is words[i], or None: both stubs and both records must be
    there and agree (a first flag word of 0, len = k1 ^ k2 a whole number of words, the second
    record's k3 the first's with bit 0 set, its k1 ^ k2 the same length)."""
    if i < 0 or i + BEFORE > len(words) or words[i] != B_BLOCK or words[i + 1] or words[i + 8] or words[i + 12]:
        return None
    k2, k3, k1 = words[i + 9], words[i + 10], words[i + 11]
    length = k1 ^ k2
    if length % 4 or length > MAX_LENGTH or k3 & 1:
        return None
    s = i + BEFORE
    e = s + length // 4
    if e + AFTER > len(words) or words[e] != B_AFTER or words[e + 1] or words[e + 11]:
        return None
    if words[e + 9] != k3 | 1 or words[e + 8] ^ words[e + 10] != length:
        return None
    return Block(i, s, e, k2, k3, tuple(words[i + 2:i + 8]), tuple(words[e + 2:e + 8]))


def find_blocks(words):
    """Every Block in `words`, in order. A block is known by its stubs and records alone."""
    out, i = [], 0
    while i + BEFORE <= len(words):
        b = block_at(words, i) if words[i] == B_BLOCK else None
        if b:
            out.append(b)
            i = b.end + AFTER
        else:
            i += 1
    return out


def is_blank(b):
    """True for a block as the compiler leaves it: key 0, zero filler (include/dnas.h)."""
    return not (b.k2 or b.k3 or any(b.before) or any(b.after))


def protect_words(words, relocated, rows, only=None):
    """The step on a list of words. `relocated`: the indices of the words that carry a
    relocation; `rows`: {index of a block's first word (Block.start): Row}. Returns the new
    list. Every block found must be blank and have its row; with `only` (a set of Block.start),
    the other blocks are left as they are."""
    out = list(words)
    for b in find_blocks(words):
        if only is not None and b.start not in only:
            continue
        row = rows.get(b.start)
        if row is None:
            raise DnasError("the block at +0x%X has no row" % (4 * b.start))
        if not is_blank(b):
            raise DnasError("the block at +0x%X is protected already (k2 %08X)" % (4 * b.start, b.k2))
        length = 4 * (b.end - b.start)
        r1, r2 = records(row.k2, row.k3, length)
        out[b.stub + 2:b.stub + 8] = row.before
        out[b.stub + 8:b.stub + 13] = r1
        skip = [k - b.start for k in range(b.start, b.end) if k in relocated]
        out[b.start:b.end] = encrypt(words[b.start:b.end], r2[0], skip)
        out[b.end + 2:b.end + 8] = row.after
        out[b.end + 8:b.end + 12] = r2
    return out


# --- the tables of random words -------------------------------------------------------------------

Row = collections.namedtuple("Row", "function block offset length k2 k3 before after")
Row.__doc__ = """One line of a table: the catalogue name of the function and the block's number in it (in
address order, from 0), the block's offset in the function and its length in bytes (retail's
layout, for messages and checks), then the fifteen random words: k2, k3 and the six filler
words of each group."""

HEAD = """# The random words of level 39's protected DNAS blocks on the %(disc)s disc (docs/build/dnas.md).
# Sony's tool drew fifteen words per block when it protected the library's objects: k2 (the
# schedule and the mask of the length), k3 (a key id; 0 for a block with no relocated word) and
# twelve filler words that nothing reads. They are not functions of the code (identical code has
# other words on the other disc), so the build takes them from here (tools/dnas.py). This table is
# the one exception to "never commit game data" (AGENTS.md); nothing else from a disc is here.
# Written and checked from your own disc by tools/dnas_blocks.py%(flag)s --write / --check.
#
# function (its catalogue name on this disc), the block's number in it (address order), the
# block's offset in the function and its length in bytes, k2, k3, the six filler words before
# record 1, the six before record 2. Tab-separated; the words are hexadecimal.
"""
WORD = re.compile(r"^[0-9A-F]{8}$")


def table_path(v=None):
    """config/levels/dnas_blocks.tsv, or config/us/levels/dnas_blocks.tsv for NTSC-U."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import version
    return version.cfg("levels", "dnas_blocks.tsv", v=v)


def parse_table(text, where="the table"):
    """{(function, block): Row} of a table's text. DnasError names the line that is wrong."""
    out = {}
    for n, line in enumerate(text.splitlines(), 1):
        if not line.strip() or line.startswith("#"):
            continue
        f = line.split("\t")
        try:
            if len(f) != 8:
                raise ValueError("%d fields, not 8" % len(f))
            before, after = f[6].split(" "), f[7].split(" ")
            words = [f[4], f[5]] + before + after
            if len(before) != 6 or len(after) != 6 or not all(WORD.match(w) for w in words):
                raise ValueError("it needs k2, k3 and two groups of six words, each 8 hexadecimal digits")
            if not re.match(r"^func_\w+$", f[0]):
                raise ValueError("%r is not a function name" % f[0])
            row = Row(f[0], int(f[1]), int(f[2], 16), int(f[3], 16), int(f[4], 16), int(f[5], 16),
                      tuple(int(w, 16) for w in before), tuple(int(w, 16) for w in after))
            if row.block < 0 or row.offset % 4 or row.length % 4 or row.k3 & 1:
                raise ValueError("a block number, a word-aligned offset and length, and an even k3 are needed")
        except ValueError as e:
            raise DnasError("%s, line %d: %s" % (where, n, e))
        if (row.function, row.block) in out:
            raise DnasError("%s, line %d: %s block %d is there twice" % (where, n, row.function, row.block))
        out[(row.function, row.block)] = row
    for (function, block) in out:
        if block and (function, block - 1) not in out:
            raise DnasError("%s: %s has a block %d but no block %d" % (where, function, block, block - 1))
    return out


def format_table(rows, v="pal"):
    """A table's text from Rows."""
    lines = [(HEAD % {"disc": "NTSC-U" if v == "us" else "PAL", "flag": " --version us" if v == "us" else ""})
             .rstrip("\n")]
    for r in sorted(rows, key=lambda r: (r.function, r.block)):
        lines.append("\t".join([r.function, "%d" % r.block, "0x%X" % r.offset, "0x%X" % r.length,
                                "%08X" % r.k2, "%08X" % r.k3, " ".join("%08X" % w for w in r.before),
                                " ".join("%08X" % w for w in r.after)]))
    return "\n".join(lines) + "\n"


_TABLES = {}


def read_table(v=None, path=None):
    """{(function, block): Row} of a version's table ({} when the file is not there)."""
    path = path or table_path(v)
    if path not in _TABLES:
        if not os.path.exists(path):
            return {}
        with open(path, encoding="utf-8") as f:
            _TABLES[path] = parse_table(f.read(), os.path.relpath(path, ROOT))
    return _TABLES[path]


# --- an object file ---------------------------------------------------------------------------------

LABEL = re.compile(r"^dnas_(rec|blk|end|rec2|aft)_(func_\w+)_(\d+)$")
SHT_SYMTAB, SHT_RELA, SHT_REL = 2, 4, 9


def read_object(data):
    """What the step needs of an ELF32 little-endian object: {text: (file offset, size), relocated:
    {byte offsets in .text that carry a relocation}, symbols: {name: (value, size)} of the symbols
    defined in .text}."""
    if data[:6] != b"\x7fELF\x01\x01":
        raise DnasError("not a 32-bit little-endian ELF object")
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    sh = [struct.unpack_from("<10I", data, shoff + shentsize * i) for i in range(shnum)]

    def cstr(table, at):
        start = sh[table][4] + at
        return data[start:data.index(b"\0", start)].decode("latin-1")
    names = [cstr(shstrndx, s[0]) for s in sh]
    if ".text" not in names:
        raise DnasError("no .text section")
    ti = names.index(".text")
    relocated, symbols = set(), {}
    for s in sh:
        if s[1] in (SHT_REL, SHT_RELA) and s[7] == ti:
            size = 8 if s[1] == SHT_REL else 12
            for k in range(s[5] // size):
                relocated.add(struct.unpack_from("<I", data, s[4] + size * k)[0])
        elif s[1] == SHT_SYMTAB:
            for k in range(s[5] // 16):
                name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", data, s[4] + 16 * k)
                if shndx == ti and name and info & 0xF != 3:
                    symbols[cstr(s[6], name)] = (value, size)
    return {"text": (sh[ti][4], sh[ti][5]), "relocated": relocated, "symbols": symbols}


def object_blocks(obj, words):
    """[(Block, function, number)] of the blocks an object's C made: those found in its .text
    that have their label `dnas_blk_<function>_<number>`. A block without a label is left out
    when it is not blank: it is a function still in assembly (INCLUDE_ASM), with retail's own
    stored words. A blank block without its label, a label without its block, or a block
    outside the function its label names is a DnasError."""
    labels = {}
    for name, (value, _) in obj["symbols"].items():
        m = LABEL.match(name)
        if m and m.group(1) == "blk":
            labels[value] = (m.group(2), int(m.group(3)))
    found = find_blocks(words)
    out = []
    for b in found:
        if 4 * b.start not in labels:
            if not is_blank(b):
                continue
            raise DnasError("the protected block at +0x%X has no dnas_blk_ label: write it with "
                            "include/dnas.h's DNAS_BEGIN and DNAS_END" % (4 * b.start))
        function, number = labels.pop(4 * b.start)
        own = obj["symbols"].get(function)
        if own is None or not own[0] <= 4 * b.stub < own[0] + (own[1] or 1 << 32):
            raise DnasError("block %d of %s is not inside %s: DNAS_BEGIN names the function it is in"
                            % (number, function, function))
        out.append((b, function, number))
    for at, (function, number) in sorted(labels.items()):
        raise DnasError("block %d of %s (+0x%X) is not a whole block: DNAS_BEGIN without its DNAS_END, "
                        "or code the compiler moved out of it" % (number, function, at))
    return out


def protect_object(path, table=None, name_of=None, v=None, notes=None):
    """Run the step on the object file `path`, in place. `table`: {(function, block): Row}
    (default: the version's); `name_of(function)`: the table's name of a function as the C
    names it (NTSC-U's table has NTSC-U's names; default: the same name). Returns
    [(function, number, Row)] of the blocks protected; [] (and the file untouched) for an
    object without blocks. `notes` (a list) gets a line per block whose place or length is not
    retail's. DnasError when a block cannot be protected."""
    with open(path, "rb") as f:
        data = bytearray(f.read())
    obj = read_object(bytes(data))
    off, size = obj["text"]
    words = list(struct.unpack_from("<%dI" % (size // 4), data, off))
    blocks = object_blocks(obj, words)
    if not blocks:
        return []
    table = read_table(v) if table is None else table
    rows, done = {}, []
    for b, function, number in blocks:
        name = name_of(function) if name_of else function
        row = table.get((name, number)) if name else None
        if row is None:
            raise DnasError("no row for block %d of %s%s in %s (tools/dnas_blocks.py writes the table "
                            "from your disc)" % (number, function, " (%s)" % name if name and name != function else "",
                                                 os.path.relpath(table_path(v), ROOT)))
        rows[b.start] = row
        done.append((function, number, row))
        if notes is not None:
            at, length = 4 * b.start - obj["symbols"][function][0], 4 * (b.end - b.start)
            if (at, length) != (row.offset, row.length):
                notes.append("block %d of %s: 0x%X bytes at +0x%X here, 0x%X at +0x%X in retail"
                             % (number, function, length, at, row.length, row.offset))
    out = protect_words(words, {r // 4 for r in obj["relocated"]}, rows, only=set(rows))
    struct.pack_into("<%dI" % len(out), data, off, *out)
    with open(path, "wb") as f:
        f.write(data)
    return done


def has_blocks(assembly):
    """True when a compiler's assembly text has a protected block (so its object needs the step)."""
    return "dnas_blk_" in assembly


def main():
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import version  # noqa: F401  (takes --version out of the arguments)
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["protect", "blocks"])
    ap.add_argument("object")
    a = ap.parse_args()
    try:
        if a.command == "protect":
            notes = []
            for function, number, row in protect_object(a.object, notes=notes):
                print("%s block %d: protected (k2 %08X, k3 %08X)" % (function, number, row.k2, row.k3))
            print("\n".join(notes), end="\n" if notes else "")
        else:
            data = open(a.object, "rb").read()
            obj = read_object(data)
            off, size = obj["text"]
            words = list(struct.unpack_from("<%dI" % (size // 4), data, off))
            for b, function, number in object_blocks(obj, words):
                print("%s block %d: +0x%X..+0x%X, %s" % (function, number, 4 * b.start, 4 * b.end,
                                                       "blank" if is_blank(b) else "k2 %08X k3 %08X" % (b.k2, b.k3)))
    except DnasError as e:
        sys.exit("dnas: %s: %s" % (a.object, e))


if __name__ == "__main__":
    main()
