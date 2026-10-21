#include "common.h"

/* localdecomp:start func_L01_00515DE0 */
s32 func_L01_00515DE0(u8 *p) {
    u8 *q = *(u8 **)(p + 4);
    if (q != 0) {
        return *(s32 *)(q + 20);
    }
    return -1;
}
/* localdecomp:end func_L01_00515DE0 */
