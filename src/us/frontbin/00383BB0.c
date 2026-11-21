#include "common.h"

/* NTSC-U counterpart of func_00388258 (src/frontbin/382380.c): the random delay is not scaled by 5/6 (50/60 Hz) */
/* localdecomp:start func_U_00383BB0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00388258;
typedef struct { V_00388258 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_00388258;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_00388258;
extern f32 D_U_001D59B0, D_U_001D59B4, D_U_001D59BC;
extern s32 D_U_001D59B8;
extern f32 D_U_001D5948, D_U_001D5958;
extern f32 D_U_001D594C, D_U_001D5950, D_U_001D5954, D_U_001D595C, D_U_001D5960, D_U_001D5964;
__asm__(".extern D_U_001D59B0, 4");
__asm__(".extern D_U_001D59B4, 4");
__asm__(".extern D_U_001D59B8, 4");
__asm__(".extern D_U_001D59BC, 4");
__asm__(".extern D_U_001D5948, 4");
__asm__(".extern D_U_001D5958, 4");
extern V_00388258 D_U_00222500_00383BB0;
extern s32 func_U_00388398(void *);
extern void func_U_003BEB58_00383BB0(V_00388258 *, V_00388258, V_00388258, f32);
extern void func_U_00388758_00383BB0(V_00388258 *, V_00388258, V_00388258);
extern f32 func_U_00388730(void *, void *);
extern void func_U_00388830(s32 a, s32 b, f32 x);
extern f32 func_U_003BEB48(f32, f32, f32);
extern void func_U_003CD830(void *, s32, s32);
extern s32 func_U_0037E208(s32 lo, s32 hi);
void func_U_00383BB0(void *o, void *q, long tex) {
    O_00388258 *obj = o;
    V_00388258 *quad = q;
    P_00388258 p;
    V_00388258 t0, t1;
    V_00388258 n, d;
    f32 s, dot;
    if (func_U_00388398(&obj->f3C) == 0) {
        return;
    }
    p.c = 0xFF90UL << 32 | 0x260;
    p.tex = tex;
    p.a = 5;
    p.d = 0x8000UL << 24 | 0x44;
    p.rgba[3] = D_U_001D59B8;
    p.rgba[2] = D_U_001D59B8;
    p.rgba[1] = D_U_001D59B8;
    p.rgba[0] = D_U_001D59B8;
    t0 = quad[0]; t1 = quad[1];
    func_U_003BEB58_00383BB0(&p.pos[0], t0, t1, obj->f38 - D_U_001D59B0);
    t0 = quad[0]; t1 = quad[1];
    func_U_003BEB58_00383BB0(&p.pos[1], t0, t1, obj->f38 + D_U_001D59B0);
    t0 = quad[2]; t1 = quad[3];
    func_U_003BEB58_00383BB0(&p.pos[2], t0, t1, obj->f38 - D_U_001D59B0);
    t0 = quad[2]; t1 = quad[3];
    func_U_003BEB58_00383BB0(&p.pos[3], t0, t1, obj->f38 + D_U_001D59B0);
    {
        vu0_q q0, q1, q2, q3, y0, y2;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(quad[1]));
        __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(quad[0]));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(quad[2]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y0) : "j"(q1), "j"(q0));
        __asm__("lqc2 %0, %1" : "=j"(q3) : "m"(quad[0]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y2) : "j"(q2), "j"(q3));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(y0));
        __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(y2));
    }
    func_U_00388758_00383BB0(&n, t0, t1);
    vec_sub_ba(&d, &D_U_00222500_00383BB0, &quad[0]);
    dot = func_U_00388730(&n, &d);
    s = D_U_001D59BC;
    if (!(dot > 0.0f)) {
        s = -s;
    }
    func_U_00388830((s32)&n, (s32)&n, s);
    vec_add_ab(&p.pos[0], &p.pos[0], &n);
    vec_add_ab(&p.pos[1], &p.pos[1], &n);
    vec_add_ba(&p.pos[2], &p.pos[2], &n);
    vec_add_ab(&p.pos[3], &p.pos[3], &n);
    p.uv[0][0] = obj->f24 * D_U_001D5948 + 0.5f + D_U_001D59B4;
    p.uv[1][0] = obj->f24 * D_U_001D594C + 0.5f + D_U_001D59B4;
    p.uv[2][0] = obj->f24 * D_U_001D5950 + 0.5f - D_U_001D59B4;
    p.uv[3][0] = obj->f24 * D_U_001D5954 + 0.5f - D_U_001D59B4;
    p.uv[0][1] = obj->f28 * func_U_003BEB48(D_U_001D5958, D_U_001D595C, obj->f38 - D_U_001D59B0) + 0.5f;
    p.uv[1][1] = obj->f28 * func_U_003BEB48(D_U_001D595C, D_U_001D5958, obj->f38 - D_U_001D59B0) + 0.5f;
    p.uv[2][1] = obj->f28 * func_U_003BEB48(D_U_001D5960, D_U_001D5964, obj->f38 - D_U_001D59B0) + 0.5f;
    p.uv[3][1] = obj->f28 * func_U_003BEB48(D_U_001D5964, D_U_001D5960, obj->f38 - D_U_001D59B0) + 0.5f;
    func_U_003CD830(&p, 0, 0);
    obj->f38 += obj->f34;
    if (obj->f34 > 0.0f) {
        if (obj->f38 >= 1.0f - D_U_001D59B0) {
            obj->f38 -= 1.0f;
            obj->f3C = func_U_0037E208(30, 120);
        }
        if (obj->f38 < D_U_001D59B0) {
            obj->f38 = D_U_001D59B0;
        }
    } else {
        if (obj->f38 <= D_U_001D59B0) {
            obj->f38 += 1.0f;
            obj->f3C = func_U_0037E208(30, 120);
        }
        if (obj->f38 >= 1.0f - D_U_001D59B0) {
            obj->f38 = 1.0f - D_U_001D59B0;
        }
    }
}
/* localdecomp:end func_U_00383BB0 */
