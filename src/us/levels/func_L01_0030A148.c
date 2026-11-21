#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0030A3E8 (src/levels/shared/L01_003068B8.c): the slot at +0x88 is set to 20, not 17 */
/* localdecomp:start func_L01_0030A148 */
typedef struct {
    u8 pad0[140];
    s32 a;
    u8 pad1[16];
} A_0030A148;
extern A_0030A148 D_L01_0026FDB0[30];
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_0044E010(u8 *, f32 *, s32);
extern void func_003886E8(f32 *, f32 *, f32);
void func_L01_0030A148(u8 *m, u8 *target, s32 value) {
    u8 *vars=*(u8 **)(m+0x68);
    u8 *r;
    u8 *base=(u8 *)D_L01_0026FDB0;
    u8 *info;
    f32 tmp[4];
    s32 i;
    for(i=0;i<30;i++) {
        r=(u8 *)(i*0xa0+(u32)base);
        if (*(s32 *)(r+0x8c)) continue;
        *(u8 **)(r+0x8c)=m;
        ++*(s32 *)(vars+0x54);
        *(vu0_q *)(r+0x20)=*(vu0_q *)(m+0x10);
        *(f32 *)(r+0x40)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x44)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x48)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x64)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x68)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x6c)=func_0037E250(-3.1415927f,3.1415927f);
        *(f32 *)(r+0x4c)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x50)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x54)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x70)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x74)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x78)=func_L01_00440918(0.001f,0.005f);
        *(f32 *)(r+0x58)=func_0037E250(3.25f,4.75f);
        *(f32 *)(r+0x5c)=func_0037E250(3.25f,4.75f);
        *(f32 *)(r+0x60)=func_0037E250(3.25f,4.75f);
        *(f32 *)(r+0x7c)=func_0037E250(3.25f,4.75f);
        *(f32 *)(r+0x80)=func_0037E250(3.25f,4.75f);
        *(f32 *)(r+0x84)=func_0037E250(3.25f,4.75f);
        *(s32 *)(r+0x94)=value;
        *(s32 *)(r+0x98)=value;
        qzero(r);
        qzero(r+0x10);
        *(s32 *)(r+0x88)=20;
        *(u8 **)(r+0x90)=target;
        *(s32 *)(r+0x9c)=0;
        info=func_0037E0B8(target);
        if (info) {
            func_L01_0044E010(target,tmp,1);
            func_003886E8(tmp,tmp,*(f32 *)(info+0x10));
            vec_add_ba(r+0x30,tmp,target+0x10);
        } else {
            *(vu0_q *)(r+0x30)=*(vu0_q *)(target+0x10);
        }
        break;
    }
}
/* localdecomp:end func_L01_0030A148 */
