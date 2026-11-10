# Docs

Every doc of this repository, by folder. New here? Read [building.md](build/building.md), then
[CONTRIBUTING.md](../CONTRIBUTING.md) and the [workflow](wiki/Workflow.md).

## build/: build and check the match

| Doc | What it covers |
|---|---|
| [building.md](build/building.md) | Setup, the build, the levels, the progress table and the tools |
| [versions.md](build/versions.md) | PAL and NTSC-U: one source checked against both discs |
| [targets.md](build/targets.md) | The three core programs, their layout and their tables |
| [levels.md](build/levels.md) | The 49 level programs, how they are built and counted |
| [globals.md](build/globals.md) | Each program's `$gp` and how C names globals |
| [build-fidelity.md](build/build-fidelity.md) | What the build reproduces of retail's toolchain, and the rules that keep it honest |
| [trailing-padding.md](build/trailing-padding.md) | Zero words after functions and `TEXT_PADDING` |

## contributing/: write and review code

| Doc | What it covers |
|---|---|
| [names.md](contributing/names.md) | How symbols get readable names |
| [permuter.md](contributing/permuter.md) | Using decomp-permuter |
| [large-function-families.md](contributing/large-function-families.md) | Per-level copies of large functions: match one, port it to the rest |

## game/: how the game works

| Doc | What it covers |
|---|---|
| [beta-disc.md](game/beta-disc.md) | The July 2004 beta disc |
| [protected-values.md](game/protected-values.md) | Scrambled game-state values in levels 39-53 |

## research/us/: NTSC-U notes (US addresses)

| Doc | What it covers |
|---|---|
| [targets.md](research/us/targets.md) | The executables the US repository builds |
| [boot_elf.md](research/us/boot_elf.md), [i5bootn.md](research/us/i5bootn.md) | The main executable and the loader |
| [source_files.md](research/us/source_files.md) | Source files |
| [shared_code_findings.md](research/us/shared_code_findings.md) | Code shared between executables and overlays |
| [compiler_matrix_findings.md](research/us/compiler_matrix_findings.md), [compiler_matrix_i5bootn.md](research/us/compiler_matrix_i5bootn.md) | Compiler and flag matrix |
| [full_match_roadmap.md](research/us/full_match_roadmap.md) | Road to 100%: blockers and plan |
| [permuter_todo.md](research/us/permuter_todo.md) | decomp-permuter worklist |

## history/

| Doc | What it covers |
|---|---|
| [porting-from-us.md](history/porting-from-us.md) | How this tree was made from the US decompilation |

## wiki/: the GitHub wiki

The pages in [wiki/](wiki/Home.md) are published to the GitHub wiki by `.github/workflows/wiki-sync.yml`, so they
stay in this folder: [Setup](wiki/Setup.md), [Workflow](wiki/Workflow.md), [Matching patterns](wiki/Matching-Patterns.md),
[Cross-repository resources](wiki/Cross-Repository-Resources.md), [Tools](wiki/Tools.md),
[Toolchain and build](wiki/Toolchain-and-Build.md), [Pull requests](wiki/Pull-Requests.md), [Credits](wiki/Credits.md).
