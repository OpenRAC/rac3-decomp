/* functional: high. Takes the farthest squared distance from the object to its active slot targets (slots at +0x50, stride 0x30, 4 of them) and turns it into two fade values: the state byte at +0x30 and halfword at +0x32 (distance+0.99 biased by two globals and clamped to two caps); with no active slot, byte = cap, halfword = 0. Retail has two extra nops around the sqrt (assembler), irrelevant to behaviour. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L04_0035C1B8 */
extern f32 func_L01_0040E548(void *, void *);
__asm__(".extern D_L04_001DD4E8, 4");
__asm__(".extern D_L04_001DD4EC, 4");
__asm__(".extern D_L04_001DD4F0, 4");
__asm__(".extern D_L04_001DD4F4, 4");
extern f32 D_L04_001DD4E8;
extern s32 D_L04_001DD4EC;
extern f32 D_L04_001DD4F0;
extern s32 D_L04_001DD4F4;

void func_L04_0035C1B8(u8 *a0, u8 *a1) {
    f32 max;
    f32 d;
    s32 i;
    s32 v;
    u8 *p;

    max = 0.0f;
    p = a1 + 0x50;
    for (i = 3; i >= 0; i--) {
        if (*(s32 *)(p + 0x20) != 0) {
            d = func_L01_0040E548(a0 + 0x10, p + 0x10);
            if (max < d) {
                max = d;
            }
        }
        p += 0x30;
    }
    if (max > 0.0f) {
        max = sqrt_asm(max) + 0.99f;
        v = (s32)(max + D_L04_001DD4E8);
        if (v > D_L04_001DD4EC) {
            v = D_L04_001DD4EC;
        }
        a0[0x30] = v;
        v = (s32)(max + D_L04_001DD4F0);
        if (v > D_L04_001DD4F4) {
            v = D_L04_001DD4F4;
        }
        *(s16 *)(a0 + 0x32) = v;
    } else {
        a0[0x30] = D_L04_001DD4EC;
        *(s16 *)(a0 + 0x32) = 0;
    }
}
/* localdecomp:end func_L04_0035C1B8 */
