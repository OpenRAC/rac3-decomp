/* functional: high. Not byte-exact (about 276 words differ: pooled float constants, loop form); the 27 calls match in order and arguments. Rewritten from the PAL assembly (sibling of func_L01_0044A030 and func_L01_00449088, fixed colour byte 0x48 and the table entry D_00221098[0x1A0/4]). */
#include "vu0.h"
extern s32 func_003C2B88(void *, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *D_L01_00221098[];

void func_L01_00449BA8(void *owner, void *velocity, s32 mode, u32 arg3, s32 lo, s32 hi) {
    vu0_v4 a, b, c, d, points[8];
    vu0_v4 *p;
    s32 count;
    u8 *part;
    f32 x, y;

    count = func_003C2B88(owner, 0);
    if (count != 0) {
        if (count > 0) {
            p = (vu0_v4 *)0x70000000;
            do {
                if (p[1].w == 0.0f) {
                    *(vu0_q *)&a = *(vu0_q *)p;
                    a.w = 1.0f;
                    x = func_00382538();
                    y = func_00382538();
                    func_00382760(&c, 0.00800000037997961f, x, y);
                    vec_add_ab(&c, &c, velocity);
                    c.z += 0.00800000037997961f;
                    func_00382580(&b, 0.0f, p->w);
                    vec_add_ab(&a, &a, &b);
                    part = func_L01_004713C8(&a, &c, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 47, 0, 1,
                                             63000.00390625f, 105000.0f, 0.0f);
                } else {
                    *(vu0_q *)&a = *(vu0_q *)p;
                    a.w = 1.0f;
                    *(vu0_q *)&b = *(vu0_q *)&p[1];
                    b.w = 1.0f;
                    func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                    c.x += func_003824E0(-p->w * 0.4f, p->w * 0.4f);
                    c.y += func_003824E0(-p->w * 0.4f, p->w * 0.4f);
                    c.z += func_003824E0(-p->w * 0.4f, p->w * 0.4f);
                    x = func_00382538();
                    y = func_00382538();
                    func_00382760(&d, 0.00800000037997961f, x, y);
                    vec_add_ab(&d, &d, velocity);
                    d.z += 0.00800000037997961f;
                    part = func_L01_004713C8(&c, &d, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 47, 0, 1,
                                             63000.00390625f, 105000.0f, 0.0f);
                }
                if (part != 0) {
                    part[3] = 0x48;
                    part[2] = D_L01_00221098[0x1A0 / 4][func_00382468(4)];
                }
                p += 2;
            } while (--count != 0);
        }
    } else {
        count = func_L01_00447938(owner, 8, points, mode, 6.0f);
        if (count > 0) {
            p = points;
            do {
                x = func_00382538();
                y = func_00382538();
                func_00382760(&a, 0.00800000037997961f, x, y);
                vec_add_ab(&a, &a, velocity);
                a.z += 0.00800000037997961f;
                part = func_L01_004713C8(p, &a, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 47, 0, 1,
                                         42000.0f, 84000.0f, 0.0f);
                if (part != 0) {
                    part[3] = 0x48;
                    part[2] = D_L01_00221098[0x1A0 / 4][func_00382468(4)];
                }
                p++;
            } while (--count != 0);
        }
    }
}
