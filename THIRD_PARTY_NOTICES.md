# Third-party notices

The repository is split-licensed ([LICENSE](LICENSE) is the GPL-3.0 the project's own work
carries; [LEGAL.md](LEGAL.md) says what that covers and what it does not). The following parts keep
their own licence or come from another project.

## rac3-uya-decomp (the US decompilation)

This repository was made from [rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp), the
decompilation of the NTSC-U version (`SCUS-97353`), at

- branch `cleanup/restructure` (pull request #59 there), commit
  `13cf5c592de88ca8f76e22d81f1684d9c06f8f58` (2026-10-20),

which is licensed under the GNU General Public License version 3, as this repository is.
From it come:

- the tools in `tools/` and `tests/` (adapted to PAL; `tools/port_from_us.py`,
  `tools/port_verify.py`, `tools/resolve_symbols.py` and the rewritten `tools/progress.py` are
  new), `include/`, the linker scripts and splat configurations (with PAL addresses), the
  Makefile, the GitHub workflow, the wiki sources in `docs/wiki/` and the research notes in
  `docs/us/`;
- the C in `src/` of every function whose PAL bytes equal the US ones, with its names moved to
  PAL addresses (docs/porting.md), and the drafts in `nonmatching/` marked "US draft".

[CREDITS.md](CREDITS.md) names its contributors.

## GCC runtime library (libgcc)

`src/libgcc/` (except its README.md), `src/i5bootn/libgcc/` and `src/boot_elf/core/libgcc/` hold
source from GCC 2.95.2's libgcc, copyright the Free Software Foundation, Inc., under the GNU
General Public License version 2 or later with the libgcc runtime exception, as each file's header
states.

## Patches to other projects

`tools/decomp-permuter-aligned-scorer.patch` and `tools/decomp-permuter-asm-passes.patch` are
changes to [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (Simon Lindholm),
applied to a separate checkout of it; they are offered under decomp-permuter's own licence.

## Tools used, not redistributed

splat, spimdisasm, rabbitizer, objdiff, asm-differ, pyelftools, Capstone, NumPy, Wrench and wibo
are installed or downloaded separately under their own licences (`tools/requirements.txt`,
docs/wiki/Setup.md). The SN Systems and Sony compilers are proprietary and are never included.
