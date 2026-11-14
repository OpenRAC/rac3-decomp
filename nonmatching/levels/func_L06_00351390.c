/* Level 06 shared (src/levels/shared/L06_*.c) draft, 2026-11-14. 3 differences with the file's flags (-mvu0-use-vf0-vf2 -mno-split-addresses @ps2as): retail sets r = 0 after the lui/addiu of D_001A4C60, this C before it; the if/else-if, ||, separate-call, typed-struct and return-type forms all leave it there. */
#include "common.h"
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern u8 D_001A4C60[];
s32 func_L06_00351390(u8 *a0, u8 *a1) {
    s32 r;
    r = 0;
    if (func_00382380(D_001A4C60, *(s32 *)(a1 + 0x264), 0) != 0 ||
        func_0038CF38(a0 + 0x10, a1 + 0x220) < *(f32 *)(a1 + 0x268)) {
        r = 1;
    }
    return r;
}
