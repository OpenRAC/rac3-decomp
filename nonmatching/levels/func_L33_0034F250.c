/* func_L33_0034F250 (Claude wave 14 r54, 2026-11-28). Replaces the earlier draft of this function (sonnet-b30-j3b near miss (round 19)). */
/* PAL near miss (r54, wave 14) under the file's own line "-O2 -G8 -fopt-stack -mno-check-zero-division" (147 diff):
 * the cut-line version out/func_L33_0034F250.cut.c (14 diff under "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as" with divs 0 2 2) is the real draft; this one replaces vec_add_ab with the three
 * component adds so that it compiles without -mvu0-use-vf0-vf2. What differs here: retail's lqc2/vadd.xyz/sqc2
 * (VU0 class) and its lui/ori/mtc1 float constants (Ps2EeAs li.s; GNU as gives $gp .lit4 loads), plus the
 * move $a0 / $f4-$f5 difference described in the cut version. */
#include "common.h"
/* localdecomp:start func_L33_0034F250 */
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} P_0034F250;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 padC[2];
    u16 hE;
    u8 pad10[8];
    f32 f18;
    f32 f1C;
} Q_0034F250;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 D_L33_001DD704;
__asm__(".extern D_L33_001DD704, 4");
extern f32 D_L33_001DD700;
__asm__(".extern D_L33_001DD700, 4");
extern f32 D_L33_001DD6F8;
__asm__(".extern D_L33_001DD6F8, 4");
extern s32 D_L33_001DD6C4;
__asm__(".extern D_L33_001DD6C4, 4");
extern s32 D_L33_001DD6C8;
__asm__(".extern D_L33_001DD6C8, 4");
extern s32 D_L33_001DD760;
__asm__(".extern D_L33_001DD760, 4");
extern f32 D_L33_001DD6E8;
__asm__(".extern D_L33_001DD6E8, 4");
extern f32 D_L33_001DD6EC;
__asm__(".extern D_L33_001DD6EC, 4");
extern f32 D_L33_001DD6D4;
__asm__(".extern D_L33_001DD6D4, 4");
extern f32 D_L33_001DD708;
__asm__(".extern D_L33_001DD708, 4");
extern f32 D_L33_001DD6D0;
__asm__(".extern D_L33_001DD6D0, 4");
extern f32 D_L33_001DD6CC;
__asm__(".extern D_L33_001DD6CC, 4");
extern f32 D_L33_001DD6E4;
__asm__(".extern D_L33_001DD6E4, 4");

void func_L33_0034F250(u8 *p_, u8 *q_) {
    P_0034F250 *p = (P_0034F250 *)p_;
    Q_0034F250 *q = (Q_0034F250 *)q_;
    vu0_v4 v;
    vu0_v4 a;
    u8 *m;
    u8 *pv;
    s32 n;
    s32 on;
    s32 n2;

    if (q == 0) return;
    m = q->m;
    pv = *(u8 **)(m + 0x68);
    on = q->w4;
    if (m == 0) return;
    if (on == 0) return;

    if (q->hA & 1) {
        f32 ang1;
        f32 ang2;
        f32 s;

        ang1 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = func_003824E0(D_L33_001DD704, D_L33_001DD700);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(m, 1, &p->pos);
        a.x = func_0038D098(ang2) * D_L33_001DD6F8;
        a.z = func_0038D0B0(ang2) * D_L33_001DD6F8;
        a.y = 0.0f;
        p->pos.x += a.x;
        p->pos.y += a.y;
        p->pos.z += a.z;
        q->f18 = s * func_0038D098(ang1);
        q->f1C = s * func_0038D0B0(ang1);
        p->w4 = func_L30_0034DBA0(D_L33_001DD6C4, D_L33_001DD6C8);
        p->fC = func_003C4088(D_L33_001DD6E8, D_L33_001DD6EC, (f32)*(s32 *)(pv + 0xA8) / (f32)D_L33_001DD760);
    }

    p->pos.x += q->f18;
    q->f1C += D_L33_001DD6D4;
    p->pos.z += q->f1C;
    n = p->hA;
    p->fC *= 1.0f - D_L33_001DD708 * (1.0f - (f32)n / (f32)(n + 1));
    func_L33_00344F88(&v, p->w4);
    n2 = p->hA;
    v.x *= D_L33_001DD6D0;
    v.y *= D_L33_001DD6CC;
    v.w *= (f32)n2 / (f32)(n2 + 1);
    func_L33_003453C8(&p->w4, &v);
    {
        f32 lo = (f32)(q->hE & 0xFF);
        f32 hi = (f32)(q->hE >> 8);
        f32 hi2 = D_L33_001DD6E4 * (f32)q->h8 * hi * 0.00390625f;
        p->b8 = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(p->hA, q->h8, 0.0f));
    }
}
/* localdecomp:end func_L33_0034F250 */

/* The other form the notes name (Claude wave 14 r54, func_L33_0034F250.cut.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* PAL near miss (r54, wave 14), for the cut line "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
 * (the line of the next file L33_0034F530.c; 0x0034F250-0x0034F530 is 8-aligned on both ends) plus the divs row
 * 'func_L33_0034F250 0 2 2'. Changed against the draft: the definition takes (u8 *, u8 *) as the file declares it
 * (the draft's typed parameters conflicted with that declaration) and casts to the typed P/Q structs inside.
 * 14 words differ under that line: retail issues "move $a0, $sp" (&v for func_L33_00344F88) after the pos.x store;
 * our sched1 issues it in the free ALU slot of the join block's first cycle (it has no dependence), which also
 * shortens the 1.0f pseudo's life so local-alloc gives it $f4 and (f32)(n + 1) $f5 (retail: n + 1 in $f4, 1.0f
 * in $f5). Tried (no effect): -fno-sched-interblock, an inline fade helper for n / (n + 1), an inline helper for
 * the colour tail (moves v to 0x10(sp), 25). Under the file's own line the function cannot match (li.s needs
 * Ps2EeAs, vec_add_ab needs the VU0 class). */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L33_0034F250 */
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} P_0034F250;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 padC[2];
    u16 hE;
    u8 pad10[8];
    f32 f18;
    f32 f1C;
} Q_0034F250;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 D_L33_001DD704;
__asm__(".extern D_L33_001DD704, 4");
extern f32 D_L33_001DD700;
__asm__(".extern D_L33_001DD700, 4");
extern f32 D_L33_001DD6F8;
__asm__(".extern D_L33_001DD6F8, 4");
extern s32 D_L33_001DD6C4;
__asm__(".extern D_L33_001DD6C4, 4");
extern s32 D_L33_001DD6C8;
__asm__(".extern D_L33_001DD6C8, 4");
extern s32 D_L33_001DD760;
__asm__(".extern D_L33_001DD760, 4");
extern f32 D_L33_001DD6E8;
__asm__(".extern D_L33_001DD6E8, 4");
extern f32 D_L33_001DD6EC;
__asm__(".extern D_L33_001DD6EC, 4");
extern f32 D_L33_001DD6D4;
__asm__(".extern D_L33_001DD6D4, 4");
extern f32 D_L33_001DD708;
__asm__(".extern D_L33_001DD708, 4");
extern f32 D_L33_001DD6D0;
__asm__(".extern D_L33_001DD6D0, 4");
extern f32 D_L33_001DD6CC;
__asm__(".extern D_L33_001DD6CC, 4");
extern f32 D_L33_001DD6E4;
__asm__(".extern D_L33_001DD6E4, 4");

void func_L33_0034F250(u8 *p_, u8 *q_) {
    P_0034F250 *p = (P_0034F250 *)p_;
    Q_0034F250 *q = (Q_0034F250 *)q_;
    vu0_v4 v;
    vu0_v4 a;
    u8 *m;
    u8 *pv;
    s32 n;
    s32 on;
    s32 n2;

    if (q == 0) return;
    m = q->m;
    pv = *(u8 **)(m + 0x68);
    on = q->w4;
    if (m == 0) return;
    if (on == 0) return;

    if (q->hA & 1) {
        f32 ang1;
        f32 ang2;
        f32 s;

        ang1 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = func_003824E0(D_L33_001DD704, D_L33_001DD700);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(m, 1, &p->pos);
        a.x = func_0038D098(ang2) * D_L33_001DD6F8;
        a.z = func_0038D0B0(ang2) * D_L33_001DD6F8;
        a.y = 0.0f;
        vec_add_ab(&p->pos, &p->pos, &a);
        q->f18 = s * func_0038D098(ang1);
        q->f1C = s * func_0038D0B0(ang1);
        p->w4 = func_L30_0034DBA0(D_L33_001DD6C4, D_L33_001DD6C8);
        p->fC = func_003C4088(D_L33_001DD6E8, D_L33_001DD6EC, (f32)*(s32 *)(pv + 0xA8) / (f32)D_L33_001DD760);
    }

    p->pos.x += q->f18;
    q->f1C += D_L33_001DD6D4;
    p->pos.z += q->f1C;
    n = p->hA;
    p->fC *= 1.0f - D_L33_001DD708 * (1.0f - (f32)n / (f32)(n + 1));
    func_L33_00344F88(&v, p->w4);
    n2 = p->hA;
    v.x *= D_L33_001DD6D0;
    v.y *= D_L33_001DD6CC;
    v.w *= (f32)n2 / (f32)(n2 + 1);
    func_L33_003453C8(&p->w4, &v);
    {
        f32 lo = (f32)(q->hE & 0xFF);
        f32 hi = (f32)(q->hE >> 8);
        f32 hi2 = D_L33_001DD6E4 * (f32)q->h8 * hi * 0.00390625f;
        p->b8 = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(p->hA, q->h8, 0.0f));
    }
}
/* localdecomp:end func_L33_0034F250 */
#endif
