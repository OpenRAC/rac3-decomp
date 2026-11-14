#include "common.h"

/* localdecomp:start func_L39_004BECC0 */
__asm__(".extern D_L39_00464818, 16");
extern s32 (*D_L39_00464818[])(void);

s32 func_L39_004BECC0(void) {
    s32 (*fn)(void) = D_L39_00464818[0];
    s32 ret;

    do {
        ret = 1;
        if (fn == 0) {
            break;
        }
        ret = fn();
    } while (0);
    return ret;
}
/* localdecomp:end func_L39_004BECC0 */
