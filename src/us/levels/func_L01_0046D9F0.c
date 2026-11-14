#include "common.h"
typedef int QD9 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) VD9;
/* localdecomp:start func_L01_0046D9F0 */
extern int func_003883C8(short *);
extern void func_003C7CE0(void *);
void func_L01_0046D9F0(u8 *a) {
    QD9 v;
    u8 *d=a+0x20;
    *(float *)(d+0x10)+=0.001f;
    *(float *)(d+8)-=0.003f;
    *(float *)(a+12)=*(float *)(d+0x14)* *(float *)(d+0x10)*210000.0f;
    v=*(QD9 *)d;
    __asm__("lqc2 $vf2, %1; lqc2 $vf1, %2; vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, %0" : "=m"(*(VD9 *)(a+0x10)) : "m"(v), "m"(*(VD9 *)(a+0x10)) : "vf1","vf2");
    *(int *)(a+4)=(*(short *)(a+10)<<24)|0xFFD2D2;
    a[8]+=d[0x18];
    if(func_003883C8((short *)(a+10))) func_003C7CE0(a);
}
/* localdecomp:end func_L01_0046D9F0 */
