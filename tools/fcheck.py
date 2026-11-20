#!/usr/bin/env python3
"""fcheck.py: does C do what the retail function does? A check by behaviour, for the native port.

The C need not match a byte (that is tools/check.py's job), only leave the same memory, result
and kept registers as retail from real calls of the game, captured headless in OpenRAC's
test-only interpreter (tools/interpreter there; never part of the port, the launcher or a
release, and never used to play).

    python3 tools/fcheck.py check NAME [CANDIDATE.c] [--program boot_elf|frontbin] [--retail] [--ulps N] [--keep DIR]
    python3 tools/fcheck.py gate [NAME ...] [--write] [--jobs N] [--shard K/N] [--only RE] [--out FILE]
    python3 tools/fcheck.py merge FILE ...
    python3 tools/fcheck.py capture [NAME ...] [--program P] [--script menu|title|all] [--list FILE] [--force]
    python3 tools/fcheck.py reach [--script menu] [--out FILE]
    python3 tools/fcheck.py scripts

`check` compiles CANDIDATE.c (a function and what it needs; by default NAME's C in src/) in its
source file's context with that file's flags, through tools/check.py (which also says how far
it is from a byte match), places its code in the kernel's area at 0x000A0000 and runs OpenRAC's
`openrac-fcheck` on NAME's captured call states. When the file's declarations clash with the
candidate's it is compiled on its own; when it reads a float constant or a small variable that
$gp cannot reach in retail's program, again with -G0 (other code, the same deeds). From each state retail runs, then the
candidate, on a fresh machine; compared are main memory (but the dead stack), the scratchpad,
the result by the return type, the registers a function keeps, the order of device accesses
and system calls, and, at each call the function makes, where it goes and the memory written
so far (a store retail makes in a call's delay slot must be made before the call). A NaN or
infinity the candidate writes where retail has a number is named as such.

The verdict always says how much of retail's code the states ran: its basic blocks run of all
and which were not run. Rows whose states left blocks unrun are `same-partial`, not `same`: on
Going Commando the calls a capture held ran only 53% of the gated rows' bytes, and reading the
unrun blocks found one slip in seven. Read those blocks against retail's instructions; when they
agree, list them in a comment of the C, `fcheck-read: 0012F0F8-0012F104,...` (the ranges as the
verdict prints them), and the row becomes `same-read`. A new state that runs other blocks, or
an edit, brings it back to `same-partial` until those are read too.

Names are resolved by symbol, never by position: each relocation of the candidate takes the
address its name has (config/<program>/symbol_addrs_resolved.txt, the address in a
D_/func_/jtbl_ name, an sda alias under $gp), and a name with none stops the build ("LINK").
The verdict also lists the data addresses the candidate's code forms that retail's never does
(`refs`): a wrong D_ name shows there even in a block no state ran.

Programs. The states are of the boot program (boot_elf: the core and its copy of the front
end), which runs the boot, the title and the main menu; frontbin, the front end loaded later,
is never in memory then. A frontbin function is compiled as frontbin's and checked at its
boot_elf twin (config/frontend_pairs.tsv: the same code at another address): the addresses of
front-end code it reaches are moved to their twins', data stays (the two programs' data have
the same addresses and sizes). The two programs share many names for different code, so the
table's `program` column (or --program) says whose a name is.

Levels. A level function (its catalogue name func_LNN_XXXXXXXX, config/levels/functions.tsv) is
checked at every level whose states hold calls of it (states/levelNN/NAME.k.snap), at its place
there: built for that level as tools/check.py --target level_NN builds it (the level's flags
and its src/levels/ file's context), its names read as that level has them, as the decomp's
level tooling does (tools/level_symbols.py: catalogue names at their places, fe_ names at the
level's copy of the front end, sda names under the level's $gp, address names; core names as
boot_elf has them). A name of another level (D_L01_ in level 05) is moved by what the
function's retail code forms at its places in the two levels; a level where some name cannot
be moved is left out. The verdict is the worst of the levels', the blocks run those any of
them ran; unrun blocks are named in the home level's addresses.

`gate` checks every row of nonmatching/functional.tsv (or the NAMEs) and with --write puts each
verdict in the table's `gate` column, the rest of the table untouched: `same 4/4 blocks, 2/2
states`, `same-partial 5/17 blocks, 12/12 states (unrun: ...)`, `same-read ... (unrun read:
...)`, `differs ...`, `no-states: ...`, `build: ...`, and `; refs not in retail: ...` when the C
forms data addresses retail's code does not. Done is `same` or `same-read`. --jobs N checks N
rows at once; --shard K/N takes every N-th row from the K-th, for spreading the table over
machines; --out FILE appends `name, program, verdict` lines instead of writing the table, and
`merge` puts such files in the table (the last line of a row wins, but no-states never
replaces a verdict with states).

`capture` plays the PAL disc (baserom/SCES_524.56.iso) headless (`openrac-boot --capture`,
no window, no memory card) and writes call states of NAME's (default: every row of
nonmatching/functional.tsv) into $RAC3_FCHECK_STATES (default
~/Projects/RAC/OpenRAC/build/fcheck/rac3-pal/states). Scripts (SCRIPTS): `title` (the boot to
the main menu), `menu` (the main menu's pages), `levelNN` (New Game into story level NN, then
played: LEVEL_SCRIPT; levels other than 01 are reached by keeping entry 01 of the disc's level
table, in memory, as level NN's). Each run is cut into phases and takes the calls numbered 1 and
2 of each phase (in a level, one), so a function called every frame has states from each part
of the run. A function a run never calls gets a NAME.none marker. A state is the whole machine
(about 5 MB compressed at the menu, 13-18 MB in a level). A level run takes the level functions
with a place in it and the resident core's boot_elf functions. $RAC3_FCHECK_BOOT_ARGS adds
openrac-boot options (--one-thread, for many runs at once).

`reach` counts, for every boot_elf function (in a level's run: every level function with a place
there and the core's), how often a script's run calls it (no states): which functions the gate
can check at all, and in which levels, before capturing (level states are large).

Exit status of `check`: 0 same, same-read or same-partial, 1 differs, 2 the candidate did not build
or place, 3 no states, 4 every state skipped.

Needs: OpenRAC's interpreter (cmake -S tools/interpreter -B build/interpreter in OpenRAC;
$OPENRAC_ROOT, default ~/Projects/RAC/OpenRAC), the toolchain tools/check.py uses
(UYA_TOOLCHAIN, UYA_RUNNER, UYA_EE29; without UYA_EEAS an @eeas file is assembled with the
default assembler, which changes no behaviour), asm/ from tools/setup_asm.py, and the disc.
"""
import argparse
import datetime
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import zlib
from functools import lru_cache

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.environ["UYA_TARGET"] = "boot_elf"  # the states are of boot_elf (see above)

OPENRAC = os.environ.get("OPENRAC_ROOT", os.path.expanduser("~/Projects/RAC/OpenRAC"))
BOOT = os.path.join(OPENRAC, "build/interpreter/openrac-boot")
FCHECK = os.path.join(OPENRAC, "build/interpreter/openrac-fcheck")
HOOKS = os.path.join(OPENRAC, "tools/interpreter/games/SCES_524.56.hooks")
DISC = os.path.join(ROOT, "baserom/SCES_524.56.iso")
TABLE = os.path.join(ROOT, "nonmatching/functional.tsv")
PAIRS = os.path.join(ROOT, "config/frontend_pairs.tsv")
BASE = 0x000A0000   # where the candidate goes: the kernel's area, which the game does not use
LIMIT = 0x000F0000
STATES_PER_PHASE = 2

# Pad bits: Select 1, Start 8, Up 10, Right 20, Down 40, Left 80, L2 100, R2 200, L1 400, R1 800,
# Triangle 1000, Circle 2000, Cross 4000, Square 8000.
# The boot (no memory card: "Continue anyway? Press any button"), the logos and the title to the
# main menu (Load Game selected), shown from about field 640.
TO_MENU = ["300:4000:10"]
SCRIPTS = {
    "title": {"frames": 900, "phases": [0, 300, 640], "presses": TO_MENU},
    # The main menu's pages, each backed out of: down through New Game, Multiplayer, Multiplayer
    # Tutorial to Options; Options opened, moved through and changed; back up to Load Game
    # (no card); New Game's question.
    "menu": {"frames": 2600, "phases": [0, 640, 1000, 1700],
             "presses": TO_MENU + ["720:40:8", "780:40:8", "840:40:8", "900:40:8", "1000:4000:8",
                                   "1080:40:8", "1140:40:8", "1200:20:8", "1260:80:8", "1320:40:8",
                                   "1380:4000:8", "1460:1000:8", "1540:1000:8", "1620:10:8",
                                   "1680:10:8", "1740:10:8", "1800:10:8", "1860:4000:8", "1980:1000:8",
                                   "2060:40:8", "2120:4000:8", "2240:1000:8", "2320:1000:8"]},
}


def play(start, end, seed=0):
    """Presses and left-stick holds (openrac-boot's --press, --stick) that play a level from START
    to END: cycles of running forward (the stick up for 200 fields) with a jump, a swing of the
    wrench (Square) and a second jump, then turning right, left or back for 60 fields with another
    swing and a shot (R1). A SEED other than 0 ($RAC3_FCHECK_PLAY_SEED) takes another walk: the
    run's length, the turn and its length drawn from it, and the weapon quick-selected (Triangle,
    then a direction) now and then, so a second run reaches other parts of a level."""
    import random
    rng = random.Random(seed)
    presses, sticks = [], []
    f, k = start, 0
    while f < end:
        run = 200 if not seed else rng.choice([120, 200, 300, 400])
        sticks.append(f"{f}:80:00:{run}")
        presses += [f"{f + 60}:4000:8", f"{f + 120}:8000:8", f"{f + 170}:4000:8"]
        turn = ['ff:80', '00:80', '80:ff'][k % 3] if not seed else rng.choice(['ff:80', '00:80', '80:ff', 'ff:00', '00:00'])
        sticks.append(f"{f + run}:{turn}:{60 if not seed else rng.choice([30, 60, 100])}")
        presses += [f"{f + run + 30}:8000:8", f"{f + run + 70}:800:20"]
        if seed and rng.random() < 0.2:
            presses += [f"{f + run + 100}:1000:30", f"{f + run + 110}:{rng.choice(['10', '20', '40', '80'])}:8"]
        f, k = f + run + 100 + (30 if seed else 0), k + 1
    return ([x for x in presses if int(x.split(":")[0]) < end],
            [x for x in sticks if int(x.split(":")[0]) < end])


# New Game from the main menu: Down to New Game, Cross, and Cross through the questions (no card:
# continue anyway); the first level (01, Veldin) loads by about field 1450 and runs at about 30
# fields a second in the interpreter. Its opening is skipped with Cross every 100 fields from 1500
# (Start at 1650 and 2050, Triangle backing out of the pause menu), then
# it is played (play()) to the end, with the pause menu (Start, Down, Triangle back) at 4200,
# the quick select (Triangle) at 4800 and the map (Select) at 5400. Phases: the load (from 1200,
# before any level's program is in: the CRC guard keeps the boot's code at a place out; a level's
# setup runs once, from about 1300), the play, and its second half.
NEW_GAME = ["720:40:8", "800:4000:8", "900:4000:8", "1000:4000:8", "1100:4000:8", "1200:4000:8"]
LEVEL_PLAY = play(2500, 7000)
LEVEL_SCRIPT = {
    "frames": 7000, "phases": [1200, 3000, 5000], "per_phase": 1,
    "presses": TO_MENU + NEW_GAME + [f"{f}:4000:8" for f in range(1500, 2500, 100)]
    + ["1650:8:8", "1700:1000:8", "2050:8:8", "2100:1000:8"] + LEVEL_PLAY[0]
    + ["4200:8:8", "4260:40:8", "4320:1000:8", "4400:1000:8", "4800:1000:8", "4860:1000:8",
       "5400:1:8", "5500:1:8"],
    "sticks": LEVEL_PLAY[1],
}
# Every other story level is reached the same way: New Game loads level 01 through entry 01 of the
# level table in the disc's table of contents, which the boot reads to 0x160C40 (sector 1001; the
# level table at +0x7400, 24 bytes a level: three (sector, size) pairs, tools/levels.py); entry 01
# kept as level NN's from field 100 on makes New Game load level NN's files. The level's program
# then runs as if New Game had started there.
TOC_RAM = 0x160C40
LEVEL_TABLE = 0x7400


def play_style(style, s, seed=0):
    """Other ways of playing a level ($RAC3_FCHECK_PLAY_STYLE), for code the walk never runs:
    `idle` (New Game, then no input: the opening plays out, the hero stands), `watch` (the opening
    not skipped, the walk from 4000), `mash` (every button and the d-pad at random, SEED's draw,
    with the left stick walking)."""
    import random
    base = TO_MENU + NEW_GAME
    if style == "idle":
        return {"presses": base, "sticks": []}
    if style == "watch":
        walk = play(4000, s["frames"], seed)
        return {"presses": base + walk[0], "sticks": walk[1]}
    if style == "mash":
        rng = random.Random(seed or 1)
        presses, sticks = list(base) + [f"{f}:4000:8" for f in range(1500, 2500, 100)], []
        for f in range(2500, s["frames"], 40):
            presses.append(f"{f}:{rng.choice(['1', '8', '10', '20', '40', '80', '100', '200', '400', '800', '1000', '2000', '4000', '8000', '4000', '8000', '200', '800'])}:{rng.choice([4, 8, 30, 60])}")
            if (f - 2500) % 120 == 0:
                sticks.append(f"{f}:{rng.choice(['80:00', '00:80', 'ff:80', '80:ff', '00:00', 'ff:ff'])}:{rng.choice([60, 120])}")
        return {"presses": presses, "sticks": sticks}
    raise SystemExit(f"unknown RAC3_FCHECK_PLAY_STYLE {style!r} (idle, watch, mash)")


def level_script(level):
    s = dict(LEVEL_SCRIPT, level=level)
    seed = int(os.environ.get("RAC3_FCHECK_PLAY_SEED", "0"))
    if seed:
        walk = play(2500, s["frames"], seed)
        keep = [p for p in s["presses"] if p not in LEVEL_PLAY[0]]
        s.update(presses=keep + walk[0], sticks=walk[1])
    style = os.environ.get("RAC3_FCHECK_PLAY_STYLE", "")
    if style:
        s.update(play_style(style, s, seed))
    longer = int(os.environ.get("RAC3_FCHECK_LEVEL_FRAMES", "0"))
    if longer > s["frames"]:
        # $RAC3_FCHECK_LEVEL_FRAMES: the same play, kept up to that field
        more = play(s["frames"], longer)
        s.update(frames=longer, presses=s["presses"] + more[0], sticks=s["sticks"] + more[1])
    if level != 1:
        with open(DISC, "rb") as f:
            f.seek(1001 * 0x800 + LEVEL_TABLE + 24 * level)
            entry = struct.unpack("<6I", f.read(24))
        s["writes"] = [f"100:{TOC_RAM + LEVEL_TABLE + 24 + 4 * k:x}:{v:x}:{s['frames']}" for k, v in enumerate(entry)]
    return s


STORY_LEVELS = [n for n in list(range(1, 15)) + list(range(16, 25)) + list(range(26, 37))]
for _n in STORY_LEVELS:
    SCRIPTS[f"level{_n:02d}"] = None   # made when used (level_script reads the disc)


def script_of(name):
    return SCRIPTS[name] or level_script(int(name[5:]))


class Link(Exception):
    """The candidate cannot be built or placed."""


def states_root():
    return os.environ.get("RAC3_FCHECK_STATES") or os.path.join(OPENRAC, "build/fcheck/rac3-pal/states")


# --- functions and programs ---------------------------------------------------------------

@lru_cache(maxsize=None)
def functions(program):
    """Name -> (address, size, kind) of PROGRAM's functions, from asm/ (kind "c", "handwritten" or
    "remnant", a linker remnant)."""
    import targets
    t = targets.ALL[program]
    out = {}
    dirs = [(u.asm_dir, "c") for u in t.units] + [(t.handwritten, "handwritten"), (t.remnants, "remnant")]
    for d, kind in dirs:
        p = os.path.join(ROOT, d)
        if not os.path.isdir(p):
            continue
        for f in os.listdir(p):
            m = re.fullmatch(r"(func_([0-9A-F]{8}))\.s", f)
            if not m:
                continue
            text = open(os.path.join(p, f), errors="ignore").read()
            s = re.search(r"nonmatching \w+, (0x[0-9A-Fa-f]+)", text)
            if s:
                out[m.group(1)] = (int(m.group(2), 16), int(s.group(1), 16), kind)
    return out


@lru_cache(maxsize=None)
def pairs():
    """frontbin name -> its boot_elf twin."""
    out = {}
    for line in open(PAIRS):
        f = line.split("#", 1)[0].split()
        if len(f) >= 2:
            out[f[1]] = f[0]
    return out


@lru_cache(maxsize=None)
def retail_image(program):
    import check
    import targets
    return check.Retail(targets.ALL[program].path("elf"))


def retail_bytes(address, size):
    return retail_image("boot_elf").read(address, size)


def place_of(name, program=None):
    """(program, twin) where NAME of PROGRAM is checked: a boot_elf function as itself, a frontbin
    one at its boot_elf twin. The two programs share many names for different code (both front
    ends start at 0x381080), so PROGRAM decides; without it boot_elf's comes first."""
    if program not in (None, "boot_elf", "frontbin"):
        raise Link(f"LINK {name}: {program} has no states yet (only boot_elf and frontbin)")
    if program != "frontbin" and name in functions("boot_elf"):
        return "boot_elf", name
    if program != "boot_elf" and name in functions("frontbin"):
        twin = pairs().get(name)
        if twin is None:
            raise Link(f"LINK {name}: a frontbin function without a boot_elf twin (config/frontend_pairs.tsv)")
        return "frontbin", twin
    raise Link(f"LINK {name}: not a boot_elf or frontbin function")


# --- levels -----------------------------------------------------------------------------------

LEVEL_NAME = re.compile(r"^func_L(\d\d)_([0-9A-F]{8})$")
LEVEL_BASE = 0x1D5680   # a level's program (its .lit first) replaces memory from here; the core below stays


@lru_cache(maxsize=None)
def catalogue():
    """Catalogue name -> (size, {level: address}) of the level functions (config/levels/functions.tsv)."""
    import level_catalogue as lc
    import version
    return {r[0]: (r[2], dict(r[5])) for r in lc.read_catalogue(version.cfg("levels", "functions.tsv", v="pal"))}


@lru_cache(maxsize=None)
def level_image(level):
    """[(address, bytes)] of level LEVEL's program sections (.lit first, .text last)."""
    import levels
    _, secs = levels.read_elf(open(levels.elf_path(level), "rb").read())
    return [(a, data) for a, n, kind, data in secs if kind != 8]   # SHT_NOBITS: the .bss


def level_bytes(level, address, size):
    for a, data in level_image(level):
        if a <= address and address + size <= a + len(data):
            return data[address - a:address - a + size]
    raise Link(f"LINK: level {level:02d} has no bytes at {address:08X}")


@lru_cache(maxsize=None)
def level_gp(level):
    import gp as gpmod
    import levels
    return gpmod.gp_of(levels.target_name(level))


FRONTBIN_TEXT = (0x381080, 0x3F256C)


@lru_cache(maxsize=None)
def twin_addresses():
    """frontbin function address -> its boot_elf twin's address."""
    fb, be = functions("frontbin"), functions("boot_elf")
    return {fb[f][0]: be[b][0] for f, b in pairs().items() if f in fb and b in be}


def to_boot(address, what):
    """An address of frontbin's as boot_elf has it: front-end code moves to its twin, data stays
    (the two programs' data sections have the same addresses and sizes)."""
    if not FRONTBIN_TEXT[0] <= address < FRONTBIN_TEXT[1]:
        return address
    twin = twin_addresses().get(address)
    if twin is None:
        raise Link(f"LINK {what}: frontbin code at {address:08X} has no boot_elf twin (config/frontend_pairs.tsv)")
    return twin


@lru_cache(maxsize=None)
def source_of(program, name):
    """The src/ file whose INCLUDE_ASM or C definition is NAME's."""
    import targets
    t = targets.ALL[program]
    for u in t.units:
        d = os.path.join(ROOT, u.src_dir)
        for f in sorted(os.listdir(d)):
            if f.endswith(".c"):
                text = open(os.path.join(d, f), errors="ignore").read()
                if re.search(r"\b%s\b" % name, text) and (
                        re.search(r'(INCLUDE_ASM|ASM_FUNC)\("[^"]*",\s*%s\)' % name, text)
                        or re.search(r"^[^\n;]*\b%s\s*\([^;]*\)\s*\{" % name, text, re.M)):
                    return os.path.join(d, f)
    return None


def own_c(program, name):
    """NAME's C in src/ (between its localdecomp markers), or None when it is still INCLUDE_ASM."""
    path = source_of(program, name)
    if path is None:
        return None
    text = open(path).read()
    m = re.search(r"/\* localdecomp:start %s \*/\n(.*?)/\* localdecomp:end %s \*/" % (name, name), text, re.S)
    return m.group(1) if m else None


RETURN = re.compile(r"^\s*(?:static\s+)?(?:inline\s+)?([A-Za-z_][\w\s\*]*?)\s*\b%s\s*\(", re.M)


def return_type(text, name):
    m = re.search(r"^\s*(?:static\s+)?([A-Za-z_][\w \t\*]*?)[\s\*]+%s\s*\([^;]*\)\s*\{" % name, text, re.M)
    if not m:
        return "int"
    t = m.group(0).split(name)[0]
    if "*" in t:
        return "int"
    t = " ".join(t.split())
    if re.search(r"\bvoid\b", t):
        return "void"
    if re.search(r"\b(float|f32)\b", t):
        return "float"
    if re.search(r"\b(s64|u64|long long|long64)\b", t):
        return "long"
    return "int"


# --- building and placing -------------------------------------------------------------------

def use_target(program):
    """Points tools/check.py's tables (flags, symbols) at PROGRAM."""
    import check
    os.environ["UYA_TARGET"] = program
    check.reset()
    return check


def compile_candidate(text, name, program, work, extra_flags=()):
    """Compiles TEXT (C defining NAME of PROGRAM) with NAME's file flags (and EXTRA_FLAGS after
    them) and context into WORK/cand.o through tools/check.py. Returns (object path, check.py's
    verdict line)."""
    src = os.path.join(work, "cand.c")
    obj = os.path.join(work, "cand.o")
    open(src, "w").write(text)
    if program.startswith("level_"):
        import level_tree
        flags = level_tree.function_context(name)[0] or []
    else:
        flags = use_target(program).flags_for(int(name[5:], 16))
    cmd = [sys.executable, os.path.join(ROOT, "tools/check.py"), src, name, "--target", program,
           "--keep-object", obj, "--quiet"]
    if extra_flags:
        cmd += ["--flags=" + " ".join(extra_flags)]
    if "@eeas" in flags and not os.environ.get("UYA_EEAS"):
        cmd += ["--as", "default"]
    out = ""
    # In its file's context first (as the build compiles it); when the file's declarations clash
    # with the candidate's (another program's twin file, a draft's own externs), on its own.
    errors = []
    for extra in ([], ["--no-context"]):
        if os.path.exists(obj):
            os.unlink(obj)
        p = subprocess.run(cmd + extra, capture_output=True, text=True, cwd=ROOT)
        out = p.stdout + p.stderr
        if os.path.exists(obj):
            break
        errors.append([l for l in out.splitlines() if re.search(r":\d+: ", l)][:6] or out.splitlines()[-3:])
    else:
        raise Link("BUILD in its file's context:\n  " + "\n  ".join(errors[0]) + "\nalone:\n  " + "\n  ".join(errors[1]))
    line = next((l for l in reversed(out.splitlines()) if l.startswith(name + ":")), "")
    return obj, (line.split(":", 1)[1].strip() if line else "?") + (" (alone)" if extra else "")


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


@lru_cache(maxsize=None)
def lit_region():
    """(address, bytes) of boot_elf's read-only literal pools within $gp's reach: core.lit, .lit."""
    from elftools.elf.elffile import ELFFile
    import targets
    e = ELFFile(open(targets.ALL["boot_elf"].path("elf"), "rb"))
    out = []
    for s in e.iter_sections():
        if s.name in ("core.lit", ".lit"):
            out.append((s["sh_addr"], s.data()))
    return out


@lru_cache(maxsize=None)
def level_lits(level):
    """A level's literal pools in $gp's reach: the core's (below LEVEL_BASE, which stays) and the
    level's own .lit."""
    return [(a, b) for a, b in lit_region() if a < LEVEL_BASE] + [level_image(level)[0]]


def find_literal(data, level=None):
    for address, blob in (lit_region() if level is None else level_lits(level)):
        k = blob.find(data)
        while k >= 0:
            if (address + k) % len(data) == 0:
                return address + k
            k = blob.find(data, k + 1)
    return None


def place(obj, name, program, notes, level=None, g0=False):
    """Lays the object's sections out from BASE and resolves its relocations by name, as PROGRAM
    has them and then as boot_elf does (to_boot); a level function's (LEVEL: the level it runs
    in) as that level has them (level_value). Returns (image bytes, entry address, the data
    addresses its code forms). G0: the object was built with -G0, whose assembler leaves a
    $gp-relative reference to a global (an extern the C puts in .sdata) holding its offset less the
    object's own $gp too, as it does for a local one; without -G0 such a reference holds the offset
    alone."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    import gp as gpmod
    check = use_target("boot_elf" if level is not None else program)
    twin = name
    GP = gpmod.gp_of("boot_elf") if level is None else level_gp(level)
    e = ELFFile(open(obj, "rb"))
    sections = list(e.iter_sections())
    # The object's own $gp (.reginfo's ri_gp_value): a $gp-relative relocation against a local
    # symbol (a section's, a static's) holds its offset less that value (the MIPS ELF ABI)
    reginfo = e.get_section_by_name(".reginfo")
    gp0 = struct.unpack_from("<I", reginfo.data(), 20)[0] if reginfo is not None else 0
    alloc = [(i, s) for i, s in enumerate(sections) if s["sh_flags"] & 2 and s["sh_size"]]
    at, where = BASE, {}
    # code first, then the read-only data, then the writable data (with a note), in the kernel area
    order = sorted(alloc, key=lambda x: (0 if x[1]["sh_flags"] & 4 else 1 if not x[1]["sh_flags"] & 1 else 2))
    image = bytearray()
    for i, s in order:
        if s.name.startswith((".lit4", ".lit8", ".lit")) and not s["sh_flags"] & 4:
            continue  # literals: used where retail's pool has the same bytes (below)
        align = max(s["sh_addralign"], 4)
        at = (at + align - 1) & ~(align - 1)
        where[i] = at
        if s["sh_flags"] & 1:
            notes.append(f"{s.name} of the candidate placed at {at:08x} in the kernel area, not where retail has it")
        data = s.data() if s["sh_type"] != "SHT_NOBITS" else bytes(s["sh_size"])
        image += bytes(at - BASE - len(image)) + data
        at += s["sh_size"]
    if at > LIMIT:
        raise Link(f"LINK {twin}: the candidate is too large for the kernel area")
    symtab = e.get_section_by_name(".symtab")
    syms = list(symtab.iter_symbols())

    entry = None
    for s in syms:
        if s.name == twin and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS") and s["st_shndx"] in where:
            entry = where[s["st_shndx"]] + s["st_value"]
    if entry is None:
        raise Link(f"LINK {twin}: the candidate does not define it")

    def literal(sec_index, offset, size):
        sec = sections[sec_index]
        data = sec.data()[offset:offset + size] if sec["sh_type"] != "SHT_NOBITS" else b""
        if len(data) != size:
            raise Link(f"LINK {twin}: a $gp-relative reference to {sec.name}+{offset:#x}, which is not a "
                       f"literal: the candidate's own small data has no place in $gp's reach")
        a = find_literal(data, level)
        if a is None:
            where = "boot_elf's" if level is None else f"level {level:02d}'s and the core's"
            raise Link(f"LINK {twin}: a literal {data.hex()} of {sec.name} that {where} .lit has not")
        return a

    def value(sym):
        """The address of a relocation's symbol: by name, or a section's placed address."""
        shndx = sym["st_shndx"]
        if sym["st_info"]["type"] == "STT_SECTION":
            if shndx in where:
                return where[shndx]
            return None  # a literal section: resolved by its contents
        if sym.name and shndx not in ("SHN_UNDEF", "SHN_COMMON"):
            # defined here: the twin itself and static helpers are placed; another global
            # func_XXXXXXXX the file defines is retail's own function
            if sym.name != twin and sym["st_info"]["bind"] == "STB_GLOBAL":
                a = check.symbol_address(sym.name) if level is None else level_value(sym.name, level, twin, True)
                if a is not None:
                    return to_boot(a, f"{twin}: {sym.name}") if program == "frontbin" else a
            if shndx in where:
                return where[shndx] + sym["st_value"]
        if level is not None:
            return level_value(sym.name, level, twin)
        a = check.symbol_address(sym.name) if sym.name else None
        if a is None:
            raise Link(f"LINK {twin}: no address for {sym.name!r} (by name: symbol_addrs_resolved.txt, "
                       f"D_/func_/jtbl_ names, sda aliases)")
        return to_boot(a, f"{twin}: {sym.name}") if program == "frontbin" else a

    refs = []
    for rs in sections:
        if not isinstance(rs, RelocationSection):
            continue
        target = rs["sh_info"]
        if target not in where:
            continue
        base = where[target]
        # in the table's order: a %hi comes before its %lo there (the MIPS ELF ABI), not
        # always in the code (the scheduler moves a %hi after a %lo of another use)
        rel = list(rs.iter_relocations())
        hi = []
        for r in rel:
            off, t = r["r_offset"], r["r_info_type"]
            sym = syms[r["r_info_sym"]]
            k = base - BASE + off
            ins = struct.unpack_from("<I", image, k)[0]
            if t in (7, 8) and sym["st_info"]["type"] == "STT_SECTION" and sym["st_shndx"] not in where:
                # $gp-relative literal: retail's pool entry with the same bytes
                size = 8 if sections[sym["st_shndx"]].name.startswith(".lit8") else 4
                a = literal(sym["st_shndx"], sext16(ins & 0xFFFF) + gp0, size)
                d = a - GP
                if not -0x8000 <= d < 0x8000:
                    raise Link(f"LINK {twin}: literal out of $gp's reach")
                struct.pack_into("<I", image, k, (ins & 0xFFFF0000) | (d & 0xFFFF))
                continue
            a = value(sym)
            if t == 2:  # R_MIPS_32
                struct.pack_into("<I", image, k, (ins + a) & 0xFFFFFFFF)
            elif t == 4:  # R_MIPS_26
                tgt = a + ((ins & 0x3FFFFFF) << 2)
                struct.pack_into("<I", image, k, (ins & 0xFC000000) | ((tgt >> 2) & 0x3FFFFFF))
            elif t == 5:  # R_MIPS_HI16: at its LO16
                hi.append((k, sym.name or r["r_info_sym"], ins, a))
            elif t == 6:  # R_MIPS_LO16
                lo = sext16(ins & 0xFFFF)
                key = sym.name or r["r_info_sym"]
                full = None
                for hk, hname, hins, ha in [h for h in hi if h[1] == key]:
                    full = ha + ((hins & 0xFFFF) << 16) + lo
                    struct.pack_into("<I", image, hk, (hins & 0xFFFF0000) | (((full + 0x8000) >> 16) & 0xFFFF))
                hi = [h for h in hi if h[1] != key]
                if full is None:
                    full = a + lo
                struct.pack_into("<I", image, k, (ins & 0xFFFF0000) | (full & 0xFFFF))
                if not (BASE <= full < LIMIT) and sections[target]["sh_flags"] & 4:
                    refs.append(full & 0xFFFFFFFF)
            elif t in (7, 8):  # R_MIPS_GPREL16 / LITERAL
                full = a + sext16(ins & 0xFFFF) + (gp0 if g0 or sym["st_info"]["bind"] == "STB_LOCAL" else 0)
                d = full - GP
                if not -0x8000 <= d < 0x8000:
                    raise Link(f"LINK {twin}: {sym.name or 'a section'} is out of $gp's reach")
                struct.pack_into("<I", image, k, (ins & 0xFFFF0000) | (d & 0xFFFF))
                if sections[target]["sh_flags"] & 4:
                    refs.append(full & 0xFFFFFFFF)
            else:
                raise Link(f"LINK {twin}: relocation type {t} not handled")
        if hi:
            raise Link(f"LINK {twin}: a %hi without its %lo")
    return bytes(image), entry, refs


# the instructions whose immediate forms an address from a base register: addiu, the loads and
# stores (ldl/ldr, lq/sq, the byte to word ones, lwc1/swc1, ld/sd) and the VU0 quadword's lqc2
# and sqc2 (0x36, 0x3E: data some code reads or writes only through VU0)
ADDRESS_OPS = {0x09, 0x1A, 0x1B, 0x1E, 0x1F, *range(0x20, 0x30), 0x31, 0x35, 0x36, 0x37, 0x39, 0x3D, 0x3E, 0x3F}
LOADS = {0x1A, 0x1B, 0x1E, *range(0x20, 0x28), 0x37}


def retail_references(code, address, gp):
    """The data addresses retail's code forms: a lui's register with a %lo-style immediate, or $gp-based."""
    hi, out = {}, set()
    for at in range(0, len(code) - 3, 4):
        w = struct.unpack_from("<I", code, at)[0]
        op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        if op == 0x0F:
            hi[rt] = (w & 0xFFFF) << 16
            continue
        if op in ADDRESS_OPS and (rs in hi or rs == 28):
            out.add(((gp if rs == 28 else hi[rs]) + sext16(w & 0xFFFF)) & 0xFFFFFFFF)
        if op in (0, 0x1C):
            hi.pop(rd, None)
        elif op in LOADS or 0x08 <= op <= 0x0E:
            hi.pop(rt, None)
        if op == 3:
            hi.pop(31, None)
    return out


def formed(code, address, gp):
    """[(word index, address)] of what retail's code forms: data addresses (as
    retail_references) and the targets of its jumps (j, jal)."""
    hi, out = {}, []
    for at in range(0, len(code) - 3, 4):
        w = struct.unpack_from("<I", code, at)[0]
        op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        if op == 0x0F:
            hi[rt] = (w & 0xFFFF) << 16
            continue
        if op in (2, 3):
            out.append((at // 4, ((address + at + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)))
        if op in ADDRESS_OPS and (rs in hi or rs == 28):
            out.append((at // 4, ((gp if rs == 28 else hi[rs]) + sext16(w & 0xFFFF)) & 0xFFFFFFFF))
        if op in (0, 0x1C):
            hi.pop(rd, None)
        elif op in LOADS or 0x08 <= op <= 0x0E:
            hi.pop(rt, None)
        if op == 3:
            hi.pop(31, None)
    return out


@lru_cache(maxsize=None)
def address_map(fn, a, b):
    """{address in level A: address in level B} of what catalogue function FN's retail code
    forms at its places in the two levels (the same instructions, other addresses)."""
    size, places = catalogue()[fn]
    if a not in places or b not in places:
        return {}
    one = formed(level_bytes(a, places[a], size), places[a], level_gp(a))
    two = dict(formed(level_bytes(b, places[b], size), places[b], level_gp(b)))
    return {x: two[i] for i, x in one if i in two}


@lru_cache(maxsize=None)
def level_data_map(a, b):
    """{address in level A: address in level B} of the data (above LEVEL_BASE) that every catalogue
    function placed in both levels forms, where they all agree (a name the function being checked
    forms nowhere near, as another function of the level does)."""
    seen = {}
    for fn, (size, places) in catalogue().items():
        if a in places and b in places:
            for x, y in address_map(fn, a, b).items():
                if x >= LEVEL_BASE and not (places[a] <= x < places[a] + size):
                    seen.setdefault(x, set()).add(y)
    return {x: ys.pop() for x, ys in seen.items() if len(ys) == 1}


@lru_cache(maxsize=None)
def level_names(level):
    import level_catalogue as lc
    import level_symbols
    import version
    rows = lc.read_catalogue(version.cfg("levels", "functions.tsv", v="pal"))
    return level_symbols.Level(level, rows, level_gp(level))


OTHER_LEVEL = re.compile(r"^(?:func|D)_L(\d\d)_([0-9A-F]{8})")


SDA_NAME = re.compile(r"^D_[0-9A-F]{8}_sda$")


def sda_level_value(name, level, fn):
    """The slot an sda name (D_XXXXXXXX_sda: XXXXXXXX - 0x1DC8B0 from $gp) of FN's C stands for in
    level LEVEL. The name is written for FN's home level (its catalogue name's), but a level's
    literal pool is its own: the same constant sits at another $gp offset in each level (0.1375f
    at gp-0xD0 in 01, gp-0x1BC in 02). So the home level's slot is moved as FN's retail code
    moves it (address_map: the slot the same instruction reads in LEVEL); a slot retail never
    reads there, when it is a literal, to the slot of LEVEL's pools with the same bytes; else
    (a variable of .sdata, which keeps its offset) the same offset from LEVEL's $gp."""
    canon = int(fn[6:8])
    places = catalogue()[fn][1]
    here = level_names(level).expected(name)
    if level == canon or canon not in places:
        return here
    home = level_names(canon).expected(name)
    moved = address_map(fn, canon, level)
    if home in moved:
        return moved[home]
    for a, blob in level_lits(canon):
        if a <= home and home + 4 <= a + len(blob):
            found = find_literal(blob[home - a:home - a + 4], level)
            if found is None:
                raise Link(f"LINK {fn}: {name} is the literal {blob[home - a:home - a + 4].hex()} in level "
                           f"{canon:02d}, which level {level:02d}'s pools have not")
            return found
    return here


def level_value(name, level, fn, optional=False):
    """The address NAME has in level LEVEL, as the decomp's level tooling reads a name there
    (tools/level_symbols.py: catalogue names at their places, fe_ names at the level's front-end
    copy, sda names under its $gp, address names); a core name (boot_elf's table, below
    LEVEL_BASE) as itself; a name of another level's (D_LMM_/func_LMM_) moved by what FN's
    retail code forms at its places in both (address_map: the nearest address formed, within
    0x800 bytes, gives the distance), else by what all the functions the two levels share form
    there (level_data_map)."""
    import check
    if name and SDA_NAME.match(name):
        return sda_level_value(name, level, fn)
    v = level_names(level).expected(name) if name else None
    if v is not None:
        return v
    a = check.symbol_address(name) if name else None
    if a is not None and a < LEVEL_BASE:
        return a
    m = OTHER_LEVEL.match(name or "")
    if m:
        there, a = int(m.group(1)), int(m.group(2), 16)
        moved = address_map(fn, there, level)
        if a in moved:
            return moved[a]
        near = min(moved, key=lambda x: abs(x - a), default=None)
        if near is not None and abs(near - a) < 0x800 and (near >= LEVEL_BASE) == (a >= LEVEL_BASE):
            return a + moved[near] - near
        if a >= LEVEL_BASE:
            data = level_data_map(there, level)
            if a in data:
                return data[a]
    if optional:
        return None
    raise Link(f"LINK {fn}: no address for {name!r} in level {level:02d}")


# --- coverage --------------------------------------------------------------------------------

BRANCH_REGIMM = {0, 1, 2, 3, 16, 17, 18, 19}


def blocks(code, address):
    """Retail's basic blocks, [(start, end)): a block starts at the entry, at a branch's target
    inside the function and after a branch's or jump's delay slot."""
    n = len(code) // 4
    leaders = {0}
    for i in range(n):
        w = struct.unpack_from("<I", code, i * 4)[0]
        op = w >> 26
        target = None
        branch = False
        if op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 1 and ((w >> 16) & 31) in BRANCH_REGIMM) \
                or (op in (0x11, 0x12) and ((w >> 21) & 31) == 8):
            branch, target = True, i + 1 + sext16(w & 0xFFFF)
        elif op in (2, 3):
            branch = op == 2
            t = ((address + i * 4 + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if op == 2 and address <= t < address + len(code):
                target = (t - address) // 4
        elif op == 0 and (w & 0x3F) in (8, 9):  # jr, jalr
            branch = (w & 0x3F) == 8
        if branch:
            leaders.add(i + 2)
        if target is not None and 0 <= target < n:
            leaders.add(target)
    starts = sorted(x for x in leaders if x < n)
    return [(s, (starts[k + 1] if k + 1 < len(starts) else n)) for k, s in enumerate(starts)]


def hits_of(cov_file, address):
    """Which words of the function at ADDRESS ran, from openrac-fcheck --coverage."""
    if os.path.exists(cov_file):
        for line in open(cov_file):
            f = line.split()
            if len(f) == 5 and int(f[0], 16) == address:
                return [c == "1" for c in f[4]]
    return []


def coverage(cov_file, code, address, shift=0, hits=None):
    """(blocks run, blocks, words run, words, unrun ranges) from openrac-fcheck --coverage (or
    HITS, the words run)."""
    if hits is None:
        hits = hits_of(cov_file, address)
    n = len(code) // 4
    hits = list(hits) + [False] * n
    bl = blocks(code, address)
    # a trailing run of nops after the last jr is alignment, not code
    run = [b for b in bl if any(hits[b[0]:b[1]])]
    unrun = [b for b in bl if b not in run and any(struct.unpack_from("<I", code, i * 4)[0] for i in range(*b))]
    total = len(run) + len(unrun)
    words = sum(1 for i in range(n) if hits[i])
    ranges = ",".join(f"{address + shift + a * 4:08X}-{address + shift + b * 4 - 4:08X}" for a, b in unrun)
    return len(run), total, words, n, ranges


# --- fuzzing ---------------------------------------------------------------------------------
#
# A function no captured state calls, or whose states leave blocks unrun, is run from made-up
# calls: a captured state (of the function, or any state of a level that has it, or of the
# menus for a boot function) with the program counter at the function, its argument registers
# and the memory they point at generated, retail and the candidate run from it as from a real
# state. A difference there is a real one for those inputs, though the game may never make them;
# the verdict says it is fuzz evidence (same-fuzz, differs-fuzz), apart from the real states'.

SNAP_MAGIC = b"ORSNAP1\0"
SNAP_REGS = 4 + 32 * 16 + 32 * 4 + 8 * 4 + 4 * 3 + 32 * 16 + 16 * 2 + 4 * 4 + 4 * 7
SCRATCH = 0x00080000      # 64 buffers of 0x800 bytes below the candidate's code (BASE)
SCRATCH_BUFFERS = 64
SCRATCH_SIZE = 0x800
FUZZ_LIMIT = 5_000_000    # instructions retail gets from a made-up call
# the interpreter's resident memory on a made-up call ($RAC3_FCHECK_FUZZ_MB: keep jobs x this
# under the machine's memory; a run of its own holds about 300 MB)
FUZZ_MEMORY = int(os.environ.get("RAC3_FCHECK_FUZZ_MB", "3072")) << 20
FUZZ_SECONDS = 120        # and its time
FUZZ_FLOATS = [0.0, 1.0, -1.0, 0.5, 2.0, 10.0, -10.0, 100.0, 0.001]


def resident(pid):
    """A process's resident bytes (/proc on Linux, ps elsewhere), or 0."""
    try:
        with open(f"/proc/{pid}/statm") as f:
            return int(f.read().split()[1]) * os.sysconf("SC_PAGE_SIZE")
    except OSError:
        pass
    try:
        out = subprocess.run(["ps", "-o", "rss=", "-p", str(pid)], capture_output=True, text=True).stdout
        return int(out.strip() or 0) * 1024
    except (OSError, ValueError):
        return 0


def fuzz_run(cmd):
    """openrac-fcheck on a made-up call, held to FUZZ_MEMORY resident and FUZZ_SECONDS: a made-up
    pointer into nowhere can make it note millions of accesses outside memory (8 GB and more a
    run, which brought a 64 GB machine to swapping with 55 at once). It reserves a large address
    space up front, so the limit is on what it holds, watched, not on what it maps. One held up
    counts as a crash."""
    import time
    with tempfile.TemporaryFile("w+") as out, tempfile.TemporaryFile("w+") as err:
        p = subprocess.Popen(cmd, stdout=out, stderr=err, text=True)
        start, killed = time.monotonic(), False
        while p.poll() is None:
            if time.monotonic() - start > FUZZ_SECONDS or resident(p.pid) > FUZZ_MEMORY:
                p.kill()
                killed = True
            time.sleep(0.2)
        out.seek(0)
        err.seek(0)
        return subprocess.CompletedProcess(cmd, -9 if killed else p.returncode, out.read(), err.read())


def read_state(path):
    """(registers, [(size, compressed bytes)] of RAM, scratchpad, VU0 micro and data) of a state
    file (openrac-boot --capture: OpenRAC's tools/interpreter/src/sys/snapshot.cpp)."""
    data = open(path, "rb").read()
    if data[:8] != SNAP_MAGIC:
        raise ValueError(f"{path} is not a call state")
    regs = bytearray(data[8:8 + SNAP_REGS])
    at, blocks = 8 + SNAP_REGS, []
    for _ in range(4):
        size, packed = struct.unpack_from("<QQ", data, at)
        blocks.append((size, data[at + 16:at + 16 + packed]))
        at += 16 + packed
    return regs, blocks


def write_state(path, regs, blocks, ram=None):
    """Writes a state as read_state reads it; RAM, when given, replaces the first block."""
    if ram is not None:
        blocks = [(len(ram), zlib.compress(bytes(ram), 1))] + list(blocks[1:])
    with open(path, "wb") as f:
        f.write(SNAP_MAGIC + bytes(regs))
        for size, packed in blocks:
            f.write(struct.pack("<QQ", size, len(packed)) + packed)


def set_gpr(regs, r, value):
    struct.pack_into("<q", regs, 4 + 16 * r, sext32(value))


def get_gpr(regs, r):
    return struct.unpack_from("<I", regs, 4 + 16 * r)[0]


def set_fpr(regs, f, value):
    struct.pack_into("<f", regs, 4 + 32 * 16 + 4 * f, value)


def sext32(v):
    v &= 0xFFFFFFFF
    return v - (1 << 32) if v & 0x80000000 else v


def branch_constants(code):
    """The integers a function's code compares against or masks with (slti/sltiu, li, andi,
    ori, xori immediates), each with its neighbours: the edges of its branches."""
    out = set()
    for at in range(0, len(code) - 3, 4):
        w = struct.unpack_from("<I", code, at)[0]
        op, rs, imm = w >> 26, (w >> 21) & 31, w & 0xFFFF
        if op in (0x0A, 0x0B) or (op == 0x09 and rs == 0):
            v = sext16(imm)
        elif op in (0x0C, 0x0D, 0x0E):
            v = imm
        else:
            continue
        out |= {v - 1, v, v + 1}
    return sorted(out)


def float_constants(code, address, gp, read):
    """The floats a function loads from fixed addresses (lwc1 from $gp or a lui's %lo): READ
    gives 4 bytes at an address or None."""
    out = set()
    for i, a in formed(code, address, gp):
        w = struct.unpack_from("<I", code, i * 4)[0]
        if w >> 26 == 0x31:
            b = read(a)
            if b:
                f = struct.unpack("<f", b)[0]
                if f == f and abs(f) < 1e30:
                    out.add(f)
    return sorted(out)


def live_objects(ram, function):
    """Addresses of the mobys (0x100-byte records) whose update (+0x64) is FUNCTION: the
    live objects of its class, the pointer an update function is called with."""
    key = struct.pack("<I", function)
    out, k = [], ram.find(key)
    while k >= 0 and len(out) < 16:
        if k % 4 == 0 and (k - 0x64) % 0x10 == 0 and k >= 0x64:
            out.append(k - 0x64)
        k = ram.find(key, k + 1)
    return out


def any_objects(ram, updates):
    """Addresses of live mobys of any class: records whose update (+0x64) is one of UPDATES (the
    level's functions), whose class pointer (+0x24) is in RAM and whose scale (+0x2C) is a
    plausible float."""
    import array
    words = array.array("I")
    words.frombytes(bytes(ram[:len(ram) // 16 * 16]))
    out, seen = [], set()
    for k, w in enumerate(words[0x64 // 4::4]):
        if w in updates and w not in seen:   # one of each class
            at = 16 * k
            scale = struct.unpack("<f", struct.pack("<I", words[at // 4 + 11]))[0]
            if 0x100000 <= words[at // 4 + 9] < len(ram) and 0.001 < scale < 1000:
                seen.add(w)
                out.append(at)
                if len(out) >= 64:
                    break
    return out


def fuzz_states(work, function, code, base_states, own, n, seed, gp, read, updates=frozenset()):
    """N made-up calls of the function at address FUNCTION (CODE its retail bytes), written to
    WORK from BASE_STATES (OWN: those that are the function's own calls). A call from one of its
    own states keeps the call's arguments and changes words of what they point at, or replaces
    one or two of them; one from another state gets every argument made up: a live moby of its
    class (live_objects) or a scratch buffer, the constants its branches test (branch_constants)
    and their neighbours, small numbers, floats it loads and a few plain ones. A function no live
    moby has for its update (UPDATES: the level's functions, whose mobys are found) gets as $a0 now
    and then a copy of a live moby of another class in a scratch buffer, its update the function
    and its pvars a scratch buffer: a moby of its own made up from a real one. The scratch
    buffers (SCRATCH) hold zeroes, small numbers, those constants, floats, pointers to the live
    mobys and to other buffers, each buffer pointed at once (a tree, filled breadth first while
    buffers last): no two made-up pointers alias, as the game's distinct objects do not, so a
    load the C makes after a store retail makes before it reads the same. Returns the files."""
    import random
    ints = branch_constants(code) + [0, 1, 2, 3, -1, 0x80, 0xFF, 0x7FFFFFFF]
    quad = any(struct.unpack_from("<I", code, at)[0] >> 26 in (0x1E, 0x1F, 0x36, 0x3E)
               for at in range(0, len(code) - 3, 4))
    floats = float_constants(code, function, gp, read) + FUZZ_FLOATS
    out = []
    loaded = {}
    for k in range(n):
        rng = random.Random(seed * 1000003 + k)
        path = base_states[k % len(base_states)]
        if path not in loaded:
            regs, blocks = read_state(path)
            loaded = {path: (regs, blocks, bytearray(zlib.decompress(blocks[0][1])))}
        regs0, blocks, ram0 = loaded[path]
        regs, ram = bytearray(regs0), bytearray(ram0)
        objects = live_objects(ram, function)
        free = [SCRATCH + SCRATCH_SIZE * b for b in range(SCRATCH_BUFFERS)]
        ram[SCRATCH:SCRATCH + SCRATCH_SIZE * SCRATCH_BUFFERS] = bytes(SCRATCH_SIZE * SCRATCH_BUFFERS)
        others = any_objects(ram, updates) if updates and not objects else []
        queue = []

        def fresh():
            if not free:
                return 0
            b = free.pop(0)
            queue.append(b)
            return b

        def word():
            x = rng.random()
            if x < 0.4:
                return 0
            if x < 0.55:
                return rng.randrange(17)
            if x < 0.65:
                return rng.choice(ints)
            if x < 0.8:
                return struct.unpack("<I", struct.pack("<f", rng.choice(floats) if rng.random() < 0.5
                                                       else rng.uniform(-50, 50)))[0]
            if x < 0.9:
                return fresh()
            if x < 0.95 and objects:
                return rng.choice(objects)
            return 0xFFFFFFFF

        if others:
            # a real moby of another class made the function's own, its pvars a fresh buffer
            made = free.pop()
            src = rng.choice(others)
            ram[made:made + 0x100] = ram[src:src + 0x100]
            struct.pack_into("<I", ram, made + 0x64, function)
            struct.pack_into("<I", ram, made + 0x68, fresh())
            objects = [made]

        def argument(r):
            x = rng.random()
            if r == 4 and objects and x < 0.6:
                return rng.choice(objects)
            if x < 0.45:
                return fresh()
            if x < 0.8:
                return rng.choice(ints)
            return word()

        if quad:
            # code that reads or writes quadwords (lq/sq, lqc2/sqc2, which drop an address's low
            # four bits) gets 16-aligned pointers, as the game's are
            argument0 = argument

            def argument(r):
                v = argument0(r) & 0xFFFFFFFF
                return v & ~15 if SCRATCH <= (v & 0x1FFFFFFF) < 0x02000000 else v
        struct.pack_into("<I", regs, 0, function)
        if path in own and k % 3 != 2:
            if k % 3 == 0:
                # the call's own arguments, what they point at changed
                for r in range(4, 12):
                    p = get_gpr(regs, r) & 0x01FFFFFF
                    if 0x100000 <= p < len(ram) - 0x100:
                        for _ in range(rng.randrange(1, 5)):
                            struct.pack_into("<I", ram, p + 4 * rng.randrange(0x40), word() & 0xFFFFFFFF)
            else:
                for r in rng.sample(range(4, 8), rng.randrange(1, 3)):
                    set_gpr(regs, r, argument(r))
        else:
            for r in range(4, 12):
                set_gpr(regs, r, argument(r))
            for f in range(12, 20):
                set_fpr(regs, f, rng.choice(floats) if rng.random() < 0.7 else rng.uniform(-100, 100))
        while queue:
            b = queue.pop(0)
            for w in range(0, SCRATCH_SIZE, 4):
                struct.pack_into("<I", ram, b + w, word() & 0xFFFFFFFF)
        name = os.path.join(work, f"fuzz{k}.snap")
        write_state(name, regs, blocks, ram)
        out.append(name)
    return out


def run_fuzz(work, image_path, entry, returns, size, address, states, ulps, code=None):
    """Runs openrac-fcheck on each made-up call by itself (a call that never returns would stop
    the ones after it), --limit FUZZ_LIMIT. A made-up call is a reference only when retail's
    own bytes, run as the candidate (CODE), come out the same from it: one where retail faults
    (its program counter leaves memory: the interpreter ends the call there, registers and stack
    as they were) or depends on where it runs is left out ("astray"), so a fault both make is
    no difference. Returns ({status: count}, the words retail ran, the report's lines of the
    first difference)."""
    counts, hits, first = {}, [False] * (size // 4), []
    self_path = None
    if code is not None:
        self_path = os.path.join(work, "retail.bin")
        open(self_path, "wb").write(code)
    for k, st in enumerate(states):
        cov = os.path.join(work, f"fuzzcover{k}.txt")
        base = [FCHECK, "--returns", returns, "--hooks", HOOKS, "--disc", DISC, "--size", str(size),
                "--limit", str(FUZZ_LIMIT)] + (["--ulps", str(ulps)] if ulps else [])
        if self_path and image_path != self_path:
            p = fuzz_run(base + ["--code", f"{self_path}@{BASE:x}", "--entry", f"{BASE:x}", st])
            if p.returncode != 0:
                counts["astray"] = counts.get("astray", 0) + 1
                os.unlink(st)
                continue
        cmd = base + ["--code", f"{image_path}@{BASE:x}", "--entry", f"{entry:x}", "--coverage", cov,
                      "--cover-size", str(size)]
        p = fuzz_run(cmd + [st])
        st_ = {0: "same", 1: "differs", 4: "skipped"}.get(p.returncode, "error")
        if p.returncode < 0 or "bad_alloc" in p.stderr:
            # the interpreter itself died on the made-up call (a quadword access past the end of
            # RAM brings OpenRAC's interpreter down): no evidence either way
            st_ = "crash"
        if st_ == "differs" and stack_only(p.stdout, state_sp(st)):
            st_ = "astray"
        counts[st_] = counts.get(st_, 0) + 1
        if st_ != "skipped":
            hits = [x or y for x, y in zip(hits, hits_of(cov, address) + [False] * len(hits))]
        if st_ == "differs" and not first:
            out = mark_ulps(p.stdout)
            first = [l for l in out.splitlines() if l.startswith("    ") and "misaligned" not in l
                     and "does not keep" not in l][:4]
        os.unlink(st)
    return counts, hits, first


def state_sp(path):
    with open(path, "rb") as f:
        head = f.read(8 + SNAP_REGS)
    return struct.unpack_from("<I", head, 8 + 4 + 16 * 29)[0]


UNMAPPED_STEP = re.compile(r"outside memory, step \d+: ours \[\w ([0-9a-f]+)[^\]]*\], retail \[\w ([0-9a-f]+)")
STACK_WORD = re.compile(r"^\s+(?:before call \d+ \(to [0-9a-f]+\): )?word at ([0-9a-f]+):? ours ([0-9a-f]+), retail ([0-9a-f]+)")


def unmapped(a):
    a = int(a, 16) & 0x1FFFFFFF
    return 0x02000000 <= a < 0x10000000 or 0x10010000 <= a < 0x12000000 or a >= 0x12010000


def stack_only(report, sp):
    """Whether a difference of a made-up call is only one a made-up value causes, not the C:
    in the registers a function keeps and the stack near SP (a made-up index or pointer that
    sends a store into the live stack hits retail's and the candidate's frames, which are laid
    out differently; or two stack addresses, a local's, stored), any call where the candidate's
    accesses are misaligned more often (a made-up odd pointer: the console refuses such an
    access, and retail's byte loads and the C's word loads read the same values from an aligned
    one), or in the order of accesses outside memory where nothing is mapped (a made-up pointer
    past RAM). Such a call is no reference (left out as "astray"); the game's own calls never
    do these."""
    lines = [l for l in report.splitlines() if l.startswith("    ") and not l.strip().startswith("note:")]
    if not lines:
        return False
    for l in lines:
        if "misaligned loads or stores" in l:
            return True     # an access the console refuses: what follows is no reference
        if "does not keep $" in l or l.strip().startswith("..."):
            continue
        u = UNMAPPED_STEP.search(l)
        if u and unmapped(u.group(1)) and unmapped(u.group(2)):
            continue
        m = STACK_WORD.match(l)
        near = [m and abs((int(m.group(g), 16) & 0x01FFFFFF) - (sp & 0x01FFFFFF)) < 0x4000 for g in (1, 2, 3)]
        if m and (near[0] or near[1] and near[2]):
            continue      # in the stack, or two addresses in it (frames laid out differently)
        return False
    return True


def fuzz_calls(work, name, code, address, own, base, n, image_path, entry, returns, size, ulps, gp, read,
               lv_of=None):
    """Makes N calls of NAME (at ADDRESS) from BASE (OWN: its own states) and runs them: (counts,
    words run, first difference), as run_fuzz."""
    fdir = os.path.join(work, f"fuzz{address:08x}")
    os.makedirs(fdir, exist_ok=True)
    updates = (frozenset(p[lv_of] for _, p in catalogue().values() if lv_of in p) if lv_of is not None
               else frozenset())
    states = fuzz_states(fdir, address, code, base, set(own), n, zlib.crc32(name.encode()), gp, read, updates)
    # retail's own bytes as the candidate, with the two words after it: a function whose last
    # jump's delay slot the split gave to the next function (func_003D30F8's sqc2) runs whole
    try:
        tail = level_bytes(lv_of, address + size, 8) if lv_of is not None else retail_bytes(address + size, 8)
    except Exception:
        tail = b""
    return run_fuzz(fdir, image_path, entry, returns, size, address, states, ulps, code + tail)


def merge_counts(a, b):
    return {k: a.get(k, 0) + b.get(k, 0) for k in set(a) | set(b)}


def boot_base_states():
    """States a boot function's made-up calls start from: the menus' (boot_elf is whole there)."""
    out = []
    for d in ("menu", "title"):
        p = os.path.join(states_root(), d)
        if os.path.isdir(p):
            snaps = sorted(f for f in os.listdir(p) if f.endswith(".snap"))
            out += [os.path.join(p, f) for f in snaps[::max(1, len(snaps) // 3)][:3]]
    return out


def level_base_states(level):
    """States of a level a level function's made-up calls start from: a few of its run's,
    which the level's program is loaded in."""
    p = os.path.join(states_root(), f"level{level:02d}")
    if not os.path.isdir(p):
        return []
    snaps = sorted(f for f in os.listdir(p) if f.endswith(".snap"))
    return [os.path.join(p, f) for f in snaps[::max(1, len(snaps) // 3)][:3]]


def boot_read(a):
    try:
        return retail_bytes(a, 4)
    except Exception:
        return None


def level_read(level):
    def read(a):
        for base, blob in level_lits(level):
            if base <= a and a + 4 <= base + len(blob):
                return blob[a - base:a - base + 4]
        return None
    return read


def fuzz_word(counts):
    return ("differs-fuzz" if counts.get("differs") else "error-fuzz" if counts.get("error")
            else "same-fuzz" if counts.get("same") else "skipped-fuzz")


def fuzz_result(counts, hits, real_hits, code, address, first, shift=0):
    """The fuzz verdict: its word, the blocks the made-up and real calls ran together of all,
    how many blocks the made-up ones added, the calls compared, the unrun blocks, the first
    difference."""
    run, total, _, _, ranges = coverage(None, code, address, shift, [x or y for x, y in zip(hits, real_hits)])
    before = coverage(None, code, address, 0, real_hits)[0] if any(real_hits) else 0
    n = sum(counts.values())
    done = n - counts.get("skipped", 0) - counts.get("astray", 0) - counts.get("crash", 0)
    return {"status": fuzz_word(counts), "blocks": f"{run}/{total}", "new": run - before,
            "states": f"{counts.get('same', 0) + counts.get('differs', 0)}/{n}", "unrun": ranges,
            "first": first, "done": done}


def fuzz_cell(f):
    return (f"{f['status']} {f['blocks']} blocks (+{f['new']}), {f['states']} fuzz states"
            + (f", first: {f['first'][0].strip()}" if f["first"] else ""))


# --- checking --------------------------------------------------------------------------------

ULP_PAIR = re.compile(r"(ours|float bits) ([0-9a-f]{1,8}), retail ([0-9a-f]{1,8})")
ULP_NOTE = "float constant one ulp off"


def one_ulp(a, b):
    """Whether words A and B are two normal floats of one sign next to each other."""
    def normal(x):
        return 0 < (x >> 23) & 0xFF < 0xFF
    return a != b and normal(a) and normal(b) and (a ^ b) >> 31 == 0 and abs(a - b) == 1


def mark_ulps(out):
    """openrac-fcheck's report with each value one ulp from retail's named as such: floats are
    compared exactly (a PAL constant must be the same bits), and a constant written one ulp off
    (0.1375f for retail's 0x3E0CCCCD, say) is the usual cause; the fix is in the C's spelling."""
    lines = []
    for line in out.splitlines():
        for m in ULP_PAIR.finditer(line):
            a, b = int(m.group(2), 16), int(m.group(3), 16)
            if one_ulp(a, b):
                fa, fb = (struct.unpack("<f", struct.pack("<I", x))[0] for x in (a, b))
                line += f" [{ULP_NOTE}: ours {fa!r}, retail {fb!r}]"
                break
        lines.append(line)
    return "\n".join(lines)


def states_of(twin):
    d = states_root()
    out = []
    for sub in sorted(os.listdir(d)) if os.path.isdir(d) else []:
        p = os.path.join(d, sub)
        if os.path.isdir(p):
            k = 0
            while os.path.exists(os.path.join(p, f"{twin}.{k}.snap")):
                out.append(os.path.join(p, f"{twin}.{k}.snap"))
                k += 1
    return out


def check(name, candidate=None, use_retail=False, ulps=0, keep=None, quiet=False, program=None, fuzz=0):
    """Checks NAME; returns a dict: status, states, blocks, unrun, refs, text (the report), and with
    FUZZ made-up calls (fuzz_states) "fuzz", their verdict (fuzz_result)."""
    res = {"status": "", "states": "", "blocks": "", "unrun": "", "refs": "", "text": []}
    say = res["text"].append
    if LEVEL_NAME.match(name):
        return check_level(name, candidate, use_retail, ulps, keep, res, fuzz)
    try:
        program, twin = place_of(name, program)
    except Link as e:
        res["status"] = "not-checkable"
        say(str(e))
        return res
    address, size, kind = functions("boot_elf")[twin]
    if twin != name:
        say(f"{name} (frontbin) is checked at its boot_elf twin {twin}")
    if kind != "c":
        say(f"{twin} is {'hand-written assembly' if kind == 'handwritten' else 'a linker remnant'} in boot_elf")
    code = retail_bytes(address, size)
    work = keep or tempfile.mkdtemp(prefix="fcheck_")
    os.makedirs(work, exist_ok=True)
    notes = []
    t0 = datetime.datetime.now()
    if candidate and not os.path.exists(candidate):
        res["status"] = "no-file"
        say(f"{name}: {os.path.relpath(candidate, ROOT)} does not exist")
        return res
    if candidate:
        text = open(candidate).read()
    else:
        text = own_c(program, name)
        if text is None and not use_retail:
            res["status"] = "no-c"
            say(f"{name}: no C in src/ and no CANDIDATE given")
            return res
        text = text or ""
    returns = return_type(text, name) if text else "int"
    try:
        if use_retail:
            image, entry, refs = code, BASE, []
            say("self-test: retail's own bytes are the candidate")
        else:
            obj, match = compile_candidate(text, name, program, work)
            say(f"built: tools/check.py says {match} against retail")
            try:
                image, entry, refs = place(obj, name, program, notes)
            except Link as e:
                if "literal" not in str(e) and "reach" not in str(e):
                    raise
                # A float constant retail's literal pools do not hold (retail builds it in
                # registers, or its pool entry is elsewhere): built again with -G0, which reads
                # constants and small data by address instead of from $gp. Other code, same deeds.
                say(f"{e}; built again with -G0")
                obj, _ = compile_candidate(text, name, program, work, ["-G0"])
                image, entry, refs = place(obj, name, program, notes, g0=True)
    except Link as e:
        res["status"] = "build"
        say(str(e))
        return res
    t1 = datetime.datetime.now()
    open(os.path.join(work, "code.bin"), "wb").write(image)
    import gp as gpmod
    mine = retail_references(code, address, gpmod.gp_of("boot_elf"))
    strange = sorted(set(a for a in refs if a not in mine))
    res["refs"] = ",".join(f"{a:08X}" for a in strange)
    if strange:
        say("refs: the candidate forms data addresses retail's code never does: " + res["refs"]
            + " (a wrong D_ name, or a structure reached another way: read them)")
    states = states_of(twin)
    nones = [d for d in (os.listdir(states_root()) if os.path.isdir(states_root()) else [])
             if os.path.exists(os.path.join(states_root(), d, twin + ".none"))]
    shift = functions(program)[name][0] - address
    if not states:
        res["status"] = "no-states"
        res["states"] = "0"
        say(f"no states of {twin}" + (f" (not called in: {', '.join(nones)})" if nones else
                                       " (capture it: tools/fcheck.py capture " + name + ")"))
        if fuzz:
            base = boot_base_states()
            if base:
                counts, hits, first = fuzz_calls(work, name, code, address, [], base, fuzz,
                                                 os.path.join(work, "code.bin"), entry, returns, size, ulps,
                                                 gpmod.gp_of("boot_elf"), boot_read)
                res["fuzz"] = fuzz_result(counts, hits, [False] * len(hits), code, address, first, shift)
                say(f"{name}: fuzz: {fuzz_cell(res['fuzz'])}")
        if not keep:
            shutil.rmtree(work, ignore_errors=True)
        return res
    cov = os.path.join(work, "cover.txt")
    cmd = [FCHECK, "--code", f"{os.path.join(work, 'code.bin')}@{BASE:x}", "--entry", f"{entry:x}",
           "--returns", returns, "--hooks", HOOKS, "--disc", DISC, "--size", str(size),
           "--coverage", cov, "--cover-size", str(size)]
    if ulps:
        cmd += ["--ulps", str(ulps)]
    p = subprocess.run(cmd + states, capture_output=True, text=True)
    t2 = datetime.datetime.now()
    # the interpreter's notes on what its picture model lacks are no part of the verdict
    out = mark_ulps(p.stdout + "".join(l for l in p.stderr.splitlines(True) if not l.startswith("gs:")))
    res["ulp"] = ULP_NOTE in out
    for n in notes:
        say("note: " + n)
    say(out.rstrip())
    # unrun blocks in NAME's own addresses (a frontbin function's are its twin's moved by the distance)
    run, total, words, nwords, ranges = coverage(cov, code, address, shift)
    res["blocks"] = f"{run}/{total}"
    res["unrun"] = ranges
    m = re.search(r"compared (\d+) of (\d+) states", out)
    res["states"] = f"{m.group(1)}/{m.group(2)}" if m else f"?/{len(states)}"
    status = {0: "same", 1: "differs", 4: "skipped"}.get(p.returncode, "error")
    if status == "same" and run < total:
        # Blocks no state ran, which someone read against retail's instructions and listed in the
        # C's comment ("fcheck-read: RANGE,..."): done when every unrun block is listed there.
        listed = ",".join(re.findall(r"fcheck-read:\s*([0-9A-Fa-f,\-\s]+)", text))
        read = set(re.sub(r"\s", "", listed).upper().split(","))
        status = "same-read" if set(ranges.split(",")) <= read else "same-partial"
    res["status"] = status
    say(f"{name}: {status.upper()}, states {res['states']}, blocks run {run}/{total} "
        f"({100 * words // max(nwords, 1)}% of the words)" + (f", unrun {ranges}" if ranges else "")
        + f"; build {(t1 - t0).total_seconds():.1f} s, run {(t2 - t1).total_seconds():.1f} s")
    if fuzz:
        counts, hits, first = fuzz_calls(work, name, code, address, states, states, fuzz,
                                         os.path.join(work, "code.bin"), entry, returns, size, ulps,
                                         gpmod.gp_of("boot_elf"), boot_read)
        real = hits_of(cov, address) + [False] * len(hits)
        res["fuzz"] = fuzz_result(counts, hits, real[:len(hits)], code, address, first, shift)
        say(f"{name}: fuzz: {fuzz_cell(res['fuzz'])}")
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return res


def level_states(name):
    """{level: [state files]} of a level function: states/levelNN/NAME.k.snap (and the levels
    whose run never called it, with a NAME.none)."""
    d = states_root()
    out, nones = {}, []
    for sub in sorted(os.listdir(d)) if os.path.isdir(d) else []:
        m = re.fullmatch(r"level(\d\d)", sub)
        if not m:
            continue
        p = os.path.join(d, sub)
        k, got = 0, []
        while os.path.exists(os.path.join(p, f"{name}.{k}.snap")):
            got.append(os.path.join(p, f"{name}.{k}.snap"))
            k += 1
        if got:
            out[int(m.group(1))] = got
        elif os.path.exists(os.path.join(p, name + ".none")):
            nones.append(sub)
    return out, nones


def check_level(name, candidate, use_retail, ulps, keep, res, fuzz=0):
    """check() of a level function: at every level whose states hold calls of it, its C built for
    that level (tools/check.py --target level_NN: the level's flags and context) and its names
    read as that level has them (level_value); the verdict is the worst of the levels', and the
    blocks run those any level's states ran (each level has the same code at its own place).
    FUZZ made-up calls are made at up to two levels: those of its states, else levels that have it
    and states of their own (level_base_states)."""
    say = res["text"].append
    size, places = catalogue()[name]
    canon = int(name[6:8])
    home = places.get(canon, int(name[9:], 16))
    states, nones = level_states(name)
    states = {lv: st for lv, st in states.items() if lv in places}
    if candidate and not os.path.exists(candidate):
        res["status"] = "no-file"
        say(f"{name}: {os.path.relpath(candidate, ROOT)} does not exist")
        return res
    text = open(candidate).read() if candidate else ""
    if not text and not use_retail:
        res["status"] = "no-c"
        say(f"{name}: no CANDIDATE given (level functions are checked from nonmatching/functional/)")
        return res
    fuzz_levels = []
    if fuzz:
        have = sorted(states) or [lv for lv in places if level_base_states(lv)]
        fuzz_levels = sorted(have, key=lambda lv: (lv != canon, lv))[:2]
    if not states:
        res["status"] = "no-states"
        res["states"] = "0"
        say(f"no states of {name}" + (f" (not called in: {', '.join(nones)})" if nones else
                                       " (capture it: tools/fcheck.py capture --script levelNN " + name + ")"))
        if not fuzz_levels:
            return res
    returns = return_type(text, name) if text else "int"
    work = keep or tempfile.mkdtemp(prefix="fcheck_")
    os.makedirs(work, exist_ok=True)
    first_lv = min(states) if states else fuzz_levels[0]
    code0 = level_bytes(canon if canon in places else first_lv, places.get(canon) or places[first_lv], size)
    hits = [False] * (size // 4)
    fhits, fcounts, ffirst = [False] * (size // 4), {}, []
    verdicts, compared, total_states, strange = [], 0, 0, set()
    built = False
    t0 = datetime.datetime.now()
    order = sorted(set(states) | set(fuzz_levels), key=lambda lv: (lv != canon, lv))
    for lv in order:
        address = places[lv]
        code = level_bytes(lv, address, size)
        sub = os.path.join(work, f"level{lv:02d}")
        os.makedirs(sub, exist_ok=True)
        notes = []
        try:
            if use_retail:
                image, entry, refs = code, BASE, []
            else:
                obj, match = compile_candidate(text, name, f"level_{lv:02d}", sub)
                say(f"level {lv:02d} at {address:08X}: built, tools/check.py says {match}")
                try:
                    image, entry, refs = place(obj, name, f"level_{lv:02d}", notes, lv)
                except Link as e:
                    if "literal" not in str(e) and "reach" not in str(e):
                        raise
                    say(f"{e}; built again with -G0")
                    obj, _ = compile_candidate(text, name, f"level_{lv:02d}", sub, ["-G0"])
                    image, entry, refs = place(obj, name, f"level_{lv:02d}", notes, lv, g0=True)
        except Link as e:
            if lv == canon or lv == order[-1] and not built:
                res["status"] = "build"
                say(f"level {lv:02d}: {e}")
                return res
            # a name the home level has that this one cannot be told (no place, nothing formed
            # near it): its states are left out, the home level's still count
            say(f"level {lv:02d} left out: {e}")
            continue
        built = True
        mine = retail_references(code, address, level_gp(lv))
        # refs in the home level's addresses (where the C's names are written)
        back = {v: k for k, v in address_map(name, canon, lv).items()} if lv != canon else {}
        strange |= {back.get(a, a) for a in refs if a not in mine}
        open(os.path.join(sub, "code.bin"), "wb").write(image)
        if lv in fuzz_levels:
            c, h, f = fuzz_calls(sub, name, code, address, states.get(lv, []),
                                 states.get(lv) or level_base_states(lv), -(-fuzz // len(fuzz_levels)),
                                 os.path.join(sub, "code.bin"), entry, returns, size, ulps, level_gp(lv),
                                 level_read(lv), lv)
            fcounts, fhits, ffirst = merge_counts(fcounts, c), [x or y for x, y in zip(fhits, h)], ffirst or f
        if lv not in states:
            continue
        cov = os.path.join(sub, "cover.txt")
        cmd = [FCHECK, "--code", f"{os.path.join(sub, 'code.bin')}@{BASE:x}", "--entry", f"{entry:x}",
               "--returns", returns, "--hooks", HOOKS, "--disc", DISC, "--size", str(size),
               "--coverage", cov, "--cover-size", str(size)]
        if ulps:
            cmd += ["--ulps", str(ulps)]
        p = subprocess.run(cmd + states[lv], capture_output=True, text=True)
        out = mark_ulps(p.stdout + "".join(l for l in p.stderr.splitlines(True) if not l.startswith("gs:")))
        res["ulp"] = res.get("ulp") or ULP_NOTE in out
        for n in notes:
            say("note: " + n)
        say(out.rstrip())
        hits = [x or y for x, y in zip(hits, hits_of(cov, address) + [False] * len(hits))]
        m = re.search(r"compared (\d+) of (\d+) states", out)
        if m:
            compared += int(m.group(1))
        total_states += len(states[lv])
        verdicts.append({0: "same", 1: "differs", 4: "skipped"}.get(p.returncode, "error"))
    t2 = datetime.datetime.now()
    res["refs"] = ",".join(f"{a:08X}" for a in sorted(strange))
    if strange:
        say("refs: the candidate forms data addresses retail's code never does: " + res["refs"]
            + " (a wrong D_ name, or a structure reached another way: read them)")
    if fuzz_levels and built:
        res["fuzz"] = fuzz_result(fcounts, fhits, hits, code0, home, ffirst)
        say(f"{name}: fuzz at levels {','.join(f'{lv:02d}' for lv in fuzz_levels)}: {fuzz_cell(res['fuzz'])}")
    if not states:
        if not keep:
            shutil.rmtree(work, ignore_errors=True)
        return res
    run, total, words, nwords, ranges = coverage(None, code0, home, 0, hits)
    res["blocks"] = f"{run}/{total}"
    res["unrun"] = ranges
    res["states"] = f"{compared}/{total_states}"
    status = ("differs" if "differs" in verdicts else "error" if "error" in verdicts
              else "same" if "same" in verdicts else "skipped")
    if status == "same" and run < total:
        listed = ",".join(re.findall(r"fcheck-read:\s*([0-9A-Fa-f,\-\s]+)", text))
        read = set(re.sub(r"\s", "", listed).upper().split(","))
        status = "same-read" if set(ranges.split(",")) <= read else "same-partial"
    res["status"] = status
    say(f"{name}: {status.upper()}, levels {','.join(f'{lv:02d}' for lv in order)}, states {res['states']}, "
        f"blocks run {run}/{total} ({100 * words // max(nwords, 1)}% of the words)"
        + (f", unrun {ranges}" if ranges else "") + f"; {(t2 - t0).total_seconds():.1f} s")
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return res


# --- the table -------------------------------------------------------------------------------

def read_table():
    """(lines, columns, rows) of nonmatching/functional.tsv: the columns are its last comment line
    that starts with "# name"; each row a dict by column, with "_line" its index in LINES."""
    lines = open(TABLE).read().splitlines() if os.path.exists(TABLE) else []
    columns = ["name", "file"]
    rows = []
    for k, line in enumerate(lines):
        if line.startswith("# name"):
            columns = line[2:].split("\t")
        elif line.strip() and not line.startswith("#"):
            f = line.split("\t")
            row = dict(zip(columns, f + [""] * (len(columns) - len(f))))
            row["_line"] = k
            rows.append(row)
    return lines, columns, rows


def gate_cell(res):
    """The table's `gate` column for a check's result: the status, the blocks run of all and the
    states, the unrun blocks (and refs) when there are any."""
    st = res["status"]
    if st in ("same", "same-read", "same-partial", "differs", "skipped"):
        cell = f"{st} {res['blocks']} blocks, {res['states']} states"
        if res["unrun"] and st != "same":
            cell += f" ({'unrun read' if st == 'same-read' else 'unrun'}: {res['unrun']})"
        if st == "differs" and res.get("ulp"):
            cell += f"; {ULP_NOTE}"
    else:
        last = res["text"][-1].splitlines() if res["text"] else [""]
        cell = st + ": " + last[0]
        if len(last) > 1 and last[0].rstrip().endswith(":"):
            # BUILD: the compiler's first complaint, without the scratch file's path
            cell += " " + re.sub(r"^\s*\S*?(cand|t)\.c:", "line ", last[1])
    f = res.get("fuzz")
    if f and st == "no-states":
        # no real state: the made-up calls' verdict is the row's, its unrun blocks with it
        cell = fuzz_cell(f) + (f" (unrun: {f['unrun']})" if f["unrun"] and f["status"] != "differs-fuzz" else "")
    elif f:
        cell += "; fuzz: " + fuzz_cell(f)
    if res["refs"]:
        cell += f"; refs not in retail: {res['refs']}"
    return cell.replace("\t", " ")


def gate_one(row, fuzz=0):
    """One row's check, for gate's workers: (name, program, the result)."""
    res = check(row["name"], os.path.join(ROOT, row["file"]), program=row.get("program") or None, fuzz=fuzz)
    return row["name"], row.get("program", ""), res


def write_gates(verdicts):
    """Puts VERDICTS ({(name, program): gate cell}) in the table's `gate` column, the rest of the
    table as it is now on disk (read again: someone may have added rows meanwhile)."""
    lines, columns, rows = read_table()
    if "gate" not in columns:
        sys.exit("nonmatching/functional.tsv has no `gate` column")
    for r in rows:
        cell = verdicts.get((r["name"], r.get("program", "")))
        if cell is not None:
            r["gate"] = cell
            lines[r["_line"]] = "\t".join(r.get(c, "") for c in columns)
    open(TABLE, "w").write("\n".join(lines) + "\n")


def gate(names, write, jobs=1, shard=None, out=None, only=None, fuzz=0):
    """Checks the table's rows (or NAMES), JOBS at a time; SHARD (k, n) takes every n-th row from
    the k-th, ONLY a regular expression the gate cell must match (e.g. ^pending). With WRITE puts
    each verdict in its `gate` column, the rest of the table untouched; with OUT appends
    `name<TAB>program<TAB>gate` lines to that file instead (`merge` puts them in the table)."""
    _, columns, rows = read_table()
    todo = [r for r in rows if (not names or r["name"] in names)
            and (only is None or re.search(only, r.get("gate", "")))]
    if shard:
        todo = todo[shard[0]::shard[1]]
    worst = 0
    verdicts = {}
    sink = open(out, "a") if out else None
    t0 = datetime.datetime.now()

    def take(name, program, res):
        nonlocal worst
        print("\n".join(res["text"]), flush=True)
        cell = gate_cell(res)
        verdicts[(name, program)] = cell
        if sink:
            sink.write(f"{name}\t{program}\t{cell}\n")
            sink.flush()
        worst = max(worst, {"same": 0, "same-read": 0, "same-partial": 0}.get(res["status"], 1))

    if jobs > 1:
        import concurrent.futures as cf
        with cf.ProcessPoolExecutor(jobs) as pool:
            import functools
            for name, program, res in pool.map(functools.partial(gate_one, fuzz=fuzz), todo, chunksize=1):
                take(name, program, res)
    else:
        for r in todo:
            take(*gate_one(r, fuzz))
    took = (datetime.datetime.now() - t0).total_seconds()
    print(f"gate: {len(todo)} rows in {took:.0f} s ({len(todo) / max(took, 1e-9):.2f} a second, {jobs} jobs)")
    if write:
        write_gates(verdicts)
    return worst


def with_states(cell):
    """A gate cell from states that ran (not pending, no-states, not-checkable or no-file)."""
    return cell.split(":")[0].split(" ")[0] in ("same", "same-read", "same-partial", "differs", "skipped", "build", "error",
                                                "same-fuzz", "differs-fuzz", "skipped-fuzz", "error-fuzz")


def merge(files):
    """Puts the verdicts of gate --out FILES in the table (the last line of a row wins, but a
    no-states one never replaces one with states, the table's own included)."""
    # the table's own verdicts first: a file's no-states never replaces one with states there
    verdicts = {(r["name"], r.get("program", "")): r.get("gate", "") for r in read_table()[2]}
    for f in files:
        for line in open(f):
            p = line.rstrip("\n").split("\t")
            # a verdict without states never replaces one with (machines hold different states)
            if len(p) == 3 and not (p[2].startswith("no-states") and with_states(verdicts.get((p[0], p[1]), ""))):
                verdicts[(p[0], p[1])] = p[2]
    write_gates(verdicts)
    print(f"merge: {len(verdicts)} verdicts into {os.path.relpath(TABLE, ROOT)}")


# --- capturing -------------------------------------------------------------------------------

def capture_line(twin, wanted, level=None):
    """A line of openrac-boot's capture list: the address, the CRC of the first (up to) 256 bytes
    there (a call is taken only while that code is there: a level's place holds other code
    before the level loads), the name the states are written under and how many a phase."""
    if level is None:
        address, size, _ = functions("boot_elf")[twin]
        head = retail_bytes(address, min(size, 256))
    else:
        size, places = catalogue()[twin]
        address = places[level]
        head = level_bytes(level, address, min(size, 256))
    return f"{address:08X} {len(head)} {zlib.crc32(head) & 0xFFFFFFFF:08X} {twin} {wanted}\n"


def boot_cmd(name, listfile, outdir):
    s = script_of(name)
    cmd = [BOOT, DISC, "--hooks", HOOKS, "--no-card", "--report", "0", "--frames", str(s["frames"]),
           "--capture", listfile, outdir, "--capture-phases", ",".join(map(str, s["phases"])), "--capture-spread"]
    for p in s["presses"]:
        cmd += ["--press", p]
    for p in s.get("sticks", []):
        cmd += ["--stick", p]
    for w in s.get("writes", []):
        cmd += ["--write", w]
    # $RAC3_FCHECK_BOOT_ARGS: more of openrac-boot's options (--one-thread for many runs at once)
    return cmd + os.environ.get("RAC3_FCHECK_BOOT_ARGS", "").split()


def capture(names, script, force, programs=None):
    boot_twins, level_names = [], []
    for n in names:
        if LEVEL_NAME.match(n):
            level_names.append(n)
            continue
        try:
            boot_twins.append(place_of(n, (programs or {}).get(n))[1])
        except Link as e:
            print(e)
    for sc in (["title", "menu"] if script == "all" else [script]):
        level = script_of(sc).get("level")
        if level is None:
            twins = boot_twins
        else:
            # a level's run: the level functions with a place in it, and boot functions of the
            # resident core (below LEVEL_BASE: the level's program replaces the rest)
            twins = [n for n in level_names if level in catalogue().get(n, (0, {}))[1]] + [
                t for t in boot_twins if functions("boot_elf")[t][0] < LEVEL_BASE]
        outdir = os.path.join(states_root(), sc)
        os.makedirs(outdir, exist_ok=True)
        todo = [t for t in dict.fromkeys(twins) if force or not (
            os.path.exists(os.path.join(outdir, t + ".0.snap")) or os.path.exists(os.path.join(outdir, t + ".none")))]
        if not todo:
            print(f"{sc}: every state already there")
            continue
        for t in todo:
            for f in os.listdir(outdir):
                if f.startswith(t + "."):
                    os.unlink(os.path.join(outdir, f))
        lst = os.path.join(outdir, "capture.txt")
        per = script_of(sc).get("per_phase", STATES_PER_PHASE)
        open(lst, "w").writelines(capture_line(t, per, level if LEVEL_NAME.match(t) else None) for t in todo)
        t0 = datetime.datetime.now()
        p = subprocess.run(boot_cmd(sc, lst, outdir), capture_output=True, text=True, cwd=outdir)
        took = (datetime.datetime.now() - t0).total_seconds()
        if p.returncode:
            print(p.stdout[-2000:] + p.stderr[-2000:])
        got = 0
        for t in todo:
            if os.path.exists(os.path.join(outdir, t + ".0.snap")):
                got += 1
            else:
                open(os.path.join(outdir, t + ".none"), "w").close()
        size = sum(os.path.getsize(os.path.join(outdir, f)) for f in os.listdir(outdir) if f.endswith(".snap"))
        print(f"{sc}: {got} of {len(todo)} functions called; {took:.0f} s; states in {outdir} "
              f"({size / 1e6:.0f} MB in all)")


def reach(script, out):
    """Call counts of every boot_elf function (in a level's run: of every level function with a
    place there, and of the resident core's) in SCRIPT's run (`--calls`, no states)."""
    work = tempfile.mkdtemp(prefix="fcheck_reach_")
    lst = os.path.join(work, "list.txt")
    level = script_of(script).get("level")
    if level is None:
        fn = functions("boot_elf")
        lines = [capture_line(n, 0) for n in sorted(fn)]
    else:
        fn = [n for n, (_, places) in catalogue().items() if level in places]
        lines = [capture_line(n, 0, level) for n in sorted(fn)] + [
            capture_line(n, 0) for n, (a, _, _) in sorted(functions("boot_elf").items()) if a < LEVEL_BASE]
    open(lst, "w").writelines(lines)
    calls = os.path.join(work, "calls.txt")
    cmd = boot_cmd(script, lst, work) + ["--calls", calls]
    subprocess.run(cmd, capture_output=True, text=True, cwd=work)
    text = open(calls).read() if os.path.exists(calls) else ""
    open(out, "w").write(text)
    called = sum(1 for line in text.splitlines() if line.split() and line.split()[1] != "0")
    print(f"{script}: {called} of {len(lines)} functions called; table in {out}")
    shutil.rmtree(work, ignore_errors=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("check")
    c.add_argument("name")
    c.add_argument("candidate", nargs="?")
    c.add_argument("--retail", action="store_true")
    c.add_argument("--ulps", type=int, default=0)
    c.add_argument("--keep")
    c.add_argument("--fuzz", type=int, default=0, help="also N made-up calls (fuzz_states)")
    c.add_argument("--program", choices=["boot_elf", "frontbin"],
                   help="NAME's program, where both have the name (default: boot_elf's)")
    g = sub.add_parser("gate")
    g.add_argument("names", nargs="*")
    g.add_argument("--write", action="store_true")
    g.add_argument("--jobs", type=int, default=1, help="rows checked at once (one process each)")
    g.add_argument("--shard", help="K/N: every N-th row from the K-th (0-based), for spreading over machines")
    g.add_argument("--only", help="a regular expression the row's gate cell must match (e.g. ^pending)")
    g.add_argument("--out", help="append name, program and verdict lines to this file (see merge)")
    g.add_argument("--fuzz", type=int, default=0, help="also N made-up calls a row (fuzz_states)")
    m = sub.add_parser("merge")
    m.add_argument("files", nargs="+")
    k = sub.add_parser("capture")
    k.add_argument("names", nargs="*")
    k.add_argument("--script", default="all", choices=list(SCRIPTS) + ["all"])
    k.add_argument("--list")
    k.add_argument("--force", action="store_true")
    k.add_argument("--program", choices=["boot_elf", "frontbin"],
                   help="the NAMEs' program, where both have the name (default: the table's, else boot_elf's)")
    r = sub.add_parser("reach")
    r.add_argument("--script", default="menu", choices=list(SCRIPTS))
    r.add_argument("--out", default=os.path.join(states_root(), "reach.txt"))
    sub.add_parser("scripts")
    a = ap.parse_args()
    if a.cmd == "check":
        res = check(a.name, a.candidate, a.retail, a.ulps, a.keep, program=a.program, fuzz=a.fuzz)
        print("\n".join(res["text"]))
        if (res.get("fuzz") or {}).get("status") == "differs-fuzz":
            sys.exit(1)
        sys.exit({"same": 0, "same-read": 0, "same-partial": 0, "differs": 1, "build": 2, "not-checkable": 2, "no-c": 2,
                  "no-states": 3, "skipped": 4}.get(res["status"], 1))
    if a.cmd == "gate":
        shard = tuple(int(x) for x in a.shard.split("/")) if a.shard else None
        sys.exit(gate(a.names, a.write, a.jobs, shard, a.out, a.only, a.fuzz))
    if a.cmd == "merge":
        merge(a.files)
    if a.cmd == "capture":
        names = list(a.names)
        if a.list:
            names += [l.split()[0] for l in open(a.list) if l.strip() and not l.startswith("#")]
        if not names:
            names = [r["name"] for r in read_table()[2]]
        programs = {r["name"]: r.get("program") for r in read_table()[2]}
        if a.program:
            programs.update({n: a.program for n in names})
        capture(names, a.script, a.force, programs)
    if a.cmd == "reach":
        reach(a.script, a.out)
    if a.cmd == "scripts":
        for n in SCRIPTS:
            s = script_of(n)
            print(n, s["frames"], "fields; phases", s["phases"], "; presses", " ".join(s["presses"]))


if __name__ == "__main__":
    main()
