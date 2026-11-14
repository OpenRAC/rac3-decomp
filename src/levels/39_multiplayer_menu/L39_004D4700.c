#include "common.h"

/* localdecomp:start func_L39_004D4700 */
extern s32 func_L39_004D1DC8(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004D4700(s32 arg0, s32 arg1, s32 arg2)
{
    return func_L39_004D1DC8(arg1, arg2, arg2 + 8, arg2 + 16, arg0, arg2 + 24, 1);
}
/* localdecomp:end func_L39_004D4700 */

INCLUDE_ASM("asm/levels", func_L39_004D4730);

INCLUDE_ASM("asm/levels", func_L39_004D4D18);

INCLUDE_ASM("asm/levels", func_L39_004D51F0);

INCLUDE_ASM("asm/levels", func_L39_004D5288);

INCLUDE_ASM("asm/levels", func_L39_004D5370);

INCLUDE_ASM("asm/levels", func_L39_004D5420);

INCLUDE_ASM("asm/levels", func_L39_004D5488);
