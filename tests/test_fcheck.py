"""Unit tests for tools/fcheck.py's pieces that need no game data: retail's basic blocks and their
coverage, the references retail's code forms, and the gate column it writes into
nonmatching/functional.tsv (the rest of the table untouched).

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

import fcheck  # noqa: E402

ZERO, V0, A0, GP, RA = 0, 2, 4, 28, 31
NOP = 0


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def code(*words):
    return struct.pack("<%dI" % len(words), *words)


JR_RA = (RA << 21) | 8
BEQZ_A0_2 = i_type(4, A0, ZERO, 2)       # beqz a0, +2 (to the jr)
ADDIU_V0_1 = i_type(9, ZERO, V0, 1)
LUI_V0_1D = i_type(0x0F, 0, V0, 0x1D)
LW_A0_LO = i_type(0x23, V0, A0, 0x5520)    # lw a0, 0x5520(v0): 0x1D5520
LW_A0_GP = i_type(0x23, GP, A0, -0x10)


class Blocks(unittest.TestCase):
    def test_a_branch_splits_the_function(self):
        c = code(BEQZ_A0_2, NOP, ADDIU_V0_1, JR_RA, NOP)
        self.assertEqual(fcheck.blocks(c, 0x100000), [(0, 2), (2, 3), (3, 5)])

    def test_coverage_names_the_unrun_block(self):
        c = code(BEQZ_A0_2, NOP, ADDIU_V0_1, JR_RA, NOP)
        with tempfile.TemporaryDirectory() as d:
            cov = os.path.join(d, "cover.txt")
            open(cov, "w").write("00100000 5 1 1 11011\n")
            run, total, words, n, ranges = fcheck.coverage(cov, c, 0x100000)
        self.assertEqual((run, total, words, n), (2, 3, 4, 5))
        self.assertEqual(ranges, "00100008-00100008")

    def test_unrun_ranges_in_the_names_own_addresses(self):
        c = code(BEQZ_A0_2, NOP, ADDIU_V0_1, JR_RA, NOP)
        with tempfile.TemporaryDirectory() as d:
            cov = os.path.join(d, "cover.txt")
            open(cov, "w").write("00100000 5 1 1 11011\n")
            ranges = fcheck.coverage(cov, c, 0x100000, shift=-0x100)[4]
        self.assertEqual(ranges, "000FFF08-000FFF08")


class References(unittest.TestCase):
    def test_lui_lo_and_gp(self):
        refs = fcheck.retail_references(code(LUI_V0_1D, LW_A0_LO, LW_A0_GP, JR_RA, NOP), 0x100000, 0x1DC8B0)
        self.assertEqual(refs, {0x1D5520, 0x1DC8A0})


class Levels(unittest.TestCase):
    def test_formed_gives_data_addresses_and_jump_targets_by_word(self):
        jal = (3 << 26) | (0x2F7800 >> 2)
        got = fcheck.formed(code(LUI_V0_1D, LW_A0_LO, jal, NOP, LW_A0_GP), 0x300000, 0x1DC8B0)
        self.assertEqual(got, [(1, 0x1D5520), (2, 0x2F7800), (4, 0x1DC8A0)])

    def test_coverage_of_runs_merged_by_word(self):
        c = code(BEQZ_A0_2, NOP, ADDIU_V0_1, JR_RA, NOP)
        run, total, words, n, ranges = fcheck.coverage(None, c, 0x300000, hits=[True, True, False, True])
        self.assertEqual((run, total, words, n, ranges), (2, 3, 3, 5, "00300008-00300008"))


class Table(unittest.TestCase):
    def test_gate_writes_only_its_column(self):
        text = ("# a comment\n"
                "# name\tfile\tprogram\tdraft\tconfidence\tgate\tworker\twhat it does\n"
                "func_00100000\tnonmatching/functional/func_00100000.c\tboot_elf\tfunctional\thigh\tpending\tw\tx\n"
                "func_00200000\tnonmatching/functional/func_00200000.c\tfrontbin\tfunctional\tlow\tpending\tw\ty\n")
        with tempfile.TemporaryDirectory() as d:
            table = os.path.join(d, "functional.tsv")
            open(table, "w").write(text)
            saved, saved_check = fcheck.TABLE, fcheck.check
            fcheck.TABLE = table
            fcheck.check = lambda name, candidate, program=None: {
                "status": "same-partial", "states": "3/3", "blocks": "2/3", "unrun": "00100008-00100008",
                "refs": "", "text": [program]}
            try:
                fcheck.gate(["func_00100000"], True)
            finally:
                fcheck.TABLE, fcheck.check = saved, saved_check
            lines = open(table).read().splitlines()
        self.assertEqual(lines[:2], text.splitlines()[:2])
        self.assertEqual(lines[2].split("\t")[5], "same-partial 2/3 blocks, 3/3 states (unrun: 00100008-00100008)")
        self.assertEqual(lines[2].split("\t")[:5], text.splitlines()[2].split("\t")[:5])
        self.assertEqual(lines[3], text.splitlines()[3])

    def test_merge_puts_verdict_files_in_the_table(self):
        text = ("# name\tfile\tconfidence\tprogram\tdraft\tgate\tworker\twhat it does\n"
                "func_L01_00300000\tf.c\thigh\tlevels:shared\tfunctional\tpending\tw\tx\n"
                "func_00100000\tg.c\thigh\tboot_elf\tfunctional\tpending\tw\ty\n")
        with tempfile.TemporaryDirectory() as d:
            table, out = os.path.join(d, "functional.tsv"), os.path.join(d, "out.tsv")
            open(table, "w").write(text)
            open(out, "w").write("func_L01_00300000\tlevels:shared\tdiffers 1/2 blocks, 1/1 states\n"
                                 "func_L01_00300000\tlevels:shared\tsame 2/2 blocks, 3/3 states\n")
            saved = fcheck.TABLE
            fcheck.TABLE = table
            try:
                fcheck.merge([out])
            finally:
                fcheck.TABLE = saved
            lines = open(table).read().splitlines()
        self.assertEqual(lines[1].split("\t")[5], "same 2/2 blocks, 3/3 states")
        self.assertEqual(lines[2], text.splitlines()[2])

    def test_same_has_no_unrun_and_refs_are_shown(self):
        cell = fcheck.gate_cell({"status": "same", "states": "2/2", "blocks": "4/4", "unrun": "",
                                 "refs": "001D0560", "text": []})
        self.assertEqual(cell, "same 4/4 blocks, 2/2 states; refs not in retail: 001D0560")


if __name__ == "__main__":
    unittest.main()
