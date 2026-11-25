/* Unlinked NTSC-U draft. 48 to 41 differences. The native phase step is restored, but the first branch delay slot and saved-register allocation still differ. */
/* Unlinked NTSC-U candidate: 41: conditional layout and saved-register swap. */
#include "common.h"

/* NTSC-U counterpart of PAL func_L07_003B3C78. */
/* localdecomp:start func_L07_003B2388 */
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_L07_003B24C0(void *, s32, f32);

void func_L07_003B2388(void *self) {
    u8 *arg0 = self;
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 v, r;
    s32 i;

    *(f32 *)(p + 0x658) += 0.0075f;
    if (*(f32 *)(p + 0x658) > 1.5f) {
        *(f32 *)(p + 0x658) -= 1.5f;
    }

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            f32 a = *(f32 *)(p + 0x658);
            if (a < 1.0f) {
                v = a;
                goto interpolate;
            }
            v = 1.5f - a;
            v *= 2.0f;
        } else {
            f32 a = *(f32 *)(p + 0x658);
            if (a < 0.5f) {
                v = a * 2.0f;
            } else {
                v = 1.5f - a;
            }
        }
    interpolate:
        r = func_003BE6A8(-7.0f, 7.0f, v);
        func_L07_003B24C0(arg0, i, r + (i == 0 ? -2.0f : 2.0f));
    }
}
/* localdecomp:end func_L07_003B2388 */
