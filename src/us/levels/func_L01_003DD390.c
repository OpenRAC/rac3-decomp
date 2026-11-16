#include "common.h"

/* NTSC-U counterpart of func_L01_003DEFE8 (src/levels/shared/L01_003D9510.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40_003DD390;
typedef struct {
    u128_t direction;
    f32 life;
    s32 ticks;
    s32 flag;
    s32 state;
    f32 length;
    s32 lead;
    s32 target;
} Vars_003DC268;
typedef struct {
    u8 pad0[16];
    u128_t position;
    u8 pad20[4];
    u8 *cls;
    u8 pad28[4];
    f32 scale;
    u8 opacity;
    u8 mode;
    u16 flags;
    u8 pad34[0x34];
    Vars_003DC268 *vars;
    u8 pad6C[0x4C];
    void *parent;
    u8 padBC[4];
    u8 matrix[0x30];
    f32 rotation[4];
} Obj_003DC268;
#include "vu0.h"

/* localdecomp:start func_L01_003DD390 */
extern vu0_v4 D_L01_001E2A40_003DD390;
extern s32 D_L01_001DF590;
__asm__(".extern D_L01_001DF590, 4");
u8 *func_L01_003DD390(u128_t *position) {
    extern Obj_003DC268 *func_003BCFB0(s32,s32);
    extern void func_00388830(void *,void *,f32);
    extern void func_003BFC18(void *,void *,s32);
    extern void func_00388758(void *,void *,void *);
    extern void func_L01_003DDB38(void *,void *,f32,f32,f32,s32,u32,u32,f32,s32,s32);
    vu0_v4 direction;
    vu0_v4 normal;
    u8 *obj=(u8 *)func_003BCFB0(0x1df6,128);
    u8 *vars;
    s32 i;
    if(obj) {
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=255;
        obj[0x20]=0;
        *(u128_t *)(obj+0x10)=*position;
        vars=*(u8 **)(obj+0x68);
        *(f32 *)(obj+0x1c)=1.0f;
        vec_sub_ba(&direction,&D_L01_001E2A40_003DD390,obj+0x10);
        func_00388830(&direction,&direction,1.0f);
        func_003BFC18(obj+0x10,&normal,1);
        *(u128_t *)(obj+0xc0)=*(u128_t *)&direction;
        func_00388758(obj+0xd0,obj+0xc0,&normal);
        func_00388830(obj+0xd0,obj+0xd0,1.0f);
        func_00388758(obj+0xe0,obj+0xd0,obj+0xc0);
        *(f32 *)(obj+0xcc)=*(f32 *)(obj+0xdc)=*(f32 *)(obj+0xec)=0.0f;
        *(s32 *)(vars+8)=64;
        *(s32 *)(vars+0x10)=30;
        *(s32 *)(vars+0xc)=-1;
        *(s32 *)(vars+0x14)=0;
        obj[0x20]=1;
        *(s32 *)(vars+0x18)=-1;
        *(s32 *)(vars+0x28)=0;
        for(i=0;i<24;i++) {
            func_L01_003DDB38(obj,obj+0x10,0.03490658476948738f,0.3f,1.1f,D_L01_001DF590,0x204080ff,0x204080ff,4.0f,255,255);
        }
    }
    return obj;
}
/* localdecomp:end func_L01_003DD390 */
