/* functional: high. Beam/line effect between two points: 10 interpolated points, 8 inner ones jittered; VU0 vsub/vadd as float math. 136 diffs, same call order and args. */
#include "common.h"
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_00382538(void);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L04_003D11F8(u8 *a0, u8 *a1) {
    vu0_v4 cur;
    vu0_v4 d;
    vu0_v4 pts[10];
    s32 i;

    d.x = ((vu0_v4 *)a1)->x - ((vu0_v4 *)a0)->x;
    d.y = ((vu0_v4 *)a1)->y - ((vu0_v4 *)a0)->y;
    d.z = ((vu0_v4 *)a1)->z - ((vu0_v4 *)a0)->z;
    d.w = ((vu0_v4 *)a1)->w;
    func_0038CE20(&d, &d, 0.11111111f);
    *(vu0_q *)&cur = *(vu0_q *)a0;
    for (i = 0; i < 10; i++) {
        *(vu0_q *)&pts[i] = *(vu0_q *)&cur;
        if (i != 0 && i != 9) {
            func_003C4C18(&pts[i], 0.3f);
        }
        pts[i].w = 0.075f;
        cur.x += d.x;
        cur.y += d.y;
        cur.z += d.z;
    }
    func_L01_00409658(pts, 0.075f, 4.0f, 0.0f, 0x17, 0x17, 0xB, -1, 0x80802020, 0);
    func_003D9508(a0, 0x31, 0xFFFFFFFF, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(a0, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
    func_003D9508(a1, 0x31, 0xFFFFFFFF, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(a1, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
}
