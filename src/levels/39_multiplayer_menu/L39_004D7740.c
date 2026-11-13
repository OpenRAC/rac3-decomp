#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004D7740);

INCLUDE_ASM("asm/levels", func_L39_004D7770);

INCLUDE_ASM("asm/levels", func_L39_004D7B38);

INCLUDE_ASM("asm/levels", func_L39_004D8110);

INCLUDE_ASM("asm/levels", func_L39_004D8168);

INCLUDE_ASM("asm/levels", func_L39_004D83E0);

INCLUDE_ASM("asm/levels", func_L39_004D8660);

INCLUDE_ASM("asm/levels", func_L39_004D8BC0);

INCLUDE_ASM("asm/levels", func_L39_004D8CB0);

INCLUDE_ASM("asm/levels", func_L39_004D8E10);

INCLUDE_ASM("asm/levels", func_L39_004D8F00);

INCLUDE_ASM("asm/levels", func_L39_004D8FD0);

INCLUDE_ASM("asm/levels", func_L39_004D9058);

INCLUDE_ASM("asm/levels", func_L39_004D9168);

INCLUDE_ASM("asm/levels", func_L39_004D9330);

INCLUDE_ASM("asm/levels", func_L39_004D9508);

/* localdecomp:start func_L39_004D9610 */
s32 func_L39_004B5748(s32, s32);

s32 func_L39_004D9610(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_L39_004B5748(arg0, arg2);
    s32 n = ret;

    if (ret < 0) {
        return ret;
    }
    ret = arg1;
    ret ^= n;
    ret = ret ? -0x6A : n;
    return ret;
}
/* localdecomp:end func_L39_004D9610 */

INCLUDE_ASM("asm/levels", func_L39_004D9650);

INCLUDE_ASM("asm/levels", func_L39_004D98F8);
