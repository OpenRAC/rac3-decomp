#include "common.h"

/* localdecomp:start func_L39_005B24C8 */
extern s32 func_0019D650(void);

s32 func_L39_005B24C8(s32 minimum, s32 maximum) {
    return (func_0019D650() % ((maximum - minimum) + 1)) + minimum;
}
/* localdecomp:end func_L39_005B24C8 */
