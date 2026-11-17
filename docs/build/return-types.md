# Return types: definitions against declarations

`tools/check_return_types.py` lists every function whose C definition and the declarations other
C uses for it disagree on the return type, as the EE ABI returns it. For a function that is still
assembly, it compares the declarations with each other. **It only reports: the exit code is 0
whatever it finds, and CI does not run it.** Fixing the conflicts is a separate decision.

## Why it matters

The build compiles each source file on its own, and a file matches when its bytes equal retail's.
A caller's prototype only decides what the caller does after the `jal`: it reads `$v0`, reads
`$f0`, or reads nothing. So a caller can declare `s32 func_X()` for a `void` or `f32` function and
still match, as long as retail's code reads that register or ignores it.

A tool that links all the C together (OpenRAC's port) compiles each call against the caller's
prototype and the callee against its definition. Then it reads the result from the wrong place.
rac2-decomp found 989 such functions (commit 005bfc4dd). There, a `float` sound function that its
callers declared `int` silenced every 3D sound in the port.

## What it measures

Every `.c` under `src/` is parsed by clang (`-fsyntax-only -Xclang -ast-dump=json`, MIPS target,
`-I include -I .`). Each function declaration gets a return class: file scope, block scope, header
prototypes, and C89 implicit declarations at a call (`int f()`, as gcc 2.95 makes them). So does
each definition.

| Class | C types | Returned in |
| --- | --- | --- |
| `void` | `void` | nothing |
| `int32` | `char`, `short`, `int`, enums | `$v0` |
| `int64` | `long`, `long long` (both 64-bit on the EE) | `$v0` |
| `int128` | `mode(TI)` | `$v0` |
| `float` | `float` | `$f0` |
| `double` | `double` (software floating point) | `$v0` |
| `pointer` | any pointer | `$v0` |
| `aggregate` | `struct`, `union` | depends on its size |

Declarations are grouped by the function they name, the way each version's build resolves names:

- An address name's suffixes are dropped. `func_003ABE48_A6520` and the per-caller aliases
  (`<name>_<caller>`) stand for their base's function: `tools/resolve_symbols.py` and
  `tools/level_symbols.py` give them its address. `func_11F0A0` is `func_0011F0A0`.
- An asm label (`__asm__("func_L07_00353D60")`) is the linker name.
- `D_` and `jtbl_` names are data, so they are skipped. Static functions are skipped too.
- Each program has its own addresses. An address below `0x1D5680` is the resident engine core
  (boot_elf) in every program except i5bootn.
- Level C is read the way a level's tree has it. Front-end names are frontbin's functions, written
  as `fe_func_` there (`tools/level_tree.py`). A bare address in `src/levels/<NN_name>/` is level
  NN's own function at that address, under its catalogue name.
- **PAL**: the C in `src/`, outside `src/us/`.
- **NTSC-U**: `src/`'s shared C, renamed through `config/us/map.tsv` the way the port renames it
  ([versions.md](versions.md)), and `src/us/`'s own C under its NTSC-U names (`func_U_` names
  NTSC-U addresses). A PAL definition whose function differs on NTSC-U (status `differs` or `none`)
  is not NTSC-U code, so it is left out of the NTSC-U count. A PAL name with no NTSC-U twin is
  shown as `pal:<name>`.

## Running it

It needs clang (any recent version; set `$CLANG` to choose one). It does not need a toolchain or
game data. On 16 threads it takes about 35 s for all 6,317 files.

    python3 tools/check_return_types.py                    # counts, then one entry per conflict
    python3 tools/check_return_types.py --summary          # counts only
    python3 tools/check_return_types.py --version pal --details   # every declaration of each conflict
    python3 tools/check_return_types.py --tsv build/return_types.tsv   # all of it, one row per declaration
    python3 tools/check_return_types.py src/levels/shared/L01_002F7800.c   # some files only
    python3 tools/check_return_types.py --save-scan scan.json   # keep what clang found ...
    python3 tools/check_return_types.py --from-scan scan.json   # ... and report from it without clang

`--strict` exits 1 when there is a conflict or a file clang could not parse. It is there for when
the conflicts are fixed. Today it fails.

clang parses a copy of each file. The sources are never changed. In that copy:

- asm statements are blanked, because VU0 operands and EE constraints fail the MIPS target's
  checks (asm labels stay);
- multi-line strings are split;
- the system headers libgcc includes are empty stubs.

A file that still has clang errors keeps its declarations, and the report lists it with its first
error. Most of these errors are conflicting K&R redeclarations, bit-fields wider than clang's
32-bit `long`, or gcc-only builtins. None of them changes a return class.

Deep expressions can overflow clang's stack. `func_L01_0045AA30` has a cast chain 600 casts deep.
It overflows clang's stack at 8 MB, both clang 23 on Windows and libclang 21 on Linux. With 64 MB
it parses.

- **On POSIX**, the tool gives clang the hard stack limit.
- **On Windows**, a program's stack size is fixed. So when clang crashes, the tool blanks the line
  clang was parsing and parses the file again. The report names the file and the line.

## Figures (2026-11-16, master f47c3ad3, clang 23.1.5)

| | PAL | NTSC-U |
| --- | ---: | ---: |
| functions declared or defined in C | 15,348 | 15,638 |
| conflicts | 1,113 | 1,164 |
| without the C89 implicit declarations | 1,032 | 1,075 |
| `void` vs `int32` | 717 | 749 |
| `int32` vs `pointer` | 189 | 199 |
| `void` vs `pointer` | 126 | 129 |
| `void` vs `float` | 28 | 29 |
| `void` vs `int32` vs `pointer` | 24 | 29 |
| `int32` vs `int64` | 19 | 18 |
| the rest (`void` vs `int64`, `double`, other mixes of three or four) | 10 | 11 |
| by program: boot_elf / frontbin / i5bootn / levels | 249 / 165 / 1 / 698 | 263 / 168 / 1 / 732 |

952 of the PAL conflicts involve a C definition. The other 161 are functions that are still
assembly, whose declarations disagree with each other. 80 files keep clang errors, and one
(`src/levels/shared/L01_0045A6F0.c`) is parsed again with its cast chain blanked.
