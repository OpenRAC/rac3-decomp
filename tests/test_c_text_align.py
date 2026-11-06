"""ELF metadata trimming for native NTSC-U C without a game file or SDK."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from c_text_align import trim_four_aligned_function


NAME = "func_L39_005A3D9C"
BODY = bytes(range(36))


def example_object(padding=b"\0" * 4):
    """A minimal ELF32 MIPS compiler object: one 36-byte function plus alignment."""
    strings = b"\0" + NAME.encode("ascii") + b"\0"
    section_strings = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    text_at = 64
    symbols_at = text_at + 40
    strings_at = symbols_at + 32
    section_strings_at = strings_at + len(strings)
    headers_at = (section_strings_at + len(section_strings) + 3) & ~3
    data = bytearray(headers_at + 5 * 40)
    data[:16] = b"\x7fELF\x01\x01\x01" + b"\0" * 9
    struct.pack_into("<HHIIIIIHHHHHH", data, 16, 1, 8, 1, 0, 0, headers_at, 0,
                     52, 0, 0, 40, 5, 4)
    data[text_at:text_at + 40] = BODY + padding
    struct.pack_into("<IIIBBH", data, symbols_at + 16, 1, 0, 36, 0x12, 0, 1)
    data[strings_at:strings_at + len(strings)] = strings
    data[section_strings_at:section_strings_at + len(section_strings)] = section_strings
    section = lambda i, values: struct.pack_into("<IIIIIIIIII", data, headers_at + i * 40, *values)
    section(1, (section_strings.index(b".text"), 1, 6, 0, text_at, 40, 0, 0, 8, 0))
    section(2, (section_strings.index(b".symtab"), 2, 0, 0, symbols_at, 32, 3, 1, 4, 16))
    section(3, (section_strings.index(b".strtab"), 3, 0, 0, strings_at, len(strings), 0, 0, 1, 0))
    section(4, (section_strings.index(b".shstrtab"), 3, 0, 0, section_strings_at,
                len(section_strings), 0, 0, 1, 0))
    return bytes(data)


class TextAlignmentTest(unittest.TestCase):
    def test_trims_only_zero_padding_metadata(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "candidate.o"
            original = example_object()
            path.write_bytes(original)
            trim_four_aligned_function(path, NAME, 36)
            changed = path.read_bytes()
            headers_at = struct.unpack_from("<I", changed, 32)[0]
            text_header = headers_at + 40
            self.assertEqual((struct.unpack_from("<I", changed, text_header + 20)[0],
                              struct.unpack_from("<I", changed, text_header + 32)[0]), (36, 4))
            self.assertEqual(changed[64:100], BODY)
            self.assertEqual(struct.unpack_from("<I", changed, 104 + 16 + 8)[0], 36)
            self.assertEqual({i for i, (before, after) in enumerate(zip(original, changed)) if before != after},
                             {text_header + 20, text_header + 32})

    def test_rejects_nonzero_padding_without_mutating_object(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "candidate.o"
            original = example_object(b"\x01\0\0\0")
            path.write_bytes(original)
            with self.assertRaisesRegex(ValueError, "one zero alignment word"):
                trim_four_aligned_function(path, NAME, 36)
            self.assertEqual(path.read_bytes(), original)

    def test_rejects_truncated_elf(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "candidate.o"
            path.write_bytes(b"\x7fELF\x01\x01\x01")
            with self.assertRaisesRegex(ValueError, "requires little-endian ELF32"):
                trim_four_aligned_function(path, NAME, 36)


if __name__ == "__main__":
    unittest.main()
