/* functional: high. 3-word diff: order of one lq vs sw only; same behaviour. */
#include "common.h"
/* localdecomp:start func_L01_003949E8 */
typedef struct { s128 direction; s128 origin; u8 pad20[0x10]; f32 random; s32 timer; s32 owner; f32 value; s32 kind; s32 zero44; s32 zero48; s32 effect; } Vars_003949E8;
typedef struct { u8 pad0[0x10]; s128 position; u8 state; u8 pad21[0xf]; u8 update; u8 pad31; u16 distance; u16 flags; u8 pad36[0x32]; Vars_003949E8 *vars; u8 pad6c[0x2c]; s32 zero98; } Moby_003949E8;
Moby_003949E8 *func_L01_003949E8(s32 owner, s128 *position, s128 *direction, s32 kind, f32 value) {
    extern void *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern s32 func_L01_004C85C8(void *, void *, f32, f32, f32);
    extern void func_L01_004AA7E8(void *, s32);
    Moby_003949E8 *m=func_003C24B0(0x1890,0x80);
    if (m) {
        Vars_003949E8 *v;
        m->state=0;
        m->distance=255;
        m->update=255;
        v=m->vars;
        m->position=*position;
        v->kind=kind;
        v->direction=*direction;
        v->owner=owner;
        v->random=func_00382538();
        v->value=value;
        v->timer=0;
        v->zero44=0;
        v->zero48=0;
        v->origin=*position;
        v->effect=func_L01_004C85C8(m,0,1.0f,1.0f,1.0f);
        m->zero98=0;
        m->flags |= 0x41;
        m->flags &= 0xefff;
        func_L01_004AA7E8(m,1);
    }
    return m;
}
/* localdecomp:end func_L01_003949E8 */
