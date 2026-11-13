#include "common.h"

/* NTSC-U counterpart of func_L19_00465AD0 (src/levels/19_thran_asteroid_belt/L19_00465AD0.c) */
/* localdecomp:start func_L19_00461CC0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L19_0021F058_00461CC0[];
extern f32 D_L19_001D7EB8_00461CC0;
extern f32 D_L19_001D7EBC_00461CC0;
__asm__(".extern D_L19_001D7EBC_00461CC0, 4");
extern f32 D_L19_001D7EC0_00461CC0;
__asm__(".extern D_L19_001D7EC0_00461CC0, 4");
extern u8 *func_L01_0045E438(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);

u8 *func_L19_00461CC0(void *a0, void *a1, s32 a2) {
    u8 *p = func_L01_0045E438(0x60);
    u8 *q;
    f32 t;
    s32 v;
    if (p != 0) {
        p[9] = 0x42;
        p[3] = 0x44;
        p[1] = 0;
        q = p + 0x20;
        p[2] = *D_L19_0021F058_00461CC0[0];
        *(f32 *)(p + 0xC) = func_0037E250(D_L19_001D7EB8_00461CC0, D_L19_001D7EBC_00461CC0) * 0.5f * 210000.0f;
        p[8] = func_0037E1D8(0xFF);
        *(s32 *)(p + 4) = 0x40808080;
        *(s16 *)(p + 0xA) = a2;
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(u128_t *)(p + 0x20) = *(u128_t *)a1;
        *(s32 *)(q + 0xC) = 0;
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0xC) + *(f32 *)(p + 0xC);
        v = func_0037E208(0, 3);
        t = D_L19_001D7EC0_00461CC0;
        *(s32 *)(q + 0x14) = v;
        *(s32 *)(q + 0x10) = a2 / 2;
        *(f32 *)(q + 0x1C) = func_0037E250(t, t + 2.0f) * 0.00027777778f;
    }
    return p;
}
/* localdecomp:end func_L19_00461CC0 */
