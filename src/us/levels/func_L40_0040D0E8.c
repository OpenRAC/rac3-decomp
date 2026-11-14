#include "common.h"

/* NTSC-U counterpart of func_L40_0040D7D0 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern f32 func_00388770(void *v);
extern f32 func_00388800(void *a, void *b);
extern f32 func_00388A28(f32 x, f32 y);
extern f32 func_00389468(f32 a, f32 b);
extern void func_003886E8(void *d, void *s, f32 k);
extern void func_L01_00445758(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);
extern void func_003886E8(void *d, void *s, f32 k);
extern f32 func_003887A0(void *v);

/* localdecomp:start func_L40_0040D0E8 */
extern f32 func_00388730(void *a, void *b);
extern void func_003BEE20(void *p, f32 target, f32 a, f32 b, f32 c);

/* Steer the walker towards `yaw` and the path (pVar+0x310), and keep it on the ground. */
void func_L40_0040D0E8(u8 *m, u8 *w, void *target, f32 yaw, vu0_v4 *a, vu0_v4 *b) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 z;
    vu0_v4 d;
    f32 diff;
    f32 dist;
    f32 h;

    if (!(*(s32 *)(w + 0x38) & 0x10)) {
        func_L01_00445758(m + 0xF8, yaw, *(f32 *)(w + 0x14), *(f32 *)(w + 0x18), *(f32 *)(w + 0x1C), w + 0xB4, 0);
    }
    diff = func_00389468(*(f32 *)(m + 0xF8), yaw);
    if (!(*(s32 *)(w + 0x38) & 0x10) && diff > *(f32 *)(w + 0x30)) {
        qzero(&z);
        if (diff - *(f32 *)(w + 0x30) > *(f32 *)(w + 0xB4) * 30.0f) {
            *(s32 *)(w + 0x9C) |= 2;
        }
    }
    dist = func_00388800(m + 0x10, v + 0x330);
    vec_sub_ba(&d, v + 0x310, m + 0x10);
    *(s32 *)&d.z = 0;
    func_003886E8(&d, &d, 0.04f);
    vec_sub_ab(&d, &d, v + 0x110);
    if (dist > 1.29999995f) {
        func_003886E8(&d, &d, 0.13f);
    } else {
        func_003886E8(&d, &d, 0.25f);
    }
    d.z *= 0.9f;
    vec_add_ab(v + 0x110, v + 0x110, &d);
    if (*(s32 *)(w + 0x38) & 0x400) {
        *(f32 *)(w + 0xB0) = func_00388770(w + 0xA0);
    } else {
        *(f32 *)(w + 0xB0) = func_003887A0(w + 0xA0);
    }
    if (*(s32 *)(w + 0x38) & 4) {
        return;
    }
    if (*(f32 *)(w + 0x90) < *(f32 *)(m + 0x18)) {
        if (*(s16 *)(w + 0xC2) < 2) {
            if (*(f32 *)(m + 0x18) - *(f32 *)(w + 0x90) < 0.150000006f) {
                if (func_00388A28(*(f32 *)(w + 0x58), func_003887A0(w + 0x50)) > 0.0872664601f) {
                    if (-func_00388730(w + 0xA0, w + 0x50) < *(f32 *)(w + 0xA8)) {
                        *(f32 *)(w + 0xA8) = -func_00388730(w + 0xA0, w + 0x50);
                    }
                }
            }
        }
        *(f32 *)(w + 0xA8) -= *(f32 *)(w + 0x2C);
        if (*(s16 *)(w + 0xC0) == 0) {
            *(s32 *)(w + 0x94) |= 0x20;
        }
    } else {
        h = *(f32 *)(w + 0x90) - *(f32 *)(m + 0x18);
        if (h < *(f32 *)(w + 0xA8)) {
            *(f32 *)(w + 0xA8) = h;
        } else if (*(f32 *)(w + 0xA8) < 0.0f) {
            *(f32 *)(w + 0xA8) = 0.0f;
        }
        func_003BEE20(w + 0xA8, *(f32 *)(w + 0x90) - *(f32 *)(m + 0x18), 0.011111111f, 0.011111111f, 1.0f);
    }
}
/* localdecomp:end func_L40_0040D0E8 */
