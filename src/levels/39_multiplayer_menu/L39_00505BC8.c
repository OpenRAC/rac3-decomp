#include "common.h"

/* localdecomp:start func_L39_00505BC8 */
s32 *func_0011A6E0(void);
s32 func_L39_00505C08(s32);

s32 func_L39_00505BC8(s32 arg0) {
    s32 ret;
    if (arg0 == 0 || arg0 == -1) {
        ret = func_L39_00505C08(*func_0011A6E0());
    } else {
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00505BC8 */

INCLUDE_ASM("asm/levels", func_L39_00505C08);
