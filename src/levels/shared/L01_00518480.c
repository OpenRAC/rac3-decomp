#include "common.h"

/* localdecomp:start func_L01_00518480 */
extern s32 func_003E8630(s32, s32);
static inline s32 chk(s32 a, s32 b) { return func_003E8630(a, b) != 0; }
s32 func_L01_00518480(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    s32 r = chk(a0, a1);
    r = r & chk(a0, a2);
    r = r & chk(a0, a3);
    r = r & chk(a0, a4);
    r = r & chk(a0, a5);
    r = r & chk(a0, a6);
    r = r & chk(a0, a7);
    r = r & chk(a0, a8);
    return r;
}
/* localdecomp:end func_L01_00518480 */
