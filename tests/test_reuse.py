"""Unit tests for the reuse of unchanged work: tools/c_objects.py's stored results and
tools/setup_asm.py's skipped level setup (tools/stamps.py). No toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import argparse
import os
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import c_objects  # noqa: E402
import setup_asm  # noqa: E402
import stamps  # noqa: E402


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\n") as f:
        f.write(text)


class StampsTest(unittest.TestCase):
    def test_content_names_exclusions_and_missing_paths(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "a", "x.txt"), "one")
            write(os.path.join(d, "a", "y.txt"), "two")
            write(os.path.join(d, "a", "__pycache__", "x.pyc"), "cache")
            base = stamps.of([os.path.join(d, "a")], root=d)
            write(os.path.join(d, "a", "__pycache__", "x.pyc"), "other cache")
            self.assertEqual(stamps.of([os.path.join(d, "a")], root=d), base)
            write(os.path.join(d, "a", "y.txt"), "three")
            self.assertNotEqual(stamps.of([os.path.join(d, "a")], root=d), base)
            ex = stamps.of([os.path.join(d, "a")], exclude=[os.path.join(d, "a", "y.txt")], root=d)
            write(os.path.join(d, "a", "y.txt"), "four")
            self.assertEqual(stamps.of([os.path.join(d, "a")], exclude=[os.path.join(d, "a", "y.txt")], root=d), ex)
            # a renamed file is a change; a missing path is hashed as missing
            os.rename(os.path.join(d, "a", "x.txt"), os.path.join(d, "a", "z.txt"))
            self.assertNotEqual(stamps.of([os.path.join(d, "a")], exclude=[os.path.join(d, "a", "y.txt")], root=d), ex)
            self.assertNotEqual(stamps.of([os.path.join(d, "nothing")], root=d), stamps.of([], root=d))
            self.assertEqual(stamps.file_sha1(os.path.join(d, "nothing")), "-")

    def test_tool_closure_follows_imports_within_tools(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "main.py"), "import os, helper\nfrom sub import x\n")
            write(os.path.join(d, "helper.py"), "def f():\n    import deep\n")
            write(os.path.join(d, "deep.py"), "")
            write(os.path.join(d, "sub.py"), "x = 1\n")
            write(os.path.join(d, "unused.py"), "")
            got = [os.path.basename(p) for p in stamps.tool_closure([os.path.join(d, "main.py")], dirs=[d])]
            self.assertEqual(got, ["deep.py", "helper.py", "main.py", "sub.py"])

    def test_setup_closure_has_the_tools_it_runs(self):
        got = {os.path.basename(p) for p in stamps.tool_closure(
            [str(ROOT / "tools" / "setup_asm.py")] + [str(ROOT / "tools" / s) for s in setup_asm.RUN_SCRIPTS])}
        self.assertTrue({"setup_asm.py", "targets.py", "srcfiles.py", "trailing_padding.py", "fix_reg_names.py",
                         "gen_level_targets.py", "levels.py", "level_catalogue.py"} <= got)


def row(**kw):
    r = {"pal": "func_L01_00300000", "program": "levels", "us": "func_L01_00300100", "place": "01:00300100",
         "size": 64, "state": "C", "status": "match", "closeness": 100.0, "hash": "aaaaaaaaaaaa"}
    r.update(kw)
    return r


def file_inputs(root, **kw):
    """A c_objects.FileInputs over ROOT with its tables given (no repository files read)."""
    f = c_objects.FileInputs.__new__(c_objects.FileInputs)
    f.root, f.cache = root, {}
    f.level_parts, f.us_parts = kw.get("level_parts", {}), kw.get("us_parts", {})
    f.core_parts, f.core_files = kw.get("core_parts", {}), kw.get("core_files", {})
    f.all_parts, f.rows = kw.get("all_parts", "all"), kw.get("rows", {})
    f._earlier = kw.get("earlier", {})
    return f


class CObjectsKeyTest(unittest.TestCase):
    ITEM = ("levels", "func_L01_00300000", [("level_01", 0x300100)], "src/levels/01/a.c", False)

    def key(self, files, rows=None, item=None, gkey="g"):
        rows = {("levels", "func_L01_00300000"): row()} if rows is None else rows
        return c_objects.item_key(item or self.ITEM, gkey, rows, files)

    def test_the_file_its_flags_and_its_rows(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "src/levels/01/a.c"), "void func_L01_00300000(void) { }\n")
            write(os.path.join(d, "src/levels/01/b.c"), "void func_L01_00300200(void) { }\n")
            parts = {"src/levels/01/a.c": "-O2 -G8"}
            rows = {"func_L01_00300000": ["config/levels/divs_nops.txt: func_L01_00300000 2"],
                    "func_L01_00300200": ["config/levels/divs_nops.txt: func_L01_00300200 1"]}
            base = self.key(file_inputs(d, level_parts=parts, rows=rows))
            self.assertEqual(self.key(file_inputs(d, level_parts=parts, rows=rows)), base)
            # another file's text, flags line or table rows: not this function's
            write(os.path.join(d, "src/levels/01/b.c"), "void func_L01_00300200(void) { int x; }\n")
            other = dict(parts, **{"src/levels/01/b.c": "-O1"})
            rows2 = dict(rows, func_L01_00300200=["config/levels/divs_nops.txt: func_L01_00300200 3"])
            self.assertEqual(self.key(file_inputs(d, level_parts=other, rows=rows2)), base)
            # its own file's text, its flags line, its rows, its map row, the global part
            self.assertNotEqual(self.key(file_inputs(d, level_parts={"src/levels/01/a.c": "-O1"}, rows=rows)), base)
            rows3 = dict(rows, func_L01_00300000=["config/levels/divs_nops.txt: func_L01_00300000 1"])
            self.assertNotEqual(self.key(file_inputs(d, level_parts=parts, rows=rows3)), base)
            self.assertNotEqual(self.key(file_inputs(d, level_parts=parts, rows=rows),
                                         rows={("levels", "func_L01_00300000"): row(status="nomatch")}), base)
            self.assertNotEqual(self.key(file_inputs(d, level_parts=parts, rows=rows), gkey="h"), base)
            write(os.path.join(d, "src/levels/01/a.c"), "void func_L01_00300000(void) { return; }\n")
            self.assertNotEqual(self.key(file_inputs(d, level_parts=parts, rows=rows)), base)
            os.remove(os.path.join(d, "src/levels/01/a.c"))
            self.assertNotEqual(self.key(file_inputs(d, level_parts=parts, rows=rows)), base)

    def test_a_core_file_has_its_flag_lines_and_the_earlier_declarations(self):
        item = ("frontbin", "func_00381140", [("frontbin", 0x381140)], "src/frontbin/b.c", False)
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "src/frontbin/b.c"), "void func_00381140(void) { }\n")
            files = {("frontbin", "src/frontbin/a.c"): (0x381000, 0x381140),
                     ("frontbin", "src/frontbin/b.c"): (0x381140, 0x382000)}
            parts = [(0x381000, "0x00381000 -O2"), (0x381140, "0x00381140 -O2 -G8"), (0x382000, "0x00382000 -O1")]
            kw = dict(core_files=files, earlier={("frontbin", "src/frontbin/b.c"): "e1"})
            rows = {("frontbin", "func_00381140"): row(pal="func_00381140", program="frontbin")}
            base = self.key(file_inputs(d, core_parts={"frontbin": parts}, **kw), rows=rows, item=item)
            # the line of the next file is not its own
            parts2 = parts[:2] + [(0x382000, "0x00382000 -O0")]
            self.assertEqual(self.key(file_inputs(d, core_parts={"frontbin": parts2}, **kw), rows=rows, item=item), base)
            parts3 = [parts[0], (0x381140, "0x00381140 -O1"), parts[2]]
            self.assertNotEqual(self.key(file_inputs(d, core_parts={"frontbin": parts3}, **kw), rows=rows, item=item),
                                base)
            kw2 = dict(core_files=files, earlier={("frontbin", "src/frontbin/b.c"): "e2"})
            self.assertNotEqual(self.key(file_inputs(d, core_parts={"frontbin": parts}, **kw2), rows=rows, item=item),
                                base)

    def test_map_projection_ignores_what_a_match_changes(self):
        base = c_objects.map_projection([row()])
        self.assertEqual(c_objects.map_projection([row(state="INCLUDE_ASM", status="asm", closeness=0.0,
                                                       hash="-")]), base)
        self.assertNotEqual(c_objects.map_projection([row(place="01:00300108")]), base)
        self.assertNotEqual(c_objects.map_projection([row(us="func_L01_00300108")]), base)
        self.assertNotEqual(c_objects.map_projection([row(size=68)]), base)
        self.assertNotEqual(c_objects.map_projection([row(state="near")]), base)

    def test_global_key_has_the_toolchain_options_and_environment(self):
        from unittest.mock import patch
        a = argparse.Namespace(toolchain=None, runner=None, ee29=None, ee296=None, eeas=None)
        base = c_objects.global_key(a)
        self.assertEqual(c_objects.global_key(a), base)
        with patch.dict(os.environ, {"UYA_REUSE_TEST": "1"}):
            self.assertNotEqual(c_objects.global_key(a), base)
        self.assertNotEqual(c_objects.global_key(argparse.Namespace(toolchain="/elsewhere", runner=None, ee29=None,
                                                                    ee296=None, eeas=None)), base)

    def test_reuse_needs_the_same_key_and_the_same_object(self):
        with tempfile.TemporaryDirectory() as d:
            obj = os.path.join(d, "f.o")
            write(obj, "object")
            sha = stamps.file_sha1(obj)
            stored = ("k", "build/us/cobj/levels/f.o", sha, "ok")
            self.assertEqual(c_objects.reusable(stored, "k", obj), ("build/us/cobj/levels/f.o", "ok"))
            self.assertIsNone(c_objects.reusable(stored, "other", obj))
            self.assertIsNone(c_objects.reusable(None, "k", obj))
            write(obj, "changed")
            self.assertIsNone(c_objects.reusable(stored, "k", obj))
            os.remove(obj)
            self.assertIsNone(c_objects.reusable(stored, "k", obj))
            # a function left as assembly whose check removed its object: reused while it stays absent
            gone = ("k", "-", "-", "no compile of the block alone gives MATCH")
            self.assertEqual(c_objects.reusable(gone, "k", obj), ("-", gone[3]))
            write(obj, "stale")
            self.assertIsNone(c_objects.reusable(gone, "k", obj))

    def test_results_round_trip_and_the_last_line_wins(self):
        with tempfile.TemporaryDirectory() as d:
            path = os.path.join(d, "results.tsv")
            c_objects.write_results({("levels", "f"): ("k1", "-", "-", "why")}, path)
            with open(path, "a") as f:
                f.write("levels\tf\tk2\tbuild/x.o\tabc\tok\n")
            self.assertEqual(c_objects.read_results(path), {("levels", "f"): ("k2", "build/x.o", "abc", "ok")})


class SetupSkipTest(unittest.TestCase):
    META = {"key": "k", "cuts": [["func_00300000", "asm/x", 2]], "from_splat": ["build/u.txt"], "files": []}

    def test_skip_reason(self):
        cuts = [["func_00300000", "asm/x", 2]]
        self.assertIsNone(setup_asm.skip_reason(self.META, "k", cuts, []))
        self.assertIsNone(setup_asm.skip_reason(self.META, "k", cuts, ["build/u.txt"]))
        self.assertEqual(setup_asm.skip_reason(None, "k", cuts, []), "no stored setup")
        self.assertEqual(setup_asm.skip_reason(self.META, "other", cuts, []), "its inputs changed")
        self.assertIn("trailing nops", setup_asm.skip_reason(self.META, "k", [], []))
        self.assertIn("build/v.txt", setup_asm.skip_reason(self.META, "k", cuts, ["build/v.txt"]))

    def test_splat_names_ignore_c_code_but_not_the_macros(self):
        try:
            import splat.segtypes.common.c  # noqa: F401
        except ImportError:
            self.skipTest("splat is not installed")
        asm = b'INCLUDE_ASM("asm/levels/x/text", func_00300000);\nINCLUDE_ASM("asm/levels/x/text", func_00300040);\n'
        stub = b'\nINCLUDE_ASM("asm/levels/x/text", func_00300040);\n'
        c = b'/* localdecomp:start func_00300040 */\nvoid func_00300040(int a) {\n    a++;\n}\n' \
            b'/* localdecomp:end func_00300040 */\n'
        before = setup_asm.splat_names(asm)
        # the function matched: C in its place, its stub at the end of the temporary file
        after = setup_asm.splat_names(asm.split(b"\n")[0] + b"\n" + c + stub)
        self.assertEqual(after, before)
        self.assertNotEqual(setup_asm.splat_names(asm.replace(b"func_00300040", b"func_00300048")), before)
        self.assertNotEqual(setup_asm.splat_names(asm + b'INCLUDE_RODATA("asm/levels/x/rodata", D_00400000);\n'),
                            before)
        # a C function splat sees without an INCLUDE_ASM of its own is marked defined: a change
        self.assertNotEqual(setup_asm.splat_names(asm + b"static void helper(void) {\n}\n"), before)


if __name__ == "__main__":
    unittest.main()
