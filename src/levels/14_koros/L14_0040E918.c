#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0040E918);

/* localdecomp:start func_L14_0040E9D0 */
extern int D_L14_001EEC50[];

int func_L14_0040E9D0(void)
{
    int i;
    int *base = D_L14_001EEC50;
    int *p = base + 4;
    for (i = 0; i < 0x28; i++) {
        if (*p <= 0)
            return i;
        p += 8;
    }
    return -1;
}
/* localdecomp:end func_L14_0040E9D0 */

INCLUDE_ASM("asm/levels", func_L14_0040EA08);

INCLUDE_ASM("asm/levels", func_L14_0040EA78);

INCLUDE_ASM("asm/levels", func_L14_0040EC48);

INCLUDE_ASM("asm/levels", func_L14_0040EF88);

INCLUDE_ASM("asm/levels", func_L14_0040F1B8);
