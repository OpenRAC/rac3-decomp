#!/usr/bin/env python3
"""port_verify.py: after a build, compare every function of a program with retail.

The full build's MATCH line is the proof; this says which functions break it. For each entry of
the program's sources (in address order, each up to the next one), it compares the built flat
binary with the retail file at the function's file offset and prints the functions that differ,
with their kind (C, INCLUDE_ASM, ...). With symbols out of place (the linked ELF's func_/D_/jtbl_
symbols at addresses other than their names) it lists those first, since one wrong size moves
everything after it.

    python3 tools/port_verify.py --target boot_elf
    python3 tools/port_verify.py --target all --hold build/port/hold.txt   # append the C ones

--hold appends the C functions that differ to a list tools/port_from_us.py --hold reads.
--sizes instead checks each C function's size in the per-file objects (no link needed; run it
first, since one wrong size moves everything after it). --errors BUILD_LOG reads a failed build's log and appends the C functions the compiler's
errors point at (file:line inside their block, or the function a "conflicting types" error names).
"""
import argparse
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import progress  # noqa: E402
import targets  # noqa: E402


def file_offsets(data):
    """[(vaddr, offset, size)] of the retail ELF's loaded sections."""
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", data, 0x2E)
    out = []
    for i in range(shnum):
        _, typ, _, addr, off, size = struct.unpack_from("<6I", data, shoff + i * shentsize)
        if addr and size and typ != 8:
            out.append((addr, off, size))
    return out


def misplaced(elf_path):
    try:
        from elftools.elf.elffile import ELFFile
    except ImportError:
        return []
    out = []
    with open(elf_path, "rb") as f:
        e = ELFFile(f)
        st = e.get_section_by_name(".symtab")
        for s in st.iter_symbols() if st else []:
            parts = s.name.split("_")
            if parts[0] in ("func", "D", "jtbl") and len(parts) == 2 and len(parts[1]) == 8 \
                    and s["st_shndx"] != "SHN_ABS":
                try:
                    a = int(parts[1], 16)
                except ValueError:
                    continue
                if a != s["st_value"]:
                    out.append((a, s["st_value"], s.name))
    return sorted(out)


def verify(t, hold):
    built = os.path.join(ROOT, t.build_dir, t.bin_name)
    if not os.path.exists(built):
        sys.exit("%s: no %s; run tools/build.py --target %s first" % (t.name, built, t.name))
    b = open(built, "rb").read()
    r = open(t.path("elf"), "rb").read()
    secs = file_offsets(r)

    def off(a):
        return next((o + a - s for s, o, n in secs if s <= a < s + n), None)

    mp = misplaced(os.path.join(ROOT, t.build_dir, t.name + ".elf"))
    if mp:
        print("%s: %d symbols out of place; the first: %s at %08X" % (t.name, len(mp), mp[0][2], mp[0][1]))
    es = progress.entries(t)
    bad = []
    for i, (rel, u, addr, kind) in enumerate(es):
        end = es[i + 1][2] if i + 1 < len(es) and es[i + 1][1] is u else u.end
        o = off(addr)
        if o is None:
            continue
        if b[o:o + end - addr] != r[o:o + end - addr]:
            bad.append((addr, kind, rel))
    for addr, kind, rel in bad:
        print("  differs: func_%08X (%s, %s)" % (addr, kind, rel))
    print("%s: %d of %d functions differ (%d of them C)"
          % (t.name, len(bad), len(es), sum(1 for _, k, _ in bad if k == "C")))
    if hold:
        with open(hold, "a") as f:
            for addr, kind, _ in bad:
                if kind == "C":
                    f.write("func_%08X %s\n" % (addr, t.name))
    return not bad and not mp


def errors_to_functions(log, hold):
    """C functions that the compile errors in a build log point at."""
    import re
    import srcfiles as sf
    found = set()
    for line in open(log, errors="replace"):
        m = re.match(r"(src/\S+?\.c):(\d+): (.*)", line)
        if not m or "warning" in m.group(3):
            continue
        rel, n = m.group(1), int(m.group(2))
        if not os.path.exists(os.path.join(ROOT, rel)):
            continue
        text = sf.read_source(rel)
        _, _, chunks = sf.split_file(text)
        owner = None
        for addr, start, body in chunks:
            if start <= n < start + body.count("\n") + 1 and "localdecomp:start" in body:
                owner = addr
        c = re.search(r"conflicting types for `(func_[0-9A-F]{8})'", m.group(3))
        if owner is None and c:
            owner = int(c.group(1)[5:], 16)
        if owner is not None:
            t = next((t for t in targets.TARGETS.values()
                      if any(rel.startswith(u.src_dir + "/") for u in t.units)), None)
            found.add("func_%08X %s" % (owner, t.name if t else "?"))
    with open(hold, "a") as f:
        for x in sorted(found):
            f.write(x + "\n")
    print("%d functions held for compile errors" % len(found))
    return found


def sizes(t, hold):
    """C functions whose compiled size is not retail's, from the per-file objects (no link
    needed): a function is the distance from its symbol to the next entry's symbol."""
    from elftools.elf.elffile import ELFFile
    import srcfiles as sf
    es = progress.entries(t)
    by_file = {}
    for rel, u, addr, kind in es:
        by_file.setdefault(rel, (u, []))[1].append((addr, kind))
    starts = sorted((addr for _, _, addr, _ in es))
    bad = []
    for rel, (u, items) in by_file.items():
        stem = os.path.splitext(os.path.basename(rel))[0]
        obj = os.path.join(t.workdir(u), stem + ".o")
        if not os.path.exists(obj):
            continue
        with open(obj, "rb") as f:
            e = ELFFile(f)
            st = e.get_section_by_name(".symtab")
            text = e.get_section_by_name(".text")
            syms = {s.name: s["st_value"] for s in st.iter_symbols() if s.name.startswith("func_")} if st else {}
            tsize = text["sh_size"] if text else 0
        items.sort()
        base = items[0][0]
        nxt_file = next((a for a in starts if a > items[-1][0] and t.unit_for(a) is u), u.end)
        for k, (addr, kind) in enumerate(items):
            if kind != "C":
                continue
            name = "func_%08X" % addr
            if name not in syms:
                continue
            end = items[k + 1][0] if k + 1 < len(items) else nxt_file
            nname = "func_%08X" % end
            actual_end = syms.get(nname) if k + 1 < len(items) else (tsize + 7) & ~7
            if actual_end is None:
                continue
            if k + 1 == len(items) and ((tsize + 7) & ~7 == nxt_file - base
                                        or nxt_file == u.end and tsize <= nxt_file - base):
                continue   # the file's last function: the whole object has retail's size
                           # (the section's last file may be followed by the section's padding)
            if actual_end - syms[name] != end - addr:
                bad.append((addr, rel, actual_end - syms[name], end - addr))
    for addr, rel, got, want in bad:
        print("  size: func_%08X %s: 0x%X, retail 0x%X" % (addr, rel, got, want))
    print("%s: %d C functions with the wrong size" % (t.name, len(bad)))
    if hold:
        with open(hold, "a") as f:
            for addr, _, _, _ in bad:
                f.write("func_%08X %s\n" % (addr, t.name))
    return not bad


def main():
    if "--sizes" in sys.argv:
        t = targets.from_argv(allow_all=True)
        ap = argparse.ArgumentParser()
        ap.add_argument("--sizes", action="store_true")
        ap.add_argument("--hold")
        a = ap.parse_args()
        sys.exit(0 if sizes(t, a.hold) else 1)
    if "--errors" in sys.argv:
        ap = argparse.ArgumentParser()
        ap.add_argument("--errors", required=True)
        ap.add_argument("--hold", required=True)
        ap.add_argument("--target", default="all")
        a = ap.parse_args()
        errors_to_functions(a.errors, a.hold)
        return
    t = targets.from_argv(allow_all=True)
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--hold", help="append the C functions that differ to this file")
    a = ap.parse_args()
    sys.exit(0 if verify(t, a.hold) else 1)


if __name__ == "__main__":
    main()
