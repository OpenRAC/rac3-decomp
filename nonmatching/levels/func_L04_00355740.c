/* PAL draft (2026-11-21, Promises fleet rac3-w2): func_L04_00355740 (1204 B; levels 04 24 26 39-53), written
 * from retail. check.py at level 04 with its file's line (-mvu0-use-vf0-vf2 ... @ps2as): 233 diff. Calls,
 * constants and the order of the vector operations follow retail. What differs: the frame is 0x180, retail's
 * 0x160, because the scheduler interleaves the vu0.h helper asm statements so that three VU0 values are live
 * and reload spills one to two extra 16-byte slots (0x100/0x110($sp)); and vf1/vf2 roles are flipped against
 * retail in most sequences (retail's first sequence loads a into $vf1, this C into $vf2). The colour fields
 * are s32 (u32 gives `lui/ori 0xFFFF` for -1, retail has `addiu -1`: 247 -> 233). #2735's 231-diff first draft
 * was not committed; this one is new.
 */
#include "common.h"
#include "vu0.h"

typedef struct { f32 u, v; } UV_355740;
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_355740 uv[4];
    long x70, x78, x80, x88;
} Q_355740;

extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern vu0_v4 D_001E27C0;

void func_L04_00355740(void *unused, u32 c0, u32 c1, u8 *o) {
    Q_355740 q;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 f;
    vu0_v4 e;
    vu0_v4 g;
    u8 *t;
    s32 i;

    t = *(u8 **)(o + 0x68);
    func_L01_0034D840(&q);
    func_003D93B0(&q, 0x2F, 0, 0x80);
    q.col[3] = 0x40FFFFFF;
    q.col[2] = 0x40FFFFFF;
    q.col[1] = -1;
    q.col[0] = -1;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(t + 0x28);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    *(f32 *)(t + 0x28) += 0.1f;
    if (4.0f <= *(f32 *)(t + 0x28)) {
        *(f32 *)(t + 0x28) -= 4.0f;
    }
    func_0038CF68(&a, t, -0.17f);
    vec_add_ba(&a, o + 0x10, &a);
    vec_copy(&e, &D_001E27C0);
    vec_sub_ab(&b, o + 0x10, &e);
    if (t[0x34] != 0 && *(f32 *)(t + 0x38) < 4.0f) {
        func_0038CF68(&c, t, -*(f32 *)(t + 0x38));
    } else {
        func_0038CF68(&c, t, -4.0f);
    }
    vec_add_ba(&d, &a, &c);
    func_0038CE90(&f, &b, &c);
    func_0038CF68(&f, &f, 0.1f);
    vec_add_ba(&q.v[0], o + 0x10, &f);
    vec_sub_ab(&q.v[1], o + 0x10, &f);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ba(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[0] = q.col[2];
    q.col[1] = q.col[3];
    q.col[2] = 0x801010;
    q.col[3] = 0x801010;
    *(vu0_q *)&q.v[0] = *(vu0_q *)&q.v[2];
    *(vu0_q *)&q.v[1] = *(vu0_q *)&q.v[3];
    vec_add_ba(&q.v[2], &q.v[2], &c);
    vec_add_ba(&q.v[3], &q.v[3], &c);
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0x29, 1, 0x80);
    q.col[1] = c0;
    q.col[0] = c0;
    q.col[3] = c1;
    q.col[2] = c1;
    q.uv[3].v = 1.0f;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    func_0038CF68(&f, &f, 0.2f);
    vec_add_ba(&q.v[0], o + 0x10, &f);
    vec_sub_ab(&q.v[1], o + 0x10, &f);
    vec_copy(&g, o + 0x10);
    vec_add_ab(&d, &g, &c);
    vec_add_ba(&d, &d, &c);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[0] = c0;
    q.col[2] = c1;
    q.col[1] = c0;
    q.col[3] = c1;
    func_0038CF68(&f, &f, 0.4f);
    func_0038CF68(&a, t, -0.1f);
    vec_add_ba(&a, o + 0x10, &a);
    vec_add_ba(&q.v[0], &a, &f);
    vec_sub_ba(&q.v[1], &a, &f);
    vec_add_ba(&d, &a, &c);
    vec_add_ba(&d, &d, &c);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    func_003D9508(o + 0x10, 0x13, 0x60804020, 1, 0.3f, 0.08f, func_00382538());
}
