#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005D0378 */
extern void *func_003CD108(s32);
extern u32 func_L01_00448CC0(f32, f32, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0019D510();
extern u8 *D_L39_00296960[];
void *func_L39_005D0378(u128_t *a, u128_t *b, u8 kind, s32 arg) {
    u8 *p = func_003CD108(0x52);
    u8 *s;
    f32 r;
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *a;
        s = p + 0x20;
        *(u128_t *)(p + 0x20) = *b;
        *(u32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        r = func_L39_005B4410(0.0f, 1.0f);
        *(f32 *)(s + 0x10) = r;
        p[8] = (s32)(r * 256.0f);
        p[2] = D_L39_00296960[0][func_0019D510() & 7];
        s[0x18] = kind;
        *(s16 *)(s + 0x14) = 0;
        *(s16 *)(s + 0x16) = 0;
        if (kind < 5) {
            *(f32 *)(p + 0xC) = func_L39_005B4410(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 15 - func_0019D510() % 12;
        } else {
            *(s16 *)(p + 0xA) = 15;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        *(s32 *)(s + 0x1C) = arg;
    }
    return p;
}
/* localdecomp:end func_L39_005D0378 */
