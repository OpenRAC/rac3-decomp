"""Unit tests for the build's object reuse (tools/objcache.py, tools/build_text.py): keys, the
cache, and whole compiles through a stand-in compiler that logs what it is asked to do. No
toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import contextlib
import io
import os
import shutil
import stat
import sys
import tempfile
import time
import unittest
import unittest.mock
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import build_text  # noqa: E402
import objcache  # noqa: E402

# a stand-in for ee-gcc: -S copies the C into "assembly" (a line `ASM name` becomes
# `.include "name"`; a line `TOUCH path` makes it rewrite that file while it runs); -c copies the
# assembly and the bytes of what it includes into the "object". Every call is logged.
FAKE_CC = r'''#!/usr/bin/env python3
import os, re, sys
args = sys.argv[1:]
out = args[args.index("-o") + 1]
src = args[-1]
with open(os.environ["FAKE_CC_LOG"], "a") as f:
    f.write(("S" if "-S" in args else "c") + " " + os.path.basename(src) + "\n")
text = open(src).read()
if "-S" in args:
    lines = []
    for line in text.splitlines():
        if line.startswith("ASM "):
            lines.append('.include "%s"' % line[4:])
        elif line.startswith("TOUCH "):
            with open(line[6:], "a") as f:
                f.write("/* changed during the compile */\n")
        else:
            lines.append("# " + line)
    open(out, "w").write("\n".join(lines) + "\n")
else:
    body = text
    for name in re.findall(r'\.include "([^"]+)"', text):
        body += open(os.path.join(os.path.dirname(src), name)).read()
    open(out, "wb").write(b"OBJ\0" + body.encode())
'''


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\n") as f:
        f.write(text)


class KeyTest(unittest.TestCase):
    def setUp(self):
        objcache.reset()

    def test_same_inputs_same_key_and_any_change_another(self):
        with tempfile.TemporaryDirectory() as d:
            a = os.path.join(d, "a.c")
            write(a, "int x;\n")
            k = lambda cmd: objcache.Key("compile").text("command", cmd).file("source", a).hexdigest()
            base = k(["cc", "-O2"])
            self.assertEqual(k(["cc", "-O2"]), base)
            self.assertNotEqual(k(["cc", "-O1"]), base)
            write(a, "int xy;\n")
            self.assertNotEqual(k(["cc", "-O2"]), base)
            self.assertNotEqual(objcache.Key("assemble").text("command", ["cc", "-O2"]).file("source", a)
                                .hexdigest(), k(["cc", "-O2"]))

    def test_a_file_changed_after_it_was_read(self):
        with tempfile.TemporaryDirectory() as d:
            a = os.path.join(d, "a.h")
            write(a, "1")
            key = objcache.Key("x").file("h", a)
            self.assertFalse(key.changed())
            write(a, "22")
            self.assertTrue(key.changed())

    def test_a_tree_has_every_file(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "tc", "bin", "cc"), "one")
            write(os.path.join(d, "tc", "lib", "cc1"), "two")
            base = objcache.Hasher().tree(os.path.join(d, "tc"))
            write(os.path.join(d, "tc", "lib", "cc1"), "three")
            self.assertNotEqual(objcache.Hasher().tree(os.path.join(d, "tc")), base)
            self.assertNotEqual(objcache.Hasher().tree(os.path.join(d, "none")), base)

    def test_standard_includes(self):
        ok = ["-I", "include", "-I", ".", "-O2", "-Wa,-I,include,-mips3", "-DX=1"]
        self.assertTrue(objcache.standard_includes(ok))
        self.assertTrue(objcache.standard_includes(["-Iinclude", "-I."]))
        for bad in (["-I", "other"], ["-Iother"], ["-include", "x.h"], ["-isystem", "y"],
                    ["-nostdinc"], ["-Wa,-I,other"], ["-Wa,-Iother"]):
            self.assertFalse(objcache.standard_includes(ok + bad), bad)

    def test_asm_includes_are_followed_and_incbin_is_never_reused(self):
        with tempfile.TemporaryDirectory() as d:
            write(os.path.join(d, "a.s"), '.include "b.s"\n')
            write(os.path.join(d, "b.s"), 'nop\n')
            k = lambda: objcache.add_asm_includes(objcache.Key("x"), b'.include "a.s"\n', d)
            key = objcache.Key("x")
            self.assertTrue(objcache.add_asm_includes(key, b'.include "a.s"\n', d))
            self.assertIn(os.path.join(d, "b.s"), key.watched)
            first = key.hexdigest()
            objcache.reset()
            write(os.path.join(d, "b.s"), 'nop\nnop\n')
            key = objcache.Key("x")
            objcache.add_asm_includes(key, b'.include "a.s"\n', d)
            self.assertNotEqual(key.hexdigest(), first)
            self.assertTrue(k())
            self.assertFalse(objcache.add_asm_includes(objcache.Key("x"), b'.incbin "c.bin"\n', d))
            objcache.reset()
            write(os.path.join(d, "b.s"), '.incbin "c.bin"\n')
            self.assertFalse(k())

    def test_cache_round_trip_disabled_and_prune(self):
        with tempfile.TemporaryDirectory() as d:
            src, dest = os.path.join(d, "o"), os.path.join(d, "out")
            write(src, "object")
            c = objcache.Cache(root=os.path.join(d, "cache"))
            self.assertFalse(c.fetch("ab" * 20, dest))
            c.store("ab" * 20, src)
            self.assertTrue(c.fetch("ab" * 20, dest))
            with open(dest) as f:
                self.assertEqual(f.read(), "object")
            self.assertEqual((c.hits, c.misses), (1, 1))
            off = objcache.Cache(enabled=False, root=os.path.join(d, "cache"))
            self.assertFalse(off.fetch("ab" * 20, dest))
            off.store("cd" * 20, src)
            self.assertFalse(os.path.exists(off.path("cd" * 20)))
            self.assertEqual(objcache.prune(14, os.path.join(d, "cache")), 0)
            self.assertEqual(objcache.prune(14, os.path.join(d, "cache"), now=time.time() + 15 * 86400), 1)
            self.assertFalse(c.fetch("ab" * 20, dest))

    def test_env_turns_it_off(self):
        old = os.environ.get("UYA_NO_CACHE")
        os.environ["UYA_NO_CACHE"] = "1"
        try:
            self.assertFalse(objcache.Cache().enabled)
        finally:
            if old is None:
                del os.environ["UYA_NO_CACHE"]
            else:
                os.environ["UYA_NO_CACHE"] = old


class FilterTablesTest(unittest.TestCase):
    """tools/asm_filter.py reads its tables once while they do not change, again when they do."""

    def test_tables_are_read_again_after_a_change(self):
        import asm_filter
        with tempfile.TemporaryDirectory() as d:
            divs, sq = os.path.join(d, "divs_nops.txt"), os.path.join(d, "sq_ra_funcs.txt")
            write(divs, "func_A 1 2\n")
            write(sq, "func_B\n")
            with unittest.mock.patch.object(asm_filter, "_divs_file", lambda: divs), \
                    unittest.mock.patch.object(asm_filter, "_sq_ra_file", lambda: sq), \
                    unittest.mock.patch.object(asm_filter, "LEVEL_DIVS", os.path.join(d, "none")), \
                    unittest.mock.patch.object(asm_filter, "LEVEL_SQ_RA", os.path.join(d, "none")):
                self.assertEqual(asm_filter.divs_table(), {"func_A": [1, 2]})
                self.assertIs(asm_filter.divs_table(), asm_filter.divs_table())
                self.assertEqual(asm_filter.sq_ra_funcs(), {"func_B"})
                write(divs, "func_A 1 2\nfunc_C 3w\n")
                write(sq, "func_B\nfunc_D\n")
                self.assertEqual(asm_filter.divs_table(), {"func_A": [1, 2], "func_C": ["3w"]})
                self.assertEqual(asm_filter.sq_ra_funcs(), {"func_B", "func_D"})


@unittest.skipIf(os.name == "nt", "the stand-in compiler is a script with a #! line")
class CompileReuseTest(unittest.TestCase):
    """build_text.compile_one() twice and after each kind of change, counting the compiles."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        d = self.d = self.tmp.name
        self.cc = os.path.join(d, "tc", "bin", "cc")
        write(self.cc, FAKE_CC)
        os.chmod(self.cc, os.stat(self.cc).st_mode | stat.S_IEXEC)
        self.log = os.path.join(d, "log")
        os.environ["FAKE_CC_LOG"] = self.log
        self.c = os.path.join(d, "src", "f.c")
        write(os.path.join(d, "src", "f.h"), "int h;\n")
        write(self.c, '#include "f.h"\nint f;\nASM g.s\n')
        self.saved = (build_text.CACHE, build_text.TOOLCHAIN, build_text.CC, build_text.LD, build_text.RUNNER)
        build_text.TOOLCHAIN, build_text.CC, build_text.LD, build_text.RUNNER = (
            os.path.join(d, "tc"), self.cc, None, None)
        self.out = os.path.join(d, "build")
        os.makedirs(self.out)

    def tearDown(self):
        (build_text.CACHE, build_text.TOOLCHAIN, build_text.CC, build_text.LD, build_text.RUNNER) = self.saved
        del os.environ["FAKE_CC_LOG"]
        self.tmp.cleanup()

    def run_once(self, enabled=True, flags=("-O2",)):
        """One build (a new process: nothing remembered); returns (steps run, object bytes)."""
        objcache.reset()
        build_text.CACHE = objcache.Cache(enabled=enabled, root=os.path.join(self.d, "cache"))
        if os.path.exists(self.log):
            os.remove(self.log)
        s, o = os.path.join(self.out, "f.s"), os.path.join(self.out, "f.o")
        with contextlib.redirect_stdout(io.StringIO()):
            build_text.compile_one(self.cc, list(flags), ["-I", "include", "-I", "."], self.c, s, o, "f.c")
        steps = []
        if os.path.exists(self.log):
            with open(self.log) as f:
                steps = f.read().split()
        with open(o, "rb") as f:
            return [x for x in steps if x in ("S", "c")], f.read()

    def test_reuse_and_what_undoes_it(self):
        # the .include in the compiler's output is found next to the assembly: put it there
        write(os.path.join(self.out, "g.s"), "nop\n")
        steps, clean = self.run_once()
        self.assertEqual(steps, ["S", "c"])
        steps, again = self.run_once()
        self.assertEqual(steps, [])
        self.assertEqual(again, clean)
        # other flags or source: compile and assemble again
        self.assertEqual(self.run_once(flags=("-O1",))[0], ["S", "c"])
        # a header: compile again; the assembly comes out the same, so its object is reused
        write(os.path.join(self.d, "src", "f.h"), "int hh;\n")
        self.assertEqual(self.run_once()[0], ["S"])
        self.assertEqual(self.run_once()[0], [])
        write(self.c, '#include "f.h"\nint f2;\nASM g.s\n')
        self.assertEqual(self.run_once()[0], ["S", "c"])
        # a file only the assembler reads: assemble again, the compile is reused
        write(os.path.join(self.out, "g.s"), "nop\nnop\n")
        steps, obj = self.run_once()
        self.assertEqual(steps, ["c"])
        self.assertTrue(obj.endswith(b"nop\nnop\n"))
        # the toolchain: everything again
        write(os.path.join(self.d, "tc", "lib", "cc1"), "new")
        self.assertEqual(self.run_once()[0], ["S", "c"])
        # back to an earlier state: reused
        shutil.rmtree(os.path.join(self.d, "tc", "lib"))
        self.assertEqual(self.run_once()[0], [])
        # --no-cache: everything, and the same bytes
        steps, fresh = self.run_once(enabled=False)
        self.assertEqual(steps, ["S", "c"])
        self.assertEqual(fresh, self.run_once()[1])

    def test_an_input_changed_during_the_compile_is_not_kept(self):
        header = os.path.join(self.d, "src", "f.h")
        write(self.c, '#include "f.h"\nTOUCH %s\n' % header)
        self.assertEqual(self.run_once()[0], ["S", "c"])
        # the compile changed f.h after the key read it: its assembly was not kept (the same
        # f.h again compiles again), the object, whose inputs did not change, was
        write(header, "int h;\n")
        self.assertEqual(self.run_once()[0], ["S"])


if __name__ == "__main__":
    unittest.main()
