"""stamps.py: hashes of a tool's inputs, so a step whose inputs did not change can be skipped
(tools/c_objects.py).

A stamp is a SHA-1 over the bytes of files, given by path; a folder stands for every file in it
(sorted, followed through symbolic links, without __pycache__). A missing path is hashed as missing,
so creating it is a change too.
"""
import hashlib
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def files_under(path, exclude=()):
    """Every file under PATH (a file: itself), sorted, minus the absolute paths in EXCLUDE."""
    exclude = {os.path.abspath(p) for p in exclude}
    if os.path.isfile(path):
        return [] if os.path.abspath(path) in exclude else [path]
    out = []
    for d, ds, fs in os.walk(path, followlinks=True):
        ds[:] = sorted(x for x in ds if x != "__pycache__")
        for f in sorted(fs):
            p = os.path.join(d, f)
            if os.path.abspath(p) not in exclude and not f.endswith(".pyc"):
                out.append(p)
    return out


def update(h, paths, exclude=(), root=ROOT):
    """Hash each path's files into H: their names (relative to ROOT where they are inside it) and
    their bytes."""
    for path in paths:
        if path is None:
            h.update(b"<none>\0")
            continue
        h.update(b"path\0" + path.encode() + b"\0")
        if not os.path.exists(path):
            h.update(b"<missing>\0")
            continue
        for p in files_under(path, exclude):
            rel = os.path.relpath(p, root) if os.path.abspath(p).startswith(root + os.sep) else os.path.abspath(p)
            h.update(rel.replace(os.sep, "/").encode() + b"\0")
            with open(p, "rb") as f:
                for block in iter(lambda: f.read(1 << 20), b""):
                    h.update(block)
            h.update(b"\0")
    return h


def of(paths, exclude=(), root=ROOT):
    """The stamp (hex SHA-1) of PATHS."""
    return update(hashlib.sha1(), paths, exclude, root).hexdigest()


def file_sha1(path):
    """The SHA-1 of a file's bytes, or '-' when it does not exist."""
    if not os.path.isfile(path):
        return "-"
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for block in iter(lambda: f.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()

