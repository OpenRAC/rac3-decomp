#include "common.h"

/* NTSC-U counterpart of func_L01_003D7288 (src/levels/shared/L01_003D0D48.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "structs/hero.h"
extern s32 func_0037E1D8(s32);
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L01_003D5778 */
#include "vu0.h"
extern u8 *D_L01_00221118_003D5778[];
void func_L01_003D5778(u8 *m,void *parent,s32 kind,s32 count,s32 mode,vu0_v4 *direction,f32 speed,f32 lo,f32 hi,f32 rotation,f32 spread) {
    extern s32 func_0037E1D8(s32);
    extern s32 func_0037E208(s32,s32);
    extern f32 func_0037E250(f32,f32);
    extern void func_00388830(vu0_v4 *,vu0_v4 *,f32);
    extern void func_003886E8(void *,void *,f32);
    extern void func_L01_003D5658(s32 *,u32 *,u32 *,s32 *);
    extern u8 *func_L01_00472438(void *,void *,s32,s32,s32,s32,f32,f32,f32,s32);
    vu0_v4 velocity,axis,temp;
    s32 color1,color2,unused;
    s32 alpha=127;
    s32 cheap;
    s32 color;
    u8 *p=*(u8 **)(m+0x68);
    s32 mask=p[0xBD];
    cheap=func_0037E1D8(3)==0;
    if(cheap) {mode=4;lo*=0.7f;hi*=0.7f;alpha=48;}
    func_L01_003D5658(&mode,(u32 *)&color1,(u32 *)&color2,&unused);
    if(p[0xBE]==0) func_00388830(&velocity,direction,speed*0.0166666675f);
    else {rotation=0.0f;qzero(&velocity);}
    *(vu0_q *)&axis=0;
    axis.x=1.0f;
    if(count>0) do {
        u8 *particle;
        if(p[0xBE]==0) {
            func_003886E8(&temp,&axis,func_0037E250(0.2f,spread)*0.0166666675f);
            vec_add_ab(&velocity,&temp,&velocity);
        }
        color=func_0037E1D8(2)?color2:color1;
        if(cheap) color|=alpha<<24;
        else color|=p[0xBC]<<24;
        if(m[0x20]==2) mask=0;
        particle=func_L01_00472438(parent,&velocity,kind,func_0037E208(-2,2),color,color&((mask<<24)|0xFFFFFF),lo**(f32 *)(p+0xB8)*210000.0f,hi**(f32 *)(p+0xB8)*210000.0f,rotation,0);
        if(particle) {
            particle[2]=cheap?D_L01_00221118_003D5778[0x61][4]:D_L01_00221118_003D5778[4][0];
            particle[3]=68;
        }
        --count;
    } while(count);
}
/* localdecomp:end func_L01_003D5778 */
