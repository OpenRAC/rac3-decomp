#include "common.h"

/* localdecomp:start func_L39_00698F78 */
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

void func_L39_00698F78(u8 *arg0)
{
    s32 v[4];
    f32 a = *(f32 *)(arg0 + 0x2B0);

    if (arg0[0x2B4]) {
        if (a != 0.6f) {
            func_L39_00688460(arg0, v, v, v, v, v, 0.5f, 0.45f, 1.7f, 1.0f, a);
        } else {
            func_L39_00688460(arg0, v, v, v, v, v, 0.5f, 0.5f, 1.7f, 1.0f, a);
        }
    } else {
        if (a != 0.6f) {
            func_L39_00688460(arg0, v, v, v, v, v, 0.5f, 0.45f, 1.0f, 1.0f, a);
        } else {
            func_L39_00688460(arg0, v, v, v, v, v, 0.5f, 0.5f, 1.0f, 1.0f, a);
        }
    }
}
/* localdecomp:end func_L39_00698F78 */
