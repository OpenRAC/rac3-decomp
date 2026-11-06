#include "common.h"

/* localdecomp:start func_L21_0031B9B0 */
extern u8 D_001A4C60[];
extern s32 func_L21_00419790(void *, s32, s32);
extern s32 func_L21_0042BFA8(void *, s32);
extern void func_L21_003F24E0(s32, s32);

void func_L21_0031B9B0(u8 *object) {
    s32 *vars = *(s32 **)(object + 0x68);
    if (object[0x20] == 0) {
        object[0x20] = 1;
        object[0x30] = 0xFF;
    }
    if (func_L21_00419790(D_001A4C60, vars[0], 0) == 0) {
        func_L21_00419790(D_001A4C60, vars[1], 0);
    }
    if (func_L21_0042BFA8(D_001A4C60, vars[2]) != 0) {
        func_L21_003F24E0(0xCD8, 0x1C20);
    }
}
/* localdecomp:end func_L21_0031B9B0 */
