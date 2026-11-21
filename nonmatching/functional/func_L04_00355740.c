/* functional: medium. Written from the PAL asm only. Draws three quads (a scrolling-texture beam plus two overlays) and a point glow. Differs from retail: vector helpers leave the w lane of results unspecified where retail's vadd.xyz/vsub.xyz keep the destination register's old w (w is not consumed by the quad submit); the unused first and fifth (f12) arguments are kept for the signature. */
#include "common.h"
#include "vu0.h"

/* plain-C stand-ins for the vector library's xyz add/sub (w taken from the first operand) */
static void vadd(vu0_v4 *d, const vu0_v4 *a, const vu0_v4 *b) {
    vu0_v4 r;
    r.x = a->x + b->x; r.y = a->y + b->y; r.z = a->z + b->z; r.w = a->w;
    *d = r;
}
static void vsub(vu0_v4 *d, const vu0_v4 *a, const vu0_v4 *b) {
    vu0_v4 r;
    r.x = a->x - b->x; r.y = a->y - b->y; r.z = a->z - b->z; r.w = a->w;
    *d = r;
}

typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_355740;

extern vu0_v4 D_L04_001E27C0;
extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L04_00355740(void *unused, s32 c1, s32 c2, u8 *o, f32 unused_f) {
    Q_355740 q;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0;
    u8 *s = *(u8 **)(o + 0x68);
    u8 *pos = o + 0x10;
    f32 t;
    f32 *u;
    s32 i;

    func_L01_0034D840(&q);
    func_003D93B0(&q, 0x2F, 0, 0x80);
    q.col[0] = -1;
    q.col[1] = -1;
    q.col[2] = 0x40FFFFFF;
    q.col[3] = 0x40FFFFFF;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    for (i = 3; i >= 0; i--) {
        u = &q.uv[i][0];
        t = *u - *(f32 *)(s + 0x28);
        *u = t;
        if (t <= 7.0f) {
            *u = t + 7.0f;
        }
    }
    t = *(f32 *)(s + 0x28) + 0.1f;
    *(f32 *)(s + 0x28) = t;
    if (4.0f <= t) {
        *(f32 *)(s + 0x28) = t - 4.0f;
    }
    func_0038CF68(&v90, s, -0.17f);
    vadd(&v90, (vu0_v4 *)pos, &v90);
    vE0 = D_L04_001E27C0;
    vsub(&vA0, (vu0_v4 *)pos, &vE0);
    if (s[0x34] != 0 && *(f32 *)(s + 0x38) < 4.0f) {
        func_0038CF68(&vB0, s, -*(f32 *)(s + 0x38));
    } else {
        func_0038CF68(&vB0, s, -4.0f);
    }
    vadd(&vC0, &v90, &vB0);
    func_0038CE90(&vD0, &vA0, &vB0);
    func_0038CF68(&vD0, &vD0, 0.1f);
    vadd(&q.v[0], (vu0_v4 *)pos, &vD0);
    vsub(&q.v[1], (vu0_v4 *)pos, &vD0);
    vadd(&q.v[2], &vC0, &vD0);
    vsub(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    {
        u32 c2_ = q.col[2], c3_ = q.col[3];
        vu0_v4 t2 = q.v[2], t3 = q.v[3];
        q.col[0] = c2_;
        q.col[1] = c3_;
        q.col[2] = 0x801010;
        q.v[0] = t2;
        q.col[3] = 0x801010;
        q.v[1] = t3;
    }
    vadd(&q.v[2], &q.v[2], &vB0);
    vadd(&q.v[3], &q.v[3], &vB0);
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0x29, 1, 0x80);
    q.col[1] = c1;
    q.col[0] = c1;
    q.col[3] = c2;
    q.col[2] = c2;
    q.uv[3][1] = 1.0f;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    func_0038CF68(&vD0, &vD0, 0.2f);
    vadd(&q.v[0], (vu0_v4 *)pos, &vD0);
    vE0 = *(vu0_v4 *)pos;
    vsub(&q.v[1], (vu0_v4 *)pos, &vD0);
    vadd(&vC0, &vE0, &vB0);
    vadd(&vC0, &vC0, &vB0);
    vadd(&q.v[2], &vC0, &vD0);
    vsub(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    func_0038CF68(&vD0, &vD0, 0.4f);
    q.col[0] = c1;
    q.col[2] = c2;
    q.col[1] = c1;
    q.col[3] = c2;
    func_0038CF68(&v90, s, -0.1f);
    vadd(&v90, (vu0_v4 *)pos, &v90);
    vadd(&q.v[0], &v90, &vD0);
    vsub(&q.v[1], &v90, &vD0);
    vadd(&vC0, &v90, &vB0);
    vadd(&vC0, &vC0, &vB0);
    vadd(&q.v[2], &vC0, &vD0);
    vsub(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    func_003D9508(pos, 0x13, 0x60804020, 1, 0.3f, 0.08f, func_00382538());
}
