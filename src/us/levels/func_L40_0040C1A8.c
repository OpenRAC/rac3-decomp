#include "common.h"

/* NTSC-U counterpart of func_L40_0040C878 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern s32 func_L39_005B2498(s32 n);
extern void func_003886E8(void *d, void *s, f32 k);

/* localdecomp:start func_L40_0040C1A8 */
extern s32 func_L39_005BC958(vu0_v4 *sphere, s32 a1, f32 dist);
extern s32 func_L39_005B2498(s32 n);
extern f32 func_L39_005B2510(f32 lo, f32 hi);
extern f32 func_L39_005B25C8_0040C1A8(void);
extern f32 func_00388960(f32 a);
extern f32 func_00388978(f32 a);
extern void func_003886E8(void *d, void *s, f32 k);
extern void func_L39_005CBA68(vu0_v4 *pos, vu0_v4 *vel, u32 colour, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f);

/* 60 sparks around `pos` (when it is in view). */
void func_L40_0040C1A8(vu0_v4 *pos) {
    vu0_v4 p;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 up;
    f32 r;
    f32 a;

    p = *pos;
    p.w = 1.5f;
    if (func_L39_005BC958(&p, 0, 48.0f) == -1) {
        return;
    }
    for (i = 0; i < 60; i++) {
        up = func_L39_005B2498(2);
        r = func_L39_005B2510(0.0f, 0.4f);
        a = func_L39_005B25C8_0040C1A8();
        off.x = func_00388960(a) * r;
        off.y = func_00388978(a) * r;
        off.z = 0.0f;
        off.z += func_L39_005B2510(0.3f, -0.3f);
        vec_add_ba(&off, &off, pos);
        vel = (vu0_v4){ 0.0f, 0.0f, func_L39_005B2510(0.5f, 1.5f) * 0.016666668f, 0.0f };
        vel.z += (0.4f - r) * 0.050000004f / 0.4f;
        if (up) {
            off.z += 2.0f;
            func_003886E8(&vel, &vel, -1.0f);
        }
        func_L39_005CBA68(&off, &vel, 0x8020C040, 0x3C, func_L39_005B2498(0xFF) & 0xFF, 0, 0x40, 0, 1.0f);
    }
}
/* localdecomp:end func_L40_0040C1A8 */
