#!/usr/bin/env python3
"""core_rodata.py: a core C object's read-only data (literal pools) in its place in retail.

gcc writes a double or float constant that is not an immediate (`0.1`, `1000000.0`) into the
file's read-only data, and the code reads it through %hi/%lo of the object's `.rodata`. In
retail the bytes sit in the program's read-only blob (boot_elf's .core_rdata, one assembly
blob for every core source file), and the linker script discards the object's `.rodata`, so
the relocations resolved to 0 and the full build differed (func_00120730) though the
per-function check, which fills a relocation from the name, matched.

derive(t) writes <build_dir>/<target>.ld: the linker script with the blob cut around the
object's `.rodata` (level_symbols.split_data(), pieces in <build_dir>/pieces/) and the
object's `.rodata` linked between the two halves. The place is found from the bytes: the
section (no relocations of its own) must occur exactly once in the retail program, 8-aligned.
Returns the script's path, or None when no unit's object has read-only data.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))


def retail_segments(path):
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        elf = ELFFile(f)
        return [(s["p_vaddr"], s.data()) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"]]


def find_once(segments, data, align):
    hits = []
    for base, b in segments:
        i = b.find(data)
        while i >= 0:
            if (base + i) % align == 0:
                hits.append(base + i)
            i = b.find(data, i + 1)
    return hits


def derive(t):
    import level_symbols as ls
    script = open(os.path.join(ROOT, t.ld)).read()
    spans, owners = {}, {}
    segments = None
    sections = [(int(m.group(2), 16), m.group(1), m.group(3)) for m in re.finditer(
        r"(\.\w+) 0x([0-9A-Fa-f]+) : AT\([^)]*\)\s*\{\s*(\S+?\.s\.o)\(\.data\);", script)]
    for u in t.units:
        obj = t.obj(u)
        if not os.path.exists(os.path.join(ROOT, obj)):
            continue
        o = ls.read_object(os.path.join(ROOT, obj))
        for sec in o["rodata"]:
            if "%s(%s)" % (obj.replace(os.sep, "/"), sec["name"]) in script:
                continue                  # the script already places it (an overlay's text.c.o)
            if sec["relocs"]:
                raise ValueError("%s's %s has relocations (jump tables in a core file need the blob "
                                 "split by file)" % (obj, sec["name"]))
            segments = segments or retail_segments(os.path.join(ROOT, t.elf))
            hits = find_once(segments, sec["data"], max(4, sec["align"]))
            if len(hits) != 1:
                raise ValueError("%s's %s (%d bytes) occurs %d times in the retail program, not once"
                                 % (obj, sec["name"], len(sec["data"]), len(hits)))
            at = hits[0]
            owner = max((s for s in sections if s[0] <= at), default=None)
            if owner is None:
                raise ValueError("0x%08X: no single-input data section of %s holds it" % (at, t.ld))
            spans.setdefault(owner, {})[at] = (len(sec["data"]), "%s(%s);" % (obj.replace(os.sep, "/"), sec["name"]))
    if not spans:
        return None
    pdir = os.path.join(ROOT, t.build_dir, "pieces")
    os.makedirs(pdir, exist_ok=True)
    prefix = t.build_dir.replace(os.sep, "/").rstrip("/") + "/"
    aliases = {}
    for (vaddr, name, aobj), sp in sorted(spans.items()):
        pieces, labels = ls.split_data(open(os.path.join(ROOT, aobj[len(prefix):-2])).read(), sp)
        aliases.update(labels)
        inputs = []
        for k, (kind, body) in enumerate(pieces):
            if kind == "c":
                inputs.append(body)
                continue
            path = os.path.join(pdir, "%s_%d.s" % (name.lstrip("."), k))
            open(path, "w", newline="\n").write(body)
            inputs.append("%s(%s);" % (os.path.relpath(path, ROOT).replace(os.sep, "/") + ".o",
                                      ".text" if kind == "asm4" else ".data"))
        script = script.replace("%s(.data);" % aobj, "\n        ".join(inputs), 1)
    head = "/* %s with its C's read-only data in place (tools/core_rodata.py; generated). */\n" % t.ld
    head += "".join("%s = 0x%08X;\n" % (n, a) for n, a in sorted(aliases.items()))
    path = os.path.join(ROOT, t.build_dir, t.name + ".ld")
    open(path, "w", newline="\n").write(head + script)
    return path
