#include "common.h"

/* NTSC-U counterpart of func_L34_00352018 (src/levels/34_vidcomic_3/L34_003515A0.c): 0.1 -> 0.0833333 */
/* localdecomp:start func_L34_003512F8 */
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);

void func_L34_003512F8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(p + 0x144) = 1;
    r = func_003824E0(0.8f, 1.2f) * 0.0833333358f;
    *(f32 *)(p + 0x178) = r;
    *(f32 *)(p + 0x14C) = func_00382538();
    *(f32 *)(p + 0x154) = *(f32 *)(a0 + 0x18);
}
/* localdecomp:end func_L34_003512F8 */
