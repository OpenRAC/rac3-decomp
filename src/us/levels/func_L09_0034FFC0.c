#include "common.h"
typedef int Q __attribute__((mode(TI)));
typedef int U64 __attribute__((mode(DI)));
typedef struct { u8 pad[0x30]; u8 a,b; short c; u16 flags; u16 pad36; U64 data; } M;
/* localdecomp:start func_L09_0034FFC0 */
extern u8 *func_003BCFB0(int,int);
extern void func_00388BD0(void *,void *);
extern float func_0037E250(float,float);
extern u8 *func_L01_00467DA8(void *,int,int,int,int,void *,float,float,float,int);
extern u8 D_L09_001D66B0_0034FFC0[8];
u8 *func_L09_0034FFC0(u8 *owner, Q *v, Q *pos, float value) {
    u8 *m=func_003BCFB0(0xF7A,0x80);
    u8 *p;
    float scale;
    u16 flags;
    if(m) {
        ((M *)m)->a=255;
        ((M *)m)->c=255;
        ((M *)m)->b=1;
        m[0x20]=0;
        flags=((M *)m)->flags|0x41;
        ((M *)m)->data=((M *)owner)->data;
        p=*(u8 **)(m+0x68);
        *(Q *)(m+0x10)=*pos;
        ((M *)m)->flags=flags;
        *(Q *)p=*v;
        *(u8 **)(p+0x10)=owner;
        *(float *)(p+0x14)=value;
        *(float *)(p+0x20)=0.15f;
        ((M *)m)->flags|=0x208;
        *(Q *)(m+0xF0)=*(Q *)(owner+0xF0);
        func_00388BD0(m+0xC0,m+0xF0);
        ((M *)m)->flags|=0x100;
        m[0x23]=128;
        *(float *)(m+0x2C)=0.0001f;
        *(int *)(p+0x24)=0;
        scale=func_0037E250(4.0f,6.0f);
        func_L01_00467DA8(m+0x10,15,0x80103080,0,10,D_L09_001D66B0_0034FFC0,scale*0.3f,scale,0.0f,0);
        func_L01_00467DA8(m+0x10,15,-1,1,-10,D_L09_001D66B0_0034FFC0,scale*0.04f,scale*0.4f,0.0f,0);
    }
    return m;
}
/* localdecomp:end func_L09_0034FFC0 */
