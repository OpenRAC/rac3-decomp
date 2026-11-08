# Near misses and US drafts

C that is not linked and not counted: a starting point. One file per function,
`nonmatching/<program>/func_XXXXXXXX.c` (`<program>` is `frontbin`, `boot_elf`, `i5bootn` or `levels`,
the name is the PAL address), with a comment at its top saying where it came from and what still
differs. Move it into `src/` once the full build prints `MATCH` with it in place, and delete its
row here. `tests/check_repository.py` checks that every file has a row.

A draft that uses inline asm (beyond `.extern` size hints), `volatile`, a `#define` alias or a hardcoded address is a study aid, not a route to a match: those are not allowed in matched C, so such a function stays here until plain C matches.

Files that start with `/* US draft` are rac3-uya-decomp's C for that function (commit 13cf5c5),
with names moved to PAL addresses where the address maps are sure of them
(`tools/port_from_us.py`, docs/porting.md). They were not carried for the reason in their row:

- **flags**: the US match used flags of its own for this one function (a "single-function
  override" or `@ps2as` range), which this repository does not allow (docs/BUILD_FIDELITY.md);
- **differs**: the PAL function's bytes are not the US ones, or the C did not build to them here;
- **symbols**: a name in the C has no PAL address yet.

`functional.tsv` lists the US drafts OpenRAC's native port of NTSC-U reads in place of the
assembly (`tools/us_names.py --candidates`, docs/versions.md): C that matched NTSC-U, for a
function NTSC-U has and src/us/ has no C for.

| Function | Program | Source | What differs |
| --- | --- | --- | --- |
| `func_00122278` | boot_elf | US draft of `func_00122278` | flags: the US matched it with without `-mno-check-zero-division` (a single-function override) |
| `func_00136010` | boot_elf | US draft of `func_00136010` | flags: the US matched it with without `-mno-check-zero-division` (a single-function override) |
| `func_0013A9F0` | boot_elf | US draft of `func_0013A9F0` | flags: the US matched it with without `-mno-check-zero-division` (a single-function override) |
| `func_0013B330` | boot_elf | US draft of `func_0013B330` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013B3F8` | boot_elf | US draft of `func_0013B3F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013B620` | boot_elf | US draft of `func_0013B620` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013B918` | boot_elf | US draft of `func_0013B918` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013BAB8` | boot_elf | US draft of `func_0013BAB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013BC30` | boot_elf | US draft of `func_0013BC30` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013C908` | boot_elf | US draft of `func_0013C908` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013CD28` | boot_elf | US draft of `func_0013CD28` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0013CDF0` | boot_elf | US draft of `func_0013CDF0` | near miss: 5 diff with the file's flags (was 37) |
| `func_0013D290` | boot_elf | US draft of `func_0013D290` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_00382360` | boot_elf | US draft of `func_00382380` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003823D0` | boot_elf | US draft of `func_003823F0` | differs: did not build, or built to other bytes, in PAL |
| `func_003824D0` | boot_elf | US draft of `func_003824F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382918` | boot_elf | US draft of `func_00382938` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382BF0` | boot_elf | US draft of `func_00382BF8` | differs: did not build, or built to other bytes, in PAL |
| `func_00382CB8` | boot_elf | US draft of `func_00382CC0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00384598` | boot_elf | US draft of `func_00384578` | symbols: func_00383E38 |
| `func_00384878` | boot_elf | US draft of `func_00384850` | differs: did not build, or built to other bytes, in PAL |
| `func_00385168` | boot_elf | US draft of `func_00385140` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00385400` | boot_elf | US draft of `func_003853D8` | near miss: 144 diff with the file's flags (was 179) |
| `func_00385A98` | boot_elf | US draft of `func_00385A70` | differs: did not build, or built to other bytes, in PAL |
| `func_00386108` | boot_elf | US draft of `func_003860E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003862D0` | boot_elf | US draft of `func_003862A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00386488` | boot_elf | US draft of `func_00386460` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00386B10` | boot_elf | US draft of `func_00386AE8` | differs: did not build, or built to other bytes, in PAL |
| `func_00388ED8` | boot_elf | US draft of `func_00388E80` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038C8E0` | boot_elf | US draft of `func_0038C828` | differs: did not build, or built to other bytes, in PAL |
| `func_0038D198` | boot_elf | US draft of `func_0038D0E0` | symbols: func_00388680 func_0038D0F4 |
| `func_0038D230` | boot_elf | US draft of `func_0038D178` | symbols: func_00388718 func_0038D18C |
| `func_0038D348` | boot_elf | US draft of `func_0038D290` | symbols: func_0038D2DC |
| `func_0038D708` | boot_elf | US draft of `func_0038D650` | symbols: func_00388BF0 func_0038D66C |
| `func_0038D990` | boot_elf | US draft of `func_0038D8D8` | symbols: func_0038D914 |
| `func_0038DD58` | boot_elf | US draft of `func_0038DCA0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038DE48` | boot_elf | US draft of `func_0038DD90` | symbols: func_0038DDDC |
| `func_0038E4C8` | boot_elf | US draft of `func_0038E410` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_0038E530` | boot_elf | US draft of `func_0038E478` | differs: did not build, or built to other bytes, in PAL |
| `func_0038E5C8` | boot_elf | US draft of `func_0038E510` | near miss: 4 diff with the file's flags (the US draft: 106) |
| `func_00390768` | boot_elf | US draft of `func_003906A8` | near miss: 234 diff with the file's flags (was 510) |
| `func_00391708` | boot_elf | US draft of `func_00391648` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003917E8` | boot_elf | US draft of `func_00391728` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00391880` | boot_elf | US draft of `func_003917C0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00391A58` | boot_elf | US draft of `func_00391998` | flags: the US matched it with `-fno-rerun-loop-opt` `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00392640` | boot_elf | US draft of `func_00392580` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_00392F98` | boot_elf | US draft of `func_00392ED8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003931D0` | boot_elf | US draft of `func_00393110` | near miss: 7 diff with the file's flags (was 41) |
| `func_003932E8` | boot_elf | US draft of `func_00393228` | differs: did not build, or built to other bytes, in PAL |
| `func_00393548` | boot_elf | US draft of `func_00393488` | near miss: 5 diff with the file's flags (was 73) |
| `func_00393670` | boot_elf | US draft of `func_003935B0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00393728` | boot_elf | US draft of `func_00393668` | near miss: 57 diff with the file's flags (was 61) |
| `func_00393898` | boot_elf | US draft of `func_003937D8` | near miss: 3 diff with the file's flags (was 8) |
| `func_00393990` | boot_elf | US draft of `func_003938D0` | near miss: 16 diff with the file's flags (was 28) |
| `func_00393A70` | boot_elf | US draft of `func_003939B0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00393F38` | boot_elf | US draft of `func_00393E68` | near miss: 17 diff with the file's flags (was 34) |
| `func_00395370` | boot_elf | US draft of `func_00395288` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00396948` | boot_elf | US draft of `func_00396860` | differs: did not build, or built to other bytes, in PAL |
| `func_00396AB8` | boot_elf | US draft of `func_003969D0` | near miss: 25 diff with the file's flags (the US draft: 49) |
| `func_00396C18` | boot_elf | US draft of `func_00396B30` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00397230` | boot_elf | US draft of `func_00397148` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_00397EF0` | boot_elf | US draft of `func_00397E08` | differs: did not build, or built to other bytes, in PAL |
| `func_00397FC0` | boot_elf | US draft of `func_00397ED8` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00398288` | boot_elf | US draft of `func_003981A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398878` | boot_elf | US draft of `func_00398760` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039A148` | boot_elf | US draft of `func_0039A030` | near miss: 42 diff with the file's flags (was 57) |
| `func_0039A530` | boot_elf | US draft of `func_0039A418` | near miss: 10 diff with the file's flags (was 16) |
| `func_0039A5C0` | boot_elf | US draft of `func_0039A4A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039A818` | boot_elf | US draft of `func_0039A700` | symbols: func_003C2898 |
| `func_0039B088` | boot_elf | US draft of `func_0039AF70` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039BD20` | boot_elf | US draft of `func_0039BC08` | near miss: 4 diff with the file's flags (was 7) |
| `func_0039BD90` | boot_elf | US draft of `func_0039BC78` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_0039C170` | boot_elf | US draft of `func_0039C058` | checks MATCH alone with its file's flags (`@ps2as`), but in place it changes how the full build compiles the next function, `func_0039C1A0` (7 diff; check the file whole: `tools/check.py src/boot_elf/text/39BE18.c func_0039C170 func_0039C1A0 --no-context`) |
| `func_0039F960` | boot_elf | US draft of `func_0039F848` | near miss: 3 diff with the file's flags (the US draft: 7) |
| `func_0039FE68` | boot_elf | US draft of `func_0039FD50` | near miss: 7 diff with the file's flags (was 18) |
| `func_003A1148` | boot_elf | US draft of `func_003A1008` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A2028` | boot_elf | US draft of `func_003A1EE8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A2A80` | boot_elf | US draft of `func_003A2940` | near miss: 4 diff with the file's flags (was 21) |
| `func_003A2FC0` | boot_elf | US draft of `func_003A2E80` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A31C8` | boot_elf | US draft of `func_003A3088` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A3B40` | boot_elf | US draft of `func_003A3A00` | near miss: 19 diff with the file's flags (was 239) |
| `func_003A4228` | boot_elf | US draft of `func_003A40E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A53F8` | boot_elf | US draft of `func_003A52B8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A5AF8` | boot_elf | US draft of `func_003A59B8` | near miss: 39 diff with the file's flags (the US draft: 87) |
| `func_003A6578` | boot_elf | US draft of `func_003A6438` | symbols: func_003D9760_003A6438 |
| `func_003A6C90` | boot_elf | US draft of `func_003A6B18` | symbols: func_003A4548 func_003A7DB0 func_003A82F8 func_003E5950 |
| `func_003A7328` | boot_elf | US draft of `func_003A71B0` | symbols: func_003A4548 |
| `func_003A76A0` | boot_elf | US draft of `func_003A7528` | symbols: func_003A4548 |
| `func_003A8708` | boot_elf | US draft of `func_003A85C0` | differs: did not build, or built to other bytes, in PAL |
| `func_003AA168` | boot_elf | US draft of `func_003AA020` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AACF8` | boot_elf | US draft of `func_003AABA0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AADB8` | boot_elf | US draft of `func_003AAC60` | differs: did not build, or built to other bytes, in PAL |
| `func_003ABBE8` | boot_elf | US draft of `func_003ABA48` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003ABDB0` | boot_elf | US draft of `func_003ABC10` | near miss: 1 diff with the file's flags (the US draft: 7) |
| `func_003ABFA0` | boot_elf | US draft of `func_003ABE00` | differs: did not build, or built to other bytes, in PAL |
| `func_003AC360` | boot_elf | US draft of `func_003AC1C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AC590` | boot_elf | US draft of `func_003AC3F0` | near miss: 22 diff with the file's flags (was 25) |
| `func_003AC9F0` | boot_elf | US draft of `func_003AC850` | differs: did not build, or built to other bytes, in PAL |
| `func_003ACD00` | boot_elf | US draft of `func_003ACB60` | near miss: 74 diff with the file's flags (was 76) |
| `func_003AD7E0` | boot_elf | US draft of `func_003AD640` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF1F0` | boot_elf | US draft of `func_003AF050` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF470` | boot_elf | US draft of `func_003AF2D0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF7C0` | boot_elf | US draft of `func_003AF620` | flags: the US matched it with without `-fopt-stack` `@ps2as` (a single-function override) |
| `func_003AFC48` | boot_elf | US draft of `func_003AFAA8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AFE10` | boot_elf | US draft of `func_003AFC70` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B08E8` | boot_elf | US draft of `func_003B0748` | flags: the US matched it with without `-fopt-stack` (a single-function override) |
| `func_003B0D08` | boot_elf | US draft of `func_003B0B68` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003B0F70` | boot_elf | US draft of `func_003B0DD0` | near miss: 71 diff with the file's flags (the US draft: 77) |
| `func_003B2A00` | boot_elf | US draft of `func_003B2860` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B2A68` | boot_elf | US draft of `func_003B28C8` | near miss: 3 diff with the file's flags (was 17) |
| `func_003B2FB0` | boot_elf | US draft of `func_003B2E10` | flags: the US matched it with `-fno-schedule-insns` and without `-mno-split-addresses` (a single-function override) |
| `func_003B3440` | boot_elf | US draft of `func_003B32A0` | differs: did not build, or built to other bytes, in PAL |
| `func_003B3510` | boot_elf | US draft of `func_003B3370` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B38E8` | boot_elf | US draft of `func_003B3748` | near miss: 2 diff with the file's flags (was 20) |
| `func_003B4218` | boot_elf | US draft of `func_003B4068` | near miss: 241 diff with the file's flags (was 253) |
| `func_003B4678` | boot_elf | US draft of `func_003B44C8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B4738` | boot_elf | US draft of `func_003B4588` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B47F0` | boot_elf | US draft of `func_003B4640` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B4A10` | boot_elf | US draft of `func_003B4860` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B4C30` | boot_elf | US draft of `func_003B4A80` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B5088` | boot_elf | US draft of `func_003B4ED8` | near miss: 39 diff with the file's flags (was 154) |
| `func_003B55D8` | boot_elf | US draft of `func_003B5428` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B5890` | boot_elf | US draft of `func_003B56E0` | symbols: func_003B6220 |
| `func_003B5C10` | boot_elf | US draft of `func_003B5A60` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B6128` | boot_elf | US draft of `func_003B5F78` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B6940` | boot_elf | US draft of `func_003B6868` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B6CC8` | boot_elf | US draft of `func_003B6BF0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B8040` | boot_elf | US draft of `func_003B7F68` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B8390` | boot_elf | US draft of `func_003B82B8` | differs: did not build, or built to other bytes, in PAL |
| `func_003B9650` | boot_elf | US draft of `func_003B9578` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003B9C58` | boot_elf | US draft of `func_003B9B80` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003BA280` | boot_elf | US draft of `func_003BA1A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BA9C0` | boot_elf | US draft of `func_003BA8E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BB348` | boot_elf | US draft of `func_003BB270` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BB760` | boot_elf | US draft of `func_003BB688` | flags: the US matched it with `-mno-split-addresses` and without `@ps2as` (a single-function override) |
| `func_003BB988` | boot_elf | US draft of `func_003BB8B0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BBC00` | boot_elf | US draft of `func_003BBB28` | near miss: 14 diff with the file's flags (was 35) |
| `func_003BBD20` | boot_elf | US draft of `func_003BBC48` | near miss: 25 diff with the file's flags (was 31) |
| `func_003BC7C0` | boot_elf | US draft of `func_003BC6E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BCA50` | boot_elf | US draft of `func_003BC978` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BCC10` | boot_elf | US draft of `func_003BCB38` | differs: did not build, or built to other bytes, in PAL |
| `func_003BDCF0` | boot_elf | US draft of `func_003BDC00` | symbols: func_003BDA80 |
| `func_003BE0F0` | boot_elf | US draft of `func_003BE000` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003BEA10` | boot_elf | US draft of `func_003BE920` | differs: did not build, or built to other bytes, in PAL |
| `func_003BEB68` | boot_elf | US draft of `func_003BEA78` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BF2B8` | boot_elf | US draft of `func_003BF1C8` | differs: did not build, or built to other bytes, in PAL |
| `func_003BF658` | boot_elf | US draft of `func_003BF568` | differs: did not build, or built to other bytes, in PAL |
| `func_003BFB58` | boot_elf | US draft of `func_003BFA68` | near miss: 6 diff with the file's flags (was 37) |
| `func_003C0010` | boot_elf | US draft of `func_003BFF08` | differs: did not build, or built to other bytes, in PAL |
| `func_003C0268` | boot_elf | US draft of `func_003C0160` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003C0760` | boot_elf | US draft of `func_003C0658` | differs: did not build, or built to other bytes, in PAL |
| `func_003C0E88` | boot_elf | US draft of `func_003C0D80` | near miss: 20 diff with the file's flags (was 24) |
| `func_003C1318` | boot_elf | US draft of `func_003C1210` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C1638` | boot_elf | US draft of `func_003C1530` | symbols: func_003C1558 |
| `func_003C1848` | boot_elf | US draft of `func_003C1740` | symbols: func_003A7DB0 |
| `func_003C19B8` | boot_elf | US draft of `func_003C18B0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C2868` | boot_elf | US draft of `func_003C2770` | symbols: func_003C2898 |
| `func_003C2D00` | boot_elf | US draft of `func_003C2BE8` | near miss: 6 diff with the file's flags (was 20) |
| `func_003C3A78` | boot_elf | US draft of `func_003C3960` | near miss: 9 diff with the file's flags (was 38) |
| `func_003C3FA0` | boot_elf | US draft of `func_003C3E68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C40E8` | boot_elf | US draft of `func_003C3FB0` | flags: the US matched it with `@ps2as` (a flag range the PAL file does not have) |
| `func_003C4280` | boot_elf | US draft of `func_003C4148` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_003C4558` | boot_elf | US draft of `func_003C4420` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4718` | boot_elf | US draft of `func_003C45E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4958` | boot_elf | US draft of `func_003C4818` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C5110` | boot_elf | US draft of `func_003C4FA8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003C5238` | boot_elf | US draft of `func_003C50D0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C5728` | boot_elf | US draft of `func_003C55C8` | differs: did not build, or built to other bytes, in PAL |
| `func_003C5A98` | boot_elf | US draft of `func_003C5948` | symbols: func_003C3CB0 func_003C4CB8 |
| `func_003C6420` | boot_elf | US draft of `func_003C62D0` | near miss: 29 diff with the file's flags (was 33) |
| `func_003C6720` | boot_elf | US draft of `func_003C65D0` | differs: did not build, or built to other bytes, in PAL |
| `func_003C6A38` | boot_elf | US draft of `func_003C68F0` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003C6D48` | boot_elf | US draft of `func_003C6C00` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003CE7F8` | boot_elf | US draft of `func_003CE690` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003CE9A0` | boot_elf | US draft of `func_003CE838` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003CF1B0` | boot_elf | US draft of `func_003CF048` | differs: did not build, or built to other bytes, in PAL |
| `func_003D0ED8` | boot_elf | US draft of `func_003D0D70` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D1280` | boot_elf | US draft of `func_003D1118` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_003D1768` | boot_elf | US draft of `func_003D1600` | symbols: func_003D2110 func_003D2300 func_003D2770 func_003D2A10 |
| `func_003D30F8` | boot_elf | US draft of `func_003D2F90` | symbols: func_003D2FEC |
| `func_003D7790` | boot_elf | US draft of `func_003D7628` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D90A8` | boot_elf | US draft of `func_003D8F40` | flags: the US matched it with without `-fopt-stack` (a flag range the PAL file does not have) |
| `func_003D9AF8` | boot_elf | US draft of `func_003D99A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D9FB8` | boot_elf | US draft of `func_003D9E70` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003DA0A8` | boot_elf | US draft of `func_003D9F60` | near miss: 12 diff with the file's flags (was 37) |
| `func_003DA160` | boot_elf | US draft of `func_003DA018` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003E17D0` | boot_elf | US draft of `func_003E1688` | near miss: 342 diff with the file's flags (was 356) |
| `func_003E41F8` | boot_elf | US draft of `func_003E40B0` | differs: did not build, or built to other bytes, in PAL |
| `func_003E47F8` | boot_elf | US draft of `func_003E46B0` | differs: did not build, or built to other bytes, in PAL |
| `func_003E5128` | boot_elf | US draft of `func_003E4FE0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E60A0` | boot_elf | US draft of `func_003E5F58` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003E6798` | boot_elf | US draft of `func_003E6650` | near miss: 56 diff with the file's flags (was 71) |
| `func_003E6FC0` | boot_elf | US draft of `func_003E6E78` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003E7620` | boot_elf | US draft of `func_003E74D8` | differs: did not build, or built to other bytes, in PAL |
| `func_003E7860` | boot_elf | US draft of `func_003E7700` | near miss: 2 diff with the file's flags (was 19) |
| `func_003E9828` | boot_elf | US draft of `func_003E96C8` | near miss: 507 diff with the file's flags (was 522) |
| `func_003EB628` | boot_elf | US draft of `func_003EB4C8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EBE58` | boot_elf | US draft of `func_003EBCF8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EC870` | boot_elf | US draft of `func_003EC710` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ECF58` | boot_elf | US draft of `func_003ECDF8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ED5B0` | boot_elf | US draft of `func_003ED450` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EDD40` | boot_elf | US draft of `func_003EDBE0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EE310` | boot_elf | US draft of `func_003EE1B0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003EE3F0` | boot_elf | US draft of `func_003EE290` | near miss: 39 diff with the file's flags (was 71) |
| `func_003EE560` | boot_elf | US draft of `func_003EE400` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EEB18` | boot_elf | US draft of `func_003EE9B8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EEBB8` | boot_elf | US draft of `func_003EEA58` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EF1D8` | boot_elf | US draft of `func_003EF078` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EF658` | boot_elf | US draft of `func_003EF4F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EF998` | boot_elf | US draft of `func_003EF838` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EFF68` | boot_elf | US draft of `func_003EFE08` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003F0AC0` | boot_elf | US draft of `func_003F0940` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003F0C98` | boot_elf | US draft of `func_003F0B18` | near miss: 5 diff with the file's flags (was 38) |
| `func_003F10A8` | boot_elf | US draft of `func_003F0EE8` | differs: did not build, or built to other bytes, in PAL |
| `func_003F1D50` | boot_elf | US draft of `func_003F1B90` | differs: did not build, or built to other bytes, in PAL |
| `func_003F2118` | boot_elf | US draft of `func_003F1F58` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003F22E0` | boot_elf | US draft of `func_003F2120` | near miss: 46 diff with the file's flags (was 53) |
| `func_00381D88` | frontbin | US draft of `func_0037DD30` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00381F80` | frontbin | US draft of `func_0037DF28` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00381FF0` | frontbin | NTSC decomp draft of `func_0037DF98`, rewritten as plain C | 2 differences with existing flags: table pointer uses `$a0` instead of `$v0`; no register pins or barriers |
| `func_003822C8` | frontbin | boot_elf's C of `func_003826A8` | near miss: 1 diff with the file's flags (boot_elf's copy is C) |
| `func_00382380` | frontbin | US draft of `func_0037E0F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003828D8` | frontbin | US draft of `func_0037E630` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382E10` | frontbin | US draft of `func_0037EB68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003834D0` | frontbin | US draft of `func_0037F228` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003841B8` | frontbin | US draft of `func_0037FEE8` | symbols: func_0037F7A8 |
| `func_00384498` | frontbin | US draft of `func_003801C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00384778` | frontbin | US draft of `func_003804A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003848D8` | frontbin | US draft of `func_00380600` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00384D88` | frontbin | US draft of `func_00380AB0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00385020` | frontbin | US draft of `func_00380D48` | near miss: 117 diff with the file's flags (was 179) |
| `func_003856B8` | frontbin | US draft of `func_003813E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003860A8` | frontbin | US draft of `func_00381DD0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003861F0` | frontbin | US draft of `func_00381F18` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003865A0` | frontbin | US draft of `func_003822C8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_00386730` | frontbin | US draft of `func_00382458` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00388AF8` | frontbin | US draft of `func_00384420` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389370` | frontbin | US draft of `func_00384C98` | flags: the US matched it with `-fno-schedule-insns` `@ps2as` (a single-function override) |
| `func_00389598` | frontbin | US draft of `func_00384EC0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389B10` | frontbin | US draft of `func_00385438` | near miss: 8 diff with the file's flags (was 55) |
| `func_0038A058` | frontbin | US draft of `func_00385980` | near miss: 61 diff with the file's flags (the US draft: 114) |
| `func_0038A948` | frontbin | US draft of `func_00386210` | near miss: 118 diff with the file's flags (was 155) |
| `func_0038AF30` | frontbin | US draft of `func_003867F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038B120` | frontbin | US draft of `func_003869E8` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_0038B4D0` | frontbin | US draft of `func_00386D98` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_0038BA30` | frontbin | US draft of `func_003872F8` | near miss: 150 diff with the file's flags (was 155) |
| `func_0038BCD8` | frontbin | US draft of `func_003875A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038C138` | frontbin | US draft of `func_00387A00` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038C248` | frontbin | US draft of `func_00387B10` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038C310` | frontbin | US draft of `func_00387BD8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_0038C500` | frontbin | US draft of `func_00387DC8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038C750` | frontbin | US draft of `func_00388018` | near miss: 58 diff with the file's flags (was 123) |
| `func_0038D2D0` | frontbin | US draft of `func_00388B98` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D308` | frontbin | US draft of `func_00388BD0` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D328` | frontbin | US draft of `func_00388BF0` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D5B0` | frontbin | US draft of `func_00388E78` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D5F0` | frontbin | US draft of `func_00388EB8` | final as `ASM_FUNC` in src/frontbin/38D278.c: VU0 macro code (lqc2, vmulax), hand-written assembly like its neighbours; the inline-asm draft is for study only: inline asm is not allowed in matched C and it is never a route to a match |
| `func_0038D688` | frontbin | US draft of `func_00388F50` | final as `ASM_FUNC` in src/frontbin/38D278.c: VU0 macro code (lqc2, vmulax), hand-written assembly like its neighbours; the inline-asm draft is for study only: inline asm is not allowed in matched C and it is never a route to a match |
| `func_0038D6C8` | frontbin | US draft of `func_00388F90` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D810` | frontbin | US draft of `func_003890D8` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D830` | frontbin | US draft of `func_003890F8` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038D850` | frontbin | US draft of `func_00389118` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038DA10` | frontbin | US draft of `func_003892D8` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038DA68` | frontbin | US draft of `func_00389330` | flags: the US matched it with without `@ps2as` (a single-function override) |
| `func_0038DBA0` | frontbin | US draft of `func_00389468` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_0038DED0` | frontbin | US draft of `func_003896E8` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_0038E150` | frontbin | US draft of `func_00389920` | differs: did not build, or built to other bytes, in PAL |
| `func_0038E1E8` | frontbin | US draft of `func_003899B8` | near miss: 2 diff with the file's flags (the US draft: 106) |
| `func_00390388` | frontbin | US draft of `func_0038BB50` | near miss: 179 diff with the file's flags (was 510) |
| `func_00391328` | frontbin | US draft of `func_0038CAF0` | near miss: 2 diff with the file's flags (was 21) |
| `func_00391408` | frontbin | US draft of `func_0038CBD0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003914A0` | frontbin | US draft of `func_0038CC68` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00391678` | frontbin | US draft of `func_0038CE40` | flags: the US matched it with `-fno-rerun-loop-opt` `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00392260` | frontbin | US draft of `func_0038DA28` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003922B8` | frontbin | US draft of `func_0038DA80` | near miss: 26 diff with the file's flags (was 36) |
| `func_00392350` | frontbin | US draft of `func_0038DB18` | near miss: 24 diff with the file's flags (was 31) |
| `func_003923D0` | frontbin | US draft of `func_0038DB98` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00392440` | frontbin | US draft of `func_0038DC08` | near miss: 134 diff with the file's flags (was 160) |
| `func_003926E8` | frontbin | US draft of `func_0038DEB0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00392748` | frontbin | US draft of `func_0038DF10` | near miss: 65 diff with the file's flags (was 71) |
| `func_00392868` | frontbin | US draft of `func_0038E030` | near miss: 84 diff with the file's flags (the US draft: 85) |
| `func_00392BB8` | frontbin | US draft of `func_0038E380` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_00392DF0` | frontbin | US draft of `func_0038E5B8` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00392F08` | frontbin | US draft of `func_0038E6D0` | differs: did not build, or built to other bytes, in PAL |
| `func_00393168` | frontbin | US draft of `func_0038E930` | near miss: 25 diff with the file's flags (was 73) |
| `func_00393290` | frontbin | US draft of `func_0038EA58` | near miss: 4 diff with the file's flags (the US draft: 7) |
| `func_00393348` | frontbin | US draft of `func_0038EB10` | near miss: 23 diff with the file's flags (was 61) |
| `func_003934B8` | frontbin | US draft of `func_0038EC80` | near miss: 3 diff with the file's flags (was 8) |
| `func_003935B0` | frontbin | US draft of `func_0038ED78` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_00393690` | frontbin | US draft of `func_0038EE58` | near miss: 27 diff with the file's flags (the US draft: 78) |
| `func_00393B58` | frontbin | US draft of `func_0038F310` | near miss: 19 diff with the file's flags (was 34) |
| `func_00394F90` | frontbin | US draft of `func_00390730` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00396278` | frontbin | US draft of `func_00391A18` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_00396568` | frontbin | US draft of `func_00391D08` | near miss: 17 diff with the file's flags (was 69) |
| `func_00396690` | frontbin | US draft of `func_00391E30` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003966D8` | frontbin | US draft of `func_00391E78` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00396838` | frontbin | US draft of `func_00391FD8` | near miss: 6 diff with the file's flags (was 73) |
| `func_00396C60` | frontbin | US draft of `func_00392400` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00396E50` | frontbin | US draft of `func_003925F0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003970D8` | frontbin | US draft of `func_00392878` | near miss: 2 diff with the file's flags (the US draft: 91) |
| `func_003972A0` | frontbin | US draft of `func_00392A40` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00397638` | frontbin | US draft of `func_00392DD8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00397BE0` | frontbin | US draft of `func_00393380` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_00397D48` | frontbin | US draft of `func_003934E8` | near miss: 9 diff with the file's flags (the US draft: 11) |
| `func_00398498` | frontbin | US draft of `func_003936A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398668` | frontbin | US draft of `func_00393878` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398808` | frontbin | US draft of `func_00393A18` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398A88` | frontbin | US draft of `func_00393C98` | near miss: 7 diff with the file's flags (was 69) |
| `func_00398BB8` | frontbin | US draft of `func_00393DC8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398C80` | frontbin | US draft of `func_00393E90` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00398E50` | frontbin | US draft of `func_00394060` | near miss: 151 diff with the file's flags (was 163) |
| `func_003990F0` | frontbin | US draft of `func_00394300` | near miss: 10 diff with the file's flags (was 18) |
| `func_00399450` | frontbin | US draft of `func_00394660` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003995A0` | frontbin | US draft of `func_003947B0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00399D68` | frontbin | US draft of `func_00394F78` | near miss: 3 diff with the file's flags (was 57) |
| `func_0039A150` | frontbin | US draft of `func_00395360` | near miss: 10 diff with the file's flags (was 16) |
| `func_0039A1E0` | frontbin | US draft of `func_003953F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039A438` | frontbin | US draft of `func_00395648` | near miss: 38 diff with the file's flags (was 39) |
| `func_0039ACA8` | frontbin | US draft of `func_00395EB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039ADE0` | frontbin | PAL near miss (PR #10) | 4 diff with the file's flags: the second read of the flag word at 0x1D4CEC is scheduled before the store that retail makes first |
| `func_0039B9B0` | frontbin | PAL near miss (PR #10) | 3 diff with the file's flags: the struct base `lui` is scheduled before the flag load (retail has the load first) |
| `func_0039BA38` | frontbin | PAL near miss (PR #10) | 8 diff with the file's flags: the flag load and the struct base `lui` are in the other order, and the registers follow |
| `func_0039C410` | frontbin | US draft of `func_00397490` | flags: the US matched it with `@ps2as` and without `-fno-force-mem` (a single-function override) |
| `func_0039EC28` | frontbin | PAL near miss (PR #10) | 65 diff with the file's flags: prologue order and the layout of the early returns |
| `func_0039F108` | frontbin | PAL near miss (PR #10) | 19 diff with the file's flags: rotation of the last loop (retail loads `f2c` in the `beql` delay slot) |
| `func_0039FA88` | frontbin | PAL near miss (PR #10) | 3 diff with the file's flags: only the order of `sll` against the `lui`/`addiu` of the table address; about 15 variants of the table access and the index did not move it |
| `func_0039FDA0` | frontbin | US draft of `func_0039AE08` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A0D48` | frontbin | US draft of `func_0039BD48` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A0EC0` | frontbin | US draft of `func_0039BEC0` | near miss: 7 diff with the file's flags (was 47) |
| `func_003A0F98` | frontbin | US draft of `func_0039BF98` | near miss: 29 diff with the file's flags (was 33) |
| `func_003A1F30` | frontbin | US draft of `func_0039CEA8` | differs: did not build, or built to other bytes, in PAL |
| `func_003A2680` | frontbin | US draft of `func_0039D5F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A2DC8` | frontbin | US draft of `func_0039DB38` | differs: did not build, or built to other bytes, in PAL |
| `func_003A3E28` | frontbin | US draft of `func_0039EB98` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A4FF8` | frontbin | US draft of `func_0039FBD8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A56F8` | frontbin | US draft of `func_003A02D8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A6178` | frontbin | US draft of `func_003A0D58` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A6890` | frontbin | US draft of `func_003A1438` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A6CC8` | frontbin | US draft of `func_003A1870` | near miss: 74 diff with the file's flags (was 75) |
| `func_003A6F28` | frontbin | US draft of `func_003A1AD0` | near miss: 38 diff with the file's flags (was 182) |
| `func_003A72A0` | frontbin | US draft of `func_003A1E48` | near miss: 20 diff with the file's flags (the US draft: 59) |
| `func_003A7480` | frontbin | US draft of `func_003A2028` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A7618` | frontbin | US draft of `func_003A21C0` | near miss: 4 diff with the file's flags (was 164) |
| `func_003A8308` | frontbin | US draft of `func_003A2EE0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A8450` | frontbin | US draft of `func_003A3028` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A8678` | frontbin | US draft of `func_003A3128` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A8770` | frontbin | US draft of `func_003A3220` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A8980` | frontbin | US draft of `func_003A3430` | near miss: 17 diff with the file's flags (was 22) |
| `func_003A8A58` | frontbin | US draft of `func_003A3508` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9050` | frontbin | US draft of `func_003A3B00` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9108` | frontbin | US draft of `func_003A3BB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A91D0` | frontbin | US draft of `func_003A3C80` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9338` | frontbin | US draft of `func_003A3DE8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9440` | frontbin | US draft of `func_003A3EF0` | near miss: 43 diff with the file's flags (was 45) |
| `func_003A9618` | frontbin | US draft of `func_003A40C8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9678` | frontbin | US draft of `func_003A4128` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9740` | frontbin | US draft of `func_003A41F0` | near miss: 55 diff with the file's flags (was 56) |
| `func_003A9830` | frontbin | US draft of `func_003A42E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9AD0` | frontbin | US draft of `func_003A4580` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9C70` | frontbin | US draft of `func_003A4720` | near miss: 8 diff with the file's flags (the US draft: 11) |
| `func_003A9DB0` | frontbin | US draft of `func_003A4860` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AA940` | frontbin | US draft of `func_003A53E0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AAA00` | frontbin | US draft of `func_003A54A0` | differs: did not build, or built to other bytes, in PAL |
| `func_003AB9F8` | frontbin | US draft of `func_003A6450` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ABBE8` | frontbin | US draft of `func_003A6640` | differs: did not build, or built to other bytes, in PAL |
| `func_003AC1D8` | frontbin | US draft of `func_003A6C30` | near miss: 27 diff with the file's flags (was 30) |
| `func_003AC638` | frontbin | US draft of `func_003A7090` | differs: did not build, or built to other bytes, in PAL |
| `func_003AC948` | frontbin | US draft of `func_003A73A0` | near miss: 58 diff with the file's flags (was 60) |
| `func_003ACC38` | frontbin | US draft of `func_003A7690` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AD278` | frontbin | US draft of `func_003A7CD0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AD428` | frontbin | US draft of `func_003A7E80` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AEE38` | frontbin | US draft of `func_003A9890` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF0B8` | frontbin | US draft of `func_003A9B10` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF2A0` | frontbin | US draft of `func_003A9CF8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003AF3A8` | frontbin | US draft of `func_003A9E00` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF408` | frontbin | US draft of `func_003A9E60` | flags: the US matched it with without `-fopt-stack` `-mno-split-addresses` (a single-function override) |
| `func_003AF498` | frontbin | US draft of `func_003A9EF0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF628` | frontbin | US draft of `func_003AA080` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF660` | frontbin | US draft of `func_003AA0B8` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AF838` | frontbin | US draft of `func_003AA290` | near miss: 2 diff with the file's flags (the US draft: 14) |
| `func_003AF890` | frontbin | US draft of `func_003AA2E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AFA58` | frontbin | US draft of `func_003AA4B0` | near miss: 181 diff with the file's flags (was 192) |
| `func_003AFDD0` | frontbin | US draft of `func_003AA828` | near miss: 34 diff with the file's flags (the US draft: 80) |
| `func_003AFFA8` | frontbin | US draft of `func_003AAA00` | near miss: 2 diff with the file's flags (was 37) |
| `func_003B0530` | frontbin | US draft of `func_003AAF88` | flags: the US matched it with without `-fopt-stack` (a single-function override) |
| `func_003B0950` | frontbin | US draft of `func_003AB3A8` | near miss: 107 diff with the file's flags (was 123) |
| `func_003B0BB8` | frontbin | US draft of `func_003AB610` | near miss: 71 diff with the file's flags (the US draft: 77) |
| `func_003B0FF0` | frontbin | US draft of `func_003ABA48` | near miss: 18 diff with the file's flags (was 49) |
| `func_003B1108` | frontbin | US draft of `func_003ABB60` | near miss: 12 diff with the file's flags (was 33) |
| `func_003B2648` | frontbin | US draft of `func_003AD0A0` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B26B0` | frontbin | US draft of `func_003AD108` | near miss: 3 diff with the file's flags (was 17) |
| `func_003B3088` | frontbin | US draft of `func_003ADAE0` | differs: did not build, or built to other bytes, in PAL |
| `func_003B3158` | frontbin | US draft of `func_003ADBB0` | near miss: 7 diff with the file's flags (was 45) |
| `func_003B3258` | frontbin | US draft of `func_003ADCB0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B3530` | frontbin | US draft of `func_003ADF88` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B36C8` | frontbin | US draft of `func_003AE120` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B3E60` | frontbin | US draft of `func_003AE8A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B42C0` | frontbin | US draft of `func_003AED08` | near miss: 6 diff with the file's flags (was 8) |
| `func_003B4380` | frontbin | US draft of `func_003AEDC8` | near miss: 5 diff with the file's flags (the US draft: 6) |
| `func_003B4438` | frontbin | US draft of `func_003AEE80` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003B4658` | frontbin | US draft of `func_003AF0A0` | 2 differences: table store and return-pointer move reversed; four user checks without improvement (table-first forms: 5, table-last: same 2); original struct-based draft retained, attempt stopped, not integrated |
| `func_003B4878` | frontbin | US draft of `func_003AF2C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B4CD0` | frontbin | US draft of `func_003AF718` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B5220` | frontbin | US draft of `func_003AFC68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B54D8` | frontbin | US draft of `func_003AFF20` | symbols: func_003B0A60 |
| `func_003B5858` | frontbin | US draft of `func_003B02A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B5D70` | frontbin | US draft of `func_003B07B8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B6280` | frontbin | US draft of `func_003B0DA0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B6588` | frontbin | US draft of `func_003B10A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B66F0` | frontbin | US draft of `func_003B1210` | near miss: 7 diff with the file's flags (was 27) |
| `func_003B6910` | frontbin | US draft of `func_003B1430` | near miss: 16 diff with the file's flags (was 23) |
| `func_003B6AC0` | frontbin | US draft of `func_003B15E0` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003B6B90` | frontbin | US draft of `func_003B16B0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B7288` | frontbin | US draft of `func_003B1DA8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B77A0` | frontbin | US draft of `func_003B22C0` | near miss: 73 diff with the file's flags (was 77) |
| `func_003B78D8` | frontbin | US draft of `func_003B23F8` | near miss: 85 diff with the file's flags (was 144) |
| `func_003B7C88` | frontbin | US draft of `func_003B27A8` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B7F80` | frontbin | US draft of `func_003B2AA0` | near miss: 6 diff with the file's flags (the US draft: 19) |
| `func_003B7FD8` | frontbin | US draft of `func_003B2AF8` | near miss: 267 diff with the file's flags (was 272) |
| `func_003B8430` | frontbin | US draft of `func_003B2F50` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B9298` | frontbin | US draft of `func_003B3DB8` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003B98A0` | frontbin | US draft of `func_003B43C0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003B9A90` | frontbin | US draft of `func_003B45B0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003B9EC8` | frontbin | US draft of `func_003B49E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BA608` | frontbin | US draft of `func_003B5128` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BAF90` | frontbin | US draft of `func_003B5AB0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BB1F0` | frontbin | US draft of `func_003B5D10` | near miss: 68 diff with the file's flags (the US draft: 100) |
| `func_003BB3A8` | frontbin | US draft of `func_003B5EC8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BB468` | frontbin | US draft of `func_003B5F88` | near miss: 44 diff with the file's flags (was 45) |
| `func_003BB530` | frontbin | US draft of `func_003B6050` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BB5D0` | frontbin | US draft of `func_003B60F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BB848` | frontbin | US draft of `func_003B6368` | near miss: 34 diff with the file's flags (was 35) |
| `func_003BB968` | frontbin | US draft of `func_003B6488` | near miss: 30 diff with the file's flags (was 31) |
| `func_003BC408` | frontbin | US draft of `func_003B6F28` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BC858` | frontbin | US draft of `func_003B7378` | near miss: 87 diff with the file's flags (was 91) |
| `func_003BCA48` | frontbin | US draft of `func_003B7568` | near miss: 13 diff with the file's flags (was 34) |
| `func_003BCAF8` | frontbin | US draft of `func_003B7618` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BCDA8` | frontbin | US draft of `func_003B78C8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BCF80` | frontbin | US draft of `func_003B7AA0` | near miss: 41 diff with the file's flags (was 43) |
| `func_003BD390` | frontbin | US draft of `func_003B7EB0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BD4B8` | frontbin | US draft of `func_003B7FD8` | near miss: 4 diff with the file's flags (the US draft: 86) |
| `func_003BD760` | frontbin | US draft of `func_003B8280` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BD938` | frontbin | US draft of `func_003B8440` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BDCB0` | frontbin | US draft of `func_003B87B8` | user NTSC-U check of pointer-based do/while: 13 differences in setup/registers, size 84 bytes; for-loop revision awaiting user check with the owning file's flags |
| `func_003BDD38` | frontbin | US draft of `func_003B8840` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BE3F0` | frontbin | US draft of `func_003B8EF8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BE448` | frontbin | US draft of `func_003B8F50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BE658` | frontbin | US draft of `func_003B9160` | differs: did not build, or built to other bytes, in PAL |
| `func_003BE7B0` | frontbin | US draft of `func_003B92B8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BEE98` | frontbin | US draft of `func_003B99A0` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BEF00` | frontbin | US draft of `func_003B9A08` | differs: did not build, or built to other bytes, in PAL |
| `func_003BF058` | frontbin | US draft of `func_003B9B60` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BF0E0` | frontbin | US draft of `func_003B9BE8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BF148` | frontbin | US draft of `func_003B9C50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BF2A0` | frontbin | US draft of `func_003B9DA8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BF390` | frontbin | US draft of `func_003B9E98` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BF7A0` | frontbin | US draft of `func_003BA2A8` | near miss: 3 diff with the file's flags (was 37) |
| `func_003BFAC8` | frontbin | US draft of `func_003BA5B8` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003BFC58` | frontbin | US draft of `func_003BA748` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BFD60` | frontbin | US draft of `func_003BA850` | near miss: 48 diff with the file's flags (was 54) |
| `func_003BFE58` | frontbin | US draft of `func_003BA948` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BFEB0` | frontbin | US draft of `func_003BA9A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C03A8` | frontbin | US draft of `func_003BAE98` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C0AD0` | frontbin | US draft of `func_003BB5C0` | near miss: 20 diff with the file's flags (the US draft: 22) |
| `func_003C0C40` | frontbin | US draft of `func_003BB730` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C0F60` | frontbin | US draft of `func_003BBA50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C1600` | frontbin | US draft of `func_003BC0F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C24B0` | frontbin | US draft of `func_003BCFB0` | symbols: func_003BD0D8 |
| `func_003C2948` | frontbin | US draft of `func_003BD428` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C33C8` | frontbin | US draft of `func_003BDEA8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C38E0` | frontbin | US draft of `func_003BE3C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C3BE8` | frontbin | US draft of `func_003BE6A8` | near miss: 4 diff with the file's flags (was 19) |
| `func_003C3D30` | frontbin | US draft of `func_003BE7F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C3EC8` | frontbin | US draft of `func_003BE988` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_003C41A0` | frontbin | US draft of `func_003BEC60` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4360` | frontbin | US draft of `func_003BEE20` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C45A0` | frontbin | US draft of `func_003BF058` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C48A8` | frontbin | US draft of `func_003BF360` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4E80` | frontbin | US draft of `func_003BF910` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C5110` | frontbin | US draft of `func_003BFBA8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C5180` | frontbin | US draft of `func_003BFC18` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003C5370` | frontbin | US draft of `func_003BFE08` | differs: did not build, or built to other bytes, in PAL |
| `func_003C56E0` | frontbin | US draft of `func_003C0188` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003C6068` | frontbin | US draft of `func_003C0B10` | flags: the US matched it with `@ps2as` and without `-fopt-stack` `-mno-split-addresses` (a single-function override) |
| `func_003C62C8` | frontbin | US draft of `func_003C0D70` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003C6368` | frontbin | US draft of `func_003C0E10` | differs: did not build, or built to other bytes, in PAL |
| `func_003C6680` | frontbin | US draft of `func_003C1130` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003C6990` | frontbin | US draft of `func_003C1440` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003CCF60` | frontbin | US draft of `func_003C79F0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003CE098` | frontbin | US draft of `func_003C8B28` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003CE1B0` | frontbin | US draft of `func_003C8C40` | near miss: 12 diff with the file's flags (was 37) |
| `func_003CE250` | frontbin | US draft of `func_003C8CE0` | near miss: 23 diff with the file's flags (was 27) |
| `func_003CE2C0` | frontbin | US draft of `func_003C8D50` | near miss: 48 diff with the file's flags (was 68) |
| `func_003CE440` | frontbin | US draft of `func_003C8ED0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003CE5E8` | frontbin | US draft of `func_003C9078` | near miss: 40 diff with the file's flags (the US draft: 75) |
| `func_003CEDF8` | frontbin | US draft of `func_003C9888` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003CEF40` | frontbin | US draft of `func_003C99D0` | near miss: 22 diff with the file's flags (was 66) |
| `func_003CF0F0` | frontbin | US draft of `func_003C9B80` | near miss: 10 diff with the file's flags (was 50) |
| `func_003D0B20` | frontbin | US draft of `func_003CB5B0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D0EC8` | frontbin | US draft of `func_003CB958` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_003D13B0` | frontbin | US draft of `func_003CBE40` | symbols: func_003CC950 func_003CCB40 func_003CCFB0 func_003CD250 |
| `func_003D6BC0` | frontbin | US draft of `func_003D1650` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D6EE8` | frontbin | US draft of `func_003D1978` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003D7080` | frontbin | US draft of `func_003D1B10` | near miss: 131 diff with the file's flags (was 136) |
| `func_003D73D8` | frontbin | US draft of `func_003D1E68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D78E0` | frontbin | US draft of `func_003D2370` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003D7DE8` | frontbin | US draft of `func_003D2878` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D85C0` | frontbin | US draft of `func_003D3050` | near miss: 27 diff with the file's flags (was 31) |
| `func_003D86B8` | frontbin | US draft of `func_003D3148` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D8998` | frontbin | US draft of `func_003D3428` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D8CF0` | frontbin | US draft of `func_003D3780` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003D8FC0` | frontbin | US draft of `func_003D3A50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D91F0` | frontbin | US draft of `func_003D3C80` | near miss: 10 diff with the file's flags (was 15) |
| `func_003D9740` | frontbin | US draft of `func_003D41E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E1418` | frontbin | US draft of `func_003DBEC8` | near miss: 408 diff with the file's flags (was 743) |
| `func_003E38F8` | frontbin | US draft of `func_003DE3A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E3E40` | frontbin | US draft of `func_003DE8F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E4440` | frontbin | US draft of `func_003DEEF0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E4508` | frontbin | US draft of `func_003DEFB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E4588` | frontbin | US draft of `func_003DF038` | near miss: 433 diff with the file's flags (was 442) |
| `func_003E4D70` | frontbin | US draft of `func_003DF820` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003E5520` | frontbin | US draft of `func_003DFFD0` | near miss: 28 diff with the file's flags (was 36) |
| `func_003E5CE8` | frontbin | US draft of `func_003E0798` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003E63E0` | frontbin | US draft of `func_003E0E90` | near miss: 56 diff with the file's flags (was 71) |
| `func_003E6C08` | frontbin | US draft of `func_003E16B8` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003E7268` | frontbin | US draft of `func_003E1D18` | near miss: 9 diff with the file's flags (the US draft: 13) |
| `func_003E74A8` | frontbin | US draft of `func_003E1F40` | near miss: 2 diff with the file's flags (was 19) |
| `func_003E9470` | frontbin | US draft of `func_003E3F08` | near miss: 457 diff with the file's flags (was 522) |
| `func_003EB270` | frontbin | US draft of `func_003E5D08` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EBAA0` | frontbin | US draft of `func_003E6538` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EC4B8` | frontbin | US draft of `func_003E6F50` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ECBA0` | frontbin | US draft of `func_003E7638` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ED1F8` | frontbin | US draft of `func_003E7C90` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003ED988` | frontbin | US draft of `func_003E8420` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EDD40` | frontbin | US draft of `func_003E87D8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EDDA0` | frontbin | US draft of `func_003E8838` | flags: the US matched it with without `-mno-split-addresses` (a single-function override) |
| `func_003EDF58` | frontbin | US draft of `func_003E89F0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003EE038` | frontbin | US draft of `func_003E8AD0` | near miss: 38 diff with the file's flags (was 71) |
| `func_003EE1A8` | frontbin | US draft of `func_003E8C40` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EE760` | frontbin | US draft of `func_003E91F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EE800` | frontbin | US draft of `func_003E9298` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EEE20` | frontbin | US draft of `func_003E98B8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EF2A0` | frontbin | US draft of `func_003E9D38` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EF5E0` | frontbin | US draft of `func_003EA078` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EFBB0` | frontbin | US draft of `func_003EA648` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003EFFF8` | frontbin | US draft of `func_003EAA90` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003F0708` | frontbin | US draft of `func_003EB180` | near miss: 42 diff with the file's flags (the US draft: 103) |
| `func_003F08E0` | frontbin | US draft of `func_003EB358` | near miss: 5 diff with the file's flags (was 38) |
| `func_003F0CF0` | frontbin | US draft of `func_003EB728` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003F1998` | frontbin | US draft of `func_003EC3D0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003F1D60` | frontbin | US draft of `func_003EC798` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003F1F28` | frontbin | US draft of `func_003EC960` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_L01_004F0558` | levels | PR #5 draft (open-rac-engine names) | inline asm: matches only with `__asm__("sq $0,%0")` for the quadword zero store, which is not allowed in matched C |
| `func_L01_004F05F0` | levels | PR #5 draft (open-rac-engine names) | inline asm: matches only with `__asm__("sq $0,%0")` for the quadword zero store, which is not allowed in matched C |
| `func_L01_00350040` | levels | level 1 draft | code equals retail except the final `addiu $sp` (1 diff): the function's `jr` delay slot is a shared remnant the compiled function cannot give up; needs `@ps2as` and `aligned(16)` quadword structs copied through locals |
| `func_L01_00355D88` | levels | level 1 draft | 1 difference: a `b` target. Retail makes both arms of the first `p[0x5f]` branch jump to one shared `jal func_L01_00456C98`; this C reaches the last `jal` from the second arm. Swapping arms, explicit returns, dropping the else and merging the arms were all worse |
| `func_L01_003B1128` | levels | level 1 draft | 6 differences, all one `ori` (finishing `0x388EF7`) that retail schedules after `sw $a1,0x30($sp)` and this C schedules earlier; the scheduler tie-break did not converge in about 14 compiles |
| `func_L01_003E36E8` | levels | level 1 draft | 16 differences, one rotation of the callee-saved registers (retail: s0=j, s1=i, s2=o, s3=offset, s4=flag, s5=buf, s6=s; this C gives o=$s5, buf=$s4, flag=$s3). Scheduling, the VLA `subu $sp`, the `$fp` frame and the loop match; all 12 local orders, `__builtin_alloca`, a hoisted pointer and while loops were tried. Landing it also needs func_L01_003E34F0 re-prototyped as `(void *, f32, s32, s32)` |
| `func_L01_00423E20` | levels | level 1 draft | 42 differences from one extra instruction: the zero quadword is built as `por $v0,$zero,$zero` + `sq $v0` instead of retail's single `sq $zero,0x30($sp)`; `__builtin_memset`, a compound literal, a `mode(TI)` zero and `V4 = {0}` (hoisted into the prologue, 122 diff) were tried. The search loop, constants, the 0x20-byte `ldl/ldr` copy and the casts already match; needs `@ps2as` |
| `func_L01_003E1CD0` | levels | level 1 draft | 31 differences, all the jump-table address: retail builds it as `lui`/`sll`/`addiu`/`addu`/`lw` (separate `addiu` for the `%lo`), this C folds the `%lo` into the `lw` and emits the `lui` after the `sll`; no C form found that unfolds it (the `.extern` hint does not apply to the compiler-made table symbol). Control flow and callees match |
| `func_L01_003D9428` | levels | level 1 draft | 7 differences in the argument setup of `func_L01_00451FE0`: retail schedules `move $a0,$s0` late and puts `addiu $a1,$zero,0x7f` in the `jal` delay slot, gcc hoists both above the `mov.s` copies. About 25 variants (locals, narrower prototype types, early return, `.extern` hint) did not change it; needs `@ps2as` |
| `func_L01_00356818` | levels | level 1 draft | 1 instruction off (76 diff reported because it shifts everything after it): retail starts with a bare `sq $zero,0x0($sp)` for the zeroed stack quadword, plain C gives `por $v0,$zero,$zero` + `sq $v0`; `{0}`, per-field stores, `long long` pairs and a `mode(TI)` zero were tried |
| `func_L01_003569A0` | levels | level 1 draft | 42 differences: retail zeroes a quadword twice with a bare `sq $zero` (`sp+0` and `0xC0($s1)`), plain C gives `por`+`sq`, same blocker as `func_L01_00423E20`. The file records the structure and `$gp` slots, not a compiling C |
| `func_L01_00356748` | levels | level 1 draft | 41 differences: same list-search loop as the matched `func_L01_003B0D48`, but retail hoists the invariant `x <= D_001E0058` and `x & 0xFF` tests into the preheader (an always-zero `$a3`, a copy in `$a2`) and rotates the loop with `r` heading it; every `while`, `for`, entry-guard + `do while` and pointer-to-entry form left gcc emitting a bottom test with the table address and limit recomputed inside |
| `func_L01_00356050` | levels | level 1 draft | 4 differences, one register swap: retail `addiu $v0,0x1a; addiu $v1,6; sb $v0,0x25e; sb $v1,0x25f`, this C gives `$v1=0x1a`, `$v0=6`; about 28 variants of store order, `u8`/`s32` locals and struct fields did not change it; needs `@ps2as` on `L01_00353EA0.c` |
| `func_L01_0049CD08` | levels | level 1 draft | 28 differences: same table walk as the matched `func_L01_0049DE10` (five jump-table entries, 8 callee-saved registers), but retail increments `i` in place in case 1 so `i` stays live across the list loop (flag value in `$s3`, `k` in `$s4`); this C computes `n = i + 1` into `$s3`. Delete the `jtbl_002BCCA0` INCLUDE_RODATA line when integrating |
| `func_L01_0049BBD8` | levels | level 1 draft | 106 differences of 170, one cause: retail keeps `n = i + 1` in `$s3` separate from `i` (`$s2`) and ends each case with `move $s2,$s3`, case 1 reusing `$s2` for the flag value; gcc coalesces `n` into `i`, so everything after case 0 shifts. Cases 0, 2, 3 and the prologue/jump table line up. Same family as `func_L01_0049CD08` |
| `func_U_003B0C70` | frontbin | NTSC-U native draft at `0x003B0C70` | 2 differences: initial `lui` and stack adjustment reversed; rechecked 2026-10-31, three C forms unchanged, literal read gives 6 differences |
| `func_001206A0` | boot_elf | PAL near miss (PR #10) | 22 diff with the file's flags: `$a1`/`$a2` swapped for the argument copy and the exponent |
| `func_L17_003B38B0` | levels | PAL near miss (PR #10) | 4 diff in level 17: order of `abs.s` against the second `sub.s`, `bc1tl` against `bc1fl` |
| `func_L06_0032E168` | levels | PAL near miss (PR #10) | 13 diff in level 6: the loop bound is loaded into `$a1` instead of `$v0` and not copied into the delay slots |
| `func_L31_003A5958` | levels | PAL near miss (PR #10) | 56 diff in level 31: order of the stores and the data pointer's register |
| `func_L17_003BE210` | levels | PAL near miss (PR #10) | 51 diff in level 17: layout of the state switch and the two forms of the D_001D545C read |
| `func_L02_003523D0` | levels | level 2 draft | register allocation only: retail loads `lw $v0,0xb8($a0)` and keeps the `lui`/`addiu` of the quadword source in `$a2`; this C uses `$v1` for `o->p` and `lui $v0; addiu $a2,$v0`. About 12 variants (do-while, while, a source-pointer local, statement order, with and without the `.extern` hint) did not move it |
| `func_L02_00351208` | levels | level 2 draft | 2 differences: in the second `if (new30 < f20)` block retail has `addiu $v0,$zero,0xff` before `move $a1,$s2`, this C the other way round; about 8 variants (store/call order, `q` versus `p + 0x160`, a `u8` temp, compare forms) did not change it. Needs `@ps2as` (already set for its file) |
| `func_L02_003F2870` | levels | level 2 draft | about 27 differences: gcc compiles the leading `if (call != 0) return 1;` as `beqz` plus a `b` to a duplicated epilogue where retail uses `bnez` with `li $v0,1` in the delay slot and one shared epilogue; the table `lui` and the 0x14 `lui` land in different registers; the loop exit falls straight into the epilogue in retail |
| `func_L02_0034F958` | levels | level 2 draft | 34 differing lines in two parts: (a) the float constants sit in `$f1..$f7` in a different order and the byte stores at 0x1d7/0x171/0x172 do not interleave as in retail (moving them re-merges the constant 1 and gets worse); (b) the tail keeps `id` in `$a1` and loads `D_001D545C` into `$a0` in retail. Needs `@ps2as` for L02_0034C9F0.c |
| `func_L02_004BE7A8` | levels | level 2 draft | 22 differences, all the prologue/epilogue: retail saves callee-saved registers with 16-byte `sq` slots in a 0xD0 frame, this compiler gives 8-byte `sd` slots in a 0x80 frame (the `sq_ra` class). Body and register allocation match; `pv = &v` kept through every use is what gives retail's `move $s2,$sp`. Levels have no `sq_ra_funcs` table, so it cannot be reached with the file's flags. Needs `@ps2as` |
| `func_L02_0034BF90` | levels | level 2 draft | 139 differences, inflated by one cause: retail loads `309.0f` into `$f2` before the first compare, copies x with `mov.s $f3,$f0` and reloads 309.0f at the join (4 more instructions, shifting every later branch); this C keeps one constant register. The argument order of `func_L01_00451FE0` (the `mov.s $f14/$f15/$f17` interleaved with `$a3/$t0..$t3`) and of the `func_L01_00456C98` calls also differ. Needs `@ps2as` (set for L02_003484D8.c) |
| `func_L02_0039CE20` | levels | level 2 draft | VU0: retail's case 2 adds a returned vector into `self+0x10` with `lqc2`/`vadd.xyz`/`sqc2`, which plain C cannot reach (this draft uses three `+=`, so everything after shifts). Everything else matches: dispatch, jump table (`jtbl_002BCBE0`), the other cases |
| `func_L02_0039D200` | levels | level 2 draft | 5 differences in the first five instructions of the switch dispatch: retail `lbu $v0; addiu $a0,$v0,-1; sltiu $v1,$a0,6; beqz $v1; sll $v1,$a0,2`, this C `lbu $v1; addiu $v1,$v1,-1; sltiu $v0,$v1,6; ...`. A local copy, `switch (f20 - 1)`, casts, a `default:` label and local reordering all gave the same bytes. The rest matches, including the jump table (`jtbl_002BCC00`). Uses one `goto` into the shared tail |
| `func_L02_00473410` | levels | level 2 draft | 13 differences, one cause: retail increments `i` in place (`addiu $s2,$s2,1`) and hoists `&D[i].c` / `&D[i].flag` as loop invariants in `$s0`/`$s1`; this C reproduces the hoisting and the instruction sequence (cases 0-2 as two separate bodies, flag = `bit test || call`) but gcc emits `addiu $s4,$s2,1` followed by `move $s2,$s4`, which shifts `j` to `$s3` and the flag temporary to `$s2` (retail: `j`=`$s4`, temporary=`$s3`). Same family as func_L01_0049BBD8; the `for` and `n = i + 1` shapes gave 28 differences, a `while` with `i++` ending every case gave 13. Delete the INCLUDE_RODATA line (jtbl_002BA8B0, five entries) when landing |
| `func_L02_003A2320` | levels | level 2 draft | 4 differences with `@ps2as` (set for its file): the `addiu 7` and `addiu 100` are swapped (`$v0`/`$a0`) and the `sh 0x2e` and `sw 0x20` stores are swapped; all 120 orderings of the five stores after the call, and 2520 orderings including the two stores through arg0, give the same two differences |
| `func_L02_00313B38` | levels | level 2 draft | about 208 differences, most of them one instruction shift: retail fills the `beqz` delay slot after `func_00382380(..., p->f1C, 0)` with `lhu $v0, lo(D_001A7C10)($s2)`, this C with `lui $v0`; in about seven bit-test blocks retail keeps the shift index in `$a1` and the word in `$v1` (this C `$v0`/`$a0`); near the end retail hoists `addiu $s1,$s5,lo(D_001A4BE0)` into a `bnez` delay slot. Structure, calls, frame (0x60) and constants (501.0f is 0x43FA8000) match. Needs `@ps2as` for L02_00313B38.c |
| `func_L01_003506B8` | levels | rac4-decomp's `func_0046B4C0`, ported | 6 instruction(s) differ |
| `func_L01_003CFAE8` | levels | rac4-decomp's `func_L01_003D78E0`, ported | 7 instruction(s) differ |
| `func_L01_00432F68` | levels | rac2-decomp's `func_L00_002D6710`, ported | 1 instruction(s) differ |
| `func_L01_00436020` | levels | rac2-decomp's `func_0029B658`, ported | 6 instruction(s) differ |
| `func_L01_00446BC8` | levels | rac2-decomp's `func_002A90C8`, ported | 8 instruction(s) differ |
| `func_L01_00448FF0` | levels | rac4-decomp's `func_00476660`, ported | 1 instruction(s) differ |
| `func_L01_00451DF8` | levels | rac2-decomp's `func_002B0990`, ported | 4 instruction(s) differ |
| `func_L01_004943D0` | levels | rac4-decomp's `func_L00_0062A688`, ported | 4 instruction(s) differ |
| `func_L01_00494540` | levels | rac4-decomp's `func_L00_0062A688`, ported | 4 instruction(s) differ |
| `func_L01_004B9798` | levels | rac4-decomp's `func_004E55C0`, ported | 1 instruction(s) differ |
| `func_L04_0035A030` | levels | rac4-decomp's `func_L01_003EBCC0`, ported | 7 instruction(s) differ |
| `func_L07_003B28B8` | levels | rac4-decomp's `func_L01_0045B5D8`, ported | 2 instruction(s) differ |
| `func_L07_004522E8` | levels | rac2-decomp's `func_L06_003660F0`, ported | 8 instruction(s) differ |
| `func_L12_003DEA50` | levels | rac4-decomp's `func_L01_003D78E0`, ported | 5 instruction(s) differ |
| `func_L12_003E48C8` | levels | rac4-decomp's `func_L01_003D78E0`, ported | 5 instruction(s) differ |
| `func_L16_004DCA98` | levels | rac2-decomp's `func_L04_003C70C8`, ported | 5 instruction(s) differ |
| `func_L21_003AA0A0` | levels | rac4-decomp's `func_L01_003CC6B0`, ported | 6 instruction(s) differ |
| `func_L21_003AFED0` | levels | rac4-decomp's `func_L01_003CC6B0`, ported | 6 instruction(s) differ |
| `func_L22_004200C8` | levels | rac2-decomp's `func_L01_003246D0`, ported | 1 instruction(s) differ |
| `func_L28_00420020` | levels | rac2-decomp's `func_L00_003294F0`, ported | 1 instruction(s) differ |
| `func_L28_00490040` | levels | rac2-decomp's `func_L00_0037DE30`, ported | 2 instruction(s) differ |
| `func_L31_00460008` | levels | rac2-decomp's `func_L07_003791E8`, ported | 1 instruction(s) differ |
| `func_L39_004BCE38` | levels | rac2-decomp's `func_00131CA8`, ported | 7 instruction(s) differ |
| `func_L39_004C3CC0` | levels | rac4-decomp's `func_L00_004FFAC0`, ported | 6 instruction(s) differ |
| `func_L39_004C4168` | levels | rac4-decomp's `func_L00_004FFF68`, ported | 1 instruction(s) differ |
| `func_L39_004CC178` | levels | rac4-decomp's `func_L00_00507F78`, ported | 1 instruction(s) differ |
| `func_L39_004CC510` | levels | rac2-decomp's `func_0011FA20`, ported | 7 instruction(s) differ |
| `func_L39_004D14C8` | levels | rac4-decomp's `func_003F1020`, ported | 5 instruction(s) differ |
| `func_L39_004D1C00` | levels | rac4-decomp's `func_003F1020`, ported | 5 instruction(s) differ |
| `func_L39_004D7740` | levels | rac4-decomp's `func_L00_00513540`, ported | 2 instruction(s) differ |
| `func_L39_004DD340` | levels | rac4-decomp's `func_L00_00519140`, ported | 1 instruction(s) differ |
| `func_L39_004DD668` | levels | rac4-decomp's `func_L00_00519468`, ported | 1 instruction(s) differ |
| `func_L39_004DE0C8` | levels | rac4-decomp's `func_L00_00519EC8`, ported | 3 instruction(s) differ |
| `func_L39_004DE0F0` | levels | rac4-decomp's `func_L00_00519EF0`, ported | 1 instruction(s) differ |
| `func_L39_004DE120` | levels | rac4-decomp's `func_L00_00519F20`, ported | 1 instruction(s) differ |
| `func_L39_004DE938` | levels | rac4-decomp's `func_L00_0051A738`, ported | 1 instruction(s) differ |
| `func_L39_004DF408` | levels | rac4-decomp's `func_L00_0051B208`, ported | 7 instruction(s) differ |
| `func_L39_004E0E98` | levels | rac4-decomp's `func_L00_0051CC98`, ported | 1 instruction(s) differ |
| `func_L39_004E2E00` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2E50` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2EA0` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2EF0` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2F40` | levels | rac4-decomp's `func_L00_0051ED40`, ported | 1 instruction(s) differ |
| `func_L39_004E2F70` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E3028` | levels | rac4-decomp's `func_L00_0051EE28`, ported | 1 instruction(s) differ |
| `func_L39_004E5108` | levels | rac4-decomp's `func_L00_00520F08`, ported | 8 instruction(s) differ |
| `func_L39_004E5168` | levels | rac2-decomp's `func_0011FA18`, ported | 6 instruction(s) differ |
| `func_L39_004F20E0` | levels | rac4-decomp's `func_L00_0052DEE0`, ported | 1 instruction(s) differ |
| `func_L39_004F4EE8` | levels | rac2-decomp's `func_L00_004338A8`, ported | 1 instruction(s) differ |
| `func_L39_004F5E70` | levels | rac4-decomp's `func_003FE6C0`, ported | 8 instruction(s) differ |
| `func_L39_004F5F80` | levels | rac4-decomp's `func_003FE7D0`, ported | 5 instruction(s) differ |
| `func_L39_004F5FA0` | levels | rac4-decomp's `func_003FE7F0`, ported | 4 instruction(s) differ |
| `func_L39_004F74E8` | levels | rac4-decomp's `func_00403308`, ported | 7 instruction(s) differ |
| `func_L39_004F7510` | levels | rac4-decomp's `func_00403308`, ported | 7 instruction(s) differ |
| `func_L39_004F7538` | levels | rac4-decomp's `func_00403308`, ported | 7 instruction(s) differ |
| `func_L39_004F7590` | levels | rac4-decomp's `func_004033B0`, ported | 5 instruction(s) differ |
| `func_L39_004F7620` | levels | rac4-decomp's `func_00403440`, ported | 7 instruction(s) differ |
| `func_L39_004F7648` | levels | rac4-decomp's `func_003F1020`, ported | 5 instruction(s) differ |
| `func_L39_004F7660` | levels | rac4-decomp's `func_003F1020`, ported | 5 instruction(s) differ |
| `func_L39_004FCD30` | levels | rac4-decomp's `func_L00_0051EE28`, ported | 1 instruction(s) differ |
| `func_L39_004FCF88` | levels | rac4-decomp's `func_L00_00538D98`, ported | 6 instruction(s) differ |
| `func_L39_00504460` | levels | rac4-decomp's `func_L00_00540270`, ported | 5 instruction(s) differ |
| `func_L39_00504488` | levels | rac4-decomp's `func_L00_00540298`, ported | 5 instruction(s) differ |
| `func_L39_005044B0` | levels | rac4-decomp's `func_L00_005402C0`, ported | 5 instruction(s) differ |
| `func_L39_005044D8` | levels | rac4-decomp's `func_L00_005402E8`, ported | 5 instruction(s) differ |
| `func_L39_00504500` | levels | rac4-decomp's `func_L00_00540310`, ported | 5 instruction(s) differ |
| `func_L39_00504A30` | levels | rac4-decomp's `func_L00_0051EE28`, ported | 1 instruction(s) differ |
| `func_L39_0050C550` | levels | rac4-decomp's `func_003F8670`, ported | 6 instruction(s) differ |
| `func_L39_00515E00` | levels | rac4-decomp's `func_L00_00554600`, ported | 6 instruction(s) differ |
| `func_L39_005161F8` | levels | rac2-decomp's `func_0011FA20`, ported | 8 instruction(s) differ |
| `func_L39_00517068` | levels | rac4-decomp's `func_L00_005285D8`, ported | 3 instruction(s) differ |
| `func_L39_00519408` | levels | rac4-decomp's `func_L00_00566D00`, ported | 5 instruction(s) differ |
| `func_L39_0053EA08` | levels | rac2-decomp's `func_L16_003E70E0`, ported | 4 instruction(s) differ |
| `func_L39_00554D98` | levels | rac4-decomp's `func_00436970`, ported | 5 instruction(s) differ |
| `func_L39_00554DD8` | levels | rac4-decomp's `func_004369B0`, ported | 5 instruction(s) differ |
| `func_L39_00554E18` | levels | rac4-decomp's `func_004369F0`, ported | 5 instruction(s) differ |
| `func_L39_00557D20` | levels | rac2-decomp's `func_L00_00403CB8`, ported | 3 instruction(s) differ |
| `func_L39_00597E48` | levels | rac2-decomp's `func_00284E80`, ported | 8 instruction(s) differ |
| `func_L39_0059A638` | levels | rac4-decomp's `func_L01_0064FAC8`, ported | 8 instruction(s) differ |
| `func_L39_0059D940` | levels | rac4-decomp's `func_0045F460`, ported | 6 instruction(s) differ |
| `func_L39_0059FEF0` | levels | rac2-decomp's `func_002932B8`, ported | 1 instruction(s) differ |
| `func_L39_005ABE58` | levels | rac2-decomp's `func_002A0180`, ported | 7 instruction(s) differ |
| `func_L39_005C1310` | levels | rac2-decomp's `func_002B6788`, ported | 2 instruction(s) differ |
| `func_L39_005C1368` | levels | rac2-decomp's `func_002B6828`, ported | 5 instruction(s) differ |
| `func_L39_005C1968` | levels | rac2-decomp's `func_002B6D80`, ported | 2 instruction(s) differ |
| `func_L39_005C1AC0` | levels | rac2-decomp's `func_002B6E78`, ported | 2 instruction(s) differ |
| `func_L39_005FB7D0` | levels | rac2-decomp's `func_002F5E20`, ported | 1 instruction(s) differ |
| `func_L39_005FBDA0` | levels | rac4-decomp's `func_004E5550`, ported | 6 instruction(s) differ |
| `func_L39_00608220` | levels | rac2-decomp's `func_0034F918`, ported | 5 instruction(s) differ |
| `func_L39_006384B0` | levels | rac2-decomp's `func_003480D8`, ported | 2 instruction(s) differ |
| `func_L39_006625A8` | levels | rac4-decomp's `func_0053C920`, ported | 2 instruction(s) differ |
| `func_L39_00662B68` | levels | rac4-decomp's `func_0053CB70`, ported | 3 instruction(s) differ |
| `func_L39_006775B8` | levels | rac4-decomp's `func_004F4E58`, ported | 4 instruction(s) differ |
| `func_L39_0067EC00` | levels | rac4-decomp's `func_L00_00708228`, ported | 1 instruction(s) differ |
| `func_L39_0067F030` | levels | rac4-decomp's `func_L01_00446AC0`, ported | 1 instruction(s) differ |
| `func_L39_00680390` | levels | rac4-decomp's `func_L00_0053BEF0`, ported | 3 instruction(s) differ |
| `func_L39_00680C78` | levels | rac4-decomp's `func_L00_0053BEF0`, ported | 3 instruction(s) differ |
| `func_L39_00682720` | levels | rac4-decomp's `func_L00_007131A8`, ported | 2 instruction(s) differ |
| `func_L39_00682CE8` | levels | rac4-decomp's `func_L00_0053BEF0`, ported | 3 instruction(s) differ |
| `func_L39_00683718` | levels | rac4-decomp's `func_L00_004F7328`, ported | 4 instruction(s) differ |
| `func_L39_00684218` | levels | rac4-decomp's `func_L00_0053BEF0`, ported | 3 instruction(s) differ |
| `func_L39_00685A80` | levels | rac4-decomp's `func_L00_00717A08`, ported | 1 instruction(s) differ |
| `func_L39_00685AB0` | levels | rac4-decomp's `func_L00_00717A38`, ported | 1 instruction(s) differ |
| `func_L39_0068B178` | levels | rac4-decomp's `func_L00_0071B768`, ported | 5 instruction(s) differ |
| `func_L39_0068B3C0` | levels | rac4-decomp's `func_L00_0071B9B0`, ported | 2 instruction(s) differ |
| `func_L39_00699668` | levels | rac4-decomp's `func_L00_0071AB38`, ported | 3 instruction(s) differ |
| `func_L39_0069F5E8` | levels | rac4-decomp's `func_L00_00763480`, ported | 1 instruction(s) differ |
| `func_L39_0069F618` | levels | rac4-decomp's `func_L00_007634B0`, ported | 1 instruction(s) differ |
| `func_L39_006A6FA0` | levels | rac4-decomp's `func_004EE7B0`, ported | 8 instruction(s) differ |
| `func_L39_006AB6D0` | levels | rac4-decomp's `func_L00_0071AB38`, ported | 3 instruction(s) differ |
| `func_L39_006AB8A8` | levels | rac4-decomp's `func_L00_007418C0`, ported | 6 instruction(s) differ |
| `func_L39_006B6A80` | levels | rac4-decomp's `func_L00_0071AB38`, ported | 3 instruction(s) differ |
| `func_L39_006B6AA8` | levels | rac4-decomp's `func_L00_0071AB38`, ported | 3 instruction(s) differ |
| `func_L39_006CAA70` | levels | rac4-decomp's `func_L00_0071AB38`, ported | 3 instruction(s) differ |
| `func_L39_006CAA98` | levels | rac4-decomp's `func_L00_00749408`, ported | 2 instruction(s) differ |
| `func_L39_006CDD90` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CDF18` | levels | rac4-decomp's `func_L00_00766DB0`, ported | 7 instruction(s) differ |
| `func_L39_006CF080` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CF218` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CF3C8` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CF588` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CF750` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CF900` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CFAD0` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CFCB0` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CFE68` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006CFE88` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D0058` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D0208` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D0398` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D0550` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D4018` | levels | rac4-decomp's `func_L00_0076F1E0`, ported | 5 instruction(s) differ |
| `func_L39_006D5440` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D55C0` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D6378` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006D6500` | levels | rac4-decomp's `func_L00_00766DB0`, ported | 7 instruction(s) differ |
| `func_L39_006DB5B0` | levels | rac4-decomp's `func_L00_00778848`, ported | 7 instruction(s) differ |
| `func_L39_006DB730` | levels | rac4-decomp's `func_L00_007789D0`, ported | 7 instruction(s) differ |
| `func_L39_006DDDE8` | levels | rac4-decomp's `func_L00_0077C368`, ported | 6 instruction(s) differ |
| `func_L39_006DE010` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006DE2D0` | levels | rac4-decomp's `func_L00_0077C700`, ported | 7 instruction(s) differ |
| `func_L39_006DEA58` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L39_006DEAA0` | levels | rac4-decomp's `func_L00_00766C00`, ported | 7 instruction(s) differ |
| `func_L40_00422C30` | levels | rac4-decomp's `func_L41_00411AD8`, ported | 3 instruction(s) differ |
| `func_L03_0032E7A0` | levels | level 3 (Starship Phoenix) draft | 16 differences: logic is right but retail keeps the object pointer in $a0 and loads the field before the lui of the second global, with an unfilled nop in the second bnez delay slot; the C keeps it in $v1 and hoists the lui/lw into the slot; about 10 wordings tried (reassigning a0, nested if vs &&, flat u8 pointer, unsized array, hints 8/16/32, @ps2as) |
| `func_L03_003AF7F0` | levels | level 3 (Starship Phoenix) draft | 6 differences: everything matches except the order of the float argument loads; retail loads $f13 and $f14 (lui $at form) first and puts the $gp load of $f12 in the jal delay slot, the C loads the $gp one first; tried locals, pointer alias, callee return types, @ps2as |
| `func_L03_003B27D0` | levels | level 3 (Starship Phoenix) draft | 6 differences: int side, lq/sq and lui forms match; only the order of the float argument loads differs (retail: $f13, $f14 via lui $at, then $f12 from $gp in the jal delay slot); locals, statement order, return type and unsized/16-byte arrays tried |
| `func_L03_003B2B30` | levels | level 3 (Starship Phoenix) draft | 6 differences: same shape and failure as func_L03_003B27D0 (callee func_L01_00450DE8); int side, lq/sq and lui forms match, only the float argument scheduling differs (retail loads $f13/$f14 first and the $gp $f12 in the jal delay slot); about 20 variants tried |
| `func_L03_0032FE10` | levels | level 3 (Starship Phoenix) draft | 9 differences: retail has a single `sq $zero, 0xF0($s0)` (the quadword zero store, known out of reach from plain C, see level 1 notes), gcc emits `por` + `sq` and shifts the rest by one; everything else matches (store order 2E,0E,30,2F) |
| `func_L03_003B0238` | levels | level 3 (Starship Phoenix) draft | 4 differences: retail keeps a loop copy `move $a3,$a1` that the C drops (srav reads $a1) and puts cnt-n in $v1 where the C uses $v0; do-while/for loops, separate locals, helper-style expressions all give 4 or more |
| `func_L03_003A2B48` | levels | level 3 (Starship Phoenix) draft | 5 differences: do-while over 0x50-byte entries with three null-checked stores of 0x7F; only the third pointer check differs (retail: bnel with the sb in the delay slot, then addiu; slt; gcc hoists the loop increment into the branch); inline increment, while(1)+break, continue, loading the pointers up front all tried |
| `func_L03_003A1C60` | levels | level 3 (Starship Phoenix) draft | 29 differences, all from one instruction: retail has a bare `sq $zero` for the quadword zero store, gcc emits `por` + `sq` (known out of reach from plain C) and that shifts the rest; needs @ps2as for the inline float constants (L03_0039E470.c has none) |
| `func_L03_003220D8` | levels | level 3 (Starship Phoenix) draft | 5 differences: retail has `beqz $v0` with `lui $a0` in the delay slot, then `b`, then `lw $a1, 0x60`, the C has `beql` with the `lw` in the delay slot; and the `lh` destination is $v1 in retail, $v0 in the C; about 8 rewrites tried |
| `func_L03_0032CE38` | levels | level 3 (Starship Phoenix) draft | flags: matches only with @ps2as (inline float constants), but L03_0032C3A8.c cannot take it: func_L03_0032C8F8, already matched in that file, then differs at word +0x8; the C itself matched with --as ps2as |
| `func_L03_00397BF0` | levels | level 3 (Starship Phoenix) draft | 2 differences: retail loads the u16 at D_00143954 into $v1 (lhu $v1), the C into $v0, and the following bnez uses that register; everything else matches (single return tail via goto, .extern hint 16); unsigned int, unsized array, local copy and > 0 give the same 2 diffs |
| `func_L03_00395CA8` | levels | level 3 (Starship Phoenix) draft | 24 differences, one cause: needs @ps2as for the inline float constants (L03_00395808.c has none) and even then retail has two nops between cvt.s.w and div.s that the assembler does not emit; looks like an assembler-version effect, not reachable from C |
| `func_L03_00397B38` | levels | level 3 (Starship Phoenix) draft | 43 differences: logic is right (bit-mask loop over six table entries) but retail reads *q twice without CSE, puts lbu in the i==0 beql delay slot and does the sllv after the join, with registers i=$6, q=$7, s=$5; the C reuses one load and hoists the sllv; continue/&&/while/do-while variants give the same bytes (about 7 compiles) |
| `func_L03_004070C8` | levels | level 3 (Starship Phoenix) draft | 16 differences: instruction sequence and count match, only register allocation differs (retail keeps the table pointer in $v1 with the lui for 0x14 and 0x2D in $v1 and the table base in $a0, and fills the first beqz delay slot with move $v0,$zero); for/while/do-while and pointer init order tried |
| `func_L03_0032CED0` | levels | level 3 (Starship Phoenix) draft | 17 differences, scheduling and register allocation: retail loads D_L03_001DFA80 (lui/lw into $v1) in the prologue before lw $s0,0x68($s1) and keeps the table pointer in $v1, the C loads it after the object field and builds the address in $a0/$a1; inline expression, local base, struct-array indexing, entry pointer and assignment inside the argument all give the same bytes |
| `func_L03_0032E640` | levels | level 3 (Starship Phoenix) draft | 2 differences: two adjacent instructions before the inner loop are swapped (retail: addiu $t0,$zero,-1 then move $v1,$a0); about 25 variants tried (declaration places of q, i/id order, short id, ++q, array form) |
| `func_L03_003302D0` | levels | level 3 (Starship Phoenix) draft | 2 differences: retail has `move $s2,$zero` before `sd $s0,0($sp)` in the prologue, the C emits them in the other order; about 15 variants of the declaration and init order of the result, u8 vs s32 and callee return types tried |
| `func_L03_0032F948` | levels | level 3 (Starship Phoenix) draft | 31 differences: incomplete attempt; the control flow and the float scaling constants are in place, the instruction sequence is not yet verified against retail (uses mult $ac2 forms), so it needs another pass |
| `func_L03_003B0088` | levels | level 3 (Starship Phoenix) draft | 40 differences: control flow and instruction count match, register allocation and scheduling differ (mask in $t2 not $t1, the s+0x160 pointer in $t1 not $t0, call argument built in $a3 and moved to $a0, sll/addiu order before the mult); about 8 variants tried |
| `func_L03_0046FF38` | levels | level 3 (Starship Phoenix) draft | 1 difference: the trailing delay-slot instruction (addiu $sp,$sp,0x20) after jr $ra is cut by the catalogue size (0xC8), so the C is one instruction longer; everything else is byte-identical (the loop over the $gp slot array); same class as func_L01_00350040 |
| `func_L03_0039EE10` | levels | level 3 (Starship Phoenix) draft | 2 differences: in the delay slot of the jal to func_L01_00448890 retail has `move $a2,$zero; jal; mov.s $f12,$f0`, the C emits `mov.s $f12,$f0; jal; move $a2,$zero`; needs @ps2as (now set on L03_0039E470.c); zero-argument type, prototype order, indexing and inlined calls tried |
| `func_L03_003A1A78` | levels | level 3 (Starship Phoenix) draft | 2 differences: retail builds the last global read as `lui $v1,%hi(D_L03_00235A00); lw $v0,%lo($v1)`, the C puts the lui in $v0; hints 4/16, u32/u8 types, unsized array and callee return types give the same 2 (or worse) |
| `func_L03_003A04D0` | levels | level 3 (Starship Phoenix) draft | 16 differences from one cause: retail has two nops before the div.s that the build does not emit (frontbin gets them from config/frontbin/divs_nops.txt, levels have no such table); every instruction otherwise matches in order, and the twin func_L03_0039F2C8 matched with the same body |
| `func_L03_003B0140` | levels | level 3 (Starship Phoenix) draft | 12 differences, all register choices in the two blocks that call func_L03_003B2DA8 and func_L03_003B1198: the C puts `sll j,2` in $v0 where retail uses $v1 (the register that held the mask), shifting the addu/lw/sll/addu/addiu registers by one; temp, pointer, typed arr[1], split and inverted-condition variants tried (sibling func_L03_003AFFB8 has the same prologue and matched) |
| `func_L03_003A16D8` | levels | level 3 (Starship Phoenix) draft | 15 differences from one cause: retail has two nops before the div.s, the build emits one (same div.s nop padding class as func_L03_003A04D0); the twin func_L03_0039F2C8 matched with the same shape |
| `func_L03_0032EE30` | levels | level 3 (Starship Phoenix) draft | 58 differences, register allocation only: retail keeps the raw argument in $s2 and the object field a->0x68 in $s3 and recomputes s+0xA8 and b<<2 after the calls, the C hoists b*4 into a saved register (about 12 variants: char*/base+offset/array/struct idx[1]/goto loop/header-condition loop); same loop family as func_L03_0032EF78 and func_L03_0032EB30 |
| `func_L03_0032DF60` | levels | level 3 (Starship Phoenix) draft | 11 differences: the shape and every other register match (the for loop over three entries with the func_L03_0032EB30 style walk); retail reads the loop-entry copy of the D_001DF9D8 limit with lui/lw and the back-edge copy through $gp (0x3128), the C uses $gp in both, shifting four instructions around the entry test; splitting the entry guard gives 71-92 diffs |
| `func_L03_0039D038` | levels | level 3 (Starship Phoenix) draft | 46 differences: the structure and the beginning match; retail has two nops before the div.s (levels have no divs_nops table) so everything after it is scheduled differently, with f7/f5 register choice and swc1 order; about 30 store-order permutations tried |
| `func_L03_0039E748` | levels | level 3 (Starship Phoenix) draft | 67 differences: the stores, constants and callees match retail but the scheduling differs; retail also loads four float constants (0x3A9D4952, 0x3D75C290, 0x3AA4B5BF, 0x3D80ADFD) into $f12-$f15 for the func_L01_0045BD78 call that shift the register allocation; dead locals and stores under a false condition were folded away |
| `func_L03_0039F960` | levels | level 3 (Starship Phoenix) draft | 38 differences: structure, prologue, constants and call sequence match; the order of the ~35 independent stores in the middle block differs (retail 80,82,E9,AC,86,8C...; the C delays the 0x82/0xE9/0x86 byte stores), which also swaps a1/a2 and v0/v1; about 12 source permutations tried |
| `func_L03_003A0BF8` | levels | level 3 (Starship Phoenix) draft | 39 differences, scheduling and register allocation: the C emits the sb 0x82/0xE9 stores after the swc1 stores where retail has them before swc1 0xAC, 0.3 and 0.15 are in swapped float registers and the integer constant registers differ; store reorders (move, swap, reversed, bytes-floats-words) and a typed struct gave 39-72 |
| `func_L03_00330140` | levels | level 3 (Starship Phoenix) draft | 3 differences: retail emits `sw $zero,0x10($sp)` after `sd $s1` and `lw $s1,0x68($s0)`, the C emits it first; moving the counter init, an initialiser, a comma expression and the id init did not change it; the loop only matched as a pointer walk (`p = &v[1]`, `for (i = 1; i >= 0; i--, p++)`) |
| `func_L03_0032FE70` | levels | level 3 (Starship Phoenix) draft | 7 differences, two scheduling groups: in the 0x40 branch retail emits a2=0, a0=4, a1=0 and then the sw of 2 into D_L03_001DF514, the C emits a0, the store, a1, a2; and for the last two calls retail has `move a0,s0` before the jal and `move a1,v0` in the delay slot, the C the reverse; reordering, typed arguments, K&R and a temp for the hash result tried |
| `func_L03_00396E00` | levels | level 3 (Starship Phoenix) draft | 101 differences, cascading from two things: the prologue (retail loads the lbu after the four sd and the move, with the object field load in the bnez delay slot and a shared jump target that leaves $4 untouched; the C hoists the lbu) and the tail (a shared jal func_L01_004450F0 whose $a1 is set in the delay slot of a b, plus a separate (a,1,-1) call); four control-flow shapes tried; float stores, lq/sq, constants and offsets look right |
| `func_L03_0048B918` | levels | level 3 (Starship Phoenix) draft | 91 differences, register allocation and ordering: the 5-entry jump table compiles as retail's (case 4 next to default) and the dispatch prologue matches; the bit test needs a separate mask statement for sllv+and; retail keeps the base in $a1/$t5, sets the flag value in delay slots and loads the list pointer and flag inside the loop, the C if-converts to movz/movn when a local is used |
| `func_L03_0032D348` | levels | level 3 (Starship Phoenix) draft | flags: matches only with @ps2as (the float constants 1.0e7 and -1.0 are built inline with lui/mtc1; the default assembler gives 115 diff), and L03_0032C3A8.c cannot take @ps2as because the already matched func_L03_0032C8F8 then differs; the C itself matched with --as ps2as |
| `func_L03_0032E900` | levels | level 3 (Starship Phoenix) draft | 95 differences, register allocation and loop entry: the frame (0xB0), locals and instructions line up with retail; retail keeps a=$s6, s=$s5, cnt=$s4, n=$s3, i=$s2, list pointer=$s7 and s+0x60=$fp, gcc hoists the D_001A4C60 lui into $fp and the loop gets a redundant entry b + blez; hoisted slots pointer, list pointer and declaration reorders give 102-140 |
| `func_L03_0032CBD8` | levels | level 3 (Starship Phoenix) draft | 29 differences, all in the last stretch: retail fills the delay slot of the beqz after func_L03_0032F660 with `addiu $v0,$s4,lo(D_001A4BE0)`, reloads lbu 0xF1 in the then-arm and sets v0=9 in the else-arm; the C puts `addiu $a0,9` there and never hoists the base address; ternary, if/else in both orders and a hoisted gp load tried |
| `func_L03_003B28D0` | levels | level 3 (Starship Phoenix) draft | 6 differences: the jump table (cases 0,2,4,3,5 in retail block order, case 1 and default sharing a tail through gotos) and the lui forms match; in three beq delay-slot groups retail emits `move $a0` before `addiu $a1,N`, the C the reverse; two alias externs for the same $gp slot are needed or gcc cross-jumps the two calls; a different argument variable, typed prototype and moving the assignment did not change it |
| `func_L03_003A20E0` | levels | level 3 (Starship Phoenix) draft | 97 differences with the default assembler (needs @ps2as for the 1.2f / 0.017f constants, which L03_003A20E0.c does not have): the prologue, the jump-table dispatch and the register allocation match and every case is written, but retail cross-jumps the four func_L01_004450F0(a,n,-1) calls into one shared tail (case 1 is laid out as `b tail` with li $a1,5 in the delay slot) and the C does not; a goto to a shared tail swaps the saved registers (131-134 diff) |
| `func_L03_00330530` | levels | level 3 (Starship Phoenix) draft | 157 differences from scheduling and register allocation (every call and argument matches, needs @ps2as which the file has): retail saves s2 then s3 and keeps the arg0->f68 pointer in s3, the C keeps it in s2; retail reloads D_L03_001E0B24 for each of two (int)(f*256+0.5f+0.0f) style arguments with dead lw D_L03_001E0B20 loads between them, the C interleaves them; locals, a static inline helper and 0.0f*D did not help (4 compiles only) |
| `func_L03_003A2790` | levels | level 3 (Starship Phoenix) draft | 10 differences, only reachable with @ps2as (L03_003A20E0.c has none; 131 diff with the default assembler): retail has i in $s5 and a in $s6, the C the other way round, rippling through the lw/lq operands and the bgez, and orders addiu $t3,1 and mov.s $f14,$f21 the other way; do-while, a local copy of a, declaring i first and a per-iteration pointer tried |
| `func_L03_0048A810` | levels | level 3 (Starship Phoenix) draft | 133 differences, saved-register assignment: the structure matches (5-entry jump table, three simple cases sharing a tail written with goto, a list walk through e->ids, 0x50 frame) but retail keeps i in $s2 and the C in $s4, and e/l and ok/any coalesce differently, shifting nearly every line; 7 declaration orders and merging ok/l via casts changed nothing; sibling of func_L03_0048B918 |
| `func_L03_003A1158` | levels | level 3 (Starship Phoenix) draft | 20 differences, all register choices in the three cases that write floats at p+0x150 (cases 6, 9 and 14): retail keeps p+0x150 in $v1 and the compare constant in $a0, the C in $a1 and $v1; offsets, constants, store order (f20, w38, f28, f24 in the source), jump table and delay slots match; typed struct, f32 pointer, P struct and declaration orders tried |
| `func_L03_003A17D8` | levels | level 3 (Starship Phoenix) draft | flags/layout: the C matches with --as ps2as (check.py says MATCH) but cannot be linked yet: the build stops with `§.rodata would be at 0x002BE0A0 and at 0x002BE1A0` because L03_0039E470.c's jump tables must sit next to each other and the table of the assembly function func_L03_003A1158 (a 20-diff near miss) lies between this table and func_L03_0039ECA0's; it can be integrated once func_L03_003A1158 is C too |
| `func_L03_0032C918` | levels | level 3 (Starship Phoenix) draft | 132 differences, register allocation in the 3-iteration list-walk loop (the 0x60 frame, callees, epilogue, the four short loops and the first ~45 instructions match): retail spills q (p+0xB4) to 0($sp) before the sw to the $gp slot, keeps the A8 base in $s7 with a per-iteration move $a3,$fp and daddu reloads, the C spills the A8 base and keeps q in $fp; an extra copy variable gets CSE'd (147) |
| `func_L03_004896E0` | levels | level 3 (Starship Phoenix) draft | 137 differences, almost all register allocation (case 0 matches retail apart from register names; the 5-entry jump table with case 4 next to default and the inner loops are structurally right): retail keeps next in $s3, e in $s0/$s1/$a2 and the table pointer in $s1/$s7 and saves s2, s7 first, the C puts next in $s1 and the high-half pointer in $s5; an explicit table pointer and offset made it worse; sibling of func_L03_0048B918 and func_L03_0048A810 |
| `func_L03_0039A780` | levels | level 3 (Starship Phoenix) draft | 137 differences with @ps2as needed for the inline float constants (162 with the default assembler; L03_00399D30.c has no @ps2as): logic, call sequence, constants and the movn/movz selects match; retail puts each func_L01_0046FB40 result in $a1 where the C uses $a2 and computes f12 = f20*0.6f then f12 *= f22 keeping f20, the C multiplies in place; separate locals per call gave 127 |
| `func_L03_00396320` | levels | level 3 (Starship Phoenix) draft | 77 differences with @ps2as needed for the inline float constants (L03_00395808.c has no @ps2as): the logic is right (two pre-loop spawn calls, then a do/while with two per iteration), register allocation only: retail keeps each spawn result in $a1 and c in $s3 with t in $f20 and a in $f21, the C uses $a2/$a0 and $s4 with the float roles swapped; a shared result local and a single float were worse (80-87) |
| `func_L03_00321DD0` | levels | level 3 (Starship Phoenix) draft | 163 differences, codegen detail (all five cases of the jump-table switch are written in table order): the jump-table setup differs (the C puts sll before the lui and uses $v1 where retail uses $a0), retail keeps the D_00142CA0 base in $a0 (lui+addiu, so +0x22 and +0x1E are offsets from a held pointer) and puts the D_001426E0 lui in the beqz delay slot while the C folds the offset into the address and leaves a nop; globals as plain arrays, locals at the top (189), locals inside case 0 (163-177) and struct-typed globals (174) tried |
| `func_L03_00397698` | levels | level 3 (Starship Phoenix) draft | 6 differences: all ten cases of the jump-table switch are written in retail block order (3, 10, 6, 5, 9 falling into 7, 4, 1, 8, then 2/default); only the register choice in the two D_L03_002D09B0[0] == 1 checks (cases 5 and 9) differs: retail has the lui in $v1, the loaded value in $v0 and the constant 1 in $a0, the C the lui in $v0 and the value in $v1; a scalar, a local, a reordered comparison and an early read of the sda pointer tried; the four shared tails are separate calls with return (gotos flipped $s0/$s1) |
| `func_L03_0039E470` | levels | level 3 (Starship Phoenix) draft | 1 real difference (check.py counts 63 because the missing nop shifts every later line): all eight cases of the jump-table switch are in retail order (case 1 empty, case 3 falling into case 4, shared tails with goto); retail has `bnez $v0, end; nop` before the shared ECA0(a,8) tail, the C puts `move $a0,$s0` in that delay slot; five structural variants (goto, label placement, duplicated call, done-label) tried; its jump table must also be adjacent to the file's other C tables |
| `func_L03_003CB5E0` | levels | level 3 (Starship Phoenix) draft | 106 differences, almost all register allocation (control flow and instruction sequence match; a switch on a0->0x20 with explicit empty cases 0, 1 and 2 reproduces the beq 3 / slti 4 / beq 4 tree): retail keeps a0 in $s4 and the D_L03_001DEF60 loop pointer in $s3, the C swaps them; the case-3 index walk orders and allocates the D_L03_001DE858 and D_001426E0 loads differently; about 17 compiles (loop locals, a table pointer, do-while/for); reading D_001426E0[0x77] directly everywhere took it from 166 to 106 |
| `func_L03_003AF450` | levels | level 3 (Starship Phoenix) draft | 92 differences: everything except cases 4 and 5 matches structurally (nine-entry jump table, retail block order 0,1,3,6,4,5,7,8, lui forms through unsized arrays with hint 16); retail case 4 is `if (call(a)) { if (a->f43 != 4) f(a,4,0,8); }` followed by lbu 0x60 / andi 2, gcc emits beql with a duplicated lbu in the delay slot and then b with andi in its delay slot, case 5 has the same shape; a shared variable with goto, a duplicated load in both arms and t = ... & 2 all give a plain beqz and different delay-slot filling |
| `func_L03_0039FEF0` | levels | level 3 (Starship Phoenix) draft | needs real VU0: case 11 contains lqc2 / vadd.xyz / sqc2 at 0x3A00E8-0x3A0110 (inline asm for VU0 is allowed since 2026-11-08 and was not tried here; the todo bucket says switch because it classifies by the jump table first); the C approximates it with an lq/sq copy plus float adds, and a $s1/$s2 swap (retail keeps obj in $17, s in $18) shifts about 100 lines (174 counted); every other case is structurally identical |
| `func_L03_00322160` | levels | level 3 (Starship Phoenix) draft | 240 differences, mostly one structural problem (full control flow and constants are right; an explicit case 0 gives retail's slti tree): retail hoists lui $fp for D_001A7E18 and lui $s7 for D_001426E0 into callee-saved registers and re-emits addiu from them before each use, the C folds sym+offset into a fresh lui+lhu per use and keeps D_001426E0 as whole-pointer registers, shifting the saved-register allocation; D_001A7E18 as u8/u16 array, struct and unsized struct array, with and without hint, and local pointers (247) tried; the sibling func_L03_003A4550 matches with the lui-hoist form |
| `func_L03_00411220` | levels | level 3 (Starship Phoenix) draft | 200 differences, mostly a cascade from one divergence in the case 0 compare chain: after each `t < (X*5+2)/6` test the compiler hoists the next block's lui into the delay slot and its lw into the fall-through while retail leaves a nop and starts every block with its own lui; lw (the first test matches); an if/else chain, sequential if/break and a ternary chain (211) tried, with and without hints on the six scalars; retail has a=$t3, b=$t2, c=$t1, d=$t0, e=$t7 and the 0x1E6800 high half in $t4; not tried: the six loads through one struct array with a variable index |
| `func_L03_004121B8` | levels | level 3 (Starship Phoenix) draft | 5 differences, needs @ps2as for the inline float arguments (L03_004121B8.c has none; 200+ diff with the default assembler): in the retail loop over the null-terminated list `addiu $a0,$s3,-0x7190` comes after `lw; beqz; lui $s1; li $a1,1`, the C emits it before the lw; the loop body, the $fp copy of the 0x1E6800 high half and the register assignments match; about 10 placements of the list pointer tried |
| `func_L03_003A2398` | levels | level 3 (Starship Phoenix) draft | 126 differences (one cause) with @ps2as needed for the inline float constants (L03_003A20E0.c has none; 231 diff with the default assembler): the six-entry jump-table switch is written in retail block order; in case 3's bit-clear branch retail puts `move $a2,$s1` (arg0 of func_L01_00456230) in the delay slot of the bnez on D_00142C1C & 0x40000000, the C puts `move $a0,$zero` there, so every later instruction of case 3 is one slot off; the inverted if/else (149) and a split result declaration tried; not tried: other argument orders or types for the result |
| `func_L03_0032E0D8` | levels | level 3 (Starship Phoenix) draft | 308 differences, register allocation (not VU0: the lq/sq are caller-save spills of $7 around the call; the jump table covers cases 0x10..0x97 and best.c has all blocks in retail order: 27, 77, 2F, 7F, 37, 47 sharing the tail at E404 by goto, 57, 6F, 3F, 4F, 5F, 97, 15, 11, 13, 10): retail keeps hi(D_001425C0) in $fp and hi(D_L03_002C49C0) in caller-saved $a3/$7 with a 0x80 frame, the C keeps both in callee-saved registers and the frame comes out 0x70 or 0xA0; the case 0x37 loop does not reproduce retail's q/offset/base trio (i counter, q pointer plus i, local base pointer all about 308) |
| `func_L03_0039F3C0` | levels | level 3 (Starship Phoenix) draft | check.py says MATCH with the file's @ps2as and its context, but the full build rejects it: the jump table's entry +0x2C is 0x0039F4C0 where the level has 0x0039F4CC (one case block lands three instructions early, the case 3 into case 4 fall-through block); check.py does not compare the table, and the file's C jump tables must also be adjacent (func_L03_003A1158 and func_L03_003A17D8 are still assembly between them); the shared tails written out per case with four gotos left (FEF0(s,5/9/6/14)) |
| `func_L03_0032C3A8` | levels | level 3 (Starship Phoenix) draft | 267 differences (interrupted attempt, about 20 variants measured afterwards at 267-270): the jump-table switch is written but the structure and register allocation are far from retail; no variant came close, so this needs a fresh look; needs no @ps2as (L03_0032C3A8.c cannot take it) |
| `func_L03_00396860` | levels | level 3 (Starship Phoenix) draft | 157 differences (attempt interrupted by an API limit; eight variants measured at 157-160): the jump-table switch is written but far from retail in register allocation and scheduling; no variant came close, so it needs a fresh look |
| `func_L03_003B0810` | levels | level 3 (Starship Phoenix) draft | 140 differences with @ps2as needed for the inline float constants (L03_003AF410.c has none): the six-case jump-table switch (blocks +0x220, +0x2A0, +0x1A0, +0x310, +0x1E0, +0x360 in retail order), the 0xD0 frame, saved registers, constants and $gp accesses match; the remaining diffs are scheduling and register choice (the head `(f&1) + (0 < (f&2))` puts the first temp in $s0 not $v0; the shared return 0 sits just before the switch loop in retail, at the function end in the C; g*24 and lui ordering after the first func_L03_003B0670 call; sll h*8 placement); about 25 variants tried |
| `func_L03_003A05D0` | levels | level 3 (Starship Phoenix) draft | 192 differences, mostly shifted branch targets (needs no flag: the file has @ps2as): the prologue, saved registers and cases 2-8, 10-14 match in instruction order (case 1 empty for the table range, case 3 falling into case 4, a goto for the shared andi 2 test, switch(bBC) in case 12); the blocker is case 9: retail keeps two copies of `i188 &= ~0x10; func_L03_0032DA08(s); b` (one on the h144 != 1 fall-through, one after a bc1f) and gcc cross-jumps them into one, so the C is 8 instructions short and every later target shifts by 0x20; explicit if/else, goto reorder, temps and an inline call tried; in cases 6 and 8 retail uses $v1 for the lbu 0x60 where the C uses $v0 |
| `func_L01_003386E0` | levels | no twin (wrench_update); near-sibling func_L39_0055B4D8 (0.41); m2c draft (Sonnet w7) | 9,592 B hero wrench update, 13 VU0 ops: near miss only |
| `func_L01_0033D2B8` | levels | rac2 `func_L01_00399170` | exact with --as ps2as; file built without it |
| `func_L01_0033D780` | levels | p2 quick win | exact at 01 with ps2as; gp slot differs in other levels (false fold) |
| `func_L01_00350750` | levels | no twin; sibling func_L01_00353EA0 (0.50); m2c draft (Sonnet w7) | 8,704 B, 2 switches, 9 VU0 ops: near miss only |
| `func_L01_00353EA0` | levels | no twin; sibling func_L01_00350750 (0.50); m2c draft (Sonnet w7) | 7,908 B, 2 switches, 21 VU0 ops: near miss only |
| `func_L01_003A0778` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c fails on delay-slot label; dossier only |
| `func_L01_003A4320` | levels | p2 from asm (entity scan family) | level 08 stores at +0x2D8 not +0x2E8 (false fold) |
| `func_L01_003A4910` | levels | prep from rac2 `func_L18_003F8E80` | 5 diff: sltiu result lands in $a1 directly instead of $v0 then move |
| `func_L01_003B6458` | levels | prep from rac2 `func_00351268` | 4 diff: idx/base regalloc swap (a1, v0 vs v0, v1) |
| `func_L01_003C8E98` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L01_003CD778` | levels | from asm | state switch; 4 diff: position of lqc2 vf2 vs arg moves |
| `func_L01_003F5498` | levels | p2 near miss 13 diff | needs --as ps2as; same ops but lui/div.s/addiu scheduling order differs |
| `func_L01_003F55D0` | levels | p2 quick win | exact once levels get a div.s nop table (2 2) |
| `func_L01_003F8B30` | levels | from asm | VU0 vsub non-volatile m-operand asm; 6 diff: index regs v0/v1 swapped |
| `func_L01_0042E360` | levels | prep from rac2 `func_00295870` | 6 diff: addiu/sll order in index calc |
| `func_L01_004360B8` | levels | hand draft | matches L01-L38; L39-L53 use offsets 0x4de0/0x4de4 and another gp slot |
| `func_L01_00436740` | levels | prep from rac2 `func_0029CD48` | matches at 01 + 3 levels; false fold, callbacks differ per level |
| `func_L01_00443B18` | levels | prep from rac2 `func_L02_0031E9E8` | bare `sq $zero` (retail) vs por+sq; 4 diff |
| `func_L01_00448F30` | levels | rac2 `func_002AB168` | 2 diff: epilogue ld $s0 scheduled before sqc2 (VU0 m-operand asm) |
| `func_L01_0044ABD0` | levels | prep from rac2 `func_002AB8C0` | only the nop before div.s (divs_nops) |
| `func_L01_00450F00` | levels | from asm | VU0 block form; 3 rows off in epilogue ld order |
| `func_L01_00451738` | levels | prep from rac2 `func_L02_00329C48` | 2 diff: abs.s scheduled before ld $ra (unscheduled fabsf) |
| `func_L01_0045B8F0` | levels | prep from asm (u128 copy) | 4 diff rows: v0/v1 swapped (address vs lq result) |
| `func_L01_0049C950` | levels | prep from rac2 `func_00130250` | 3 diff: lw of D_001D52FC scheduled after move a0 |
| `func_L01_004AD9A0` | levels | prep from rac2 `func_002E9268` (0.80) | cutscene player; draft 77% opcode-equal; needs VU0 inline asm for 5 vadd.xyz sites, frame layout, debug-skip block |
| `func_L01_004B14C8` | levels | p2 quick win | exact with @ps2as + div.s nop table (2) |
| `func_L01_004CE720` | levels | prep from rac2 `func_00335E88` | exact at 35 places; L40-53 use +0x45e4 not +0x4614 |
| `func_L01_004D2470` | levels | p2w3 port | MATCH at 01..38 places; false fold: levels 39-53 use 0x45E0 instead of 0x4610 |
| `func_L01_004D2498` | levels | draft | near miss (see the header) |
| `func_L01_004F5E98` | levels | prep from rac2 `func_L00_002BA7D8` | 7941 diff, 5031/8692 opcodes; VU0 inline (114 lqc2) so near miss at best; rac3-only states undrafted |
| `func_L01_00507AF8` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 5097 of 7707 opcodes equal; seed of the 0x110 dispatcher family |
| `func_L02_0034FD58` | levels | prep from rac2 `func_L19_0041C328` | matches 6 places; false fold: levels 04,08,17,22,28 use +0x2F8 |
| `func_L02_00351780` | levels | p2w2 draft | false fold: levels 08,20,28 store at +0x198 (rest +0x2D8) |
| `func_L02_003A5138` | levels | p2 quick win | matches at 02/US; false fold (offsets differ in 05,08,11,28) |
| `func_L02_00428520` | levels | VU0 block asm from rac2 twin | epilogue ld s1 hoisted between vadd and sqc2 (4 diff) |
| `func_L02_00431568` | levels | port of rac2 `func_L02_00331440` + f15/0x24 | 10 diff: single FPR swap f22/f23 |
| `func_L02_004C2BA0` | levels | from asm | gp float load comes out lui-form; store order of 25C0/25E4/BF4 and C00/C04 |
| `func_L02_004CAF58` | levels | prep from rac2 `func_L04_002E04A8` (draft via rac2 twin) | VU0 COP2 inlined in rac3 (76 lqc2); draft 4195 of 6803 opcodes equal, 6217 diff rows; rac3-only states stubbed |
| `func_L02_004D36C0` | levels | prep from rac2 `func_L12_002C8BD0` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 84% opcodes equal (ps2as) |
| `func_L02_004DA1D0` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 17304 vs 22620 B (4326 vs 5655 instr) |
| `func_L02_004E2118` | levels | from asm | 4 diff: store/addiu scheduling around two quadword stores |
| `func_L03_0032ED88` | levels | p2 | exact at L03, level-07 place differs by field 0x50 vs 0x60: false fold |
| `func_L03_003AAD60` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c (with jtbl) 951 lines, compile blocked by prototype conflicts; most tractable for a later Opus pass after cleanup |
| `func_L03_0040F9E8` | levels | prep from rac2 `func_L05_003D1E20` | two-array clear loop; address setup order, 3 diff |
| `func_L03_0040FEE8` | levels | prep from rac2 `func_00290B48` | catalogue size: delay slot of jr missing from retail size, otherwise exact |
| `func_L04_00362EF0` | levels | p2 quick win from rac2 func_L18_003F8E80 | 5 diff: result lives in $a1 then moves to $v0 (extra move, branch target 0x18) |
| `func_L04_003E5788` | levels | entity-walk template + VU0 vsub asm | 2 diff: move $a0 scheduled before sqc2 (needs j-form) |
| `func_L04_00504520` | levels | prep from rac2 `func_L19_002BCA50` (draft via sibling draft) | VU0 COP2 inlined in rac3 (82 lqc2); draft 3833 of 6695 opcodes equal, 6123 diff rows; rac3-only states stubbed |
| `func_L04_0050CB28` | levels | prep from rac2 `func_L12_002C8BD0` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 85% opcodes equal (ps2as) |
| `func_L04_00513880` | levels | prep from rac2 `func_L20_002DEBE0` (decider family) | compiles; 0.795 opcode ratio, 21472 vs 25360 B; ~26 rac3-only states (jtbl targets listed) and the prologue locals missing |
| `func_L05_003B1BD0` | levels | from asm | exact with --as ps2as (inline float const); file flags lack @ps2as |
| `func_L06_0034A7A8` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; 167 VU0 sites + sq $zero; m2c fails; dossier only |
| `func_L07_003318D8` | levels | p2 quick win from rac2 func_L04_00415EA8 | 2 diff: lui goes to $v0 then addiu $v1; retail lui $v1 directly |
| `func_L07_00331FA0` | levels | p2 quick win from rac2 func_00351EE8 | 5 diff: lw 0x18(s0) must be scheduled before the lui/lw of the table pointer |
| `func_L07_00335448` | levels | hand draft | 2 diff: lui order for the 0x150006 call args |
| `func_L07_0035CA80` | levels | prep from rac2 `func_L00_00403C30` | 3 diff: lui/move order and base reg v0 vs v1 |
| `func_L07_003AA9C0` | levels | p2 near miss 5 diff | mask -0x11 hoisted into a1 above sd s0 in retail; mine a0 after |
| `func_L07_003ACA00` | levels | p2 (not from rac2 twin) | 5 diff: mask -0x11 lands in $a0 not $a1 |
| `func_L08_003A4E60` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; not hand-written (neg); m2c fails; dossier only |
| `func_L08_004D6580` | levels | prep from rac2 `func_L19_002BCA50` (draft via sibling draft) | VU0 COP2 inlined in rac3 (46 lqc2); draft 3211 of 5504 opcodes equal, 5012 diff rows; rac3-only states stubbed |
| `func_L08_004DD0C0` | levels | prep from rac2 `func_L12_002C8BD0` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 82% opcodes equal (ps2as) |
| `func_L08_004E36C0` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 20508 vs 24640 B (5127 vs 6160 instr) |
| `func_L09_00350B30` | levels | rac2 `func_L30_0040E660` | 8 diff (ps2as): arg-move scheduling |
| `func_L09_003B8580` | levels | no twin; m2c draft (Sonnet w7) | 13,784 B boss update, 3 switches, 9 VU0 ops: near miss only |
| `func_L09_003C7338` | levels | p2w3 port | MATCH at all 5 PAL places (09,18,20,24,29) but only with --as ps2as; file L09_003C5E78.c has C compiled without @ps2as, so lead must decide (flag is per file); NTSC-U differs |
| `func_L09_0050E198` | levels | prep from rac2 `func_L04_002E04A8` (draft via rac2 twin) | VU0 COP2 inlined in rac3 (68 lqc2); draft 4187 of 6532 opcodes equal, 5971 diff rows; rac3-only states stubbed |
| `func_L09_005164C0` | levels | prep from rac2 `func_L04_002E7C08` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 84% opcodes equal (ps2as) |
| `func_L09_0051CD50` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 17304 vs 22344 B (4326 vs 5586 instr) |
| `func_L10_003AEE90` | levels | no twin; m2c draft (Sonnet w7) | 6,388 B, one state switch, 9 VU0 ops: near miss only |
| `func_L10_003B64C8` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; plain-C candidate |
| `func_L14_0035CD38` | levels | from asm (sibling of L03_0032EF78) | 4 diff: p++ delay-slot placement in the 0x1699/0x16CA dispatch |
| `func_L16_003C9768` | levels | no twin; m2c draft (Sonnet w7) | 7,348 B, 3 switches, 12 VU0 ops: near miss only |
| `func_L19_00302998` | levels | prep from rac2 `func_L01_00390A50` | one extra nop from do{}while(0) forced-flag block; without it s3/s4 swap |
| `func_L19_00335748` | levels | prep from rac2 `func_L03_004197C8` | 4 diff: epilogue ld order around sqc2 (needs j-form VU0 statements) |
| `func_L19_00336100` | levels | VU0 block asm from rac2 twin | j++ addiu must sit between vsub and sqc2 (one moved insn, 7 rows); needs j-form (flag absent) |
| `func_L19_003556D0` | levels | wave4 VU0 blocks | 4 diff: ld $s1 hoisted between vadd and sqc2 in retail |
| `func_L19_003AFCB0` | levels | no twin; m2c draft (Sonnet w7) | 6,784 B, 4 switches, 6 VU0 ops: near miss only |
| `func_L19_003D0108` | levels | p2 from rac2 `func_00279988` | exact under mode N; file is mode S+ps2as (sibling needs it): 2 diff (lui/addiu vs sd ra order) |
| `func_L19_00465AD0` | levels | from asm, `--as ps2as`; gp floats D_L19_001D7EB8/BC/C0 need `.extern ,4` hints | 4 diff: lui register of the D_L19_0021F058 pointer load (hoisted $a0 vs $v0) |
| `func_L19_004EA280` | levels | prep from the L01 seed draft (rac2 `func_L00_002BA7D8`) | 6676 diff, 4089 of 7342 opcodes; differs from the seed by 1192+ instr of states removed |
| `func_L19_004F32A0` | levels | prep from rac2 `func_L03_002C6F08` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 79% opcodes equal (ps2as) |
| `func_L19_004F9D80` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 4778 of 7251 opcodes equal; differs from the seed by blocks listed in the header |
| `func_L20_003AF880` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L20_003D0910` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin, one function, 88 lq/sq (u128_t now allowed), m2c fails; dossier only |
| `func_L20_003DFF98` | levels | rac2 `func_L00_00322EC8` | loop right; 8 diff prologue/delay slot |
| `func_L20_003EE6B8` | levels | p2 near miss 5 diff | flag test D_00142C58&0x2000000; retail schedules lw after addiu sp, mask in a1 |
| `func_L20_003FB6A8` | levels | no rac2 twin; sibling func_L05_003560C8 (0.64); m2c draft (Sonnet w7) | 10,560 B final-boss update, 7 switches, no VU0: matchable in principle |
| `func_L20_003FEDF0` | levels | rac2 `func_L02_003CD8C0` | 2 diff: base reg a0 vs v1 |
| `func_L20_004024E8` | levels | from asm (ps2as) | stack Params struct; const-1 register sharing / early schedule of arg setup differs |
| `func_L20_0048FF30` | levels | hand port from retail asm + rac2 func_002C6868 | ps2as; s-reg numbering swap (self/ctl), 24 diff |
| `func_L20_0053FFD8` | levels | p2 quick win from rac2 func_L02_003D69F0 (not really) | 1 diff: only diff is the trailing delay-slot addiu sp that retail keeps in the LINKER_REMNANT at 00540000; body matches |
| `func_L21_00339088` | levels | rac2 `func_L20_00442E68` | 2 diff: reg of loaded base pointer (a0 vs v1) |
| `func_L21_003A8050` | levels | no twin; m2c draft (Sonnet w7) | 6,036 B boss update, 3 switches, 3 VU0 ops: near miss only |
| `func_L22_003B3228` | levels | no twin; m2c draft (Sonnet w7) | 11,472 B, 2 switches, 12 VU0 ops: near miss only |
| `func_L23_003A5328` | levels | from asm | 2 diff: loop compare slti/bnez register ($v0 vs $v1) |
| `func_L23_003A8028` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; no switch, float+random code; m2c fails on delay-slot label; dossier only |
| `func_L23_003AD800` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L23_003B1490` | levels | no twin; m2c draft (Sonnet w7) | 8,296 B, 6 switches, 11 VU0 ops: near miss only |
| `func_L23_003D8628` | levels | prep from rac2 `func_L02_002DCEA0` | exact modulo 2 nops before div.s; ps2as |
| `func_L23_004C2CE8` | levels | rac2 `func_L22_002AA480` | divs_nops (2 nops before each div.s) + a1/v1 swap in anim index |
| `func_L23_004D8188` | levels | prep from the L01 seed draft (rac2 `func_L00_002BA7D8`) | 8703 diff, 5063 of 9527 opcodes; differs from the seed by extra states (+854 instr) |
| `func_L23_004E3428` | levels | prep from rac2 `func_L22_002C9898` and rac3 seed `func_L30_004CF4B0` | subset of the func_L30_004CF4B0 hero state entry (seed draft minus states); draft 82% opcodes equal (ps2as) |
| `func_L23_004EAE60` | levels | prep from rac2 `func_L22_002D0C98` | draft compiles, 5227 of 8405 opcodes equal; differs from the seed by blocks listed in the header |
| `func_L24_0034AE40` | levels | rac2 `func_L30_003847F8` | 2 diff: ori/addiu order before call |
| `func_L24_00351448` | levels | from asm | 4 diff: store order in state block (0x10/0x20/0x14); needs ps2as |
| `func_L24_00352060` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c fails; dossier only |
| `func_L24_003B8878` | levels | p2w3 port | needs --as ps2as (inline float consts); all matches except final 4 insns: reg alloc of slot/p24/value tail (a1/v1/a0 vs a0/v0/v1); twin was wrong, written from asm |
| `func_L28_00309CE8` | levels | prep from rac2 `func_L08_003DB8E8` | one extra lui+lw reload of D_L28_001DE840 in the arm block (shift only) |
| `func_L30_004C4318` | levels | prep from the L01 seed draft (rac2 `func_L00_002BA7D8`) | 8666 diff, 5073 of 9457 opcodes; differs from the seed by 11 extra states (+791 instr) |
| `func_L30_004CF4B0` | levels | prep from rac2 `func_L22_002C9898` and rac3 seed `func_L30_004CF4B0` | hero state entry, 5239 instr; draft 76% opcodes equal (ps2as); 18 added states (0x4F-0x59, 0x81, 0x9A-0xAD) undrafted, 7-group parameter blocks differ |
| `func_L30_004D7368` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 5058 of 8822 opcodes equal; differs from the seed by blocks listed in the header |
| `func_L31_003A5178` | levels | re-derived (jal chain) | 2 diff: lwc1 gp float vs abs.s order |
| `func_L31_00424440` | levels | prep from rac2 `func_002B04E0` | one VU0 asm block, 2 diff: move a1,sp vs sqc2 order |
| `func_L33_00350818` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; plain-C candidate |
| `func_L35_0043FF68` | levels | wave4 VU0 blocks | 1 diff: catalogue size (trailing delay slot); needs --as ps2as |
| `func_L39_004B3F28` | levels | from asm (twin func_002A0430) | 5 diff: delay-slot scheduling of -11/lw saved, lui reg |
| `func_L39_004B40C8` | levels | p2 near miss 4 diff | delay slot fill: retail puts sh in jal delay, addiu a0 before; return 4 vs ld s0 order |
| `func_L39_004B95C0` | levels | from jtbl | 7 diff: dispatch codegen (in-place a0-4, nop slot) |
| `func_L39_004C1BA8` | levels | prep (rac2 func_002ED9C0) | body matches; entry holds a 2nd 8-byte fn (return 300) at 004C1BE0, needs split |
| `func_L39_004D1480` | levels | p2w2 draft | 5 diff: prologue scheduling only (sd/sw/move a3 order) |
| `func_L39_004D1BB8` | levels | p2 quick win | scheduling only: retail stores a0 to 0x14(sp) before setting a1/a2/a3; ours sinks the store after |
| `func_L39_004ECE38` | levels | no twin found (part3 best < 0.35, callee overlap none) | merged chunk: 11 functions in one catalogue entry; split needed |
| `func_L39_004F16B0` | levels | p2 quick win from rac2 func_L20_00449AD8 | 1 diff: only diff is a 0xCDCDCDCD fill word retail counts inside the 16 bytes (catalogue size); body matches |
| `func_L39_004FA538` | levels | from asm | 10 diff: stack frame 0x50 vs 0x40 (save slot spacing) |
| `func_L39_004FBED8` | levels | prep from rac2 `func_0011CD20` | arg-shuffle scheduling, 2 diff |
| `func_L39_004FC1A0` | levels | from asm | 17 diff: 16-byte save-slot frame, logic right |
| `func_L39_004FF3C0` | levels | from asm | body exact; retail 16-byte sd save slots (frame 0x40) vs our 8-byte |
| `func_L39_0050C5A8` | levels | p2 | 8 diff: instruction scheduling of the 7-arg call setup |
| `func_L39_0050D838` | levels | p2w2 draft | 5 diff: jtbl address load shape only |
| `func_L39_0050DB08` | levels | hand draft | 2 diff: store order of final sw D,(a0) vs sw 0,4(a1) |
| `func_L39_0050DE20` | levels | prep from rac3 asm (twin func_0028DF38) | byte-swap 2 bytes into stack buf + call; reg allocation of temps (a1/a2 vs t0/t1), 19 diff |
| `func_L39_00510298` | levels | p2 near miss 2 diff | only prologue order differs: retail move s0,a0 before sd s1; tried param types, callee returns, negation |
| `func_L39_00537B28` | levels | rac2 `func_L00_003AE900` weak family (opcode 0.57); sibling `func_L39_00539398` | draft = renamed rac2 body, 2104 diff; COP2 blocks, ~50% opcodes aligned |
| `func_L39_00539398` | levels | rac2 `func_L00_003AE900` weak family (opcode 0.42); sibling `func_L39_00537B28` | draft = renamed rac2 body, 2235 diff; COP2 blocks, ~50% opcodes aligned |
| `func_L39_0053C248` | levels | portrun + VU0 vsub asm | 4 diff: lw $a1 scheduled inside the VU0 sequence (needs j-form) |
| `func_L39_0055B418` | levels | from asm | exact except 2 retail nops before div.s (no divs_nops for levels); --as ps2as |
| `func_L39_0055B4D8` | levels | no twin; near-sibling func_L01_003386E0 (0.41); m2c draft (Sonnet w7) | 8,384 B menu update with inlined obfuscated-variable decoder, 10 VU0 ops: near miss only |
| `func_L39_00565750` | levels | prep from rac2 `func_L11_004349F8` | 17 diff: reg alloc of st/0xFF temps |
| `func_L39_0059A578` | levels | p2 quick win | matches at 39; false fold (40-53 differ in addresses) |
| `func_L39_0059DB38` | levels | prep from rac2 `func_00290758` | matches level 39; other levels differ in callee addresses (false fold) |
| `func_L39_005A12B8` | levels | prep from rac2 `func_L00_00300618` (level gameplay loader) | draft compiles, 2787 diff; frame 0x90 vs 0xB0; rac2-only blocks to delete; max.s inline |
| `func_L39_005A5F48` | levels | prep from rac2 `func_002D7B00` | lw/lui scheduling and reg (v0/v1 vs a0/v1), 5 diff |
| `func_L39_005A61D8` | levels | prep from rac2 `func_00298F00` (0.86), API draft | memory-card state machine; draft 98.9% opcode-equal (+12 instr): tail-merge, scheduling and loop-inversion hunks |
| `func_L39_005B25C8` | levels | no twin found (part3 best < 0.35, callee overlap none) | hand-written assembly (scratchpad save, addi, DMA regs); not C |
| `func_L39_005C2960` | levels | prep from rac2 `func_002B7AD0` | 2 diff: constant 1 in $v0 vs $v1 |
| `func_L39_005C7F38` | levels | prep from rac2 `func_002BCF18` | needs @ps2as; 1 diff: delay slot of first bc1f (lwc1 vs nop) |
| `func_L39_005C8CA8` | levels | prep from rac2 `func_002BDBC0` | exact with --as ps2as except missing nop;nop before div.s (divs_nops) |
| `func_L39_005CA8B0` | levels | from asm, needs `--as ps2as` | 4 diff: register/schedule of the D_L39_002968A0 pointer load (lui $a2 vs $v0) |
| `func_L39_005D2930` | levels | rac2 `func_L00_0033FFB8` | 7 diff: lui of D_L39_002969A4 scheduled later ($v1 vs $a0); needs --as ps2as |
| `func_L39_005E3A10` | levels | prep from rac2 `func_L14_003DE990` | 2 diff: sll/addiu order before memset call |
| `func_L39_005F3668` | levels | from asm | matches at L39/NTSC-U; levels 40-53 differ only in the gp slot (false fold) |
| `func_L39_00602010` | levels | rac2 `func_00336CE8` | 10 diff: s0/s1 swap, bnez loop end |
| `func_L39_00608FE0` | levels | p2 quick win from rac2 func_003501E0 | 4 diff: needs --as ps2as; scheduler puts ld $ra before the two lui $at stores, retail interleaves |
| `func_L39_0060FDB0` | levels | prep (static-init idiom) | matches level 39; levels 40-53 differ in gp offsets (false fold) |
| `func_L39_00624658` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c compiles to 19 type errors (ring buffer); best tractable of the no-twin set |
| `func_L39_00632328` | levels | prep from rac2 `func_L00_002D3C68` | mode byte test: retail lbu+bltz+slti, we get lb+andi+sltiu |
| `func_L39_00640738` | levels | prep (no twin; anti-tamper Get/Set helpers) | compiles, 3147 diff; register layout (2 extra pseudos) and switch constants |
| `func_L39_00648C20` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; 148-entry/27-target switch; m2c fails; dossier only |
| `func_L39_0064EA40` | levels | prep (no twin; MP-menu command dispatcher, 145-case switch) | partial draft compiles, 8275 diff; needs Dec/Set helper shapes and @ps2as |
| `func_L39_00656F28` | levels | no twin; prefix draft + 31-target case map (Sonnet w7) | 24,952 B multiplayer state machine, 145-entry jump table with 31 distinct bodies, 72 inlined obfuscated-variable reads, 3 VU0 ops: near miss only |
| `func_L39_0066C7D8` | levels | prep from rac2 `func_L00_003B9CB8` (weak) | table lookup; needs --mode S --as ps2as, 2 diff (sll/lui order) |
| `func_L39_0067ED40` | levels | re-derived from asm | 3 diff: lw a1 / move a0,v0 order before final jal |
| `func_L39_00687450` | levels | from asm | 7 diff: s3/s4 swap, clamp movn vs movz |
| `func_L40_0040D310` | levels | p2w3 port | structure ported from asm (twin func_002B50E0); retail reads one global (0x24112C) in both gp form and lui form within the function; single-declaration C gives one form, so ~60 diff; no clean C form found |
| `func_L40_0041B9F0` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
