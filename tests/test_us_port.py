"""Unit tests for tools/us_port.py's constant substitution (no toolchain, no game data).

  python3 -m unittest discover -s tests
"""
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import us_port  # noqa: E402

BODY = """void f(int *p) {
    switch (*p) {
    case 0x7E:
        if (p[1] < 0x7E) {
            p[2] = 0;
        }
        break;
    case 3:
        p[3] = 25;
        break;
    }
}
"""


class SubstituteTest(unittest.TestCase):
    def test_case_labels_are_kept_first(self):
        # 126 -> 151 is a frame count in the code; the case 0x7E label is a state number
        cands = us_port.substitute_all(BODY, [("i", 0x7E, 0x97)])
        self.assertIn("case 0x7E:", cands[0])
        self.assertIn("p[1] < 0x97", cands[0])
        # the label can still change, for a switch compiled to compares
        self.assertTrue(any("case 0x97:" in c for c in cands[1:]))

    def test_a_constant_only_in_a_label_still_changes(self):
        text = "void h(int *p) {\n    switch (*p) {\n    case 5:\n        p[0] = 1;\n        break;\n    }\n}\n"
        cands = us_port.substitute_all(text, [("i", 5, 6)])
        self.assertEqual(len(cands), 1)
        self.assertIn("case 6:", cands[0])

    def test_no_case_labels(self):
        text = "void g(int *p) {\n    p[0] = 25;\n}\n"
        self.assertEqual(us_port.substitute_all(text, [("i", 25, 30)]), ["void g(int *p) {\n    p[0] = 30;\n}\n"])


class RenameTest(unittest.TestCase):
    def test_a_new_name_is_not_renamed_again(self):
        # D_00100010 is D_00100020 on NTSC-U, and the PAL D_00100020 is D_00100030 there:
        # renaming one name at a time would turn both into D_00100030
        names = {"D_00100010": "D_00100020", "D_00100020": "D_00100030"}
        text = "extern s32 D_00100010;\nextern s32 D_00100020;\nvoid f(void) { D_00100020 = D_00100010; }\n"
        self.assertEqual(us_port.rename_all(text, names),
                         "extern s32 D_00100020;\nextern s32 D_00100030;\nvoid f(void) { D_00100030 = D_00100020; }\n")

    def test_only_whole_names(self):
        # an alias (a suffix) and a longer name are other names
        names = {"D_00100010": "D_00100020"}
        text = "D_00100010 D_00100010_ABC D_001000100"
        self.assertEqual(us_port.rename_all(text, names), "D_00100020 D_00100010_ABC D_001000100")

    def test_native_names(self):
        names = us_port.native_names({"D_00100010": 0x100020, "func_00380000": 0x380100,
                                      "D_00100010_ABC": 0x100020, "jtbl_x": 0x10})
        self.assertEqual(names, {"D_00100010": "D_00100020", "func_00380000": "func_U_00380100",
                                 "D_00100010_ABC": "D_00100020_ABC"})


class DistinctCorePairTest(unittest.TestCase):
    def test_historical_draft_keeps_the_current_c_counterpart(self):
        from tempfile import TemporaryDirectory
        import version_map

        with TemporaryDirectory() as directory:
            path = Path(directory) / "map.tsv"
            path.write_text("func_00380010\tfrontbin\tfunc_00390010\t00390010\t16\tC\tdiffers\t75.00\thash\n"
                            "func_00380010\tfrontbin\t-\t-\t16\tnear\tnone\t0.00\tdraft\n", encoding="utf-8")
            versioned = version_map.Map(path)
        self.assertEqual(versioned.us_place("frontbin", "func_00380010"), (None, 0x390010, 16))
        self.assertEqual(versioned.by_pal["frontbin", "func_00380010"]["status"], "differs")

    def test_equal_fingerprints_can_be_distinct_executable_counterparts(self):
        import inventory
        import level_catalogue
        import version_map

        pal_start = 0x380000
        us_start = 0x390000

        def core_inventory(start):
            programs = {program: [] for program in version_map.CORE}
            programs["frontbin"] = [(".text", start + offset, 16, "function") for offset in (0, 16, 32)]
            return programs

        inventories = {version_map.version.cfg("inventory.tsv", v="pal"): core_inventory(pal_start),
                       version_map.version.cfg("inventory.tsv", v="us"): core_inventory(us_start)}
        exact = {("frontbin", pal_start + offset): us_start + offset for offset in (0, 16, 32)}
        key = "frontbin", "func_00380010"
        with (patch.object(inventory, "read_inventory", side_effect=inventories.__getitem__),
              patch.object(level_catalogue, "read_catalogue", return_value=[]),
              patch.object(version_map, "core_twins", side_effect=exact.copy),
              patch.object(version_map, "distinct_level_pairs", return_value=[]),
              patch.object(version_map, "relocated_level_pairs", return_value=[])):
            with patch.object(version_map, "distinct_core_pairs", return_value={key: "func_00390010"}):
                cores, _, counterparts, _ = version_map.pair_versions({})
                self.assertEqual(cores, {("frontbin", pal_start): us_start,
                                         ("frontbin", pal_start + 32): us_start + 32})
                self.assertEqual(counterparts, {key: ("func_00390010", "00390010", 16)})
            with patch.object(version_map, "distinct_core_pairs", return_value={key: "func_00390020"}):
                with self.assertRaisesRegex(SystemExit, "do not pair by position"):
                    version_map.pair_versions({})


class DistinctLevelPairTest(unittest.TestCase):
    def test_equal_fingerprints_can_be_distinct_regional_counterparts(self):
        import inventory
        import level_catalogue
        import version_map

        def rows(start):
            return [("func_L16_%08X" % address, "level", 16, digest, False, [(16, address)])
                    for address, digest in zip(range(start, start + 48, 16), ("first", "timer", "last"))]

        pal = rows(0x300000)
        us = rows(0x310000)
        pal_timer, us_timer = pal[1][0], us[1][0]
        catalogues = {version_map.cat_path("pal"): pal, version_map.cat_path("us"): us}
        empty_core = {program: [] for program in version_map.CORE}
        with patch.object(level_catalogue, "read_catalogue", side_effect=catalogues.__getitem__), \
                patch.object(inventory, "read_inventory", return_value=empty_core), \
                patch.object(version_map, "core_twins", return_value={}), \
                patch.object(version_map, "distinct_core_pairs", return_value={}), \
                patch.object(version_map, "relocated_level_pairs", return_value=[]):
            self.assertEqual(version_map.level_twins()[pal_timer], us[1])
            with patch.object(version_map, "distinct_level_pairs", return_value=[(pal_timer, us_timer)]):
                _, twins, counterparts, _ = version_map.pair_versions({})
            self.assertEqual(twins, {pal[0][0]: us[0], pal[2][0]: us[2]})
            self.assertEqual(counterparts, {("levels", pal_timer): (us_timer, "16:00310010", 16)})
            with patch.object(version_map, "distinct_level_pairs", return_value=[(pal_timer, us[0][0])]):
                with self.assertRaisesRegex(SystemExit, "do not pair by position"):
                    version_map.pair_versions({})


class RelocatedLevelPairTest(unittest.TestCase):
    def test_verified_address_operand_preserves_the_shared_source(self):
        import inventory
        import level_catalogue
        import version_map

        def rows(start, digest):
            return [("func_L16_%08X" % address, "level", 16, key, False, [(16, address)])
                    for address, key in zip(range(start, start + 48, 16), ("first", digest, "last"))]

        pal = rows(0x300000, "pal-address")
        us = rows(0x310000, "us-address")
        left, right = pal[1][0], us[1][0]
        states = {("levels", left): ("C", "src/levels/owner.c", 16, 0x300010)}
        catalogues = {version_map.cat_path("pal"): pal, version_map.cat_path("us"): us}
        empty_core = {program: [] for program in version_map.CORE}
        with (patch.object(level_catalogue, "read_catalogue", side_effect=catalogues.__getitem__),
              patch.object(inventory, "read_inventory", return_value=empty_core),
              patch.object(version_map, "core_twins", return_value={}),
              patch.object(version_map, "distinct_core_pairs", return_value={}),
              patch.object(version_map, "distinct_level_pairs", return_value=[]),
              patch.object(version_map, "native_sources_by_us_name", return_value={})):
            self.assertNotIn(left, version_map.level_twins())
            with patch.object(version_map, "relocated_level_pairs", return_value=[(left, right)]):
                _, twins, counterparts, supplemental = version_map.pair_versions(states)
                self.assertEqual(twins[left], us[1])
                self.assertNotIn(("levels", left), counterparts)
                self.assertFalse(supplemental)
            with patch.object(version_map, "relocated_level_pairs", return_value=[(left, us[0][0])]):
                with self.assertRaisesRegex(SystemExit, "equal-sized positional counterparts"):
                    version_map.pair_versions(states)

    def test_existing_shared_twin_cannot_be_reassigned(self):
        import level_catalogue
        import version_map

        incumbent = "func_L12_00381578"
        pal, us = "func_L05_0038B7A0", "func_L05_00389EE0"
        size = 1748
        row = (us, "level", size, "address", False, [(5, 0x00389EE0)])
        states = {("levels", pal): ("C", "src/levels/owner.c", size, 0x0038B7A0)}
        positional = {("levels", pal): (us, "05:00389EE0", size)}
        with (patch.object(level_catalogue, "read_catalogue", return_value=[row]),
              patch.object(version_map, "core_twins", return_value={}),
              patch.object(version_map, "distinct_core_pairs", return_value={}),
              patch.object(version_map, "level_twins", return_value={incumbent: row}),
              patch.object(version_map, "counterparts", return_value=positional),
              patch.object(version_map, "distinct_level_pairs", return_value=[]),
              patch.object(version_map, "relocated_level_pairs", return_value=[(pal, us)]),
              patch.object(version_map, "native_sources_by_us_name", return_value={})):
            with self.assertRaisesRegex(SystemExit, "already has a PAL twin"):
                version_map.pair_versions(states)

    def test_supplement_keeps_the_primary_twin_and_requires_a_separate_level(self):
        import level_catalogue
        import version_map

        pal, primary, extra = "func_L09_00381000", "func_L16_00397000", "func_L09_0037F000"
        a = (pal, "level", 24, "old", False, [(9, 0x381000)])
        b = (primary, "level", 24, "old", False, [(16, 0x397000)])
        c = (extra, "level", 24, "new", False, [(9, 0x37F000)])
        cat = {version_map.cat_path("pal"): [a], version_map.cat_path("us"): [b, c]}
        states = {("levels", pal): ("C", "src/levels/owner.c", 24, 0x381000)}
        positional = {("levels", pal): (extra, "09:0037F000", 24)}
        with (patch.object(level_catalogue, "read_catalogue", side_effect=cat.__getitem__),
              patch.object(version_map, "core_twins", return_value={}),
              patch.object(version_map, "distinct_core_pairs", return_value={}),
              patch.object(version_map, "level_twins", return_value={pal: b}),
              patch.object(version_map, "counterparts", side_effect=lambda *args: positional.copy()),
              patch.object(version_map, "distinct_level_pairs", return_value=[]),
              patch.object(version_map, "relocated_level_pairs", return_value=[(pal, extra)]),
              patch.object(version_map, "native_sources_by_us_name", return_value={})):
            _, twins, counterparts, supplemental = version_map.pair_versions(states)
            self.assertEqual(twins, {pal: b})
            self.assertEqual(supplemental, {pal: c})
            self.assertFalse(counterparts)
            cat[version_map.cat_path("us")][1] = (*c[:5], [(16, 0x37F000)])
            with self.assertRaisesRegex(SystemExit, "must add distinct PAL source levels"):
                version_map.pair_versions(states)


if __name__ == "__main__":
    unittest.main()
