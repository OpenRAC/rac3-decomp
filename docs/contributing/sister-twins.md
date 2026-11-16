# Twins in the sister decompilations

`tools/sister_twins.py` lists the rac3 functions still in assembly whose code is a function another
OpenRAC decompilation has already matched in C. These sisters are
[rac1-decomp](https://github.com/OpenRAC/rac1-decomp), [rac2-decomp](https://github.com/OpenRAC/rac2-decomp),
[rac4-decomp](https://github.com/OpenRAC/rac4-decomp), [rac-sac-decomp](https://github.com/OpenRAC/rac-sac-decomp)
and [rac5-sm-decomp](https://github.com/OpenRAC/rac5-sm-decomp). All of them come from the same engine
family and the same Sony SDK. The sister's C is then the starting point: port it rather than write
it again. On 2026-11-15 the first scan found 203 such functions (179 exact). Most of them have
been matched from their sister's C since.

## What it compares

Two functions are **twins** when their relocation-masked words are equal (`exact`). Functions of
20 words and more are also twins when at least 95 % of those words are equal (`near`, `--near PCT`
changes the share). The words are compared after trailing zero padding is dropped. The mask
(`tools/twin_mask.py`) keeps every bit except what a relocation fills:

- the target of `j`/`jal`;
- the immediate of a `lui` whose register reaches a load/store base or an `addiu` (an address
  `%hi`, followed along the control flow);
- the low half of such an access;
- every `$gp`-relative offset.

A `lui` that only feeds `mtc1`, `ori` or arithmetic is a constant and stays. Branch offsets,
registers, struct offsets and constants stay too. The same rule runs on both sides, from the bytes
alone. `--check-mask` measures it against splat's relocation annotations in rac3's `asm/`. On
boot_elf, the mask equals the relocations in 1,941 of 2,118 functions, and only 35 of 20,224
relocated words are left unmasked. The 744 words masked without a relocation are mostly field
offsets from a register that already holds a global's address, which the rule cannot tell from a
`%lo`. The rest are accesses to constant addresses: the scratchpad, uncached memory and hardware
registers. They make the rule a little more lenient, never stricter.

The rac3 side covers every function under 100 % in `progress/report.json` (PAL) or
`progress/us/report.json` (NTSC-U), 16 bytes and more. The sister side takes the functions each
sister has proved in C:

- **rac1, rac2, rac4:** a function of the progress report with an active C definition and no asm
  marker;
- **rac-sac and rac5-sm:** the bodies of `config/levels/bodies.tsv` (and the boot's), plus
  rac5-sm's boot functions at 100 %.

The tool's docstring has the exact rules.

## What it needs

- **rac3's dumps:** `baserom/` as for the build, with `us/` for NTSC-U. Use `--baserom DIR` or
  `UYA_BASEROM` when they live in another checkout (a worktree has none). A version whose programs
  are missing is skipped.
- **A working tree for each sister,** given as `--sister NAME=PATH`. NAME is `rac1`, `rac2`, `rac4`,
  `sac` or `rac5` (or the repository's name). The tool only reads it: it never fetches or checks
  out. Update the clones yourself first (`git -C PATH pull --ff-only`), because a stale sister
  misses its newest C.
- **Each sister's own dumps,** in its `baserom/` laid out as that repository's setup makes them
  (`--sister-baserom NAME=DIR` when they are elsewhere). A sister, or one version of it, whose
  dumps are missing is skipped, and the summary says so.
- **For `--check-mask`:** rac3's `asm/boot_elf` (`tools/setup_asm.py --target boot_elf`, or `--asm DIR`).

## Running it

    python3 tools/sister_twins.py --sister rac1=../rac1-decomp --sister rac2=../rac2-decomp \
        --sister rac4=../rac4-decomp --sister sac=../rac-sac-decomp --sister rac5=../rac5-sm-decomp
    python3 tools/sister_twins.py ... --baserom ../rac3-decomp/baserom --out twins.tsv
    python3 tools/sister_twins.py ... --include-matched     # also matched functions: a recall check
    python3 tools/sister_twins.py --check-mask --asm ../rac3-decomp/asm

The scan takes about half a minute. It prints what it read from each sister and a summary: rac3
functions per version and tier, per sister, and the distinct work items (an NTSC-U function counts
once with its PAL twin). It writes `build/sister_twins.tsv`.

## Reading the TSV

The TSV has one row per rac3 function and sister repository with a twin. Each row holds that
repository's best candidate: exact before near, then the most masked words equal, then the most raw
words equal.

| Column | Meaning |
|---|---|
| `rac3_version`, `rac3_function`, `rac3_program` | `pal`/`us`, the function's name in that version's report, and the program whose bytes were compared (`level_NN` for level code: the level of its catalogue name) |
| `rac3_size`, `rac3_file` | its size in bytes, and the source file that holds its marker (an NTSC-U function with a PAL twin: the twin's file) |
| `pal_twin` | an NTSC-U function's PAL twin (config/us/map.tsv). Matching the twin in its PAL file matches both. `-` with `rac3_file` `-`: NTSC-U's own code, whose C goes in `src/us/` (docs/build/versions.md) |
| `sister_repo`, `sister_version`, `sister_function` | the sister, the disc version it matched, and its address name |
| `sister_c_name`, `sister_source` | the name its C defines the function under, and `path:first-last` of that definition in the sister's tree |
| `tier`, `words`, `masked_equal_pct` | `exact` or `near`, how many masked words were compared, and how many are equal (100.0 for exact) |
| `raw_equal_pct` | the same share before masking. Low means many relocations differ, so many names to rename |
| `other_candidates` | other functions of that sister at the same tier (copies, or other near twins) |

## A twin is a start, not a match

Equal masked words say that the sister's C *can* compile to rac3's function. They do not say that
it will in rac3's file. Before anything is committed:

- **Names.** Rename every callee and global to rac3's address names (`func_XXXXXXXX`,
  `D_XXXXXXXX`, `D_XXXXXXXX_sda` for `$gp` slots). Readable names stay in `config/names.tsv`,
  never in the C (docs/contributing/names.md).
- **Declarations.** Carry over the sister's prototypes, structs and externs. They must agree with
  rac3's: a callee declared `void` in one file and `s32` in another changes the code. The sister's
  types are not rac3's `include/structs/`.
- **Flags.** The function compiles with its rac3 file's one flag line
  (`config/<program>/text_parts.txt`), not the sister's. A twin of a Sony library function may
  need `@ee29`, `@ee296` or `@eeas`, and only a file of that kind takes it.
- **Near twins** differ in a few words: usually a constant, an offset, or one instruction more or
  less. Read the diff before porting.

Check each port with `python3 tools/check.py FILE.c func_XXXXXXXX` in the rac3 file that owns it
(`--version us` checks a PAL function on its NTSC-U twin; `--version us --native` checks C in
`src/us/`). Then
follow the usual steps (AGENTS.md): a function counts only when the full build says `MATCH`. Credit
the sister's file in the commit message.
