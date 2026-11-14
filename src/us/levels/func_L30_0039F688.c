#include "common.h"

/* NTSC-U counterpart of func_L30_003A10B8 (src/levels/shared/L30_003A10B8.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L30_0039F688 */
typedef struct { u8 pad0[0x100]; f32 x100; u8 pad1[0x35C - 0x104]; u8 *x35C; s32 x360; } S_003A10B8;
extern S_003A10B8 D_001A4BE0;
extern f32 D_L30_001E2258_0039F688 __attribute__((section(".data")));
extern f32 D_L30_001DE8C0;
extern f32 func_00389468(f32, f32);

/* When the hero's lock target is this moby, sets the hero's turn rate to a global rate per frame,
 * positive or negative by whether the angle to a global target is under 90 degrees. */
void func_L30_0039F688(u8 *a0) {
    S_003A10B8 *h = &D_001A4BE0;
    if (h->x35C == a0 && h->x360 != 0) {
        if (func_00389468(*(f32 *)(a0 + 0xF8), D_L30_001E2258_0039F688) < 1.5707964f) {
            h->x100 = D_L30_001DE8C0 * 0.0166666675f;
        } else {
            h->x100 = -(D_L30_001DE8C0 * 0.0166666675f);
        }
    }
}
/* localdecomp:end func_L30_0039F688 */
