/* functional: high. Ribbon-trail drawer (two quad strips over a ring buffer of points); written from the disassembly, compiles in the level context and is within 0x10 bytes of retail frame size. PS2 float divide: step = 1/(cnt-1) guarded for cnt==1 (retail yields FLT_MAX). */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Quad_003D7CE0;

extern f32 func_0038CEA8(void *);
extern s32 func_0038DBD8(s32, s32, f32);

/* Draws a ribbon trail through the ring buffer of points `pts` (n entries) from index `start` up to
 * (not including) `end`: first as a strip of width w0 around the path (colour fading c1 -> c0), then,
 * as a second strip, the path projected onto the sphere around the anchor D_L20_001E2E00 with width w1
 * (colour c3 -> c2) and the two edges pushed apart by w2. cnt - 1 is the number of colour steps. */
void func_L20_003D7CE0(void *pp, s32 n, s32 texA, s32 texB, s32 c0, s32 c1, s32 c2, s32 c3,
                       s32 start, s32 end, s32 cnt, f32 w0, f32 w1, f32 w2) {
    vu0_v4 *pts = pp;
    Quad_003D7CE0 q0;
    Quad_003D7CE0 q1;
    vu0_v4 X;
    vu0_v4 Y;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 S;
    vu0_v4 R;
    vu0_v4 E;
    vu0_v4 F;
    vu0_v4 G;
    vu0_v4 H;
    vu0_v4 T;
    vu0_v4 P0;
    vu0_v4 anchor;
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
    vec_sub_ab(&A, &pts[start], D_L20_001E2E00);
    P0 = pts[start];
    vec_sub_ab(&B, &pts[next], &P0);
    func_0038CE90(&X, &B, &A);
    func_0038CF68(&X, &X, w0);
    /* retail divides by (cnt - 1) as a PS2 float: x / 0 is the largest float, not Inf */
    step = (cnt != 1) ? 1.0f / (f32)(cnt - 1) : 3.4028235e38f;
    vec_add_ab(&q0.v[0], &pts[start], &X);
    vec_sub_ab(&q0.v[1], &pts[start], &X);
    t = step;
    prev = start;
    cur = next;
    while (cur != end) {
        vec_sub_ab(&A, &pts[cur], D_L20_001E2E00);
        vec_sub_ab(&B, &pts[cur], &pts[prev]);
        func_0038CE90(&X, &B, &A);
        func_0038CF68(&X, &X, w0);
        vec_add_ab(&q0.v[2], &pts[cur], &X);
        vec_sub_ab(&q0.v[3], &pts[cur], &X);
        col = func_0038DBD8(c1, c0, t);
        t += step;
        q0.col[3] = col;
        q0.col[2] = col;
        func_003D2DA0(&q0, 0, 0);
        prev = cur;
        q0.v[1] = q0.v[3];
        q0.v[0] = q0.v[2];
        q0.col[0] = q0.col[2];
        q0.col[1] = q0.col[2];
        cur = (cur + 1) % n;
    }

    vec_sub_ab(&R, &pts[start], D_L20_001E2E00);
    t = step;
    cur = next;
    lp = func_0038CEA8(&R);
    while (cur != end) {
        vec_sub_ab(&S, &pts[cur], D_L20_001E2E00);
        lc = func_0038CEA8(&S);
        if (lp < lc) {
            if (lp == 0.0f) {
                T = S;
            } else {
                func_0038CE20(&T, &R, lc / lp);
            }
            vec_add_ab(&E, D_L20_001E2E00, &S);
            vec_add_ab(&F, D_L20_001E2E00, &T);
        } else {
            if (lc == 0.0f) {
                T = R;
            } else {
                func_0038CE20(&T, &S, lp / lc);
            }
            vec_add_ab(&E, D_L20_001E2E00, &T);
            vec_add_ab(&F, D_L20_001E2E00, &R);
        }
        vec_sub_ab(&B, &F, &E);
        lp = lc;
        func_0038CE20(&G, &B, w2);
        vec_sub_ab(&E, &E, &G);
        anchor = *(vu0_v4 *)D_L20_001E2E00;
        vec_add_ab(&F, &F, &G);
        vec_sub_ab(&H, &anchor, &E);
        func_0038CE90(&X, &H, &B);
        func_0038CF68(&Y, &X, w1);
        vec_add_ab(&q1.v[0], &E, &Y);
        vec_sub_ab(&q1.v[1], &E, &Y);
        vec_add_ab(&q1.v[2], &F, &Y);
        vec_sub_ab(&q1.v[3], &F, &Y);
        col = func_0038DBD8(c3, c2, t);
        t += step;
        q1.col[2] = col;
        q1.col[3] = col;
        func_003D2DA0(&q1, 0, 0);
        R = S;
        q1.col[0] = q1.col[2];
        q1.col[1] = q1.col[2];
        cur = (cur + 1) % n;
    }
    func_003A9440(0x47, 0x5360B);
}
