#include "common.h"

/* localdecomp:start func_L39_005ABA28 */
extern u8 *D_L39_0024CE20;
extern f32 D_L39_002935A0[];
extern void func_L01_0043BA48(s32, f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L39_005ABA28(void)
{
    f32 v[3];
    f32 angle;
    f32 zero;
    u8 *p;

    p = D_L39_0024CE20;
    if (p != 0 && *(s32 *)(p + 9508) != 0) {
        func_L01_0043BA48(*(s32 *)(p + 9508), v);
    } else {
        zero = 0.0f;
        v[1] = zero;
        v[2] = -0.99f;
        v[0] = zero;
    }
    angle = func_0038D160(v[0], v[1]);
    D_L39_002935A0[0] = func_0038D098(angle) * 0.14f;
    D_L39_002935A0[1] = func_0038D0B0(angle) * 0.14f;
    D_L39_002935A0[2] = -0.99f;
}
/* localdecomp:end func_L39_005ABA28 */
