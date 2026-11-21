#include "common.h"

/* localdecomp:start func_L01_003C7560 */
extern s32 D_L01_001DFB40_003C7560;
extern s32 D_L01_001DEC34;
extern f32 D_L01_001DEC28_003C7560;
extern f32 D_L01_001DEC2C_003C7560;
extern f32 D_L01_001DEC24_003C7560;
extern f32 D_L01_001DEC44_003C7560;
extern f32 D_L01_001DEC48_003C7560;
extern f32 D_L01_001DEC40_003C7560;
__asm__(".extern D_L01_001DFB40_003C7560, 16");
__asm__(".extern D_L01_001DEC34, 4");
__asm__(".extern D_L01_001DEC28_003C7560, 4");
__asm__(".extern D_L01_001DEC2C_003C7560, 4");
__asm__(".extern D_L01_001DEC24_003C7560, 4");
__asm__(".extern D_L01_001DEC44_003C7560, 4");
__asm__(".extern D_L01_001DEC48_003C7560, 4");
__asm__(".extern D_L01_001DEC40_003C7560, 4");
extern s32 func_L01_003C7000(void *, void *);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);

s32 func_L01_003C7560(void *m, u8 *v) {
    if (D_L01_001DFB40_003C7560 - D_L01_001DEC34 < *(s32 *)(v + 0xA4)) {
        func_L01_003C7000(m, v);
    } else {
        func_L01_00448890(v + 0x674, 0.0f, v + 0x98, 0,
                          D_L01_001DEC28_003C7560 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC2C_003C7560 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC24_003C7560 * 0.017453292f * 0.0200000014f);
        *(f32 *)(v + 0x694) = *(f32 *)(v + 0x674);
    }
    func_003C41A0((f32 *)(v + 0x6A8), v + 0x9C, 0.0f,
                  D_L01_001DEC44_003C7560 * 0.017453292f * 0.000400000019f,
                  D_L01_001DEC48_003C7560 * 0.017453292f * 0.000400000019f,
                  D_L01_001DEC40_003C7560 * 0.017453292f * 0.0200000014f);
    if (*(f32 *)(v + 0x674) == 0.0f && *(f32 *)(v + 0x6A8) == 0.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003C7560 */

/* localdecomp:start func_L01_003C76A0 */
typedef struct { char p0[0xC8]; f32 timer; char p1[0x5F0]; s32 index; char p2[0x10]; s32 a[8]; s32 b[8]; s32 c[4]; s32 d[8]; } State_003C76A0;
extern void func_L01_003C6EF0_003C76A0(void *, State_003C76A0 *);
extern s32 func_L01_003C6860_003C76A0(void *);
extern void func_L01_003C7810_003C76A0(void *, State_003C76A0 *, s32, s32, s32);
extern void func_L01_004450F0_003C76A0(void *, s32, s32);
extern void func_L01_003C54E8_003C76A0(void *, State_003C76A0 *);
extern void func_L01_003C57B0_003C76A0(void *, State_003C76A0 *, s32);
extern void func_L01_003C6E78_003C76A0(void *, State_003C76A0 *);
extern void func_L01_003C5290_003C76A0(void *, State_003C76A0 *);
extern f32 D_L01_001DEC80_003C76A0;
__asm__(".extern D_L01_001DEC80_003C76A0, 4");

void func_L01_003C76A0(void *obj, State_003C76A0 *s, s32 enabled) {
    func_L01_003C6EF0_003C76A0(obj, s);
    if (enabled && s->d[s->index] != -1 && !func_L01_003C6860_003C76A0(obj)) {
        func_L01_003C7810_003C76A0(obj, s, s->d[s->index], s->a[s->index], 1);
        s->timer = D_L01_001DEC80_003C76A0 * 0.0200000014f;
        if (s->c[s->index] != -1) {
            func_L01_004450F0_003C76A0(obj, 1, -1);
        } else {
            func_L01_004450F0_003C76A0(obj, 2, -1);
        }
        func_L01_003C54E8_003C76A0(obj, s);
    } else {
        s->timer = 0;
        func_L01_003C57B0_003C76A0(obj, s, s->a[s->index]);
        if (s->b[s->index]) {
            func_L01_004450F0_003C76A0(obj, 5, -1);
        } else {
            func_L01_004450F0_003C76A0(obj, 4, -1);
        }
        func_L01_003C6E78_003C76A0(obj, s);
        func_L01_003C5290_003C76A0(obj, s);
    }
}
/* localdecomp:end func_L01_003C76A0 */

/* localdecomp:start func_L01_003C7810 */
#include "vu0.h"

typedef struct { s32 count; s32 pad[3]; vu0_v4 pts[1]; } Path_003C7810;
extern Path_003C7810 *D_L01_0021F6C0_003C7810[];
extern u8 *D_L01_001E0100_003C7810;
extern f32 D_L01_001DEC70_003C7810;
__asm__(".extern D_L01_001DEC70_003C7810, 4");
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_003C5728_003C7810(void *, void *, void *, void *);

void func_L01_003C7810(void *obj, void *st, s32 idx, s32 target, s32 snap) {
    u8 *o = obj;
    u8 *s = st;
    Path_003C7810 *p;
    vu0_v4 v;
    vu0_v4 d;
    vu0_q qa, qb;
    u8 *m;

    *(s32 *)(s + 0xC0) = idx;
    p = D_L01_0021F6C0_003C7810[idx];
    if (snap) {
        vu0_v4 *pos = (vu0_v4 *)(o + 0x10);
        vu0_v4 *rot = (vu0_v4 *)(o + 0xF0);
        *pos = p->pts[0];
        vec_sub_ba(&v, &p->pts[1], &p->pts[0]);
        qzero(rot);
        *(f32 *)(o + 0xF8) = func_0038D160(v.x, v.y);
        func_L01_003C5728_003C7810(o, s, pos, rot);
        *(f32 *)(s + 0xC4) = 0.0f;
        *(vu0_v4 *)(s + 0x140) = p->pts[0];
        *(f32 *)(s + 0x14C) = -1.0f;
    } else {
        vu0_v4 *pos = (vu0_v4 *)(o + 0x10);
        vu0_v4 *first = &p->pts[0];
        if (func_0038CF00(pos, first) < D_L01_001DEC70_003C7810) {
            *(f32 *)(s + 0xC4) = 0.0f;
            *(vu0_v4 *)(s + 0x140) = p->pts[0];
            *(f32 *)(s + 0x14C) = -1.0f;
        } else {
            *(f32 *)(s + 0xC4) = -1.0f;
            *(vu0_v4 *)(s + 0x140) = *pos;
            *(f32 *)(s + 0x14C) = func_0038CF00(pos, first);
        }
    }
    if (target != -1) {
        m = D_L01_001E0100_003C7810 + target * 128;
        *(vu0_v4 *)(s + 0x150) = *(vu0_v4 *)(m + 0x30);
        p->pts[p->count - 1].w = func_0038CF00(m + 0x30, &p->pts[p->count - 1]);
        func_0038CF68(s + 0x160, m, 10.0f);
        vec_add_ba(s + 0x160, s + 0x160, m + 0x30);
        *(f32 *)(s + 0x15C) = func_0038CF00(s + 0x160, m + 0x30);
        *(f32 *)(s + 0x16C) = 5.0f;
    } else {
        vec_sub_ba(&d, &p->pts[p->count - 1], &p->pts[p->count - 2]);
        func_0038CF68(&d, &d, 0.1f);
        p->pts[p->count - 1].w = 0.1f;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(d));
        vec_add_ba(s + 0x150, &p->pts[p->count - 1], &d);
        *(f32 *)(s + 0x15C) = 0.1f;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(s + 0x150)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(s + 0x160)) : "j"(qa));
        *(f32 *)(s + 0x16C) = 0.1f;
    }
    qzero(s + 0x130);
}
/* localdecomp:end func_L01_003C7810 */

/* localdecomp:start func_L01_003C7A68 */
extern void func_L01_00477ED0(int, int, float, float, float);
void func_L01_003C7A68(void *a, char *b, float f) {
    func_L01_00477ED0(*(int *)(b + 192), 1, *(float *)(b + 332), *(float *)(b + 196), f);
}
/* localdecomp:end func_L01_003C7A68 */

/* localdecomp:start func_L01_003C7A98 */
f32 func_L01_003C7A98(u8 *s, Path_003C7810 *p, s32 *idx, f32 t, f32 dist) {
    f32 rem = 1.0f;
    f32 step;
    f32 k;
    while (rem > 0.0f) {
        if (t < 0.0f) {
            *idx = -1;
            step = dist / *(f32 *)(s + 0x14C) * rem;
            if (t + step >= 0.0f) {
                *idx = 0;
                k = (0.0f - t) / step;
                rem -= k * rem;
                t = 0.0f;
            } else {
                t += step;
                rem = 0.0f;
            }
        } else {
            s32 i = (s32)t;
            f32 frac;
            *idx = i;
            step = dist / p->pts[i].w * rem;
            frac = t + step - (f32)i;
            if (frac >= 1.0f && i < p->count - 1) {
                k = (step - (frac - 1.0f)) / step;
                t += step * k;
                rem -= k * rem;
                *idx = (s32)t;
            } else {
                t += step;
                rem = 0.0f;
            }
        }
    }
    return t;
}
/* localdecomp:end func_L01_003C7A98 */

/* localdecomp:start func_L01_003C7BC0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s32 count;
    u128_t e[1];
} L_003C7BC0;
extern void func_0038CDF8(u8 *, u128_t *, u128_t *);

static inline u128_t quad_003C7BC0(u128_t *p) {
    return *p;
}

void func_L01_003C7BC0(u8 *a0, L_003C7BC0 *l, s32 idx, u8 *out) {
    u128_t a;
    u128_t b;
    s32 n = l->count;
    if (idx >= n) {
        a = quad_003C7BC0((u128_t *)(a0 + 0x150));
        b = quad_003C7BC0((u128_t *)(a0 + 0x160));
    } else if (idx == n - 2) {
        a = quad_003C7BC0(&l->e[idx]);
        b = quad_003C7BC0(&l->e[idx + 1]);
    } else if (idx == n - 1) {
        a = quad_003C7BC0(&l->e[idx]);
        b = quad_003C7BC0((u128_t *)(a0 + 0x150));
    } else {
        if (idx < 0) {
            a = quad_003C7BC0((u128_t *)(a0 + 0x140));
        } else {
            a = quad_003C7BC0(&l->e[idx]);
        }
        b = quad_003C7BC0(&l->e[idx + 1]);
    }
    func_0038CDF8(out, &a, &b);
}
/* localdecomp:end func_L01_003C7BC0 */

/* localdecomp:start func_L01_003C7C80 */
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 D_L01_001DECC8;
extern f32 D_L01_001DECCC;
extern f32 D_L01_001DECD0;
__asm__(".extern D_L01_001DECC8, 4");
__asm__(".extern D_L01_001DECCC, 4");
__asm__(".extern D_L01_001DECD0, 4");

void func_L01_003C7C80(u8 *o, void *unused, vu0_v4 pos, f32 *outA, f32 *outB) {
    vu0_v4 d;
    vec_sub_ab(&d, o + 0x10, &pos);
    if (func_0038CEA8(&d) > D_L01_001DECC8) {
        func_0038CF68(&d, &d, D_L01_001DECC8);
    }
    *outA = func_0038CE68(&d, o + 0xD0) * D_L01_001DECCC;
    *outB = func_0038CE68(&d, o + 0xC0) * D_L01_001DECD0;
}
/* localdecomp:end func_L01_003C7C80 */

INCLUDE_ASM("asm/levels", func_L01_003C7D38);

INCLUDE_ASM("asm/levels", func_L01_003C8400);

INCLUDE_ASM("asm/levels", func_L01_003C88E0);

/* localdecomp:start func_L01_003C8D60 */
extern void func_L01_003C8400(u8 *, u8 *);
extern void func_L01_003C88E0(u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);

void func_L01_003C8D60(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);

    func_L01_003C8400(a0, s);
    func_L01_003C88E0(a0, s);
    func_003A9440(8, 0);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_003C8D60 */
