/* PAL near miss (haiku-w4): 13 words differ with the file's flags; the retail VU0 sequences interleave the argument moves, the lui for D_L01_001E29C0 and the 1.0f constant, and the one-block asm form cannot place them (the j-form needs -mvu0-use-vf0-vf2 on the file line, which config/ does not allow). The second VU0 block is volatile here, a study aid only. */
#include "common.h"
#include "vu0.h"
extern S_38C110v D_L01_001E29C0;
void func_L01_0035ED40(u8 *moby) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, void *, s32);
    S_38C110v basis[4];
    u8 packet[0x90] __attribute__((aligned(16)));
    S_38C110v shifted;
    void *vars=*(void **)(moby+0x68);
    f32 width=func_003824E0(0.14f,0.22f);
    f32 length=func_003824E0(1.333f,1.5f);
    s32 i;
    func_0038CF68(&basis[0],vars,1.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(basis[1]) : "m"(D_L01_001E29C0), "m"(*(S_38C110v *)(moby+0x10)) : "vf1", "vf2");
    func_0038CE90(&basis[2],&basis[1],&basis[0]);
    func_0038CF68(&basis[2],&basis[2],width);
    func_0038CF68(&basis[0],&basis[0],length);
    *(s32 *)&basis[0].w=0;
    *(s32 *)&basis[1].w=0;
    *(s32 *)&basis[2].w=0;
    func_003D93B0(packet,63,1,128);
    *(s32 *)(packet+0x50)=0; *(s32 *)(packet+0x54)=0;
    *(s32 *)(packet+0x58)=0; *(f32 *)(packet+0x5C)=1.0f;
    *(f32 *)(packet+0x60)=1.0f; *(s32 *)(packet+0x64)=0;
    *(f32 *)(packet+0x68)=1.0f; *(f32 *)(packet+0x6C)=1.0f;
    for (i=0;i<4;i++) {
        qzero((vu0_q *)packet+i);
        { S_38C110v *v=(S_38C110v *)packet+i;
        if (i<2) *(s32 *)&v->x=0; else v->x=1.0f;
        *(s32 *)&v->y=0;
        if (i&1) v->z=1.0f; else v->z=-1.0f;
        v->w=1.0f;
        ((u32 *)(packet+0x40))[i]=0x7FFFFFFF;
        }
    }
    func_0038CF68(&shifted,vars,-1.25f);
    __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(basis[3]) : "m"(*(S_38C110v *)(moby+0x10)), "m"(shifted) : "vf1", "vf2");
    basis[3].w=1.0f;
    func_003D2DA0(packet,basis,0);
}
