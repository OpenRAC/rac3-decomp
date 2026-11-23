#include "common.h"

/* NTSC-U counterpart of func_L40_00417CC0 (src/levels/shared/L40_004179D0.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
void func_L40_00417490(u8 *, vu0_v4 *, vu0_v4 *);

/* localdecomp:start func_L40_00417490 */
#include "vu0.h"

extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L39_005BA378(void *, void *, s32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_0019D650(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L40_0029B0D8[];
extern u8 D_L40_00242AB0[1];

#define RANDF(lo, hi) ({ f32 _lo = (lo), _hi = (hi); func_L39_005B2510(_lo, _hi); })
#define JITTER(c, r) ({ f32 _c = (c), _r = (r); func_L39_005B2568(_c, _r); })
#define RANDI(lo, hi) ({ s32 _lo = (lo), _hi = (hi); func_L39_005B24C8(_lo, _hi); })

void func_L40_00417490(u8 *self, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *s;
    s32 n;
    s32 i;
    s32 j;
    f32 f;

    v0 = *a1;
    s = *(u8 **)(self + 0x68);
    v10 = *a2;
    f = func_00388770(s);
    v30 = v10;
    vec_sub_ab(&v40, &v0, &v10);
    n = (s32)(f / 0.1f);
    func_00388830(&v40, &v40, f / (f32)n);
    func_L39_005BA378(self + 0x10, &v50, 1);
    i = 0;
    while (i < n) {
        s32 spin;
        s32 k;
        s32 alpha;
        s32 col;
        u8 *d = D_L40_0029B0D8;
        {
            f32 sf = JITTER(1.0f, 3.0f);
            spin = (s32)sf;
        }
        {
            f32 sp = -(RANDF(0.1f, 0.2f) * 0.016666668f);
            func_003886E8(&v20, &v50, sp);
        }
        {
            s32 r = RANDI(6, 9);
            k = r;
        }
        {
            s32 flags = func_0019D650();
            if (flags & 2) {
                alpha = 0x60;
                col = 0xBB7F40;
            } else {
                alpha = 0x7F;
                col = 0xFF4040;
            }
        }
        {
            u8 *p = func_L01_00466F98(&v30, &v20, k, alpha, col, spin, 1050.0f, 10000.0f, 1.0f, 0.0f, 0.0f);
            vec_add_ab(&v30, &v30, &v40);
            if (p != 0) {
                p[2] = (*(u8 **)(d + 0x184))[7];
                p[3] = (alpha == 0x60) ? 0x48 : 0x44;
            }
        }
        i++;
    }
    for (j = 0; j < 50; j++) {
        f32 g;
        s32 k;
        u8 *p;
        u8 *d = D_L40_0029B0D8;
        vu0_v4 *q = &v60;
        func_003886C0(q, s + 0x10, self + 0x10, RANDF(0.0f, 1.0f));
        k = func_L39_005B2498(0xFF);
        g = RANDF(0.2f, 0.35f);
        v60.x += JITTER(0.0f, 0.02f);
        v60.y += JITTER(0.0f, 0.02f);
        v60.z += JITTER(0.0f, 0.02f);
        p = func_L01_0046C468(q, D_L40_00242AB0, 9, 0xFF1010, k, 0x30, 0, g * 210000.0f, g * 0.2f * 210000.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = **(u8 **)(d + 0x16C);
        }
        g *= 0.5f;
        p = func_L01_0046C468(&v60, D_L40_00242AB0, 9, 0x808080, k, 0x30, 0, g * 210000.0f, g * 0.2f * 210000.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = **(u8 **)(d + 0x16C);
        }
    }
}
/* localdecomp:end func_L40_00417490 */
