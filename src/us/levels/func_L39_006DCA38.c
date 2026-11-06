#include "common.h"

/* localdecomp:start func_L39_006DCA38 */
extern f32 D_001A6AD0[];

s32 func_L39_006DCA38(f32 first, f32 second) {
    s32 low = 1;
    s32 high;
    if (second <= D_001A6AD0[0x114 / 4]) {
        if (!(first <= D_001A6AD0[0x120 / 4])) {
            if (first <= D_001A6AD0[0x124 / 4]) {
                low = 2;
            } else if (first <= D_001A6AD0[0x128 / 4]) {
                low = 3;
            } else {
                low = 4;
            }
        }
        high = 1;
        if (second <= D_001A6AD0[0x11C / 4]) {
            high = 3;
        } else if (second <= D_001A6AD0[0x118 / 4]) {
            high = 2;
        }
        if (high >= low) {
            low = high;
        }
    } else {
        low = 1;
    }
    return low;
}
/* localdecomp:end func_L39_006DCA38 */
