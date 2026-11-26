"""asm_filter.insn_count: how many words Ps2EeAs gives an `la` macro."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import asm_filter  # noqa: E402


class LaCountTest(unittest.TestCase):
    LINES = ["\tla\t$a0,D_001D4B08", "\tjal\tfunc_00122A10"]

    def test_la_of_an_unknown_global_is_two_words_under_ps2as_reorder(self):
        # lui + addiu, and the jal's own delay-slot nop in reorder mode
        self.assertEqual(asm_filter.insn_count(self.LINES, noreorder=False, ps2as=True), 4)

    def test_la_stays_unknown_otherwise(self):
        self.assertIsNone(asm_filter.insn_count(self.LINES, noreorder=False, ps2as=False))
        self.assertIsNone(asm_filter.insn_count(self.LINES, noreorder=True, ps2as=True))
        self.assertIsNone(asm_filter.insn_count(self.LINES, noreorder=False, ps2as=True,
                                                small=frozenset({"D_001D4B08"})))


if __name__ == "__main__":
    unittest.main()
