#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036C2F0 */
typedef struct {
    vu0_v4 p[4];
    s32 c[4];
    f32 uv[4][2];
    unsigned long t70;
    unsigned long t78;
    unsigned long t80;
    unsigned long t88;
} Q_0036C2F0;

extern s32 func_00382498(s32, s32);
extern long func_00389598(s32);
extern void func_L01_0037C798(vu0_v4 *, s32);
extern void func_L01_0037C7D8_0036C2F0(Q_0036C2F0 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern vu0_v4 D_L05_001E2680;

void func_L05_0036C2F0(s32 a0, s32 a1, vu0_v4 *pts, s32 n) {
    Q_0036C2F0 q0;
    Q_0036C2F0 q1;
    vu0_v4 m[4];
    vu0_v4 w0;
    vu0_v4 w1;
    s32 col;
    s32 r;
    s32 i;
    f32 u0;
    f32 u1;

    r = func_00382498(0, 0xFF);
    col = 0x80000000 | (r << 16) | (func_00382498(0, 0xFF) << 8);
    q0.t78 = func_00389598(0x2B);
    q0.t88 = ((unsigned long)a1 << 32) | 0x68;
    q0.t80 = 0xFF9000000260;
    q0.c[1] = 0x7FFFFFFF;
    q0.c[0] = 0x7FFFFFFF;
    q0.t70 = 0;
    q1.t78 = func_00389598(0x2B);
    q1.t70 = 0;
    q1.t80 = 0xFF9000000260;
    q1.t88 = ((unsigned long)(a1 / 3) << 32) | 0x68;
    q0.c[1] = col;
    q1.c[0] = col;
    *(vu0_q *)&w0 = 0;
    *(vu0_q *)&w1 = 0;
    w0.z = 0.04f;
    w0.w = 1.0f;
    w1.z = 0.16f;
    w1.w = 1.0f;
    func_L01_0037C798(pts, n);
    func_L01_0037C7D8_0036C2F0(&q0);
    func_L01_0037C7D8_0036C2F0(&q1);
    q0.uv[0][0] = 0.0f;
    q0.uv[0][1] = 0.0f;
    q0.uv[1][0] = 0.0f;
    q0.uv[1][1] = 1.0f;
    q0.uv[2][0] = 1.0f;
    q0.uv[2][1] = 0.0f;
    q0.uv[3][0] = 1.0f;
    q0.uv[3][1] = 1.0f;
    q1.uv[0][0] = 0.0f;
    q1.uv[0][1] = 0.0f;
    q1.uv[1][0] = 0.0f;
    q1.uv[1][1] = 1.0f;
    q1.uv[2][0] = 0.33f;
    q1.uv[2][1] = 0.0f;
    q1.uv[3][0] = 0.33f;
    q1.uv[3][1] = 1.0f;
    vec_sub_ab(&m[0], &pts[1], &pts[0]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    vec_sub_ab(&m[1], &D_L05_001E2680, &pts[0]);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], 1.0f);
    func_0038CE90(&m[1], &m[0], &m[2]);
    m[3] = pts[0];
    q0.p[0] = w0;
    func_0038CE20(&q0.p[1], &q0.p[0], -1.0f);
    func_0038D028(&q0.p[0], &q0.p[0], m);
    func_0038D028(&q0.p[1], &q0.p[1], m);
    q1.p[0] = w1;
    func_0038CE20(&q1.p[1], &q1.p[0], -1.0f);
    func_0038D028(&q1.p[0], &q1.p[0], m);
    func_0038D028(&q1.p[1], &q1.p[1], m);
    for (i = 1; i < n - 1; i++) {
        q0.p[2] = w0;
        func_0038CE20(&q0.p[3], &q0.p[2], -1.0f);
        q1.p[2] = w1;
        func_0038CE20(&q1.p[3], &q1.p[2], -1.0f);
        vec_sub_ab(&m[0], &pts[i + 1], &pts[i]);
        func_0038CF68(&m[0], &m[0], 1.0f);
        vec_sub_ab(&m[1], &D_L05_001E2680, &pts[i]);
        func_0038CE90(&m[2], &m[1], &m[0]);
        func_0038CF68(&m[2], &m[2], 1.0f);
        func_0038CE90(&m[1], &m[0], &m[2]);
        m[3] = pts[i];
        func_0038D028(&q0.p[2], &q0.p[2], m);
        func_0038D028(&q0.p[3], &q0.p[3], m);
        func_0038D028(&q1.p[2], &q1.p[2], m);
        func_0038D028(&q1.p[3], &q1.p[3], m);
        q0.c[3] = 0x7F7F7F7F;
        q0.c[2] = 0x7F7F7F7F;
        q1.c[3] = col;
        q1.c[2] = col;
        func_003D2DA0(&q0, 0, 0);
        func_003D2DA0(&q1, 0, 0);
        u0 = i * 0.33f;
        u1 = u0 + 0.33f;
        if (1.0f <= u0) {
            u0 -= 1.0f;
            u1 -= 1.0f;
        }
        q1.uv[0][0] = u0;
        q1.uv[1][0] = u0;
        q1.uv[2][0] = u1;
        q1.uv[3][0] = u1;
        q0.p[0] = q0.p[2];
        q0.p[1] = q0.p[3];
        q1.p[0] = q1.p[2];
        q1.p[1] = q1.p[3];
    }
}
/* localdecomp:end func_L05_0036C2F0 */
