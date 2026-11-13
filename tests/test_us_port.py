"""Unit tests for tools/us_port.py's constant substitution (no toolchain, no game data).

  python3 -m unittest discover -s tests
"""
import sys
import unittest
from pathlib import Path

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


if __name__ == "__main__":
    unittest.main()
