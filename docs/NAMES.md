# Names

Every symbol keeps its address name: `func_XXXXXXXX` in the core programs, `func_LNN_XXXXXXXX` in
level code, `D_XXXXXXXX` / `D_LNN_XXXXXXXX` for data. The build and the tools read the address (and
level) out of that name, so it is what `INCLUDE_ASM` and the `localdecomp` markers name, what C
declares and what the linker sees.

Readable names sit on top, as macros:

| File | What it is |
| --- | --- |
| `config/names.tsv` | one row per named symbol: its name, tier, source (Sources, below), the evidence for the name, and other names it has been given |
| `include/names.h` | generated from the table (`#define hero_update func_L01_004EE4E0`) for every row that is not a candidate; included by `common.h` |
| `tools/names.py` | `header` (table to `names.h`), `check` (the table is valid and `names.h` current; `tests/check_repository.py` runs it), and lookup: `python3 tools/names.py func_L01_004EE4E0` or `... hero_update` |

C writes the readable name in function definitions and inside function bodies, and the address
name everywhere else: the `localdecomp` markers, `INCLUDE_ASM`, `extern` declarations and
prototypes, `__asm__` strings. The preprocessor turns one into the other, so the objects are byte
for byte the same either way.

    /* localdecomp:start func_L01_004EF128 */
    extern u8 D_001A4BE0[];
    extern f32 func_003C4138(f32 *, f32, f32);
    void hero_approach_speed(f32 accel, f32 decel) {
        u8 *h = hero;
        ...
    }
    /* localdecomp:end func_L01_004EF128 */

Level code works the same way: a level function's catalogue name is its name in every level that
has it (docs/levels.md), so the macro holds in all of them.

In the core programs (frontbin, boot_elf, i5bootn), a definition keeps its address name for
now: `tools/pr_check.py` and `tools/setup_asm.py` find a C definition there by it. Bodies may use
readable names in either.

The tools know the names: `tools/check.py` takes a readable name on the command line and finds
definitions written under one, localdecomp compiles the editor code with `names.h` in front of it,
and `tools/gen_bytematch_names.py` points ByteMatch's source view at a definition under its readable
name.

A macro renames every use of its name, so a readable name must not be anything else in `src/` (a
local, a parameter, a field): pick one nothing there uses yet.

## Tiers

| Tier | In names.h | Meaning |
| --- | --- | --- |
| recovered | yes | the original identifier |
| descriptive | yes | a name with evidence: read in the code and checked in the running game, or read in the code |
| candidate | no | weaker (inferred, or a library name seeded from another game's build), or held back (below) |

A name is given to one symbol only. Held back as candidates for now:

- names that are already identifiers in `src/` or `include/` (`memcpy`, libgcc's soft-float
  helpers): a macro would rename those uses too;
- front-end functions (catalogue kind `frontbin`/`boot_elf`): their name is frontbin's address,
  and boot_elf's copy of the front end is at other addresses, so one macro cannot name both yet.

## Sources

- **open-rac-engine** ([github.com/manstie/open-rac-engine](https://github.com/manstie/open-rac-engine), GPL-3.0):
  a Ratchet character controller with reverse-engineering notes on R&C3 PAL and UYA NTSC-U Veldin;
  [`re/SCES-52456/symbols.toml`](https://github.com/manstie/open-rac-engine/blob/main/re/SCES-52456/symbols.toml)
  and [`re/SCUS-97353/symbols.toml`](https://github.com/manstie/open-rac-engine/blob/main/re/SCUS-97353/symbols.toml),
  and the functions its [`docs/research/`](https://github.com/manstie/open-rac-engine/tree/main/docs/research)
  notes describe by address (source `open-rac-engine docs/research/<file>`): confidence `high` and
  `medium` as descriptive, `low` as candidate.
