/* func_L32_003BE4E8: matches with `--as ps2as` (tools/check.py MATCH), but its file
   src/levels/32_vidcomic_4/L32_003BE008.c cannot take @ps2as: the matched func_L32_003BED60 there need the default assembler
   (24/20/46 rows differ under ps2as). Lands when the file is split or the others match under ps2as. */
#include "common.h"

extern s32 D_L32_001DF1DC;
__asm__(".extern D_L32_001DF1DC, 4");
void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L32_003BE4E8(u8 *a0) {
    u8 *p;
    f32 f20;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 1) {
        f20 = 1.0f - (f32)*(s32 *)(p + 0x4) / (f32)*(s32 *)(p + 0x8);
    } else {
        f20 = 1.0f;
    }
    func_003D9508(a0 + 0x10, 0x43, D_L32_001DF1DC, 1, f20 * 2.25f, -0.1f, *(f32 *)(p + 0x10));
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, f20, 0.0f, -*(f32 *)(p + 0xC));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, f20 + f20, 0.025f, -*(f32 *)(p + 0x10));
}
