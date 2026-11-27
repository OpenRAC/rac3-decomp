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

/* localdecomp:start func_L01_003C7D38 */
extern f32 D_L01_001DEC74_003C7D38;
extern f32 D_L01_001DEC7C_003C7D38;
extern f32 D_L01_001DEC80_003C7D38;
extern f32 D_L01_001DEC84_003C7D38;
extern f32 D_L01_001DEC88_003C7D38;
extern f32 D_L01_001DEC90_003C7D38;
extern f32 D_L01_001DEC94_003C7D38;
extern f32 D_L01_001DEC98_003C7D38;
extern f32 D_L01_001DEC9C_003C7D38;
extern f32 D_L01_001DECA0_003C7D38;
extern f32 D_L01_001DECA4_003C7D38;
extern f32 D_L01_001DECA8_003C7D38;
extern f32 D_L01_001DECAC_003C7D38;
extern f32 D_L01_001DECB0_003C7D38;
extern f32 D_L01_001DECB4_003C7D38;
extern f32 D_L01_001DECB8_003C7D38;
extern f32 D_L01_001DECBC_003C7D38;
extern f32 D_L01_001DECC0_003C7D38;
extern s32 D_L01_001DECD4_003C7D38;
__asm__(".extern D_L01_001DEC74_003C7D38, 4");
__asm__(".extern D_L01_001DEC7C_003C7D38, 4");
__asm__(".extern D_L01_001DEC80_003C7D38, 4");
__asm__(".extern D_L01_001DEC84_003C7D38, 4");
__asm__(".extern D_L01_001DEC88_003C7D38, 4");
__asm__(".extern D_L01_001DEC90_003C7D38, 4");
__asm__(".extern D_L01_001DEC94_003C7D38, 4");
__asm__(".extern D_L01_001DEC98_003C7D38, 4");
__asm__(".extern D_L01_001DEC9C_003C7D38, 4");
__asm__(".extern D_L01_001DECA0_003C7D38, 4");
__asm__(".extern D_L01_001DECA4_003C7D38, 4");
__asm__(".extern D_L01_001DECA8_003C7D38, 4");
__asm__(".extern D_L01_001DECAC_003C7D38, 4");
__asm__(".extern D_L01_001DECB0_003C7D38, 4");
__asm__(".extern D_L01_001DECB4_003C7D38, 4");
__asm__(".extern D_L01_001DECB8_003C7D38, 4");
__asm__(".extern D_L01_001DECBC_003C7D38, 4");
__asm__(".extern D_L01_001DECC0_003C7D38, 4");
__asm__(".extern D_L01_001DECD4_003C7D38, 4");
extern f32 func_L01_003C7A68_003C7D38(void *, char *, float);
extern f32 func_L01_003C7A98_003C7D38(u8 *, Path_003C7810 *, s32 *, f32, f32);
extern void func_L01_003C7BC0_003C7D38(u8 *, Path_003C7810 *, s32, u8 *, f32);
extern void func_L01_003C7C80_003C7D38(u8 *, void *, vu0_v4, f32 *, f32 *);
extern Path_003C7810 *D_L01_0021F6C0_003C7D38[];
extern u8 *D_L01_001E0100_003C7D38;
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L01_003C7D38(u8 *o, u8 *s) {
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 tgt;
    vu0_v4 q;
    vu0_v4 d2;
    f32 unused;
    s32 idx;
    Path_003C7810 *path;
    u8 *m;
    f32 k, t, t2, t3, v, frac, lim1, lim2, lim3, lim4, lim5, a, h;
    s32 r, clamped, off;
    u8 *e;

    e = s + *(s32 *)(s + 0x6BC) * 4;
    off = *(s32 *)(e + 0x6D0) * 128;
    pos = *(vu0_v4 *)(o + 0x10);
    path = D_L01_0021F6C0_003C7D38[*(s32 *)(s + 0xC0)];
    m = D_L01_001E0100_003C7D38 + off;
    h = func_L01_003C7A68_003C7D38(o, s, D_L01_001DEC74_003C7D38);
    t = *(f32 *)(s + 0xC4);
    if (t < 0.0f) {
        vec_sub_ab(&d, &path->pts[0], s + 0x140);
    } else {
        idx = (s32)t;
        if (idx == path->count - 1) {
            vec_sub_ab(&d, s + 0x150, &path->pts[idx]);
        } else {
            vec_sub_ab(&d, &path->pts[idx + 1], &path->pts[idx]);
        }
    }
    func_0038CF68(&d, &d, 1.0f);
    a = func_0038CE68(&d, o + 0xC0);
    if (a <= 0.0f) {
        t3 = D_L01_001DEC88_003C7D38;
        a = D_L01_001DEC80_003C7D38;
    } else {
        a = a * D_L01_001DEC7C_003C7D38;
        if (1.0f < a) {
            a = 1.0f;
        }
        k = D_L01_001DEC80_003C7D38 + (D_L01_001DEC74_003C7D38 - D_L01_001DEC80_003C7D38) * a;
        t3 = D_L01_001DEC88_003C7D38 + (D_L01_001DEC84_003C7D38 - D_L01_001DEC88_003C7D38) * a;
        a = k;
    }
    unused = 0.0f;
    r = 0;
    func_003C41A0(&unused, s + 0xC8, h, t3 * 0.000400000019f, t3 * 0.000400000019f, a * 0.0200000014f);
    t2 = func_L01_003C7A98_003C7D38(s, path, &idx, *(f32 *)(s + 0xC4), *(f32 *)(s + 0xC8));
    *(f32 *)(s + 0xC4) = t2;
    clamped = 0;
    if (!(idx < path->count - 1)) {
        idx = path->count - 1;
        clamped = 1;
    }
    frac = t2 - (f32)idx;
    if (clamped) {
        if (1.0f <= frac) {
            frac = 1.0f;
            r = 2;
            *(f32 *)(s + 0xC4) = t2 - *(f32 *)(s + 0xC8) / path->pts[idx].w;
        }
    }
    func_L01_003C7BC0_003C7D38(s, path, idx, o + 0x10, frac);
    if (o[0x20] == 3 && !(idx < path->count - D_L01_001DECD4_003C7D38)) {
        func_L01_003C7C80_003C7D38(o, s, pos, &tgt.x, &tgt.y);
        tgt.x = -tgt.x;
        tgt.y = -tgt.y;
        tgt.x = func_0038DAB8(tgt.x, *(f32 *)(m + 0x70));
        lim1 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim1 < tgt.y) {
            tgt.y = lim1;
        } else if (tgt.y < -lim1) {
            tgt.y = -lim1;
        }
        tgt.y = func_0038DAB8(tgt.y, *(f32 *)(m + 0x74));
        tgt.z = *(f32 *)(m + 0x78);
    } else if ((*(f32 *)(s + 0x14C) > 0.0f && idx == -1) || (*(f32 *)(s + 0x14C) < 0.0f && idx == 0)) {
        func_L01_003C7C80_003C7D38(o, s, pos, &tgt.x, &tgt.y);
        tgt.x = func_0038DAB8(tgt.x, *(f32 *)(m + 0x70));
        lim2 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim2 < tgt.y) {
            tgt.y = lim2;
        } else if (tgt.y < -lim2) {
            tgt.y = -lim2;
        }
        tgt.y = func_0038DAB8(tgt.y, *(f32 *)(m + 0x74));
        tgt.z = *(f32 *)(o + 0xF8);
    } else {
        v = *(f32 *)(s + 0xC8) * D_L01_001DEC90_003C7D38;
        if (D_L01_001DEC94_003C7D38 < v) {
            v = D_L01_001DEC94_003C7D38;
        } else if (v < D_L01_001DEC98_003C7D38) {
            v = D_L01_001DEC98_003C7D38;
        }
        t3 = func_L01_003C7A98_003C7D38(s, path, &idx, *(f32 *)(s + 0xC4), v);
        idx = (s32)t3;
        func_L01_003C7BC0_003C7D38(s, path, idx, (u8 *)&q, t3 - (f32)idx);
        vec_sub_ab(&d2, &q, o + 0x10);
        tgt.x = 0.0f;
        v = func_0038CED8(&d2);
        tgt.y = -func_0038D160(v, d2.z);
        lim3 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim3 < tgt.y) {
            tgt.y = lim3;
        } else if (tgt.y < -lim3) {
            tgt.y = -lim3;
        }
        tgt.z = func_0038D160(d2.x, d2.y);
    }
    lim4 = 0.017453292f;
    func_L01_00448890(o + 0xF4, tgt.y, s + 0x134, 0, D_L01_001DECA4_003C7D38 * lim4 * 0.000400000019f,
                      D_L01_001DECA4_003C7D38 * lim4 * 0.000400000019f, D_L01_001DECA8_003C7D38 * lim4 * 0.0200000014f);
    func_L01_00448890(o + 0xF8, tgt.z, s + 0x138, 0, D_L01_001DECAC_003C7D38 * lim4 * 0.000400000019f,
                      D_L01_001DECAC_003C7D38 * lim4 * 0.000400000019f, D_L01_001DECB0_003C7D38 * lim4 * 0.0200000014f);
    tgt.x = func_0038DAB8(tgt.x, *(f32 *)(s + 0x138) * *(f32 *)(s + 0xC8) * D_L01_001DECC0_003C7D38);
    lim5 = D_L01_001DECB4_003C7D38 * lim4;
    if (lim5 < tgt.x) {
        tgt.x = lim5;
    } else if (tgt.x < -lim5) {
        tgt.x = -lim5;
    }
    func_L01_00448890(o + 0xF0, tgt.x, s + 0x130, 0, D_L01_001DECBC_003C7D38 * 0.017453292f * 0.000400000019f,
                      D_L01_001DECBC_003C7D38 * 0.017453292f * 0.000400000019f, D_L01_001DECB8_003C7D38 * 0.017453292f * 0.0200000014f);
    *(vu0_q *)&tgt = *(vu0_q *)(m + 0x70);
    if (r == 2) {
        if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF0), tgt.x))) {
            r = 1;
        } else if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF4), tgt.y))) {
            r = 1;
        } else if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF8), tgt.z))) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L01_003C7D38 */

/* localdecomp:start func_L01_003C8400 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C8400;
typedef struct { f32 x, y; } V2_003C8400;
typedef struct { f32 v[3]; } V3_003C8400;
typedef struct { u8 pad[8]; u8 b8; } O_003C8400;
typedef struct { u8 pad[0x58]; O_003C8400 *tab[6]; } Own_003C8400;
__asm__(".extern D_L01_001DEE78, 4");
__asm__(".extern D_L01_001DEE7C, 4");
__asm__(".extern D_L01_001DEE90, 4");
__asm__(".extern D_L01_001DEE5C, 4");
__asm__(".extern D_L01_001DEE60, 4");
__asm__(".extern D_L01_001DEEB0, 4");
__asm__(".extern D_L01_001DEE80, 4");
__asm__(".extern D_L01_001DEEF0, 4");
__asm__(".extern D_L01_001DEE70, 4");
__asm__(".extern D_L01_001DEE74, 4");
__asm__(".extern D_L01_001DEE64, 4");
__asm__(".extern D_L01_001DEE68, 4");
__asm__(".extern D_L01_001DEF10, 4");
extern s32 D_L01_001DEE78;
extern s32 D_L01_001DEE7C;
extern s32 D_L01_001DEE90;
extern s32 D_L01_001DEE5C;
extern s32 D_L01_001DEE60;
extern s32 D_L01_001DEEB0;
extern f32 D_L01_001DEE80;
extern s32 D_L01_001DEEF0;
extern f32 D_L01_001DEE70;
extern f32 D_L01_001DEE74;
extern s32 D_L01_001DEE64;
extern s32 D_L01_001DEE68;
extern s32 D_L01_001DEF10;
extern s32 D_L01_001DEEA0_003C8400;
extern V4_003C8400 D_L01_002BB450[];
extern s32 D_L01_001E2240_003C8400;
extern V2_003C8400 D_L01_001E2280_003C8400;
extern s32 D_L01_001E2270_003C8400;
extern V4_003C8400 D_L01_001E29E0_003C8400[];
extern V4_003C8400 D_L01_001E29C0_003C8400[];
extern s32 D_L01_001DFB40_003C8400;
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern s32 func_00382468();
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CC88();
extern long func_00389598(s32);
extern void func_003D3A24();
extern f32 func_0038CF00(void *, void *);
extern void func_00389478();
void func_L01_003C8400(u8 *cam, u8 *owner) {
    V4_003C8400 m0, m10, m20, m30;
    V4_003C8400 m40[4];
    s32 base;
    V4_003C8400 *e;
    V2_003C8400 *dst;
    f32 lim;
    s32 n;
    f32 u;
    s32 i;
    s32 j;
    s32 k;
    O_003C8400 **tab;
    f32 s;
    s32 col;
    f32 t;
    func_003A9440(8, 5);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    n = D_L01_001DEE78 / D_L01_001DEE7C;
    base = (D_L01_001DFB40_003C8400 + n) % D_L01_001DEE78;
    base = D_L01_001DFB40_003C8400 + base / n * n;
    for (i = 0; i < 6; i++) {
        if (((Own_003C8400 *)owner)->tab[i] != 0) {
            ((Own_003C8400 *)owner)->tab[i]->b8 = func_00382468(0xFF);
        }
        func_0038D000(&m0, &D_L01_002BB450[i], cam + 0xC0);
        vec_add_ab(&m0, &m0, cam + 0x10);
        for (j = 0; j < D_L01_001DEE7C; j++) {
            e = &D_L01_002BB450[i];
            t = (f32)((base + D_L01_001DEE78 / D_L01_001DEE7C * j) % D_L01_001DEE78) / (f32)D_L01_001DEE78;
            if (0.0f < e->y) func_0038D000(&m10, &D_L01_001DEE90, cam + 0xC0);
            else func_0038D000(&m10, &D_L01_001DEEA0_003C8400, cam + 0xC0);
            func_0038CE20((f32 *)&m10, &m10, t);
            vec_add_ab(&m30, &m0, &m10);
            u = 1.0f;
            col = func_0038DBD8(D_L01_001DEE5C, D_L01_001DEE60, t);
            for (k = 0; k < 4; k++) {
                V4_003C8400 *pm = &((V4_003C8400 *)&D_L01_001DEEB0)[k];
                s32 *pf = &(&D_L01_001E2270_003C8400)[k];
                *pf = col;
                m20 = *pm;
                s = D_L01_001DEE80 * t + u;
                m20.y *= s;
                m20.z *= s;
                func_0038D000(&m40[k], &m20, D_L01_001E29E0_003C8400);
                vec_add_ab(&m40[k], &m40[k], &m30);
                func_0038CC88(&((V3_003C8400 *)&D_L01_001E2240_003C8400)[k], &m40[k], 0xC);
                dst = &(&D_L01_001E2280_003C8400)[k];
                {
                    f32 *a = (f32 *)&((V2_003C8400 *)&D_L01_001DEEF0)[k], *b = (f32 *)dst;
                    s32 c;
                    for (c = 1; c != -1; c--) *b++ = *a++;
                }
            }
            func_003A9440(6, func_00389598(0x3B));
            func_003A9440(0x42, 0x800000006AUL);
            func_003D3A24(4, &D_L01_001E2240_003C8400, &D_L01_001E2270_003C8400, &D_L01_001E2280_003C8400, 1);
            u = D_L01_001DEE70 * (1.0f / (func_0038CF00(&m30, D_L01_001E29C0_003C8400) + 1.0f));
            lim = D_L01_001DEE74;
            if (lim < u) u = lim;
            else if (u < -lim) u = -lim;
            col = func_0038DBD8(D_L01_001DEE64, D_L01_001DEE68, t);
            for (k = 0; k < 4; k++) {
                (&D_L01_001E2270_003C8400)[k] = col;
                func_00389478(&m40[k], &(&D_L01_001E2280_003C8400)[k], &((f32 *)&D_L01_001E2280_003C8400 + 1)[k * 2]);
                (&D_L01_001E2280_003C8400)[k].x += ((V2_003C8400 *)&D_L01_001DEF10)[k].x * u;
                ((f32 *)&D_L01_001E2280_003C8400 + 1)[k * 2] += ((V2_003C8400 *)((f32 *)&D_L01_001DEF10 + 1))[k].x * u;
            }
            func_003A9440(6, func_00389598(-1));
            func_003A9440(0x42, 0x8000000054UL);
            func_003D3A24(4, &D_L01_001E2240_003C8400, &D_L01_001E2270_003C8400, &D_L01_001E2280_003C8400, 1);
        }
    }
}
/* localdecomp:end func_L01_003C8400 */

/* localdecomp:start func_L01_003C88E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C88E0;
typedef struct { u8 pad[0x70]; u8 *a[4]; u8 *b[4]; } Own_003C88E0;
extern f32 D_L01_001DEC74;
__asm__(".extern D_L01_001DEC74, 4");
extern f32 D_L01_001DEDB0;
__asm__(".extern D_L01_001DEDB0, 4");
extern f32 D_L01_001DEDB4;
__asm__(".extern D_L01_001DEDB4, 4");
extern f32 D_L01_001DEF68;
__asm__(".extern D_L01_001DEF68, 4");
extern f32 D_L01_001DEF6C;
__asm__(".extern D_L01_001DEF6C, 4");
extern f32 D_L01_001DEF40;
__asm__(".extern D_L01_001DEF40, 4");
extern f32 D_L01_001DEF44;
__asm__(".extern D_L01_001DEF44, 4");
extern f32 D_L01_001DEF48;
__asm__(".extern D_L01_001DEF48, 4");
extern f32 D_L01_001DEF4C;
__asm__(".extern D_L01_001DEF4C, 4");
extern f32 D_L01_001DEF58;
__asm__(".extern D_L01_001DEF58, 4");
extern f32 D_L01_001DEF5C;
__asm__(".extern D_L01_001DEF5C, 4");
extern f32 D_L01_001DEF60;
__asm__(".extern D_L01_001DEF60, 4");
extern f32 D_L01_001DEF64;
__asm__(".extern D_L01_001DEF64, 4");
extern s32 D_L01_001DEF34;
__asm__(".extern D_L01_001DEF34, 4");
extern s32 D_L01_001DEF38;
__asm__(".extern D_L01_001DEF38, 4");
extern s32 D_L01_001DEF3C;
__asm__(".extern D_L01_001DEF3C, 4");
extern s32 D_L01_001DEF50;
__asm__(".extern D_L01_001DEF50, 4");
extern s32 D_L01_001DEF54;
__asm__(".extern D_L01_001DEF54, 4");
extern s32 D_L01_001DEF30;
__asm__(".extern D_L01_001DEF30, 4");
extern s32 D_L01_001DEDA0;
__asm__(".extern D_L01_001DEDA0, 4");
extern s32 D_L01_001DED60;
__asm__(".extern D_L01_001DED60, 4");
extern s32 D_L01_001DBCA0_003C88E0;
__asm__(".extern D_L01_001DBCA0_003C88E0, 4");
extern s32 D_L01_001DFB40_003C88E0;
extern s32 D_L01_001DBCA0_3C88E0;
__asm__(".extern D_L01_001DBCA0_3C88E0, 16");
extern s32 func_00382468_003C88E0(s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038DC20(f32, void *);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
void func_L01_003C88E0(u8 *cam, u8 *o) {
    V4_003C88E0 q;
    V4_003C88E0 m0[3];
    V4_003C88E0 m30;
    V4_003C88E0 m40[3];
    V4_003C88E0 m70;
    f32 k, ph, t, s, w;
    s32 i, j, n, col, al, lo;
    u8 ob;
    for (i = 0; i < 4; i++) {
        if (((Own_003C88E0 *)o)->a[i] != 0) ((Own_003C88E0 *)o)->a[i][8] = func_00382468_003C88E0(0xFF);
        if (((Own_003C88E0 *)o)->b[i] != 0) ((Own_003C88E0 *)o)->b[i][8] = func_00382468_003C88E0(0xFF);
    }
    k = *(f32 *)(o + 0xC8) / (D_L01_001DEC74 * 0.020000001f);
    func_0038D000(&q, &D_L01_001DEDA0, cam + 0xC0);
    vec_add_ab(&q, &q, cam + 0x10);
    q.w = D_L01_001DEDB0;
    if (func_0038DC20(D_L01_001DEDB4, &q) != -1) {
        k = (k - D_L01_001DEF68) / (D_L01_001DEF6C - D_L01_001DEF68);
        D_L01_001DBCA0_003C88E0 = D_L01_001DBCA0_3C88E0 | 1;
        if (1.0f < k) k = 1.0f;
        else if (k < 0.1f) k = 0.1f;
        ph = (f32)(D_L01_001DFB40_003C88E0 % D_L01_001DEF34) / (f32)D_L01_001DEF34;
        func_003A9440(8, 0);
        func_003A9440(0x47, 0x513F1);
        for (i = 0; i < 4; i++) {
            if (((Own_003C88E0 *)o)->a[i] != 0) ((Own_003C88E0 *)o)->a[i][8] = func_00382468_003C88E0(0xFF);
            if (((Own_003C88E0 *)o)->b[i] != 0) ((Own_003C88E0 *)o)->b[i][8] = func_00382468_003C88E0(0xFF);
            m0[0] = *(V4_003C88E0 *)(cam + 0xD0);
            m0[1] = *(V4_003C88E0 *)(cam + 0xE0);
            m0[2] = *(V4_003C88E0 *)(cam + 0xC0);
            func_0038D000(&m30, &((V4_003C88E0 *)&D_L01_001DED60)[i], cam + 0xC0);
            vec_add_ab(&m30, &m30, cam + 0x10);
            for (j = 0; j < D_L01_001DEF3C; j++) {
                n = D_L01_001DEF38;
                t = (f32)((D_L01_001DFB40_003C88E0 + n / D_L01_001DEF3C * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_L01_001DEF44 - D_L01_001DEF40) * t * k + D_L01_001DEF40;
                    s = (D_L01_001DEF4C - D_L01_001DEF48) * t + D_L01_001DEF48;
                } else {
                    w = (D_L01_001DEF5C - D_L01_001DEF58) * t * k + D_L01_001DEF58;
                    s = (D_L01_001DEF64 - D_L01_001DEF60) * t + D_L01_001DEF60;
                }
                col = func_0038DBD8(D_L01_001DEF50, D_L01_001DEF54, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_0038CE20(&m40[0], &m0[0], s);
                func_0038CE20(&m40[1], &m0[1], s);
                func_0038CE20(&m40[2], &m0[2], w);
                vec_sub_ab(&m70, &m30, &m40[2]);
                func_003D9740(m40, D_L01_001DEF30, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
    }
}
/* localdecomp:end func_L01_003C88E0 */

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
