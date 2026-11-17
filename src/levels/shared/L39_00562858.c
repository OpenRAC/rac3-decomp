#include "common.h"

/* localdecomp:start func_L39_00562858 */
#include "vu0.h"

extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_00562858(f32 *a0, u8 *a1) {
    f32 d[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 angle;
    f32 r;
    f32 p;
    f32 t;
    s32 n;
    s32 i;
    f32 size;

    vec_sub_ab(d, a1 + 0x23A0, a0);
    angle = func_0038D160(d[0], d[1]);
    for (i = 0; i < 15; i++) {
        r = func_L39_005B4410(0.5f, 1.0f);
        n = func_L39_005B4468(1.0f, 2.0f);
        size = func_L39_005B4410(0.05f, 0.2f) * 210000.0f;
        p = func_L39_005B4410(0.0f, 1.3962634f);
        t = func_0038DAB8(angle, func_L39_005B4468(0.0f, 1.3962634f));
        func_00382760(vel, 0.1f * 0.2f * r, t, p);
        pos[0] = a0[0] + func_L39_005B4468(0.0f, 0.1f);
        pos[1] = a0[1] + func_L39_005B4468(0.0f, 0.1f);
        pos[2] = a0[2] + func_L39_005B4468(0.0f, 0.1f);
        func_L01_0046A610(pos, vel, 25, 127, 0x7F7F7F, n, func_L39_005B4410(0.05f, 0.2f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_00562858 */
