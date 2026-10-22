#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_003AA740);

INCLUDE_ASM("asm/levels", func_L21_003AABA0);

/* localdecomp:start func_L21_003AB440 */
void func_L01_004450F0(s32, s32, s32);
void func_L21_003AB440(void *arg0, s32 arg1) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 6) {
        func_L01_004450F0((s32) arg0, arg1 + 1, -1);
    }
}
/* localdecomp:end func_L21_003AB440 */
