"""Unit tests for tools/check_return_types.py: return type classes of small C snippets.

  python3 -m unittest tests.test_check_return_types

The tests that parse C need clang (or $CLANG) and are skipped without it.
"""
import os
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import check_return_types as crt  # noqa: E402

CLANG = crt.find_clang()
COMMON = """typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef float f32;
"""


class ClassifyTest(unittest.TestCase):
    """The classes, from the type text clang prints."""

    def classify(self, function_type, typedefs=None):
        typedefs = typedefs or {}
        return crt.classify(crt.return_part(function_type), typedefs.get)

    def test_classes(self):
        self.assertEqual(self.classify("void (void)"), "void")
        self.assertEqual(self.classify("int ()"), "int32")
        self.assertEqual(self.classify("unsigned char (int)"), "int32")
        self.assertEqual(self.classify("unsigned (int)"), "int32")
        self.assertEqual(self.classify("enum E (void)"), "int32")
        self.assertEqual(self.classify("long (void)"), "int64")
        self.assertEqual(self.classify("unsigned long long (void)"), "int64")
        self.assertEqual(self.classify("unsigned __int128 (void)"), "int128")
        self.assertEqual(self.classify("float (float, float)"), "float")
        self.assertEqual(self.classify("double (double)"), "double")
        self.assertEqual(self.classify("char *(const char *, int)"), "pointer")
        self.assertEqual(self.classify("struct Foo (void)"), "aggregate")
        self.assertEqual(self.classify("struct (unnamed struct at src/a.c:3:9) (void)"), "aggregate")
        self.assertEqual(self.classify("struct (unnamed struct at src/a.c:3:9) *(void)"), "pointer")

    def test_function_pointer_returned(self):
        self.assertEqual(crt.return_part("void (*(int))(void)"), "void (*(int)))")
        self.assertEqual(self.classify("void (*(int))(void)"), "pointer")

    def test_attributes(self):
        self.assertEqual(self.classify("void (void) __attribute__((noreturn))"), "void")

    def test_typedefs(self):
        typedefs = {"s32": "int", "f32": "float", "VP": "void *", "u128": "unsigned __int128"}
        self.assertEqual(self.classify("s32 (void)", typedefs), "int32")
        self.assertEqual(self.classify("f32 (s32)", typedefs), "float")
        self.assertEqual(self.classify("VP (void)", typedefs), "pointer")
        self.assertEqual(self.classify("u128 (void)", typedefs), "int128")
        self.assertTrue(self.classify("Missing (void)", typedefs).startswith("unknown:"))


CATALOGUE = """# name\tkind\tsize\tfingerprint\tremnant\tlevels\tplaces
func_L01_00300000\tshared\t8\t0\t0\t2\t01:00300000,02:00310000
func_00390000\tfrontbin\t8\t0\t0\t1\t01:00400000
"""
MAP = """# PAL name, program, NTSC-U name, place, size, state, status, closeness, hash
func_00390000\tfrontbin\tfunc_00380000\t00380000\t8\tC\tmatch\t100.00\t0
func_00390100\tfrontbin\tfunc_00380100\t00380100\t8\tC\tdiffers\t50.00\t0
-\tfrontbin\tfunc_00380100\t00380100\t8\tC\tmatch\t100.00\t0
"""


class KeyTest(unittest.TestCase):
    """Names grouped as the build resolves them."""

    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory()
        crt.write(os.path.join(cls.tmp.name, "config", "levels", "functions.tsv"), CATALOGUE)
        cls.names = crt.Names(cls.tmp.name)

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def key(self, link, rel):
        return self.names.key(link, rel)

    def test_suffixes_and_spellings(self):
        self.assertEqual(self.key("func_003ABE48_A6520", "src/frontbin/a.c"), ("frontbin", "func_003ABE48"))
        self.assertEqual(self.key("func_11F0A0", "src/frontbin/a.c"), ("boot_elf", "func_0011F0A0"))
        self.assertEqual(self.key("func_0011F0A0", "src/levels/shared/a.c"), ("boot_elf", "func_0011F0A0"))
        self.assertEqual(self.key("func_L01_00451388_002FB7D8", "src/levels/shared/a.c"),
                         ("levels", "func_L01_00451388"))

    def test_programs(self):
        self.assertEqual(self.key("func_00390000", "src/boot_elf/text/a.c"), ("boot_elf", "func_00390000"))
        self.assertEqual(self.key("func_00390000", "src/frontbin/a.c"), ("frontbin", "func_00390000"))
        self.assertEqual(self.key("func_00800158", "src/i5bootn/a.c"), ("i5bootn", "func_00800158"))
        self.assertEqual(self.key("func_U_003824B8", "src/us/boot_elf/003824B8.c"), ("boot_elf", "func_003824B8"))
        self.assertEqual(self.key("func_U_L06_00351718", "src/us/levels/func_U_L06_00351718.c"),
                         ("levels", "func_L06_00351718"))
        self.assertEqual(self.key("func_00120000", "src/us/frontbin/003C08A8.c"), ("boot_elf", "func_00120000"))
        self.assertEqual(self.key("__muldi3", "src/boot_elf/core/a.c"), ("boot_elf", "__muldi3"))

    def test_level_names(self):
        # front-end functions: frontbin's, whether written fe_func_ or not
        self.assertEqual(self.key("fe_func_00390000", "src/levels/shared/a.c"), ("frontbin", "func_00390000"))
        self.assertEqual(self.key("func_00390000_00300000", "src/levels/shared/a.c"), ("frontbin", "func_00390000"))
        # a bare address in a level's own file: that level's function there
        self.assertEqual(self.key("func_00400000", "src/levels/01_veldin/a.c"), ("frontbin", "func_00390000"))
        self.assertEqual(self.key("func_00310000", "src/levels/02_florana/a.c"), ("levels", "func_L01_00300000"))
        self.assertEqual(self.key("func_00500000", "src/levels/01_veldin/a.c"), ("levels", "L01:func_00500000"))
        self.assertEqual(self.key("func_00500000", "src/levels/shared/a.c"), ("levels", "shared:func_00500000"))

    def test_data_names_are_not_functions(self):
        self.assertIsNone(self.key("D_001DA050", "src/frontbin/a.c"))
        self.assertIsNone(self.key("D_001DA058_003BCA50", "src/frontbin/a.c"))
        self.assertIsNone(self.key("D_L01_001D66B0_3519F0", "src/levels/shared/a.c"))
        self.assertIsNone(self.key("jtbl_00390000", "src/frontbin/a.c"))
        self.assertIsNone(self.key("__builtin_memcpy", "src/frontbin/a.c"))


class UsViewTest(unittest.TestCase):
    """NTSC-U: shared C under its NTSC-U names, src/us/'s C, and no PAL C that NTSC-U does not have."""

    def test_names_and_definitions(self):
        with tempfile.TemporaryDirectory() as root:
            crt.write(os.path.join(root, "config", "us", "map.tsv"), MAP)
            us = crt.UsNames(root)
            names = crt.Names(root)

        def decl(name, kind, cls, file, line):
            return {"name": name, "link": name, "ret": cls, "class": cls, "kind": kind, "scope": "file",
                    "file": file, "line": line, "function": None}
        results = [
            {"path": "src/frontbin/a.c", "decls": [
                decl("func_00390000", "definition", "float", "src/frontbin/a.c", 2),
                decl("func_00390100", "definition", "void", "src/frontbin/a.c", 5),
                decl("func_00390200", "declaration", "int32", "src/frontbin/a.c", 9)]},
            {"path": "src/frontbin/b.c", "decls": [
                decl("func_00390000", "declaration", "int32", "src/frontbin/b.c", 2),
                decl("func_00390100", "declaration", "int32", "src/frontbin/b.c", 3)]},
            {"path": "src/us/frontbin/00380100.c", "decls": [
                decl("func_U_00380100", "definition", "int32", "src/us/frontbin/00380100.c", 3)]},
        ]
        by_version = crt.views(results, ["pal", "us"], us, names)
        pal, ntsc = (crt.conflicts(by_version[v]) for v in ("pal", "us"))
        self.assertEqual(sorted(pal), [("frontbin", "func_00390000"), ("frontbin", "func_00390100")])
        # func_00390100's PAL definition differs on NTSC-U: src/us/'s int definition stands there
        self.assertEqual(sorted(ntsc), [("frontbin", "func_00380000")])
        self.assertEqual(sorted(d["file"] for d in by_version["us"][("frontbin", "func_00380100")]),
                         ["src/frontbin/b.c", "src/us/frontbin/00380100.c"])
        self.assertIn(("frontbin", "pal:func_00390200"), by_version["us"])


class NeutralizeTest(unittest.TestCase):
    """The parser copy: asm statements blanked, asm labels kept, the same lines."""

    def test_asm_statements_and_labels(self):
        text = ('extern void *malloc(int, int) __asm__("func_003ECDC0");\n'
                '__asm__(".extern D_1DA050, 16");\n'
                'void f(void *a) {\n'
                '    __asm__ volatile("lqc2 %0, %1" : "=j"(q) : "m"(*(int *)a));\n'
                '    if (a) __asm__("sync");\n'
                '}\n')
        out = crt.neutralize(text)
        self.assertEqual(out.count("\n"), text.count("\n"))
        self.assertIn('__asm__("func_003ECDC0")', out)
        self.assertNotIn("lqc2", out)
        self.assertNotIn(".extern", out)
        self.assertNotIn("sync", out)
        self.assertIn("if (a)", out)

    def test_macro_and_multi_line_string(self):
        text = ('#define SYNC() \\\n    __asm__ __volatile__("sync" \\\n    )\n'
                'char *s = "two\nlines";\n')
        out = crt.neutralize(text)
        self.assertEqual(out.count("\n"), text.count("\n"))
        self.assertEqual(out.count("\\\n"), 2)        # the macro's continuations stay
        self.assertNotIn("sync", out)
        self.assertIn('"two\\n"\n"lines"', out)

    def test_level_names(self):
        fe = {"func_003C2880"}
        self.assertEqual(crt.level_names("func_003C2880(m); func_003C2880_x(m); func_00301558();", fe),
                         "fe_func_003C2880(m); fe_func_003C2880_x(m); func_00301558();")


@unittest.skipUnless(CLANG, "clang is not installed")
class ClangTest(unittest.TestCase):
    """Snippets parsed by clang, grouped and compared."""

    def scan(self, files):
        with tempfile.TemporaryDirectory() as root:
            for rel, text in {"include/common.h": COMMON, **files}.items():
                crt.write(os.path.join(root, rel), text)
            results = crt.collect(sorted(files), root, jobs=1, clang=CLANG)
        for r in results:
            self.assertIsNone(r["failed"], r)
        groups = crt.views(results, ["pal"], None)["pal"]
        return results, groups, crt.conflicts(groups)

    def classes(self, decls):
        return sorted((d["class"], d["kind"], d["scope"]) for d in decls)

    def test_float_definition_read_as_int(self):
        _, groups, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\nf32 func_00390000(s32 a) {\n    return a;\n}\n',
            "src/frontbin/b.c": '#include "common.h"\nextern s32 func_00390000(s32);\n'
                                's32 func_00390100(void) {\n    return func_00390000(1) == 32;\n}\n',
        })
        k = ("frontbin", "func_00390000")
        self.assertIn(k, bad)
        self.assertEqual(crt.pair(bad[k]), "int32 vs float")
        self.assertEqual(self.classes(bad[k]), [("float", "definition", "file"), ("int32", "declaration", "file")])
        self.assertEqual(bad[k][0]["file"], "src/frontbin/a.c")
        self.assertEqual(bad[k][0]["line"], 2)
        self.assertNotIn(("frontbin", "func_00390100"), bad)

    def test_void_function_read_as_a_value(self):
        _, _, bad = self.scan({
            "src/boot_elf/core/a.c": '#include "common.h"\nvoid func_00120000(void) {\n}\n',
            "src/levels/shared/b.c": '#include "common.h"\nextern s32 func_00120000(void);\n'
                                     's32 func_L01_00300000(void) {\n    return func_00120000();\n}\n',
        })
        self.assertEqual(crt.pair(bad[("boot_elf", "func_00120000")]), "void vs int32")

    def test_implicit_declaration(self):
        results, _, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\nvoid func_00390200(s32 a) {\n}\n',
            "src/frontbin/b.c": '#include "common.h"\nvoid func_00390300(void) {\n'
                                '    func_00390200(1);\n}\n',
        })
        decls = bad[("frontbin", "func_00390200")]
        implicit = [d for d in decls if d["kind"] == "implicit"]
        self.assertEqual(len(implicit), 1)
        self.assertEqual((implicit[0]["class"], implicit[0]["file"], implicit[0]["line"]),
                         ("int32", "src/frontbin/b.c", 3))
        self.assertEqual(implicit[0]["function"], "func_00390300")

    def test_block_scope_declarations(self):
        _, groups, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\n'
                                'extern s32 func_00390400(void);\n'
                                'void func_00390500(void) {\n'
                                '    extern f32 func_00390400_00390500(void);\n'
                                '    {\n'
                                '        typedef void *VP;\n'
                                '        extern VP func_00390600(void);\n'
                                '        func_00390600();\n'
                                '    }\n'
                                '    func_00390400_00390500();\n'
                                '}\n'
                                'extern void *func_00390600(void);\n',
        })
        decls = bad[("frontbin", "func_00390400")]
        self.assertEqual(self.classes(decls), [("float", "declaration", "block"), ("int32", "declaration", "file")])
        block = next(d for d in decls if d["scope"] == "block")
        self.assertEqual((block["name"], block["line"], block["function"]), ("func_00390400_00390500", 4, "func_00390500"))
        # the block's typedef: a pointer, as the file-scope declaration after it says
        self.assertNotIn(("frontbin", "func_00390600"), bad)
        self.assertEqual(self.classes(groups[("frontbin", "func_00390600")]),
                         [("pointer", "declaration", "block"), ("pointer", "declaration", "file")])

    def test_data_aliases_excluded(self):
        _, groups, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\n'
                                'extern void D_00390700(void);\n'
                                'extern s32 D_00390700_00390800(void);\n'
                                'extern u8 func_00390900[];\n'
                                'void func_00390800(void) {\n'
                                '    D_00390700();\n'
                                '    D_00390700_00390800();\n'
                                '}\n',
        })
        self.assertEqual(bad, {})
        self.assertEqual(sorted(groups), [("frontbin", "func_00390800")])

    def test_deep_expression(self):
        # func_L01_0045AA30's 600-cast chain needs more than 8 MB of clang's stack: on POSIX the
        # tool raises the limit, on Windows clang crashes and the line is parsed again blanked
        chain = "((void *(*)(s32))((s32 (*)(u8 *))" * 300 + "func_00390000" + "))" * 300
        results, groups, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\nextern s32 func_00390000(u8 *);\n'
                                'void *func_00390100(u8 *a) {\n    void *o;\n'
                                '    o = ((void *(*)(u8 *))' + chain + ')(a);\n    return o;\n}\n',
        })
        self.assertEqual(bad, {})
        self.assertEqual(groups[("frontbin", "func_00390100")][0]["class"], "pointer")
        self.assertIn(results[0]["blanked"], ([], [5]))
        if os.name == "posix":
            self.assertEqual(results[0]["blanked"], [])

    def test_agreeing_spellings_and_linkage(self):
        _, groups, bad = self.scan({
            "src/frontbin/a.c": '#include "common.h"\n'
                                'extern u32 func_11F0A0(void);\n'
                                'extern s32 func_0011F0A0_00390000(void);\n'
                                'static f32 func_00390A00(void) {\n    return 0;\n}\n'
                                'extern void *malloc(s32, s32) __asm__("func_003ECDC0");\n'
                                'extern u128 func_00390B00(void);\n'
                                'extern s64 func_00390C00(void);\n'
                                'void vu0(void *a) {\n'
                                '    u128 q;\n'
                                '    __asm__ volatile("lqc2 %0, 0(%1)" : "=j"(q) : "r"(a));\n'
                                '}\n',
            "src/frontbin/b.c": '#include "common.h"\n'
                                's32 func_00390A00(void) {\n    return 0;\n}\n'
                                'void *func_003ECDC0(s32 a, s32 b) {\n    return 0;\n}\n',
        })
        self.assertEqual(bad, {})
        self.assertEqual(len(groups[("boot_elf", "func_0011F0A0")]), 2)
        self.assertEqual(self.classes(groups[("frontbin", "func_00390A00")]), [("int32", "definition", "file")])
        self.assertEqual(len(groups[("frontbin", "func_003ECDC0")]), 2)
        self.assertEqual(groups[("frontbin", "func_00390B00")][0]["class"], "int128")
        self.assertEqual(groups[("frontbin", "func_00390C00")][0]["class"], "int64")


if __name__ == "__main__":
    unittest.main()
