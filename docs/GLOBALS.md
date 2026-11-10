# Globals, `$gp` and the names of data in C

How C here names the game's globals, how the build gives each name its value in each program,
and what is checked. It follows rac2-decomp's rules (its `tools/levels.py` LAYOUT,
`tools/build.py` `Placement.derive`, `tools/sdata_aliases.py`, `docs/COMPILER-NOTES.md`,
"Symbols, addresses and small data"), adapted to what differs in this game: rac3 has two
`$gp` values on each disc.

## Each program's `$gp`

The value is read from the retail programs, never guessed (`tools/gp.py`):

- boot_elf's `.reginfo` section holds it (`ri_gp_value`, the word at +0x14);
- every other program loads it with `la $r, _gp` into the `gpReg` field (+0x10) of the
  ThreadParam it passes to CreateThread, beside the entry (+0x4), the stack (+0x8) and the
  stack size (+0xC). The front end's copy of that function is in frontbin, in boot_elf's front
  end and in every level (PAL level 01 at 0x004D2F24, level 39 at 0x00607F54).

`tools/gp.py --write` puts the result in `config/gp.tsv` (committed, so no tool needs game data
to know it; `--check` compares it with the dumps):

| Programs | PAL (`SCES-524.56`) | NTSC-U (`SCUS-973.53`) |
| --- | --- | --- |
| boot_elf (core and front end), frontbin, levels 1-36 | `0x1DC8B0` | `0x1DC8B0` |
| the multiplayer levels | `0x247FC0` (39-53) | `0x248140` (39-55) |
| i5bootn | none (its `.reginfo` says `0x8CCCF0`; no instruction reads `$gp`) | the same |

`0x1DC8B0` is the "story `$gp`" (`gp.STORY_GP`). Its 64 KB window reaches the core's small data
(boot_elf, below `0x1D5680`) and the front end's or story level's `.lit`/small data above it.
A multiplayer level's window (`0x23FFC0..0x24FFBF` on PAL) reaches only its own `.lit` at
`0x241A00` and the memory below it: the resident core's small data is out of its reach.

`tools/targets.py` gives every target its `$gp` from the table; the level splat configurations
(`gp_value`) and linker scripts (`_gp`, both written by `tools/levels.py config`), the assembly
fixups (`tools/setup_asm.py` runs `fix_reg_names.py` and `fix_quadword_ops.py` with the target's
`$gp`: they write each `$gp` displacement as a number), `tools/level_symbols.py`,
`tools/check.py`, `tools/resolve_symbols.py`, objdiff's level targets and the NTSC-U build
(`tools/asm_build.py`) take it from there. Until 2026-11 every level was built with the story
`$gp`; the multiplayer levels still matched because their assembly and C were read with the same
wrong value, but the names in their C stood for addresses outside the level.

## Names of globals

| What | Name in C | Its value |
| --- | --- | --- |
| the resident core's data (boot_elf, below `0x1D5680`) | `D_XXXXXXXX` | the address |
| a core or front-end global under another C type | `D_XXXXXXXX_<suffix>` (`_b`, `_f`, ...) | the address |
| level data | `D_LNN_XXXXXXXX`: its address in level NN | in level NN the address, elsewhere read from the bytes |
| a level's own copy of something the catalogue counts as one | `<name>_<caller>` (docs/levels.md, aliases) | in level NN its address, elsewhere read from the bytes |
| **a `$gp`-relative slot read by code in programs with different `$gp`** | `D_XXXXXXXX_sda` | `$gp + (XXXXXXXX - 0x1DC8B0)` in every program |

### `D_XXXXXXXX_sda`: the `$gp` slots

Much code the catalogue counts as one function reads the same `$gp` offset in every program that
has it; in a multiplayer level that offset is the level's own copy of the variable, at another
address. `D_XXXXXXXX_sda` names such a slot by its address under the story `$gp`:

    extern s8 D_001DA700_sda;     /* $gp - 0x21B0: 0x001DA700 in levels 1-36, 0x00245E10 on PAL 39-53 */

- `XXXXXXXX` is the slot's address in a program with the story `$gp` (`$gp` offset plus
  `0x1DC8B0`), so in the core, the front end and levels 1-36 the name is the same address as
  `D_XXXXXXXX`, and code carried between them keeps its digits.
- In a program with another `$gp` G it is `G + (XXXXXXXX - 0x1DC8B0)`. The value is stated, not
  read from the bytes: `tools/level_symbols.py` (`Level.expected()`), `tools/check.py` and
  `tools/resolve_symbols.py` compute it with `tools/gp.py sda_value()`, and a use that reads
  another address stops the build.
- Use it for a `$gp`-relative global that code a multiplayer level has reads at the same offset
  in every program that has the code. A plain `D_XXXXXXXX` there is a core address the level
  cannot reach through its `$gp`, and the build says so (below). Story-only code may keep
  `D_XXXXXXXX`.
- Where the offset differs between the levels (data in the levels' `.lit`/`.bss`, which moves
  with each level's layout), the global is level data: `D_LNN_XXXXXXXX`, its real address in level
  NN (for a multiplayer level, under that level's `$gp`), read from the bytes elsewhere. The build
  tells the two apart: an sda name whose slot moves fails in the level where it does.
- On NTSC-U a slot name in a multiplayer level is read from the bytes (its slots are not checked
  to be at the same offsets as PAL's).

This is rac2-decomp's `D_XXXXXXXX_sda` (there "a second, `$gp`-relative declaration of
`D_XXXXXXXX`"): rac2 has one `$gp` for every program, so its sda name is always the same address;
here the suffix also says that the address follows the program's `$gp`.

### Making the compiler use `$gp`, or not

Every game file is compiled with `-G8` (`config/*/text_parts.txt`), so the compiler addresses an
`extern` of 8 bytes or less through `$gp` and anything larger, or of unknown size, through
`%hi`/`%lo`. Where retail does otherwise, the declaration says so with a section attribute, as
rac2-decomp's `MACRO_ADDR` / `NOT_SDA` do (rac2's own `sda`/`nosda` attributes need its patched
compiler; this repository uses SN's):

    extern int D_L01_001E001C __attribute__((section(".sdata")));   /* through $gp */
    extern u8 D_00142725 __attribute__((section(".data")));         /* through %hi/%lo */

Never shorten or lengthen a type to steer `-G`; give the real type and the attribute.

#### Small data at an offset stays out of delay slots

A global the compiler takes for small data (8 bytes or less, or `section(".sdata")`) is
addressed unsplit, as a macro that Ps2EeAs expands (`lui $at` + load when the symbol's size is
not known yet, `$gp` in a delay slot). What decides whether reorg may move such a load into a
delay slot is its address. SN cc1's `simple_memory_operand` (config/mips/mips.c, with its `CONST`
case `#if 0`'d out, as in Cygnus 2.9-ee) counts a bare `symbol_ref` as one instruction but
`symbol+offset` as two. So a field read at a nonzero offset is never put in a delay slot, and the
compiler still does not split it into `%hi`/`%lo`. A plain scalar `extern` gets one instruction,
and its load can be taken into a delay slot.

Retail shows the second form for the hero tunables in the levels' `.lit`. In the state deciders
(func_L09_0051CD50, func_L02_004DA1D0, func_L04_00513880, func_L19_004F9D80) a `bc1f` is filled
from its target there, not with the load from its fallthrough, and in func_L08_004D6580's case
0x66 no slot is filled with these loads. Declare such a run of values as one array in small data
and index it, never as separate scalars:

    extern f32 D_L09_001DBDCC[] __attribute__((section(".sdata")));  /* [0] 0.82, [3] 6.17 */
    ... D_L09_001DBDCC[3] * 0.02f * 0.85f ...

The same applies to a pointer to a global passed as an argument. As an incomplete `u8[]`, the
pointer is split (`lui` plus a later `addiu`, or CSE'd onto another base). With `section(".sdata")`
it is one `la`, which Ps2EeAs expands to an adjacent `lui`/`addiu` pair (func_L19_004F9D80 passes
`D_001A4C60` this way).

## What the build checks

`tools/level_symbols.py` (run by `tools/build.py` for every level) lays each object with C over
the level's retail `.text` (rac2-decomp's `Placement.derive`):

- `%hi`/`%lo`, `jal`, `R_MIPS_32` and `$gp` relocations each give the value their name needs; a
  `$gp` access's value is the level's `$gp` plus retail's offset minus the object's;
- a name gets one value per level, and a name that states its value (the table above) must have
  it: "`D_001DA700` is `0x001DA700` in level 45, the code needs `0x00245E10`";
- a plain core name read through `$gp` in a level whose `$gp` is not the story one is refused
  with the hint to use `D_XXXXXXXX_sda`;
- the values go to `build/levels/<NN_name>/symbol_addrs_derived.txt` and the level must still
  link to retail's SHA-1.

The core programs link with `config/<program>/symbol_addrs_resolved.txt`
(`tools/resolve_symbols.py`: every name at its address, an sda name at its slot) and are compared
byte for byte, as are the NTSC-U programs (`tools/asm_build.py --version us --c`, which reads the
names' values from the NTSC-U bytes the same way).

`build/levels/globals.tsv` (`tools/level_globals.py`, after a level build) lists every name the
level C uses with its value in each level: the names whose value differs between levels are the
levels' own copies, rac2-decomp's `data_copies`.

## Compared with rac2-decomp

| | rac2-decomp | rac3-decomp |
| --- | --- | --- |
| `$gp` per program | one for all programs, per release (`levels.LAYOUT`: us `0x1AEFF0`, pal `0x1AF070`) | per program, read from retail (`config/gp.tsv`): story `0x1DC8B0`, multiplayer `0x247FC0` / `0x248140` |
| `$gp`-relative names | `D_XXXXXXXX_sda`, `SDATA()` (`__gp` assembler alias, `tools/sdata_aliases.py`) | `D_XXXXXXXX_sda`, a slot that follows the program's `$gp`; no assembler alias (a stock compiler) |
| forcing `$gp` or not | patched compiler: `sda`/`nosda` attributes, `MACRO_ADDR`/`NOT_SDA` | `section(".sdata")` / `section(".data")` on the `extern` |
| a level's own copy | `ref_LNN_XXXXXXXX_kk`; OpenRAC's `data_copies`/`level_twins` (`copycalls.py --twins`) | `D_LNN_`/`func_LNN_` read from the bytes outside level NN; `<name>_<caller>` aliases; `build/levels/globals.tsv` |
| symbol resolution | `Placement.derive` per program, no resolved file | `resolve_symbols.py` (names that state addresses) plus `level_symbols.py` (values from the bytes) |
| placement checks | `build.py`: "gp access at +X differs", "X would be at ..." | `level_symbols.py`: the same derivation, the `$gp` slot rule, one value per name per level |
| flags and `-G` | per file, `-G0` default, `-G2..-G128` | per file, `-G8` for the game, `-G0` for i5bootn and some boot_elf files |
| fcheck's `$gp` window | a `$gp` access must fall in `$gp`'s 64 KB window | no fcheck; the derivation computes every `$gp` value inside the window by construction |
