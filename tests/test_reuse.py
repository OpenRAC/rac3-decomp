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
    import includes
    f._earlier_includes, f._header_sums = kw.get("earlier_includes", {}), {}
    f.scanner = includes.Scanner(root)
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

    def keys(self, d, items):
        files = file_inputs(d)
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

    def test_an_include_that_cannot_be_followed_takes_every_header(self):
        with tempfile.TemporaryDirectory() as d:
            for rel, text in self.HEADERS.items():
                write(os.path.join(d, rel), text)
            write(os.path.join(d, self.ITEM[3]), '#define H "structs/hero.h"\n#include H\nvoid f(void) { }\n')
            base = self.keys(d, [self.ITEM])
            write(os.path.join(d, "include/names.h"), "/* another name */\n")
            self.assertNotEqual(self.keys(d, [self.ITEM]), base)


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
