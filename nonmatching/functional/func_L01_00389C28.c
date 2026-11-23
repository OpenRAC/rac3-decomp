/* functional: high. 257 diff by scheduling/reg alloc; 22 jals identical and the instruction multiset matches except one move/3 nops; section(.sdata) attribute on D_L01_001D66B0 kept from draft (it was needed for gp-relative addressing); loop is count-down i=1..0 as retail */
#include "common.h"
#include "vu0.h"
typedef struct { vu0_v4 old, normal, copy, center, spawn; } Work_00389C28;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_0022116C[];
extern u8 *D_L01_00221098[];
void func_L01_00389C28(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_0038A0F8(void *);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    Work_00389C28 w;
    u8 *vars=*(u8 **)(obj+0x68);
    u8 *p;
    u8 *velocity;
    s32 spin, life, i;
    f32 t, angle, size;
    *(vu0_q *)&w.old=*(vu0_q *)(obj+0x10);
    func_003C5180(obj+0x10,&w.normal,1);
    *(vu0_q *)&w.copy=*(vu0_q *)(obj+0x10);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(obj+0x10,obj+0x10);
        func_L01_004CAB30(vars+0x50,vars+0x50);
        func_L01_004CAB30(vars,vars);
    }
    if (obj[0x20]==0) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(vars+0x50)) : "m"(*(vu0_v4 *)(vars+0x50)), "m"(*(vu0_v4 *)(vars+0x20)) : "vf1", "vf2");
        velocity=vars+0x20;
        if (func_0038CAD0(vars+0x38)) {
            func_003C2880(obj);
            return;
        }
        func_0038CF68(&w.center,velocity,-0.5f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(w.center) : "m"(w.center), "m"(*(vu0_v4 *)(obj+0x10)) : "vf1", "vf2");
        spin=func_00382468(255);
        func_L01_004CB2D8();
        p=func_L01_0046FB40(&w.center,D_L01_001D66B0,2,0x802020,spin,32,16,420000.0f,420000.0f,0.0f,2);
        if (p) p[2]=*D_L01_0022116C[0];
        spin=(spin+128)%255;
        p=func_L01_0046FB40(&w.center,D_L01_001D66B0,2,0x802020,spin,32,16,420000.0f,420000.0f,0.0f,2);
        if (p) p[2]=*D_L01_0022116C[0];
        func_L01_00404A10(func_L01_0038A0F8,obj);
        for (i=1;i>=0;i--) {
            u8 *first;
            u8 *second;
            t=func_003824E0(0.0f,1.0f);
            func_0038CDF8(&w.spawn,vars,&w.center,t);
            spin=func_00382468(255);
            angle=-(*(f32 *)(vars+0x60)*180.0f/3.1415927f);
            t=t*20.0f-angle;
            angle*=0.01f;
            life=t;
            size=1.8f-angle*5.0f;
            if (life>=10) life=9;
            else if (life<2) life=2;
            w.spawn.x+=func_L01_00443A18(0.0f,0.04f);
            w.spawn.y+=func_L01_00443A18(0.0f,0.04f);
            w.spawn.z+=func_L01_00443A18(0.0f,0.04f);
            life=(life*5+2)/6;
            first=func_L01_0046FB40(&w.spawn,velocity,life,0x808080,spin,48,0,size*210000.0f,size*0.2f*210000.0f,0.0f,2);
            if (first) first[2]=D_L01_00221098[91][1];
            size*=0.5f;
            second=func_L01_0046FB40(&w.spawn,velocity,life,0x808080,spin,48,0,size*210000.0f,size*0.2f*210000.0f,0.0f,2);
            if (second) second[2]=D_L01_00221098[91][1];
        }
    }
    if (*(f32 *)(obj+0x10)<2.0f || *(f32 *)(obj+0x10)>1021.0f ||
        *(f32 *)(obj+0x14)<2.0f || *(f32 *)(obj+0x14)>1021.0f ||
        *(f32 *)(obj+0x18)<2.0f || *(f32 *)(obj+0x18)>1021.0f) func_003C2880(obj);
}
