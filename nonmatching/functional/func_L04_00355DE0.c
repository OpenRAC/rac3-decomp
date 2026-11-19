/* functional: medium. Written from the PAL asm only, shaped like the matched func_L36_0037CF50 (the same billboard-quad routine; this copy takes the position first and re-submits the quad with a second GS setup; the fifth float argument is unused by retail). Differs from retail: xyz vector add/sub are plain C helpers (file flags lack -mvu0-use-vf0-vf2) that keep the w lane of the first operand where retail keeps the destination register old w (unused by the quad submit). */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_355DE0;

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

extern s32 D_001D52F0;
extern u8 D_L04_001E2840[];
extern vu0_v4 D_L04_001D7AD0[4];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L04_00355DE0(void *posp, s32 tex, f32 size, f32 lift, f32 roll, f32 unused, f32 jitter, s32 shrink) {
    u8 *pos = posp;
    Q_355DE0 q;
    vu0_v4 d, e, f, z, c, t, p;
    u8 *tab;
    s32 i, j;

    func_003D93B0(&q, tex, 1, 0x80);
    tab = D_L04_001E2840 + D_001D52F0 * 0x460;
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)pos;
    q.col[0] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[3] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vsub(&d, (vu0_v4 *)tab, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, tab + 0x1D0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    if (roll != 0.0f) {
        *(vu0_q *)&z = 0;
        z.x = roll;
        func_0038D308(&c, &z);
        func_0038D5F0(&d, &d, &c);
    }
    func_0038CE20(&z, &d, lift);
    vadd(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L04_001D7AD0[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    if (shrink != 0) {
        c = q.v[0];
        for (i = 1; i < 4; i++) {
            vadd(&c, &c, &q.v[i]);
        }
        func_0038CE20(&c, &c, 0.25f);
        for (j = 0; j < 4; j++) {
            vsub(&t, &q.v[j], &c);
            func_0038CE20(&t, &t, 0.8f);
            vadd(&t, &c, &t);
            func_00389478(&t, &q.uv[j][0], &q.uv[j][1]);
            if (func_00382468(1) == 0) {
                q.uv[j][0] += func_003824E0(-jitter, jitter);
                q.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[j][0]) q.uv[j][0] = 1.0f; else if (q.uv[j][0] < 0.0f) q.uv[j][0] = 0.0f;
            if (1.0f < q.uv[j][1]) q.uv[j][1] = 1.0f; else if (q.uv[j][1] < 0.0f) q.uv[j][1] = 0.0f;
        }
    } else {
        for (j = 0; j < 4; j++) {
            func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
            if (func_00382468(1) == 0) {
                q.uv[j][0] += func_003824E0(-jitter, jitter);
                q.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[j][0]) q.uv[j][0] = 1.0f; else if (q.uv[j][0] < 0.0f) q.uv[j][0] = 0.0f;
            if (1.0f < q.uv[j][1]) q.uv[j][1] = 1.0f; else if (q.uv[j][1] < 0.0f) q.uv[j][1] = 0.0f;
        }
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x54;
    func_003A9440(0x47, 0x33001);
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
