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
section must occur exactly once in the retail program, at its alignment.

A switch's jump table is read-only data with a relocation per entry (R_MIPS_32 against its
file's `.text`; the word holds the case label's offset in it). Its file's table and the other
files' pools need not sit together in retail (newlib's vfprintf, func_0011C180: its table and
func_00120730's pools are apart), so a unit whose read-only data has relocations is placed file
by file: the unit is linked from its files' objects (tools/build_text.py's <workdir>/<stem>.o,
in link order, which is what its `ld -r` object is made of) in place of that object, a file's
data with relocations is searched alone with each entry filled with the label's address (the
file's start in src_files.txt plus the offset; a word whose relocation names anything else is
masked), and each run of consecutive files with plain data together, each exactly once. The
linker writes the entries in place itself, and the full build's MATCH proves them. A unit with
no relocations in its read-only data is placed as before, its object's section whole.
Returns the script's path, or None when no unit's object has read-only data.
"""
import os
import re
import struct
import sys

R_MIPS_32 = 2

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))


def retail_segments(path):
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        elf = ELFFile(f)
        return [(s["p_vaddr"], s.data()) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"]]


def find_once(segments, data, align, masked=()):
    """Addresses (at `align`) where `data` occurs in the segments; the 4-byte words at the
    offsets in `masked` may hold anything."""
    hits = []
    if not masked:
        for base, b in segments:
            i = b.find(data)
            while i >= 0:
                if (base + i) % align == 0:
                    hits.append(base + i)
                i = b.find(data, i + 1)
        return hits
    masked = set(masked)
    keep = [k for k in range(0, len(data), 4) if k not in masked]
    if not keep:
        return []
    # an anchor: the longest run of unmasked words, searched as bytes, then every other word compared
    runs, start = [], None
    for k in range(0, len(data) + 4, 4):
        if k < len(data) and k not in masked:
            start = k if start is None else start
        elif start is not None:
            runs.append((start, k))
            start = None
    a0, a1 = max(runs, key=lambda r: r[1] - r[0])
    anchor = data[a0:a1]
    for base, b in segments:
        i = b.find(anchor)
        while i >= 0:
            at = i - a0
            if at >= 0 and at + len(data) <= len(b) and (base + at) % align == 0 and \
                    all(b[at + k:at + k + 4] == data[k:k + 4] for k in keep):
                hits.append(base + at)
            i = b.find(anchor, i + 1)
    return sorted(set(hits))


def filled(sec, text_at):
    """(the section's bytes with each R_MIPS_32 word against its object's own .text, linked at
    `text_at`, filled with the address it resolves to, [offsets of the relocated words with no known
    value])"""
    data = bytearray(sec["data"])
    masked = []
    for off, kind, sym in sec["relocs"]:
        if kind == R_MIPS_32 and sym == "§.text" and text_at is not None and off % 4 == 0:
            addend, = struct.unpack_from("<I", data, off)
            struct.pack_into("<I", data, off, (text_at + addend) & 0xFFFFFFFF)
        else:
            masked.append(off - off % 4)
    return bytes(data), masked


def per_file(t, u, obj, script, segments, place):
    """Unit `u` linked from its files' objects (build_text.py's <workdir>/<stem>.o, which `obj` is the
    `ld -r` of) in place of `obj`, and each file's read-only data placed where it is in retail: a file's
    data with relocations (its jump tables, entries filled with the file's start + the label's offset)
    alone, and each run of consecutive files with plain data (literal pools) together, as the unit's
    object has it. Returns the script."""
    import level_symbols as ls
    import srcfiles as sf
    rel_obj = obj.replace(os.sep, "/")
    if "%s(.text);" % rel_obj not in script:
        raise ValueError("%s has read-only data with relocations but %s does not link its .text" % (obj, t.ld))
    files = [(rel, start) for rel, start in sf.read_file_list(t.path("files")) if u.contains(start)]
    fobjs = []
    for rel, start in files:
        p = os.path.join(t.workdir(u), os.path.splitext(os.path.basename(rel))[0] + ".o").replace(os.sep, "/")
        if not os.path.exists(os.path.join(ROOT, p)):
            raise ValueError("%s: no object %s (tools/build_text.py makes one per file)" % (rel, p))
        fobjs.append((rel, start, p, ls.read_object(os.path.join(ROOT, p))))
    script = script.replace("%s(.text);" % rel_obj, "\n        ".join("%s(.text);" % p for _, _, p, _ in fobjs), 1)
    names = []
    for _, _, _, fo in fobjs:
        names += [sec["name"] for sec in fo["rodata"] if sec["name"] not in names]
    for name in names:
        # [(file, its start, object, section)] in link order, then groups: a section with relocations alone,
        # runs of plain ones together
        pieces = [(rel, start, p, sec) for rel, start, p, fo in fobjs for sec in fo["rodata"] if sec["name"] == name]
        groups, run = [], []
        for pc in pieces:
            if pc[3]["relocs"]:
                if run:
                    groups.append(run)
                    run = []
                groups.append([pc])
            else:
                run.append(pc)
        if run:
            groups.append(run)
        for g in groups:
            align = max(max(4, pc[3]["align"]) for pc in g)
            data, masked, inputs = bytearray(), [], []
            for rel, start, p, sec in g:
                a = max(1, sec["align"])
                data += b"\0" * ((-len(data)) % a)
                d, m = filled(sec, start) if sec["relocs"] else (sec["data"], [])
                masked += [len(data) + k for k in m]
                data += d
                inputs.append("%s(%s);" % (p, name))
            hits = find_once(segments, bytes(data), align, masked)
            if len(hits) != 1:
                raise ValueError("%s's %s of %s (%d bytes, %d relocated words) occurs %d times in the retail "
                                 "program, not once" % (rel_obj, name, ", ".join(pc[0] for pc in g), len(data),
                                                        sum(len(pc[3]["relocs"]) for pc in g), len(hits)))
            place(hits[0], len(data), "\n        ".join(inputs))
    return script


def derive(t):
    import level_symbols as ls
    script = open(os.path.join(ROOT, t.ld)).read()
    spans, owners = {}, {}
    segments = None
    sections = [(int(m.group(2), 16), m.group(1), m.group(3)) for m in re.finditer(
        r"(\.\w+) 0x([0-9A-Fa-f]+) : AT\([^)]*\)\s*\{\s*(\S+?\.s\.o)\(\.data\);", script)]
    def place(at, size, inputs):
        owner = max((s for s in sections if s[0] <= at), default=None)
        if owner is None:
            raise ValueError("0x%08X: no single-input data section of %s holds it" % (at, t.ld))
        spans.setdefault(owner, {})[at] = (size, inputs)

    for u in t.units:
        obj = t.obj(u)
        if not os.path.exists(os.path.join(ROOT, obj)):
            continue
        o = ls.read_object(os.path.join(ROOT, obj))
        todo = [sec for sec in o["rodata"] if "%s(%s)" % (obj.replace(os.sep, "/"), sec["name"]) not in script]
        if not todo:
            continue                      # the script already places it (an overlay's text.c.o), or none
        segments = segments or retail_segments(os.path.join(ROOT, t.elf))
        if any(sec["relocs"] for sec in todo):
            # a jump table: the unit's read-only data is placed file by file (the files' tables and pools need
            # not sit together in retail), so the unit is linked from its files' objects, in link order
            script = per_file(t, u, obj, script, segments, place)
            continue
        for sec in todo:
            hits = find_once(segments, sec["data"], max(4, sec["align"]))
            if len(hits) != 1:
                raise ValueError("%s's %s (%d bytes) occurs %d times in the retail program, not once"
                                 % (obj, sec["name"], len(sec["data"]), len(hits)))
            place(hits[0], len(sec["data"]), "%s(%s);" % (obj.replace(os.sep, "/"), sec["name"]))
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
