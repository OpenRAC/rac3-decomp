# Near misses and US drafts

C that is not linked and not counted: a starting point. One file per function,
`nonmatching/<program>/func_XXXXXXXX.c` (`<program>` is `frontbin`, `boot_elf` or `i5bootn`,
the name is the PAL address), with a comment at its top saying where it came from and what still
differs. Move it into `src/` once the full build prints `MATCH` with it in place, and delete its
row here. `tests/check_repository.py` checks that every file has a row.

Files that start with `/* US draft` are rac3-uya-decomp's C for that function (commit 13cf5c5),
with names moved to PAL addresses where the address maps are sure of them
(`tools/port_from_us.py`, docs/porting.md). They were not carried for the reason in their row:

- **flags**: the US match used flags of its own for this one function (a "single-function
  override" or `@ps2as` range), which this repository does not allow (docs/BUILD_FIDELITY.md);
- **differs**: the PAL function's bytes are not the US ones, or the C did not build to them here;
- **symbols**: a name in the C has no PAL address yet.

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
| `func_0013BD58` | boot_elf | US draft of `func_0013BD58` | near miss: 44 diff with the file's flags (the US draft: 62) |
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
| `func_00381FF0` | frontbin | US draft of `func_0037DF98` | differs: did not build, or built to other bytes, in PAL |
| `func_003822C8` | frontbin | boot_elf's C of `func_003826A8` | near miss: 1 diff with the file's flags (boot_elf's copy is C) |
| `func_00382380` | frontbin | US draft of `func_0037E0F0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382538` | frontbin | US draft of `func_0037E2A8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382810` | frontbin | US draft of `func_0037E568` | differs: did not build, or built to other bytes, in PAL |
| `func_003828D8` | frontbin | US draft of `func_0037E630` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00382B20` | frontbin | US draft of `func_0037E878` | near miss: 16 diff with the file's flags (was 40) |
| `func_00382BC8` | frontbin | US draft of `func_0037E920` | near miss: 25 diff with the file's flags (was 33) |
| `func_00382E10` | frontbin | US draft of `func_0037EB68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00383128` | frontbin | US draft of `func_0037EE80` | near miss: 20 diff with the file's flags (was 88) |
| `func_00383380` | frontbin | US draft of `func_0037F0D8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003834D0` | frontbin | US draft of `func_0037F228` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003841B8` | frontbin | US draft of `func_0037FEE8` | symbols: func_0037F7A8 |
| `func_00384498` | frontbin | US draft of `func_003801C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00384778` | frontbin | US draft of `func_003804A0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003848D8` | frontbin | US draft of `func_00380600` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00384D88` | frontbin | US draft of `func_00380AB0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00385020` | frontbin | US draft of `func_00380D48` | near miss: 117 diff with the file's flags (was 179) |
| `func_003856B8` | frontbin | US draft of `func_003813E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00385D28` | frontbin | US draft of `func_00381A50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003860A8` | frontbin | US draft of `func_00381DD0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003861F0` | frontbin | US draft of `func_00381F18` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003864C0` | frontbin | US draft of `func_003821E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003865A0` | frontbin | US draft of `func_003822C8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_00386730` | frontbin | US draft of `func_00382458` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00387218` | frontbin | US draft of `func_00382F40` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00387268` | frontbin | US draft of `func_00382F90` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00387F68` | frontbin | US draft of `func_003838C0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003881B0` | frontbin | US draft of `func_00383B08` | near miss: 2 diff with the file's flags (was 4) |
| `func_00388AF8` | frontbin | US draft of `func_00384420` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389240` | frontbin | US draft of `func_00384B68` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389370` | frontbin | US draft of `func_00384C98` | flags: the US matched it with `-fno-schedule-insns` `@ps2as` (a single-function override) |
| `func_00389598` | frontbin | US draft of `func_00384EC0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389B10` | frontbin | US draft of `func_00385438` | near miss: 8 diff with the file's flags (was 55) |
| `func_00389C48` | frontbin | US draft of `func_00385570` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389D00` | frontbin | US draft of `func_00385628` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389D60` | frontbin | US draft of `func_00385688` | near miss: 9 diff with the file's flags (the US draft: 18) |
| `func_00389DB0` | frontbin | US draft of `func_003856D8` | near miss: 7 diff with the file's flags (was 24) |
| `func_00389E28` | frontbin | US draft of `func_00385750` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389EA0` | frontbin | US draft of `func_003857C8` | near miss: 7 diff with the file's flags (was 24) |
| `func_00389F18` | frontbin | US draft of `func_00385840` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_00389FE0` | frontbin | US draft of `func_00385908` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038A058` | frontbin | US draft of `func_00385980` | near miss: 61 diff with the file's flags (the US draft: 114) |
| `func_0038A238` | frontbin | US draft of `func_00385B60` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038A3B8` | frontbin | US draft of `func_00385CE0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038A948` | frontbin | US draft of `func_00386210` | near miss: 118 diff with the file's flags (was 155) |
| `func_0038ABC0` | frontbin | US draft of `func_00386488` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038AD40` | frontbin | US draft of `func_00386608` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038AE20` | frontbin | US draft of `func_003866E8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038AF30` | frontbin | US draft of `func_003867F8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038B120` | frontbin | US draft of `func_003869E8` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_0038B4D0` | frontbin | US draft of `func_00386D98` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_0038B670` | frontbin | US draft of `func_00386F38` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0038B850` | frontbin | US draft of `func_00387118` | flags: the US matched it with `@ps2as` (a single-function override) |
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
| `func_0038D5F0` | frontbin | US draft of `func_00388EB8` | final as `ASM_FUNC` in src/frontbin/38D278.c: VU0 macro code (lqc2, vmulax), hand-written assembly like its neighbours; this inline-asm draft is not C |
| `func_0038D688` | frontbin | US draft of `func_00388F50` | final as `ASM_FUNC` in src/frontbin/38D278.c: VU0 macro code (lqc2, vmulax), hand-written assembly like its neighbours; this inline-asm draft is not C |
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
| `func_0039A8B8` | frontbin | US draft of `func_00395AC8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039ACA8` | frontbin | US draft of `func_00395EB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039ADE0` | frontbin | US draft of `func_00395FF0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039AEF0` | frontbin | US draft of `func_00396100` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039AF10` | frontbin | US draft of `func_00396120` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039B088` | frontbin | US draft of `func_00396298` | near miss: 5 diff with the file's flags (the US draft: 8) |
| `func_0039B100` | frontbin | US draft of `func_00396310` | near miss: 3 diff with the file's flags (was 23) |
| `func_0039B278` | frontbin | US draft of `func_00396488` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039B328` | frontbin | US draft of `func_00396538` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039B620` | frontbin | US draft of `func_00396830` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039B680` | frontbin | US draft of `func_00396890` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039B9B0` | frontbin | US draft of `func_00396BC0` | near miss: 3 diff with the file's flags (was 12) |
| `func_0039BA38` | frontbin | US draft of `func_00396C48` | near miss: 8 diff with the file's flags (was 39) |
| `func_0039BAD8` | frontbin | US draft of `func_00396CE8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039BB60` | frontbin | US draft of `func_00396D70` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039BC10` | frontbin | US draft of `func_00396E20` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039BD08` | frontbin | US draft of `func_00396F18` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039BDC0` | frontbin | US draft of `func_00396FD0` | near miss: 9 diff with the file's flags (was 19) |
| `func_0039C300` | frontbin | US draft of `func_00397380` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039C410` | frontbin | US draft of `func_00397490` | flags: the US matched it with `@ps2as` and without `-fno-force-mem` (a single-function override) |
| `func_0039EC28` | frontbin | US draft of `func_00399C90` | near miss: 144 diff with the file's flags (was 166) |
| `func_0039EED8` | frontbin | US draft of `func_00399F40` | near miss: 2 diff with the file's flags (the US draft: 8) |
| `func_0039F108` | frontbin | US draft of `func_0039A170` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039F348` | frontbin | US draft of `func_0039A3B0` | flags: the US matched it with `@ps2as` and without `-fno-force-mem` (a single-function override) |
| `func_0039F580` | frontbin | US draft of `func_0039A5E8` | near miss: 3 diff with the file's flags (was 7) |
| `func_0039FA88` | frontbin | US draft of `func_0039AAF0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_0039FDA0` | frontbin | US draft of `func_0039AE08` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A0D48` | frontbin | US draft of `func_0039BD48` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A0EC0` | frontbin | US draft of `func_0039BEC0` | near miss: 7 diff with the file's flags (was 47) |
| `func_003A0F98` | frontbin | US draft of `func_0039BF98` | near miss: 29 diff with the file's flags (was 33) |
| `func_003A1028` | frontbin | US draft of `func_0039C028` | flags: the US matched it with `@ps2as` (a single-function override) |
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
| `func_003A90A0` | frontbin | US draft of `func_003A3B50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9108` | frontbin | US draft of `func_003A3BB8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A91D0` | frontbin | US draft of `func_003A3C80` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9338` | frontbin | US draft of `func_003A3DE8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9440` | frontbin | US draft of `func_003A3EF0` | near miss: 43 diff with the file's flags (was 45) |
| `func_003A9618` | frontbin | US draft of `func_003A40C8` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9678` | frontbin | US draft of `func_003A4128` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A96D8` | frontbin | US draft of `func_003A4188` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9740` | frontbin | US draft of `func_003A41F0` | near miss: 55 diff with the file's flags (was 56) |
| `func_003A9830` | frontbin | US draft of `func_003A42E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9AD0` | frontbin | US draft of `func_003A4580` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003A9C70` | frontbin | US draft of `func_003A4720` | near miss: 8 diff with the file's flags (the US draft: 11) |
| `func_003A9DB0` | frontbin | US draft of `func_003A4860` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003AA940` | frontbin | US draft of `func_003A53E0` | flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override) |
| `func_003AAA00` | frontbin | US draft of `func_003A54A0` | differs: did not build, or built to other bytes, in PAL |
| `func_003AB830` | frontbin | US draft of `func_003A6288` | flags: the US matched it with `@ps2as` (a single-function override) |
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
| `func_003B4658` | frontbin | US draft of `func_003AF0A0` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
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
| `func_003BDCB0` | frontbin | US draft of `func_003B87B8` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
| `func_003BDD38` | frontbin | US draft of `func_003B8840` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003BE010` | frontbin | US draft of `func_003B8B18` | near miss: 3 diff with the file's flags (was 13) |
| `func_003BE168` | frontbin | US draft of `func_003B8C70` | near miss: 5 diff with the file's flags (was 34) |
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
| `func_003C36C0` | frontbin | US draft of `func_003BE1A0` | near miss: 17 diff with the file's flags (was 38) |
| `func_003C3860` | frontbin | US draft of `func_003BE340` | flags: the US matched it with `@ps2as` (a single-function override) |
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
| `func_003D8500` | frontbin | US draft of `func_003D2F90` | near miss: 19 diff with the file's flags (was 47) |
| `func_003D85C0` | frontbin | US draft of `func_003D3050` | near miss: 27 diff with the file's flags (was 31) |
| `func_003D86B8` | frontbin | US draft of `func_003D3148` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D8998` | frontbin | US draft of `func_003D3428` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D8CF0` | frontbin | US draft of `func_003D3780` | flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override) |
| `func_003D8FC0` | frontbin | US draft of `func_003D3A50` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D91F0` | frontbin | US draft of `func_003D3C80` | near miss: 10 diff with the file's flags (was 15) |
| `func_003D9740` | frontbin | US draft of `func_003D41E0` | flags: the US matched it with `@ps2as` (a single-function override) |
| `func_003D9CF0` | frontbin | US draft of `func_003D47A0` | near miss: 6 diff with the file's flags (was 37) |
| `func_003D9DA8` | frontbin | US draft of `func_003D4858` | flags: the US matched it with `-mno-split-addresses` (a single-function override) |
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
