/* functional: medium. Same calls, order and values as retail; differs only in instruction scheduling (VU0 lqc2/vadd/sqc2 as inline asm, the compiler cannot interleave the move a1 like retail). */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00475DC8;
extern s32 D_L01_001D673C;
void func_L01_00475DC8(u8 *p)
{
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_004CAB30(void *,void *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    u8 *s;
    u8 *pos;
    V_00475DC8 v;
    if (func_0038CB00(p+10)) {
        func_003CD250(p);
        return;
    }
    s=p+32;
    pos=p+16;
    *(s32 *)(p+4)=func_0038DBD8(*(s32 *)(s+28),*(s32 *)(s+24),(f32)*(s16 *)(p+10)**(f32 *)(s+12));
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(V_00475DC8 *)(p+16)) : "m"(*(V_00475DC8 *)s) : "vf1","vf2");
    func_L01_004CAB30(pos,pos);
    if (!D_L01_001D673C) {
        *(f32 *)(s+8)-=(f32)*(s16 *)(s+22)*0.0078125f*0.00040000002f;
    } else {
        func_L01_004C7D98(pos,&v);
        func_0038CF68(&v,&v,-((f32)*(s16 *)(s+22)*0.0078125f*0.00040000002f));
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(*(V_00475DC8 *)(p+16)) : "m"(v) : "vf1","vf2");
    }
    p[8]+=s[20];
    *(f32 *)(p+12)+=*(f32 *)(s+16);
}
