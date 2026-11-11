# Near misses and US drafts

C that is not linked and not counted: a starting point. One file per function,
`nonmatching/<program>/func_XXXXXXXX.c` (`<program>` is `frontbin`, `boot_elf`, `i5bootn` or `levels`,
the name is the PAL address), with a comment at its top saying where it came from and what still
differs. Move it into `src/` once the full build prints `MATCH` with it in place, and delete its
row here. `tests/check_repository.py` checks that every file has a row.

A draft that uses inline asm (beyond `.extern` size hints), `volatile`, a `#define` alias or a hardcoded address is a study aid, not a route to a match: those are not allowed in matched C, so such a function stays here until plain C matches.

Files that start with `/* US draft` are rac3-uya-decomp's C for that function (commit 13cf5c5),
with names moved to PAL addresses where the address maps are sure of them
(`tools/port_from_us.py`, docs/history/porting-from-us.md). They were not carried for the reason in their row:

- **flags**: the US match used flags of its own for this one function (a "single-function
  override" or `@ps2as` range), which this repository does not allow (docs/build/build-fidelity.md);
- **differs**: the PAL function's bytes are not the US ones, or the C did not build to them here;
- **symbols**: a name in the C has no PAL address yet.

`functional.tsv` lists the US drafts OpenRAC's native port of NTSC-U reads in place of the
assembly (`tools/us_names.py --candidates`, docs/build/versions.md): C that matched NTSC-U, for a
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
| `func_003C3BE8` | frontbin | US draft of `func_003BE6A8` | near miss: 4 diff with the file's flags (was 19) |
| `func_003C3D30` | frontbin | US draft of `func_003BE7F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C3EC8` | frontbin | US draft of `func_003BE988` | flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override) |
| `func_003C41A0` | frontbin | US draft of `func_003BEC60` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4360` | frontbin | US draft of `func_003BEE20` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C45A0` | frontbin | US draft of `func_003BF058` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C48A8` | frontbin | US draft of `func_003BF360` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003C4E80` | frontbin | US draft of `func_003BF910` | flags: the US matched it with `@ps2as` (a single-function override) |
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
| `func_L01_003B1128` | levels | level 1 draft | 6 differences, all one `ori` (finishing `0x388EF7`) that retail schedules after `sw $a1,0x30($sp)` and this C schedules earlier; the scheduler tie-break did not converge in about 14 compiles |
| `func_L01_003E36E8` | levels | level 1 draft | 16 differences, one rotation of the callee-saved registers (retail: s0=j, s1=i, s2=o, s3=offset, s4=flag, s5=buf, s6=s; this C gives o=$s5, buf=$s4, flag=$s3). Scheduling, the VLA `subu $sp`, the `$fp` frame and the loop match; all 12 local orders, `__builtin_alloca`, a hoisted pointer and while loops were tried. Landing it also needs func_L01_003E34F0 re-prototyped as `(void *, f32, s32, s32)` |
| `func_L01_003E1CD0` | levels | level 1 draft | 31 differences, all the jump-table address: retail builds it as `lui`/`sll`/`addiu`/`addu`/`lw` (separate `addiu` for the `%lo`), this C folds the `%lo` into the `lw` and emits the `lui` after the `sll`; no C form found that unfolds it (the `.extern` hint does not apply to the compiler-made table symbol). Control flow and callees match |
| `func_L01_00356748` | levels | level 1 draft | 41 differences: same list-search loop as the matched `func_L01_003B0D48`, but retail hoists the invariant `x <= D_001E0058` and `x & 0xFF` tests into the preheader (an always-zero `$a3`, a copy in `$a2`) and rotates the loop with `r` heading it; every `while`, `for`, entry-guard + `do while` and pointer-to-entry form left gcc emitting a bottom test with the table address and limit recomputed inside |
| `func_L01_00356050` | levels | level 1 draft | 4 differences, one register swap: retail `addiu $v0,0x1a; addiu $v1,6; sb $v0,0x25e; sb $v1,0x25f`, this C gives `$v1=0x1a`, `$v0=6`; about 28 variants of store order, `u8`/`s32` locals and struct fields did not change it; needs `@ps2as` on `L01_00353EA0.c` |
| `func_L01_0049CD08` | levels | level 1 draft | 28 differences: same table walk as the matched `func_L01_0049DE10` (five jump-table entries, 8 callee-saved registers), but retail increments `i` in place in case 1 so `i` stays live across the list loop (flag value in `$s3`, `k` in `$s4`); this C computes `n = i + 1` into `$s3`. Delete the `jtbl_002BCCA0` INCLUDE_RODATA line when integrating |
| `func_L01_0049BBD8` | levels | level 1 draft | 106 differences of 170, one cause: retail keeps `n = i + 1` in `$s3` separate from `i` (`$s2`) and ends each case with `move $s2,$s3`, case 1 reusing `$s2` for the flag value; gcc coalesces `n` into `i`, so everything after case 0 shifts. Cases 0, 2, 3 and the prologue/jump table line up. Same family as `func_L01_0049CD08` |
| `func_L39_00620E28` | levels | Opus L39 Sets, written from retail (2026-11-08) | 304 of 303 instructions; 65.7% of lines and 95.7% of opcodes equal. Left: the int n truncated at its use, FindE's saved registers, one callee-saved register too many; details in the file header |
| `func_L39_00628038` | levels | Opus L39 Sets, written from retail (2026-11-08) | 251 of 251 instructions; 68.9% of lines and 90.4% of opcodes equal; 110 rows differ. Needs `@ps2as` (already on src/levels/shared/L39_00622990.c). Left: the stack layout of the packet inline (frame 0x60, retail 0x50); details in the file header |
| `func_L39_00638848` | levels | Opus L39 Sets, written from retail (2026-11-08) | 248 of 248 instructions; 12 rows differ, all in one call's argument registers (the int converted to the float argument). Needs `@ps2as` on src/levels/shared/L39_00637D38.c. A permuter candidate; details in the file header |
| `func_L39_0063B5E0` | levels | Opus L39 Sets, written from retail (2026-11-08) | 228 of 228 instructions; 72.4% of lines and 96.9% of opcodes equal. Left: the early g + 0x2476 together with DecF's copy of it; details in the file header |
| `func_L39_00673EF0` | levels | Opus L39 Sets, written from retail (2026-11-08) | 168 of 168 instructions; 21 rows differ (88.1% of lines, 98.8% of opcodes). Left: the 0xD1/table register order in the DecB loops and the second loop's double *q read; details in the file header |
| `func_U_003B0C70` | frontbin | NTSC-U native draft at `0x003B0C70` | 2 differences: initial `lui` and stack adjustment reversed; rechecked 2026-10-31, three C forms unchanged, literal read gives 6 differences |
| `func_L01_003E8D48` | levels | near miss (open-rac-engine names it camera_set_tilt) | matches in 47 of its 49 levels: levels 02 and 16 store the tilt at 0x26C, not 0x204; the catalogue counts them as one function because it masks load/store offsets |
| `func_L01_003E8E10` | levels | near miss (open-rac-engine names it camera_look_springs_v) | matches in 48 of its 49 levels: level 11 adds 0x20 to the follow pointer, not 0x60; the catalogue counts them as one function because it masks `addiu` immediates |
| `func_L01_00504FE0` | levels | near miss (open-rac-engine names it hero_enter_water) | 8 words, all from one block's scheduling: at the water jump's check (state == 18) retail loads the state before the 18 (`lw $v1; addiu $v0, 18`); this loads the 18 first (sched1 issues it with the block's `addiu` address), and a `bc1f` then takes the 18 into its delay slot where retail's `bc1fl` takes the load |
| `func_001206A0` | boot_elf | PAL near miss (PR #10) | 22 diff with the file's flags: `$a1`/`$a2` swapped for the argument copy and the exponent |
| `func_L07_003328D0` | levels | level 7 (Annihilation Nation) draft | 11 differences: the three hoisted table addresses are built in another order and other registers (retail 0x2B first, in the beqz delay slot); tried locals, pointer walks and temporaries (8 wordings) |
| `func_L07_00333D70` | levels | level 7 (Annihilation Nation) draft | 15 differences: register choice in the summing loop (retail sum in $t2, base built as addu $a0,$a3,$a0) and the exit block order; tried pointer and index forms of the sum (3 wordings) |
| `func_L07_003349E8` | levels | level 7 (Annihilation Nation) draft | 9 differences, all register numbers (retail bit in $v1, index first in the addu); tried an early return, a struct member, base+offset and index+offset forms (5 wordings) |
| `func_L07_003A6EA8` | levels | level 7 (Annihilation Nation) draft | 7 differences: retail keeps arg0 in $a2 and sets the call's 0 argument in the beq delay slot; tried the callee as (void *, long|u8|s16, ...) casts (5 wordings) |
| `func_L07_003A71E8` | levels | level 7 (Annihilation Nation) draft | 7 differences, the same as func_L07_003A6EA8 (one source with another offset) |
| `func_L07_003A8D70` | levels | level 7 (Annihilation Nation) draft | 2 differences: retail sets the call's 0 argument (move $a1,$zero) before lw $a3,0x68($t0); store order found, tried casts of the callee and locals for the arguments (8 wordings) |
| `func_L07_003B3798` | levels | level 7 (Annihilation Nation) draft | 11 differences: retail copies arg0 to $v0, keeps 5 in $t0 and builds the selector as move $a1,$a3 + movn; tried a shared constant variable, a ternary and an if (4 wordings) |
| `func_L07_003B6AE8` | levels | level 7 (Annihilation Nation) draft | 10 differences: register choice (retail p in $a2, table base in $a3, 2 and 0x16 swapped between $t0/$t1); the callee reads only two arguments (6 wordings) |
| `func_L07_003BA098` | levels | level 7 (Annihilation Nation) draft | 7 differences, the same as func_L07_003A6EA8 (one source with another offset) |
| `func_L17_003B38B0` | levels | PAL near miss (PR #10) | 4 diff in level 17: order of `abs.s` against the second `sub.s`, `bc1tl` against `bc1fl` |
| `func_L06_0032E168` | levels | PAL near miss (PR #10) | 13 diff in level 6: the loop bound is loaded into `$a1` instead of `$v0` and not copied into the delay slots |
| `func_L31_003A5958` | levels | PAL near miss (PR #10) | 56 diff in level 31: order of the stores and the data pointer's register |
| `func_L17_003BE210` | levels | PAL near miss (PR #10) | 51 diff in level 17: layout of the state switch and the two forms of the D_001D545C read |
| `func_L02_003523D0` | levels | level 2 draft | register allocation only: retail loads `lw $v0,0xb8($a0)` and keeps the `lui`/`addiu` of the quadword source in `$a2`; this C uses `$v1` for `o->p` and `lui $v0; addiu $a2,$v0`. About 12 variants (do-while, while, a source-pointer local, statement order, with and without the `.extern` hint) did not move it |
| `func_L02_00351208` | levels | level 2 draft | 2 differences: in the second `if (new30 < f20)` block retail has `addiu $v0,$zero,0xff` before `move $a1,$s2`, this C the other way round; about 8 variants (store/call order, `q` versus `p + 0x160`, a `u8` temp, compare forms) did not change it. Needs `@ps2as` (already set for its file) |
| `func_L02_003F2870` | levels | level 2 draft | about 27 differences: gcc compiles the leading `if (call != 0) return 1;` as `beqz` plus a `b` to a duplicated epilogue where retail uses `bnez` with `li $v0,1` in the delay slot and one shared epilogue; the table `lui` and the 0x14 `lui` land in different registers; the loop exit falls straight into the epilogue in retail |
| `func_L02_0034F958` | levels | level 2 draft | 34 differing lines in two parts: (a) the float constants sit in `$f1..$f7` in a different order and the byte stores at 0x1d7/0x171/0x172 do not interleave as in retail (moving them re-merges the constant 1 and gets worse); (b) the tail keeps `id` in `$a1` and loads `D_001D545C` into `$a0` in retail. Needs `@ps2as` for L02_0034C9F0.c |
| `func_L02_004BE7A8` | levels | level 2 draft | 22 differences, all the prologue/epilogue: retail saves callee-saved registers with 16-byte `sq` slots in a 0xD0 frame, this compiler gives 8-byte `sd` slots in a 0x80 frame (the `sq_ra` class). Body and register allocation match; `pv = &v` kept through every use is what gives retail's `move $s2,$sp`. Levels have no `sq_ra_funcs` table, so it cannot be reached with the file's flags. Needs `@ps2as` |
| `func_L02_0034BF90` | levels | level 2 draft | 139 differences, inflated by one cause: retail loads `309.0f` into `$f2` before the first compare, copies x with `mov.s $f3,$f0` and reloads 309.0f at the join (4 more instructions, shifting every later branch); this C keeps one constant register. The argument order of `func_L01_00451FE0` (the `mov.s $f14/$f15/$f17` interleaved with `$a3/$t0..$t3`) and of the `func_L01_00456C98` calls also differ. Needs `@ps2as` and `-mvu0-use-vf0-vf2` (set for L02_003484D8.c) |
| `func_L02_0039CE20` | levels | level 2 draft | VU0: retail's case 2 adds a returned vector into `self+0x10` with `lqc2`/`vadd.xyz`/`sqc2`, which plain C cannot reach (this draft uses three `+=`, so everything after shifts). Everything else matches: dispatch, jump table (`jtbl_002BCBE0`), the other cases |
| `func_L02_0039D200` | levels | level 2 draft | 5 differences in the first five instructions of the switch dispatch: retail `lbu $v0; addiu $a0,$v0,-1; sltiu $v1,$a0,6; beqz $v1; sll $v1,$a0,2`, this C `lbu $v1; addiu $v1,$v1,-1; sltiu $v0,$v1,6; ...`. A local copy, `switch (f20 - 1)`, casts, a `default:` label and local reordering all gave the same bytes. The rest matches, including the jump table (`jtbl_002BCC00`). Uses one `goto` into the shared tail |
| `func_L02_00473410` | levels | level 2 draft | 13 differences, one cause: retail increments `i` in place (`addiu $s2,$s2,1`) and hoists `&D[i].c` / `&D[i].flag` as loop invariants in `$s0`/`$s1`; this C reproduces the hoisting and the instruction sequence (cases 0-2 as two separate bodies, flag = `bit test || call`) but gcc emits `addiu $s4,$s2,1` followed by `move $s2,$s4`, which shifts `j` to `$s3` and the flag temporary to `$s2` (retail: `j`=`$s4`, temporary=`$s3`). Same family as func_L01_0049BBD8; the `for` and `n = i + 1` shapes gave 28 differences, a `while` with `i++` ending every case gave 13. Delete the INCLUDE_RODATA line (jtbl_002BA8B0, five entries) when landing |
| `func_L02_003A2320` | levels | level 2 draft | 4 differences with `@ps2as` (set for its file): the `addiu 7` and `addiu 100` are swapped (`$v0`/`$a0`) and the `sh 0x2e` and `sw 0x20` stores are swapped; all 120 orderings of the five stores after the call, and 2520 orderings including the two stores through arg0, give the same two differences |
| `func_L02_00313B38` | levels | level 2 draft | about 208 differences, most of them one instruction shift: retail fills the `beqz` delay slot after `func_00382380(..., p->f1C, 0)` with `lhu $v0, lo(D_001A7C10)($s2)`, this C with `lui $v0`; in about seven bit-test blocks retail keeps the shift index in `$a1` and the word in `$v1` (this C `$v0`/`$a0`); near the end retail hoists `addiu $s1,$s5,lo(D_001A4BE0)` into a `bnez` delay slot. Structure, calls, frame (0x60) and constants (501.0f is 0x43FA8000) match. Needs `@ps2as` for L02_00313B38.c |
| `func_L39_005A12B8` | levels | Rebuilt from retail by the Opus family D pass (2026-11-08), from the Sonnet port of rac2 `func_L00_00300618` | 2743 of 2743 instructions, every opcode equal, 99.5% of rows equal with registers (19 words differ at level 39). Left: a `$s1`/`$s2` swap from GCSE hashing the symbol names (not reachable with address names), a `$t4`/`$t5` swap in the shrub colour average and two store positions. Needs `-mvu0-use-vf0-vf2` on the file line and include/vu0.h `fmax_asm`; listed in the file header |
| `func_L08_004D6580` | levels | Opus family A pass (2026-11-08), from the rac2-derived draft and retail | Same length as retail (5504 instructions); 97.6% of lines and 99.6% of opcodes equal retail when aligned. The hero tunables are one small-data array (D_L08_001DBC84[], docs/build/globals.md), which keeps case 0x66's loads out of delay slots. Needs `-mvu0-use-vf0-vf2` and `@ps2as` on its file, its `config/levels/divs_nops.txt` row, and include/vu0.h (qzero for the 15 `sq $0`, fabs_asm, the VU0 helpers). Left: register choice and scheduling in about ten case bodies, listed in the file header |
| `func_L04_00504520` | levels | Opus family A, port of func_L08_004D6580 plus the states Marcadia adds, written from retail (2026-11-08) | 6701 of 6695 instructions; 96.9% of lines and 99.5% of opcodes equal when aligned. Needs `-mvu0-use-vf0-vf2` and `@ps2as` on its file, include/vu0.h, its divs_nops row (with sqrt_asm for case 0x2B). Left: listed in the file header |
| `func_L09_0050E198` | levels | Opus family A, from the L04 member plus Tyhrranosis's own states, written from retail (2026-11-08) | 6421 of 6532 instructions; 94.0% of lines and 97.3% of opcodes equal when aligned. Same build needs as func_L04_00504520. Left: the b[0x1474] branches of cases 0x15/0x88, 0x7 and 0x13 (file header) |
| `func_L02_004CAF58` | levels | Opus family A, from the L09 member plus Florana's 0x76 and 0x7E, written from retail (2026-11-08) | 6671 of 6803 instructions; 92.7% of lines and 96.9% of opcodes equal when aligned. Same build needs and open items as func_L09_0050E198 |
| `func_L08_004DD0C0` | levels | Opus family C pass (2026-11-08), written case by case from retail | 3801 instructions against 3800; 94.7% of lines and 99.4% of opcodes equal retail when aligned, 115 differing rows. Needs `-mvu0-use-vf0-vf2` and `@ps2as` on its file, its `config/levels/divs_nops.txt` row, and include/vu0.h (vec_add_ab, qzero for the six `sq $0`, fabs_asm at its one abs.s). Left: register choice in state 0x80 and in the 7-group parameter blocks, listed in the file header |
| `func_L04_0050CB28` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 4161 of 4148 instructions; 91.01% of lines and 98.99% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L09_005164C0` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 3950 of 3840 instructions; 87.47% of lines and 97.58% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L02_004D36C0` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 4029 of 3999 instructions; 83.85% of lines and 95.50% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L23_004E3428` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 4659 of 4951 instructions; 78.83% of lines and 92.45% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L19_004F32A0` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 4087 of 4236 instructions; 79.46% of lines and 94.00% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L30_004CF4B0` | levels | Opus family C, ported from func_L08_004DD0C0 (2026-11-08) | 4802 of 5239 instructions; 76.58% of lines and 89.96% of opcodes equal retail when aligned. Same build needs as the root (flags, its divs_nops row, include/vu0.h). Left: the root's differences plus this level's 7-group/13-group sub-states and the draft-sourced states, listed in the file header |
| `func_L39_00656F28` | levels | Opus singleton, written from retail (2026-11-08) | 6209 of 6238 instructions; 38.7% of lines and 90.4% of opcodes equal retail when aligned (Set helpers on the docs/game/protected-values.md shape). Needs `-mvu0-use-vf0-vf2 ... @ps2as` on src/levels/shared/L39_00656DB0.c. Left: the stack layout (retail frees every statement's inline temporaries; here the 0x7D probe lands at sp+0x10), which swaps the object and s+0x19E4 registers; details in the file header |
| `func_L23_003B1490` | levels | Opus singleton, written from retail (2026-11-08) | 2030 of 2074 instructions; 53.7% of lines and 90.6% of opcodes equal retail when aligned. Needs `-mvu0-use-vf0-vf2 ... @ps2as` on L23_003AD800.c. Left: the overlapping vector stack slots (frame 0x60 in retail, 0x90 here) and the register assignment that follows from it; details in the file header |
| `func_L01_003506B8` | levels | rac4-decomp's `func_0046B4C0`, ported | 6 instruction(s) differ |
| `func_L01_00432F68` | levels | rac2-decomp's `func_L00_002D6710`, ported | 1 instruction(s) differ |
| `func_L01_00436020` | levels | rac2-decomp's `func_0029B658`, ported | 6 instruction(s) differ |
| `func_L07_004522E8` | levels | rac2-decomp's `func_L06_003660F0`, ported | 8 instruction(s) differ |
| `func_L16_004DCA98` | levels | rac2-decomp's `func_L04_003C70C8`, ported | 5 instruction(s) differ |
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
| `func_L39_004DF408` | levels | rac4-decomp's `func_L00_0051B208`, ported | 7 instruction(s) differ |
| `func_L39_004E0E98` | levels | rac4-decomp's `func_L00_0051CC98`, ported | 1 instruction(s) differ |
| `func_L39_004E2E00` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2E50` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2EA0` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2EF0` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E2F40` | levels | rac4-decomp's `func_L00_0051ED40`, ported | 1 instruction(s) differ |
| `func_L39_004E2F70` | levels | rac4-decomp's `func_L00_0051EC00`, ported | 1 instruction(s) differ |
| `func_L39_004E3028` | levels | rac4-decomp's `func_L00_0051EE28`, ported | 1 instruction(s) differ |
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
| `func_L39_00504460` | levels | rac4-decomp's `func_L00_00540270`, ported | 5 instruction(s) differ |
| `func_L39_00504488` | levels | rac4-decomp's `func_L00_00540298`, ported | 5 instruction(s) differ |
| `func_L39_005044B0` | levels | rac4-decomp's `func_L00_005402C0`, ported | 5 instruction(s) differ |
| `func_L39_005044D8` | levels | rac4-decomp's `func_L00_005402E8`, ported | 5 instruction(s) differ |
| `func_L39_00504500` | levels | rac4-decomp's `func_L00_00540310`, ported | 5 instruction(s) differ |
| `func_L39_0050C550` | levels | rac4-decomp's `func_003F8670`, ported | 6 instruction(s) differ |
| `func_L39_00515E00` | levels | rac4-decomp's `func_L00_00554600`, ported | 6 instruction(s) differ |
| `func_L39_005161F8` | levels | rac2-decomp's `func_0011FA20`, ported | 8 instruction(s) differ |
| `func_L39_00554D98` | levels | rac4-decomp's `func_00436970`, ported | 5 instruction(s) differ |
| `func_L39_00554DD8` | levels | rac4-decomp's `func_004369B0`, ported | 5 instruction(s) differ |
| `func_L39_00554E18` | levels | rac4-decomp's `func_004369F0`, ported | 5 instruction(s) differ |
| `func_L39_00557D20` | levels | rac2-decomp's `func_L00_00403CB8`, ported | 3 instruction(s) differ |
| `func_L39_0059FEF0` | levels | rac2-decomp's `func_002932B8`, ported | 1 instruction(s) differ |
| `func_L39_005ABE58` | levels | rac2-decomp's `func_002A0180`, ported | 7 instruction(s) differ |
| `func_L39_006775B8` | levels | rac4-decomp's `func_004F4E58`, ported | 4 instruction(s) differ |
| `func_L03_003AF7F0` | levels | level 3 (Starship Phoenix) draft | 6 differences: everything matches except the order of the float argument loads; retail loads $f13 and $f14 (lui $at form) first and puts the $gp load of $f12 in the jal delay slot, the C loads the $gp one first; tried locals, pointer alias, callee return types, @ps2as |
| `func_L03_003B27D0` | levels | level 3 (Starship Phoenix) draft | 6 differences: int side, lq/sq and lui forms match; only the order of the float argument loads differs (retail: $f13, $f14 via lui $at, then $f12 from $gp in the jal delay slot); locals, statement order, return type and unsized/16-byte arrays tried |
| `func_L03_003B2B30` | levels | level 3 (Starship Phoenix) draft | 6 differences: same shape and failure as func_L03_003B27D0 (callee func_L01_00450DE8); int side, lq/sq and lui forms match, only the float argument scheduling differs (retail loads $f13/$f14 first and the $gp $f12 in the jal delay slot); about 20 variants tried |
| `func_L03_003B0238` | levels | level 3 (Starship Phoenix) draft | 4 differences: retail keeps a loop copy `move $a3,$a1` that the C drops (srav reads $a1) and puts cnt-n in $v1 where the C uses $v0; do-while/for loops, separate locals, helper-style expressions all give 4 or more |
| `func_L03_003A2B48` | levels | level 3 (Starship Phoenix) draft | 5 differences: do-while over 0x50-byte entries with three null-checked stores of 0x7F; only the third pointer check differs (retail: bnel with the sb in the delay slot, then addiu; slt; gcc hoists the loop increment into the branch); inline increment, while(1)+break, continue, loading the pointers up front all tried |
| `func_L03_00395CA8` | levels | level 3 (Starship Phoenix) draft | 11 differences, prologue scheduling only (the earlier 24 were the missing @ps2as and the div.s nops, now solved by `-mvu0-use-vf0-vf2 ... @ps2as` on L03_00395808.c and the `func_L03_00395CA8 2` divs_nops row): retail puts `lw $s1,0x68($s2)` in the `jal` delay slot and loads 0x3C($s1) before the 2*pi constant, this C orders the register moves and constant differently. Registers and loop match |
| `func_L03_00397B38` | levels | level 3 (Starship Phoenix) draft | 43 differences: logic is right (bit-mask loop over six table entries) but retail reads *q twice without CSE, puts lbu in the i==0 beql delay slot and does the sllv after the join, with registers i=$6, q=$7, s=$5; the C reuses one load and hoists the sllv; continue/&&/while/do-while variants give the same bytes (about 7 compiles) |
| `func_L03_004070C8` | levels | level 3 (Starship Phoenix) draft | 16 differences: instruction sequence and count match, only register allocation differs (retail keeps the table pointer in $v1 with the lui for 0x14 and 0x2D in $v1 and the table base in $a0, and fills the first beqz delay slot with move $v0,$zero); for/while/do-while and pointer init order tried |
| `func_L03_0032CED0` | levels | level 3 (Starship Phoenix) draft | 17 differences, scheduling and register allocation: retail loads D_L03_001DFA80 (lui/lw into $v1) in the prologue before lw $s0,0x68($s1) and keeps the table pointer in $v1, the C loads it after the object field and builds the address in $a0/$a1; inline expression, local base, struct-array indexing, entry pointer and assignment inside the argument all give the same bytes |
| `func_L03_003B0088` | levels | level 3 (Starship Phoenix) draft | 40 differences: control flow and instruction count match, register allocation and scheduling differ (mask in $t2 not $t1, the s+0x160 pointer in $t1 not $t0, call argument built in $a3 and moved to $a0, sll/addiu order before the mult); about 8 variants tried |
| `func_L03_0046FF38` | levels | level 3 (Starship Phoenix) draft | 1 difference: the trailing delay-slot instruction (addiu $sp,$sp,0x20) after jr $ra is cut by the catalogue size (0xC8), so the C is one instruction longer; everything else is byte-identical (the loop over the $gp slot array); same class as func_L01_00350040 |
| `func_L03_0039EE10` | levels | level 3 (Starship Phoenix) draft | 2 differences: in the delay slot of the jal to func_L01_00448890 retail has `move $a2,$zero; jal; mov.s $f12,$f0`, the C emits `mov.s $f12,$f0; jal; move $a2,$zero`; needs @ps2as (now set on L03_0039E470.c); zero-argument type, prototype order, indexing and inlined calls tried |
| `func_L03_003A1A78` | levels | level 3 (Starship Phoenix) draft | 2 differences: retail builds the last global read as `lui $v1,%hi(D_L03_00235A00); lw $v0,%lo($v1)`, the C puts the lui in $v0; hints 4/16, u32/u8 types, unsized array and callee return types give the same 2 (or worse) |
| `func_L03_003B0140` | levels | level 3 (Starship Phoenix) draft | 12 differences, all register choices in the two blocks that call func_L03_003B2DA8 and func_L03_003B1198: the C puts `sll j,2` in $v0 where retail uses $v1 (the register that held the mask), shifting the addu/lw/sll/addu/addiu registers by one; temp, pointer, typed arr[1], split and inverted-condition variants tried (sibling func_L03_003AFFB8 has the same prologue and matched) |
| `func_L03_0032EE30` | levels | level 3 (Starship Phoenix) draft | 58 differences, register allocation only: retail keeps the raw argument in $s2 and the object field a->0x68 in $s3 and recomputes s+0xA8 and b<<2 after the calls, the C hoists b*4 into a saved register (about 12 variants: char*/base+offset/array/struct idx[1]/goto loop/header-condition loop); same loop family as func_L03_0032EF78 and func_L03_0032EB30 |
| `func_L03_0032DF60` | levels | level 3 (Starship Phoenix) draft | 11 differences: the shape and every other register match (the for loop over three entries with the func_L03_0032EB30 style walk); retail reads the loop-entry copy of the D_001DF9D8 limit with lui/lw and the back-edge copy through $gp (0x3128), the C uses $gp in both, shifting four instructions around the entry test; splitting the entry guard gives 71-92 diffs |
| `func_L03_0039E748` | levels | level 3 (Starship Phoenix) draft | 30 differences, store order only: a 32-store init of one object (the twin func_L03_003A0BF8 is the same shape); every constant, the frame and the guard match, but gcc reschedules the sb/swc1 stores and gives 0.15f/0.3f the swapped registers; a statement-order swap climb stalls at 30. Needs a permuter-style search |
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
| `func_L01_0033D2B8` | levels | rac2 `func_L01_00399170` | exact with --as ps2as; file built without it |
| `func_L01_0033D780` | levels | p2 quick win | exact at 01 with ps2as; gp slot differs in other levels (false fold) |
| `func_L01_00350750` | levels | from asm (Opus, no twin) | 2176 of 2176 opcodes equal, 2167 rows with registers: one call's argument scheduling (the D_L01_001D66B0 copy) and one `move $a0`; needs `-mvu0-use-vf0-vf2` on L01_003500B8.c and a divs_nops row (header) |
| `func_L01_00353EA0` | levels | no twin; sibling func_L01_00350750 (0.50); m2c draft (Sonnet w7) | 7,908 B, 2 switches, 21 VU0 ops: near miss only |
| `func_L01_003A0778` | levels | from asm (Opus, no twin) | 2834 of 2834 instructions, 2823 rows with registers: case 11's spilled +0x430 pointer is scheduled first; needs its own file with `-mvu0-use-vf0-vf2 ... @ps2as` (header) |
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
| `func_L01_0045B8F0` | levels | prep from asm (u128 copy) | 4 diff rows: v0/v1 swapped (address vs lq result) |
| `func_L01_0049C950` | levels | prep from rac2 `func_00130250` | 3 diff: lw of D_001D52FC scheduled after move a0 |
| `func_L01_004AD9A0` | levels | prep from rac2 `func_002E9268` (0.80) | cutscene player; draft 77% opcode-equal; needs VU0 inline asm for 5 vadd.xyz sites, frame layout, debug-skip block |
| `func_L01_004B14C8` | levels | p2 quick win | exact with @ps2as + div.s nop table (2) |
| `func_L01_004CE720` | levels | prep from rac2 `func_00335E88` | exact at 35 places; L40-53 use +0x45e4 not +0x4614 |
| `func_L01_004D2470` | levels | p2w3 port | MATCH at 01..38 places; false fold: levels 39-53 use 0x45E0 instead of 0x4610 |
| `func_L01_004D2498` | levels | draft | near miss (see the header) |
| `func_L01_00507AF8` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 5097 of 7707 opcodes equal; seed of the 0x110 dispatcher family |
| `func_L02_0034FD58` | levels | prep from rac2 `func_L19_0041C328` | matches 6 places; false fold: levels 04,08,17,22,28 use +0x2F8 |
| `func_L02_00351780` | levels | p2w2 draft | false fold: levels 08,20,28 store at +0x198 (rest +0x2D8) |
| `func_L02_003A5138` | levels | p2 quick win | matches at 02/US; false fold (offsets differ in 05,08,11,28) |
| `func_L02_00428520` | levels | VU0 block asm from rac2 twin | epilogue ld s1 hoisted between vadd and sqc2 (4 diff) |
| `func_L02_00431568` | levels | port of rac2 `func_L02_00331440` + f15/0x24 | 10 diff: single FPR swap f22/f23 |
| `func_L02_004C2BA0` | levels | from asm | gp float load comes out lui-form; store order of 25C0/25E4/BF4 and C00/C04 |
| `func_L02_004DA1D0` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 17304 vs 22620 B (4326 vs 5655 instr) |
| `func_L02_004E2118` | levels | from asm | 4 diff: store/addiu scheduling around two quadword stores |
| `func_L03_0032ED88` | levels | p2 | exact at L03, level-07 place differs by field 0x50 vs 0x60: false fold |
| `func_L03_003AAD60` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c (with jtbl) 951 lines, compile blocked by prototype conflicts; most tractable for a later Opus pass after cleanup |
| `func_L03_0040FEE8` | levels | prep from rac2 `func_00290B48` | catalogue size: delay slot of jr missing from retail size, otherwise exact |
| `func_L04_00362EF0` | levels | p2 quick win from rac2 func_L18_003F8E80 | 5 diff: result lives in $a1 then moves to $v0 (extra move, branch target 0x18) |
| `func_L04_003E5788` | levels | entity-walk template + VU0 vsub asm | 2 diff: move $a0 scheduled before sqc2 (needs j-form) |
| `func_L04_00513880` | levels | prep from rac2 `func_L20_002DEBE0` (decider family) | compiles; 0.795 opcode ratio, 21472 vs 25360 B; ~26 rac3-only states (jtbl targets listed) and the prologue locals missing |
| `func_L05_003B1BD0` | levels | from asm | exact with --as ps2as (inline float const); file flags lack @ps2as |
| `func_L06_0034A7A8` | levels | Opus giant queue, written from retail with an m2c draft, VU0 through include/vu0.h (2026-11-08) | 5042 of 5042 instructions; 99.5% of lines and 99.9% of opcodes equal when aligned (33 diff). Needs `-mvu0-use-vf0-vf2` and `@ps2as` on src/levels/shared/L06_0034A2B8.c, include/vu0.h (vec_copy), the $gp scalars' size hints (file header) |
| `func_L07_003318D8` | levels | p2 quick win from rac2 func_L04_00415EA8 | 2 diff: lui goes to $v0 then addiu $v1; retail lui $v1 directly |
| `func_L07_00331FA0` | levels | p2 quick win from rac2 func_00351EE8 | 5 diff: lw 0x18(s0) must be scheduled before the lui/lw of the table pointer |
| `func_L07_00335448` | levels | hand draft | 2 diff: lui order for the 0x150006 call args |
| `func_L07_0035CA80` | levels | prep from rac2 `func_L00_00403C30` | 3 diff: lui/move order and base reg v0 vs v1 |
| `func_L07_003AA9C0` | levels | p2 near miss 5 diff | mask -0x11 hoisted into a1 above sd s0 in retail; mine a0 after |
| `func_L07_003ACA00` | levels | p2 (not from rac2 twin) | 5 diff: mask -0x11 lands in $a0 not $a1 |
| `func_L08_003A4E60` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; not hand-written (neg); m2c fails; dossier only |
| `func_L08_004E36C0` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 20508 vs 24640 B (5127 vs 6160 instr) |
| `func_L09_00350B30` | levels | rac2 `func_L30_0040E660` | 8 diff (ps2as): arg-move scheduling |
| `func_L09_003B8580` | levels | Opus, written from retail (2026-11-08, two passes) | 3446 of 3446 instructions; 98.4% of opcodes equal retail when aligned; frame and stack slots match. Needs `-mvu0-use-vf0-vf2 ... @ps2as` on L09_003B8580.c. Left: retail addresses the 16-byte .lit vectors D_L09_001DE6A0/6B0/6D0 through $gp (seven places), which no assembler does for a 16-byte symbol under -G8; the func_L01_00448890 argument-move order; a few v0/v1 choices. The $s6 table %hi is solved (D_L09_001D66B0 in .sdata); details in the file header |
| `func_L09_003C7338` | levels | p2w3 port | MATCH at all 5 PAL places (09,18,20,24,29) but only with --as ps2as; file L09_003C5E78.c has C compiled without @ps2as, so lead must decide (flag is per file); NTSC-U differs |
| `func_L09_0051CD50` | levels | prep from rac3 seed `func_L04_00513880` (rac2 `func_L20_002DEBE0`) | decider family; seed draft renamed + own state set, 17304 vs 22344 B (4326 vs 5586 instr) |
| `func_L10_003AEE90` | levels | no twin; m2c draft (Sonnet w7) | 6,388 B, one state switch, 9 VU0 ops: near miss only |
| `func_L10_003B64C8` | levels | Opus giant queue: compiling draft, m2c with both jump tables, union style, mode switch by hand (2026-11-08) | 2025 of 2102 instructions; 53.0% of lines and 80.8% of opcodes equal when aligned; 19 m2c gotos left. Needs `@ps2as` on src/levels/10_zeldrin_starport/L10_003B5B48.c (file header) |
| `func_L14_0035CD38` | levels | from asm (sibling of L03_0032EF78) | 4 diff: p++ delay-slot placement in the 0x1699/0x16CA dispatch |
| `func_L16_003C9768` | levels | no twin; m2c draft (Sonnet w7) | 7,348 B, 3 switches, 12 VU0 ops: near miss only |
| `func_L19_00302998` | levels | prep from rac2 `func_L01_00390A50` | one extra nop from do{}while(0) forced-flag block; without it s3/s4 swap |
| `func_L19_00335748` | levels | prep from rac2 `func_L03_004197C8` | 4 diff: epilogue ld order around sqc2 (needs j-form VU0 statements) |
| `func_L19_00336100` | levels | VU0 block asm from rac2 twin | j++ addiu must sit between vsub and sqc2 (one moved insn, 7 rows); needs j-form (flag absent) |
| `func_L19_003556D0` | levels | wave4 VU0 blocks | 4 diff: ld $s1 hoisted between vadd and sqc2 in retail |
| `func_L19_003AFCB0` | levels | no twin; m2c draft (Sonnet w7) | 6,784 B, 4 switches, 6 VU0 ops: near miss only |
| `func_L19_004F9D80` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 4778 of 7251 opcodes equal; differs from the seed by blocks listed in the header |
| `func_L20_003AF880` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L20_003D0910` | levels | Opus giant queue, written from retail with an m2c draft (2026-11-08); no twin (states 16/23/29 are three copies of one charge/burst routine) | 5549 of 5560 instructions; 94.8% of lines and 97.4% of opcodes equal when aligned. Needs `-mvu0-use-vf0-vf2` and `@ps2as` on src/levels/20_final_boss/L20_003CE2D0.c, include/vu0.h, the $gp scalars' size hints (file header) |
| `func_L20_003DFF98` | levels | rac2 `func_L00_00322EC8` | loop right; 8 diff prologue/delay slot |
| `func_L20_003EE6B8` | levels | p2 near miss 5 diff | flag test D_00142C58&0x2000000; retail schedules lw after addiu sp, mask in a1 |
| `func_L20_003FB6A8` | levels | Opus giant queue, written from retail with an m2c draft (2026-11-08); 0.64 to func_L05_003560C8 | 2638 of 2640 instructions; 98.0% of lines and 99.1% of opcodes equal when aligned. Left: about 45 rows of scheduling and allocation in states 9, 10, 13, 16 and 18 (file header). Needs `@ps2as` on src/levels/20_final_boss/L20_003FB630.c, include/vu0.h `fabs_asm`, the $gp scalars' size hints |
| `func_L20_003FEDF0` | levels | rac2 `func_L02_003CD8C0` | 2 diff: base reg a0 vs v1 |
| `func_L20_004024E8` | levels | from asm (ps2as) | stack Params struct; const-1 register sharing / early schedule of arg setup differs |
| `func_L20_0048FF30` | levels | hand port from retail asm + rac2 func_002C6868 | ps2as; s-reg numbering swap (self/ctl), 24 diff |
| `func_L20_0053FFD8` | levels | p2 quick win from rac2 func_L02_003D69F0 (not really) | 1 diff: only diff is the trailing delay-slot addiu sp that retail keeps in the LINKER_REMNANT at 00540000; body matches |
| `func_L21_00339088` | levels | rac2 `func_L20_00442E68` | 2 diff: reg of loaded base pointer (a0 vs v1) |
| `func_L21_003A8050` | levels | no twin; m2c draft (Sonnet w7) | 6,036 B boss update, 3 switches, 3 VU0 ops: near miss only |
| `func_L22_003B3228` | levels | no twin; m2c draft (Sonnet w7) | 11,472 B, 2 switches, 12 VU0 ops: near miss only |
| `func_L23_003A8028` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; no switch, float+random code; m2c fails on delay-slot label; dossier only |
| `func_L23_003AD800` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L23_003D8628` | levels | prep from rac2 `func_L02_002DCEA0` | exact modulo 2 nops before div.s; ps2as |
| `func_L23_004C2CE8` | levels | rac2 `func_L22_002AA480` | divs_nops (2 nops before each div.s) + a1/v1 swap in anim index |
| `func_L23_004EAE60` | levels | prep from rac2 `func_L22_002D0C98` | draft compiles, 5227 of 8405 opcodes equal; differs from the seed by blocks listed in the header |
| `func_L24_00351448` | levels | level 24 (Insomniac Museum) draft | 4 differences: two adjacent store pairs in the state initialisation are in the other order (retail `sw $s6,0x10` before `swc1 $f22,0x20`; `swc1 $f20,0x14` before the jal); registers and frame match. All 50 single-statement moves in the store group tried |
| `func_L24_00352060` | levels | Opus giant queue: m2c on retail with both jump tables, union style, VU0 through include/vu0.h, gotos written out (2026-11-08) | 2617 of 2617 instructions; 99.5% of lines and 99.7% of opcodes equal when aligned (65 diff). Needs `-mvu0-use-vf0-vf2` and `@ps2as` on src/levels/24_insomniac_museum/L24_003519E8.c (file header) |
| `func_L28_00309CE8` | levels | prep from rac2 `func_L08_003DB8E8` | one extra lui+lw reload of D_L28_001DE840 in the arm block (shift only) |
| `func_L30_004D7368` | levels | prep from rac2 `func_L20_002DEBE0` | draft compiles, 5058 of 8822 opcodes equal; differs from the seed by blocks listed in the header |
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
| `func_L39_005A5F48` | levels | prep from rac2 `func_002D7B00` | lw/lui scheduling and reg (v0/v1 vs a0/v1), 5 diff |
| `func_L39_005A61D8` | levels | prep from rac2 `func_00298F00` (0.86), API draft | memory-card state machine; draft 98.9% opcode-equal (+12 instr): tail-merge, scheduling and loop-inversion hunks |
| `func_L39_005B25C8` | levels | no twin found (part3 best < 0.35, callee overlap none) | hand-written assembly (scratchpad save, addi, DMA regs); not C |
| `func_L39_005C8CA8` | levels | prep from rac2 `func_002BDBC0` | exact with --as ps2as except missing nop;nop before div.s (divs_nops) |
| `func_L39_005CA8B0` | levels | from asm, needs `--as ps2as` | 4 diff: register/schedule of the D_L39_002968A0 pointer load (lui $a2 vs $v0) |
| `func_L39_005D2930` | levels | rac2 `func_L00_0033FFB8` | 7 diff: lui of D_L39_002969A4 scheduled later ($v1 vs $a0); needs --as ps2as |
| `func_L39_005E3A10` | levels | prep from rac2 `func_L14_003DE990` | 2 diff: sll/addiu order before memset call |
| `func_L39_00602010` | levels | rac2 `func_00336CE8` | 10 diff: s0/s1 swap, bnez loop end |
| `func_L39_00608FE0` | levels | p2 quick win from rac2 func_003501E0 | 4 diff: needs --as ps2as; scheduler puts ld $ra before the two lui $at stores, retail interleaves |
| `func_L39_0060FDB0` | levels | prep (static-init idiom) | matches level 39; levels 40-53 differ in gp offsets (false fold) |
| `func_L39_00624658` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; m2c compiles to 19 type errors (ring buffer); best tractable of the no-twin set |
| `func_L39_00632328` | levels | prep from rac2 `func_L00_002D3C68` | mode byte test: retail lbu+bltz+slti, we get lb+andi+sltiu |
| `func_L39_00640738` | levels | Opus shared20, from the Sonnet prep (2026-11-08) | 3238 of 3242 instructions; 95.8% of lines and 99.3% of opcodes equal retail when aligned, 1021 rows differ in the stock checker (was 3140), 24 opcode-diff regions. Needs `@ps2as` on src/levels/shared/L39_0063E9E8.c. The Set handle copy is solved (docs/game/protected-values.md); variable-value Sets write buf.w[0] first, and the player struct is 16-byte aligned (address forms). Left: a recomputed handle address, branch-likely choices and the final ClrA, details in the file header |
| `func_L39_00648C20` | levels | no twin found (part3 best < 0.35, callee overlap none) | no twin; 148-entry/27-target switch; m2c fails; dossier only |
| `func_L39_0064EA40` | levels | Opus singleton, written from retail (2026-11-08); Fable pass 2026-11-09 | 8414 of 8412 instructions; 72 opcode-diff regions (was 93), 4397 rows differ in the stock checker (was 5997). Needs @ps2as. The s2/s3 swap is solved (n, t, f are block locals), as are 0x7D's cvt.s.w and the signed Dec compares. Left: &D_L39_00246018 hoisted whole, the store order of the 0x14A8-0x153C blocks (sched1 weights, see the file header), the tail's Dec buffer; details in the file header |
| `func_L39_0066C7D8` | levels | prep from rac2 `func_L00_003B9CB8` (weak) | table lookup; needs --mode S --as ps2as, 2 diff (sll/lui order) |
| `func_L39_0067ED40` | levels | re-derived from asm | 3 diff: lw a1 / move a0,v0 order before final jal |
| `func_L39_00687450` | levels | from asm | 7 diff: s3/s4 swap, clamp movn vs movz |
| `func_L40_0040D310` | levels | p2w3 port | structure ported from asm (twin func_002B50E0); retail reads one global (0x24112C) in both gp form and lui form within the function; single-declaration C gives one form, so ~60 diff; no clean C form found |
| `func_L40_0041B9F0` | levels | prep, no twin (opcode < 0.3) | m2c draft only, not compiling; COP2 blocks |
| `func_L39_0050DBB0` | levels | rac4-decomp's func_0040B730 | 4 diff: use unsigned long (u64 is 128-bit); ldl/ldr/sdl/sdr right but value reg $v1 vs retail $v0; 5 wordings same |
| `func_L39_0066C748` | levels | rac4-decomp's func_L00_006F55E8 | 9 diff: 72-byte struct fixes mult const (sra 3); remaining only reg alloc/sched (addr lui $v1, mult $ac3 vs $ac2) |
| `func_L39_0066DA10` | levels | rac4-decomp's func_005407D8 | donor global address wrong: retail reads D_001A5CD8 (lui 0x1a/0x5cd8), not D_00172170; remaining 14 diff are saved-register numbering (retail s1=a2&ff, s2=a3&ff, s3=a1 copied late; ours s1=a1) and lui/lw placement; ~9 tries |
| `func_L39_00609FF8` | levels | rac4-decomp's func_004F1618 | HW-ADDR: retail writes DMA regs 0x1000B420/B410/B430 via lui/ori constants; honest extern symbols go via $gp, only forbidden hardcoded (volatile) addresses can produce it; not attempted further |
| `func_L39_004D4700` | levels | rac4-decomp's func_L00_00510500 | SIBCALL (retail ld ra; j func_L39_004D1DC8) |
| `func_L39_004D0D68` | levels | rac4-decomp's func_003F6470 | 11 diff: retail keeps b copy in a3 and recomputes b+i (no strength reduction); 8 wordings same bytes |
| `func_L01_00439A98` | levels | rac2-decomp's func_0029F840 | VU0: retail uses COP2 (4 words lqc2/vmul-style .word 0x4bc20868 etc.) plus lq vs ld; plain C cannot produce |
| `func_L39_00505718` | levels | rac4-decomp's func_L00_00541528 | 16 diff: library-style 16-byte sd save slots (frame 0x50) vs our 8-byte slots; body equal |
| `func_L39_0066D9A8` | levels | rac4-decomp's func_00540770 | global is a scalar s32 (not array) w/ size hint 16 gives lui/lw; remaining: retail fills beqz delay slot with hoisted lui and shares epilogue, ours uses beql+duplicated ld; early-return and nested forms both tried |
| `func_L39_005D6408` | levels | rac4-decomp's func_L00_0061DAA8 | size hint on D_L39_002429AE gives retail lui/lbu; remaining: retail does the final store via lui $at/sw absolute while ours uses $gp for D_002413A8 (same symbol read via $gp); 3 tries incl. hint 4 |
| `func_L39_004BBEB8` | levels | rac4-decomp's func_L00_004F8268 | 1 diff: retail has stray extra word addiu sp,sp,0x50 after the epilogue (past jr delay slot); all else equal; not producible |
| `func_L39_005ABFE8` | levels | rac2-decomp's func_002A0300 | GP-SLOT: level 39 matches (D_001E0848_sda, .extern hint on D_L39_0024BF58, unsigned long arg) but levels 40-53 use gp slot 0x498 vs 0x3f98: 1 diff each |
| `func_L39_005C2A40` | levels | rac2-decomp's func_002B7C10 | 11 diff: all ops right (size hints on D_002256A0/D_L39_002410E4/D_L39_00240428, _sda gp slot); register allocation of the CdMode copy and lui order differ after 8 variants |
| `func_L19_003357A0` | levels | rac2-decomp's func_L03_0038AA20 | flags: donor C unchanged; retail builds f32 constants inline (lui/ori/mtc1) which needs the @ps2as marker on src/levels/shared/L19_003357A0.c in config/levels/text_parts.txt (currently no marker); file holds INCLUDE_ASM stubs perhaps so needs its own single-function range |
| `func_L39_005A5010` | levels | rac2-decomp's func_00298178 | flags: needs @ps2as on src/levels/shared/L39_005A5000.c in text_parts.txt (retail mixes lui-read and gp-store of D_L39_0024BE74); source: no flags local, D_001D4CE8_sda sdata, size hints on 4 L39 globals, fields f08/f10/f24/f16c |
| `func_L39_0066D938` | levels | rac4-decomp's func_00540700 | global base reg: ours $a2 lui after sb + beql, retail $v0 lui in beqz delay slot; 6 variants (struct/array/local/hint/early return) same |
| `func_L39_005EDE28` | levels | rac2-decomp's func_002E11C0 | GP-SLOT: matches level_39 exactly (D_001E13C0_sda store, .extern 16 hints, front-end callee names); levels 40-53 differ by 1 instr only: store disp 0x1020($gp) vs L39 0x4b10 |
| `func_L39_00672118` | levels | rac4-decomp's func_00546940 | case order/values recovered from jtbl (3,1,2,4,5,6,9,7,10 -> 0..8, 8 default; blocks match) but switch index reg: ours reuses $a0 for value-1 and sll before lui, retail keeps $a0 and uses $v1/$a0 for table load; 5 variants same |
| `func_L39_004E4BE0` | levels | rac4-decomp's func_L00_005209E0 | 16-byte save slots (frame 0x60, s0-s3/ra at 0x10..0x50) vs our 0x30 packed frame; logic/regs otherwise same (s1=&record hoisted) |
| `func_L39_0059D6B0` | levels | rac2-decomp's func_0028F948 | GP-SLOT: exact in level_39 (D_L39_0024CAD0 int* read + D_001E13C0_sda int* write, .extern 16 hint); levels 40-53 differ in only 3 instrs, the $gp disp of D_001E13C0 (0x4b10 in L39, 0x1020 elsewhere) |
| `func_L39_0067A6D0` | levels | rac4-decomp's func_00546940 | switch with retail jtbl order (3,1,2,4,5,6,9,7,10 -> results 0..8; 8 default); u8 param gives 9 diff: index reg (addiu $v1 vs in-place $a0) and lui/sll order of table address; known switch dispatch-register blocker |
| `func_L01_00438EA0` | levels | rac2-decomp's func_L00_00310048 | only diff: retail stores the increment via lui $at/sw -0xc0 (non-gp) while init store and loads use gp 0x3690; one extra instruction shifts the rest; .extern hints for E0020/E0024/FB40 fixed the rest |
| `func_L39_00584568` | levels | rac2-decomp's func_00278EB0 | gp/lui fixed with .extern hints (5 globals), z is D_L39_0024CAD8 (non-gp), D_L39_001E13C8 sdata, f26=0 store dropped (retail has none); remaining: scheduler loads D_L39_0024CAD8 after x/y (retail right after counter) -> register assignment a3/t0/t1 vs v1; 6 variants no change |
| `func_L01_0045BB60` | levels | rac2-decomp's func_002B5EF8 | retail builds 1.5707964f inline (lui/ori/mtc1) which needs @ps2as; file src/levels/shared/L01_0045A6F0.c has no @ps2as (default as gives a .lit4/gp load); with --as ps2as (information only) 71 diff: constant fixed (1.5707964f not ...965) but retail has 2 nops after the mtc1 before div.s that we do n |
| `func_L39_004FC4B8` | levels | rac4-decomp's func_L00_005382C8 | 16-byte save-slot frame (0x50, sd at 0x10/0x20/0x30/0x40) plus lui $v0 reuse for D_L39_0046EA50; structure otherwise identical |
| `func_L39_006095C8` | levels | rac4-decomp's func_004F0BE8 | needs hardware register addresses (0x1000F590/F520/B000) and volatile; forbidden constructs; not attempted |
| `func_L39_004FC448` | levels | rac4-decomp's func_L00_00538258 | SIBCALL (ld regs; j func_L39_004BEF28; addiu $sp) and 16-byte save slots; not attempted |
| `func_L39_0060B4C8` | levels | rac4-decomp's func_004F3800 | shared $gp function; retail reads the counter via $gp (hoisted into the beqz delay slot) on one path and via lui/lw 0x24112C on the other, stores via lui $at; a single declaration cannot produce both (GP-SLOT-like); 3 wordings tried |
| `func_L24_00402808` | levels | rac2-decomp's func_L08_00300100 | flags: needs @ps2as (inline lui/ori/mtc1 float const); file L24_00402798.c has default as (10 diff); must be split into its own file with @ps2as like config/*/text_parts.txt entries. C: D_L24_001E6DF0[0] = 0.62f; func_003873C0(); |
| `func_L39_005FD368` | levels | rac4-decomp's func_004E7CB0 | level_39 place is an exact MATCH; the other 14 places differ by 2 (jal target 0x45d5d0 vs 0x590360, and $gp slot 0x1020 vs 0x4b10): per-level callee and sda slot, GP-SLOT-like; needs level aliases for callee and slot |
| `func_L01_0033DED0` | levels | rac2-decomp's func_003169D0 | flags: needs @ps2as for inline lui/ori/mtc1 float constants (default as puts them in .lit4 via $gp); struct array Ent[3] stride 0xA0, key at 0x8C, flag at 0x94, obj at 0x30. Same shape as other @ps2as files in text_parts |
| `func_L01_00415A58` | levels | rac2-decomp's func_00285548 | flags: start_c unchanged (sync23/out3 file) matches under @ps2as (64-bit constants via ori/dsll32 and mixed lui/gp access are ps2as output); file flags need @ps2as. C could be tidied but is checker-verified as is |
| `func_L39_004DB0D8` | levels | rac4-decomp's func_L00_00516ED8 | FILL-ONLY: all code words equal; array externs D_..[] used as [0], no hint |
| `func_L39_004FAC00` | levels | rac4-decomp's func_L00_00536A10 | SIBCALL (j func_004BEF28 tail call) |
| `func_L39_004FA228` | levels | rac4-decomp's func_L00_00536038 | SQ_RA 0x20 frame (ra at 0x10) plus state in $v1/beql shape; C gives 0x10 frame |
| `func_L01_0042D9C0` | levels | rac2-decomp's func_00294D80 | 2 instrs: constant bit63 synthesised ori 0x8000;dsll32 16 vs retail addiu -1;dsll32 31 (8 spellings fold the same); rest exact incl. D_L01_001DF97C with .extern hint 16 and D_L01_001E7880[]; all 34 places show same 2 diff |
| `func_L01_00430118` | levels | rac2-decomp's func_L00_003080D0 | compiles; retail has extra gp byte early-return (.extern D_001D71E8,1 + sdata), 6th arg -1 to func_L01_004316B0, mask at +0x390; still 0x10 smaller frame (one fewer spilled local) and base ptr kept in s2/s7 differently; register-allocation level, stopped |
| `func_L39_004DB040` | levels | rac4-decomp's func_L00_00516E40 | SQ_RA 16-byte slots (frame 0x30, ra 0x20); callee is func_L39_004DAAB0 (jal masked); body otherwise equal |
| `func_L39_004DB168` | levels | rac4-decomp's func_L00_00516F68 | SIBCALL (tail j func_L00_004BEF28) + SQ_RA |
| `func_L39_004C3DC0` | levels | rac4-decomp's func_L00_004FFBC0 | SQ_RA frame/save order only (u64 flag read as long OK); callee func_L39_004C4EE0 by address |
| `func_L39_004DD250` | levels | rac4-decomp's func_L00_00519050 | SIBCALL (tail j func_L00_004BEF28) + SQ_RA; global is lui 0x47 +0x6270 (D_00476270 by address) |
| `func_L02_003C5C48` | levels | rac2-decomp's func_L06_0047AC68 | structure right (donor shape, u16 tag, D_001A71C4 as u8[], context decls); gcc CSEs the sll of tag and adds move $a2,$v0 where retail recomputes sll at each use: one extra insn shifts rest |
| `func_L01_00421738` | levels | rac2-decomp's func_0028FC48 | flags: Only 64-bit constant synthesis (ori/dsll32 form) needs the assembler @ps2as; file src/levels/shared/L01_00421730.c lacks it in config/levels/text_parts.txt (sibling L01_004208C8.c has it). Alias D_L01_001E1068 (+ .extern 16 hint) for lui accesses, D_L01_001E1068_sda for the final $gp store, D_001D4B |
| `func_L39_005BC798` | levels | rac2-decomp's func_L04_00347AB8 | SQRT: retail has inline sqrt.s (func_0038D160(d, sqrt(1-d*d))), unreachable in plain C without -ffast-math/asm; also frame/stack slot layout differs (retail 0x180 frame, locals at 0x00/0x40/0x80/0xa0/0xc0/0xd0/0xe0); real callees are core funcs 0038D570/0038CE68/0038D160(y,x)/0038CE90/0038D348/0038D |
| `func_L39_004F40C8` | levels | rac4-decomp's func_L00_0052FEC8 | SIBCALL: retail ends with ld ra; ld s0; j func_004BEF28 (0x20 frame) |
| `func_L19_00356030` | levels | rac2-decomp's func_L03_00419C00 | flags: retail builds 0.1f inline (lui/ori/mtc1) = needs @ps2as for src/levels/shared/L19_003553A0.c (its flags have none); also file context line 111 declares extern void func_L19_00356030(s32) which must become the 3-arg s32 prototype |
| `func_L03_00348C18` | levels | rac2-decomp's func_L30_00413528 | (19 at level_03) 64-slot register-menu add; all stores/loads right, only loop pointer register assignment differs (retail a0=DA0,v1=EA0,t3=FA0,t2=i; ours t2,a0,v1,t3); 8 wordings tried. Uses new extern char *D_L03_00281EA0[]; file decls DA0=s32*[] FA0=s32[][2] and u8 001E13C8[] |
| `func_L39_004CBA18` | levels | rac4-decomp's func_L00_00507818 | SQ_RA/16-byte save slots (retail frame 0x40: s0@0,s1@0x10,s2@0x20,ra@0x30; ours 0x20 with 8-byte slots) + a3/a0/a1 arg-set order around the first jal; calls right: func_L39_004BECC0, func_L39_004CBAA8, D_L39_00475EE8 |
| `func_L01_0045D158` | levels | rac2-decomp's func_002B63C0 | (checked with --no-context at level_01 since the clone src/levels/shared/L01_0045A6F0.c context is broken: duplicate M_4574A0/S_4574A0/func_L01_0045B958 typedefs, line 111 giant cast chain) only diff: shared-tail b displacement 0x24 vs 0x20 (assembler puts the c.lt hazard nop before the label; retai |
| `func_L05_0047FF20` | levels | level 5 (Daxx) draft | 1 difference: needs @ps2as and the divs_nops row "func_L05_0047FF20 2 0 2"; with them every instruction matches (the clamp in `do { } while (0)` gives retail's saved FP registers), and the one difference left is the catalogue size: it gives 0x11C bytes and puts a LINKER_REMNANT (func_0048003C) on the function's own jr delay slot, so the C (0x120 bytes) shifts the next function; same class as func_L01_00350040 |
| `func_L05_003E63C0` | levels | level 5 (Daxx) draft | 10 differences: an `int off = idx * 0x460;` local puts the mult in $a0 and the lq source as addu + lq 0x190; left: gcc folds the +0x50 of the ship load into the base (addiu 0x2750) where retail keeps the 0x2700 base in $t0 and loads lw 0x50 after an addu |
| `func_L05_003DC5B8` | levels | level 5 (Daxx) draft | 2 differences: needs the divs_nops row "func_L05_003DC5B8 2"; func_L01_00451FE0 declared with the parameter order other files already use fixes the first call; left: in the second call retail stores the stack argument 0x608020 (sw $a0,0x40($sp)) before lui $v0,0x100, ours the reverse (a scheduler tie; 512 prototype orders of func_L01_003303B8 and about 20 wordings tried) |
| `func_L04_003ECE58` | levels | level 4 (Marcadia) draft | 7 differences: scheduling: the store of the 10th argument (sw $v0,8($sp)) and sw $zero,0($sp) come earlier than retail |
| `func_L04_004AC5A0` | levels | level 4 (Marcadia) draft | 28 differences: remaining counter copies and inner boolean register; regular loop increment fixes outer counter allocation |
| `func_L04_003CE348` | levels | level 4 (Marcadia) historical draft | Resolved in src/: TImode source load before a narrow store and repeated-constant store grouping |
| `func_L04_00366AC8` | levels | level 4 (Marcadia) historical draft | Resolved in src/: GP float local, repeated-constant store order and vector copies before the state flag |
| `func_L04_003E5250` | levels | level 4 (Marcadia) historical draft | Resolved in src/: block-local old values, postfix increment and small-data address declaration |
| `func_L04_00434098` | levels | level 4 (Marcadia) draft | 37 differences with @ps2as: prologue/base scheduling, saved registers and inner-loop initialization |
| `func_L01_005063E8` | levels | near miss (open-rac-engine names it hero_walk_anim) | 159 lines (~45 of 270 words structurally): mode 3 arm's load order and the prologue's `lui` copy to `$s1`; the inner `if (below)` comes out `li`/`bne` where retail has `beqz`; the up loop is strength-reduced; `$a2`/`$a3` swapped in the keyframe maths. Needs `func_L01_005063E8 2` in config/levels/divs_nops.txt once it matches |
| `func_L01_005138F8` | levels | near miss (open-rac-engine names it xp_level_check) | 178 lines (343 of 382 align structurally): retail's branchy `u8` ok value with a join and a kept `is_weapon` re-test (gcc folds both); a `sw` to `D_L01_001DFD38` in a `b` delay slot becomes a `$gp` store; loop hoists; registers one off at the top |
| `func_L01_0050FF00` | levels | near miss (open-rac-engine names it hero_anim_update) | 337 lines positionally, ~26 words structurally, one cause: retail keeps 0.0 in `$f22` for the keyframe-time store (frame 0x90); gcc's loop pass folds it to `sw $zero` (frame 0x80), renumbering `$f21`-`$f24`. Needs `func_L01_0050FF00 1` in config/levels/divs_nops.txt once it matches |
| `func_L01_004EBDA8` | levels | near miss (open-rac-engine names it hero_place_item_mobys) | 386 lines positionally, ~96 instructions aligned, 22 ignoring register names: frame, spill slots and control flow agree; the fp-loop preheader schedule (`sp+0x10` before the `mtlo`), the body-start temporaries' registers and the loop-tail delay slots differ. Calls func_L01_004E9270/9298/92C0 through `_004EBDA8` aliases (the file defines them `(void)`) |
| `func_L01_005055A0` | levels | near miss (open-rac-engine names it hero_attack_start) | 780 lines positionally, but 786 of 829 instructions agree ignoring registers: the hero base is kept in one saved register where retail rebuilds it three times (shifting every register); both 0.1/0.57 apex-threshold if/else arms are converted to `x = b; if (c) x = a`; the clamp to 12 is `movn` from a temporary where retail has `movz` into `$a1` |
| `func_L01_004E9FB0` | levels | near miss (open-rac-engine names it hero_hold_layers_update) | 305 lines positionally, ~67 aligned: frame, saved registers (hero in `$fp`, i in `$s7`) and both arms' layout agree; the k-loops swap the counter and the 0x600 pointer between `$t0`/`$a3` and lack retail's alignment nop; temp register names; retail rebuilds the hero base in the changed block; spill slots for `i+1` and the anim pointer swapped |
| `func_L32_003A2508` | levels | Haiku pass (2026-11-12) | MATCH under `--as ps2as` with -mvu0-use-vf0-vf2, but L32_003A0BB8.c must stay on the default assembler for func_L32_003A0BB8 and func_L32_003A3E70; see the file header |
| `func_L32_003BE4E8` | levels | Haiku pass (2026-11-12) | MATCH under `--as ps2as`, but L32_003BE008.c must stay on the default assembler for func_L32_003BED60; see the file header |
| `func_L18_0042D0F0` | levels | level 18 draft | 15 differences (about 10 lines apart): retail keeps the table pointer in `$v1` with the table's `lui` in the first test's delay slot and `move $v0,$zero` in the second test's delay slot; this C puts the pointer in `$a0`. A result variable, a hoisted `u8 *` base and a for-loop were tried |
| `func_L22_003BC778` | levels | hand match (Sonnet), level 22 | 99 diff: logic follows retail (all branches present), but gcc keeps one more value in a callee-saved register (frame 0x30 vs 0x20, extra $s3) and folds D_001A4BE0+0x35C into one lui/lw where retail builds hi/lo apart ($17 holds the hi half for later); needs @ps2as only if the file is made ps2as, default flags otherwise |
| `func_L22_004A32D0` | levels | hand match (Sonnet), level 22 | 13 diff: the 0x260 flag-table update family (see func_L28_00464BF0): with i++ in place in each case it is 13 diff; left: case 1 increments i first in retail and keeps the list index in $s4/$s3 where gcc swaps them; plain default flags |
| `func_L28_003420C0` | levels | hand match (Sonnet), level 28 | 21 diff: all instructions in retail's order, but gcc turns the two small ifs of the nibble test into movn/movz (n++ and the h&1 shift) where retail has branches (beql/beqz), the u8 local that stops one of them makes it srl instead of sra, and p/h swap $a3/$a2; needs @ps2as for the file (inline float-free but the $gp global D_001DCF18 is written before the loop) |
| `func_L28_003A0930` | levels | hand match (Sonnet), level 28 | 7 diff: every instruction is right; only the order of the ten float stores into the state block differs (the scheduler puts 194/74/7C after 80/A0/9C where retail has them first); the file is already @ps2as; four store orders and a local per constant tried; its signature must be (void *) because func_L28_003A0708's block declares it |
| `func_L28_00464BF0` | levels | hand match (Sonnet), level 28 | 13 diff: the 0x260 flag-table update family (levels 13, 26, 29, 31 too): with i++ in place in each case it is 13 diff (was 28 with n = i + 1; i = n); left: case 1 increments i first in retail and keeps the list index in $s4/$s3 where gcc swaps them; plain default flags |
| `func_L27_003A3310` | levels | level 27 draft | 2 differences, needs `@ps2as` (inline float constants; the file L27_003A1250.c still has INCLUDE_ASM neighbours): in the second of two identical blocks retail loads `p+0x158` first and puts the `p+0x150` load in the `jal func_0038DBD8` delay slot, block 1 has the opposite order which this C gives; temps, statement order and a struct-typed pointer did not move it |
| `func_L27_003A43A8` | levels | level 27 draft | 9 differences, needs `@ps2as` (inline `1.1f`): the four `beq` of the `0x1A4E`/`0x1AA0`/`0x1BD3`/`0x16BE`/`0x1BA0` chain jump back to the first block's `b; addiu v0,1` tail (cross-jumped return 1) where retail jumps to its own return-1 block, and retail holds `D_L27_001E83C0.f18` in `$a0` with a plain `beqz` where this C has `$v1` and `beql` |
| `func_L27_00473230` | levels | level 27 draft | 107 differences, one cause (saved-register assignment): the table walk of `func_L27_00474338` with `bit || func_L01_0041A4F0()` flags; retail gives `i` `$s2` and keeps `&entry` and `&entry.c` of case 1 in independent `$s1`/`$s0`, this C gives `i` `$s4` (about 9 wordings: pointer locals, `i - 1`, order of declarations) |
| `func_L27_003A2B98` | levels | level 27 draft | 27 differences from one register swap: retail keeps the `D_L27_001DED1C` entry of `d->f0` in `$s0` and the one of `d->f4` in `$s1` (reusing the table pointer register), this C gives them the other way round; needs the VU0 flag line + `@ps2as` on L27_003A1250.c (already set for func_L27_003A2E08) and `vu0.h` |
| `func_L14_003539E0` | levels | level 14 (Koros) draft | 71 diff: needs the divs_nops row "func_L14_003539E0 2" (file already VU0 + @ps2as); D_L14_001D66B0_v is a second name for the address at vector type (resolve_symbols row needed); logic complete; left: FP register allocation (retail keeps t in $f20, 1.0f in $f21, 1.1f in $f22; ours gives 1.0f $f20, t $f22) and the absolute lqc2 of D_001D66B0 through $at |
| `func_L14_00354C28` | levels | level 14 (Koros) draft | 10 diff: file already @ps2as; left: order of the argument moves for func_L01_00451FE0 (retail interleaves mov.s $f14/$f15/$f17 with the integer li's and the two stack stores, ours groups the li's first); the same call matches in func_L01_003B1DC0, so this is a scheduling tie, not the prototype |
| `func_L14_0035CA60` | levels | level 14 (Koros) draft | 55 diff: needs the VU0 + @ps2as set on L14_0035C810.c (with .extern hints added to func_L14_0035CBA0's gp variables) and the divs_nops row "func_L14_0035CA60 2"; the logic is complete; left: float load scheduling, retail loads D_001DD6CC (const) after the multiplies, ours hoists it ahead of the second vec_add; the second block is a copy of the first |
| `func_L14_0035D490` | levels | level 14 (Koros) draft | 8 diff: needs @ps2as on L14_0035D490.c; left: (1) sw $v0,8($sp) comes before mov.s $f17,$f16 in ours, after it in retail; (2) the D_L14_001D67B8 counter: retail loads it into $v1 and compares into $v0, ours the reverse (n local, ++, +=, > 99 wordings tried; the same pattern matches in func_L14_00354C28's counter shape only by luck of allocation) |
| `func_L14_0035D590` | levels | level 14 (Koros) draft | 8 diff: sibling of func_L14_0035D490 (needs @ps2as on its file), same two differences: stack-store/mov.s order and the D_L14_001D67B8 counter registers |
| `func_L14_00361F40` | levels | level 14 (Koros) draft | 10 diff: only register naming; the lw of the object pointer should be $v1 and the +0x20 pointer $a0 (ours the reverse); about 9 wordings tried (declaration order, struct types, one pointer) |
| `func_L14_00362B68` | levels | level 14 (Koros) draft | 14 diff: needs @ps2as on L14_003622D0.c (inline 1.0f) and the divs_nops row "func_L14_00362B68 2"; left: loop registers/order, retail keeps the counter in $v0, the D_001E1220 pointer in $v1 and the D_001E1224 pointer in $a0 (address of 1224 computed first), ours counter $a0, 1224 pointer $v0; index, pointer, do-while and struct wordings tried |
| `func_L14_00362C28` | levels | level 14 (Koros) draft | 17 diff: needs @ps2as on L14_003622D0.c (the 64-bit constants as ori/dsll/ori); D_L14_001E1220_b is a second name for the same address (resolve_symbols row needed) so the address is rebuilt for the second call; left: the order of the argument moves before the calls (retail a2,a3,a0,a1 in the first call, a0..a3 in the second; ours a3,a2,...) and the 1200/1220 lui order |
| `func_L14_003AD768` | levels | level 14 (Koros) draft | 3 diff: file is already @ps2as; left: the loop-bottom reload of s->pC (lw/slt/bnel) uses $v1 in retail, $v0 in ours; not tried further |
| `func_L14_004047D8` | levels | level 14 (Koros) draft | 20 diff: same logic and block order as retail; left: retail merges the early return-1 into the epilogue (bnez to the end, v0=1 in the slot) and returns 0 from the loop exit's slot, keeps the table pointer in the $v1 of the lui and the D_001D5570 base in $a0; ours puts the return stubs after the loop and the pointer in $a0; about 10 wordings (for/do-while, result variable, goto-free returns) tried |
| `func_L19_003C3898` | levels | level 19 (Thran) first half, Sonnet session | 3 differences: file L19_003C0938.c builds with `@ps2as` (inline float constants). The C compiles to retail except the first branch: retail stores `sw $0,0x9C($s0)` before the `lui/lw D_001DF800` and keeps the entry pointer in $a2, this C loads D_001DF800 first (tab local) and the store follows. About 10 wordings (tab declared per branch, at function level, store before/after the tab load, a local for the list pointer) gave 3 to 14 differences |
| `func_L19_003AFB40` | levels | level 19 (Thran) first half, Sonnet session | first block, prologue and epilogue match with `--as ps2as` (the file must build with @ps2as: the gp/lui mix is the assembler's, every $gp access sits in a delay slot). Left in the mode==2 block: retail keeps D_001DF240 in $a1, the table base in $a0 and the index in $v1 and fills the beqz delay slot with the -1 constant; this C gives $a2, $v0, $a0 and a lui there (about 17 rows). Nested/else-if/switch shapes and a local for the loaded D_001DF240 all gave the same or worse (42 to 91 rows counting the shifted branch offsets); about 8 compiles |
| `func_L19_003B2D00` | levels | level 19 (Thran) first half, Sonnet session | 19 differences with the file's `@ps2as`: the 30-argument func_L01_003303B8 call matches func_L19_003B2748's, but here retail stores the 0x10000 argument (sw $v0,0x30($sp)) after the `move`/`mov.s` argument setup and this C stores it before `addiu $a0,$sp,0x90` (about 10 rows shifted), and the later `p->xA8 &= ~0x10` loads the word into $v1 and the mask into $v0 where this C swaps them. Declaring p late, a flags temporary and swapping the two stores before the last call changed nothing or made it worse (4 compiles) |
| `func_L19_003B2290` | levels | level 19 (Thran) first half, Sonnet session | the VU0 block, calls and prologue match with `-mvu0-use-vf0-vf2` added to L19_003B1A80.c's flags (its eight C functions still MATCH with it) and `#include "vu0.h"` in its prelude. Left (about 15 rows): the return value. Retail keeps the result in $a1 (set to 0 in the delay slot after the `beqz t`, to 1 by the `beql` / fall-through) and tests `t == p->x230` with a `bne`; this C gets `xor`/`sltiu` for that compare in every wording (r = 0 plus nested ifs, ||, early returns, 6 compiles) |
| `func_L19_003C27A8` | levels | level 19 (Thran) first half, Sonnet session | two causes: (1) the VU0 vsub: retail loads sp+0 into $vf1 and sp+0x10 into $vf2 and subtracts `vsub $vf2,$vf2,$vf1`; vec_sub_ba gives the right load order but the registers swapped (`vsub $vf1,$vf1,$vf2`), vec_sub_ab gives retail's vsub word but the loads swapped, and neither helper nor an inline copy with other declaration order changes it; (2) the 0/1 result of `20.0f <= f` is built in $v0 and copied to $a0 in retail, this C writes $a0 directly. File flag change (-mvu0-use-vf0-vf2) is needed and kept out of this commit; about 6 compiles |
| `func_L19_00307350` | levels | level 19 (Thran) first half, Sonnet session | 46 rows (about 12 real): with `@ps2as` the structure, constants, the three div.s and the $gp/lui mix of D_001DC534/538 (needs `.extern ,4` hints, in the C) are right. Left: the 0.02 constant is built in $f0 and the product in $f21 where retail builds the constant in $f20 and multiplies `mul.s $f20,$f2,$f20` (negation in $f21); and retail stores the second func_003824E0 result with `lui $at; swc1 0xe04($at)` between the argument computations where this C hoists a `lui $v0` (D_001E0E04 as unsized array) or uses $gp (as scalar). Declaration order of the temporaries changed nothing; 4 compiles |
| `func_L19_003AD6B0` | levels | level 19 (Thran) first half, Sonnet session | 60 rows (many are shifted branch offsets) with `--as ps2as` (the file needs @ps2as for the inline 1.1f; it holds only this function). Left: retail keeps one callee-saved $s1 as the base for D_001A4BE0 (hi reused) and later &D_001E8E40, uses $a0 for the call result, and a 0x20 frame; this C uses $s3 and a 0x30 frame. Local base pointers for D_001A4BE0/D_001E8E40 made it worse (95 rows); about 5 compiles |
| `func_L19_003C2628` | levels | level 19 (Thran) first half, Sonnet session | 20 differences, all one rotation: retail keeps obj in $s1 and p = obj->x68 in $s2, this C gives obj $s2 and p $s1; everything else (the `.extern` hinted $gp arrays D_001DE808/820, the constants 0x3BA4B5BF/0x3E00ADFD, the switch layout, the lq/sq copy) matches. Declaration order of p/obj, using the parameter directly with casts, a state copy: no change; 5 compiles |
| `func_L19_003C9F00` | levels | level 19 (Thran) first half, Sonnet session | draft, 83 rows with `-mvu0-use-vf0-vf2 @ps2as` on the file (not applied) and vu0.h: the four-way switch over three 0x40-stride tables (D_002BDEB0, D_002BDED0, D_002BDEC0), the `func_003824E0(0,1)` scale, the vsub/vadd and the 0x30-byte local at sp+0x20 are right in kind. Left: retail computes the row address twice in two registers (`addu $5,base,off` for the second quad, `addu $3,off,base` for the first) and lays out the temporaries at sp+0x50/0x60/0x70/0x80 (frame 0xC0), which this C does not reproduce; 4 compiles |
| `func_L19_003CF7B8` | levels | from asm | 62 diff, register allocation: the two stack quadwords (q[0] at sp, the 0.1-w copy at sp+0x10), the call shapes and constants match; left: retail keeps (n*5+2)/6's n in $s0 and the result of func_00382468 in a copy ($s0, movn $v1,$v0,$s0 for r ? r : r-1), where this C folds it to sltiu/subu and gives m $s0 / n $s2; the sq/swc1 order before the first jal also differs. About 12 wordings tried (r ? r : r-1, if (r == 0), != 0 ? r : -1, local order, array of two) |
| `func_L19_003CF930` | levels | from asm | 12 diff, register numbering only: retail holds the 1/2/3/4/0 mode in $a0 where this C uses $v1, and allocates the item pointers (s+0x40 in $s3, s+0x50 in $s1) in the other order. Everything else matches (index loop with strength-reduced pointers, float tiers, 0.05/1.0 w stores, call shapes). Calls func_L19_003CF7B8, also a near miss |
| `func_L19_003D26C0` | levels | from asm; include/vu0.h vec_add_ba | 1 instruction off: retail keeps `sqc2 vf1,0x10(s0)` before `jal func_L19_003D2A40` with a nop in the slot; this C (with -mvu0-use-vf0-vf2 on the file's line in config/levels/text_parts.txt) puts the sqc2 in the jal delay slot (25 rows shift). A volatile sqc2 (30 diff), a memory clobber, a C store of the vf register and a by-value vec argument all give the same or worse |
| `func_L19_003D2BF8` | levels | from asm | 13 diff, all from one scheduling choice in the last func_L01_0040A4A0 call: retail ends `lui $at / lwc1 $f13,%lo(D_001DEC10) / jal / addiu $t1,0x17`, this C schedules `addiu $t1` before the jal and puts the f13 load in the delay slot, where Ps2EeAs turns it into a $gp access (0x2360($gp)). Calls 1 and 2 match exactly; an unsized-array declaration of the float fixes the slot but changes the address form (lui $v0 pair) |
| `func_L19_004044B0` | levels | from asm (VU0 cross product scaled by 0x3FB504F3 = 1/sqrt2) | inline asm: byte-exact only with the lui/ori of the 0x3FB504F3 constant inside the asm block (retail interleaves them between the two lqc2); passing it as a C input operand gives 5 diff (lui/ori hoisted above the lqc2, constant in $v0 not $t0), and the j-form needs -mvu0-use-vf0-vfN which this file's flags lack |
| `func_L19_0040F070` | levels | from asm | 14 diff, register allocation only: retail keeps the table's high half and the loop pointer in one register (lui $v1 / addiu $v1,$v1,lo) and fills the loop-back bnez and the first beqz with the shared 'move $v0,$zero'; this C puts the pointer in $a0 and leaves a nop slot (about 11 wordings tried: p before/after the call, do-while vs while, id local, result variable) |
| `func_L19_00418E68` | levels | from asm | 38 diff, needs @ps2as: structure, $gp accesses and constants match; left: retail shares one register ($a1) between the f34 value and the final call pointer and keeps found in $t1 set to 0 in the second bne's delay slot, and compiles both range tests as bnel/beql with the loop increment in the slot, where this C gives slt+movz (every wording of the two tests tried: nested ifs, &&, continue, else-branch, u8/s32 found) |
| `func_L19_00492770` | levels | from asm | 79 diff: the 5-entry jump table (case 4 sharing default), the three case bodies, the inner do-while with its beql/bnel booleans and the hoisted $gp load all match in shape; left: temporary register numbering (retail: base-0xec8 in $v1, pp = base+0xC in $a0 copied to $a1 for the loop, i+1 in $t0, j in $t1; this C swaps $a0/$v1 and puts pp in $a3). Same family as func_L19_00491668 and func_L19_00490538 (other tables). About 10 compiles: i+1 as temporary, pp built as base+0xC+i*24, locals reordered, q = pp |
| `func_L24_00401EE0` | levels | level 24 draft | 15 differences, all register allocation: retail keeps the table's lui in $v1 (the loaded id in $v0, pointer p = $v1, the u8 table base in $a0) and fills the first bne's slot with that lui; this C gives hi/p/base to $v0/$a0/$v1. Structure (call, 0x67 case, entry test, rotated search loop, return 1/0 exits) already equals retail; do-while with entry test, for loop, s32* version, index local and a result variable were tried (best 15, the others 26 or worse) |
| `func_L24_003A75F0` | levels | level 24 draft | 2 differences: retail stores 0x1BC before 0x190/0x1D7/0x1D8, this C (statement order found by hill climbing from 20 down to 2; every 4-statement permutation and single moves tried) swaps the 0x1BC and 0x1D8 stores; needs @ps2as on L24_003A6BA8.c (inline float constants), checked here with --as ps2as |
| `func_L24_003A79F0` | levels | level 24 draft | 15 differences: retail keeps the table entry pointer in $v1 with per-argument register copies (move $t1/$t3/$v0,$v1; extra move $t2,$a3) and n in $t0; this C allocates n in $v1 and the pointer chain in $t2/$a3. Array-indexed D_L24_002B9460[n-1].fXX arguments (same struct as func_L24_003A7750's S_3A7750) are the closest; u8* pointer, S* pointer, index local and argument temporaries in all orders were worse |
| `func_L24_003B69F8` | levels | level 24 draft | 20 differences (VU0 helpers vec_sub_ab/vec_add_ab/vec_sub_ba/vec_add_ba from include/vu0.h, needs -mvu0-use-vf0-vf2 and @ps2as on L24_003B6050.c, plus __asm__(".extern D_L24_001DE804, 4") for the $gp divisor): the $gp divisor load is scheduled differently (retail hoists lw $v1,0x1F54($gp) into the bc1f slot and re-reads it in the p->900>=2 block; this C reads it into $a0 and reorders the 8FC load/mfhi/slt). A function-scope local for the divisor gave 28; a block-scope local gave 20. Declares the function with void *arg0 because func_L24_003B6320 declares it that way |
| `func_L24_003CB5A8` | levels | level 24 draft | 16 differences (needs .extern size hints for the $gp-relative buffers D_L24_001E1B30/70 and K&R declarations of the later-defined func_L24_003CB900/003CB990 and func_11B2E8): left is the block layout of case 2's tail (retail puts the p[1]>1 arm after the shared func_L24_0042BAC0 call and uses bne where this C gets bnel), and the argument-move order of the second func_11B2E8 call; if/else orders, a variable for the func_L24_003591B0 argument, return instead of break were tried |
| `func_L24_00359E30` | levels | level 24 draft | 34 differences after a statement-order hill climb from 59: a long run of independent stores whose retail scheduling order was not reproduced; needs the existing @ps2as, the $gp floats D_L24_001DD630/634 with .extern hints |
| `func_L24_003B64C8` | levels | level 24 draft | 81 differences after a statement-order hill climb from 94: the whole setup is a long interleaved store run (constants preloaded into $f0-$f5, then stores scheduled around func_L24_0041FCB0 and func_L24_0043B968); also needs func_L24_003B64C8's earlier K&R declaration in L24_003B6050.c, which is not committed |
| `func_L24_003A7CE8` | levels | level 24 draft | 21 differences, register allocation: retail keeps n in $s0 (reused as the last table-field pointer), the loop counter in $s1, the constant 6 in $s2 and the d-vector copy in $s3; this C rotates them (counter $s0, n a temp). Needs -mvu0-use-vf0-vf2 + @ps2as on L24_003A7AA8.c (already set) and a full table struct (fields 0,4,8,C,0x10) for D_L24_002B9460 in place of the pad-only one in func_L24_003A7AA8's block. Statement-order hill climb over the loop body gave no improvement, declaration order of n/i makes no change |
| `func_L03_003C1280` | levels | level 3 (Starship Phoenix) draft | 95 differences: the up-vector address is hoisted into a saved register and the d[2] load is not hoisted; family of 9 identical functions at level 3 |
| `func_L03_003C0608` | levels | level 3 (Starship Phoenix) draft | 90 differences: constants 0xFF/0xD4 hoisted differently in the final loop; family of 8 identical functions at level 3 |
| `func_L05_00362148` | levels | level 5 sonnet pass (2026-11-12) | 27 differences: needs -mvu0-use-vf0-vf2 on its file and the divs_nops row "func_L05_00362148 2"; all instructions right, only scheduling differs: ours hoists the sh 0x32 and the $gp float load into the div.s shadow and puts 1.0f in $f0 where retail has $f1 |
| `func_L05_003B1CF8` | levels | level 5 sonnet pass (2026-11-12) | 89 differences: needs -mvu0-use-vf0-vf2 on its file; logic and stack layout right, ours hoists the two global addresses and strength-reduces the D_001E1D70[i] store (frame 0xA0, retail 0x90); loop forms and statement orders tried |
| `func_L05_0032B630` | levels | level 5 sonnet pass (2026-11-12) | 9 differences: needs -mvu0-use-vf0-vf2 and @ps2as on its file; only the order of two argument moves (retail a1 before a0) and the register of the call's result differ |
| `func_L03_0039A118` | levels | level 3 (Starship Phoenix) draft | 12 differences, scheduling only: retail sets `addiu $a2,$zero,0x64` before the `movz` and `move $a0,$sp` after it, and keeps the pointer returned by func_L01_0046FB40 in $a2 with the 0x44 byte in $a1; this C the reverse. Needs `-mvu0-use-vf0-vf2 ... @ps2as` on L03_00399D30.c |
| `func_L24_0034C7A8` | levels | level 24 (Insomniac Museum) draft | 2 differences: two independent setup instructions of the second loop are swapped (retail `move $s1,$s4` before `addiu $s0,$s5,4`, this C the other way round); the rest matches (needs @ps2as, file already has it). About 20 compiles: declaration orders, a separate counter for the second loop (needed), pointer-copy variants (frame changes) |
| `func_L24_0034C208` | levels | level 24 (Insomniac Museum) draft | 50 differences: loop bodies, gp floats and lq/sq copies match; retail shares nothing between the two loops (rebuilds 0.02f and s+0x380 before the second; frame 0x50), this C hoists both (frame 0x60). A separate counter and pointer for the second loop did not change it |
| `func_L24_0034F4E0` | levels | level 24 (Insomniac Museum) draft | 26 differences: same instructions, different scheduling (retail preloads obj[0x18] and s[0x154] before the first jal and stores s[0x150] in its delay slot, and interleaves the last call's three float products with the s[0x134]/obj[0x18] updates); two statement orders tried |
| `func_L24_00350288` | levels | level 24 (Insomniac Museum) draft | 64 differences: logic right (pad-button chain calling the action functions), register use across the branch-likely chain differs (retail copies the pad pointer to $a0 at the second test and re-reads pad[0x1A0] in the delay slots); 3 compiles |
| `func_L24_0034C088` | levels | level 24 (Insomniac Museum) draft | 52 differences: sibling of matched func_L24_0034BF38; retail keeps n-- and q++ at the loop end and compiles the max-store to bc1tl, this C hoists the increments into the first jal's delay slot (bc1f); `f > w[2]`, increment order and `while (--n >= 0)` tried |
| `func_L24_0034EC40` | levels | level 24 (Insomniac Museum) draft | about 6 differences: the order of the first four constant stores (sb 0x58/0x5A/0x3E, sh 0x34) interleaved with the three qzero stores and their constant registers; the rest, incl. the `.extern` gp float and the rotated tail stores, matches. About 100 statement orders tried |
| `func_L24_0034BA30` | levels | level 24 (Insomniac Museum) draft | 5 differences: only the first statements (retail puts 0x34 in $v1 and the obj[0x18] load before the second gp zero store; this C swaps the registers and that order); the two constant-store runs match with rotated source order. About 100 compiles |
| `func_L24_00357D50` | levels | level 24 (Insomniac Museum) draft | 3 instructions (31 reported by the shift): every instruction of the spark loop matches except the last argument of func_L01_0046B458: retail builds `r ? r : r - 1` with a second pseudo (`move $v1,$v0; addiu $t0,$v1,-1; movn $t0,$v0,$v1`), this C gives `addiu $t0,$zero,-1; movn $t0,$v0,$v0`; four wordings tried. Needs -mvu0-use-vf0-vf2 on L24_00356100.c's line (not committed) |
| `func_L36_003A87C0` | levels | level 36 (Vid-comic 1 Special Edition) draft | 13 differences (file builds with -mvu0-use-vf0-vf2 @ps2as): every instruction is there; retail loads $f13 (D_L36_001DEAB8) before the loop's first sub.s and again in the delay slot of the bottom bc1t, so neg.s comes before the swc1; ours schedules the load after the swc1 and fills the slot with bc1tl + a copy of sub.s. Statement orders, const on the global, and while/do-while tried |
| `func_L36_00348BB8` | levels | level 36 (Vid-comic 1 Special Edition) draft | 19 differences (one: needs -mvu0-use-vf0-vf2 @ps2as on the file; every instruction matches except that ours puts the final sqc2 (vec_add_ba into a0+0x10) in the delay slot of the jal to func_0038D640 where retail has nop; callee return types and a struct-typed a0 tried) |
| `func_L36_00355388` | levels | level 36 (Vid-comic 1 Special Edition) draft | 10 differences: two 16-byte copies (lq/sq) from a1 into a0->0x68; retail copies a1 into $v1 (move) in the beqz delay slot and loads both quadwords from $v1 while reusing $a1 for the constant 2, ours loads from $a1 directly; typedef, struct, long, local-pointer wordings tried |
| `func_L36_003553B8` | levels | level 36 (Vid-comic 1 Special Edition) draft | about 62-78 differences: needs the divs_nops row 'func_L36_003553B8 2 2' (not committed); loop and calls are right, but retail keeps lo/hi in $f22/$f21 swapped from ours (div.s of a3 first into $f22), keeps i<<2 in its own saved register $s2 and the table pointer in $s5 (frame 0x70, ours 0x60); several wordings of the slot index and the lo/hi order tried |
| `func_L36_003A8920` | levels | level 36 (Vid-comic 1 Special Edition) draft | about 90 differences (word shifts from one cause): the logic and call structure are right (switch with bodies in retail's order 0, 0x42, 1); retail keeps the constant 1 (case 1 compare and the D_L36_001DEADC store) in $a0 loaded before the lbu, ours puts it in $a1 and loads it later; local copy of the state byte and per-case loads of the object pointer tried |
| `func_L36_00470E10` | levels | level 36 (Vid-comic 1 Special Edition) draft | 28 differences: same code as func_L31_0046A050 (flag-table update, other table); retail increments i in place where gcc keeps n = i + 1 in another register (about ten wordings tried; none changes it) |
| `func_L36_00350330` | levels | level 36 (Vid-comic 1 Special Edition) draft | 59 differences (file L36_0034E8C0.c, @ps2as; the u128_t typedef must go in the file prelude): the logic is right but the temporaries are allocated differently throughout the first 25 instructions (retail: $v1 = 0xFF, $a2 = -1, $a1/$a0 the table sums, ours $v0/$a1/$v1); sq order B0/A0 and statement order of the stores tried |
| `func_L36_003540D8` | levels | level 36 (Vid-comic 1 Special Edition) draft | 21 differences, one cause: retail keeps the object pointer a0 in $s2 and its state pointer s in $s1 (the D_001A4BE0 base in $s0), ours swaps $s1/$s2 (the u128_t typedef is in the file prelude); declaration order, caching the 0x5C field and a late assignment of s tried |
| `func_L36_003A8AB0` | levels | level 36 (Vid-comic 1 Special Edition) draft | about 94 differences (file builds with -mvu0-use-vf0-vf2 @ps2as): the logic is complete, but retail's prologue loads a1[0] and a1[1] before testing, hoists s = o->0x68 into the beqz delay slot and keeps o/s/a0/a1 in $s0/$s1/$s2/$s3 (ours rotates them); two restructurings of the early exits tried (worse) |
| `func_L36_0031D768` | levels | level 36 (Vid-comic 1 Special Edition) draft | 11 differences (needs -mvu0-use-vf0-vf2 and @ps2as on L36_0031D768.c, which has no C; the vmr32 line is a local asm for a VU0 op the helpers lack): every instruction is right, only the order differs: retail stores d to w (sqc2) and copies the old quadword (sq) later, and stores the vadd result after the w copy; ours stores the vadd result first. Statement orders and an early u128 temporary tried (worse) |
| `func_L36_0031D878` | levels | level 36 (Vid-comic 1 Special Edition) draft | 11 differences (L36_0031D768.c needs -mvu0-use-vf0-vf2 and @ps2as): all instructions and the frame (obj at sp+0x90, v at sp+0xC0) are right, only the scheduler's order of the 0x407FFF ori/sw and of two stack stores differs (retail does that ori last and stores 0x40/0x50 before 0x20/0x48); func_L01_003303B8 declared with the float first (11 vs 13 with the Veldin prototype) |
| `func_L11_00433210` | levels | level 11 (Obani Moons) draft | 35 differences, one cause: retail computes p->f38 & 0x400 into $v1 before the distance call and never uses it (a dead lw/andi pair, 2 instructions), which shifts everything after it; with them every other instruction matches. The C here folds the test away; tried a ternary of two equal locals before and inside the compare, if/else, equal float/double constants, a separate flag local (about 12 compiles) |
| `func_L11_004AFFF0` | levels | level 11 (Obani Moons) draft | 2 differences (the class of func_L01_00350040): retail has lui, lw, xori, jr and leaves the jr delay slot as the nop at 0x4B0000, which the catalogue counts as the linker remnant func_L01_003ECA08 in its own file (L01_003EB9C8.c's slice); gcc fills the slot with the xori, so the C is the same 16 bytes in the other order. The C needs the remnant file to become this function's delay slot |
| `func_L11_003A2CD0` | levels | level 11 (Obani Moons) draft | 4 differences, with the file's flags plus -mvu0-use-vf0-vf2 (needed by vec_sub_ba's "j" operands): two saved-register stores in the prologue (sd $s3 before sd $s2 here, retail sd $s2 first) and the v + 0x70 addiu, which retail schedules after the second lq; everything else matches, including the stack slots (pos, rot, d declared in that order as vu0_v4). Tried a pointer local for v + 0x70 (before and after the copies), a typed r pointer, declaration orders of r and v, the six declaration orders of the locals |
| `func_L11_00350EE0` | levels | level 11 (Obani Moons) draft | 13 differences, measured with the file's flags plus -mvu0-use-vf0-vf2 (vec_add_ab needs it; the file's three C functions still match with it): in the two copies of a table entry's position into v + 0x100, retail loads the table pointer (lui/lw) before the index and keeps index, pointer and quadword in $v0/$a0/$v1; the C loads the index first ($v1/$a0/$v0). Everything else matches, including the $gp loads of the same pointers in branch delay slots. Tried typed entries, u8 arithmetic, TImode copies, a local table pointer and an unsized alias for the second reads |
| `func_L11_003BDED0` | levels | level 11 (Obani Moons) draft | about 80-100 differences, measured with @ps2as on the file (its float constants are built inline with lui/ori, which only Ps2EeAs does; func_L11_003BE100 then needs __asm__(".extern D_L11_001DE3D0, 4") to keep its $gp load). The logic and calls are retail's, the differences are register allocation and loop-invariant hoisting: retail keeps &D_L11_001E1168 in $s6, the $gp address of D_L11_001DE3C0 in $s7 and 12 in $fp across the loop, n in $s0 and i in $a0, and reloads 0xF0 each pass; the C hoists 0xF0 and recomputes the $gp address. Tried a local table pointer, a local source pointer, storing the loaded flag instead of 1 |
| `func_L11_003FCBD0` | levels | level 11 (Obani Moons) draft | the same code as func_L11_003BDED0 with other tables (D_L11_001DEBF0/C20/C30/C38, $gp table D_L11_001D6B20), so the same near miss: with @ps2as on its file (inline lui/ori float constants) the differences are register allocation and loop-invariant hoisting, about 100; without @ps2as 133 (the constants come from .lit4). A match of either ports to the other by renaming the tables |
| `func_L11_00472AD8` | levels | level 11 (Obani Moons) draft | 13 differences: the sibling of func_L11_00473BE0 (same table walk, with func_L01_0041A4F0() where that one reads D_L11_001D9358); every block and the jump table are retail's, but in case 1 retail increments the index in place (addiu $s2, $s2, 1) before the inner loop and keeps the inner index in $s4, while the C computes i + 1 into $s4 and copies it back (the level-2 'in-place i++' class), which renames $s2-$s4 in that case. Tried a for loop with one i++ (28), an i++ per case (13), an entry pointer, i++ before the inner loop, e = &D[i++] (112-118) |
| `func_L11_003BDA60` | levels | level 11 (Obani Moons) draft | draft, 173 differences counted (measured with --flags=-mvu0-use-vf0-vf2, vec_add_ab needs it): the saved-register class of the level-2 open problem: retail saves $s0-$s6 and $ra with sq in 16-byte ascending slots (frame 0x170) where gcc writes sd in 8-byte slots (frame 0x130), which shifts every stack offset and the schedule; levels have no sq_ra_funcs table, and the frontbin rewrite needs a file without -fopt-stack. The calls, arguments and constants are retail's; not tuned further |
| `func_L11_003A9B30` | levels | level 11 (Obani Moons) draft | 2 differences, with @ps2as on its file (inline float constants; the file has it since func_L11_003A8FE0): two float stores in the other order (retail stores 0x70 then 0x78, the C 0x78 then 0x70); every other instruction, both constant pools and the leftover $a1 = 6 are retail's. Found with a store-order search (about 600 orders of the 18 stores, one chained assignment of the four 0.5f stores); func_L01_0045BD78 takes (void *, f32, f32, f32, f32) and $a1 is a leftover |
| `func_L11_0034F0F0` | levels | level 11 (Obani Moons) draft | draft, 174 differences counted (measured with --flags=-mvu0-use-vf0-vf2 for the VU0 helpers; the file has no other function): retail saves $s0-$s7, $fp and $ra with sq in 16-byte ascending slots (frame 0x110), the sq_ra class levels have no table for, so every stack offset and the schedule differ. Not tuned further |
| `func_L11_003510D0` | levels | level 11 (Obani Moons) draft | draft, about 220 differences (measured with --flags=-mvu0-use-vf0-vf2; in the file the u128_351528 typedef would have to move to the prelude, since func_L11_00351528 comes later): the beam bounce loop (up to 16 hits, laser colour 0x3F2020FF / 0x3FFF2020, func_L01_0040A8C0 per segment) with every call and constant retail's, but the block layout and saved-register assignment differ: retail keeps a0 in $s5, the hit count in $s6, &to in $s4 and &D_L11_001E84C0.pos in $s3, and places the no-moby sparks block after the moby cases. Not tuned further |
| `func_L11_003A9260` | levels | level 11 (Obani Moons) draft | 108 differences (with the file's flags): the block layout, both switches (the second with retail's empty cases 1, 2 and 5, which give its jump table) and every call are retail's; what differs is one register choice that runs through the function: retail keeps a0 in $s3 because the death effect's func_L01_003303B8 call holds three of its stack constants (0x63F7, 0x20FF, 0x8FFF) in $s0-$s2, while here those constants get $t1/$t3/$t7 and a0 gets $s2. Not tuned further (argument order of the 30-parameter call is the likely lever) |
| `func_L11_00316318` | levels | level 11 (Obani Moons) draft | draft, about 290 differences counted, measured with --flags=-mvu0-use-vf0-vf2 --as ps2as (the file would need @ps2as: retail reads D_L11_001DEA50 through $gp in a delay slot and through lui elsewhere, Ps2EeAs's unknown-size behaviour, and builds its float constants inline; func_L11_003161B8 in the same file would have to be rechecked under it). The first 0x90 bytes and the calls are retail's; the rest differs in store order of the camera constants and in retail keeping the %hi of D_001A4BE0 in $fp and &D_001A4BE0.pos in $s0 across the player checks (D_001A4BE0 fields are then reached as $s0 - 0x80). Not tuned further |
| `func_L14_003F9A10` | levels | PR #32 draft, reverted | the inline-asm C (lqc2/vmulx.xyzw/sqc2 scaling of a 4x4 block) does not build: under @ps2as the assembler rejects it, and under the default assembler the result differs from retail; the level 14 build broke on it, so the function is INCLUDE_ASM again |
| `func_L10_003CFF60` | levels | level 10 (Zeldrin Starport) pass (2026-11-11) | 1 difference: the catalogue cuts the jr delay slot (0x003D0000 is catalogued as the remnant func_L01_003AE6E0); every other word matches. Needs @ps2as on its file |
| `func_L10_004AFFF0` | levels | level 10 (Zeldrin Starport) pass (2026-11-11) | 1 difference: the catalogue cuts the jr delay slot, which it lists as func_L10_004B0000 (4 bytes); with that entry joined to this one the C covers both |
| `func_L10_003C8428` | levels | level 10 (Zeldrin Starport) pass (2026-11-11) | 13 differences: one scheduling tie in func_L01_003303B8's stack arguments (where the constant 1 is loaded); everything else matches. Its file is -mvu0-use-vf0-vf2 @ps2as |
| `func_L10_003C65D8` | levels | level 10 (Zeldrin Starport) pass (2026-11-11) | 3 differences: the func_L01_003303B8 stack-argument tie of func_L10_003C8428 (where the constant 1 is loaded); everything else matches. Needs the VU0 flag set on its file |
| `func_L10_003C5FE8` | levels | level 10 (Zeldrin Starport) pass (2026-11-11) | 3 differences: the func_L01_003303B8 stack-argument tie of func_L10_003C8428 (where the constant 1 is loaded); everything else matches |
