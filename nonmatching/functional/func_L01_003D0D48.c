/* functional: low. Near miss with ~300 word diffs; the earlier declaration of callee func_L01_003D22A8(void) hides retail's object argument, so verify argument passing before gating. */
#include "common.h"
/* localdecomp:start func_L01_003D0D48 */
#include "vu0.h"
#include "structs/hero.h"
typedef struct {u8 pad0[0x86]; s16 mode;} Camera_003D0D48;
typedef struct {u8 pad0[0x33C]; f32 speed; u8 pad340[0x35C-0x340]; s32 locked;} Hero_003D0D48;
typedef struct {u8 pad0[0x50]; s32 active; f32 distance,blend; u8 pad5C[0x140-0x5C]; vu0_v4 target,pad150,offset,rotation;} State_003D0D48;
extern Camera_003D0D48 *D_L01_001E2A90;
extern vu0_v4 D_L01_001E2A40[2];
extern struct Hero D_001A4BE0;
extern u8 D_001A4C60[];
extern f32 D_L01_001DF288,D_L01_001DF28C,D_L01_001DF290,D_L01_001DF294,D_L01_001DF298,D_L01_001DF29C,D_L01_001DF2A0,D_L01_001DF2A4,D_L01_001DF2A8,D_L01_001DF2AC,D_L01_001DF2B0,D_L01_001DF2B4,D_L01_001DF2B8;
__asm__(".extern D_L01_001DF288, 4");
__asm__(".extern D_L01_001DF28C, 4");
__asm__(".extern D_L01_001DF290, 4");
__asm__(".extern D_L01_001DF294, 4");
__asm__(".extern D_L01_001DF298, 4");
__asm__(".extern D_L01_001DF29C, 4");
__asm__(".extern D_L01_001DF2A0, 4");
__asm__(".extern D_L01_001DF2A4, 4");
__asm__(".extern D_L01_001DF2A8, 4");
__asm__(".extern D_L01_001DF2AC, 4");
__asm__(".extern D_L01_001DF2B0, 4");
__asm__(".extern D_L01_001DF2B4, 4");
__asm__(".extern D_L01_001DF2B8, 4");
void func_L01_003D0D48(u8 *obj,State_003D0D48 *state,s32 enabled) {
    extern void func_L01_003EB438(s32,void *,void *,s32,s32,s32);
    extern void func_L01_003EB5E0(s32,s32);
    extern void func_L01_003D22A8(void);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CDF8(void *,void *,void *,f32);
    extern f32 func_0038DB00(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_L01_003EB350(s32,void *);
    extern void func_L01_003EB3C0(s32,void *);
    vu0_v4 diff,forward,right,up,position,rotation;
    f32 side,angle,blend,height,distance,projection;
    if(state->active && D_L01_001E2A90->mode!=5) state->active=0;
    if(state->active!=enabled) {
        if(enabled) {
            func_L01_003EB438(0,&D_L01_001E2A40[0],&D_L01_001E2A40[1],1,0,0);
            vec_sub_ab(&state->offset,&D_L01_001E2A40[0],D_001A4C60);
            state->rotation= D_L01_001E2A40[1];
            state->blend=0;
            func_L01_003D22A8();
        } else func_L01_003EB5E0(0,1);
        state->active=enabled;
        return;
    }
    if((*(Hero_003D0D48 *)&D_001A4BE0).speed<D_L01_001DF2A8 && !(*(Hero_003D0D48 *)&D_001A4BE0).locked) {
        blend=0;
        angle=D_L01_001DF2B4*0.01745329238474369f;
        side=D_L01_001DF2B0;
        height=D_L01_001DF2AC;
    } else if((*(Hero_003D0D48 *)&D_001A4BE0).speed<D_L01_001DF2A4 && !(*(Hero_003D0D48 *)&D_001A4BE0).locked) {
        blend=((*(Hero_003D0D48 *)&D_001A4BE0).speed-D_L01_001DF2A8)/(D_L01_001DF2A4-D_L01_001DF2A8);
        angle=(D_L01_001DF2B4+(D_L01_001DF290-D_L01_001DF2B4)*blend)*0.01745329238474369f;
        side=D_L01_001DF2B0+(D_L01_001DF28C-D_L01_001DF2B0)*blend;
        height=D_L01_001DF2AC+(D_L01_001DF288-D_L01_001DF2AC)*blend;
    } else {
        if(state->blend<1.0f) {
            f32 x,step;
            func_L01_003D22A8();
            x=D_L01_001DF2B8;
            step=(1.0f-state->blend)*((x*0.6743000149726868f+x*0.436599999666214f*x)-x*0.10989999771118164f*x*x);
            if(step<0.002f) step=0.002f;
            state->blend+=step;
            if(state->blend>1.0f) state->blend=1.0f;
            angle=D_L01_001DF290*0.01745329238474369f;
            blend=state->blend;
            side=D_L01_001DF28C;
            height=D_L01_001DF288;
        } else {
            func_L01_003D22A8();
            blend=1.0f;
            angle=D_L01_001DF290*0.01745329238474369f;
            side=D_L01_001DF28C;
            height=D_L01_001DF288;
        }
    }
    vec_sub_ba(&diff,&state->target,D_001A4C60);
    distance=func_0038CEA8(&diff);
    func_0038CF68(&diff,&diff,1.0f);
    { f32 ratio=distance/state->distance;
    distance=ratio*blend; }
    { f32 forward_amount=func_0038CE68(&diff,obj+0xC0)*distance;
    if(forward_amount<0.0f) func_0038CE20(&forward,obj+0xC0,side+forward_amount*D_L01_001DF294);
    else func_0038CE20(&forward,obj+0xC0,side+forward_amount*D_L01_001DF298); }
    { f32 right_amount=func_0038CE68(&diff,obj+0xD0)*distance;
    if(right_amount>=0.0f) func_0038CE20(&right,obj+0xD0,right_amount*D_L01_001DF29C);
    else func_0038CE20(&right,obj+0xD0,right_amount*D_L01_001DF2A0); }
    func_0038CE20(&up,obj+0xE0,height);
    vec_add_ba(&position,&forward,&right);
    vec_add_ab(&position,&position,&up);
    if(state->blend<1.0f) func_0038CDF8(&position,&state->offset,&position,state->blend);
    vec_add_ab(&position,&position,D_001A4C60);
    qzero(&rotation);
    rotation.y=angle;
    rotation.z=*(f32 *)(obj+0xF8);
    if(state->blend<1.0f) {
        projection=func_0038DB00(rotation.x,state->rotation.x);
        rotation.x=func_0038DAB8(state->rotation.x,projection*state->blend);
        projection=func_0038DB00(rotation.y,state->rotation.y);
        rotation.y=func_0038DAB8(state->rotation.y,projection*state->blend);
        projection=func_0038DB00(rotation.z,state->rotation.z);
        rotation.z=func_0038DAB8(state->rotation.z,projection*state->blend);
    }
    func_L01_003EB350(0,&position);
    func_L01_003EB3C0(0,&rotation);
}
/* localdecomp:end func_L01_003D0D48 */
