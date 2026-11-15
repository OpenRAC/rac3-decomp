#include "common.h"

/* declared by functions of L40_00426B60.c, which this file was cut from */
extern f32 func_L01_0040E548(void *a, void *b);
extern u8 *func_L39_0061D7B0(void *);

/* localdecomp:start func_L40_004272D0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004272D0;
typedef struct {
    u8 pad0[0x1F8];
    f32 a[1];
} D_004272D0;
typedef struct {
    u8 pad0[0x80];
    u8 j80[0x60];
    f32 fE0;
    f32 fE4;
    f32 fE8;
    u8 padEC[0x200 - 0xEC];
    V_004272D0 p200;
    V_004272D0 p210;
    u8 pad220[0x10];
    u8 *m230;
    u8 pad234[0x274 - 0x234];
    f32 f274;
    f32 f278;
    s32 f27C;
    u8 pad280[0x2A0 - 0x280];
    s32 f2A0;
} P_004272D0;

extern D_004272D0 D_L40_00357260;
extern u8 D_L40_003BFE20[];
extern f32 *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L40_004272D0(u8 *a0) {
    V_004272D0 pos;
    V_004272D0 old;
    V_004272D0 d;
    u32 buf[2];
    P_004272D0 *v;
    f32 *dmg;
    u8 *g;
    u8 *r;
    f32 f;
    f32 s;
    s32 x;

    v = *(P_004272D0 **)(a0 + 0x68);
    if (v->m230 != 0 && v->f2A0 == 0) {
        g = 0;
        dmg = func_00382348(v->m230);
        pos = *(V_004272D0 *)(v->m230 + 0x10);
        r = func_L39_0061D7B0(v->m230);
        if (r != 0 && (r[3] & 0xF) == 0) {
            g = r;
        }
        f = 0.0f;
        if (dmg != 0 && g != 0) {
            func_0038CE20(&d, v->m230 + 0xE0, dmg[4] * -0.4f);
            vec_add_ab(&pos, &pos, &d);
            {
                u8 *p = g + 0x19E4;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 i;
                long t;

                t = *p;
                x = 0;
                if (t != 0) {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (i = 0; i < 40; i += 5) {
                        *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    x = buf[1];
                }
            }
            if ((x ^ 4) == 0 || g[0x24FD] != 0) {
                f = -0.25f;
            }
        }
        old = pos;
        if (func_L01_0040E548(&v->p210, &pos) < 0.0001f) {
            if (dmg != 0) {
                pos = *(V_004272D0 *)(v->m230 + 0x10);
                func_0038CE20(&d, v->m230 + 0xE0, dmg[4] + f);
            } else {
                v->p200.x = ((f32 *)v->m230)[0] * 0.0009765625f;
                v->p200.y = ((f32 *)v->m230)[1] * 0.0009765625f;
                v->p200.z = ((f32 *)v->m230)[2] * 0.0009765625f;
                v->p200.w = 0.0f;
                goto store;
            }
        } else {
            vec_sub_ab(&d, &pos, &v->p210);
            f = 1.0f;
            s = D_L40_00357260.a[v->f27C] * 4.5f;
            if (s < f) {
                s = f;
            }
            func_0038CE20(&d, &d, s);
            if (g != 0) {
                if (f < d.z) {
                    d.z = f;
                } else if (d.z < -1.0f) {
                    d.z = -1.0f;
                }
            }
        }
        vec_add_ab(&pos, &pos, &d);
store:
        v->p210 = old;
        v->p200 = pos;
        func_003C2F58(a0, 0, &d);
        v->fE0 = -func_0038D160(func_0038CF38(&v->p200, &d), d.z - v->p200.z);
        v->fE8 = func_0038DAB8(func_0038D160(d.x - v->p200.x, d.y - v->p200.y),
                               -(*(f32 *)(a0 + 0xF8) - 1.5707964f));
        if (0.61086524f < v->fE0) {
            v->fE0 = 0.61086524f;
        }
        if (v->fE0 < -0.61086524f) {
            v->fE0 = -0.61086524f;
        }
    } else {
        qzero(&v->fE0);
    }
    func_L01_0044E850(a0, v->j80, 0, (v->f274 + D_L40_00357260.a[v->f27C] * 0.009f) * 1.44f,
                      v->f278 * 1.44f);
}
/* localdecomp:end func_L40_004272D0 */

/* localdecomp:start func_L40_004276F0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004276F0;
typedef struct {
    V_004276F0 v[4];
    s32 c[4];
    s32 z0;
    s32 z1;
    s32 z2;
    f32 g0;
    f32 g1;
    s32 z3;
    f32 g2;
    f32 g3;
    u8 pad70[0x20];
} S_004276F0;

extern f32 func_L39_005B4410(f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
__asm__(".extern D_L40_002477CC, 4");
extern f32 D_L40_002477CC;
extern V_004276F0 D_L40_00249F40;

void func_L40_004276F0(void *a0) {
    V_004276F0 m[4];
    V_004276F0 w[4];
    V_004276F0 t;
    S_004276F0 s;
    f32 a;
    f32 b;
    s32 i;

    a = func_L39_005B4410(0.75f, 0.95f);
    b = func_L39_005B4410(2.0f, 2.5f);
    func_003C2EC0(a0, 3, w);
    func_0038CF68(&t, &w[1], D_L40_002477CC);
    vec_add_ba(&w[3], &w[3], &t);
    func_0038CF68(&m[0], &w[1], -1.0f);
    vec_sub_ba(&m[1], &D_L40_00249F40, &w[3]);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], a);
    func_0038CF68(&m[0], &m[0], b);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    func_003D93B0(&s, 0x3F, 1, 0x80);
    s.z0 = 0;
    s.z1 = 0;
    s.z2 = 0;
    s.g0 = 1.0f;
    s.g1 = 1.0f;
    s.z3 = 0;
    s.g2 = 1.0f;
    s.g3 = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&s.v[i]);
        if (i < 2) {
            s.v[i].x = 0.0f;
        } else {
            s.v[i].x = 1.0f;
        }
        s.v[i].y = 0.0f;
        if (i & 1) {
            s.v[i].z = 1.0f;
        } else {
            s.v[i].z = -1.0f;
        }
        s.v[i].w = 1.0f;
        s.c[i] = 0x7FFFFFFF;
    }
    m[3] = w[3];
    m[3].w = 1.0f;
    func_003D2DA0(&s, m, 0);
    func_003D2DA0(&s, m, 0);
    func_003D2DA0(&s, m, 0);
    func_003D2DA0(&s, m, 0);
    func_003D2DA0(&s, m, 0);
    func_003D2DA0(&s, m, 0);
}
/* localdecomp:end func_L40_004276F0 */
