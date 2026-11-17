#include "common.h"

/* NTSC-U counterpart of func_L01_00473268 (src/levels/shared/L01_004729D8.c) */
/* localdecomp:start func_L01_0046FB00 */
#include "vu0.h"
typedef int Q_00473268 __attribute__((mode(TI)));
typedef union { Q_00473268 q; f32 f[4]; } V_00473268;
extern u8 *D_L01_002212D0[];
u8 *func_L01_0046FB00(u8 *obj, u8 *pos, s32 render, s32 minlife, s32 maxlife, f32 scale)
{
    extern s32 func_0037E1D8(s32);
    extern f32 func_0037E250(f32, f32);
    extern void func_003888C8(void *, void *, void *);
    extern void func_L01_004C41E8(void *, void *);
    extern void func_003886E8(void *, void *, f32);
    V_00473268 v;
    u8 *p=(u8 *)func_L01_0045E438(110);
    u8 *s;
    s32 n, c;
    if (p != 0) {
        p[3]=render;
        p[1]=0;
        p[9]=68;
        s=p+32;
        p[8]=func_0037E1D8(255);
        p[2]=*D_L01_002212D0[0];
        *(s16 *)(p+10)=func_0037E208(minlife,maxlife);
        *(s32 *)(s+24)=*(s16 *)(p+10);
        *(f32 *)(p+12)=scale*3.0f*210000.0f;
        if (*(f32 *)(pos+12)==-1.0f) {
            qzero(&v);
            v.f[3]=1.0f;
            v.f[0]=-0.3f;
            func_003888C8(&v,&v,obj+192);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_00473268 *)(p+16)) : "m"(v), "m"(*(V_00473268 *)(obj+16)) : "vf1", "vf2");
        } else {
            *(Q_00473268 *)(p+16)=*(Q_00473268 *)pos;
        }
        *(f32 *)(p+16)+=func_0037E250(-0.015f,0.015f);
        *(f32 *)(p+20)+=func_0037E250(-0.015f,0.015f);
        *(f32 *)(p+24)+=func_0037E250(-0.015f,0.015f);
        func_L01_004C41E8(obj+16,&v);
        func_003886E8(s,&v,func_0037E250(0.01f,0.015f));
        *(s32 *)(s+16)=func_0037E208(80,200);
        c=func_0037E208(96,128);
        n=c+(c<<8)+(c<<16);
        *(s32 *)(s+20)=n;
        *(s32 *)(p+4)=n|(*(s32 *)(s+16)<<24);
    }
    return p;
}
/* localdecomp:end func_L01_0046FB00 */
