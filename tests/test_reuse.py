"""Unit tests for the reuse of unchanged work: tools/c_objects.py's stored results and
tools/setup_asm.py's skipped level setup (tools/stamps.py). No toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import argparse
import os
import sys
import tempfile
import time
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


FILE_INPUTS = c_objects.FileInputs       # the class, also while a test patches the name


def file_inputs(root, **kw):
    """A c_objects.FileInputs over ROOT with its tables given (no repository files read)."""
    f = FILE_INPUTS.__new__(FILE_INPUTS)
    f.root, f.cache = root, {}
    f.level_parts, f.us_parts = kw.get("level_parts", {}), kw.get("us_parts", {})
    f.core_parts, f.core_files = kw.get("core_parts", {}), kw.get("core_files", {})
    f.all_parts, f.rows = kw.get("all_parts", "all"), kw.get("rows", {})
    f._earlier = kw.get("earlier", {})
    import includes
    f._earlier_includes, f._header_sums = kw.get("earlier_includes", {}), {}
    f._inputs, f._file_lists = {}, {}
    f.scanner = includes.Scanner(root, kw.get("system", ()))
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


class IncludesTest(unittest.TestCase):
    """tools/includes.py: a superset of what the preprocessor and the assembler open."""

    def tree(self, d, files):
        for rel, text in files.items():
            write(os.path.join(d, rel), text)

    def test_directives_ignore_conditions_and_comments_and_take_every_spelling(self):
        import includes
        text = ('#include "a.h"\n#if 0\n  #  include <b.h> /* off */\n#endif\n/*\n#include "c.h"\n*/\n'
                '%:include "d.h"\n#include_next "e.h"\n#import "f.h"\n#include MACRO\n'
                '__asm__(".include \\"g.inc\\"\\n");\n    ".include \\"" FOLDER "/" #NAME ".s\\"\\n"\n')
        self.assertEqual(includes.directives(text), [
            ("quote", "a.h"), ("angle", "b.h"), ("quote", "c.h"), ("quote", "d.h"), ("quote", "e.h"),
            ("quote", "f.h"), ("quote", None), ("asm", "g.inc")])

    def test_every_folder_searched_and_every_level_followed(self):
        import includes
        with tempfile.TemporaryDirectory() as d:
            self.tree(d, {"include/one.h": '#include "two.h"\n', "include/two.h": "#ifdef X\n#include <sub/three.h>\n#endif\n",
                          "include/sub/three.h": '__asm__(".include \\"include/m.inc\\"");\n',
                          "include/m.inc": '.include "n.inc"\n', "include/n.inc": "", "include/unused.h": ""})
            got = dict(includes.Scanner(d).scan([('#include "one.h"\n', None)]))
            rel = {os.path.relpath(p, d): e for p, e in got.items()}
            for f in ("include/one.h", "include/two.h", "include/sub/three.h", "include/m.inc", "include/n.inc"):
                self.assertTrue(rel[f], f)
            self.assertNotIn("include/unused.h", rel)
            # where a file would take precedence if it were created: hashed as missing
            for f in ("one.h", "two.h", "sub/three.h", "include/sub/include/m.inc", "include/include/m.inc"):
                self.assertIs(rel.get(f), False, f)
            self.assertIsNone(includes.Scanner(d).scan([("#include HEADER\n", None)]))
            # names this scan cannot read as the compilers do: every header
            for text in ('__asm__(".include \\"include\\\\m.inc\\"");\n', '#include "C:/x/one.h"\n',
                         '#include "\\include\\one.h"\n', '#include ".../one.h"\n', '#include "on\xe9.h"\n'):
                self.assertIsNone(includes.Scanner(d).scan([(text, None)]), text)


class HeaderKeyTest(unittest.TestCase):
    """The headers in a function's key: its own includes, at any depth, and nothing else."""
    ITEM = ("levels", "func_L01_00300000", [("level_01", 0x300100)], "src/levels/01/a.c", False)
    HEADERS = {"include/common.h": '#include "include_asm.h"\n', "include/include_asm.h": "#define X 1\n",
               "include/structs/hero.h": '#include "vector.h"\n', "include/structs/vector.h": "typedef int v;\n",
               "include/vu0.h": "#define qzero(x) x = 0\n", "include/names.h": "/* func_00300000 tidy */\n"}

    def keys(self, d, items, **kw):
        files = file_inputs(d, **kw)
        rows = {(i[0], i[1]): row(pal=i[1]) for i in items}
        return [c_objects.item_key(i, "g", rows, files) for i in items]

    def test_a_header_counts_where_it_is_included_and_only_there(self):
        b = ("levels", "func_L01_00300200", [("level_01", 0x300300)], "src/levels/01/b.c", False)
        c = ("levels", "func_L01_00300400", [("level_01", 0x300500)], "src/levels/01/c.c", False)
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, self.ITEM[3]), '#include "common.h"\n#include "structs/hero.h"\nvoid f(void) { }\n')
            write(os.path.join(d, b[3]), '#include "common.h"\n#include "vu0.h"\nvoid g(void) { }\n')
            # no #include at all: the check adds common.h
            write(os.path.join(d, c[3]), 'void h(void) { }\n')
            items = [self.ITEM, b, c]
            base = self.keys(d, items)
            self.assertEqual(self.keys(d, items), base)

            def changed(rel, text):
                old = open(os.path.join(d, rel)).read()
                write(os.path.join(d, rel), text)
                got = [k != b for k, b in zip(self.keys(d, items), base)]
                write(os.path.join(d, rel), old)
                self.assertEqual(self.keys(d, items), base)
                return got
            # one level (a's own include), two levels (hero.h includes vector.h)
            self.assertEqual(changed("include/structs/hero.h", "typedef int h;\n#include \"vector.h\"\n"),
                             [True, False, False])
            self.assertEqual(changed("include/structs/vector.h", "typedef long v;\n"), [True, False, False])
            # a macro the function's code expands
            self.assertEqual(changed("include/vu0.h", "#define qzero(x) x = 1\n"), [False, True, False])
            # through common.h, which the check puts in front of every function
            self.assertEqual(changed("include/include_asm.h", "#define X 2\n"), [True, True, True])
            # a header no function includes (names.h is a lookup table nothing includes)
            self.assertEqual(changed("include/names.h", "/* func_00300000 tidy */\n/* func_00300200 neat */\n"),
                             [False, False, False])
            # creating a header where the preprocessor would find it first is a change
            write(os.path.join(d, "structs/hero.h"), "typedef int shadow;\n")
            self.assertEqual([k != b for k, b in zip(self.keys(d, items), base)], [True, False, False])

    def test_a_core_function_has_the_includes_of_the_files_before_it(self):
        item = ("frontbin", "func_00381140", [("frontbin", 0x381140)], "src/frontbin/b.c", False)
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, "src/frontbin/b.c"), '#include "common.h"\nvoid func_00381140(void) { }\n')
            rows = {("frontbin", "func_00381140"): row(pal="func_00381140", program="frontbin")}
            import includes
            before = file_inputs(d, earlier_includes={("frontbin", "src/frontbin/b.c"): frozenset(
                includes.includes_of('#include "vu0.h"\n'))})
            base = c_objects.item_key(item, "g", rows, before)
            write(os.path.join(d, "include/vu0.h"), "#define qzero(x) x = 2\n")
            again = file_inputs(d, earlier_includes=before._earlier_includes)
            self.assertNotEqual(c_objects.item_key(item, "g", rows, again), base)
            alone = file_inputs(d)
            k = c_objects.item_key(item, "g", rows, alone)
            write(os.path.join(d, "include/vu0.h"), "#define qzero(x) x = 3\n")
            self.assertEqual(c_objects.item_key(item, "g", rows, file_inputs(d)), k)

    # every spelling of include/structs/hero.h that a compiler opens (scratch/orch/batch/FIXES.md,
    # item 4: SN's ee-gcc 2.95.3 and Sony's 2.9-ee under wibo take each of these; Sony's 2.96 cpp0
    # only the exact one)
    SPELLINGS = ['"Structs/Hero.h"', '"structs\\hero.h"', '"STRUCTS\\HERO.H"', '<Structs/Hero.h>',
                 '<structs\\hero.h>', '"structs/hero.h."', '"structs./hero.h"', '"INCLUDE/structs/hero.h"',
                 '"include\\\\structs\\\\hero.h"', '"./Structs/../STRUCTS/hero.H"']

    def test_every_spelling_a_compiler_accepts_is_followed(self):
        for spell in self.SPELLINGS:
            with self.subTest(spell=spell), tempfile.TemporaryDirectory() as d:
                for rel, text in self.HEADERS.items():
                    write(os.path.join(d, rel), text)
                write(os.path.join(d, self.ITEM[3]), '#include "common.h"\n#include %s\nvoid f(void) { }\n' % spell)
                base = self.keys(d, [self.ITEM])
                # the header itself, and the one it includes
                write(os.path.join(d, "include/structs/hero.h"), '#include "vector.h"\ntypedef int pad;\n')
                after_hero = self.keys(d, [self.ITEM])
                self.assertNotEqual(after_hero, base)
                write(os.path.join(d, "include/structs/vector.h"), "typedef long v;\n")
                self.assertNotEqual(self.keys(d, [self.ITEM]), after_hero)

    def test_a_file_of_another_case_where_a_compiler_would_open_it(self):
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, "include/structs/hero.h"), '#include "vector.h"\n#include "common.h"\n')
            write(os.path.join(d, self.ITEM[3]), '#include "structs/hero.h"\nvoid f(void) { }\n')
            base = self.keys(d, [self.ITEM])
            # hero.h's "common.h" is looked for in include/structs/ first: wibo opens COMMON.H there
            write(os.path.join(d, "include/structs/COMMON.H"), "#define SHADOW 1\n")
            shadowed = self.keys(d, [self.ITEM])
            self.assertNotEqual(shadowed, base)
            write(os.path.join(d, "include/structs/COMMON.H"), "#define SHADOW 2\n")
            self.assertNotEqual(self.keys(d, [self.ITEM]), shadowed)

    def test_an_assembler_include_in_another_case(self):
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, "include/macro.inc"), ".set noat\n")
            write(os.path.join(d, self.ITEM[3]), '__asm__(".include \\"INCLUDE/MACRO.INC\\"\\n");\nvoid f(void) { }\n')
            base = self.keys(d, [self.ITEM])
            write(os.path.join(d, "include/macro.inc"), ".set at\n")
            self.assertNotEqual(self.keys(d, [self.ITEM]), base)

    def test_a_toolchain_headers_own_includes_are_followed(self):
        import includes
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            tc = os.path.join(d, "toolchain")
            write(os.path.join(tc, "lib/gcc-lib/ee/2.95.3/stddef.h"), '#include <machine/types.h>\n#include "sub.h"\n')
            write(os.path.join(tc, "bin/ee-gcc2953.exe"), "")
            system = includes.toolchain_dirs([tc, None, os.path.join(d, "no such folder")])
            self.assertIn(os.path.join(tc, "lib/gcc-lib/ee/2.95.3"), system)
            write(os.path.join(d, self.ITEM[3]), '#include "common.h"\n#include <stddef.h>\nvoid f(void) { }\n')
            base = self.keys(d, [self.ITEM], system=system)
            # <machine/types.h> of the toolchain's stddef.h is looked for in include/ (and the root) first
            for rel in ("include/machine/types.h", "machine/types.h", "include/sub.h"):
                with self.subTest(created=rel):
                    write(os.path.join(d, rel), "typedef int t;\n")
                    created = self.keys(d, [self.ITEM], system=system)
                    self.assertNotEqual(created, base)
                    write(os.path.join(d, rel), "typedef long t;\n")
                    self.assertNotEqual(self.keys(d, [self.ITEM], system=system), created)
                    os.remove(os.path.join(d, rel))
                    self.assertEqual(self.keys(d, [self.ITEM], system=system), base)

    def test_an_include_with_a_parent_folder_part_takes_every_header(self):
        # under wibo `nonexist/../structs/hero.h` opens include/structs/hero.h though nonexist/ is not there
        # (scratch/orch/batch/RECHECK.md, item 4): a name with `..` is not followed, so every header counts
        for spell in ('"nonexist/../Structs/Hero.h"', '"nonexist\\..\\structs\\hero.h"', '<structs/../structs/hero.h>'):
            with self.subTest(spell=spell), tempfile.TemporaryDirectory() as d:
                for rel, text in self.HEADERS.items():
                    write(os.path.join(d, rel), text)
                write(os.path.join(d, self.ITEM[3]), '#include "common.h"\n#include %s\nvoid f(void) { }\n' % spell)
                base = self.keys(d, [self.ITEM])
                write(os.path.join(d, "include/structs/hero.h"), '#include "vector.h"\ntypedef int pad;\n')
                after_hero = self.keys(d, [self.ITEM])
                self.assertNotEqual(after_hero, base)
                write(os.path.join(d, "include/names.h"), "/* another name */\n")
                self.assertNotEqual(self.keys(d, [self.ITEM]), after_hero)

    def test_an_include_that_cannot_be_followed_takes_every_header(self):
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, self.ITEM[3]), '#define H "structs/hero.h"\n#include H\nvoid f(void) { }\n')
            base = self.keys(d, [self.ITEM])
            write(os.path.join(d, "include/names.h"), "/* another name */\n")
            self.assertNotEqual(self.keys(d, [self.ITEM]), base)


class WatchTest(unittest.TestCase):
    """c_objects.Watch: a result is stored only when nothing its key read changed during the run."""

    def test_a_change_a_change_undone_and_a_new_file_count(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "include/a.h"), "one\n")
            write(os.path.join(d, "include/b.h"), "two\n")
            w = c_objects.Watch()
            paths = w.note_tree(os.path.join(d, "include"))
            self.assertIsNone(w.changed(paths))
            a = os.path.join(d, "include", "a.h")
            # at once and of the same size: seen only because a path is noted when its times are in the past
            # (Watch.RACY_NS; without that this failed on a machine whose /tmp keeps times by the clock tick)
            write(a, "ONE\n")
            self.assertEqual(w.changed(paths), a)
            # the same bytes again: still a change (the check may have read the other ones)
            write(a, "one\n")
            self.assertEqual(w.changed(paths), a)
            w2 = c_objects.Watch()
            paths = w2.note_tree(os.path.join(d, "include"))
            missing = w2.note(os.path.join(d, "include", "c.h"))
            write(os.path.join(d, "include", "c.h"), "")
            self.assertEqual(w2.changed([missing]), missing)
            self.assertEqual(w2.changed(paths), os.path.join(d, "include"))     # its listing changed

    def test_a_path_is_noted_only_when_its_times_are_in_the_past(self):
        with tempfile.TemporaryDirectory() as d:
            a = os.path.join(d, "a.h")
            write(a, "one\n")
            w = c_objects.Watch()
            w.note(a)
            st = os.stat(a)
            self.assertGreaterEqual(time.time_ns() - max(st.st_mtime_ns, st.st_ctime_ns), w.RACY_NS)
            for text in ("ONE\n", "one\n", "oNe\n"):          # same size, one straight after the other
                write(a, text)
                self.assertEqual(w.changed([a]), a)

    def test_main_stores_only_results_whose_inputs_did_not_change(self):
        from unittest.mock import patch
        a = ("levels", "func_L01_00300000", [("level_01", 0x300100)], "src/levels/01/a.c", False)
        b = ("levels", "func_L01_00300200", [("level_01", 0x300300)], "src/levels/01/b.c", False)
        c = ("levels", "func_L01_00300400", [("level_01", 0x300500)], "src/levels/01/c.c", False)
        with tempfile.TemporaryDirectory() as d:
            for rel, text in HeaderKeyTest.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, a[3]), '#include "common.h"\n#include "structs/hero.h"\nvoid f(void) { }\n')
            write(os.path.join(d, b[3]), '#include "common.h"\nvoid g(void) { }\n')
            write(os.path.join(d, c[3]), '#include "common.h"\n#include "vu0.h"\nvoid h(void) { }\n')
            hero, vu0 = os.path.join(d, "include/structs/hero.h"), os.path.join(d, "include/vu0.h")

            def compile_one(item, args, tmp, notes=None, run=None):
                # what lands during each check: a's header is edited, c's edited and put back
                if item is a:
                    write(hero, "typedef int other;\n")
                if item is c:
                    old = open(vu0).read()
                    write(vu0, "#define qzero(x) x = 9\n")
                    write(vu0, old)
                return item, "-", "no compile of the block alone gives MATCH"

            def watch_tree():
                w = c_objects.Watch()
                w.note_tree(d)
                return w
            out, reuse = os.path.join(d, "build/cobj"), os.path.join(d, "build/reuse")
            from io import StringIO
            printed = StringIO()
            with patch.multiple(c_objects, OUT=out, INDEX=os.path.join(out, "index.tsv"), REUSE=reuse,
                                RESULTS=os.path.join(reuse, "r.tsv"), placements=lambda: [a, b, c],
                                global_key=lambda args: "g", map_rows=lambda: {}, watch_tree=watch_tree,
                                global_inputs=lambda args, w: (), FileInputs=lambda **kw: file_inputs(d),
                                compile_one=compile_one), \
                    patch.object(sys, "argv", ["c_objects.py", "--toolchain", d, "-j", "1", "level_01"]), \
                    patch("sys.stdout", printed):
                c_objects.main()
            results = c_objects.read_results(os.path.join(reuse, "r.tsv"))
            self.assertEqual(sorted(results), [("levels", "func_L01_00300200")])
            self.assertRegex(printed.getvalue(), r"func_L01_00300000: [^\n]*; not stored: \S*include/structs/hero.h "
                                                 r"changed during the run")
            self.assertRegex(printed.getvalue(), r"func_L01_00300400: [^\n]*; not stored: \S*include/vu0.h "
                                                 r"changed during the run")
            self.assertNotIn("func_L01_00300200: no compile of the block alone gives MATCH; not stored", printed.getvalue())


    def test_main_stores_nothing_checked_after_a_global_input_changed(self):
        from io import StringIO
        from unittest.mock import patch
        items = [("levels", "func_L01_0030000%d" % i, [("level_01", 0x300000 + 8 * i)], "src/levels/01/a.c", False)
                 for i in range(3)]
        with tempfile.TemporaryDirectory() as d:
            for rel, text in HeaderKeyTest.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, items[0][3]), '#include "common.h"\nvoid f(void) { }\n')
            table = os.path.join(d, "config/levels/text_parts.txt")
            write(table, "src/levels/01/a.c\t-O2 -G8\n")

            def compile_one(item, args, tmp, notes=None, run=None):
                if item is items[1]:                     # a table every key reads changes
                    write(table, "src/levels/01/a.c\t-O1 -G8\n")
                return item, "-", "no compile of the block alone gives MATCH"

            def global_inputs(args, w):
                return (w.note(table),)
            out, reuse = os.path.join(d, "build/cobj"), os.path.join(d, "build/reuse")
            printed = StringIO()
            with patch.multiple(c_objects, OUT=out, INDEX=os.path.join(out, "index.tsv"), REUSE=reuse,
                                RESULTS=os.path.join(reuse, "r.tsv"), placements=lambda: items,
                                global_key=lambda args: "g", map_rows=lambda: {}, watch_tree=c_objects.Watch,
                                global_inputs=global_inputs, FileInputs=lambda **kw: file_inputs(d),
                                compile_one=compile_one, SETTLE=3600), \
                    patch.object(sys, "argv", ["c_objects.py", "--toolchain", d, "-j", "1", "level_01"]), \
                    patch("sys.stdout", printed):
                c_objects.main()
            results = c_objects.read_results(os.path.join(reuse, "r.tsv"))
        # the first was compared (and stored) before the change; the next comparison, at the end,
        # answers for the other two
        self.assertEqual(sorted(results), [items[0][:2]])
        for it in items[1:]:
            self.assertRegex(printed.getvalue(), r"%s: [^\n]*; not stored: \S*config/levels/text_parts.txt changed"
                             % it[1])


class RepositoryKeyTest(unittest.TestCase):
    """The narrowed key on this repository: what it reads, and what it leaves out (no game data)."""

    def test_check_tools_has_the_check_path_and_not_the_rest(self):
        got = {os.path.basename(p) for p in c_objects.check_tools()}
        for f in ("c_objects.py", "check.py", "check_batch.py", "memo.py", "includes.py", "stamps.py",
                  "version.py", "targets.py", "gp.py", "build_text.py", "split_text.py", "srcfiles.py",
                  "level_tree.py", "level_catalogue.py", "level_symbols.py", "levels.py", "version_map.py",
                  "progress.py", "inventory.py", "asm_filter.py", "ee29.py", "ee296.py", "eeas.py", "dnas.py",
                  "dnas_blocks.py", "c_text_align.py"):
            self.assertIn(f, got)
        for f in ("pr_check.py", "names.py", "asm_build.py", "build.py", "todo.py", "us_port.py", "setup_asm.py"):
            self.assertNotIn(f, got)

    def test_every_module_the_check_path_imports_lazily_is_in_check_tools(self):
        # every `import X` / `from X import` of a tools/ module, at any indentation, in the files of
        # check_tools(), is itself in check_tools() (tool_closure()'s fixed point)
        import re
        got = {os.path.abspath(p) for p in c_objects.check_tools()}
        for p in got:
            text = open(p, errors="replace").read()
            for m in re.finditer(r"^\s*(?:from\s+(\w+)\s+import|import\s+([\w, ]+))", text, re.M):
                for mod in [m.group(1)] if m.group(1) else [x.split()[0] for x in m.group(2).split(",") if x.strip()]:
                    f = os.path.join(ROOT, "tools", mod + ".py")
                    if os.path.isfile(f):
                        self.assertIn(os.path.abspath(f), got, "%s imports %s" % (p, mod))
            # loaded by path rather than imported: build_text.py (check.text_c_context)
            for m in re.finditer(r'"tools",\s*"(\w+\.py)"', text):
                self.assertIn(os.path.join(str(ROOT), "tools", m.group(1)), got, p)

    def test_names_h_is_in_no_functions_key(self):
        files = c_objects.FileInputs()
        names_h = os.path.join(str(ROOT), "include", "names.h")
        generated = os.path.join(str(ROOT), "include", "bytematch_names.h")
        seen = 0
        for program, name, places, rel, nat in c_objects.placements():
            data = open(os.path.join(str(ROOT), rel), "rb").read() if os.path.isfile(os.path.join(str(ROOT), rel)) else None
            got = files.header_paths(program, rel, nat, data)
            self.assertIsNotNone(got, rel)
            paths = {p for p, _ in got}
            self.assertNotIn(names_h, paths, rel)
            self.assertNotIn(generated, paths, rel)
            self.assertIn(os.path.join(str(ROOT), "include", "common.h"), paths)
            seen += 1
        self.assertGreater(seen, 1000)


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

    def test_splat_names_leave_out_a_level_functions_catalogue_name(self):
        try:
            import splat.segtypes.common.c  # noqa: F401
        except ImportError:
            self.skipTest("splat is not installed")
        # a level's tree keeps the INCLUDE_ASM of the level's own name beside the C, which carries
        # the catalogue name: splat has no symbol of that name
        asm = b'INCLUDE_ASM("asm/levels/x/text", func_00300000);\nINCLUDE_ASM("asm/levels/x/text", func_00300040);\n'
        c = b'/* localdecomp:start func_L08_00300040 */\nvoid func_L08_00300040(int a) {\n    a++;\n}\n' \
            b'/* localdecomp:end func_L08_00300040 */\n'
        known = setup_asm.symbol_names("func_00300000 = 0x00300000;\nfunc_00300040 = 0x00300040;\n"
                                       ".L00300010 = 0x00300010; // type:label\n")
        self.assertEqual(known, {"func_00300000", "func_00300040", ".L00300010"})
        before = setup_asm.splat_names(asm, known)
        self.assertEqual(setup_asm.splat_names(asm + c, known), before)
        # splat's pattern takes the `*` of a function that returns a pointer into its name
        ptr = b'u8 *func_L08_00300000(int a) {\n    return 0;\n}\n'
        self.assertIn("*func_L08_00300000", setup_asm.splat_names(asm + ptr)[2])
        self.assertEqual(setup_asm.splat_names(asm + c + ptr, known), before)
        # without the symbol files' names nothing is left out, and a symbol file that gives the
        # catalogue name makes it a name splat marks: a change
        self.assertNotEqual(setup_asm.splat_names(asm + c), before)
        self.assertNotEqual(setup_asm.splat_names(asm + c, known | {"func_L08_00300040"}), before)
        # any other C function is still a change
        self.assertNotEqual(setup_asm.splat_names(asm + b"static void helper(void) {\n}\n", known), before)


if __name__ == "__main__":
    unittest.main()
