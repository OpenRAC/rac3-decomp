#!/usr/bin/env python3
"""levels.py: the level overlays, from the disc to the build.

    python3 tools/levels.py dump        # baserom/levels/<NN_name>.elf from baserom/SCES_524.56.iso
    python3 tools/levels.py config      # config/levels/levels.tsv, config/splat/levels/, linker_scripts/levels/
    python3 tools/levels.py catalogue   # config/levels/functions.tsv (after tools/level_bootstrap.py)
    python3 tools/levels.py tree [NN|all]   # build/levels/<NN_name>/ from src/levels/ and the catalogue

Every level carries its own build of the game's main program: the sections `.lit`, `.bss`,
`.data`, `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` and `.text`, which replace the boot
program's ones when the level loads (frontbin, the front end, is the same kind of program; see
docs/levels.md). The engine core (`core.text` and its data, in `boot_elf`) stays resident.

## Where the levels are on the disc

All data is addressed by sector through the table of contents at sector 1001 (Wrench's
docs/file_loading.md describes the format):

  - the table opens with the global WAD headers, each starting (header size, sector), one
    after the other; then the level table: one entry per level number, three (sector,
    size) pairs pointing at copies of the headers of the level's AUDIO, LEVEL and SCENE
    files, told apart by their sizes (the LEVEL header is 0x60 bytes);
  - the LEVEL header: +0x04 the file's sector, +0x08 the level number, +0x10 the level
    data (sector offset in the file, sector count);
  - the level data opens with (offset, size) byte ranges; the first is the program: a list of
    sections, each a 16-byte record (destination, size, ELF section type, entry point)
    followed by its bytes (the .bss's zeros too). Every section repeats the entry point; the
    list ends where the program's range ends.

`dump` writes each level's program as an ELF in frontbin.elf's layout (the layout Wrench gives
the programs it unpacks): the ELF header in the first 0x1000 bytes, one PT_LOAD with every
section at `0x1000 + (address - .lit's address)`, then `.shstrtab` and the section header
table. That file is the target the build compares with; `dump` checks that converting it back
gives the disc's program byte for byte (`overlay_sha1` in config/levels/levels.tsv), and the
build does the same check on what it builds (tools/build.py). Nothing here is committed: the
ELFs stay in baserom/levels/.

The level numbers and names are the game's (the LEVEL header's own number); the names are
the ones Wrench and rac3-uya-decomp (the US decompilation) use. PAL has 49 levels: 1-14,
16-24, 26-36 (story, ranger missions and vid-comics) and 39-53 (the multiplayer menu and maps).
"""
import hashlib
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISO = os.path.join(ROOT, "baserom", "SCES_524.56.iso")
DUMP = os.path.join(ROOT, "baserom", "levels")
TABLE = os.path.join(ROOT, "config", "levels", "levels.tsv")
CATALOGUE = os.path.join(ROOT, "config", "levels", "functions.tsv")
TOC_LBA = 1001
SECTOR = 0x800

# level number -> (directory slug, title). The names are the game's own level list as Wrench
# and rac3-uya-decomp (objdiff.json's level units) give it.
NAMES = {
    1: ("veldin", "Veldin"), 2: ("florana", "Florana"), 3: ("starship_phoenix", "Starship Phoenix"),
    4: ("marcadia", "Marcadia"), 5: ("daxx", "Daxx"),
    6: ("starship_phoenix_under_attack", "Starship Phoenix Under Attack"),
    7: ("annihilation_nation", "Annihilation Nation"), 8: ("aquatos", "Aquatos"),
    9: ("tyhrranosis", "Tyhrranosis"), 10: ("zeldrin_starport", "Zeldrin Starport"),
    11: ("obani_moons", "Obani Moons"), 12: ("rilgar", "Rilgar"),
    13: ("holostar_studios_ratchet", "Holostar Studios (Ratchet)"), 14: ("koros", "Koros"),
    16: ("kerwan", "Kerwan"), 17: ("crash_site", "Crash Site"), 18: ("aridia", "Aridia"),
    19: ("thran_asteroid_belt", "Thran Asteroid Belt"), 20: ("final_boss", "Final Boss"),
    21: ("obani_draco", "Obani Draco"), 22: ("mylon", "Mylon"),
    23: ("holostar_studios_clank", "Holostar Studios (Clank)"), 24: ("insomniac_museum", "Insomniac Museum"),
    26: ("kerwan_ranger_missions", "Kerwan Ranger Missions"), 27: ("aquatos_base", "Aquatos Base"),
    28: ("aquatos_sewers", "Aquatos Sewers"),
    29: ("tyhrranosis_ranger_missions", "Tyhrranosis Ranger Missions"),
    30: ("vidcomic_unnamed", "Vid-comic (unnamed)"), 31: ("vidcomic_1", "Vid-comic 1"),
    32: ("vidcomic_4", "Vid-comic 4"), 33: ("vidcomic_2", "Vid-comic 2"), 34: ("vidcomic_3", "Vid-comic 3"),
    35: ("vidcomic_5", "Vid-comic 5"), 36: ("vidcomic_1_special_edition", "Vid-comic 1 Special Edition"),
    39: ("multiplayer_menu", "Multiplayer Menu"), 40: ("bakisi_isles", "Bakisi Isles"),
    41: ("hoven_gorge", "Hoven Gorge"), 42: ("outpost_x12", "Outpost X12"),
    43: ("korgon_outpost", "Korgon Outpost"), 44: ("metropolis", "Metropolis"),
    45: ("blackwater_city", "Blackwater City"), 46: ("command_center", "Command Center"),
    47: ("blackwater_docks", "Blackwater Docks"), 48: ("aquatos_sewers_mp", "Aquatos Sewers (multiplayer)"),
    49: ("marcadia_palace", "Marcadia Palace"),
    50: ("bakisi_isles_splitscreen", "Bakisi Isles (split screen)"),
    51: ("hoven_gorge_splitscreen", "Hoven Gorge (split screen)"),
    52: ("outpost_x12_splitscreen", "Outpost X12 (split screen)"),
    53: ("korgon_outpost_splitscreen", "Korgon Outpost (split screen)"),
}
MULTIPLAYER = range(39, 54)

# The sections of a level program, in the program's order, with frontbin.elf's names, flags and
# alignments (type 8 is the NOBITS .bss, whose zeros the program carries all the same).
SECTIONS = [(".lit", 0xF0000003, 0x40), (".bss", 0xF0000003, 0x40), (".data", 0x3, 0x40),
            ("lvl.vtbl", 0x2, 0x1), ("lvl.camvtbl", 0x2, 0x1), ("lvl.sndvtbl", 0x2, 0x1), (".text", 0x6, 0x40)]
# splat's segment names for them (and the linker script's output sections)
SEGMENTS = ["lit", None, "data", "lvl_vtbl", "lvl_camvtbl", "lvl_sndvtbl", "text"]


def dirname(number):
    return "%02d_%s" % (number, NAMES[number][0])


def title(number):
    return "Level %02d: %s" % (number, NAMES[number][1])


def target_name(number):
    return "level_%02d" % number


# --- the disc -----------------------------------------------------------------------

def read_programs(iso_path=ISO):
    """{level number: (entry, [(address, size, type, bytes)], raw program bytes)} from the disc."""
    out = {}
    with open(iso_path, "rb") as f:
        f.seek(TOC_LBA * SECTOR)
        toc = f.read(0x100000)
        ofs = 0
        while True:   # the global WAD headers
            size, _ = struct.unpack_from("<ii", toc, ofs)
            if size < 8 or size > 0xFFFF:
                break
            ofs += size
        for i in range(128):
            entry = struct.unpack_from("<6i", toc, ofs + 24 * i)
            for lba, _ in zip(entry[0::2], entry[1::2]):
                at = (lba - TOC_LBA) * SECTOR
                if lba <= TOC_LBA or at + 0x60 > len(toc):
                    continue
                size, file_lba, number, _, data_sectors, _ = struct.unpack_from("<6i", toc, at)
                if size != 0x60:
                    continue
                if number not in NAMES:
                    sys.exit("level table entry %d: unknown level number %d" % (i, number))
                base = (file_lba + data_sectors) * SECTOR
                f.seek(base)
                prog_ofs, prog_size = struct.unpack("<ii", f.read(8))
                f.seek(base + prog_ofs)
                raw = f.read(prog_size)
                sections, p, ep = [], 0, None
                while p < len(raw):
                    dest, n, kind, e = struct.unpack_from("<4I", raw, p)
                    ep = e if ep is None else ep
                    if e != ep:
                        break
                    sections.append((dest, n, kind, raw[p + 16:p + 16 + n]))
                    p += 16 + n
                if p != len(raw) or len(sections) != len(SECTIONS):
                    sys.exit("level %d: unexpected program layout" % number)
                out[number] = (ep, sections, raw)
    if sorted(out) != sorted(NAMES):
        sys.exit("levels on the disc: %s; expected %s" % (sorted(out), sorted(NAMES)))
    return out


def records(entry, sections):
    """The disc's program format for (entry, [(address, size, type, bytes)])."""
    return b"".join(struct.pack("<4I", a, n, k, entry) + b for a, n, k, b in sections)


def layout(sections):
    """[(file offset, address, size)] of each section in the ELF: one PT_LOAD from 0x1000."""
    base = sections[0][0]
    return [(0x1000 + a - base, a, n) for a, n, _, _ in sections]


def write_elf(entry, sections):
    """A level program as an ELF in frontbin.elf's layout (see the module docstring)."""
    lay = layout(sections)
    end = lay[-1][0] + lay[-1][2]
    image = bytearray(end)
    for (off, _, n), (_, _, _, b) in zip(lay, sections):
        image[off:off + n] = b
    names = b"".join(s[0].encode() + b"\0" for s in SECTIONS) + b".shstrtab\0"
    shstrtab = end
    image += names
    shoff = (len(image) + 3) & ~3
    image += bytes(shoff - len(image))
    name_at, k = [], 0
    for s in SECTIONS:
        name_at.append(k)
        k += len(s[0]) + 1
    shdrs = [bytes(40)]
    for (off, a, n), (_, _, kind, _), (_, flags, align), name in zip(lay, sections, SECTIONS, name_at):
        shdrs.append(struct.pack("<10I", name, kind, flags, a, off, n, 0, 0, align, 0))
    shdrs.append(struct.pack("<10I", k, 3, 0, 0, shstrtab, len(names), 0, 0, 1, 0))
    image += b"".join(shdrs)
    struct.pack_into("<4s5B7x2H5I6H", image, 0, b"\x7fELF", 1, 1, 1, 0, 0, 2, 8, 1, entry, 0x34, shoff,
                     0x20924001, 0x34, 0x20, 1, 0x28, len(shdrs), len(shdrs) - 1)
    load = end - 0x1000
    struct.pack_into("<8I", image, 0x34, 1, 0x1000, sections[0][0], sections[0][0], load, load, 7, 0x1000)
    return bytes(image)


def read_elf(data):
    """(entry, [(address, size, type, bytes)]) of a level ELF (write_elf's layout)."""
    entry, shoff = struct.unpack_from("<I", data, 0x18)[0], struct.unpack_from("<I", data, 0x20)[0]
    shnum = struct.unpack_from("<H", data, 0x30)[0]
    out = []
    for i in range(1, shnum - 1):
        _, kind, _, a, off, n, _, _, _, _ = struct.unpack_from("<10I", data, shoff + 40 * i)
        out.append((a, n, kind, data[off:off + n]))
    return entry, out


def program_of_elf(data):
    """The disc's program bytes for a level ELF (or a built image of one)."""
    return records(*read_elf(data))


def elf_path(number):
    return os.path.join(DUMP, dirname(number) + ".elf")


# --- the table ----------------------------------------------------------------------

def read_table(path=TABLE):
    """[{number, dir, title, elf_sha1, overlay_sha1, entry, sections: [(name, address, size, offset)]}]"""
    out = []
    for line in open(path, encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.rstrip("\n").split("\t")
        secs = []
        for s in f[6].split(","):
            name, a, n, off = s.split(":")
            secs.append((name, int(a, 16), int(n, 16), int(off, 16)))
        out.append({"number": int(f[0]), "dir": f[1], "title": f[2], "elf_sha1": f[3], "overlay_sha1": f[4],
                    "entry": int(f[5], 16), "sections": secs, "elf_size": int(f[7], 16)})
    return out


def dump(write=True):
    programs = read_programs()
    os.makedirs(DUMP, exist_ok=True)
    rows = []
    for number in sorted(programs):
        entry, sections, raw = programs[number]
        elf = write_elf(entry, sections)
        if program_of_elf(elf) != raw:
            sys.exit("level %d: the ELF does not convert back to the disc's program" % number)
        if write:
            with open(elf_path(number), "wb") as f:
                f.write(elf)
        lay = layout(sections)
        rows.append((number, entry, [(SECTIONS[i][0], a, n, off) for i, (off, a, n) in enumerate(lay)],
                     hashlib.sha1(elf).hexdigest(), hashlib.sha1(raw).hexdigest(), len(elf)))
        print("%s: %d sections, .text 0x%X..0x%X, %s" % (dirname(number), len(sections), sections[-1][0],
              sections[-1][0] + sections[-1][1], os.path.relpath(elf_path(number), ROOT) if write else "checked"))
    return rows


# --- config: the table, splat configurations, linker scripts --------------------------

TABLE_HEAD = """# The level overlays (tools/levels.py config): number, directory, title, SHA-1 of the ELF that
# tools/levels.py dump writes to baserom/levels/<directory>.elf, SHA-1 of the program as the disc
# stores it, entry point, sections (name:address:size:ELF file offset) and the ELF's size.
"""


def write_config():
    rows = dump(write=False)
    lines = [TABLE_HEAD.rstrip("\n")]
    for number, entry, secs, elf_sha1, raw_sha1, elf_size in rows:
        lines.append("\t".join([str(number), dirname(number), NAMES[number][1], elf_sha1, raw_sha1, "%08X" % entry,
                                ",".join("%s:%08X:%X:%X" % s for s in secs), "%X" % elf_size]))
    os.makedirs(os.path.dirname(TABLE), exist_ok=True)
    open(TABLE, "w", newline="\n").write("\n".join(lines) + "\n")
    for row in read_table():
        open(yaml_path(row), "w", newline="\n").write(splat_yaml(row))
        open(ld_path(row), "w", newline="\n").write(linker_script(row))
    print("wrote %s, %d splat configurations and linker scripts" % (os.path.relpath(TABLE, ROOT), len(rows)))


def yaml_path(row):
    d = os.path.join(ROOT, "config", "splat", "levels")
    os.makedirs(d, exist_ok=True)
    return os.path.join(d, row["dir"] + ".yaml")


def ld_path(row):
    d = os.path.join(ROOT, "linker_scripts", "levels")
    os.makedirs(d, exist_ok=True)
    return os.path.join(d, row["dir"] + ".ld")


def trailer_start(row):
    name, a, n, off = row["sections"][-1]
    return off + n


def splat_yaml(row):
    d, b = row["dir"], "build/levels/" + row["dir"]
    segs = ["  - {name: header, type: bin, start: 0x0}"]
    for (name, a, n, off), seg in zip(row["sections"], SEGMENTS):
        if seg == "text":
            segs.append("  - name: text\n    type: code\n    start: 0x%X\n    vram: 0x%X\n    subsegments:\n"
                        "      - [0x%X, c, text]" % (off, a, off))
        elif seg:
            segs.append("  - {name: %s, type: data, start: 0x%X, vram: 0x%X}" % (seg, off, a))
    segs.append("  - {name: trailer, type: bin, start: 0x%X}" % trailer_start(row))
    segs.append("  - [0x%X]" % row["elf_size"])
    return """# %(title)s (level %(number)d): its program as tools/levels.py dump writes it. Made by
# tools/levels.py config; regenerate it rather than editing it.
name: %(target)s
sha1: %(sha1)s
options:
  basename: %(target)s
  target_path: baserom/levels/%(dir)s.elf
  base_path: ../../..
  build_path: build
  asset_path: %(b)s/splat_assets
  asm_path: asm/levels/%(dir)s
  src_path: %(b)s/src
  ld_script_path: %(b)s/%(dir)s.splat.ld
  compiler: EEGCC
  platform: ps2
  find_file_boundaries: True
  gp_value: 0x001DC8B0
  symbol_addrs_path:
    - %(b)s/symbol_addrs.txt
  asm_function_macro: glabel
  asm_data_macro: dlabel
  migrate_rodata_to_functions: True
  generate_asm_macros_files: False
  undefined_funcs_auto_path: %(b)s/undefined_funcs_auto.txt
  undefined_syms_auto_path: %(b)s/undefined_syms_auto.txt

# frontbin's layout at the level's addresses: .lit, then .bss, which the file stores as zeros
# (part of the lit segment, as in frontbin), .data, the three lvl.* vtables and .text. The
# trailer is .shstrtab plus the section header table.
segments:
%(segs)s
""" % {"title": row["title"], "number": row["number"], "target": target_name(row["number"]), "dir": d, "b": b,
       "sha1": row["elf_sha1"], "segs": "\n".join(segs)}


def linker_script(row):
    d, b = row["dir"], "build/levels/" + row["dir"]
    out = ["/* %s (level %d): baserom/levels/%s.elf (tools/levels.py dump), built by tools/build.py" % (
        row["title"], row["number"], d),
           "   --target %s. Made by tools/levels.py config; regenerate it rather than editing it." % target_name(row["number"]),
           "",
           "   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every",
           "   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */",
           "",
           "INPUT(%s/symbol_addrs_resolved.txt)" % b,
           "/* the names the level's C uses (tools/level_symbols.py) */",
           "INPUT(%s/symbol_addrs_derived.txt)" % b, "", "SECTIONS", "{",
           "    /* ELF header and program header (file 0x0..0x1000), raw bytes. */",
           "    .header 0x0 : AT(0x0)", "    {", "        %s/asm/levels/%s/header.s.o(.data);" % (b, d), "    }", ""]
    for (name, a, n, off), seg in zip(row["sections"], SEGMENTS):
        if seg is None:
            continue
        if seg == "text":
            out += ["    /* .text: src/levels/ through %s/src/ (tools/levels.py tree). */" % b,
                    "    .text 0x%X : AT(0x%X)" % (a, off), "    {", "        %s/src/text.c.o(.text);" % b, "    }", ""]
            continue
        note = {"lit": "    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */",
                "data": "    /* .data, whole: its jump tables are spread among the other data. */"}.get(seg)
        if note:
            out.append(note)
        out += ["    .%s 0x%X : AT(0x%X)" % (seg, a, off), "    {",
                "        %s/asm/levels/%s/data/%s.data.s.o(.data);" % (b, d, seg), "    }"]
        if seg == "lit":
            out.append("    _gp = 0x001DC8B0;")
        out.append("")
    out += ["    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;",
            "       objcopy places it by file offset. */",
            "    .trailer 0x8000000 : AT(0x%X)" % trailer_start(row), "    {",
            "        %s/asm/levels/%s/trailer.s.o(.data);" % (b, d), "    }", "",
            "    /DISCARD/ :", "    {", "        *(*);", "    }", "}"]
    return "\n".join(out) + "\n"


def main():
    args = sys.argv[1:]
    if not args or args[0] not in ("dump", "config", "catalogue", "tree"):
        sys.exit(__doc__)
    if args[0] == "dump":
        dump()
    elif args[0] == "config":
        write_config()
    elif args[0] == "catalogue":
        import level_catalogue
        level_catalogue.main(args[1:])
    else:
        import level_tree
        level_tree.main(args[1:])


if __name__ == "__main__":
    main()
