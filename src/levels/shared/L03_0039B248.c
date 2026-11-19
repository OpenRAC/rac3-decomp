#include "common.h"

/* localdecomp:start func_L03_0039B248 */
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

void func_L03_0039B248(u8 *a) {
    if (a[32] == 0) {
        *(s32 *)(*(u8 **)(a + 104) + 8) = 0;
        func_L01_004450F0(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0039B248 */

INCLUDE_ASM("asm/levels", func_L03_0039B280);
