"""version.py: which disc a tool works on.

Two versions of the game, built and counted with the same tools:

    pal  SCES-524.56 (Europe and Australia): the primary target. Everything in src/ was matched
         against it; its paths are the repository's own (baserom/, config/<program>/,
         config/levels/, asm/, build/, progress/report.json).
    us   SCUS-973.53 (NTSC-U v1.00): the second version. Its dumps, tables and build are kept
         apart under baserom/us/, config/us/, asm/us/, build/us/ and progress/us/
         (docs/versions.md).

The version comes from a `--version pal|us` option (taken out of sys.argv when this module is
first imported, so every tool accepts it), else the UYA_VERSION environment variable, else pal.
The choice is put back into UYA_VERSION so the tools a tool runs see it too.
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VERSIONS = {"pal": "SCES_524.56", "us": "SCUS_973.53"}
LABELS = {"pal": "PAL (SCES-524.56)", "us": "NTSC-U (SCUS-973.53)"}


def _from_argv(argv):
    for i, a in enumerate(list(argv)):
        if a == "--version" and i + 1 < len(argv) and argv[i + 1] in VERSIONS:
            v = argv[i + 1]
            del argv[i:i + 2]
            return v
        if a.startswith("--version=") and a.split("=", 1)[1] in VERSIONS:
            del argv[i]
            return a.split("=", 1)[1]
    return None


V = _from_argv(sys.argv) or os.environ.get("UYA_VERSION") or "pal"
if V not in VERSIONS:
    sys.exit("unknown version %r (pal or us)" % V)
os.environ["UYA_VERSION"] = V


def is_us():
    return V == "us"


def disc_id(v=None):
    """SCES_524.56 / SCUS_973.53: the disc's serial, which names its ISO and its report."""
    return VERSIONS[v or V]


def iso(v=None):
    return os.path.join(ROOT, "baserom", disc_id(v) + ".iso")


def _under(top, v, parts):
    v = v or V
    return os.path.join(ROOT, top, *(([] if v == "pal" else [v]) + list(parts)))


def baserom(*parts, v=None):
    """baserom/... (pal) or baserom/us/... : the dumps, never committed."""
    return _under("baserom", v, parts)


def cfg(*parts, v=None):
    """config/... (pal) or config/us/... : the committed tables."""
    return _under("config", v, parts)


def asm(*parts, v=None):
    return _under("asm", v, parts)


def build(*parts, v=None):
    return _under("build", v, parts)


def progress(*parts, v=None):
    return _under("progress", v, parts)
