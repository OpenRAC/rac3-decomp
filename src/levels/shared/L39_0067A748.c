#include "common.h"

/* localdecomp:start func_L39_0067A748 */
extern u8 *D_L39_00241640[];
extern s32 func_L39_0067A6D0(void);

s32 func_L39_0067A748(void) {
    u8 *p = D_L39_00241640[0];
    s32 r = 1;
    if (p != 0) {
        s32 b = p[409];
        r = (b >> func_L39_0067A6D0()) & 1;
    }
    return r;
}
/* localdecomp:end func_L39_0067A748 */
