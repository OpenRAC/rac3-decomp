#include "common.h"

/* localdecomp:start func_L39_00508470 */
s32 func_L39_00508470(void *arg0, s32 (**arg1)(void *, s32), s32 arg2) {
    if (arg0 == 0) {
        return 0x212;
    }
    if (*(s32 *)((u8 *)arg0 + 0xC) != 0) {
        return 0x20E;
    }
    return (*arg1)(arg0, arg2);
}
/* localdecomp:end func_L39_00508470 */

INCLUDE_ASM("asm/levels", func_L39_005084A8);

INCLUDE_ASM("asm/levels", func_L39_00508540);

INCLUDE_ASM("asm/levels", func_L39_005085B0);

INCLUDE_ASM("asm/levels", func_L39_00508620);

INCLUDE_ASM("asm/levels", func_L39_00508684);

INCLUDE_ASM("asm/levels", func_L39_00508758);

INCLUDE_ASM("asm/levels", func_L39_005088D0);
