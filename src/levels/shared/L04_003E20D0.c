#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L04_003E20D0);

/* localdecomp:start func_L04_003E2390 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L04_001DF040, 4");
__asm__(".extern D_L04_001DF030, 4");
__asm__(".extern D_L04_001DF064, 4");
extern f32 D_L04_001DF040;
extern s32 D_L04_001DF030;
extern f32 D_L04_001DF064;
u8 *func_L04_003E2390(s32 a0, u128_t *pos, u128_t *rot, s32 a3, s32 t0, f32 f12, f32 f13, f32 f14) {
    u8 *m;
    u8 *p;
    u8 *q;
    m = func_003C24B0(0x1B29, 0x200);
    if (m != 0) {
        *(s32 *)(m + 0xB8) = a0;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 2.0f;
        *(u16 *)(m + 0x34) |= 0x20;
        p = *(u8 **)(m + 0x68);
        *(u8 **)(p + 0xC) = p + 0x30;
        func_0038CB78(p + 0x30, 0, 0x20);
        *(u128_t *)(m + 0x10) = *pos;
        q = m + 0xF0;
        *(u128_t *)q = *rot;
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), D_L04_001DF040 * 0.017453292f);
        func_0038D308(m + 0xC0, q);
        *(s32 *)(m + 0x78) = D_L04_001DF030;
        *(s32 *)(p + 0x50) = a3;
        *(f32 *)(p + 0x54) = f12;
        *(s32 *)(p + 0x58) = t0;
        *(f32 *)(p + 0x5C) = f13;
        *(f32 *)(p + 0x64) = *(f32 *)(m + 0xF8);
        *(s32 *)(p + 0x68) = 0;
        if (f14 != *(f32 *)(p + 0x68))
            *(f32 *)(p + 0x6C) = f14;
        else
            *(f32 *)(p + 0x6C) = D_L04_001DF064;
        func_0038CB78(p + 0x70, 0, 0x80);
        func_0038CB78(p + 0xF0, 0, 0x80);
        func_0038CB78(p + 0x170, 0, 0x80);
        func_L01_004450F0(m, 1, -1);
    }
    return m;
}
/* localdecomp:end func_L04_003E2390 */
