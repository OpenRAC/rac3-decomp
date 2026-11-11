# Large-function families (rac3 PAL)

The biggest unmatched level functions are per-level copies of a few engine routines, as in
rac2-decomp (one routine per level with states added or pruned). Match one member (the root),
then port it to the others by opcode alignment and renaming. Measured 2026-11-08 over every
unmatched function of 8 KB or more plus the 61 functions prepared in `nonmatching/levels/`
(72 functions): opcode sequences with registers and addresses masked, `difflib` similarity.
Families are the groups linked at similarity 0.70 or more; 41 of the 72 are singletons.

Columns: size in bytes, VU0 = COP2/`lqc2`/`sqc2` words, places = levels that have it,
similarity = against the family root, `+`/`-`/`~` = instructions the member has in addition to,
lacks against, or changed from the root. "claimed": another contributor's scope in issue #3
(listed for the family picture only).

Flag notes for all families: the root files' lines are `-O2 -G8 -fopt-stack
-mno-check-zero-division`. Members with VU0 code whose sequences interleave with ordinary
instructions need the one-statement-per-instruction VU0 form, which compiles only with
`-mvu0-use-vf0-vf2` on the file's line (a whole-file flag: add it only when every other C
function of the file still matches with it). Drafts measured more opcodes equal with `@ps2as`
on the state-entry family (inline float constants). The drafts' headers in
`nonmatching/levels/<func>.c` have the rac2 mapping and the per-case detail.

## A1. Hero per-frame state machine, small variant (rac2: `func_L04_002E04A8`, `func_L19_002BCA50`)

Root: **`func_L08_004D6580`**, the smallest member (it is also 0.991 to the claimed L27 copy).
Its VU0 block count is the lowest of A1/A2. No member has a matched rac3 sibling yet.

| Member | Size | VU0 | Places | Similarity | + / - / ~ | Note |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| `func_L08_004D6580` | 22,016 | 91 | 1 | root | | rac2 `func_L19_002BCA50` 0.71 |
| `func_L27_004CA9C8` | 21,992 | 91 | 1 | 0.991 | +44 -50 ~3 | claimed |
| `func_L04_00504520` | 26,780 | 163 | 1 | 0.894 | +1241 -50 ~4 | rac2 `func_L19_002BCA50` 0.76 |
| `func_L09_0050E198` | 26,128 | 136 | 1 | 0.804 | +1652 -522 ~148 | 0.978 to L02 |
| `func_L02_004CAF58` | 27,212 | 152 | 1 | 0.787 | +1913 -518 ~158 | rac2 `func_L04_002E04A8` 0.79 |

## A2. Hero per-frame state machine, large variant (rac2: `func_L00_002BA7D8`, `func_L22_002BF1B0`)

Root: **`func_L01_004F5E98`** (20 places; the others are it plus or minus whole state bodies). It
is 0.77 to the A1 root, so A1 and A2 are one routine with different state sets.

| Member | Size | VU0 | Places | Similarity | Note |
| --- | ---: | ---: | ---: | ---: | --- |
| `func_L01_004F5E98` | 34,768 | 227 | 20 | root | rac2 `func_L00_002BA7D8` 0.79 |
| `func_L30_004C4318` | 37,828 | 249 | 7 | 0.954 | adds states 0x9A-0xAE (+791) |
| `func_L23_004D8188` | 38,108 | 231 | 1 | 0.950 | +854 |
| `func_L19_004EA280` | 29,368 | 207 | 1 | 0.915 | drops 1192 instructions |

## B. Decider (rac2: `func_L12_002CF7B0`, `func_L08_002D90C8`)

Root: **`func_L09_0051CD50`**: no VU0 at all, and the smallest. The best first target for Opus
among the families.

| Member | Size | VU0 | Places | Similarity | + / - / ~ | Note |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| `func_L09_0051CD50` | 22,344 | 0 | 1 | root | | rac2 `func_L08_002D90C8` 0.81 |
| `func_L02_004DA1D0` | 22,620 | 0 | 1 | 0.986 | +55 ~56 | |
| `func_L04_00513880` | 25,360 | 0 | 1 | 0.859 | +1172 -420 ~47 | also 0.858 to the B2 root |
| `func_L08_004E36C0` | 24,640 | 0 | 1 | 0.845 | +1156 -585 ~44 | 0.983 to L27 |
| `func_L27_004D7CD8` | 24,436 | 0 | 1 | 0.839 | +1156 -635 ~45 | claimed |

## B2. 0x110 dispatcher (rac2: `func_L20_002DEBE0`, `func_L22_002D0C98`)

Root: **`func_L19_004F9D80`** (smallest; 12 VU0 words, the same in every member). Once it
matches, `func_L01_00507AF8` (20 places) is a 0.966 port.

| Member | Size | VU0 | Places | Similarity | + / - / ~ |
| --- | ---: | ---: | ---: | ---: | --- |
| `func_L19_004F9D80` | 29,004 | 12 | 1 | root | |
| `func_L01_00507AF8` | 30,828 | 12 | 20 | 0.966 | +429 -1 ~53 |
| `func_L23_004EAE60` | 33,620 | 12 | 1 | 0.919 | +1127 -1 ~85 |
| `func_L30_004D7368` | 35,288 | 12 | 7 | 0.892 | +1569 -26 ~88 |

## C. Hero state entry (rac2: `func_L22_002C9898`, `func_L12_002C8BD0`)

Root: **`func_L08_004DD0C0`** (smallest, 4 VU0 words). Every other member is the root plus states.

| Member | Size | VU0 | Places | Similarity | + / - / ~ | Note |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| `func_L08_004DD0C0` | 15,200 | 4 | 1 | root | | rac2 `func_L12_002C8BD0` 0.70 |
| `func_L27_004D1568` | 15,564 | 4 | 1 | 0.980 | +108 -22 ~13 | claimed |
| `func_L04_0050CB28` | 16,592 | 4 | 1 | 0.949 | +365 -22 ~13 | |
| `func_L09_005164C0` | 15,360 | 4 | 1 | 0.897 | +382 -323 ~76 | |
| `func_L01_005003D0` | 19,048 | 12 | 20 | 0.883 | +949 -9 ~32 | claimed |
| `func_L02_004D36C0` | 15,996 | 8 | 1 | 0.879 | +532 -315 ~83 | |
| `func_L23_004E3428` | 19,804 | 12 | 1 | 0.864 | +1086 -9 ~84 | |
| `func_L19_004F32A0` | 16,944 | 12 | 1 | 0.852 | +721 -284 ~155 | |
| `func_L30_004CF4B0` | 20,956 | 16 | 7 | 0.836 | +1427 -10 ~32 | superset of all states |

## D. Level gameplay loader (rac2: `func_L00_00300618`)

| Member | Size | VU0 | Places | Similarity | Note |
| --- | ---: | ---: | ---: | ---: | --- |
| `func_L39_005A12B8` | 10,972 | 8 | 15 | root | file has `@ps2as`; rac2 0.84 |
| `func_L01_00428098` | 11,540 | 8 | 34 | 0.911 | claimed |

## E. Memory-card state machine (rac2: `func_00298F00`)

| Member | Size | VU0 | Places | Similarity | Note |
| --- | ---: | ---: | ---: | ---: | --- |
| `func_0039C410` (frontbin) | 8,652 | 0 | 2 programs | root | the cross-game port's scope |
| `func_L39_005A61D8` | 9,340 | 0 | 15 | 0.951 | draft at 98.9% opcodes equal |

## Singletons (8 KB or more, no family at 0.70)

`func_L39_0064EA40` (33.6 KB), `func_L39_00656F28`, `func_L20_003D0910`, `func_L06_0034A7A8`,
`func_L09_003B8580`, `func_L39_00640738`, `func_L22_003B3228`, `func_L01_003A0778`,
`func_L20_003FB6A8` (0.64 to `func_L05_003560C8`), `func_L24_00352060`, `func_L39_006BE7E0`,
`func_L20_003AF880`, `func_L01_003386E0`, `func_L39_00539398`, `func_L39_00624658`,
`func_L01_00350750`, `func_L08_003A4E60`, `func_L10_003B64C8`, `func_L39_0055B4D8`,
`func_L39_004ECE38` (not one function: 11 functions under one catalogue entry), `func_L23_003B1490`
and the claimed or cross-game ones in the same size range. Their drafts are in `nonmatching/levels/`.

## Order for Opus

1. B `func_L09_0051CD50` (no VU0), then port to L02 (0.986) and L04/L08.
2. C `func_L08_004DD0C0` (4 VU0 words), then L04 (0.949) and the rest.
3. E `func_L39_005A61D8` (draft 98.9% equal; 26 hunks listed in its header).
4. B2 `func_L19_004F9D80`, then `func_L01_00507AF8` (20 places).
5. A1/A2 last: the most VU0 code (91-249 words); they need the VU0 form and probably
   `-mvu0-use-vf0-vf2` on their files.
