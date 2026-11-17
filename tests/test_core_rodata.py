"""Unit tests for tools/core_rodata.py's search (no toolchain, no game data).

  python3 -m unittest discover -s tests
"""
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import core_rodata as cr  # noqa: E402


def words(*ws):
    return b"".join(struct.pack("<I", w) for w in ws)


class CoreRodataTest(unittest.TestCase):
    def test_filled_jump_table(self):
        # two entries against the file's .text (the words hold the labels' offsets), one against a name
        sec = {"data": words(0x40, 0x88, 0, 0x3F800000),
               "relocs": [(0, cr.R_MIPS_32, "§.text"), (4, cr.R_MIPS_32, "§.text"),
                          (8, cr.R_MIPS_32, "func_00120000")]}
        data, masked = cr.filled(sec, 0x116F80)
        self.assertEqual(data, words(0x116FC0, 0x117008, 0, 0x3F800000))
        self.assertEqual(masked, [8])

    def test_find_once_exact_and_aligned(self):
        seg = [(0x1000, words(1, 2, 3, 4, 1, 2, 3, 4))]
        self.assertEqual(cr.find_once(seg, words(1, 2), 8), [0x1000, 0x1010])
        self.assertEqual(cr.find_once(seg, words(2, 3), 8), [])          # only at 4 mod 8
        self.assertEqual(cr.find_once(seg, words(2, 3), 4), [0x1004, 0x1014])

    def test_find_once_masked(self):
        seg = [(0x2000, words(7, 0xAAAA, 9, 5, 7, 0xBBBB, 8, 5))]
        # the second word may hold anything: the third tells the two places apart
        self.assertEqual(cr.find_once(seg, words(7, 0, 9, 5), 4, masked=[4]), [0x2000])
        self.assertEqual(cr.find_once(seg, words(7, 0, 8, 5), 4, masked=[4]), [0x2010])
        self.assertEqual(cr.find_once(seg, words(7, 0, 0, 5), 4, masked=[4, 8]), [0x2000, 0x2010])


if __name__ == "__main__":
    unittest.main()
