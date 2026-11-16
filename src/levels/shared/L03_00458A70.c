#include "common.h"

/* localdecomp:start func_L03_00458A70 */
typedef int u128_00458A70 __attribute__((mode(TI)));
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern u8 *D_L03_0021F358[];

u8 *func_L03_00458A70(u128_00458A70 *pos, u128_00458A70 *vel, s32 life, s32 a3, s32 color, f32 size) {
    u8 *p = func_L01_004618E0(0x30);
    if (p != 0) {
        s32 c = color & 0xFFFFFF;
        u8 *q;
        *(u128_00458A70 *)(p + 0x10) = *pos;
        p[9] = 0x12;
        p[3] = 0x44;
        *(s32 *)(p + 4) = c;
        p[1] = 0;
        p[2] = *D_L03_0021F358[0];
        *(f32 *)(p + 0xC) = size * 210000.0f;
        p[8] = func_00382468(0x100);
        q = p + 0x20;
        *(u128_00458A70 *)(p + 0x20) = *vel;
        *(f32 *)(q + 0x10) = 2.0f / (f32)life;
        *(s16 *)(p + 0xA) = life;
        *(s16 *)(q + 0x1C) = a3;
        *(s32 *)(q + 0x14) = c;
        *(s32 *)(q + 0x18) = color;
    }
    return p;
}
/* localdecomp:end func_L03_00458A70 */
