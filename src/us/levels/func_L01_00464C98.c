#include "common.h"

/* NTSC-U counterpart of func_L01_004682B8 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_00464C98 */
#include "vu0.h"
__asm__(".extern D_L01_001D7F14_00464C98, 4");
__asm__(".extern D_L01_001D7F18_00464C98, 4");
extern f32 D_L01_001D7F14_00464C98 __attribute__((section(".sdata")));
extern f32 D_L01_001D7F18_00464C98 __attribute__((section(".sdata")));
void func_L01_00464C98(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern void func_003886E8(void *, void *, f32);
    extern f32 func_003887C8(void *, void *);
    vu0_v4 v[2], temp;
    u8 *pos, *old;
    if (!*(u8 **)(self+0x30) || (*(u8 **)(self+0x30))[0x20] == 254 || (*(u8 **)(self+0x30))[0x20] == 253 || func_003883C8(self+0xA)) {
        func_003C7CE0(self);
        return;
    }
    vec_sub_ba(&temp, *(u8 **)(self+0x30)+0x10, self+0x10);
    pos=self+0x10;
    old=self+0x20;
    v[0]=v[1]=temp;
    func_003886E8(v,v,D_L01_001D7F14_00464C98);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x10)=v[1]=temp;
    vec_sub_ba(&temp,*(u8 **)(self+0x30)+0x10,self+0x20);
    v[0]=v[1]=temp;
    func_003886E8(v,v,D_L01_001D7F18_00464C98);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x20)=v[1]=temp;
    if (func_003887C8(pos,old)<0.1f || func_003887C8(pos,*(u8 **)(self+0x30)+0x10)<1.0f) func_003C7CE0(self);
}
/* localdecomp:end func_L01_00464C98 */
