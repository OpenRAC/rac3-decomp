#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003E8DF8);

INCLUDE_ASM("asm/levels", func_L09_003E91B8);

/* localdecomp:start func_L09_003E9298 */
void func_L01_004450F0(s32, s32, s32);
void func_L09_003E9298(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if (arg1 != -1) {
        *(s32 *)((u8 *)temp_v1 + 0x70) = arg1;
    } else {
        *(s32 *)((u8 *)temp_v1 + 0x70) = 0x7D;
    }
    func_L01_004450F0((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003E9298 */
