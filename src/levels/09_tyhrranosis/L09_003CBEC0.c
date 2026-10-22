#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003CBEC0);

INCLUDE_ASM("asm/levels", func_L09_003CC1F0);

INCLUDE_ASM("asm/levels", func_L09_003CC3A0);

/* localdecomp:start func_L09_003CCB28 */
void func_L01_00445130(s32, s32, s32);
void func_L09_003CCB28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x20) = arg1;
    func_L01_00445130((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003CCB28 */

INCLUDE_ASM("asm/levels", func_L09_003CCB50);

INCLUDE_ASM("asm/levels", func_L09_003CCC00);
