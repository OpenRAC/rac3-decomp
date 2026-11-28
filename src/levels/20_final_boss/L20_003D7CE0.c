#include "common.h"
#include "vu0.h"

/* declared by functions of L20_003D6F30.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_003A9440(s32 reg, long value);
extern f32 D_L20_001E2E00[];

/* localdecomp:start func_L20_003D7CE0 */

typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    f32 uv[4][2];
    u8 p70[0x20];
} Q_003D7CE0;

void func_L20_003D7CE0(vu0_v4 *pts, s32 n, s32 texA, s32 texB, s32 c0, s32 c1, s32 c2, s32 c3,
                       s32 start, s32 end, s32 cnt, f32 w0, f32 w1, f32 w2) {
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_0038CEA8(void *);
    Q_003D7CE0 q0;
    Q_003D7CE0 q1;
    vu0_v4 X;
    vu0_v4 Y;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 E;
    vu0_v4 F;
    vu0_v4 S;
    vu0_v4 R;
    vu0_v4 H;
    vu0_v4 T1;
    vu0_v4 T2;
    vu0_v4 G;
    s32 cur;
    s32 prev;
    s32 next;
    s32 col;
    f32 t;
    f32 step;
    f32 lp;
    f32 lc;

    func_003D93B0(&q0, texA, 1, 0x80);
    q0.col[3] = c1;
    q0.col[2] = c1;
    q0.col[1] = c1;
    q0.col[0] = c1;
    q0.uv[0][0] = 0.0f;
    q0.uv[0][1] = 0.0f;
    q0.uv[1][0] = 0.0f;
    q0.uv[1][1] = 1.0f;
    q0.uv[2][0] = 1.0f;
    q0.uv[2][1] = 0.0f;
    q0.uv[3][0] = 1.0f;
    q0.uv[3][1] = 1.0f;
    func_003D93B0(&q1, texB, 1, 0x80);
    q1.col[3] = c3;
    q1.col[2] = c3;
    q1.col[1] = c3;
    q1.col[0] = c3;
    q1.uv[0][0] = 0.0f;
    q1.uv[0][1] = 0.0f;
    q1.uv[1][0] = 0.0f;
    q1.uv[1][1] = 1.0f;
    q1.uv[2][0] = 1.0f;
    q1.uv[2][1] = 0.0f;
    q1.uv[3][0] = 1.0f;
    q1.uv[3][1] = 1.0f;

    next = (start + 1) % n;
    vec_sub_ba(&A, &pts[start], D_L20_001E2E00);
    vec_sub_ba(&B, &pts[next], &pts[start]);
    func_0038CE90(&X, &B, &A);
    func_0038CF68(&X, &X, w0);
    step = 1.0f / (f32)(cnt - 1);
    vec_add_ba(&q0.v[0], &pts[start], &X);
    vec_sub_ba(&q0.v[1], &pts[start], &X);
    t = step;
    prev = start;
    for (cur = next; cur != end; cur = (cur + 1) % n) {
        vec_sub_ab(&A, &pts[cur], D_L20_001E2E00);
        vec_sub_ab(&B, &pts[cur], &pts[prev]);
        func_0038CE90(&X, &B, &A);
        func_0038CF68(&X, &X, w0);
        vec_add_ba(&q0.v[2], &pts[cur], &X);
        vec_sub_ab(&q0.v[3], &pts[cur], &X);
        col = func_0038DBD8(c1, c0, t);
        t += step;
        q0.col[3] = col;
        q0.col[2] = col;
        func_003D2DA0(&q0, 0, 0);
        prev = cur;
        q0.v[0] = q0.v[2];
        q0.v[1] = q0.v[3];
        q0.col[1] = q0.col[2];
        q0.col[0] = q0.col[2];
    }

    vec_sub_ba(&R, &pts[start], D_L20_001E2E00);
    t = step;
    lp = func_0038CEA8(&R);
    for (cur = next; cur != end; cur = (cur + 1) % n) {
        vec_sub_ba(&S, &pts[cur], D_L20_001E2E00);
        lc = func_0038CEA8(&S);
        if (lp < lc) {
            if (lp == 0.0f) {
                T1 = S;
            } else {
                func_0038CE20(&T1, &R, lc / lp);
            }
            vec_add_ba(&E, D_L20_001E2E00, &S);
            vec_add_ab(&F, D_L20_001E2E00, &T1);
        } else {
            if (lc == 0.0f) {
                T2 = R;
            } else {
                func_0038CE20(&T2, &S, lp / lc);
            }
            vec_add_ba(&E, D_L20_001E2E00, &T2);
            vec_add_ab(&F, D_L20_001E2E00, &R);
        }
        vec_sub_ab(&B, &F, &E);
        lp = lc;
        func_0038CE20(&G, &B, w2);
        vec_sub_ab(&E, &E, &G);
        vec_add_ab(&F, &F, &G);
        vec_sub_ab(&H, D_L20_001E2E00, &E);
        func_0038CE90(&X, &H, &B);
        func_0038CF68(&Y, &X, w1);
        vec_add_ab(&q1.v[0], &E, &Y);
        vec_sub_ab(&q1.v[1], &E, &Y);
        vec_add_ba(&q1.v[2], &F, &Y);
        vec_sub_ab(&q1.v[3], &F, &Y);
        col = func_0038DBD8(c3, c2, t);
        t += step;
        q1.col[3] = col;
        q1.col[2] = col;
        func_003D2DA0(&q1, 0, 0);
        R = S;
        q1.col[1] = q1.col[2];
        q1.col[0] = q1.col[2];
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003D7CE0 */
