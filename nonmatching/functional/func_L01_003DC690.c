/* functional: high. Codex near miss, 2 words differ: f12/f13 argument moves in opposite order before the second func_L01_00448690 call; values identical. */
#include "common.h"
/* localdecomp:start func_L01_003DC690 */
#include "vu0.h"
void func_L01_003DC690(u8 *m, u8 *out, vu0_q *target, f32 rate) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_00448690(void *, s32, f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    vu0_v4 pos;
    vu0_v4 delta;
    f32 pitch;
    f32 yaw;
    pos = *(vu0_v4 *)target;
    vec_sub_ba(&delta, &pos, m + 0x10);
    if (delta.z < 3.0f) pitch = -1.5707963705062866f;
    else pitch = -func_0038D160(func_0038CED8(&delta), delta.z);
    func_L01_00448690(m + 0xF4, 0, pitch, rate);
    yaw = func_0038D160(delta.x, delta.y);
    func_L01_00448690(m + 0xF8, 0, yaw, rate);
    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(out, m + 0xC0, *(f32 *)(out + 0x20));
}
/* localdecomp:end func_L01_003DC690 */
