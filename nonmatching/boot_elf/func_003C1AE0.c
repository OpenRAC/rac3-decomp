/* func_003C1AE0 (boot_elf), NM-FE6 2026-11-22: 0 differences (tools/check.py) with its file's flags
 * (src/boot_elf/text/3C1848.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division), in the file's context and with
 * --no-context (with the file's S_BC0F0 typedef and D_002D2060 extern in front); no NTSC-U twin
 * (config/us/map.tsv). The twin frontbin func_003C1728 is the same code: this C with its callees' names is 0 there too.
 * Two things made it match:
 * - (counts measured on boot_elf's func_003C1AE0, from 197) D_002D2060 seen through a per-function type whose f30 and f50 are floats (retail writes them with swc1):
 *   `*(f32 *)&D_002D2060->f30` made gcc form &f30 first (197); the cast view gives retail's base
 *   addressing, with %hi(D_002D2060) in $s2 (74); three store orders as retail has them (66) and the else
 *   branch's case 2 as `if (... == 1) done = 1;` (65);
 * - its row in config/boot_elf/divs_nops.txt is `func_003C1AE0 2 2 1 2`: before the third div.s (the else branch's
 *   case 0) the default assembler adds its own hazard nop after `mtc1 $f1`, so the table gives one nop
 *   less than retail has (as Matching-Patterns says of Ps2EeAs, func_00384420).
 * What blocks it is not the code. Its jump table's .s (rodata/jtbl_0031C9D0.s) also holds 42 words that no code
 * refers to (0x31C9E8 to 0x31CA90 in boot_elf). Deleting the INCLUDE_RODATA line with the function (as for any
 * switch) drops them (measured on boot_elf: NO MATCH, the data after them 0xA0 too early). Written as `const u32 D_0031C9E8[42]`
 * after the function (Matching-Patterns, "Unreferenced rodata after a jump table"), in both twins, the full
 * build gives 3 MATCH, but pr_check.py and check_repository.py reject the definition (AGENTS.md: globals are extern).
 * It needs a tool change: tools/setup_asm.py's split_data writing such a tail to its own rodata/D_*.s
 * (it aborts on non-jtbl data in the jump table block today), and pr_check.py accepting that
 * INCLUDE_RODATA after the C function.
 * Needs the file's S_BC0F0 and D_002D2060 (src/boot_elf/text/3C1848.c).
 */
#include "common.h"
/* localdecomp:start func_003C1AE0 */
/* D_002D2060 (S_BC0F0, above) seen with its float fields as floats: f30 and f50 are written with swc1. */
typedef struct { u8 n[0x30]; f32 f30; s32 f34, f38, f3C, f40, f44, f48, f4C; f32 f50; u8 p54[0xC]; u8 f60; } T_3C1AE0;
extern s32 D_001D9094;
extern f32 D_001D9044;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_003BBC00(s32);
extern s32 func_0038CEB0(void *);
extern s32 func_003BE2D0();
extern void func_003BBD20();
extern s32 func_003BE6B8(void);
extern void func_003BBCA8(s32, f32);
extern f32 func_0038DE98(f32, f32);
s32 func_003C1AE0(void) {
    s32 done = 0;

    if (((T_3C1AE0 *)D_002D2060)->f60 == 0) {
        func_003BBC00(2);
        ((T_3C1AE0 *)D_002D2060)->f60 = 1;
    }
    if (((T_3C1AE0 *)D_002D2060)->f40) {
        switch (((T_3C1AE0 *)D_002D2060)->f48) {
        case 0:
            ((T_3C1AE0 *)D_002D2060)->f30 = 1.0f - (f32)((T_3C1AE0 *)D_002D2060)->f4C / 50.0f;
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                ((T_3C1AE0 *)D_002D2060)->f48 = 1;
                ((T_3C1AE0 *)D_002D2060)->f4C = 75;
            }
            break;
        case 1:
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                ((T_3C1AE0 *)D_002D2060)->f48 = 2;
                ((T_3C1AE0 *)D_002D2060)->f4C = ((T_3C1AE0 *)D_002D2060)->f34 * 3;
            }
            break;
        case 2:
            ((T_3C1AE0 *)D_002D2060)->f30 = 1.0f;
            if ((((T_3C1AE0 *)D_002D2060)->f34 * 3 - ((T_3C1AE0 *)D_002D2060)->f4C) % D_001D9094 == 0) {
                func_003BBC00(0);
            }
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                ((T_3C1AE0 *)D_002D2060)->f48 = 3;
                ((T_3C1AE0 *)D_002D2060)->f4C = 75;
                func_003BBC00(1);
            }
            break;
        case 3:
            ((T_3C1AE0 *)D_002D2060)->f30 = 1.0f;
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                ((T_3C1AE0 *)D_002D2060)->f48 = 4;
                ((T_3C1AE0 *)D_002D2060)->f4C = 100;
            }
            if (*(u32 *)(D_001D52FC + 0x1C4) & 0x40) {
                ((T_3C1AE0 *)D_002D2060)->f4C = 0;
            }
            break;
        case 4:
            if (func_003BE2D0()) {
                func_003BBD20();
            }
            if (func_003BE6B8()) {
                if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                    ((T_3C1AE0 *)D_002D2060)->f48 = 5;
                    ((T_3C1AE0 *)D_002D2060)->f4C = 50;
                }
            }
            break;
        case 5:
            done = (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C) == 1);
            ((T_3C1AE0 *)D_002D2060)->f30 = (f32)((T_3C1AE0 *)D_002D2060)->f4C / 50.0f;
            func_003BBCA8(2, ((T_3C1AE0 *)D_002D2060)->f30);
            break;
        }
    } else {
        switch (((T_3C1AE0 *)D_002D2060)->f48) {
        case 0:
            ((T_3C1AE0 *)D_002D2060)->f30 = 1.0f - (f32)((T_3C1AE0 *)D_002D2060)->f4C / 50.0f;
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                ((T_3C1AE0 *)D_002D2060)->f48 = 1;
                ((T_3C1AE0 *)D_002D2060)->f4C = 100;
            }
            break;
        case 1:
            ((T_3C1AE0 *)D_002D2060)->f30 = 1.0f;
            if (func_003BE6B8()) {
                if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C)) {
                    ((T_3C1AE0 *)D_002D2060)->f48 = 2;
                    ((T_3C1AE0 *)D_002D2060)->f4C = 50;
                }
            }
            break;
        case 2:
            if (func_0038CEB0(&((T_3C1AE0 *)D_002D2060)->f4C) == 1) {
                done = 1;
            }
            ((T_3C1AE0 *)D_002D2060)->f30 = (f32)((T_3C1AE0 *)D_002D2060)->f4C / 50.0f;
            break;
        }
        ((T_3C1AE0 *)D_002D2060)->f50 = func_0038DE98(((T_3C1AE0 *)D_002D2060)->f50, D_001D9044);
    }
    return done;
}
/* localdecomp:end func_003C1AE0 */
