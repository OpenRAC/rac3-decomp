#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0066F948);

INCLUDE_ASM("asm/levels", func_L39_0066FA90);

INCLUDE_ASM("asm/levels", func_L39_0066FC08);

INCLUDE_ASM("asm/levels", func_L39_0066FF08);

INCLUDE_ASM("asm/levels", func_L39_006702A0);

INCLUDE_ASM("asm/levels", func_L39_006703B0);

INCLUDE_ASM("asm/levels", func_L39_00670438);

INCLUDE_ASM("asm/levels", func_L39_00670930);

INCLUDE_ASM("asm/levels", func_L39_00670968);

INCLUDE_ASM("asm/levels", func_L39_00670AE0);

INCLUDE_ASM("asm/levels", func_L39_00670C50);

INCLUDE_ASM("asm/levels", func_L39_00670D90);

INCLUDE_ASM("asm/levels", func_L39_00671448);

INCLUDE_ASM("asm/levels", func_L39_00672118);

INCLUDE_ASM("asm/levels", func_L39_00672190);

/* localdecomp:start func_L39_00672208 */
extern u8 *D_L39_00241640[];
extern s32 func_L39_00672118(void);

s32 func_L39_00672208(void) {
    u8 *p = D_L39_00241640[0];
    s32 r = 1;
    if (p != 0) {
        s32 b = p[409];
        r = (b >> func_L39_00672118()) & 1;
    }
    return r;
}
/* localdecomp:end func_L39_00672208 */

INCLUDE_ASM("asm/levels", func_L39_00672248);

INCLUDE_ASM("asm/levels", func_L39_00672400);
