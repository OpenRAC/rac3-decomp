#include "common.h"

/* localdecomp:start func_L13_004429F0 */
#include "vu0.h"
typedef struct {
    u8 type;        /* 0x00 */
    s8 flags;       /* 0x01 */
    u8 texture;     /* 0x02 */
    u8 render;      /* 0x03 */
    u32 rgba;       /* 0x04 */
    u8 spin;        /* 0x08 */
    u8 render2;     /* 0x09 */
    s16 life;       /* 0x0A */
    u32 end_rgba;   /* 0x0C */
    vu0_v4 pos;     /* 0x10 */
    vu0_v4 end;     /* 0x20 */
    vu0_v4 vel;     /* 0x30 */
} P_004429F0;
extern u8 *D_L13_0021EF18[];
extern P_004429F0 *func_L01_004618E0(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
void func_L13_004429F0(vu0_v4 *pos, s32 type, vu0_v4 *vel, f32 scale) {
    vu0_v4 v;
    vu0_v4 *vp;
    vu0_v4 d;
    vu0_v4 end;
    vu0_v4 t;
    P_004429F0 *p;
    s32 a;
    s32 idx;
    f32 grow;
    f32 spd;
    vp = &v;
    v = *vel;
    p = func_L01_004618E0(0);
    if (p == 0) {
        return;
    }
    a = 0;
    grow = 0.0f;
    spd = grow;
    idx = type;
    switch (type) {
    case 0:
        a = 0x14;
        grow = 0.015f;
        spd = func_003824E0(0.01f, 1.0f);
        break;
    case 1:
        a = 0xD;
        grow = 0.5f;
        spd = func_003824E0(1.0f, 5.0f);
        break;
    case 2:
        a = 0xD;
        idx = 1;
        grow = 1.0f;
        spd = func_003824E0(20.0f, 30.0f);
        break;
    }
    d = *vp;
    func_0038CF68(&d, &d, spd);
    p->life = type;
    p->rgba = ((a >> 2) << 24) | 0x606060;
    p->end_rgba = (a << 24) | 0x907070;
    p->render2 = 100;
    p->render = 0x44;
    p->flags = 3;
    p->texture = D_L13_0021EF18[0][idx];
    p->pos = *pos;
    vec_add_ab(&t, pos, &d);
    end = t;
    p->end = end;
    p->pos.w = grow;
    p->end.w = 1.0f;
    p->vel = *vp;
    p->vel.w = scale;
}
/* localdecomp:end func_L13_004429F0 */
