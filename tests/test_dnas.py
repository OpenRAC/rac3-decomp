"""Unit tests for tools/dnas.py: the protected DNAS blocks' cipher, block finder, tables and the
build step on an object. No game data and no toolchain: the words are made up here.

  python3 -m unittest discover -s tests
"""
import os
import random
import re
import struct
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import dnas  # noqa: E402


def blank(length_words, body=None):
    """A block as include/dnas.h's macros compile it: the stub's `b` and nop, six zero filler words,
    the record of key 0, the block, the second `b`, filler and record."""
    body = list(body if body is not None else range(0x24020000, 0x24020000 + length_words))
    n = 4 * len(body)
    return [dnas.B_BLOCK, 0] + [0] * 6 + [0, 0, 0, n, 0] + body + [dnas.B_AFTER, 0] + [0] * 6 + [0, 1, n, 0]


def row(k2=0x50CA7FBF, k3=0x9413EE4E, function="func_L39_00400000", block=0, offset=0x70, length=0xC):
    return dnas.Row(function, block, offset, length, k2, k3, tuple(range(0xA0000001, 0xA0000007)),
                    tuple(range(0xB0000001, 0xB0000007)))


class CipherTest(unittest.TestCase):
    def test_each_transform_has_its_inverse(self):
        rng = random.Random(1)
        for t in range(8):
            for _ in range(200):
                v = rng.getrandbits(32)
                self.assertEqual(dnas.D[t](dnas.E[t](v)), v, t)
                self.assertEqual(dnas.E[t](dnas.D[t](v)), v, t)
                self.assertLessEqual(dnas.E[t](v), 0xFFFFFFFF)

    def test_transforms(self):
        self.assertEqual(dnas.perm(0x11223344), 0x22441133)
        self.assertEqual(dnas.iperm(0x22441133), 0x11223344)
        self.assertEqual(dnas.rotl(0x80000001, 13), 0x00003000)
        self.assertEqual(dnas.E[0](0), dnas.X0)
        self.assertEqual(dnas.E[1](0), dnas.X1)
        self.assertEqual(dnas.E[5](1), 0x2000 ^ dnas.X0)

    def test_schedule(self):
        # the top nibble's low three bits count the steps, 0 meaning 5; step i is nibble i's low three bits
        self.assertEqual(dnas.schedule(0x50CA7FBF), [7, 3, 7, 7, 2])
        self.assertEqual(dnas.schedule(0x00000321), [1, 2, 3, 0, 0])
        self.assertEqual(dnas.schedule(0x80000321), [1, 2, 3, 0, 0])
        self.assertEqual(dnas.schedule(0x2000004D), [5, 4])
        self.assertEqual(len(dnas.schedule(0xF7654321)), 7)

    def test_second_k2_reverses_the_schedule(self):
        self.assertEqual(dnas.second_k2(0x50CA7FBF), 0x50CFBF7A)
        self.assertEqual(dnas.second_k2(0x4157528D), 0x4157D825)
        rng = random.Random(2)
        for _ in range(200):
            k2 = rng.getrandbits(32)
            e = dnas.second_k2(k2)
            self.assertEqual(dnas.schedule(e), dnas.schedule(k2)[::-1])
            self.assertEqual(dnas.second_k2(e), k2)
            n = 4 * len(dnas.schedule(k2))
            self.assertEqual(e >> n, k2 >> n)

    def test_round_trip(self):
        # decrypting with a record's k2 undoes encrypting with the second record's k2e
        rng = random.Random(3)
        for _ in range(100):
            k2 = rng.getrandbits(32)
            words = [rng.getrandbits(32) for _ in range(rng.randrange(0, 40))]
            skip = [i for i in range(len(words)) if rng.random() < 0.2]
            stored = dnas.encrypt(words, dnas.second_k2(k2), skip)
            self.assertEqual(dnas.decrypt(stored, k2, skip), words)
            self.assertEqual(dnas.encrypt(dnas.decrypt(stored, k2, skip), dnas.second_k2(k2), skip), stored)
            for i in skip:
                self.assertEqual(stored[i], words[i])

    def test_encrypt_changes_what_is_not_skipped(self):
        words = [0x3C020046, 0x92030000, 0xA0434634]
        out = dnas.encrypt(words, 0x50CFBF7A, [0, 2])
        self.assertEqual(out[0], words[0])
        self.assertEqual(out[2], words[2])
        self.assertNotEqual(out[1], words[1])
        self.assertEqual(dnas.encrypt([], 0x12345678), [])

    def test_records(self):
        r1, r2 = dnas.records(0x50CA7FBF, 0x9413EE4E, 0xC)
        self.assertEqual(r1, [0, 0x50CA7FBF, 0x9413EE4E, 0x50CA7FB3, 0])
        self.assertEqual(r2, [0x50CFBF7A, 0x9413EE4F, 0x50CFBF76, 0])
        self.assertEqual(dnas.records(0, 0, 0x58), ([0, 0, 0, 0x58, 0], [0, 1, 0x58, 0]))


class FinderTest(unittest.TestCase):
    def test_finds_a_blank_block(self):
        words = [0x27BDFFF0, 0xFFBF0008] + blank(3) + [0x03E00008, 0x27BD0010]
        (b,) = dnas.find_blocks(words)
        self.assertEqual((b.stub, b.start, b.end, b.k2, b.k3), (2, 15, 18, 0, 0))
        self.assertTrue(dnas.is_blank(b))

    def test_finds_several_and_an_empty_one(self):
        words = [1, 2] + blank(5) + [3] + blank(0) + [4, 5, 6] + blank(1)
        found = dnas.find_blocks(words)
        self.assertEqual([b.end - b.start for b in found], [5, 0, 1])
        self.assertEqual(found[1].stub, 2 + len(blank(5)) + 1)

    def test_finds_a_protected_block(self):
        words = blank(4)
        out = dnas.protect_words(words, set(), {dnas.BEFORE: row()})
        (b,) = dnas.find_blocks(out)
        self.assertEqual((b.k2, b.k3), (0x50CA7FBF, 0x9413EE4E))
        self.assertEqual(b.before, row().before)
        self.assertEqual(b.after, row().after)
        self.assertFalse(dnas.is_blank(b))

    def test_not_a_block(self):
        good = blank(3)
        self.assertEqual(len(dnas.find_blocks(good)), 1)
        for at, value in ((1, 4),                 # no nop after the b
                          (8, 1),                 # a flag word that is not 0
                          (12, 1),                # the record's last word
                          (10, 1),                # an odd k3
                          (11, 0x10),             # another length: the second stub is not there
                          (16, 0x1000000C),       # the second b
                          (17, 5),                # its nop
                          (25, 0),                # the second record's k3 without bit 0
                          (26, 0x10),             # its length
                          (27, 9)):               # its last word
            words = list(good)
            words[at] = value
            self.assertEqual(dnas.find_blocks(words), [], at)
        self.assertEqual(dnas.find_blocks(good[:-1]), [])
        self.assertEqual(dnas.find_blocks([dnas.B_BLOCK, 0]), [])
        self.assertEqual(dnas.find_blocks([]), [])

    def test_block_at(self):
        words = [7] + blank(2)
        self.assertIsNone(dnas.block_at(words, 0))
        self.assertIsNone(dnas.block_at(words, -1))
        self.assertEqual(dnas.block_at(words, 1).start, 1 + dnas.BEFORE)


class ProtectWordsTest(unittest.TestCase):
    def test_fills_and_encrypts(self):
        body = [0x3C020046, 0x92030000, 0xA0434634]
        words = [0x11111111] + blank(3, body) + [0x22222222]
        s = 1 + dnas.BEFORE
        r = row()
        out = dnas.protect_words(words, {s, s + 2}, {s: r})
        self.assertEqual(len(out), len(words))
        self.assertEqual(out[0], 0x11111111)
        self.assertEqual(out[-1], 0x22222222)
        self.assertEqual(out[1:3], [dnas.B_BLOCK, 0])
        self.assertEqual(tuple(out[3:9]), r.before)
        self.assertEqual(out[9:14], [0, r.k2, r.k3, r.k2 ^ 0xC, 0])
        k2e = dnas.second_k2(r.k2)
        # the relocated words stay as they are: the linker fills them in later
        self.assertEqual(out[s], body[0])
        self.assertEqual(out[s + 2], body[2])
        self.assertEqual(out[s + 1], dnas.encrypt([body[1]], k2e)[0])
        e = s + 3
        self.assertEqual(out[e:e + 2], [dnas.B_AFTER, 0])
        self.assertEqual(tuple(out[e + 2:e + 8]), r.after)
        self.assertEqual(out[e + 8:e + 12], [k2e, r.k3 | 1, k2e ^ 0xC, 0])
        # what the driver does at run time gives the compiled words back
        self.assertEqual(dnas.decrypt(out[s:e], r.k2, [0, 2]), body)

    def test_a_relocation_outside_the_block_changes_nothing(self):
        words = blank(2)
        s = dnas.BEFORE
        self.assertEqual(dnas.protect_words(words, {0, 3, s + 2, s + 5}, {s: row()}),
                         dnas.protect_words(words, set(), {s: row()}))

    def test_two_blocks_take_their_own_rows(self):
        words = blank(2) + [5] + blank(1)
        s0, s1 = dnas.BEFORE, len(blank(2)) + 1 + dnas.BEFORE
        r0, r1 = row(k2=0x11111111, k3=0), row(k2=0x7654321F, k3=0x10, block=1)
        out = dnas.protect_words(words, set(), {s0: r0, s1: r1})
        found = dnas.find_blocks(out)
        self.assertEqual([(b.k2, b.k3) for b in found], [(0x11111111, 0), (0x7654321F, 0x10)])

    def test_errors(self):
        words = blank(2)
        with self.assertRaisesRegex(dnas.DnasError, "no row"):
            dnas.protect_words(words, set(), {})
        once = dnas.protect_words(words, set(), {dnas.BEFORE: row()})
        with self.assertRaisesRegex(dnas.DnasError, "protected already"):
            dnas.protect_words(once, set(), {dnas.BEFORE: row()})
        self.assertEqual(dnas.protect_words([1, 2, 3], set(), {}), [1, 2, 3])


class TableTest(unittest.TestCase):
    LINE = ("func_L39_004B4620\t0\t0x70\t0xC\t50CA7FBF\t9413EE4E\t"
            "00000001 00000002 00000003 00000004 00000005 00000006\t"
            "0000000A 0000000B 0000000C 0000000D 0000000E 0000000F")

    def test_parse(self):
        t = dnas.parse_table("# a comment\n\n" + self.LINE + "\n")
        r = t[("func_L39_004B4620", 0)]
        self.assertEqual((r.offset, r.length, r.k2, r.k3), (0x70, 0xC, 0x50CA7FBF, 0x9413EE4E))
        self.assertEqual(r.before, (1, 2, 3, 4, 5, 6))
        self.assertEqual(r.after, (10, 11, 12, 13, 14, 15))

    def test_format_and_parse_again(self):
        rows = [row(function="func_L39_00400100", block=1), row(function="func_L39_00400100", k3=0),
                row(function="func_L39_00400000", k2=1)]
        for v in ("pal", "us"):
            text = dnas.format_table(rows, v)
            self.assertEqual(sorted(dnas.parse_table(text).values()), sorted(rows))
            self.assertTrue(text.startswith("#"))
        self.assertIn("NTSC-U", dnas.format_table(rows, "us"))

    def test_bad_lines(self):
        f = self.LINE.split("\t")
        for change, why in (
                (f[:7], "fields"),
                (f[:6] + ["00000001 00000002", f[7]], "six words"),
                (f[:4] + ["50CA7FB", f[5], f[6], f[7]], "hexadecimal"),
                (f[:4] + ["50ca7fbf", f[5], f[6], f[7]], "hexadecimal"),
                (["4B4620"] + f[1:], "function name"),
                ([f[0], "x"] + f[2:], "line 1"),
                (f[:5] + ["9413EE4F", f[6], f[7]], "even k3"),
                (f[:2] + ["0x71"] + f[3:], "word-aligned"),
                (f[:3] + ["0xE"] + f[4:], "word-aligned")):
            with self.assertRaisesRegex(dnas.DnasError, why):
                dnas.parse_table("\t".join(change) + "\n")
        with self.assertRaisesRegex(dnas.DnasError, "twice"):
            dnas.parse_table(self.LINE + "\n" + self.LINE + "\n")
        with self.assertRaisesRegex(dnas.DnasError, "no block 0"):
            dnas.parse_table(self.LINE.replace("\t0\t0x70", "\t1\t0x70") + "\n")


def elf_object(text_words, relocs, symbols):
    """A small ELF32 little-endian relocatable object: .text, .rel.text (R_MIPS types at byte
    offsets), .symtab/.strtab with `symbols` [(name, value, size)] in .text."""
    strtab = b"\0"
    syms = [struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0), struct.pack("<IIIBBH", 0, 0, 0, 3, 0, 1)]   # null, .text section
    for name, value, size in symbols:
        syms.append(struct.pack("<IIIBBH", len(strtab), value, size, 0x12 if name.startswith("func_") else 0, 0, 1))
        strtab += name.encode() + b"\0"
    shstr = b"\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0"
    text = struct.pack("<%dI" % len(text_words), *text_words)
    rel = b"".join(struct.pack("<II", off, (1 << 8) | kind) for off, kind in relocs)
    blobs = [text, rel, b"".join(syms), strtab, shstr]
    offsets, at = [], 0x34
    for b in blobs:
        offsets.append(at)
        at += len(b) + (-len(b) % 4)
    shoff = at
    name = lambda s: shstr.index(b"\0" + s + b"\0") + 1
    sh = [(0,) * 10,
          (name(b".text"), 1, 6, 0, offsets[0], len(text), 0, 0, 8, 0),
          (name(b".rel.text"), 9, 0, 0, offsets[1], len(rel), 3, 1, 4, 8),
          (name(b".symtab"), 2, 0, 0, offsets[2], len(blobs[2]), 4, 2, 4, 16),
          (name(b".strtab"), 3, 0, 0, offsets[3], len(strtab), 0, 0, 1, 0),
          (name(b".shstrtab"), 3, 0, 0, offsets[4], len(shstr), 0, 0, 1, 0)]
    head = b"\x7fELF\x01\x01\x01" + b"\0" * 9 + struct.pack("<HHIIIIIHHHHHH", 1, 8, 1, 0, 0, shoff, 0, 0x34, 0, 0,
                                                             40, len(sh), 5)
    body = b"".join(b + b"\0" * (-len(b) % 4) for b in blobs)
    return head + body + b"".join(struct.pack("<10I", *s) for s in sh)


class ObjectTest(unittest.TestCase):
    FN = "func_L39_00400000"

    def make(self, words=None, relocs=(), symbols=None, fn=None):
        fn = fn or self.FN
        words = words if words is not None else [0x27BDFFF0] + blank(3) + [0x03E00008, 0x27BD0010]
        s = 4 * (1 + dnas.BEFORE)
        if symbols is None:
            symbols = [(fn, 0, 4 * len(words)), ("dnas_rec_%s_0" % fn, s - 0x14, 0), ("dnas_blk_%s_0" % fn, s, 0),
                       ("dnas_end_%s_0" % fn, s + 12, 0)]
        fd, path = tempfile.mkstemp(suffix=".o")
        os.write(fd, elf_object(words, relocs, symbols))
        os.close(fd)
        self.addCleanup(os.remove, path)
        return path, words

    def text(self, path, n):
        data = open(path, "rb").read()
        off, size = dnas.read_object(data)["text"]
        self.assertEqual(size, 4 * n)
        return list(struct.unpack_from("<%dI" % n, data, off))

    def test_read_object(self):
        path, words = self.make(relocs=[(0x38, 5), (0x40, 6), (0x10, 4)])
        obj = dnas.read_object(open(path, "rb").read())
        self.assertEqual(obj["relocated"], {0x38, 0x40, 0x10})
        self.assertEqual(obj["symbols"][self.FN], (0, 4 * len(words)))
        self.assertEqual(obj["symbols"]["dnas_blk_%s_0" % self.FN][0], 0x38)
        with self.assertRaises(dnas.DnasError):
            dnas.read_object(b"not an object")

    def test_protects_in_place(self):
        s = 1 + dnas.BEFORE
        path, words = self.make(relocs=[(4 * s, 5), (4 * (s + 2), 6), (4, 4)])
        before = open(path, "rb").read()
        r = row(function=self.FN, offset=0x38, length=0xC)
        notes = []
        done = dnas.protect_object(path, {(self.FN, 0): r}, notes=notes)
        self.assertEqual(done, [(self.FN, 0, r)])
        self.assertEqual(notes, [])
        after = open(path, "rb").read()
        self.assertEqual(len(after), len(before))
        self.assertEqual(self.text(path, len(words)), dnas.protect_words(words, {s, s + 2, 1}, {s: r}))
        off, size = dnas.read_object(after)["text"]
        self.assertEqual(after[:off], before[:off])                  # nothing but .text is written
        self.assertEqual(after[off + size:], before[off + size:])
        with self.assertRaisesRegex(dnas.DnasError, "protected already"):
            dnas.protect_object(path, {(self.FN, 0): r})

    def test_the_tables_name(self):
        # NTSC-U's table has the function under its NTSC-U name
        path, words = self.make()
        r = row(function="func_L39_003FFE00")
        with self.assertRaisesRegex(dnas.DnasError, "no row for block 0 of %s" % self.FN):
            dnas.protect_object(path, {("func_L39_003FFE00", 0): r})
        done = dnas.protect_object(path, {("func_L39_003FFE00", 0): r}, name_of=lambda fn: "func_L39_003FFE00")
        self.assertEqual(done, [(self.FN, 0, r)])

    def test_notes_another_place(self):
        path, _ = self.make()
        notes = []
        dnas.protect_object(path, {(self.FN, 0): row(function=self.FN, offset=0x70, length=0x10)}, notes=notes)
        self.assertEqual(notes, ["block 0 of %s: 0xC bytes at +0x38 here, 0x10 at +0x70 in retail" % self.FN])

    def test_an_object_without_blocks_is_left_alone(self):
        path, _ = self.make(words=[1, 2, 3, 4], symbols=[(self.FN, 0, 16)])
        before = open(path, "rb").read()
        self.assertEqual(dnas.protect_object(path, {}), [])
        self.assertEqual(open(path, "rb").read(), before)

    def test_labels_and_blocks_must_agree(self):
        words = [0x27BDFFF0] + blank(3) + [0x03E00008, 0x27BD0010]
        s = 4 * (1 + dnas.BEFORE)
        table = {(self.FN, 0): row(function=self.FN), ("func_L39_00400100", 0): row(function="func_L39_00400100")}
        path, _ = self.make(words, symbols=[(self.FN, 0, 4 * len(words))])
        with self.assertRaisesRegex(dnas.DnasError, "no dnas_blk_ label"):
            dnas.protect_object(path, table)
        # a block that is protected and has no label is a function still in assembly: left alone
        stored = dnas.protect_words(words, set(), {1 + dnas.BEFORE: row()})
        both = stored + [0, 0] + words
        s2 = 4 * (len(stored) + 2) + s
        path, _ = self.make(both, symbols=[("func_L39_003FFF00", 0, 4 * len(stored)),
                                           (self.FN, 4 * (len(stored) + 2), 4 * len(words)),
                                           ("dnas_blk_%s_0" % self.FN, s2, 0)])
        self.assertEqual(len(dnas.protect_object(path, table)), 1)
        got = self.text(path, len(both))
        self.assertEqual(got[:len(stored)], stored)
        self.assertEqual(got[len(stored) + 2:], dnas.protect_words(words, set(), {1 + dnas.BEFORE: row(function=self.FN)}))
        path, _ = self.make(words, symbols=[(self.FN, 0, 4 * len(words)), ("dnas_blk_%s_0" % self.FN, s, 0),
                                            ("dnas_blk_%s_1" % self.FN, s + 0x100, 0)])
        with self.assertRaisesRegex(dnas.DnasError, "not a whole block"):
            dnas.protect_object(path, table)
        # the label names another function than the one the block is in
        path, _ = self.make(words, symbols=[(self.FN, 0, 4 * len(words)), ("func_L39_00400100", 0x400, 8),
                                            ("dnas_blk_func_L39_00400100_0", s, 0)])
        with self.assertRaisesRegex(dnas.DnasError, "not inside func_L39_00400100"):
            dnas.protect_object(path, table)

    def test_has_blocks(self):
        self.assertTrue(dnas.has_blocks("\tla\t$3,dnas_rec_f_0\ndnas_blk_f_0:\n"))
        self.assertFalse(dnas.has_blocks("\tjal\tfunc_L39_004BD350\n"))


if __name__ == "__main__":
    unittest.main()
