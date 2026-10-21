#include "common.h"

/* localdecomp:start func_L40_00545BF0 */
extern u8 *D_L40_00241640[];

s32 func_L40_00545BF0(void) {
    s32 n = 0;
    s32 i;
    u8 b = D_L40_00241640[0][409];
    for (i = 0; i < 8; i++) {
        n += (b >> i) & 1;
    }
    return n;
}
/* localdecomp:end func_L40_00545BF0 */
