#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L08_00310D78);

/* localdecomp:start func_L08_00311438 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 D_001A30B0[];

u8 *func_L08_00311438(u8 *a0, u128_t *a1, u128_t *a2, s32 a3, s32 a4, f32 a5) {
    u8 *p;
    u8 *q;
    u8 *e;
    s32 idx;
    p = func_003C24B0(0xB7F, 0x80);
    if (p != 0) {
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0xFF;
        p[0x31] = 1;
        p[0x20] = 0;
        q = *(u8 **)(p + 0x68);
        *(long *)(p + 0x38) = *(long *)(a0 + 0x38);
        *(u128_t *)(p + 0x10) = *a2;
        *(u128_t *)q = *a1;
        *(u8 **)(q + 0x10) = a0;
        *(f32 *)(q + 0x14) = a5;
        *(f32 *)(q + 0x18) = func_00382538();
        *(f32 *)(q + 0x1C) = func_003824E0(0.25132743f, 0.7539823f);
        *(f32 *)(q + 0x20) = 1.0f;
        *(s32 *)(q + 0x24) = a4;
        p[0x23] = 0x5D;
        *(u16 *)(p + 0x34) |= 0x100;
        *(f32 *)(p + 0x2C) = func_003824E0(0.01f, 0.0125f) * *(f32 *)(q + 0x20);
        idx = *(s32 *)(q + 0x28);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) != p || e[0xD0] == 0) {
                *(s32 *)(q + 0x28) = func_003A52A0(0, 4, p);
            }
        } else {
            *(s32 *)(q + 0x28) = func_003A52A0(0, 4, p);
        }
    }
    return p;
}
/* localdecomp:end func_L08_00311438 */

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
