#include "common.h"

/* localdecomp:start func_L30_004437E8 */
typedef int u128_004437E8 __attribute__((mode(TI)));

extern u8 *D_L30_0021F28C[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);

u8 *func_L30_004437E8(void *pos, s32 rgba, s32 a2, s32 life, f32 size, f32 end) {
    u8 *p = func_L01_004618E0(0x7D);
    u8 *q;

    if (p != 0) {
        *(u128_004437E8 *)(p + 0x10) = *(u128_004437E8 *)pos;
        *(s32 *)(p + 4) = rgba;
        q = p + 0x20;
        p[9] = 0x44;
        p[1] = 0;
        p[3] = 0x44;
        p[2] = *D_L30_0021F28C[0];
        *(s16 *)(p + 0xA) = life;
        *(f32 *)(p + 0xC) = size * 210000.0f;
        p[8] = func_00382468(0xFF);
        *(s32 *)(q + 4) = rgba;
        *(s32 *)(q + 8) = a2;
        *(f32 *)(q + 0) = (end - size) / (f32)life * 210000.0f;
        *(f32 *)(q + 0xC) = 1.0f / (f32)life;
    }
    return p;
}
/* localdecomp:end func_L30_004437E8 */
