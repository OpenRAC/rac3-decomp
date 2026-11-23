# Small-function pass, 2026-11-23

This pass uses the strict **less than 400 bytes** inventory cutoff on PAL and NTSC-U. Active reservations in [coordination issue #3](https://github.com/OpenRAC/rac3-decomp/issues/3) apply to regional counterparts as well as to their PAL source files.

## New C definitions

| Definition | Bytes | Region and placements | Main evidence |
| --- | ---: | --- | --- |
| `func_00139E50` | 304 | PAL boot and NTSC-U boot | MPEG stream-callback registration; signed callback/data fields and pointer GP field reproduce the aliasing and reloads |
| `func_U_L03_0039FEF0` | 256 | NTSC-U level 03 | Native 0.08 phase increment and the original source file's division padding |
| `func_U_L35_003A3920` | 388 | NTSC-U level 35 | Native 1/240 particle velocity; the zero vector is a real 16-byte float vector in small data |
| `func_U_L41_0041AE28` | 360 | Six NTSC-U multiplayer levels | Native 1/60 frame step; every relocated placement checked |

There are four C definitions, represented by ten physical placements across the two discs. The MPEG API and key-conversion structure were compared with the GPL-3.0 RAC1 NTSC decomp, Lombyte: [sce_mpeg_add_str_callback.c](https://github.com/lombyte-project/Lombyte/blob/c9a03b5fcdafe2b11403167bb0aa09d566e5d64e/src/sdk/dma/sce_mpeg_add_str_callback.c) and [type2id.c](https://github.com/lombyte-project/Lombyte/blob/c9a03b5fcdafe2b11403167bb0aa09d566e5d64e/src/sdk/library/type2id.c). The NTSC checkout is nested under the local RAC1 PAL workspace.

The native level prefix previously prevented `divs_pass()` from finding the paired PAL function's existing `divs_nops.txt` row. A unique PAL pairing now supplies that existing metadata for NTSC-U native level names. The corresponding reuse key includes the inherited row. Regression tests cover ambiguous/absent pairs, version isolation and cache invalidation.

A global input sweep measured 8.8 seconds on the local filesystem, longer than its 0.25-second batching interval. The next sweep now waits after the previous sweep finishes, with an interval at least as long as that sweep. Pending results still require a comparison begun after their check ended, and the final comparison is forced. A simulated slow-filesystem test verifies batching and the final flush.

## SPR-DMA classification

The PAL boot inventory group at `003A0510` contains an eight-byte stripped tail, forty bytes of linker fill and the 32-byte SPR-DMA leaf at `003A0540`. The leaf is byte-identical to the code at frontbin `003A0140`, already final assembly under `func_003A0138` in `src/frontbin/39FDA0.c`. It keeps the assembler-reserved `$at` register as the MMIO base across four stores.

The ten `0xCDCDCDCD` fill words have no branch targets or address-word references in the loaded boot sections. The fill is classified as a linker remnant and the DMA leaf as final assembly. This contributes zero new C definitions. NTSC-U's composite inventory boundaries still need separate repair.

## Preserved near misses

| Function | Remaining difference |
| --- | --- |
| NTSC-U `func_U_L08_0037B8B8` | Two words: float and integer argument moves are reversed. The 1/60 frame step and native lifetime are restored. |
| NTSC-U `func_U_L23_00446600` | Two words: target-pointer and packed-colour stores are reversed. The lifetime global is a `u16`. |
| PAL `func_L06_00351A68` | 67 words, improved from 71: range folding, a redundant sequence check and register allocation. |

These drafts remain in `nonmatching/`, outside the linked build and match count. Three equivalent type wordings left the two native two-word differences unchanged.

The other free PAL attempts remain open: `func_00393168`, `func_00125A70`, `func_00125BE8`, `func_L05_003E63C0`, `func_L07_003B3C78` and `func_L23_00406AC0`. Their remaining issues include address construction, alarm-state accesses, multiply scratch allocation, table-base folding, pulse branches and history-loop induction pointers. The repository's per-function stopping criteria apply.

A separate NTSC-U-only candidate, `func_L30_003B1CD0` (392 bytes, seven vidcomic placements), corresponds structurally to PAL `func_L30_003B3A30` (412 bytes). Removing PAL lifetime scaling exposes a different constant-hoisting choice; the best current private attempt still differs by 91 words. Equal-size twin searches miss this relationship.

Several raw NTSC-U inventory entries contain preceding epilogues or linker fill. In particular, the real interior starts at frontbin `003932B0` and `003A0178`, and i5bootn `00802640`, are held by another contributor. These fragments are not additional C matches from this pass.
