/* func_L32_003B66A0: 216 diff with --as ps2as (217 with the file's flags; the file needs @ps2as for lui/ori/mtc1 float constants, NEEDS-FLAGS --as ps2as). Structure and call order match; float locals f20-f24 get different registers (retail: f20 angle, f21 zero, f22 rnd, f23 DAB8 result, f24 one) and the early null tests compile to beql instead of beqz. Tried declaration order of locals (no effect). */
#include "common.h"

#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DEF44; __asm__(".extern D_L32_001DEF44, 4");
extern f32 D_L32_001DEF4C; __asm__(".extern D_L32_001DEF4C, 4");
extern f32 D_L32_001DEF48; __asm__(".extern D_L32_001DEF48, 4");
extern f32 D_L32_001DEF1C; __asm__(".extern D_L32_001DEF1C, 4");
extern f32 D_L32_001DEF64; __asm__(".extern D_L32_001DEF64, 4");
extern f32 D_L32_001DEF60; __asm__(".extern D_L32_001DEF60, 4");
extern f32 D_L32_001DEF58; __asm__(".extern D_L32_001DEF58, 4");
extern f32 D_L32_001DEF68; __asm__(".extern D_L32_001DEF68, 4");
extern s32 D_L32_001DEF30; __asm__(".extern D_L32_001DEF30, 4");
extern s32 D_L32_001DEF2C; __asm__(".extern D_L32_001DEF2C, 4");
extern s32 D_L32_001DEF28; __asm__(".extern D_L32_001DEF28, 4");
extern s32 D_L32_001DEF24; __asm__(".extern D_L32_001DEF24, 4");
extern f32 D_L32_001DEF20; __asm__(".extern D_L32_001DEF20, 4");
extern f32 D_L32_001DEF50; __asm__(".extern D_L32_001DEF50, 4");
extern f32 D_L32_001DEF18; __asm__(".extern D_L32_001DEF18, 4");
extern u8 D_L32_001E9980[];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L32_003B66A0(u8 *a0, u8 *a1) {
    u8 *p;
    f32 f20, f21, f22, f23, f24, f25, f26, f27;
    u16 v;
    f32 vC[4];
    f32 vA[4];
    f32 vB[4];
    if (a1 != 0) {
        p = *(u8 **)a1;
        if (p != 0 && *(u8 **)(a1 + 4) != 0) {
            v = *(u16 *)(a1 + 0xE);
            f25 = (f32)(v & 0xFF);
            f26 = D_L32_001DEF44 * (f32)*(s16 *)(a1 + 8) * (f32)(v >> 8) * 0.00390625f;
            f27 = func_003C4088(D_L32_001DEF4C, D_L32_001DEF48, (f32)*(u8 *)(a1 + 0xC) * 0.00390625f);
            if (*(u16 *)(a1 + 0xA) & 1) {
                f21 = 0.0f;
                f24 = 1.0f;
                f23 = func_0038DAB8(func_0038DB48(func_003824E0(-D_L32_001DEF1C, D_L32_001DEF1C)), 3.1415927f);
                f22 = func_003824E0(D_L32_001DEF64, D_L32_001DEF60);
                f20 = func_0038DB48(func_003824E0(f21, 6.2831855f));
                func_003C2F58(p, 0, a0 + 0x10);
                vA[0] = func_0038D098(f20) * D_L32_001DEF58;
                vA[1] = f21;
                vA[2] = func_0038D0B0(f20) * D_L32_001DEF58;
                vec_add_ab(a0 + 0x10, a0 + 0x10, vA);
                *(f32 *)(a0 + 0x14) += D_L32_001DEF68;
                vB[0] = func_0038D098(f23) * f22;
                vB[2] = func_0038D0B0(f23) * f22;
                *(f32 *)(a1 + 0x10) = vB[0];
                vB[1] = f21;
                *(f32 *)(a1 + 0x14) = vB[2];
                *(s32 *)(a1 + 0x18) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF30, D_L32_001DEF2C);
                *(s32 *)(a1 + 0x1C) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF28, D_L32_001DEF24);
            }
            *(f32 *)(a1 + 0x14) += D_L32_001DEF20;
            *(u128_t *)vC = *(u128_t *)(a0 + 0x10);
            vC[0] += *(f32 *)(a1 + 0x10);
            vC[2] += *(f32 *)(a1 + 0x14);
            if (func_003D3CB0(a0 + 0x10, vC, 1, p, 0) != 0) {
                if (*(s32 *)(D_L32_001E9980 + 0x18) != 0) {
                    f32 z = vC[2];
                    f32 d = *(f32 *)(a1 + 0x10) * 0.73f;
                    vC[0] = *(f32 *)(a0 + 0x10) + d;
                    if (*(f32 *)(a0 + 0x14) <= *(f32 *)(D_L32_001E9980 + 0x24)) {
                        vC[2] = z - d;
                    } else {
                        vC[2] = z + d;
                    }
                }
            }
            *(u128_t *)(a0 + 0x10) = *(u128_t *)vC;
            f21 = f25 + f26;
            f20 = 0.0f;
            *(f32 *)(a0 + 0xC) = func_003C4088(D_L32_001DEF50, f27, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), f20));
            *(s32 *)(a0 + 4) = func_0038DBD8(func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), f20), *(s32 *)(a1 + 0x18), *(s32 *)(a1 + 0x1C));
            *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) + ((s32)(func_L03_0034B148(*(s16 *)(a1 + 8) - *(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), D_L32_001DEF18) * 128.0f) << 24);
            *(u8 *)(a0 + 8) = (s32)func_003C4088(f25, f21, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), f20));
        }
    }
}

INCLUDE_ASM("asm/levels", func_L32_003B66A0);
