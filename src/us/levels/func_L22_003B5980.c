#include "common.h"

/* NTSC-U counterpart of func_L22_003B71D0 (src/levels/shared/L22_003B71D0.c): the call's time 12.0f (PAL 10.0f, 60 Hz against 50 Hz) */
/* localdecomp:start func_L22_003B5980 */
extern u8 *D_001D52FC;
extern u8 D_001D5477 __attribute__((section(".data")));

extern s32 D_L22_001E2080;
__asm__(".extern D_L22_001E2080, 16");
extern void func_L01_0050BB98(s32, s32, f32);

s32 func_L22_003B5980(u8 *obj, u8 *other) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 r = 0;
    s32 b;

    if (*(s32 *)(sub + 0x480) != 0) {
        if (other[0x60] & 2) {
            *(s32 *)(sub + 0x480) = 0;
        }
    }
    b = *(s32 *)(D_001D52FC + 0x1A0);
    if (b & 0x10) {
        r = 1;
    } else if (b & 0x20) {
        r = 2;
    } else if (b & 0x40) {
        r = 3;
    } else if (b & 0x80) {
        r = 4;
    } else if (b & 0x1000) {
        r = 5;
    } else if (b & 0x4000) {
        r = 7;
    } else if (b & 0x2000) {
        r = D_001D5477 == 0 ? 6 : 8;
    } else if (b & 0x8000) {
        r = D_001D5477 == 0 ? 8 : 6;
    }
    if (D_L22_001E2080 != r) {
        if (*(s32 *)(sub + 0x480) == 0 || r > 0) {
            func_L01_0050BB98(r == 0 ? 1 : r + 5, 0, 12.0f);
        }
    }
    return r;
}
/* localdecomp:end func_L22_003B5980 */
