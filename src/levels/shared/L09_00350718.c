#include "common.h"

typedef int Q __attribute__((mode(TI)));
typedef int U64 __attribute__((mode(DI)));
typedef struct { u8 pad[0x30]; u8 a,b; short c; u16 flags; u16 pad36; U64 data; } M;

INCLUDE_ASM("asm/levels", func_L09_00350718);

/* localdecomp:start func_L09_00350968 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_0034FFC0.c */

extern u8 *func_003C24B0(int,int);
extern void func_0038D308(void *,void *);
extern float func_003824E0(float,float);
extern u8 *func_L01_0046B458(void *,int,int,int,int,void *,float,float,float,int);
extern u8 D_L09_001D66B0_0034FFC0[8];
u8 *func_L09_00350968(u8 *owner, Q *v, Q *pos, float value) {
    u8 *m=func_003C24B0(0xF7A,0x80);
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
        func_0038D308(m+0xC0,m+0xF0);
        ((M *)m)->flags|=0x100;
        m[0x23]=128;
        *(float *)(m+0x2C)=0.0001f;
        *(int *)(p+0x24)=0;
        scale=func_003824E0(4.0f,6.0f);
        func_L01_0046B458(m+0x10,12,0x80103080,0,10,D_L09_001D66B0_0034FFC0,scale*0.3f,scale,0.0f,0);
        func_L01_0046B458(m+0x10,12,-1,1,-10,D_L09_001D66B0_0034FFC0,scale*0.04f,scale*0.4f,0.0f,0);
    }
    return m;
}
/* localdecomp:end func_L09_00350968 */

/* localdecomp:start func_L09_00350B30 */
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L09_00350CB0(u8 *, s32, f32, s32, f32, f32, s32, s32, u8 *);

void func_L09_00350B30(u8 *a0) {
    f32 x = *(f32 *)(a0 + 0x2C) * 90.0f;
    func_L09_00350CB0(a0 + 0x10, 0x80103080, x, func_00382498(0x5F, 0x6F), func_00382538(), 1.0f, 0x1C, 2, a0);
    {
        f32 half = *(f32 *)(a0 + 0x2C) * 90.0f * 0.5f;
        func_L09_00350CB0(a0 + 0x10, -1, half, func_00382498(0x6F, 0x7F), func_00382538(), 1.0f, 8, 2, a0);
    }
}
/* localdecomp:end func_L09_00350B30 */
