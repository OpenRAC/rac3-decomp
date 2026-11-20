#include "common.h"

/* localdecomp:start func_L24_0034F040 */
#include "vu0.h"
typedef struct {
    u8 p0[0x80];
    vu0_q x80;
    vu0_q x90;
    u8 pA0[0x30];
    vu0_q xD0;
    u8 pE0[0x108 - 0xE0];
    f32 x108;
    u8 p10C[0x19E0 - 0x10C];
    s32 x19E0;
    s16 x19E4;
    u8 p19E6[0x25C0 - 0x19E6];
    u8 *x25C0;
    u8 p25C4[0x25E5 - 0x25C4];
    u8 x25E5;
} S_34F040;
extern S_34F040 D_001A4BE0;

void func_L24_0034F040(u8 *obj) {
    S_34F040 *g = &D_001A4BE0;
    *(vu0_q *)(g->x25C0 + 0x10) = *(vu0_q *)(obj + 0x10);
    g->x80 = *(vu0_q *)(g->x25C0 + 0x10);
    *(vu0_q *)(g->x25C0 + 0xF0) = *(vu0_q *)(obj + 0xF0);
    g->x90 = *(vu0_q *)(g->x25C0 + 0xF0);
    g->xD0 = *(vu0_q *)(obj + 0x10);
}
/* localdecomp:end func_L24_0034F040 */

/* localdecomp:start func_L24_0034F080 */
#include "vu0.h"
typedef struct {
    vu0_q x0;
    u8 p10[0x2540 - 0x10];
    u8 *x2540;
} S_34F080;
extern S_34F080 D_001A4C60;
extern vu0_q D_L24_001E21A0;
extern vu0_q D_L24_001E8F60;
extern s32 func_L24_0041CE48(s32, s32, s32);
extern s32 func_L01_005003D0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

void func_L24_0034F080(u8 *obj) {
    S_34F040 *g;
    f32 v[4];
    vu0_q a, c, r;

    func_L24_0041CE48(0, 0, 1);
    g = &D_001A4BE0;
    g->x25E5 = 0;
    func_L01_005003D0(0, 1);
    *(vu0_q *)v = D_L24_001E21A0;
    g->x19E4 = -1;
    g->x108 = 0.20000002f;
    g->x19E0 = 0;
    v[2] = 0.0f;
    func_0038CF68(v, v, 2.5f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(obj + 0x10)));
    *(s32 *)(obj + 0x98) = 0;
    v[2] = 0.7f;
    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_v4 *)v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(c));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v) : "j"(r));
    if (func_003D3CB0(&g->x80, v, 2, g->x25C0, 0) != 0) {
        *(vu0_q *)v = D_L24_001E8F60;
        if (func_L01_003FB640(v, 2, g->x25C0, 0.4f) != 0) {
            *(vu0_q *)v = D_L24_001E8F60;
        }
    }
    D_001A4C60.x0 = *(vu0_q *)v;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    *(s32 *)(D_001A4C60.x2540 + 0x9C) = 0;
}
/* localdecomp:end func_L24_0034F080 */

/* localdecomp:start func_L24_0034F1B8 */
#include "vu0.h"
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_004455E8(void *, void *, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0040E728(void *, void *, f32);
extern s32 func_L24_0034ED28(u8 *);
extern void func_L24_0034E6F8(void *, s32);
extern u8 *D_001D52FC;
extern vu0_q D_L24_001E21A0;
__asm__(".extern D_L24_001DD3F0, 4");
__asm__(".extern D_L24_001DD3F4, 4");
__asm__(".extern D_L24_001DD3F8, 4");
__asm__(".extern D_L24_001DD3FC, 4");
__asm__(".extern D_L24_001DD400, 4");
__asm__(".extern D_L24_001DD404, 4");
__asm__(".extern D_L24_001DD408, 4");
__asm__(".extern D_L24_001DD40C, 4");
__asm__(".extern D_L24_001DD410, 4");
__asm__(".extern D_L24_001DD414, 4");
__asm__(".extern D_L24_001DD418, 4");
__asm__(".extern D_L24_001DD41C, 4");
__asm__(".extern D_L24_001DD4BC, 4");
__asm__(".extern D_L24_001DD4C0, 4");
extern f32 D_L24_001DD3F0;
extern f32 D_L24_001DD3F4;
extern f32 D_L24_001DD3F8;
extern f32 D_L24_001DD3FC;
extern f32 D_L24_001DD400;
extern f32 D_L24_001DD404;
extern f32 D_L24_001DD408;
extern f32 D_L24_001DD40C;
extern f32 D_L24_001DD410;
extern f32 D_L24_001DD414;
extern f32 D_L24_001DD418;
extern f32 D_L24_001DD41C;
extern f32 D_L24_001DD4BC;
extern f32 D_L24_001DD4C0;

typedef struct {
    u8 p0[0x100];
    f32 x100;
    f32 x104;
    f32 x108;
    f32 x10C;
    u8 p110[0x118 - 0x110];
    f32 x118;
    u8 p11C[0x140 - 0x11C];
    f32 x140;
    f32 x144;
    f32 x148;
    f32 x14C;
    u8 p150[0x1A0 - 0x150];
    u8 *x1A0;
} S_0034F1B8;

typedef struct {
    u8 p0[0x100];
    f32 x100;
    f32 x104;
    f32 x108;
    f32 x10C;
} H_0034F1B8;

static __inline__ void vadd2_34F1B8(void *d1, void *d2, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d1) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d2) : "j"(qr));
}

s32 func_L24_0034F1B8(void *o) {
    u8 *obj = (u8 *)o;
    S_0034F1B8 *s = *(S_0034F1B8 **)(obj + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 z;
    f32 yaw;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 turn;
    u8 *m;
    H_0034F1B8 *h;
    s32 r;

    s->x118 = s->x118 * D_L24_001DD410;
    s->x144 = s->x144 * D_L24_001DD414;
    z = s->x108 * D_L24_001DD41C;
    c = 0.0f;
    func_0038CE20(&s->x100, &s->x100, D_L24_001DD418);
    s->x108 = z;
    a = 0.0f;
    b = 0.0f;
    d = 0.0f;
    m = s->x1A0;
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
        s->x1A0 = 0;
        h = (H_0034F1B8 *)D_001D52FC;
        d = -h->x10C;
        c = -h->x108;
        b = -(h->x104 - 0.25f);
        a = h->x100;
        c *= D_L24_001DD3F4 * 0.00040000002f;
        d *= D_L24_001DD3F8 * 0.00040000002f;
        a *= D_L24_001DD408 * 0.017453292f * 0.00040000002f;
    }
    yaw = func_0038D160(s->x100, s->x104);
    s->x144 = func_0038DAB8(s->x144, a);
    turn = 0.0f;
    if (b < 0.0f) {
        turn = D_L24_001DD4BC * 0.017453292f * b;
    } else if (0.0f < b) {
        turn = D_L24_001DD4C0 * 0.017453292f * b;
    }
    func_L01_00448890(&s->x148, &s->x14C, 0, turn, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD404 * 0.017453292f * 0.020000001f);
    {
        f32 lim = D_L24_001DD40C * 0.017453292f * 0.020000001f;
        if (lim < s->x144) {
            s->x144 = lim;
        } else if (s->x144 < -lim) {
            s->x144 = -lim;
        }
    }
    func_L01_004455E8(obj, &s->x118, yaw, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD400 * 1.44f, D_L24_001DD404 * 0.017453292f * 0.020000001f);
    s->x140 = func_0038DAB8(s->x140, s->x144);
    s->x140 = func_0038DB00(s->x140, s->x118);
    v[0] = d;
    v[1] = c;
    v[2] = 0.0f;
    func_0038D000(v, v, &D_L24_001E21A0);
    v[2] = 0.0f;
    vadd2_34F1B8(&s->x100, t, &s->x100, v);
    func_L01_0040E728(&s->x100, &s->x100, D_L24_001DD3F0 * 0.020000001f);
    vadd2_34F1B8(obj + 0x10, t, obj + 0x10, &s->x100);
    r = func_L24_0034ED28(obj);
    func_L24_0034E6F8(obj, 0);
    return r;
}
/* localdecomp:end func_L24_0034F1B8 */

LINKER_REMNANT("asm/levels", func_L24_0034F4D8);

/* localdecomp:start func_L24_0034F4E0 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
__asm__(".extern D_L24_001DD474, 4");
__asm__(".extern D_L24_001DD478, 4");
__asm__(".extern D_L24_001DD47C, 4");
__asm__(".extern D_L24_001DD480, 4");
__asm__(".extern D_L24_001DD484, 4");
extern f32 D_L24_001DD474;
extern f32 D_L24_001DD478;
extern f32 D_L24_001DD47C;
extern f32 D_L24_001DD480;
extern f32 D_L24_001DD484;

void func_L24_0034F4E0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v;
    f32 y;
    f32 w;
    f32 u;
    f32 a;
    f32 b;
    f32 c;

    w = D_L24_001DD478 * 0.017453292f * 0.020000001f;
    y = *(f32 *)(obj + 0x18);
    w = w * *(f32 *)(s + 0x154);
    u = *(f32 *)(s + 0x130);
    *(f32 *)(s + 0x150) = y;
    v = func_0038DAB8(u, w);
    *(f32 *)(s + 0x130) = v;
    v = func_0038D0B0(v);
    b = D_L24_001DD480 * 0.017453292f * 0.020000001f;
    c = D_L24_001DD484 * 0.017453292f * 0.020000001f;
    a = D_L24_001DD47C * 0.017453292f;
    *(f32 *)(s + 0x134) = v * D_L24_001DD474 * *(f32 *)(s + 0x154);
    *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + *(f32 *)(s + 0x134) * *(f32 *)(s + 0x154);
    func_L01_0044EBA0(obj, s + 0x138, s + 0x13C, a, b * *(f32 *)(s + 0x154), c * *(f32 *)(s + 0x154));
    vec_add_ab(obj + 0xF0, obj + 0xF0, s + 0x120);
}
/* localdecomp:end func_L24_0034F4E0 */

/* localdecomp:start func_L24_0034F5D8 */
#include "vu0.h"
extern u8 *D_0021C7A0[];
extern u8 *func_00382348(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

u8 *func_L24_0034F5D8(f32 *pos, f32 *rot, f32 yawMax, f32 pitchMax, f32 range) {
    s32 i;
    u8 *m;
    u8 *t;
    u8 *best;
    f32 bestScore;
    f32 d;
    f32 e;
    f32 score;
    f32 v[4];

    best = 0;
    bestScore = 1e9f;
    for (i = 0; (m = D_0021C7A0[i]) != 0; i++) {
        if (*(s16 *)(m + 0x32) == 0) continue;
        if (*(u8 *)(m + 0x31) == 0) continue;
        t = func_00382348(m);
        if (t == 0) continue;
        if (*(f32 *)t < 0.0f) continue;
        if (m == 0) continue;
        if (*(u8 **)(m + 0x24) == 0) continue;
        if (*(u8 *)(*(u8 **)(m + 0x24) + 0x46) != 5) continue;
        d = func_0038CF38(pos, m + 0x10);
        if (!(d < range)) continue;
        *(vu0_q *)v = *(vu0_q *)(m + 0x10);
        v[2] = v[2] + (*(f32 *)(t + 0x10) + 0.1f);
        e = func_0038DBA0(rot[2], func_0038D160(v[0] - pos[0], v[1] - pos[1]));
        score = e * e;
        if (score < yawMax * yawMax) {
            e = func_0038DBA0(rot[1], func_0038D160(d, v[2] - pos[2]));
            e = e * e;
            if (e < pitchMax * pitchMax) {
                if (5.0f < d) {
                    score = score * e * d;
                    score = score + d;
                } else {
                    score = d / 5.0f;
                }
                if (score < bestScore && func_003D3CB0(pos, v, 2, m, 0) == 0) {
                    bestScore = score;
                    best = m;
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L24_0034F5D8 */

/* localdecomp:start func_L24_0034F828 */
#include "vu0.h"
extern void func_0038D590(void *, void *);
extern void func_0038D5B0(void *, void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(void *);
extern u8 *func_L24_0034F5D8(f32 *, f32 *, f32, f32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *D_001D52FC;
extern u8 D_L24_001E2040[];
extern f32 D_L24_001E2180[];
extern vu0_q D_L24_001E2190;
__asm__(".extern D_L24_001DD49C, 4");
__asm__(".extern D_L24_001DD4A0, 4");
__asm__(".extern D_L24_001DD4A4, 4");
extern f32 D_L24_001DD49C;
extern f32 D_L24_001DD4A0;
extern f32 D_L24_001DD4A4;

void func_L24_0034F828(u8 *obj) {
    u8 *s;
    u8 *t;
    u8 *m;
    u8 *r;
    u8 m1[0x30];
    u8 m2[0x40];
    f32 v[4];
    f32 p[4];
    f32 f;

    *(s32 *)(obj + 0x98) = 0;
    s = *(u8 **)(obj + 0x68);
    func_0038D590(m1, D_L24_001E2040);
    func_0038D5B0(m2, m1);
    if ((*(s32 *)(D_001D52FC + 0x1A0) & 0xC3) == 0) {
        if (func_0038CB00(s + 0x164) != 0 || *(u8 **)(s + 0x15C) == 0 || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFE
            || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFD || *(u8 *)(*(u8 **)(s + 0x15C) + 0x31) == 0) {
            *(u8 **)(s + 0x15C) = 0;
            *(f32 *)(s + 0x160) = 0.0f;
        }
        *(vu0_q *)v = D_L24_001E2190;
        v[1] = 0.0f;
        func_003C2F58(obj, 2, p);
        m = func_L24_0034F5D8(p, v, D_L24_001DD49C, D_L24_001DD4A0, D_L24_001DD4A4);
        if ((m != 0 && *(u8 **)(s + 0x15C) == 0) || *(u8 **)(s + 0x15C) == 0 || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFE
            || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFD || *(u8 *)(*(u8 **)(s + 0x15C) + 0x31) == 0) {
            *(f32 *)(s + 0x160) = 0.0f;
            *(s16 *)(s + 0x164) = 0x11;
            *(u8 **)(s + 0x15C) = m;
            r = func_00382348(m);
            if (r != 0) {
                *(f32 *)(s + 0x160) = *(f32 *)(r + 0x10);
            }
        }
        if (*(u8 **)(s + 0x15C) != 0 && func_0038CB00(s + 0x168) != 0) {
            t = *(u8 **)(s + 0x15C);
            if (t == 0 || *(u8 *)(t + 0x20) == 0xFE || *(u8 *)(t + 0x20) == 0xFD) {
                *(u8 **)(s + 0x15C) = 0;
                *(f32 *)(s + 0x160) = 0.0f;
            } else {
                f = func_0038CF00(D_L24_001E2180, t + 0x10) / 150.0f;
                *(vu0_q *)v = *(vu0_q *)(*(u8 **)(s + 0x15C) + 0x10);
                v[2] = v[2] + *(f32 *)(s + 0x160);
                *(vu0_q *)(s + 0x170) = *(vu0_q *)v;
                func_L01_003F6F20(0, obj, 0xFF0FFF0F, v, 0x23, -1, 4, fabs_asm(0.9f - f * 0.65f), 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        }
    }
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
}
/* localdecomp:end func_L24_0034F828 */

/* localdecomp:start func_L24_0034FA98 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L24_00350980(u8 *, void *, s32, f32, f32, f32, f32, f32, f32, f32);
__asm__(".extern D_L24_001DD4B0, 4");
__asm__(".extern D_L24_001DD498, 2");
extern f32 D_L24_001DD4B0;
extern s16 D_L24_001DD498;

void func_L24_0034FA98(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 c[4];
    f32 b[4];
    u8 m1[0x30];
    u8 m2[0x40];
    f32 w[4];

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    func_00382760(a, 1.0f, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    func_0038CE20(c, s + 0x100, 3.0f);
    vec_add_ab(a, a, c);
    func_003C2F58(obj, 2, out);
    func_0038D308(m1, b);
    func_0038D5B0(m2, m1);
    func_0038D028(w, s + 0x100, m2);
    if (func_L24_00350980(obj, out, *(s32 *)(s + 0x15C), b[2], b[1], *(f32 *)(s + 0x160), b[2], b[1], w[0], D_L24_001DD4B0) != 0) {
        *(s16 *)(s + 0x168) = (D_L24_001DD498 * 5 + 2) / 6;
    }
}
/* localdecomp:end func_L24_0034FA98 */

/* localdecomp:start func_L24_0034FBE8 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L24_00351448(void *, void *, void *, f32, f32, f32, s32, s32, f32);
__asm__(".extern D_L24_001DD4D8, 4");
__asm__(".extern D_L24_001DD4DC, 4");
__asm__(".extern D_L24_001DD4E0, 4");
__asm__(".extern D_L24_001DD4E4, 2");
extern f32 D_L24_001DD4D8;
extern f32 D_L24_001DD4DC;
extern f32 D_L24_001DD4E0;
extern s16 D_L24_001DD4E4;

void func_L24_0034FBE8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD4D8 * 0.020000001f;
    func_00382760(a, k, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ab(a, a, s + 0x100);
    func_003C2F58(obj, 2, out);
    if (func_L24_00351448(out, obj, a, D_L24_001DD4DC, D_L24_001DD4E0, 2.0f, 2, 3, 2.0f) != 0) {
        *(s16 *)(s + 0x168) = (D_L24_001DD4E4 * 5 + 2) / 6;
    }
}
/* localdecomp:end func_L24_0034FBE8 */

/* localdecomp:start func_L24_0034FCF8 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

s32 func_L24_0034FCF8(u8 *obj, void *a1, void *a2, void *a3, s32 b0, s32 b1, s32 n, f32 scale, f32 d) {
    f32 v[4];
    u8 q[0x30];

    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(u128_t *)v = *(u128_t *)(obj + 0xC0);
    } else {
        v[0] = func_0038D098(*(f32 *)(obj + 0xF8));
        v[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
        v[2] = 0.0f;
    }
    func_0038CE20(v, v, d);
    v[2] = 1.0f;
    v[3] = 5627.925f;
    func_L01_00446760(q, obj, (s32)a3, v, scale);
    q[0x18] = b0;
    q[0x19] = b1;
    *(u16 *)(q + 0x1A) = *(u16 *)(obj + 0xAA);
    return func_003D3CB0(a1, a2, n, obj, q);
}
/* localdecomp:end func_L24_0034FCF8 */

/* localdecomp:start func_L24_0034FE28 */
#include "vu0.h"
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_00446780(void *, void *, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L24_0034FCF8(u8 *, void *, void *, void *, s32, s32, s32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 *func_L01_00464EC8(void *, void *, f32, u8);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern vu0_q D_L24_001E8F60;
extern u8 D_001D66B0;
__asm__(".extern D_001D66B0, 16");
__asm__(".extern D_L24_001DD4B4, 4");
__asm__(".extern D_L24_001DD4C4, 4");
__asm__(".extern D_L24_001DD4C8, 4");
__asm__(".extern D_L24_001DD4CC, 4");
extern f32 D_L24_001DD4B4;
extern f32 D_L24_001DD4C4;
extern s32 D_L24_001DD4C8;
extern f32 D_L24_001DD4CC;


void func_L24_0034FE28(void *o) {
    u8 *obj = (u8 *)o;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 m[16];
    f32 d[4];
    f32 p[4];
    f32 a[4];
    f32 b[4];
    f32 e[4];
    f32 c[4];
    f32 t[4];
    f32 len;
    f32 k;
    u8 *q;
    u8 *fx;
    s32 i;
    vu0_q acc;

    func_003C2EC0(obj, 2, m);
    *(vu0_q *)d = *(vu0_q *)m;
    func_003C2F58(obj, 2, p);
    func_0038CF68(a, d, D_L24_001DD4CC);
    len = D_L24_001DD4CC;
    func_0038CF68(b, d, D_L24_001DD4C4 * 0.020000001f);
    vec_add_ba(b, b, s + 0x100);
    func_L01_00446780(obj, p, 0.3f, 0x8110000, D_L24_001DD4B4, 1.0f, 9, 1, 0);
    vec_add_ab(e, a, p);
    func_L01_00446780(obj, e, 0.6f, 0x8110000, D_L24_001DD4B4, 1.0f, 9, 1, 0);
    if (((s32 (*)(u8 *, void *, void *, s32, s32, s32, s32, f32, f32))func_L24_0034FCF8)(obj, p, e, 0x8110000, 9, 1, 0, D_L24_001DD4B4, 1.0f) != 0) {
        *(vu0_q *)a = D_L24_001E8F60;
        len = func_0038CF38(p, a);
        fx = func_L01_00464EC8(a, &D_001D66B0, 0.2f, 0);
        if (fx != 0) {
            *(f32 *)(fx + 0xC) *= 4.0f;
        }
    }
    func_0038CE20(c, b, 1.0f / (f32)D_L24_001DD4C8);
    for (i = 0; i < D_L24_001DD4C8; i++) {
        func_003C4C18(p, (f32)i * 0.02f);
        q = func_L01_00464EC8(p, b, len, i);
        if (q != 0) {
            *(s16 *)(q + 0xA) = (s32)(len / (D_L24_001DD4C4 * 0.020000001f)) + 6;
            q[0x3D] = q[0xA];
        }
        {
            vu0_q tmp;
            __asm__("lqc2 %0, %1" : "=j"(tmp) : "m"(*(vu0_v4 *)c));
            __asm__("lqc2 %0, %1" : "=j"(acc) : "m"(*(vu0_v4 *)p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(acc) : "j"(acc), "j"(tmp));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)p) : "j"(acc));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)t) : "j"(acc));
        }
        k = func_003824E0(0.1f, 0.9f);
        func_0038CE20(e, a, k);
        {
            vu0_q tmp;
            __asm__("lqc2 %0, %1" : "=j"(acc) : "m"(*(vu0_v4 *)e));
            __asm__("lqc2 %0, %1" : "=j"(tmp) : "m"(*(vu0_v4 *)p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(acc) : "j"(acc), "j"(tmp));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)e) : "j"(acc));
        }
        {
            f32 size = 0.3f;
            size *= k + 1.0f;
            func_L01_00446780(obj, e, size, 0x8110000, D_L24_001DD4B4, 1.0f, 9, 1, 0);
        }
    }
}
/* localdecomp:end func_L24_0034FE28 */

/* localdecomp:start func_L24_00350190 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
__asm__(".extern D_L24_001DD4D8, 4");
__asm__(".extern D_L24_001DD4DC, 4");
extern f32 D_L24_001DD4D8;
extern f32 D_L24_001DD4DC;

void func_L24_00350190(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(u128_t *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD4D8 * 0.020000001f;
    func_00382760(a, k, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ba(a, a, s + 0x100);
    func_003C2F58(obj, 2, out);
    s[0x1A4] = func_L01_004C7A18(D_L24_001DD4DC * 0.00040000002f, out, a, s + 0x170, s + 0x180, obj, 0, 0);
}
/* localdecomp:end func_L24_00350190 */

/* localdecomp:start func_L24_00350288 */
extern void func_L24_0034F828(u8 *);
extern void func_L24_0034FA98(u8 *);
extern void func_L24_0034FE28(void *);
extern void func_L24_0034FBE8(u8 *);
extern void func_L24_00350190(u8 *);
extern void func_L24_0034E6B0(void *);
extern void func_L01_00404A10(void *, void *);
extern u8 *D_001D52FC;

void func_L24_00350288(u8 *obj) {
    u8 *s;

    *(s32 *)(obj + 0x98) = 0;
    s = *(u8 **)(obj + 0x68);
    func_L24_0034F828(obj);
    if ((*(s32 *)(D_001D52FC + 0x1A0) & 0x28) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FA98(obj);
    } else if ((*(s32 *)(D_001D52FC + 0x1A0) & 0x42) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FE28(obj);
    } else if ((*(s32 *)(D_001D52FC + 0x1A8) & 0x81) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FBE8(obj);
    } else if ((*(s32 *)(D_001D52FC + 0x1A0) & 0x81) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_00350190(obj);
        func_L01_00404A10(func_L24_0034E6B0, obj);
    } else if ((*(s32 *)(D_001D52FC + 0x1A4) & 4) == 0 || *(s16 *)(s + 0x168) != 0 || !(*(f32 *)(s + 0x148) < -0.6981317f)) {
        s[0x1A4] = 0;
    } else if (*(u8 **)(s + 0x1A0) != 0 && (*(u8 **)(s + 0x1A0))[0x20] != 0xFE && (*(u8 **)(s + 0x1A0))[0x20] != 0xFD) {
        s[0x1A4] = 0;
    }
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
}
/* localdecomp:end func_L24_00350288 */

/* localdecomp:start func_L24_003503F0 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern u8 D_L24_001E2200[];
extern f32 D_001A65CC[];

void func_L24_003503F0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *r;
    u8 *t;
    s32 h;

    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L24_001E2200, obj + 0x10) < 1024.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x1E;
        }
    }
    if (obj[0x95] != 0) {
        *(f32 *)(obj + 0x18) = *(f32 *)(s + 0x150);
        r = (u8 *)func_L01_00447490(obj, 1, 0);
        if (r != 0 && *(u8 **)(r + 0x20) != 0) {
            t = *(u8 **)(r + 0x20);
            h = *(s16 *)(t + 0xAA);
            if (h != 0x15D4 && h != 0) {
                if (t != *(u8 **)(s + 0x48) || *(s16 *)(s + 0x36) == 0) {
                    s[0x77] = 0xD2;
                    s[0x78] = 0xD2;
                    s[0x79] = 0xD2;
                    func_003C4A40(obj, s + 0x70);
                    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - *(f32 *)(r + 0x2C);
                    D_001A65CC[0] = *(f32 *)(s + 0x30);
                    if (*(f32 *)(s + 0x30) <= 0.0f) {
                        obj[0x95] = 6;
                    }
                    *(u8 **)(s + 0x48) = *(u8 **)(r + 0x20);
                    *(s16 *)(s + 0x36) = 8;
                }
            }
        }
        obj[0xA8] = 0xFF;
    } else {
        *(f32 *)(s + 0x150) = *(f32 *)(obj + 0x18);
    }
    func_L01_0044ABD0(obj, s + 0x70);
}
/* localdecomp:end func_L24_003503F0 */

/* localdecomp:start func_L24_00350560 */
__asm__(".extern D_L24_001DD3D0, 4");
__asm__(".extern D_L24_001DD488, 4");
__asm__(".extern D_L24_001DD3E8, 4");
__asm__(".extern D_L24_001DD3EC, 4");
extern f32 D_L24_001DD3D0;
extern f32 D_L24_001DD488;
extern f32 D_L24_001DD3E8;
extern s32 D_L24_001DD3EC;
extern void func_L24_003503F0(u8 *);
extern void func_L24_0034EC40(void *);
extern s32 func_L01_0038B988(void *);
extern f32 func_L18_0044E098(void *, void *);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L24_0034F040(u8 *);
extern s32 func_L24_0034E370(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L24_0034E6F8(void *, s32);
extern s32 func_L24_0034F1B8(void *);
extern void func_L24_00350288(u8 *);
extern void func_L24_0034EBF8(void *);
extern void func_L24_0034F080(u8 *);
extern void func_L24_0034F4E0(u8 *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L24_00350560(u8 *obj) {
    u8 *s;
    u8 *b;
    u8 *t;
    s32 r;
    s32 ok;
    f32 k;

    s = *(u8 **)(obj + 0x68);
    func_L24_003503F0(obj);
    switch (obj[0x95]) {
    case 0:
        func_L24_0034EC40(obj);
        break;
    case 1:
        r = func_L01_0038B988(obj);
        k = D_L24_001DD3D0;
        *(f32 *)(obj + 0x2C) += (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k - *(f32 *)(obj + 0x2C)) * 0.060000002f;
        if (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k * 0.98f < *(f32 *)(obj + 0x2C) && r != 0) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k;
            func_L01_004450F0(obj, 0, 2);
        }
        break;
    case 2:
        *(f32 *)(s + 0x154) -= D_L24_001DD488 * 1.2f;
        if (*(f32 *)(s + 0x154) < 0.0f) {
            *(f32 *)(s + 0x154) = 0.0f;
        }
        func_L01_0038B988(obj);
        b = (u8 *)&D_001A4BE0;
        t = *(u8 **)(b + 0x35C);
        if (t != 0 && *(s16 *)(t + 0xAA) == 0xF51) {
            break;
        }
        if (func_L18_0044E098(obj, *(u8 **)(b + 0x25C0)) < D_L24_001DD3E8 && *(s32 *)(b + 0x25C4) != 0x31) {
            ok = func_L01_00452560(0, 8, 0x855, 1, 0, 0, 0) != 0;
            if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) && ok) {
                func_L01_005003D0(0x31, 0);
                func_L01_0050FB40(D_L24_001DD3EC, 0, 15.0f);
                func_L24_0034F040(obj);
                *(u8 **)(b + 0x19E0) = obj;
                *(f32 *)(b + 0x19EC) = *(f32 *)(s + 0x30);
                *(f32 *)(b + 0x19F0) = *(s16 *)(s + 0x34);
                func_L24_0041CE48(0, (s32)func_L24_0034E370, 1);
                *(s32 *)(*(u8 **)(b + 0x25C0) + 0x9C) = -1;
                func_L01_004450F0(obj, 0, 3);
            }
        }
        break;
    case 3:
        *(f32 *)(s + 0x154) = D_L24_001DD488 * 1.2f;
        func_L01_0038B988(obj);
        func_L24_0034F040(obj);
        func_L24_0034E6F8(obj, 1);
        func_L01_004450F0(obj, 0, 4);
        break;
    case 4:
        *(f32 *)(s + 0x154) += D_L24_001DD488 * 1.2f;
        if (1.0f < *(f32 *)(s + 0x154)) {
            *(f32 *)(s + 0x154) = 1.0f;
        }
        func_L24_0034F1B8(obj);
        func_L24_0034F040(obj);
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
            func_L01_004450F0(obj, 0, 5);
        } else {
            func_L24_00350288(obj);
        }
        break;
    case 5:
        *(f32 *)(s + 0x154) -= D_L24_001DD488 * 1.2f;
        if (*(f32 *)(s + 0x154) < 0.0f) {
            *(f32 *)(s + 0x154) = 0.0f;
        }
        func_L24_0034EBF8(obj);
        func_L24_0034F080(obj);
        func_L01_0038B988(obj);
        func_L01_004450F0(obj, 0, 2);
        break;
    case 6:
        func_L24_0034EBF8(obj);
        func_L01_0044AF78(obj, s + 0x100, 0, 2.0f, 4.0f, 10, 3, 16, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, -1, 1, 1, -1, 0, 0x1010001);
        func_L24_0034F080(obj);
        func_L01_0038B988(obj);
        func_003C2880(obj);
        return;
    }
    func_0038CB00(s + 0x166);
    func_0038CB00(s + 0x168);
    func_0038CB00(s + 0x16A);
    func_L24_0034F4E0(obj);
}
/* localdecomp:end func_L24_00350560 */

/* localdecomp:start func_L24_00350980 */
#include "vu0.h"
extern u8 *func_003C24B0(s32, s32);
extern u8 *func_00382348(void *);
extern void func_003C7C38(void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern vu0_q D_L24_001E8F60;

s32 func_L24_00350980(u8 *owner, void *pos, s32 tgt, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    u8 *m;
    u8 *s;
    u8 *r;
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];

    m = func_003C24B0(0x15DB, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        *(u8 *)(m + 0x30) = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        *(u8 *)(m + 0x31) = 1;
        *(f32 *)(m + 0xF8) = d;
        *(f32 *)(m + 0xF4) = e;
        *(u8 *)(m + 0x20) = 0;
        *(u8 **)(s + 0x10) = owner;
        *(vu0_q *)(m + 0x10) = *(vu0_q *)pos;
        *(f32 *)(s + 0x20) = f;
        *(f32 *)(s + 0x38) = g;
        *(s32 *)(s + 0x24) = 0;
        *(s32 *)(s + 0x28) = 0;
        *(s32 *)(s + 0x18) = tgt;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.25f;
        if (tgt != 0) {
            *(s32 *)(s + 0x34) = *(s16 *)((u8 *)tgt + 0xAA);
            r = func_00382348((void *)tgt);
            if (r != 0) {
                *(u16 *)(r + 0x1E) |= 0x80;
            }
            *(vu0_q *)s = *(vu0_q *)((u8 *)tgt + 0x10);
            *(f32 *)(s + 0x1C) = c;
            *(f32 *)(s + 8) = *(f32 *)(s + 8) + c;
        }
        *(f32 *)(s + 0x2C) = a;
        *(f32 *)(s + 0x30) = b;
        *(s32 *)(s + 0x14) = 0xD0;
        func_003C7C38(m);
        func_003A52A0(1, 0, m);
        *(vu0_q *)v40 = 0;
        v40[2] = 0.16000001f;
        *(vu0_q *)v30 = *(vu0_q *)(D_001A4BE0.x25C0 + 0x10);
        v30[2] = ((f32 *)pos)[2];
        if (func_003D3CB0(v30, pos, 0, *(void **)(s + 0x10), 0) != 0) {
            *(u8 *)(m + 0xBC) = 2;
            *(vu0_q *)(m + 0x10) = D_L24_001E8F60;
            func_00382760(v20, *(f32 *)(s + 0x20), *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            func_L01_0040E790(v40, v20, (f32 *)((u8 *)&D_L24_001E8F60 + 0x20));
            func_0038CF68(v40, v40, 0.040000003f);
            func_L01_0044AF78(m, v40, 0, 0.0f, 0.0f, 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 0, 1, 1, -1, 0, 0x1010001);

            func_003C2880(m);
            return 0;
        }
    }
    return (s32)m;
}
/* localdecomp:end func_L24_00350980 */

/* localdecomp:start func_L24_00350C30 */
#include "vu0.h"
extern u8 *func_00382348(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L18_00457C10(f32, f32, f32 *, f32, f32, f32);
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern s32 func_0038CAD0(void *);
extern u8 D_L24_001E8F40[];

typedef struct {
    f32 dir[4];
    void *obj;
    s32 x14;
    u8 x18;
    u8 x19;
    u16 x1A;
    f32 x1C;
    s32 x20;
    u8 p24[0x30 - 0x24];
} S_350C30;

void func_L24_00350C30(u8 *obj) {
    u8 *s;
    u8 *t;
    u8 *r;
    u8 *g;
    u8 *h;
    f32 *from;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 r1;
    f32 r2;
    f32 k;
    s32 n;
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];
    f32 v50[4];

    if (obj == 0) return;
    s = *(u8 **)(obj + 0x68);
    if (s == 0) return;
    *(vu0_q *)v30 = 0;
    v30[2] = 0.16000001f;
    *(f32 *)(obj + 0x2C) += (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) - *(f32 *)(obj + 0x2C)) * 0.060000002f;
    *(f32 *)(s + 0x20) += (1.2f - *(f32 *)(s + 0x20)) * 0.120000005f * 1.44f;
    if (*(u8 **)(s + 0x18) != 0) {
        r = func_00382348(*(u8 **)(s + 0x18));
        if (r != 0) {
            if (*(f32 *)r <= 0.0f) {
                *(u8 **)(s + 0x18) = 0;
            }
        } else if (4.0f < func_0038CF38(*(u8 **)(s + 0x18) + 0x10, s)) {
            *(u8 **)(s + 0x18) = 0;
        }
    }
    if (*(s32 *)(s + 0x14) < 0xCC) {
        t = *(u8 **)(s + 0x18);
        if (t == 0 || *(s16 *)(t + 0xAA) != *(s32 *)(s + 0x34) || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            *(u8 **)(s + 0x18) = 0;
            *(f32 *)(obj + 0xF8) = func_L18_00457C10(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x2C), (f32 *)(s + 0x24), 0.037699115f, 0.0f, 0.0f);
            *(f32 *)(obj + 0xF4) = func_L18_00457C10(*(f32 *)(obj + 0xF4), *(f32 *)(s + 0x30), (f32 *)(s + 0x28), 0.037699115f, 0.0f, 0.0f);
        } else {
            f32 v60[4];
            f32 v70[4];
            f32 v80[4];
            f32 v90[4];
            vu0_q p;
            vu0_q a2;

            __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(vu0_v4 *)(obj + 0x10)));
            *(vu0_q *)v80 = *(vu0_q *)(t + 0x10);
            v80[2] += *(f32 *)(s + 0x1C);
            vec_sub_ab(v70, v80, s);
            __asm__("lqc2 %0, %1" : "=j"(a2) : "m"(*(vu0_v4 *)v80));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(a2) : "j"(a2), "j"(p));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v60) : "j"(a2));
            *(vu0_q *)s = *(vu0_q *)v80;
            c = func_L01_0040E4C0(v70);
            b = (v70[0] * v60[0] + v70[1] * v60[1] + v70[2] * v60[2]) * -2.0f;
            a = *(f32 *)(s + 0x20) * *(f32 *)(s + 0x20) - c;
            c = func_L01_0040E4C0(v60);
            d = sqrt_asm(b * b - a * 4.0f * -c);
            r1 = (-b + d) / (a + a);
            r2 = (-b - d) / (a + a);
            if (0.0f < r1 && 0.0f < r2) {
                k = (r2 < r1) ? r1 : r2;
            } else if (0.0f < r1) {
                k = r1;
            } else if (0.0f < r2) {
                k = r2;
            } else {
                k = -1.0f;
            }
            if (0.0f < k) {
                func_0038CE20(v90, v70, k);
                vec_add_ab(v90, v90, v60);
                *(f32 *)(obj + 0xF8) = func_L18_00457C10(*(f32 *)(obj + 0xF8), func_0038D160(v90[0], v90[1]), (f32 *)(s + 0x24), 0.037699115f, 0.0f, 0.0f);
                *(f32 *)(obj + 0xF4) = func_L18_00457C10(*(f32 *)(obj + 0xF4), -func_0038D160(func_0038CED8(v90), v90[2]), (f32 *)(s + 0x28), 0.037699115f, 0.0f, 0.0f);
            }
        }
    } else {
        if (*(u8 **)(s + 0x18) != 0) {
            *(vu0_q *)s = *(vu0_q *)(*(u8 **)(s + 0x18) + 0x10);
        }
    }
    func_00382760(v50, *(f32 *)(s + 0x20), *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    {
    {
        f32 v60[4];
        f32 v70[4];

        *(vu0_q *)v70 = 0;
        v70[0] = func_003824E0(-1.0f, 1.0f);
        v70[1] = func_003824E0(-1.0f, 1.0f);
        v70[2] = func_003824E0(-1.0f, 1.0f);
        *(vu0_q *)v60 = *(vu0_q *)v70;
        func_0038CF68(v60, v60, func_003824E0(0.1f, 0.2f) * 0.020000001f);
        func_0038CF68(v40, v50, -func_003824E0(0.002f, 0.020000001f));
        vec_add_ba(v60, v60, v40);
        func_0038CF68(v40, v50, func_003824E0(0.0f, 1.0f) * *(f32 *)(s + 0x20));
        vec_add_ba(v40, v40, obj + 0x10);
        n = (func_00382498(0x1C, 0x28) * 5 + 2) / 6;
        func_L01_004637C8(v40, v60, 0x6F00AFFF, 0x100000FF, n, 0x28, func_00382498(0x28, 0x46), 1);
    }
    }
    from = v20;
    *(vu0_q *)from = *(vu0_q *)(obj + 0x10);
    vec_add_ab(obj + 0x10, obj + 0x10, v50);
    if (*(f32 *)(obj + 0x10) < 0.0f || *(f32 *)(obj + 0x14) < 0.0f || *(f32 *)(obj + 0x18) < 0.0f) {
        func_003C2880(obj);
        return;
    }
    {
        S_350C30 q;

        q.obj = obj;
        q.x14 = 0x01030000;
        q.x1C = *(f32 *)(s + 0x38);
        q.x20 = 1;
        *(vu0_q *)q.dir = *(vu0_q *)v50;
        func_0038CFB8(q.dir, q.dir, 1.0f);
        q.dir[2] = 1.0f;
        q.dir[3] = 5627.925f;
        q.x18 = 3;
        q.x19 = 3;
        q.x1A = *(u16 *)(obj + 0xAA);
        if (func_003D3CB0(from, obj + 0x10, 0, *(void **)(s + 0x10), &q) != 0) {
            g = D_L24_001E8F40;
            h = *(u8 **)(g + 0x18);
            if (h != 0) {
                if (h == D_001A4BE0.x25C0) return;
                if (h == *(u8 **)(s + 0x10)) return;
                if (*(s16 *)(h + 0xAA) == 0x15DB) return;
                if (*(s16 *)(h + 0xAA) == 0) return;
                obj[0xBC] = 2;
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)(g + 0x20);
                func_L01_0040E790(v30, v50, (f32 *)(g + 0x40));
                func_0038CF68(v30, v30, 0.040000003f);
                func_L01_0044AF78(obj, v30, 0, 0.0f, 0.0f, 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 0, 1, 1, -1, 0, 0x1010001);
                func_003C2880(obj);
            } else {
                if (*(s32 *)(g + 0x1C) <= 0) return;
                obj[0xBC] = 1;
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)(g + 0x20);
                func_L01_0040E790(v30, v50, (f32 *)(g + 0x40));
                func_0038CF68(v30, v30, 0.040000003f);
                func_L01_0044AF78(obj, v30, 0, 0.0f, *(f32 *)(s + 0x38), 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 0, 1, 1, -1, 0, 0x1010001);
                func_003C2880(obj);
            }
        } else if (func_0038CAD0(s + 0x14) != 0 || 300.0f < func_0038CF38(obj + 0x10, D_001A4BE0.x25C0 + 0x10)) {
            func_003C2880(obj);
        }
    }
}
/* localdecomp:end func_L24_00350C30 */

/* localdecomp:start func_L24_00351448 */
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_003A52A0(s32, s32, void *);

s32 func_L24_00351448(void *a0, void *a1, void *a2, f32 f12, f32 f13, f32 f14, s32 a3, s32 a4, f32 f15) {
    u8 *o = func_003C24B0(0x15E2, 0x80);
    u8 *s;
    f32 *v = (f32 *)a2;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(u128_t *)s = *(u128_t *)a2;
        *(u128_t *)(o + 0x10) = *(u128_t *)a0;
        *(f32 *)(o + 0xF8) = func_0038D160(v[0], v[1]);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(v), v[2]);
        *(s32 *)(o + 0xF0) = 0;
        *(void **)(s + 0x10) = a1;
        *(f32 *)(s + 0x20) = f13;
        *(s32 *)(s + 0x28) = a3;
        *(s32 *)(s + 0x2C) = a4;
        *(f32 *)(s + 0x24) = f14;
        *(f32 *)(s + 0x18) = f12 * 0.00040000002f;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * f15;
        *(f32 *)(s + 0x14) = f15;
        o[0x20] = 0;
        func_003A52A0(0, 0, o);
        func_003C7C38(o);
    }
    return (s32)o;
}
/* localdecomp:end func_L24_00351448 */

/* localdecomp:start func_L24_003515A8 */
#include "vu0.h"
typedef struct { vu0_v4 v; void *obj; s32 f14; u8 b18; u8 b19; u16 id; f32 f1C; s32 f20; } Q_3515A8;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_00451388(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_003C2880(void *);

void func_L24_003515A8(u8 *obj) {
    vu0_v4 p20;
    vu0_v4 p30;
    u8 *pos = obj + 0x10;
    u8 *s;
    f32 x;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 r60;

    p30 = p20 = *(vu0_v4 *)(obj + 0x10);
    s = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        {
            s32 n;

            *(vu0_q *)&r60 = 0;
            r60.x = func_003824E0(-1.0f, 1.0f);
            r60.y = func_003824E0(-1.0f, 1.0f);
            r60.z = func_003824E0(-1.0f, 1.0f);
            v50 = r60;
            func_0038CF68(&v50, &v50, func_003824E0(0.1f, 0.2f) * 0.020000001f);
            func_0038CF68(&v40, s, -func_003824E0(0.002f, 0.020000001f));
            vec_add_ba(&v50, &v50, &v40);
            func_0038CE20((f32 *)&v40, s, func_003824E0(0.0f, 1.0f));
            vec_add_ab(&v40, &v40, pos);
            n = (func_00382498(0x1C, 0x28) * 5 + 2) / 6;
            func_L01_004637C8(&v40, &v50, 0x6F00AFFF, 0x100000FF, n, 0x28, func_00382498(0x28, 0x46), 1);
        }
        vec_add_ba(pos, pos, s);
        *(f32 *)(obj + 0xF8) = func_0038D160(*(f32 *)(s + 0), *(f32 *)(s + 4));
        *(f32 *)(obj + 0xF4) = -func_0038D160(func_0038CED8(s), *(f32 *)(s + 8));
        func_L01_00451388(obj, s, s, *(f32 *)(s + 0x18));
        {
            ((Q_3515A8 *)&v40)->obj = obj;
            ((Q_3515A8 *)&v40)->f14 = 0x10001;
            ((Q_3515A8 *)&v40)->f1C = *(f32 *)(s + 0x20);
            ((Q_3515A8 *)&v40)->f20 = 1;
            ((Q_3515A8 *)&v40)->v = *(vu0_v4 *)s;
            func_0038CF68(&((Q_3515A8 *)&v40)->v, &((Q_3515A8 *)&v40)->v, *(f32 *)(s + 0x24));
            ((Q_3515A8 *)&v40)->v.w = 5627.925f;
            ((Q_3515A8 *)&v40)->b18 = s[0x28];
            ((Q_3515A8 *)&v40)->b19 = s[0x2C];
            ((Q_3515A8 *)&v40)->id = *(u16 *)(obj + 0xAA);
            if (func_003D3CB0(&p30, pos, 0, *(void **)(s + 0x10), (Q_3515A8 *)&v40) != 0
                || func_L01_003FB640(pos, 0, *(u8 **)(s + 0x10), 0.2f) != 0) {
                func_003A52A0(0, 0, obj);
                x = *(f32 *)(s + 0x14);
                func_L01_0044AF78(obj, s, 0, 0.0f, 0.0f, (s32)(x * 5.0f), (s32)(x * 4.0f), (s32)(x * 10.0f),
                                  x * 4.0f, x + x, 9.0f, *(f32 *)(s + 0x14), x * 15.0f, -1, 1, 1, -1, 0, 0x1010001);
                func_003D4D00(pos, 0x10, *(void **)(s + 0x10), (Q_3515A8 *)&v40, *(f32 *)(s + 0x14) * 4.0f);
                func_003C2880(obj);
                return;
            }
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10)
        || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14)
        || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L24_003515A8 */
