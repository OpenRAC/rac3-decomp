"""Unit tests for tools/fcheck.py's pieces that need no game data: retail's basic blocks and their
coverage, the references retail's code forms, and the gate column it writes into
nonmatching/functional.tsv (the rest of the table untouched).

  python3 -m unittest discover -s tests
"""
import os
import struct
import sys
import tempfile
import importlib.util
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


class VectorUnitReferences(unittest.TestCase):
    def test_lqc2_and_sqc2_form_addresses(self):
        lqc2 = i_type(0x36, V0, 1, 0x16D0)    # lqc2 vf1, 0x16D0(v0): 0x1E16D0
        sqc2 = i_type(0x3E, GP, 2, -0x20)     # sqc2 vf2, -0x20(gp)
        lui = i_type(0x0F, 0, V0, 0x1E)
        refs = fcheck.retail_references(code(lui, lqc2, sqc2, JR_RA, NOP), 0x300000, 0x1DC8B0)
        self.assertEqual(refs, {0x1E16D0, 0x1DC890})


class SmallDataUnderG0(unittest.TestCase):
    """A -G0 rebuild's $gp-relative reference to an extern the C puts in .sdata holds its offset
    less the object's $gp (as a local's does); place() must add it back for a global too."""

    def object_with_gprel_to_a_global(self, d, addend):
        # a minimal MIPS ELF: .text (lw a0, ADDEND(gp); jr ra; nop), .reginfo with gp0 0x4000, a
        # symbol table with the undefined global D_001DC880_sda, and one R_MIPS_GPREL16 against it
        text = code(LW_A0_GP & 0xFFFF0000 | (addend & 0xFFFF), JR_RA, NOP)
        reginfo = bytes(20) + struct.pack("<I", 0x4000)
        strtab = b"\0D_001DC880_sda\0func_L01_00300000\0"
        shstr = b"\0.text\0.reginfo\0.symtab\0.strtab\0.rel.text\0.shstrtab\0"
        sym0 = bytes(16)
        sym1 = struct.pack("<IIIBBH", 1, 0, 0, 0x10, 0, 0)    # STB_GLOBAL, STT_NOTYPE, SHN_UNDEF
        sym2 = struct.pack("<IIIBBH", 16, 0, len(text), 0x12, 0, 1)    # the function, in .text
        symtab = sym0 + sym1 + sym2
        rel = struct.pack("<II", 0, (1 << 8) | 7)
        blobs = [text, reginfo, symtab, strtab, rel, shstr]
        off, at = [], 52
        for b in blobs:
            at = (at + 3) & ~3
            off.append(at)
            at += len(b)
        shoff = (at + 3) & ~3
        names = [shstr.index(n) for n in (b".text", b".reginfo", b".symtab", b".strtab", b".rel.text", b".shstrtab")]
        # name, type, flags, addr, offset, size, link, info, addralign, entsize
        heads = [bytes(40),
                 struct.pack("<10I", names[0], 1, 6, 0, off[0], len(text), 0, 0, 4, 0),
                 struct.pack("<10I", names[1], 0x70000006, 2, 0, off[1], len(reginfo), 0, 0, 4, 24),
                 struct.pack("<10I", names[2], 2, 0, 0, off[2], len(symtab), 4, 1, 4, 16),
                 struct.pack("<10I", names[3], 3, 0, 0, off[3], len(strtab), 0, 0, 1, 0),
                 struct.pack("<10I", names[4], 9, 0, 0, off[4], len(rel), 3, 1, 4, 8),
                 struct.pack("<10I", names[5], 3, 0, 0, off[5], len(shstr), 0, 0, 1, 0)]
        ehdr = (b"\x7fELF\x01\x01\x01" + bytes(9)
                + struct.pack("<HHIIIIIHHHHHH", 1, 8, 1, 0, 0, shoff, 0, 52, 0, 0, 40, len(heads), 6))
        image = bytearray(ehdr)
        for o, b in zip(off, blobs):
            image += bytes(o - len(image)) + b
        image += bytes(shoff - len(image)) + b"".join(heads)
        path = os.path.join(d, "cand.o")
        open(path, "wb").write(image)
        return path

    def placed_reference(self, addend, g0):
        saved = fcheck.use_target, fcheck.level_value, fcheck.level_gp
        fcheck.use_target = lambda program: None
        fcheck.level_value = lambda name, level, fn, optional=False: 0x1DC880
        fcheck.level_gp = lambda level: 0x1DC8B0
        try:
            with tempfile.TemporaryDirectory() as d:
                obj = self.object_with_gprel_to_a_global(d, addend)
                image, entry, refs = fcheck.place(obj, "func_L01_00300000", "level_01", [], 1, g0=g0)
        finally:
            fcheck.use_target, fcheck.level_value, fcheck.level_gp = saved
        return refs, struct.unpack_from("<I", image, 0)[0] & 0xFFFF

    @unittest.skipUnless(importlib.util.find_spec("elftools"), "fcheck.place needs pyelftools")
    def test_a_g0_object_links_the_global_where_its_name_is(self):
        self.assertEqual(self.placed_reference(-0x4000, True), ([0x1DC880], 0xFFD0))

    @unittest.skipUnless(importlib.util.find_spec("elftools"), "fcheck.place needs pyelftools")
    def test_without_g0_the_addend_is_the_offset_alone(self):
        self.assertEqual(self.placed_reference(0, False), ([0x1DC880], 0xFFD0))


class LiteralSlots(unittest.TestCase):
    """An sda name in a level function's C is written for its home level; a literal slot moves
    from level to level, so it is read where the same retail instruction reads in each."""

    def test_the_slot_moves_as_retail_code_moves_it(self):
        saved = (fcheck.catalogue, fcheck.level_names, fcheck.address_map, fcheck.level_lits)

        class Names:
            def __init__(self, gp):
                self.gp = gp

            def expected(self, name):
                return self.gp + int(name[2:10], 16) - 0x1DC8B0

        fcheck.catalogue = lambda: {"func_L01_00300000": (8, {1: 0x300000, 2: 0x310000})}
        fcheck.level_names = lambda level: Names(0x1DC8B0)
        fcheck.address_map = lambda fn, a, b: {0x1DC7E0: 0x1DC6F4} if (a, b) == (1, 2) else {}
        fcheck.level_lits = lambda level: [(0x1DC000, bytes(0x1000))]
        try:
            self.assertEqual(fcheck.sda_level_value("D_001DC7E0_sda", 2, "func_L01_00300000"), 0x1DC6F4)
            self.assertEqual(fcheck.sda_level_value("D_001DC7E0_sda", 1, "func_L01_00300000"), 0x1DC7E0)
            # retail never reads the slot: a literal found by its bytes in the level's pools
            fcheck.address_map = lambda fn, a, b: {}
            pool = bytearray(0x1000)
            pool[0x7E0:0x7E4] = struct.pack("<f", 0.1375)
            other = bytearray(0x1000)
            other[0x6F4:0x6F8] = struct.pack("<f", 0.1375)
            fcheck.level_lits = lambda level: [(0x1DC000, bytes(pool if level == 1 else other))]
            self.assertEqual(fcheck.sda_level_value("D_001DC7E0_sda", 2, "func_L01_00300000"), 0x1DC6F4)
        finally:
            fcheck.catalogue, fcheck.level_names, fcheck.address_map, fcheck.level_lits = saved


class FloatUlps(unittest.TestCase):
    def test_one_ulp_is_named(self):
        out = fcheck.mark_ulps("    word at 001dc000: ours 3e0ccccd, retail 3e0cccce (before 0)\n"
                               "    word at 001dc004: ours 00000000, retail 00000001 (before 0)")
        first, second = out.splitlines()
        self.assertIn(fcheck.ULP_NOTE, first)
        self.assertNotIn(fcheck.ULP_NOTE, second)

    def test_the_gate_cell_says_so(self):
        cell = fcheck.gate_cell({"status": "differs", "states": "1/1", "blocks": "2/2", "unrun": "",
                                 "refs": "", "ulp": True, "text": []})
        self.assertEqual(cell, "differs 2/2 blocks, 1/1 states; float constant one ulp off")


class Fuzz(unittest.TestCase):
    def test_a_state_reads_and_writes_back(self):
        regs = bytearray(range(256)) * 5
        regs = regs[:fcheck.SNAP_REGS]
        ram = bytearray(64)
        blocks = [(len(ram), b""), (4, __import__("zlib").compress(b"spad")), (2, __import__("zlib").compress(b"mi")),
                  (2, __import__("zlib").compress(b"da"))]
        with tempfile.TemporaryDirectory() as d:
            path = os.path.join(d, "s.snap")
            ram[8:12] = b"\x01\x02\x03\x04"
            fcheck.set_gpr(regs, 4, 0x80001000)
            fcheck.set_fpr(regs, 12, 1.5)
            fcheck.write_state(path, regs, blocks, ram)
            got, back = fcheck.read_state(path)
            self.assertEqual(fcheck.get_gpr(got, 4), 0x80001000)
            self.assertEqual(struct.unpack_from("<q", got, 4 + 16 * 4)[0], -0x7FFFF000)   # sign-extended
            self.assertEqual(struct.unpack_from("<f", got, 4 + 512 + 48)[0], 1.5)
            self.assertEqual(__import__("zlib").decompress(back[0][1]), bytes(ram))
            self.assertEqual(back[1:], blocks[1:])
            self.assertEqual(fcheck.state_sp(path), fcheck.get_gpr(got, 29))

    def test_branch_constants_are_the_edges(self):
        slti = i_type(0x0A, A0, V0, 10)          # slti v0, a0, 10
        andi = i_type(0x0C, A0, V0, 0x80)        # andi v0, a0, 0x80
        li = i_type(0x09, ZERO, V0, -3)          # li v0, -3
        got = fcheck.branch_constants(code(slti, andi, li, ADDIU_V0_1))
        self.assertEqual(got, [-4, -3, -2, 0, 1, 2, 9, 10, 11, 0x7F, 0x80, 0x81])

    def test_live_objects_are_records_whose_update_is_the_function(self):
        ram = bytearray(0x400)
        struct.pack_into("<I", ram, 0x200 + 0x64, 0x00312345)
        struct.pack_into("<I", ram, 0x108, 0x00312345)     # not at a record's +0x64
        self.assertEqual(fcheck.live_objects(bytes(ram), 0x00312345), [0x200])

    def test_live_mobys_of_any_class_one_of_each(self):
        ram = bytearray(0x200000)
        for at, update in ((0x150000, 0x300000), (0x150100, 0x300000), (0x150200, 0x310000)):
            struct.pack_into("<I", ram, at + 0x64, update)
            struct.pack_into("<I", ram, at + 0x24, 0x180000)
            struct.pack_into("<f", ram, at + 0x2C, 1.0)
        struct.pack_into("<I", ram, 0x160000 + 0x64, 0x320000)    # scale 0: no moby
        struct.pack_into("<I", ram, 0x160000 + 0x24, 0x180000)
        got = fcheck.any_objects(bytes(ram), frozenset({0x300000, 0x310000, 0x320000}))
        self.assertEqual(got, [0x150000, 0x150200])

    def test_made_up_values_that_hit_the_stack_or_misalign_are_left_out(self):
        sp = 0x01FFF000
        self.assertTrue(fcheck.stack_only("x: DIFFERS\n    does not keep $s0 (1, was 2)\n"
                                          "    word at 01ffeff0: ours 0, retail 1 (before 0)\n", sp))
        self.assertTrue(fcheck.stack_only("    3 misaligned loads or stores (the console raises an address error), retail 0\n"
                                          "    word at 00100000: ours 0, retail 1 (before 0)\n", sp))
        self.assertTrue(fcheck.stack_only("    outside memory, step 0: ours [r 021608c2 4 0], retail [r 021608c6 4 0] "
                                          "(r read, w write, s system call)\n", sp))
        self.assertFalse(fcheck.stack_only("    word at 00100000: ours 0, retail 1 (before 0)\n", sp))
        self.assertTrue(fcheck.stack_only("    before call 5 (to 004cb128): word at 0022042c ours 01ffefa8, retail 01ffefb8\n", sp))
        self.assertFalse(fcheck.stack_only("    returns 1, retail 0\n", sp))
        self.assertFalse(fcheck.stack_only("    outside memory, step 0: ours [w 1000d420 3 4], retail [r 1000d400 4 0]\n", sp))

    def test_the_fuzz_verdict_is_its_own_word(self):
        c = code(BEQZ_A0_2, NOP, ADDIU_V0_1, JR_RA, NOP)
        f = fcheck.fuzz_result({"same": 6, "astray": 2}, [True, True, True, True, True], [True, True, False, True, True],
                               c, 0x300000, [])
        self.assertEqual((f["status"], f["blocks"], f["new"], f["states"]), ("same-fuzz", "3/3", 1, "6/8"))
        cell = fcheck.gate_cell({"status": "no-states", "states": "0", "blocks": "", "unrun": "", "refs": "",
                                 "fuzz": f, "text": ["no states of x"]})
        self.assertEqual(cell, "same-fuzz 3/3 blocks (+1), 6/8 fuzz states")
        cell = fcheck.gate_cell({"status": "same-partial", "states": "1/1", "blocks": "2/3", "unrun": "00300008-00300008",
                                 "refs": "", "fuzz": f, "text": []})
        self.assertEqual(cell, "same-partial 2/3 blocks, 1/1 states (unrun: 00300008-00300008); "
                               "fuzz: same-fuzz 3/3 blocks (+1), 6/8 fuzz states")
        self.assertTrue(fcheck.with_states(cell) and fcheck.with_states("differs-fuzz 1/2 blocks (+1), 1/1 fuzz states"))
        self.assertEqual(fcheck.fuzz_word({"differs": 1, "same": 5}), "differs-fuzz")
        self.assertEqual(fcheck.fuzz_word({"skipped": 3, "astray": 1}), "skipped-fuzz")


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
            fcheck.check = lambda name, candidate, program=None, fuzz=0: {
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
