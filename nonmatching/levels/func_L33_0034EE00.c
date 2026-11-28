/* func_L33_0034EE00 (Claude wave 14 r72, 2026-11-28). Replaces the earlier draft of this function (sonnet-b30-j3d near miss (round 19)). */
/* PAL near miss (wave 14 r72, 2026-11-28): func_L33_0034EE00 (1104 B, level 33 only), a particle's per-frame update
 * (the bigger sibling of func_L33_0034F250). First plain-C version that compiles under its file's own line
 * (-O2 -G8 -fopt-stack -mno-check-zero-division): 195 diff (p10 check). The existing draft (sonnet-b30-j3d) does not
 * compile there: vu0.h's vec_add_ab / vec_sub_ab need -mvu0-use-vf0-vf2. Changed against it: the file's own prototype
 * `void func_L33_0034EE00(u8 *, u8 *)` (the EA80 block declares it) with the records cast inside, so the file context
 * no longer conflicts; vu0_q from vu0.h instead of a block typedef; the two vector ops as one VU0 asm sequence each
 * (lqc2/lqc2/vadd.xyz or vsub.xyz/sqc2, vf1/vf2 clobbered) in suffixed inline helpers.
 * What differs is the line, not the C: retail builds 0.00390625f, 6.2831855f and 0.74f Ps2EeAs-style (lui at/ori/mtc1)
 * where this line's ee-as loads them from .lit4, the assembler adds mfc1 nops, and the clobber-form subtract makes cc1
 * keep a copy of p in $s5 (frame 0xB0 against 0xA0), which shifts every later word.
 * With the line `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (exactly the line of the next
 * file, L33_0034F530.c) the existing draft's C (vec_add_ab/vec_sub_ab, this prototype) gives 2 diff WITH the file's
 * context (tools/check.py ... --flags "-mvu0-use-vf0-vf2 @ps2as"; wr72/func_L33_0034EE00.cut.c). The cut: 0x0034EE00
 * (8-aligned, after func_L33_0034EC28's end at 0x0034EDFC + pad) to 0x0034F530 (end of func_L33_0034F250, INCLUDE_ASM,
 * which needs the same line), i.e. L33_0034F530.c's start moved back to 0x0034EE00 or a new file of the same line.
 * The 2 words under that line: the first func_L03_0034B148 call of the tail, retail lh a0; lh a1; jal; mov.s f12,f20
 * (slot), ours lh a0; mov.s; jal; lh a1. The sched2 dump (r72) shows why: lh a1 (q->h8) depends on the TImode sq of
 * the pos copy-back (alias), so it is ready at t5, while the mov.s is ready at t4 (mtc1 zero at t2, cost 2) and issues
 * beside lh a0; retail's order needs the mov.s not ready before t5. Same two words in func_L30_003518F0 and
 * func_L32_003B66A0. */
#include "common.h"
/* localdecomp:start func_L33_0034EE00 */
#include "vu0.h"
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} P_0034EE00;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 b0C;
    u8 pad0D;
    u16 hE;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1C;
} Q_0034EE00;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 D_L33_001DD688;
__asm__(".extern D_L33_001DD688, 4");
extern f32 D_L33_001DD690;
__asm__(".extern D_L33_001DD690, 4");
extern f32 D_L33_001DD68C;
__asm__(".extern D_L33_001DD68C, 4");
extern f32 D_L33_001DD6AC;
__asm__(".extern D_L33_001DD6AC, 4");
extern f32 D_L33_001DD6BC;
__asm__(".extern D_L33_001DD6BC, 4");
extern f32 D_L33_001DD6B8;
__asm__(".extern D_L33_001DD6B8, 4");
extern f32 D_L33_001DD6A4;
__asm__(".extern D_L33_001DD6A4, 4");
extern f32 D_L33_001DD6C0;
__asm__(".extern D_L33_001DD6C0, 4");
extern f32 D_L33_001DD580;
__asm__(".extern D_L33_001DD580, 4");
extern f32 D_L33_001DD584;
__asm__(".extern D_L33_001DD584, 4");
extern s32 D_L33_001DD660[2];
__asm__(".extern D_L33_001DD660, 8");
extern s32 D_L33_001DD670[2];
__asm__(".extern D_L33_001DD670, 8");
extern s32 D_L33_001DD640[2];
__asm__(".extern D_L33_001DD640, 8");
extern s32 D_L33_001DD650[2];
__asm__(".extern D_L33_001DD650, 8");
extern f32 D_L33_001DD598;
__asm__(".extern D_L33_001DD598, 4");
extern f32 D_L33_001DD5E0;
__asm__(".extern D_L33_001DD5E0, 4");
extern f32 D_L33_001DD5E4;
__asm__(".extern D_L33_001DD5E4, 16");
extern f32 D_L33_001DD5E8;
__asm__(".extern D_L33_001DD5E8, 16");
extern s32 D_L33_001DD634;
__asm__(".extern D_L33_001DD634, 4");
extern f32 D_L33_001DD70C;
__asm__(".extern D_L33_001DD70C, 4");
extern f32 D_L33_001DD694;
__asm__(".extern D_L33_001DD694, 4");
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    u8 pad1C[8];
    f32 f24;
} G_0034EE00;

extern G_0034EE00 D_L33_001E9600;

/* The vector add and subtract as one VU0 sequence each (this file's line has no
 * -mvu0-use-vf0-vf2, so vu0.h's "j"-operand helpers cannot be used here). */
static __inline__ void vadd_0034EE00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vadd.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0"
            : "=m"(*(vu0_v4 *)d)
            : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
            : "vf1", "vf2");
}

static __inline__ void vsub_0034EE00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1
	lqc2 $vf2, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)d)
            : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
            : "vf1", "vf2");
}

void func_L33_0034EE00(u8 *a0, u8 *a1) {
    P_0034EE00 *p = (P_0034EE00 *)a0;
    Q_0034EE00 *q = (Q_0034EE00 *)a1;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 w;
    u8 *m;
    u8 *pv;
    s32 on;
    f32 lo;
    f32 hi2;
    f32 c;

    if (q == 0) return;
    m = q->m;
    pv = *(u8 **)(m + 0x68);
    on = q->w4;
    if (m == 0) return;
    if (on == 0) return;

    lo = (f32)(q->hE & 0xFF);
    hi2 = D_L33_001DD688 * (f32)q->h8 * (f32)(q->hE >> 8) * 0.00390625f;
    c = func_003C4088(D_L33_001DD690, D_L33_001DD68C, (f32)q->b0C * 0.00390625f);

    if (q->hA & 1) {
        f32 ang1;
        f32 spd;
        f32 ang2;

        ang1 = func_0038DAB8(*(f32 *)(pv + 0xA0), func_003824E0(-D_L33_001DD6AC, D_L33_001DD6AC));
        spd = func_003824E0(D_L33_001DD6BC, D_L33_001DD6B8);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(m, 1, &p->pos);
        v.x = func_0038D098(ang2) * D_L33_001DD6A4;
        v.z = func_0038D0B0(ang2) * D_L33_001DD6A4;
        v.y = 0.0f;
        vadd_0034EE00(&p->pos, &p->pos, &v);
        p->pos.y += D_L33_001DD6C0;
        q->f10 = spd * func_0038D098(ang1);
        if (fabs_asm(func_0038DB00(D_L33_001DD580, *(f32 *)(m + 0xF8))) < fabs_asm(func_0038DB00(D_L33_001DD584, *(f32 *)(m + 0xF8)))) {
            q->f10 = -q->f10;
        }
        q->f14 = spd * func_0038D0B0(ang1);
        q->w18 = func_L30_0034DBA0(D_L33_001DD670[*(s32 *)(pv + 0xA4)], D_L33_001DD660[*(s32 *)(pv + 0xA4)]);
        *(s32 *)((u8 *)q + 0x1C) = func_L30_0034DBA0(D_L33_001DD650[*(s32 *)(pv + 0xA4)], D_L33_001DD640[*(s32 *)(pv + 0xA4)]);
        p->hA = q->h8 = q->h8 + (s32)(D_L33_001DD598 / spd);
    }

    *(vu0_q *)&tmp = *(vu0_q *)&p->pos;
    tmp.x += q->f10;
    tmp.z += q->f14;
    if (func_003D3CB0(&p->pos, &tmp, 1, m, 0) != 0 && D_L33_001E9600.w18 != 0) {
        f32 z = tmp.z;
        f32 t = q->f10 * 0.74f;

        tmp.x = p->pos.x + t;
        tmp.z = (p->pos.y <= D_L33_001E9600.f24) ? z - t : z + t;
        func_L33_00344F88(&v, q->w1C);
        v.x += D_L33_001DD5E0;
        v.y += D_L33_001DD5E4;
        v.z += D_L33_001DD5E8;
        func_L33_003453C8(&q->w1C, &v);
        vsub_0034EE00(&w, &tmp, &p->pos);
        if (D_L33_001DD634 < ((u8 *)p)[7]) {
            func_L30_0034CB68(q->m, &w, 1, -1, &p->pos, 0, (f32)pv[0x24], D_L33_001DD70C);
        }
    }
    *(vu0_q *)&p->pos = *(vu0_q *)&tmp;
    p->fC = func_003C4088(D_L33_001DD694, c, func_L03_0034B148(p->hA, q->h8, 0.0f));
    p->w4 = func_0038DBD8(q->w18, q->w1C, func_L03_0034B148(p->hA, q->h8, 0.0f));
    p->b8 = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(p->hA, q->h8, 0.0f));
}
/* localdecomp:end func_L33_0034EE00 */

/* The other form the notes name (Claude wave 14 r72, func_L33_0034EE00.cut.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
#include "common.h"
/* localdecomp:start func_L33_0034EE00 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} P_0034EE00;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 b0C;
    u8 pad0D;
    u16 hE;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1C;
} Q_0034EE00;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 D_L33_001DD688;
__asm__(".extern D_L33_001DD688, 4");
extern f32 D_L33_001DD690;
__asm__(".extern D_L33_001DD690, 4");
extern f32 D_L33_001DD68C;
__asm__(".extern D_L33_001DD68C, 4");
extern f32 D_L33_001DD6AC;
__asm__(".extern D_L33_001DD6AC, 4");
extern f32 D_L33_001DD6BC;
__asm__(".extern D_L33_001DD6BC, 4");
extern f32 D_L33_001DD6B8;
__asm__(".extern D_L33_001DD6B8, 4");
extern f32 D_L33_001DD6A4;
__asm__(".extern D_L33_001DD6A4, 4");
extern f32 D_L33_001DD6C0;
__asm__(".extern D_L33_001DD6C0, 4");
extern f32 D_L33_001DD580;
__asm__(".extern D_L33_001DD580, 4");
extern f32 D_L33_001DD584;
__asm__(".extern D_L33_001DD584, 4");
extern s32 D_L33_001DD660[2];
__asm__(".extern D_L33_001DD660, 8");
extern s32 D_L33_001DD670[2];
__asm__(".extern D_L33_001DD670, 8");
extern s32 D_L33_001DD640[2];
__asm__(".extern D_L33_001DD640, 8");
extern s32 D_L33_001DD650[2];
__asm__(".extern D_L33_001DD650, 8");
extern f32 D_L33_001DD598;
__asm__(".extern D_L33_001DD598, 4");
extern f32 D_L33_001DD5E0;
__asm__(".extern D_L33_001DD5E0, 4");
extern f32 D_L33_001DD5E4;
__asm__(".extern D_L33_001DD5E4, 16");
extern f32 D_L33_001DD5E8;
__asm__(".extern D_L33_001DD5E8, 16");
extern s32 D_L33_001DD634;
__asm__(".extern D_L33_001DD634, 4");
extern f32 D_L33_001DD70C;
__asm__(".extern D_L33_001DD70C, 4");
extern f32 D_L33_001DD694;
__asm__(".extern D_L33_001DD694, 4");
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    u8 pad1C[8];
    f32 f24;
} G_0034EE00;

extern G_0034EE00 D_L33_001E9600;

void func_L33_0034EE00(u8 *a0, u8 *a1) {
    P_0034EE00 *p = (P_0034EE00 *)a0;
    Q_0034EE00 *q = (Q_0034EE00 *)a1;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 w;
    u8 *m;
    u8 *pv;
    s32 on;
    f32 lo;
    f32 hi2;
    f32 c;

    if (q == 0) return;
    m = q->m;
    pv = *(u8 **)(m + 0x68);
    on = q->w4;
    if (m == 0) return;
    if (on == 0) return;

    lo = (f32)(q->hE & 0xFF);
    hi2 = D_L33_001DD688 * (f32)q->h8 * (f32)(q->hE >> 8) * 0.00390625f;
    c = func_003C4088(D_L33_001DD690, D_L33_001DD68C, (f32)q->b0C * 0.00390625f);

    if (q->hA & 1) {
        f32 ang1;
        f32 spd;
        f32 ang2;

        ang1 = func_0038DAB8(*(f32 *)(pv + 0xA0), func_003824E0(-D_L33_001DD6AC, D_L33_001DD6AC));
        spd = func_003824E0(D_L33_001DD6BC, D_L33_001DD6B8);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(m, 1, &p->pos);
        v.x = func_0038D098(ang2) * D_L33_001DD6A4;
        v.z = func_0038D0B0(ang2) * D_L33_001DD6A4;
        v.y = 0.0f;
        vec_add_ab(&p->pos, &p->pos, &v);
        p->pos.y += D_L33_001DD6C0;
        q->f10 = spd * func_0038D098(ang1);
        if (fabs_asm(func_0038DB00(D_L33_001DD580, *(f32 *)(m + 0xF8))) < fabs_asm(func_0038DB00(D_L33_001DD584, *(f32 *)(m + 0xF8)))) {
            q->f10 = -q->f10;
        }
        q->f14 = spd * func_0038D0B0(ang1);
        q->w18 = func_L30_0034DBA0(D_L33_001DD670[*(s32 *)(pv + 0xA4)], D_L33_001DD660[*(s32 *)(pv + 0xA4)]);
        *(s32 *)((u8 *)q + 0x1C) = func_L30_0034DBA0(D_L33_001DD650[*(s32 *)(pv + 0xA4)], D_L33_001DD640[*(s32 *)(pv + 0xA4)]);
        p->hA = q->h8 = q->h8 + (s32)(D_L33_001DD598 / spd);
    }

    *(u128_t *)&tmp = *(u128_t *)&p->pos;
    tmp.x += q->f10;
    tmp.z += q->f14;
    if (func_003D3CB0(&p->pos, &tmp, 1, m, 0) != 0 && D_L33_001E9600.w18 != 0) {
        f32 z = tmp.z;
        f32 t = q->f10 * 0.74f;

        tmp.x = p->pos.x + t;
        tmp.z = (p->pos.y <= D_L33_001E9600.f24) ? z - t : z + t;
        func_L33_00344F88(&v, q->w1C);
        v.x += D_L33_001DD5E0;
        v.y += D_L33_001DD5E4;
        v.z += D_L33_001DD5E8;
        func_L33_003453C8(&q->w1C, &v);
        vec_sub_ab(&w, &tmp, &p->pos);
        if (D_L33_001DD634 < ((u8 *)p)[7]) {
            func_L30_0034CB68(q->m, &w, 1, -1, &p->pos, 0, (f32)pv[0x24], D_L33_001DD70C);
        }
    }
    *(u128_t *)&p->pos = *(u128_t *)&tmp;
    p->fC = func_003C4088(D_L33_001DD694, c, func_L03_0034B148(p->hA, q->h8, 0.0f));
    p->w4 = func_0038DBD8(q->w18, q->w1C, func_L03_0034B148(p->hA, q->h8, 0.0f));
    p->b8 = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(p->hA, q->h8, 0.0f));
}
/* localdecomp:end func_L33_0034EE00 */
#endif
