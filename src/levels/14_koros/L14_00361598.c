#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_00361598);

/* localdecomp:start func_L14_00361788 */
s32 func_L14_00362868(s32, s32);
void func_L01_00404A10(void *, void *);
void func_L01_0044F450(void *, s32);
void func_L14_00361F40(void *, s32);
void func_L14_00361F98(void *, s32);
extern u8 D_L14_00362D30[];

void func_L14_00361788(void *arg0) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (func_L14_00362868((s32) arg0, temp_s0) != 0) {
        func_L01_0044F450(arg0, temp_s0 + 0x60);
        func_L14_00361F40(arg0, temp_s0);
        func_L14_00361F98(arg0, temp_s0);
        func_L01_00404A10(D_L14_00362D30, arg0);
    }
}
/* localdecomp:end func_L14_00361788 */

INCLUDE_ASM("asm/levels", func_L14_003617F8);

INCLUDE_ASM("asm/levels", func_L14_00361A50);

INCLUDE_ASM("asm/levels", func_L14_00361B30);

INCLUDE_ASM("asm/levels", func_L14_00361D00);

INCLUDE_ASM("asm/levels", func_L14_00361DC0);

INCLUDE_ASM("asm/levels", func_L14_00361E90);

INCLUDE_ASM("asm/levels", func_L14_00361F40);

INCLUDE_ASM("asm/levels", func_L14_00361F98);
