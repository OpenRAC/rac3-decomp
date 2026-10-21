#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00408C98);

LINKER_REMNANT("asm/levels", func_L01_00409058);

INCLUDE_ASM("asm/levels", func_L01_00409070);

INCLUDE_ASM("asm/levels", func_L01_00409428);

INCLUDE_ASM("asm/levels", func_L01_00409598);

/* localdecomp:start func_L01_004095C8 */
typedef s32 (*Fn004071B0)(s32, s32, s32, s32, s32);
extern Fn004071B0 *func_L01_0043B568(s32, s32, s32);
s32 func_L01_004095C8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    Fn004071B0 *f = func_L01_0043B568(7721, 0, 4);
    if (f == 0) {
        return 0;
    }
    return (*f)(a0, a1, a2, a3, t0);
}
/* localdecomp:end func_L01_004095C8 */

INCLUDE_ASM("asm/levels", func_L01_00409658);
