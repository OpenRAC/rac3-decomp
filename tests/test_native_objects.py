"""Native core objects with compiler-generated data, without game inputs or tools."""
import sys
import unittest
from contextlib import ExitStack
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import mock_open, patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import asm_build
import c_objects
import level_symbols
import srcfiles
import version_map


class NativeObjectsTest(unittest.TestCase):
    name = "func_U_00380000"
    relative = "src/us/boot_elf/00380000.c"

    def compiler_object(self, extra=True):
        return {"text": b"\0" * 8, "relocs": [], "extra": [".rodata"] if extra else [],
                "defined": {self.name: 0}, "exported": {self.name}}

    def test_native_core_data_object_kept_after_stock_match(self):
        item = ("boot_elf", self.name, [("boot_elf", 0x380000)], self.relative, True)
        options = SimpleNamespace(toolchain="compiler", runner=None, ee29=None)
        process = SimpleNamespace(stdout=self.name + ": MATCH\n")
        with patch.object(c_objects.subprocess, "run", return_value=process), \
                patch.object(c_objects.os.path, "exists", return_value=True), \
                patch.object(level_symbols, "read_object", return_value=self.compiler_object()):
            result, obj, why = c_objects.compile_one(item, options, "unused")
        self.assertEqual(result, item)
        self.assertNotEqual(obj, "-")
        self.assertEqual(why, "ok")

    def test_native_level_data_still_rejected(self):
        item = ("levels", self.name, [("level_01", 0x380000)], self.relative, True)
        options = SimpleNamespace(toolchain="compiler", runner=None, ee29=None)
        process = SimpleNamespace(stdout=self.name + ": MATCH\n")
        with patch.object(c_objects.subprocess, "run", return_value=process), \
                patch.object(c_objects.os.path, "exists", return_value=True), \
                patch.object(level_symbols, "read_object", return_value=self.compiler_object()):
            result, obj, why = c_objects.compile_one(item, options, "unused")
        self.assertEqual(obj, "-")
        self.assertIn("data of its own", why)

    def test_shared_data_object_still_rejected(self):
        item = ("boot_elf", self.name, [("boot_elf", 0x380000)], "shared.c", False)
        options = SimpleNamespace(toolchain="compiler", runner=None, ee29=None)
        process = SimpleNamespace(stdout=self.name + ": MATCH\n")
        with patch.object(c_objects.subprocess, "run", return_value=process), \
                patch.object(c_objects.os.path, "exists", return_value=True), \
                patch("builtins.open", mock_open()), \
                patch.object(version_map, "chunk_text", return_value=""), \
                patch.object(level_symbols, "read_object", return_value=self.compiler_object()):
            result, obj, why = c_objects.compile_one(item, options, "unused")
        self.assertEqual(obj, "-")
        self.assertIn("data of its own", why)

    def test_native_object_without_stock_match_not_kept(self):
        item = ("boot_elf", self.name, [("boot_elf", 0x380000)], self.relative, True)
        options = SimpleNamespace(toolchain="compiler", runner=None, ee29=None)
        process = SimpleNamespace(stdout=self.name + ": 1 diff\n")
        with patch.object(c_objects.subprocess, "run", return_value=process), \
                patch.object(c_objects.os.path, "exists", return_value=True), \
                patch.object(c_objects.os, "remove") as remove:
            result, obj, why = c_objects.compile_one(item, options, "unused")
        self.assertEqual(obj, "-")
        remove.assert_called_once()

    def native_file_rows(self, compiler_object):
        with patch.object(c_objects, "read_index", return_value={("boot_elf", self.name): "native.o"}), \
                patch.object(version_map, "Map", return_value=SimpleNamespace(rows=[], by_pal={})), \
                patch.object(version_map, "pal_states", return_value={}), \
                patch.object(version_map, "us_sources", return_value={("boot_elf", self.name): self.relative}), \
                patch.object(srcfiles, "read_file_list", return_value=[]), \
                patch.object(level_symbols, "read_object", return_value=compiler_object):
            return c_objects.file_pieces(write=False)

    def test_native_data_registered_as_whole_file(self):
        self.assertEqual(self.native_file_rows(self.compiler_object()),
                         [("boot_elf", self.relative, 0x380000, 0x380000, "native.o", [self.name])])

    def test_text_only_native_not_registered_twice(self):
        self.assertEqual(self.native_file_rows(self.compiler_object(extra=False)), [])

    def test_nonzero_function_offset_not_registered(self):
        compiler_object = self.compiler_object()
        compiler_object["defined"][self.name] = 4
        self.assertEqual(self.native_file_rows(compiler_object), [])

    def pieces(self, compiler_object, values, whole=False):
        sections = [(".text", 0x380000, 8, 1, b"\0" * 8)]
        files = [("boot_elf", self.relative, 0x380000, 0x380000, "native.o", [self.name])] if whole else []
        placements = [] if whole else [("boot_elf", self.name, [("boot_elf", 0x380000)], self.relative, True)]
        with ExitStack() as stack:
            stack.enter_context(patch.object(c_objects, "read_index", return_value={("boot_elf", self.name): "native.o"}))
            stack.enter_context(patch.object(c_objects, "placements", return_value=placements))
            stack.enter_context(patch.object(c_objects, "read_files", return_value=files))
            stack.enter_context(patch.object(version_map, "Map", return_value=SimpleNamespace()))
            stack.enter_context(patch.object(version_map, "UsNames", return_value=SimpleNamespace(expected=lambda name: None)))
            stack.enter_context(patch.object(level_symbols, "read_object", return_value=compiler_object))
            stack.enter_context(patch.object(level_symbols, "derive", return_value=values))
            stack.enter_context(patch.object(asm_build, "function_starts", return_value={0x380000: self.name}))
            stack.enter_context(patch.object(asm_build, "find_data", return_value=None))
            return asm_build.c_pieces("boot_elf", sections)

    def test_native_wrong_address_rejected_for_text_object(self):
        pieces, symbols, dropped = self.pieces(self.compiler_object(extra=False), {"D_U_00200000": 0x200004})
        self.assertEqual(pieces, {})
        self.assertEqual(len(dropped), 1)
        self.assertIn("should be", dropped[0][2])

    def test_native_whole_object_uses_existing_data_link_path(self):
        pieces, symbols, dropped = self.pieces(self.compiler_object(), {"\u00a7.rodata": 0x310000}, whole=True)
        self.assertEqual(dropped, [])
        self.assertEqual(pieces[0x380000][4], [(".rodata", 0x310000)])
        self.assertEqual(pieces[0x380000][3], [self.name])

    def test_native_whole_object_rejects_wrong_named_address(self):
        pieces, symbols, dropped = self.pieces(self.compiler_object(),
                                              {"\u00a7.rodata": 0x310000, "D_U_00200000": 0x200004}, whole=True)
        self.assertEqual(pieces, {})
        self.assertEqual(len(dropped), 1)

    def test_native_whole_object_without_data_place_is_rejected(self):
        pieces, symbols, dropped = self.pieces(self.compiler_object(), {}, whole=True)
        self.assertEqual(pieces, {})
        self.assertEqual(len(dropped), 1)
        self.assertIn("neither read", dropped[0][2])


if __name__ == "__main__":
    unittest.main()
