#include "common.h"
/* localdecomp:start func_L01_00382620 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003837B8;
extern Vec_003837B8 D_L01_001E2A40_00382620;
void func_L01_00382620(f32 *position) {
    extern f32 func_00388A28(f32,f32);
    extern f32 func_0037E250(f32,f32);
    extern f32 func_L01_00440918(f32,f32);
    extern f32 func_00389380(f32,f32);
    extern void func_0037E4B8(void *,f32,f32,f32);
    extern void func_L01_00466F98(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
    Vec_003837B8 delta,velocity,spawn;
    f32 angle;
    s32 i;
    vec_sub_ab(&delta, &D_L01_001E2A40_00382620, (Vec_003837B8 *)position);
    angle=func_00388A28(delta.x,delta.y);
    for(i=19;i>=0;i--) {
        f32 speed=func_0037E250(0.5f,1.0f);
        s32 kind=(s32)func_L01_00440918(1.0f,2.0f);
        f32 pitch, yaw;
        f32 scale=210000.0f;
        func_0037E250(0.1f,0.3f);
        pitch=func_0037E250(0.0f,1.3962634f);
        yaw=func_L01_00440918(0.0f,1.3962634f);
        yaw=func_00389380(angle,yaw);
        func_0037E4B8(&velocity,speed*0.0166666675f,yaw,pitch);
        spawn.x=position[0]+func_L01_00440918(0.0f,0.2f);
        spawn.y=position[1]+func_L01_00440918(0.0f,0.2f);
        spawn.z=position[2]+func_L01_00440918(0.0f,0.2f);
        func_L01_00466F98(&spawn,&velocity,30,127,0x7f7f7f,kind,func_0037E250(0.05f,0.2f)*scale,500.0f,1.0f,0.0f,1.0f);
    }
}
/* localdecomp:end func_L01_00382620 */
