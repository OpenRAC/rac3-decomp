"""Native level names retain paired assembler metadata and correct reuse keys."""
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import asm_filter
import version
import version_map

PAL = "func_L03_003A16D8"
RAW = "func_L03_0039FEF0"
NATIVE = "func_U_L03_0039FEF0"
PAIR = {"program": "levels", "pal": PAL, "us": RAW, "state": "C"}


class NativeDivsTest(unittest.TestCase):
    def test_only_a_unique_real_level_counterpart_is_inherited(self):
        self.assertEqual(version_map.native_level_counterpart(NATIVE, [PAIR]), PAL)
        self.assertIsNone(version_map.native_level_counterpart(RAW, [PAIR]))
        self.assertIsNone(version_map.native_level_counterpart(NATIVE, [dict(PAIR, pal="-")]))
        self.assertIsNone(version_map.native_level_counterpart(NATIVE, [dict(PAIR, state="near")]))
        self.assertIsNone(version_map.native_level_counterpart(NATIVE, [PAIR, dict(PAIR, pal="func_L03_003A0000")]))

    def test_native_padding_uses_the_paired_row_on_us_only(self):
        text = f".ent {NATIVE}\n{NATIVE}:\n div.s $f0, $f0, $f1\n.end {NATIVE}\n"
        with patch.object(asm_filter, "divs_table", return_value={PAL: [2]}), \
             patch.object(version_map, "load", return_value=SimpleNamespace(rows=[PAIR])):
            with patch.object(version, "V", "us"):
                padded = asm_filter.divs_pass(text)
                self.assertEqual(padded.count(".word 0x00000000"), 2)
                self.assertIn("div.s $f0, $f0, $f1", padded)
            with patch.object(version, "V", "pal"):
                self.assertEqual(asm_filter.divs_pass(text), text)
            pal_text = text.replace(NATIVE, PAL)
            self.assertEqual(asm_filter.divs_pass(pal_text).count(".word 0x00000000"), 2)

    def test_changing_the_inherited_row_invalidates_the_native_object_key(self):
        from test_reuse import file_inputs, write
        with tempfile.TemporaryDirectory() as directory:
            relative = f"src/us/levels/{NATIVE}.c"
            write(str(Path(directory) / relative), f"float {NATIVE}(float x) {{ return x / 2.0f; }}\n")
            rows = {PAL: [f"config/levels/divs_nops.txt: {PAL} 2"]}
            first = file_inputs(directory, rows=rows, native_rows=[PAIR]).of("levels", relative, True)
            changed = {PAL: [f"config/levels/divs_nops.txt: {PAL} 1"]}
            second = file_inputs(directory, rows=changed, native_rows=[PAIR]).of("levels", relative, True)
            self.assertNotEqual(first, second)
            unrelated = dict(rows, func_L01_00300000=["func_L01_00300000 9"])
            self.assertEqual(first, file_inputs(directory, rows=unrelated, native_rows=[PAIR]).of("levels", relative, True))
