#include "common.h"

/* NTSC-U counterpart of func_L07_003BF158 (src/levels/07_annihilation_nation/L07_003BEAC0.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003BD810 */
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);

u8 *func_L07_003BD810(u8 *a0, u8 *a1, u8 *a2, s32 a3, u8 a4, s32 a5, s32 a6) {
    u8 *m;
    u8 *d;
    u8 *p10;
    u8 *pF0;

    m = func_003BCFB0(0x1A9F, 0x80);
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        d = *(u8 **)(m + 0x68);
        p10 = m + 0x10;
        pF0 = m + 0xF0;
        *(u128_t *)p10 = *(u128_t *)a1;
        *(u128_t *)pF0 = *(u128_t *)a2;
        *(u16 *)(m + 0x34) = *(u16 *)(a0 + 0x34);
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        m[0x30] = 0xFF;
        m[0x31] = 1;
        *(u16 *)(d + 0xC) = 0x1E;
        *(s32 *)(d + 0x10) = 0;
        m[0x20] = 1;
        *(s32 *)(d + 4) = a3;
        d[0xE] = a6;
        d[0xF] = a4;
        if (a6 > 0) {
            *(u16 *)(m + 0x34) |= 9;
            m[0x23] = (s32)((1.0f - (f32)a6 / (f32)a5) * 128.0f);
        }
        if (a6 + 1 < a5) {
            *(u8 **)d = func_L07_003BD810(m, p10, pF0, a3, a4, a5, a6 + 1);
        }
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L07_003BD810 */
