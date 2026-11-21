/* functional: high. 106 instructions differ (VU0 helper register use and scheduling); same calls, constants and branches as retail (constants from the PAL assembly). */
#include "vu0.h"
extern u8 D_L01_001A4BE0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_003C4360(f32 *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);

void func_L01_003CBB40(u8 *obj, u8 *q) {
    vu0_v4 t, d, u, n;
    f32 x, old, l;
    u8 *h;
    t.x = func_0038D098(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.y = func_0038D0B0(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.z = 0.0f;
    vec_add_ab(&t, &t, q + 0x4B0);
    old = *(f32 *)(q + 0x238);
    *(f32 *)(q + 0x238) = 0.0f;
    vec_sub_ab(&d, &t, obj + 0x10);
    d.z = 0.0f;
    func_0038CF68(&u, &d, 1.0f);
    func_0038CE90(&n, &u, obj + 0xE0);
    func_0038CF68(&n, &n, 1.0f);
    x = func_0038CE68(&n, q + 0x230);
    if (0.0014000000664964318f < x) {
        x = 0.0014000000664964318f;
    } else if (x < -0.0014000000664964318f) {
        x = -0.0014000000664964318f;
    }
    func_0038CF68(&n, &n, x);
    vec_sub_ba(q + 0x230, q + 0x230, &n);
    l = func_0038CED8(&d);
    x = func_0038CED8(q + 0x230);
    func_003C4360(&x, l, 0.0028000001329928637f, 0.001600000075995922f, 0.12000000476837158f);
    func_0038CF68(&u, &d, 0.0028000001329928637f);
    vec_add_ab(q + 0x230, q + 0x230, &u);
    if (x < func_0038CED8(q + 0x230)) {
        func_0038CF68(q + 0x230, q + 0x230, x);
    }
    if (obj[0x20] == 0x13) {
        *(f32 *)(q + 0x238) = old + 0.04000000283122063f;
        if (-0.10000000894069672f < *(f32 *)(q + 0x238)) *(f32 *)(q + 0x238) = -0.10000000894069672f;
    } else {
        *(f32 *)(q + 0x238) = old;
        h = D_L01_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0xB0) {
            f32 hy = *(f32 *)(h + 0x88);
            f32 oy = *(f32 *)(obj + 0x18);
            f32 dist = fabs_asm(hy - oy);
            s32 mode;
            if (dist < 2.25f) {
                mode = (oy < hy) ? 1 : 2;
            } else if (10.0f < dist) {
                mode = (oy < hy) ? 2 : 1;
            } else {
                mode = 0;
            }
            if (mode == 2) {
                *(f32 *)(q + 0x238) = old + 0.020000001415610313f;
                if (-0.18000000715255737f < *(f32 *)(q + 0x238)) *(f32 *)(q + 0x238) = -0.18000000715255737f;
            } else if (mode == 1) {
                *(f32 *)(q + 0x238) = old - 0.020000001415610313f;
                if (*(f32 *)(q + 0x238) < -0.2600000202655792f) *(f32 *)(q + 0x238) = -0.2600000202655792f;
            } else {
                *(f32 *)(q + 0x238) = *(f32 *)(q + 0x238) - 0.020000001415610313f;
                if (*(f32 *)(q + 0x238) < -0.2200000137090683f) *(f32 *)(q + 0x238) = -0.2200000137090683f;
            }
        } else {
            *(f32 *)(q + 0x238) = *(f32 *)(q + 0x238) - 0.020000001415610313f;
            if (*(f32 *)(q + 0x238) < -0.2200000137090683f) *(f32 *)(q + 0x238) = -0.2200000137090683f;
        }
    }
    vec_add_ba(obj + 0x10, obj + 0x10, q + 0x230);
    *(f32 *)(q + 0x220) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
}
