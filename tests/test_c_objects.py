"""tools/c_objects.py: a whole PAL object moved to its NTSC-U place keeps its code pointers right."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import c_objects  # noqa: E402
import level_catalogue  # noqa: E402
import level_symbols  # noqa: E402
import srcfiles  # noqa: E402
import targets  # noqa: E402
import version_map  # noqa: E402


class SupplementalLevelTest(unittest.TestCase):
    def test_primary_and_supplement_share_one_compiled_object(self):
        pal, primary, extra = "func_L09_00381000", "func_L16_00397000", "func_L09_0037F000"
        owner = "src/levels/shared/owner.c"
        catalogue = [
            (primary, "shared", 24, "old", False, [(16, 0x397000), (31, 0x398000)]),
            (extra, "level", 24, "new", False, [(9, 0x37F000)]),
        ]
        states = {("levels", pal): ("C", owner, 24, 0x381000)}
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / "map.tsv"
            path.write_text(f"{pal}\tlevels\t{primary}\t16:00397000\t24\tC\tmatch\t100.00\told\n"
                            f"{pal}\tlevels\t{extra}\t09:0037F000\t24\tC\tmatch\t100.00\told\n")
            mapped = version_map.Map(path)
        with (patch.object(version_map, "Map", return_value=mapped),
              patch.object(version_map, "pal_states", return_value=states),
              patch.object(version_map, "us_sources", return_value={}),
              patch.object(level_catalogue, "read_catalogue", return_value=catalogue)):
            self.assertEqual(c_objects.placements(), [
                ("levels", pal, [("level_16", 0x397000), ("level_31", 0x398000), ("level_09", 0x37F000)],
                 owner, False),
            ])
            self.assertEqual(c_objects.map_rows(), {("levels", pal): mapped.rows[0]})
            self.assertEqual(mapped.us_place("levels", pal), (16, 0x397000, 24))
            self.assertEqual(mapped.us_place("levels", pal, 9), (9, 0x37F000, 24))
            self.assertEqual(mapped.us_place("levels", pal, 31), (31, 0x398000, 24))
            self.assertIsNone(mapped.us_place("levels", pal, 8))
            catalogue[1] = (*catalogue[1][:5], [(16, 0x37F000)])
            with self.assertRaisesRegex(ValueError, "multiple C placements"):
                c_objects.placements()

    def test_incomplete_supplement_preserves_primary_coverage(self):
        expected = {"level_09", "level_16", "level_31"}
        entry = (2, "level_09: table mismatches; C stays assembly")
        self.assertEqual(c_objects.carried_level_targets(entry, expected), {"level_16", "level_31"})
        self.assertIsNone(c_objects.carried_level_targets((2, ""), expected))
        self.assertIsNone(c_objects.carried_level_targets((2, "level_05: no object"), expected))


class NativeLevelNameTest(unittest.TestCase):
    def test_one_raw_spelling_can_name_two_distinct_c_objects(self):
        pal = "func_L06_00351718"
        incumbent_us = "func_L06_00350A20"
        native = "func_U_L06_00351718"
        owner = "src/levels/shared/incumbent.c"
        source = "src/us/levels/func_U_L06_00351718.c"
        old = [(6, 0x00350A20), (14, 0x00354DB0)]
        new = [(6, 0x00351718), (14, 0x00355B68)]
        catalogue = [(incumbent_us, "shared", 12, "old", False, old), (pal, "shared", 240, "new", False, new)]
        states = {("levels", pal): ("C", owner, 12, 0x00351718)}
        sources = {("levels", native): source}
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / "map.tsv"
            path.write_text(f"{pal}\tlevels\t{incumbent_us}\t06:00350A20\t12\tC\tmatch\t100.00\told\n"
                            f"-\tlevels\t{pal}\t06:00351718\t240\tC\tmatch\t100.00\tnew\n")
            mapped = version_map.Map(path)
        with (patch.object(version_map, "Map", return_value=mapped),
              patch.object(version_map, "pal_states", return_value=states),
              patch.object(version_map, "us_sources", return_value=sources),
              patch.object(level_catalogue, "read_catalogue", return_value=catalogue)):
            self.assertEqual(c_objects.placements(), [
                ("levels", pal, [("level_06", 0x00350A20), ("level_14", 0x00354DB0)], owner, False),
                ("levels", native, [("level_06", 0x00351718), ("level_14", 0x00355B68)], source, True),
            ])
            self.assertEqual(c_objects.map_rows(), {
                ("levels", pal): mapped.rows[0],
                ("levels", native): mapped.rows[1],
            })
            self.assertEqual(mapped.us_place("levels", pal), (6, 0x00350A20, 12))
            self.assertEqual(mapped.us_place("levels", native), (6, 0x00351718, 240))
            for number, address in new:
                names = version_map.NativeNames(number)
                self.assertEqual(names.expected(native), address)
                self.assertEqual(names.expected(pal), address)

    def test_legacy_names_and_duplicate_raw_definitions(self):
        legacy = ("levels", "func_L06_00351FA0")
        core = ("boot_elf", "func_U_003B4588")
        raw_core = ("boot_elf", "func_003B4588")
        sources = {legacy: "legacy.c", core: "core.c"}
        with patch.object(version_map, "us_sources", return_value=sources):
            self.assertEqual(version_map.native_sources_by_us_name(), {
                legacy: (legacy[1], "legacy.c"),
                raw_core: (core[1], "core.c"),
            })
            sources[("levels", "func_U_L06_00351FA0")] = "duplicate.c"
            with self.assertRaisesRegex(ValueError, "two NTSC-U C definitions"):
                version_map.native_sources_by_us_name()

    def test_same_symbol_in_two_source_files_is_an_error(self):
        name = "func_U_L06_00351718"
        with tempfile.TemporaryDirectory() as folder:
            sources = Path(folder) / "src/us/levels"
            sources.mkdir(parents=True)
            marker = f"/* localdecomp:start {name} */\n"
            (sources / "first.c").write_text(marker * 2)
            with (patch.object(version_map, "ROOT", folder),
                  patch.object(version_map, "US_SRC", str(sources.parent))):
                self.assertEqual(version_map.us_sources(), {("levels", name): "src/us/levels/first.c"})
                (sources / "second.c").write_text(marker)
                with self.assertRaisesRegex(ValueError, f"duplicate NTSC-U C symbol {name}"):
                    version_map.us_sources()


def elf(rodata_words, rel_offsets):
    """A minimal ELF32 little-endian relocatable: .text, .rodata (the words), .rel.rodata (one
    R_MIPS_32 entry per offset) and .shstrtab."""
    names = b"\0.text\0.rodata\0.rel.rodata\0.shstrtab\0"
    text = b"\0" * 8
    rodata = b"".join(struct.pack("<I", w) for w in rodata_words)
    rel = b"".join(struct.pack("<II", off, 2) for off in rel_offsets)
    body = bytearray(b"\0" * 0x34)
    offs = {}
    for key, blob in (("text", text), ("rodata", rodata), ("rel", rel), ("names", names)):
        offs[key] = len(body)
        body += blob
    while len(body) % 4:
        body += b"\0"
    shoff = len(body)
    secs = [
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        (names.index(b".text"), 1, 6, 0, offs["text"], len(text), 0, 0, 4, 0),          # alloc + exec
        (names.index(b".rodata"), 1, 2, 0, offs["rodata"], len(rodata), 0, 0, 4, 0),    # alloc
        (names.index(b".rel.rodata"), 9, 0, 0, offs["rel"], len(rel), 0, 2, 4, 8),      # REL for section 2
        (names.index(b".shstrtab"), 3, 0, 0, offs["names"], len(names), 0, 0, 1, 0),
    ]
    for s in secs:
        body += struct.pack("<IIIIIIIIII", *s)
    body[0:16] = b"\x7fELF\x01\x01\x01" + b"\0" * 9
    struct.pack_into("<HHIIIIIHHHHHH", body, 0x10, 1, 8, 1, 0, 0, shoff, 0, 0x34, 0, 0, 40, len(secs), 4)
    return bytes(body)


def rodata_words(blob, n):
    shoff = struct.unpack_from("<I", blob, 0x20)[0]
    off = struct.unpack_from("<IIIIIIIIII", blob, shoff + 40 * 2)[4]
    return [struct.unpack_from("<I", blob, off + 4 * i)[0] for i in range(n)]


class RebaseCodeWordsTest(unittest.TestCase):
    def run_rebase(self, words, rel_offsets, start, end, delta):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "f.o"
            path.write_bytes(elf(words, rel_offsets))
            changed = c_objects.rebase_code_words(str(path), start, end, delta)
            return changed, rodata_words(path.read_bytes(), len(words))

    def test_absolute_jump_table_moves_with_the_code(self):
        # an @ps2as jump table: absolute PAL label addresses, no relocation
        words = [0x003A0E04, 0x003A0DA8, 0x003A0E04]
        changed, out = self.run_rebase(words, [], 0x003A0C00, 0x003A0EBC, -0x5000)
        self.assertEqual(changed, 3)
        self.assertEqual(out, [0x0039BE04, 0x0039BDA8, 0x0039BE04])

    def test_relocated_words_and_other_values_stay(self):
        # word 0 has a relocation (the linker moves it), word 1 points outside the file's code,
        # word 2 is not word-aligned: none of them changes
        words = [0x003A0E04, 0x00400000, 0x003A0E06]
        changed, out = self.run_rebase(words, [0], 0x003A0C00, 0x003A0EBC, -0x5000)
        self.assertEqual(changed, 0)
        self.assertEqual(out, words)

    def test_no_move_no_change(self):
        changed, out = self.run_rebase([0x003A0E04], [], 0x003A0C00, 0x003A0EBC, 0)
        self.assertEqual((changed, out), (0, [0x003A0E04]))


class WholeCoreFileTest(unittest.TestCase):
    program = "i5bootn"
    source = "src/i5bootn/100000.c"
    start = 0x100000

    def file_rows(self, address, size, *, remnant=None, standalone_size=None):
        name = f"func_{address:08X}"
        key = (self.program, name)
        row = {"program": self.program, "pal": name, "state": "C", "status": "match",
               "place": f"{address:08X}", "size": size}
        rows = [row]
        if remnant:
            rows.append({"program": self.program, "pal": "func_00100010", "state": remnant,
                         "status": "none", "place": "-"})
        unit = SimpleNamespace(end=self.start + 64)
        target = SimpleNamespace(path=lambda kind: self.program, unit_for=lambda at: unit,
                                 workdir=lambda u: "build/i5bootn/src/i5bootn")
        program_targets = dict.fromkeys(c_objects.CORE, target)
        built = {key: "standalone.o"} if standalone_size is not None else {}
        with patch.object(targets, "TARGETS", program_targets), \
                patch.object(srcfiles, "read_file_list", return_value=[(self.source, self.start)]), \
                patch.object(version_map, "Map", return_value=SimpleNamespace(by_pal={key: row}, rows=rows)), \
                patch.object(version_map, "pal_states", return_value={key: ("C", self.source, size, address)}), \
                patch.object(version_map, "us_sources", return_value={}), \
                patch.object(c_objects, "read_index", return_value=built), \
                patch.object(c_objects.os.path, "exists", return_value=True), \
                patch.object(level_symbols, "read_object",
                             return_value={"text": bytes(standalone_size or 0), "extra": []}):
            return c_objects.file_pieces(write=False)

    def test_unpaired_remnant_leaves_full_object_validation_to_linker(self):
        rows = self.file_rows(self.start, 12, remnant="LINKER_REMNANT")
        self.assertEqual([(row[1], row[3]) for row in rows], [(self.source, self.start)])
        self.assertEqual(self.file_rows(self.start, 12, remnant="C"), [])

    def test_four_mod_eight_partial_object_gets_whole_file_fallback(self):
        rows = self.file_rows(self.start + 4, 12, standalone_size=4)
        self.assertEqual([(row[1], row[3]) for row in rows], [(self.source, self.start)])
        self.assertEqual(self.file_rows(self.start + 4, 12, standalone_size=12), [])

    def test_aligned_prefix_object_gets_whole_file_fallback(self):
        rows = self.file_rows(self.start, 60, standalone_size=8)
        self.assertEqual([(row[1], row[3]) for row in rows], [(self.source, self.start)])
        self.assertEqual(self.file_rows(self.start, 60, standalone_size=60), [])
        self.assertEqual(self.file_rows(self.start, 60, standalone_size=64), [])


if __name__ == "__main__":
    unittest.main()
