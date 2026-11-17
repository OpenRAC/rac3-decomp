/* PAL near miss (Codex wave 8): near miss: 96 words differ with the file's flags.
 * Worker's note: 95 positional word differences; w397/func_L01_00343658.05.log and .07.log; loop decrement hoisted into first call delay slot, conditional particle stores and argument scheduling differ; repeated wordings unchanged.
 */
#include "common.h"
/* localdecomp:start func_L01_00343658 */
typedef struct { u8 pad[9]; u8 flags; } Particle_00343658;
void func_L01_00343658(void *input,u32 color) {
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382468(s32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *,f32,f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern Particle_00343658 *func_L01_0046B458(void *,f32,s32,f32,u32,s32,s32,void *,f32,s32);
    V_00341C10 velocity,position;
    f32 size,speed,x,y;
    s32 sign;
    u32 i;
    Particle_00343658 *particle;
    for(i=7;(s32)i>=0;i--) {
        size=func_003824E0(1.0f,6.0f);
        sign=func_00382468(2);
        if(sign==0)sign--;
        speed=func_003824E0(0.5f,6.0f)*0.020000001415610313f;
        x=func_00382538();
        y=func_00382538();
        func_00382760(&velocity,speed,x,y);
        position.q=*(s128_00341C10 *)input;
        position.f[0]+=func_L01_00443A18(0.0f,0.1f);
        position.f[1]+=func_L01_00443A18(0.0f,0.1f);
        position.f[2]+=func_L01_00443A18(0.0f,0.1f);
        particle=func_L01_0046B458(&position,size*0.1f,17,size,color|0x7F000000,0,sign,&velocity,0.0f,1);
        if(particle)particle->flags=116;
        particle=func_L01_0046B458(&position,size*0.03999999910593033f,17,size*0.4f,0x7F7F7F7F,1,-sign,&velocity,0.0f,1);
        if(particle)particle->flags=116;

    }
}
/* localdecomp:end func_L01_00343658 */
