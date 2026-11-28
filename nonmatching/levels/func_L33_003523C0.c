/* func_L33_003523C0 (Claude wave 14 r65, 2026-11-28). First draft kept here. */
/* func_L33_003523C0 (924 B, level 33 only, src/levels/33_vidcomic_2/L33_00350818.c): first draft, written from
   retail by wr65 (wave 14, 2026-11-28). A particle update callback, the twin of func_L33_00353970's set-up block.
   Under the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as) with the divs row
   'func_L33_003523C0 0 2' (retail: no nop before the first div.s, two before the second): 7 diff.
   What made it close: p, q, the moby and its vars as struct pointers (MEM_IN_STRUCT stores let gcc schedule the
   fixed scalar loads D_L33_001DDBC8 / D_L33_001DDBA8 above them, as retail; the cast-pointer form gave ~110 diff),
   and the `pv->fA8 == 0` test with the call arm first (retail keeps two `sw $v0, 4($s1)`; the `!= 0` order lets
   jump cross-jump them into one).
   Still differs:
   1. (2 rows) the vadd: retail issues `lqc2 $vf1, 0x10($s1)` between the stores of v.y and v.z, so it is the
      vector library's per-instruction helper (vec_add_ab, "j" operands), which needs -mvu0-use-vf0-vf2; under
      this file's line the "j" class does not exist (vf17 spill error), so this draft has one whole VU0 block
      and its lqc2 comes after the last store. With vec_add_ab and the line
      '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (L33_00353970.c's, and
      L33_00352A08.c's, the next file) these 2 rows match (tools/check.py --flags=-mvu0-use-vf0-vf2: only the
      rows below plus the 2 divs nops tools/check.py cannot inject). The cut would be 0x3523C0-0x352760, both ends
      8-aligned (next function func_L33_00352760).
   2. (5 rows) the bottom block: retail schedules `mul.s $f0,$f0,$f5` before `li.s $f4,128.0` and
      `mul.s $f2,$f2,$f0` before `mtc1 $zero,$f12`; ours issues both constants one slot earlier (sched2 dump:
      both have no dependences and fill the memory unit at t7/t9 before the mul is ready at t8). Tried: the
      shift in an s32 local, the alpha in an s32 local, the or operands swapped (27), const on the two globals
      (CSE then keeps D_L33_001DDBC8 across the calls: 159). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_003523C0 */
typedef struct {
    u8 pad0[0x60];
    f32 f60;
    u8 pad64[4];
    f32 f68;
    u8 pad6C[0x3C];
    s32 fA8;
} Vars_003523C0;

typedef struct {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x10];
    u8 state;
    u8 pad21[0x47];
    Vars_003523C0 *vars;
    u8 pad6C[0x3E];
    s16 oclass;
} Moby_003523C0;

typedef struct {
    u8 pad0[4];
    s32 f4;
    s8 f8;
    u8 pad9;
    s16 fA;
    f32 fC;
    vu0_v4 pos;
} Part_003523C0;

typedef struct {
    Moby_003523C0 *m;
    s32 on;
    s16 f8;
    u16 fA;
    s16 fC;
    u16 fE;
    f32 f10;
    f32 f14;
} Src_003523C0;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L33_001DDAE0[2];
__asm__(".extern D_L33_001DDAE0, 8");
extern f32 D_L33_001DD964;
__asm__(".extern D_L33_001DD964, 4");
extern f32 D_L33_001DDB98;
__asm__(".extern D_L33_001DDB98, 4");
extern f32 D_L33_001DDB9C;
__asm__(".extern D_L33_001DDB9C, 4");
extern s32 D_L33_001DDBA0;
__asm__(".extern D_L33_001DDBA0, 4");
extern s32 D_L33_001DDBA4;
__asm__(".extern D_L33_001DDBA4, 4");
extern f32 D_L33_001DDBA8;
__asm__(".extern D_L33_001DDBA8, 4");
extern f32 D_L33_001DDBAC;
__asm__(".extern D_L33_001DDBAC, 4");
extern f32 D_L33_001DDBB0;
__asm__(".extern D_L33_001DDBB0, 4");
extern f32 D_L33_001DDBBC;
__asm__(".extern D_L33_001DDBBC, 4");
extern f32 D_L33_001DDBC8;
__asm__(".extern D_L33_001DDBC8, 4");
extern f32 D_L33_001DDBCC;
__asm__(".extern D_L33_001DDBCC, 4");

void func_L33_003523C0(Part_003523C0 *p, Src_003523C0 *q) {
    vu0_v4 v;
    vu0_v4 b;
    Moby_003523C0 *m;
    Vars_003523C0 *pv;
    s32 on;
    u16 e;
    f32 lo;
    f32 hi;

    if (q == 0) return;
    m = q->m;
    pv = m->vars;
    on = q->on;
    if (m == 0) return;
    if (on == 0) return;

    if (q->fA & 1) {
        f32 ang;
        f32 s;
        u8 t;

        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = D_L33_001DDB98 * m->fC * func_003824E0(0.0f, 1.0f) * 0.0009765625f;
        func_003C2F58(m, 2, &p->pos);
        v.x = func_0038D098(ang) * s;
        v.z = func_0038D0B0(ang) * s;
        v.y = 0.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(p->pos) : "m"(p->pos), "m"(v) : "vf1", "vf2");
        p->pos.y += func_003824E0(-D_L33_001DDBCC, D_L33_001DDBCC);
        t = m->state;
        if (t == 2 || t == 4) {
            q->f10 = pv->f60 * D_L33_001DDB9C * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
            q->f14 = pv->f68 * D_L33_001DDB9C * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
        } else if (t == 0x42) {
            f32 k;
            func_0038CF68(&b, &v, D_L33_001DDAE0[0x1761 - m->oclass]
                * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f));
            k = D_L33_001DD964;
            q->f10 = b.x + k * pv->f60;
            q->f14 = b.z + k * pv->f68;
        }
        if (pv->fA8 == 0) {
            p->f4 = func_L30_0034DBA0(D_L33_001DDBA0, D_L33_001DDBA4);
        } else {
            p->f4 = 0x80000000;
        }
        p->fC = func_003824E0(D_L33_001DDBB0, D_L33_001DDBAC);
    }

    q->f14 -= D_L33_001DDBBC * ((f32)((q->fC & 0xFF00) >> 8) * 0.00390625f);
    p->pos.x += q->f10;
    p->pos.z += q->f14;
    p->f4 = (p->f4 & 0xFFFFFF) | ((s32)((f32)p->fA * 128.0f / (f32)q->f8) << 24);
    e = q->fE;
    lo = (f32)(e & 0xFF);
    hi = lo + D_L33_001DDBA8 * (f32)q->f8 * (f32)(e >> 8) * 0.00390625f;
    p->f8 = (s32)func_003C4088(lo, hi, func_L03_0034B148(p->fA, q->f8, 0.0f));
    p->fC = p->fC * ((f32)p->fA / (f32)(p->fA + 1));
}
/* localdecomp:end func_L33_003523C0 */

/* The other form the notes name (Claude wave 14 r65, func_L33_003523C0.vf.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_003523C0 */
typedef struct {
    u8 pad0[0x60];
    f32 f60;
    u8 pad64[4];
    f32 f68;
    u8 pad6C[0x3C];
    s32 fA8;
} Vars_003523C0;

typedef struct {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x10];
    u8 state;
    u8 pad21[0x47];
    Vars_003523C0 *vars;
    u8 pad6C[0x3E];
    s16 oclass;
} Moby_003523C0;

typedef struct {
    u8 pad0[4];
    s32 f4;
    s8 f8;
    u8 pad9;
    s16 fA;
    f32 fC;
    vu0_v4 pos;
} Part_003523C0;

typedef struct {
    Moby_003523C0 *m;
    s32 on;
    s16 f8;
    u16 fA;
    s16 fC;
    u16 fE;
    f32 f10;
    f32 f14;
} Src_003523C0;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L33_001DDAE0[2];
__asm__(".extern D_L33_001DDAE0, 8");
extern f32 D_L33_001DD964;
__asm__(".extern D_L33_001DD964, 4");
extern f32 D_L33_001DDB98;
__asm__(".extern D_L33_001DDB98, 4");
extern f32 D_L33_001DDB9C;
__asm__(".extern D_L33_001DDB9C, 4");
extern s32 D_L33_001DDBA0;
__asm__(".extern D_L33_001DDBA0, 4");
extern s32 D_L33_001DDBA4;
__asm__(".extern D_L33_001DDBA4, 4");
extern f32 D_L33_001DDBA8;
__asm__(".extern D_L33_001DDBA8, 4");
extern f32 D_L33_001DDBAC;
__asm__(".extern D_L33_001DDBAC, 4");
extern f32 D_L33_001DDBB0;
__asm__(".extern D_L33_001DDBB0, 4");
extern f32 D_L33_001DDBBC;
__asm__(".extern D_L33_001DDBBC, 4");
extern f32 D_L33_001DDBC8;
__asm__(".extern D_L33_001DDBC8, 4");
extern f32 D_L33_001DDBCC;
__asm__(".extern D_L33_001DDBCC, 4");

void func_L33_003523C0(Part_003523C0 *p, Src_003523C0 *q) {
    vu0_v4 v;
    vu0_v4 b;
    Moby_003523C0 *m;
    Vars_003523C0 *pv;
    s32 on;
    u16 e;
    f32 lo;
    f32 hi;

    if (q == 0) return;
    m = q->m;
    pv = m->vars;
    on = q->on;
    if (m == 0) return;
    if (on == 0) return;

    if (q->fA & 1) {
        f32 ang;
        f32 s;
        u8 t;

        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = D_L33_001DDB98 * m->fC * func_003824E0(0.0f, 1.0f) * 0.0009765625f;
        func_003C2F58(m, 2, &p->pos);
        v.x = func_0038D098(ang) * s;
        v.z = func_0038D0B0(ang) * s;
        v.y = 0.0f;
        vec_add_ab(&p->pos, &p->pos, &v);
        p->pos.y += func_003824E0(-D_L33_001DDBCC, D_L33_001DDBCC);
        t = m->state;
        if (t == 2 || t == 4) {
            q->f10 = pv->f60 * D_L33_001DDB9C * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
            q->f14 = pv->f68 * D_L33_001DDB9C * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
        } else if (t == 0x42) {
            f32 k;
            func_0038CF68(&b, &v, D_L33_001DDAE0[0x1761 - m->oclass]
                * func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f));
            k = D_L33_001DD964;
            q->f10 = b.x + k * pv->f60;
            q->f14 = b.z + k * pv->f68;
        }
        if (pv->fA8 == 0) {
            p->f4 = func_L30_0034DBA0(D_L33_001DDBA0, D_L33_001DDBA4);
        } else {
            p->f4 = 0x80000000;
        }
        p->fC = func_003824E0(D_L33_001DDBB0, D_L33_001DDBAC);
    }

    q->f14 -= D_L33_001DDBBC * ((f32)((q->fC & 0xFF00) >> 8) * 0.00390625f);
    p->pos.x += q->f10;
    p->pos.z += q->f14;
    p->f4 = (p->f4 & 0xFFFFFF) | ((s32)((f32)p->fA * 128.0f / (f32)q->f8) << 24);
    e = q->fE;
    lo = (f32)(e & 0xFF);
    hi = lo + D_L33_001DDBA8 * (f32)q->f8 * (f32)(e >> 8) * 0.00390625f;
    p->f8 = (s32)func_003C4088(lo, hi, func_L03_0034B148(p->fA, q->f8, 0.0f));
    p->fC = p->fC * ((f32)p->fA / (f32)(p->fA + 1));
}
/* localdecomp:end func_L33_003523C0 */
#endif
