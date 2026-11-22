#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_00341218 */
typedef struct {
    vu0_v4 m[4];
    s32 col[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} __attribute__((aligned(16))) Packet_00341218;

extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern long func_00389598(s32);
extern vu0_v4 D_L30_001E2240;
extern void func_003A9440(s32, unsigned long);

void func_L30_00341218(void *pv, s32 a1, s32 a2, f32 w0, f32 w1, f32 k, s32 n, s32 c0, s32 c1) {
    Packet_00341218 q1;
    Packet_00341218 q2;
    vu0_v4 perp;
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 c;
    vu0_v4 s;
    vu0_v4 *p = pv;
    s32 col0;
    s32 col1;
    f32 len;
    f32 m0;
    f32 m1;
    f32 l0;
    f32 l1;
    s32 i;

    q1.x78 = func_00389598(0x14);
    col0 = c0 | (a1 << 24);
    q1.x88 = 0x8000000048L;
    q1.x80 = 0xFF9000000260L;
    q1.x70 = 0;
    q1.col[0] = q1.col[1] = q1.col[2] = q1.col[3] = col0;
    q2.x78 = func_00389598(0x10);
    q2.x88 = q1.x88;
    q2.x80 = q1.x80;
    q2.x70 = q1.x70;
    col1 = c1 | (a2 << 24);
    q2.col[0] = q2.col[1] = q2.col[2] = q2.col[3] = col1;
    q2.uv[0] = 0.0f;
    q2.uv[1] = 0.0f;
    q2.uv[2] = 0.0f;
    q2.uv[3] = 1.0f;
    q2.uv[4] = 1.0f;
    q2.uv[5] = 0.0f;
    q2.uv[6] = 1.0f;
    q2.uv[7] = 1.0f;
    q1.uv[0] = 0.0f;
    q1.uv[1] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[4] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[6] = 1.0f;
    q1.uv[7] = 1.0f;

    vec_sub_ab(&a, &p[0], &D_L30_001E2240);
    vec_sub_ab(&b, &p[1], &p[0]);
    func_0038CE90(&perp, &b, &a);
    m0 = func_0038CEA8(&perp);
    if (m0 != 0.0f) {
        m0 = 1.0f / m0;
    }
    func_0038CE20(&perp, &perp, w0 * m0);
    vec_add_ba(&q1.m[0], &p[0], &perp);
    vec_sub_ab(&q1.m[1], &p[0], &perp);

    for (i = 1; i < n - 1; i++) {
        vec_sub_ab(&a, &p[i], &D_L30_001E2240);
        vec_sub_ab(&b, &p[i + 1], &p[i]);
        func_0038CE90(&perp, &b, &a);
        m1 = func_0038CEA8(&perp);
        if (m1 != 0.0f) {
            m1 = 1.0f / m1;
        }
        func_0038CE20(&perp, &perp, w0 * m1);
        vec_add_ba(&q1.m[2], &p[i], &perp);
        vec_sub_ab(&q1.m[3], &p[i], &perp);
        if (i == 1) {
            q1.col[0] = q1.col[1] = c0;
        } else if (i == 2) {
            q1.col[0] = q1.col[1] = col0;
        }
        func_003D2DA0(&q1, 0, 0);
        q1.m[0] = q1.m[2];
        q1.m[1] = q1.m[3];
    }

    for (i = 0; i < n - 1; i++) {
        vec_sub_ab(&t, &p[i], &D_L30_001E2240);
        vec_sub_ab(&u, &p[i + 1], &D_L30_001E2240);
        l0 = func_0038CEA8(&t);
        l1 = func_0038CEA8(&u);
        if (l1 < l0) {
            if (l1 == 0.0f) {
                u = t;
            } else {
                func_0038CE20(&u, &u, l0 / l1);
            }
        } else {
            if (l0 == 0.0f) {
                t = u;
            } else {
                func_0038CE20(&t, &t, l1 / l0);
            }
        }
        vec_add_ba(&v, &D_L30_001E2240, &t);
        vec_add_ab(&w, &D_L30_001E2240, &u);
        vec_sub_ba(&b, &w, &v);
        func_0038CE20(&s, &b, k);
        vec_sub_ab(&v, &v, &s);
        vec_add_ab(&w, &w, &s);
        vec_sub_ab(&c, &D_L30_001E2240, &v);
        func_0038CE90(&perp, &c, &b);
        len = func_0038CEA8(&perp);
        if (len != 0.0f) {
            len = 1.0f / len;
        }
        func_0038CE20(&r, &perp, w1 * len);
        vec_add_ba(&q2.m[0], &v, &r);
        vec_sub_ab(&q2.m[1], &v, &r);
        vec_add_ba(&q2.m[2], &w, &r);
        vec_sub_ab(&q2.m[3], &w, &r);
        if (i == 0) {
            q2.col[0] = q2.col[1] = c1;
        } else if (i == 1) {
            q2.col[0] = q2.col[1] = col1;
        }
        func_003D2DA0(&q2, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L30_00341218 */
