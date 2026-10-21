# The programs this repository builds

All addresses here are the PAL version's. The disc is `SCES-52456` (*Ratchet & Clank 3*,
Europe and Australia, English, French, German, Spanish and Italian), kept locally as
`baserom/SCES_524.56.iso` (the July 2004 beta, docs/BETA.md, as `baserom/TCES_524.56.iso`); `SYSTEM.CNF` reads `BOOT2 = cdrom0:\SCES_524.56;1`,
`VER = 1.00`, `VMODE = PAL`. The image this was done with has SHA-1
`5593eab45eac8814ce4b95fa1c23510fc0a21ebf` (4,464,115,712 bytes).

| Program | Where it comes from | Size | SHA-1 | Entry |
| --- | --- | ---: | --- | --- |
| `frontbin` | `globals/misc/frontbin.elf` of Wrench's unpack (inside the global WAD files) | 2,219,756 | `5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553` | `0x381250` |
| `boot_elf` | `boot_elf.elf` of Wrench's unpack: `SCES_524.56`'s compressed payload, with ELF headers | 3,534,436 | `e0a4e82e9a363a64db5a555db8c8f927ef58c3d8` | `0x13ADA8` |
| `i5bootn` | `I5BOOTN.ELF` in the disc's root (Wrench: `files/i5bootn.elf`), as it is | 810,640 | `c1166658edad1b6b04b7671af77fff53f2560e71` | `0x800008` |

`tools/targets.py` is the registry: each program's ELF and SHA-1, its code sections ("units"), its
tables, linker script and splat configuration. Every tool takes `--target NAME` (or `all`).

## The disc's executables

- **`SCES_524.56`** (771,648 bytes, SHA-1 `e3a8f37d6033b007a80f63dfbfca9afe24f27a47`), the
  program `SYSTEM.CNF` boots, is a loader linked at `0x800000`. Its `.text` is `i5bootn`'s code
  (5,093 of its 5,110 words are the same; the 17 others are relocations of its `.bss`, which moved
  with the payload's size), and its `.rodata` carries a WAD-compressed image at file offset
  `0x7080` ("WAD", then the compressed size, `0xB53FC`): the main program, 0x35BF54 bytes once
  decompressed, entry `0x13ADA8`. Wrench decompresses it and rebuilds its ELF headers and section
  table: that file is `boot_elf.elf`. It is not built here (it would be `i5bootn`'s code again with
  another payload).
- **`I5BOOTN.ELF`** (`i5bootn`) is the same loader with another payload at `0x7080` (compressed
  `0xBEC4B` bytes, 0x20A194 once decompressed, entry `0x192D18`); which program that is has not
  been looked at yet.
- `frontbin.elf` is not a disc file: it is in the global WAD files, as on the US disc.

This matches what notes on Ratchet: Deadlocked's PAL version describe for that game (a small
loader at `0x800000` that decompresses the real game to `0x100000`; the menu program and the
level overlays loaded at one shared address): the same engine generation. The Deadlocked notes' byte signature of a
32-byte-block `memcpy` (`00864821 2484ffe0 2528fff0 2529ffe0`) does not occur in any of these
programs.

## Compared with the US programs

The US programs are rac3-uya-decomp's (`SCUS-97353`). Same layout, same section names; what
moved:

| | US | PAL |
| --- | --- | --- |
| `boot_elf` `core.text` (`0x116F80`, 0x264A0 bytes) | | the same bytes but one word (`0x13B3C0`, a relocated `%lo`) |
| `boot_elf` `.vutext`, `core.rdata`, `legal.data`, `mc1.data` | | identical |
| `boot_elf` `.lit` / `.bss` / `.data` | `0x1D5680` / `0x1D9900` / `0x31BE80` | `0x1D5680` (0x40 bytes shorter) / `0x1D9880` / `0x31BE00` |
| `boot_elf` `.text` (the front end) | `0x381180`, 0x71438 bytes | `0x381080`, 0x716F8 bytes |
| `frontbin` `.data`, `.text` | `0x317E80`, `0x37D100` (0x6FCF8 bytes) | `0x31BE00`, `0x381080` (0x71340 bytes) |
| `i5bootn` `.text` | | the same but 17 relocated words |
| `i5bootn` `.rodata` (the payload) | 0xBEFC3 bytes | 0xBF2CB bytes; `.sbss`/`.bss` 0x300 later |

In PAL, `frontbin`'s and `boot_elf`'s front ends both start at `0x381080` (in the US version
`frontbin` was linked at `0x37D100`). `$gp` is `0x1DC8B0` in both versions: `core.text`, which
reaches its small data through `$gp`, is unchanged.

Function by function (masked comparison, `tools/port_from_us.py`): every function of
`boot_elf`'s core and of `i5bootn` is still there; of the front end, 1,799 of frontbin's 1,867 US
functions and 1,828 of boot_elf's 1,891 are found again; the rest changed, and PAL has code of
its own in their place. [porting.md](porting.md) has the
details.

## Layout of each program

The build reproduces each file as a straight memory image: every section at its retail file
offset (the linker scripts' `AT(...)`), the gaps zero, the ELF headers and the trailing section
table as raw bytes (`asm/<program>/header.s`, `trailer.s`).

| Program | Code units | Data the linker places around the code |
| --- | --- | --- |
| `frontbin` | `.text` `0x381080`..`0x3F256C` (the file's end) | `.lit`, `.data` (split around the jump tables), `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` |
| `boot_elf` | `core.text` `0x116F80`..`0x13D420`, `.text` `0x381080`..`0x3F2778` | `.vutext`, `core.data`, `core.rdata`, `core.lit`, `.lit`, `.data`, the three vtables, `patch.data`, `legal.data`, two `mc1.data` |
| `i5bootn` | `.text` `0x800000`..`0x804FD8` | `.data`, `.rodata` (its first part, the code's read-only data, comes from the sources) |

## Adding a program

As in the US project ([us/targets.md](us/targets.md), "Adding a target"): an entry in
`tools/targets.py`, a splat configuration, a linker script, then `tools/setup_asm.py` and a
build that prints `MATCH`.
