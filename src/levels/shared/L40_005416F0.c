#include "common.h"

/* localdecomp:start func_L40_005416F0 */
extern s32 D_L40_002499F4[];
extern s32 D_L40_001DE2E0;

s32 func_L40_005416F0(s32 *a) {
    s32 r = 0;
    s32 v = D_L40_002499F4[0];
    if (v != -1) {
        s32 x = a[1];
        if (x == v || (x == -1 && D_L40_001DE2E0 == v)) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L40_005416F0 */
