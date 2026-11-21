/* functional: high. Verified against PAL asm op by op (callees, constants, arg slots, VU sub/add operands, particle byte writes); Vars_00372240 declared locally (level at 0x2D4); bytes differ only in regalloc/scheduling. */
#include "vu0.h"
typedef struct { u8 pad0[0x2D4]; s32 level; } Vars_00372240;
extern u8 *D_L01_00221098[];
extern u8 *D_L01_0022116C[];
extern f32 D_001A4EC0[];
void func_L01_00372430(u8 *p, vu0_v4 *from_ptr, vu0_v4 *to_ptr) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    s32 spin;
    s32 colour1=0x407FFF, colour2=0x4040FF;
    vu0_v4 from=*from_ptr;
    vu0_v4 to=*to_ptr;
    vu0_v4 velocity, position, step, tail;
    Vars_00372240 *v=*(Vars_00372240 **)(p+0x68);
    f32 length=func_0038CEA8(v);
    s32 count=length/0.1f;
    s32 i;
    position=to;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(step) : "m"(from), "m"(to) : "vf1", "vf2");
    func_0038CF68(&step,&step,length/count);
    if ((u32)(v->level-2)<2) {colour1=0xFF7F40;colour2=0xFF4040;}
    if (v->level<4) {
        for(i=0;i<count;++i) {
            s32 life, alpha, colour;
            u8 *particle;
            spin=func_L01_00443A18(1.0f,3.0f);
            func_0038CE20(&velocity,D_001A4EC0,-(func_003824E0(0.1f,0.2f)*0.020000001415610313f));
            life=func_00382498(3,6);
            if (func_0013D3E0()&2) {alpha=64;colour=colour1;}
            else {alpha=96;colour=colour2;}
            particle=func_L01_0046A610(&position,&velocity,(life*5+2)/6,alpha,colour,spin,63000.00390625f,10000.0f,1.0f,0.0f,0.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(position) : "m"(position), "m"(step) : "vf1", "vf2");
            if (particle) {
                particle[2]=*D_L01_00221098[23];
                particle[3]=alpha==64?0x48:0x44;
            }
        }
    }
    {
        s32 colour1=0x7F407FFF,colour2=0x7F80DFFF,alpha=255;
        if ((u32)(v->level-2)<2) {colour1=0x7FFF7F40;colour2=0x7FFFDF80;alpha=0xFF0000;}
        if (v->level<4 && func_00382468(2)) {
            s32 colour;
            u8 *particle;
            func_0038CE20(&tail,v,-0.04000000283122063f);
            func_003C4C18(&tail,0.12000000476837158f);
            tail.z+=0.06000000238418579f;
            colour=func_00382468(2)?colour1:colour2;
            particle=func_L01_00465738(p+0x10,&tail,colour,alpha,func_00382498(8,17),0,-1,-1,0,94500.0f);
            if (particle) {
                *(f32 *)(particle+0x2C)=0.002400000113993883f;
                particle[2]=*D_L01_0022116C[0];
            }
        }
    }
}
