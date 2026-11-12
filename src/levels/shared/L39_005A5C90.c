#include "common.h"

/* localdecomp:start func_L39_005A5C90 */
extern s32 D_001D4CE8_sda;
extern s32 D_001D4CEC_sda;
extern s32 D_001A43E8[];

void func_L39_005A5C90(void)
{
    s32 x;
    s32 v;

    v = D_001A43E8[0];
    if (2 != v) {
        D_001D4CE8_sda = 4;
        return;
    }
    x = D_001D4CEC_sda;
    if (x & 0x2020) {
        s32 y = x & ~0x20;
        *(s32 *)0x002403F8 = 14;
        *(s32 *)0x002403FC = y & ~0x2000;
    }
}
/* localdecomp:end func_L39_005A5C90 */

INCLUDE_ASM("asm/levels", func_L39_005A5CE8);

INCLUDE_ASM("asm/levels", func_L39_005A5D48);

INCLUDE_ASM("asm/levels", func_L39_005A5DE0);
