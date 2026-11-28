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
their bit patterns (the assembler loses a denormal's bits). spimdisasm takes the target of every
word that decodes as a call for a function start; an address that such a word reaches inside a
catalogue row (only where a `boundaries.tsv` line joins over it: level 39's encrypted DNAS blocks,
below) is handed to splat as a branch label (`.LXXXXXXXX = ...; // type:label` in the temporary
symbol file), which spimdisasm never ends a function at, so the row's `.s` is whole and a branch
into its second half assembles. After splat, `tools/levels.py tree
--fill NN` completes the `.s` of a function where splat cut it short (it splits the linker's
`0xCDCDCDCD` fill and hand-written VU0 code on its own).

A level's setup is skipped when nothing it reads has changed (since 2026-11-16; the docstring of
`tools/setup_asm.py` lists what its key covers). A full setup keeps a copy of all it writes
(the level's `asm/` folder, splat's linker script and assets, `nohalt.py`, the splat side files
it created) in `build/setup_asm/level_NN/`; the next one with the same key puts back the files
that are missing or differ (`levels.py tree --fill` edits some `.s` after every setup), deletes
the files of the `asm/` folder the setup did not write and runs `trailing_padding.py --apply`,
the setup's one step that writes into the tree. The files are then byte for byte those of a full
setup, in 1 to 1.5 s on the build VM instead of 28 to 42 (all 49 levels with `--setup -P 8 -j 2`:
206 s instead of 416). Matching a function changes no input of the setup: what
splat reads from the tree is its `INCLUDE_ASM` / `INCLUDE_RODATA` macros and the functions it takes
for C. A level's tree keeps the `INCLUDE_ASM` of a function's own name (`func_XXXXXXXX`) beside its
C, which carries the catalogue name (`func_LNN_XXXXXXXX`); splat marks symbols by name and has none
of that name, so a catalogue name no symbol file gives is not part of the key. The setup runs in full when the dump, the splat
configuration, the tree's symbol file, the function starts or inner-call labels (from the
catalogue), the `ASM_FUNC` / `LINKER_REMNANT` entries, the functions whose trailing nops it cuts,
`levels.tsv`, `gp.tsv`, frontbin's symbol files, Python, splat, or `setup_asm.py` and the tools it
runs and imports change. `setup_asm.py --force` and `build_levels.py --force-setup` run it in full.

A level's build, like the core programs', reuses every object whose inputs did not change
(since 2026-11-28, `tools/objcache.py`, [incremental.md](incremental.md)): after a change to one
file only that file's objects are compiled and assembled again in each level that has it: a level that took
6 to 7 minutes to build takes about 25 s when nothing or one file changed. `--no-cache` builds
every object again; the bytes are the same either way.

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
| a `$gp`-relative slot (code a multiplayer level has: its `$gp` is `0x247FC0`) | `D_XXXXXXXX_sda` (`XXXXXXXX` under the story `$gp` `0x1DC8B0`) | `$gp + (XXXXXXXX - 0x1DC8B0)` ([globals.md](globals.md)) |
| an alias of one of these, `<name>_<suffix>` (for example `func_L01_00431808_0040ABCD`) | the name with a suffix | in level NN its address (`func_LNN_`/`D_LNN_`), elsewhere where the code reads it |

An alias is for code the catalogue counts as one function but that in some levels calls or reads another copy than the catalogue's place (another function with the same code, other data): the suffix (the caller's address) gives it a name of its own, whose value in the other levels comes from the bytes. In a level's tree a bare `func_XXXXXXXX` is the level's own label at that address (an assembly function of a file with C), never a front-end function, which is always `fe_func_XXXXXXXX` there.

    extern u8 D_L01_001D66B0[];
    extern void func_L01_00301558(s32 a0, u8 *a1, u8 a2);

    void func_L01_003016B0(s32 a0, u8 a1) {
        func_L01_00301558(a0, D_L01_001D66B0, a1);
    }

**Multiplayer twins that differ.** Levels 39 to 53 keep their own rows for a few functions whose
single-player twin has other bytes there (`func_L39_005A8D48`/`005A8D90` against
`func_L01_00436070`/`004360B8`: the struct they index is 0x30 smaller; `func_L39_006073C8`/`006073F0`
against `func_L01_004D2470`/`004D2498`: 0x45E0 instead of 0x4610; `func_L40_004D5970` against
`func_L01_004CE720`). They are different functions, not one row with a wrong cell
(`config/levels/split_places.tsv`), so a caller that exists only in the multiplayer levels names the
multiplayer row (`func_L39_005A8D48`, never `func_L01_00436070`), and the maps' copies share that
row with level 39. A caller shared with the story levels reaches the right copy through its alias.

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
where retail has more zero words after the function than gcc's alignment, `TEXT_FILL` where it
has the linker's `0xCDCDCDCD` fill word there: a file's last function ending 4 mod 8). After compiling,
`tools/level_symbols.py` (run by `tools/build.py`) lays each such object over the level's retail
`.text` at its file's address: the words without relocations must be retail's, and each
relocation in a C function (`R_MIPS_26`, `%hi`/`%lo`, `$gp`, `R_MIPS_32`) gives the value its
name must have there. A name gets one value per level, and where the value is known (the
table above) it must be that one; the values go to `build/levels/<NN_name>/
symbol_addrs_derived.txt`, which the level's linker script reads. A difference stops the build
naming the function and word: the C is not that function in that level.

Types (`typedef`, `struct`) that several functions of a file use go in the file's prelude; a later function's type that clashes with an earlier one of another body takes the function's address as a suffix.

**`nop`s before `div.s`/`sqrt.s`.** As in the core programs (`config/frontbin/divs_nops.txt`,
docs/wiki/Matching-Patterns.md), retail pads some `div.s` and `sqrt.s` with `nop`s that no
compiler or assembler mode keeps; `tools/asm_filter.py` puts them back from a table. The levels'
is `config/levels/divs_nops.txt`, by catalogue name (`func_L01_004DFD60 2`: one count per
`div.s`/`sqrt.s`, in order). `check.py` reads it as it is; `level_tree.py tree` writes each
level's own copy, under that level's names, to `build/levels/<NN_name>/divs_nops.txt`. Add a
function's line when its C matches with the padding (`tools/gen_divs_nops.py`'s `counts()`
reads retail's from the function's `.s`). Under `@ps2as` a `div.s` that uses the register an
`mtc1` right before it set gets Ps2EeAs's own hazard `nop`: count one less there.

**Functions that save `$ra` with `sq`.** As in the core programs (`config/frontbin/sq_ra_funcs.txt`,
docs/wiki/Matching-Patterns.md, "Functions that save `$ra` with `sq`"), some level functions save
the callee-saved registers and `$ra` with `sq` in ascending 16-byte slots (`$s0` lowest, `$ra`
highest), which no compiler or flag we have lays out; `tools/asm_filter.py` moves the saves and
restores to those slots from a table. The levels' is `config/levels/sq_ra_funcs.txt`, one
catalogue name per line, read and written as `divs_nops.txt` is: `check.py` reads it as it is,
`level_tree.py tree` writes each level's copy under that level's names to
`build/levels/<NN_name>/sq_ra_funcs.txt`. Such a function is compiled without `-fopt-stack`
(retail's `$s` saves are `sq`), and a level file has one flag line: it goes in a file of its own
that starts at it, with its own line in `config/levels/text_parts.txt`
([build-fidelity.md](build-fidelity.md), rule 1); there are no per-function flags for levels.

**Switch jump tables.** gcc writes a `switch`'s jump table into the file's read-only data
(`.rdata`, which the assembler names `.rodata`). In retail, every level's tables are in its
`.data`: one block of all the source files' read-only data in link order (Veldin's runs from
0x2BB830 to 0x2BF2C0, fenced by the linker's `0xCD` fill), each function's tables 16-aligned
and in the order of the functions, with the const arrays of some files among them; the block
does not follow `.text`'s order throughout (Veldin's starts with the tables of the code at
0x3F08C8 and has those of 0x2F78B0..0x3EB5E0 at its end), and its place differs per level. So
the build takes the place from the code: a file's `.rodata` must sit where its `%hi`/`%lo`
read it (`level_symbols.py`, `jump_table()`), and there every word must be the level's: each
entry (an `R_MIPS_32` into the file's own `.text`) the address of the same instruction in the
level, every other word (the `.align` between two tables) equal. The level's linker script is
then written for that build (`build/levels/<NN_name>/level_NN.ld`): `.text` from each file's
object instead of `text.c.o`, and the data section cut around each placed `.rodata`
(`split_data()`: the span must be whole `.word`s, its labels go with it; the pieces go to
`build/levels/<NN_name>/pieces/`). The bytes come from the compiler's own table, never from
the assembly. A file's `.rodata` is one piece: its C functions' tables must be next to each
other in every level that has them, so a file whose C tables have an assembly function's
table or other data between them in some level fails there (split the file, or match the
function between).

**Level 39's protected DNAS blocks.** 112 runs of Sony's DNAS library in the multiplayer menu are
stored encrypted, each inside a function between two stubs. Such a function is C with
`DNAS_BEGIN(function, n, driver)` and `DNAS_END(function, n, driver)` around the block
(`include/dnas.h`); after assembling, `tools/build_text.py` runs `tools/dnas.py` on the object,
which fills in the block's random words from `config/levels/dnas_blocks.tsv` and encrypts it, so
that `level_symbols.py` compares it with retail's stored words like any other object.
`tools/check.py` does the same before its diff, and `tools/dnas_blocks.py --show` prints a
function with its blocks decrypted: [dnas.md](dnas.md) has the format, the evidence and how to
write one.

Limits for now: the C must have no other data of its own (string literals, literal pools,
`.data`: the level's data is its assembly's), a C function must start 8-aligned in every
level, and the declarations a function needs from another function of its file go in the
file's prelude or in its own block.

## Counting functions (`config/inventory.tsv`, `config/levels/functions.tsv`)

The functions are found from the binaries, with rac1-decomp's rules (`tools/overlays.py
split()`, `code_size()`, `tools/overlay_remnants.py` there), the same way in every code section
(`tools/inventory.py`):

- **starts**: the section's start and the entry point; every `jal`, `bgezal` or `bltzal` target;
  the instruction after a `jr $ra` and its delay slot, past the zero words after it; after a
  `j` and its delay slot when a frame opener (`addiu $sp, $sp, -N`) follows; a frame opener right
  after a zero word; a pointer in the program's data that points just after finished code (after a jump's delay slot, never at it: a data word such as `0x00410000` that equals a delay slot's address once cut the slot off into a remnant, 2026-11-13); the
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
- **exceptions** (`config/levels/boundaries.tsv`, read by `tools/level_catalogue.py`): the rows
  whose boundaries these rules get wrong, each with retail's evidence (linker remnants in front
  of a function, a delay slot cut off by a data word that happens to equal its address, a
  function cut where data in `.text` decodes as branches or where a frontbin function's code is
  found, the linker's fill counted into a size, two variants the identity cannot tell apart).
  Most lines are level 39's: its DNAS library stores 112 blocks of its code encrypted in `.text`.
  Each follows a stub that calls a decrypt routine (0x4BD350 or 0x4F7890 on PAL) with the block's
  address, beside a record whose second and fourth words XOR to the block's length, and another
  record follows the block for the call that encrypts it again. Those words are data, but the
  rules read them as branches across other functions' starts, as jals and as pointers; a `cut`
  line gives an entry the pieces the rules make without them, with the linker's fill between two
  functions left out of both, and a start that exists only because a block word decodes as a
  `jal` to it is joined like any start a branch crosses (`tools/setup_asm.py` then keeps the
  joined row whole, above). A piece marked `o` is a row of its own though another level has its
  code: a library's small wrapper equals a game function's once jump targets are masked, and they
  call different things.
  An edit names a row the rules give and applies at all its places; the other rows keep their
  places, but for the entries a join or a cut takes in. A piece an edit makes goes to the row of its
  code when no row of that code has a place in its levels, and is a row of its own otherwise,
  so no other row's copies move. Add a line, not a rule, when a matched function shows one more
  such row; then `tools/levels.py catalogue`, the `src/levels/` markers, and `--setup` of every
  level that has it. NTSC-U's catalogue (`tools/levels.py --version us catalogue`) reads its own
  table, `config/us/levels/boundaries.tsv`, in NTSC-U names: give the same function the same
  correction there, read from the NTSC-U disc's words (its row, the remnant's length and the data
  coincidences can differ), so that `config/us/map.tsv` keeps pairing it with its twin. A PAL
  correction NTSC-U's rules already get right needs no line there; say so in that table's header.

Then each distinct function counts once (rac1-decomp's and rac2-decomp's catalogue,
`tools/level_catalogue.py`): two places are one function when their instructions are equal apart
from what linking changes (`inventory.identity()`: jump targets and address halves are masked,
except those into the resident core; constants, stack slots and field offsets are compared) and
their sizes are equal; the k-th copy of identical code in each level is one function.

- **false folds** (rac1-decomp's `split_places.tsv`): `identity()` masks the offset on any
  register that held an address anywhere in the function (its tracking is not flow-sensitive),
  so a field offset on a register reloaded later (`lw $v1, 0x68($a0); sw $v0, 0x2D8($v1)`) can
  hide a real difference between levels. `config/levels/split_places.tsv` (and
  `config/us/levels/split_places.tsv`) lists such places: each line is one group that leaves its
  row and becomes a function of its own, named after its first place. Splitting a place out
  shifts the k-th-copy order of the copies left in that level, so the list is regenerated until
  no row mixes offsets (2026-11-13: 10 families, 25 groups).

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
