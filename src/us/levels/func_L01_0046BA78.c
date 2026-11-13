#include "common.h"

/* NTSC-U version of func_L39_005D0378 (src/levels/shared/L39_005D0378.c): rand() is func_0013D3E0 here, spawn timer 18 - rand() % 15 (PAL 15 - rand() % 12) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0046BA78 */
extern void *func_L01_0045E438(s32);
extern u32 func_L01_00445B88(f32, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0013D3E0();
extern u8 *D_L01_00221260[];
void *func_L01_0046BA78(u128_t *a, u128_t *b, u8 kind, s32 arg) {
    u8 *p = func_L01_0045E438(0x52);
    u8 *s;
    f32 r;
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *a;
        s = p + 0x20;
        *(u128_t *)(p + 0x20) = *b;
        *(u32 *)(p + 4) = func_L01_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        r = func_0037E250(0.0f, 1.0f);
        *(f32 *)(s + 0x10) = r;
        p[8] = (s32)(r * 256.0f);
        p[2] = D_L01_00221260[0][func_0013D3E0() & 7];
        s[0x18] = kind;
        *(s16 *)(s + 0x14) = 0;
        *(s16 *)(s + 0x16) = 0;
        if (kind < 5) {
            *(f32 *)(p + 0xC) = func_0037E250(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 18 - func_0013D3E0() % 15;
        } else {
            *(s16 *)(p + 0xA) = 18;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        *(s32 *)(s + 0x1C) = arg;
    }
    return p;
}
/* localdecomp:end func_L01_0046BA78 */
