/* functional: high. check.py at level_06: 3 instruction diffs, all the order of 'r = 0' vs the D_001A4C60 address load (scheduling only). */
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
