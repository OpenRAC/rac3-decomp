#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00634E18);

INCLUDE_ASM("asm/levels", func_L39_00634E28);

INCLUDE_ASM("asm/levels", func_L39_00634E38);

INCLUDE_ASM("asm/levels", func_L39_00634E48);

INCLUDE_ASM("asm/levels", func_L39_00634E58);

/* localdecomp:start func_L39_00634F38 */
extern u8 func_L39_00635270[];
extern void func_L01_00404A10(void *a0, s32 a1);
void func_L39_00634F38(u8 *a0) {
    if (a0[6676] && *(s16 *)(a0 + 6626) == 0) {
        *(s16 *)(a0 + 6626) = 1;
        func_L01_00404A10(func_L39_00635270, *(s32 *)(a0 + 9508));
    }
}
/* localdecomp:end func_L39_00634F38 */

INCLUDE_ASM("asm/levels", func_L39_00634F80);

INCLUDE_ASM("asm/levels", func_L39_00635270);

INCLUDE_ASM("asm/levels", func_L39_00635DE8);

INCLUDE_ASM("asm/levels", func_L39_00636F30);

INCLUDE_ASM("asm/levels", func_L39_00637120);

INCLUDE_ASM("asm/levels", func_L39_00637310);

INCLUDE_ASM("asm/levels", func_L39_006378B0);
