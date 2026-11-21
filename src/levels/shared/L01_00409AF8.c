#include "common.h"
#include "vu0.h"

LINKER_REMNANT("asm/levels", func_L01_00409AF8);

/* localdecomp:start func_L01_00409B08 */
typedef struct {
    vu0_v4 v[4];
    u32 c[4];
    f32 w[8];
    u8 pad70[0x20];
    vu0_v4 mat[3];
    vu0_v4 pp;
    f32 r[4];
    vu0_v4 d;
} L409B08;

typedef struct {
    u8 pad0[0x140];
    vu0_v4 p;
    f32 z;
} G409B08;

extern G409B08 D_L01_001E2880_00409B08;
extern void func_003D93B0(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_00409B08(f32 *pos, s32 col, s32 dbl) {
    L409B08 l;
    f32 sc;
    u32 c;

    l.v[0].z = -2.0f;
    l.v[1].z = 2.0f;
    l.v[2].z = -2.0f;
    l.v[3].z = 2.0f;
    l.v[0].y = -2.0f;
    l.v[2].y = 2.0f;
    l.v[1].y = -2.0f;
    l.v[3].y = 2.0f;
    l.v[0].x = 0.0f;
    l.v[1].x = 0.0f;
    l.v[2].x = 0.0f;
    l.v[3].x = 0.0f;
    l.v[0].w = 1.0f;
    l.v[1].w = 1.0f;
    l.v[2].w = 1.0f;
    l.v[3].w = 1.0f;
    func_003D93B0(&l, 0x2C, 1, 0x80);
    c = (func_00382498(0x30, 0x40) << 24) | ((col >> 17) << 16) | ((col >> 9) & 0xFF00) | ((col >> 1) & 0xFF);
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    l.w[0] = 0.0f;
    l.w[1] = 0.0f;
    l.w[2] = 0.0f;
    l.w[3] = 1.0f;
    l.w[4] = 1.0f;
    l.w[5] = 0.0f;
    l.w[6] = 1.0f;
    l.w[7] = 1.0f;
    l.r[3] = 0.0f;
    l.r[2] = func_0038D160(D_L01_001E2880_00409B08.p.x - pos[0], D_L01_001E2880_00409B08.p.y - pos[1]);
    l.r[1] = -func_0038D160(func_0038CF38(pos, &D_L01_001E2880_00409B08.p), D_L01_001E2880_00409B08.p.z - pos[2]);
    l.r[0] = func_00382538();
    func_0038D328(l.mat, l.r);
    vec_sub_ab(&l.d, &D_L01_001E2880_00409B08.p, pos);
    func_0038CF68(&l.d, &l.d, 0.25f);
    l.pp.x = pos[0] + l.d.x;
    l.pp.y = pos[1] + l.d.y;
    l.pp.z = pos[2] + l.d.z;
    l.pp.w = 1.0f;
    sc = func_003824E0(0.3f, 0.4f);
    if (dbl != 0) {
        sc += sc;
    }
    func_0038CE20(&l.v[0], &l.v[0], sc);
    func_0038CE20(&l.v[1], &l.v[1], sc);
    func_0038CE20(&l.v[2], &l.v[2], sc);
    func_0038CE20(&l.v[3], &l.v[3], sc);
    func_003D2DA0(&l, l.mat, 0);
    func_0038CE20(&l.v[0], &l.v[0], 0.5f);
    func_0038CE20(&l.v[1], &l.v[1], 0.5f);
    func_0038CE20(&l.v[2], &l.v[2], 0.5f);
    func_0038CE20(&l.v[3], &l.v[3], 0.5f);
    c = col + (func_00382498(0x40, 0x7F) << 24);
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    func_003D2DA0(&l, l.mat, 0);
    func_0038CE20(&l.v[0], &l.v[0], 0.5f);
    func_0038CE20(&l.v[1], &l.v[1], 0.5f);
    func_0038CE20(&l.v[2], &l.v[2], 0.5f);
    func_0038CE20(&l.v[3], &l.v[3], 0.5f);
    c = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    func_003D2DA0(&l, l.mat, 0);
}
/* localdecomp:end func_L01_00409B08 */

/* localdecomp:start func_L01_00409E70 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00409E70;
typedef struct { V_00409E70 v[4]; u32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_00409E70;
extern V_00409E70 D_L01_001E29C0;
extern s32 func_0013D3E0(void);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);

void func_L01_00409E70(V_00409E70 *start, V_00409E70 *pts, u32 color, s32 n, f32 u0, f32 du) {
    V_00409E70 prevv;
    V_00409E70 *prev = &prevv;
    Q_00409E70 a;
    Q_00409E70 b;
    V_00409E70 m[4];
    V_00409E70 wa;
    V_00409E70 wb;
    s32 i;
    f32 lo, hi;
    f32 ua, ub;

    *prev = *start;
    func_003D93B0(&a, 0x17, 1, 0x80);
    func_003D93B0(&b, 0x17, 1, 0x80);
    *(vu0_q *)&wa = 0;
    *(vu0_q *)&wb = 0;
    a.c[0] = a.c[1] = color | 0x7F000000;
    b.c[0] = b.c[1] = color | 0x3F000000;
    wa.w = 1.0f;
    wb.w = 1.0f;
    wa.z = func_003824E0(0.2f, 0.45f);
    wb.z = wa.z * 1.5f;
    if ((func_0013D3E0() & 1) == 0) {
        lo = u0 + 0.0f;
        hi = du + u0;
        a.uv[0] = lo; a.uv[1] = 0.0f;
        a.uv[2] = lo; a.uv[3] = 1.0f;
        a.uv[4] = hi; a.uv[5] = 0.0f;
        a.uv[6] = hi; a.uv[7] = 1.0f;
        b.uv[0] = lo; b.uv[1] = 0.0f;
        b.uv[2] = lo; b.uv[3] = 1.0f;
        b.uv[4] = hi; b.uv[5] = 0.0f;
        b.uv[6] = hi; b.uv[7] = 1.0f;
    } else {
        lo = u0 + 0.0f;
        hi = du + u0;
        a.uv[0] = lo; a.uv[1] = 1.0f;
        a.uv[2] = lo; a.uv[3] = 0.0f;
        a.uv[4] = hi; a.uv[5] = 1.0f;
        a.uv[6] = hi; a.uv[7] = 0.0f;
        b.uv[0] = lo; b.uv[1] = 1.0f;
        b.uv[2] = lo; b.uv[3] = 0.0f;
        b.uv[4] = hi; b.uv[5] = 1.0f;
        b.uv[6] = hi; b.uv[7] = 0.0f;
    }
    vec_sub_ba(&m[0], &pts[0], prev);
    func_0038CF68(&m[0], &m[0], 1.0f);
    vec_sub_ba(&m[1], &D_L01_001E29C0, prev);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], 1.0f);
    func_0038CE90(&m[1], &m[0], &m[2]);
    m[3] = *prev;
    a.v[0] = wa;
    b.v[0] = wb;
    func_0038CE20(&a.v[1], &a.v[0], -1.0f);
    func_0038CE20(&b.v[1], &b.v[0], -1.0f);
    func_0038D028(&a.v[0], &a.v[0], m);
    func_0038D028(&a.v[1], &a.v[1], m);
    func_0038D028(&b.v[0], &b.v[0], m);
    func_0038D028(&b.v[1], &b.v[1], m);
    for (i = 0; i < n - 1; i++) {
        vec_sub_ba(&m[0], &pts[i + 1], &pts[i]);
        func_0038CF68(&m[0], &m[0], 1.0f);
        vec_sub_ab(&m[1], &D_L01_001E29C0, &pts[i]);
        func_0038CE90(&m[2], &m[1], &m[0]);
        func_0038CF68(&m[2], &m[2], 1.0f);
        func_0038CE90(&m[1], &m[0], &m[2]);
        wa.z *= 0.75f;
        wb.z = wa.z * 1.5f;
        m[3] = pts[i];
        a.v[2] = wa;
        b.v[2] = wb;
        func_0038CE20(&a.v[3], &a.v[2], -1.0f);
        func_0038CE20(&b.v[3], &b.v[2], -1.0f);
        func_0038D028(&a.v[2], &a.v[2], m);
        func_0038D028(&a.v[3], &a.v[3], m);
        func_0038D028(&b.v[2], &b.v[2], m);
        func_0038D028(&b.v[3], &b.v[3], m);
        a.c[2] = a.c[3] = color | 0x7F000000;
        b.c[2] = b.c[3] = color | 0x3F000000;
        ua = du * (f32)(i + 1);
        ub = ua + du;
        if (ua >= 1.0f) {
            ua -= 1.0f;
            ub -= 1.0f;
        }
        ua += u0;
        ub += u0;
        a.uv[0] = ua;
        a.uv[2] = ua;
        a.uv[4] = ub;
        a.uv[6] = ub;
        b.uv[0] = ua;
        b.uv[2] = ua;
        b.uv[4] = ub;
        b.uv[6] = ub;
        func_003D2DA0(&a, 0, 0);
        func_003D2DA0(&b, 0, 0);
        a.v[0] = a.v[2];
        a.v[1] = a.v[3];
        b.v[0] = b.v[2];
        b.v[1] = b.v[3];
    }
    m[3] = pts[n - 1];
    wa.z *= 0.75f;
    wb.z = wa.z * 1.5f;
    a.v[2] = wa;
    b.v[2] = wb;
    func_0038CE20(&a.v[3], &a.v[2], -1.0f);
    func_0038CE20(&b.v[3], &b.v[2], -1.0f);
    func_0038D028(&a.v[2], &a.v[2], m);
    func_0038D028(&a.v[3], &a.v[3], m);
    func_0038D028(&b.v[2], &b.v[2], m);
    func_0038D028(&b.v[3], &b.v[3], m);
    a.c[2] = a.c[3] = color;
    b.c[2] = b.c[3] = color;
    ub = du * (f32)(i + 1);
    ua = ub + du;
    if (ub >= 1.0f) {
        ub -= 1.0f;
        ua -= 1.0f;
    }
    ub += u0;
    ua += u0;
    a.uv[0] = ub;
    a.uv[2] = ub;
    a.uv[4] = ua;
    a.uv[6] = ua;
    b.uv[0] = ub;
    b.uv[2] = ub;
    b.uv[4] = ua;
    b.uv[6] = ua;
    func_003D2DA0(&a, 0, 0);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L01_00409E70 */

INCLUDE_ASM("asm/levels", func_L01_0040A4A0);
