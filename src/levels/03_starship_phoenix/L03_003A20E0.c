#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003A20E0);

/* localdecomp:start func_L03_003A2328 */
void func_L01_004450F0(s32, s32, s32);
void func_L03_003A2328(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 4) = 0;
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L03_003A2328 */

INCLUDE_ASM("asm/levels", func_L03_003A2360);

INCLUDE_ASM("asm/levels", func_L03_003A2398);

INCLUDE_ASM("asm/levels", func_L03_003A2790);

INCLUDE_ASM("asm/levels", func_L03_003A2A10);

INCLUDE_ASM("asm/levels", func_L03_003A2B48);

INCLUDE_ASM("asm/levels", func_L03_003A2BB8);
