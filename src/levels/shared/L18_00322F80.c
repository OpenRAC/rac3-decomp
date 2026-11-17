#include "common.h"

/* localdecomp:start func_L18_00322F80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00322F80;
extern s32 func_L01_00459590(void *, void *, f32);
extern void func_L01_0044AF78(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L18_00322F80(u8 *a0, void *a1, void *at, f32 a, f32 b) {
    V_00322F80 *pos = at;
    V_00322F80 v;
    f32 dist;
    s32 n0, n1, n2;

    if (pos == 0) {
        pos = (V_00322F80 *)(a0 + 0x10);
    }
    v = *pos;
    v.w = a;
    if (func_L01_00459590(&v, &dist, 128.0f) >= 0) {
        n0 = 10;
        n1 = 3;
        n2 = 9;
        if (64.0f < dist) {
            n0 = 0;
            n1 = 1;
            n2 = 1;
        } else if (32.0f < dist) {
            n0 = 5;
            n2 = 1;
        }
        func_L01_0044AF78(a0, a1, pos, a, b, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, n0, n1, n2, 0, 1, 1, -1, 0, 0x1010001);
    }
    func_L01_003303B8(pos, 0, 3, 3, 6, 10, 3, 0, 1.5f, 0.0f, 0.0f, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L18_00322F80 */

/* localdecomp:start func_L18_00323178 */
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA;
} M_00323178;
extern M_00323178 *D_L18_001EAA98 __attribute__((section(".data")));
extern void (**func_L01_0043B568(s32, s32, s32))(void);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L18_00323178(s32 a0, void *a1, void *a2, s32 a3, void *a4, s32 a5) {
    void (**v)(void) = func_L01_0043B568(0x1E6F, 0, 0xC);
    s32 r;
    if (v != 0) {
        v[1]();
    }
    func_L01_004CB320();
    r = func_003D3CB0(a1, a2, a3, a4, a5);
    if (r != 0) {
        M_00323178 *m = D_L18_001EAA98;
        if (m != 0 && m->hAA == 0x186D && m->b20 != 2 && m->b20 != 5) {
            m->b20 = 4;
        }
    }
    func_L01_004CB358();
    if (v != 0) {
        v[2]();
    }
    return r;
}
/* localdecomp:end func_L18_00323178 */

/* localdecomp:start func_L18_00323278 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00323278;
typedef struct {
    u8 p0[0x10]; V_00323278 v10; V_00323278 v20; u8 *w30; s32 w34; f32 f38; f32 f3C; f32 f40; f32 f44;
    f32 f48; f32 f4C; f32 f50; f32 f54; u8 p58[4]; f32 f5C; s32 w60; s32 w64;
} P_00323278;
typedef struct { u8 p0[0x24]; f32 f24; } C_00323278;
typedef struct {
    u8 p0[0x10]; V_00323278 pos; u8 b20; u8 p21[3]; C_00323278 *cls; u8 p28[4]; f32 f2C; u8 b30; u8 b31; s16 h32;
    u8 p34[0x34]; P_00323278 *vars; u8 p6C[0x88]; f32 fF4; f32 fF8;
} M_00323278;
typedef struct { u8 p0[0x10]; V_00323278 pos; } H_00323278;
typedef struct { u8 p0[0x25C0]; H_00323278 *hero; } G_00323278;
typedef struct { u8 p0[0x18]; H_00323278 *w18; u8 p1C[4]; V_00323278 v20; u8 p30[0x10]; V_00323278 v40; } T_00323278;
extern G_00323278 D_001A4BE0;
extern T_00323278 D_L18_001EAA80;
extern M_00323278 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L18_00323178(s32, void *, void *, s32, void *, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L18_00322F80(u8 *, void *, void *, f32, f32);
extern void func_003C2880(void *);

M_00323278 *func_L18_00323278(u8 *owner, V_00323278 *at, V_00323278 *to, s32 a3, s32 t0, f32 f12, f32 f13, f32 f14, f32 f15) {
    M_00323278 *m;
    P_00323278 *p;
    V_00323278 v;
    V_00323278 dir;
    V_00323278 vel;
    T_00323278 *t;

    m = func_003C24B0(0x15A5, 0x80);
    if (m == 0) {
        return 0;
    }
    m->b30 = 0xFF;
    m->fF8 = f12;
    m->fF4 = f13;
    m->h32 = 0xFF;
    m->b31 = 1;
    m->b20 = 0;
    m->f2C = m->cls->f24 * 0.25f;
    p = m->vars;
    p->w30 = owner;
    p->w64 = t0;
    m->pos = *at;
    p->v20 = *at;
    p->v10 = *to;
    p->f50 = func_003824E0(-0.007736f, 0.007736f);
    p->f54 = func_003824E0(-0.019248f, 0.019248f);
    p->f38 = f14;
    p->f5C = f15;
    p->f3C = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = func_003824E0(-0.785398f, 0.785398f);
    p->f4C = func_003824E0(-0.785398f, 0.785398f);
    p->w60 = a3;
    p->w34 = 0xD0;
    func_003C7C38(m);
    func_003A52A0(0, 0, m);
    v = D_001A4BE0.hero->pos;
    v.z = at->z;
    if (func_L18_00323178(-1, &v, at, 0, p->w30, 0) != 0) {
        t = &D_L18_001EAA80;
        if (t->w18 == 0 || (t->w18 != D_001A4BE0.hero && t->w18 != (H_00323278 *)p->w30)) {
            m->pos = t->v20;
            func_00382760(&dir, p->f38, m->fF8, -m->fF4);
            func_L01_0040E790(&vel, &dir, &t->v40);
            func_0038CF68(&vel, &vel, 0.0400000028f);
            func_L18_00322F80((u8 *)m, &vel, 0, 0.0f, 0.0f);
            func_003C2880(m);
            return 0;
        }
    }
    return m;
}
/* localdecomp:end func_L18_00323278 */

/* localdecomp:start func_L18_00323518 */
#include "vu0.h"
typedef struct { u8 p0[0x38]; f32 f38; } P_00323518;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; P_00323518 *vars; } M_00323518;
extern u8 *D_L18_00221174 __attribute__((section(".data")));
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0013D3E0(void);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L18_00323518(M_00323518 *m, vu0_v4 *dir) {
    P_00323518 *p = m->vars;
    vu0_v4 vel;
    vu0_v4 pos;
    f32 size;
    s32 n;
    s32 alpha;
    s32 color;
    u8 *q;

    size = func_003824E0(200.0f, 1000.0f);
    n = func_L01_00443A18(1.0f, 3.0f);
    pos = (vu0_v4){0};
    pos.x = func_003824E0(-1.0f, 1.0f);
    pos.y = func_003824E0(-1.0f, 1.0f);
    pos.z = func_003824E0(-1.0f, 1.0f);
    vel = pos;
    func_0038CF68(&vel, &vel, func_003824E0(0.1f, 0.2f) * 0.0200000014f);
    func_0038CF68(&pos, dir, -func_003824E0(0.002f, 0.0200000014f));
    vec_add_ba(&vel, &vel, &pos);
    func_0038CF68(&pos, dir, func_003824E0(0.0f, 1.0f) * p->f38);
    vec_add_ba(&pos, &pos, &m->pos);
    if (func_0013D3E0() & 1) {
        alpha = 0x40;
        color = 0;
        size += size;
    } else {
        color = 0x406080;
        alpha = 0x7F;
    }
    q = func_L01_0046A610(&pos, &vel, (func_00382498(0x1C, 0x28) * 5 + 2) / 6, alpha, color, n, 273000.0f, size, 1.0f, 0.0f, 0.0f);
    if (q != 0) {
        q[2] = *D_L18_00221174;
        q[3] = alpha == 0x7F ? 0x48 : 0x44;
    }
}
/* localdecomp:end func_L18_00323518 */

INCLUDE_ASM("asm/levels", func_L18_00323760);
