#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033CBC0 */
typedef struct Obj_33CBC0 Obj_33CBC0;
typedef struct Aux_33CBC0 Aux_33CBC0;
struct Aux_33CBC0 {
    u8 pad0[0x70];
    f32 v70[4];
    u8 pad80[0x40];
    f32 vc0[4];
    Obj_33CBC0 *wd0;
    Obj_33CBC0 *wd4;
    u8 padd8[4];
    s32 wdc;
    f32 fe0;
    s32 we4;
    u8 pade8[0x18];
    f32 v100[4];
    f32 v110[4];
    s32 w120;
    f32 f124;
    u8 pad128[4];
    Obj_33CBC0 *w12c;
};
struct Obj_33CBC0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 b20;
    u8 pad21[0x15];
    s16 h36;
    u8 pad38[0x30];
    Aux_33CBC0 *aux;
    u8 pad6C[0x3E];
    s16 haa;
    u8 padAC[0x10];
    u8 bbc;
    u8 padBD[3];
    f32 mat[12];
    f32 vf0[4];
};
typedef struct {
    u8 pad0[0x270];
    f32 f270;
    u8 pad274[0x10];
    f32 f284;
} Hero_33CBC0;

extern s32 D_L01_001DFB40;
extern Hero_33CBC0 D_001A4BE0;
extern f32 D_001A4C60[];
extern u8 D_L01_001EAA20[];
extern s32 func_003C4B50(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0033C520(void *, s32, s32);
extern void func_L01_0033C030(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
extern s32 func_003C4D58(void *);
extern void func_003C4DA8(void *, void *, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern f32 func_0038CEA8(void *);

void func_L01_0033CBC0(Obj_33CBC0 *o) {
    f32 pa[4];
    f32 pb[4];
    f32 pc[4];
    f32 d[4];
    f32 loc[4];
    f32 old[4];
    f32 savf0[4];
    f32 delta[4];
    Obj_33CBC0 *next;
    Obj_33CBC0 *root;
    Aux_33CBC0 *a;
    u8 *zv;
    s32 hit;
    f32 t;
    u8 k1;
    u8 k2;

    if (o->b20 == 0) {
        return;
    }
    a = o->aux;
    if (a->we4 == D_L01_001DFB40) {
        return;
    }
    next = o;
    do {
        root = next;
        next = root->aux->wd4;
    } while (next != 0);
    next = root;
    do {
        o = next;
        a = o->aux;
        zv = D_L01_001EAA20;
        next = a->wd0;
        if (!(a->wdc & 4)) {
            a->wdc &= ~0x10;
        }
        a->wdc &= ~4;
        if (func_003C4B50(o) == 0) {
            return;
        }
        if (a->wdc & 2) {
            return;
        }
        a->we4 = D_L01_001DFB40;
        if (o->b20 != 0) {
            vec_sub_ab(d, D_001A4C60, o->pos);
            func_0038D000(d, d, o->mat);
            if (fabs_asm(d[0]) < 0.55f && fabs_asm(d[1]) < 0.55f && d[2] < 0.0f) {
                if (-(((Hero_33CBC0 *)((u8 *)D_001A4C60 - 0x80))->f270 + ((Hero_33CBC0 *)((u8 *)D_001A4C60 - 0x80))->f284) < d[2]) {
                    if (o->b20 == 1 || o->b20 == 5) {
                        func_L01_0033C520(o, o->haa == 0x1F9, 0);
                        func_L01_0033C030(o);
                    }
                }
            }
            a->vc0[2] -= 0.00392f;
            a->vc0[2] = a->vc0[2] < -0.3f ? -0.3f : a->vc0[2];
            a->vc0[2] = a->vc0[2] > 0.3f ? 0.3f : a->vc0[2];
            if (a->w120 != 0) {
                if (a->wd4 == 0) {
                    a->vc0[3] -= 0.004f;
                    t = func_003C4138(&a->f124, 0.0f, fabs_asm(a->vc0[3]));
                    if (t == 0.0f) {
                        a->vc0[3] = 0.0f;
                    }
                } else {
                    a->vc0[3] -= 0.004f;
                    t = func_003C4138(&a->f124, a->wd4->aux->f124 + 1.0f, fabs_asm(a->vc0[3]));
                    if (t == 0.0f) {
                        a->vc0[3] = 0;
                    }
                }
                *(vu0_q *)loc = *(vu0_q *)a->v100;
                loc[2] += a->f124;
                if (o != 0) {
                    o->h36 = 0x7F80;
                }
                *(vu0_q *)old = *(vu0_q *)o->pos;
                *(vu0_q *)savf0 = *(vu0_q *)o->vf0;
                func_L01_0044C998(o, (void *)a->w120, loc, a->v110, o->pos, o->vf0);
                if (*(s32 *)(func_003C4D58((void *)a->w120) + 0x3C) & 4) {
                    *(vu0_q *)a->v100 = *(vu0_q *)loc;
                    a->v100[2] -= a->f124;
                }
                vec_sub_ab(delta, o->pos, old);
                delta[3] = a->vc0[3];
                *(vu0_q *)a->vc0 = *(vu0_q *)delta;
                func_003C4DA8(a->v70, a->vc0, savf0, o->vf0);
                if (a->w12c != 0) {
                    *(vu0_q *)a->w12c->pos = *(vu0_q *)o->pos;
                }
            } else {
                if (a->wd4 != 0) {
                    t = func_0038CF38(o->pos, a->wd4->pos);
                    if (t > 0.707f) {
                        hit = 0;
                        a->wd4 = 0;
                    } else {
                        hit = 0;
                        *(vu0_q *)pc = *(vu0_q *)a->wd4->pos;
                        pc[2] += 1.0f;
                        if (o->pos[2] + a->vc0[2] < pc[2]) {
                            hit = 1;
                        }
                    }
                }
                if (a->wd4 == 0) {
                    *(vu0_q *)pa = *(vu0_q *)o->pos;
                    *(vu0_q *)pb = *(vu0_q *)o->pos;
                    pa[2] += a->fe0 * 0.75f;
                    pb[2] += a->vc0[2];
                    hit = func_003D3CB0(pa, pb, 2, 0, 0);
                    *(vu0_q *)pc = *(vu0_q *)zv;
                }
                if (hit != 0) {
                    if (a->wdc & 0x20) {
                        if (func_0038CEA8(a->vc0) > 0.010000001f) {
                            if (o->haa == 0x1F9 && o->b20 == 1) {
                                k1 = 5;
                                o->b20 = k1;
                                k1 = 0;
                                o->bbc = k1;
                            } else if (a->wd4 != 0) {
                                if (a->wd4->haa == 0x1F9) {
                                    if (a->wd4->b20 == 1) {
                                        k2 = 5;
                                        a->wd4->b20 = k2;
                                        k2 = 0;
                                        a->wd4->bbc = k2;
                                    }
                                }
                            }
                        }
                    }
                    o->pos[2] = pc[2];
                    a->vc0[2] = 0;
                } else {
                    a->wdc |= 4;
                    vec_add_ab(o->pos, o->pos, a->vc0);
                }
            }
        }
    } while (next != 0);
}
/* localdecomp:end func_L01_0033CBC0 */
