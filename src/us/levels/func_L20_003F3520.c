#include "common.h"

/* NTSC-U counterpart of func_L20_003F5688 (src/levels/20_final_boss/L20_003F53A8.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L20_003F3520 */
#include "vu0.h"
extern s32 D_L20_001DEC30;
extern u8 *D_L20_0021E880_003F3520[];
extern f32 D_001DF530_sda;
extern f32 D_001DF538_sda;
__asm__(".extern D_001DF530_sda, 4");
__asm__(".extern D_001DF538_sda, 4");
void func_L20_003F3520(u8 *obj) {
    extern void func_L01_00458A70(void *,f32,f32,f32,f32);
    extern void func_L01_00441FB8(void *,s32,s32);
    extern void func_L01_004A6DF8(void *,s32);
    extern void func_L20_003F3240(u8 *,s32,f32);
    extern void func_00388830(void *,void *,f32);
    extern void func_L01_00457440(void *,void *);
    extern f32 func_00388800(void *,void *);
    extern f32 func_00388A28(f32,f32);
    extern void func_L01_00458A08(void *,f32);
    extern f32 func_00388730(void *,void *);
    vu0_v4 point;
    vu0_v4 velocity;
    u8 *p=*(u8 **)(obj+0x68);
    u8 *path;
    u8 *owner;
    u8 *node;
    f32 speed, desired;
    if(obj[0x20]==0) {
        *(s32 *)(p+0x70)=0;
        *(f32 *)(p+0x74)=0.5f;
        *(f32 *)(p+0x78)=0.5f;
        *(f32 *)(p+0x7C)=1.0f;
        *(f32 *)(p+0x80)=0.7853981852531433f;
        *(f32 *)(p+0xA0)=0.3490658402442932f;
        *(f32 *)(p+0x9C)=0.0027222223579883575f;
        func_L01_00458A70(obj,0.011111111380159855f,1.0f,0.0017453293548896909f,0.05235988274216652f);
        *(u32 *)(p+0xA8)|=0x15;
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=500;
        func_L01_00441FB8(obj,1,-1);
    }
    if(D_L20_001DEC30==0) {
        *(s32 *)(obj+0x98)=0;
        *(u16 *)(obj+0x34)=(*(u16 *)(obj+0x34)|0x41)&~0x1000;
        func_L01_004A6DF8(obj,1);
        return;
    }
    *(u16 *)(obj+0x34)&=~0x41;
    owner=*(u8 **)(obj+0x24);
    *(u16 *)(obj+0x34)|=*(u16 *)(owner+0x44)&0x1000;
    *(s32 *)(obj+0x98)=*(s32 *)(owner+0x10);
    if(obj[0x20]==1) {
        func_L20_003F3240(obj,1,1.0f);
        path=D_L20_0021E880_003F3520[*(s32 *)(p+0x240)];
        func_00388830(&point,obj+0xC0,17.0f);
        vec_add_ab(&point,&point,obj+0x10);
        func_L01_00457440(obj,&point);
        if(func_00388800(obj+0x10,path+((*(s32 *)(p+0x244)<<4)+0x10))<7.0f) {
            ++*(s32 *)(p+0x244);
            if(*(s32 *)(p+0x244)>=*(s32 *)path) *(s32 *)(p+0x244)=0;
        }
        node=path+(*(s32 *)(p+0x244)<<4);
        func_L01_00458A08(obj,func_00388A28(*(f32 *)(node+0x10)-*(f32 *)(obj+0x10),*(f32 *)(node+0x14)-*(f32 *)(obj+0x14)));
        speed=D_001DF530_sda*0.01745329238474369f;
        *(vu0_q *)&velocity=*(vu0_q *)(p+0x110);
        if(func_00388730(&velocity,obj+0xD0)/0.5f<1.0f) desired=speed*(func_00388730(&velocity,obj+0xD0)/0.5f);
        else desired=speed;
        *(f32 *)(obj+0xF0)=*(f32 *)(obj+0xF0)*(1.0f-D_001DF538_sda)+desired*D_001DF538_sda;
    }
}
/* localdecomp:end func_L20_003F3520 */
