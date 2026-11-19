/* functional: high. PAL near-miss draft; constants, loop count, flag/sh 0x7C thresholds and callees re-read against PAL asm; only scheduling and constant loading differ. */
#include "common.h"
extern u8 *D_L07_001DF41C[];
void func_L07_003D51D8(u8 *a0) {
    extern f32 func_003C3BE8(f32, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 input = *(f32 *)(p + 0x28);
    f32 t;
    f32 extra;
    f32 angle;
    f32 step;
    u8 **item;
    s32 i;
    if (input < 1.0f) {
        t = input;
        extra = 0.0f;
    } else {
        t = 1.0f;
        extra = input - t;
    }
    angle = 0.0f;
    step = func_003C3BE8(0.0f, -1.483529806137085f, t);
    item = (u8 **)(p + 0x10);
    for (i = 4; i >= 0; ) {
        u8 *m = *item;
        *(f32 *)(m + 0xF8) = func_0038DAB8(angle, step);
        if (t < 0.76f) {
            *(u8 *)(m + 0x31) = 1;
            *(u16 *)(m + 0x34) &= ~1;
            if (t < 0.39f) {
                *(u16 *)(m + 0x7C) = 3;
            } else if (t < 0.55f) {
                *(u16 *)(m + 0x7C) = 1;
            } else {
                *(u16 *)(m + 0x7C) = 0;
            }
        } else {
            *(u8 *)(m + 0x31) = 0;
            *(u16 *)(m + 0x34) |= 1;
        }
        ++item;
        --i;
        angle = func_0038DAB8(angle, 1.2566370964050293f);
    }
    *(f32 *)(D_L07_001DF41C[0] + (*(s32 *)(p + 0x24) << 8) + 0x18) =
        *(f32 *)(a0 + 0x18) + func_003C3BE8(-3.5f, 3.0f, extra);
}
