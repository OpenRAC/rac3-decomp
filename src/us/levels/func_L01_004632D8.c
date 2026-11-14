#include "common.h"

/* NTSC-U counterpart of func_L01_004668A0 (src/levels/shared/L01_00462978.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_004632D8 */
extern u8 *func_L01_0045E438(s32);
extern s32 func_0013D3E0(void);
extern u8 *D_L01_00221170[];

void func_L01_004632D8(u128_t *a0, u128_t *a1, s32 a2, s32 a3, s32 a4, f32 f)
{
    u8 *p;
    u8 *q;

    p = func_L01_0045E438(0x16);
    if (p != 0) {
        *(s32 *)(p + 4) = a2;
        p[1] = 0;
        *(f32 *)(p + 0xC) = f * 0.2f;
        p[9] = 0x74;
        p[3] = 0x44;
        p[8] = func_0013D3E0();
        q = p + 0x20;
        p[2] = **D_L01_00221170;
        *(s16 *)(p + 0xA) = a4;
        *(s16 *)(q + 0x18) = a4;
        *(f32 *)(q + 0x1C) = (f - *(f32 *)(p + 0xC)) / (f32)a4;
        *(s32 *)(q + 0x10) = a2;
        *(s32 *)(q + 0x14) = a3;
        *(u128_t *)q = *a1;
        *(u128_t *)(p + 0x10) = *a0;
        *(f32 *)(q + 0xC) = 0.00034444444f;
    }
}
/* localdecomp:end func_L01_004632D8 */
