#include "common.h"

/* NTSC-U counterpart of func_L01_00449BA8 (src/levels/shared/L01_00449BA8.c) */
/* localdecomp:start func_L01_00446A00 */
#include "vu0.h"

typedef struct {
    vu0_v4 a;
    vu0_v4 b;
} Scratch_00449BA8;
typedef struct { u8 pad0[0x1A0]; u8 *tex; } S_221098_00449BA8;
extern S_221098_00449BA8 D_L01_00221118_00446A00;
extern s32 func_003BD668(void *, s32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern u8 *func_L01_0046DCB8_00446A00(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00444800_00446A00(void *, s32, void *, void *, f32);

void func_L01_00446A00(void *obj, vu0_v4 *pos, void *arg2, s32 arg3, s32 lo, s32 hi) {
    vu0_v4 a, b, c, d;
    vu0_v4 pts[8];
    s32 count;
    s32 n;
    s32 i;
    f32 r1, r2;
    u8 *q;
    Scratch_00449BA8 *p;

    count = func_003BD668(obj, 0);
    if (count) {
        p = (Scratch_00449BA8 *)0x70000000;
        for (n = 0; n < count; n++, p++) {
            if (p->b.w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&p->a;
                a.w = 1.0f;
                r1 = func_0037E2A8();
                r2 = func_0037E2A8();
                func_0037E4B8(&c, 0.0066666672f, r1, r2);
                vec_add_ab(&c, &c, pos);
                c.z += 0.0066666672f;
                func_0037E2F0(&b, 0.0f, p->a.w);
                vec_add_ab(&a, &a, &b);
                q = func_L01_0046DCB8_00446A00(&a, &c, func_0037E208(lo, hi), arg3, func_0037E1D8(10), 0x2F, 0, 1, 63000.00390625f, 105000.0f, 0.0f);
                if (q) {
                    q[3] = 0x48;
                    q[2] = D_L01_00221118_00446A00.tex[func_0037E1D8(4)];
                }
            } else {
                *(vu0_q *)&a = *(vu0_q *)&p->a;
                *(vu0_q *)&b = *(vu0_q *)&p->b;
                a.w = 1.0f;
                b.w = 1.0f;
                func_003886C0(&c, &a, &b, func_0037E250(0.0f, 1.0f));
                c.x += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                c.y += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                c.z += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                r1 = func_0037E2A8();
                r2 = func_0037E2A8();
                func_0037E4B8(&d, 0.0066666672f, r1, r2);
                vec_add_ab(&d, &d, pos);
                d.z += 0.0066666672f;
                q = func_L01_0046DCB8_00446A00(&c, &d, func_0037E208(lo, hi), arg3, func_0037E1D8(10), 0x2F, 0, 1, 63000.00390625f, 105000.0f, 0.0f);
                if (q) {
                    q[3] = 0x48;
                    q[2] = D_L01_00221118_00446A00.tex[func_0037E1D8(4)];
                }
            }
        }
    } else {
        count = func_L01_00444800_00446A00(obj, 8, pts, arg2, 6.0f);
        if (count) {
            for (i = 0; i < count; i++) {
                r1 = func_0037E2A8();
                r2 = func_0037E2A8();
                func_0037E4B8(&a, 0.0066666672f, r1, r2);
                vec_add_ab(&a, &a, pos);
                a.z += 0.0066666672f;
                q = func_L01_0046DCB8_00446A00(&pts[i], &a, func_0037E208(lo, hi), arg3, func_0037E1D8(10), 0x2F, 0, 1, 42000.0f, 84000.0f, 0.0f);
                if (q) {
                    q[3] = 0x48;
                    q[2] = D_L01_00221118_00446A00.tex[func_0037E1D8(4)];
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00446A00 */
