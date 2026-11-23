/* functional: high. Verified line by line against PAL asm (callees, constants, arg order, loop counts, VU vsub/vadd operands); bytes differ only in scheduling/regalloc (check.py: 228 words). */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001D66B0[];
void func_L01_00371CA8(u8 *self, vu0_v4 *source)
{
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_00382498(s32,s32);
    extern void func_L01_00470668(void *,void *,s32,f32);
    extern void func_00382580(void *,f32,f32);
    extern void func_L01_00474078(void *,void *,s32,u32,u32,s32,s32,f32,f32,f32,f32);
    extern u8 *func_L01_0046B458(void *,f32,s32,f32,u32,s32,s32,void *,f32,s32);
    extern u8 *func_L01_00470C78(void *,f32,s32,f32,u32,s32,s32,void *,s32,s32,s16,s32);
    s32 level=*(s32 *)(*(u8 **)(self+0x68)+0x2d4);
    struct { vu0_v4 velocity, offset; } vectors;
    s32 i;
    if(level<2) {
        vu0_v4 *v=&vectors.velocity;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*v) : "m"(*source), "m"(D_L01_001E29C0) : "vf1", "vf2");
        func_0038CF68(v,v,func_003824E0(0.1f,0.2f));
        for(i=14;i>=0;i--) {
            s32 divisor=6;
            v->x+=func_003824E0(-0.05f,0.05f);
            v->y+=func_003824E0(-0.05f,0.05f);
            v->z+=func_003824E0(-0.05f,0.05f);
            func_L01_00470668(self+0x10,v,(func_00382498(25,40)*5+2)/divisor,0.0058400002f);
        }
    } else {
    vu0_v4 *v=&vectors.velocity;
    vu0_v4 *toward=&vectors.offset;
    u32 color0, color1, color2, tint;
    color0=0x80804020;
    color1=0xBF804020;
    color2=0xBF604020;
    tint=0xFF0000;
    if(level>=4) {
        color0=0x80204080;
        color1=0xBF2040FF;
        color2=0xBF2040FF;
        tint=0xFF;
    }
    for(i=9;i>=0;i--) {
        s32 divisor=6;
        func_00382580(v,0.10000001f,0.20000002f);
        func_L01_00474078(self+0x10,v,(func_00382498(15,25)*5+2)/divisor,color0,tint,0,0,0.1f,0.25f,0.9f,0.5f);
    }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*toward) : "m"(*(vu0_v4 *)(self+0x10)), "m"(D_L01_001E29C0) : "vf1", "vf2");
    func_0038CF68(toward,toward,0.4f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*v) : "m"(*toward), "m"(*(vu0_v4 *)(self+0x10)) : "vf1", "vf2");
    func_L01_0046B458(v,3.5f,14,0.1f,color1,2,1,D_L01_001D66B0,0.0f,1);
    func_L01_0046B458(v,2.5f,14,0.1f,color2,2,-1,D_L01_001D66B0,0.0f,1);
    func_L01_0046B458(v,1.75f,14,0.1f,0xC0FFFFFF,2,1,D_L01_001D66B0,0.0f,1);
    func_L01_0046B458(v,1.25f,14,0.1f,0xB0FFFFFF,2,-1,D_L01_001D66B0,0.0f,1);
    func_L01_00470C78(v,0.9f,17,0.7f,0x46787878,2,2,D_L01_001D66B0,0,2,6,1);
    func_L01_00470C78(v,1.7f,17,0.7f,0x46787878,2,-1,D_L01_001D66B0,1,2,6,1);
    func_L01_00470C78(v,2.0f,17,1.5f,0x2D787878,2,1,D_L01_001D66B0,1,2,6,1);
    }
}
