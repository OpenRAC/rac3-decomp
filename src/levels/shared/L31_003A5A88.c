#include "common.h"

/* localdecomp:start func_L31_003A5A88 */
extern void func_L31_003A55A0(u8 *a0, s32 a1);
void func_L31_003A5A88(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (*(s32 *)(s0 + 456) == 0) {
        func_L31_003A55A0(a0, 2);
    }
    if (*(s32 *)(s0 + 456) == 1) {
        func_L31_003A55A0(a0, 8);
    }
    if (*(s32 *)(s0 + 456) == 2) {
        func_L31_003A55A0(a0, 9);
    }
}
/* localdecomp:end func_L31_003A5A88 */

INCLUDE_ASM("asm/levels", func_L31_003A5B00);

INCLUDE_ASM("asm/levels", func_L31_003A5B30);
