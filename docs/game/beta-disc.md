# The July 2004 beta disc

*Ratchet & Clank 3 (Europe) (Beta) (2004-07-12)*, kept locally as `baserom/TCES_524.56.iso`
(1,262,387,200 bytes, SHA-1 `ffc6872964aca480e5263fa0fb23e6e443acdc71`). It is a reference for
names and behaviour only: it is not a build target, and nothing from it (its programs, its data,
its strings) is committed. This page says what it holds, in words, as checked on 2026-10-20.

## What is on it

`SYSTEM.CNF` boots `cdrom0:\TCES_524.56;1` (`VMODE = PAL`). The ISO file system lists 39 files:
`TCES_524.56`, the IOP images, the `NETGUI` online-setup program and its modules, and a 32 MB
`Z6TAIL.DUP`. There is no `I5BOOTN.ELF`. The game's data is outside the file system, as on the
retail disc; it was not unpacked here.

## The executable

`TCES_524.56` (2,307,824 bytes, SHA-1 `a231d62ec0554d805da5cf90d27b467dd16dcc44`) is the main
program **uncompressed**, with its own section headers: there is no loader in front of it as on
the retail disc (where `SCES_524.56` decompresses `boot_elf`). Entry `0x18EA50`.

| | Beta | Retail `boot_elf` |
| --- | --- | --- |
| section headers | 77, written by the linker | 20, rebuilt by Wrench |
| symbols (`.symtab`) | none | none |
| `.mdebug.eabi64` | present, empty | none |
| VU microcode | `.vutext` plus 52 `.DVP.overlay..*` sections and `.DVP.ovlystrtab` / `.DVP.ovlytab` (the VU overlay tables) | `.vutext` only |
| `core.text` | `0x118000`, 0x80068 bytes | `0x116F80`, 0x264A0 bytes |
| `.text` (front end) | `0x296B00`, 0x18020 bytes | `0x381080`, 0x716F8 bytes |
| `.data` | `0x295000`, 0x1980 bytes | `0x31BE00`, 0x65100 bytes |

The overlay names in `.DVP.ovlystrtab` are numeric (`.DVP.overlay..0x800.104691.427.1`: VU
address, then numbers), not symbolic. The beta's `core.text` is three times retail's because the
online libraries are linked into it: it carries 30 CVS `$Header$` lines of the network middleware
(`DmeLocal.h`, `Dme.c`, `rt_audio`, `rt_crypt`, `rt_msg_client`, `rt_udp`, `rt_upnp`), with dates
from 2003 to June 2004. Retail has none of those strings. Its `.text` is far smaller than
retail's front end: most of the front end is not in this executable.

## Strings

The beta has more debugging text than retail (102 printf-style format strings against 58 in
retail `boot_elf`): `assert` messages (`assertion "%s" failed: file "%s", line %d`, an
`RT_XML_ASSERT` with file and line), `host0:` paths to a development host's files (scene data
under `built/scenes/level%d/...`, `data\configs\%s.txt`), the 989snd library's RPC errors, the
pre-production online server's host name, and the source file names `hud.cpp` and `loaders.cpp`
(which retail also has) and `network/nellymoser_wrapper.cpp`.

## Shared code

With the immediates of relocated instructions masked (as `tools/port_from_us.py` compares), 796
of retail `boot_elf`'s 2,140 functions of six words or more are in the beta's code: 462 of the
core's 571, and 334 of the front end's 1,569 (50 of those in the beta's `core.text`). Of the 796,
148 are still `INCLUDE_ASM` here (108 in the core, 40 in the front end). The code is the same
compiler output, not less optimised, so the beta does not make matching easier by itself.

## What it is good for

- **Section boundaries.** Its linker-written section table shows the original section names and
  alignments (`core.text` 64, `core.data` 128, `.lit` and `.bss` 64), which agree with the ones
  Wrench rebuilds for retail.
- **Names and behaviour.** The assert and debug strings name source files and checks that retail
  dropped; the CVS headers identify the network library and its versions. Use them to name
  functions in comments and to understand them, never by copying text into the repository.
- **Not:** symbols (there are none), C (there is none), or a cleaner compiler output.
