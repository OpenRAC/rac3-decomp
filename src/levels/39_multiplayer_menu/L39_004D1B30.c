#include "common.h"

/* localdecomp:start func_L39_004D1B30 */
extern s32 func_L39_004F6D38(void *, void *, s32 *, s32, void *, s32, s32, s32);

s32 func_L39_004D1B30(void *arg0, void *arg1, void *arg2, s32 n) {
    s32 len;
    s32 r;

    while ((r = func_L39_004F6D38(arg0, arg2, &len, n * 8, arg1, n * 8, 0, 0)) == 0) {
        if (len != n * 8)
            r = -2;
        break;
    }
    return r;
}
/* localdecomp:end func_L39_004D1B30 */

LINKER_REMNANT("asm/levels", func_L39_004D1B90);

INCLUDE_ASM("asm/levels", func_L39_004D1B98);
