<p align="center">
  <a href="https://openrac.dev/">
    <picture>
      <source media="(prefers-color-scheme: dark)" srcset="docs/assets/openrac-logo-dark.svg">
      <img src="docs/assets/openrac-logo-light.svg" alt="OpenRAC" width="360">
    </picture>
  </a>
</p>

<h3 align="center">Ratchet &amp; Clank 3 decompilation project</h3>

<p align="center">
  <a href="https://bytematch.dev/OpenRAC/rac3-decomp"><img src="https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent" alt="Code matched"></a>
  <a href="https://github.com/OpenRAC/rac3-decomp/actions/workflows/progress.yml"><img src="https://github.com/OpenRAC/rac3-decomp/actions/workflows/progress.yml/badge.svg" alt="Progress report"></a>
  <a href="https://openrac.dev/"><img src="https://img.shields.io/badge/website-openrac.dev-e8a317" alt="openrac.dev"></a>
  <a href="https://discord.gg/Sfd2B54PDG"><img src="https://img.shields.io/badge/Discord-join%20us-5865F2?logo=discord&logoColor=white" alt="Discord"></a>
</p>

<p align="center">
  A work-in-progress, matching decompilation of <i>Ratchet &amp; Clank 3</i> (<i>Up Your Arsenal</i>, 2004) for PlayStation 2.<br>
  Three core programs and 49 level programs, rebuilt as C that compiles back to the same bytes as retail.
</p>

> [!WARNING]
> This repository has no game data, executables, disc images or proprietary toolchains.
> You need your own copy of the game. Read [LEGAL.md](LEGAL.md) before contributing.

## Progress

PAL, the primary version, counted by `tools/progress.py`. "Final source" is C, hand-written assembly (`ASM_FUNC`)
and linker remnants (`LINKER_REMNANT`); `INCLUDE_ASM` is what is left. Live numbers are on
[ByteMatch](https://bytematch.dev/OpenRAC/rac3-decomp).

<!-- progress:begin (tools/progress.py --write) -->
| Program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| frontbin | 1719 | 1454 (84.6%) | 1095 | 138 | 221 | 265 |
| boot_elf | 991 | 803 (81.0%) | 527 | 204 | 72 | 188 |
| i5bootn | 194 | 193 (99.5%) | 41 | 147 | 5 | 1 |
| Shared level code | 7747 | 3309 (42.7%) | 2810 | 0 | 499 | 4438 |
| Level-specific code | 5513 | 1925 (34.9%) | 1763 | 0 | 162 | 3588 |

| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| Core programs | 2,450 of 2,904 | 383,900 of 639,780 bytes (60.01%) | 60.01% |
| Shared level code | 3,309 of 7,747 | 506,856 of 3,914,160 bytes (12.95%) | 12.95% |
| Level-specific code | 1,925 of 5,513 | 715,240 of 2,993,008 bytes (23.90%) | 23.90% |
| **Total** | 7,684 of 16,164 | 1,605,996 of 7,546,948 bytes (21.28%) | 21.28% |

Each distinct function counts once: boot_elf's copy of the front end is frontbin's, and a level function counts once however many of the 49 levels have it. 194,584 bytes (2.58%) are in source files with nothing left to decompile.
<!-- progress:end -->

<details>
<summary>NTSC-U progress</summary>

<!-- progress-us:begin (tools/progress.py --version us --write) -->
| NTSC-U program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| frontbin | 1698 | 1435 (84.5%) | 1077 | 138 | 220 | 263 |
| boot_elf | 1004 | 782 (77.9%) | 511 | 204 | 67 | 222 |
| i5bootn | 191 | 185 (96.9%) | 37 | 145 | 3 | 6 |
| Shared level code | 7728 | 3244 (42.0%) | 2738 | 0 | 506 | 4484 |
| Level-specific code | 5601 | 1775 (31.7%) | 1613 | 0 | 162 | 3826 |

| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| Core programs | 2,402 of 2,893 | 376,632 of 639,076 bytes (58.93%) | 63.41% |
| Shared level code | 3,244 of 7,728 | 346,580 of 3,883,768 bytes (8.92%) | 10.11% |
| Level-specific code | 1,775 of 5,601 | 298,988 of 2,986,136 bytes (10.01%) | 12.40% |
| **Total** | 7,421 of 16,222 | 1,022,200 of 7,508,980 bytes (13.61%) | 15.55% |

Counted from the NTSC-U disc's own function tables; a function is final when PAL's source for the function with its code checks MATCH there (config/us/map.tsv, tools/version_map.py), and the fuzzy figure adds what the near misses and the C that does not check yet reach there (docs/build/versions.md). 51 levels; each distinct function counts once.
<!-- progress-us:end -->

</details>

## Supported versions

| Release | Region | Disc | Code | Notes |
| --- | --- | --- | --- | --- |
| v1.00 | PAL (Europe and Australia) | `SCES-524.56` | [![Code](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac3-decomp) | Primary version |
| v1.00 | NTSC-U | `SCUS-973.53` | [![Code](https://bytematch.dev/OpenRAC/rac3-decomp.svg?mode=shield&label=Code&measure=matched_code_percent&version=SCUS_973.53)](https://bytematch.dev/OpenRAC/rac3-decomp?version=SCUS_973.53) | Released as *Up Your Arsenal* |

A function whose code is the same on both discs is one C source, checked against both. Expected SHA-1 of the
PAL disc image (`baserom/SCES_524.56.iso`):

```text
5593eab45eac8814ce4b95fa1c23510fc0a21ebf
```

The three core programs, their hashes and how the versions fit together: [docs/build/targets.md](docs/build/targets.md)
and [docs/build/versions.md](docs/build/versions.md).

## Quick setup

You need Python 3, [wibo](https://github.com/decompals/wibo) (Linux and macOS), [Wrench](https://github.com/chaoticgd/wrench)
to unpack the disc, and the SN Systems ee-gcc 2.95.3 v1.36 and Sony ee-gcc 2.9-ee-991111 toolchains.

```sh
git clone https://github.com/OpenRAC/rac3-decomp.git && cd rac3-decomp
wrenchbuild unpack baserom/SCES_524.56.iso -o out    # your own disc image
cp out/uya_sces_524_56/boot_elf.elf out/uya_sces_524_56/globals/misc/frontbin.elf out/uya_sces_524_56/files/i5bootn.elf baserom/
python3 -m venv venv && venv/bin/pip install -r tools/requirements.txt
python3 tools/setup_asm.py --target all
python3 tools/build.py --target all -j 8 --toolchain <SN ee-gcc dir> --runner <wibo> --ee29 <2.9-ee dir>
```

It ends with one `MATCH` line per program. Windows, the levels and every step in detail:
[docs/build/building.md](docs/build/building.md).

## Contributing

Start with [CONTRIBUTING.md](CONTRIBUTING.md) and [AGENTS.md](AGENTS.md). All docs are listed in [docs/README.md](docs/README.md):

- [docs/build/](docs/build) - building, versions, levels, targets and globals
- [docs/contributing/](docs/contributing) - names, the permuter and large function families
- [docs/game/](docs/game) - how the game works, and the beta disc
- [docs/research/us/](docs/research/us) - NTSC-U research notes, with US addresses
- [docs/history/](docs/history) - how this repository was made from the US decompilation
- [docs/wiki/](docs/wiki) - the wiki pages: setup, workflow, matching patterns, pull requests

Keep the build matching retail. Never commit game images, extracted game data or proprietary compiler binaries.

## Credits

rac3-decomp is led by [Veradictus](https://github.com/Veradictus), both the PAL and the NTSC versions.
[CREDITS.md](CREDITS.md) and [docs/wiki/Credits.md](docs/wiki/Credits.md) name everyone else. The main projects:

- [rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp) by vetusmagnus - the NTSC-U decompilation this
  repository was made from: its tools, its layout and the C of every function whose PAL bytes are the US ones.
- [rac1-decomp](https://github.com/OpenRAC/rac1-decomp) and [rac2-decomp](https://github.com/OpenRAC/rac2-decomp) -
  function finding, linker remnants, the level catalogue and the report categories.
- [Lombyte](https://github.com/lombyte-project/Lombyte) - function pairing and symbol names.
- [ReRAC](https://github.com/re-rac/rerac) - formats and overlay mechanics.
- [Wrench](https://github.com/chaoticgd/wrench) by chaoticgd - modding tools; it unpacks the disc.
- [wibo](https://github.com/decompals/wibo), [splat](https://github.com/ethteck/splat),
  [spimdisasm](https://github.com/Decompollaborate/spimdisasm), [m2c](https://github.com/matt-kempster/m2c),
  [asm-differ](https://github.com/simonlindholm/asm-differ), [decomp-permuter](https://github.com/simonlindholm/decomp-permuter),
  [objdiff](https://github.com/encounter/objdiff), [ByteMatch](https://bytematch.dev) and
  [AngheloAlf](https://github.com/AngheloAlf)'s PS2 toolchain mirrors.

## License

Code written for this project is under the [GNU General Public License v3.0](LICENSE). Code reconstructed from
third-party binaries belongs to its copyright holders; see [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).
