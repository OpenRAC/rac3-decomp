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
import level_symbols  # noqa: E402
import srcfiles  # noqa: E402
import targets  # noqa: E402
import version_map  # noqa: E402


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
        unit = SimpleNamespace(end=self.start + 32)
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


if __name__ == "__main__":
    unittest.main()
