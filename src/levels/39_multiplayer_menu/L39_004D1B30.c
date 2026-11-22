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

/* localdecomp:start func_L39_004D1B98 */
extern s32 func_L39_004D1B30_004D1B98(s32, s32, s32, s32);

s32 func_L39_004D1B98(s32 a0, s32 a1, s32 a2, s32 a3) {
    return func_L39_004D1B30_004D1B98(a0, a1, a2, a3);
}
/* localdecomp:end func_L39_004D1B98 */

LINKER_REMNANT("asm/levels", func_L39_004D1BB0);
