#include "common.h"

/* localdecomp:start func_L40_00422608 */
extern u8 *D_L40_00241640;

s32 func_L40_00422608(u8 *a0) {
    s32 n = *(s32 *)(*(u8 **)(a0 + 0x68) + 0x8C);
    s32 r = 0;

    if (n == 0 || (n == 1 && *(s32 *)(D_L40_00241640 + 0x180) == 0)
        || (n == 2 && *(s32 *)(D_L40_00241640 + 0x180) == 1)
        || (n == 3 && *(s32 *)(D_L40_00241640 + 0x180) == 2)) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L40_00422608 */
