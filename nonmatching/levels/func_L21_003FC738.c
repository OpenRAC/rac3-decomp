/* func_L21_003FC738: 141 diff with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line lacks -mvu0-use-vf0-vf2, which vec_add_* needs). Structure matches. Differs: retail keeps 5 float regs (f24=f0, f23=copy of 1.0 used for q.p[i].w, f20=1.0); mine merges the copy (f20 only, 4 regs, frame 0x160 vs 0x170); retail loads the m[] quads in order a1,t1,a3,por,t0. Tried: one2 = one / one2 = 1.0f, store order of q.c[] (retail emits 0x60,6C,68,64), qzero vs *(vu0_q*)&w = 0 (the latter matches the por). */
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
    f32 one2;
    s32 i;
    u32 c;
    f32 s;

    func_003D93B0(&q, a5, a1, 0x80);
    one = 1.0f;
    c = (func_00382468(a3) + a2) << 24 | a4 << 16 | a4 << 8 | a4;
    *(vu0_q *)&w = 0;
    m[0] = D_L21_001D6C30[0];
    m[1] = D_L21_001D6C30[1];
    m[2] = D_L21_001D6C30[2];
    m[3] = D_L21_001D6C30[3];
    one2 = one;
    w.x = 0.1f;
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
    func_0038D000(&v, &w, D_L21_001E16A0);
    vec_add_ab(&v, &D_L21_001E16A0[-2], &v);
    for (i = 0; i < 4; i++) {
        func_0038CF68(&m[i], &m[i], f2);
        ((f32 *)&m[i])[2] = f1 * ((f32 *)&m[i])[2] + *ptr;
        func_0038D000(&m[i], &m[i], D_L21_001E16A0);
        vec_add_ba(&tmp, &v, &m[i]);
        q.p[i] = tmp;
        ((f32 *)&q.p[i])[3] = one2;
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
