#include "common.h"

/* NTSC-U counterpart of func_L02_003514D0 (src/levels/02_florana/L02_0034FE10.c): 0.0024 -> 0.00166667; 0.04 -> 0.0333333; 0.00251327 -> 0.00174533; 0.0418879 -> 0.0349066 */
void func_L01_004A6DF8(void *, s32);
void func_003C3A10(void *, s32, s32, s32);

/* localdecomp:start func_L02_003503C0 */
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L02_003503C0(u8 *a0)
{
    u8 *p;
    f32 zero = 0.0f;

    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) - zero;
    *(u32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
    p = *(u8 **)(a0 + 0x68);
    func_L01_004A6DF8(a0, 1);
    *(f32 *)(p + 0x190) = 0.5f;
    p[0x1A8] = 3;
    p[0x170] = 0xB;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1D8] = 1;
    p[0x1D9] = 1;
    p[0x171] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1DB] = 0x1C;
    p[0x1DA] = 0;
    p[0x176] = 0x10;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x74) = 3.0f;
    *(f32 *)(p + 0x9C) = zero;
    *(f32 *)(p + 0x78) = 1.0f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 1.5707964f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    p[0x172] = 3;
    func_L01_00458A70(a0, 0.00166666671f, 0.0333333351f, 0.00174532935f, 0.0349065885f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 5;
        *(f32 *)(p + 0x30) = 5.0f;
    }
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    p[0x3F] = 0;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.5f;
    p[0x3E] = 1;
    func_L01_00441FB8(a0, 1, 0);
    if (a0[0x43] != 0xE) {
        func_003C3A10(a0, 0xE, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L02_003503C0 */
