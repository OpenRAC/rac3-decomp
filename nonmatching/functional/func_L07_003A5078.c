/* functional: high. Constant stores ordered differently from retail; no behaviour effect. */
#include "common.h"
/* localdecomp:start func_L07_003A5078 */
typedef struct { f32 health; s16 max; u8 pad6[3]; u8 b9; u8 padA[5]; u8 bF; f32 scale; u8 b14,b15,b16; u8 pad17[17]; u8 b28; u8 pad29; u8 b2A; } Sub_003A5078;
typedef struct {
    u8 pad0[48];
    f32 f30;
    s16 f34;
    u8 pad36[14];
    u8 f44;
    u8 f45;
    u8 f46;
    u8 pad47[57];
    u8 f80;
    u8 pad81[31];
    f32 fA0;
    f32 fA4;
    u8 padA8[4];
    f32 fAC;
    u8 padB0[8];
    u8 fB8;
    u8 padB9[103];
    f32 f120;
    s32 f124;
    u8 pad128[40];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15C;
    f32 f160;
    u8 pad164[24];
    f32 f17C;
    f32 f180;
    f32 f184;
    u8 pad188[184];
    u8 f240;
    u8 f241;
    u8 f242;
    u8 f243;
    u8 f244;
    u8 pad245[27];
    s32 f260;
    s32 f264;
    u8 pad268[12];
    void (*f274)(void *);
    void (*f278)(void *);
    s16 f27C;
    u8 pad27E[15];
    u8 f28D;
    u8 pad28E[1];
    u8 f28F;
    u8 pad290[516];
    s32 f494;
    s32 f498;
} State_003A5078;
void func_L07_003A5078(u8 *m)
{
    extern s32 func_L07_003C1AF8(void *);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *,s32,s32);
    extern void func_L01_0045BD78(void *,f32,f32,f32,f32);
    extern void func_L07_003A5670(void *);
    extern void func_L07_003A55D8(void *);
    State_003A5078 *p=*(State_003A5078 **)(m+0x68);
    s32 type=func_L07_003C1AF8(m);
    Sub_003A5078 *q=(Sub_003A5078 *)((u8 *)p+0x30);
    f32 scale=func_L07_003C1B40(type);
    q->max = p->f34*scale;
    p->f30=q->max;
    q->b14=p->f44*scale;
    q->b15=p->f45*scale;
    q->b16=p->f46*scale;
    if (type==1 || type==3) func_L01_00446058(m,0x1D8C,0x195E);
    q->b9=1;
    q->b28=20;
    q->b2A=14;
    q->scale=1.25f;
    q->bF=0;
    p->f80=5;
    p->f240=0xB0;
    p->f241=0x50;
    p->f242=0x80;
    
    p->fB8=0xFF;
    p->f120=1.0f;
    p->f124|=1;
    p->f150=0.6499999761581421f;
    
    
    p->f160=3.1415927410125732f;
    p->f180=0.7853981852531433f;
    p->f17C=0.003920000046491623f;
    p->f184=0.20000000298023224f;
    p->f244=0xE0; p->f243=p->f244;
    
    
    p->f154=0.15000000596046448f; p->fAC=p->f154;
    p->f15C=0.5f; p->fA0=p->f15C; p->fA4=p->fA0; p->f158=p->fA4;
    func_L01_0045BD78(m,0.0020000000949949026f,0.04400000348687172f,0.005026548635214567f,0.12566371262073517f);
    p->f28D=5;
    p->f260=0;
    p->f498=0;
    p->f264=0;
    p->f494=0;
    p->f274=func_L07_003A5670;
    p->f278=func_L07_003A55D8;
    p->f27C=-1;
    p->f28F=7;
    
    func_L07_003A55D8(m);
}
/* localdecomp:end func_L07_003A5078 */
