#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_003A28A8);

INCLUDE_ASM("asm/levels", func_L02_003A29D0);

INCLUDE_ASM("asm/levels", func_L02_003A2C98);

INCLUDE_ASM("asm/levels", func_L02_003A2EC8);

/* localdecomp:start func_L02_003A3878 */
s32 func_L02_003A3878(u8 *a0) {
    s32 r = 0;
    if (a0[3] & 0x80) {
        r = *(s32 *)(a0 + 92) == 0;
    }
    return r;
}
/* localdecomp:end func_L02_003A3878 */

INCLUDE_ASM("asm/levels", func_L02_003A3898);

INCLUDE_ASM("asm/levels", func_L02_003A3988);

INCLUDE_ASM("asm/levels", func_L02_003A49F0);

INCLUDE_ASM("asm/levels", func_L02_003A4CC0);

/* localdecomp:start func_L02_003A5010 */
void func_L01_004443E8(s32, s32, s32);
void func_L02_003A5010(s32 arg0) {
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L02_003A5010 */

INCLUDE_ASM("asm/levels", func_L02_003A5030);

INCLUDE_ASM("asm/levels", func_L02_003A5138);

INCLUDE_ASM("asm/levels", func_L02_003A51F0);
