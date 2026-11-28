/* func_L30_00343E10 (Claude wave 14 retry r83, 2026-11-28). Replaces the earlier draft of this function (PAL draft (k6 a6, 2026-11-26), written from retail). */
/* PAL near miss, wave 14 retry r83 (2026-11-28): func_L30_00343E10 (884 B, levels 30-36), from r63's 10-diff near.
 * 8 diff (build/codex/wave10/p10/check.py, level 30, the file's own line, existing divs row 2 2 2 2 2).
 * Changed: case 2 is rad = sqrt_asm(w * w + h * h) * (...) (no reuse of c: retail's sqrt.s writes $f0, not c's $f24),
 * and the first colour branch is wrapped in do { } while (0). The RTL dumps show why: k (4 refs, live 81) outranks c
 * (4 refs, live 90) in global allocation, so k takes $f24; the loop around branch 1 counts c's use there at loop
 * depth 2 (flow weights refs by loop depth), c then outranks k and gets $f24, k $f25 as retail. Reusing c for the
 * case-2 square root (r63) raised c's refs too but made the sqrt write $f24. Wrapping the else branch as well breaks
 * the cross-jumped colour store (70).
 * Still differs: the last lerp's argument schedule. Retail issues lh hE / mov.s $f14, andi hE, lh hC, sra hE, lwc1 D_EE0;
 * here sched2 issues lh hC in cycle 2 (lh hE, mov.s, lh hC, andi, lwc1, ...): in retail neither lh hC nor the lwc1 is
 * ready in cycle 2. Tried: hE converted first, ang/k copy for the third argument, the permuter (600 s, no better). */
#include "common.h"

/* localdecomp:start func_L30_00343E10 */
#include "vu0.h"
__asm__(".extern D_L30_001DCE90, 4");
__asm__(".extern D_L30_001DCEE0, 4");
__asm__(".extern D_L30_001DCEE4, 4");
__asm__(".extern D_L30_001DCEE8, 4");
__asm__(".extern D_L30_001DCEEC, 4");
__asm__(".extern D_L30_001DCEF0, 4");
__asm__(".extern D_L30_001DCEF4, 4");
__asm__(".extern D_L30_001DCEF8, 4");
__asm__(".extern D_L30_001DCEFC, 4");
__asm__(".extern D_L30_001DCF00, 1");
__asm__(".extern D_L30_001DCF01, 1");
__asm__(".extern D_L30_001DCF04, 4");
extern f32 D_L30_001DCE90;
extern f32 D_L30_001DCEE0;
extern f32 D_L30_001DCEE4;
extern f32 D_L30_001DCEE8;
extern f32 D_L30_001DCEEC;
extern f32 D_L30_001DCEF0;
extern f32 D_L30_001DCEF4;
extern f32 D_L30_001DCEF8;
extern f32 D_L30_001DCEFC;
extern u8 D_L30_001DCF00;
extern u8 D_L30_001DCF01;
extern f32 D_L30_001DCF04;
typedef struct {
    u8 p0[3];
    u8 b3;
    s32 color;
    u8 b8;
    u8 p9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} M_00343E10;
typedef struct {
    u8 *owner;
    s32 f4;
    s16 h8;
    u16 hA;
    s16 hC;
    s16 hE;
    f32 f10;
    f32 f14;
} P_00343E10;
extern void func_L30_00343AC8(u8 *, s32, f32 *, f32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
void func_L30_00343E10(M_00343E10 *m, P_00343E10 *p) {
    u8 *o;
    u8 *v;
    s32 n;
    vu0_v4 pos;
    vu0_v4 d;
    f32 w;
    f32 h;
    f32 rad;
    f32 k;
    f32 c;
    f32 ang;
    f32 r;
    f32 a;
    f32 al;
    f32 sq;

    if (p == 0) return;
    o = p->owner;
    n = p->f4;
    v = *(u8 **)(o + 0x68);
    if (o == 0) return;
    if (n == 0) return;
    func_L30_00343AC8(o, (s32)&pos, &w, &h);
    if (o[0x20] == 1) {
        sq = sqrt_asm(w * w + h * h);
        rad = D_L30_001DCE90 * *(f32 *)(v + 0x160) * sq + sq;
    } else if (o[0x20] == 2) {
        rad = sqrt_asm(w * w + h * h) * (D_L30_001DCE90 * (1.0f - *(f32 *)(v + 0x160)) + 1.0f);
    } else {
        rad = 0.0f;
    }
    if (p->hA & 1) {
        p->f10 = func_003824E0(0.0f, 1.0f);
        p->f14 = func_003824E0(D_L30_001DCF04, 1.0f);
        p->f10 = 1.0f - p->f10 * p->f10;
    }
    k = func_L03_0034B148(m->hA, p->h8, 0.0f);
    c = func_0038D0B0(func_0038DB48(k * 3.1415927f));
    ang = func_0038DB48(func_003C4088((f32)*(u8 *)&p->hC * 3.1415927f * 0.0078125f, (f32)*(u8 *)&p->hC * 3.1415927f * 0.0078125f + D_L30_001DCEE8 * 6.2831855f * p->f10, k));
    r = p->f10 * rad;
    d.x = func_0038D098(ang) * r;
    d.z = func_0038D0B0(ang) * r;
    d.y = 0.0f;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(m->pos) : "m"(*(vu0_v4 *)(v + 0x130)), "m"(d) : "vf1", "vf2");
    m->pos.y += D_L30_001DCEFC;
    if (p->f10 < p->f14) {
        do {
            m->b3 = D_L30_001DCF01;
            al = c * D_L30_001DCEEC;
            al = al * func_003C4088(D_L30_001DCEF0, 1.0f, (p->f14 - p->f10) / p->f14);
        } while (0);
        m->color = (s32)al << 24;
    } else {
        m->b3 = D_L30_001DCF00;
        al = c * D_L30_001DCEF4;
        al = al * func_003C4088(D_L30_001DCEF8, 1.0f, (p->f10 - p->f14) / (1.0f - p->f14));
        m->color = ((s32)al << 24) | 0x808080;
    }
    a = (f32)((p->hC & 0xFF00) >> 8);
    m->b8 = func_003C4088(a, a + D_L30_001DCEE0 * (f32)((p->hE & 0xFF00) >> 8), k);
    m->fC = D_L30_001DCEE4 * sqrt_asm(c);
}
/* localdecomp:end func_L30_00343E10 */
