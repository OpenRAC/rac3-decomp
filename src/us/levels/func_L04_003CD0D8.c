#include "common.h"

/* NTSC-U counterpart of func_L04_003CEF60 (src/levels/04_marcadia/L04_003CE760.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);

/* localdecomp:start func_L04_003CD0D8 */
extern u8 D_001A4BE0[];
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern void func_003BEE20(f32 *, f32, f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, void *, f32);

void func_L04_003CD0D8(u8 *obj, u8 *q) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 u;
    vu0_v4 n;
    f32 x;
    f32 old;
    f32 l;
    u8 *h;

    t.x = func_00388960(*(f32 *)(q + 0x318)) * *(f32 *)(q + 0x31C);
    t.y = func_00388978(*(f32 *)(q + 0x318)) * *(f32 *)(q + 0x31C);
    t.z = 0.0f;
    vec_add_ab(&t, &t, q + 0x2D0);
    old = *(f32 *)(q + 0x118);
    vec_sub_ab(&d, &t, obj + 0x10);
    *(f32 *)(q + 0x118) = 0.0f;
    d.z = 0.0f;
    func_00388830(&u, &d, 1.0f);
    func_00388758(&n, &u, obj + 0xE0);
    func_00388830(&n, &n, 1.0f);
    x = func_00388730(&n, q + 0x110);
    if (0.0011111111380159855f < x) {
        x = 0.0011111111380159855f;
    } else if (x < -0.0011111111380159855f) {
        x = -0.0011111111380159855f;
    }
    func_00388830(&n, &n, x);
    vec_sub_ba(q + 0x110, q + 0x110, &n);
    l = func_003887A0(&d);
    x = func_003887A0(q + 0x110);
    func_003BEE20(&x, l, 0.002222222276031971f, 0.0011111111380159855f, 0.11666667461395264f);
    func_00388830(&u, &d, 0.002222222276031971f);
    vec_add_ab(q + 0x110, q + 0x110, &u);
    if (x < func_003887A0(q + 0x110)) {
        func_00388830(q + 0x110, q + 0x110, x);
    }
    if (obj[0x20] == 0x12) {
        *(f32 *)(q + 0x118) = old + 0.02777777798473835f;
        if (-0.0833333358168602f < *(f32 *)(q + 0x118))
            *(f32 *)(q + 0x118) = -0.0833333358168602f;
    } else {
        *(f32 *)(q + 0x118) = old;
        h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0xB0 && fabs_asm(*(f32 *)(h + 0x88) - *(f32 *)(obj + 0x18)) < 2.25f) {
            if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                *(f32 *)(q + 0x118) = old - 0.013888888992369175f;
                if (*(f32 *)(q + 0x118) < -0.21666666865348816f)
                    *(f32 *)(q + 0x118) = -0.21666666865348816f;
            } else {
                *(f32 *)(q + 0x118) = old + 0.013888888992369175f;
                if (-0.15000000596046448f < *(f32 *)(q + 0x118))
                    *(f32 *)(q + 0x118) = -0.15000000596046448f;
            }
        } else {
            *(f32 *)(q + 0x118) = *(f32 *)(q + 0x118) - 0.013888888992369175f;
            if (*(f32 *)(q + 0x118) < -0.18333333730697632f)
                *(f32 *)(q + 0x118) = -0.18333333730697632f;
        }
    }
    vec_add_ba(obj + 0x10, obj + 0x10, q + 0x110);
    *(f32 *)(q + 0x100) = func_003BE7F0(obj + 0x10, 0, 0, 0.5f);
}
/* localdecomp:end func_L04_003CD0D8 */
