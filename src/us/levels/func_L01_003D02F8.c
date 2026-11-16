#include "common.h"

/* NTSC-U counterpart of func_L01_003D1C60 (src/levels/shared/L01_003D0D48.c) */
#include "vu0.h"
extern s32 D_L01_001E0180;

/* localdecomp:start func_L01_003D02F8 */
#include "vu0.h"
__asm__(".extern D_L01_001DF374, 4");
__asm__(".extern D_L01_001DF36C, 4");
__asm__(".extern D_L01_001DF370, 4");
__asm__(".extern D_L01_001DF378, 4");
__asm__(".extern D_L01_001DF37C, 4");
__asm__(".extern D_L01_001DF340, 4");
extern s32 D_L01_001E0180;
extern f32 D_L01_001DF374;
extern f32 D_L01_001DF36C;
extern f32 D_L01_001DF370;
extern f32 D_L01_001DF378;
extern f32 D_L01_001DF37C;
extern f32 D_L01_001DF340;
extern s32 D_L01_001DFBC0_003D02F8;
void func_L01_003D02F8(u8 *obj, u8 *state)
{
    extern void func_003886E8(f32 *, f32 *, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern u8 *func_L01_003CFFB0(u8 *, u8 *, f32 *, f32);
    f32 pos[4], base[4];
    f32 r, radius, angle;
    s32 i;
    u8 *p;
    if(*(s32 *)(state+0x10)<0) return;
    func_003886E8(base,(f32 *)(obj+0xD0),D_L01_001DF374);
    vec_add_ab(base,base,(void *)((*(s32 *)(state+0x64)<<7)+D_L01_001E0180+0x30));
    for(i=0;i<160;i++) {
        r=func_0037E250(0.05f,1.0f);
        radius=(1.0f-r*r*r)**(f32 *)(state+0x54)*2.0f+5.0f;
        r=func_0037E250(D_L01_001DF36C*0.017453292f,D_L01_001DF370*0.017453292f);
        angle=func_00389380(*(f32 *)(obj+0xF8),r);
        pos[0]=func_00388960(angle)*radius;
        pos[1]=func_00388978(angle)*radius;
        pos[2]=0.0f;
        pos[2]+=func_0037E250(D_L01_001DF378,D_L01_001DF37C);
        vec_add_ab(pos,pos,base);
        p=func_L01_003CFFB0(obj,state,pos,1.0f);
        if(p==0) break;
        *(f32 *)(p+0x14)=1.0f;
    }
    *(s32 *)(state+0x1C)=D_L01_001DFBC0_003D02F8+(s32)D_L01_001DF340;
    *(f32 *)(state+0x20)=12.0f;
}
/* localdecomp:end func_L01_003D02F8 */
