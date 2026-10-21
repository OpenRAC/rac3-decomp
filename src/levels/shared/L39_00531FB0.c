#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00531FB0);

INCLUDE_ASM("asm/levels", func_L39_005324E8);

INCLUDE_ASM("asm/levels", func_L39_00532550);

INCLUDE_ASM("asm/levels", func_L39_00532698);

INCLUDE_ASM("asm/levels", func_L39_00532BE0);

INCLUDE_ASM("asm/levels", func_L39_00532FE0);

/* localdecomp:start func_L39_00533210 */
extern void func_L39_005FE358(f32, u8 *, u8 *, s32, s32);

void func_L39_00533210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 356) != 0) {
        func_L39_005FE358(1.0f, p + 288, p + 304, 0, 1);
    }
}
/* localdecomp:end func_L39_00533210 */

INCLUDE_ASM("asm/levels", func_L39_00533250);

INCLUDE_ASM("asm/levels", func_L39_00533600);

INCLUDE_ASM("asm/levels", func_L39_00533790);

INCLUDE_ASM("asm/levels", func_L39_005338A8);

INCLUDE_ASM("asm/levels", func_L39_00534030);

INCLUDE_ASM("asm/levels", func_L39_00534220);

INCLUDE_ASM("asm/levels", func_L39_00534530);

INCLUDE_ASM("asm/levels", func_L39_00534880);
