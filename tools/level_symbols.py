#!/usr/bin/env python3
"""level_symbols.py: what the names in a level's C stand for, read from the level's own bytes.

    python3 tools/level_symbols.py --target level_NN    # tools/build.py runs it before linking

The C in src/levels/ is written once, with catalogue names (docs/levels.md): a shared function
calls func_L01_00301558 and reads D_L01_001D66B0 in every level that has it, while in each level
those are somewhere else. As in rac2-decomp's build (Placement.derive there), each object of
build/levels/<NN_name>/src/ that has C is laid over the level's retail .text at its file's
address, and:

  - every word without a relocation must equal retail's word there;
  - every relocation gives the value its symbol must have for the word to read as retail's:
    R_MIPS_26 (a jump's target), R_MIPS_HI16 with its first R_MIPS_LO16 (an address's halves;
    every other %lo of that symbol must then agree), R_MIPS_GPREL16 (the level's $gp, config/gp.tsv) and
    R_MIPS_32;
  - a name must get one value in the whole level, and where its value is known it must be that:
      func_LNN_XXXXXXXX     its place in this level (config/levels/functions.tsv), if it has one
      fe_func_XXXXXXXX      a front-end function's copy in this level (tools/level_tree.py)
      D_XXXXXXXX_sda        a $gp-relative slot: XXXXXXXX - 0x1DC8B0 from the level's $gp
                            (config/gp.tsv; docs/GLOBALS.md)
      func_/D_/jtbl_XXXXXXXX the address in the name (the resident core, or this level's own
                            address in a level-only function)
      D_LNN_/func_LNN_ in level NN itself: the address in the name
    and a name the object defines must be where the object puts it.

The values are written to build/levels/<NN_name>/symbol_addrs_derived.txt, which the level's
linker script reads after symbol_addrs_resolved.txt, with each C function's address name
(func_XXXXXXXX, what the level's assembly calls it). A difference stops the build with the
function and the word that differ: the C is not that function in this level. The C must not
have data of its own (.data, .bss, strings, literal pools): the level's data is its assembly's,
except its switch jump tables. An object's .rodata of jump tables goes where its code reads it,
when every word there is the level's (jump_table()); the level then links with
build/levels/<NN_name>/<target>.ld (derived_script()): .text from each file's object, and the
data section cut around each table (split_data()).
"""
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 2, 4, 5, 6, 7
ADDRESS_NAME = re.compile(r"^(?:func|D|jtbl)_([0-9A-Fa-f]{8})(?:_[A-Za-z0-9]+)*$")
LEVEL_NAME = re.compile(r"^(?:func|D)_L(\d\d)_([0-9A-F]{8})(?:_[A-Za-z0-9]+)*$")
C_MARKER = re.compile(r"localdecomp:start func_([0-9A-F]{8}) ")
FUNCTION_MARK = re.compile(r"(localdecomp:start )func_([0-9A-F]{8}) "
                           r"|^(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(\"[^\"]*\",\s*func_([0-9A-F]{8})\)", re.M)
SKIP = (".reginfo", ".mdebug", ".comment", ".note", ".pdr", ".gnu", ".gptab")
# gcc's read-only data (`.rdata`, which the assembler names .rodata): in level C, switch jump tables
RODATA = (".rodata", ".rdata")


class Differ(Exception):
    def __init__(self, offset, why):
        Exception.__init__(self, why)
        self.offset, self.why = offset, why


def sext(v):
    return v - 0x10000 if v & 0x8000 else v


def read_object(path):
    """{text, relocs [(offset, type, symbol name)], defined {name: offset}, extra [section]} of
    one object's .text."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    with open(path, "rb") as f:
        elf = ELFFile(f)
        secs = list(elf.iter_sections())
        idx = next(i for i, s in enumerate(secs) if s.name == ".text")
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols()) if symtab else []

        def name_of(i):
            s = syms[i]
            if s["st_info"]["type"] == "STT_SECTION":
                return "\u00a7" + secs[s["st_shndx"]].name
            return s.name
        relocs = []
        for s in secs:
            if isinstance(s, RelocationSection) and s["sh_info"] == idx:
                relocs += [(r["r_offset"], r["r_info_type"], name_of(r["r_info_sym"])) for r in s.iter_relocations()]
        defined = {s.name: s["st_value"] for s in syms
                   if s.name and s["st_shndx"] == idx and s["st_info"]["type"] != "STT_SECTION"}
        exported = {s.name for s in syms if s.name in defined and s["st_info"]["bind"] != "STB_LOCAL"}
        extra = [s.name for s in secs if s["sh_flags"] & 2 and s["sh_size"] and s.name != ".text"
                 and not s.name.startswith(SKIP)]
        rodata = []
        for k, s in enumerate(secs):
            if s.name in RODATA and s["sh_size"]:
                rel = []
                for r in secs:
                    if isinstance(r, RelocationSection) and r["sh_info"] == k:
                        rel += [(x["r_offset"], x["r_info_type"], name_of(x["r_info_sym"])) for x in r.iter_relocations()]
                rodata.append({"name": s.name, "data": s.data(), "relocs": sorted(rel),
                               "align": s["sh_addralign"] or 1})
        return {"text": secs[idx].data(), "text_align": secs[idx]["sh_addralign"] or 1,
                "relocs": relocs, "defined": defined, "exported": exported,
                "extra": extra, "rodata": rodata}


def section_size(path, name):
    """The size of an object's section NAME."""
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        return ELFFile(f).get_section_by_name(name)["sh_size"]


def derive(data, ref, relocs, address, gp, ranges=None, gp_names=None):
    """{symbol: value} that make `data` (an object's .text with `relocs`, in table order) read
    as `ref` at `address`, with `gp` the program's $gp; Differ when no values can. With `ranges`
    ([(start, end)] offsets: the C functions), only the relocations inside them give values: the
    assembly's are its own addresses already. `gp_names` (a set) gets the names read through
    $gp."""
    if len(ref) != len(data):
        raise Differ(len(ref), "runs past the end of .text")
    touched = {o for o, _, _ in relocs}
    if ranges is not None:
        relocs = [r for r in relocs if any(a <= r[0] < b for a, b in ranges)]
    for at in range(0, len(data), 4):
        if at not in touched and data[at:at + 4] != ref[at:at + 4]:
            raise Differ(at, "the instruction differs")
    word = lambda b, at: struct.unpack_from("<I", b, at)[0]
    values = {}

    def agree(at, symbol, value):
        value &= 0xFFFFFFFF
        if values.setdefault(symbol, value) != value:
            raise Differ(at, "%s would be at 0x%08X and at 0x%08X" % (symbol, values[symbol], value))
    for i, (at, kind, symbol) in enumerate(relocs):
        mine, theirs = word(data, at), word(ref, at)
        if kind == R_MIPS_26:
            if (mine ^ theirs) & 0xFC000000:
                raise Differ(at, "the jump differs")
            agree(at, symbol, (((address + at) & 0xF0000000) | ((theirs & 0x3FFFFFF) << 2))
                  - ((mine & 0x3FFFFFF) << 2))
        elif kind == R_MIPS_HI16:
            lo = next((r for r in relocs[i + 1:] if r[1] == R_MIPS_LO16 and r[2] == symbol), None)
            if lo is None:
                raise Differ(at, "a %%hi of %s without its %%lo" % symbol)
            if (mine ^ theirs) & 0xFFFF0000:
                raise Differ(at, "the instruction differs")
            target = ((theirs & 0xFFFF) << 16) + sext(word(ref, lo[0]) & 0xFFFF)
            addend = ((mine & 0xFFFF) << 16) + sext(word(data, lo[0]) & 0xFFFF)
            agree(at, symbol, target - addend)
        elif kind == R_MIPS_LO16:
            pass              # checked below, once every %hi has given its value
        elif kind == R_MIPS_GPREL16:
            if (mine ^ theirs) & 0xFFFF0000:
                raise Differ(at, "the gp access differs")
            agree(at, symbol, gp + sext(theirs & 0xFFFF) - sext(mine & 0xFFFF))
            if gp_names is not None:
                gp_names.add(symbol)
        elif kind == R_MIPS_32:
            agree(at, symbol, theirs - mine)
        else:
            raise Differ(at, "relocation type %d (a literal pool or a jump table?) is not handled" % kind)
    for at, kind, symbol in relocs:
        if kind != R_MIPS_LO16:
            continue
        mine, theirs = word(data, at), word(ref, at)
        if symbol not in values:
            raise Differ(at, "a %%lo of %s without a %%hi" % symbol)
        if (mine ^ theirs) & 0xFFFF0000 or (values[symbol] + sext(mine & 0xFFFF) - theirs) & 0xFFFF:
            raise Differ(at, "the instruction differs")
    return values


class Level:
    """What a level's names must be, where that is known."""

    def __init__(self, number, rows=None, gp=None):
        import level_catalogue as lc
        import gp as gp_table
        import levels
        self.number = number
        # the level's $gp (config/gp.tsv): an sda name's value depends on it
        self.gp = gp if gp is not None else gp_table.gp_of(levels.target_name(number))
        rows = rows or lc.read_catalogue()
        self.place = {r[0]: a for r in rows for n, a in r[5] if n == number}
        self.by_address = {a: r[0] for r in rows for n, a in r[5] if n == number}
        # a front-end function is named fe_func_XXXXXXXX in a level's tree; a bare func_XXXXXXXX
        # there is the level's own label at that address (an assembly function of a file with C)
        self.front_end = {r[0] for r in rows if r[1] in ("frontbin", "boot_elf")}

    def expected(self, name):
        import gp as gp_table
        sda = gp_table.sda_value(name, self.gp)
        if sda is not None:
            return sda            # D_XXXXXXXX_sda: the slot XXXXXXXX - 0x1DC8B0 from this level's $gp
        if name.startswith("fe_"):
            return self.place.get(name[3:])
        if name in self.place and name not in self.front_end:
            return self.place[name]
        m = LEVEL_NAME.match(name)
        if m:
            return int(m.group(2), 16) if int(m.group(1)) == self.number else None
        m = ADDRESS_NAME.match(name)
        return int(m.group(1), 16) if m else None

    def function_at(self, address):
        """(catalogue name, start) of the function holding `address` in this level."""
        starts = [a for a in self.by_address if a <= address]
        return (self.by_address[max(starts)], max(starts)) if starts else ("?", address)


def retail_text(t):
    import levels
    _, secs = levels.read_elf(open(t.path("elf"), "rb").read())
    base, size, _, text = secs[-1]
    return base, text


def object_values(path, start, base, text, gp, c_starts=None, data_sections=None, gp_names=None):
    """(values, defined, exported, tables) of one object placed at `start`, its C functions at
    `c_starts` (addresses, each running to the next function), `tables` its read-only sections
    [(name, address, size)] (jump_table()), placed where its code reads them in
    `data_sections` [(address, bytes)]: Differ (offset from `start`) or ValueError when it
    cannot be."""
    obj = read_object(path)
    other = [x for x in obj["extra"] if x not in RODATA]
    if other:
        raise ValueError("has data of its own (%s): constants or strings; the level's "
                         "data comes from its assembly" % ", ".join(other))
    data = obj["text"]
    ranges = None
    if c_starts is not None:
        ranges = [(a - start, b - start) for a, b in c_starts]
    values = derive(data, text[start - base:start - base + len(data)], obj["relocs"], start, gp, ranges,
                    gp_names)
    tables = []
    for sec in obj["rodata"]:
        at = values.get("\u00a7" + sec["name"])
        if at is None:
            raise ValueError("has a %s its C does not read" % sec["name"])
        jump_table(sec, at, start, len(data), data_sections or [])
        tables.append((sec["name"], at, len(sec["data"])))
    return values, {n: start + v for n, v in obj["defined"].items()}, obj["exported"], tables


def jump_table(sec, at, start, text_size, data_sections):
    """Check that an object's read-only section SEC, linked at AT with its .text at START, is the
    level's bytes there: its switch jump tables. Every word is a case entry (R_MIPS_32 into the
    object's own .text) or a zero word of the `.align` between two tables; an entry must read
    as the level's word, the address of the same instruction in its retail .text. ValueError
    when not."""
    data, size = sec["data"], len(sec["data"])
    where = "its %s at 0x%08X" % (sec["name"], at)
    if size % 4 or at % sec["align"]:
        raise ValueError("%s: not whole words at its alignment" % where)
    owner = next(((a, b) for a, b in data_sections if a <= at and at + size <= a + len(b)), None)
    if owner is None:
        raise ValueError("%s is not in one of the level's data sections" % where)
    a, b = owner
    entries = {}
    for off, kind, symbol in sec["relocs"]:
        if kind != R_MIPS_32 or symbol != "\u00a7.text" or off % 4 or off in entries:
            raise ValueError("%s: +0x%X is not a jump table entry (relocation %d against %s)"
                             % (where, off, kind, symbol))
        entries[off] = struct.unpack_from("<I", data, off)[0]
    for off in range(0, size, 4):
        retail = struct.unpack_from("<I", b, at - a + off)[0]
        if off in entries:
            mine = entries[off]
            if mine % 4 or mine >= text_size or start + mine != retail:
                raise ValueError("%s: entry +0x%X is 0x%08X, the level has 0x%08X"
                                 % (where, off, start + mine, retail))
        elif data[off:off + 4] != b[at - a + off:at - a + off + 4]:
            raise ValueError("%s: word +0x%X differs from the level's" % (where, off))


def retail_data(t):
    """[(address, bytes)] of the level's sections other than .text."""
    import levels
    _, secs = levels.read_elf(open(t.path("elf"), "rb").read())
    return [(a, b) for a, n, kind, b in secs[:-1] if kind != 8]


def level_values(t, rows=None, tables=None):
    """({name: value}, [error]) for every name the level's C objects use; `tables` (a list) gets
    each object's jump tables, (source, object, section, address, size)."""
    import srcfiles as sf
    level = Level(t.level, rows, t.gp)
    base, text = retail_text(t)
    data_sections = retail_data(t)
    placed = []
    workdir = os.path.join(ROOT, t.workdir(t.units[0]))
    values, where, errors, own, made, through_gp = {}, {}, [], {}, set(), set()
    for rel, start in sf.read_file_list(t.path("files")):
        src = open(os.path.join(ROOT, rel), errors="replace").read()
        if "localdecomp:start" not in src:
            continue
        obj = os.path.join(workdir, os.path.splitext(os.path.basename(rel))[0] + ".o")
        try:
            marks = [(int(m.group(2) or m.group(3), 16), bool(m.group(1))) for m in FUNCTION_MARK.finditer(src)]
            c_ranges = [(a, marks[i + 1][0] if i + 1 < len(marks) else 1 << 32)
                        for i, (a, is_c) in enumerate(marks) if is_c]
            vals, defined, exported, objtables = object_values(obj, start, base, text, t.gp, c_ranges,
                                                               data_sections, through_gp)
        except Differ as e:
            a = start + e.offset
            name, f = level.function_at(a)
            errors.append("%s: %s (0x%08X), its word at +0x%X: %s" % (rel, name, f, a - f, e.why))
            continue
        except ValueError as e:
            errors.append("%s: %s" % (rel, e))
            continue
        for sec, at, size in objtables:
            clash = next((p for p in placed if p[3] < at + size and at < p[3] + p[4]), None)
            if clash:
                errors.append("%s: its %s at 0x%08X overlaps %s's" % (rel, sec, at, clash[0]))
                continue
            placed.append((rel, obj, sec, at, size))
        for a in C_MARKER.findall(src):
            own["func_" + a] = int(a, 16)
        made |= exported
        for name in exported:
            value = defined[name]
            if values.setdefault(name, value) != value:
                errors.append("%s: %s is defined at 0x%08X and used at 0x%08X" % (rel, name, value, values[name]))
        for name, value in vals.items():
            if name.startswith("\u00a7"):
                if name[1:] in RODATA:
                    pass          # its jump tables, placed there (jump_table())
                elif name != "\u00a7.text":
                    errors.append("%s: uses its own %s; the level's data comes from its assembly" % (rel, name[1:]))
                elif value != start:
                    errors.append("%s: its .text would have to be at 0x%08X" % (rel, value))
                continue
            if name in defined and defined[name] != value:
                errors.append("%s: %s is at 0x%08X but the code needs it at 0x%08X" % (rel, name, defined[name], value))
            if name in defined and name not in exported:
                continue          # a local of this object (a static function, a label)
            if values.setdefault(name, value) != value:
                errors.append("%s: %s needs 0x%08X, %s gave it 0x%08X" % (rel, name, value, where.get(name, "?"), values[name]))
            where.setdefault(name, rel)
    import gp as gp_table
    for name, value in sorted(values.items()):
        want = level.expected(name)
        if want is not None and want != value:
            hint = ""
            if name in through_gp and gp_table.sda_value(name, t.gp) is None:
                # a $gp access that reads another address: in a level with its own $gp, its slot
                hint = (" (read through $gp 0x%08X: the slot's name is D_%08X_sda, docs/GLOBALS.md)"
                        % (t.gp, (value - t.gp + gp_table.STORY_GP) & 0xFFFFFFFF))
            elif ADDRESS_NAME.match(name):
                hint = " (in level code, name what is not resident D_LNN_XXXXXXXX / func_LNN_XXXXXXXX)"
            errors.append("%s: %s is 0x%08X in level %02d, the code needs 0x%08X%s"
                          % (where.get(name, "?"), name, want, t.level, value, hint))
    values = {n: v for n, v in values.items() if n not in made and not n.startswith("\u00a7")}
    values.update(own)
    if tables is not None:
        tables += sorted(placed, key=lambda p: p[3])
    return values, errors


DATA_ITEM = re.compile(r"^\s*/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8})(?: [0-9A-Fa-f]+)? \*/\s*\.(\w+)")
LABEL_LINE = re.compile(r"^\s*(?:(dlabel|nonmatching|enddlabel)\s+([\w.$]+)\b.*)?$")


def split_data(text, spans):
    """Cut a data section's assembly (splat's .s: one `/* offset address word */` item a line) at
    the jump tables C provides now: `spans` {address: (size, input)}. Returns ([("asm", text) or
    ("c", input)] in address order, {label: address} of the labels cut out with a table).
    A table's span must be whole `.word` items; the labels just before it go with it."""
    lines = text.splitlines(keepends=True)
    first = next((i for i, l in enumerate(lines) if DATA_ITEM.match(l)
                  or re.match(r"\s*(?:dlabel|nonmatching|glabel)\s", l)), len(lines))
    header, body = "".join(lines[:first]), lines[first:]
    pieces, aliases, cur, pending, seen = [], {}, [], [], set()
    active = None                 # (start, end, consumed)

    def flush():
        if any(DATA_ITEM.match(l) for l in cur):
            pieces.append(("asm", cur[:]))
        elif "".join(cur).strip() and pieces and pieces[-1][0] == "asm":
            pieces[-1][1].extend(cur)
        del cur[:]
    for line in body:
        m = DATA_ITEM.match(line)
        if not m:
            pending.append(line)
            continue
        addr, kind = int(m.group(1), 16), m.group(2)
        if active and addr >= active[1]:
            if active[2] != active[1]:
                raise ValueError("the data at 0x%08X..0x%08X is not whole words" % tuple(active[:2]))
            active = None
        if active is None and addr in spans:
            cut = len(pending)
            while cut and LABEL_LINE.match(pending[cut - 1]) and not pending[cut - 1].lstrip().startswith("enddlabel"):
                cut -= 1
            cur.extend(pending[:cut])
            for l in pending[cut:]:
                lm = LABEL_LINE.match(l)
                if lm.group(1) == "dlabel":
                    aliases[lm.group(2)] = addr
            pending = []
            flush()
            size, owner = spans[addr]
            pieces.append(("c", owner))
            seen.add(addr)
            active = [addr, addr + size, addr]
        if active:
            for l in pending:
                lm = LABEL_LINE.match(l)
                if not lm and not re.fullmatch(r"\s*/\*.*\*/\s*", l):
                    raise ValueError("0x%08X: %r inside a jump table" % (addr, l.strip()))
                if lm and lm.group(1) == "dlabel":
                    aliases[lm.group(2)] = addr
            pending = []
            if kind != "word" or addr != active[2]:
                raise ValueError("0x%08X: a jump table's data is not consecutive words" % addr)
            active[2] += 4
            continue
        cur.extend(pending)
        cur.append(line)
        pending = []
    if active and active[2] != active[1]:
        raise ValueError("the data at 0x%08X..0x%08X runs past the section" % tuple(active[:2]))
    cur.extend(pending)
    flush()
    if seen != set(spans):
        raise ValueError("no data item starts at %s" % ", ".join("0x%08X" % a for a in sorted(set(spans) - seen)))
    out = []
    expanded = []
    for kind, body in pieces:
        # the words after a table that ends 4 mod 8 (the `.align` zero words up to the next table)
        # cannot share a piece with a later `.align 3`: the assembler aligns inside the piece, not
        # at its address. They get a piece of their own, up to the first item that is aligned.
        while kind == "asm":
            first_item = next(DATA_ITEM.match(l) for l in body if DATA_ITEM.match(l))
            start = int(first_item.group(1), 16)
            aligns = [int(x) for x in re.findall(r"^\s*\.align\s+(\d+)", "".join(body), re.M)]
            need = max(8, 1 << max(aligns)) if aligns else 8      # the header's `.align 3` makes every piece 8-aligned
            if start % need == 0 or not expanded or expanded[-1][0] != "c":
                break
            cut = next((i for i, l in enumerate(body) if DATA_ITEM.match(l) and int(DATA_ITEM.match(l).group(1), 16) % need == 0), None)
            if cut is None:
                break
            while cut and (LABEL_LINE.match(body[cut - 1]) and not body[cut - 1].lstrip().startswith("enddlabel")
                           or re.match(r"\s*\.align\s", body[cut - 1])):
                cut -= 1
            if cut == 0 or any(re.match(r"\s*\.align\s", l) for l in body[:cut]):
                break
            expanded.append(("asm4", body[:cut]))
            body = body[cut:]
        expanded.append((kind, body))
    for kind, body in expanded:
        if kind == "c":
            out.append((kind, body))
            continue
        # a label's .size goes with the label: drop it where the label is not in this piece
        defined = {LABEL_LINE.match(l).group(2) for l in body if LABEL_LINE.match(l) and LABEL_LINE.match(l).group(1) == "dlabel"}
        body = [l for l in body if not (LABEL_LINE.match(l) and LABEL_LINE.match(l).group(1) == "enddlabel"
                                        and LABEL_LINE.match(l).group(2) not in defined)]
        start = int(next(DATA_ITEM.match(l) for l in body if DATA_ITEM.match(l)).group(1), 16)
        aligns = [int(x) for x in re.findall(r"^\s*\.align\s+(\d+)", "".join(body), re.M)]
        if aligns and start % (1 << max(aligns)):
            raise ValueError("0x%08X: the data after a jump table has an .align %d it does not start on"
                             % (start, max(aligns)))
        text = header + "".join(body)
        if kind == "asm4":
            # a .data piece, and any piece whose header has the file's `.align 3`, is 8-aligned,
            # which would move it off the table's end: this one is a 4-aligned .text piece
            text = re.sub(r'(?m)^\s*\.section\s+\.data[^\n]*$', ".text", text, count=1)
            text = re.sub(r'(?m)^\s*\.align\s+\d+[ \t]*$', "", text)
        out.append((kind, text))
    return out, aliases


def derived_script(t, tables):
    """The level's linker script with its C's jump tables at their places: .text from each
    file's object (so that each file's .rodata can go where it belongs), every data section that
    holds a table cut around it (split_data()). Writes build/levels/<NN_name>/<target>.ld and the
    pieces' .s (pieces/); returns the script's path."""
    import srcfiles as sf
    build = os.path.join(ROOT, t.build_dir)
    script = open(os.path.join(ROOT, t.ld)).read()
    unit = t.units[0]
    whole = "%s(.text);" % t.obj(unit).replace(os.sep, "/")
    if script.count(whole) != 1:
        raise ValueError("%s: no single %s" % (t.ld, whole))
    stems = [os.path.splitext(os.path.basename(rel))[0] for rel, start in sf.read_file_list(t.path("files"))
             if unit.contains(start)]
    workdir = t.workdir(unit).replace(os.sep, "/")
    script = script.replace(whole, "\n        ".join("%s/%s.o(.text);" % (workdir, s) for s in stems))
    sections = [(int(m.group(2), 16), m.group(1), m.group(3)) for m in re.finditer(
        r"(\.\w+) 0x([0-9A-Fa-f]+) : AT\([^)]*\)\s*\{\s*(\S+?\.s\.o)\(\.data\);", script)]
    by_section = {}
    for rel, obj, sec, at, size in tables:
        owner = max((s for s in sections if s[0] <= at), default=None)
        if owner is None:
            raise ValueError("0x%08X: no data section of %s holds it" % (at, t.ld))
        by_section.setdefault(owner, {})[at] = (size, "%s(%s);" % (os.path.relpath(obj, ROOT).replace(os.sep, "/"), sec))
    pdir = os.path.join(build, "pieces")
    os.makedirs(pdir, exist_ok=True)
    prefix = t.build_dir.replace(os.sep, "/").rstrip("/") + "/"
    aliases = {}
    for (vaddr, name, obj), spans in sorted(by_section.items()):
        source = obj[len(prefix):-2]
        pieces, labels = split_data(open(os.path.join(ROOT, source)).read(), spans)
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
        script = script.replace("%s(.data);" % obj, "\n        ".join(inputs), 1)
    head = "/* %s with its C's jump tables in place (tools/level_symbols.py; generated). */\n" % t.ld
    head += "".join("%s = 0x%08X;\n" % (n, a) for n, a in sorted(aliases.items()))
    path = os.path.join(build, t.name + ".ld")
    open(path, "w", newline="\n").write(head + script)
    return path


def write(t):
    path = os.path.join(ROOT, t.build_dir, "symbol_addrs_derived.txt")
    derived = os.path.join(ROOT, t.build_dir, t.name + ".ld")
    if os.path.exists(derived):
        os.remove(derived)
    tables = []
    values, errors = level_values(t, tables=tables)
    if tables and not errors:
        try:
            derived_script(t, tables)
        except ValueError as e:
            errors.append("the jump tables: %s" % e)
    resolved = {}
    rp = t.path("symbols_resolved")
    if os.path.exists(rp):
        for m in re.finditer(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", open(rp).read(), re.M):
            resolved[m.group(1)] = int(m.group(2), 16)
    for name, value in sorted(values.items()):
        if name in resolved and resolved[name] != value:
            errors.append("%s is 0x%08X in %s, the C needs 0x%08X" % (name, resolved[name], t.symbols_resolved, value))
    lines = ["/* %s: the values of the names its C uses, read from its bytes" % t.level_dir,
             "   (tools/level_symbols.py; generated, never committed). */"]
    lines += ["%s = 0x%08X;" % (n, v) for n, v in sorted(values.items()) if n not in resolved]
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, "w", newline="\n").write("\n".join(lines) + "\n")
    return len(lines) - 2, errors


def main():
    import targets
    t = targets.from_argv()
    if not targets.is_level(t):
        sys.exit("level_symbols.py works on a level (--target level_NN)")
    n, errors = write(t)
    if errors:
        sys.exit("%s: the C does not match this level:\n  %s" % (t.level_dir, "\n  ".join(errors)))
    print("%s: %d names from the C's relocations" % (t.level_dir, n))


if __name__ == "__main__":
    main()
