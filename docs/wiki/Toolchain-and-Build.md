# Toolchain and build

> **PAL repository.** These pages come from rac3-uya-decomp, the US project this repository was made
> from (CREDITS.md). The workflow and the matching patterns apply unchanged; function addresses in
> examples are mostly the US ones, and flags here are per source file, never per function
> (docs/build/build-fidelity.md). The level code and the self-hosted progress job are not part of this
> repository yet.

How `make` turns the repo into a byte-identical `frontbin.elf`, and which files you touch when a function needs something special. `boot_elf.elf` and `i5bootn.elf` are built the same way from their own tables (`config/<target>/`, see `docs/build/targets.md`); `make` builds and checks all three.

## Pipeline

1. `asm/header.s` (the retail ELF header) and the data segments `asm/data/{lit,data_a,data_b,lvl_vtbl,lvl_camvtbl,lvl_sndvtbl}.data.s` are assembled with `bin/ee-as.exe`.
2. `src/frontbin/*.c` (one file per original source file, listed in `config/frontbin/src_files.txt`) are built by `tools/build_text.py`. Each file is compiled with its flags from `config/frontbin/text_parts.txt` (in slices if some functions need other flags), giving one object per file in `build/src/frontbin/` (the per-slice objects go in `build/src/frontbin/slices/`), and the objects are joined with `ld -r` into `build/src/text.c.o`. See `docs/source_files.md`.
3. `ee-ld.exe -T linker_scripts/frontbin.ld` places every section at its retail file offset. `INPUT(config/frontbin/symbol_addrs_resolved.txt)` supplies the address of every external symbol. The `.data` output is `data_a` + `text.c.o(.rodata)` (all switch jump tables, in function order) + `data_b`, the same layout the original linker produced.
4. `ee-objcopy -O binary` makes `build/frontbin.bin`, and `tools/check_match.py` compares its SHA-1 with the one in `config/splat/frontbin.yaml`. That is the `MATCH` line.

`make objdiff` also builds the objdiff inputs, one unit per source file: `build/objdiff/target/frontbin/<file>.o` (the full build) and `build/objdiff/base/frontbin/<file>.o` (the same file with every `INCLUDE_ASM` compiled away), so objdiff reports decompiled/total per file. It also builds `build/objdiff/base/common.o`, the base of the `levels/common` unit, from the common-level C in `src/levels/common/` (`tools/objdiff/common_c_base.py`, which runs `tools/build_common_c.py` against the reference files in `C:\decomp-refs`; without them it writes an empty base).

`tools/build.py` runs steps 1 to 4 on Linux and macOS through wibo.

## Compiler and flags

- Compiler: SN ee-gcc 2.95.3 v1.36 (`bin/ee-gcc2953.exe`).
- Every frontbin and boot_elf range: `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division`. i5bootn uses `-O2 -G0 -fopt-stack -mno-check-zero-division` (nothing there uses `$gp`) and no VU0 flag; it builds the same at every VU0 range.
  - `-mvu0-use-vf0-vf2` (Sony's patch-set option, "Specify the range of vu0 registers to use") makes `$vf1` and `$vf2` allocatable for the `j` asm constraint that the [VU0 j-form](Matching-Patterns#vu0-j-form-one-asm-statement-per-instruction) uses. It also raises `n_non_fixed_regs`, which loop.c uses in its hoisting and strength-reduction thresholds, so it changes ordinary code too. N = 2 is the only range that fits every j-form match and the whole build; it has been on every line since 2026-10-07.
  - `-fopt-stack` (SN-only) saves `$s` registers with `sd` in 8-byte slots instead of `sq` in 16-byte ones.
  - `-mno-check-zero-division` drops the `break 7` trap after `div`.
  - `-G8` puts objects of 8 bytes or less in small data (`$gp`), which is why declarations matter ([Matching patterns](Matching-Patterns#globals-gp-vs-lui)).
- Some ranges add `-mno-split-addresses`. A few files or functions differ in other flags: `3958F0.c` adds `-fno-force-mem` (five of its functions have overrides without it), `func_00394060` adds `-fno-rerun-loop-opt`, and three boot_elf core functions drop `-mno-check-zero-division`.
- The Makefile adds `-B$(TOOLBIN)/ee-` so gcc uses `bin/ee-as.exe`, and `-Wa,...` options for the GNU assembler that the `INCLUDE_ASM` stubs need.

## text_parts.txt

One line per range: a start address, then the flags used from there up to the next line.

```
0x0037D100     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
0x0037D1A8     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses   # single-function override
0x0037D200     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as   # single-function override
0x0037DC30     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
```

Every source file starts with a line at its first function's address: those are the file's flags. A **single-function override** is two lines: one at the function's address with its flags, and one at the next function's address that restores the file's flags. Mark the first with `# single-function override`. The build compiles such a file in slices (see `docs/source_files.md`).

The build groups a run of lines with **equal flag lists** into one slice. Two adjacent `@ps2as` overrides therefore become one slice, and the first function's `.extern` hints then reach the second. Writing the same flags in another order makes the lists unequal and keeps the slices apart (the large-function batch used this for `func_003D2878`); per-function alias names in the later block are the other fix. The same rule is why `-mvu0-use-vf0-vf2` was put first on the lines that didn't have it: appending it would have made more neighbouring lines equal, merged their slices and exposed declaration conflicts (the first in `39FFC8.c`). Copy a neighbour's flags exactly as written when you add a line.

Pseudo-flags, expanded by `build_text.py`, localdecomp and `check.py`:

| Flag | Effect |
|---|---|
| `@ps2as` | Assemble with `ee/bin/Ps2EeAs.exe`. Adds `-DNO_MACRO_INC` and drops `-Wa,` options, which Ps2EeAs doesn't understand. The range (file or slice) must contain no `INCLUDE_ASM`. |
| `@newas` | Assemble with `ee/bin/as.exe` (May 2001). |
| `@ee29` | **Compile** with Sony's ee-gcc 2.9-ee-991111 instead of SN's compiler (`tools/ee29.py`). The assembly goes to the range's assembler without `asm_filter.py` (Sony's library objects don't have SN's short-loop padding). Write only options 2.9-ee knows on such a line (i5bootn's libgcc uses `@ee29 -O2 -G0`). |
| `@ee296` | **Compile** with Sony's ee-gcc 2.96-ee-001003-1 (`tools/ee296.py`), also without `asm_filter.py`. Level 39's DNAS2 library uses `@ee296 @newas -O2 -G0`: write `@newas` too (below). |
| `@eeas` | **Assemble** with Sony's ee-as 2.10-ee-001003-1 (`tools/eeas.py`) instead of the driver's assembler, without `asm_filter.py`. In place of `@newas`/`@ps2as` (a line names one assembler); combines with `@ee29` and `@ee296` (below). |

gcc uses the last `-B` on its command line, so a range's assembler choice wins over the Makefile default.

`@ee29` is for library code that came prebuilt with Sony's own compiler (i5bootn's libgcc in `src/i5bootn/libgcc/`; see `docs/compiler_matrix_i5bootn.md`). It runs the 2.9-ee **driver** (`bin/ee-gcc.exe`, never `cc1` directly: the driver defines `__mips__`, `__R5900__` and the other target macros libgcc's `longlong.h` depends on), with its `lib/gcc-lib/ee/<version>/` folder passed explicitly as `-B` (and its `include/` as `-I` when there is one). Where it is:

- `make`: the `EE29` variable, default `C:/tools/testfolder/ee-gcc2.9-991111`, or the `UYA_EE29` environment variable (`make EE29=D:/cc/ee-gcc2.9-991111`).
- `build.py`, `build_text.py`, `check.py`, `try_in_context.py`, `permuter_setup.py`: `--ee29 DIR` or `UYA_EE29`, same default. On Linux and macOS the Windows driver runs through `UYA_RUNNER` (wibo). A folder with a Linux `bin/ee-gcc` instead (Sony's 2.9-ee-991111-01) works too, for experiments; committed code must match with the Windows 2.9-ee-991111, which the maintainer's build uses.
- localdecomp: `UYA_EE29`, same default.
- `check.py --flags=@ee29` compiles any function with it.

The Windows 2.9-ee `cpp` rejects `#line 1 "file"` (it writes `# 0`, which its `cc1` refuses); `tools/ee29.py` turns those into `#line 2`, so compiler messages in that stretch are one line late. `regalloc.py` takes it in `--flags` (`--flags "@ee29 -O2 -G0"`).

`@ee296` is for the code Sony's ee-gcc 2.96-ee-001003-1 built: level 39's DNAS2 library (`PsIIdnas2no 300`, population B in [Matching patterns](Matching-Patterns#code-from-another-compiler-sibcall)), and by the same test i5bootn's newlib `exit()` and boot_elf's newlib region. Measured 2026-11-14 with `-O2 -G0`: `exit()` (`func_008006E0`), `atexit()` (`func_00116FD0`) and six DNAS functions byte-identical, and 17 of the 35 DNAS functions held for "another compiler" with their workers' C unchanged.

- The compiler exists only as **i386 Linux** programs: `lib/gcc-lib/ee/2.96-ee-001003-1/cpp0` and `cc1` from the SDK tree the binutils come from (`AngheloAlf/sce_ps2_sdk_24`). That folder's Windows `cc1.exe`/`cpp.exe` are SN's 2.95.3 v1.07, not 2.96, and there is no 2.96 driver, so `tools/ee296.py` runs `cpp0` with the predefines of the folder's `specs`, then `cc1` with the range's options (only options 2.96 knows: no `-fopt-stack`, no `-mvu0-use-vf0-vf2`). A `bin/cpp0` or `bin/cc1` in the folder is used instead of gcc-lib's: a wrapper for a system without a 32-bit loader (NixOS: the Nix glibc's `ld-linux.so.2`, as `native-bin/` does for the binutils; on a Mac presumably the linux/386 container the binutils use, untested). Windows can't run it directly (WSL, untested).
- Where it is: `--ee296 DIR` (`check.py`, `try_in_context.py`, `build.py`, `build_levels.py`, `build_text.py`, `c_objects.py`, `version_map.py`; `carry_us.sh` passes `$TOOLCHAINS/ee296`) or `UYA_EE296`, default `~/Projects/RAC/rac3-toolchains/ee296`. `permuter_setup.py` and the permuter engine refuse an `@ee296` range; localdecomp doesn't know it yet.
- Assemble with **`@newas`**: the default `bin/ee-as.exe` puts load-delay `nop`s after `mtc1`/`mfc1` that the 2.96 objects don't have (`func_L39_004D5A40`: 30 diff with it, MATCH with `@newas` or the native `ee-as` 2.10-ee-001003-1).
- What it does by default that no flag gives SN or 2.9-ee: 8-byte save slots with `$ra` saved last and restored last, sibling calls, argument and return-value moves hoisted above a branch, an alignment `nop` after a `b` (labels after a barrier 8-aligned, without any `-malign` option) and two `nop`s before `div.s` (`-mhandle-ee-div-pipeline-bug` is on; the `divs_nops` table is not needed). `float` to `unsigned` is converted inline (`li.s 2^31; c.le.s; cvt.w.s`). `-O3` gives the same as `-O2` on everything tried; `-O1`, `-Os` and `-G8` don't match (`exit()` needs `-G0`).

`@eeas` assembles a range's assembly with Sony's own assembler, the binutils 2.10-ee-001003-1 of the SDK release the 2.96 compiler comes from, instead of one of SN's (`bin/ee-as.exe` and `ee/bin/as.exe` are both GNU as 2.9-ee-991111b). Sony's library objects were assembled with it. The difference is in reorder mode: when the compiler leaves a `jal`/`jr` delay slot to the assembler and the instruction before it is a macro that expands to several (`lw $4,67268($16)`, `la`, `dli`), ee-as 2.10-ee puts the expansion's last instruction in the slot; SN's assemblers leave a `nop`.

- The compiler step is unchanged (SN's compiler, or Sony's with `@ee29`/`@ee296`); `tools/eeas.py` then runs ee-as on the `.s` instead of the driver's `-c` step, with what the driver's specs would pass (`-G<n> -EL -O2 -mabi=eabi`, `-O3` for `-O3`, no `-O` for `-O0`/`-Os`) and the build's `-Wa,` options (`-I include -mips3 -mcpu=5900 -mabi=eabi`). No `asm_filter.py`: its short-loop and divide padding are SN's assembler's.
- One assembler per line: `@eeas` with `@newas` or `@ps2as` is an error (`tests/test_tools.py` checks every table).
- Where it is: `--eeas PROGRAM` (`check.py`, `try_in_context.py`, `build.py`, `build_levels.py`, `build_text.py`, `c_objects.py`, `version_map.py`) or `UYA_EEAS`. There is no default: a file that asks for `@eeas` without either stops with an error naming `UYA_EEAS`. It is the same i386 Linux program as the binutils `asm_build.py` uses, so `UYA_EEAS=$UYA_BINUTILS/ee-as` (`rac3-toolchains/native-bin/ee-as`; `mac-bin/ee-as` on a Mac, untested); `carry_us.sh` passes `${UYA_EEAS:-$UYA_BINUTILS/ee-as}`, with `UYA_BINUTILS` defaulting to `sn-prodg-24-ee/gcc/bin`. An i386 program cannot stat files on a filesystem with 64-bit inode numbers (`Value too large for defined data type`; a FUSE share): build from a checkout on a normal disk.
- `check.py --as eeas` (or `--flags=@eeas`) assembles any function with it, in place of its line's assembler. `permuter_setup.py` and the permuter engine refuse an `@eeas` range; localdecomp doesn't know it yet.
- Measured 2026-11-14 on level 39: eleven held library functions whose C compiles to retail's instructions (seven `@ee296`, four `@ee29`) MATCH with it and are 2 to 171 diff with SN's assemblers; every already matched function of their seven files MATCHes with either. Level 39 still builds to MATCH with `@eeas` on all 169 of its `@ee29`/`@ee296` lines (638 C functions, 392 assembly blocks). i5bootn's libgcc does not take it everywhere: with `@eeas` on its 17 `@ee29` lines, 198 of its 199 functions match, but `func_00801778` (`801778.c`, today `@ee29 @newas`) does not, so it is a per-file choice, not a default.

## localdecomp_flags.txt

`config/frontbin/localdecomp_flags.txt` gives a **work-in-progress** function its own flags in localdecomp and `check.py` while it is still `INCLUDE_ASM` in its source file (an `@ps2as` range can't contain the asm stub, so `text_parts.txt` can't hold it yet):

```
func_0039BEC0 -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
```

The line replaces the range's flags, so it needs `-mvu0-use-vf0-vf2` too (the two lines in the file on 2026-10-07 predate the flag). When the function matches, move its flags to a single-function override in `text_parts.txt` and delete the line. `pr_check.py` warns about leftovers.

## Symbol files

| File | Used by | Holds |
|---|---|---|
| `config/<program>/symbol_addrs_resolved.txt` | the linker | `NAME = 0xADDR;` for every external symbol, including per-function aliases. Add yours here. |
| `config/<program>/symbol_addrs.txt` | splat | Names for splat's disassembly |
| `config/<program>/undefined_syms_auto.txt`, `undefined_funcs_auto.txt`, `reloc_addrs.txt` | splat | Generated by splat. Don't edit by hand. |

## include/

- `common.h`: the `s8`...`f64` typedefs and `include_asm.h`.
- `include_asm.h`: the `INCLUDE_ASM` and `INCLUDE_RODATA` macros (the latter pulls an asm function's jump table from `asm/nonmatchings/text/rodata/`), the `OBJDIFF_BASE` switch that compiles stubs away, and the `NO_MACRO_INC` guard for `@ps2as` ranges.
- `macro.inc`, `labels.inc`: splat's assembler macros for the stubs.

## CI

`.github/workflows/build-and-report.yml` runs on pushes to `master`, on the maintainer's self-hosted Windows runner that has the toolchain and retail files. It builds, requires `MATCH`, and uploads an objdiff progress report. It does not run on pull requests from forks (the runner holds copyrighted files and must not run untrusted code), so reviewers build PRs locally.

## Level overlays

Level overlays are counted in progress reports through target objects made from your own unpacked overlays. They're derived from retail code, so they are never committed. Decompiling them has started with a few shared functions in `src/levels/common/`, checked by the opt-in `tools/build_common_c.py` (not part of `make`; see `docs/common_level_c.md`).

About 95% of the code in the 51 overlays is shared: the same function appears, at different addresses, in two or more of them. Reporting each overlay on its own made decomp.dev show about 100 MB of level code to decompile when only about 9.4 MB is distinct. So the report is split:

| Category | Unit(s) | What it counts |
|---|---|---|
| Common level code | `levels/common` | every function that appears in two or more overlays, once (about 4.3 MB, 7,779 functions) |
| Level-specific code | one unit per level | functions found in only one overlay (about 5.1 MB) |
| Level N: Name | the level's code unit | that level's specific code |
| Common level data | `levels/common data` | `.data`/`.lit` content found in two or more overlays, once (about 0.26 MB) |
| Level-specific data | one `(data)` unit per level | the rest of each level's non-zero data, plus its `lvl.*` vtables (about 0.49 MB) |

"Same function" means the same bytes once `j`/`jal` targets are masked. Data has no function boundaries, so it is matched by content: a 16-word window (at least 8 words non-zero) that occurs in two or more overlays is shared, with address-like words treated as wildcards because shared data holds pointers that move. This is meant for progress numbers. Its run boundaries are approximate, so it isn't a guide to where data sits in a real level build.

`.bss` (52.7 MB over all levels) and zero words inside `.data`/`.lit` (8.0 MB) have nothing to decompile, only a size. They are written to `uninitialised.o` but left out of `objdiff.json` so they don't swamp the data total. Pass `--include-zero-fill` to list them as a "Zero-filled data" category.

The pipeline runs outside the repo, in two steps:

```
python3 tools/objdiff/gen_level_targets.py <levels_dir> C:\decomp-refs\level-targets
python tools/objdiff/split_shared_levels.py C:\decomp-refs\level-targets C:\decomp-refs\level-targets-split --objdiff objdiff.json
```

The second step writes 105 objects (`common.o`, `common_data.o`, `uninitialised.o`, 51 code objects, 51 data objects) and rewrites the level units and categories in `objdiff.json`. Only the script and `objdiff.json` are committed. The tool refuses to write into the repo (other than `build/`). Re-run it if the overlays are regenerated or a level starts being decompiled.

## Other executables

`boot_elf.elf`, `i5bootn.elf`, `ntgui.elf` and `sly2.elf` (from the unpacked disc) are also counted. They have no symbols, so `tools/objdiff/gen_exe_targets.py` finds functions the way the level generator does (every `jal` target, then splat), but builds each object straight from the ELF bytes, so the code is retail by construction. It writes `<name>.o` (code sections) and `<name>_data.o` (other allocated sections with bytes: `.data`, `.rodata`, `.lit`, `.irx`, VU microcode) to `C:\decomp-refs\exe-targets\`, and with `--objdiff objdiff.json` adds their units and categories (one per executable, all under "Other executables"):

```
python tools/objdiff/gen_exe_targets.py "<game_dir>" C:\decomp-refs\exe-targets --objdiff objdiff.json
```

About 3.0 MB of code in 15,146 functions and 6.6 MB of data. The objects have no relocations and are never committed. `.bss` and `.sbss` are left out (nothing to decompile). The main executable `SCUS_973.53` is not among these files and isn't counted yet.
