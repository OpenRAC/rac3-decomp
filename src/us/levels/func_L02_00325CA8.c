#include "common.h"

/* NTSC-U counterpart of func_L02_00326520 (src/levels/shared/L02_00326430.c) */
extern int func_0037E1D8(int);

/* localdecomp:start func_L02_00325CA8 */
extern s32 func_0037E1D8(s32);
void func_L02_00325CA8(u8 *o)
{
    u8 *p = *(u8 **)(o + 0x68);
    s32 i;
    s32 color;
    s32 *c;
    for (i = 0; i < 4; i++) {
        ((f32 *)(p + 0x20))[i] = (f32)func_0037E1D8(255);
    }
    *(f32 *)(p + 0x30) = -1.0f;
    *(f32 *)(p + 0x34) = -2.25f;
    *(f32 *)(p + 0x38) = 1.25f;
    *(f32 *)(p + 0x3C) = 2.5f;
    i = 3;
    c = (s32 *)(p + 0x4C);
    color = 255;
    do {
        *c = color;
        c--;
        i--;
        color -= 64;
    } while (i >= 0);
    *(f32 *)(p + 0x50) = 2.5f;
    *(f32 *)(p + 0x54) = 3.0f;
    *(f32 *)(p + 0x5C) = 2.5f;
    *(f32 *)(p + 0x58) = 3.0f;
}
/* localdecomp:end func_L02_00325CA8 */
