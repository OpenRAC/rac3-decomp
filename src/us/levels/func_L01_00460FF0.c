#include "common.h"

/* NTSC-U counterpart of func_L01_00464558 (src/levels/shared/L01_00462978.c) */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"

/* localdecomp:start func_L01_00460FF0 */
#include "vu0.h"
void func_L01_00460FF0(u8 *p)
{
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern void func_003886E8(void *, void *, f32);
    u8 *s=p+0x20;
    *(f32 *)(s+0x1C) += -0.04f;
    if (*(f32 *)(s+0x1C)<=0.0f || func_003883C8(p+0xA)) {
        func_003C7CE0(p);
    } else {
        *(f32 *)(p+0xC) += 12000.0f;
        if (*(f32 *)(s+0x18)<0.225f) {
            *(f32 *)(s+0x18) += 0.0484f;
        }
        *(u32 *)(p+4) = (*(u32 *)(p+4) & 0xFFFF) |
            (((s32)(*(f32 *)(s+0x18)*255.0f) & 255)<<16) |
            ((s32)(*(f32 *)(s+0x1C)*255.0f)<<24);
        vec_add_ab(p+0x10,p+0x10,p+0x20);
        func_003886E8(s,s,0.9f);
        p[8]--;
    }
}
/* localdecomp:end func_L01_00460FF0 */
