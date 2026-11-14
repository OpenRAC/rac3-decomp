#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_00350718);

INCLUDE_ASM("asm/levels", func_L09_00350968);

/* localdecomp:start func_L09_00350B30 */
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L09_00350CB0(u8 *, s32, f32, s32, f32, f32, s32, s32, u8 *);

void func_L09_00350B30(u8 *a0) {
    f32 x = *(f32 *)(a0 + 0x2C) * 90.0f;
    func_L09_00350CB0(a0 + 0x10, 0x80103080, x, func_00382498(0x5F, 0x6F), func_00382538(), 1.0f, 0x1C, 2, a0);
    {
        f32 half = *(f32 *)(a0 + 0x2C) * 90.0f * 0.5f;
        func_L09_00350CB0(a0 + 0x10, -1, half, func_00382498(0x6F, 0x7F), func_00382538(), 1.0f, 8, 2, a0);
    }
}
/* localdecomp:end func_L09_00350B30 */
