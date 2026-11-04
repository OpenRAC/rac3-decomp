#include "common.h"

/* localdecomp:start func_L04_003CE760 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L04_003CE760(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s3 = *(u8 **)(a0 + 0x68);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(s3 + 0x300), a1, a2, a3);
    }
}
/* localdecomp:end func_L04_003CE760 */

INCLUDE_ASM("asm/levels", func_L04_003CE7C8);

INCLUDE_ASM("asm/levels", func_L04_003CEC40);

INCLUDE_ASM("asm/levels", func_L04_003CEF60);

INCLUDE_ASM("asm/levels", func_L04_003CF2B8);
