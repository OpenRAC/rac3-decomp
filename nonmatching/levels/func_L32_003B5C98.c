/* func_L32_003B5C98: 156 diff with the file's flags. Remaining: s-register roles (retail a0=s0,a1=s1,v=s2,d=s3; mine a0/a1/v permuted), then float/scheduling cascade. Tried d loaded before m test, early returns, nested ifs. */
#include "common.h"

extern f32 D_L32_001DEF00;
extern f32 D_L32_001DEF04;
extern f32 D_L32_001DEF14;
extern f32 D_L32_001DEEFC;
extern s32 D_L32_001DEEF4;
extern s32 D_L32_001DEEF0;
extern s32 D_L32_001DEEEC;
extern s32 D_L32_001DEEE8;
extern f32 D_L32_001DEEE4;
extern f32 D_L32_001DEEE0;
extern s32 D_L32_001DF9C0[];
extern u8 D_L32_001E24A0[];
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);

void func_L32_003B5C98(u8 *a0, u8 *a1) {
    u8 *m;
    u8 *v;
    f32 f20;
    f32 f1;
    f32 f2;
    s32 n;

    u8 *d;
    if (a1 != 0 && (m = *(u8 **)a1, d = D_L32_001E24A0, m != 0) && (v = *(u8 **)(m + 0x68)) != 0 && d != 0) {
        if (a1[9] & 1) {
            func_003C2F58(m, 0, a0 + 0x10);
            *(f32 *)(a0 + 0x18) += D_L32_001DEF00 * 0.5f;
            *(u128_t *)(a0 + 0x20) = *(u128_t *)(a0 + 0x10);
            *(f32 *)(a0 + 0x2C) = 1.0f;
            *(f32 *)(a0 + 0x28) -= D_L32_001DEF00;
            *(f32 *)(a0 + 0x1C) = D_L32_001DEF14;
            *(f32 *)(a1 + 0xC) = D_L32_001DEF04 * *(f32 *)(v + 0x140);
            a0[3] = d[0x10];
        }
        *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(a1 + 0xC);
        *(f32 *)(a0 + 0x20) = *(f32 *)(a0 + 0x20) + *(f32 *)(a1 + 0xC);
        f1 = D_L32_001DEEFC - D_L32_001DEF00;
        n = D_L32_001DEEF4;
        f20 = 1.0f - (f32)*(s16 *)(a0 + 0xA) * 0.25f / (f32)a1[8];
        *(f32 *)(a0 + 0x18) += f1 / ((f32)a1[8] * 4.0f);
        *(f32 *)(a0 + 0x28) -= f1 / ((f32)a1[8] * 4.0f);
        *(f32 *)(a0 + 0x1C) += D_L32_001DEF14 * f1 / (D_L32_001DEF00 * 4.0f * (f32)a1[8]);
        *(s32 *)(a0 + 4) = func_0038DBD8(func_L03_0034B440(0, 0, 5, (f32)(D_L32_001DF9C0[0] % n), (f32)n, 1.0f), D_L32_001DEEEC, D_L32_001DEEF0);
        {
            s32 k = D_L32_001DEEE8;
            u32 c;
            f32 q = func_003C4088(D_L32_001DEEE0, D_L32_001DEEE4, func_L03_0034B440(0, 0, 5, (f32)(D_L32_001DF9C0[0] % k), (f32)k, 1.0f)) * (1.0f - f20);
            c = (*(u32 *)(a0 + 4) & 0xFFFFFF) + ((s32)q << 24);
            *(u32 *)(a0 + 0xC) = c;
            *(u32 *)(a0 + 4) = c;
        }
    }
}

INCLUDE_ASM("asm/levels", func_L32_003B5C98);
