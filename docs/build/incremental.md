# Incremental builds: reusing unchanged objects

Since 2026-11-28 `tools/build.py` (and so `tools/build_levels.py`, which runs it per level) keeps
what it compiles and assembles in `build/objcache/` and reuses it when nothing that could change
it has changed (`tools/objcache.py`). A build after a one-file fix compiles and assembles that
file, in every program or level that has it, and takes every other object from the cache; the
link, the flat binary and the check against the disc run every time. The output is byte for byte
a clean build's (the proof is below).

    python3 tools/build.py --target frontbin -j 8 ...          # reuses what it can
    python3 tools/build.py --target frontbin -j 8 --no-cache ... # compiles everything again
    python3 tools/build_levels.py -P 8 -j 4 --no-cache ...       # the same for the levels

`--no-cache` (or `UYA_NO_CACHE=1` in the environment) reuses nothing and keeps nothing; deleting
`build/objcache/` empties the cache. `build_levels.py` removes, after its builds, the entries
nothing has used for `--cache-days` days (default 3). The cache holds about 230 MB for frontbin,
boot_elf and four levels; every change to a tool in the keys (below) starts a new set of entries,
and the old set goes at the next prune.

## What is reused, and under which key

`tools/build_text.py` builds each source file (or each slice of a file whose blocks need different
flags) in steps, and each step's output is kept under a SHA-1 of every input that step has:

| Step | What is kept | Its key |
| --- | --- | --- |
| compile (SN's `ee-gcc -S`, `@ee29`, `@ee296`) | the compiler's assembly as it wrote it | the C text it reads (the file, or the slice `build_text.py` wrote); every header it can include, by name and bytes; the exact command (the file's `text_parts.txt` line, the project's options, the source and output paths); the compiler and every file of its toolchain folder, the runner (wibo), the `--cc`/`--ld` wrapper scripts and every `-B` folder |
| `tools/asm_filter.py` (not for `@ee29`, `@ee296`, `@eeas`) | the filtered assembly | the compiler's assembly; whether the range is `@ps2as`; the tables the filter reads: the program's (or level's) `divs_nops.txt` and `sq_ra_funcs.txt` and `config/levels/`'s |
| assemble (the driver's `-c`, or `@eeas`) | the object as the assembler wrote it | the filtered assembly's bytes; every file its `.include`s reach (`include/macro.inc`, the `INCLUDE_ASM` / `INCLUDE_RODATA` / `ASM_FUNC` files under `asm/`, and what those include); the exact command; the assembler with its bytes |
| `ld -r` of a file's slices | the file's object | the slice objects' bytes, the command, the linker and its toolchain |
| `ee-as.exe` in `build.py` (the header blobs, the data segments, the jump-table pieces) | the object | the `.s` file's bytes and every file it includes, the command, the toolchain and the runner |

Every key also has the tools that build the commands and change the output: `build_text.py` (or
`build.py`) and every module of `tools/` it imports (`asm_filter.py`, `dnas.py`, `ee29.py`,
`ee296.py`, `eeas.py`, `srcfiles.py`, `targets.py`, ...: `tools/stamps.py`'s `tool_closure()`),
the repository's path and every `UYA_*` environment variable.

The headers come from a scan, not the preprocessor (`tools/includes.py`, the one the NTSC-U
objects' reuse uses): every `#include` counts whether or not an `#if` around it is taken, in every
folder the compilers search (the quoting file's, `include/`, the root, the toolchains' own), in
every spelling a compiler can open, with the candidates that do not exist counted as missing, so
creating a header that would be found first is a change too. An `#include` the scan cannot follow
(a macro) makes the key take every header of `include/` and `src/`. A file whose flags name
another include folder or file (`-I`, `-include`, `-isystem`, ...) is never reused. Assembly is
scanned the same way for `.include`; assembly with an `.incbin`, or with an `.include` the scan
cannot follow, is never reused. The scans find a superset of what the compilers and assemblers
open: they can make a key change when the output would not, but never miss a file that changes it.

What is never reused: `tools/dnas.py`'s protection of level 39's DNAS blocks runs on every object
that has them, reused or not (the cache keeps the object as the assembler wrote it), from
`config/levels/dnas_blocks.tsv`; the link of a program, `level_symbols.py`, `core_rodata.py`, the
flat binary and `check_match.py` run every time.

A step's output is not kept when a file its key read changed while it ran (size, times or inode),
so a file edited during a build is compiled again by the next one. Each entry is one file,
`build/objcache/<2 hex>/<key>`, written to a temporary name and renamed into place, so the levels
`build_levels.py -P` builds at once share it safely (a key has the paths of the command, so each
level's objects are its own). A reused entry has its time set to now (that is what `--cache-days`
looks at).

`build_text.py` first goes through the files in its own thread and takes each file all of whose
steps can be reused; only the others go to its `-j` workers. (When everything is reused the work
is Python's, and threads only slow it down: frontbin's no-change pass takes 3.6 s in one thread and
9.6 s in twelve.)

## Proof and timings

Measured on box2 (64 threads, shared with other agents' builds at a load of 30 to 47; this run
kept to 16 jobs) on 2026-11-28, master 5ba01ef3 plus this change: frontbin and boot_elf at
`-j 8` each, at the same time ("core"), then levels 1, 16, 39 and 44 with
`build_levels.py -P 4 -j 4` (without `--setup`; their setups had been done). After each row the
SHA-1 of every object, ELF and flat binary under `build/` (10,817 files) was compared with the
clean build's.

| Build | core | 4 levels | What ran | Result |
| --- | ---: | ---: | --- | --- |
| clean (`--no-cache`) | 52.7 s | 383.9 s | everything | frontbin, boot_elf, levels 1, 16, 44 `MATCH` |
| first run with the cache (empty) | 47.8 s | 387.4 s | everything (and kept) | all `MATCH`; every ELF and binary identical |
| again, nothing changed | 9.7 s | 39.2 s | nothing: 1,713 steps reused in frontbin, 5,243 to 8,716 per level | the same |
| a comment in `src/frontbin/381080.c` and in `src/levels/shared/L01_002F7800.c` (in all four levels) | 9.8 s | 40.2 s | that file's compile (its assembly came out the same, so its object was reused) | the same |
| a code change in `L01_002F7800.c` (`i < 10` to `i < 11`) | 10.3 s | 38.8 s | 7 steps in levels 1 and 16, the two of the four that have its functions | levels 1 and 16 do not match (`func_L01_002F7808 +0x3C: the instruction differs`): the change is built |
| the change undone | 10.8 s | 40.4 s | nothing (the earlier objects) | all `MATCH`; identical |

Level 39 does not match on master 5ba01ef3 with or without the cache (`func_L39_004D7770 +0x84`,
from `level_symbols.py`); its objects were compared all the same. In every row every ELF and flat
binary is the clean build's, and so is every object but 143: the `@ee296` objects (24 of boot_elf's
core, 117 of level 39's DNAS library, which `dnas.py` protects) and the two `ld -r` objects that
hold them. Those differ between any two clean builds too: `tools/ee296.py` runs cpp0 into a new
temporary folder each time, and cc1 writes that path (`/tmp/ee296_XXXXXXXX/116FD0.i`) into the
object's file symbol, which the link drops. With that path masked, a reused object and one from a
fresh `--no-cache` build are identical: boot_elf's 198 + 24, level 39's 2,654 + 117, none
different.

Where a no-change level build's time goes (level 1 alone): `levels.py tree` 3.4 s,
`trailing_padding.py` 1.2 s, then `build.py` 19 s: `build_text.py` 12 s (a third of it the text of
the mixed-flag files' slices, which it writes every time, a third the keys), `level_symbols.py`,
the link and the check the other 7 s. Each level is one process, so a no-change or one-file
build of all 49 levels at `-P 49` on box2 is a matter of a minute or two, against 25 to 30 minutes
of compiling before.
