#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_00310D78);

INCLUDE_ASM("asm/levels", func_L08_00311438);

/* localdecomp:start func_L08_003115B0 */
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_003190A8(void *, s32, f32, s32, f32, s32, s32, f32);

void func_L08_003115B0(u8 *arg0) {
    u8 *s3 = *(u8 **)(arg0 + 0x68);

    switch (arg0[0x20]) {
    case 0: {
        f32 f1 = *(f32 *)(arg0 + 0x2C) * 45.0f * *(f32 *)(s3 + 0x20);
        s32 r1 = func_00382498(0x5F, 0x6F);
        f32 f2;
        s32 r2;
        func_L01_003190A8(arg0 + 0x10, 0x103080, f1, r1, func_00382538(), 0xB, 2, 1.0f);
        f2 = *(f32 *)(arg0 + 0x2C) * 45.0f * 0.5f * *(f32 *)(s3 + 0x20);
        r2 = func_00382498(0x6F, 0x7F);
        func_L01_003190A8(arg0 + 0x10, 0x3F3F3F, f2, r2, func_00382538(), 0xB, 2, 1.0f);
        return;
    }
    case 1: {
        f32 f1 = *(f32 *)(arg0 + 0x2C) * 45.0f * *(f32 *)(s3 + 0x20);
        s32 r1 = func_00382498(0x5F, 0x6F);
        f32 f2;
        s32 r2;
        func_L01_003190A8(arg0 + 0x10, 0x103080, f1, r1, func_00382538(), 0xB, 2, 1.0f);
        f2 = *(f32 *)(arg0 + 0x2C) * 45.0f * 0.5f * *(f32 *)(s3 + 0x20);
        r2 = func_00382498(0x6F, 0x7F);
        func_L01_003190A8(arg0 + 0x10, 0x3F3F3F, f2, r2, func_00382538(), 0xB, 2, 1.0f);
        return;
    }
    }
}
/* localdecomp:end func_L08_003115B0 */
