#include "common.h"

/* localdecomp:start func_L01_0033AC58 */
__asm__(".extern D_L01_001DCFB8, 4");
extern s32 D_L01_001DCFB8;
s32 *func_L01_0033AC58(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L01_001DCFB8;
    }
    return 0;
}
/* localdecomp:end func_L01_0033AC58 */

INCLUDE_ASM("asm/levels", func_L01_0033AC78);
