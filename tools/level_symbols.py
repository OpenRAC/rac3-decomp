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
    every other %lo of that symbol must then agree), R_MIPS_GPREL16 (gp = 0x1DC8B0) and
    R_MIPS_32;
  - a name must get one value in the whole level, and where its value is known it must be that:
      func_LNN_XXXXXXXX     its place in this level (config/levels/functions.tsv), if it has one
      fe_func_XXXXXXXX      a front-end function's copy in this level (tools/level_tree.py)
      func_/D_/jtbl_XXXXXXXX the address in the name (the resident core, or this level's own
                            address in a level-only function)
      D_LNN_/func_LNN_ in level NN itself: the address in the name
    and a name the object defines must be where the object puts it.

The values are written to build/levels/<NN_name>/symbol_addrs_derived.txt, which the level's
linker script reads after symbol_addrs_resolved.txt, with each C function's address name
(func_XXXXXXXX, what the level's assembly calls it). A difference stops the build with the
function and the word that differ: the C is not that function in this level. The C must not
have data of its own (.rodata, .data, .bss, literal pools): the level's data is its assembly's.
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
        return {"text": secs[idx].data(), "relocs": relocs, "defined": defined, "exported": exported,
                "extra": extra}


def section_size(path, name):
    """The size of an object's section NAME."""
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        return ELFFile(f).get_section_by_name(name)["sh_size"]


def derive(data, ref, relocs, address, gp, ranges=None):
    """{symbol: value} that make `data` (an object's .text with `relocs`, in table order) read
    as `ref` at `address`; Differ when no values can. With `ranges` ([(start, end)] offsets: the
    C functions), only the relocations inside them give values: the assembly's are its own
    addresses already."""
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
                raise Differ(at, "the instruction differs")
            agree(at, symbol, gp + sext(theirs & 0xFFFF) - sext(mine & 0xFFFF))
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

    def __init__(self, number, rows=None):
        import level_catalogue as lc
        self.number = number
        rows = rows or lc.read_catalogue()
        self.place = {r[0]: a for r in rows for n, a in r[5] if n == number}
        self.by_address = {a: r[0] for r in rows for n, a in r[5] if n == number}
        # a front-end function is named fe_func_XXXXXXXX in a level's tree; a bare func_XXXXXXXX
        # there is the level's own label at that address (an assembly function of a file with C)
        self.front_end = {r[0] for r in rows if r[1] in ("frontbin", "boot_elf")}

    def expected(self, name):
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


def object_values(path, start, base, text, gp, c_starts=None):
    """(values, defined, exported) of one object placed at `start`, its C functions at
    `c_starts` (addresses, each running to the next function): Differ (offset from `start`) or
    ValueError when it cannot be."""
    obj = read_object(path)
    if obj["extra"]:
        raise ValueError("has data of its own (%s): constants, strings or a jump table; the level's "
                         "data comes from its assembly" % ", ".join(obj["extra"]))
    data = obj["text"]
    ranges = None
    if c_starts is not None:
        ranges = [(a - start, b - start) for a, b in c_starts]
    values = derive(data, text[start - base:start - base + len(data)], obj["relocs"], start, gp, ranges)
    return values, {n: start + v for n, v in obj["defined"].items()}, obj["exported"]


def level_values(t, rows=None):
    """({name: value}, [error]) for every name the level's C objects use."""
    import srcfiles as sf
    level = Level(t.level, rows)
    base, text = retail_text(t)
    workdir = os.path.join(ROOT, t.workdir(t.units[0]))
    values, where, errors, own, made = {}, {}, [], {}, set()
    for rel, start in sf.read_file_list(t.path("files")):
        src = open(os.path.join(ROOT, rel), errors="replace").read()
        if "localdecomp:start" not in src:
            continue
        obj = os.path.join(workdir, os.path.splitext(os.path.basename(rel))[0] + ".o")
        try:
            marks = [(int(m.group(2) or m.group(3), 16), bool(m.group(1))) for m in FUNCTION_MARK.finditer(src)]
            c_ranges = [(a, marks[i + 1][0] if i + 1 < len(marks) else 1 << 32)
                        for i, (a, is_c) in enumerate(marks) if is_c]
            vals, defined, exported = object_values(obj, start, base, text, t.gp, c_ranges)
        except Differ as e:
            a = start + e.offset
            name, f = level.function_at(a)
            errors.append("%s: %s (0x%08X), its word at +0x%X: %s" % (rel, name, f, a - f, e.why))
            continue
        except ValueError as e:
            errors.append("%s: %s" % (rel, e))
            continue
        for a in C_MARKER.findall(src):
            own["func_" + a] = int(a, 16)
        made |= exported
        for name in exported:
            value = defined[name]
            if values.setdefault(name, value) != value:
                errors.append("%s: %s is defined at 0x%08X and used at 0x%08X" % (rel, name, value, values[name]))
        for name, value in vals.items():
            if name.startswith("\u00a7"):
                if name != "\u00a7.text":
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
    for name, value in sorted(values.items()):
        want = level.expected(name)
        if want is not None and want != value:
            hint = ""
            if ADDRESS_NAME.match(name):
                hint = " (in level code, name what is not resident D_LNN_XXXXXXXX / func_LNN_XXXXXXXX)"
            errors.append("%s: %s is 0x%08X in level %02d, the code needs 0x%08X%s"
                          % (where.get(name, "?"), name, want, t.level, value, hint))
    values = {n: v for n, v in values.items() if n not in made and not n.startswith("\u00a7")}
    values.update(own)
    return values, errors


def write(t):
    path = os.path.join(ROOT, t.build_dir, "symbol_addrs_derived.txt")
    values, errors = level_values(t)
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
