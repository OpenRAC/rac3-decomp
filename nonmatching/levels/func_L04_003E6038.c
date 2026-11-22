/* Level 4 (Marcadia), file L04_003E6018.c. Promises fleet near miss (2026-11-20), reworked 2026-11-21 (tasks 2784, 2796).
 * Needs -mvu0-use-vf0-vf2 and @ps2as on that file (VU0 vector adds via include/vu0.h's j-form helpers, inline float
 * constants); with them func_L04_003E6018 needs `__asm__(".extern D_L04_001DF2A0, 4");` to keep its $gp address
 * (checked in the level 04 build on 2026-11-20). check.py --as ps2as --flags=-mvu0-use-vf0-vf2: 6 diff (4 aligned;
 * the 2026-11-20 draft: 40 diff, 36 aligned).
 * Found: the two store groups come out in retail's order when written v->150, v->15E and C8, 140, 30, 81, 82 (found by
 * trying all 120 orders of the five); the hit-damage blocks read h->dmg into a local first (`d = h->dmg;` before the
 * tests in the first, `d = h->dmg; h->dmg = d * 0.5f;` in the second) and compare `m->oClass == h->owner->oClass`;
 * a `vu0_v4 *pp = &pos;` local gives retail's $s0 for &pos.
 * Left: in the last block retail sets the stack argument (`li $v0, 1`) after the two float constants and the last
 * sqc2; here it comes first. Tried: four prototype orders for func_L04_00325460 (including L20_003F1A78.c's
 * EABI-equivalent one), u8/s16 types for the stack arguments, &pos or pp at each use, one temporary for both scaled
 * vectors, vec_add_ab/ba swapped: no gain.
 * Task 2796: the sched2 dump (-fsched-verbose-5) shows a tie. When the vadd issues, the `li $v0, 1` and the two float
 * constant loads are all ready at priority 8; the li wins on dependents (4: its `sw` and the three later calls,
 * against 3 for each constant), so it goes first. All 182 positions of the two f32 parameters in
 * func_L04_00325460's prototype give 6 diff; so do separate or block-local variables for the constants (the
 * constant-1 locals hoisted to the top give 25), and floats in locals. Stopped per AGENTS.md.
 * LV-R2 retry (2026-11-22): 6 differences (tools/check.py) at level 04 with -mvu0-use-vf0-vf2 @ps2as (the 'aligned' figures above are older wording; r3-46 counts are tools/check.py's).
 */
/* RT-B retry (2026-11-22, rac3-w1, upstream b7be60ac): the whole-file line this needs cannot ship. With
 * `-mvu0-use-vf0-vf2 @ps2as` on L04_003E6018.c, Clank700's matched func_L04_003E6018 gives 4 differences at all five
 * placements (04, 12, 18, 26, 29); `-mvu0-use-vf0-vf2` alone keeps it matching, but this draft is then 142 (the
 * default assembler fills one `jal` delay slot that retail leaves as `jal; nop`, and every later word shifts).
 * With both flags it is still 6. */
#include "common.h"

/* localdecomp:start func_L04_003E6038 */
#include "vu0.h"

typedef struct {
    void (*f0)(void *);
} Tbl_L04_003E6038;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    s16 f36;
    u8 pad38[0x38];
    u8 f70;
    u8 pad71[0x10];
    u8 f81;
    u8 f82;
    u8 pad83[0x45];
    f32 fC8;
    u8 padCC[0x4C];
    f32 f118;
    u8 pad11C[0x14];
    u8 f130;
    u8 pad131[0xF];
    s32 f140;
    u8 pad144[0xC];
    s32 f150;
    u8 pad154[0xA];
    u8 f15E;
} Vars_L04_003E6038;

typedef struct Moby_L04_003E6038 Moby_L04_003E6038;
typedef struct {
    u8 pad0[0x20];
    Moby_L04_003E6038 *owner;
    u8 pad24[0x2C - 0x24];
    f32 dmg;
} Hit_L04_003E6038;

struct Moby_L04_003E6038 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    Vars_L04_003E6038 *vars;
    u8 pad6C[0xA8 - 0x6C];
    u8 fA8;
    u8 padA9;
    s16 oClass;
    u8 padAC[0xC0 - 0xAC];
    vu0_v4 fC0;
    vu0_v4 fD0;
};

extern void func_L04_004DB090(void *);
extern Tbl_L04_003E6038 *func_L01_0043B548(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern Hit_L04_003E6038 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_00455E18(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L04_003E6308(u8 *, s32);

void func_L04_003E6038(Moby_L04_003E6038 *m) {
    Vars_L04_003E6038 *v = m->vars;
    Hit_L04_003E6038 *h;
    f32 d;
    vu0_v4 pos;
    vu0_v4 t2;
    vu0_v4 t1;

    switch (m->state) {
    case 0:
        func_L04_004DB090(m);
        if (v->f150 > 0) {
            Tbl_L04_003E6038 *t = func_L01_0043B548(0x19E1, 0x6C);
            v->f150 = -1;
            v->f15E = 2;
            t->f0(m);
            return;
        }
        func_L01_004450F0(m, 1, -1);
        v->fC8 = 0.01f;
        v->f140 = 0;
        v->f30 = v->f34;
        v->f81 = 0xFF;
        v->f82 = 0xFF;
    case 1:
        break;
    default:
        return;
    }
    func_L01_0044ABD0(m, &v->f70);
    h = func_L01_00447490(m, 1, 1);
    if (func_0038CB00(&v->f36) == 0) {
        h = 0;
    }
    if (h != 0) {
        d = h->dmg;
        if (v->f118 != 0.0f && h->owner != 0 && m->oClass == h->owner->oClass) {
            h->dmg = d * v->f118;
        }
    } else {
        h = func_L01_00447490(m, -1, 0);
        if (h != 0) {
            d = h->dmg;
            h->dmg = d * 0.5f;
            if (v->f118 != 0.0f && h->owner != 0 && m->oClass == h->owner->oClass) {
                h->dmg *= v->f118;
            }
        }
    }
    m->fA8 = 0xFF;
    d = func_L01_004474E8(m, h);
    m->fA8 = 0xFF;
    v->f30 -= d;
    if (func_L01_00455E18(m, &v->f130, &v->f30) != 0) {
        func_003A52A0(0, 0, m);
    }
    if (v->f30 <= 0.0f) {
        vu0_v4 *pp = &pos;
        pos = m->pos;
        func_0038CF68(&t1, &m->fD0, -2.0f);
        vec_add_ba(pp, &t1, pp);
        func_0038CF68(&t2, &m->fC0, 1.5f);
        vec_add_ab(pp, &t2, pp);
        func_L04_00325460(pp, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.75f, 20.0f, 1, 0, 0, 0);
        func_003A52A0(0, 0, m);
        func_L04_003E6308((u8 *)m, 1);
    }
}
/* localdecomp:end func_L04_003E6038 */
