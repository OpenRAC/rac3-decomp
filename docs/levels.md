# The levels, and how the game's functions are counted

Every level carries its own build of the game's main program: `.lit`, `.bss`, `.data`,
`lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` and `.text`, loaded over the front end's sections when
the level starts (frontbin is the same kind of program). The engine core (`core.text` and its
data, in `boot_elf`) stays resident and is the same for every level. PAL has 49 levels: 1-14,
16-24 and 26-36 (story, ranger missions, vid-comics) and 39-53 (the multiplayer menu and maps);
the US disc's 54 and 55 are not on it.

## From the disc

    python3 tools/levels.py dump      # baserom/levels/<NN_name>.elf
    python3 tools/levels.py config    # config/levels/levels.tsv, config/splat/levels/, linker_scripts/levels/

`dump` reads the levels straight from `baserom/SCES_524.56.iso` through the disc's table of
contents (sector 1001; the module docstring of `tools/levels.py` has the format). Each program is
written as an ELF in frontbin.elf's layout, and `dump` checks that it converts back to the
disc's bytes. `config/levels/levels.tsv` keeps, per level, the SHA-1 of that ELF and of the
program as the disc stores it, its entry point and its sections. No Wrench unpack is needed.

## Building a level

Each level is a target like frontbin, `level_NN` (`tools/targets.py`), with its splat
configuration and linker script. Its sources are made for it under `build/levels/<NN_name>/`
from `src/levels/` (`tools/levels.py tree NN`), so the build is the core programs' build:
`tools/setup_asm.py`, `tools/build.py`. `tools/build_levels.py` runs all of it for many levels at
once and checks each built program against the disc's SHA-1:

    python3 tools/build_levels.py --setup -P 8 -j 4 --toolchain DIR --runner WIBO --ee29 DIR

prints one `MATCH` per level (`--setup` the first time and after the catalogue changes; without
it only the tree is remade, which is enough after changing C). On a level, `setup_asm.py` disables spimdisasm's "halt function
search" (the multiplayer menu's `.text` holds data that stops it) and writes the data's floats as
their bit patterns (the assembler loses a denormal's bits). After splat, `tools/levels.py tree
--fill NN` completes the `.s` of a function where splat cut it short (it splits the linker's
`0xCDCDCDCD` fill and hand-written VU0 code on its own).

## C in level code

A level function is matched once, in its `src/levels/` file, under its catalogue name, and built
into every level that has it. Write it as in the core programs, between
`/* localdecomp:start func_L01_003016B0 */` and `/* localdecomp:end func_L01_003016B0 */`, with
the names it uses written as:

| What | Name in level C | Its value in a level |
| --- | --- | --- |
| a shared or level function | `func_LNN_XXXXXXXX` (catalogue) | its place there (`config/levels/functions.tsv`) |
| a front-end function (kind `frontbin`/`boot_elf`) | `func_XXXXXXXX` (frontbin's name) | the level's copy |
| level data (`.lit`, `.bss`, `.data`, ...) | `D_LNN_XXXXXXXX`: its address in a level NN that has it | where the code reads it |
| the resident core (`boot_elf`'s `core.text` and data) | `func_XXXXXXXX`, `D_XXXXXXXX` | the address |
| an alias of one of these, `<name>_<suffix>` (for example `func_L01_00431808_0040ABCD`) | the name with a suffix | in level NN its address (`func_LNN_`/`D_LNN_`), elsewhere where the code reads it |

An alias is for code the catalogue counts as one function but that in some levels calls or reads another copy than the catalogue's place (another function with the same code, other data): the suffix (the caller's address) gives it a name of its own, whose value in the other levels comes from the bytes. In a level's tree a bare `func_XXXXXXXX` is the level's own label at that address (an assembly function of a file with C), never a front-end function, which is always `fe_func_XXXXXXXX` there.

    extern u8 D_L01_001D66B0[];
    extern void func_L01_00301558(s32 a0, u8 *a1, u8 a2);

    void func_L01_003016B0(s32 a0, u8 a1) {
        func_L01_00301558(a0, D_L01_001D66B0, a1);
    }

**Checking one function** (as `tools/check.py` for the core programs): the file's flags
(`config/levels/text_parts.txt`) and its context (the file's prelude and earlier declarations),
diffed against the function's place in its canonical level NN (the one in its name), or in the
level `--target level_MM` names:

    python3 tools/check.py scratch/f.c func_L01_003016B0 --toolchain DIR --runner WIBO
    python3 tools/check.py scratch/f.c func_L01_003016B0 --target level_40 ...

The names are filled in as that level has them (catalogue names at their places, `D_LNN_` in
level NN at its address); a name whose value there is not known is masked. Then the full build
of the levels: the function counts when every level that has it says `MATCH`.

**How the build does it** (rac2-decomp's approach, `Placement.derive` there): `tools/levels.py
tree` copies a file with C into each level that has its functions (the prelude, the
declarations of the functions that level lacks, then the level's run of them, the markers
renamed to the level's addresses; front-end names become `fe_func_XXXXXXXX`; `TEXT_PADDING`
where retail has more zero words after the function than gcc's alignment). After compiling,
`tools/level_symbols.py` (run by `tools/build.py`) lays each such object over the level's retail
`.text` at its file's address: the words without relocations must be retail's, and each
relocation in a C function (`R_MIPS_26`, `%hi`/`%lo`, `$gp`, `R_MIPS_32`) gives the value its
name must have there. A name gets one value per level, and where the value is known (the
table above) it must be that one; the values go to `build/levels/<NN_name>/
symbol_addrs_derived.txt`, which the level's linker script reads. A difference stops the build
naming the function and word: the C is not that function in that level.

Types (`typedef`, `struct`) that several functions of a file use go in the file's prelude; a later function's type that clashes with an earlier one of another body takes the function's address as a suffix.

Limits for now: the C must have no data of its own (string literals, `.rodata` jump tables,
literal pools: the level's data is its assembly's), a C function must start 8-aligned in every
level, and the declarations a function needs from another function of its file go in the
file's prelude or in its own block.

## Counting functions (`config/inventory.tsv`, `config/levels/functions.tsv`)

The functions are found from the binaries, with rac1-decomp's rules (`tools/overlays.py
split()`, `code_size()`, `tools/overlay_remnants.py` there), the same way in every code section
(`tools/inventory.py`):

- **starts**: the section's start and the entry point; every `jal`, `bgezal` or `bltzal` target;
  the instruction after a `jr $ra` and its delay slot, past the zero words after it; after a
  `j` and its delay slot when a frame opener (`addiu $sp, $sp, -N`) follows; a frame opener right
  after a zero word; a pointer in the program's data that points just after finished code; the
  `lvl.*` dispatch tables' pointers;
- **joined**: a conditional branch never leaves its function, so a start that one crosses is
  not a start (an early return, a trap block, a loop after a return), unless a call or a
  dispatch table reaches it (rac1-decomp's `joined.tsv`, from the bytes);
- **proven**: in the core programs, a function that is C starts and ends where its byte-identical
  build puts it;
- **size**: without the zero words after it, but with its last jump's delay slot; an entry of
  only zero words or `0xCDCDCDCD` fill is padding, not a function;
- **linker remnants** (rac1-decomp's rule): an 8-aligned entry of words that are not jumps or
  branches, after finished code, that nothing branches to or points at. They count as finished.

Then each distinct function counts once (rac1-decomp's and rac2-decomp's catalogue,
`tools/level_catalogue.py`): two places are one function when their instructions are equal apart
from what linking changes (`inventory.identity()`: jump targets and address halves are masked,
except those into the resident core; constants, stack slots and field offsets are compared) and
their sizes are equal; the k-th copy of identical code in each level is one function.

- **boot_elf's front end** (`config/frontend_pairs.tsv`): boot_elf's `.text` is frontbin's
  `.text` linked a second time. 1,873 of its 1,876 functions (456,392 bytes) are frontbin's
  functions; the report counts each pair once, in frontbin's unit (in boot_elf's when only
  boot_elf's copy is final).
- **levels**: 239,763 function places in the 49 levels are 14,570 distinct functions: 1,310 are
  frontbin's (counted with frontbin), 7,747 are shared by two or more levels (3,914,340 bytes;
  1,189 are in all 49) and 5,513 are in one level only (2,993,008 bytes; the multiplayer menu
  has 3,091 of them).

### Compared with the counts before (2026-10-20)

The report counted the core programs' source entries: 532 units and 4,903 functions
(1,106,012 bytes). Found from the binaries, the core programs have 4,775 functions:

| Program | Before | Now | Why |
| --- | ---: | ---: | --- |
| frontbin | 1,902 | 1,877 | 21 entries split a function where a branch crosses or with no start at all; 6 `LINKER_REMNANT`s were the delay slot of the function before; 2 remnants the sources join to a function are their own |
| boot_elf | 2,802 | 2,704 | 36 delay-slot `LINKER_REMNANT`s; 27 entries of only zero words (padding); 40 splits inside a function; 5 starts the sources do not have |
| i5bootn | 199 | 194 | 3 delay-slot `LINKER_REMNANT`s; 2 splits inside hand-written code |

The bytes drop by the padding (zero words after a function are not code) and by frontbin's last
entry, which ran 428 bytes past `.text` into the ELF's section table. 31 entries change only
whether they are remnants (rac1-decomp's rule against the US list). Then the 1,873 front-end
pairs count once: 2,902 distinct core functions (639,576 bytes). The core units are still one per
source file; the 133 boot_elf `.text` files (and one frontbin file) whose functions are all
counted in the other program's unit have no unit: 398 core units. With the level code the game
has 16,162 functions in 436 units.

The source entries are unchanged: a function is final when every source entry it covers is
(the build still proves each entry), so splitting or joining entries never changes a count.

## `src/levels/`

As in rac1-decomp and rac2-decomp, every shared and level-specific function is in `src/levels/`
once, under its catalogue name `func_LNN_XXXXXXXX` (its address in the lowest-numbered level that
has it): `src/levels/shared/` and `src/levels/<NN_name>/`, in canonical order, files of up to
32 KB starting 8-aligned in every level (estimates; flags in `config/levels/text_parts.txt`, one
line per file). A level's copy of a front-end function has no source here.

## Report

`tools/progress.py` (rac1-decomp's units and categories): one unit per core source file, one
"Shared level code" unit (category `common`), one unit per level with its own functions
("Level 01: Veldin", categories `levels` and `level_01`); `core`, each core program and section,
and `level_code` group them.
