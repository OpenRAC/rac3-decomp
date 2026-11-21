/* functional: high. 75 diff but traced end to end against retail asm: all constants, branches and the return-path logic (null obj / null class / kind==5) agree; 8 jals identical; differences are scheduling and return lowering (xori/movn vs beq) */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003882A0;
typedef struct { u8 pad[0x46]; u8 kind; } Class_003882A0;
typedef struct { u8 pad[0x24]; Class_003882A0 *cls; } Moby_003882A0;
typedef struct { u8 pad[0x18]; Moby_003882A0 *obj;
    Vec_003882A0 *hitpos; s32 hit; Vec_003882A0 pos; } Hit_003882A0;
typedef struct { u8 pad[0x6c]; f32 damage; u8 tail[0x80]; } Weapon_003882A0;
extern Hit_003882A0 D_L01_001EAA00;
extern Vec_003882A0 D_L01_001EAA20;
extern Weapon_003882A0 D_L01_002C5600[];
extern u8 D_001425E7[16];
extern s32 D_001A71A0[4];
static __inline__ void sub_003882A0(Vec_003882A0 *d, Vec_003882A0 *a, Vec_003882A0 *b) {
    __asm__("lqc2 $vf1, %1\n lqc2 $vf2, %2\n vsub.xyz $vf1, $vf1, $vf2\n sqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
Moby_003882A0 *func_L01_003882A0(void *owner, Vec_003882A0 *start, Vec_003882A0 *end, Vec_003882A0 *shot, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_00389B00(void *, void *, void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    Vec_003882A0 delta;
    f32 damage, dist;
    Moby_003882A0 *obj;
    Vec_003882A0 *hitpos;
    sub_003882A0(shot,end,start);
    func_0038CF68(shot,shot,1.5f);
    shot->w=5627.925f;
    if (func_003D3CB0(start,end,16,D_001A71A0[0],0)) {
        sub_003882A0(&delta,end,start);
        func_0038CF68(&delta,&delta,1.0f);
        hitpos=&D_L01_001EAA20;
        sub_003882A0(&delta,hitpos,start);
        func_L01_00389B00(start,&delta,hitpos,1,radius);
        if (((s32 *)hitpos)[-2]) {
            damage=D_L01_002C5600[D_001425E7[0]].damage;
            dist=func_0038CF00(hitpos,start);
            if (dist<10.0f) ((f32 *)shot)[7]=damage;
            else if (dist<14.0f) ((f32 *)shot)[7]=damage*0.75f;
            else if (dist<20.0f) ((f32 *)shot)[7]=damage*0.5f;
            else ((f32 *)shot)[7]=damage*0.125f;
            func_L01_00446978(D_L01_001EAA00.obj,shot);
            func_L01_0034C9F0(D_L01_001EAA00.obj,39,owner);
            owner=D_L01_001EAA00.obj;
            if (owner) {
                if (((Moby_003882A0 *)owner)->cls==0) goto fail;
                if (((Moby_003882A0 *)owner)->cls->kind==5) goto done;
                owner=0;
            }
            goto done;
        }
    } else {
        sub_003882A0(&delta,end,start);
        func_L01_00389B00(start,&delta,end,0,-1.0f);
    }
fail:
    owner=0;
done:
    return owner;
}
