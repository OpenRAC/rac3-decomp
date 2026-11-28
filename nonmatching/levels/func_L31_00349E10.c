/* Fix pass (2026-11-28, Claude Opus): in the sched2 dump of the join block the p->f14 load (insn 257) depends on
 * the m->v10[0] store (252: two incoming pointers, which may alias), so it waits from t=7 to t=9 and li.s 128.0f
 * (276) takes the memory slot at t=8. Retail issues the load in the cycle right after the store, as if the two did
 * not alias (only the $f0 anti-dependence). -fstrict-aliasing / -fargument-noalias do not give it (85 / 128 diff). */
/* Wave 14c c52 (2026-11-28): 5 raw differences (was 23) under the existing line
 * '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (L31_0034A740.c), at L31 and L36
 * (tools/check.py --flags '-mvu0-use-vf0-vf2 @ps2as', wc52/func_L31_00349E10/p1-31.log, p1-36.log); cut
 * 0x00349E10-0x0034A0F8 (L36 0x0034B270-0x0034B558), divs row func_L31_00349E10 2 2 2 0 0 (committed).
 * Changed against the existing draft: the callee prototype. func_L03_0034B148 is f32 (s32, s32, f32) (its matched
 * definition in L03_0034B128.c); retail passes m->hA in $a0 (the lh at +0x1B4 feeds both the alpha and the call)
 * and p->h8 in $a1 (the lh at +0x220 feeds both `hi` and the call). With the one-argument prototype the join block's
 * loads and registers were wrong (the 17 aligned words of the old note); with the real arguments the whole join's
 * registers and load order match. Left: retail issues the p->f14 load before li.s 128.0f and the v10[2] add before
 * the hA*128 mul (sched2 puts li.s 128.0 in the memory slot at the cycle after the v10[0] store; retail leaves that
 * slot empty). Tried without effect: -fno-sched-interblock / -fno-gcse / split-address variants of the line, s16 and
 * s32 locals for hA, a const view of p->f14, two 600 s permuter runs (21563 and 15849 candidates). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_00349E10 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[4];
    f32 f18;
    u8 pad1C[0x38];
    f32 f54;
} V_00349E10;
typedef struct {
    u8 pad0[0x10];
    f32 x10;
    f32 y14;
    f32 z18;
    u8 pad1C[0x4C];
    V_00349E10 *w68;
} O_00349E10;
typedef struct {
    O_00349E10 *owner;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 padC[2];
    u16 hE;
    f32 f10;
    f32 f14;
} P_00349E10;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    f32 v10[4];
} M_00349E10;
__asm__(".extern D_L31_001DD0F8, 4");
__asm__(".extern D_L31_001DD0FC, 4");
__asm__(".extern D_L31_001DD100, 4");
__asm__(".extern D_L31_001DD104, 4");
__asm__(".extern D_L31_001DD108, 4");
__asm__(".extern D_L31_001DD10C, 4");
__asm__(".extern D_L31_001DD110, 4");
__asm__(".extern D_L31_001DD114, 4");
extern f32 D_L31_001DD0F8;
extern f32 D_L31_001DD0FC;
extern f32 D_L31_001DD100;
extern f32 D_L31_001DD104;
extern f32 D_L31_001DD108;
extern f32 D_L31_001DD10C;
extern s32 D_L31_001DD110;
extern s32 D_L31_001DD114;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_L31_00349D18(void *, f32 *, f32 *, f32);

void func_L31_00349E10(M_00349E10 *m, P_00349E10 *p) {
    O_00349E10 *o;
    V_00349E10 *ov;
    f32 v[4] __attribute__((aligned(16)));
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 zero;
    f32 one;
    f32 ang;
    f32 rad;
    f32 t;
    f32 dx;
    f32 dz;
    f32 lo;
    f32 hi;
    s32 n;

    if (p == 0) {
        return;
    }
    o = p->owner;
    n = p->w4;
    ov = o->w68;
    if (o == 0) {
        return;
    }
    if (n == 0) {
        return;
    }
    if (p->hA & 1) {
        zero = 0.0f;
        one = 1.0f;
        ang = func_0038DB48(func_003824E0(zero, 6.2831855f));
        rad = D_L31_001DD0F8 * func_003824E0(zero, one);
        *(vu0_q *)m->v10 = *(vu0_q *)&o->x10;
        v[0] = func_0038D098(ang) * rad;
        v[2] = func_0038D0B0(ang) * rad;
        v[1] = zero;
        vec_add_ab(m->v10, m->v10, v);
        func_L31_00349D18(o, w1, w2, ov->f54);
        dx = o->x10 - w1[0];
        p->f10 = dx * D_L31_001DD104;
        dz = o->z18 - w1[2];
        p->f14 = dz * D_L31_001DD104;
        t = D_L31_001DD108 * rad;
        t = t / D_L31_001DD0F8;
        one = one - t;
        p->h8 = (s32)((f32)p->h8 * one);
        m->hA = (s32)((f32)m->hA * one);
        rad = rad / D_L31_001DD0F8;
        m->w4 = func_0038DBD8(D_L31_001DD110, D_L31_001DD114, sqrt_asm(rad));
    }
    m->v10[0] += p->f10;
    m->v10[2] += p->f14;
    m->w4 = (m->w4 & 0xFFFFFF) | ((s32)((f32)m->hA * 128.0f / (f32)p->h8) << 24);
    lo = (f32)(p->hE & 0xFF);
    hi = lo + D_L31_001DD10C * (f32)p->h8 * (f32)(p->hE >> 8) * 0.00390625f;
    m->b8 = (s32)func_003C4088(lo, hi, func_L03_0034B148(m->hA, p->h8, 0.0f));
    m->fC = func_003C4088(D_L31_001DD100, D_L31_001DD0FC, (f32)m->hA / (f32)p->h8);
}
/* localdecomp:end func_L31_00349E10 */
