# Legal scope of this project

This repository is a **matching decompilation** of *Ratchet & Clank 3* (PS2,
PAL, `SCES-524.56`, known as *Up Your Arsenal* in North America): the three
core programs and the 49 level programs of the disc, rebuilt from C and
assembly until every byte equals retail.

[LICENSE](LICENSE) is the GNU General Public License version 3. This file
says what that licence covers here, because the answer is not "everything in
the repository".

## What is licensed under the GPL-3.0

The project's own work is GPL-3.0:

- `tools/` (the scripts and programs, including the decomp-permuter
  patches) and `tests/`;
- the build system: `Makefile`, `linker_scripts/`, `config/splat/`,
  `objdiff.json` and `.github/`;
- `include/` (the project's headers and assembler macros);
- the project's tables in `config/` (`symbol_addrs*.txt`,
  `undefined_*_auto.txt`, `reloc_addrs.txt`, `src_files.txt`,
  `text_parts.txt`, `divs_nops.txt`, `sq_ra_funcs.txt`);
- `docs/`, `nonmatching/README.md`, `README.md`, `CONTRIBUTING.md`,
  `AGENTS.md`, `CLAUDE.md`, `CREDITS.md`, `THIRD_PARTY_NOTICES.md` and this
  file.

The tables and linker scripts record facts about the original executables
(addresses, sizes, section layout, compiler flags). They contain no game
code.

## What is not licensed

The decompiled game code is excluded from the GPL-3.0:

- everything under `src/` except the GCC runtime library files listed below,
  including the matching C rewrites and the hand-written assembly
  (`ASM_FUNC`) and linker remnants (`LINKER_REMNANT`);
- the C drafts under `nonmatching/`, which are near misses kept as a record;
- the `asm/` directory that `tools/setup_asm.py` generates locally from your
  own copy of the disc (it is gitignored and never committed).

This code is a derivative work of *Ratchet & Clank: Up Your Arsenal*, whose
copyright is owned by Sony Interactive Entertainment LLC, and of the libraries
linked into the original executables. The project's contributors claim no
copyright over it and grant no licence to it. It is provided strictly for
educational, preservation and research purposes.

## What keeps its own licence

The GCC runtime library files keep their own licence, as each file's header
states: `src/libgcc/` (except its `README.md`), `src/i5bootn/libgcc/` and
`src/boot_elf/core/libgcc/` hold source from GCC 2.95.2's libgcc,
copyright the Free Software Foundation, Inc., under the GNU General Public
License version 2 or later with the libgcc runtime exception.

Everything else that comes from another project keeps that project's
licence; [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) lists them.

## What the repository never contains

The retail programs (`frontbin.elf`, `boot_elf.elf`, `i5bootn.elf`), the
disc's other files, the level overlays, disc images, the assembly that
`tools/setup_asm.py` generates from them, build output and other game data
are never committed: every contributor supplies their own disc. Nothing from
the 2004-07-12 beta disc is committed either: [docs/BETA.md](docs/BETA.md)
describes what it holds, in words. The SN Systems and Sony toolchains are
proprietary and stay outside the repository too.
`python3 tests/check_repository.py` (run by CI) rejects tracked game data.

You need your own legally obtained copy of the game to build anything here.

## Sources

Only permitted sources are used: the retail programs of a disc you own, SDK
library *binaries*, open-source code under its licence, public
decompilations and tools, and public hardware documentation. Never Sony SDK
source, samples or headers, and never leaked or NDA material. If a function
looks like SDK sample code, it is decoded from the assembly. The beta disc
is a reference for names and behaviour only; nothing taken from it is
committed.

## Practical implication

This repository will not build into a runnable game for anyone who does not
already own a copy of the disc and supply it locally. Cloning it gets you
build scripts and, as the decompilation progresses, increasingly complete C
source: never assets, never the retail executables.

*Ratchet & Clank* is a trademark of Sony Interactive Entertainment LLC. This
is an unofficial fan project, not affiliated with or endorsed by Insomniac
Games or Sony Interactive Entertainment.
