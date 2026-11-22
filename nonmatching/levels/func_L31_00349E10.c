/* PAL near miss (Sonnet round 20, b33 h8): 23 raw / 17 aligned differences of 185 words (H5b's start: 53 raw / 39 aligned). Checks with
 *   python tools/check.py nonmatching/levels/func_L31_00349E10.c func_L31_00349E10 --no-context --as ps2as --flags=-mvu0-use-vf0-vf2
 * and needs (not committed: only a match may cut): its own file L31_00349E10.c (flags `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`, cut at 0x00349E10 / 0x0034B270,
 * both 8-aligned, the old file keeps func_L31_00349DD0 only, `#include "vu0.h"` in the prelude) and the divs_nops row `func_L31_00349E10 2 2 2 0 0` (committed with this draft).
 * Particle update (M = particle record, P = emitter descriptor, O = owner moby). The lever of this round (39 -> 17 aligned in one edit): in the init arm after func_L31_00349D18
 * the two position deltas come FIRST (`dx = o->x - w1[0]; p->f10 = dx * D104; dz = o->z - w1[2]; p->f14 = dz * D104;`), then the factor chain (`t = D108 * rad; t = t / D0F8; one = one - t;
 * p->h8 = ..*one; m->hA = ..*one`), and `rad / D0F8` LAST as the sqrt argument: with `p->h8 = ...` stored before `dz = o->z - ...` the o->z load is alias-gated behind that store (no
 * strict aliasing: every pointer-based struct access conflicts), the chain through the arm raises D0F8's load priority to 44 (above o->x 28 / w1[0] 25) and retail's load order
 * D108, w1[0], o->x, D0F8, D104, h8, w1[2] with the `t / D0F8` div before `rad / D0F8` is lost. The whole arm and the prologue match now.
 * Left (17 aligned words, all in the join block after the arm): retail loads m->hA, D10C, m->w4 (in that order, into $a0 / $f20 / $v1, the 0xFFFFFF mask in $v0) before the first
 * `swc1 v10[0]` and puts the 128.0f and 1/256 constants after the p->f14 load; ours loads D10C first, the 128.0f constant (sched1 priority 56 against the w4 load's 44: the whole
 * hA*128/h8 -> sll -> or -> sw w4 -> lhu hE chain is alias-gated) early, and w4 after the store; then the registers (mask $v1, hA $v0, w4 $a0, h8 $v1) follow. The sched1 / sched2 tables
 * (-dS -dR -fsched-verbose-5) show retail needs prio(hA) >= prio(D10C) >= prio(w4) with the 128.0f constant below the p->f14 load, i.e. a shorter chain behind the w4 store than ours
 * (the lhu hE / lh h8 loads of the next statements are alias-dependent on the w4 store in ours). Tried without effect: all 12 orders of m->v10[0] / m->v10[2] / w4 / lo / hi statements,
 * a 36-compile first-improvement climb over a 7-statement tail (the w4 update split into mask / shift / store; its best, 16 aligned, has 32 raw), 6 spellings of the w4 update (all give the same RTL), -fstrict-aliasing
 * (diagnostic only: hoists the hE load, 34 aligned). */
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
extern f32 func_L03_0034B148(f32);
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
    m->b8 = (s32)func_003C4088(lo, hi, func_L03_0034B148(0.0f));
    m->fC = func_003C4088(D_L31_001DD100, D_L31_001DD0FC, (f32)m->hA / (f32)p->h8);
}
/* localdecomp:end func_L31_00349E10 */
