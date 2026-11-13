#include "common.h"

/* NTSC-U counterpart of func_L19_00349880 (src/levels/shared/L19_00349880.c): 0.0006 -> 0.000416667; 0.06 -> 0.05 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_00348AD0 */
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_00452F60(u8 *);
extern f32 func_003C41A0(void *, void *, f32, f32, f32, f32);

void func_L19_00348AD0(u8 *object)
{
    u8 *vars = *(u8 **)(object + 0x68);
    switch (object[0x20]) {
    case 0:
        *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 0.2f;
        *(u32 *)(vars + 0x6C) |= 1;
        *(u128_t *)(vars + 0xA0) = *(u128_t *)(object + 0x10);
        func_L01_00441FB8(object, 1, -1);
        break;
    case 1:
        if (func_L01_00452F60(object) != 0)
            func_L01_00441FB8(object, 2, -1);
        break;
    case 2:
        *(f32 *)(object + 0x18) = *(f32 *)(vars + 0xB0) + *(f32 *)(vars + 0xA8);
        if (func_L01_00452F60(object) == 0) {
            *(f32 *)(object + 0x18) = *(f32 *)(vars + 0xB0) + *(f32 *)(vars + 0xA8);
            func_L01_00441FB8(object, 3, -1);
        }
        break;
    case 3:
        func_003C41A0(object + 0x18, vars + 0xB4, *(f32 *)(vars + 0xA8) + 2.8f,
                      0.000416666677f, 0.000416666677f,
                      0.0500000045f);
        if (*(f32 *)(vars + 0xA8) + 2.8f <= *(f32 *)(object + 0x18))
            *(u16 *)(object + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L19_00348AD0 */
