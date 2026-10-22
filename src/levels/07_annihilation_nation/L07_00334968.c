#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00334968);

INCLUDE_ASM("asm/levels", func_L07_003349E8);

INCLUDE_ASM("asm/levels", func_L07_00334A20);

/* localdecomp:start func_L07_00334A70 */
s32 func_L07_00333460(s32, s32);
s32 func_L07_00334A70(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_L07_00333460(arg0, -1);
    if (temp_v0 == 0) {
        return -1;
    }
    return (*(s32 *)((u8 *)temp_v0 + 8));
}
/* localdecomp:end func_L07_00334A70 */

INCLUDE_ASM("asm/levels", func_L07_00334A98);
