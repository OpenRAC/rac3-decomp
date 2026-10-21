#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0030FA80);

INCLUDE_ASM("asm/levels", func_L02_0030FB58);

/* localdecomp:start func_L02_0030FC08 */
f32 func_L02_0030FC08(f32 x) {
    if (x < 0.0f) {
        x = -x;
        x = x - (f32)(s32)x;
        return 1.0f - x;
    }
    return x - (f32)(s32)x;
}
/* localdecomp:end func_L02_0030FC08 */

INCLUDE_ASM("asm/levels", func_L02_0030FC68);

INCLUDE_ASM("asm/levels", func_L02_0030FF48);

INCLUDE_ASM("asm/levels", func_L02_003102A8);

INCLUDE_ASM("asm/levels", func_L02_00310368);

INCLUDE_ASM("asm/levels", func_L02_00310428);

INCLUDE_ASM("asm/levels", func_L02_003104A8);

INCLUDE_ASM("asm/levels", func_L02_00310730);

INCLUDE_ASM("asm/levels", func_L02_003107D8);

INCLUDE_ASM("asm/levels", func_L02_00310838);
