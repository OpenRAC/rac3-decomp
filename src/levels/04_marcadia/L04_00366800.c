#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00366800);

INCLUDE_ASM("asm/levels", func_L04_00366AC8);

INCLUDE_ASM("asm/levels", func_L04_00366DC8);

/* localdecomp:start func_L04_00367068 */
extern void func_L04_003672E8(void *);
extern void func_L04_00367150(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L04_00367068(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(s32 *)p = 8;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        func_L04_003672E8(a0);
        func_L01_004450F0(a0, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p) != 0) {
            func_L04_00367150(a0);
        }
        break;
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L04_00367068 */

INCLUDE_ASM("asm/levels", func_L04_00367150);

INCLUDE_ASM("asm/levels", func_L04_003672E8);
