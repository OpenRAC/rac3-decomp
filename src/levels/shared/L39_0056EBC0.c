#include "common.h"

/* localdecomp:start func_L39_0056EBC0 */
#include "vu0.h"
typedef struct { u8 pad0[0x4]; s16 h4; s16 h6; f32 f8; f32 fC; } Q_0056EBC0;
typedef struct { u8 pad0[0x58]; f32 f58; } R_0056EBC0;
typedef struct { u8 pad0[0x70]; u8 *p70; u8 pad74[0x20]; s32 i94; } A_0056EBC0;
typedef struct { u8 pad0[0xF0]; u8 *pF0; u8 padF4[0xC]; s32 i100; } F_0056EBC0;
typedef struct { u8 pad0[0x80]; u8 v80[0x24]; f32 fA4; u8 padA8[0xF0 - 0xA8]; F_0056EBC0 b; u8 pad[0x460 - 0xF0 - sizeof(F_0056EBC0)]; } E_0056EBC0;
extern E_0056EBC0 D_L39_0024DEE0_0056EBC0[];
extern f32 func_0038CE68(void *, void *);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
void func_L39_0056EBC0(u8 *arg, f32 *out1, f32 *out2) {
    A_0056EBC0 *a = (A_0056EBC0 *)arg;
    s32 idx = a->i94;
    Q_0056EBC0 *q = (Q_0056EBC0 *)(a->p70 + 0x260);
    R_0056EBC0 *r = (R_0056EBC0 *)(a->p70 + 0x180);
    E_0056EBC0 *e = &D_L39_0024DEE0_0056EBC0[idx];
    F_0056EBC0 *g = &D_L39_0024DEE0_0056EBC0[idx].b;
    f32 t;
    if (q->h6 == 0 && ((q->h4 != 0 && e->fA4 == 0.0f && func_0038CE68(g->pF0 + 0xC0, a) <= -0.3f)
                       || (fabs_asm(e->fA4) > 0.0001f && func_0038CE68(e->v80, a) <= -0.3f))) {
        q->h4 = 100;
        t = e->fA4 * 14.2857f;
        if (t > 1.0f) t = 1.0f;
        {
            f32 v = r->f58 + (q->fC - r->f58) * t;
            if (q->f8 < v) q->f8 = v;
        }
        func_L01_003E8BD0(a->i94, 0, q->f8, 0.003f);
        *out1 = t * 0.02f + 0.02f;
        *out2 = t * 0.100000009f + 0.2f;
    } else {
        if (q->h4 != 0) {
            q->h4 = 0;
            q->f8 = r->f58;
        }
        if (g->i100 == 0x86) {
            *out1 = 0.04f;
            *out2 = 0.2f;
        } else {
            *out1 = 0.02f;
            *out2 = 0.2f;
        }
    }
}
/* localdecomp:end func_L39_0056EBC0 */

/* localdecomp:start func_L39_0056EE00 */
#include "vu0.h"
typedef int Q_0056EE00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0056EE00;
typedef struct {
    u8 pad0[0x460];
} Ent_0056EE00;

extern Ent_0056EE00 D_L39_0024DEE0[];
extern V4_0056EE00 D_L39_0025F770;
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern void func_L39_0056EBC0(u8 *, f32 *, f32 *);
extern f32 func_L39_00578EA0(f32, f32 *, f32, f32, f32, f32);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

void func_L39_0056EE00(u8 *a)
{
    V4_0056EE00 v0;
    V4_0056EE00 v10;
    V4_0056EE00 v20;
    V4_0056EE00 v30;
    V4_0056EE00 v40;
    V4_0056EE00 v50;
    V4_0056EE00 v60;
    V4_0056EE00 v70;
    V4_0056EE00 old;
    V4_0056EE00 d;
    f32 fa;
    f32 fb;
    u8 *ent = (u8 *)&D_L39_0024DEE0[*(s32 *)(a + 0x94)];
    u8 *st = (u8 *)D_L39_0024DEE0 + 0xF0 + *(s32 *)(a + 0x94) * 0x460;
    u8 *cam = *(u8 **)(a + 0x70);
    u8 *c180;
    u8 *c60;
    f32 len1, len2, dot1, dot2;
    f32 ang1 = 0.0f;
    f32 ang2;
    f32 r2;
    f32 t;
    f32 zero;
    f32 sgn;
    f32 dd, ll, ang3;
    f32 side;
    s32 i;
    s32 hit;

    c180 = cam + 0x180;
    {
        Q_0056EE00 qt, qd;
        __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_0056EE00 *)(cam + 0xB0)));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(*(V4_0056EE00 *)(cam + 0x180)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_0056EE00 *)(cam + 0x0)) : "j"(qt));
    }
    c60 = cam + 0x60;
    len1 = func_0038CEA8(c180);
    len2 = func_0038CEA8(cam + 0x190);
    func_L39_0056EBC0(a, &fa, &fb);
    len2 = func_L39_00578EA0(len2, (f32 *)(cam + 0x1A8), len1, fa, fb, ang1);
    dot1 = func_0038CE68(c180, (ent + 0x20));
    if (!(fabs_asm(len1) < 0.0001f)) {
        t = dot1 / len1;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < -1.0f) {
            t = -1.0f;
        }
        ang1 = func_0038D0C8(t);
    }
    dot2 = func_0038CE68(c180 + 0x10, (ent + 0x20));
    if (fabs_asm(len2) < 0.0001f) {
        ang2 = 0.0f;
    } else {
        t = dot2 / len2;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < -1.0f) {
            t = -1.0f;
        }
        ang2 = func_0038D0C8(t);
    }
    zero = 0.0f;
    ang2 = func_00382C58((f32 *)(c180 + 0x24), ang2, ang1, 0.015f, 0.2f, zero);
    func_0038CE20(&v0, (ent + 0x20), dot1);
    vec_sub_ba(&v10, c180, &v0);
    func_0038CE20(&v20, (ent + 0x20), dot2);
    vec_sub_ba(&v30, c180 + 0x10, &v20);
    dd = func_0038CE68(&v10, &v30);
    ll = func_0038CEA8(&v10) * func_0038CEA8(&v30);
    if (ll < 0.0001f) {
        ang3 = zero;
    } else {
        ang3 = 1.5707964f - func_0038D0C8(dd / ll);
    }
    if (*(s16 *)(st + 0x126) != 0 && *(s32 *)(st + 0x100) != 0x7D) {
        r2 = func_00382C58((f32 *)(c180 + 0x20), 0.0f, ang3, 0.2f, 0.2f, 0.0f);
    } else {
        r2 = func_00382C58((f32 *)(c180 + 0x20), 0.0f, ang3, 0.015f, 0.2f, 0.0f);
    }
    func_0038CE90(&v40, &v30, (ent + 0x20));
    side = func_0038CE68(&v40, &v10);
    sgn = -1.0f;
    if (side >= 0.0f) {
        sgn = 1.0f;
    }
    func_0038D890(&v50, &v30, (ent + 0x20), r2 * sgn);
    hit = 0;
    func_0038CE90(&v40, (ent + 0x20), &v50);
    func_0038D890(&v50, &v50, &v40, ang2);
    func_0038CF68(c180 + 0x10, &v50, len2);
    func_0038CE20(&v60, (ent + 0x20), *(f32 *)(c180 + 0x30));
    vec_add_ba(&v70, &v60, c60 + 0x60);
    vec_add_ba(a + 0x30, &v70, c180 + 0x10);
    old = *(V4_0056EE00 *)(a + 0x30);
    for (i = 0; i < 3; i++) {
        if (func_L01_003FB640(a + 0x30, 0x36, 0, 0.25f)) {
            *(V4_0056EE00 *)(a + 0x30) = D_L39_0025F770;
            hit = 1;
        } else {
            break;
        }
    }
    if (hit) {
        vec_sub_ba(&d, a + 0x30, &old);
        {
            Q_0056EE00 qt, qd;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_0056EE00 *)(c60 + 0x0)));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_0056EE00 *)(c60 + 0x0)) : "j"(qt));
        }
        vec_add_ba(c60 + 0x60, c60 + 0x60, &d);
        {
            Q_0056EE00 qt, qd;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_0056EE00 *)(c60 + 0xB0)));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_0056EE00 *)(c60 + 0xB0)) : "j"(qt));
        }
        vec_add_ab(c60 + 0x30, c60 + 0x30, &d);
    }
}
/* localdecomp:end func_L39_0056EE00 */
