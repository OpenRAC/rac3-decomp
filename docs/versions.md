# Two versions: PAL and NTSC-U

One repository, one source tree, two discs:

| Version | Disc | ISO (yours, never committed) | Role |
| --- | --- | --- | --- |
| `pal` | PAL, `SCES-524.56` (Europe and Australia) | `baserom/SCES_524.56.iso` | the primary target: every C function in `src/` was matched against it |
| `us` | NTSC-U v1.00, *Ratchet & Clank: Up Your Arsenal*, `SCUS-973.53` | `baserom/SCUS_973.53.iso` | the second version |

`baserom/TCES_524.56.iso` (the July 2004 PAL beta, [BETA.md](BETA.md)) is a reference only: never
a target and never counted.

Every tool takes `--version pal|us` (or the environment's `UYA_VERSION`; `pal` without either,
`tools/version.py`). PAL's paths are the repository's own and stay as they were; NTSC-U's are
kept apart:

| | PAL | NTSC-U |
| --- | --- | --- |
| dumps (never committed) | `baserom/{frontbin,boot_elf,i5bootn}.elf`, `baserom/levels/` | `baserom/us/...`, `baserom/us/levels/` |
| program tables | `tools/targets.py`, `config/levels/levels.tsv` | `config/us/programs.tsv`, `config/us/levels/levels.tsv` |
| function tables | `config/inventory.tsv`, `config/frontend_pairs.tsv`, `config/levels/functions.tsv` | `config/us/inventory.tsv`, `config/us/frontend_pairs.tsv`, `config/us/levels/functions.tsv` |
| the source | `src/` | `src/` (shared) and `src/us/` (NTSC-U only) |
| how it is matched | the full build (`tools/build.py`, `tools/build_levels.py`) | `config/us/map.tsv` (`tools/version_map.py`) |
| report | `progress/report.json` (`SCES_524.56_report`) | `progress/us/report.json` (`SCUS_973.53_report`) |

## The NTSC-U disc

    python3 tools/levels.py --version us dump      # baserom/us/: the three core programs and the 51 levels
    python3 tools/levels.py --version us config    # config/us/programs.tsv, config/us/levels/levels.tsv

`dump` reads everything straight from the ISO (no Wrench unpack) and checks that each ELF
converts back to the disc's bytes; it does the same for PAL, where it reproduces Wrench's
`frontbin.elf`, `boot_elf.elf` and `i5bootn.elf` byte for byte (their SHA-1s in
`tools/targets.py`):

- `i5bootn`: `I5BOOTN.ELF` in the disc's root, as it is;
- `boot_elf`: the loader `SYSTEM.CNF` boots (`SCUS_973.53` / `SCES_524.56`) carries the main
  program WAD-compressed in its `.rodata`; `tools/unpack_wad.py` unpacks it (18 section
  records) and `levels.boot_elf_image()` gives it Wrench's ELF headers;
- `frontbin`: the front end's program in the MISC wad (the global header of size 0x48 at
  table-of-contents offset 0x648, its `frontend_code` range at +0x20);
- the levels: through the table of contents at sector 1001, as for PAL ([levels.md](levels.md)).

| Program | NTSC-U SHA-1 (the ELF) | Code |
| --- | --- | --- |
| `frontbin` | `3bc94ee895e4b4af9b5602a229af599c1103b542` | `.text` `0x37D100`, 0x6FCF8 bytes |
| `boot_elf` | `487975305f8a263c750dfede50391b575ed07835` | `core.text` `0x116F80` (0x264A0), `.text` `0x381180` (0x71438) |
| `i5bootn` | `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f` | `.text` `0x800000`, 0x4FD8 bytes |

NTSC-U has 51 levels: PAL's 49 and two more split-screen multiplayer maps, 54 (Metropolis) and 55
(Blackwater City), builds of 44 and 45 linked 0x11000 higher, as 50-53 are of 40-43. Their code is
44's and 45's: they add no distinct function.

### Building it

    python3 tools/asm_build.py --version us -P 16      # 54 targets: MATCH for each

The NTSC-U programs are built from assembly alone (`tools/asm_build.py`, rac-deadlocked-decomp's
`asm_programs.py` and `build_levels.py` applied to this game): one `.s` per function from the
committed function tables, assembled in parts of about 8 KB that no branch crosses with
binutils 2.10-ee (`sn-prodg-24-ee`, native on Linux; `--bin`), linked at their addresses, written
back into the dump's ELF and the disc's program format, and compared with both SHA-1s. All 54
targets (frontbin, boot_elf, i5bootn and the 51 levels) match. The words the assembler does not
give back as they are (VU0 macro instructions, COP0 moves, data among code) are found by the
build itself (`--rounds`) and written as `.word`. `--version pal` builds PAL the same way, as a
check of its dumps and tables; PAL's real build is still `tools/build.py`.

### With the shared C

    python3 tools/c_objects.py -j 32 --toolchain DIR --runner WIBO --ee29 DIR
    python3 tools/asm_build.py --version us --c -P 16
    python3 tools/c_objects.py --collect

The NTSC-U programs are built from src/'s C and assembly, as PAL's are:

1. `tools/c_objects.py` compiles every function that checks MATCH on NTSC-U (config/us/map.tsv,
   below) on its own, with its file's flags and context, exactly as `tools/check.py --version us`
   compiles it, and keeps the object when that very compile gives MATCH.
2. `tools/asm_build.py --c` links each object at the function's NTSC-U place(s) in place of its
   assembly. The values of the names the C uses are read from the disc's bytes as PAL's level
   build reads them (`tools/level_symbols.py`'s `derive()`): every word without a relocation must
   be the disc's, each relocation gives its name's value, a name gets one value per program, a
   function's name the address of its NTSC-U twin. A function that disagrees stays assembly and
   the build says why.
3. A core function whose block does not reproduce alone (a block of several functions such as
   libgcc's, an `@ps2as` file's slices, data of its own) is built the way PAL's build builds it:
   `c_objects.py` takes the PAL build's own object of its whole file (build/.../src/<unit>/
   <file>.o) when every function of that file has its NTSC-U twin at one and the same distance
   (build/us/cobj/files.tsv), and `asm_build.py` links the whole object there, with its `.data` or
   `.rodata` at the place its code reads it (or, when its code does not, the one place in the
   disc's data with its bytes). 13 files are built so (libgcc's `frame.c`, i5bootn's two files
   with read-only data, nine of boot_elf's front-end files and one of frontbin's).
4. Each of the 54 programs must still equal the disc byte for byte: all 54 do.
5. `--collect` writes config/us/built.tsv: per function, the programs that build it from C, and
   where it stays assembly and why. The NTSC-U report counts a C function as final only when every
   program that has it builds it from C, so its exact figure is a full build's, as PAL's is.
   4,686 of the 4,719 C functions that check MATCH build from C everywhere. The others stay
   assembly: libgcc's `_eh.c` (17; its `.data`, an exception table, is laid out otherwise in the
   disc), 14 functions of files that differ inside between the two discs or still hold a literal
   address (`src/frontbin/3B0FF0.c`), and 2 that start on a 4-mod-8 address in one NTSC-U program
   (`func_0039ADD8` in frontbin, `func_L01_004D2DC8` in level 39), where C cannot start, as in
   PAL's build. The checker still counts them in the fuzzy figure.

Where one PAL name stood for what are two places on NTSC-U (another copy of a front-end function,
of a level function, or of a variable, in some levels), the shared C names it with an alias
(`<name>_<caller>`, docs/levels.md): PAL's bytes are unchanged and each disc's build reads the
alias's value from its own bytes. 17 level functions use one for that.

## One source for both

A function whose code is the same on both discs is **one C source**: the PAL source in `src/`,
compiled with that file's flags (`config/<program>/text_parts.txt`, `config/levels/text_parts.txt`;
one set per file, never per function). It is never copied. C for NTSC-U alone goes in `src/us/`,
only where the bytes differ: `src/us/<frontbin|boot_elf|i5bootn>/XXXXXXXX.c`, one function per
file, with each file's flags in `config/us/text_parts.txt` (the flags of the PAL file its
counterpart is in). Its names have a prefix of their own, `func_U_XXXXXXXX` and `D_U_XXXXXXXX`
(NTSC-U addresses), so they never meet src/'s PAL names in one build; a name in the resident
engine core (below `0x1D5680`, the same on both discs) is written plainly.

32 functions are there now. `tools/us_port.py` wrote 30 of them: for a PAL function whose
NTSC-U counterpart differs only in immediates (the 60 Hz values of NTSC against PAL's 50 Hz: 30
and 25, 300 and 250, 210 and 180, 0x60 and 0x50, 1/60.0f and 1/50.0f), it replaces each PAL
constant in the C, checks the result on NTSC-U, reads every name's NTSC-U value from the bytes,
and writes the file only when it checks MATCH natively (`tools/check.py --version us --native`).
Two (`func_U_003EB588`, `func_U_003EB598`) were written by hand: NTSC-U stores a value that PAL
converts to 50 Hz frames first. Two counterparts are left, those of `func_003C0C60` (boot_elf)
and `func_003C08A8` (frontbin): their PAL C writes a byte through a literal address (the reason
is in config/us/exceptions.tsv: as a symbol, gcc moves that store into the next branch's delay
slot, which retail does not).

`tools/version_map.py --write` (needs both dumps and the toolchain) makes `config/us/map.tsv`:

1. **Twins.** Every PAL function is paired with the NTSC-U function with the same code: equal
   `inventory.identity()` (only address fields masked) and equal size. Core programs: per code
   section, unique code first as anchors, then repeated code copy by copy in order. Levels:
   PAL catalogue row against NTSC-U catalogue row.
2. **The check.** PAL's C for a function with a twin is compiled with its own file's flags and
   context and compared with the twin by the stock checker, `tools/check.py --version us`:
   calls and function addresses as the NTSC-U disc has them (the twins' addresses), the resident
   engine core (below `0x1D5680`, the same on both discs) at its own addresses, any other name
   masked. MATCH there is `match`; anything else is `nomatch` with its closeness.
   `ASM_FUNC` and `LINKER_REMNANT` are final source on both discs by their twin's code.
3. **Counterparts.** A PAL function with no twin (`differs`) is paired by position with the
   NTSC-U function between the same twinned neighbours: that is where NTSC-U's own C goes. Most
   are the 60 Hz constants of NTSC against PAL's 50 Hz (30 frames against 25, 60 against 50,
   a float 60.0 against 50.0), counts and offsets. Its PAL C is checked there too: the diff count
   gives a fuzzy figure.
4. **Near misses** in `nonmatching/` are checked at their twin: their closeness is NTSC-U's fuzzy
   figure for that function.

`tools/check.py --version us FILE.c func_XXXXXXXX` checks one PAL function on NTSC-U;
`--version us --native` checks NTSC-U's own C (NTSC-U names, its file's flags).

Native core C with compiler-generated data, such as a switch jump table, is carried
as a whole object through `c_objects.py`'s existing `files.tsv` path. It must first
pass the stock native check with its inherited file flags. The full build resolves
the object's named symbols with `NativeNames`, places its data where the code reads
it (or where those bytes occur uniquely in the retail data), and links both code
and data from the compiler object. The entire program must still match retail;
a code-only check or a masked relocation is not evidence that the data matches.
Shared objects retain their existing whole-PAL-file requirements; this does not
enable isolated level objects with private data or change compiler flags.

### Staying in step

`tools/version_map.py --check` (run by `tools/progress.py --check`, by
`tests/check_repository.py` and by CI; it needs no disc) fails when:

- `src/` changed since the map was written: a PAL change or a new PAL match not carried to
  NTSC-U (each row keeps a hash of its source file and flags line);
- a function final on one disc and with the same code on the other is not final there
  (`nomatch`): the shared C must match both;
- `src/us/` has C for a function that has a PAL twin (shared code is one source) or C that does
  not check MATCH (near misses go in `nonmatching/`).

- a function that checks MATCH has no line in config/us/built.tsv: it was not carried into the
  NTSC-U build.

Before every push, after any change to `src/`, on a Linux machine with both discs' dumps and the
toolchains (it builds the 54 NTSC-U programs with the C):

    TOOLCHAINS=~/Projects/RAC/rac3-toolchains JOBS=32 sh tools/carry_us.sh

It runs `tools/version_map.py --write` (only the functions whose file changed are checked
again), `tools/c_objects.py`, `tools/asm_build.py --version us --c`, `tools/c_objects.py
--collect` and both progress reports; commit what it changes in config/us/, progress/ and the
README with the change.

## The counts

Each version is counted from its own disc's function tables with the same rules
([levels.md](levels.md), "Counting functions"): `tools/inventory.py --version us`,
`tools/levels.py --version us catalogue`. boot_elf's front end counts once with frontbin, a
level function once however many levels have it.

| | PAL functions / bytes | PAL final | NTSC-U functions / bytes | NTSC-U final | NTSC-U fuzzy |
| --- | ---: | ---: | ---: | ---: | ---: |
| frontbin (its own; boot_elf's front end counts here) | 1,665 / 383,852 | 1,391 (51.06%) | 1,650 / 380,356 | 1,369 (50.49%) | 57.25% |
| boot_elf (engine core and the front-end functions frontbin lacks) | 1,045 / 235,620 | 854 (69.92%) | 1,052 / 238,404 | 827 (66.97%) | 68.71% |
| i5bootn | 194 / 20,308 | 193 (99.15%) | 191 / 20,316 | 185 (95.20%) | 95.83% |
| Shared level code | 7,747 / 3,914,160 | 2,518 (6.26%) | 7,728 / 3,883,768 | 2,522 (6.31%) | 6.32% |
| Level-specific code | 5,513 / 2,993,008 | 237 (0.22%) | 5,601 / 2,986,136 | 237 (0.22%) | 0.22% |
| **Total** | 16,164 / 7,546,948 | 5,193 (8.38%) | 16,222 / 7,508,980 | 5,140 (8.29%) | 8.69% |

(Percentages are of the code bytes; NTSC-U final is what its build makes from C. A snapshot: the
README has the current figures.)

**Why the totals differ.** NTSC-U has 58 more functions in 37,968 fewer bytes:

- *Core programs.* NTSC-U's front end is 0x1648 bytes smaller (frontbin's `.text` 0x6FCF8 against
  0x71340) and is cut into 1,858 functions against 1,878; boot_elf's front end the same (0x71438
  against 0x716F8, 1,870 functions against 1,876). The engine core (`core.text`) is the same size,
  cut into 820 functions against 828: each inventory takes the extents the C proves, and PAL's
  sources split a few functions NTSC-U's tables keep whole. Fewer of boot_elf's front-end
  functions pair with frontbin's on NTSC-U (1,846 against 1,872: every pair their code allows,
  tools/level_catalogue.py align(); a pair counts once), so it has
  2,893 distinct core functions against 2,904.
- *Levels.* 51 levels against 49: 54 and 55 are split-screen builds of 44 and 45 and add no
  distinct function. 14,624 distinct level functions against 14,571: 7,728 shared, 5,601
  level-specific, 1,294 counted with frontbin.
- *Matched.* NTSC-U's exact figure is its build's: a C function counts when every program
  that has it builds it from C (config/us/built.tsv, above). Of PAL's 4,688 final C functions with an NTSC-U twin (counted per
  program: boot_elf's front-end copies too), 4,687 check MATCH there; 1 does not
  (config/us/exceptions.tsv). 34 PAL C functions have a counterpart whose bytes differ (32 of
  those counterparts have their own C in src/us/), 34 have none. ASM_FUNC and LINKER_REMNANT twins
  (621 and 1,102) are final on both discs. NTSC-U counts 497 linker remnants of its own as final, as PAL
  does.
- *Fuzzy.* NTSC-U's fuzzy figure adds the near misses of nonmatching/ checked at their twins (548)
  and PAL's C checked at its differing counterparts. PAL's report keeps fuzzy equal to exact:
  nothing partly matched is built there.

## Machines

The PAL build compiles with SN's Windows compilers through [wibo](https://github.com/decompals/wibo),
on Linux and on an Apple Silicon Mac alike. wibo publishes a build for each: `wibo-x86_64` (or
`wibo-i686`) for Linux and `wibo-macos`, an x86-64 macOS program that runs under Rosetta 2
(wibo 1.2.0). Rosetta runs its 32-bit code natively; the *Linux* builds do not run on a Mac, not
even in a container (Rosetta rejects their segment setup with "invalid gdt selector", and under
QEMU wibo 1.x fails to start child processes).

Each machine keeps its toolchains in `~/Projects/RAC/rac3-toolchains` with `wibo` there being the
right build for it (on the Mac, a link to `wibo-macos`), so every command is the same on all of them:

    T=~/Projects/RAC/rac3-toolchains
    export UYA_TOOLCHAIN=$T/eegcc_2.95.3_sn_v1.36 UYA_RUNNER=$T/wibo UYA_EE29=$T/sn-prodg-24-ee/gcc

`tools/check.py`, `tools/build.py`, `tools/build_levels.py`, `tools/c_objects.py`,
`tools/version_map.py` and the permuter tools read those three variables when `--toolchain`,
`--runner` and `--ee29` are not given, and `tools/carry_us.sh` passes `$T/wibo` itself.

The NTSC-U build needs only binutils 2.10-ee, which exists only as i386 Linux programs. On a Mac
`tools/asm_build.py` (and `carry_us.sh`'s step 3) default to `$T/mac-bin`, whose `ee-as` and `ee-ld`
run those programs in a `linux/386` container (OrbStack or Docker); `--bin` or `UYA_BINUTILS`
override it.

The Mac's output is the boxes' byte for byte: on 2026-10-21 the full PAL build on the Mac (the
three core programs and all 49 levels) printed the same SHA-1s as box1's, and its checks the same
results. Measured against box1 (wibo 1.2.0 on both):

| | Mac (M-series, 18 cores) | box1 (32 threads) |
| --- | --- | --- |
| one `check.py` call | 0.43 s | 0.33 s |
| 144 checks, 12 at a time | 8.4 s: 17 checks/s | 8.6 s: 17 checks/s |
| 144 checks, 32 at a time | not run | 6.4 s: 23 checks/s |
| core build (`build.py --target all`) | 12 s at `-j 18`, 18 s at `-j 12` | 9 s at `-j 32` |
| 49 levels with `--setup` | 34 min at `-P 6 -j 2` | |

Wine for macOS (WineHQ 11.18, WoW64) also builds byte-identical programs, but is several times
slower: 0.8 s per check, 3.6 s for 32 checks at once, 76 s for the core build.

Builds split per program, per level and per version: `tools/build_levels.py NN ...` and
`tools/asm_build.py TARGET ...` take the targets to build.

## PAL's catalogue, refreshed (2026-10-21)

`tools/levels.py catalogue` regenerated config/levels/functions.tsv and config/frontend_pairs.tsv
from the committed config/inventory.tsv, which they no longer followed in one place: frontbin's
0x397AF0 is a 28-byte linker remnant there, followed by a 176-byte function at 0x397B10. So
boot_elf's 208-byte 0x397ED0 no longer pairs with a frontbin function of its size (one pair fewer:
1,872), and in the 34 levels that have it the old 192-byte `func_L01_004218C8` is that remnant's
12 bytes (now `LINKER_REMNANT`) followed by frontbin's `func_00397B10`. PAL counts one more
function and one more final one: 5,193 of 16,164.
