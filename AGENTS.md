# Instructions for agents

This file is for AI agents (Claude, Codex or others) working in this repository. Read it
completely before changing anything; then read README.md, CONTRIBUTING.md,
docs/build/build-fidelity.md and the wiki pages in `docs/wiki/` (Setup, Workflow, Matching-Patterns,
Pull-Requests). The repository follows the structure of rac1-decomp and rac2-decomp, the other
OpenRAC decompilations, and of rac3-uya-decomp (the US version), which it started from: keep it
that way.

## What this repository is

A matching decompilation of Ratchet & Clank 3 (PS2, PAL, `SCES-52456`): three core programs and
the 49 level programs from the disc, rebuilt from C and assembly until every byte equals retail.

| Program | What it is | SHA-1 of the retail file |
| --- | --- | --- |
| `frontbin` | the front end (menus) | `5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553` |
| `boot_elf` | the engine core plus a second copy of the front end | `e0a4e82e9a363a64db5a555db8c8f927ef58c3d8` |
| `i5bootn` | a loader that decompresses and starts another program | `c1166658edad1b6b04b7671af77fff53f2560e71` |

`tools/targets.py` names every program's files; every tool reads its paths there and takes
`--target frontbin|boot_elf|i5bootn` (or `all` where it makes sense), or `--target level_NN` for a
level. The levels ([docs/build/levels.md](docs/build/levels.md)): their code is `src/levels/shared/` (in two
or more levels) and `src/levels/<NN_name>/` (one level), each distinct function once under its
catalogue name `func_LNN_XXXXXXXX`; `config/levels/functions.tsv` lists every place it has. A
level's build tree is made from them under `build/levels/` (`tools/levels.py tree`). Level C uses
catalogue names and is built into every level that has it (docs/build/levels.md, "C in level code").
Readable names are a lookup table (docs/contributing/names.md), not macros: C always uses the address
names, because `#define` aliases are not allowed in matched C. Shared layouts (the
hero, mobys, cameras, the pad, weapon rows, particles) are in `include/structs/`, and the hero's
state numbers in `include/enums/`; `common.h` doesn't include them, so a file includes the ones
it uses, as long as it has no per-function type of the same name (docs/wiki/Matching-Patterns.md).

| Path | What it is | Who writes it |
| --- | --- | --- |
| `src/<program>/` | one C file per source file: C, or `INCLUDE_ASM` markers | you (C replacing markers) |
| `config/<program>/src_files.txt` | each program's source files and their start addresses | by hand, rarely |
| `config/<program>/text_parts.txt` | one flag line per source file (see "Compiler flags") | by hand |
| `config/<program>/symbol_addrs.txt`, `divs_nops.txt`, `sq_ra_funcs.txt` | symbols, and the tables the build reads by function | by hand / their tools |
| `config/<program>/symbol_addrs_resolved.txt` | addresses of the names no object defines | `tools/resolve_symbols.py` |
| `config/names.tsv`, `include/names.h` | readable names for address names, a lookup only (docs/contributing/names.md) | by hand / `tools/names.py header` |
| `include/structs/`, `include/enums/` | shared layouts and named numbers, each header citing its source | by hand |
| `config/splat/<program>.yaml` | splat's configuration (`tools/setup_asm.py` runs it) | by hand |
| `include/`, `linker_scripts/` | headers, assembler macros, the hand-kept linker scripts | by hand |
| `nonmatching/` | near misses and the US drafts not carried, never linked (`nonmatching/README.md`) | you |
| `progress/report.json` | the counts per program | `tools/progress.py --write` |
| `objdiff.json` | objdiff's units (stays in the root, where objdiff looks) | `tools/objdiff/gen_objdiff_units.py` |
| `tools/`, `tests/` | build, checks, the local matching editor | by hand |
| `docs/`, `docs/wiki/` | research notes; the wiki's source; `docs/research/us/` is the US project's notes | by hand |
| the retail programs, `asm/`, `build/` | game data, generated assembly, build output | never committed |

## Two versions

The repository also covers the NTSC-U disc (`SCUS-973.53`): docs/build/versions.md. PAL stays the
primary target and every path above is PAL's. A function whose code is the same on both discs
is one C source in `src/`, never a copy; NTSC-U's own C goes in `src/us/` only where its bytes
differ. After any change to `src/` (and before every push):

    TOOLCHAINS=~/Projects/RAC/rac3-toolchains JOBS=32 sh tools/carry_us.sh

`tools/version_map.py --check` (part of `progress.py --check` and `tests/check_repository.py`)
fails when the versions are out of step. `python3 tools/check.py --version us FILE.c func_X`
checks a PAL function on NTSC-U; `--version us --native` checks src/us/ C. The NTSC-U programs
are built from src/'s C and assembly: `python3 tools/asm_build.py --version us --c` (after
`tools/c_objects.py`; carry_us.sh runs both).

## How a function is matched

1. Pick a function with an `INCLUDE_ASM` marker (`python3 tools/todo.py` sorts what is left). If
   `nonmatching/<program>/` has a draft for it (often the US C), start from that.
2. Write C for it with `python3 tools/check.py FILE.c [func_XXXXXXXX]` (or localdecomp) until it
   compiles to retail's bytes with **its file's** flags.
3. Replace the marker with the C, in place, in the file that owns its address, inside
   `/* localdecomp:start func_XXXXXXXX */ ... /* localdecomp:end func_XXXXXXXX */`.
4. `python3 tools/resolve_symbols.py --target <program>`, `python3 tools/progress.py --write`,
   `python3 tests/check_repository.py` and `python3 -m unittest discover -s tests`.
5. The real check: the full build (`python3 tools/build.py --target all`) prints one `MATCH`
   line per program with the SHA-1s above. A function counts only when it links into a program
   that equals retail byte for byte.

If you get close but not exact, put your C in `nonmatching/<program>/func_XXXXXXXX.c` with a row
in `nonmatching/README.md` saying what still differs, and keep the `INCLUDE_ASM` marker.

## Commands

| Command | What it does |
| --- | --- |
| `python3 tools/setup_asm.py --target all` | generates `asm/` from your programs in `baserom/` |
| `python3 tools/build.py --target all -j 8 --toolchain DIR --runner WIBO --ee29 DIR` | the full build, one `MATCH` per program |
| `python3 tools/check.py FILE.c [func_XXXXXXXX]` | compiles a snippet with its file's flags and diffs it against retail |
| `python3 tools/check.py FILE.c func_LNN_XXXXXXXX [--target level_MM]` | the same for a level function, at its place in level NN (or MM) |
| `python3 tools/todo.py [--target NAME]` | the functions still to match, sorted by what they need |
| `python3 tools/port_verify.py --target NAME` | after a build: every function's bytes against retail |
| `python3 tests/check_repository.py` | source checks of every program, tables, progress, no game data (CI) |
| `python3 -m unittest discover -s tests` | the tools' unit tests (CI) |
| `python3 tools/progress.py [--write\|--check]` | the counts and the report |
| `python3 tools/levels.py dump` | the 49 level programs from your disc into `baserom/levels/` |
| `python3 tools/build_levels.py --setup -P 8 -j 4 ...` | every level's build, one `MATCH` per level |

## Compiler flags: one set per source file

`config/<program>/text_parts.txt` has exactly one line per source file, at the file's first
function (tests check it). There are no per-function flags: a function that matches only with
flags its neighbours do not use is not matched here, even when it was matched that way in the US
project (docs/build/build-fidelity.md). Sony's library code is built with Sony's ee-gcc
2.9-ee-991111 (`@ee29`) in files of its own, because Sony compiled it separately.

What may differ inside a file is not a compiler flag: an assembly block (`INCLUDE_ASM`,
`ASM_FUNC`, `LINKER_REMNANT`) in an `@ps2as` file is assembled with GNU as, because SN's
Ps2EeAs cannot read the assembler macros its `.s` uses
(`tools/build_text.py`, `file_slices`). Nothing compiled is affected.

## Matching rules

- **Plain C.** No inline assembly for ordinary EE instructions, no register pins, no artificial
  barriers, no `#define` aliases and no hardcoded addresses. A function that matches only with one of
  these stays a near miss in `nonmatching/`. Asm is allowed in three cases only:
  - the size hint `__asm__(".extern X, N");`;
  - **the vector-library helpers in `include/vu0.h`** (`qzero`, `fabs_asm`, `sqrt_asm`,
    `fmax_asm`, `abs_asm`): small macros that retail proves were asm in the original (the
    compiler cannot emit the instruction, or retail never schedules it into a delay slot), each
    defined once there with its evidence, and used at all of a file's sites or none
    (docs/wiki/Matching-Patterns.md, "Vector-library asm macros"). A new one needs the same
    evidence;
  - **VU0 code** (since 2026-11-08): the macro-mode/COP2 instructions the compiler cannot emit
    (`lqc2`, `sqc2`, `vadd*`, `vsub*`, `vmul*`, `vmadd*`, `vopmula`/`vopmsub`, `vdiv`, `vsqrt`,
    `vrsqrt`, `qmfc2`/`qmtc2`, `ctc2`/`cfc2`, `vcallms`, ...), written the way Insomniac's source
    plausibly had it: one asm block per VU0 sequence with real operands and clobbers, or shared
    VU0 helpers in a header. Never asm for an ordinary EE instruction, nor asm used to force register
    allocation, scheduling or a delay slot.
- **`volatile`** only where it describes the memory: hardware registers and memory written by the
  IOP, DMA or interrupts, on a named declaration (never `*(volatile T *)0xADDR`). Never as a
  code-generation barrier on game data or locals. Older notes that say a function "matched with
  volatile" as a barrier are history, not a method to copy.
- **Globals are `extern`.** Never define a variable in `src/`: it creates data that breaks the
  layout.
- **`$gp` differs per program** (`config/gp.tsv`): the multiplayer levels have their own. A
  `$gp`-relative global in code they have is named by its slot, `D_XXXXXXXX_sda`
  (docs/build/globals.md).
- **Handwritten assembly** (`ASM_FUNC`) and linker remnants (`LINKER_REMNANT`) are final source,
  marked only on evidence (VU0 / COP2 code, instructions the compiler never emits), never because a
  function resisted matching.
- **A match is the full build saying `MATCH`.** Not a compiled object, not a masked comparison, not
  a model's claim. Report exactly what you ran and what it printed.

## When to stop on a function

Stop when it is not a function (it reads registers it never sets or has no `jr $ra`), when it is
handwritten, when three different wordings compile to the same wrong bytes, or after about ten
compiles without getting closer. Leave the attempt in `nonmatching/` with what differs, and move
on.

## Rules

- **Sources.** Use the retail programs of your own disc, SDK library *binaries*, open-source code
  under its licence, public decompilations and tools, and public hardware documentation. Never use
  Sony's SDK source, samples or headers, or leaked or NDA material, not even as a reference. If a
  function looks like SDK sample code, decode it from the assembly. The beta disc
  (docs/game/beta-disc.md) is a reference for names and behaviour only; nothing taken from it is
  committed.
- Refer to the third-party Ratchet & Clank NTSC-U decompilation as "the NTSC decomp", never by
  an author's name or handle.
- **Never commit game data or proprietary tools**: the retail programs, level overlays, disc
  images, `asm/`, build output, the SN or Sony toolchains. They stay in ignored places; keep them
  so. `python3 tests/check_repository.py` checks this.
- **English** in everything that lands here: code, comments, commits, `nonmatching/` notes.
- **LF line endings** in every text file you write or change (`.gitattributes` makes git commit and
  check them out so). On Windows, write files with LF too: Python's `open(path, "w", newline="\n")`,
  never PowerShell's `>`, `Out-File` or `Set-Content` (UTF-16 or CRLF). `config/us/map.tsv` hashes a
  source file's bytes, so a CRLF working copy of a file gives a hash no other checkout gets.
  `python3 tests/check_repository.py` checks it. Files committed with CRLF before this rule keep it
  until a change of their own converts them; don't convert files you don't otherwise change.
- **Coordinate before matching.** Check the pinned issue
  [#3, Contributor coordination](https://github.com/OpenRAC/rac3-decomp/issues/3) before you pick
  or assign matching work. Make sure the contributor you work for has their one comment there,
  creating it if it's missing. Claim scopes (a level, a shared source file, a directory) rather than
  single functions, and don't take anything another contributor's comment holds.
- **Never delete what you did not create**, and leave other people's uncommitted work alone.
- Before a commit: `python3 -m unittest discover -s tests` and `python3 tests/check_repository.py`
  (both need no game data; CI runs them), and for anything that affects the build, the full build
  with its three `MATCH` lines.

## Commits

- Conventional Commits with a scope: `feat(frontbin): match func_0039BEC0`,
  `fix(tools): ...`, `docs: ...`, `build: ...`, `chore: ...`.
- A body that says what changed, why, and what you verified (the commands and what they printed).
- No `Co-authored-by:` trailers or other attribution lines for AI tools.
- Small, coherent commits, each leaving the build and the checks green.
