#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003FB350);

/* localdecomp:start func_L20_003FB3B0 */
s32 func_L20_003FB3B0(void *arg0) {
    s32 var_v1;
    u8 temp_a0;

    var_v1 = 0;
    if (((u32) ((*(u8 *)((u8 *)arg0 + 0x42)) - 0x12) < 2U) || (temp_a0 = (*(u8 *)((u8 *)arg0 + 0x43)), (temp_a0 == 0x13)) || (temp_a0 == 0x12)) {
        var_v1 = 1;
    }
    return var_v1;
}
/* localdecomp:end func_L20_003FB3B0 */
