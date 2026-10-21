"""Unit tests for tools/ that need no toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import os
import re
import sys
import tempfile
import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tests"))

import build_text  # noqa: E402
import check_repository  # noqa: E402
import ee29  # noqa: E402
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

    def test_every_flag_table_parses(self):
        for t in targets.TARGETS.values():
            parts = build_text.read_parts(t.path("parts"))
            self.assertTrue(parts, t.name)


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

    def test_readme_has_the_progress_block(self):
        import progress
        text = (ROOT / "README.md").read_text()
        self.assertIn(progress.BEGIN, text)
        self.assertIn(progress.END, text)


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
