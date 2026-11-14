#include "common.h"

/* NTSC-U counterpart of func_L12_003D50C8 (src/levels/shared/L12_003D4B18.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L12_003D3430 */
extern s32 D_001A65C0[];
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388770(void *);
extern void func_00388BD0(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C26C8(void *);

u8 *func_L12_003D3430(u8 *a0, u8 *a1, u8 *a2, u8 *a3, f32 f12) {
    u8 *m;
    u8 *d;

    m = func_003BCFB0(0x1C17, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        *(u8 **)(m + 0xB8) = a0;
        *(u8 **)(d + 0x28) = a1;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.75f;
        *(u128_t *)(m + 0x10) = *(u128_t *)a2;
        *(f32 *)(m + 0xF4) = -func_00388A28(func_003887A0(a3), *(f32 *)(a3 + 8));
        *(f32 *)(m + 0xF8) = func_00388A28(*(f32 *)a3, *(f32 *)(a3 + 4));
        func_00388BD0(m + 0xC0, m + 0xF0);
        *(u128_t *)d = *(u128_t *)a3;
        *(f32 *)(d + 0x38) = func_00388770(a3);
        *(f32 *)(d + 0x20) = f12;
        if (D_001A65C0[0] != 0) {
            *(s32 *)(d + 0x24) = 0x1A4;
        } else {
            *(s32 *)(d + 0x24) = 0xA0;
        }
        *(s32 *)(d + 0x2C) = 0;
        *(s32 *)(d + 0x3C) = -1;
        func_L01_00441FB8(m, 1, -1);
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L12_003D3430 */
