/* functional: high. Draft verified against asm, including the discarded rand(0.1,0.3) call that keeps the RNG sequence in step. */
#include "common.h"
/* localdecomp:start func_L01_003837B8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003837B8;
extern Vec_003837B8 D_L01_001E29C0;
void func_L01_003837B8(f32 *position) {
    extern f32 func_0038D160(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_00382760(void *,f32,f32,f32);
    extern void func_L01_0046A610(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
    Vec_003837B8 delta,velocity,spawn;
    f32 angle;
    s32 i;
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
      : "=m"(delta) : "m"(D_L01_001E29C0),"m"(*(Vec_003837B8 *)position) : "vf1","vf2");
    angle=func_0038D160(delta.x,delta.y);
    for(i=19;i>=0;i--) {
        f32 speed=func_003824E0(0.5f,1.0f);
        s32 kind=(s32)func_L01_00443A18(1.0f,2.0f);
        f32 pitch, yaw;
        func_003824E0(0.1f,0.3f);
        pitch=func_003824E0(0.0f,1.3962634f);
        yaw=func_L01_00443A18(0.0f,1.3962634f);
        yaw=func_0038DAB8(angle,yaw);
        func_00382760(&velocity,speed*0.02f,yaw,pitch);
        spawn.x=position[0]+func_L01_00443A18(0.0f,0.2f);
        spawn.y=position[1]+func_L01_00443A18(0.0f,0.2f);
        spawn.z=position[2]+func_L01_00443A18(0.0f,0.2f);
        func_L01_0046A610(&spawn,&velocity,25,127,0x7f7f7f,kind,func_003824E0(0.05f,0.2f)*210000.0f,500.0f,1.0f,0.0f,1.0f);
    }
}
/* localdecomp:end func_L01_003837B8 */
