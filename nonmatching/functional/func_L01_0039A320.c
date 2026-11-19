/* functional: high. Codex PAL draft re-checked in context: 14 words differs only in scheduling/register allocation/addressing, same calls in the same order. Typedef Vec4_0039E0C8 is defined later in the owner file: hoist it or drop the casts. */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
#include "vu0.h"
typedef struct {
    vu0_v4 push;
    u8 *owner;
    s32 flags;
    u8 active, kind;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Query_0039A320;
typedef struct {
    vu0_v4 initial, starting, direction, previous, axis;
    Query_0039A320 query;
    vu0_v4 temporary;
} Scratch_0039A320;
typedef struct { u8 pad[0x25c0]; u8 *moby; } Hero_0039A320;
extern Hero_0039A320 D_001A4BE0;
typedef struct { u8 pad[0x6c]; f32 damage; } Gun_0039A320;
extern f32 D_L01_001DE0E4;
extern s32 D_L01_001DE0E0;
__asm__(".extern D_L01_001DE0E4, 4");
__asm__(".extern D_L01_001DE0E0, 4");
extern u8 D_00142607[];
extern vu0_v4 D_L01_001EAA20;
typedef struct { u8 pad0[0x64]; u8 *first; u8 pad68[0x1a0-0x68]; u8 *second; } Settings_0039A320;
extern Settings_0039A320 D_L01_00221098;
extern u8 D_L01_001D66B0[8];
void func_L01_0039A320(u8 *self)
{
    extern void func_003C2F58(void *,s32,void *);
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CF68(Vec4_0039E0C8 *,Vec4_0039E0C8 *,f32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038D890(Vec4_0039E0C8 *,Vec4_0039E0C8 *,Vec4_0039E0C8 *,f32);
    extern s32 func_003D3CB0(Vec4 *,s32 *,s32,s32,s32);
    extern void func_L01_0039AB60(void *,s32,s32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_L01_00424CB0(void *,f32,f32,f32,f32,f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00424D88(s32);
    extern void func_003C2880(void *);
    extern u8 *func_L01_0046FB40(void *,void *,s32,s32,s32,s32,s32,f32,f32,f32,s32);
    extern void func_L01_00399E80(u8 *);
    extern void func_L01_0039A860(u8 *);
    extern void func_L01_00404A10(void *,void *);
    Scratch_0039A320 scratch;
    u8 *vars=*(u8 **)(self+0x68);
    f32 angle;
    func_003C2F58(*(void **)(self+0xb8),0,&scratch.initial);
    scratch.starting=scratch.initial;
    *(vu0_v4 *)(self+0x10)=scratch.starting;
    func_003C5180(self+0x10,&scratch.direction,1);
    scratch.previous=*(vu0_v4 *)(self+0x10);
    vec_sub_ba(&scratch.axis,vars+0x30,self+0x10);
    func_0038CF68((Vec4_0039E0C8 *)&scratch.axis,(Vec4_0039E0C8 *)&scratch.axis,1.0f);
    angle=func_0038D160(*(f32 *)(vars+0x30)-*(f32 *)(D_001A4BE0.moby+0x10),
                       *(f32 *)(vars+0x34)-*(f32 *)(D_001A4BE0.moby+0x14));
    if(angle<1.5707964f) angle=func_003824E0(0.0f,-0.7853982f);
    else angle=func_003824E0(0.0f,0.7853982f);
    *(vu0_q *)(vars+0x40)=*(vu0_q *)(self+0x10);
    *(f32 *)(vars+0x48)-=D_L01_001DE0E4;
    vec_sub_ba(vars+0x40,vars+0x40,self+0x10);
    func_0038D890((Vec4_0039E0C8 *)(vars+0x40),(Vec4_0039E0C8 *)(vars+0x40),(Vec4_0039E0C8 *)&scratch.axis,angle);
    vec_add_ab(vars+0x40,self+0x10,vars+0x40);
    switch(self[0x20]) {
    case 0: {
        s32 divisor;
        scratch.query.owner=self;
        scratch.query.flags=0x410000;
        scratch.query.enabled=1;
        scratch.query.damage=((Gun_0039A320 *)((s32)D_L01_002C5600+D_00142607[0]*sizeof(Ent_003985C0)))->damage*0.5f;
        vec_sub_ba(&scratch.query.push,vars+0x30,self+0x10);
        func_0038CF68((Vec4_0039E0C8 *)&scratch.query.push,(Vec4_0039E0C8 *)&scratch.query.push,0.7f);
        scratch.query.push.w=5627.9248046875f;
        scratch.query.class_id=*(u16 *)(self+0xaa);
        scratch.query.active=1;
        scratch.query.kind=1;
        if(func_003D3CB0((Vec4 *)(self+0x10),(s32 *)(vars+0x30),0,(s32)D_001A4BE0.moby,(s32)&scratch.query)) {
            u8 *hit;
            scratch.temporary=D_L01_001EAA20;
            hit=*(u8 **)((u8 *)&D_L01_001EAA20-8);
            if(hit==0) func_L01_0039AB60(&scratch.temporary,15,0);
            else if(*(s32 *)(hit+0x98)!=0) func_L01_0039AB60(&scratch.temporary,10,0);
            self[0x20]=1;
            divisor=6;
        } else {
            self[0x20]=1;
            divisor=6;
        }
        *(s32 *)(vars+0x10)=(D_L01_001DE0E0*5+2)/divisor;
        vec_sub_ba(&scratch.temporary,vars+0x30,self+0x10);
        func_0038CF68((Vec4_0039E0C8 *)&scratch.temporary,(Vec4_0039E0C8 *)&scratch.temporary,func_0038CEA8(&scratch.temporary)*0.5f);
        vec_add_ba(&scratch.temporary,self+0x10,&scratch.temporary);
        *(s32 *)(vars+0x18)=func_L01_00424CB0(&scratch.temporary,10.0f,0.0f,0.1f,0.1f,1.0f);
        break;
    }
    case 1: {
        s32 i;
        if(func_0038CAD0(vars+0x10)) {
            *(s32 *)(vars+0xc)=0;
            if(*(s32 *)(vars+0x18)!=-1) func_L01_00424D88(*(s32 *)(vars+0x18));
            func_003C2880(self);
            return;
        }
        for(i=9;i>=0;i--) {
            f32 size=func_003824E0(0.15f,0.25f)*210000.0f;
            u8 *p=func_L01_0046FB40(self+0x10,D_L01_001D66B0,2,0x804020,2,127,16,size,size,0.0f,0);
            if(p) p[2]=D_L01_00221098.first[0];
            p=func_L01_0046FB40(self+0x10,D_L01_001D66B0,2,0x804020,-1,127,16,size,size,0.0f,0);
            if(p) p[2]=D_L01_00221098.second[0];
        }
        if(*(s32 *)(vars+0x10)>=6) func_L01_00399E80(self);
        func_L01_00404A10(func_L01_0039A860,self);
        break;
    }
    }
    if(*(f32 *)(self+0x10)<2.0f || *(f32 *)(self+0x10)>1021.0f ||
       *(f32 *)(self+0x14)<2.0f || *(f32 *)(self+0x14)>1021.0f ||
       *(f32 *)(self+0x18)<2.0f || *(f32 *)(self+0x18)>1021.0f) func_003C2880(self);
}
