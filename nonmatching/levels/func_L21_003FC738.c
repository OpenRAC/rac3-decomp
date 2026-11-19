/* func_L21_003FC738: 13 diff with --flags=-mvu0-use-vf0-vf2 on the file's line (-O2 -G8 -fopt-stack -mno-check-zero-division; the line lacks -mvu0-use-vf0-vf2, which vec_add_* needs). Frame 0x170 and every float register match.
 * What fixed it (141 to 13): (1) the .w store of the loop is a literal 1.0f (the loop-invariant copy `mov.s $f23,$f20` becomes the fifth float register; the old one2 copy was merged by cse); (2) the global's address in a local pointer `dp` used only by the first func_0038D000 call and the vec_add_ab read (retail keeps that full address in its own register); (3) statement order M0, w.x, M1, M2, M3 (120 orders tried); (4) m[i].z and q.p[i].w written as struct members instead of f32 casts.
 * Left (13): four setup instructions around `sq $a0,0xb0($sp)` (retail loads m[2] into $t0 before that store and copies $f20 to $f23 before `move $a0,$sp`), and the loop's address registers: retail has s0 = &m[i] (calls, m[i].z), s1 = &q.p[i].w stored through `($s1)`, s2 = &q.p[i] with the vadd reading m[i] as 0xa0($s2); this C keeps s0 = &m[i], a second copy s1 = &m[i] for the vadd and stores the w through 0xc($s2). Tried without gain: explicit pointer locals mp/qp/wp in every combination (59 to 152), the w store as (&q.p[0].w)[i*4] / ((f32 *)q.p)[i*4+3] (14), mp = &m[i] per iteration (13). */
#include "common.h"

#include "vu0.h"
extern s32 func_00382468(s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);
extern vu0_v4 D_L21_001E16A0[];
extern vu0_v4 D_L21_001D6C30[];

typedef struct {
    vu0_v4 p[4];
    u32 c[4];
    f32 uv[8];
    u8 pad[0x10];
} L21_Q;

void func_L21_003FC738(f32 f0, f32 f1, f32 f2, f32 *ptr, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    vu0_v4 v;
    vu0_v4 tmp;
    L21_Q q;
    vu0_v4 pad;
    vu0_v4 w;
    vu0_v4 m[4];
    f32 one;
    s32 i;
    u32 c;
    f32 s;
    vu0_v4 *dp;

    func_003D93B0(&q, a5, a1, 0x80);
    one = 1.0f;
    c = (func_00382468(a3) + a2) << 24 | a4 << 16 | a4 << 8 | a4;
    *(vu0_q *)&w = 0;
    m[0] = D_L21_001D6C30[0];
    w.x = 0.1f;
    m[1] = D_L21_001D6C30[1];
    m[2] = D_L21_001D6C30[2];
    m[3] = D_L21_001D6C30[3];
    q.c[3] = c;
    q.c[2] = c;
    q.c[1] = c;
    q.c[0] = c;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = one;
    q.uv[4] = one;
    q.uv[5] = 0.0f;
    q.uv[6] = one;
    q.uv[7] = one;
    dp = D_L21_001E16A0;
    func_0038D000(&v, &w, dp);
    vec_add_ab(&v, &dp[-2], &v);
    for (i = 0; i < 4; i++) {
        func_0038CF68(&m[i], &m[i], f2);
        m[i].z = f1 * m[i].z + *ptr;
        func_0038D000(&m[i], &m[i], D_L21_001E16A0);
        vec_add_ba(&tmp, &v, &m[i]);
        q.p[i] = tmp;
        q.p[i].w = 1.0f;
    }
    s = *ptr + f0;
    *ptr = s;
    if (s >= 0.05f) {
        *ptr = s - 0.1f;
    } else if (s <= -0.05f) {
        *ptr = s + 0.1f;
    }
    func_003D2DA0(&q, 0, 0);
}

INCLUDE_ASM("asm/levels", func_L21_003FC738);
