/* functional: high. Camera spring/distance step: recomputes the spring delta (target minus look+0xB0), either re-scales it by the steer timer, or clamps/limits its length (0.2 minimum, ratio kept when approaching, hero-motion fallback below 1e-4) and updates steer+0x30; returns the flag or 1. Branches and callee args checked against retail; only VU0 scheduling differs */
#include "vu0.h"
extern u8 D_L01_001E2B90[];
s32 func_L01_003E75A8(u8 *obj, f32 *target, s32 force, s32 flag) {
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    u8 *base = *(u8 **)(obj + 0x70);
    f32 *delta = (f32 *)(base + 0x180);
    u8 *hero = D_L01_001E2B90 + *(s32 *)(obj + 0x94) * 0x460;
    u8 *steer = base + 0x210;
    u8 *motion = base + 0x60;
    f32 old_length = func_0038CEA8(delta);
    f32 length;
    __asm__("lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)delta)
            : "m"(*(vu0_v4 *)target), "m"(*(vu0_v4 *)(base + 0xB0))
            : "vf1", "vf2");
    if (*(s16 *)(steer + 0x38)) {
        func_0038CF68(delta, delta, delta[11] - *(f32 *)(steer + 0x30));
        return flag;
    }
    length = func_0038CEA8(delta);
    if (hero[0x12B] != 2 && fabs_asm(*(f32 *)(*(u8 **)(hero + 0x134) + 0x100)) > 0.05f && flag) {
        *(s16 *)(steer + 0x34) = 0x719;
        length -= 0.09f;
    }
    if (!force && *(s32 *)(hero + 0x104) != 2 && old_length < length) {
        func_0038CE20(delta, delta, old_length / length);
        *(f32 *)(steer + 0x30) = delta[11] - old_length;
        return flag;
    }
    if (length < 0.2f) {
        if (length <= 0.0001f) {
            func_0038CF68(delta, (f32 *)(*(u8 **)(motion + 0xE0) + 0xC0), -0.2f);
        } else {
            func_0038CE20(delta, delta, 0.2f / length);
        }
        length = 0.2f;
    }
    *(f32 *)(steer + 0x30) = delta[11] - length;
    return 1;
}
