#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_003098F0);

/* localdecomp:start func_L28_00309928 */
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;

/* from rac2-decomp's func_L08_003DB4E8 */
s32 func_L28_00309928(void)
{
    s32 v = D_001D545C;
    s32 r = 1;
    if (v == 8)
        return 1;
    if (v == 0x13)
        r = 2;
    return r;
}
/* localdecomp:end func_L28_00309928 */

INCLUDE_ASM("asm/levels", func_L28_00309958);

INCLUDE_ASM("asm/levels", func_L28_00309CE8);
