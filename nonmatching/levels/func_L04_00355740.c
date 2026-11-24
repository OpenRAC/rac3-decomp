/* PAL draft (2026-11-21, Promises fleet rac3-w2; retried 2026-11-22 by NM-R10, rac3-w3): func_L04_00355740
 * (1204 B; levels 04 24 26 39-53), written from retail. check.py at level 04 with its file's line
 * (-mvu0-use-vf0-vf2 ... @ps2as): 136 diff (was 233; re-measured 2026-11-23, also 136 with --no-context). Calls, constants and the order of the vector operations
 * follow retail. The colour fields are s32 (u32 gives `lui/ori 0xFFFF` for -1, retail has `addiu -1`: 247 -> 233).
 * The 2026-11-22 retry, each step measured on top of the one before:
 *  - vec_copy(&e, &D_001E27C0) before the func_0038CF68(&a, t, -0.17f) call: the scheduler no longer keeps three
 *    VU0 values live there, one of the two 16-byte spill slots goes (frame 0x180 -> 0x170) and the first half's
 *    vf1/vf2 roles line up with retail: 233 -> 148 (between the call and vec_add_ba it stays 233);
 *  - the second block's col[3] stored before col[2]: 148 -> 146;
 *  - the second block's uv stores in plain order uv[0].u ... uv[3].v: 146 -> 138;
 *  - the third block's colours stored col[3], col[2], col[1], col[0]: 138 -> 136 (all 24 orders tried: 136-138).
 * What still differs: the frame is 0x170, retail's 0x160. vec_copy(&g, o + 0x10) is the last spill: retail loads
 * o + 0x10 for the copy right after storing q.v[0] and stores g at once, where this C's scheduling keeps the copy's
 * value live across vec_sub_ab(&q.v[1], ...) and reload spills it to 0x100($sp). The copy placed before
 * vec_sub_ab (153) or before vec_add_ba (155) moves the spill to another value; before the func_0038CF68(&f, &f,
 * 0.2f) call it goes (frame 0x160) but the copy is then out of place (158). The _ab/_ba choice of those two
 * helpers changes nothing (the loads are reordered freely). Everything after that point is two instructions out of
 * step, and vf1/vf2 are the other way round in most of the later sequences.
 * 2026-11-23 (RT-G, rac3-w3): re-measured at 136. The copy at each of its three places after the 0.2f call
 * (before vec_add_ba(&q.v[0], ...): 143; before vec_sub_ab(&q.v[1], ...): 141; after it: 136), each with all four
 * _ab/_ba choices of the q.v[0]/q.v[1] helpers (no change at any place) and vec_add_ba for d = g + c (no change):
 * the frame stays 0x170 in all 15. Retail's order is lqc2 o + 0x10 for the vsub, sqc2 q.v[0], lqc2 o + 0x10,
 * sqc2 g, lqc2 f, vsub: the copy's store comes before f's load, where this C's sched1 puts it after the vsub's
 * store and reload spills the copied value to 0x100($sp).
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
    vec_copy(&e, &D_001E27C0);
    func_0038CF68(&a, t, -0.17f);
    vec_add_ba(&a, o + 0x10, &a);
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
    q.col[3] = 0x801010;
    q.col[2] = 0x801010;
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
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    func_0038CF68(&f, &f, 0.2f);
    vec_add_ba(&q.v[0], o + 0x10, &f);
    vec_sub_ab(&q.v[1], o + 0x10, &f);
    vec_copy(&g, o + 0x10);
    vec_add_ab(&d, &g, &c);
    vec_add_ba(&d, &d, &c);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[3] = c1;
    q.col[1] = c0;
    q.col[2] = c1;
    q.col[0] = c0;
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
