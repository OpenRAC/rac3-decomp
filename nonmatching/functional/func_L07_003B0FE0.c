/* functional: high. From PAL near-miss draft (goto layout copies retail's flow); I traced every block against PAL asm: list walk and end tests, 0x7FFF index mask, (rand+20)*5+2)/6 timer, group[]/special[] stores, angle 2x radius, 1.5708 step, owner-facing atan. Note retail dereferences a null angle pointer if func_L07_003343E8(i) is neither 0 nor 1; the C does too (kept). 142 diff = frame 0x90 vs 0x80 and allocation. */
#include "vu0.h"
extern u8 *D_L07_001DF41C;
extern s32 D_L07_001DF458 __attribute__((section(".data")));
extern s16 *D_L07_0021C020[];
typedef struct { u8 pad[0x30]; u8 *m; } Slot_003B0FE0;
typedef struct { void *owner; u8 pad[8]; u8 counts[7]; u8 pad13[13]; u8 *group[4]; u8 *special[4]; } Vars_003B0FE0;
void func_L07_003B0FE0(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_L07_00333CE0(void *, s32);
    extern u8 *func_L07_00333918(void *);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L07_003343E8(s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L07_00333D40(void *, void *);
    extern f32 func_0038D160(f32, f32);
    vu0_v4 pos, delta;
    f32 angles[2];
    Vars_003B0FE0 *vars=*(Vars_003B0FE0 **)(self+0x68);
    u8 **group=vars->group;
    u8 **out;
    s32 i, next, n;
    s32 clear=3;
    s32 *slot=(s32 *)(group+3);
    u8 *counts;
    s16 *list;
    u8 *m, *state;
    f32 *angle;
    do { *slot=0; clear--; slot--; } while(clear>=0);
    func_003C2F58(self,1,&pos);
    out=group;
    n=0;
    pos.z += -2.5f;
    angles[1]=angles[0]=*(f32 *)(self+0xF8);
    counts=vars->counts;
    for(i=0;i<7;i=next) {
        next=i+1;
        if (!counts[i]) continue;
        list=D_L07_0021C020[func_L07_00333CE0(vars->owner,i)];
        goto test;
body:
            m=D_L07_001DF41C+((*(u16 *)list & 0x7FFF)<<8);
            if (!m) goto next_group;
            if(m[0x20]==1) {
                state=func_L07_00333918(m);
                angle=0;
                *(s16 *)(state+0xE)=((func_00382498(-10,10)+20)*5+2)/6;
                state[0x1E]=0;
                state[0x1D]=i;
                qzero(&delta);
                if(func_L07_003343E8(i)==1) {
                    group[n+4]=m;
                    n++;
                    delta.z=3.0f;
                    angle=&angles[0];
                } else if(func_L07_003343E8(i)==0) {
                    *out++=m;
                    angle=&angles[1];
                }
                delta.x=func_0038D098(*angle)*2.0f;
                delta.y=func_0038D0B0(*angle)*2.0f;
                *angle=func_0038DAB8(*angle,1.5707963705062866f);
                vec_add_ab(m+0x10,&pos,&delta);
                func_L07_00333D40(*(void **)(state+4),m);
                *(f32 *)(m+0xF8)=func_0038D160(*(f32 *)(*(u8 **)vars+0x10)-*(f32 *)(m+0x10),*(f32 *)(*(u8 **)vars+0x14)-*(f32 *)(m+0x14));
                ((u8 *)((s32)counts+i))[0]--;
                if(((u8 *)((s32)counts+i))[0]==0) goto next_group;
            }
            list++;
test:
            if ((u8)func_L07_00333CE0(vars->owner,i)==255) goto next_group;
            if (func_L07_00333CE0(vars->owner,i)>D_L07_001DF458) goto next_group;
            if (!list) goto next_group;
            if (list[-1]>=0) goto body;
            if (list==D_L07_0021C020[func_L07_00333CE0(vars->owner,i)]) goto body;
next_group:
        ;
    }
}
