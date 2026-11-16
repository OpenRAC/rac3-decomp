#include "common.h"

/* localdecomp:start func_L39_005B2510 */
extern s32 func_0019D650(void);

/* Returns a random float between minimum and maximum, using the 16-bit random value from
 * func_0019D650 as the fraction. */
f32 func_L39_005B2510(f32 minimum, f32 maximum) {
    return minimum + ((f32)func_0019D650() * (maximum - minimum) * 0.000030517578f);
}
/* localdecomp:end func_L39_005B2510 */
