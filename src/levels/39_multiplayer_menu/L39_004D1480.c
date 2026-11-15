#include "common.h"

/* localdecomp:start func_L39_004D1480 */
extern s32 func_L39_004F6BF0(s32, s32 *, s32 *, s32, s32, s32);
extern void func_L39_004F4F18(s32 *);

s32 func_L39_004D1480(s32 a0) {
    s32 buf[4];
    s32 v;
    s32 r;

    do {
        r = func_L39_004F6BF0(a0, buf, &v, 0, 0, 0);
    } while (0);
    func_L39_004F4F18(&a0);
    return r;
}
/* localdecomp:end func_L39_004D1480 */
