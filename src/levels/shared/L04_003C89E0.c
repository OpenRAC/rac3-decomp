#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003C89E0);

/* localdecomp:start func_L04_003C8DA0 */
extern s16 *D_L04_0021C9A0[];
extern void func_L04_003C89E0(s32, s32, s32);

void func_L04_003C8DA0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s16 *p = D_L04_0021C9A0[a2];
    if (p != 0) {
        do {
            func_L04_003C89E0(*p & 0x7fff, a1, a3);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_L04_003C8DA0 */

INCLUDE_ASM("asm/levels", func_L04_003C8E10);
