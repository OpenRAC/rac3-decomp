#include "common.h"

/* localdecomp:start func_L01_00449BA8 */
#include "vu0.h"

typedef struct {
    vu0_v4 a;
    vu0_v4 b;
} Scratch_00449BA8;
typedef struct { u8 pad0[0x1A0]; u8 *tex; } S_221098_00449BA8;
extern S_221098_00449BA8 D_L01_00221098_00449BA8;
extern s32 func_003C2B88(void *, s32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern u8 *func_L01_004713C8_00449BA8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00447938_00449BA8(void *, s32, void *, void *, f32);

void func_L01_00449BA8(void *obj, vu0_v4 *pos, void *arg2, s32 arg3, s32 lo, s32 hi) {
    vu0_v4 a, b, c, d;
    vu0_v4 pts[8];
    s32 count;
    s32 n;
    s32 i;
    f32 r1, r2;
    u8 *q;
    Scratch_00449BA8 *p;

    count = func_003C2B88(obj, 0);
    if (count) {
        p = (Scratch_00449BA8 *)0x70000000;
        for (n = 0; n < count; n++, p++) {
            if (p->b.w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&p->a;
                a.w = 1.0f;
                r1 = func_00382538();
                r2 = func_00382538();
                func_00382760(&c, 0.008f, r1, r2);
                vec_add_ab(&c, &c, pos);
                c.z += 0.008f;
                func_00382580(&b, 0.0f, p->a.w);
                vec_add_ab(&a, &a, &b);
                q = func_L01_004713C8_00449BA8(&a, &c, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 0x2F, 0, 1, 63000.00390625f, 105000.0f, 0.0f);
            } else {
                *(vu0_q *)&a = *(vu0_q *)&p->a;
                *(vu0_q *)&b = *(vu0_q *)&p->b;
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                c.x += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                c.y += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                c.z += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                r1 = func_00382538();
                r2 = func_00382538();
                func_00382760(&d, 0.008f, r1, r2);
                vec_add_ab(&d, &d, pos);
                d.z += 0.008f;
                q = func_L01_004713C8_00449BA8(&c, &d, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 0x2F, 0, 1, 63000.00390625f, 105000.0f, 0.0f);
            }
            if (q) {
                q[3] = 0x48;
                q[2] = D_L01_00221098_00449BA8.tex[func_00382468(4)];
            }
        }
    } else {
        count = func_L01_00447938_00449BA8(obj, 8, pts, arg2, 6.0f);
        if (count) {
            for (i = 0; i < count; i++) {
                r1 = func_00382538();
                r2 = func_00382538();
                func_00382760(&a, 0.008f, r1, r2);
                vec_add_ab(&a, &a, pos);
                a.z += 0.008f;
                q = func_L01_004713C8_00449BA8(&pts[i], &a, (func_00382498(lo, hi) * 5 + 2) / 6, arg3, func_00382468(10), 0x2F, 0, 1, 42000.0f, 84000.0f, 0.0f);
                if (q) {
                    q[3] = 0x48;
                    q[2] = D_L01_00221098_00449BA8.tex[func_00382468(4)];
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00449BA8 */

INCLUDE_ASM("asm/levels", func_L01_0044A030);

LINKER_REMNANT("asm/levels", func_L01_0044A530);
