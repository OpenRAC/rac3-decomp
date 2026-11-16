#include "common.h"

/* localdecomp:start func_L39_006DC8F0 */
extern u8 D_001A6AD0[];

/* Writes into values[target] the integer left * total / values[second], scaled by global floats,
 * when values[first] exceeds a global threshold and the divisor and values[11] pass checks;
 * otherwise writes 0. */
void func_L39_006DC8F0(s32 *values, s32 target, s32 first, s32 second) {
    s32 result;
    f32 left;
    f32 right;
    f32 total;
    u8 *global;

    global = D_001A6AD0;
    total = (f32)values[first];
    if (*(f32 *)(global + 0xD0) < total) {
        result = values[second];
        if (result > 0) {
            right = (f32)values[11];
            if (*(f32 *)(global + 0xEC) <= right) {
                left = *(f32 *)(global + 0xD4);
                right = (f32)result;
                values[target] = (s32)(left * total / right);
                return;
            }
        }
    }
    values[target] = 0;
}
/* localdecomp:end func_L39_006DC8F0 */
