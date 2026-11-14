#include "common.h"

/* NTSC-U counterpart of func_L20_003E56D8 (src/levels/20_final_boss/L20_003E5058.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003E3958 */
extern u8 D_L20_001D66B0[8];
__asm__(".extern D_L20_001D66B0, 16");
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00467DA8(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);

u8 *func_L20_003E3958(u8 *a0, u8 *a1, u8 *a2, u8 a3, s32 a4) {
    u8 *m;
    u8 *d;
    u8 *p;
    u128_t q;

    m = func_003BCFB0(0x1CC1, 0x40);
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        m[0x31] = 1;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x30] = 0xFF;
        d = *(u8 **)(m + 0x68);
        q = *(u128_t *)a1;
        p = d + 0x10;
        *(u128_t *)(m + 0x10) = q;
        *(u128_t *)p = q;
        *(u128_t *)d = *(u128_t *)a2;
        *(f32 *)(m + 0xF8) = func_00388A28(*(f32 *)a2, *(f32 *)(a2 + 4));
        *(f32 *)(m + 0xF4) = -func_00388A28(func_003887A0(a2), *(f32 *)(a2 + 8));
        *(f32 *)(d + 0x2C) = 0.5f;
        d[0x24] = a3;
        *(s32 *)(d + 0x20) = a4;
        d[0x25] = 0x14;
        *(s32 *)(d + 0x34) = 0;
        *(s32 *)(d + 0x30) = 0;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
        func_L01_00441FB8(m, 1, -1);
        func_L01_00467DA8(p, 10, 0x3F00005F, 0, 2, D_L20_001D66B0, 0, 2.0f, 3.0f, 0.0f);
    }
    return m;
}
/* localdecomp:end func_L20_003E3958 */
