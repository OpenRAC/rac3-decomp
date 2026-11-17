/* func_L32_003B37A8: 92 diff with --flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division' --as ps2as (file flags give a vu0 spill compile error; needs those flags). Remaining: float reg numbering in the vsub tail, s0/s1 roles of tmp and a0+0x10. Tried switch, buf[0x40] holding both stack vectors, split locals. */
#include "common.h"

#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DECF0;
extern f32 D_L32_001DED2C;
extern f32 D_L32_001DECDC;
extern f32 D_L32_001DECE0;
extern s32 D_L32_001DECE4;
extern u8 D_L32_001D66B0[];
extern u8 D_L32_001E2440[];
extern u8 D_L32_001E2460[];
extern void func_L32_003B4310(void *);
extern void func_L32_003B3A00(void *);
extern void func_L32_003B41E8(void *, void *, f32, f32, f32 *);
extern s32 func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern void func_L01_00404A10(void *, s32);
extern s32 func_003D4D00(f32, void *, s32, void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

__asm__(".extern D_L32_001DECF0, 4");
__asm__(".extern D_L32_001DED2C, 4");
__asm__(".extern D_L32_001DECDC, 4");
__asm__(".extern D_L32_001DECE0, 4");
__asm__(".extern D_L32_001DECE4, 4");

void func_L32_003B37A8(u8 *a0) {
    u8 buf[0x40] __attribute__((aligned(16)));
    u8 *tmp;
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 f;
    f32 g;

    if (a0[0x20] == 0) {
        func_L32_003B4310(a0);
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_004561B8(a0)) {
            func_L01_004AAC98(8, 0, a0, 0x19D1);
        }
        f = *(f32 *)(v + 0x34) + D_L32_001DECF0;
        *(f32 *)(v + 0x34) = f;
        if (1.0f <= f) {
            func_L01_004450F0(a0, 2, -1);
        } else {
            *(u128_t *)buf = *(u128_t *)(a0 + 0x10);
            func_L32_003B41E8(a0, a0 + 0x10, -1.0f, 0.01f, (f32 *)(v + 0x34));
            vec_sub_ab(v + 0x20, a0 + 0x10, buf);
            g = *(f32 *)(v + 0x48) + D_L32_001DED2C;
            *(f32 *)(v + 0x48) = g - (f32)(s32)g;
            if (0.0f < *(f32 *)(v + 0x34)) {
                func_L30_0034C8A8(D_L32_001E2440, a0);
                func_L01_00404A10((void *)func_L32_003B3A00, (s32)a0);
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            tmp = buf + 0x10;
            *(u128_t *)(a0 + 0x10) = *(u128_t *)(v + 0x10);
            p = a0 + 0x10;
            func_L30_0034CC28(tmp, a0, D_L32_001D66B0, 1, 0, D_L32_001DECDC);
            *(s32 *)(tmp + 0x14) |= 0x30000;
            func_003D4D00(D_L32_001DECE0, p, 1, a0, tmp);
            *(s32 *)(v + 0x38) = D_L32_001DECE4;
            func_L01_004AAC98(9, 0, a0, 0x19D1);
        }
        *(f32 *)(v + 0x3C) = *(f32 *)(v + 0x3C) - D_L32_001DECF0;
        if (*(f32 *)(v + 0x3C) < 0.0f) {
            *(f32 *)(v + 0x3C) = 0.0f;
        }
        if (0.0f < *(f32 *)(v + 0x3C)) {
            func_L30_0034C8A8(D_L32_001E2460, a0);
            func_L01_00404A10((void *)func_L32_003B3A00, (s32)a0);
        }
        if (func_0038CAD0(v + 0x38)) {
            func_003C2880(a0);
        }
    }
}

INCLUDE_ASM("asm/levels", func_L32_003B37A8);
