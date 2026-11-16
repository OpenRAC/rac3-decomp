#!/usr/bin/env python3
"""sister_twins.py: rac3 functions still in assembly whose code is a function already matched in C
in a sister decompilation (docs/contributing/sister-twins.md).

The sisters are OpenRAC's other decompilations of the same engine family, built with the same Sony
SDK: rac1-decomp, rac2-decomp, rac4-decomp, rac-sac-decomp and rac5-sm-decomp. A rac3 function and
a sister function are twins when their relocation-masked words (tools/twin_mask.py) are equal
(`exact`) or, for functions of 20 words and more, at least 95 % equal (`near`). The sister's C is
then a starting point for rac3's: it still has to be checked with tools/check.py in rac3's file.

  python3 tools/sister_twins.py --sister rac1=../rac1-decomp --sister rac2=../rac2-decomp \\
      --sister rac4=../rac4-decomp --sister sac=../rac-sac-decomp --sister rac5=../rac5-sm-decomp
  python3 tools/sister_twins.py ... --baserom ../rac3-decomp/baserom --out twins.tsv
  python3 tools/sister_twins.py --check-mask [--asm DIR]     # the mask against splat's relocations

rac3's side comes from this working tree: the functions under 100 % in progress/report.json (PAL)
and progress/us/report.json (NTSC-U), 16 bytes and more; config/us/map.tsv for an NTSC-U function's
PAL twin; the asm markers and definitions in src/ for the file that owns each function. Its bytes
come from --baserom (default $UYA_BASEROM, else baserom/): frontbin.elf, boot_elf.elf, i5bootn.elf,
levels/NN_*.elf and the same under us/.

Each sister is read from its working tree as it is (this tool never fetches or changes it: update
the clones yourself first), with its own dumps in its baserom/ (or --sister-baserom NAME=DIR). A
sister, or one of its versions, whose dumps are missing is skipped and the summary says so. What
counts as a sister's matched C (SISTER_RULES):

- rac1 (PAL v2, SCES-509.16), rac2 (NTSC-U, SCUS-972.68), rac4 (NTSC-U, SCUS-974.65; and PAL's own
  C under src/pal/ on SCES-532.85): a function of the version's progress report with an active
  top-level C definition in src/ (under its address name or a readable name of config/names.tsv or
  config/names_local.tsv; outside the other versions' own directories), and named by no asm marker
  (INCLUDE_ASM, ASM_FUNC, LINKER_REMNANT, GLOBAL_ASM) anywhere in that tree;
- sac (NTSC-U, SCUS-976.23) and rac5 (NTSC-U, SCUS-976.15): the placements of config/levels/
  bodies.tsv (sac also config/boot/bodies.tsv), a compiled C body equal to retail at that place,
  the first placement of each source; rac5's boot functions at 100 % in its report, placed by
  config/boot/symbols.tsv.

Writes one TSV row per (rac3 function, sister repo) with a twin: the best sister function there
(exact before near, then the most masked words equal, then the most raw words equal), and prints a
summary.
"""
import argparse
import collections
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from twin_mask import check_mask, key_of, masked, strip_padding, words_of  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MIN_SIZE = 16           # bytes; shorter functions twin with everything
NEAR_MIN_WORDS = 20     # under 20 words, 95 % means every word
TWIN_STATUSES = ("match", "nomatch", "asm", "near")     # config/us/map.tsv: same code on both discs


# ------------------------------------------------------------------ program images
class Image:
    """Bytes of a program by virtual address: an ELF's PT_LOAD segments, an overlay directory
    (manifest.json and <section>.bin, the PT_LOAD-type records), or a raw file by file offset
    (a .REL module)."""

    def __init__(self, path, kind="auto"):
        self.path = path
        self.segs = []          # (vaddr, bytes)
        if kind == "manifest":
            with open(os.path.join(path, "manifest.json"), encoding="utf-8") as f:
                man = json.load(f)
            for r in man.get("records") or man.get("sections") or []:
                fn = os.path.join(path, r["name"] + ".bin")
                if r.get("type") == 1 and os.path.exists(fn):
                    with open(fn, "rb") as f:
                        self.segs.append((r["address"], f.read()))
            return
        with open(path, "rb") as f:
            d = f.read()
        if kind == "raw" or d[:4] != b"\x7fELF":
            self.segs.append((0, d))
            return
        phoff = struct.unpack_from("<I", d, 0x1C)[0]
        phentsize, phnum = struct.unpack_from("<HH", d, 0x2A)
        for i in range(phnum):
            p_type, p_off, p_vaddr, _, p_filesz = struct.unpack_from("<IIIII", d, phoff + i * phentsize)
            if p_type == 1 and p_filesz:
                self.segs.append((p_vaddr, d[p_off:p_off + p_filesz]))

    def get(self, vaddr, size):
        for base, data in self.segs:
            if base <= vaddr and vaddr + size <= base + len(data):
                return data[vaddr - base:vaddr - base + size]
        return None


_images = {}


def image(path):
    """The Image of path (cached): a directory is an overlay manifest, a .REL a raw module."""
    if path not in _images:
        if os.path.isdir(path):
            _images[path] = Image(path, "manifest")
        elif path.upper().endswith(".REL"):
            _images[path] = Image(path, "raw")
        else:
            _images[path] = Image(path)
    return _images[path]


# ------------------------------------------------------------------ C scanning
ASM_MARK = re.compile(r"\b(INCLUDE_ASM|INCLUDE_ASM_[A-Z_]+|ASM_FUNC|LINKER_REMNANT|GLOBAL_ASM|INCLUDE_ASM_FUNC)\b")
DEF_TAIL = re.compile(r"([A-Za-z_$][A-Za-z0-9_$]*)\s*\(([^;{}]*)\)\s*(?:__attribute__\s*\(\(.*?\)\)\s*)*$", re.S)


def blank_comments(src):
    """Replace comments and string/char literals by spaces, keeping newlines."""
    out = []
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if c == "/" and i + 1 < n and src[i + 1] == "*":
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", src[i:j]))
            i = j
            continue
        if c == "/" and i + 1 < n and src[i + 1] == "/":
            j = src.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
            continue
        if c in "\"'":
            j = i + 1
            while j < n and src[j] != c:
                if src[j] == "\\":
                    j += 1
                if j < n and src[j] == "\n":
                    break
                j += 1
            j = min(j + 1, n)
            out.append(c + re.sub(r"[^\n]", " ", src[i + 1:j - 1]) + (c if j - 1 > i else ""))
            i = j
            continue
        out.append(c)
        i += 1
    return "".join(out)


def scan_c(raw):
    """-> (defs, asm_names) of C source text: defs = [(name, first_line, last_line, active)] of its
    top-level function definitions; asm_names = the names its asm markers name. Code inside
    `#if 0` / `#ifdef NON_MATCHING` (and the #else of `#ifndef NON_MATCHING`) is inactive."""
    asm_names = set()
    for ln in raw.splitlines():
        if ASM_MARK.search(ln):
            for m in re.finditer(r"\b(func_[A-Za-z0-9_]+|[A-Za-z_][A-Za-z0-9_$]*__F[A-Za-z0-9_]*)\b", ln):
                asm_names.add(m.group(1))
            m = re.search(r",\s*([A-Za-z_$][A-Za-z0-9_$]*)\s*\)", ln)
            if m:
                asm_names.add(m.group(1))
    lines = blank_comments(raw).split("\n")
    stack = []            # each: [inactive_now, kind]
    inactive = []
    for ln in lines:
        s = ln.strip()
        if s.startswith("#"):
            d = s[1:].strip()
            if d.startswith("if"):
                if (re.match(r"if\s+0\b", d) or re.match(r"ifdef\s+NON_MATCHING\b", d)
                        or re.match(r"if\s+(defined\s*\(?\s*)?NON_MATCHING\b", d)):
                    stack.append([True, "nm"])
                elif re.match(r"ifndef\s+NON_MATCHING\b", d) or re.match(r"if\s+!\s*defined\s*\(?\s*NON_MATCHING", d):
                    stack.append([False, "nnm"])
                else:
                    stack.append([False, "other"])
            elif d.startswith("else") or d.startswith("elif"):
                if stack:
                    top = stack[-1]
                    if top[1] == "nm":
                        top[0] = False
                    elif top[1] == "nnm":
                        top[0] = True
            elif d.startswith("endif"):
                if stack:
                    stack.pop()
            inactive.append(True)     # the directive line itself
            continue
        inactive.append(any(t[0] for t in stack))
    defs = []
    depth = 0
    header_start = None
    header = []
    cur = None            # (name, first_line, active) while inside a function body
    for li, ln in enumerate(lines):
        if ln.lstrip().startswith("#"):
            if depth == 0:
                header = []
                header_start = None
            continue
        for ch in ln:
            if depth == 0:
                if ch == "{":
                    text = "".join(header).strip()
                    m = DEF_TAIL.search(text)
                    if m and "=" not in text.split("(")[0] and not re.match(r"^(struct|union|enum|typedef)\b", text):
                        name = m.group(1)
                        if name not in ("if", "while", "for", "switch", "sizeof", "__attribute__"):
                            cur = (name, header_start if header_start is not None else li, not inactive[li])
                    depth = 1
                    header = []
                    header_start = None
                    continue
                if ch == ";" or ch == "}":
                    header = []
                    header_start = None
                    continue
                if not ch.isspace() and header_start is None:
                    header_start = li
                header.append(ch)
            else:
                if ch == "{":
                    depth += 1
                elif ch == "}":
                    depth -= 1
                    if depth == 0:
                        if cur:
                            defs.append((cur[0], cur[1] + 1, li + 1, cur[2]))
                        cur = None
        if depth == 0:
            header.append("\n")
    return defs, asm_names


def read_text(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def scan_files(repo, exclude_dirs=()):
    """Yields (path relative to repo, defs, asm_names) for every .c/.cpp/.cc file under repo/src,
    leaving out the directories exclude_dirs (relative to src/)."""
    top = os.path.join(repo, "src")
    for dp, dn, fn in os.walk(top):
        dn.sort()
        rel = os.path.relpath(dp, top).replace("\\", "/")
        if any(rel == e or rel.startswith(e + "/") for e in exclude_dirs):
            dn[:] = []
            continue
        for f in sorted(fn):
            if f.endswith((".c", ".cpp", ".cc")):
                p = os.path.join(dp, f)
                defs, asm = scan_c(read_text(p))
                yield os.path.relpath(p, repo).replace("\\", "/"), defs, asm


def scan_tree(repo, exclude_dirs=()):
    """-> (defs, asm): defs = name -> [(path, first, last, active)]; asm = every marker's name."""
    defs, asm = {}, set()
    for rel, ds, an in scan_files(repo, exclude_dirs):
        asm |= an
        for name, a, b, act in ds:
            defs.setdefault(name, []).append((rel, a, b, act))
    return defs, asm


_located = {}


def locate(repo, src, name):
    """-> (C name, first line, last line) of the definition of name in repo/src: the one named name,
    else the one named after the file, else the longest active one; (name, 0, 0) if none."""
    key = (repo, src)
    if key not in _located:
        p = os.path.join(repo, src)
        _located[key] = scan_c(read_text(p))[0] if os.path.isfile(p) else []
    ds = _located[key]
    stem = os.path.splitext(os.path.basename(src))[0]
    for want in (name, stem):
        for d in ds:
            if d[0] == want and d[3]:
                return d[0], d[1], d[2]
    ds = [d for d in ds if d[3]] or ds
    if ds:
        d = max(ds, key=lambda d: d[2] - d[1])
        return d[0], d[1], d[2]
    return name, 0, 0


# ------------------------------------------------------------------ the sisters
class SisterFunction:
    __slots__ = ("repo", "root", "version", "name", "size", "image", "addr", "src", "loc", "raw", "m")

    def __init__(self, repo, root, version, name, size, image_path, addr, src, loc=None):
        self.repo, self.root, self.version, self.name = repo, root, version, name
        self.size, self.image, self.addr, self.src = size, image_path, addr, src
        self.loc = loc          # (C name, first, last), or None until a twin needs it
        self.raw = self.m = None

    def where(self):
        if self.loc is None:
            self.loc = locate(self.root, self.src, self.name)
        return self.loc


class Part:
    """One version of one sister: its matched-C functions, or why it was skipped."""

    def __init__(self, repo, version, functions=None, skipped=None, note=""):
        self.repo, self.version, self.functions, self.skipped, self.note = repo, version, functions, skipped, note


def level_map(top, pattern):
    """-> level number -> path, for the entries of top whose name matches pattern (group 1: NN)."""
    out = {}
    if os.path.isdir(top):
        for f in sorted(os.listdir(top)):
            m = re.match(pattern, f)
            if m:
                out.setdefault("%02d" % int(m.group(1)), os.path.join(top, f))
    return out


def readable_names(repo):
    """address name -> readable names (config/names.tsv, config/names_local.tsv: name in column 2)."""
    out = {}
    for t in ("config/names.tsv", "config/names_local.tsv"):
        p = os.path.join(repo, t)
        if not os.path.exists(p):
            continue
        for ln in read_text(p).splitlines():
            if ln.startswith("#"):
                continue
            f = ln.split("\t")
            if len(f) >= 2 and f[0].startswith("func_") and f[1] and f[1] not in out.setdefault(f[0], []):
                out[f[0]].append(f[1])
    return out


def pick_def(defs, names, where=None):
    """First active definition under any of names; inside the report unit's source path when given."""
    for scoped in ((True, False) if where else (False,)):
        for name in names:
            for d in defs.get(name, []):
                if d[3] and (not scoped or d[0].startswith(where)):
                    return d
    return None


_trees = {}


def report_part(repo, root, version, report, exclude, core, levels, frontbin=None, only_src=None):
    """The functions of a progress report that are C in src/ and named by no asm marker."""
    if not os.path.isfile(core):
        return Part(repo, version, skipped="no %s" % core)
    rp = os.path.join(root, report)
    if not os.path.isfile(rp):
        return Part(repo, version, skipped="no %s" % rp)
    if (root, exclude) not in _trees:
        _trees[(root, exclude)] = scan_tree(root, exclude)
    defs, asm = _trees[(root, exclude)]
    with open(rp, encoding="utf-8") as f:
        rep = json.load(f)
    rn = readable_names(root)
    out, total = [], 0
    for u in rep["units"]:
        lvl_unit = re.match(r"Level (\d+)", u["name"])
        for fn in u.get("functions", []):
            total += 1
            name = fn["name"]
            names = [name] + rn.get(name, [])
            if any(n in asm for n in names):
                continue
            d = pick_def(defs, names, u.get("metadata", {}).get("source_path"))
            if not d or (only_src and not d[0].startswith(only_src)):
                continue
            m = re.match(r"func_L(\d\d)_", name)
            if m:
                img = levels.get(m.group(1))
            elif frontbin and name.startswith("func_FB_"):
                img = frontbin
            elif lvl_unit and not re.match(r"func_[0-9A-F]{8}$", name):
                img = levels.get("%02d" % int(lvl_unit.group(1)))
            else:
                img = core
            cname = next(n for n in names if d in defs.get(n, []))
            out.append(SisterFunction(repo, root, version, name, int(fn["size"]), img,
                                      int(fn["metadata"]["virtual_address"]), d[0], (cname, d[1], d[2])))
    return Part(repo, version, out, note="%s: %d functions" % (report, total))


def bodies_part(repo, root, version, table, image_of):
    """The sources of a bodies table (module, offset, size, source): a compiled C body equal to
    retail at that placement; the first placement of each source."""
    tp = os.path.join(root, table)
    if not os.path.isfile(tp):
        return Part(repo, version, skipped="no %s" % tp)
    out, seen, placements = [], set(), 0
    for ln in read_text(tp).splitlines():
        if not ln or ln.startswith("#") or ln.startswith("module\t"):
            continue
        f = ln.split("\t")
        placements += 1
        src = f[3]
        if src in seen:
            continue
        seen.add(src)
        out.append(SisterFunction(repo, root, version, os.path.splitext(os.path.basename(src))[0], int(f[2]),
                                  image_of(f[0]), int(f[1], 16), src))
    return Part(repo, version, out, note="%s: %d placements" % (table, placements))


def rac5_boot_part(repo, root, baserom):
    core = os.path.join(baserom, "SCUS_976.15")
    for p in (core, os.path.join(root, "config/boot/symbols.tsv"), os.path.join(root, "progress/report.json")):
        if not os.path.isfile(p):
            return Part(repo, "us", skipped="no %s" % p)
    sym = {}
    for ln in read_text(os.path.join(root, "config/boot/symbols.tsv")).splitlines():
        f = ln.split("\t")
        if ln.startswith("#") or ln.startswith("symbol\t") or len(f) < 4:
            continue
        if f[3] == ".text":
            sym.setdefault(f[0], int(f[1], 16))
    with open(os.path.join(root, "progress/report.json"), encoding="utf-8") as f:
        rep = json.load(f)
    out = []
    for u in rep["units"]:
        if not u["name"].startswith("boot/"):
            continue
        src = u.get("metadata", {}).get("source_path")
        for fn in u.get("functions", []):
            if fn.get("fuzzy_match_percent", 0) >= 100 and fn["name"] in sym and src:
                out.append(SisterFunction(repo, root, "us", fn["name"], int(fn["size"]), core, sym[fn["name"]], src))
    return Part(repo, "us", out, note="progress/report.json: boot units at 100 %")


def rac1_parts(root, base):
    yield report_part("rac1-decomp", root, "pal", "progress/report.json", ("versions",),
                      os.path.join(base, "SCES_509.16"),
                      level_map(os.path.join(base, "overlays"), r"level_(\d\d)$"))


def rac2_parts(root, base):
    yield report_part("rac2-decomp", root, "us", "progress/report.json", ("jp", "kr", "pal", "us2"),
                      os.path.join(base, "SCUS_972.68"), level_map(os.path.join(base, "levels"), r"(\d\d)_"))


def rac4_parts(root, base):
    for version, report, exclude, only in (("us", "progress/report.json", ("pal",), None),
                                           ("pal", "progress/pal/report.json", (), "src/pal/")):
        d = os.path.join(base, version)
        yield report_part("rac4-decomp", root, version, report, exclude, os.path.join(d, "main.elf"),
                          level_map(os.path.join(d, "levels"), r"(\d\d)_.*\.elf$"),
                          frontbin=os.path.join(d, "frontbin.elf"), only_src=only)


def sac_parts(root, base):
    if not os.path.isdir(base):
        yield Part("rac-sac-decomp", "us", skipped="no %s" % base)
        return
    yield bodies_part("rac-sac-decomp", root, "us", "config/boot/bodies.tsv", lambda m: os.path.join(base, m))
    yield bodies_part("rac-sac-decomp", root, "us", "config/levels/bodies.tsv",
                      lambda m: os.path.join(base, "BIN", m))


def rac5_parts(root, base):
    if not os.path.isdir(base):
        yield Part("rac5-sm-decomp", "us", skipped="no %s" % base)
        return
    yield bodies_part("rac5-sm-decomp", root, "us", "config/levels/bodies.tsv",
                      lambda m: os.path.join(base, "LVL", m))
    yield rac5_boot_part("rac5-sm-decomp", root, base)


# short name -> (repository, its parts); --sister also takes the repository's name
SISTER_RULES = {
    "rac1": ("rac1-decomp", rac1_parts),
    "rac2": ("rac2-decomp", rac2_parts),
    "rac4": ("rac4-decomp", rac4_parts),
    "sac": ("rac-sac-decomp", sac_parts),
    "rac5": ("rac5-sm-decomp", rac5_parts),
}
ORDER = ["rac4-decomp", "rac2-decomp", "rac1-decomp", "rac-sac-decomp", "rac5-sm-decomp"]


def sister_key(name):
    for k, (repo, _) in SISTER_RULES.items():
        if name in (k, repo):
            return k
    raise SystemExit("unknown sister %r (one of: %s)" % (name, ", ".join(
        "%s (%s)" % (k, r) for k, (r, _) in SISTER_RULES.items())))


def load_bytes(fns):
    """Reads each function's bytes and masked words; -> (functions with bytes, count without)."""
    out, missing = [], 0
    for s in fns:
        b = None
        if s.image and os.path.exists(s.image):
            b = image(s.image).get(s.addr, s.size)
        if b is None:
            missing += 1
            continue
        s.raw = words_of(b)
        s.m = strip_padding(masked(b))
        out.append(s)
    return out, missing


# ------------------------------------------------------------------ rac3
class Rac3Function:
    __slots__ = ("version", "name", "program", "size", "file", "pal", "raw", "m")

    def __init__(self, version, name, program, size, file, pal, raw, m):
        self.version, self.name, self.program, self.size = version, name, program, size
        self.file, self.pal, self.raw, self.m = file, pal, raw, m


def rac3_owners():
    """-> (marker, define, us_define): name -> the file of src/ (outside src/us/) whose asm marker
    names it, or whose active C defines it; and name -> the file of src/us/ that defines it (NTSC-U
    addresses: kept apart, since a PAL function can have the same address name)."""
    marker, define, us_define = {}, {}, {}
    for rel, defs, asm in scan_files(ROOT):
        us = rel.startswith("src/us/")
        for n in asm:
            if not us:
                marker.setdefault(n, rel)
        for d in defs:
            if d[3]:
                (us_define if us else define).setdefault(d[0], rel)
    return marker, define, us_define


def us_twins():
    """(program, NTSC-U name) -> PAL twin's name (config/us/map.tsv; twins only, not `differs`)."""
    out = {}
    for ln in read_text(os.path.join(ROOT, "config/us/map.tsv")).splitlines():
        f = ln.split("\t")
        if ln.startswith("#") or len(f) < 7 or f[2] == "-":
            continue
        if f[6] in TWIN_STATUSES:
            out[(f[1], f[2])] = f[0]
    return out


def rac3_functions(baserom, include_matched=False, log=print):
    marker, define, us_define = rac3_owners()
    twins = us_twins()
    out = []
    for version, report, base in (("pal", "progress/report.json", baserom),
                                  ("us", "progress/us/report.json", os.path.join(baserom, "us"))):
        progs = {p: os.path.join(base, p + ".elf") for p in ("frontbin", "boot_elf", "i5bootn")}
        if not all(os.path.isfile(p) for p in progs.values()):
            log("rac3 %s: skipped, no %s" % (version, " / ".join(p for p in progs.values() if not os.path.isfile(p))))
            continue
        levels = level_map(os.path.join(base, "levels"), r"(\d\d)_.*\.elf$")
        with open(os.path.join(ROOT, report), encoding="utf-8") as f:
            rep = json.load(f)
        n = nobytes = 0
        for u in rep["units"]:
            lvl_unit = re.match(r"Level (\d+)", u["name"])
            for fn in u.get("functions", []):
                size = int(fn["size"])
                if size < MIN_SIZE or (fn.get("fuzzy_match_percent", 0) >= 100 and not include_matched):
                    continue
                name = fn["name"]
                va = int(fn["metadata"]["virtual_address"])
                m = re.match(r"func_L(\d\d)_", name)
                nn = m.group(1) if m else ("%02d" % int(lvl_unit.group(1)) if lvl_unit else None)
                if nn or u["name"] == "Shared level code":
                    program, img, map_prog = "level_%s" % nn, levels.get(nn), "levels"
                else:
                    map_prog = u["name"].split("/")[0]
                    program, img = map_prog, progs.get(map_prog)
                pal = twins.get((map_prog, name), "") if version == "us" else ""
                if version == "pal":
                    owner = marker.get(name) or define.get(name)
                elif pal:
                    owner = marker.get(pal) or define.get(pal)
                else:           # no twin: NTSC-U's own C, src/us/ (func_U_XXXXXXXX in the core)
                    owner = us_define.get(re.sub(r"^func_(?=[0-9A-F]{8}$)", "func_U_", name)) or us_define.get(name)
                b = image(img).get(va, size) if img and os.path.exists(img) else None
                if b is None:
                    nobytes += 1
                    continue
                n += 1
                out.append(Rac3Function(version, name, program, size, owner or "-", pal or "-",
                                        words_of(b), strip_padding(masked(b))))
        log("rac3 %s: %d functions %sof 16 bytes and more%s" % (
            version, n, "" if include_matched else "under 100 % ",
            ", %d without bytes in %s" % (nobytes, base) if nobytes else ""))
    return out


# ------------------------------------------------------------------ twins
def raw_equal(a, b):
    return sum(x == y for x, y in zip(a, b))


def near_equal(a, b, need):
    """-> how many words of a and b (same length) are equal, or None if fewer than need."""
    miss = len(a) - need
    for x, y in zip(a, b):
        if x != y:
            miss -= 1
            if miss < 0:
                return None
    return need + miss


def find_twins(rac3, sisters, near_pct=95.0):
    """-> rows: one per (rac3 function, sister repo) with a twin there, as dicts."""
    exact_idx = collections.defaultdict(list)
    by_len = collections.defaultdict(lambda: collections.defaultdict(list))
    for s in sisters:
        exact_idx[key_of(s.m)].append(s)
        by_len[s.repo][len(s.m)].append(s)
    near_cache = {}
    rows = []
    for r in rac3:
        n = len(r.m)
        key = key_of(r.m)
        best = {}
        for s in exact_idx.get(key, []):
            best.setdefault(s.repo, []).append(("exact", n, s))
        if n >= NEAR_MIN_WORDS:
            if key not in near_cache:
                need = -(-round(near_pct * 100) * n // 10000)     # ceil(near_pct % of n)
                found = []
                for repo, sizes in by_len.items():
                    if repo in best:
                        continue
                    for s in sizes.get(n, []):
                        eq = near_equal(r.m, s.m, need)
                        if eq is not None:
                            found.append((eq, s))
                near_cache[key] = found
            for eq, s in near_cache[key]:       # repos without an exact twin of this code
                best.setdefault(s.repo, []).append(("near", eq, s))
        for repo, cands in best.items():
            cands = [(t, eq, raw_equal(r.raw, s.raw), s) for t, eq, s in cands]
            cands.sort(key=lambda c: (c[0] != "exact", -c[1], -c[2], c[3].name))
            tier, eq, req, s = cands[0]
            cname, first, last = s.where()
            rows.append(dict(
                rac3_version=r.version, rac3_function=r.name, rac3_program=r.program, rac3_size=r.size,
                rac3_file=r.file, pal_twin=r.pal, sister_repo=repo, sister_version=s.version,
                sister_function=s.name, sister_c_name=cname, sister_source="%s:%d-%d" % (s.src, first, last),
                tier=tier, words=n, masked_equal_pct="%.1f" % (100.0 * eq / n),
                raw_equal_pct="%.1f" % (100.0 * req / n),
                other_candidates=sum(1 for c in cands if c[0] == tier) - 1))
    rows.sort(key=lambda x: (x["rac3_version"], x["tier"] != "exact", -x["rac3_size"], x["rac3_function"],
                             ORDER.index(x["sister_repo"])))
    return rows


COLUMNS = ["rac3_version", "rac3_function", "rac3_program", "rac3_size", "rac3_file", "pal_twin",
           "sister_repo", "sister_version", "sister_function", "sister_c_name", "sister_source",
           "tier", "words", "masked_equal_pct", "raw_equal_pct", "other_candidates"]


def write_tsv(path, rows):
    d = os.path.dirname(os.path.abspath(path))
    os.makedirs(d, exist_ok=True)
    with open(path, "w", newline="\n", encoding="utf-8") as f:
        f.write("\t".join(COLUMNS) + "\n")
        for x in rows:
            f.write("\t".join(str(x[c]) for c in COLUMNS) + "\n")


def summary(rows):
    """-> the summary lines: rac3 functions per version and best tier, per sister repo, and the
    distinct work items (an NTSC-U function folded into its PAL twin when both are listed)."""
    best = {}
    size = {}
    for x in rows:
        k = (x["rac3_version"], x["rac3_function"])
        if best.get(k) != "exact":
            best[k] = x["tier"]
        size[k] = (x["rac3_size"], x["pal_twin"])
    out = ["twins: %d rows, %d rac3 functions" % (len(rows), len(best))]
    c = collections.Counter()
    b = collections.Counter()
    for k, t in best.items():
        c[(k[0], t)] += 1
        b[(k[0], t)] += size[k][0]
    out.append("  %-4s %-6s %9s %9s" % ("", "", "functions", "bytes"))
    for k in sorted(c):
        out.append("  %-4s %-6s %9d %9d" % (k + (c[k], b[k])))
    out.append("by sister (rac3 functions with a twin there, by its tier):")
    c = collections.Counter((x["sister_repo"], x["rac3_version"], x["tier"]) for x in rows)
    for k in sorted(c, key=lambda k: (ORDER.index(k[0]), k[1], k[2])):
        out.append("  %-15s %-4s %-6s %5d" % (k + (c[k],)))
    items = {}
    for k, t in best.items():
        pal = size[k][1]
        ident = ("pal", pal) if k[0] == "us" and pal != "-" and ("pal", pal) in best else k
        if items.get(ident) != "exact":
            items[ident] = t
    c = collections.Counter(items.values())
    out.append("work items (an NTSC-U function folded into its PAL twin when both have a twin): "
               "%d exact, %d near" % (c["exact"], c["near"]))
    return out


# ------------------------------------------------------------------ main
def parse_pairs(values, what):
    out = {}
    for v in values or []:
        name, sep, path = v.partition("=")
        if not sep or not path:
            raise SystemExit("--%s takes NAME=PATH, not %r" % (what, v))
        out[sister_key(name)] = os.path.abspath(path)
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sister", action="append", metavar="NAME=PATH",
                    help="a sister's working tree: rac1, rac2, rac4, sac or rac5 (or its repository name)")
    ap.add_argument("--sister-baserom", action="append", metavar="NAME=DIR",
                    help="that sister's dumps, when they are not in its baserom/")
    ap.add_argument("--baserom", default=os.environ.get("UYA_BASEROM") or os.path.join(ROOT, "baserom"),
                    help="rac3's dumps (default: $UYA_BASEROM, else baserom/)")
    ap.add_argument("--out", default=os.path.join(ROOT, "build", "sister_twins.tsv"),
                    help="the TSV to write (default: build/sister_twins.tsv)")
    ap.add_argument("--near", type=float, default=95.0, metavar="PCT",
                    help="the share of equal masked words a near twin needs (default 95)")
    ap.add_argument("--include-matched", action="store_true",
                    help="also rac3's functions at 100 %% (a recall check of the rule on known ports)")
    ap.add_argument("--check-mask", action="store_true",
                    help="compare the mask with splat's relocations in rac3's asm, then exit")
    ap.add_argument("--asm", default=os.path.join(ROOT, "asm"), help="rac3's generated asm (default: asm/)")
    a = ap.parse_args(argv)

    if a.check_mask:
        if not os.path.isdir(os.path.join(a.asm, "boot_elf", "nonmatchings")):
            raise SystemExit("no %s (python3 tools/setup_asm.py --target boot_elf, or --asm DIR)"
                             % os.path.join(a.asm, "boot_elf", "nonmatchings"))
        t = check_mask(a.asm)
        print("words: masked and relocated %d, masked not relocated %d, relocated not masked %d, plain %d"
              % (t["masked_reloc"], t["masked_plain"], t["reloc_kept"], t["plain"]))
        print("functions whose mask equals splat's relocations: %d / %d" % (t["agree"], t["functions"]))
        if t["examples"]:
            print("some that differ:", " ".join(t["examples"]))
        return 0

    roots = parse_pairs(a.sister, "sister")
    if not roots:
        ap.error("name at least one sister: --sister rac1=PATH (rac1, rac2, rac4, sac, rac5)")
    bases = parse_pairs(a.sister_baserom, "sister-baserom")
    for k in bases:
        if k not in roots:
            ap.error("--sister-baserom %s without --sister %s" % (k, k))

    rac3 = rac3_functions(os.path.abspath(a.baserom), a.include_matched)
    if not rac3:
        raise SystemExit("no rac3 functions with bytes: is %s rac3's baserom/ (--baserom)?" % a.baserom)
    sisters = []
    for k, root in roots.items():
        repo, parts = SISTER_RULES[k]
        if not os.path.isdir(os.path.join(root, "src")):
            print("%s: skipped, %s is not its working tree (no src/)" % (repo, root))
            continue
        for p in parts(root, bases.get(k, os.path.join(root, "baserom"))):
            if p.skipped:
                print("%s %s: skipped, %s" % (p.repo, p.version, p.skipped))
                continue
            fns, missing = load_bytes([s for s in p.functions if s.size >= MIN_SIZE])
            print("%s %s: %d matched-C functions of %d bytes and more (%s)%s" % (
                p.repo, p.version, len(fns), MIN_SIZE, p.note,
                "; %d more without bytes (a dump is missing)" % missing if missing else ""))
            sisters += fns
    seen, unique = set(), []
    for s in sisters:
        if (s.repo, s.version, s.name, s.src) not in seen:
            seen.add((s.repo, s.version, s.name, s.src))
            unique.append(s)
    if not unique:
        raise SystemExit("no sister function with bytes: every sister was skipped (see above)")
    rows = find_twins(rac3, unique, a.near)
    write_tsv(a.out, rows)
    print("\n".join(summary(rows)))
    print("wrote", a.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
