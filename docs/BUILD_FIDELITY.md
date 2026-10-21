# Build fidelity

What "matched" means here and the rules that keep the build honest. They are rac1-decomp's
(its `docs/BUILD_FIDELITY.md`), applied to this repository.

## What "matched" means

A function is matched when its C in `src/` builds, through `tools/build.py` (or the Makefile),
into the bytes retail has at its address, and the whole program still links byte for byte: the
build prints `MATCH` with the program's SHA-1. `tools/port_verify.py` and `tools/check.py`
compare single functions; neither replaces the full build.

## The rules

1. **Flags apply to whole files.** `config/<program>/text_parts.txt` has one line per source file
   (`tests/test_tools.py` and `tools/pr_check.py` check it). A function that needs options its
   neighbours do not was in another object in retail or is not matched yet: it stays
   `INCLUDE_ASM`. The US project matched many functions with a flag range of their own (a
   "single-function override", or `@ps2as` for one function); those are not carried here as
   matched. Their US C is in `nonmatching/<program>/` as a draft (docs/porting.md).
2. **Library code is its own files.** Sony's library code was compiled by Sony with Sony's ee-gcc
   2.9-ee-991111, separately from the game: a run of such functions is a file of its own with
   `@ee29` flags, and libgcc's members are rebuilt from GCC's own source (src/libgcc/README.md).
3. **No step may change what the compiler emitted**, except what retail's assembler or linker did
   to that code. The steps that do this are the US project's (`tools/asm_filter.py`: the
   short-loop and divide padding of SN's assembler, `sq`/`lq` saves of `$ra` for the functions in
   `sq_ra_funcs.txt`), documented in docs/wiki/Toolchain-and-Build.md.
4. **Assembly blocks are not compiled code.** In an `@ps2as` file, an `INCLUDE_ASM` /
   `ASM_FUNC` / `LINKER_REMNANT` block is assembled with GNU as, as its own slice (SN's Ps2EeAs
   cannot read the GNU assembler macros the `.s` files use). The bytes are the
   `.s` file's either way; when the function becomes C, it is compiled with its file's flags.
5. **A function that only matches through a new transform or a new flag range is not matched.**
   Leave it in `nonmatching/` and write down what differs.

## Choosing a file's flags

A file's flags are the ones that make its C match. For a file carried from the US project, they
are the flags of the US non-override range the file's functions sat in; a US file whose ranges
changed inside it was split where they change (at an 8-aligned function, since an object's code
starts 8-aligned). Moving a file boundary, or giving a whole file other flags because more of its
functions match with them, is allowed; giving one function its own flags is not.
