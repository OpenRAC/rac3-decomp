#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003CD520);

/* localdecomp:start func_L09_003CD998 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L09_003CD998(void *arg0, s32 arg1) {
    s32 var_v0;

    if (((*(u8 *)((u8 *)arg0 + 0x20)) == 1) || (var_v0 = 0, (arg1 != 0))) {
        *(s8 *)((u8 *)arg0 + 0xBC) = 0;
        if (arg1 == 0) {
            func_L01_004450F0((s32) arg0, 2, -1);
        } else {
            func_L01_004450F0((s32) arg0, 3, -1);
        }
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L09_003CD998 */

INCLUDE_ASM("asm/levels", func_L09_003CD9F0);

INCLUDE_ASM("asm/levels", func_L09_003CDA30);
