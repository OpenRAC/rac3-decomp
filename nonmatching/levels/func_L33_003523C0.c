/* PAL near miss (c51, wave 14c): r65's vec_add_ab version (wr65/out/func_L33_003523C0.vf.c), unchanged, for the line
 * "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line + -mvu0-use-vf0-vf2; L33_00352A08.c,
 * the next file, and L33_00353970.c have it) plus the divs row 'func_L33_003523C0 0 2'. wc51/chk.py (tools/check.py, line and
 * divs row in memory) --target level_33: 5 diff (wc51/func_L33_003523C0/try-01.log), the vadd now as retail.
 * The whole file L33_00350818.c can take that line: func_L33_00350818, 00352760, 003527C0 and 00352908 each MATCH under it
 * (wc51/func_L33_003523C0/sib-*.log); otherwise the cut is 0x003523C0-0x00352760 (both 8-aligned).
 * Left (5 rows, the bottom block): retail issues li.s 128.0 ($f4) after mul.s $f0,$f0,$f5 and mtc1 $zero,$f12 after
 * mul.s $f2,$f2,$f0; sched1 and sched2 here (wc51/sched.py, sched1-01.log / sched2-01.log) issue both in the cycle before,
 * alone (t7 and t9), since neither has a dependence. The same kind of difference as func_L33_0034F250's move $a0,$sp. */
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
