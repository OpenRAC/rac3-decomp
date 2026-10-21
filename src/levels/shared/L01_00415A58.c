#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00415A58);

INCLUDE_ASM("asm/levels", func_L01_00415C18);

/* localdecomp:start func_L01_00415C98 */
extern int D_L01_001EA6C0[];

void func_L01_00415C98(int a0, int a1)
{
    int x = 64;
    int y = 16;
    if (a0) x = a0;
    if (a1) y = a1;
    D_L01_001EA6C0[35] = x;
    D_L01_001EA6C0[36] = y;
}
/* localdecomp:end func_L01_00415C98 */

/* localdecomp:start func_L01_00415CC0 */
extern s32 D_L01_001D655C;
s32 func_L01_00415CC0(void) {
    return D_L01_001D655C;
}
/* localdecomp:end func_L01_00415CC0 */
