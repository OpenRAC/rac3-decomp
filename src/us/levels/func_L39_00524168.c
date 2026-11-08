#include "common.h"

/* localdecomp:start func_L39_00524168 */
extern f32 func_L01_00445168(f32 *, f32, f32 *, f32, f32, f32);
extern s32 func_00388398(void *);

void func_L39_00524168(u8 *self)
{
    s32 i, axis;
    u8 *rec;
    f32 *vel, *pos, v;
    u8 *obj = *(u8 **)(self + 0x68);

    for (i = 0; i < 10; i++) {
        rec = (u8 *)(i * 0x530 + *(s32 *)(obj + 0x60));
        if (*(s32 *)(rec + 0x514) != 1)
            continue;
        vel = (f32 *)(rec + 0x4F0);
        pos = (f32 *)(rec + 0x500);
        for (axis = 0; axis < 2; axis++) {
            v = pos[axis] + vel[axis];
            pos[axis] = v;
            if (v <= -8.0f)
                pos[axis] = v + 8.0f;
        }
        if (*(s32 *)(rec + 0x518) == 0) {
            func_L01_00445168((f32 *)(rec + 0x510), 0.5f, (f32 *)(rec + 0x51C), 0.00200000009f, 0.000199999995f, 0.0199999996f);
            if (*(f32 *)(rec + 0x510) == 0.5f) {
                *(s32 *)(rec + 0x518) = 2;
                *(s32 *)(rec + 0x520) = 60;
            }
        } else if (*(s32 *)(rec + 0x518) == 1) {
            func_L01_00445168((f32 *)(rec + 0x510), 0.0f, (f32 *)(rec + 0x51C), 0.00200000009f, 0.000199999995f, 0.0199999996f);
            if (*(f32 *)(rec + 0x510) == 0.0f)
                *(s32 *)(rec + 0x514) = 0;
        } else if (func_00388398(rec + 0x520)) {
            *(s32 *)(rec + 0x518) = 1;
        }
    }
}
/* localdecomp:end func_L39_00524168 */
