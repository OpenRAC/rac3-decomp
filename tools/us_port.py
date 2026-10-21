#!/usr/bin/env python3
"""us_port.py: NTSC-U C for PAL functions whose NTSC-U counterpart differs only in constants.

    python3 tools/us_port.py -j 16 --toolchain DIR --runner WIBO --ee29 DIR [PAL_NAME ...]

For each PAL C function whose NTSC-U counterpart has other bytes (config/us/map.tsv, status
`differs`, docs/versions.md): the words that differ are compared, and where they differ only in an
immediate (addiu/ori/slti/... the 50 Hz values of PAL against NTSC's 60 Hz: 25 and 30, 250 and
300, a float 0.02 and 1/60), each PAL constant in the C is replaced by the NTSC-U one. The result
is checked on NTSC-U (tools/check.py --version us: names masked or read as their twins'). When it
gives MATCH, the values of the names it uses are read from the NTSC-U bytes
(tools/level_symbols.py derive()), the names are rewritten as NTSC-U addresses, and the C is
checked again natively (--native: NTSC-U names, the counterpart's file flags). Only then is it
written to src/us/<program>/<ADDRESS>.c with its config/us/text_parts.txt line. Anything else is
reported and left for a person.
"""
import argparse
import os
import re
import struct
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import version  # noqa: E402

IMM_OPS = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x18, 0x19}   # addi addiu slti sltiu andi ori xori daddi daddiu
RESIDENT_END = 0x1D5680


def sext(v):
    return v - 0x10000 if v & 0x8000 else v


def words_at(program, v, addr, size):
    import inventory as inv
    import levels
    for n, a, d, _ in inv.elf_sections(levels.core_elf_path(program, v=v)):
        if a <= addr < a + len(d):
            return list(struct.unpack("<%dI" % (size // 4), d[addr - a:addr - a + size]))
    return None


def check(path, name, program, a, extra=(), keep=None):
    cmd = [sys.executable, os.path.join(ROOT, "tools", "check.py"), "--version", "us", path, name, "--quiet",
           "--target", program, "--toolchain", a.toolchain] + (["--runner", a.runner] if a.runner else []) + \
        (["--ee29", a.ee29] if a.ee29 else []) + list(extra) + (["--keep-object", keep] if keep else [])
    p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, env=dict(os.environ, UYA_VERSION="us"))
    m = re.search(r"^%s: (MATCH|(\d+) diff)" % re.escape(name), p.stdout, re.M)
    return (None if not m else m.group(1) == "MATCH"), p.stdout + p.stderr


def constant_pairs(pal, us, relocated):
    """[(PAL value, NTSC-U value)] of the immediates that differ in words without a relocation;
    None when a difference is anything else."""
    pairs = []
    i = 0
    while i < len(pal):
        x, y = pal[i], us[i]
        if x != y and 4 * i not in relocated:
            if x >> 16 != y >> 16 or (x >> 26) not in IMM_OPS:
                # lui + ori of a float constant: both words differ
                if x >> 26 == 0x0F and y >> 26 == 0x0F and i + 1 < len(pal) and pal[i + 1] >> 26 == 0x0D \
                        and (x ^ y) & 0xFFFF0000 == 0:
                    fx = struct.unpack("<f", struct.pack("<I", ((x & 0xFFFF) << 16) | (pal[i + 1] & 0xFFFF)))[0]
                    fy = struct.unpack("<f", struct.pack("<I", ((y & 0xFFFF) << 16) | (us[i + 1] & 0xFFFF)))[0]
                    pairs.append(("f", fx, fy))
                    i += 2
                    continue
                return None
            op = x >> 26
            px, py = x & 0xFFFF, y & 0xFFFF
            if op in (0x08, 0x09, 0x0A, 0x0B, 0x18, 0x19):
                px, py = sext(px), sext(py)
            pairs.append(("i", px, py))
        i += 1
    return pairs


def literals(value, kind):
    """Ways C writes this constant."""
    if kind == "f":
        return []
    out = [str(value), "0x%X" % value, "0x%x" % value] if value >= 0 else [str(value), "-0x%X" % -value]
    return out


def float_literals(text):
    return re.findall(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?f|\d*\.\d+(?:[eE][-+]?\d+)?f|\d+\.0f)", text)


def f32(s):
    return struct.unpack("<f", struct.pack("<f", float(s.rstrip("f"))))[0]


def substitute(text, pairs):
    """TEXT with each PAL constant replaced by its NTSC-U value (inside the function body only)."""
    head, sep, body = text.partition("{")
    for kind, px, py in dict.fromkeys(pairs):
        if px == py:
            continue
        if kind == "f":
            done = False
            for lit in sorted(set(float_literals(body)), key=len, reverse=True):
                if abs(f32(lit) - px) <= abs(px) * 1e-6:
                    body = re.sub(r"(?<![\w.])%s" % re.escape(lit), "%.9gf" % py if "." in "%.9g" % py else "%.1ff" % py, body)
                    done = True
            if not done:
                return None
            continue
        hit = False
        for lit in literals(px, kind):
            rx = r"(?<![\w.])%s(?![\w.])" % re.escape(lit)
            if re.search(rx, body):
                new = ("0x%X" % py if lit.lower().startswith(("0x", "-0x")) else str(py)) if py >= 0 else str(py)
                body = re.sub(rx, new, body)
                hit = True
                break
        if not hit:
            return None
    return head + sep + body


NAME = re.compile(r"\b(?:func|D)_[0-9A-F]{8}\w*")


def context(program, pal, block):
    """What the build puts in front of PAL's block in its file (build_text.function_context), with
    only the declarations and size hints of names the block uses."""
    import build_text as bt
    import targets
    os.environ["UYA_TARGET"] = program
    parts = bt.read_parts(targets.TARGETS[program].path("parts"))
    ctx = bt.function_context(None, parts, pal, own_src=block)
    used = set(NAME.findall(block))
    out = []
    for line in ctx.splitlines():
        names = NAME.findall(line)
        if line.lstrip().startswith(("extern", "__asm__")) and names and not set(names) & used:
            continue
        out.append(line)
    return bt.drop_repeated_typedefs(block, "\n".join(out) + "\n")


def substitute_all(text, pairs, limit=24):
    """substitute(), then, for a constant written more than once, each single occurrence replaced
    (the others left): the candidates to check, in that order."""
    out = []
    first = substitute(text, pairs)
    if first is not None:
        out.append(first)
    head, sep, body = text.partition("{")
    for kind, px, py in dict.fromkeys(pairs):
        if kind == "f" or px == py:
            continue
        for lit in literals(px, kind):
            rx = re.compile(r"(?<![\w.])%s(?![\w.])" % re.escape(lit))
            spots = list(rx.finditer(body))
            if len(spots) > 1:
                rest = [p for p in pairs if p != (kind, px, py)]
                for m in spots:
                    new = "0x%X" % py if lit.lower().startswith("0x") else str(py)
                    one = head + sep + body[:m.start()] + new + body[m.end():]
                    c = substitute(one, rest)
                    if c is not None:
                        out.append(c)
                break
    return list(dict.fromkeys(out))[:limit]


def port(row, a, tmp):
    import level_symbols as ls
    import version_map as vm
    program, pal, us = row["program"], row["pal"], row["us"]
    st = vm.pal_states()[(program, pal)]
    rel, size, paddr = st[1], st[2], st[3]
    uaddr = int(us[5:], 16)
    pal_w = words_at(program, "pal", paddr, size)
    us_w = words_at(program, "us", uaddr, size)
    if pal_w is None or us_w is None or len(pal_w) != len(us_w):
        return pal, "sizes differ: not a constant change"
    block = vm.chunk_text(program, rel, pal, block_only=True)
    work = os.path.join(tmp, pal)
    os.makedirs(work, exist_ok=True)
    p0 = os.path.join(work, "pal.c")
    open(p0, "w").write(block)
    ok, out = check(p0, pal, program, a, keep=os.path.join(work, "pal.o"))
    if ok is None:
        return pal, "the PAL block does not compile alone"
    relocated = {o for o, _, _ in ls.read_object(os.path.join(work, "pal.o"))["relocs"]}
    pairs = constant_pairs(pal_w, us_w, relocated)
    if pairs is None:
        return pal, "code differs beyond constants"
    cands = substitute_all(block, pairs)
    if not cands:
        return pal, "a constant (%s) is not written as a literal in the C" % ", ".join("%s->%s" % (x, y) for _, x, y in pairs)
    p1 = os.path.join(work, "cand.c")
    obj = os.path.join(work, "cand.o")
    for cand in cands:
        open(p1, "w").write(cand)
        ok, out = check(p1, pal, program, a, keep=obj)
        if ok:
            break
    if not ok:
        return pal, "with the NTSC-U constants: %s" % (out.strip().splitlines()[-1][:120] if out.strip() else "no result")
    o = ls.read_object(obj)
    try:
        ref = struct.pack("<%dI" % (len(o["text"]) // 4), *words_at(program, "us", uaddr, len(o["text"])))
        vals = ls.derive(o["text"], ref, o["relocs"], uaddr, 0x1DC8B0)
    except ls.Differ as e:
        return pal, "names: +0x%X %s" % (e.offset, e.why)
    # the context the block is compiled in (its file's types, declarations and size hints), only
    # the declarations of the names the block uses
    native = context(program, pal, cand) + cand
    # the NTSC-U names: every relocated name as the address it has there (an alias keeps its suffix)
    renamed = set()
    for name, v in sorted(vals.items(), key=lambda x: -len(x[0])):
        m = re.match(r"^(func|D)_[0-9A-F]{8}(_\w+)?$", name)
        if not m:
            continue
        new = ("%s_%08X%s" if v < RESIDENT_END else "%s_U_%08X%s") % (m.group(1), v, m.group(2) or "")
        renamed.add(new)
        native = re.sub(r"\b%s\b" % re.escape(name), new, native)
    us = vm.native_name(us)
    native = re.sub(r"\b%s\b" % re.escape(pal), us, native)
    left = sorted(set(re.findall(r"\b(?:func|D)_[0-9A-F]{8}\w*", native)) - renamed)
    left = [n for n in left if not (re.match(r"^(?:func|D)_([0-9A-F]{8})$", n) and int(n.split("_")[1], 16) < RESIDENT_END)]
    # a function the block declares without a relocation to it: its twin's or counterpart's name
    for n in list(left):
        r = vm.Map().by_pal.get((program, n))
        if r and r["us"] != "-" and n.startswith("func_"):
            native = re.sub(r"\b%s\b" % re.escape(n), vm.native_name(r["us"]), native)
            left.remove(n)
    if left:
        # declarations from the file's context of names the function does not use
        keep = []
        for line in native.splitlines():
            if line.lstrip().startswith(("extern", "__asm__")) and any(re.search(r"\b%s\b" % re.escape(n), line)
                                                                     for n in left):
                continue
            keep.append(line)
        native = "\n".join(keep) + "\n"
        left = [n for n in left if re.search(r"\b%s\b" % re.escape(n), native)]
    if left:
        return pal, "names with no NTSC-U value: %s" % ", ".join(left[:5])
    native = native.replace("/* localdecomp:start %s */" % us, "/* localdecomp:start %s */" % us)
    text = '#include "common.h"\n\n/* NTSC-U version of %s (%s): %s */\n%s' % (
        pal, program, "; ".join("%s -> %s" % ("%g" % x if k == "f" else x, "%g" % y if k == "f" else y)
                               for k, x, y in pairs if x != y), native.strip() + "\n")
    dest = os.path.join(ROOT, "src", "us", program, "%s.c" % vm.us_name(us)[5:])
    p2 = os.path.join(work, "native.c")
    open(p2, "w").write(text)
    ok, out = check(p2, us, program, a, extra=["--native"])
    if not ok:
        return pal, "native check: %s" % (out.strip().splitlines()[-1][:120] if out.strip() else "no result")
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    open(dest, "w").write(text)
    return pal, "MATCH: %s" % os.path.relpath(dest, ROOT)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*")
    ap.add_argument("-j", "--jobs", type=int, default=8)
    ap.add_argument("--toolchain", required=True)
    ap.add_argument("--runner")
    ap.add_argument("--ee29")
    a = ap.parse_args()
    import version_map as vm
    rows = [r for r in vm.Map().rows if r["status"] == "differs" and r["state"] == "C" and r["program"] != "levels"
            and (not a.names or r["pal"] in a.names)]
    tmp = os.environ.get("US_PORT_KEEP") or tempfile.mkdtemp(prefix="us_port_")
    parts = vm.us_parts()
    with ThreadPoolExecutor(a.jobs) as ex:
        results = list(ex.map(lambda r: port(r, a, tmp), rows))
    for r, (pal, msg) in zip(rows, results):
        print("%s %s -> %s: %s" % (r["program"], pal, r["us"], msg))
        if msg.startswith("MATCH: "):
            rel = msg[7:]
            parts[rel] = vm.counterpart_flags(r["program"], r["us"])
    lines = ["# Compiler flags of src/us/'s files (NTSC-U's own C), one line per file: the flags of the PAL",
             "# source file its function's counterpart is in (docs/versions.md). No per-function flags."]
    lines += ["%s\t%s" % (k, v) for k, v in sorted(parts.items())]
    open(vm.US_PARTS, "w", newline="\n").write("\n".join(lines) + "\n")
    if not os.environ.get("US_PORT_KEEP"):
        import shutil
        shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    main()
