"""objcache.py: reuse of the build's compiled objects, so that a run of tools/build.py (and of
tools/build_levels.py, which runs it per level) only compiles and assembles what changed.

tools/build_text.py builds each source file (or each slice of a mixed-flag file) in three steps,
and keeps the output of each step in build/objcache/ under a key of everything that can change it:

  1. compile (gcc -S, or Sony's 2.9-ee / 2.96-ee to assembly): the output kept is the compiler's
     assembly as it wrote it, before tools/asm_filter.py. The key: the C text the compiler reads
     (the source file, or the slice build_text.py wrote), every file it can include (a scan by
     tools/includes.py: every #include in it and in the headers it names, in every folder the
     compilers search, the compilers' own folders too, missing candidates counted as missing; when
     an #include cannot be followed, every header of include/ and src/), the exact command (the
     file's flags from text_parts.txt, the project's options, the source and output paths), which
     compiler (SN's ee-gcc through the --cc wrapper, @ee29, @ee296) and the bytes of every file of
     its toolchain folder and of the runner (wibo), the --cc and --ld wrapper scripts, every UYA_*
     environment variable, the repository's path, and the tools that build the commands and
     transform the output (build_text.py and every module of tools/ it imports: asm_filter.py,
     dnas.py, ee29.py, ee296.py, eeas.py, srcfiles.py, targets.py, ...; tools/stamps.py's
     tool_closure()).
  2. tools/asm_filter.py over that assembly (not for @ee29, @ee296 and @eeas ranges, which it
     leaves as they are): the output kept is the filtered assembly. The key: the compiler's
     assembly's bytes, whether the range is @ps2as, the tables the filter reads (the program's or
     the level's divs_nops.txt and sq_ra_funcs.txt, and config/levels/'s) and the tools.
  3. assemble (the driver's -c, or Sony's ee-as for @eeas): the output kept is the object as the
     assembler wrote it. The key: the filtered assembly's bytes, every file its `.include`s reach
     (include/macro.inc, the INCLUDE_ASM / INCLUDE_RODATA / ASM_FUNC .s files of asm/, and theirs,
     in every folder the assembler searches; tools/includes.py), the exact command, the assembler
     (SN's toolchain, or the @eeas program) with its bytes, and the same tools, environment and path
     as step 1. Assembly with an `.incbin`, or an `.include` the scan cannot follow, is never
     reused. tools/dnas.py then protects the object's DNAS blocks (level 39) every time, from
     config/levels/dnas_blocks.tsv, as a full build does.

A mixed-flag file's slices are joined with ld -r; that object is kept under a key of the slice
objects' bytes, the command and the --ld wrapper with its toolchain. The objects that
tools/build.py assembles from asm/ itself (the header blobs and data segments its linker script
names, and the pieces a level's or a core program's jump tables are cut into) are kept the same way
as step 3, with ee-as.exe's command and the .s file's path and bytes. Linking, flattening and the
check against the disc always run.

build_text.py first goes through the files in its own thread, taking each one whose steps can all
be reused (the work is then Python's, which -j threads only slow down), and gives the others to its
-j workers.

A kept output is reused only when its key is the same; nothing is ever reused across a change of
any input. An output is not kept when an input file the key read changed while the step ran (its
size, change time or inode differ after the step), so a source edited during a build does not get
its old object. Each entry is one file, build/objcache/<2 hex>/<key>, written whole or not at all
(a temporary file renamed into place), so builds running at once (tools/build_levels.py -P) share
the cache safely; a reused entry has its time set to now, and `prune()` removes the entries not
used for a number of days (tools/build_levels.py, after its builds: --cache-days, default 3).

--no-cache (tools/build.py, tools/build_levels.py, tools/build_text.py) or UYA_NO_CACHE=1 builds
everything again and leaves the cache as it is; deleting build/objcache/ empties it. The output is
byte for byte a full build's either way (docs/build/incremental.md has the proof and the timings).
"""
import hashlib
import os
import shutil
import sys
import threading
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

KEY_VERSION = "objcache 1"
CACHE_DIR = os.path.join(ROOT, "build", "objcache")
# what a key never reads: a flag that names another include folder or file makes the C scan unsound
EXTRA_INCLUDE_FLAGS = ("-I", "-include", "-imacros", "-idirafter", "-iprefix", "-iwithprefix",
                       "-isystem", "-nostdinc", "-iquote")


def disabled_by_env():
    return os.environ.get("UYA_NO_CACHE", "") not in ("", "0")


class Hasher:
    """SHA-1s of files and folders, kept per process; a file's is taken again when its state
    (size, change time, inode) differs from the one it was taken at."""

    def __init__(self):
        self._files, self._trees = {}, {}
        self._lock = threading.Lock()

    @staticmethod
    def state(path):
        try:
            s = os.stat(path)
        except OSError:
            return None
        return (s.st_size, s.st_mtime_ns, s.st_ctime_ns, s.st_ino, s.st_dev)

    def _take(self, path):
        """(SHA-1, whether it has an `.incbin`) of a file; ('-', False) when it is missing."""
        st = self.state(path)
        if st is None or not os.path.isfile(path):
            return "-", False
        with self._lock:
            got = self._files.get(path)
        if got and got[0] == st:
            return got[1]
        with open(path, "rb") as f:
            data = f.read()
        got = (hashlib.sha1(data).hexdigest(), b".incbin" in data)
        with self._lock:
            self._files[path] = (st, got)
        return got

    def file(self, path):
        """The file's SHA-1, or '-' when it is missing."""
        return self._take(path)[0]

    def has_incbin(self, path):
        return self._take(path)[1]

    def tree(self, path):
        """The SHA-1 of a folder's files (names and bytes, followed through links), of a file, or
        of a missing path; taken once per process (a toolchain does not change during a build)."""
        path = os.path.abspath(path)
        with self._lock:
            if path in self._trees:
                return self._trees[path]
        import stamps
        h = hashlib.sha1()
        if not os.path.exists(path):
            h.update(b"<missing>\0")
        for p in stamps.files_under(path) if os.path.exists(path) else ():
            h.update(os.path.relpath(p, path).replace(os.sep, "/").encode() + b"\0")
            h.update(self.file(p).encode() + b"\0")
        with self._lock:
            self._trees[path] = h.hexdigest()
        return self._trees[path]


HASHER = Hasher()


def which(program):
    """A program as a path: itself when it names a file, else the one PATH finds (or the name)."""
    if program and not os.path.isfile(program):
        found = shutil.which(program)
        if found:
            return found
    return program


class Key:
    """A key being built: a SHA-1 over labelled parts. The files it reads are remembered (watch)
    so that a caller can tell, after the step, whether any of them changed meanwhile."""

    def __init__(self, kind):
        self.h = hashlib.sha1(("%s\0%s\0" % (KEY_VERSION, kind)).encode())
        self.watched = {}

    def text(self, label, value):
        if isinstance(value, str):
            value = value.encode("utf-8", "surrogateescape")
        elif not isinstance(value, bytes):
            value = repr(value).encode("utf-8", "surrogateescape")
        self.h.update(label.encode() + b"\0" + str(len(value)).encode() + b"\0" + value + b"\0")
        return self

    def file(self, label, path):
        """A file by name and bytes (or as missing)."""
        self.watched[path] = Hasher.state(path)
        return self.text(label, "%s %s" % (rel(path), HASHER.file(path)))

    def tree(self, label, path):
        """A toolchain folder or program: every file's name and bytes."""
        return self.text(label, "%s %s" % (path, HASHER.tree(path)))

    def common(self, scripts):
        """What every key has: the tools (SCRIPTS and the modules of tools/ they import), the
        repository's path and the UYA_* environment variables (common_digest())."""
        return self.text("common", common_digest(scripts))

    def changed(self):
        """True when a file the key read is not in the state it was in when it was read."""
        return any(Hasher.state(p) != st for p, st in self.watched.items())

    def hexdigest(self):
        return self.h.hexdigest()


_COMMON = {}


def common_digest(scripts):
    """Key.common()'s part, once per process: the files of tools/ that SCRIPTS are made of
    (tools/stamps.py's tool_closure()), the repository's path and the UYA_* environment variables."""
    import stamps
    k = tuple(os.path.abspath(p) for p in scripts)
    with _SCAN_LOCK:
        if k not in _COMMON:
            key = Key("common")
            for p in stamps.tool_closure(list(k)):
                key.file("tool", p)
            key.text("root", ROOT)
            key.text("env", sorted((n, v) for n, v in os.environ.items() if n.startswith("UYA_")))
            _COMMON[k] = key.hexdigest()
        return _COMMON[k]


def standard_includes(options):
    """True when the compile OPTIONS (a list) name no include folder or file but `-I include` and
    `-I .` (what tools/includes.py's scan assumes)."""
    i = 0
    while i < len(options):
        o = options[i]
        if o == "-I" and i + 1 < len(options):
            if options[i + 1].rstrip("/\\") not in ("include", ".", ""):
                return False
            i += 2
            continue
        if o in ("-Iinclude", "-I.", "-Iinclude/"):
            i += 1
            continue
        if o.startswith(EXTRA_INCLUDE_FLAGS):
            return False
        if o.startswith("-Wa,"):
            # the assembler's -I: include/ only (tools/includes.py's assembler folders)
            parts = o[4:].split(",")
            for n, w in enumerate(parts):
                if w == "-I" and (n + 1 >= len(parts) or parts[n + 1] != "include"):
                    return False
                if w.startswith("-I") and w != "-I" and w[2:] != "include":
                    return False
        i += 1
    return True


def rel(path):
    a = os.path.abspath(path)
    return os.path.relpath(a, ROOT).replace(os.sep, "/") if a.startswith(ROOT + os.sep) else a


_SCANNERS = {}
_SCAN_LOCK = threading.Lock()


def scanner(system=()):
    """One tools/includes.py Scanner per set of compiler folders, for the whole process."""
    import includes
    k = tuple(system)
    with _SCAN_LOCK:
        if k not in _SCANNERS:
            _SCANNERS[k] = includes.Scanner(ROOT, includes.toolchain_dirs(system))
        return _SCANNERS[k]


def add_headers(key, text, here, system=()):
    """Every file the C TEXT (in folder HERE) can include, into KEY (tools/includes.py); every
    header of include/ and src/ when an #include cannot be followed."""
    import stamps
    sc = scanner(system)
    with _SCAN_LOCK:
        found = sc.scan([(text, here)])
    if found is None:
        key.text("headers", "every header")
        for p in stamps.files_under(os.path.join(ROOT, "include")):
            key.file("header", p)
        for p in stamps.files_under(os.path.join(ROOT, "src")):
            if not p.endswith(".c"):
                key.file("header", p)
        return key
    existing, missing = _split(found)
    key.text("headers missing", missing)
    for path in existing:
        key.file("header", path)
    return key


_SPLITS = {}


def _split(found):
    """([paths that exist], the names of the missing ones as one text) of a scan's result."""
    with _SCAN_LOCK:
        got = _SPLITS.get(found)
    if got is None:
        got = ([p for p, e in found if e], "\0".join(rel(p) for p, e in found if not e))
        with _SCAN_LOCK:
            _SPLITS[found] = got
    return got


def add_asm_includes(key, text, here):
    """Every file the assembly TEXT (in folder HERE) can `.include`, into KEY. False when the
    assembly cannot be reused: an `.incbin` (in it or in a file it includes), or an include that
    tools/includes.py cannot follow."""
    import includes
    if b".incbin" in text:
        return False
    decoded = text.decode("latin-1")
    found = {(k, n, here) for k, n in includes.directives(decoded) if k == "asm"}
    if any(n is None for _, n, _ in found):
        return False
    sc = scanner()
    with _SCAN_LOCK:
        got = sc.resolve(frozenset(found))
    if got is None:
        return False
    existing, missing = _split(got)
    key.text("asm includes missing", missing)
    for path in existing:
        if HASHER.has_incbin(path):
            return False
        key.file("asm include", path)
    return True


class Cache:
    """build/objcache/: one file per key. ENABLED False: nothing is looked up or kept."""

    def __init__(self, enabled=True, root=CACHE_DIR):
        self.enabled = enabled and not disabled_by_env()
        self.root = root
        self.hits, self.misses = 0, 0
        self._lock = threading.Lock()

    def path(self, key):
        return os.path.join(self.root, key[:2], key)

    def _count(self, hit):
        with self._lock:
            if hit:
                self.hits += 1
            else:
                self.misses += 1

    def has(self, key):
        return self.enabled and key is not None and os.path.isfile(self.path(key))

    def fetch(self, key, dest):
        """Copy the entry for KEY to DEST (whole or not at all); True when there was one."""
        if not self.enabled or key is None:
            return False
        src = self.path(key)
        tmp = "%s.objcache.%d.%d" % (dest, os.getpid(), threading.get_ident())
        try:
            shutil.copyfile(src, tmp)
        except OSError:
            self._count(False)
            return False
        os.replace(tmp, dest)
        try:
            os.utime(src)
        except OSError:
            pass
        self._count(True)
        return True

    def store(self, key, src):
        """Keep a copy of the file SRC as the entry for KEY."""
        if not self.enabled or key is None:
            return
        dest = self.path(key)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        tmp = "%s.tmp.%d.%d" % (dest, os.getpid(), threading.get_ident())
        shutil.copyfile(src, tmp)
        os.replace(tmp, dest)

    def summary(self):
        if not self.enabled:
            return "objcache: off"
        return "objcache: %d steps reused, %d run" % (self.hits, self.misses)


def reset():
    """Forget what this process has hashed and scanned (for a test that plays several runs)."""
    global HASHER
    HASHER = Hasher()
    with _SCAN_LOCK:
        _SCANNERS.clear()
        _COMMON.clear()
        _SPLITS.clear()


def prune(days, root=CACHE_DIR, now=None):
    """Remove the entries not used (kept or reused) for DAYS days; returns how many."""
    now = time.time() if now is None else now
    gone = 0
    if not os.path.isdir(root):
        return 0
    for d in os.listdir(root):
        sub = os.path.join(root, d)
        if not os.path.isdir(sub):
            continue
        for f in os.listdir(sub):
            p = os.path.join(sub, f)
            try:
                if now - os.stat(p).st_mtime > days * 86400:
                    os.remove(p)
                    gone += 1
            except OSError:
                pass
    return gone
