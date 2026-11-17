#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00323C48);

/* localdecomp:start func_L03_003240B8 */
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

void func_L03_003240B8(u8 *a0) {
    switch (*(s32 *)(*(u8 **)(a0 + 0x68) + 0x10)) {
    case 0: func_L01_00452560(0, 12, 0x8BD, 1, 0, 0, 0); break;
    case 1: func_L01_00452560(0, 12, 0x14D6, 1, 0, 0, 0); break;
    case 2: func_L01_00452560(0, 12, 0x16B6, 1, 0, 0, 0); break;
    case 3: func_L01_00452560(0, 12, 0x16B7, 1, 0, 0, 0); break;
    case 4: func_L01_00452560(0, 12, 0x16B8, 1, 0, 0, 0); break;
    case 5: func_L01_00452560(0, 12, 0x16C2, 1, 0, 0, 0); break;
    default: func_L01_00452560(0, 12, 0x850, 1, 0, 0, 0); break;
    }
}
/* localdecomp:end func_L03_003240B8 */

INCLUDE_ASM("asm/levels", func_L03_00324190);
