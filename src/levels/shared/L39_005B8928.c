#include "common.h"

/* localdecomp:start func_L39_005B8928 */
extern u8 *D_L39_001E084C;
extern u8 *D_L39_001E0854;

s32 func_L39_005B8928(u8 *obj)
{
    u8 *p;
    u8 c;

    if (obj != 0) {
        goto check;
    }
fail:
    return 0;
check:
    if (obj < D_L39_001E084C) {
        goto fail;
    }
    if (obj > D_L39_001E0854) {
        goto fail;
    }
    p = *(u8 **)(obj + 0x24);
    if (p != 0) {
        c = p[0x46];
        if (c == 9) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005B8928 */

INCLUDE_ASM("asm/levels", func_L39_005B8978);
