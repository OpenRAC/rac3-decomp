#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_00336EF0);

/* localdecomp:start func_L21_00337BB8 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_00337BB8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 0) {
        return 0;
    }
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x7D) = 0;
    func_L01_004450F0((s32) arg0, 1, -1);
    return 1;
}
/* localdecomp:end func_L21_00337BB8 */

INCLUDE_ASM("asm/levels", func_L21_00337BF0);

INCLUDE_ASM("asm/levels", func_L21_00337F08);

INCLUDE_ASM("asm/levels", func_L21_00338090);

INCLUDE_ASM("asm/levels", func_L21_00338150);

INCLUDE_ASM("asm/levels", func_L21_003381D8);

INCLUDE_ASM("asm/levels", func_L21_003383A8);

INCLUDE_ASM("asm/levels", func_L21_00338638);

INCLUDE_ASM("asm/levels", func_L21_003387B0);

INCLUDE_ASM("asm/levels", func_L21_00338B00);

INCLUDE_ASM("asm/levels", func_L21_00338C20);

INCLUDE_ASM("asm/levels", func_L21_00338CC8);

INCLUDE_ASM("asm/levels", func_L21_00338D38);

/* localdecomp:start func_L21_00338D60 */
s32 func_L21_00338D60(void *arg0, u8 *arg1) {
    switch (*(u8 *)((u8 *)arg0 + 0xBC)) {
    case 1:
        return arg1[1];
    case 2:
        return arg1[2];
    case 0:
        return arg1[3];
    case 3:
        return arg1[4];
    default:
        return 0;
    }
}
/* localdecomp:end func_L21_00338D60 */
