#include "common.h"
#include "vu0.h"

/* declared by functions of L20_003F1A78.c, which this file was cut from */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L20_003F4320 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

u8 *func_L20_003F4320(u8 *a0, f32 x, f32 y) {
    u8 *o;
    u8 *p;

    o = func_003C24B0(0x1D91, 0xB0);
    if (o == 0) {
        return 0;
    }
    o[0x20] = 0;
    o[0x30] = 0xFF;
    *(s16 *)(o + 0x32) = 0xFF;
    p = *(u8 **)(o + 0x68);
    *(vu0_q *)(o + 0x10) = *(vu0_q *)a0;
    *(f32 *)(p + 0x90) = 10.0f;
    qzero(p);
    *(f32 *)(p + 0x94) = 10.0f;
    *(f32 *)(p + 0x98) = x;
    *(f32 *)(p + 0x9C) = y;
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L20_003F4320 */
