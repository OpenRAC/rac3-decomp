"""The executables this repo decompiles, and where each one's files live.

Every tool works on one target at a time. The target comes from, in order:
  * a `--target NAME` option (tools strip it from sys.argv with from_argv());
  * the UYA_TARGET environment variable;
  * frontbin, the default, so existing commands behave exactly as before.

A target has one source-file list and one flags file (text_parts) covering all
of its code. Its code can sit in several sections ("units"): boot_elf has the
engine core (core.text) and the front-end overlay (.text). A unit is an address
range; each unit's files build into one object, and each unit gets its own
place in the linker script. Address ranges of different units never overlap,
so every by-address lookup (file_for_address, flags_for) works on the whole
target.

Function names are func_<address>, so two targets can both have a
func_00381180 that are unrelated functions. Anything keyed by function name
(divs_nops, sq_ra_funcs, localdecomp_flags, symbol files) is per target.

Every program's tables (source-file list, flags, symbols, ...) are in
config/<program>/ and its splat configuration in config/splat/<program>.yaml.
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

class Unit:
    def __init__(self, name, start, end, src_dir, asm_dir, section, objdir=None):
        self.name = name          # "text", "core"
        self.objdir = objdir or name  # folder under <build>/src/ for its per-file objects
        self.start = start        # first address of the code section
        self.end = end            # one past its last byte
        self.src_dir = src_dir    # where its .c files live (relative to ROOT)
        self.asm_dir = asm_dir    # INCLUDE_ASM folder for its functions
        self.section = section    # section name in the ELF (".text", "core.text")

    def contains(self, addr):
        return self.start <= addr < self.end


class Target:
    def __init__(self, name, **kw):
        self.name = name
        self.__dict__.update(kw)

    def path(self, attr):
        return os.path.join(ROOT, getattr(self, attr))

    def unit_for(self, addr):
        for u in self.units:
            if u.contains(addr):
                return u
        return None

    def unit(self, name):
        for u in self.units:
            if u.name == name:
                return u
        raise KeyError(f"{self.name} has no unit {name!r} (units: {', '.join(u.name for u in self.units)})")

    def obj(self, unit):
        """The relocatable object build_text.py links one unit's files into."""
        return os.path.join(self.build_dir, "src", unit.name + ".c.o")

    def workdir(self, unit):
        """Where build_text.py puts one unit's per-file objects (objdiff reads them)."""
        return os.path.join(self.build_dir, "src", unit.objdir)

    def objdiff_prefix(self, unit):
        return self.objdiff_units[unit.name]

    def objdiff_dir(self, unit):
        """Folder under build/objdiff/{target,base}/ for one unit's per-file objects."""
        return self.objdiff_dirs[unit.name]


TARGETS = {
    "frontbin": Target(
        "frontbin",
        elf="baserom/frontbin.elf",
        sha1="5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553",
        yaml="config/splat/frontbin.yaml",
        ld="linker_scripts/frontbin.ld",
        build_dir="build",
        bin_name="frontbin.bin",
        files="config/frontbin/src_files.txt",
        parts="config/frontbin/text_parts.txt",
        divs_nops="config/frontbin/divs_nops.txt",
        sq_ra_funcs="config/frontbin/sq_ra_funcs.txt",
        localdecomp_flags="config/frontbin/localdecomp_flags.txt",
        symbol_addrs="config/frontbin/symbol_addrs.txt",
        symbols_resolved="config/frontbin/symbol_addrs_resolved.txt",
        asm_root="asm",
        handwritten="asm/handwritten",
        remnants="asm/remnants",
        gp=0x1DC8B0,
        units=[Unit("text", 0x381080, 0x3F256C, "src/frontbin", "asm/nonmatchings/text", ".text", objdir="frontbin")],
        # objdiff: unit name prefix, object folder under build/objdiff/{target,base}/
        # and progress categories, per code section (tools/objdiff/gen_objdiff_units.py)
        objdiff_units={"text": "frontbin/src/"},
        objdiff_dirs={"text": "frontbin"},
        objdiff_categories={"text": ["menu", "frontend"]},
        # raw byte ranges of the file that aren't code or data: (asm name, start, end)
        raw_blobs=[("header", 0x0, 0x1000)],
        splat_src="src",
        # data segments holding switch jump tables: {segment: unit that uses them}
        jtbl_segments={"data": "text"},
        base_flags="-O2 -G8 -fopt-stack -mno-check-zero-division",
        label="frontbin (front end)",
    ),
    # boot_elf.elf: the engine core (core.text) plus a front-end overlay
    # (.text) that is frontbin's code linked at other addresses.
    "boot_elf": Target(
        "boot_elf",
        elf="baserom/boot_elf.elf",
        sha1="e0a4e82e9a363a64db5a555db8c8f927ef58c3d8",
        yaml="config/splat/boot_elf.yaml",
        ld="linker_scripts/boot_elf.ld",
        build_dir="build/boot_elf",
        bin_name="boot_elf.bin",
        files="config/boot_elf/src_files.txt",
        parts="config/boot_elf/text_parts.txt",
        divs_nops="config/boot_elf/divs_nops.txt",
        sq_ra_funcs="config/boot_elf/sq_ra_funcs.txt",
        localdecomp_flags="config/boot_elf/localdecomp_flags.txt",
        symbol_addrs="config/boot_elf/symbol_addrs.txt",
        symbols_resolved="config/boot_elf/symbol_addrs_resolved.txt",
        asm_root="asm/boot_elf",
        handwritten="asm/boot_elf/handwritten",
        remnants="asm/boot_elf/remnants",
        gp=0x1DC8B0,
        units=[
            Unit("core", 0x116F80, 0x13D420, "src/boot_elf/core", "asm/boot_elf/nonmatchings/core", "core.text"),
            Unit("text", 0x381080, 0x3F2778, "src/boot_elf/text", "asm/boot_elf/nonmatchings/text", ".text"),
        ],
        objdiff_units={"core": "boot_elf/core/", "text": "boot_elf/text/"},
        objdiff_dirs={"core": "boot_elf/core", "text": "boot_elf/text"},
        objdiff_categories={"core": ["menu", "executables", "boot_elf", "boot_elf_core"],
                            "text": ["menu", "executables", "boot_elf", "boot_elf_frontend"]},
        # objdiff.json units this target's per-file units replace (the old
        # reference-only unit for the whole code)
        objdiff_replaces=["exes/boot_elf"],
        # 0x0..0x2000: ELF header, program headers and .reginfo; 0x35EA98..: .shstrtab
        # and the section header table
        raw_blobs=[("header", 0x0, 0x2000), ("trailer", 0x35EA98, 0x35EE64)],
        splat_src="src/boot_elf",
        # core.rdata isn't split: its jump tables sit between each source file's
        # other read-only data (strings, constants), so splitting it means giving
        # every piece to its file. Needed once a core switch function becomes C.
        jtbl_segments={"data": "text"},
        base_flags="-O2 -G8 -fopt-stack -mno-check-zero-division",
        label="boot_elf (engine core + boot front end)",
    ),
    # i5bootn.elf: the bootstrap launcher the disc boots first. Its startup code,
    # a small loader and Sony's libkernl; .rodata is mostly the payload it loads.
    # Nothing touches $gp (gp 0: no small data), so its code was built with -G0.
    "i5bootn": Target(
        "i5bootn",
        elf="baserom/i5bootn.elf",
        sha1="c1166658edad1b6b04b7671af77fff53f2560e71",
        yaml="config/splat/i5bootn.yaml",
        ld="linker_scripts/i5bootn.ld",
        build_dir="build/i5bootn",
        bin_name="i5bootn.bin",
        files="config/i5bootn/src_files.txt",
        parts="config/i5bootn/text_parts.txt",
        divs_nops="config/i5bootn/divs_nops.txt",
        sq_ra_funcs="config/i5bootn/sq_ra_funcs.txt",
        localdecomp_flags="config/i5bootn/localdecomp_flags.txt",
        symbol_addrs="config/i5bootn/symbol_addrs.txt",
        symbols_resolved="config/i5bootn/symbol_addrs_resolved.txt",
        asm_root="asm/i5bootn",
        handwritten="asm/i5bootn/handwritten",
        remnants="asm/i5bootn/remnants",
        gp=0,
        # flags tools/bootstrap_target.py gives a new file (estimates until C matches)
        base_flags="-O2 -G0 -fopt-stack -mno-check-zero-division",
        units=[Unit("text", 0x800000, 0x804FD8, "src/i5bootn", "asm/i5bootn/nonmatchings/text", ".text", objdir="i5bootn")],
        objdiff_units={"text": "i5bootn/src/"},
        objdiff_dirs={"text": "i5bootn"},
        objdiff_categories={"text": ["menu", "executables", "i5bootn"]},
        objdiff_replaces=["exes/i5bootn"],
        # 0x0..0x1000: ELF and program headers; 0xC5CCC..: .reginfo, .shstrtab and
        # the section header table
        raw_blobs=[("header", 0x0, 0x1000), ("trailer", 0xC5CCC, 0xC5E90)],
        splat_src="src/i5bootn",
        # .rodata starts with the code's read-only data (one jump table) and then
        # holds the payload
        jtbl_segments={"rodata": "text"},
        # ...and the read-only data of the functions just before the switch's
        # function starts at 0x805A90 (func_008015A0's strings and double
        # literals, then func_00801778's digit strings): cut out with the jump
        # table so it can come from src/i5bootn/8010A8.c (tools/setup_asm.py)
        rodata_cut={"rodata": 0x805A90},
        # flat binary from tools/elf2bin.py: SN's ee-objcopy corrupts 21 bytes of
        # this file's section-name table (see tools/elf2bin.py)
        flatten="elf2bin",
        label="i5bootn (bootstrap launcher)",
    ),
}



def _levels():
    """The 49 level programs (tools/levels.py, docs/levels.md), one target each, named level_NN.
    Their tables come from config/levels/levels.tsv; everything a level's build reads besides
    that (its source tree, file list, flags, symbols) is made under build/levels/<NN_name>/ from
    src/levels/ and config/levels/functions.tsv by `tools/levels.py tree`."""
    out = {}
    table = os.path.join(ROOT, "config", "levels", "levels.tsv")
    if not os.path.exists(table):
        return out
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import levels
    for row in levels.read_table(table):
        d, n = row["dir"], row["number"]
        b = "build/levels/" + d
        _, text, size, _ = row["sections"][-1]
        trailer = levels.trailer_start(row)
        out[levels.target_name(n)] = Target(
            levels.target_name(n), level=n, level_dir=d,
            elf="baserom/levels/%s.elf" % d, sha1=row["elf_sha1"], overlay_sha1=row["overlay_sha1"],
            yaml="config/splat/levels/%s.yaml" % d, ld="linker_scripts/levels/%s.ld" % d,
            build_dir=b, bin_name=d + ".bin",
            files=b + "/src_files.txt", parts=b + "/text_parts.txt", divs_nops=b + "/divs_nops.txt",
            sq_ra_funcs=b + "/sq_ra_funcs.txt", localdecomp_flags=b + "/localdecomp_flags.txt",
            symbol_addrs=b + "/symbol_addrs.txt", symbols_resolved=b + "/symbol_addrs_resolved.txt",
            asm_root="asm/levels/" + d, handwritten="asm/levels/%s/handwritten" % d,
            remnants="asm/levels/%s/remnants" % d, gp=0x1DC8B0,
            units=[Unit("text", text, text + size, b + "/src", "asm/levels/%s/nonmatchings/text" % d, ".text", objdir=d)],
            objdiff_units={"text": "levels/%s/" % d}, objdiff_dirs={"text": "levels/" + d},
            objdiff_categories={"text": ["level_code", "level_%02d" % n]},
            raw_blobs=[("header", 0x0, 0x1000), ("trailer", trailer, row["elf_size"])],
            splat_src=b + "/src", jtbl_segments={},
            base_flags="-O2 -G8 -fopt-stack -mno-check-zero-division",
            label=levels.title(n))
    return out


# the level programs, apart from TARGETS (the three core programs) so that every loop over the
# core programs stays as it is; get() and from_argv() take either
LEVELS = _levels()
ALL = dict(TARGETS, **LEVELS)

DEFAULT = "frontbin"


def get(name=None):
    name = name or os.environ.get("UYA_TARGET") or DEFAULT
    if name not in ALL:
        sys.exit(f"unknown target {name!r}; known: {', '.join(TARGETS)}, level_NN ({', '.join(LEVELS)})")
    return ALL[name]


def is_set_up(t):
    """True when the target's retail ELF and asm folders are in the repo
    (tools/setup_asm.py --target NAME has been run)."""
    return os.path.exists(t.path("elf")) and all(os.path.isdir(os.path.join(ROOT, u.asm_dir)) for u in t.units)


def run_for_all(argv, elf_only=False):
    """`--target all`: run this same command once per target that is set up and
    exit with the worst exit code. Targets that aren't set up are skipped (with
    elf_only, only the retail ELF has to be there: setup_asm.py makes the rest)."""
    import subprocess
    worst = 0
    for t in TARGETS.values():
        print("=== %s ===" % t.name, flush=True)
        if not (os.path.exists(t.path("elf")) if elf_only else is_set_up(t)):
            print("skipped: %s or its asm/ folder is missing (python tools/setup_asm.py --target %s)"
                  % (t.elf, t.name), flush=True)
            continue
        env = dict(os.environ, UYA_TARGET=t.name)
        r = subprocess.run([sys.executable, argv[0], "--target", t.name] + argv[1:], env=env)
        worst = max(worst, r.returncode)
    sys.exit(worst)


def from_argv(argv=None, allow_all=False):
    """Take `--target NAME` / `--target=NAME` out of argv (sys.argv by default),
    set UYA_TARGET for any tool this one runs, and return the Target.

    With allow_all, `--target all` reruns the tool once per target (run_for_all)
    and doesn't return; allow_all="elf" only needs each target's ELF."""
    argv = sys.argv if argv is None else argv
    name = None
    i = 1
    while i < len(argv):
        a = argv[i]
        if a == "--target" and i + 1 < len(argv):
            name = argv[i + 1]
            del argv[i:i + 2]
            continue
        if a.startswith("--target="):
            name = a.split("=", 1)[1]
            del argv[i]
            continue
        i += 1
    if name == "all":
        if not allow_all:
            sys.exit("--target all isn't supported by this tool; name one of: %s" % ", ".join(TARGETS))
        run_for_all(argv, elf_only=(allow_all == "elf"))
    t = get(name)
    os.environ["UYA_TARGET"] = t.name
    return t


def for_function_address(addr):
    """Every target whose code contains `addr` (names are only unique per target)."""
    return [t for t in TARGETS.values() if t.unit_for(addr)]


def is_level(t):
    return getattr(t, "level", None) is not None
