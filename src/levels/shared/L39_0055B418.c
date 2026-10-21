#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0055B418);

INCLUDE_ASM("asm/levels", func_L39_0055B4D8);

INCLUDE_ASM("asm/levels", func_L39_0055D598);

INCLUDE_ASM("asm/levels", func_L39_0055D6B0);

/* localdecomp:start func_L39_0055D790 */
extern s32 D_L39_00242914[];
extern s32 D_L39_001D5A08;
extern void func_003C2880(void *);

void func_L39_0055D790(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    if (D_L39_00242914[0] != 0 && p != 0 && (*p)[9417] == D_L39_001D5A08) {
        func_003C2880(a0);
        return;
    }
    *(u16 *)(a0 + 52) &= 0xFFBE;
}
/* localdecomp:end func_L39_0055D790 */
