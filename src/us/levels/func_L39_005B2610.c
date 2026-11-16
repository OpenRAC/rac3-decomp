#include "common.h"

/* localdecomp:start func_L39_005B2610 */
extern s32 func_0019D650(void);

/* Returns the scale times one minus the square of a random fraction in [0,1) taken from bits 16-27
 * of func_0019D650. */
f32 func_L39_005B2610(f32 scale) {
    f32 ratio = ((f32)(0xFFF & (func_0019D650() >> 16))) * (1.0f / 4096.0f);
    f32 result;
    result = ratio * ratio;
    result = 1.0f - result;
    return result * scale;
}
/* localdecomp:end func_L39_005B2610 */
