/* PAL near miss (wave 13, r23), first draft of a fresh entry: 319 words differ in its file's context with
 * the file's flags (measured with the divs row `func_L39_0061ED80 0 2 2 2` injected; four div.s, the row
 * is not in config/levels/divs_nops.txt yet), but almost all of them are one shifted word: the real
 * difference is about eight instructions.
 * What it has: the clock word read through D_001A5CD0_0061ED80.f128 (retail forms &D_001A5CD0 and loads
 * 0x128 off it), the plain extern D_L39_0024118C (its absolute $at loads in the branches and the $gp-
 * relative one in the tail's delay slot both come out), ~0x80U (lui/ori mask), the bit-0 test as
 * ((u8)k->i148 ^ 1) & 1 (retail's lbu/xori/andi + beql), `s = len; if (cap < len) s = cap;` clamps,
 * 0.02 as (1.2f / 60.0f) (bits 0x3CA3D70B, written 0.020000002f elsewhere), tt converted in its own
 * variable, dist -= s; dist = fabs_asm(dist), and the i158/iE8/i148 store order.
 * Left: retail computes &k->vA0 into a2 before the func_0038CF00 call and copies it to s2 in the call's
 * delay slot (the GCSE copy of a value computed there); this draft's pv = &k->vA0 goes straight to s2,
 * one word short, which shifts every later word. Passing &k->vA0 as a third argument to
 * func_0038CF00 gives that copy and 7 diff (build/codex/wr23/func_L39_0061ED80.phantom3.c), but the
 * callee is handwritten with two parameters, so that form is not used here. The other few words: the
 * copy's slot, and `mov.s $f12` before `addiu $a0` at the two func_003C4360 calls of the branches.
 * Callee func_L39_0061F5A0 is declared unprototyped here (its definition comes later in the file with a
 * later block's struct type).
 */
#include "common.h"

/* localdecomp:start func_L39_0061ED80 */
#include "vu0.h"

typedef struct {
    vu0_v4 q[2];
    s32 t[2];
    s32 idx;
    u8 pad2C[4];
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    u8 padC0[0x28];
    s32 iE8;
    f32 fEC;
    f32 *pF0;
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x10];
    vu0_v4 q110[2];
    s32 pend[2];
    s32 i138;
    u8 pad13C[4];
    s32 i140;
    s32 i144;
    s32 i148;
    u8 pad14C[0xC];
    s32 i158;
    s32 i15C;
    vu0_v4 q160;
    vu0_v4 q170;
    vu0_v4 q180;
} U_0061ED80;
typedef struct { u8 p0[0x128]; s32 f128; } T_0061ED80;

extern T_0061ED80 D_001A5CD0_0061ED80;
extern f32 D_L39_0024118C;

void func_L39_0061ED80(U_0061ED80 *k, vu0_q *vec, s32 *tp) {
    extern void func_L39_0061F5A0();
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CED8(void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4360(f32 *, f32, f32, f32, f32);
    vu0_v4 old90;
    vu0_v4 oldA0;
    vu0_v4 p20;
    vu0_v4 p30;
    vu0_v4 p40;
    vu0_v4 p50;
    vu0_v4 p60;
    vu0_v4 *pv;
    s32 now;
    f32 d;
    f32 fa;
    f32 fb;
    f32 len;
    f32 cap;
    f32 dist;
    f32 tt;
    f32 z;

    fa = k->pF0[8];
    fb = k->pF0[9];
    if (k->i15C >= 0 && D_001A5CD0_0061ED80.f128 >= k->i15C) {
        k->q180 = k->q170;
        k->q170 = k->q160;
        k->i15C = -1;
    }
    if (vec != 0) {
        if ((*tp >> 9) != (k->i158 >> 9) && k->i158 != -1 && (*tp & 0x1FF) < 0x100) {
            k->q160 = *(vu0_v4 *)vec;
            k->i15C = *tp + 0xF5;
        }
        k->i158 = *tp;
        k->iE8 = 0;
        k->i148 &= ~0x80U;
        func_L39_0061F5A0(k, vec, *tp, 0);
    }
    now = D_001A5CD0_0061ED80.f128 - k->i144;
    if ((k->i148 & 0x40) && now >= k->i140) {
        k->iE8 = 0;
        k->i148 &= ~0x80U;
        func_L39_0061F5A0(k, &k->q110[k->i138], k->pend[k->i138], 1);
    }
    old90 = k->v90;
    oldA0 = k->vA0;
    pv = &k->vA0;
    d = func_0038CF00(&k->v80, &k->v90);
    if (now < k->iF8) {
        k->fEC = d;
    } else if (((u8)k->i148 ^ 1) & 1) {
        if (d < 0.2f || (0.0f < k->fEC && k->fEC < d && k->fEC < func_0038CEA8(pv))) {
            k->fEC = 0.0f;
            k->i148 |= 1;
        } else {
            k->fEC = d;
        }
    } else {
        k->fEC = d;
    }
    if (k->iE8 != 0 && now >= k->iE8) {
        k->iE8 = 0;
        k->i148 |= 0x80;
    }
    if (k->i148 & 0x80) {
        f32 s70;
        f32 l70;
        f32 c70;
        l70 = func_0038CED8(pv);
        c70 = k->pF0[6] * (1.2f / 60.0f);
        s70 = l70;
        if (c70 < l70) {
            s70 = c70;
        }
        func_003C4360(&s70, 0.0f, 0.0f, k->pF0[9] * 1.44f, c70);
        if (s70 < 0.0f) {
            s70 = 0.0f;
        }
        func_0038CFB8(pv, pv, s70);
        vec_add_ab(&k->v90, &k->v90, &k->vA0);
    } else if (k->i148 & 1) {
        f32 s74;
        tt = now - k->t[(k->idx + 1) % 2];
        tt = tt / (D_L39_0024118C * 1000.0f);
        cap = k->pF0[6];
        func_0038CE20(&p20, &k->v30, tt);
        func_0038CE20(&p30, &k->v40, tt * 0.5f * tt);
        vec_add_ba(&p40, &p20, &p30);
        vec_add_ba(&p50, &k->q[(k->idx + 1) % 2], &p40);
        k->v90.z = 0.0f;
        z = p50.z;
        p50.z = 0.0f;
        len = func_0038CED8(pv);
        cap = cap * (1.2f / 60.0f);
        s74 = len;
        if (cap < len) {
            s74 = cap;
        }
        vec_sub_ba(&p60, &p50, &k->v90);
        dist = func_0038CEA8(&p60);
        func_003C4360(&s74, dist, fa * 1.44f, fb * 1.44f, cap);
        func_0038CF68(&p60, &p60, s74);
        vec_add_ab(&k->v90, &k->v90, &p60);
        dist = dist - s74;
        dist = fabs_asm(dist);
        if (dist < cap * 0.01f) {
            k->v90 = p50;
        }
        k->v90.z = z;
    } else {
        f32 s78;
        tt = now - k->iF4;
        tt = tt / (D_L39_0024118C * 1000.0f);
        cap = k->pF0[7];
        func_0038CE20(&p20, &k->v50, tt);
        func_0038CE20(&p30, &k->v60, tt * 0.5f * tt);
        vec_add_ba(&p40, &p20, &p30);
        vec_add_ab(&p50, &k->v70, &p40);
        k->v90.z = 0.0f;
        z = p50.z;
        p50.z = 0.0f;
        len = func_0038CED8(pv);
        cap = cap * (1.2f / 60.0f);
        s78 = len;
        if (cap < len) {
            s78 = cap;
        }
        vec_sub_ba(&p60, &p50, &k->v90);
        dist = func_0038CEA8(&p60);
        func_003C4360(&s78, dist, fa * 1.44f, fb * 1.44f, cap);
        func_0038CF68(&p60, &p60, s78);
        vec_add_ab(&k->v90, &k->v90, &p60);
        dist = dist - s78;
        dist = fabs_asm(dist);
        if (dist < cap * 0.01f) {
            k->v90 = p50;
        }
        k->v90.z = z;
    }
    if (now != k->iFC) {
        f32 inv;
        inv = 1.0f / ((f32)(now - k->iFC) / (D_L39_0024118C * 1000.0f));
        vec_sub_ab(pv, &old90, &k->v90);
        func_0038CE20(pv, pv, inv);
        vec_sub_ba(&k->vB0, &oldA0, pv);
        func_0038CE20(&k->vB0, &k->vB0, inv);
        k->iFC = now;
    }
}
/* localdecomp:end func_L39_0061ED80 */
