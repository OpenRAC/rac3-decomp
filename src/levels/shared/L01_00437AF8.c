#include "common.h"

/* localdecomp:start func_L01_00437AF8 */
extern u8 *D_L01_002E99F0[];

u8 *func_L01_00437AF8(u32 a0, s32 a1) {
    u8 *r = 0;
    if (a0 < 96) {
        r = D_L01_002E99F0[a0] + a1 * 48;
    }
    return r;
}
/* localdecomp:end func_L01_00437AF8 */

/* localdecomp:start func_L01_00437B38 */
extern u8 *func_L01_00437AF8(u32 a0, s32 a1);

void func_L01_00437B38(unsigned char *a0)
{
    ((void (*)(int, int))func_L01_00437AF8)(a0[0] - 1, a0[1]);
}
/* localdecomp:end func_L01_00437B38 */

LINKER_REMNANT("asm/levels", func_L01_00437B60);

INCLUDE_ASM("asm/levels", func_L01_00437B68);

LINKER_REMNANT("asm/levels", func_L01_00437DC8);
