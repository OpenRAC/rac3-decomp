#include "common.h"

/* NTSC-U counterpart of func_L07_003CAE10 (src/levels/shared/L07_003CAE10.c): 17 -> 20; 0.0588235 -> 0.05 */
/* localdecomp:start func_L07_003C9438 */
/* log: PAL port of the NTSC draft (func_L07_003C9438): 0x11 frames, 0.05882353f */
#include "vu0.h"

typedef int u128_003CAE10 __attribute__((mode(TI)));

extern u8 *func_003BCFB0(s32, s32);

u8 *func_L07_003C9438(u128_003CAE10 *pos, u128_003CAE10 *vec, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, f32 fa, f32 fb)
{
    u8 *o = func_003BCFB0(0x1B35, 0x80);
    u8 *v;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        *(u16 *)(o + 0x34) |= 0x41;
        *(s32 *)(o + 0xB8) = a2;
        o[0x20] = 0;
        v = *(u8 **)(o + 0x68);
        *(u128_003CAE10 *)(o + 0x10) = *pos;
        *(s32 *)(v + 0x40) = t1;
        *(s32 *)(v + 0x44) = t2;
        *(s32 *)(v + 0x24) = 0x14;
        *(f32 *)(v + 0x28) = 0.0500000007f;
        *(f32 *)(v + 0x20) = fa;
        *(u128_003CAE10 *)v = *vec;
        *(s32 *)(v + 0x3C) = t0;
        qzero(v + 0x10);
        *(f32 *)(v + 0x34) = fb;
        *(s32 *)(v + 0x38) = a3;
        *(s32 *)(v + 0x30) = 0;
    }
    return o;
}
/* localdecomp:end func_L07_003C9438 */
