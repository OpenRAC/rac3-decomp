#include "common.h"

/* localdecomp:start func_L39_0052CA90 */
#include "vu0.h"

typedef struct Sub3_0052CA90 {
    u8 pad0[0x10];
    vu0_q q10;
} Sub3_0052CA90;

typedef struct Sub2_0052CA90 {
    u8 pad0[0xA0];
    vu0_q qA0;
    vu0_q qB0;
    u8 padC0[0x424 - 0xC0];
    Sub3_0052CA90 *p424;
} Sub2_0052CA90;

typedef struct Sub1_0052CA90 {
    u8 pad0[0x250];
    vu0_q q250;
    u8 pad260_[0];
    vu0_q q260;
    u8 pad270[0x2D8 - 0x270];
    Sub2_0052CA90 *p2D8;
} Sub1_0052CA90;

typedef struct Obj_0052CA90 {
    u8 pad0[0x1F8];
    Sub1_0052CA90 *p1F8;
} Obj_0052CA90;

typedef struct Self_0052CA90 {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 pad20[0x68 - 0x20];
    Obj_0052CA90 *p68;
    u8 pad6C[0xC0 - 0x6C];
    u8 bC0[0x30];
    vu0_q qF0;
} Self_0052CA90;

extern vu0_v4 D_L39_0024AAF0;
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L39_00632180(void *, void *, s32, f32, f32, f32);

void func_L39_0052CA90(Self_0052CA90 *self) {
    Obj_0052CA90 *o = self->p68;
    vu0_v4 v;

    if (o->p1F8->p2D8 != 0) {
        func_0038D308(self->bC0, &self->qF0);
        func_0038D000(&v, &D_L39_0024AAF0, self->bC0);
        vec_add_ab(&v, &v, &self->v10);
        o->p1F8->q250 = *(vu0_q *)&v;
        o->p1F8->p2D8->qA0 = *(vu0_q *)&v;
        o->p1F8->q260 = self->qF0;
        o->p1F8->p2D8->qB0 = self->qF0;
        o->p1F8->p2D8->p424->q10 = *(vu0_q *)&v;
        func_0038D308((u8 *)o->p1F8->p2D8->p424 + 0xC0, &o->p1F8->p2D8->qB0);
        func_L39_00632180(o->p1F8->p2D8, (u8 *)o->p1F8->p2D8 + 0xE0, 1, 0.0f, 0.0f, 0.7f);
    }
}
/* localdecomp:end func_L39_0052CA90 */
