"""Unit tests for many checks in one process: tools/check_batch.py's workers, tools/memo.py's kept
tables and tools/check.py's state between checks.

  python3 -m unittest discover -s tests

The first tests need no toolchain and no game data: they run checks that end before or at the
compile (a missing file, a bad option, a level or NTSC-U check whose dump is not there, a compile
through a stand-in compiler) and compare a worker's answers with separate processes', and they
make the stand-in compiler hang or kill its worker. RealChecksTest compiles real functions of
every kind and needs the toolchain (env.sh's UYA_* variables) and both discs' dumps; it is
skipped without them.
"""
import importlib.util
import json
import os
import re
import signal
import subprocess
import sys
import tempfile
import textwrap
import time
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

HAVE_PACKAGES = bool(importlib.util.find_spec("elftools") and importlib.util.find_spec("capstone"))
TEMP_NAMES = re.compile(r"/tmp/(?:c_objects|try_func|ee29|ee296|cobj_test|tmp)[A-Za-z0-9_]*/")


def process(args, env):
    """(exit status, standard output, standard error) of `python3 tools/check.py ARGS`."""
    p = subprocess.run([sys.executable, str(ROOT / "tools" / "check.py")] + list(args), cwd=ROOT, env=env,
                       capture_output=True, text=True, timeout=600)
    return p.returncode, p.stdout, p.stderr


def masked(text):
    """Without the random names of temporary folders (a compile error prints its command)."""
    return TEMP_NAMES.sub("<tmp>/", text)


def read(path):
    with open(path, errors="replace") as f:
        return f.read()


def last_line(text):
    lines = [l for l in text.splitlines() if l.strip()]
    return lines[-1] if lines else ""


def write(path, text, mode=0o644):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\n") as f:
        f.write(text)
    os.chmod(path, mode)


def tiny_elf(path):
    """An ELF32 little-endian MIPS header with no segments or sections: a retail program for
    check.py's --retail that holds nothing (every diff then fails, which is fine here)."""
    import struct
    hdr = b"\x7fELF" + bytes([1, 1, 1]) + bytes(9)
    hdr += struct.pack("<HHIIIIIHHHHHH", 2, 8, 1, 0, 0, 0, 0, 52, 32, 0, 40, 0, 0)
    with open(path, "wb") as f:
        f.write(hdr)


@unittest.skipUnless(HAVE_PACKAGES, "check.py needs pyelftools and capstone")
class WorkerTest(unittest.TestCase):
    """A worker against separate processes, without the toolchain or game data."""

    def setUp(self):
        import check_batch
        self.cb = check_batch
        self.dir = tempfile.mkdtemp(prefix="cobj_test_")
        self.elf = os.path.join(self.dir, "retail.elf")
        tiny_elf(self.elf)
        # a stand-in compiler run as check.py's --runner: says what it was asked and fails
        self.fake = os.path.join(self.dir, "fake_cc")
        write(self.fake, "#!/bin/sh\necho \"stand-in compiler: $# arguments\" >&2\nexit 1\n", 0o755)
        self.snippet = os.path.join(self.dir, "f.c")
        write(self.snippet, "void func_00381140(void) { }\n")
        self.level = os.path.join(self.dir, "l.c")
        write(self.level, "void func_L01_002F8F70(void) { }\n")
        self.env = {k: v for k, v in os.environ.items() if not k.startswith("UYA_")}
        self.workers = []

    def tearDown(self):
        for w in self.workers:
            w.close()
        import shutil
        shutil.rmtree(self.dir, ignore_errors=True)

    def worker(self, version="pal", **kw):
        # in verify mode: a check that changes a table the worker keeps fails here (KeptTableChanged),
        # without the toolchain RealChecksTest needs
        w = self.cb.Worker(env=dict(self.env, UYA_VERSION=version, CHECK_BATCH_VERIFY="1"), **kw)
        self.workers.append(w)
        return w

    def compile_args(self, extra=()):
        return [self.snippet, "func_00381140", "--quiet", "--toolchain", self.dir, "--runner", self.fake,
                "--retail", self.elf] + list(extra)

    def sequence(self):
        """Checks of different kinds, each ending early in its own way, that leave state behind."""
        level = self.level_name()
        return [
            ["--help"],
            ["--mode", "X", self.snippet],                                   # argparse's error: exit 2
            [os.path.join(self.dir, "missing.c")],                           # a traceback: exit 1
            [os.path.join(self.dir, "empty.c")],                             # sys.exit("no func_...")
            self.compile_args(),                                             # a compile error
            [self.level, level[0], "--quiet", "--toolchain", self.dir, "--runner", self.fake, "--retail", self.elf],
            self.compile_args(["--target", "boot_elf"]),
            [self.level, level[0], "--quiet", "--toolchain", self.dir, "--runner", self.fake, "--retail", self.elf,
             "--target", "level_%02d" % level[1]],
            self.compile_args(["--mode", "N", "--as", "ps2as"]),
            self.compile_args(),
        ]

    def level_name(self):
        """A shared level function of the catalogue (config/levels/functions.tsv) and another level
        of it, written into the level snippet."""
        import level_catalogue as lc
        import version
        for r in lc.read_catalogue(version.cfg("levels", "functions.tsv", v="pal")):
            if r[1] == "shared" and len(r[5]) > 2:
                write(self.level, "void %s(void) { }\n" % r[0])
                return r[0], r[5][2][0]
        self.skipTest("no shared level function in the catalogue")

    def test_a_worker_answers_as_separate_processes(self):
        write(os.path.join(self.dir, "empty.c"), "int x;\n")
        seq = self.sequence()
        w = self.worker()
        for args in seq + list(reversed(seq)):
            want = process(args, dict(self.env, UYA_VERSION="pal"))
            got = w.run(args, timeout=120)
            self.assertEqual(got[0], want[0], args)
            self.assertEqual(masked(got[1]), masked(want[1]), args)
            # standard error: the same message (a traceback's frames are the worker's own)
            self.assertEqual(masked(last_line(got[2])), masked(last_line(want[2])), args)
        self.assertEqual(w.started, 1)

    def test_ntsc_u_checks_in_a_worker(self):
        # --version us: the twin's place from config/us/map.tsv, then the NTSC-U dump (missing in CI,
        # or there): the same either way, in any order with PAL-style level checks
        import version_map as vm
        m = vm.Map()
        core = next(r for r in m.rows if r["program"] == "frontbin" and r["status"] == "match" and r["pal"] != "-")
        lvl = next(r for r in m.rows if r["program"] == "levels" and r["status"] == "match" and r["pal"] != "-")
        write(self.snippet, "void %s(void) { }\n" % core["pal"])
        write(self.level, "void %s(void) { }\n" % lvl["pal"])
        seq = [[self.snippet, core["pal"], "--quiet", "--toolchain", self.dir, "--runner", self.fake, "--target", "frontbin"],
               [self.level, lvl["pal"], "--quiet", "--toolchain", self.dir, "--runner", self.fake],
               [self.snippet, "func_00000000", "--quiet", "--toolchain", self.dir, "--target", "frontbin"]]
        w = self.worker("us")
        for args in seq + seq[::-1] + seq:
            want = process(["--version", "us"] + args, dict(self.env, UYA_VERSION="us"))
            got = w.run(["--version", "us"] + args, timeout=120)
            self.assertEqual((got[0], masked(got[1])), (want[0], masked(want[1])), args)
            self.assertEqual(masked(last_line(got[2])), masked(last_line(want[2])), args)
        # a worker checks on one version only
        rc, _, err = w.run(["--version", "pal", self.snippet], timeout=60)
        self.assertEqual(rc, 2)
        self.assertIn("not pal", err)

    def test_a_hung_compile_is_killed_and_the_worker_replaced(self):
        pid_file = os.path.join(self.dir, "hung.pid")
        hang = os.path.join(self.dir, "hang_cc")
        write(hang, "#!/bin/sh\necho $$ > %s\nexec sleep 300\n" % pid_file, 0o755)
        w = self.worker()
        args = self.compile_args()
        args[args.index(self.fake)] = hang
        t = time.monotonic()
        with self.assertRaises(subprocess.TimeoutExpired):
            w.run(args, timeout=5)
        self.assertLess(time.monotonic() - t, 60)
        pid = int(read(pid_file))
        self.assertFalse(alive(pid), "the hung compiler is still running")
        # the next check gets a new worker and its usual answer
        want = process(self.compile_args(), dict(self.env, UYA_VERSION="pal"))
        got = w.run(self.compile_args(), timeout=120)
        self.assertEqual((got[0], masked(got[1])), (want[0], masked(want[1])))
        self.assertEqual(w.started, 2)

    def test_a_worker_that_dies_during_a_check_is_replaced(self):
        crash = os.path.join(self.dir, "crash_cc")
        # the compiler's parent is the worker: kill it
        write(crash, "#!/bin/sh\nkill -9 $PPID\nsleep 1\n", 0o755)
        w = self.worker()
        args = self.compile_args()
        args[args.index(self.fake)] = crash
        with self.assertRaises(self.cb.WorkerDied) as e:
            w.run(args, timeout=60)
        self.assertIn(str(-signal.SIGKILL), str(e.exception))
        got = w.run(["--help"], timeout=60)
        self.assertEqual(got[0], 0)
        self.assertEqual(w.started, 2)

    def test_a_changed_kept_table_is_raised_and_the_worker_replaced(self):
        # a caller that changes a kept table in place (here: every read of the level catalogue
        # reverses it), put into the worker by a stand-in python that patches level_catalogue
        inject = os.path.join(self.dir, "inject.py")
        write(inject, textwrap.dedent("""\
            import os, runpy, sys
            script = sys.argv[1]
            sys.argv = sys.argv[1:]
            sys.path.insert(0, os.path.dirname(script))
            import level_catalogue
            kept = level_catalogue.read_catalogue

            def changing(*args, **kwargs):
                rows = kept(*args, **kwargs)
                rows.reverse()
                return rows
            level_catalogue.read_catalogue = changing
            runpy.run_path(script, run_name="__main__")
            """))
        python = os.path.join(self.dir, "python")
        write(python, "#!/bin/sh\nexec '%s' '%s' \"$@\"\n" % (sys.executable, inject), 0o755)
        name, _ = self.level_name()
        args = [self.level, name, "--quiet", "--toolchain", self.dir, "--runner", self.fake, "--retail", self.elf]
        # without verify mode nothing notices (the reason verify mode exists)
        env = {k: v for k, v in self.env.items() if k != "CHECK_BATCH_VERIFY"}
        plain = self.cb.Worker(env=dict(env, UYA_VERSION="pal"), python=python)
        self.workers.append(plain)
        self.assertEqual(plain.run(args, timeout=120)[0], process(args, dict(env, UYA_VERSION="pal"))[0])
        w = self.cb.Worker(env=dict(env, UYA_VERSION="pal", CHECK_BATCH_VERIFY="1"), python=python)
        self.workers.append(w)
        with self.assertRaises(self.cb.KeptTableChanged) as e:
            w.run(args, timeout=120)
        self.assertIn("level_catalogue.read_catalogue", str(e.exception))
        self.assertIsNone(w.proc)                       # killed: none of its later checks can read it
        self.assertEqual(w.run(["--help"], timeout=60)[0], 0)
        self.assertEqual(w.started, 2)

    def test_a_worker_retires_after_its_checks(self):
        w = self.worker(max_checks=2)
        for _ in range(5):
            self.assertEqual(w.run(["--help"], timeout=60)[0], 0)
        self.assertEqual(w.started, 3)


def alive(pid):
    """True while PID runs (a zombie, killed and not yet reaped, is not running)."""
    try:
        with open("/proc/%d/status" % pid) as f:
            return "\nState:\tZ" not in f.read()
    except FileNotFoundError:
        return False


class CompileOneTest(unittest.TestCase):
    """c_objects.compile_one() with a check that does not finish: never a stored result."""

    def test_timeout_and_a_dead_worker_are_transient_with_their_reason(self):
        import argparse
        import c_objects
        import check_batch
        item = ("frontbin", "func_U_00381140", [("frontbin", 0x381140)], "src/us/frontbin/x.c", True)
        a = argparse.Namespace(toolchain="tc", runner=None, ee29=None, ee296=None, eeas=None)
        for error in (subprocess.TimeoutExpired(["check"], 600), check_batch.WorkerDied("exit -9")):
            def run(args):
                raise error
            notes = {}
            result = c_objects.compile_one(item, a, tempfile.gettempdir(), notes, run)
            self.assertEqual(result[1], "-")
            self.assertTrue(notes["transient"])
            self.assertEqual(len(notes["lost"]), 1)
        # killed by a signal (the old way's process): transient too
        notes = {}
        c_objects.compile_one(item, a, tempfile.gettempdir(), notes, lambda args: (-9, ""))
        self.assertTrue(notes["transient"])
        self.assertIn("signal 9", notes["lost"][0])


class NoInputs:
    """A c_objects.FileInputs whose functions read nothing (their keys are given)."""

    def inputs(self, program, rel, nat):
        return frozenset()


class StopTest(unittest.TestCase):
    """c_objects.main() when a worker reports a changed kept table: the run stops, that result and
    everything after it is not stored, what was stored before stays, index.tsv is untouched."""

    def test_the_run_stops_and_stores_nothing_of_that_check(self):
        import c_objects
        import check_batch
        from unittest.mock import patch
        items = [("levels", "func_L01_0030000%d" % i, [("level_01", 0x300000 + i * 8)], "src/levels/x.c", True)
                 for i in range(3)]

        def compile_one(item, a, tmp, notes=None, run=None):
            if item[1].endswith("1"):
                raise check_batch.KeptTableChanged("a check changed a table the worker keeps: "
                                                   "level_catalogue.read_catalogue(...)")
            return item, "-", "no compile of the block alone gives MATCH"
        seen = {}
        with tempfile.TemporaryDirectory() as d:
            out, reuse = os.path.join(d, "cobj"), os.path.join(d, "reuse")
            index = os.path.join(out, "index.tsv")
            os.makedirs(out)
            with open(index, "w") as f:
                f.write("levels\tfunc_L01_00300000\tbuild/us/cobj/levels/func_L01_00300000.o\n")
            with patch.multiple(c_objects, OUT=out, INDEX=index, REUSE=reuse, RESULTS=os.path.join(reuse, "r.tsv"),
                                placements=lambda: items, global_key=lambda a: "g", map_rows=lambda: {},
                                FileInputs=lambda **kw: seen.update(kw) or NoInputs(),
                                watch_tree=c_objects.Watch, global_inputs=lambda a, w: (), item_key=lambda i, g, r, f: "key " + i[1],
                                compile_one=compile_one), \
                    patch.object(sys, "argv", ["c_objects.py", "--toolchain", d, "-j", "1", "level_01"]):
                with self.assertRaises(SystemExit) as e:
                    c_objects.main()
                results = c_objects.read_results(os.path.join(reuse, "r.tsv"))
            self.assertIn("stopped", str(e.exception.code))
            self.assertIn("func_L01_00300001", str(e.exception.code))
            self.assertIn("level_catalogue.read_catalogue", str(e.exception.code))
            self.assertEqual(sorted(results), [("levels", "func_L01_00300000")])
            # the keys' header scan searches the toolchain's own folders (--toolchain D here)
            self.assertIn(os.path.abspath(d), seen["system"])
            self.assertEqual(read(index), "levels\tfunc_L01_00300000\tbuild/us/cobj/levels/func_L01_00300000.o\n")


class MemoTest(unittest.TestCase):
    def setUp(self):
        import memo
        self.memo = memo
        memo.disable()

    def tearDown(self):
        self.memo.disable()

    def test_off_unless_enabled_and_keyed_by_arguments_version_and_target(self):
        calls = []

        @self.memo.kept()
        def load(path, flag=False):
            calls.append((path, flag))
            return [path, flag]

        @self.memo.kept(target=True)
        def per_target():
            calls.append(os.environ.get("UYA_TARGET"))
            return {"t": os.environ.get("UYA_TARGET")}

        load("a")
        load("a")
        self.assertEqual(len(calls), 2)                 # off: read every time
        self.memo.enable()
        first = load("a")
        self.assertIs(load("a"), first)
        load("a", flag=True)
        load("b")
        self.assertEqual(len(calls), 5)
        from unittest.mock import patch
        with patch.dict(os.environ, {"UYA_TARGET": "level_01"}):
            self.assertEqual(per_target()["t"], "level_01")
            per_target()
        with patch.dict(os.environ, {"UYA_TARGET": "level_02"}):
            self.assertEqual(per_target()["t"], "level_02")
        self.assertEqual(len(calls), 7)
        import version
        with patch.object(version, "V", "us" if version.V == "pal" else "pal"):
            load("a")
        self.assertEqual(len(calls), 8)

    def test_verify_names_a_changed_table(self):
        @self.memo.kept()
        def table():
            return {"rows": [1, 2]}
        self.memo.enable(verify=True)
        t = table()
        self.assertEqual(self.memo.verify(), [])
        t["rows"].append(3)
        self.assertEqual(len(self.memo.verify()), 1)

    def test_targets_are_keyed_by_name(self):
        import targets
        self.assertEqual(self.memo._frozen((targets.TARGETS["frontbin"],)), ("tuple", ("target", "frontbin")))

    def test_the_marked_loaders(self):
        # the loaders a worker keeps (scratch/orch/batch/REPORT.md lists their callers)
        import level_catalogue
        import level_tree
        import progress
        import split_text
        import version_map
        for fn in (level_catalogue.read_catalogue, level_tree.source_entries, version_map.load,
                   progress.entries, split_text.file_statements):
            self.assertTrue(hasattr(fn, "uncached"), fn)


class CheckStateTest(unittest.TestCase):
    @unittest.skipUnless(HAVE_PACKAGES, "check.py needs pyelftools and capstone")
    def test_reset_forgets_every_check_state(self):
        import check
        check._ADDRS = {"x": 1}
        check.LEVEL.update(places={"f": (1, 2)}, names=object(), context="ctx", fe={"a"}, extra=1)
        check.US.update(places={"f": (1, 2)}, names=object())
        check.DNAS["plain"] = b"x"
        check.reset()
        self.assertIsNone(check._ADDRS)
        self.assertEqual(check.LEVEL, {"places": {}, "names": None, "context": None, "fe": set()})
        self.assertEqual(check.US, {"places": {}, "names": None})
        self.assertIsNone(check.DNAS["plain"])


def toolchain_ready():
    need = ("UYA_TOOLCHAIN", "UYA_RUNNER", "UYA_EE29", "UYA_EE296", "UYA_EEAS")
    return HAVE_PACKAGES and all(os.environ.get(k) for k in need) and \
        os.path.exists(ROOT / "baserom" / "us" / "frontbin.elf") and os.path.isdir(ROOT / "build" / "levels")


@unittest.skipUnless(toolchain_ready(), "needs the toolchain (env.sh), both discs' dumps and the level trees")
class RealChecksTest(unittest.TestCase):
    """Real functions of every kind, in one worker in two orders, against separate processes."""

    @classmethod
    def setUpClass(cls):
        import c_objects
        import version_map as vm
        cls.tmp = tempfile.mkdtemp(prefix="cobj_test_")
        items = c_objects.placements()
        files = c_objects.FileInputs()
        a = os.environ
        tc = ["--toolchain", a["UYA_TOOLCHAIN"], "--runner", a["UYA_RUNNER"], "--ee29", a["UYA_EE29"],
              "--ee296", a["UYA_EE296"], "--eeas", a["UYA_EEAS"]]

        def flags(it):
            return repr(files.flags(it[0], it[3], it[4])[1])

        def block(it):
            text = read(ROOT / it[3])
            m = re.search(r"localdecomp:start %s \*/(.*?)localdecomp:end" % re.escape(it[1]), text, re.S)
            return m.group(1) if m else ""

        def pick(why, test):
            for it in items:
                if test(it):
                    return why, it
            raise unittest.SkipTest("no function for: " + why)
        chosen = [
            pick("level function", lambda i: i[0] == "levels" and not i[4] and len(i[2]) == 1 and "@" not in flags(i)),
            pick("shared level function", lambda i: i[0] == "levels" and not i[4] and len(i[2]) > 3),
            pick("frontbin", lambda i: i[0] == "frontbin" and not i[4]),
            pick("boot_elf", lambda i: i[0] == "boot_elf" and not i[4]),
            pick("i5bootn", lambda i: i[0] == "i5bootn" and not i[4]),
            pick("@ps2as", lambda i: i[0] == "frontbin" and not i[4] and "@ps2as" in flags(i)),
            pick("@ee29", lambda i: i[0] == "boot_elf" and not i[4] and "@ee29" in flags(i) and "@ee296" not in flags(i)),
            pick("@ee296", lambda i: i[0] == "levels" and not i[4] and "@ee296" in flags(i)),
            pick("@eeas", lambda i: i[0] == "levels" and not i[4] and "@eeas" in flags(i) and "@ee296" not in flags(i)),
            pick("DNAS", lambda i: i[0] == "levels" and not i[4] and "DNAS_BEGIN" in block(i)),
            pick("native core", lambda i: i[0] == "boot_elf" and i[4]),
            pick("native level", lambda i: i[0] == "levels" and i[4]),
        ]
        cls.checks = []
        for why, (program, name, places, rel, nat) in chosen:
            if nat:
                target = program if program in c_objects.CORE else places[0][0]
                cls.checks.append((why, [str(ROOT / rel), name, "--quiet", "--native", "--target", target] + tc))
                continue
            path = os.path.join(cls.tmp, name + ".c")
            write(path, vm.chunk_text(program, rel, name))
            target = ["--target", program] if program in c_objects.CORE else []
            cls.checks.append((why, [path, name, "--quiet"] + tc + target))
            if why == "shared level function":
                for level, _ in places[1:4]:
                    cls.checks.append((why + " in " + level, [path, name, "--quiet", "--target", level] + tc))
            if why == "boot_elf":
                # a function that does not match: its block compiled without optimisation
                cls.checks.append(("not matching", [path, name, "--quiet", "--flags", "-O0"] + tc + target))
        cls.env = dict(os.environ, UYA_VERSION="us")
        cls.want = {why: process(["--version", "us"] + args, cls.env) for why, args in cls.checks}

    def run_in_worker(self, order):
        import check_batch
        w = check_batch.Worker(env=dict(self.env, CHECK_BATCH_VERIFY="1"))
        try:
            for why, args in order:
                got = w.run(["--version", "us"] + args, timeout=600)
                want = self.want[why]
                self.assertNotIn("check_batch:", got[2], why)
                self.assertEqual((got[0], masked(got[1])), (want[0], masked(want[1])), why)
            self.assertEqual(w.started, 1)
        finally:
            w.close()

    def test_every_kind_in_one_worker_as_in_separate_processes(self):
        verdicts = {why: re.findall(r"^func_\w+: (MATCH|\d+ diff)$", out, re.M) for why, (_, out, _) in self.want.items()}
        self.assertTrue(all(v == ["MATCH"] for why, v in verdicts.items() if why != "not matching"), verdicts)
        self.assertNotEqual(verdicts["not matching"], ["MATCH"])
        self.run_in_worker(self.checks)
        self.run_in_worker(self.checks[::-1])
        self.run_in_worker(self.checks[1::2] + self.checks[0::2])


if __name__ == "__main__":
    unittest.main()
