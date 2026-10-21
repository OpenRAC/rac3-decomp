# Credits

## This project

rac3-decomp is led by **[Veradictus](https://github.com/Veradictus)**, both the PAL and the NTSC versions.

## rac3-uya-decomp

This project is built on [rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp), the
decompilation of *Ratchet & Clank: Up Your Arsenal* (NTSC-U), taken from its branch
`cleanup/restructure` at commit `13cf5c592de88ca8f76e22d81f1684d9c06f8f58` (2026-10-20). Its
tools, its layout and the C of every function the PAL version shares with the US one come from
there (THIRD_PARTY_NOTICES.md, docs/porting.md). Thank you to its contributors:

- **vetusmagnus**: the initial NTSC setup and findings this project started from: led
  rac3-uya-decomp, identified the toolchain, built its build system and localdecomp, and wrote most
  of the matched C the PAL port carried over.
- **Louis-Philippe Le Sieur ([llesieur99](https://github.com/llesieur99))**: matched functions, the
  common-level C and its verified build, the cross-repository research, tool fixes and many of
  the matching patterns.
- everyone else in its history.

## The levels

The level code (docs/levels.md) follows rac1-decomp and rac2-decomp, the OpenRAC decompilations
of the first two games: their way of finding functions in the binaries, of telling linker
remnants and joined pieces apart, and their level catalogue, units and report categories, were
carried over as tools/inventory.py, tools/level_catalogue.py and tools/progress.py. From
rac3-uya-decomp come the level names and numbers, the layout of a level program as a target like
frontbin (its level-target work of 2026-10-20) and the patch that turns off spimdisasm's halt
function search for the levels. Wrench's documentation describes the disc's table of contents and
the level files that tools/levels.py reads.

## The game

*Ratchet & Clank 3* (*Up Your Arsenal*) was developed by **Insomniac Games** and published by
**Sony Computer Entertainment** (2004). This is an unofficial fan project, not affiliated with or
endorsed by Insomniac Games or Sony Interactive Entertainment. *Ratchet & Clank* is a trademark of
Sony Interactive Entertainment LLC. You need your own copy of the game to build anything here.

## Tools and other projects

[docs/wiki/Credits.md](docs/wiki/Credits.md) lists the toolchain, the decompilation tools and
libraries, Wrench (which unpacks the disc) and the related decompilations.
