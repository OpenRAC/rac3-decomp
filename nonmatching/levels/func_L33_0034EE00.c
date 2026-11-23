/* PAL near miss (sonnet-b30-j3d): a particle's per-frame update, the bigger sibling of func_L33_0034F250 (same P/Q record layout, first-frame block: random
 * direction and speed from the emitter's moby, collision against the floor with func_003D3CB0, bounce, colour/size/alpha fade with func_003C4088 and three
 * func_L03_0034B148 calls). Plain C with the vu0.h helpers vec_add_ab / vec_sub_ab and fabs_asm. Needs the file line
 * `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (a cut of src/levels/33_vidcomic_2/L33_0034E8C0.c, which has neither flag: the
 * head up to func_L33_0034EC28 keeps the old line, a new L33_0034EE00.c holds this function and the INCLUDE_ASM of func_L33_0034F250, which needs the
 * same line) and no divs_nops row (one div.s with only the assembler's mtc1 nop).
 * 2 raw words differ (check.py `--no-context --mode S --as ps2as --flags=-mvu0-use-vf0-vf2`; with the file's context the earlier
 * `void func_L33_0034EE00(u8 *, u8 *);` declaration of the EA80 block conflicts, which a cut removes): in the first of the three func_L03_0034B148 calls at the end retail has
 * `lh $a0; lh $a1; jal; mov.s $f12,$f20 (slot)` where ours has `lh $a0; mov.s $f12,$f20; jal; lh $a1 (slot)`: the sched2 dump (`-dS -dR -fsched-verbose-5`)
 * shows `mtc1 $zero,$f20` at clock 2 and the `mov.s` ready at clock 4, beside `lh $a0`; retail's order needs the `mtc1 -> mov.s` edge to cost 3 (the
 * same two words as func_L30_003518F0, nm2's analysis). Tried without effect (about 25 wordings): the zero as a local / cast / double, locals for
 * the three results, for hA and h8 (also in both orders), hi = lo + hi2 as a local at three places, the pos copy as a struct assignment or a cast store,
 * stores through casts, `c` computed late. What fixed the rest: typed P/Q/G structs (G = the global at 0x1E9600 as a struct, so the address is formed once
 * and the loads use displacements), `z = tmp.z` read before the branch and the select as `tmp.z = cond ? z - t : z + t` (one store after the join),
 * the store of q->w1C through a cast (a struct-member store let sched1 hoist the $gp load of D_L33_001DD598 above it).
 *
 * Round 21 (sonnet-b30-nm8, still 2 words; the join tail is the same as func_L30_003518F0's, whose header lists everything tried): no matched caller has
 * this shape (a scan of the retail text of all 49 levels finds `lh; lh; jal; mov.s $f12,$f20 (slot)` only in func_L30_003518F0, this function and
 * func_L32_003B66A0, a third near miss with the same two words), and inline wrappers, `do { } while (0)` note barriers, the zero as a function-level variable
 * and the existing flags `-fno-strict-aliasing` / `-fno-sched-interblock` do not move it. A fix found for one of the three functions should fix all three.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L33_0034EE00 */
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

void func_L33_0034EE00(P_0034EE00 *p, Q_0034EE00 *q) {
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
