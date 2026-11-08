# Ratchet & Clank 3 (PS2) Decompilation

[![Website](https://img.shields.io/badge/Website-openrac.dev-ff8a00?logo=googlechrome&logoColor=white)](https://openrac.dev)
[![Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?logo=discord&logoColor=white)](https://discord.gg/Sfd2B54PDG)
[![Progress report](https://github.com/OpenRAC/rac3-decomp/actions/workflows/progress.yml/badge.svg)](https://github.com/OpenRAC/rac3-decomp/actions/workflows/progress.yml)
[![Code](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac3-decomp)
[![Functions](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/OpenRAC/rac3-decomp)

A work-in-progress **matching decompilation** of *Ratchet & Clank 3* (Insomniac Games, 2004) for the PlayStation 2, part of the **[OpenRAC](https://openrac.dev)** initiative. One repository covers two versions ([docs/versions.md](docs/versions.md)): PAL (`SCES-524.56`), the primary target, and NTSC-U (*Ratchet & Clank: Up Your Arsenal*, `SCUS-973.53`). A function whose code is the same on both discs is one C source, checked against both.

The PAL disc's three core programs and its 49 level programs are rebuilt from C and assembly until every byte equals retail:

| Program | What it is | Size | SHA-1 of the retail file |
| --- | --- | ---: | --- |
| `frontbin` | the front end (menus) | 2,219,756 | `5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553` |
| `boot_elf` | the main executable: the engine core plus a second copy of the front end | 3,534,436 | `e0a4e82e9a363a64db5a555db8c8f927ef58c3d8` |
| `i5bootn` | a loader: decompresses and starts another program | 810,640 | `c1166658edad1b6b04b7671af77fff53f2560e71` |

The objective is to produce C source code that, when compiled with the original toolchain, generates a byte-identical copy of the retail programs. Matched code is then refactored toward readable, idiomatic C with accurate types and naming, using matching builds as continuous regression tests.

> [!NOTE]
> This repository contains **no game assets, retail executables, or disassembly**. To build, you must provide your own legally obtained copy of the game. Please review [`LEGAL.md`](LEGAL.md) before contributing.

---

## Progress

Decompilation progress is tracked live on **[openrac.dev](https://openrac.dev)** and **[bytematch.dev/OpenRAC/rac3-decomp](https://bytematch.dev/OpenRAC/rac3-decomp)**.

| Version | Region | Target ID | Code Matched | Functions Matched |
|---|---|---|---|---|
| v1.00 | PAL (En, Fr, De, Es, It) | `SCES-524.56` | [![](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac3-decomp) | [![](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/OpenRAC/rac3-decomp) |
| v1.00 | NTSC-U | `SCUS-973.53` | [![](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent&version=SCUS_973.53)](https://bytematch.dev/OpenRAC/rac3-decomp?version=SCUS_973.53) | [![](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Functions&measure=matched_functions&version=SCUS_973.53)](https://bytematch.dev/OpenRAC/rac3-decomp?version=SCUS_973.53) |

<!-- progress:begin (tools/progress.py --write) -->
| Program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| frontbin | 1719 | 1454 (84.6%) | 1095 | 138 | 221 | 265 |
| boot_elf | 991 | 803 (81.0%) | 527 | 204 | 72 | 188 |
| i5bootn | 194 | 193 (99.5%) | 41 | 147 | 5 | 1 |
| Shared level code | 7747 | 3309 (42.7%) | 2810 | 0 | 499 | 4438 |
| Level-specific code | 5513 | 1403 (25.4%) | 1241 | 0 | 162 | 4110 |

| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| Core programs | 2,450 of 2,904 | 383,900 of 639,780 bytes (60.01%) | 60.01% |
| Shared level code | 3,309 of 7,747 | 506,856 of 3,914,160 bytes (12.95%) | 12.95% |
| Level-specific code | 1,403 of 5,513 | 605,360 of 2,993,008 bytes (20.23%) | 20.23% |
| **Total** | 7,162 of 16,164 | 1,496,116 of 7,546,948 bytes (19.82%) | 19.82% |

Each distinct function counts once: boot_elf's copy of the front end is frontbin's, and a level function counts once however many of the 49 levels have it. 194,584 bytes (2.58%) are in source files with nothing left to decompile.
<!-- progress:end -->

**NTSC-U** (`SCUS-973.53`: 3 core programs and 51 levels, built byte-identical from assembly; [docs/versions.md](docs/versions.md)):

<!-- progress-us:begin (tools/progress.py --version us --write) -->
| NTSC-U program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| frontbin | 1698 | 1435 (84.5%) | 1077 | 138 | 220 | 263 |
| boot_elf | 1004 | 782 (77.9%) | 511 | 204 | 67 | 222 |
| i5bootn | 191 | 185 (96.9%) | 37 | 145 | 3 | 6 |
| Shared level code | 7728 | 3236 (41.9%) | 2730 | 0 | 506 | 4492 |
| Level-specific code | 5601 | 1326 (23.7%) | 1164 | 0 | 162 | 4275 |

| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| Core programs | 2,402 of 2,893 | 376,632 of 639,076 bytes (58.93%) | 63.41% |
| Shared level code | 3,236 of 7,728 | 345,428 of 3,883,768 bytes (8.89%) | 10.07% |
| Level-specific code | 1,326 of 5,601 | 210,632 of 2,986,136 bytes (7.05%) | 8.72% |
| **Total** | 6,964 of 16,222 | 932,692 of 7,508,980 bytes (12.42%) | 14.07% |

Counted from the NTSC-U disc's own function tables; a function is final when PAL's source for the function with its code checks MATCH there (config/us/map.tsv, tools/version_map.py), and the fuzzy figure adds what the near misses and the C that does not check yet reach there (docs/versions.md). 51 levels; each distinct function counts once.
<!-- progress-us:end -->

"Final source" is C, hand-written assembly (`ASM_FUNC`) and linker remnants (`LINKER_REMNANT`); `INCLUDE_ASM` is what is left to decompile. Flags are per source file, never per function ([docs/BUILD_FIDELITY.md](docs/BUILD_FIDELITY.md)).

Every function links at its original retail address. Functions not yet decompiled are built from disassembly, so a program always links and matches retail byte-for-byte outside in-progress functions. For the level overlays and the breakdown details, see [ByteMatch](https://bytematch.dev/OpenRAC/rac3-decomp) and [`docs/levels.md`](docs/levels.md).

The disc is `SCES-524.56` (Europe and Australia; English, French, German, Spanish, Italian), kept locally as `baserom/SCES_524.56.iso` (SHA-1 `5593eab45eac8814ce4b95fa1c23510fc0a21ebf`). [`docs/targets.md`](docs/targets.md) says where each core program comes from on the disc and how its layout compares with the US version's; [`docs/BETA.md`](docs/BETA.md) what the July 2004 beta disc (`baserom/TCES_524.56.iso`, a reference only) offers.

---

## Quick Start

### Prerequisites

- **Linux & macOS**: Python 3, [wibo](https://github.com/decompals/wibo) to run the Windows compilers, and [Wrench](https://github.com/chaoticgd/wrench) to unpack the disc.
- **Windows**: SN's `make.exe`, Python 3.9+, and the toolchain mirrors.

### Toolchain

You need the **SN Systems ee-gcc 2.95.3 v1.36** package (the compiler and the assemblers retail was built with) and **Sony's ee-gcc 2.9-ee-991111** (for the Sony library files), plus Python 3.9 or newer. The SN package is preserved in [AngheloAlf/SN-Systems-ProDG_for_PS2_3.01](https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01).

### Setup & Build

1. **Clone the repository:**
   ```bash
   git clone https://github.com/OpenRAC/rac3-decomp.git
   cd rac3-decomp
   ```

2. **Provide your original disc:**
   Put your own copy of the disc image in `baserom/` as `SCES_524.56.iso` (the folder is gitignored), unpack it with Wrench and copy the three programs out of it:
   ```bash
   # wrenchbuild unpack baserom/SCES_524.56.iso -o out
   cp out/uya_sces_524_56/boot_elf.elf baserom/
   cp out/uya_sces_524_56/globals/misc/frontbin.elf baserom/
   cp out/uya_sces_524_56/files/i5bootn.elf baserom/
   shasum baserom/*.elf   # must print the SHA-1s of the table above
   ```
   On a Mac, run Wrench's Linux build in an amd64 container.

3. **Install the dependencies:**
   ```bash
   python3 -m venv venv && venv/bin/pip install -r tools/requirements.txt
   ```

4. **Generate the disassembly:**
   ```bash
   python3 tools/setup_asm.py --target all
   ```
   It writes `asm/` from your programs (gitignored, so a fresh clone has none; without it the build stops with "No rule to make target `asm/...`"). It takes a few minutes and is safe to repeat.

5. **Build and verify:**
   ```bash
   python3 tools/build.py --target all -j 8 \
       --toolchain <SN ee-gcc dir> --runner <wibo> --ee29 <2.9-ee dir>
   ```
   It ends with one `MATCH` line per program:
   ```
   MATCH: build/frontbin.bin sha1 5a7ff1fe9c73a63c6ce6fe7b5f80cd7cab3aa553
   MATCH: build/boot_elf/boot_elf.bin sha1 e0a4e82e9a363a64db5a555db8c8f927ef58c3d8
   MATCH: build/i5bootn/i5bootn.bin sha1 c1166658edad1b6b04b7671af77fff53f2560e71
   ```

6. **The levels:**
   ```bash
   python3 tools/levels.py dump
   python3 tools/build_levels.py --setup -P 8 -j 4 \
       --toolchain <SN ee-gcc dir> --runner <wibo> --ee29 <2.9-ee dir>
   ```
   It ends with one `MATCH` line per level.

On Windows, the Makefile does step 5 with SN's `make.exe`. `python3 tools/check.py FILE.c` compiles one function with its file's flags and diffs it against retail.

For detailed documentation:

- [`docs/wiki/Setup.md`](docs/wiki/Setup.md) – the toolchain, your own copy of the game, the first build
- [`docs/BUILD_FIDELITY.md`](docs/BUILD_FIDELITY.md) – what the build reproduces of retail's toolchain, what it models, and the rules that keep it honest
- [`docs/levels.md`](docs/levels.md) – the 49 level programs, how they are built and how their functions are counted
- [`docs/GLOBALS.md`](docs/GLOBALS.md) – each program's `$gp`, how C names globals (`D_XXXXXXXX_sda` slots) and what the build checks
- [`docs/targets.md`](docs/targets.md) – the three core programs, their layout and their tables

---

## Contributing

Contributions are warmly welcome! Whether you are interested in decompiling functions, researching engine quirks, or improving documentation:

- Read [`AGENTS.md`](AGENTS.md) and [`CONTRIBUTING.md`](CONTRIBUTING.md) first; they hold the rules.
- The wiki sources are in [`docs/wiki/`](docs/wiki): [Setup](docs/wiki/Setup.md), [Workflow](docs/wiki/Workflow.md), [Matching patterns](docs/wiki/Matching-Patterns.md), [Pull requests](docs/wiki/Pull-Requests.md), [Credits](docs/wiki/Credits.md).
- The matching techniques of the US project apply here unchanged ([Matching patterns](docs/wiki/Matching-Patterns.md)); its research notes, with US addresses, are in [`docs/us/`](docs/us).
- `python3 tools/todo.py` sorts the functions still to match into buckets; many have a US draft in `nonmatching/` to start from.
- Join our **[Discord Community](https://discord.gg/Sfd2B54PDG)** to discuss progress, ask questions, and collaborate! `info@openrac.dev` reaches the maintainers privately.

---

## Tools

| Tool | Purpose |
|---|---|
| `tools/setup_asm.py` | Generates `asm/` from your programs (splat plus the fix-ups the build needs) |
| `tools/build.py` | The full build for Linux and macOS: one `MATCH` per program |
| `tools/build_levels.py` | Builds the levels, several at a time; one `MATCH` per level |
| `tools/build_text.py` | Builds a program's code, one object per source file, with that file's flags |
| `tools/check.py` | Compiles a snippet with its file's flags and diffs it against retail |
| `tools/todo.py` | Sorts the functions still to match into buckets |
| `tools/progress.py` | The counts, the README table and `progress/report.json` |
| `tools/levels.py` | The levels: from the disc, their configuration, the catalogue, their build trees |
| `tools/inventory.py` | Every function of the core programs, found from the binaries (`config/inventory.tsv`) |
| `tools/level_catalogue.py` | Every distinct level function once, and boot_elf's front-end pairs |
| `tools/resolve_symbols.py` | Writes `config/<program>/symbol_addrs_resolved.txt` |
| `tools/port_from_us.py` | Made this tree from the US decompilation (kept as the record) |
| `tools/port_verify.py` | Checks every function of a build against retail, for the port |
| `tools/pr_check.py` | One program's source checks, plus compiling every file |
| `tools/try_in_context.py` | Compiles a draft in place, in the file's real build context |
| `tools/flags_probe.py` | Finds the mode and assembler a near miss wants, for the file's `text_parts.txt` line |
| `tools/permuter_setup.py` | Sets up a decomp-permuter run for one function ([docs/permuter.md](docs/permuter.md)) |
| `tests/check_repository.py` | The pre-commit check: sources, tables, progress, no game data (CI runs it) |

---

## Credits

This project builds upon years of dedicated reverse-engineering research and tooling by the community:

- **[rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp)** by vetusmagnus – Matching decompilation of the NTSC-U release of *Ratchet & Clank: Up Your Arsenal*. This repository was made from it: its tools, its layout and the C of every function whose PAL bytes are the US ones come from there ([docs/porting.md](docs/porting.md), [CREDITS.md](CREDITS.md)).
- **[rac1-decomp](https://github.com/OpenRAC/rac1-decomp)** and **[rac2-decomp](https://github.com/llesieur99/rac2-decomp)** – the OpenRAC decompilations of the first two games: their way of finding functions in the binaries, of telling linker remnants and joined pieces apart, and their level catalogue and report categories came over as `tools/inventory.py`, `tools/level_catalogue.py` and `tools/progress.py`.
- **[Lombyte](https://github.com/mateuszklysz/Lombyte)** by mateuszklysz – Matching decompilation of the NTSC build of *Ratchet & Clank*. A reference for function pairing and symbol names.
- **[ReRAC](https://github.com/re-rac/rerac)** by the ReRAC team – Native PC port of the US release. Documentation of formats and overlay mechanics.
- **[Wrench](https://github.com/chaoticgd/wrench)** by chaoticgd – *Ratchet & Clank* PS2 modding tools and asset format specifications; it unpacks the disc.
- **[wibo](https://github.com/decompals/wibo)** by decompals – Runs the Windows toolchain on Linux and macOS.
- **Decompilation Tooling & Ecosystem**:
  - [splat](https://github.com/ethteck/splat) & [spimdisasm](https://github.com/Decompollaborate/spimdisasm) – Binary splitting and MIPS disassembly.
  - [m2c](https://github.com/matt-kempster/m2c) & [asm-differ](https://github.com/simonlindholm/asm-differ) – Assembly-to-C translation and diffing.
  - [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) – Finds the C rewrites behind register and scheduling near misses.
  - [objdiff](https://github.com/encounter/objdiff) – Object diffing tool.
  - [ByteMatch](https://bytematch.dev) & [decomp.wiki](https://decomp.wiki) – Progress tracking and decompilation knowledge base.
  - [AngheloAlf](https://github.com/AngheloAlf) – PS2 toolchain mirrors.

rac3-decomp is led by **[Veradictus](https://github.com/Veradictus)**, both the PAL and the NTSC versions; [CREDITS.md](CREDITS.md) and [docs/wiki/Credits.md](docs/wiki/Credits.md) name everyone else.

---

## License

- Code written for this project is licensed under the [GNU General Public License v3.0](LICENSE).
- Reconstructed libraries and third-party components retain their original licenses (see [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md) and [`LEGAL.md`](LEGAL.md)).
- The decompiled game code in `src/` is a derivative of the original game (copyright Sony Interactive Entertainment LLC): no copyright is claimed over it and it is not licensed.
- *Ratchet & Clank* is a registered trademark of Sony Interactive Entertainment. This project is not affiliated with or endorsed by Sony or Insomniac Games.
