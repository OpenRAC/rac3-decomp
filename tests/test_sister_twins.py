"""Unit tests for tools/twin_mask.py and tools/sister_twins.py, on synthetic MIPS words and C text
(no game data). The mask check against splat's relocations runs only where rac3's asm/ is set up.

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

import sister_twins  # noqa: E402
import twin_mask  # noqa: E402
from twin_mask import masked, strip_padding  # noqa: E402

SP, GP, RA = 29, 28, 31
NOP = 0


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def r_type(fn, rs=0, rt=0, rd=0):
    return (rs << 21) | (rt << 16) | (rd << 11) | fn


def lui(rt, imm):
    return i_type(0x0F, 0, rt, imm)


def lw(rt, off, base):
    return i_type(0x23, base, rt, off)


def sw(rt, off, base):
    return i_type(0x2B, base, rt, off)


def lwc1(ft, off, base):
    return i_type(0x31, base, ft, off)


def addiu(rt, rs, imm):
    return i_type(0x09, rs, rt, imm)


def ori(rt, rs, imm):
    return i_type(0x0D, rs, rt, imm)


def beq(rs, rt, off):
    return i_type(0x04, rs, rt, off)


def addu(rd, rs, rt):
    return r_type(0x21, rs, rt, rd)


def subu(rd, rs, rt):
    return r_type(0x23, rs, rt, rd)


def mtc1(rt, fs):
    return (0x11 << 26) | (0x04 << 21) | (rt << 16) | (fs << 11)


def jal(target):
    return (0x03 << 26) | ((target >> 2) & 0x3FFFFFF)


def j(target):
    return (0x02 << 26) | ((target >> 2) & 0x3FFFFFF)


JR_RA = r_type(0x08, RA)


def code(*words):
    return struct.pack("<%dI" % len(words), *words)


def kept(words):
    """The positions masked() leaves unchanged."""
    return [x == y for x, y in zip(words, masked(code(*words)))]


class MaskTest(unittest.TestCase):
    def test_jal_and_j_lose_their_target(self):
        w = [jal(0x00123450), NOP, j(0x00200000), NOP]
        self.assertEqual(masked(code(*w)), (0x0C000000, NOP, 0x08000000, NOP))

    def test_branch_offsets_and_registers_are_kept(self):
        w = [beq(4, 5, 3), NOP, addiu(2, 0, 7), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_lui_feeding_a_load_base_is_masked(self):
        w = [lui(2, 0x0040), lw(3, 0x1234, 2), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), (lui(2, 0), lw(3, 0, 2), JR_RA, NOP))

    def test_lui_feeding_a_store_base_and_an_addiu_is_masked(self):
        w = [lui(4, 0x0041), sw(5, -0x7000, 4), lui(6, 0x0042), addiu(6, 6, 0x10), JR_RA, NOP]
        self.assertEqual(kept(w), [False, False, False, False, True, True])

    def test_lui_feeding_an_fpu_load_is_masked(self):
        w = [lui(2, 0x0043), lwc1(0, 0x20, 2), JR_RA, NOP]
        self.assertEqual(kept(w), [False, False, True, True])

    def test_lui_reaches_the_base_through_addu(self):
        w = [lui(2, 0x0040), addu(2, 2, 4), lw(3, 0x5678, 2), JR_RA, NOP]
        self.assertEqual(kept(w), [False, True, False, True, True])

    def test_lui_for_mtc1_is_a_constant(self):
        w = [lui(1, 0x3F80), mtc1(1, 0), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_lui_with_ori_is_a_constant(self):
        w = [lui(2, 0x1234), ori(2, 2, 0x5678), sw(2, 0x8, 4), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_lui_feeding_only_arithmetic_is_kept(self):
        w = [lui(2, 0x0010), subu(3, 3, 2), addu(4, 5, 2), sw(3, 0x10, SP), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_lui_overwritten_before_the_use_is_kept(self):
        w = [lui(2, 0x0040), addiu(2, 0, 5), lw(3, 0x8, 2), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_gp_relative_immediates_are_masked(self):
        w = [lw(2, -0x7FF0, GP), addiu(3, GP, 0x10), sw(2, 0x14, GP), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), (lw(2, 0, GP), addiu(3, GP, 0), sw(2, 0, GP), JR_RA, NOP))

    def test_struct_and_stack_offsets_are_kept(self):
        w = [lw(2, 0x18, 4), sw(2, 0x10, SP), addiu(SP, SP, -0x20), JR_RA, NOP]
        self.assertEqual(masked(code(*w)), tuple(w))

    def test_hi_followed_across_a_branch(self):
        # the lui is in the branch's delay slot; its %lo use is past the join
        w = [beq(4, 0, 2), lui(2, 0x0040), addiu(5, 5, 1), NOP, lw(3, 0x1234, 2), JR_RA, NOP]
        self.assertEqual(kept(w), [True, False, True, True, False, True, True])

    def test_hi_on_one_path_reaches_the_join(self):
        # the branch skips the lui; the lw after the join may still read its value
        w = [beq(4, 0, 2), NOP, lui(2, 0x0040), lw(3, 0x1234, 2), JR_RA, NOP]
        self.assertEqual(kept(w), [True, True, False, False, True, True])

    def test_a_call_clobbers_caller_saved_hi_registers(self):
        w = [lui(2, 0x0040), jal(0x00100000), NOP, lw(3, 0x4, 2), JR_RA, NOP]
        self.assertEqual(kept(w), [True, False, True, True, True, True])
        w = [lui(16, 0x0040), jal(0x00100000), NOP, lw(3, 0x4, 16), JR_RA, NOP]
        self.assertEqual(kept(w), [False, False, True, False, True, True])

    def test_copies_with_other_relocations_are_equal(self):
        a = code(lui(2, 0x0040), lw(3, 0x1234, 2), jal(0x00100000), lw(4, 0x8, GP), JR_RA, NOP)
        b = code(lui(2, 0x0051), lw(3, -0x10, 2), jal(0x00234560), lw(4, -0x40, GP), JR_RA, NOP)
        c = code(lui(2, 0x0040), lw(3, 0x1234, 2), jal(0x00100000), lw(4, 0x8, 5), JR_RA, NOP)
        self.assertEqual(masked(a), masked(b))
        self.assertNotEqual(masked(a), masked(c))       # another base register

    def test_empty_code(self):
        self.assertEqual(masked(b""), ())

    def test_strip_padding(self):
        self.assertEqual(strip_padding((JR_RA, NOP, NOP, NOP)), (JR_RA,))
        self.assertEqual(strip_padding((JR_RA, NOP, 1, NOP)), (JR_RA, NOP, 1))
        self.assertEqual(strip_padding((NOP, NOP)), (NOP,))


class AsmAnnotationTest(unittest.TestCase):
    ASM = [
        "glabel func_00100000\n",
        "    /* 1000 00100000 4000023C */  lui        $2, %hi(D_00400000)\n",
        "    /* 1004 00100004 3412438C */  lw         $3, %lo(D_00401234)($2)\n",
        "    /* 1008 00100008 10F0828F */  lw         $2, %gp_rel(D_x)($28)\n",
        "    /* 100C 0010000C 0010043C */  lui        $4, (0x10001000 >> 16)\n",
        "    /* 1010 00100010 0000040C */  jal        func_00100000\n",
        "    /* 1014 00100014 0800E003 */  jr         $31\n",
        "endlabel func_00100000\n",
        "    /* 1018 00100018 00000000 */  nop\n",
    ]

    def test_reads_words_and_relocations_until_endlabel(self):
        data, relocated = twin_mask.asm_function(self.ASM)
        self.assertEqual(len(data), 24)
        self.assertEqual(relocated, [True, True, True, False, True, False])

    def test_compare_mask_counts(self):
        data, relocated = twin_mask.asm_function(self.ASM)
        c = twin_mask.compare_mask(data, relocated)
        self.assertEqual(c, dict(masked_reloc=4, masked_plain=0, reloc_kept=0, plain=2))


ASM_DIR = ROOT / "asm"


@unittest.skipUnless((ASM_DIR / "boot_elf" / "nonmatchings").is_dir(), "needs asm/ (tools/setup_asm.py)")
class MaskAgainstSplatTest(unittest.TestCase):
    def test_mask_agrees_with_splat(self):
        t = twin_mask.check_mask(str(ASM_DIR))
        self.assertGreater(t["functions"], 0)
        self.assertGreaterEqual(t["agree"] / t["functions"], 0.9)
        self.assertLessEqual(t["reloc_kept"], 0.005 * t["masked_reloc"])


class ScanCTest(unittest.TestCase):
    SRC = "\n".join([
        '#include "common.h"',                                   # 1
        'INCLUDE_ASM("asm/levels", func_L01_00400000);',         # 2
        "/* void commented(void) { } */",                        # 3
        "s32 func_00100000(s32 a)",                              # 4
        "{",                                                     # 5
        '    char *s = "}";',                                    # 6
        "    if (a) { return 1; }",                              # 7
        "    return 0;",                                         # 8
        "}",                                                     # 9
        "#ifdef NON_MATCHING",                                   # 10
        "void func_00100040(void) { }",                          # 11
        "#else",                                                 # 12
        'INCLUDE_ASM("asm/nonmatchings", func_00100040);',       # 13
        "#endif",                                                # 14
        "struct S { s32 x; };",                                  # 15
        "",
    ])

    def test_definitions_markers_and_activity(self):
        defs, asm = sister_twins.scan_c(self.SRC)
        self.assertEqual(defs, [("func_00100000", 4, 9, True), ("func_00100040", 11, 11, False)])
        self.assertEqual(asm, {"func_L01_00400000", "func_00100040"})

    def test_locate_prefers_the_name_then_the_file_stem(self):
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "src"))
            with open(os.path.join(d, "src", "FRONTEND_001DE8.c"), "w", newline="\n") as f:
                f.write("static void helper(void)\n{\n}\nvoid FRONTEND_001DE8(void)\n{\n    helper();\n}\n")
            self.assertEqual(sister_twins.locate(d, "src/FRONTEND_001DE8.c", "helper"), ("helper", 1, 3))
            self.assertEqual(sister_twins.locate(d, "src/FRONTEND_001DE8.c", "x"), ("FRONTEND_001DE8", 4, 7))


class FindTwinsTest(unittest.TestCase):
    def fn(self, repo, name, words):
        s = sister_twins.SisterFunction(repo, "/r", "us", name, 4 * len(words), None, 0, "src/%s.c" % name,
                                        (name, 1, 2))
        s.raw = s.m = tuple(words)
        return s

    def rac3(self, words):
        return sister_twins.Rac3Function("pal", "func_00100000", "boot_elf", 4 * len(words), "src/x.c", "-",
                                         tuple(words), tuple(words))

    def test_exact_and_near(self):
        base = list(range(1, 41))                          # 40 words
        near = base[:]
        near[7] = 999                                      # 39 of 40 equal: 97.5 %
        far = base[:]
        far[1] = far[2] = far[3] = 999                     # 37 of 40: 92.5 %
        rows = sister_twins.find_twins([self.rac3(base)], [
            self.fn("rac2-decomp", "exact_a", base), self.fn("rac2-decomp", "exact_b", base),
            self.fn("rac4-decomp", "near", near), self.fn("rac4-decomp", "far", far),
            self.fn("rac1-decomp", "far", far)])
        got = {(r["sister_repo"], r["sister_function"], r["tier"], r["masked_equal_pct"], r["other_candidates"])
               for r in rows}
        self.assertEqual(got, {("rac2-decomp", "exact_a", "exact", "100.0", 1),
                               ("rac4-decomp", "near", "near", "97.5", 0)})
        rows = sister_twins.find_twins([self.rac3(base)], [self.fn("rac1-decomp", "far", far)], near_pct=90)
        self.assertEqual([(r["tier"], r["masked_equal_pct"]) for r in rows], [("near", "92.5")])

    def test_no_near_under_twenty_words(self):
        base = list(range(1, 20))
        other = base[:]
        other[0] = 999
        self.assertEqual(sister_twins.find_twins([self.rac3(base)], [self.fn("rac2-decomp", "f", other)]), [])


if __name__ == "__main__":
    unittest.main()
