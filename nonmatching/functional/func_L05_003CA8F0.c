/* functional: medium. Effect beam renderer (two layered ribbon strips along a segment, scrolled UVs, 3+2 draw calls). Re-derived from PAL asm, VU0 vadd/vsub.xyz written as plain float helpers keeping the first operand's w; D_ names are gp-relative colour/uv globals (gp+0x2548..0x2568) left unnamed; compiles at level_05 (454 diff, bytes only). Draw buffer layout (points 0x00-0x3F, colours 0x40-0x4F, uv floats 0x50-0x6F) inferred from the stores. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V4_3CA8F0;
typedef struct {
    V4_3CA8F0 p[4];
    u32 col[4];
    f32 f[8];
} Quad_3CA8F0;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern vu0_v4 D_L05_001E2680;
extern s32 D_001DEDF8_sda, D_001DEDFC_sda, D_001DEE00_sda, D_001DEE04_sda;
extern f32 D_001DEE08_sda;
extern s32 D_001DEE0C_sda, D_001DEE10_sda, D_001DEE14_sda, D_001DEE18_sda;

/* xyz of a +/- b, w of a (VU0 vadd.xyz / vsub.xyz keep the first operand's w) */
static void add3_3CA8F0(V4_3CA8F0 *d, V4_3CA8F0 *a, V4_3CA8F0 *b) {
    d->w = a->w; d->x = a->x + b->x; d->y = a->y + b->y; d->z = a->z + b->z;
}
static void sub3_3CA8F0(V4_3CA8F0 *d, V4_3CA8F0 *a, V4_3CA8F0 *b) {
    d->w = a->w; d->x = a->x - b->x; d->y = a->y - b->y; d->z = a->z - b->z;
}

void func_L05_003CA8F0(u8 *obj) {
    Quad_3CA8F0 q;
    V4_3CA8F0 P, Q, D, W, A, S160, S170, S180, v[8];
    u8 *sub;
    f32 *fp;
    f32 t, k;
    s32 i, c, ca, cb;
    u8 st;

    if (obj == 0) return;
    sub = *(u8 **)(obj + 0x68);
    st = obj[0x20];
    if (st == 0xFE || st == 0xFD) return;
    if (sub == 0) return;

    P = *(V4_3CA8F0 *)(obj + 0x10);
    if (*(s32 *)(sub + 0x30) != 0) {
        Q = *(V4_3CA8F0 *)(sub + 0x10);
        sub3_3CA8F0(&D, &Q, &P);
    } else {
        func_0038CF68(&D, sub, *(f32 *)(sub + 0x20));
        add3_3CA8F0(&Q, &P, &D);
    }
    k = (f32)*(s32 *)(sub + 0x24) * *(f32 *)(sub + 0x28);

    func_003D93B0(&q, 0x17, 0, 0x80);
    c = (s32)(k * 64.0f) << 24;
    q.f[0] = 0.0f; q.f[1] = 0.0f; q.f[2] = 0.0f;   /* 0x50,0x54,0x58 */
    q.f[3] = 1.0f; q.f[4] = 1.0f;                  /* 0x5C,0x60 */
    q.f[5] = 0.0f; q.f[6] = 1.0f; q.f[7] = 1.0f;   /* 0x64,0x68,0x6C */
    q.col[2] = c | 0x101080;
    q.col[0] = c | 0x108080;
    q.col[1] = c | 0x108080;
    q.col[3] = c | 0x101080;
    fp = &q.f[0];
    for (i = 3; i >= 0; i--) {
        t = *fp - *(f32 *)(sub + 0x2C);
        *fp = t;
        if (t <= 7.0f) *fp = t + 7.0f;
        fp += 2;
    }
    t = *(f32 *)(sub + 0x2C) + 0.1f;
    *(f32 *)(sub + 0x2C) = t;
    if (4.0f <= t) *(f32 *)(sub + 0x2C) = t - 4.0f;

    {
        V4_3CA8F0 ref = *(V4_3CA8F0 *)&D_L05_001E2680;
        sub3_3CA8F0(&W, &P, &ref);
    }
    func_0038CE90(&A, &W, &D);
    func_0038CF68(&A, &A, 1.0f);
    func_0038CE20(&S160, &D, D_001DEE08_sda);
    func_0038CE20(&S170, &D, 1.0f - D_001DEE08_sda);
    func_0038CE20(&S180, &D, 0.5f);
    add3_3CA8F0(&S160, &S160, &P);
    add3_3CA8F0(&S170, &S170, &P);
    add3_3CA8F0(&S180, &S180, &P);
    add3_3CA8F0(&v[0], &P, &A);
    sub3_3CA8F0(&v[1], &P, &A);
    add3_3CA8F0(&v[2], &S160, &A);
    sub3_3CA8F0(&v[3], &S160, &A);
    add3_3CA8F0(&v[4], &S170, &A);
    sub3_3CA8F0(&v[5], &S170, &A);
    add3_3CA8F0(&v[6], &Q, &A);
    sub3_3CA8F0(&v[7], &Q, &A);

    cb = (D_001DEE00_sda << 16) | (D_001DEDFC_sda << 8) | D_001DEDF8_sda;
    ca = (D_001DEE04_sda << 24) | cb;
    q.p[0] = v[0]; q.p[1] = v[1]; q.p[2] = v[2]; q.p[3] = v[3];
    q.col[1] = cb; q.col[3] = ca; q.col[0] = cb; q.col[2] = ca;
    func_003D2DA0(&q, 0, 0);

    q.p[0] = v[4]; q.p[1] = v[5];
    q.col[1] = ca; q.col[0] = ca;
    func_003D2DA0(&q, 0, 0);

    q.p[3] = v[7]; q.p[2] = v[6];
    q.col[3] = cb; q.col[2] = cb;
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, 1, 0x80);
    c = ((s32)(k * 64.0f) << 24) | 0x40FF;
    q.f[0] = 0.0f; q.f[1] = 0.0f; q.f[2] = 0.0f;
    q.f[3] = 1.0f; q.f[4] = 1.0f;
    q.f[5] = 0.0f; q.f[6] = 1.0f; q.f[7] = 1.0f;
    q.col[0] = c; q.col[3] = c; q.col[2] = c; q.col[1] = c;
    func_0038CF68(&A, &A, 2.0f);
    add3_3CA8F0(&v[0], &P, &A);
    sub3_3CA8F0(&v[1], &P, &A);
    add3_3CA8F0(&v[2], &S180, &A);
    sub3_3CA8F0(&v[3], &S180, &A);
    add3_3CA8F0(&v[4], &Q, &A);
    sub3_3CA8F0(&v[5], &Q, &A);
    cb = (D_001DEE14_sda << 16) | (D_001DEE10_sda << 8) | D_001DEE0C_sda;
    ca = (D_001DEE18_sda << 24) | cb;
    q.p[2] = v[2]; q.p[3] = v[3]; q.p[0] = v[0]; q.p[1] = v[1];
    q.col[1] = cb; q.col[0] = cb; q.col[2] = ca; q.col[3] = ca;
    func_003D2DA0(&q, 0, 0);
    q.p[0] = v[4]; q.p[1] = v[5];
    func_003D2DA0(&q, 0, 0);
}
