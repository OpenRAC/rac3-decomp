#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005000E0);

INCLUDE_ASM("asm/levels", func_L39_005000F8);

/* localdecomp:start func_L39_00500158 */
s32 func_0011AFE8(s32, s32, s32, s32);
s32 func_L39_00500158(void *arg0, s32 arg1, s32 arg2) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xC)) != 0) {
        if (arg1 != 0) {
            var_v1 = func_0011AFE8(arg1, 1, arg2, (*(s32 *)((u8 *)arg0 + 0x20)));
        }
    }
    return var_v1;
}
/* localdecomp:end func_L39_00500158 */

INCLUDE_ASM("asm/levels", func_L39_00500198);

INCLUDE_ASM("asm/levels", func_L39_005001E8);

INCLUDE_ASM("asm/levels", func_L39_00500450);

INCLUDE_ASM("asm/levels", func_L39_005004B0);

INCLUDE_ASM("asm/levels", func_L39_005004F8);

INCLUDE_ASM("asm/levels", func_L39_00500510);

INCLUDE_ASM("asm/levels", func_L39_00500568);

INCLUDE_ASM("asm/levels", func_L39_00500600);

INCLUDE_ASM("asm/levels", func_L39_00500680);

INCLUDE_ASM("asm/levels", func_L39_00500948);

INCLUDE_ASM("asm/levels", func_L39_00500990);
