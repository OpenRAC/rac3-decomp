#include "common.h"

/* localdecomp:start func_L39_005CBE30 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003CD108(s32);
extern u32 func_L01_00448CC0(f32, f32, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0019D510(void);
extern u8 *D_L39_00296848 __attribute__((section(".data")));

u8 *func_L39_005CBE30(void *a0, void *a1, u8 a2, s32 a3) {
    u8 *p = func_003CD108(0x2A);
    u8 *data;
    f32 r;
    if (p) {
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        data = p + 0x20;
        *(u128_t *)(p + 0x20) = *(u128_t *)a1;
        *(u32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        r = func_L39_005B4410(0.0f, 1.0f);
        *(f32 *)(data + 0x10) = r;
        p[8] = (s32)(r * 256.0f);
        p[2] = D_L39_00296848[func_0019D510() & 7];
        data[0x18] = a2;
        *(s16 *)(data + 0x14) = 0;
        *(s16 *)(data + 0x16) = 0;
        if (a2 < 5) {
            *(f32 *)(p + 0xC) = func_L39_005B4410(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 15 - func_0019D510() % 12;
        } else {
            *(s16 *)(p + 0xA) = 15;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        *(s32 *)(data + 0x1C) = a3;
    }
    return p;
}
/* localdecomp:end func_L39_005CBE30 */
