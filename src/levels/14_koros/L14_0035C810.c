#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0035C810);

INCLUDE_ASM("asm/levels", func_L14_0035C9C0);

INCLUDE_ASM("asm/levels", func_L14_0035CA20);

INCLUDE_ASM("asm/levels", func_L14_0035CA60);

INCLUDE_ASM("asm/levels", func_L14_0035CBA0);

INCLUDE_ASM("asm/levels", func_L14_0035CC40);

INCLUDE_ASM("asm/levels", func_L14_0035CD38);

/* localdecomp:start func_L14_0035CE38 */
void func_L14_0035CF00(u8 *a0);
s32 func_L01_00447490(u8 *a0, s32 a1, s32 a2);
void func_L01_00439880(u8 *a0, u16 *a1, s32 *a2);
void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L14_0035CE38(u8 *arg0) {
    u16 tmp;
    s32 tmp2;
    s32 v;

    v = arg0[0x20];
    switch (v) {
    case 0:
        func_L01_00439880(arg0, &tmp, &tmp2);
        *(u16 *)(arg0 + 0x7C) = tmp;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(arg0, -1, 0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
        }
        break;
    case 2:
        func_L14_0035CF00(arg0);
        break;
    }
    arg0[0xA8] = 0xFF;
}
/* localdecomp:end func_L14_0035CE38 */

INCLUDE_ASM("asm/levels", func_L14_0035CF00);

INCLUDE_ASM("asm/levels", func_L14_0035D088);
