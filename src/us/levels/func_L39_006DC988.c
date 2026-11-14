#include "common.h"

/* localdecomp:start func_L39_006DC988 */
extern f32 D_001A6AD0[];

/* Stores in values[target] a ratio of two entries (left times a global scale, divided by right)
 * when their sum exceeds a global limit and another entry passes a threshold; otherwise stores 0. */
void func_L39_006DC988(s32 *values, s32 target, s32 first, s32 second) {
    s32 left = values[first];
    s32 right = values[second];

    if (D_001A6AD0[52] < (f32)(left + right)) {
        if (right > 0 && D_001A6AD0[59] <= (f32)values[11]) {
            values[target] = (s32)(D_001A6AD0[53] * (f32)left / (f32)right);
            return;
        }
    }
    values[target] = 0;
}
/* localdecomp:end func_L39_006DC988 */
