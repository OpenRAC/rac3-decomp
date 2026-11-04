#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_0044BE48);

INCLUDE_ASM("asm/levels", func_L01_0044BE50);

/* localdecomp:start func_L01_0044BEC8 */
extern int D_L01_001E001C __attribute__((section(".sdata")));
extern int D_L01_001E001C __attribute__((section(".data")));

/* from rac2-decomp's func_002ACAD0, renamed */
void func_L01_0044BEC8(int param_1, unsigned short *param_2)
{
    int i;
    for (i = 1; i <= (short)param_2[0]; i++) {
        if (D_L01_001E001C + ((short)param_2[i] << 8) == param_1) {
            param_2[i] = param_2[(short)param_2[0]];
            param_2[0] = param_2[0] - 1;
            return;
        }
    }
}
/* localdecomp:end func_L01_0044BEC8 */

LINKER_REMNANT("asm/levels", func_L01_0044BF40);
