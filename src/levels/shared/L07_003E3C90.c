#include "common.h"

/* localdecomp:start func_L07_003E3C90 */
typedef int u128_003E3C90 __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern f32 func_00382538(void);

u8 *func_L07_003E3C90(u8 *parent, u128_003E3C90 *pos, u128_003E3C90 *vec, f32 fa, s32 a3, s32 t0, s32 t1, f32 fb, f32 fc)
{
    u8 *o = func_003C24B0(0x1EC4, 0x80);
    u8 *v;
    u128_003E3C90 t;

    if (o != 0) {
        func_L01_00456160(o, parent);
        o[0x20] = 0;
        o[0x30] = *(u16 *)(o + 0x32) = 0xFF;
        v = *(u8 **)(o + 0x68);
        *(u128_003E3C90 *)(o + 0x10) = *pos;
        t = *vec;
        *(s32 *)(v + 0x28) = a3;
        *(u128_003E3C90 *)v = t;
        *(u8 **)(v + 0x1C) = parent;
        *(f32 *)(v + 0x10) = func_00382538();
        *(f32 *)(v + 0x24) = fa;
        *(s32 *)(v + 0x18) = -1;
        *(s32 *)(v + 0x14) = 0;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * fb;
        *(s32 *)(v + 0x2C) = t0;
        *(f32 *)(v + 0x34) = fc;
        *(s32 *)(v + 0x38) = t1;
        *(s32 *)(o + 0x98) = 0;
    }
    return o;
}
/* localdecomp:end func_L07_003E3C90 */
