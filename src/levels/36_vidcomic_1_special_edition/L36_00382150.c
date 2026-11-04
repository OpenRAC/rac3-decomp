#include "common.h"

INCLUDE_ASM("asm/levels", func_L36_00382150);

/* localdecomp:start func_L36_00382188 */
extern u32 D_L36_001E0BD0[4];

s32 func_L36_00382188(void)
{
    u32 *p;
    s32 i;

    i = 0;
    p = D_L36_001E0BD0;
    for (; i < 4; i++, p++) {
        if (*p == 0)
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L36_00382188 */

INCLUDE_ASM("asm/levels", func_L36_003821C0);
