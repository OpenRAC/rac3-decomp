#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00524E00);

/* localdecomp:start func_L39_00525030 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00525030;
typedef struct R_00525030 { u8 pad0[0x10]; void *p10; } R_00525030;
typedef struct M_00525030 {
    u8 pad0[0x10];
    V_00525030 pos;
    u8 pad20[4];
    R_00525030 *p24;
    u8 pad28[0x70];
    void *p98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x14];
    V_00525030 vC0;
    u8 padD0[0x10];
    V_00525030 vE0;
    u8 padF0[8];
    f32 fF8;
} M_00525030;
typedef struct G_00525030 {
    u8 pad0[0xA0];
    f32 fA0;
    f32 fA4;
    u8 padA8[0x2B4 - 0xA8];
    f32 f2B4;
    u8 pad2B8[0x2D8 - 0x2B8];
    s16 h2D8;
    u8 pad2DA[0x2524 - 0x2DA];
    M_00525030 *p2524;
    u8 pad2528[0x2548 - 0x2528];
    s32 i2548;
} G_00525030;
typedef struct T_00525030 { u8 pad0[0x10]; M_00525030 *target; u8 pad14[0x40]; G_00525030 *g; } T_00525030;
typedef struct S_00525030 { u8 pad0[0x68]; T_00525030 *t; } S_00525030;
typedef struct C_00525030 { u8 pad0[0x18]; M_00525030 *hit; u8 pad1C[4]; V_00525030 pos; } C_00525030;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_00524E00(void *, s32);
extern u8 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);
extern M_00525030 *D_L39_00292C20[];
extern C_00525030 D_L39_0025F740;
extern V_00525030 D_L39_0025F760;
__asm__(".extern D_L39_002429BC, 16");
extern s32 D_L39_002429BC;
extern s32 D_001D72B0_sda;
M_00525030 *func_L39_00525030(S_00525030 *self, V_00525030 *src, f32 *yawOut, f32 *pitchOut) {
    V_00525030 pos;
    V_00525030 *pp;
    V_00525030 tmp;
    V_00525030 end;
    M_00525030 *list[128];
    V_00525030 mpos;
    V_00525030 off;
    V_00525030 v250;
    V_00525030 v260;
    T_00525030 *t;
    G_00525030 *g;
    M_00525030 *result;
    M_00525030 *m;
    M_00525030 *hit;
    u8 *r;
    s32 idx;
    s32 n;
    s32 i;
    s32 j;
    s32 found;
    f32 best;
    f32 yaw, pitch, dyaw, dist, d, a, l, ang, rad, sub;

    best = 12.0f;
    pp = &pos;
    *pp = *src;
    t = self->t;
    g = t->g;
    result = 0;
    func_0038CE20(&tmp, &g->p2524->vE0, 0.5f);
    vec_add_ba(&end, &g->p2524->pos, &tmp);
    if (func_003D3CB0(&end, pp, 6, g->p2524, 0) != 0) {
        *(vu0_q *)pp = *(vu0_q *)&D_L39_0025F760;
        return 0;
    }
    n = 0;
    for (idx = 0; (m = D_L39_00292C20[idx]) != 0; idx++) {
        if (m == g->p2524) continue;
        if (func_L39_00524E00(m, g->i2548) == 0) continue;
        mpos = m->pos;
        r = func_00382348(m);
        if (r == 0) continue;
        func_0038CE20(&off, &m->vE0, *(f32 *)(r + 0x10));
        found = 0;
        vec_add_ab(&mpos, &mpos, &off);
        yaw = func_0038D160(mpos.x - pp->x, mpos.y - pp->y);
        d = func_0038CF38(pp, &mpos);
        pitch = func_0038D160(d, mpos.z - pp->z);
        dyaw = func_0038DBA0(*yawOut, yaw);
        dist = func_0038CF00(pp, &mpos);
        if (D_L39_002429BC != 0 || g->h2D8 != 0 || D_001D72B0_sda != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&v250, &m->pos, &g->p2524->pos);
                d = func_0038CE68(&v250, &g->p2524->vE0);
                if (fabs_asm(d) < 2.0f) {
                    func_0038CE20(&v260, &g->p2524->vE0, d);
                    vec_sub_ab(&v250, &v250, &v260);
                    a = func_0038CE68(&v250, &g->p2524->vC0);
                    l = func_0038CEA8(&v250);
                    if (l != 0.0f) {
                        if (1.5707964f - func_0038D0C8(a / l) < 1.0471976f) {
                            found = 1;
                        }
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                M_00525030 *p = g->p2524;
                if (func_0038DBA0(p->fF8, func_0038D160(m->pos.x - g->fA0, m->pos.y - g->fA4)) < 1.0471976f) {
                    if (fabs_asm(pp->z - mpos.z) < 2.0f) {
                        found = 1;
                    }
                }
            }
        }
        if (found) {
            if (func_003D3CB0(pp, &mpos, 6, g->p2524, 0) == 0) {
                *pitchOut = -pitch;
                result = m;
                *yawOut = yaw;
                break;
            }
        }
        if (best < dist && m != t->target) continue;
        if (12.0f < dist) continue;
        func_00382760(&off, dist, *yawOut, *pitchOut + g->f2B4 * 0.5f);
        vec_add_ab(&off, &off, pp);
        ang = func_0038D0C8(func_0038CF00(&off, &mpos) / (dist + dist)) * 2.0f;
        if (0.2617994f < ang) {
            r = func_00382348(m);
            if (r != 0) {
                rad = r[0xA] * 0.125f;
                sub = func_0038D0C8(rad / dist);
                if (rad < dist) {
                    ang -= sub;
                    if (ang < 0.0f) ang = 0.0f;
                }
            }
        }
        if (!(ang < 0.2617994f)) continue;
        found = 1;
        v250 = *pp;
        for (i = 0; func_003D3CB0(&v250, &mpos, 6, self, 0) != 0 && ++i < 7; ) {
            hit = D_L39_0025F740.hit;
            if (hit != 0) {
                if (hit->hAA == 0x10AA || hit->hAA == 0x1080) {
                    list[n] = hit;
                    n++;
                    hit->p98 = 0;
                    if (n >= 0x80) break;
                    v250 = D_L39_0025F740.pos;
                    continue;
                }
                if (hit == m) break;
            }
            found = 0;
            break;
        }
        if (found) {
            *pitchOut = -pitch;
            best = dist;
            if (dyaw < 0.17453292f) *yawOut = yaw;
            result = m;
            if (m == t->target) return result;
        }
    }
    for (j = 0; j < n; j++) {
        list[j]->p98 = list[j]->p24->p10;
    }
    return result;
}
/* localdecomp:end func_L39_00525030 */

INCLUDE_ASM("asm/levels", func_L39_00525690);

INCLUDE_ASM("asm/levels", func_L39_00526280);

INCLUDE_ASM("asm/levels", func_L39_00526340);

INCLUDE_ASM("asm/levels", func_L39_00526FC0);

/* localdecomp:start func_L39_00527460 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00527460;

typedef struct {
    V_00527460 v[4];
    s32 col[4];
    f32 uv[8];
    long tag[4];
} S_00527460;

extern long func_L39_00589890(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003A9440(s32, unsigned long);

void func_L39_00527460(V_00527460 *pts, V_00527460 *center, s32 a1, s32 a2, s32 n, s32 color,
                       f32 unused, f32 height, f32 width, f32 u) {
    S_00527460 s1;
    S_00527460 s2;
    V_00527460 nrm;
    V_00527460 h;
    V_00527460 d0;
    V_00527460 d1;
    V_00527460 e;
    V_00527460 f;
    V_00527460 a;
    V_00527460 b;
    V_00527460 d2;
    V_00527460 g;
    V_00527460 *p;
    s32 c1;
    s32 c2;
    s32 i;
    f32 len;
    f32 l0;
    f32 l1;
    f32 la;
    f32 lb;

    s1.tag[1] = func_L39_00589890(0xE);
    s1.tag[3] = 0x8000000048L;
    s1.tag[2] = 0xFF9000000260L;
    s1.tag[0] = 0;
    c1 = (a1 << 24) | 0x7F7F7F;
    s1.col[0] = s1.col[1] = s1.col[2] = s1.col[3] = c1;
    s2.tag[1] = func_L39_00589890(0x10);
    s2.tag[3] = s1.tag[3];
    s2.tag[2] = s1.tag[2];
    s2.tag[0] = s1.tag[0];
    c2 = color | (a2 << 24);
    s2.col[0] = s2.col[1] = s2.col[2] = s2.col[3] = c2;
    s2.uv[0] = 0.0f;
    s2.uv[1] = 0.0f;
    s2.uv[2] = 0.0f;
    s2.uv[3] = 1.0f;
    s2.uv[4] = 1.0f;
    s2.uv[5] = 0.0f;
    s2.uv[6] = 1.0f;
    s2.uv[7] = 1.0f;
    s1.uv[0] = u + s2.uv[0];
    s1.uv[1] = s2.uv[1];
    s1.uv[2] = u + s2.uv[2];
    s1.uv[3] = s2.uv[3];
    s1.uv[4] = u + s2.uv[4];
    s1.uv[5] = s2.uv[5];
    s1.uv[6] = u + s2.uv[6];
    s1.uv[7] = s2.uv[7];

    vec_sub_ab(&d0, &pts[0], center);
    vec_sub_ab(&d1, &pts[1], &pts[0]);
    func_0038CE90(&nrm, &d1, &d0);
    l0 = func_0038CEA8(&nrm);
    if (l0 != 0.0f) {
        l0 = 1.0f / l0;
    }
    func_0038CE20(&nrm, &nrm, l0 * 0.05f);
    vec_add_ba(&s1.v[0], &pts[0], &nrm);
    vec_sub_ab(&s1.v[1], &pts[0], &nrm);

    for (i = 1; i < n - 1; i++) {
        p = &pts[i];
        vec_sub_ab(&d0, p, center);
        vec_sub_ab(&d1, p + 1, p);
        func_0038CE90(&nrm, &d1, &d0);
        l1 = func_0038CEA8(&nrm);
        if (l1 != 0.0f) {
            l1 = 1.0f / l1;
        }
        func_0038CE20(&nrm, &nrm, l1 * 0.05f);
        vec_add_ba(&s1.v[2], p, &nrm);
        vec_sub_ab(&s1.v[3], p, &nrm);
        if (i == 1) {
            s1.col[0] = s1.col[1] = 0x7F7F7F;
        } else if (i == n - 2) {
            s1.col[2] = s1.col[3] = 0x7F7F7F;
        } else if (i == 2) {
            s1.col[0] = s1.col[1] = c1;
        }
        func_003D2DA0(&s1, 0, 0);
        s1.v[0] = s1.v[2];
        s1.v[1] = s1.v[3];
    }

    for (i = 0; i < n - 1; i++) {
        p = &pts[i];
        vec_sub_ab(&a, p, center);
        vec_sub_ab(&b, p + 1, center);
        la = func_0038CEA8(&a);
        lb = func_0038CEA8(&b);
        if (lb < la) {
            if (lb == 0.0f) {
                b = a;
            } else {
                func_0038CE20(&b, &b, la / lb);
            }
        } else {
            if (la == 0.0f) {
                a = b;
            } else {
                func_0038CE20(&a, &a, lb / la);
            }
        }
        vec_add_ba(&e, center, &a);
        vec_add_ab(&f, center, &b);
        vec_sub_ba(&d1, &f, &e);
        func_0038CE20(&g, &d1, width);
        vec_sub_ab(&e, &e, &g);
        vec_add_ab(&f, &f, &g);
        vec_sub_ba(&d2, center, &e);
        func_0038CE90(&nrm, &d2, &d1);
        len = func_0038CEA8(&nrm);
        if (len != 0.0f) {
            len = 1.0f / len;
        }
        func_0038CE20(&h, &nrm, height * len);
        vec_add_ba(&s2.v[0], &e, &h);
        vec_sub_ab(&s2.v[1], &e, &h);
        vec_add_ba(&s2.v[2], &f, &h);
        vec_sub_ab(&s2.v[3], &f, &h);
        if (i == 0) {
            s2.col[0] = s2.col[1] = color;
        } else if (i == n - 2) {
            s2.col[2] = s2.col[3] = color;
        } else if (i == 1) {
            s2.col[0] = s2.col[1] = c2;
        }
        func_003D2DA0(&s2, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L39_00527460 */

INCLUDE_ASM("asm/levels", func_L39_00527A38);

INCLUDE_ASM("asm/levels", func_L39_00527C88);

INCLUDE_ASM("asm/levels", func_L39_005285A8);

/* localdecomp:start func_L39_005287B0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005287B0;
typedef struct { u8 pad0[0x10]; V_005287B0 pos; } O_005287B0;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_005287B0;
extern s32 D_L39_0024D4E0_b;
extern T_005287B0 D_L39_0024DCC0;
__asm__(".extern D_L39_0024AA70, 4");
extern f32 D_L39_0024AA70;
__asm__(".extern D_L39_0024AA74, 4");
extern f32 D_L39_0024AA74;
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_005D2930(void *, void *, s32);
extern void func_L39_00528AF0(s32);
extern void func_003C2880(void *);
void func_L39_005287B0(O_005287B0 *o) {
    V_005287B0 v0;
    V_005287B0 v1;
    s32 i;
    f32 a, b, c;
    f32 ang, spd, dir, s;

    for (i = 0; i < 0x21 - D_L39_0024D4E0_b; i++) {
        a = func_L39_005B4410(0.0f, 0.37f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v1, a, b, c);
        v1.z += func_L39_005B4410(0.35f, 0.6f);
        vec_add_ba(&v1, &v1, &o->pos);
        a = func_L39_005B4410(0.002f, 0.020000001f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v0, a, b, c);
        func_L39_005C8CA8(&v1, &v0, 0x4F20507F, 0x102F, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }
    for (i = 0; i < 0x32 - D_L39_0024D4E0_b; i++) {
        ang = func_0038D160(D_L39_0024DCC0.x - o->pos.x, D_L39_0024DCC0.y - o->pos.y);
        func_L39_005B4468(1.0f, 2.0f);
        v0.x = o->pos.x + func_L39_005B4468(0.0f, 0.15f);
        v0.y = o->pos.y + func_L39_005B4468(0.0f, 0.15f);
        v0.z = o->pos.z + func_L39_005B4468(0.0f, 0.15f);
        s = D_L39_0024AA70;
        spd = s * 0.020000001f;
        dir = func_0038DAB8(ang, func_L39_005B4468(0.0f, -1.5707964f));
        v1.x = func_0038D098(dir) * spd;
        v1.y = func_0038D0B0(dir) * spd;
        s = D_L39_0024AA74;
        v1.z = s * 0.020000001f;
        func_L39_005D2930(&v0, &v1, 0xFA);
    }
    func_L39_00528AF0((s32)o);
    func_003C2880(o);
}
/* localdecomp:end func_L39_005287B0 */
