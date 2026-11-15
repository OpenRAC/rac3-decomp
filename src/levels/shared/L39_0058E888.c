#include "common.h"

/* localdecomp:start func_L39_0058E888 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0058E888;
typedef struct { V_0058E888 v[4]; u32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_0058E888;
extern V_0058E888 D_L39_0024DE00;
extern void func_003D93B0(void *, s32, s32, long);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0019D510();
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L39_0058E888(V_0058E888 *start, V_0058E888 *pts, u32 color, s32 n, f32 u0, f32 du) {
    V_0058E888 prevv;
    V_0058E888 *prev = &prevv;
    Q_0058E888 a;
    Q_0058E888 b;
    V_0058E888 m[4];
    V_0058E888 wa;
    V_0058E888 wb;
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
    wa.z = func_L39_005B4410(0.2f, 0.45f);
    wb.z = wa.z * 1.5f;
    if ((func_0019D510() & 1) == 0) {
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
    vec_sub_ba(&m[1], &D_L39_0024DE00, prev);
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
        vec_sub_ab(&m[1], &D_L39_0024DE00, &pts[i]);
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
/* localdecomp:end func_L39_0058E888 */

LINKER_REMNANT("asm/levels", func_L39_0058EEB8);
