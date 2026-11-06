#include "common.h"

/* localdecomp:start func_L39_005B2568 */
extern s32 func_0019D650(void);

f32 func_L39_005B2568(f32 minimum, f32 maximum) {
    f32 result;
    s32 random = func_0019D650();
    result = minimum + ((f32)random * (maximum - minimum) * 0.000030517578f);
    if (random & 1) {
        result = -result;
    }
    return result;
}
/* localdecomp:end func_L39_005B2568 */
