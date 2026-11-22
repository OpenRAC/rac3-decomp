#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003B7408. */
/* localdecomp:start func_L07_003B5B18 */
typedef union { vu0_q q; f32 f[4]; } V_003B5B18;
__asm__(".extern D_L07_001DE4C0,4");
extern V_003B5B18 D_L07_001DE4C0 __attribute__((section(".sdata")));
void func_L07_003B5B18(void *a, s32 b, f32 scale, f32 amount) {
    extern void func_003BD9A0(void *,s32,void *);
    extern void func_00389158(void *,void *,void *,f32);
    extern void func_00388830(void *,void *,f32);
    extern void func_003BF6A8(void *,f32);
    extern f32 func_0037E250(f32,f32);
    extern void func_003886E8(void *,void *,f32);
    extern void func_L01_0046A9C8(s32,void *,void *,void *,s32);
    V_003B5B18 matrix[4],dir,scaled,pos,p,vel;
    V_003B5B18 *color=&D_L07_001DE4C0;
    s32 i;
    func_003BD9A0(a,b,matrix);
    vec_neg(&dir,&matrix[2]);
    func_00389158(&dir,&dir,&matrix[1],amount);
    func_00388830(&dir,&dir,1.0f);
    func_003886E8(&scaled,&dir,scale);
    vec_add_ab(&pos,&matrix[3],&scaled);
    for(i=0;i<3;i++) {
        p.q=pos.q;
        func_003BF6A8(&p,0.1f);
        func_003886E8(&vel,&dir,func_0037E250(0.1666666716337204f, 0.20000001788139343f));
        func_L01_0046A9C8(0,&p,&vel,color,i<2);
        color++;
    }
}
/* localdecomp:end func_L07_003B5B18 */
