/* Level 4 (Marcadia), file L04_003E6018.c. Needs -mvu0-use-vf0-vf2 and @ps2as on that file (VU0 vector adds and inline float constants); with them func_L04_003E6018 needs `__asm__(".extern D_L04_001DF2A0, 4");` to keep its $gp address (checked in the level 04 build). check.py with those flags: 40 diff (42 aligned). Left: the scheduler reorders two store groups that retail keeps in source order (v->15E/v->150, and v->82, C8, 140, 30, 81 after func_L01_004450F0; every permutation of the five gives the same output), and the hit-damage block (retail loads h->dmg before the owner test and shares the multiply). Stopped per AGENTS.md. */
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
            v->f15E = 2;
            v->f150 = -1;
            t->f0(m);
            return;
        }
        func_L01_004450F0(m, 1, -1);
        v->f82 = 0xFF;
        v->fC8 = 0.01f;
        v->f140 = 0;
        v->f30 = v->f34;
        v->f81 = 0xFF;
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
        if (v->f118 != 0.0f && h->owner != 0 && h->owner->oClass == m->oClass) {
            h->dmg *= v->f118;
        }
    } else {
        h = func_L01_00447490(m, -1, 0);
        if (h != 0) {
            h->dmg *= 0.5f;
            if (v->f118 != 0.0f && h->owner != 0 && h->owner->oClass == m->oClass) {
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
        pos = m->pos;
        func_0038CF68(&t1, &m->fD0, -2.0f);
        vec_add_ba(&pos, &t1, &pos);
        func_0038CF68(&t2, &m->fC0, 1.5f);
        vec_add_ab(&pos, &t2, &pos);
        func_L04_00325460(&pos, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.75f, 20.0f, 1, 0, 0, 0);
        func_003A52A0(0, 0, m);
        func_L04_003E6308((u8 *)m, 1);
    }
}
/* localdecomp:end func_L04_003E6038 */
