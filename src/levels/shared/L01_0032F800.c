#include "common.h"


INCLUDE_ASM("asm/levels", func_L01_0032F800);

INCLUDE_ASM("asm/levels", func_L01_0032F8E8);

/* localdecomp:start func_L01_0032FB18 */
extern s32 D_L01_00278990[];

void func_L01_0032FB18(void)
{
    int i;
    D_L01_00278990[138] = 5;
    D_L01_00278990[137] = 0;
    D_L01_00278990[136] = 0;
    for (i = 0; i < 64; ++i) {
        D_L01_00278990[i] = 0;
        D_L01_00278990[i + 64] = 0;
    }
    for (i = 7; i >= 0; --i)
        D_L01_00278990[i + 128] = 0;
}
/* localdecomp:end func_L01_0032FB18 */
