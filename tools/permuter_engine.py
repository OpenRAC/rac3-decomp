#!/usr/bin/env python3
"""permuter_engine.py: run decomp-permuter's random search natively, with live progress.

decomp-permuter's command line is Linux-only (bash compile scripts, objdump).
This engine reuses its randomizer and candidate logic (the `src` package of a
decomp-permuter checkout) but compiles with the project's own toolchain the
same way tools/permuter_setup.py's compile.sh does and scores with
tools/permuter_scorer.py (aligned instruction diffs, 0 = match). So it runs on
Windows (no WSL) as well as Linux, and localdecomp uses it for its Permuter
panel.

    python3 tools/permuter_engine.py scratch/f.c func_0038E930 -j4 --seconds 600
    python3 tools/permuter_engine.py scratch/f.c --permuter ../Tools/decomp-permuter

It prints one status line per second and writes improvements to
scratch/permuter/<func>/output-<diffs>-<n>/source.c.

Needs: a decomp-permuter checkout (--permuter, $DECOMP_PERMUTER, or
../Tools/decomp-permuter, ../decomp-permuter next to the repo) and its Python
dependency `toml` (pip install toml; on Python 3.11+ the standard library's
tomllib stands in when it's missing). The empty-asm passes (perm_reg_fence,
perm_sched_barrier) need tools/decomp-permuter-asm-passes.patch applied to that
checkout; without it the engine runs the stock passes and says so.
"""
import argparse, hashlib, json, os, queue, re, shutil, subprocess, sys, tempfile, threading, time, traceback
import multiprocessing as mp

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

ASM_PASS_WEIGHTS = {"perm_reg_fence": 15, "perm_sched_barrier": 10}
KEEP_PROB = 0.6   # decomp-permuter's DEFAULT_RAND_KEEP_PROB


def find_permuter(explicit=None):
    cands = [explicit, os.environ.get("DECOMP_PERMUTER"),
             os.path.join(ROOT, "..", "Tools", "decomp-permuter"),
             os.path.join(ROOT, "..", "decomp-permuter"),
             os.path.join(ROOT, "..", "..", "Tools", "decomp-permuter"),
             os.path.join(ROOT, "tools", "decomp-permuter")]
    for c in cands:
        if c and os.path.isfile(os.path.join(c, "src", "permuter.py")) and \
                os.path.isdir(os.path.join(c, "perm_pycparser")):
            return os.path.abspath(c)
    return None


def _toml_shim():
    """decomp-permuter imports `toml`; on Python 3.11+ stand in with the
    standard library's tomllib when toml isn't installed."""
    try:
        import toml  # noqa: F401
        return True
    except ImportError:
        pass
    try:
        import tomllib
    except ImportError:
        return False
    import types
    m = types.ModuleType("toml")
    m.load = lambda f: tomllib.loads(f.read() if hasattr(f, "read") else open(f).read())
    m.loads = tomllib.loads
    sys.modules["toml"] = m
    return True


def _import_permuter(path):
    _toml_shim()
    if path not in sys.path:
        sys.path.insert(0, path)
    import src.permuter as sp  # noqa: F401  (decomp-permuter's package)
    import src.helpers as sh
    import src.randomizer as sr
    return sp, sh, sr


def check_permuter(path):
    """(ok, message, has_asm_passes) without starting a job."""
    if not path:
        return False, ("no decomp-permuter checkout found: pass --permuter, set DECOMP_PERMUTER, "
                       "or put it at ../Tools/decomp-permuter"), False
    if not _toml_shim():
        return False, "decomp-permuter needs the Python package toml (pip install toml) or Python 3.11+", False
    try:
        _, _, sr = _import_permuter(path)
    except Exception as e:
        return False, f"can't import decomp-permuter from {path}: {e}", False
    names = {m.__name__ for m in sr.RANDOMIZATION_PASSES}
    return True, path, all(n in names for n in ASM_PASS_WEIGHTS)


# --------------------------------------------------------------------------
# preparation (parent process)
# --------------------------------------------------------------------------

LEVEL_FUNC_RE = re.compile(r"func_L\d\d_[0-9A-Fa-f]{8}$")


def level_setup(func, t):
    """A level function (catalogue name func_LNN_XXXXXXXX, docs/build/levels.md): set check.py's
    LEVEL for it in this process, at its place in level NN (or in `t` when that is a level that
    has it), as tools/check.py does. Returns (the level's target name, its file's flags), or None
    for a program function."""
    if not LEVEL_FUNC_RE.match(func):
        return None
    import io, contextlib
    import check as tf
    with contextlib.redirect_stdout(io.StringIO()):
        lt, flags = tf.level_function([func], t)
    return lt.name, flags


def prepare(src_text, func, target, toolchain, runner, mode=None, asm=None, no_context=False, cpp=None):
    """Everything a worker needs: base source, prelude hints, typedef
    attributes and the compile flags (flags_for(), then --mode/--as)."""
    os.environ["UYA_TARGET"] = target
    cwd = os.getcwd()
    os.chdir(ROOT)
    try:
        import targets
        import check as tf
        import permuter_setup as psu
        t = targets.get(target)
        level = level_setup(func, t)
        if level:
            target, flags = level
        else:
            flags = tf.flags_for(int(func[5:13], 16))
        cpp = cpp or psu.default_cpp(toolchain, runner)
        base, hints, attrs = psu.build_base(src_text, func, cpp, no_context, tf)
        flags = tf.apply_overrides(flags, mode, asm)
        if not level and ("@ee29" in flags or "@ee296" in flags or "@eeas" in flags):
            raise RuntimeError(f"{func} is in an @ee29/@ee296/@eeas range; the engine only drives SN ee-gcc")
        return dict(func=func, target=target, base=base, prelude="\n".join(h.strip() for h in hints) + "\n",
                    attrs=attrs, flags=flags, toolchain=toolchain, runner=runner, level=bool(level))
    finally:
        os.chdir(cwd)


# --------------------------------------------------------------------------
# workers
# --------------------------------------------------------------------------

class _Compiler:
    """compile.sh from tools/permuter_setup.py, in Python."""

    def __init__(self, cfg, tmp):
        import check as tf
        import permuter_setup as psu
        self.cfg, self.tmp, self.psu = cfg, tmp, psu
        self.cc_flags = tf.expand(cfg["flags"], cfg["toolchain"])
        gcc = os.path.join(cfg["toolchain"], "bin", "ee-gcc2953.exe")
        self.base = ([cfg["runner"]] if cfg["runner"] else []) + [gcc]
        self.attrs_path = os.path.join(tmp, "attrs.json")
        json.dump(cfg["attrs"], open(self.attrs_path, "w"))
        self.n = 0
        self.last_error = ""

    def compile(self, source, show_errors=False):
        self.n += 1
        c = os.path.join(self.tmp, "in.c")
        s = os.path.join(self.tmp, "out.s")
        o = os.path.join(self.tmp, "out%d.o" % (self.n % 4))
        open(c, "w").write(self.cfg["prelude"] + source)
        if self.cfg["attrs"]:
            self.psu.reattach(self.attrs_path, c)
        for f in (s, o):
            if os.path.exists(f):
                os.remove(f)
        if self.cfg.get("level"):
            return self._compile_level(c, o)
        p = subprocess.run(self.base + ["-S", "-I", "include", "-I", "."] + self.cc_flags + ["-o", s, c],
                           cwd=ROOT, capture_output=True, text=True)
        if p.returncode or not os.path.exists(s):
            self.last_error = (p.stderr or p.stdout)[-2000:]
            return None
        subprocess.run([sys.executable, os.path.join(TOOLS, "asm_filter.py")]
                       + (["--ps2as"] if "@ps2as" in self.cfg["flags"] else []) + [s], cwd=ROOT,
                       capture_output=True)
        p = subprocess.run(self.base + ["-c", "-I", "include", "-I", "."] + self.cc_flags + ["-o", o, s],
                           cwd=ROOT, capture_output=True, text=True)
        if p.returncode or not os.path.exists(o):
            self.last_error = (p.stderr or p.stdout)[-2000:]
            return None
        return o


    def _compile_level(self, c, o):
        """A level function: check.py's own compile (its level names, loop padding, div.s nops,
        @ee29/@ee296/@eeas), with no context added, since base.c already holds the file's context.
        base.c is preprocessed, so the "common.h" check.py would add is already in it."""
        import io, contextlib
        import check as tf
        src = open(c).read()
        open(c, "w").write("/* common.h: already preprocessed into base.c */\n" + src)
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            got = tf.compile_c(c, self.cfg["flags"], _CArgs(self.cfg["toolchain"], self.cfg["runner"], True),
                               name=self.cfg["func"])
        if not got:
            self.last_error = out.getvalue()[-2000:]
            return None
        shutil.move(got, o)
        shutil.rmtree(os.path.dirname(got), ignore_errors=True)
        return o


class _Scorer:
    PENALTY_INF = 10 ** 9

    def __init__(self, func):
        import permuter_scorer as ps
        self.ps, self.func = ps, func

    def score(self, o):
        if not o:
            return self.PENALTY_INF, ""
        try:
            nd = self.ps.score(o, self.func)
        except Exception:
            return self.PENALTY_INF, ""
        from elftools.elf.elffile import ELFFile
        with open(o, "rb") as fh:
            text = ELFFile(fh).get_section_by_name(".text").data()
        return nd, hashlib.sha256(text).hexdigest()


def _worker(cfg, wid, outq, stop, seed):
    comp = None
    try:
        os.chdir(ROOT)
        os.environ["UYA_TARGET"] = cfg["target"]
        if TOOLS not in sys.path:
            sys.path.insert(0, TOOLS)
        if cfg.get("level"):
            import targets
            level_setup(cfg["func"], targets.get(cfg["target"]))
        sp, sh, sr = _import_permuter(cfg["permuter"])
        import random as _r
        _r.seed(seed)
        weights = dict(sh.get_default_randomization_weights("gcc"))
        for k, v in cfg.get("weights", {}).items():
            if k in weights:
                weights[k] = v
        # record which pass each randomization used, for the activity feed
        last_pass = [None]
        orig = sr.Randomizer.randomize

        def randomize(self, ast, fn_name):
            methods = self.methods
            chosen = []

            def wrap(m):
                def f(*a, **k):
                    chosen.append(m.__name__)
                    return m(*a, **k)
                f.__name__ = m.__name__
                return f
            self.methods = [(wrap(m), w) for m, w in methods]
            try:
                orig(self, ast, fn_name)
            finally:
                self.methods = methods
            last_pass[0] = chosen[-1] if chosen else None
        sr.Randomizer.randomize = randomize

        tmp = tempfile.mkdtemp(prefix="permw%d_" % wid)
        comp = _Compiler(cfg, tmp)
        scorer = _Scorer(cfg["func"])
        p = sp.Permuter(tmp, cfg["func"], comp, scorer, "base.c", cfg["base"],
                        randomization_weights=weights, force_seed=None, force_rng_seed=None,
                        keep_prob=KEEP_PROB, need_profiler=False, need_all_sources=False,
                        show_errors=False, best_only=False, better_only=False,
                        score_threshold=None, debug_mode=False, speed=100)
        outq.put(("base", wid, p.base_score, p.base_source if wid == 0 else None))
        batch, last_flush = [], time.time()
        for s in p.seed_iterator():
            if stop.is_set():
                break
            last_pass[0] = None
            res = p.try_eval_candidate(s)
            if isinstance(res, sp.EvalError):
                batch.append((last_pass[0], None))
                if res.exc_str:
                    outq.put(("error", wid, res.exc_str[-1500:]))
            else:
                sc = res.score if res.score < scorer.PENALTY_INF else None
                batch.append((last_pass[0], sc))
                if p.should_output(res):
                    p.record_result(res)
                    outq.put(("found", wid, res.score, res.source, last_pass[0]))
            if time.time() - last_flush > 0.5:
                outq.put(("tick", wid, batch))
                batch, last_flush = [], time.time()
        outq.put(("tick", wid, batch))
        shutil.rmtree(tmp, ignore_errors=True)
        outq.put(("done", wid))
    except Exception:
        tb = traceback.format_exc()
        if comp is not None and comp.last_error:
            tb += "\ncompiler output:\n" + comp.last_error
        outq.put(("fatal", wid, tb))


# --------------------------------------------------------------------------
# jobs (parent)
# --------------------------------------------------------------------------

class Job:
    """One permuter run: N worker processes plus a collector thread. All state
    lives in self.state (plain JSON-able data) for the localdecomp panel."""

    def __init__(self, cfg, jobs=2, seconds=0, out_dir=None):
        self.cfg = cfg
        self.jobs = max(1, int(jobs))
        self.seconds = float(seconds or 0)
        self.out_dir = out_dir or os.path.join(ROOT, "scratch", "permuter", cfg["func"])
        self.id = "%s-%d" % (cfg["func"], int(time.time() * 1000))
        self.lock = threading.Lock()
        self.state = dict(id=self.id, func=cfg["func"], target=cfg["target"], flags=cfg["flags"],
                          jobs=self.jobs, seconds=self.seconds, status="starting", message="",
                          started=time.time(), elapsed=0.0, iterations=0, errors=0, compile_errors=0,
                          base_score=None, best_score=None, rate=0.0, timeline=[], events=[],
                          event_seq=0, passes={}, outputs=[], asm_passes=bool(cfg.get("weights")),
                          out_dir=self.out_dir, worker_errors=[])
        self.base_source = None
        self._sources = {}
        self._seen = set()
        self._ctx = mp.get_context("spawn")
        self._stop = self._ctx.Event()
        self._q = self._ctx.Queue()
        self._procs = []
        self._rate_win = []

    # -- lifecycle --
    def start(self):
        os.makedirs(self.out_dir, exist_ok=True)
        for w in range(self.jobs):
            pr = self._ctx.Process(target=_worker, args=(self.cfg, w, self._q, self._stop, int(time.time() * 1e6) + w),
                                   daemon=True)
            pr.start()
            self._procs.append(pr)
        self._thread = threading.Thread(target=self._collect, daemon=True)
        self._thread.start()
        return self

    def stop(self, reason="stopped"):
        with self.lock:
            if self.state["status"] in ("running", "starting"):
                self.state["status"] = reason
        self._stop.set()

    def _finish(self):
        for pr in self._procs:
            pr.join(timeout=3)
            if pr.is_alive():
                pr.terminate()

    # -- collection --
    def _event(self, kind, **kw):
        self.state["event_seq"] += 1
        ev = dict(seq=self.state["event_seq"], t=round(time.time() - self.state["started"], 2), kind=kind, **kw)
        self.state["events"].append(ev)
        if len(self.state["events"]) > 600:
            del self.state["events"][:-600]

    def _collect(self):
        done = 0
        last_tl = 0
        while done < self.jobs:
            try:
                msg = self._q.get(timeout=0.5)
            except queue.Empty:
                msg = None
            now = time.time()
            with self.lock:
                st = self.state
                st["elapsed"] = round(now - st["started"], 1)
                if self.seconds and st["elapsed"] >= self.seconds and st["status"] == "running":
                    st["status"] = "time limit"
                    self._stop.set()
                if msg:
                    kind = msg[0]
                    if kind == "base":
                        _, wid, score, src = msg
                        if st["base_score"] is None:
                            st["base_score"] = score
                            st["best_score"] = score
                            st["timeline"].append([st["elapsed"], score])
                            self._event("base", score=score)
                        if src:
                            self.base_source = src
                        if st["status"] == "starting":
                            st["status"] = "running"
                    elif kind == "tick":
                        _, wid, batch = msg
                        for pas, sc in batch:
                            st["iterations"] += 1
                            if sc is None:
                                st["compile_errors"] += 1
                            ps_ = st["passes"].setdefault(pas or "(none)", [0, 0, 0])
                            ps_[0] += 1
                            if sc is None:
                                ps_[2] += 1
                        self._rate_win.append((now, len(batch)))
                        # sample a few recent candidates for the feed
                        for pas, sc in batch[-3:]:
                            self._event("try", worker=wid, pass_=pas, score=sc)
                    elif kind == "found":
                        _, wid, score, src, pas = msg
                        h = hashlib.sha256((src or "").encode()).hexdigest()
                        if h not in self._seen:
                            self._seen.add(h)
                            improved = st["best_score"] is None or score < st["best_score"]
                            if improved:
                                st["best_score"] = score
                                st["timeline"].append([st["elapsed"], score])
                                if pas:
                                    st["passes"].setdefault(pas, [0, 0, 0])[1] += 1
                            n = len(st["outputs"]) + 1
                            d = os.path.join(self.out_dir, "output-%d-%d" % (score, n))
                            os.makedirs(d, exist_ok=True)
                            open(os.path.join(d, "source.c"), "w").write(src)
                            self._sources[n] = src
                            st["outputs"].append(dict(n=n, score=score, t=st["elapsed"], pass_=pas,
                                                      worker=wid, path=d, improved=improved))
                            self._event("found", worker=wid, pass_=pas, score=score, n=n, improved=improved)
                            if score == 0:
                                st["status"] = "matched"
                                self._stop.set()
                    elif kind == "error":
                        st["errors"] += 1
                        if len(st["worker_errors"]) < 5:
                            st["worker_errors"].append(msg[2])
                    elif kind == "fatal":
                        st["worker_errors"].append(msg[2])
                        self._event("fatal", worker=msg[1], text=msg[2][-800:])
                        if st["base_score"] is None:
                            st["status"] = "error"
                            st["message"] = msg[2].strip().split("\n")[-1]
                        done += 1
                    elif kind == "done":
                        done += 1
                self._rate_win = [(t, n) for t, n in self._rate_win if now - t < 10]
                span = max(1.0, min(10.0, now - st["started"]))
                st["rate"] = round(sum(n for _, n in self._rate_win) / span, 2)
                if now - last_tl > 5 and st["best_score"] is not None:
                    st["timeline"].append([st["elapsed"], st["best_score"]])
                    last_tl = now
                    if len(st["timeline"]) > 2000:
                        st["timeline"] = st["timeline"][:1] + st["timeline"][-1999:]
        self._finish()
        with self.lock:
            if self.state["status"] in ("running", "starting"):
                self.state["status"] = "finished"
            self.state["elapsed"] = round(time.time() - self.state["started"], 1)

    # -- queries --
    def snapshot(self, since=0):
        with self.lock:
            st = dict(self.state)
            st["events"] = [e for e in self.state["events"] if e["seq"] > since]
            st["outputs"] = sorted(self.state["outputs"], key=lambda o: (o["score"], o["n"]))[:40]
            st["passes"] = {k: list(v) for k, v in self.state["passes"].items()}
            st["timeline"] = list(self.state["timeline"])
            return st

    def output(self, n):
        import difflib
        src = self._sources.get(int(n))
        if src is None:
            return None
        func = self.cfg["func"]

        def fn_only(s):
            i = s.find(func + "(")
            j = s.rfind("\n", 0, i) if i >= 0 else -1
            return s[j + 1:] if j >= 0 else s
        a, b = fn_only(self.base_source or ""), fn_only(src)
        diff = "\n".join(difflib.unified_diff(a.split("\n"), b.split("\n"), "base", "candidate", lineterm="", n=2))
        return dict(n=int(n), source=src, function=b, diff=diff)


# --------------------------------------------------------------------------
# exhaustive fence/barrier search (tools/fence_search.py's edits, run as a job)
# --------------------------------------------------------------------------

def prepare_exhaustive(src_text, func, target, toolchain, runner, mode=None, asm=None):
    os.environ["UYA_TARGET"] = target
    cwd = os.getcwd()
    os.chdir(ROOT)
    try:
        import targets
        import check as tf
        level = level_setup(func, targets.get(target))
        if level:
            target, flags = level
        else:
            flags = tf.flags_for(int(func[5:13], 16))
        flags = tf.apply_overrides(flags, mode, asm)
        return dict(func=func, target=target, source=src_text, flags=flags, toolchain=toolchain,
                    runner=runner, exhaustive=True, weights={}, level=bool(level))
    finally:
        os.chdir(cwd)


class _CArgs:
    def __init__(self, toolchain, runner, no_context=False):
        self.toolchain, self.runner = toolchain, runner
        self.no_context, self.early_extern_sizes, self.ee29 = no_context, {}, None
        self.ee296, self.eeas = os.environ.get("UYA_EE296"), os.environ.get("UYA_EEAS")


def _exh_score(job):
    """Pool task: compile one variant in context and score it."""
    cfg, tag, text = job
    try:
        os.chdir(ROOT)
        os.environ["UYA_TARGET"] = cfg["target"]
        if TOOLS not in sys.path:
            sys.path.insert(0, TOOLS)
        import check as tf
        import permuter_scorer as ps
        import io, contextlib
        if cfg.get("level"):
            import targets
            level_setup(cfg["func"], targets.get(cfg["target"]))
        d = tempfile.mkdtemp(prefix="fence_")
        path = os.path.join(d, "v.c")
        open(path, "w").write(text)
        with contextlib.redirect_stdout(io.StringIO()):
            o = tf.compile_c(path, cfg["flags"], _CArgs(cfg["toolchain"], cfg["runner"]), name=cfg["func"])
        n = None
        if o:
            try:
                n = ps.score(o, cfg["func"])
            except Exception:
                n = None
            shutil.rmtree(os.path.dirname(o), ignore_errors=True)
        shutil.rmtree(d, ignore_errors=True)
        return tag, n
    except Exception:
        return tag, None


def _edit_kind(tag):
    return "pair" if "+" in tag else tag.split("_")[0]


class ExhaustiveJob(Job):
    """Every fence, barrier, do-while wrap and swap from tools/fence_search.py,
    then pairs of the best ones, compiled on a process pool. Same state and
    queries as Job, so the panel shows it the same way."""

    def start(self):
        os.makedirs(self.out_dir, exist_ok=True)
        self.state["asm_passes"] = True
        self._thread = threading.Thread(target=self._run, daemon=True)
        self._thread.start()
        return self

    def _found(self, tag, score, text):
        st = self.state
        st["best_score"] = score
        st["timeline"].append([st["elapsed"], score])
        st["passes"].setdefault(_edit_kind(tag), [0, 0, 0])[1] += 1
        n = len(st["outputs"]) + 1
        d = os.path.join(self.out_dir, "output-%d-%d" % (score, n))
        os.makedirs(d, exist_ok=True)
        open(os.path.join(d, "source.c"), "w").write(text)
        self._sources[n] = text
        st["outputs"].append(dict(n=n, score=score, t=st["elapsed"], pass_=tag, worker=0, path=d, improved=True))
        self._event("found", worker=0, pass_=tag, score=score, n=n, improved=True)
        if score == 0:
            st["status"] = "matched"
            self._stop.set()

    def _batch(self, pool, items, texts):
        """Score items [(tag, text)] on the pool; True when the run should stop."""
        import concurrent.futures as cf
        futs = {pool.submit(_exh_score, (self._small, tag, text)): tag for tag, text in items}
        texts.update(dict(items))
        results = []
        for fut in cf.as_completed(futs):
            tag, n = fut.result()
            now = time.time()
            with self.lock:
                st = self.state
                st["elapsed"] = round(now - st["started"], 1)
                st["iterations"] += 1
                ps_ = st["passes"].setdefault(_edit_kind(tag), [0, 0, 0])
                ps_[0] += 1
                if n is None:
                    st["compile_errors"] += 1
                    ps_[2] += 1
                self._rate_win.append((now, 1))
                self._rate_win = [(t, k) for t, k in self._rate_win if now - t < 10]
                st["rate"] = round(len(self._rate_win) / max(1.0, min(10.0, now - st["started"])), 2)
                self._event("try", worker=0, pass_=tag, score=n)
                if n is not None:
                    results.append((n, tag))
                    if st["best_score"] is None or n < st["best_score"]:
                        self._found(tag, n, texts[tag])
                if self.seconds and st["elapsed"] >= self.seconds and st["status"] == "running":
                    st["status"] = "time limit"
                    self._stop.set()
            if self._stop.is_set():
                for f in futs:
                    f.cancel()
                return results, True
        return results, False

    def _run(self):
        import concurrent.futures as cf
        os.environ["UYA_TARGET"] = self.cfg["target"]
        if TOOLS not in sys.path:
            sys.path.insert(0, TOOLS)
        cwd = os.getcwd()
        try:
            os.chdir(ROOT)
            import fence_search as fs
        finally:
            os.chdir(cwd)
        func, src = self.cfg["func"], self.cfg["source"]
        self._small = {k: self.cfg[k] for k in ("func", "target", "flags", "toolchain", "runner")}
        lines = src.split("\n")
        try:
            start, end = fs.func_range(lines, func)
        except StopIteration:
            with self.lock:
                self.state["status"] = "error"
                self.state["message"] = f"no definition of {func} in the editor code"
            return
        types = fs.var_types(lines, start, end)
        singles = fs.edits(lines, start, end, types, {"fence", "barrier", "dowhile", "swap"})
        self.base_source = src
        texts = {}
        with cf.ProcessPoolExecutor(max_workers=self.jobs, mp_context=self._ctx) as pool:
            tag, base = pool.submit(_exh_score, (self._small, "base", src)).result()
            with self.lock:
                st = self.state
                if base is None:
                    st["status"] = "error"
                    st["message"] = "the editor code doesn't compile (Build shows why)"
                    return
                st["base_score"] = st["best_score"] = base
                st["timeline"].append([0, base])
                st["status"] = "running"
                self._event("base", score=base)
                self._event("phase", text=f"{len(singles)} single edits")
            results, stop = self._batch(pool, [(e[0], fs.apply(lines, [e])) for e in singles], texts)
            if not stop:
                ranked = []
                for n, tag in sorted(results):
                    if tag not in ranked:
                        ranked.append(tag)
                    if len(ranked) >= 12:
                        break
                top = [e for e in singles if e[0] in ranked]
                pairs = set()
                for e1 in top:
                    for e2 in singles:
                        if e1 is not e2 and not fs.conflicts(e1, e2):
                            pairs.add(tuple(sorted((e1, e2), key=lambda e: e[0])))
                items = [("+".join(e[0] for e in p), fs.apply(lines, list(p))) for p in sorted(pairs)]
                with self.lock:
                    self._event("phase", text=f"{len(items)} pairs of the 12 best edits with every other edit")
                self._batch(pool, items, texts)
        with self.lock:
            if self.state["status"] in ("running", "starting"):
                self.state["status"] = "finished"
            self.state["elapsed"] = round(time.time() - self.state["started"], 1)


# --------------------------------------------------------------------------
# command line
# --------------------------------------------------------------------------

def compile_level(cfg_path, c_path, o_path):
    """compile.sh of a level function's tools/permuter_setup.py directory: one candidate through
    check.py's compile, as the engine's workers do. Exit status 1 when it does not compile."""
    cfg = json.load(open(cfg_path))
    os.chdir(ROOT)
    os.environ["UYA_TARGET"] = cfg["target"]
    import targets
    level_setup(cfg["func"], targets.get(cfg["target"]))
    tmp = tempfile.mkdtemp(prefix="permc_")
    try:
        c = os.path.join(tmp, "in.c")
        shutil.copyfile(c_path, c)
        comp = _Compiler(cfg, tmp)
        o = comp._compile_level(c, os.path.join(tmp, "out.o"))
        if not o:
            sys.stderr.write(comp.last_error)
            return 1
        shutil.copyfile(o, o_path)
        return 0
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


def main():
    if len(sys.argv) == 5 and sys.argv[1] == "--compile-level":
        sys.exit(compile_level(*sys.argv[2:5]))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("func", nargs="?")
    ap.add_argument("-j", type=int, default=max(1, (os.cpu_count() or 2) - 1))
    ap.add_argument("--seconds", type=float, default=0)
    ap.add_argument("--permuter")
    ap.add_argument("--asm-passes", action="store_true",
                    help="DIAGNOSIS ONLY: enable the fence/barrier passes (inline asm, not allowed in matched C)")
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--target", default=os.environ.get("UYA_TARGET", "frontbin"))
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN", "C:/tools/eegcc_2.95.3_sn_v1.36"))
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    a = ap.parse_args()
    perm = find_permuter(a.permuter)
    ok, msg, has_asm = check_permuter(perm)
    if not ok:
        sys.exit(msg)
    src = open(a.file).read()
    func = a.func or re.search(r"\b(func_(?:L\d\d_)?[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{", src).group(1)
    cfg = prepare(src, func, a.target, a.toolchain, a.runner, a.mode, a.asm)
    cfg["permuter"] = perm
    cfg["weights"] = dict(ASM_PASS_WEIGHTS) if (a.asm_passes and has_asm) else {}
    if a.asm_passes and not has_asm:
        print("note: this decomp-permuter has no empty-asm passes (apply tools/decomp-permuter-asm-passes.patch)")
    job = Job(cfg, a.j, a.seconds).start()
    print(f"{func}: flags {' '.join(cfg['flags'])}; {a.j} workers; outputs in {job.out_dir}")
    seen = 0
    try:
        while True:
            time.sleep(1)
            s = job.snapshot(seen)
            for e in s["events"]:
                seen = e["seq"]
                if e["kind"] in ("found", "base", "fatal"):
                    print(f"  [{e['t']:7.1f}s] {e['kind']} score={e.get('score')} pass={e.get('pass_')}"
                          + (f"\n{e['text']}" if e['kind'] == 'fatal' else ""))
            print(f"{s['status']:10s} {s['elapsed']:7.1f}s  iter {s['iterations']}  {s['rate']}/s  "
                  f"base {s['base_score']}  best {s['best_score']}", flush=True)
            if s["status"] not in ("running", "starting"):
                if not job._thread.is_alive():
                    break
    except KeyboardInterrupt:
        job.stop()
        job._thread.join(10)


if __name__ == "__main__":
    mp.freeze_support()
    main()
