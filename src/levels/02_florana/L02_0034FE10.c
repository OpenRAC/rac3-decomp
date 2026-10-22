#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0034FE10);

INCLUDE_ASM("asm/levels", func_L02_00350030);

INCLUDE_ASM("asm/levels", func_L02_00350200);

/* localdecomp:start func_L02_00350398 */
s32 func_00382468(s32);
void func_003C3A10(void *, s32, s32, s32);

void func_L02_00350398(void *arg0) {
    s32 temp_s0_2;
    s32 temp_s1;
    u8 temp_s0;
    u8 temp_s0_3;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = *(u8 *)((u8 *)arg0 + 0x43);
        if (temp_s0 != func_00382468(4)) {
            temp_s1 = func_00382468(4);
            temp_s0_2 = func_00382468(2);
            func_003C3A10(arg0, temp_s1, temp_s0_2, func_00382468(0xA));
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 1) {
        if ((*(u8 *)((u8 *)arg0 + 0x60)) & 2) {
            temp_s0_3 = *(u8 *)((u8 *)arg0 + 0x43);
            if (temp_s0_3 != func_00382468(4)) {
                func_003C3A10(arg0, func_00382468(4), 0, 0x11);
            }
        }
    }
}
/* localdecomp:end func_L02_00350398 */

INCLUDE_ASM("asm/levels", func_L02_00350478);

INCLUDE_ASM("asm/levels", func_L02_00351208);

INCLUDE_ASM("asm/levels", func_L02_003514D0);
