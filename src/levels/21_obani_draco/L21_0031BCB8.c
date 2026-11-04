#include "common.h"

/* localdecomp:start func_L21_0031BCB8 */
extern u8 D_001A4C60[];
s32 func_00382380(void *, s32, s32);
s32 func_L01_00456500(void *, s32);
void func_L02_003F4BE8(s32, s32);

void func_L21_0031BCB8(u8 *a0)
{
    s32 *s0 = *(s32 **)(a0 + 0x68);

    if (*(u8 *)(a0 + 0x20) == 0) {
        *(u8 *)(a0 + 0x20) = 1;
        *(u8 *)(a0 + 0x30) = 0xFF;
    }
    if (func_00382380(D_001A4C60, s0[0], 0) == 0) {
        func_00382380(D_001A4C60, s0[1], 0);
    }
    if (func_L01_00456500(D_001A4C60, s0[2]) != 0) {
        func_L02_003F4BE8(0xCD8, 0x1770);
    }
}
/* localdecomp:end func_L21_0031BCB8 */
