#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00434AB8);

INCLUDE_ASM("asm/levels", func_L40_00434CD0);

/* localdecomp:start func_L40_00434D68 */
extern u8 *D_L40_0024845C[];
extern s32 func_L40_003F6028(u8 *);

s32 func_L40_00434D68(u8 *a0) {
    s32 idx = *(s32 *)(*(u8 **)(a0 + 104) + 80);
    s32 r = 0;
    if (idx >= 0) {
        r = func_L40_003F6028(D_L40_0024845C[0] + (idx << 8));
    }
    return r;
}
/* localdecomp:end func_L40_00434D68 */

INCLUDE_ASM("asm/levels", func_L40_00434DA8);

INCLUDE_ASM("asm/levels", func_L40_00435388);
