/* PAL near miss: 197 differences (tools/check.py) with the file's flags
 * (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division), in src/boot_elf/text/3C1848.c's
 * context (it supplies S_BC0F0 and D_002D2060). No NTSC-U twin (config/us/map.tsv).
 * Ported from the frontbin twin's draft (nonmatching/frontbin/func_003C1728.c, 209) with boot_elf's
 * callees, then the global used directly instead of a local pointer (205: retail's 0x30 frame with
 * $s0-$s3) and the flag byte read as u8 (retail `lbu`). func_0038DE98 takes its plain name: this
 * file does not declare it (the earlier Codex wave 8 note found a void(f32, f32) declaration in the
 * context of that time).
 * What differs is register allocation: retail keeps %hi(D_002D2060) in $s2 from the first block on
 * and rebuilds the base in each case block (`addiu $s0, $s2, %lo`, or from D_2D20AC then -0x4C);
 * gcc here rebuilds the %hi with a new `lui` per block and folds field offsets into the address.
 * The u8 cast, a u8 field and the direct global with or without a local switch value all give 197.
 */
#include "common.h"
/* localdecomp:start func_003C1AE0 */
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
    s32 st;

    if ((u8)D_002D2060->f60 == 0) {
        func_003BBC00(2);
        D_002D2060->f60 = 1;
    }
    if (D_002D2060->f40) {
        switch (D_002D2060->f48) {
        case 0:
            *(f32 *)&D_002D2060->f30 = 1.0f - (f32)D_002D2060->f4C / 50.0f;
            if (func_0038CEB0(&D_002D2060->f4C)) {
                D_002D2060->f4C = 75;
                D_002D2060->f48 = 1;
            }
            break;
        case 1:
            if (func_0038CEB0(&D_002D2060->f4C)) {
                D_002D2060->f48 = 2;
                D_002D2060->f4C = D_002D2060->f34 * 3;
            }
            break;
        case 2:
            *(f32 *)&D_002D2060->f30 = 1.0f;
            if ((D_002D2060->f34 * 3 - D_002D2060->f4C) % D_001D9094 == 0) {
                func_003BBC00(0);
            }
            if (func_0038CEB0(&D_002D2060->f4C)) {
                D_002D2060->f4C = 75;
                D_002D2060->f48 = 3;
                func_003BBC00(1);
            }
            break;
        case 3:
            *(f32 *)&D_002D2060->f30 = 1.0f;
            if (func_0038CEB0(&D_002D2060->f4C)) {
                D_002D2060->f48 = 4;
                D_002D2060->f4C = 100;
            }
            if (*(u32 *)(D_001D52FC + 0x1C4) & 0x40) {
                D_002D2060->f4C = 0;
            }
            break;
        case 4:
            if (func_003BE2D0()) {
                func_003BBD20();
            }
            if (func_003BE6B8()) {
                if (func_0038CEB0(&D_002D2060->f4C)) {
                    D_002D2060->f48 = 5;
                    D_002D2060->f4C = 50;
                }
            }
            break;
        case 5:
            done = (func_0038CEB0(&D_002D2060->f4C) == 1);
            *(f32 *)&D_002D2060->f30 = (f32)D_002D2060->f4C / 50.0f;
            func_003BBCA8(2, *(f32 *)&D_002D2060->f30);
            break;
        }
    } else {
        switch (D_002D2060->f48) {
        case 0:
            *(f32 *)&D_002D2060->f30 = 1.0f - (f32)D_002D2060->f4C / 50.0f;
            if (func_0038CEB0(&D_002D2060->f4C)) {
                D_002D2060->f48 = 1;
                D_002D2060->f4C = 100;
            }
            break;
        case 1:
            *(f32 *)&D_002D2060->f30 = 1.0f;
            if (func_003BE6B8()) {
                if (func_0038CEB0(&D_002D2060->f4C)) {
                    D_002D2060->f4C = 50;
                    D_002D2060->f48 = 2;
                }
            }
            break;
        case 2:
            done = (func_0038CEB0(&D_002D2060->f4C) == 1);
            *(f32 *)&D_002D2060->f30 = (f32)D_002D2060->f4C / 50.0f;
            break;
        }
        *(f32 *)&D_002D2060->f50 = func_0038DE98(*(f32 *)&D_002D2060->f50, D_001D9044);
    }
    return done;
}
/* localdecomp:end func_003C1AE0 */
