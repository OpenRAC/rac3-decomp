#include "common.h"

/* localdecomp:start func_L39_005B2610 */
extern s32 func_0019D650(void);

f32 func_L39_005B2610(f32 scale) {
    f32 ratio = ((f32)(0xFFF & (func_0019D650() >> 16))) * (1.0f / 4096.0f);
    f32 result;
    result = ratio * ratio;
    result = 1.0f - result;
    return result * scale;
}
/* localdecomp:end func_L39_005B2610 */
