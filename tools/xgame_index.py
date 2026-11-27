#!/usr/bin/env python3
"""xgame_index.py: a cross-game index of every function of the OpenRAC decompilations, to find
matched C of the same engine routine in another game (docs/contributing/cross-game-index.md).

  python3 tools/xgame_index.py build [--games DIR] [-j N]   # build/xgame_index.sqlite
  python3 tools/xgame_index.py query func_L01_0044AF78 [-n 10] [--game rac3]
  python3 tools/xgame_index.py query rac2:func_002B2A10
  python3 tools/xgame_index.py query path/to/func_00308E88.s
  python3 tools/xgame_index.py sweep [-j N] [--out build/xgame_sweep.tsv]

`build` reads the games of config/xgame_index.json: each version's progress report (every
function, matched or not), its retail bytes from the game's dumps, and its src/ (a function is
matched when an active C definition names it, under its address name or a readable name, and no
asm marker does: the rule of tools/sister_twins.py). For every function it stores fingerprints that
survive other addresses, registers and constants:

  ops     the normalised opcode sequence: mnemonics without registers or immediates, a move, a
          load-immediate and a stack access as one token each whatever their width, branch-likely
          folded into its branch, each branch marked forward or backward;
  cfg     the basic blocks in order: how each ends (fall, branch, jump, call, return, switch),
          where its successors are (next, forward, back, out) and its length class;
  calls   the calls in order, each as its number of integer and float argument registers set
          before it (no targets), plus tail calls and indirect calls;
  consts  float constants (lui + mtc1), 32-bit integer constants (lui + ori), loads of immediate
          over 16 and andi/slti operands;
  offs    struct field offsets of loads and stores (relocated %lo halves and $sp/$gp left out);
  frame   the stack frame size;
  key     the relocation-masked words (tools/twin_mask.py): equal keys are the same code.

Candidates come from a MinHash of the opcode 4-grams, then every kind is scored (0..1) and
combined: ops 0.40, cfg 0.20, calls 0.15, consts 0.10, offs 0.10, frame 0.05 (a kind empty on
both sides drops out of the mean). `query` lists matched counterparts first, then unmatched
ones. `sweep` lists, for every rac3 PAL function still in assembly, its best matched counterpart
in any game and its best one in another game, largest first.
"""
import argparse
import hashlib
import json
import os
import re
import sqlite3
import struct
import sys
import time
import zlib
from difflib import SequenceMatcher

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from twin_mask import key_of, masked, strip_padding, words_of  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MANIFEST = os.path.join(ROOT, "config", "xgame_index.json")
INDEX = os.path.join(ROOT, "build", "xgame_index.sqlite")
SWEEP = os.path.join(ROOT, "build", "xgame_sweep.tsv")
FORMAT = 1
NHASH = 64
PRIME = (1 << 31) - 1
SHINGLE = 4
WEIGHTS = {"ops": 0.40, "cfg": 0.20, "calls": 0.15, "consts": 0.10, "offs": 0.10, "frame": 0.05}
KINDS = list(WEIGHTS)
# how many candidates get the exact opcode alignment, by the query's instruction count
FULL_RATIO = ((300, 120), (1000, 40), (1 << 30, 15))
SP, GP, RA = 29, 28, 31

try:
    import numpy as np
except ImportError:         # the tests run without it; build and query are just slower
    np = None


def _seeds():
    import random
    r = random.Random(0x5AC3)
    return [(r.randrange(1, PRIME), r.randrange(0, PRIME)) for _ in range(NHASH)]


SEEDS = _seeds()

# ------------------------------------------------------------------ instruction decoding
LIKELY_OF = {0x14: 0x04, 0x15: 0x05, 0x16: 0x06, 0x17: 0x07}
COND_BRANCH = {0x04: "beq", 0x05: "bne", 0x06: "blez", 0x07: "bgtz"}
REGIMM_BRANCH = {0: "bltz", 1: "bgez", 2: "bltz", 3: "bgez", 0x10: "bltzal", 0x11: "bgezal",
                 0x12: "bltzal", 0x13: "bgezal"}
LOADS_INT = {0x1A, 0x1B, 0x1E, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x37}
STORES = {0x1F, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x39, 0x3D, 0x3E, 0x3F}
LOADS_OTHER = {0x31, 0x35, 0x36}         # lwc1 ldc1 lqc2
MEM = LOADS_INT | STORES | LOADS_OTHER
WIDTH = {0x20: "b", 0x24: "b", 0x28: "b", 0x21: "h", 0x25: "h", 0x29: "h", 0x23: "w", 0x27: "w",
         0x2B: "w", 0x22: "w", 0x26: "w", 0x2A: "w", 0x2E: "w", 0x37: "d", 0x3F: "d", 0x1A: "d",
         0x1B: "d", 0x2C: "d", 0x2D: "d", 0x1E: "q", 0x1F: "q", 0x31: "f", 0x39: "f", 0x35: "fd",
         0x3D: "fd", 0x36: "v", 0x3E: "v"}
MOVES = {0x21, 0x2D, 0x25}               # addu daddu or with $zero
IMM_ALU = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x18, 0x19}
INT_ARGS = range(4, 12)                  # $a0-$a7 (the EE ABI)
FLT_ARGS = range(12, 20)                 # $f12-$f19


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def decode(w):
    """-> (token, control, int dest, float dest) of one word. control: None, or one of
    ('b', offset) conditional branch, ('B', offset) unconditional, 'j' jump, 'call', 'callr',
    'ret', 'jr'."""
    op = w >> 26
    rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    fn = w & 63
    imm = w & 0xFFFF
    if w == 0:
        return "nop", None, None, None
    if op == 0:
        if fn == 0x08:
            return ("ret", "ret", None, None) if rs == RA else ("jr", "jr", None, None)
        if fn == 0x09:
            return "jalr", "callr", rd, None
        if fn in MOVES and (rt == 0 or rs == 0):
            return "mov", None, rd, None
        if fn in (0x0C, 0x0D, 0x0F, 0x11, 0x13, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F):
            return "s%x" % fn, None, None, None
        return "s%x" % fn, None, rd, None
    if op == 0x01:
        if rt in REGIMM_BRANCH:
            if rt == 1 and rs == 0:
                return "b", ("B", s16(imm)), None, None
            return REGIMM_BRANCH[rt], ("b", s16(imm)), None, None
        return "r%x" % rt, None, None, None
    if op == 0x02:
        return "j", "j", None, None
    if op == 0x03:
        return "jal", "call", RA, None
    if op in COND_BRANCH or op in LIKELY_OF:
        base = LIKELY_OF.get(op, op)
        if base == 0x04 and rs == 0 and rt == 0:
            return "b", ("B", s16(imm)), None, None
        return COND_BRANCH[base], ("b", s16(imm)), None, None
    if op == 0x0F:
        return "lui", None, rt, None
    if op in IMM_ALU:
        if rs == 0 and op in (0x09, 0x0D, 0x19):
            return "li", None, rt, None
        if rs == SP and rt == SP:
            return "sp", None, rt, None
        return "i%x" % op, None, rt, None
    if op in MEM:
        if rs == SP:
            return ("spl" if op in LOADS_INT or op in LOADS_OTHER else "sps"), None, \
                (rt if op in LOADS_INT else None), (rt if op == 0x31 else None)
        kind = "l" if op in LOADS_INT or op in LOADS_OTHER else "s"
        return kind + WIDTH.get(op, "%x" % op), None, (rt if op in LOADS_INT else None), \
            (rt if op == 0x31 else None)
    if op == 0x11:                                       # COP1
        if rs == 0x08:
            return "bc1", ("b", s16(imm)), None, None
        if rs in (0, 2):
            return ("mfc1", "cfc1")[rs // 2], None, rt, None
        if rs in (4, 6):
            return ("mtc1", "ctc1")[rs // 4 - 1], None, None, (rd if rs == 4 else None)
        fd = (w >> 6) & 31
        return "f%x.%x" % (rs, fn), None, None, (None if fn >= 0x30 else fd)
    if op == 0x12:                                       # COP2 (VU0 macro mode)
        if rs == 0x08:
            return "bc2", ("b", s16(imm)), None, None
        if rs < 0x10:
            return "v.%x" % rs, None, (rt if rs in (1, 2) else None), None
        if fn >= 0x3C:
            return "v2.%x.%x" % ((w >> 6) & 31, fn & 3), None, None, None
        return "v%x" % fn, None, None, None
    if op == 0x1C:                                       # MMI
        if fn in (0x08, 0x09, 0x28, 0x29):
            return "m%x.%x" % (fn, (w >> 6) & 31), None, rd, None
        return "m%x" % fn, None, (rd if fn not in (0x18, 0x19, 0x1A, 0x1B, 0x11, 0x13) else None), None
    if op == 0x10:
        return "c0.%x" % rs, None, (rt if rs == 0 else None), None
    return "o%x" % op, None, None, None


# ------------------------------------------------------------------ fingerprints
def _bucket(n):
    return 0 if n <= 1 else 1 if n <= 3 else 2 if n <= 7 else 3 if n <= 15 else 4 if n <= 31 else 5


def fingerprint(code, va=0):
    """-> dict of the fingerprints of a function whose bytes are code at address va."""
    raw = strip_padding(words_of(code))
    m = masked(key_of(raw)) if raw else ()
    n = len(raw)
    dec = [decode(w) for w in raw]
    ops = []
    for i, (tok, ctl, _, _) in enumerate(dec):
        if ctl and ctl[0] in ("b", "B"):
            tok += ">" if ctl[1] >= 0 else "<"
        elif ctl == "j":
            tgt = ((va + 4 * i) & 0xF0000000) | ((raw[i] & 0x03FFFFFF) << 2)
            tok = "j>" if va <= tgt < va + 4 * n else "tail"
        ops.append(tok)

    # basic blocks
    leaders = {0}
    term = {}                       # index of the control word -> (kind, [targets])
    for i, (tok, ctl, _, _) in enumerate(dec):
        if not ctl:
            continue
        if ctl in ("call", "callr"):
            continue                # a call does not end a block
        tg = []
        if ctl[0] in ("b", "B"):
            t = i + 1 + ctl[1]
            tg = [t]
            kind = "c" if ctl[0] == "b" else "u"
        elif ctl == "j":
            t = ((((va + 4 * i) & 0xF0000000) | ((raw[i] & 0x03FFFFFF) << 2)) - va) // 4
            tg = [t]
            kind = "u" if 0 <= t < n else "t"
        elif ctl == "ret":
            kind = "r"
        else:
            kind = "s"              # jr: a switch
        term[i] = (kind, tg)
        for t in tg:
            if 0 <= t < n:
                leaders.add(t)
        if i + 2 < n:
            leaders.add(i + 2)
    starts = sorted(x for x in leaders if x < n)
    bidx = {s: k for k, s in enumerate(starts)}
    cfg = []
    for k, s in enumerate(starts):
        e = starts[k + 1] if k + 1 < len(starts) else n
        ctl_at = next((i for i in range(max(s, e - 2), e) if i in term), None)
        if ctl_at is None:
            cfg.append("f%d" % _bucket(e - s))
            continue
        kind, tg = term[ctl_at]
        succ = ""
        for t in tg:
            if not 0 <= t < n:
                succ += "x"
            else:
                d = bidx.get(t, k) - k
                succ += "n" if d == 1 else "b" if d <= 0 else "f"
        if kind == "c":
            succ += "n"
        cfg.append("%s%s%d" % (kind, succ, _bucket(e - s)))

    # calls: argument registers set since the previous call
    calls = []
    ints, flts = set(), set()
    i = 0
    while i < n:
        tok, ctl, di, df = dec[i]
        if di is not None and di in INT_ARGS:
            ints.add(di)
        if df is not None and df in FLT_ARGS:
            flts.add(df)
        if ctl in ("call", "callr") or (ctl == "j" and ops[i] == "tail"):
            if i + 1 < n:
                _, _, di2, df2 = dec[i + 1]
                if di2 is not None and di2 in INT_ARGS:
                    ints.add(di2)
                if df2 is not None and df2 in FLT_ARGS:
                    flts.add(df2)
            lead = {"call": "c", "callr": "r", "j": "t"}[ctl]
            calls.append("%s%d.%d" % (lead, len(ints), len(flts)))
            ints, flts = set(), set()
            i += 2
            continue
        i += 1

    # constants and offsets
    consts, offs = set(), set()
    lui = {}
    frame = 0
    for i, w in enumerate(raw):
        op = w >> 26
        rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = w & 0xFFFF
        if op == 0x0F:
            if m[i] == w:               # not an address %hi (twin_mask)
                lui[rt] = imm
            else:
                lui.pop(rt, None)
            continue
        if op == 0x11 and rs == 4 and rt in lui:            # mtc1: a float constant
            consts.add("f%04X" % lui[rt])
        elif op == 0x0D and rs in lui and rs == rt:           # lui + ori: a 32-bit integer
            consts.add("i%08X" % ((lui[rs] << 16) | imm))
        elif op in (0x09, 0x19, 0x0D) and rs == 0 and not -16 <= s16(imm) <= 16:
            consts.add("i%d" % (imm if op == 0x0D else s16(imm)))
        elif op == 0x0C:
            consts.add("&%X" % imm)
        elif op in (0x0A, 0x0B) and not -16 <= s16(imm) <= 16:
            consts.add("<%d" % s16(imm))
        if op in (0x09, 0x19) and rs == SP and rt == SP and s16(imm) < 0 and not frame and i < 8:
            frame = -s16(imm)
        if op in MEM and rs not in (SP, GP) and m[i] == w:
            offs.add("%s%X" % (WIDTH.get(op, "?"), imm))
        dst = decode(w)[2]
        if dst is not None and op != 0x0D:
            lui.pop(dst, None)
    return {
        "n": n,
        "ops": ops,
        "cfg": cfg,
        "calls": calls,
        "consts": sorted(consts),
        "offs": sorted(offs),
        "frame": frame,
        "key": hashlib.sha1(key_of(m)).hexdigest()[:16] if m else "",
    }


def shingles(ops):
    """The hashed opcode 4-grams of a sequence (the whole of a shorter one)."""
    if len(ops) < SHINGLE:
        return {zlib.crc32(" ".join(ops).encode()) % PRIME} if ops else {0}
    return {zlib.crc32(" ".join(ops[i:i + SHINGLE]).encode()) % PRIME for i in range(len(ops) - SHINGLE + 1)}


def minhash(ops):
    xs = shingles(ops)
    if np is not None:
        x = np.fromiter(xs, dtype=np.uint64)
        a = np.array([s[0] for s in SEEDS], dtype=np.uint64)[:, None]
        b = np.array([s[1] for s in SEEDS], dtype=np.uint64)[:, None]
        return [int(v) for v in ((a * x[None, :] + b) % PRIME).min(axis=1)]
    return [min((a * x + b) % PRIME for x in xs) for a, b in SEEDS]


# ------------------------------------------------------------------ similarity
def seq_ratio(a, b):
    if not a and not b:
        return 1.0
    if not a or not b:
        return 0.0
    sm = SequenceMatcher(None, a, b, autojunk=False)
    return sm.ratio()


def jaccard(a, b):
    if not a and not b:
        return None
    a, b = set(a), set(b)
    return len(a & b) / len(a | b)


def similarity(f, g, quick=False):
    """-> (combined score, {kind: score or None}) of two fingerprint dicts. quick: the ops kind as
    the share of equal tokens whatever their order (an upper bound, in linear time)."""
    ops = SequenceMatcher(None, f["ops"], g["ops"], autojunk=False).quick_ratio() if quick \
        else seq_ratio(f["ops"], g["ops"])
    s = {
        "ops": ops,
        "cfg": seq_ratio(f["cfg"], g["cfg"]),
        "calls": seq_ratio(f["calls"], g["calls"]),
        "consts": jaccard(f["consts"], g["consts"]),
        "offs": jaccard(f["offs"], g["offs"]),
        "frame": 1.0 if f["frame"] == g["frame"] else
        1.0 - abs(f["frame"] - g["frame"]) / max(f["frame"], g["frame"]),
    }
    tw = sum(WEIGHTS[k] for k in KINDS if s[k] is not None)
    total = sum(WEIGHTS[k] * s[k] for k in KINDS if s[k] is not None) / tw
    if f["key"] and f["key"] == g["key"]:
        total = 1.0
    return total, s


# ------------------------------------------------------------------ reading the games
def games_root(arg=None):
    for c in (arg, os.environ.get("OPENRAC_GAMES")):
        if c:
            return os.path.abspath(os.path.expanduser(c))
    up = os.path.dirname(os.path.dirname(ROOT))
    if os.path.isfile(os.path.join(up, "rac3", "game.json")):
        return up
    return os.path.expanduser("~/Projects/RAC/OpenRAC/games")


def load_manifest(path=MANIFEST):
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def asm_files(data_root, prefix, exclude):
    """stem -> [path] of every func_*.s under data_root/prefix."""
    out = {}
    top = os.path.join(data_root, prefix)
    if not os.path.isdir(top):
        return out
    for dp, dn, fn in os.walk(top):
        rel = os.path.relpath(dp, data_root).replace("\\", "/") + "/"
        if any(rel.startswith(e) for e in exclude):
            dn[:] = []
            continue
        for f in fn:
            if f.startswith("func_") and f.endswith(".s"):
                out.setdefault(f[:-2], []).append(os.path.join(dp, f))
    return out


LEVEL_NAME = re.compile(r"func_(?:[A-Z0-9]+_)?L(\d\d)_")


def asm_path(files, name, va, nn):
    for stem in (name, "func_%08X" % va):
        cands = files.get(stem, [])
        if nn:
            lv = [p for p in cands if re.search(r"/(?:level_)?%s(?:_|/)" % nn, p.replace("\\", "/"))]
            cands = lv or (cands if stem == name else [])
        else:
            cands = [p for p in cands if not re.search(r"/(?:levels|overlays)/|/level_\d\d/", p)] or cands
        if cands:
            return cands[0]
    return ""


def collect(manifest, groot, log=print, only=None):
    """-> rows (dicts without fingerprints) of every function of every game version, with the
    image path and address of its bytes."""
    import sister_twins as st
    rows = []
    for g in manifest["games"]:
        game = g["game"]
        if only and game not in only:
            continue
        src_root = ROOT if g.get("self") else os.path.join(groot, g["root"])
        data_root = src_root
        if g.get("self") and not os.path.isdir(os.path.join(ROOT, "baserom")):
            data_root = os.environ.get("UYA_DATA") or os.path.join(groot, g["root"])
        if not os.path.isdir(os.path.join(src_root, "src")):
            log("%s: skipped, no %s/src" % (game, src_root))
            continue
        for v in g["versions"]:
            rp = os.path.join(src_root, v["report"])
            core = os.path.join(data_root, v["core"])
            if not os.path.isfile(rp) or not os.path.exists(core):
                log("%s %s: skipped, no %s" % (game, v["version"], rp if not os.path.isfile(rp) else core))
                continue
            key = (src_root, tuple(v["exclude"]))
            if key not in st._trees:
                st._trees[key] = st.scan_tree(src_root, tuple(v["exclude"]))
            defs, asm = st._trees[key]
            rn = st.readable_names(src_root)
            levels = st.level_map(os.path.join(data_root, v["levels"][0]), v["levels"][1])
            units = {k: os.path.join(data_root, p) for k, p in v.get("units", {}).items()}
            names = {k: os.path.join(data_root, p) for k, p in v.get("names", {}).items()}
            files = asm_files(data_root, v["asm"], v.get("asm_exclude", [])) if v.get("asm") else {}
            with open(rp, encoding="utf-8") as f:
                rep = json.load(f)
            n = nm = 0
            for u in rep["units"]:
                lvl_unit = re.match(r"Level (\d+)", u["name"])
                where = u.get("metadata", {}).get("source_path")
                for fn in u.get("functions", []):
                    name = fn["name"]
                    size = int(fn["size"])
                    va = int(fn["metadata"]["virtual_address"])
                    m = LEVEL_NAME.match(name)
                    nn = m.group(1) if m else None
                    if not nn and lvl_unit and not re.match(r"func_[0-9A-F]{8}$", name):
                        nn = "%02d" % int(lvl_unit.group(1))
                    if nn:
                        img = levels.get(nn)
                    else:
                        img = next((p for k, p in names.items() if name.startswith(k)), None) \
                            or units.get(u["name"].split("/")[0]) or core
                    al = [name] + rn.get(name, [])
                    matched, cpath = False, ""
                    if not any(x in asm for x in al):
                        d = st.pick_def(defs, al, where)
                        if d:
                            matched = True
                            cpath = "%s:%d-%d" % (os.path.join(src_root, d[0]), d[1], d[2])
                    n += 1
                    nm += matched
                    rows.append(dict(game=game, version=v["version"], name=name, size=size, va=va,
                                     level=nn or "", image=img or "", matched=int(matched), c=cpath,
                                     s=asm_path(files, name, va, nn) if files else ""))
            log("%s %s: %d functions, %d matched in C" % (game, v["version"], n, nm))
    return rows


def _work(row):
    import sister_twins as st
    b = None
    if row["image"] and os.path.exists(row["image"]):
        b = st.image(row["image"]).get(row["va"], row["size"])
    if not b:
        return None
    f = fingerprint(b, row["va"])
    f["sig"] = minhash(f["ops"])
    return f


SCHEMA = """
CREATE TABLE meta (k TEXT PRIMARY KEY, v BLOB);
CREATE TABLE fn (id INTEGER PRIMARY KEY, game TEXT, version TEXT, name TEXT, size INT, va INT,
  level TEXT, matched INT, c TEXT, s TEXT, n INT, frame INT, key TEXT,
  ops TEXT, cfg TEXT, calls TEXT, consts TEXT, offs TEXT);
CREATE INDEX fn_name ON fn(name);
CREATE INDEX fn_key ON fn(key);
"""


def build(groot, out=INDEX, jobs=None, only=None, log=print):
    t0 = time.time()
    manifest = load_manifest()
    rows = collect(manifest, groot, log, only)
    log("fingerprinting %d functions ..." % len(rows))
    if jobs == 1:
        fps = [_work(r) for r in rows]
    else:
        import multiprocessing as mp
        with mp.get_context("fork" if hasattr(os, "fork") else "spawn").Pool(jobs or os.cpu_count()) as p:
            fps = p.map(_work, rows, chunksize=64)
    # a later version keeps only what differs from an earlier version of the same game
    seen = {}
    keep = []
    dropped = nobytes = 0
    for r, f in zip(rows, fps):
        if f is None:
            nobytes += 1
            continue
        k = (r["game"], r["name"])
        if k in seen and seen[k][0] != r["version"]:
            if f["key"] == seen[k][1]:
                dropped += 1
                continue
        seen.setdefault(k, (r["version"], f["key"]))
        keep.append((r, f))
    write_index(out, keep, groot)
    log("wrote %s: %d functions (%d later-version copies left out, %d without bytes) in %.0f s"
        % (out, len(keep), dropped, nobytes, time.time() - t0))
    return len(keep)


def write_index(out, keep, groot=""):
    """Write [(row, fingerprint with "sig")] to the sqlite index out."""
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    tmp = out + ".tmp"
    if os.path.exists(tmp):
        os.remove(tmp)
    db = sqlite3.connect(tmp)
    db.executescript(SCHEMA)
    sigs = []
    for i, (r, f) in enumerate(keep):
        db.execute("INSERT INTO fn VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
                   (i, r["game"], r["version"], r["name"], r["size"], r["va"], r["level"], r["matched"],
                    r["c"], r["s"], f["n"], f["frame"], f["key"], " ".join(f["ops"]), " ".join(f["cfg"]),
                    " ".join(f["calls"]), " ".join(f["consts"]), " ".join(f["offs"])))
        sigs.append(f["sig"])
    blob = struct.pack("<%dI" % (len(sigs) * NHASH), *[x for s in sigs for x in s])
    db.execute("INSERT INTO meta VALUES ('sig', ?)", (blob,))
    db.execute("INSERT INTO meta VALUES ('format', ?)", (str(FORMAT),))
    db.execute("INSERT INTO meta VALUES ('built', ?)", (time.strftime("%Y-%m-%d %H:%M:%S"),))
    db.execute("INSERT INTO meta VALUES ('games_root', ?)", (groot,))
    db.commit()
    db.close()
    os.replace(tmp, out)


# ------------------------------------------------------------------ the index at query time
def _split(s):
    return s.split(" ") if s else []


class Index:
    def __init__(self, path=INDEX):
        if not os.path.isfile(path):
            raise SystemExit("no %s: run `python3 tools/xgame_index.py build` first" % path)
        self.db = sqlite3.connect(path)
        fmt = self.db.execute("SELECT v FROM meta WHERE k='format'").fetchone()
        if not fmt or int(fmt[0]) != FORMAT:
            raise SystemExit("%s is an older format: rebuild it (tools/xgame_index.py build)" % path)
        cols = self.db.execute("SELECT id, game, matched, n, key FROM fn ORDER BY id").fetchall()
        self.game = [c[1] for c in cols]
        self.matched_l = [c[2] for c in cols]
        self.n_l = [c[3] for c in cols]
        self.by_key = {}
        for c in cols:
            if c[4]:
                self.by_key.setdefault(c[4], []).append(c[0])
        blob = self.db.execute("SELECT v FROM meta WHERE k='sig'").fetchone()[0]
        if np is not None:
            self.sig = np.frombuffer(blob, dtype=np.uint32).reshape(-1, NHASH)
            self.n = np.array(self.n_l)
            self.matched = np.array(self.matched_l, dtype=bool)
            self.games = np.array(self.game)
        else:
            flat = struct.unpack("<%dI" % (len(blob) // 4), blob)
            self.sig = [flat[i:i + NHASH] for i in range(0, len(flat), NHASH)]
        self._rows = {}

    def row(self, i):
        if i not in self._rows:
            r = self.db.execute("SELECT * FROM fn WHERE id=?", (int(i),)).fetchone()
            d = dict(zip(["id", "game", "version", "name", "size", "va", "level", "matched", "c", "s", "n",
                          "frame", "key", "ops", "cfg", "calls", "consts", "offs"], r))
            for k in ("ops", "cfg", "calls", "consts", "offs"):
                d[k] = _split(d[k])
            self._rows[i] = d
        return self._rows[i]

    def find(self, name, game=None):
        """ids of the functions named name (game:name also works), rac3's first."""
        if ":" in name and not game:
            game, name = name.split(":", 1)
        q = "SELECT id, game FROM fn WHERE name=?" + (" AND game=?" if game else "")
        ids = self.db.execute(q, (name, game) if game else (name,)).fetchall()
        ids.sort(key=lambda r: (r[1] != "rac3", r[0]))
        return [r[0] for r in ids]

    def candidates(self, f, sig, limit=120, matched_only=False, exclude=None, games=None):
        """ids of the likeliest counterparts of f (its MinHash sig), best first."""
        n = f["n"]
        lo, hi = (n * 0.4, n * 2.5) if n >= 8 else (0, n * 4 + 8)
        if np is not None:
            q = np.array(sig, dtype=np.uint32)
            est = (self.sig == q[None, :]).sum(axis=1).astype(np.float32)
            ok = (self.n >= lo) & (self.n <= hi)
            if matched_only:
                ok &= self.matched
            if games is not None:
                ok &= np.isin(self.games, list(games))
            est[~ok] = -1
            k = min(limit, len(est))
            top = np.argpartition(-est, k - 1)[:k] if k else []
            ids = [int(i) for i in top if est[i] >= 0]
            ids.sort(key=lambda i: -est[i])
        else:
            sc = []
            for i, s in enumerate(self.sig):
                if not lo <= self.n_l[i] <= hi or (matched_only and not self.matched_l[i]):
                    continue
                if games is not None and self.game[i] not in games:
                    continue
                sc.append((sum(a == b for a, b in zip(s, sig)), i))
            sc.sort(key=lambda x: (-x[0], x[1]))
            ids = [i for _, i in sc[:limit]]
        for i in self.by_key.get(f["key"], []) if f["key"] else []:
            if (not matched_only or self.matched_l[i]) and (games is None or self.game[i] in games) \
                    and i not in ids:
                ids.insert(0, i)
        if exclude is not None:
            ids = [i for i in ids if i != exclude]
        return ids

    def rank(self, f, sig, n=10, matched_only=False, exclude=None, games=None, limit=120):
        pre = []
        for i in self.candidates(f, sig, limit, matched_only, exclude, games):
            g = self.row(i)
            if SequenceMatcher(None, f["ops"], g["ops"], autojunk=False).real_quick_ratio() < 0.3:
                continue
            pre.append((similarity(f, g, quick=True)[0], i, g))
        # the exact opcode alignment is quadratic: only for the best of the order-blind scores
        pre.sort(key=lambda x: (-x[0], x[1]))
        keep = FULL_RATIO[-1][1]
        for most, k in FULL_RATIO:
            if f["n"] <= most:
                keep = k
                break
        out = []
        for _, i, g in pre[:keep]:
            total, parts = similarity(f, g)
            out.append((total, parts, g))
        out.sort(key=lambda x: (-x[0], x[2]["id"]))
        # one row per C definition: a later version's copy of the same source adds nothing
        seen, uniq = set(), []
        for x in out:
            k = (x[2]["game"], x[2]["c"] or x[2]["name"])
            if k in seen:
                continue
            seen.add(k)
            uniq.append(x)
        return uniq[:max(n, 1) * 3]


# ------------------------------------------------------------------ .s files
ASM_3 = re.compile(r"/\*\s+[0-9A-F]+\s+([0-9A-F]{8})\s+([0-9A-F]{8})\s+\*/")
ASM_2 = re.compile(r"/\*\s+([0-9A-F]{6,8})\s+([0-9A-F]{8})\s+\*/")
ASM_WORD = re.compile(r"^\s*\.word\s+0x([0-9A-Fa-f]{8})\b")


def read_asm(path):
    """-> (bytes, address) of the first function of a splat .s file: rac1/rac3 lines carry
    `/* rom vaddr BYTES */` (the bytes as stored), rac4 lines `/* vaddr WORD */`; `.word 0x...`
    lines are words."""
    words, va = [], None
    started = False
    with open(path, encoding="utf-8", errors="replace") as f:
        for ln in f:
            s = ln.strip()
            if started and s.startswith(("glabel", "endlabel", ".size")):
                break
            m = ASM_WORD.match(ln)
            if m:
                words.append(int(m.group(1), 16))
                started = True
                continue
            m = ASM_3.search(ln)
            if m:
                va = int(m.group(1), 16) if va is None else va
                words.append(int.from_bytes(bytes.fromhex(m.group(2)), "little"))
                started = True
                continue
            m = ASM_2.search(ln)
            if m:
                va = int(m.group(1), 16) if va is None else va
                words.append(int(m.group(2), 16))
                started = True
    return struct.pack("<%dI" % len(words), *words), va or 0


# ------------------------------------------------------------------ commands
def fmt_parts(parts):
    return " ".join("%s=%s" % (k, "-" if parts[k] is None else "%.2f" % parts[k]) for k in KINDS)


def resolve(ix, target, game=None):
    """-> (fingerprint, signature, id or None, label) of a name or a .s path."""
    if target.endswith(".s") and os.path.isfile(target):
        b, va = read_asm(target)
        f = fingerprint(b, va)
        sid = ix.db.execute("SELECT id FROM fn WHERE s=?", (os.path.abspath(target),)).fetchone()
        return f, minhash(f["ops"]), sid[0] if sid else None, target
    ids = ix.find(target, game)
    if not ids:
        raise SystemExit("%s: not in the index (a name, game:name, or a .s path)" % target)
    r = ix.row(ids[0])
    sig = ix.sig[ids[0]]
    return r, list(sig), ids[0], "%s %s %s" % (r["game"], r["version"], r["name"])


def cmd_query(a):
    t0 = time.time()
    ix = Index(a.index)
    f, sig, own, label = resolve(ix, a.target, a.game)
    res = ix.rank(f, sig, a.n, exclude=own, limit=a.candidates)
    m = [x for x in res if x[2]["matched"]][:a.n]
    u = [x for x in res if not x[2]["matched"]][:max(1, a.n // 2)]
    print("%s: %d instructions, frame %d, %d calls" % (label, f["n"], f["frame"], len(f["calls"])))
    for title, xs in (("matched counterparts", m), ("unmatched counterparts", u)):
        print("%s:" % title)
        for total, parts, g in xs:
            print("  %.3f %-4s %-4s %-26s %5dB  %s%s" % (
                total, g["game"], g["version"], g["name"], g["size"], fmt_parts(parts),
                "  identical" if f["key"] and f["key"] == g["key"] else ""))
            print("        %s" % (g["c"] or g["s"] or "-"))
        if not xs:
            print("  (none)")
    print("(%.2f s)" % (time.time() - t0))
    return 0


_SW = None


def _sweep_init(path):
    global _SW
    _SW = Index(path)


def _sweep_one(i):
    ix = _SW
    f = ix.row(i)
    sig = list(ix.sig[i])
    best = ix.rank(f, sig, 1, matched_only=True, exclude=i)
    other = [x for x in best if x[2]["game"] != f["game"]]
    if not other:
        others = sorted(set(ix.game) - {f["game"]})
        other = ix.rank(f, sig, 1, matched_only=True, exclude=i, games=others)
    pick = lambda xs: (xs[0][0], xs[0][2]["game"], xs[0][2]["name"], xs[0][2]["c"],
                       fmt_parts(xs[0][1])) if xs else None
    return i, pick(best), pick(other)


def cmd_sweep(a):
    t0 = time.time()
    ix = Index(a.index)
    tg = [r[0] for r in ix.db.execute(
        "SELECT id FROM fn WHERE game='rac3' AND version='pal' AND matched=0 AND size>=? ORDER BY size DESC, name",
        (a.min_size,))]
    print("sweeping %d unmatched rac3 PAL functions of %d bytes and more ..." % (len(tg), a.min_size))
    if a.jobs == 1:
        _sweep_init(a.index)
        res = [_sweep_one(i) for i in tg]
    else:
        import multiprocessing as mp
        with mp.get_context("fork" if hasattr(os, "fork") else "spawn").Pool(
                a.jobs or os.cpu_count(), _sweep_init, (a.index,)) as p:
            res = p.map(_sweep_one, tg, chunksize=8)
    cols = ["function", "size", "level", "s", "best_score", "best_game", "best_function", "best_c",
            "best_kinds", "xgame_score", "xgame_game", "xgame_function", "xgame_c", "xgame_kinds"]
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w", encoding="utf-8", newline="\n") as fo:
        fo.write("\t".join(cols) + "\n")
        for i, best, other in res:
            r = ix.row(i)
            row = [r["name"], str(r["size"]), r["level"] or "-", r["s"] or "-"]
            for x in (best, other):
                row += ["%.3f" % x[0], x[1], x[2], x[3] or "-", x[4]] if x else ["0", "-", "-", "-", "-"]
            fo.write("\t".join(row) + "\n")
    print("wrote %s (%.0f s)" % (a.out, time.time() - t0))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--index", default=INDEX, help="the index file (default build/xgame_index.sqlite)")
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("build", help="read every game and write the index")
    b.add_argument("--games", help="the OpenRAC games folder (default: $OPENRAC_GAMES, the folder this "
                                   "checkout sits in, else ~/Projects/RAC/OpenRAC/games)")
    b.add_argument("--only", action="append", help="only this game (repeatable)")
    b.add_argument("-j", "--jobs", type=int, default=None)
    q = sub.add_parser("query", help="the best counterparts of one function")
    q.add_argument("target", help="a name (func_..., game:func_...) or a .s file")
    q.add_argument("-n", type=int, default=10)
    q.add_argument("--game", help="the game of a name present in several")
    q.add_argument("--candidates", type=int, default=120, help="MinHash candidates to score (default 120)")
    s = sub.add_parser("sweep", help="best matched counterpart of every unmatched rac3 PAL function")
    s.add_argument("--out", default=SWEEP)
    s.add_argument("--min-size", type=int, default=16)
    s.add_argument("-j", "--jobs", type=int, default=None)
    a = ap.parse_args(argv)
    if a.cmd == "build":
        build(games_root(a.games), a.index, a.jobs, set(a.only) if a.only else None)
        return 0
    if a.cmd == "query":
        return cmd_query(a)
    return cmd_sweep(a)


if __name__ == "__main__":
    sys.exit(main())
