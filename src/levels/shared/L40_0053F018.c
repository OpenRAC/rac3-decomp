#include "common.h"

/* localdecomp:start func_L40_0053F018 */
u32 func_L40_0053F018(u8 *p) {
    u8 *q = *(u8 **)(p + 144);
    if (q != 0) {
        return *(u8 *)(q + 48);
    }
    return 0;
}
/* localdecomp:end func_L40_0053F018 */

INCLUDE_ASM("asm/levels", func_L40_0053F038);

/* localdecomp:start func_L40_0053F068 */
s32 func_L40_0053F068(s32 a0, s32 a1, s32 a2) {
    s32 p = *(s32 *)(a0 + 144);
    if (p != 0) {
        *(s32 *)(p + 64) = a2;
        *(s32 *)(p + 60) = a1;
        *(u8 *)(p + 48) = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_0053F068 */
