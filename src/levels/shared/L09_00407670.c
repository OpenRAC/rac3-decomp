#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_00407670);

INCLUDE_ASM("asm/levels", func_L09_00407D08);

/* localdecomp:start func_L09_00408150 */
extern u8 D_L09_001E2B80[];

s32 func_L09_00408150(u8 *obj) {
    u8 *e = (u8 *)(*(s32 *)(obj + 148) * 1120 + (s32)D_L09_001E2B80);
    return *(s32 *)(e + 588) == 0x1D;
}
/* localdecomp:end func_L09_00408150 */

INCLUDE_ASM("asm/levels", func_L09_00408178);
