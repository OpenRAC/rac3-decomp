/* PAL near miss (k6 a6, 2026-11-26): func_L30_00343E10 (884 B, levels 30-36), written from retail.
 * 10 diff with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
 * (its file's line needs -mvu0-use-vf0-vf2 for vec_add_ab; func_L30_00344188 still matches with it) and the
 * divs_nops row `func_L30_00343E10 2 2 2 2 2`. The first branch stores the colour without | 0x808080
 * (a cross-jumped tail). Reusing c for case 2's square root fixes the $f24/$f25 swap of k and c
 * (decomp-permuter found it); what differs: that sqrt.s now writes $f24 directly where retail has $f0, and
 * the hE/hC loads of the last lerp are scheduled in another order. */
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
extern void func_L30_00343AC8(u8 *, vu0_v4 *, f32 *, f32 *);
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
    func_L30_00343AC8(o, &pos, &w, &h);
    if (o[0x20] == 1) {
        sq = sqrt_asm(w * w + h * h);
        rad = D_L30_001DCE90 * *(f32 *)(v + 0x160) * sq + sq;
    } else if (o[0x20] == 2) {
        c = sqrt_asm(w * w + h * h);
        rad = c * (D_L30_001DCE90 * (1.0f - *(f32 *)(v + 0x160)) + 1.0f);
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
    vec_add_ab(&m->pos, v + 0x130, &d);
    m->pos.y += D_L30_001DCEFC;
    if (p->f10 < p->f14) {
        m->b3 = D_L30_001DCF01;
        al = c * D_L30_001DCEEC;
        al = al * func_003C4088(D_L30_001DCEF0, 1.0f, (p->f14 - p->f10) / p->f14);
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
