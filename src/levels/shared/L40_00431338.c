#include "common.h"

/* localdecomp:start func_L40_00431338 */
extern u8 *func_L39_0066DD30(s32, s32, s32);
extern void func_L39_00662B18(u8 *, void *, s32);

f32 func_L40_00431338(s32 a0, void *a1) {
    f32 v = 0.0f;
    u8 *o = func_L39_0066DD30(a0, 1, 1);
    if (o != 0) {
        o[84] = 0;
        func_L39_00662B18(o, &v, 4);
        func_L39_00662B18(o, a1, 8);
    }
    return v;
}
/* localdecomp:end func_L40_00431338 */
