#include "common.h"

/* NTSC-U counterpart of func_L01_00335AD0 (src/levels/shared/L01_003326A8.c) */
extern s32 func_00388398(u8 *);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388800(void *, void *);

/* localdecomp:start func_L01_003354A8 */
typedef void (*Callback_00335AD0)(u8 *, s32, s32);
s32 func_L01_003354A8(u8 *a, u8 *b, u8 *moby, u8 *state, s32 value, u8 *cfg, Callback_00335AD0 *vt) {
    extern void func_L01_00457590(u8 *, void *, f32);
    extern f32 func_00388A28(f32, f32);
    extern void func_L01_00445758(f32 *, f32 *, s32, f32, f32, f32, f32);
    extern f32 func_00388800(void *, void *);
    extern s32 func_L01_00334DF0(u8 *, u8 *, u8 *, u8 *, s32, u8 *);
    extern s32 func_00388398(u8 *);
    extern s32 func_0037E208(s32, s32);
    f32 *yaw=(f32 *)(moby+0xf8);
    f32 *target=(f32 *)(state+0x4a0);
    f32 angle;
    func_L01_00457590(moby,target,*yaw);
    angle=func_00388A28(*(f32 *)(state+0x4a0)-*(f32 *)(moby+0x10),*(f32 *)(state+0x4a4)-*(f32 *)(moby+0x14));
    func_L01_00445758(yaw,(f32 *)(b+0x74),0,angle,
        *(f32 *)(state+0x1a4)*0.2f,*(f32 *)(state+0x1a8)*0.2f,*(f32 *)(state+0x1ac)*0.2f);
    if(func_00388800(moby+0x10,target)<2.0f) {
        func_L01_00334DF0(a,b,moby,state,value,cfg);
    }
    if(func_00388398(b+0x68)) {
        a[0xbc]=1;
        *(s32 *)(b+0x68)=func_0037E208(300,530);
    }
    if(!cfg[0x97]) vt[9](moby,0,10);
    else vt[8](moby,0,10);
    return 0;
}
/* localdecomp:end func_L01_003354A8 */
