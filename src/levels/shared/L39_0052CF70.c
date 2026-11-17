#include "common.h"

/* declared by functions of L39_0052CE80.c, which this file was cut from */
typedef struct { u8 pad[0x90]; s32 f90; } R_0052CE80;
extern R_0052CE80 *func_L39_005422E8(f32, void *, s32, void *, s32, s32, s32, s32);

/* localdecomp:start func_L39_0052CF70 */
/* Log: needs --flags=-mvu0-use-vf0-vf2 --mode S --as ps2as. Compared with retail ignoring nops: every instruction equal; the only
   difference is retail's 'nop nop' before each of the two div.s (no row in config/levels/divs_nops.txt for this function: counts 2 2).
   Keys: compare o->f2B0 directly (not through a local), f21 declared in the if block, k = m->w2548 then 'if (w180 == 2) k = 0'
   (movz), 'o->w1D8 == 0 ? 0xA : 0xB' (movn), the u32 -1 argument, sda float with section(".sdata") + .extern 4. */
#include "vu0.h"

typedef struct Aux_0052CF70 {
    u8 pad0[0x1A0];
    u32 w1A0;
} Aux_0052CF70;

typedef struct Sub2_0052CF70 {
    s32 w0;
    u8 pad4[0x320 - 4];
    s16 h320;
    u8 pad322[0x2534 - 0x322];
    Aux_0052CF70 *p2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 w2548;
} Sub2_0052CF70;

typedef struct Sub1_0052CF70 {
    u8 pad0[0x2D8];
    Sub2_0052CF70 *p2D8;
} Sub1_0052CF70;

typedef struct Obj_0052CF70 {
    u8 pad0[0x1D8];
    s32 w1D8;
    s32 w1DC;
    u8 pad1E0[0x1F8 - 0x1E0];
    Sub1_0052CF70 *p1F8;
    u8 pad1FC[4];
    u8 b200[0x10];
    u8 pad210[0x28C - 0x210];
    s32 w28C;
    u8 pad290[0x2A0 - 0x290];
    f32 f2A0[4];
    f32 f2B0;
    u8 pad2B4[0x310 - 0x2B4];
    vu0_q q310;
} Obj_0052CF70;

typedef struct Self_0052CF70 {
    u8 pad0[0x68];
    Obj_0052CF70 *p68;
} Self_0052CF70;

typedef struct Dst2_0052CF70 {
    u8 pad0[0x30];
    s32 w30;
} Dst2_0052CF70;

typedef struct Dst_0052CF70 {
    u8 pad0[0x68];
    Dst2_0052CF70 *p68;
    u8 pad6C[0x90 - 0x6C];
    s32 w90;
} Dst_0052CF70;

typedef struct Glob_0052CF70 {
    u8 pad0[0x180];
    s32 w180;
} Glob_0052CF70;

extern Glob_0052CF70 *D_001D5F30_sda;
/* per-function alias: the file declares D_L39_0024AAE0 without a section, which this function reads through $gp */
extern f32 D_L39_0024AAE0_0052CF70 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AAE0_0052CF70, 4");
extern s32 func_0038CAD0(void *);
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L39_005BE878(s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003F1F20(s32, void *);
extern s32 func_L39_0066E010(void *, s32, void *, s32, void *);

void func_L39_0052CF70(Self_0052CF70 *self) {
    Obj_0052CF70 *o = self->p68;
    Sub2_0052CF70 *m = o->p1F8->p2D8;
    struct {
        u8 m[0x30];
        vu0_q v30;
        vu0_q v40;
        vu0_q v50;
        vu0_q v60;
    } L;
    f32 f20;
    f32 d;
    Dst_0052CF70 *r;
    Glob_0052CF70 *g;
    s32 k;

    func_0038CAD0(&o->w1DC);
    if (o->w1DC > 0) {
        return;
    }
    if (m->h320 > 0) {
        return;
    }
    if ((m->p2534->w1A0 & 0xA8) == 0) {
        return;
    }
    func_003C2EC0(self, o->w1D8, &L);
    if (o->f2B0 >= 0.9f) {
        f32 f21;

        f20 = (o->f2B0 - 0.9f) / 0.100000024f;
        f21 = func_0038CF00(&L.v30, &o->q310) / 1.5000001f;
        func_L39_005BE878(o->w28C, &L.v50, 0);
        func_0038CE20(&L.v60, o->f2A0, f21 * f20);
        vec_add_ab(&L.v50, &L.v50, &L.v60);
    } else {
        L.v50 = o->q310;
    }
    vec_sub_ab(&L.v40, &L.v50, &L.v30);
    d = func_0038CE68(&L.v40, &L);
    if (d > 0.0f) {
        func_0038CF68(&L.v40, &L.v40, 1.5000001f);
    } else {
        func_0038CF68(&L.v40, o->b200, 1.5000001f);
    }
    g = D_001D5F30_sda;
    k = m->w2548;
    if (g->w180 == 2) {
        k = 0;
    }
    r = ((Dst_0052CF70 *(*)(f32, void *, void *, void *, s32, u32, s32, s32))func_L39_005422E8)(D_L39_0024AAE0_0052CF70, self, &L.v40, &L.v30, 0, -1, 1, k);
    func_L01_003F1F20(0x1B, m->p2534);
    if (r != 0) {
        r->w90 = m->w0;
        r->p68->w30 = func_L39_0066E010(m, o->w1D8 == 0 ? 0xA : 0xB, r, 0, &L.v40);
    }
    o->w1D8 = (o->w1D8 + 1) & 1;
    o->w1DC = 7;
}
/* localdecomp:end func_L39_0052CF70 */
