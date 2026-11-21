#include "common.h"

/* localdecomp:start func_L01_00494088 */
extern u8 D_001D54B0[];

s32 func_L01_00494088(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_001D54B0[i] != 0) {
            n++;
        }
    }
    return n;
}
/* localdecomp:end func_L01_00494088 */
