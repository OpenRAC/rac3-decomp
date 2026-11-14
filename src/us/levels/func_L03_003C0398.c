#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C0398 */
extern vu0_v4 D_L03_001E24C0_003C0398;
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_003C0398(f32 *position, s32 count) {
    vu0_v4 velocity, at, delta, axis, base;
    f32 size, angle;
    s32 spin, i;
    u8 *p;
    vec_sub_ab(&delta, &D_L03_001E24C0_003C0398, position);
    func_00388830(&base, &delta, 0.3f);
    delta.z=0.0f;
    axis.x=0.0f;
    axis.y=0.0f;
    axis.z=1.0f;
    axis.w=1.0f;
    for(i=0;i<count;i++) {
        size=func_0037E250(0.5f, 2.0f);
        spin=func_0037E1D8(2);
        if(spin==0) spin--;
        angle=func_0037E250(-1.0471976f, 1.0471976f);
        func_00389158(&velocity, &delta, &axis, angle);
        func_00388830(&velocity, &velocity, func_0037E250(0.05f, 3.0f)*0.016666668f);
        velocity.z=func_0037E250(1.0f,5.0f)*0.016666668f;
        vec_add_ab(&at, position, &base);
        position[0]+=func_L01_00440918(0.0f,0.15f);
        position[1]+=func_L01_00440918(0.0f,0.15f);
        position[2]+=func_L01_00440918(0.0f,0.15f);
        p=func_L01_00467DA8(&at,60,size*0.1f,size,0xDD10FFFF,0,spin,&velocity,0.002f,0);
        if(p) p[9]=0x74;
        p=func_L01_00467DA8(&at,60,size*0.07f,size*0.7f,0xDD10FFFF,1,-spin,&velocity,0.002f,0);
        if(p) p[9]=0x74;
    }
}
/* localdecomp:end func_L03_003C0398 */
