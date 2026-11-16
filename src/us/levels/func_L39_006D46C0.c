#include "common.h"

/* localdecomp:start func_L39_006D46C0 */
extern s32 func_00196DF8(s32, s32, s32);

/* Wrapper that drops its first argument and returns func_00196DF8 called with the other three. */
s32 func_L39_006D46C0(s32 unused, s32 first, s32 second, s32 third) {
    return func_00196DF8(first, second, third);
}
/* localdecomp:end func_L39_006D46C0 */
