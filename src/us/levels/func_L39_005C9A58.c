#include "common.h"

/* NTSC-U counterpart of func_L39_005CBE30 (src/levels/shared/L39_005CBE30.c) */
/* localdecomp:start func_L39_005C9A58 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C7B98(s32);
extern u32 func_L01_00445B88(f32, f32, f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_0019D650(void);
extern u8 *D_L39_00296948 __attribute__((section(".data")));

u8 *func_L39_005C9A58(void *a0, void *a1, u8 a2, s32 a3) {
    u8 *p = func_003C7B98(0x2A);
    u8 *data;
    f32 r;
    if (p) {
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        data = p + 0x20;
        *(u128_t *)(p + 0x20) = *(u128_t *)a1;
        *(u32 *)(p + 4) = func_L01_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        r = func_L39_005B2510(0.0f, 1.0f);
        *(f32 *)(data + 0x10) = r;
        p[8] = (s32)(r * 256.0f);
        p[2] = D_L39_00296948[func_0019D650() & 7];
        data[0x18] = a2;
        *(s16 *)(data + 0x14) = 0;
        *(s16 *)(data + 0x16) = 0;
        if (a2 < 5) {
            *(f32 *)(p + 0xC) = func_L39_005B2510(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 18 - func_0019D650() % 15;
        } else {
            *(s16 *)(p + 0xA) = 18;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        *(s32 *)(data + 0x1C) = a3;
    }
    return p;
}
/* localdecomp:end func_L39_005C9A58 */
