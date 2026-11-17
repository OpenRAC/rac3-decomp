#!/usr/bin/env python3
"""check_batch.py: many tools/check.py runs in one long-lived process (tools/c_objects.py).

A check reads the same large tables for every function (the level catalogues, config/us/map.tsv,
src/levels/'s source entries, the core programs' earlier declarations): started once per function,
about 85% of its time is reading them again. A worker of this module imports check.py once and
runs check after check in it, each exactly as `python3 tools/check.py ARGS` would, and keeps those
tables between checks (tools/memo.py: only in such a worker, only the loaders marked there).

    worker = check_batch.Worker()                     # starts `python3 tools/check_batch.py --serve`
    rc, out, err = worker.run(["--version", "us", "f.c", "func_X", ...], timeout=600)
    worker.close()

run() returns what the separate process would have: its exit status, its standard output and its
standard error. It raises subprocess.TimeoutExpired when the check took longer than TIMEOUT (the
worker and everything it started are killed; the next run() starts a new one) and WorkerDied when
the worker ended in the middle of a check (killed, crashed); either way the caller records the
check as not done. It raises KeptTableChanged when the worker, in verify mode
(CHECK_BATCH_VERIFY=1), found after the check that a table it keeps is no longer what its loader
returned: the worker is killed, and the caller must not use that check's result and should stop,
since every later check of a worker with a changed table could read it (tools/c_objects.py
stops its run). A worker retires after MAX_CHECKS checks and is replaced at the next run(), so
that memory it gathers stays bounded.

Between two checks the worker puts back what a check may leave in the process: the environment
(check.py sets UYA_TARGET), sys.path, sys.argv, the working directory, check.py's module state
(check.reset(), also done by every check.main()); the tables kept are given out as they were read
(tools/memo.py, which can verify that no check changed one: CHECK_BATCH_VERIFY=1).

Protocol (one JSON object per line): the parent writes {"args": [...]} to the worker's standard
input; the worker answers {"returncode": N, "stdout": "...", "stderr": "...", "changed": [...]} on
its standard output ("changed": the kept tables a check changed, in verify mode; the check's
status is then 70 unless it already failed, and its standard error says so, for a reader of the
reply alone). Inside the worker, file descriptor 0 is /dev/null and 1 is its standard error, so nothing a
compiler run by a check reads or writes can reach the protocol.
"""
import contextlib
import io
import json
import os
import select
import signal
import subprocess
import sys
import time
import traceback

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
MAX_CHECKS = 1000


class WorkerDied(Exception):
    """The worker ended while it ran a check."""


class KeptTableChanged(Exception):
    """In verify mode, the worker found after a check that the check changed a table it keeps
    (tools/memo.py): that check's result, and any later one of the worker, cannot be trusted."""


class Worker:
    """A worker process, started on its first run()."""

    def __init__(self, env=None, max_checks=MAX_CHECKS, log=None, python=sys.executable):
        self.env, self.max_checks, self.log, self.python = env, max_checks, log, python
        self.proc, self.done, self.started = None, 0, 0

    def _start(self):
        cmd = [self.python, os.path.join(TOOLS, "check_batch.py"), "--serve"]
        err = open(self.log, "ab") if self.log else subprocess.DEVNULL
        try:
            self.proc = subprocess.Popen(cmd, cwd=ROOT, env=self.env, stdin=subprocess.PIPE,
                                         stdout=subprocess.PIPE, stderr=err, start_new_session=True)
        finally:
            if self.log:
                err.close()
        self.buf, self.done = b"", 0
        self.started += 1

    def run(self, args, timeout=600):
        if self.proc is not None and self.done >= self.max_checks:
            self.close()
        if self.proc is None:
            self._start()
        self.done += 1
        try:
            self.proc.stdin.write((json.dumps({"args": list(args)}) + "\n").encode())
            self.proc.stdin.flush()
        except (BrokenPipeError, OSError):
            self._lost()
            raise WorkerDied("the worker had ended before the check (exit %s)%s" % (self.proc_status, self._tail()))
        line = self._readline(time.monotonic() + timeout)
        if line is None:
            self._kill()
            raise subprocess.TimeoutExpired(args, timeout)
        if line == b"":
            self._lost()
            raise WorkerDied("the worker ended during the check (exit %s)%s" % (self.proc_status, self._tail()))
        reply = json.loads(line)
        if reply.get("changed"):
            self._kill()
            raise KeptTableChanged("a check changed a table the worker keeps: %s (check: %s)"
                                   % (", ".join(reply["changed"]), " ".join(args)))
        return reply["returncode"], reply["stdout"], reply["stderr"]

    def _tail(self):
        """The end of the worker's log (its standard error), for the reason a check was lost."""
        try:
            with open(self.log, errors="replace") as f:
                text = f.read()[-300:].strip()
        except (OSError, TypeError):
            return ""
        return ": " + " | ".join(text.splitlines()[-3:]) if text else ""

    def _readline(self, deadline):
        """The next line from the worker; b"" at its end, None when DEADLINE passes first."""
        fd = self.proc.stdout.fileno()
        while b"\n" not in self.buf:
            left = deadline - time.monotonic()
            if left <= 0 or not select.select([fd], [], [], left)[0]:
                return None
            chunk = os.read(fd, 1 << 16)
            if not chunk:
                return b""
            self.buf += chunk
        line, self.buf = self.buf.split(b"\n", 1)
        return line

    def _kill(self):
        """End the worker and every process it started (its session)."""
        if self.proc is None:
            return
        try:
            os.killpg(self.proc.pid, signal.SIGKILL)
        except (ProcessLookupError, PermissionError):
            pass
        self._lost()

    def _lost(self):
        p, self.proc = self.proc, None
        for f in (p.stdin, p.stdout):
            try:
                f.close()
            except OSError:
                pass
        try:
            self.proc_status = p.wait(timeout=30)
        except subprocess.TimeoutExpired:
            p.kill()
            self.proc_status = p.wait()
        try:
            os.killpg(p.pid, signal.SIGKILL)      # what it started and left behind
        except (ProcessLookupError, PermissionError):
            pass

    def close(self):
        """Stop the worker (it ends when its input does)."""
        if self.proc is None:
            return
        try:
            self.proc.stdin.close()
        except OSError:
            pass
        try:
            self.proc.wait(timeout=30)
        except subprocess.TimeoutExpired:
            pass
        self._kill()


# --- the worker -----------------------------------------------------------------------------------

def serve():
    """Answer checks until standard input ends (see the module's docstring)."""
    requests = os.fdopen(os.dup(0), "rb")
    replies = os.fdopen(os.dup(1), "wb")
    null = os.open(os.devnull, os.O_RDONLY)
    os.dup2(null, 0)
    os.close(null)
    os.dup2(2, 1)
    sys.argv = [os.path.join(TOOLS, "check.py")]
    sys.path.insert(0, TOOLS)
    import memo
    memo.enable(verify=os.environ.get("CHECK_BATCH_VERIFY") == "1")
    import check
    import version
    env, path, cwd = dict(os.environ), list(sys.path), os.getcwd()
    for line in requests:
        args = list(json.loads(line)["args"])
        v = version._from_argv(args)
        out, err = io.StringIO(), io.StringIO()
        if v is not None and v != version.V:
            err.write("this worker checks on %s, not %s\n" % (version.V, v))
            code = 2
        else:
            code = run_one(check, args, out, err)
        # what a check may leave in the process
        os.environ.clear()
        os.environ.update(env)
        sys.path[:] = path
        sys.argv[:] = [os.path.join(TOOLS, "check.py")]
        os.chdir(cwd)
        problems = memo.verify()
        if problems:
            err.write("check_batch: a check changed a kept table: %s\n" % ", ".join(problems))
            code = code or 70
        replies.write((json.dumps({"returncode": code, "stdout": out.getvalue(), "stderr": err.getvalue(),
                                   "changed": problems}) + "\n").encode())
        replies.flush()


def run_one(check, args, out, err):
    """check.main(ARGS) with its output in OUT and ERR; the exit status a process would have had."""
    code = 0
    with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
        try:
            check.main(args)
        except SystemExit as e:
            # as Python's own exit: None is 0, a number is the status, anything else is printed
            if e.code is None:
                code = 0
            elif isinstance(e.code, int):
                code = e.code
            else:
                print(e.code, file=sys.stderr)
                code = 1
        except Exception:
            traceback.print_exc()
            code = 1
        sys.stdout.flush()
        sys.stderr.flush()
    return code


if __name__ == "__main__":
    if sys.argv[1:] != ["--serve"]:
        sys.exit(__doc__)
    serve()
