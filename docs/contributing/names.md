# Names

Every symbol keeps its address name: `func_XXXXXXXX` in the core programs, `func_LNN_XXXXXXXX` in
level code, `D_XXXXXXXX` / `D_LNN_XXXXXXXX` for data. The build and the tools read the address (and
level) out of that name, so it is what `INCLUDE_ASM` and the `localdecomp` markers name, what C
declares and what the linker sees.

Readable names sit alongside, as a lookup table. They are **not** used in C: `#define` aliases are not allowed in matched C (AGENTS.md), so no source file or header includes `names.h`:

| File | What it is |
| --- | --- |
| `config/names.tsv` | one row per named symbol: its name, tier, source (Sources, below), the evidence for the name, and other names it has been given |
| `include/names.h` | generated from the table (`#define hero_update func_L01_004EE4E0` lines) for every row that is not a candidate; a reference list only, never included |
| `tools/names.py` | `header` (table to `names.h`), `check` (the table is valid and `names.h` current; `tests/check_repository.py` runs it), and lookup: `python3 tools/names.py func_L01_004EE4E0` or `... hero_update` |

C keeps the address name everywhere: definitions, bodies, markers, `INCLUDE_ASM`, `extern` declarations and prototypes. Use `python3 tools/names.py` to look a name up while reading or writing code.

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
- **rac1-decomp and rac2-decomp** ([OpenRAC](https://github.com/OpenRAC)): the same engine and
  libraries, so many functions have a twin there. A name comes from rac1's `config/names.tsv`
  (PAL v2.00, `SCES-50916`; its recovered and descriptive rows) or rac2's `include/names.h` and
  `symbol_addrs/usa/symbol_addrs.txt` (USA v1.01, `SCUS-97268`), and the source column names the
  file and the twin's address name there (`rac1-decomp config/names.tsv func_00121DC8`). Twins are
  found by code alone: each function becomes its sequence of opcode names (registers, immediates
  and targets masked), compared with difflib's ratio inside a size window. The evidence column
  gives the ratio, the ratio of the masked register sequences, both sizes, and whether the twin is
  unique both ways (no other function of either game as close). Tiers:
  - recovered: rac1's name is recovered there (the original identifier), the opcode and register
    sequences are identical, and the twin is unique both ways;
  - descriptive: the opcode sequence is identical and the twin unique both ways, 48 bytes or more
    (32 when the registers are identical too);
  - candidate: everything else down to a ratio of 0.90 (64 bytes or more when not identical), and
    every name held back above. Shapes that more than three functions of either game share are
    left out.
