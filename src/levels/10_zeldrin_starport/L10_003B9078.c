#include "common.h"

/* localdecomp:start func_L10_003B9078 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L10_003B9078(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s3 = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(a0 + 0x43) != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(s3 + 0x2DC), a1, a2, a3);
    }
}
/* localdecomp:end func_L10_003B9078 */

INCLUDE_ASM("asm/levels", func_L10_003B90E0);

INCLUDE_ASM("asm/levels", func_L10_003B9570);

INCLUDE_ASM("asm/levels", func_L10_003B9D28);

INCLUDE_ASM("asm/levels", func_L10_003B9DB0);
