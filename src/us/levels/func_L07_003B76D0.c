#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003B8FC0. */
/* localdecomp:start func_L07_003B76D0 */
typedef union { vu0_q q; f32 f[4]; } V_003B76D0;
__asm__(".extern D_L07_001DE4F0,4");
extern V_003B76D0 D_L07_001DE4F0 __attribute__((section(".sdata")));
void func_L07_003B76D0(void *o,s32 n) {
    extern void func_003BD9A0(void *,s32,void *);
    extern void func_00389158(void *,void *,void *,f32);
    extern void func_00388830(void *,void *,f32);
    extern void func_003BF6A8(void *,f32);
    extern f32 func_0037E250(f32,f32);
    extern void func_003886E8(void *,void *,f32);
    extern void func_L01_0046A9C8(s32,void *,void *,void *,s32);
    V_003B76D0 matrix[4],dir,pos,vel;
    V_003B76D0 *color=&D_L07_001DE4F0;
    s32 i;
    f32 speed;
    func_003BD9A0(o,n,matrix);
    vec_neg(&dir,&matrix[2]);
    func_00389158(&dir,&dir,&matrix[1],0.7853981852531433f);
    func_00388830(&dir,&dir,1.0f);
    for(i=0;i<3;i++) {
        pos.q=matrix[3].q;
        func_003BF6A8(&pos,0.1f);
        speed=func_0037E250(0.1666666716337204f, 0.20000001788139343f);
        func_003886E8(&vel,&dir,speed);
        func_L01_0046A9C8(0,&pos,&vel,color,i<2);
        color++;
    }
}
/* localdecomp:end func_L07_003B76D0 */
