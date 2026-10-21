#include "common.h"

/* localdecomp:start func_L40_004167D0 */
s32 func_L40_004167D0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (p[332] == 0) {
        *(s16 *)(p + 334) = 0;
        p[332] = 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_004167D0 */
