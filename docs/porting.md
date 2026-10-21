# How this tree was made from the US decompilation

`tools/port_from_us.py` made `src/` and the per-program tables from rac3-uya-decomp (branch
`cleanup/restructure`, commit `13cf5c5`) and the PAL programs. It is kept as the record; its
docstring has the details.

    python3 tools/port_from_us.py --us-tree US_CHECKOUT --us-baserom US_ELFS [--asm-only] \
        [--extra build/port/extra.json] [--hold build/port/hold.txt]

## 1. Functions

Every US function (an entry of the US sources) is looked for in PAL's code with the immediates of
`lui`/`addiu`/`ori`/loads/stores and the targets of `j`/`jal` masked. Long functions with one
candidate anchor the map (kept only where they stay in order), their neighbours follow by
contiguity, and a function with a single candidate between two mapped neighbours is taken too.

| Code | US functions | found in PAL | not found |
| --- | ---: | ---: | ---: |
| `frontbin` `.text` | 1,867 | 1,799 | 68 |
| `boot_elf` `core.text` | 900 | 900 | 0 |
| `boot_elf` `.text` | 1,891 | 1,828 | 63 |
| `i5bootn` `.text` | 199 | 199 | 0 |

Where nothing maps (changed or new code), the function starts are the ones splat finds there,
plus the pieces `tools/setup_asm.py` split off on its own (`--extra`). Those are `INCLUDE_ASM`.

## 2. Addresses

The relocated fields of every mapped function pair US and PAL addresses: `%hi`/`%lo` pairs,
`$gp` offsets (`$gp` is `0x1DC8B0` in both) and `jal` targets. A US name no relocation reaches is
placed by the nearest pairs around it in the same section when they agree on the shift; otherwise
it has no PAL address, and a function that names it keeps `INCLUDE_ASM`.

## 3. Source files and flags

US source files keep their place; their names are their PAL start addresses. Flags are per file
(docs/BUILD_FIDELITY.md): Sony library runs (`@ee29`) became files of their own, and a US file
was split where its non-override flag ranges change (at an 8-aligned function). A file never
starts at a 4-mod-8 function: unmapped functions in front of it move into it, or it joins the file
before it.

## 4. The all-assembly milestone (commit efcfa99)

With `--asm-only` every function is `INCLUDE_ASM` (or `ASM_FUNC` / `LINKER_REMNANT` as in the US
sources). That tree builds all three programs byte-identical to the PAL retail files.

## 5. The C

Without `--asm-only`, a US C function keeps its C when it was found in PAL, its US flags are its
PAL file's, and every name in it has a PAL address. Then the build decides:
`tools/port_verify.py --errors` holds the functions compile errors point at, `--sizes` the ones
whose compiled size is not retail's, and a function-by-function comparison of the linked program
with retail the ones whose bytes differ (`--hold`), until every program prints `MATCH`.

| Program | US functions in C | carried | flags of their own in the US | differ in PAL | names without a PAL address | not in PAL |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `frontbin` | 1,455 | 892 | 470 | 35 | 17 | 41 |
| `boot_elf` | 1,818 | 1,476 | 196 | 64 | 39 | 43 |
| `i5bootn` | 42 | 42 | 0 | 0 | 0 | 0 |
| all | 3,315 | 2,410 | 666 | 99 | 56 | 84 |

The 821 held back with a PAL counterpart are drafts in `nonmatching/<program>/` with a row each
in `nonmatching/README.md`; the 84 whose function PAL changed have no PAL name. Names (`func_`,
`D_`, `jtbl_`, with the US suffixes for aliases and second types) were moved to PAL addresses;
below `.lit` (`0x1D5680`), where the engine core's code, data and `.bss` are unchanged, an
address stays as it is.

Two things the US C needed to compile as one translation unit per file, which it was not in the US
build (mixed-flag files were compiled in slices there): a part of a US file that became a file of
its own gets the declarations of the US file's earlier blocks, and a type a file defined twice is
defined once (`--dedupe-types`). Neither changes code.
