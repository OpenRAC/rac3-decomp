#include "common.h"
/* localdecomp:start func_L01_002FB7B0 */
#include "vu0.h"
typedef struct { s32 a[4]; } Colors_002FB7D8;
extern Colors_002FB7D8 D_L01_001DC388;
extern vu0_v4 D_L01_001EAAC0;
void func_L01_002FB7B0(u8 *self)
{
    extern s32 func_0037E1D8(s32);
    extern f32 func_0037E250(f32, f32);
    extern void func_00388830(void *, void *, f32);
    extern s32 func_L01_00445C50(s32,s32);
    extern void func_L01_00460318(void *,void *,s32,s32,s32,s32,s32,s32);
    extern f32 func_00389380(f32,f32);
    extern s32 func_003CE740(void *,void *,s32,void *,s32);
    extern void func_L01_0040C260(void *,void *,void *);
    extern f32 func_00388770(void *);
    extern void func_L01_0044E108(void *,void *,void *,f32);
    extern void func_003BD360(void *);
    extern s32 func_003883C8(void *);
    u8 *vars=*(u8 **)(self+0x68);
    s32 spawn=1;
    s32 quarter;
    union { Colors_002FB7D8 colors; vu0_v4 old; } temporary;
    if(*(s32 *)(vars+0x20)!=0) {
        if(func_0037E1D8(2)) spawn=0;
    }
    if((self[0xbc]&1) && spawn) {
        vu0_v4 direction;
        temporary.colors=D_L01_001DC388;
        {
            vu0_v4 random={0};
            random.x=func_0037E250(-1.0f,1.0f);
            random.y=func_0037E250(-1.0f,1.0f);
            random.z=func_0037E250(-1.0f,1.0f);
            direction=random;
        }
        func_00388830(&direction,&direction,0.0166666675f);
        if(self[0xbc]&0xfe) {
            s32 color=func_L01_00445C50(temporary.colors.a[func_0037E1D8(4)],self[0xbc]>>1);
            s32 other=func_L01_00445C50(0x4fff,self[0xbc]>>1);
            func_L01_00460318(self+0x10,&direction,color,other,45,50,120,1);
        } else {
            func_L01_00460318(self+0x10,&direction,temporary.colors.a[func_0037E1D8(4)],0x4fff,45,50,120,1);
        }
    }
    *(f32 *)(self+0xf0)=func_00389380(*(f32 *)(self+0xf0),*(f32 *)(vars+0x10));
    *(f32 *)(self+0xf4)=func_00389380(*(f32 *)(self+0xf4),*(f32 *)(vars+0x14));
    if(*(s32 *)(vars+0x24)) {
        temporary.old=*(vu0_v4 *)(self+0x10);
        vec_add_ab(self+0x10,self+0x10,vars);
        if(func_003CE740(&temporary.old,self+0x10,16,self,0)) {
            func_L01_0040C260(vars,vars,&D_L01_001EAAC0);
            func_00388830(vars,vars,func_00388770(vars)*0.800000012f);
        }
    } else {
        vec_add_ab(self+0x10,self+0x10,vars);
    }
    func_L01_0044E108(self,vars,vars,0.00405555591f);
    if(*(f32 *)(self+0x10)<0.0f || *(f32 *)(self+0x14)<0.0f || *(f32 *)(self+0x18)<0.0f) {
        func_003BD360(self);
        return;
    }
    quarter=*(s16 *)(vars+0x1a)/4;
    if(*(s16 *)(vars+0x18)<quarter) {
        *(f32 *)(self+0x2c)=*(f32 *)(vars+0x1c)*(f32)*(s16 *)(vars+0x18)/(f32)quarter;
    }
    if(func_003883C8(vars+0x18)) func_003BD360(self);
}
/* localdecomp:end func_L01_002FB7B0 */
