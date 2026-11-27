"""Unit tests for tools/idioms.py (the idiom cookbook), on synthetic instructions, C text and gcc
output (no game data, no toolchain).

  python3 -m unittest discover -s tests
"""
import os
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import idioms  # noqa: E402

try:
    import capstone  # noqa: F401
    HAVE_CAPSTONE = True
except ImportError:
    HAVE_CAPSTONE = False


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


class Normalise(unittest.TestCase):
    def test_registers_become_numbered_classes(self):
        fine, coarse = idioms.normalise([("sltu $v0, $a1, $a2", None), ("movn $v1, $a1, $v0", None)])
        self.assertEqual(fine, ("sltu v1,a1,a2", "movn v2,a1,v1"))
        self.assertEqual(coarse, ("sltu", "movn"))

    def test_numeric_and_named_registers_agree(self):
        a = idioms.normalise([("addu $2, $4, $5", None)])
        b = idioms.normalise([("addu $v0, $a0, $a1", None)])
        self.assertEqual(a, b)

    def test_relocations_and_buckets(self):
        fine, coarse = idioms.normalise([
            ("lui $v0, %hi(D_001A71A4)", "hi"),
            ("lw $a0, %lo(D_001A71A4)($v0)", "lo"),
            ("lw $v1, -0x21b0($gp)", "gp"),
            ("sw $zero, 0x10($sp)", None),
            ("jal 0x3c3a10", "26"),
            ("addiu $a1, $zero, 0x123", None),
        ])
        self.assertEqual(fine, ("lui v1,%hi", "lw a1,%lo(v1)", "lw v2,%gp(gp)", "sw zero,s(sp)", "jal F",
                                "addiu a2,zero,i16"))
        self.assertEqual(coarse, ("lui@hi", "lw@lo", "lw@gp", "sw@sp", "jal", "addiu"))

    def test_symbol_at_an_offset(self):
        fine, _ = idioms.normalise([("sw $zero, 0x8($at)", "lo+")])
        self.assertEqual(fine, ("sw zero,%lo+(at)",))

    def test_branches_by_direction(self):
        fine, _ = idioms.normalise([("bnez $v0, -0x10", None), ("beql $v0, $zero, 0x20", None), ("nop", None)])
        self.assertEqual(fine, ("bnez v1,Lb", "beql v1,zero,Lf", "nop"))

    def test_float_and_vector_registers(self):
        fine, _ = idioms.normalise([("mov.s $f12, $f20", None), ("vadd.xyz $vf1, $vf1, $vf2", None)])
        self.assertEqual(fine, ("mov.s fa1,fs1", "vadd.xyz vf1,vf1,vf2"))


class NormaliseC(unittest.TestCase):
    def test_names_abstracted_shape_kept(self):
        self.assertEqual(idioms.normalise_c("if (p->count < 0x10) D_001A4BE0 = func_00382E60(i, 1.5f);"),
                         "if ( v -> m < N ) G = F ( v , Nf ) ;")

    def test_types_keywords_and_helpers_stay(self):
        self.assertEqual(idioms.normalise_c("x = (s32)fabs_asm(y) + 0; /* note */", {"fabs_asm"}),
                         "v = ( s32 ) fabs_asm ( v ) + 0 ;")

    def test_asm_template_kept(self):
        self.assertIn('"vadd.xyz %0, %1, %2"',
                      idioms.normalise_c('__asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(b), "j"(c));'))

    def test_structural(self):
        self.assertTrue(idioms.structural("} else {"))
        self.assertTrue(idioms.structural("break ;"))
        self.assertFalse(idioms.structural("return 0 ;"))


class Vu0(unittest.TestCase):
    def test_lqc2_and_macro_ops(self):
        self.assertEqual(idioms.vu0_text(0xDA820010), "lqc2 $vf2, 0x10($s4)")
        self.assertEqual(idioms.vu0_text(0xFBA200D0), "sqc2 $vf2, 0xd0($sp)")
        # vadd.xyz vf1, vf1, vf2: COP2, co bit, dest xyz (0b1110), ft 2, fs 1, fd 1, funct 0x28
        word = (0x12 << 26) | (1 << 25) | (0b1110 << 21) | (2 << 16) | (1 << 11) | (1 << 6) | 0x28
        self.assertEqual(idioms.vu0_text(word), "vadd.xyz $vf1, $vf1, $vf2")
        # qmfc2 $v0, $vf3
        self.assertEqual(idioms.vu0_text((0x12 << 26) | (1 << 21) | (2 << 16) | (3 << 11)), "qmfc2 $v0, $vf3")
        self.assertIsNone(idioms.vu0_text(0x03E00008))


class LineLabels(unittest.TestCase):
    GCC = """\t.file\t1 "t.c"
\t#@stabs
 .stabs "/work/",100,0,0,$Ltext0
 .stabs "src/x.c",100,0,0,$Ltext0
 .stabs "s32:t24=1",128,0,14,0
$LM1:
\t.stabn 68,0,15,$LM1
func_00100000:
 .stabs "include/vu0.h",132,0,0,$Ltext1
$LM2:
\t.stabn 68,0,73,$LM2
\tlqc2\t$vf1,0($4)
 .stabs "src/x.c",132,0,0,$Ltext2
$LM3:
\t.stabn 68,0,16,$LM3
\tj\t$31
"""

    def test_markers_become_labels(self):
        asm, files = idioms.lines_to_labels(self.GCC)
        self.assertEqual(files, ["src/x.c", "include/vu0.h"])
        self.assertIn("__idl_1_15_0:", asm)
        self.assertIn("__idl_2_73_1:", asm)
        self.assertIn("__idl_3_16_0:", asm)
        self.assertNotIn(".stab", asm)
        self.assertNotIn("$LM", asm)
        self.assertIn("\tlqc2\t$vf1,0($4)", asm)


class Components(unittest.TestCase):
    def test_data_flow_groups(self):
        texts = ["addiu $v0, $s2, -1", "addiu $v1, $zero, 0xc7", "slti $a1, $v0, 0xc8", "move $a0, $s0",
                 "movn $v1, $v0, $a1", "move $a1, $s3", "jal 0x6ab6f8", "sw $v1, 0x394($s0)"]
        self.assertEqual(idioms.components(texts), [[0, 1, 2, 4, 7], [3, 5, 6]])

    def test_delay_slot_runs_before_the_call(self):
        texts = ["move $a0, $s4", "jal 0x687268", "addiu $a1, $zero, 0x13"]
        self.assertEqual(idioms.components(texts), [[0, 1, 2]])

    def test_likely_slot_and_nops(self):
        texts = ["mtc1 $zero, $f0", "nop", "c.olt.s $f1, $f0", "nop", "bc1tl 0x10", "mov.s $f1, $f0"]
        self.assertEqual(idioms.components(texts), [[0, 1, 2, 3, 4, 5]])
        texts = ["lwc1 $f0, 0($a0)", "nop", "nop", "div.s $f0, $f1, $f0"]
        self.assertEqual(idioms.components(texts), [[0, 1, 2, 3]])


class Families(unittest.TestCase):
    def test_tags(self):
        fine, coarse = idioms.normalise([("sltu $v0, $a1, $a2", None), ("movn $v1, $a1, $v0", None)])
        self.assertEqual(idioms.tag_families(fine, coarse, {}), {"movn_movz", "set_less"})
        fine, coarse = idioms.normalise([("lui $at, 0x3f80", None), ("mtc1 $at, $f0", None), ("nop", None)])
        self.assertEqual(idioms.tag_families(fine, coarse, {}), {"mtc1_nop", "float_const"})
        fine, coarse = idioms.normalise([("lq $v0, 0x10($a1)", None), ("sq $v0, 0($a0)", None)])
        self.assertIn("quad_copy", idioms.tag_families(fine, coarse, {}))

    def test_signature_rank(self):
        self.assertLess(idioms.sig_rank("movn"), idioms.sig_rank("sltu"))
        self.assertLess(idioms.sig_rank("bc1tl"), idioms.sig_rank("c.olt.s"))
        self.assertLess(idioms.sig_rank("c.olt.s"), idioms.sig_rank("mtc1"))


@unittest.skipUnless(HAVE_CAPSTONE, "needs capstone (tools/requirements.txt)")
class EndToEnd(unittest.TestCase):
    """A fake raw record of one function through fragments_of, the database, query and report."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.src = os.path.join(self.tmp.name, "f.c")
        with open(self.src, "w") as fh:
            fh.write("int func_00100000(int a, int b) {\n"
                     "    int m;\n"
                     "    m = (a < b) ? a : b;\n"
                     "    return m;\n"
                     "}\n")
        # sltu v0,a0,a1 ; move v1,a1 ; movn v1,a0,v0 ; jr ra ; move v0,v1
        self.words = [(4 << 21) | (5 << 16) | (2 << 11) | 0x2B,
                      (5 << 21) | (0 << 16) | (3 << 11) | 0x25,
                      (4 << 21) | (2 << 16) | (3 << 11) | 0x0B,
                      0x03E00008,
                      (3 << 21) | (0 << 16) | (2 << 11) | 0x25]
        self.rec = {"rel": self.src, "files": [self.src], "functions": []}
        self.fn = {"name": "func_00100000", "status": "ok", "words": self.words, "relocs": {},
                   "lines": [[3, 0], [3, 0], [3, 0], [5, 0], [4, 0]],
                   "callers": [3, 3, 3, 5, 4]}

    def tearDown(self):
        self.tmp.cleanup()

    def db(self):
        src = idioms.Source()
        shapes = {}
        for fine, coarse, c_norm, ex, tags in idioms.fragments_of(self.fn, self.rec, src, set()):
            s = shapes.setdefault(" ; ".join(fine), {"fine": list(fine), "coarse": list(coarse), "count": 0,
                                                    "tags": [], "c": {}})
            s["count"] += 1
            s["tags"] = sorted(set(s["tags"]) | tags)
            c = s["c"].setdefault(c_norm, {"count": 0, "examples": [], "tags": {}})
            c["count"] += 1
            c["examples"].append(ex)
            for t in tags:
                c["tags"][t] = c["tags"].get(t, 0) + 1
        return {"functions": 1, "fragments": sum(s["count"] for s in shapes.values()), "files": 1,
                "skipped": 0, "copies": 0, "shapes": shapes}

    def test_fragments_and_query(self):
        db = self.db()
        key = "sltu v1,a1,a2 ; move v2,a2 ; movn v2,a1,v1"
        self.assertIn(key, db["shapes"])
        self.assertIn("v = ( v < v ) ? v : v ;", db["shapes"][key]["c"])
        self.assertIn("movn_movz", db["shapes"][key]["tags"])
        lines = idioms.query_lines(db, idioms.Index(db), "sltu $2,$4,$5\nmove $3,$5\nmovn $3,$4,$2\n")
        text = "\n".join(lines)
        self.assertIn("exact", text)
        self.assertIn("v = ( v < v ) ? v : v ;", text)

    def test_reordered_query(self):
        db = self.db()
        lines = idioms.query_lines(db, idioms.Index(db), "move $3,$5\nsltu $2,$4,$5\nmovn $3,$4,$2\n")
        self.assertIn("same instructions in another order", "\n".join(lines))

    def test_report(self):
        text = idioms.report_text(self.db())
        self.assertIn("# Idiom cookbook", text)
        self.assertIn("movn / movz", text)
        self.assertIn("v = ( v < v ) ? v : v ;", text)

    def test_splat_listing(self):
        listing = ("glabel func_00100000\n"
                   "    /* 0 00100000 2B108500 */  sltu       $2, $4, $5\n"
                   "    .word 0xDA820010 /* lqc2       $vf2, 0x10($20) */\n"
                   "  .L00100008:\n"
                   "    /* 8 00100008 0800E003 */  jr         $31\n")
        insns = idioms.parse_asm(listing)
        self.assertEqual([t for t, _, _, _ in insns], ["sltu $v0, $a0, $a1", "lqc2 $vf2, 0x10($s4)", "jr $ra"])
        self.assertEqual([lab for _, _, _, lab in insns], [False, False, True])
        self.assertEqual(idioms.blocks_of(insns), [[0, 1], [2]])


if __name__ == "__main__":
    unittest.main()
