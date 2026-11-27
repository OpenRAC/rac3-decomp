"""Unit tests for tools/xgame_index.py, on synthetic MIPS words (no game data, no numpy needed).

  python3 -m unittest discover -s tests
"""
import os
import struct
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import xgame_index as xi  # noqa: E402

SP, RA, AT = 29, 31, 1


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def r_type(fn, rs=0, rt=0, rd=0):
    return (rs << 21) | (rt << 16) | (rd << 11) | fn


def addiu(rt, rs, imm):
    return i_type(0x09, rs, rt, imm)


def lui(rt, imm):
    return i_type(0x0F, 0, rt, imm)


def lw(rt, off, base):
    return i_type(0x23, base, rt, off)


def sw(rt, off, base):
    return i_type(0x2B, base, rt, off)


def sd(rt, off, base):
    return i_type(0x3F, base, rt, off)


def sq(rt, off, base):
    return i_type(0x1F, base, rt, off)


def ld(rt, off, base):
    return i_type(0x37, base, rt, off)


def lq(rt, off, base):
    return i_type(0x1E, base, rt, off)


def mtc1(rt, fs):
    return (0x11 << 26) | (4 << 21) | (rt << 16) | (fs << 11)


def jal(target):
    return (0x03 << 26) | ((target >> 2) & 0x03FFFFFF)


def beq(rs, rt, off):
    return i_type(0x04, rs, rt, off)


def bnel(rs, rt, off):
    return i_type(0x15, rs, rt, off)


def bne(rs, rt, off):
    return i_type(0x05, rs, rt, off)


def daddu(rd, rs, rt):
    return r_type(0x2D, rs, rt, rd)


def jr(rs):
    return r_type(0x08, rs)


NOP = 0


def routine(s0=16, s1=17, callee=0x00200000, glob=0x1D, frame=0x40, save=sd, load=ld, likely=False):
    """One small routine: a frame, a float constant passed to a call, a loop, a field store."""
    br = bnel if likely else bne
    return [
        addiu(SP, SP, -frame),
        save(s0, 0x10, SP),
        save(RA, 0x20, SP),
        daddu(s0, 4, 0),                 # move s0, a0
        lui(AT, 0x3F80),                 # 1.0f
        mtc1(AT, 12),
        daddu(4, s0, 0),
        jal(callee),
        addiu(5, 0, 0x64),               # li a1, 100 (delay slot)
        lui(s1, glob),                   # an address %hi
        lw(2, 0x1230, s1),               # its %lo
        sw(2, 0x48, s0),                 # a field
        addiu(2, 2, -1),
        br(2, 0, -3),
        NOP,
        load(RA, 0x20, SP),
        load(s0, 0x10, SP),
        jr(RA),
        addiu(SP, SP, frame),
    ]


def code(words):
    return struct.pack("<%dI" % len(words), *words)


class Fingerprints(unittest.TestCase):
    def test_tokens(self):
        self.assertEqual(xi.decode(NOP)[0], "nop")
        self.assertEqual(xi.decode(daddu(16, 4, 0))[0], "mov")
        self.assertEqual(xi.decode(addiu(5, 0, 7))[0], "li")
        self.assertEqual(xi.decode(sd(16, 0, SP))[0], "sps")
        self.assertEqual(xi.decode(sq(16, 0, SP))[0], "sps")
        self.assertEqual(xi.decode(jr(RA))[1], "ret")
        self.assertEqual(xi.decode(bnel(2, 0, 4))[0], "bne")        # likely folded
        self.assertEqual(xi.decode(beq(0, 0, 4))[1], ("B", 4))

    def test_survives_registers_addresses_and_widths(self):
        a = xi.fingerprint(code(routine()), 0x00300000)
        b = xi.fingerprint(code(routine(s0=18, s1=19, callee=0x00412340, glob=0x22, save=sq, load=lq,
                                        likely=True)), 0x00500000)
        for k in ("ops", "cfg", "calls", "consts", "offs", "frame"):
            self.assertEqual(a[k], b[k], k)
        total, parts = xi.similarity(a, b)
        self.assertGreater(total, 0.99)

    def test_features(self):
        f = xi.fingerprint(code(routine()), 0x00300000)
        self.assertEqual(f["frame"], 0x40)
        self.assertIn("f3F80", f["consts"])
        self.assertIn("i100", f["consts"])
        self.assertIn("w48", f["offs"])
        self.assertNotIn("w1230", f["offs"])                    # a relocated %lo is not a field
        self.assertEqual(f["calls"], ["c2.1"])                  # a0 a1 and f12 set before the call
        self.assertIn("bne<", f["ops"])
        self.assertTrue(any(c.startswith("cb") for c in f["cfg"]))     # the loop's back edge

    def test_masked_key_ignores_relocations(self):
        a = xi.fingerprint(code(routine()), 0)
        b = xi.fingerprint(code(routine(callee=0x00123450, glob=0x30)), 0)
        c = xi.fingerprint(code(routine(s0=18)), 0)
        self.assertEqual(a["key"], b["key"])
        self.assertNotEqual(a["key"], c["key"])                 # registers stay in the key

    def test_different_code_scores_low(self):
        a = xi.fingerprint(code(routine()), 0)
        other = [addiu(SP, SP, -0x100)] + [sw(i % 8 + 2, 4 * i, 4) for i in range(30)] + [jr(RA), NOP]
        total, _ = xi.similarity(a, xi.fingerprint(code(other), 0))
        self.assertLess(total, 0.5)

    def test_minhash_is_stable(self):
        ops = xi.fingerprint(code(routine()), 0)["ops"]
        self.assertEqual(xi.minhash(ops), xi.minhash(list(ops)))
        self.assertEqual(len(xi.minhash(ops)), xi.NHASH)


class AsmFiles(unittest.TestCase):
    def test_both_comment_styles(self):
        words = routine()
        with tempfile.TemporaryDirectory() as d:
            p3 = os.path.join(d, "func_00300000.s")       # rac1/rac3: /* rom vaddr BYTES */
            p2 = os.path.join(d, "func_00300000_4.s")     # rac4: /* vaddr WORD */
            with open(p3, "w") as f:
                f.write(".align 3\nnonmatching func_00300000, 0x4C\n\nglabel func_00300000\n")
                for i, w in enumerate(words):
                    if i == 3:
                        f.write("    .word 0x%08X /* move */\n" % w)
                    else:
                        f.write("    /* %X %08X %s */  op\n" % (0x1000 + 4 * i, 0x300000 + 4 * i,
                                                              struct.pack("<I", w).hex().upper()))
                f.write("endlabel func_00300000\nglabel func_00300050\n    /* 0 00300050 00000000 */ nop\n")
            with open(p2, "w") as f:
                f.write("/* main .text 0x00300000 */\nglabel func_00300000\n")
                for i, w in enumerate(words):
                    f.write("/* %X %08X */ op\n" % (0x300000 + 4 * i, w))
            for p in (p3, p2):
                b, va = xi.read_asm(p)
                self.assertEqual(b, code(words), p)
                self.assertEqual(va, 0x300000, p)


class IndexQueries(unittest.TestCase):
    def test_rank(self):
        def item(i, game, name, words, matched):
            f = xi.fingerprint(code(words), 0x00300000)
            f["sig"] = xi.minhash(f["ops"])
            return dict(game=game, version="pal", name=name, size=4 * len(words), va=0x00300000, level="",
                        matched=matched, c="%s.c:1-9" % name if matched else "", s=""), f

        other = [addiu(SP, SP, -0x100)] + [sw(i % 8 + 2, 4 * i, 4) for i in range(30)] + [jr(RA), NOP]
        edited = routine(s0=18, callee=0x00412340)
        edited[12:12] = [addiu(3, 3, 1)]                 # one more instruction
        items = [item(0, "rac3", "func_L01_00300000", routine(), 0),
                 item(1, "rac2", "func_002B2A10", edited, 1),
                 item(2, "rac2", "func_002B3000", other, 1),
                 item(3, "rac4", "func_00450000", routine(likely=True), 0)]
        with tempfile.TemporaryDirectory() as d:
            path = os.path.join(d, "ix.sqlite")
            xi.write_index(path, items)
            ix = xi.Index(path)
            (me,) = ix.find("func_L01_00300000")
            f = ix.row(me)
            res = ix.rank(f, list(ix.sig[me]), 5, exclude=me)
            names = [g["name"] for _, _, g in res]
            self.assertEqual(names[0], "func_00450000")          # the same code, unmatched
            self.assertLess(names.index("func_002B2A10"), names.index("func_002B3000")
                            if "func_002B3000" in names else 99)
            res = ix.rank(f, list(ix.sig[me]), 5, matched_only=True, exclude=me)
            self.assertEqual(res[0][2]["name"], "func_002B2A10")
            self.assertGreater(res[0][0], 0.8)
            res = ix.rank(f, list(ix.sig[me]), 5, matched_only=True, exclude=me, games=["rac4"])
            self.assertEqual(res, [])
            self.assertEqual(ix.find("rac2:func_002B2A10"), [1])


if __name__ == "__main__":
    unittest.main()
