#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC4B0 */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC4B0(void *a) {
    if (D_L39_00443498[0] != 0) {
        ((void (*)(void *))D_L39_00443498[0])(a);
    } else {
        func_L39_004BC6C8(26, 136, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC4B0 */

INCLUDE_ASM("asm/levels", func_L39_004BC4F8);

INCLUDE_ASM("asm/levels", func_L39_004BC6C8);

INCLUDE_ASM("asm/levels", func_L39_004BC880);

INCLUDE_ASM("asm/levels", func_L39_004BC898);

INCLUDE_ASM("asm/levels", func_L39_004BC8B0);
