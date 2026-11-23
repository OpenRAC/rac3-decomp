/* PAL near miss (haiku-w5): 4 words differ with the file's flags; the two float parameters width ($f12) and speed ($f14) get the callee-saved $f21/$f22 the other way round at entry (mov.s) and in their two stores. The signature is the one block func_L01_00475278 declares (u8 *, void *, void *, s32, f32, s32, s32, s32, s32, f32, f32), which the matching draft's prototype conflicted with in the full file (conflicting types); this version compiles there. divs_nops row 2 is in use. */
#include "common.h"
typedef int Quad_00475128 __attribute__((mode(TI)));
typedef struct {
    Quad_00475128 v;
    s32 owner;
    f32 scale, speed;
    u8 alpha, mode, flag;
} Sub_00475128;
typedef struct {
    u8 type, flags, texture, render;
    s32 rgba;
    u8 spin, render2;
    s16 life;
    f32 age;
    Quad_00475128 position;
    Sub_00475128 sub;
} Part_00475128;
extern u8 *D_L01_00221288[];
u8 *func_L01_00475128(s32 owner, void *pos_, void *vel_, s32 color, f32 width,
                      s32 life_, s32 flag_, s32 mode_, s32 texture_, f32 age, f32 speed)
{
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 fe_func_00443948(s32);
    Part_00475128 *p;
    Sub_00475128 *q;
    Quad_00475128 *pos = (Quad_00475128 *)pos_;
    Quad_00475128 *vel = (Quad_00475128 *)vel_;
    u8 flag = flag_, mode = mode_, texture = texture_;
    s32 life = life_;
    p = (Part_00475128 *)func_L01_004618E0(0x7C);
    if (p) {
        p->flags=0;
        p->render2=0x44;
        p->render=0x48;
        p->spin=fe_func_00443948(0x100);
        p->age=age;
        p->texture=D_L01_00221288[0][texture];
        p->rgba=color;
        p->life=life;
        p->position=*pos;
        ((f32 *)&p->position)[3]=1.0f/(f32)life;
        q=&p->sub;
        q->owner=owner;
        q->v=*vel;
        /* The store order is a scheduling lever: gcc issues the last store of the
         * run to one base first and the rest in source order, so writing these
         * backwards of retail is what reproduces retail's at 0x00475210. */
        ((f32 *)&q->v)[3]=width;
        q->scale=age;
        q->speed=speed;
        q->alpha=color>>24;
        q->flag=flag;
        q->mode=mode;
    }
    return (u8 *)p;
}
