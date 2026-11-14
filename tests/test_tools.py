"""Unit tests for tools/ that need no toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import importlib.util
import os
import re
import sys
import tempfile
import json
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tests"))

import build_text  # noqa: E402
import check_repository  # noqa: E402
import ee29  # noqa: E402
import ee296  # noqa: E402
import eeas  # noqa: E402
import srcfiles  # noqa: E402
import targets  # noqa: E402

SHA1 = {
    "frontbin": "5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553",
    "boot_elf": "e0a4e82e9a363a64db5a555db8c8f927ef58c3d8",
    "i5bootn": "c1166658edad1b6b04b7671af77fff53f2560e71",
}


class TargetsTest(unittest.TestCase):
    def test_three_programs_and_their_sha1s(self):
        self.assertEqual(set(targets.TARGETS), set(SHA1))
        for name, sha1 in SHA1.items():
            self.assertEqual(targets.TARGETS[name].sha1, sha1)

    def test_tables_exist(self):
        for t in targets.TARGETS.values():
            for attr in ("files", "parts", "divs_nops", "sq_ra_funcs", "symbol_addrs",
                         "symbols_resolved", "yaml", "ld"):
                self.assertTrue(os.path.isfile(t.path(attr)), f"{t.name}.{attr}: {getattr(t, attr)}")

    def test_yaml_names_the_same_sha1(self):
        for t in targets.TARGETS.values():
            m = re.search(r"^sha1:\s*([0-9A-Fa-f]{40})", open(t.path("yaml")).read(), re.M)
            self.assertIsNotNone(m, t.yaml)
            self.assertEqual(m.group(1).lower(), t.sha1)

    def test_units_do_not_overlap(self):
        for t in targets.TARGETS.values():
            spans = sorted((u.start, u.end) for u in t.units)
            for (_, end), (start, _) in zip(spans, spans[1:]):
                self.assertLessEqual(end, start, t.name)

    def test_from_argv_strips_the_option(self):
        argv = ["tool", "--target", "boot_elf", "x"]
        old = os.environ.get("UYA_TARGET")
        try:
            t = targets.from_argv(argv)
            self.assertEqual(t.name, "boot_elf")
            self.assertEqual(argv, ["tool", "x"])
            argv = ["tool", "--target=i5bootn"]
            self.assertEqual(targets.from_argv(argv).name, "i5bootn")
        finally:
            if old is None:
                os.environ.pop("UYA_TARGET", None)
            else:
                os.environ["UYA_TARGET"] = old

    def test_for_function_address(self):
        names = {t.name for t in targets.for_function_address(0x116F80)}
        self.assertEqual(names, {"boot_elf"})


class SourceListTest(unittest.TestCase):
    def test_file_lists_are_sorted_and_in_their_units(self):
        for t in targets.TARGETS.values():
            files = srcfiles.read_file_list(t.path("files"))
            self.assertTrue(files, t.name)
            starts = [s for _, s in files]
            self.assertEqual(starts, sorted(starts), t.name)
            for rel, start in files:
                self.assertIsNotNone(t.unit_for(start), f"{t.name}: {rel} at 0x{start:X}")

    def test_file_for_address(self):
        files = [("a.c", 0x100), ("b.c", 0x200)]
        self.assertEqual(srcfiles.file_for_address(files, 0x1FF), "a.c")
        self.assertEqual(srcfiles.file_for_address(files, 0x200), "b.c")


class FlagTableTest(unittest.TestCase):
    def write(self, text):
        fd, path = tempfile.mkstemp(suffix=".txt")
        with os.fdopen(fd, "w") as f:
            f.write(text)
        self.addCleanup(os.remove, path)
        return path

    def test_read_parts_and_lookup(self):
        parts = build_text.read_parts(self.write(
            "# comment\n00100000 -O2 -G8\n00100010 -O2 -G8 @ps2as  # one function\n00100018 -O2 -G8\n"))
        self.assertEqual(build_text.flags_for(parts, 0x100004), ["-O2", "-G8"])
        self.assertEqual(build_text.flags_for(parts, 0x100010), ["-O2", "-G8", "@ps2as"])
        self.assertEqual(build_text.flags_for(parts, 0x100018), ["-O2", "-G8"])

    def test_file_slices_group_runs_of_equal_flags(self):
        parts = [(0x0, ["-O2"]), (0x20, ["-O1"]), (0x40, ["-O2"])]
        chunks = [(0x0, 1, ""), (0x10, 2, ""), (0x20, 3, ""), (0x40, 4, ""), (0x50, 5, "")]
        self.assertEqual(build_text.file_slices(chunks, parts),
                         [(["-O2"], [0, 1]), (["-O1"], [2]), (["-O2"], [3, 4])])

    def test_pseudo_flags(self):
        cc = os.path.join("tc", "bin", "ee-gcc2953.exe")
        out = build_text.expand_flags(["-O2", "@ps2as", "@ee29"], cc)
        self.assertEqual(out[0], "-O2")
        self.assertTrue(out[1].startswith("-B") and out[1].endswith("Ps2Ee"))
        self.assertIn("-DNO_MACRO_INC", out)
        self.assertNotIn("@ee29", out)
        self.assertTrue(ee29.wanted(["-O2", "@ee29"]))
        self.assertFalse(ee29.wanted(["-O2"]))

    def test_ee296_options(self):
        # @ee296 (tools/ee296.py): dropped from the SN driver's options, kept for the assembler choice;
        # cpp0 gets -I/-D and __OPTIMIZE__, cc1 the rest, nobody -B or -Wa
        cc = os.path.join("tc", "bin", "ee-gcc2953.exe")
        out = build_text.expand_flags(["@ee296", "@newas", "-O2", "-G0"], cc)
        self.assertNotIn("@ee296", out)
        self.assertTrue(out[0].startswith("-B") and out[1:] == ["-O2", "-G0"])
        self.assertTrue(ee296.wanted(["@ee296", "-O2"]))
        self.assertFalse(ee296.wanted(["@ee29", "-O2"]))
        cpp, cc1 = ee296.split_flags(["@ee296", "@newas", "-O2", "-G0"],
                                     ["-I", "include", "-I", ".", "-Wa,-I,include", "-DX=1", "-Btc/bin/ee-"])
        self.assertEqual(cpp, ["-I", "include", "-I", ".", "-DX=1", "-D__OPTIMIZE__"])
        self.assertEqual(cc1, ["-O2", "-G0"])
        self.assertIn("-DNO_MACRO_INC", ee296.split_flags(["@ee296", "@ps2as", "-O0"])[0])
        self.assertNotIn("-D__OPTIMIZE__", ee296.split_flags(["@ee296", "-O0"])[0])

    def test_eeas_options(self):
        # @eeas (tools/eeas.py): dropped from the driver's options and from Sony's compilers' options,
        # the assembler gets what the driver's specs would give it, plus the project's -Wa options
        cc = os.path.join("tc", "bin", "ee-gcc2953.exe")
        self.assertEqual(build_text.expand_flags(["@ee296", "@eeas", "-O2", "-G0"], cc), ["-O2", "-G0"])
        self.assertTrue(eeas.wanted(["@ee29", "@eeas", "-O2"]))
        self.assertFalse(eeas.wanted(["@ee29", "@newas", "-O2"]))
        self.assertEqual(ee29.compile_flags(["@ee29", "@eeas", "-O2", "-G8"]), ["-O2", "-G8"])
        self.assertEqual(ee296.split_flags(["@ee296", "@eeas", "-O2", "-G0"])[1], ["-O2", "-G0"])
        self.assertEqual(eeas.as_options(["@ee296", "@eeas", "-O2", "-G0"]), ["-G0", "-EL", "-O2", "-mabi=eabi"])
        self.assertEqual(eeas.as_options(["@ee29", "-O2", "-G8", "-fno-strict-aliasing"],
                                         ["-I", "include", "-Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi"]),
                         ["-G8", "-EL", "-O2", "-mabi=eabi", "-I", "include", "-mips3", "-mcpu=5900", "-mabi=eabi"])
        self.assertEqual(eeas.as_options(["-O1"]), ["-EL", "-O2", "-mabi=eabi"])
        self.assertEqual(eeas.as_options(["-O3", "-G4"]), ["-G4", "-EL", "-O3", "-mabi=eabi"])
        for o in ("-O0", "-Os"):
            self.assertEqual(eeas.as_options([o]), ["-EL", "-mabi=eabi"])

    def test_eeas_one_assembler(self):
        eeas.check_flags(["@ee29", "@eeas", "-O2"])
        eeas.check_flags(["@ee296", "@newas", "-O2"])
        for other in ("@newas", "@ps2as"):
            with self.assertRaises(ValueError):
                eeas.check_flags(["@ee296", "@eeas", other, "-O2"])

    def test_eeas_program(self):
        with tempfile.TemporaryDirectory() as d:
            prog = os.path.join(d, "ee-as")
            open(prog, "w").close()
            with patch.dict(os.environ, {"UYA_EEAS": prog}):
                self.assertEqual(eeas.program(), prog)
            with patch.dict(os.environ, {}, clear=True):
                self.assertEqual(eeas.program(prog), prog)
                with self.assertRaisesRegex(FileNotFoundError, "UYA_EEAS"):
                    eeas.program()
                with self.assertRaises(FileNotFoundError):
                    eeas.program(os.path.join(d, "missing"))

    @unittest.skipUnless(importlib.util.find_spec("elftools") and importlib.util.find_spec("capstone"),
                         "tools/check.py needs pyelftools and capstone")
    def test_check_as_override(self):
        # check.py --as eeas / --flags=@eeas: Sony's assembler in place of the file's
        import check
        self.assertEqual(check.apply_overrides(["@ee296", "@newas", "-O2", "-G0"], None, "eeas"),
                         ["@ee296", "-O2", "-G0", "@eeas"])
        self.assertEqual(check.apply_overrides(["@ee29", "@eeas", "-O2"], None, "newas"),
                         ["@ee29", "-O2", "@newas"])
        self.assertEqual(check.apply_overrides(["@ee29", "@eeas", "-O2"], None, "default"), ["@ee29", "-O2"])
        self.assertNotIn("@eeas", " ".join(check.expand(["@ee29", "@eeas", "-O2"], "tc")))

    def test_every_flag_table_parses(self):
        for t in targets.TARGETS.values():
            parts = build_text.read_parts(t.path("parts"))
            self.assertTrue(parts, t.name)
            for _, flags in parts:
                eeas.check_flags(flags)
        # the level code's table (tools/level_tree.py): one assembler per file too
        for line in (ROOT / "config" / "levels" / "text_parts.txt").read_text().splitlines():
            if line.strip() and not line.startswith("#"):
                eeas.check_flags(line.split("\t", 1)[1].split())


class EntryPointTest(unittest.TestCase):
    def test_old_names_are_the_new_modules(self):
        import todo
        import triage
        self.assertIs(triage, todo)
        for old, new in (("try_func", "check"), ("triage", "todo")):
            text = (ROOT / "tools" / (old + ".py")).read_text()
            self.assertIn('run_path(os.path.join(_HERE, "%s.py"), run_name="__main__")' % new, text)
            self.assertTrue((ROOT / "tools" / (new + ".py")).is_file())

    def test_progress_report_is_current(self):
        import progress
        rep, rows = progress.report()
        self.assertEqual((ROOT / "progress" / "report.json").read_text(), json.dumps(rep, indent=1) + "\n")
        self.assertEqual(rep["measures"]["total_functions"], sum(sum(c.values()) for _, c in rows))

    def test_progress_table(self):
        import progress
        row = {"C": 6, "ASM_FUNC": 1, "LINKER_REMNANT": 1, "INCLUDE_ASM": 2}
        text = progress.text_table([("frontbin", row)])
        self.assertIn("| frontbin | 10 | 8 (80.0%) | 6 | 1 | 1 | 2 |", text)

    def test_one_flag_line_per_source_file(self):
        import srcfiles
        for name, t in targets.TARGETS.items():
            starts = [s for _, s in srcfiles.read_file_list(t.path("files"))]
            lines = [int(l.split()[0], 16) for l in open(t.path("parts"))
                     if l.split("#", 1)[0].strip()]
            self.assertEqual(sorted(lines), sorted(starts), name)

    def test_readme_takes_progress_from_bytematch(self):
        # The README shows ByteMatch's badges only, so progress never needs a README commit.
        text = (ROOT / "README.md").read_text()
        self.assertIn("bytematch.dev/OpenRAC/rac3-decomp.svg", text)
        self.assertNotIn("<!-- progress", text)


class RepositoryCheckTest(unittest.TestCase):
    def test_tables_check_passes(self):
        errors = []
        check_repository.check_tables(errors)
        self.assertEqual(errors, [])

    def test_game_data_check_flags_an_elf(self):
        with tempfile.TemporaryDirectory() as d:
            Path(d, "x.txt").write_bytes(b"\x7fELF\x01\x01")
            Path(d, "frontbin.elf").write_bytes(b"")
            old_root, old_list = check_repository.ROOT, check_repository.tracked_files
            check_repository.ROOT = Path(d)
            check_repository.tracked_files = lambda: ["x.txt", "frontbin.elf"]
            try:
                errors = []
                check_repository.check_game_data(errors)
            finally:
                check_repository.ROOT, check_repository.tracked_files = old_root, old_list
            self.assertTrue(any("x.txt" in e and "ELF" in e for e in errors), errors)
            self.assertTrue(any("frontbin.elf" in e for e in errors), errors)


class GpTest(unittest.TestCase):
    """config/gp.tsv (tools/gp.py): each program's $gp, and the sda names' values."""

    def test_table_has_every_program(self):
        import gp
        import levels
        table = gp.read_table()
        for version, path in (("pal", "config/levels/levels.tsv"), ("us", "config/us/levels/levels.tsv")):
            rows = levels.read_table(os.path.join(ROOT, path))
            for program in ["frontbin", "boot_elf"] + [levels.target_name(r["number"]) for r in rows]:
                self.assertIn((version, program), table)
            for r in rows:
                want = gp.STORY_GP if r["number"] < 39 else None
                if want is not None:
                    self.assertEqual(table[(version, levels.target_name(r["number"]))], want)
        self.assertEqual(table[("pal", "boot_elf")], gp.STORY_GP)
        self.assertEqual({table[("pal", "level_%02d" % n)] for n in range(39, 54)}, {0x247FC0})
        self.assertEqual({table[("us", "level_%02d" % n)] for n in range(39, 56)}, {0x248140})

    def test_sda_value(self):
        import gp
        self.assertEqual(gp.sda_value("D_001DA700_sda", gp.STORY_GP), 0x1DA700)
        self.assertEqual(gp.sda_value("D_001DA700_sda", 0x247FC0), 0x245E10)
        self.assertIsNone(gp.sda_value("D_001DA700", 0x247FC0))
        self.assertIsNone(gp.sda_value("D_L39_001DA700_sda", 0x247FC0))

    def test_globals_kinds(self):
        import level_globals as lg
        self.assertEqual([lg.kind(n) for n in ("D_001DA700_sda", "D_L39_00245E10", "D_001D4BE0",
                                               "D_L39_0024D490_b")], ["sda", "level", "core", "alias"])

    def test_level_names_follow_the_levels_gp(self):
        import level_symbols as ls
        rows = [("func_L39_00500000", "levels", 8, 0, 0, [(39, 0x500000)])]
        mp, story = ls.Level(39, rows, 0x247FC0), ls.Level(1, rows, 0x1DC8B0)
        self.assertEqual(mp.expected("D_001DA700_sda"), 0x245E10)
        self.assertEqual(story.expected("D_001DA700_sda"), 0x1DA700)
        self.assertEqual(mp.expected("D_001DA700"), 0x1DA700)      # a plain name states its address
        self.assertEqual(mp.expected("func_L39_00500000"), 0x500000)


class LevelCodeTest(unittest.TestCase):
    """tools/level_symbols.py and tools/level_tree.py: level C's names, from synthetic words."""

    @staticmethod
    def words(*ws):
        import struct
        return struct.pack("<%dI" % len(ws), *ws)

    def test_derive_reads_values_from_relocations(self):
        import level_symbols as ls
        # lui $5, %hi(D); addiu $5, $5, %lo(D); jal f; sw $0, %gp_rel(G)($gp)
        mine = self.words(0x3C050000, 0x24A50000, 0x0C000000, 0xAF800000)
        theirs = self.words(0x3C050024, 0x24A52930, 0x0C0F1B7C, 0xAF80FDF8)
        relocs = [(0, ls.R_MIPS_HI16, "D"), (4, ls.R_MIPS_LO16, "D"), (8, ls.R_MIPS_26, "f"),
                  (12, ls.R_MIPS_GPREL16, "G")]
        v = ls.derive(mine, theirs, relocs, 0x3C6F48, 0x1DC8B0)
        self.assertEqual(v, {"D": 0x242930, "f": 0x3C6DF0, "G": 0x1DC6A8})

    def test_derive_refuses_other_bytes(self):
        import level_symbols as ls
        with self.assertRaises(ls.Differ) as e:
            ls.derive(self.words(0x27BDFFF0, 0x0C000000), self.words(0x27BDFFE0, 0x0C000001),
                      [(4, ls.R_MIPS_26, "f")], 0x300000, 0)
        self.assertEqual(e.exception.offset, 0)
        with self.assertRaises(ls.Differ):         # one name, two values
            ls.derive(self.words(0x0C000000, 0x0C000000), self.words(0x0C000001, 0x0C000002),
                      [(0, ls.R_MIPS_26, "f"), (4, ls.R_MIPS_26, "f")], 0x300000, 0)

    def test_jump_table_must_be_the_levels(self):
        import level_symbols as ls
        # two entries into an object placed at 0x3F79D8, then the .align's zero words
        sec = {"name": ".rodata", "data": self.words(0x560, 0x5EC, 0, 0), "align": 16,
               "relocs": [(0, ls.R_MIPS_32, "\u00a7.text"), (4, ls.R_MIPS_32, "\u00a7.text")]}
        level = [(0x2BB8C0, self.words(7, 7, 7, 7, 0x3F7F38, 0x3F7FC4, 0, 0, 9))]
        ls.jump_table(sec, 0x2BB8D0, 0x3F79D8, 0x1000, level)
        for bad in ([(0x2BB8C0, self.words(7, 7, 7, 7, 0x3F7F38, 0x3F7FC0, 0, 0, 9))],    # an entry
                    [(0x2BB8C0, self.words(7, 7, 7, 7, 0x3F7F38, 0x3F7FC4, 0, 1, 9))],    # padding
                    [(0x2BB8C0, self.words(7, 7, 7, 7, 0x3F7F38))]):                      # outside
            with self.assertRaises(ValueError):
                ls.jump_table(sec, 0x2BB8D0, 0x3F79D8, 0x1000, bad)
        with self.assertRaises(ValueError):          # not 16-aligned
            ls.jump_table(sec, 0x2BB8D4, 0x3F79D8, 0x1000, level)

    def test_split_data_around_a_table(self):
        import level_symbols as ls
        text = ('.include "macro.inc"\n\n.section .data, "wa"\n\n'
                'dlabel D_A\n    /* 0 002BB8C8 01000000 */ .word 0x00000001\n'
                '    /* 4 002BB8CC 02000000 */ .word 0x00000002\nenddlabel D_A\n\n'
                'nonmatching jtbl_002BB8D0\n\ndlabel jtbl_002BB8D0\n'
                '    /* 8 002BB8D0 387F3F00 */ .word 0x003F7F38\n'
                '    /* C 002BB8D4 00000000 */ .word 0x00000000\nenddlabel jtbl_002BB8D0\n\n'
                'dlabel D_B\n    /* 10 002BB8D8 03000000 */ .word 0x00000003\nenddlabel D_B\n')
        pieces, aliases = ls.split_data(text, {0x2BB8D0: (8, "x.o(.rodata);")})
        self.assertEqual([k for k, _ in pieces], ["asm", "c", "asm"])
        self.assertEqual(pieces[1][1], "x.o(.rodata);")
        self.assertIn("D_A", pieces[0][1])
        self.assertNotIn("jtbl_002BB8D0", pieces[0][1] + pieces[2][1])
        self.assertTrue(pieces[2][1].startswith('.include "macro.inc"'))
        self.assertIn("0x00000003", pieces[2][1])
        self.assertEqual(aliases, {"jtbl_002BB8D0": 0x2BB8D0})
        with self.assertRaises(ValueError):          # the span ends inside an item
            ls.split_data(text, {0x2BB8D0: (6, "x.o(.rodata);")})
        with self.assertRaises(ValueError):          # no item starts there
            ls.split_data(text, {0x2BB8D2: (8, "x.o(.rodata);")})

    def test_split_data_after_a_table_ending_4_mod_8(self):
        import level_symbols as ls
        text = ('.include "macro.inc"\n\n.section .data, "wa"\n\n.align 3\n'
                'dlabel jtbl_002BB8D0\n    /* 8 002BB8D0 387F3F00 */ .word 0x003F7F38\n'
                '    /* C 002BB8D4 CDCDCDCD */ .word 0xCDCDCDCD\nenddlabel jtbl_002BB8D0\n\n.align 3\n'
                'dlabel D_B\n    /* 10 002BB8D8 03000000 */ .word 0x00000003\nenddlabel D_B\n')
        pieces, _ = ls.split_data(text, {0x2BB8D0: (4, "x.o(.rodata);")})
        self.assertEqual([k for k, _ in pieces], ["c", "asm4", "asm"])
        self.assertIn("0xCDCDCDCD", pieces[1][1])
        self.assertTrue(pieces[1][1].startswith('.include "macro.inc"'))
        self.assertNotIn(".align", pieces[1][1])
        self.assertIn(".text", pieces[1][1])
        self.assertIn("0x00000003", pieces[2][1])

    def test_expected_values(self):
        import level_symbols as ls
        rows = [("func_L01_00301558", "shared", 8, "", False, [(1, 0x301558), (5, 0x304500)]),
                ("func_003820F0", "frontbin", 8, "", False, [(1, 0x3F27B0), (5, 0x3EC770)])]
        level = ls.Level(5, rows)
        self.assertEqual(level.expected("func_L01_00301558"), 0x304500)
        self.assertEqual(level.expected("fe_func_003820F0"), 0x3EC770)
        self.assertEqual(level.expected("D_L05_001E0000"), 0x1E0000)
        self.assertIsNone(level.expected("D_L01_001E0000"))
        self.assertEqual(level.expected("D_00143950"), 0x143950)

    def test_tree_names_and_padding(self):
        import level_tree
        fe = {"func_003820F0"}
        self.assertEqual(level_tree.level_names("func_003820F0(); func_L01_003820F0(); fe_func_003820F0();", fe),
                         "fe_func_003820F0(); func_L01_003820F0(); fe_func_003820F0();")
        self.assertEqual(level_tree.text_padding(0x1000, 0x1C, 0x1020), 0)    # gcc's one nop
        self.assertEqual(level_tree.text_padding(0x1000, 0x1C, 0x1030), 4)
        self.assertEqual(level_tree.text_padding(0x1000, 0x18, 0x1018), 0)

    def test_parse_source(self):
        import level_tree
        text = ('#include "common.h"\r\n\r\nINCLUDE_ASM("asm/levels", func_L01_002F7800);\r\n\r\n'
                '/* localdecomp:start func_L01_002F7808 */\r\nvoid func_L01_002F7808(void) {\r\n}\r\n'
                '/* localdecomp:end func_L01_002F7808 */\r\n')
        with tempfile.TemporaryDirectory(dir=ROOT) as d:
            path = os.path.join(d, "x.c")
            open(path, "w", newline="").write(text)
            prelude, chunks = level_tree.parse_source(os.path.relpath(path, ROOT))
        self.assertEqual(prelude, '#include "common.h"\r\n\r\n')
        self.assertEqual([(n, k) for n, k, _ in chunks], [("func_L01_002F7800", "INCLUDE_ASM"),
                                                          ("func_L01_002F7808", "C")])


if __name__ == "__main__":
    unittest.main()


class LevelDivsNopsTest(unittest.TestCase):
    """tools/level_tree.py: the committed level div.s padding table reaches each level's build."""

    def test_rows_of_the_level_only(self):
        import level_tree
        with tempfile.TemporaryDirectory() as d:
            table = os.path.join(d, "divs_nops.txt")
            with open(table, "w") as f:
                f.write("# comment\nfunc_L08_00000010 2 0 1\nfunc_L09_00000020 1\nfunc_L08_00000030\n")
            rows = level_tree.read_divs_nops(table)
            self.assertEqual(sorted(rows), ["func_L08_00000010", "func_L09_00000020"])
            places = [(0x00400010, ["func_L08_00000010"]), (0x00400030, ["func_L08_00000030"])]
            level_tree.write_divs_nops(d, 8, places, rows)
            lines = [l for l in open(os.path.join(d, "divs_nops.txt")) if not l.startswith("#")]
            self.assertEqual(lines, ["func_00400010 2 0 1\n"])  # under the level's own names

    def test_committed_table_parses(self):
        import level_tree
        for name, line in level_tree.read_divs_nops().items():
            self.assertTrue(re.match(r"func_L\d\d_[0-9A-F]{8}$", name), name)
            self.assertTrue(all(x.isdigit() for x in line.split()[1:]), line)


class LevelSqRaTest(unittest.TestCase):
    """The level sq-$ra table: tools/level_tree.py writes each level's copy under its names, and
    tools/asm_filter.py reads the catalogue-name table as it is (check.py, the NTSC-U objects)."""

    def test_rows_of_the_level_only(self):
        import level_tree
        with tempfile.TemporaryDirectory() as d:
            table = os.path.join(d, "sq_ra_funcs.txt")
            with open(table, "w") as f:
                f.write("# comment\nfunc_L08_00000010\nfunc_L09_00000020  # other level\n")
            rows = level_tree.read_sq_ra_funcs(table)
            self.assertEqual(sorted(rows), ["func_L08_00000010", "func_L09_00000020"])
            places = [(0x00400010, ["func_L08_00000010"]), (0x00400030, ["func_L08_00000030"])]
            level_tree.write_sq_ra_funcs(d, 8, places, rows)
            lines = [l for l in open(os.path.join(d, "sq_ra_funcs.txt")) if not l.startswith("#")]
            self.assertEqual(lines, ["func_00400010\n"])  # under the level's own names

    def test_committed_table_parses(self):
        import level_tree
        for name in level_tree.read_sq_ra_funcs():
            self.assertTrue(re.match(r"func_L\d\d_[0-9A-F]{8}$", name), name)

    def test_filter_reads_the_catalogue_table(self):
        import asm_filter
        old = asm_filter.LEVEL_SQ_RA
        with tempfile.TemporaryDirectory() as d:
            asm_filter.LEVEL_SQ_RA = os.path.join(d, "sq_ra_funcs.txt")
            with open(asm_filter.LEVEL_SQ_RA, "w") as f:
                f.write("# comment\nfunc_L08_00000010\n")
            try:
                self.assertIn("func_L08_00000010", asm_filter.sq_ra_funcs())
                text = ("\t.ent\tfunc_L08_00000010\n"
                        "\tsd\t$31,0($sp)\n\tsq\t$16,16($sp)\n\tsq\t$17,32($sp)\n"
                        "\tld\t$31,0($sp)\n\tlq\t$17,32($sp)\n\tlq\t$16,16($sp)\n"
                        "\t.end\tfunc_L08_00000010\n")
                out = asm_filter.sq_pass(text)
            finally:
                asm_filter.LEVEL_SQ_RA = old
        self.assertIn("sq $16,0($sp)", out)
        self.assertIn("sq $17,16($sp)", out)
        self.assertIn(".word 0x7FBF0020", out)   # sq $31,32($sp): $ra in the highest slot
        self.assertIn(".word 0x7BBF0020", out)

    def test_ra_in_a_delay_slot_under_ps2as(self):
        # Ps2EeAs crashes on a .word in a branch delay slot: there $ra's save is the instruction
        import asm_filter
        lines = ["\t.ent\tf\n", "\tsq\t$16,16($sp)\n", "\t.set\tnoreorder\n", "\tbne\t$17,$0,$L3\n",
                 "\tsd\t$31,0($sp)\n", "\t.set\treorder\n", "\tld\t$31,0($sp)\n", "\tlq\t$16,16($sp)\n",
                 "\t.end\tf\n"]
        ps2 = "".join(asm_filter.sq_rewrite(list(lines), ps2as=True))
        self.assertIn("\tsq $31,16($sp)\n", ps2)
        self.assertIn(".word 0x7BBF0010", ps2)          # the restore is not in a delay slot
        gnu = "".join(asm_filter.sq_rewrite(list(lines)))
        self.assertIn(".word 0x7FBF0010", gnu)


class LevelBoundariesTest(unittest.TestCase):
    """tools/level_catalogue.py: config/levels/boundaries.tsv's edits change the rows they name
    and the entries their joins take in, and no other row."""

    @staticmethod
    def level(base, words):
        import struct
        return base, struct.pack("<%dI" % len(words), *words)

    def setUp(self):
        import level_catalogue as lc
        self.lc = lc
        JR, NOP, POP = 0x03E00008, 0, 0x27BD0020          # jr $ra, nop, addiu $sp,$sp,0x20
        RET1, RETV = 0x24020001, 0x8C820030              # addiu $v0,$zero,1; lw $v0,0x30($a0)
        FILL = 0xCDCDCDCD
        # level 1: [POP NOP | JR RET1] [JR RETV JR RET1] [JR NOP] [JR (POP)] [JR RET1 FILL ...]
        self.data = {1: self.level(0x1000, [POP, NOP, JR, RET1, JR, RETV, JR, RET1, JR, NOP, JR, POP, NOP, NOP,
                                            0x3C020001, JR, RET1, FILL, JR, RETV]),
                     2: self.level(0x2000, [POP, NOP, JR, RET1, JR, NOP])}
        def place(n, a, size, rem=False):
            base, text = self.data[n]
            return (a, text[a - base:a - base + size], rem, None)
        self.per_level = {1: [place(1, 0x1000, 16), place(1, 0x1010, 16), place(1, 0x1020, 8),
                              place(1, 0x1028, 4), place(1, 0x102C, 4, True), place(1, 0x1038, 16),
                              place(1, 0x1048, 8)],
                          2: [place(2, 0x2000, 16), place(2, 0x2010, 8)]}
        self.rows = lc.catalogue_rows(self.per_level, {}, {})

    def apply(self, edits):
        return self.lc.apply_boundaries(self.per_level, self.data, self.rows, edits, {}, {})[0]

    def test_start_split_join_size(self):
        names = {r[0]: r for r in self.rows}
        self.assertIn("func_L01_00001000", names)
        rows = self.apply([("func_L01_00001000", "start", "+0x8", 1), ("func_L01_00001010", "split", "+0x8", 2),
                           ("func_L01_00001028", "join", "1", 3), ("func_L01_00001038", "size", "12", 4)])
        got = {r[0]: (r[1], r[2], r[4], r[5]) for r in rows}
        self.assertEqual(got["func_L01_00001000"], ("shared", 4, True, [(1, 0x1000), (2, 0x2000)]))
        self.assertEqual(got["func_L01_00001008"], ("shared", 8, False, [(1, 0x1008), (2, 0x2008)]))
        self.assertEqual(got["func_L01_00001010"][1:3], (8, False))
        self.assertEqual(got["func_L01_00001018"][3], [(1, 0x1018)])
        self.assertEqual(got["func_L01_00001028"][1:], (8, False, [(1, 0x1028)]))
        self.assertNotIn("func_L01_0000102C", got)             # the delay slot the join took in
        self.assertEqual(got["func_L01_00001038"][1], 12)      # without the fill word
        # rows no edit names keep their places
        for name in ("func_L01_00001020", "func_L01_00001048"):
            self.assertEqual(got[name][3], names[name][5])

    def test_cut(self):
        """cut: the entry (with the K entries after it) is the pieces named, and nothing else moves."""
        names = {r[0]: r for r in self.rows}
        rows = self.apply([("func_L01_00001000", "cut", "+0x0:0x4r,+0x8:0x8", 1),
                           ("func_L01_00001010", "cut", "+0x0:0x8,+0x8:0x8", 2),
                           ("func_L01_00001028", "cut", "1/+0x0:0x8", 3),
                           ("func_L01_00001038", "cut", "+0x0:0xc", 4)])
        got = {r[0]: (r[1], r[2], r[4], r[5]) for r in rows}
        self.assertEqual(got["func_L01_00001000"], ("shared", 4, True, [(1, 0x1000), (2, 0x2000)]))
        self.assertEqual(got["func_L01_00001008"], ("shared", 8, False, [(1, 0x1008), (2, 0x2008)]))
        self.assertEqual(got["func_L01_00001010"][1:3], (8, False))
        self.assertEqual(got["func_L01_00001018"][3], [(1, 0x1018)])
        self.assertEqual(got["func_L01_00001028"][1:], (8, False, [(1, 0x1028)]))
        self.assertNotIn("func_L01_0000102C", got)             # the entry the cut took in
        self.assertEqual(got["func_L01_00001038"][1], 12)      # without the fill word
        for name in ("func_L01_00001020", "func_L01_00001048"):
            self.assertEqual(got[name][3], names[name][5])
        self.assertEqual(self.lc.parse_cut("2/+0x0:0x10,+0x18:0x4r,+0x20:0x8o"),
                         (2, [(0, 16, False, False), (24, 4, True, False), (32, 8, False, True)]))
        # `o`: a piece that is a row of its own though level 2 has its code where level 1's row has no place
        rows = self.apply([("func_L01_00001010", "cut", "+0x0:0x8,+0x8:0x8o", 1)])
        got = {r[0]: r[5] for r in rows}
        self.assertEqual(got["func_L01_00001018"], [(1, 0x1018)])
        for bad in ("+0x0", "0x0:0x8", "+0x0:0x8,+0x4:0x8", "+0x2:0x8", "+0x0:0"):
            with self.assertRaises(SystemExit):
                self.lc.parse_cut(bad)
        with self.assertRaises(SystemExit):                    # a piece that runs past its entries
            self.apply([("func_L01_00001010", "cut", "+0x0:0x8,+0x8:0x10", 1)])

    def test_variant_and_unknown_names(self):
        rows = self.apply([("func_L01_00001000", "variant", "2", 1)])
        got = {r[0]: r[5] for r in rows}
        self.assertEqual(got["func_L01_00001000"], [(1, 0x1000)])
        self.assertEqual(got["func_L02_00002000"], [(2, 0x2000)])
        with self.assertRaises(SystemExit):
            self.apply([("func_L01_00009999", "size", "4", 1)])

    def test_committed_tables_parse(self):
        """Both versions' tables (config/levels/ and config/us/levels/boundaries.tsv): one edit per name."""
        import version
        for v in ("pal", "us"):
            path = version.cfg("levels", "boundaries.tsv", v=v)
            names = [name for name, edit, arg, _ in self.lc.read_boundaries(path)]
            self.assertEqual(len(names), len(set(names)), path)
            for name, edit, arg, _ in self.lc.read_boundaries(path):
                self.assertTrue(re.match(r"func_L\d\d_[0-9A-F]{8}$", name), name)
                self.assertIn(edit, self.lc.EDITS)
