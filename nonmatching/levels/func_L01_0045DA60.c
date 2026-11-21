#include "vu0.h"
extern s32 func_L01_0045DF48(u8 *, u8 *);
/* func_L01_0045DA60: 61 raw rows (one extra move shifts the rest), 5 rows when aligned, in the file's S + @ps2as + vu0 flags (L01_0045D248.c). Written from the retail words with the matched
 * sibling func_L01_0045AF28 as template (same hit-test step, no 0x404 test, `r |= func_L01_0045DF48()` accumulating, `else x80 = 0`).
 * Left: (1) retail computes o + 0xA0 into $a1 and copies it into $s1 (`addiu $a1,$s0,0xA0; move $s1,$a1`), the draft computes it into $s1 and moves it to $a1 at the
 * call; (2) after the call retail compares `lwc1 $f12,0xB0($s0); c.lt.s $f12,$f0` (len stays in $f0, the temp is $f12; the store in the else arm is `swc1 $f0`), the draft
 * gives `mov.s $f1,$f0; lwc1 $f0,0xB0; c.lt.s $f0,$f1` (len is a cross-block pseudo, local-alloc gives the temp $f0 first; a toy with len used in the else arm
 * reproduces it; len used only in the compare gives $f1 for the temp). Source levers that fixed things: the local pointer p = &m->xA0 (without it the vsub
 * roles come out swapped: qa = vf2), `func_L01_00451048` called with 4 arguments (an f32 fifth argument adds `mtc1 $zero,$f12`).
 * No effect: swapped compare, named xB0 local, dp pointer for D_L01_001E0240, callee return types f32/s32, assigning p in the argument, statement orders. */
typedef int u128_t_45DA60 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
} M_45DA60;
typedef struct {
    u8 pad0[0x28];
    f32 x28;
    u8 pad2C[0x34];
    vu0_v4 x60;
    vu0_v4 x70;
    s32 x80;
    s32 x84;
    u8 pad88[8];
    f32 x90;
    u8 pad94[0xC];
    vu0_v4 xA0;
    f32 xB0;
} S_45DA60;
extern u128_t_45DA60 D_L01_001E0240[] __attribute__((section(".sdata")));
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451048_0045DA60(void *, void *, void *, s32);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern void func_L01_004510A8(void *, void *, void *, f32, s32);

void func_L01_0045DA60(u8 *a0, u8 *a1, void *a2, void *mp) {
    M_45DA60 *self = (M_45DA60 *)a0;
    S_45DA60 *m = (S_45DA60 *)a1;
    vu0_q old;
    s32 any;
    s32 i;
    s32 r;
    f32 len;
    vu0_v4 *p;

    vec_add_ab(&self->pos, &self->pos, &m->xA0);
    any = 0;
    r = 0;
    old = *(vu0_q *)&self->pos;
    m->x84 = 0;
    qzero(&m->x60);
    for (i = 0; i < 8; i++) {
        r |= func_L01_0045DF48(a0, a1);
        any |= r;
        if (r == 0) {
            break;
        }
    }
    if (any) {
        vec_sub_ab(&m->xA0, &self->pos, (vu0_v4 *)D_L01_001E0240);
        p = &m->xA0;
        len = func_L01_004510F8(a0, &m->xA0, (s32)mp);
        if (m->xB0 < len) {
            func_L01_00451048_0045DA60(a0, p, p, (s32)mp);
        } else {
            m->xB0 = len;
        }
        if (0.0f < m->x90) {
            func_L01_00450E48(a0, &self->pos, 0.0f, 0.0f, m->x90);
            func_L01_004510A8(a0, p, p, 0.0f, (s32)mp);
        }
        if (m->xB0 < m->x28 * 0.5f) {
            m->x80++;
        } else {
            m->x80 = 0;
        }
    } else {
        m->x80 = 0;
    }
    vec_sub_ab(&m->x70, &self->pos, &old);
}
