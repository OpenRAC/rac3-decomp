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

INCLUDE_ASM("asm/levels", func_L24_0034F1B8);

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
extern s32 func_L24_00351448(void *, void *, void *, s32, s32, f32, f32, f32, f32);
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
    if (func_L24_00351448(out, obj, a, 2, 3, D_L24_001DD4DC, D_L24_001DD4E0, 2.0f, 2.0f) != 0) {
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

INCLUDE_ASM("asm/levels", func_L24_0034FE28);

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
extern void func_L24_0034F1B8(void *);
extern void func_L24_00350288(u8 *);
extern void func_L24_0034EBF8(void *);
extern void func_L24_0034F080(u8 *);
extern void func_L24_0034F4E0(u8 *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
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
        func_L01_0044AF78(obj, s + 0x100, 0, 2.0f, 4.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 16, -1, 1, 1, -1, 0, 0x1010001);
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
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
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
            func_L01_0044AF78(m, v40, 0, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 9, 0, 1, 1, -1, 0, 0x1010001);

            func_003C2880(m);
            return 0;
        }
    }
    return (s32)m;
}
/* localdecomp:end func_L24_00350980 */

INCLUDE_ASM("asm/levels", func_L24_00350C30);

INCLUDE_ASM("asm/levels", func_L24_00351448);

INCLUDE_ASM("asm/levels", func_L24_003515A8);
