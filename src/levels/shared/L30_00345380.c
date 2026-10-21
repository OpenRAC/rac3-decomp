#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00345380);

INCLUDE_ASM("asm/levels", func_L30_00345990);

/* localdecomp:start func_L30_00345B68 */
extern s32 func_L05_00328FF8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
void func_L30_00345B68(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 19 && v[440] == 0 && func_L05_00328FF8(a0) && *(s16 *)(a0 + 170) == 5957) {
        func_003A52A0(0, 0, a0);
    }
}
/* localdecomp:end func_L30_00345B68 */

INCLUDE_ASM("asm/levels", func_L30_00345BD0);

INCLUDE_ASM("asm/levels", func_L30_00346080);
