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
3. Each of the 54 programs must still equal the disc byte for byte: all 54 do, with 56,333
   function places (frontbin 998, boot_elf 1,506, i5bootn 35, the 51 levels the rest) linked
   from C.
4. `--collect` writes config/us/built.tsv: per function, the programs that build it from C, and
   where it stays assembly and why. The NTSC-U report counts a C function as final only when every
   program that has it builds it from C, so its exact figure is a full build's, as PAL's is.
   4,615 of the 4,683 functions that check MATCH build from C everywhere. The others stay
   assembly: 51 core functions whose block reproduces only when its whole file is compiled
   (libgcc's `_eh.c` and `frame.c`, some `@ps2as` files) or that have data of their own
   (`.rodata`), and 17 level functions whose names take two values in one NTSC-U level (a
   front-end copy or a variable that is one on PAL and two there). The checker still counts them
   in the fuzzy figure.

## One source for both

A function whose code is the same on both discs is **one C source**: the PAL source in `src/`,
compiled with that file's flags (`config/<program>/text_parts.txt`, `config/levels/text_parts.txt`;
one set per file, never per function). It is never copied. C for NTSC-U alone goes in `src/us/`,
only where the bytes differ (`src/us/<frontbin|boot_elf|i5bootn>/*.c` named by NTSC-U
addresses, `src/us/levels/**.c` by NTSC-U catalogue names; each file's flags in
`config/us/text_parts.txt`, the flags of the PAL file its counterpart is in).

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
| frontbin (its own; boot_elf's front end counts here) | 1,665 / 383,852 | 1,391 (51.06%) | 1,664 / 394,768 | 1,354 (48.09%) | 55.55% |
| boot_elf (engine core and the front-end functions frontbin lacks) | 1,044 / 235,412 | 854 (69.98%) | 1,038 / 224,008 | 802 (63.43%) | 66.30% |
| i5bootn | 194 / 20,308 | 193 (99.15%) | 191 / 20,316 | 183 (76.39%) | 95.83% |
| Shared level code | 7,747 / 3,914,340 | 2,517 (6.26%) | 7,728 / 3,883,768 | 2,506 (6.28%) | 6.32% |
| Level-specific code | 5,513 / 2,993,008 | 237 (0.22%) | 5,601 / 2,986,136 | 237 (0.22%) | 0.22% |
| **Total** | 16,163 / 7,546,920 | 5,192 (8.38%) | 16,222 / 7,508,996 | 5,082 (7.96%) | 8.51% |

(Percentages are of the code bytes; NTSC-U final is what its build makes from C. A snapshot: the
README has the current figures.)

**Why the totals differ.** NTSC-U has 59 more functions in 37,924 fewer bytes:

- *Core programs.* NTSC-U's front end is 0x1648 bytes smaller (frontbin's `.text` 0x6FCF8 against
  0x71340) and is cut into 1,858 functions against 1,878; boot_elf's front end the same (0x71438
  against 0x716F8, 1,870 functions against 1,876). The engine core (`core.text`) is the same size,
  cut into 820 functions against 828: each inventory takes the extents the C proves, and PAL's
  sources split a few functions NTSC-U's tables keep whole. Fewer of boot_elf's front-end
  functions pair with frontbin's on NTSC-U (1,846 against 1,872: every pair their code allows,
  tools/level_catalogue.py align(); a pair counts once), so it has
  2,893 distinct core functions against 2,903.
- *Levels.* 51 levels against 49: 54 and 55 are split-screen builds of 44 and 45 and add no
  distinct function. 14,624 distinct level functions against 14,570: 7,728 shared, 5,601
  level-specific, 1,294 counted with frontbin.
- *Matched.* NTSC-U's exact figure is its build's: a C function counts when every program
  that has it builds it from C (config/us/built.tsv, above). Of PAL's 4684 final C functions with an NTSC-U twin (counted per program: boot_elf's
  front-end copies too), 4683 check MATCH there; 1 does not
  (config/us/exceptions.tsv). 38 PAL C functions have a counterpart whose bytes differ (their
  NTSC-U C belongs in src/us/), 34 have none. ASM_FUNC and LINKER_REMNANT twins (621 and 1102) are
  final on both discs. NTSC-U counts 497 linker remnants of its own as final, as PAL does.
- *Fuzzy.* NTSC-U's fuzzy figure adds the near misses of nonmatching/ checked at their twins (548)
  and PAL's C checked at its differing counterparts. PAL's report keeps fuzzy equal to exact:
  nothing partly matched is built there.

## Machines

The PAL build compiles with SN's Windows compiler through wibo (Linux); the NTSC-U build needs
only binutils 2.10-ee. `tools/asm_build.py --bin` takes any folder with an `ee-as` and `ee-ld`,
so on a Mac they can run in a `linux/386` container (wibo itself does not run under Rosetta).
Builds split per program, per level and per version: `tools/build_levels.py NN ...` and
`tools/asm_build.py TARGET ...` take the targets to build.
