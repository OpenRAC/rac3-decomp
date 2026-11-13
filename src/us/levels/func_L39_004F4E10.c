#include "common.h"

/* localdecomp:start func_L39_004F4E10 */
extern s32 func_L39_004F4DD8(void *);

s32 func_L39_004F4E10(void *p) {
    s32 r = 0;
    if (p != 0) {
        r = func_L39_004F4DD8(p) != 0 ? 0x21B : 0;
    }
    return r;
}
/* localdecomp:end func_L39_004F4E10 */
