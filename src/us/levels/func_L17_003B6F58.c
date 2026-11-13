#include "common.h"

/* NTSC-U counterpart of func_L17_003B8B18 (src/levels/shared/L17_003B8400.c) */
/* localdecomp:start func_L17_003B6F58 */
extern f32 D_L17_001DE5DC;
__asm__(".extern D_L17_001DE5DC, 4");
extern f32 D_L17_001DE5E0;
__asm__(".extern D_L17_001DE5E0, 4");
extern s32 D_L17_001DE5CC_003B6F58;
__asm__(".extern D_L17_001DE5CC_003B6F58, 4");
extern s32 D_L17_001DE5D0;
__asm__(".extern D_L17_001DE5D0, 4");
extern f32 D_L17_001DE5EC;
__asm__(".extern D_L17_001DE5EC, 4");
extern f32 D_L17_001DE5F0;
__asm__(".extern D_L17_001DE5F0, 4");
extern f32 D_L17_001DE608;
__asm__(".extern D_L17_001DE608, 4");
extern s32 D_L17_001DE5F4;
__asm__(".extern D_L17_001DE5F4, 4");
extern s32 D_L17_001DE5F8;
__asm__(".extern D_L17_001DE5F8, 4");
extern f32 D_L17_001DE5FC;
__asm__(".extern D_L17_001DE5FC, 4");
extern f32 D_L17_001DE600;
__asm__(".extern D_L17_001DE600, 4");
extern f32 D_L17_001DE60C;
__asm__(".extern D_L17_001DE60C, 4");
extern u8 D_L17_002A3270_003B6F58[];
extern void func_L17_003B7020(void *, s32, s32, s32, f32, f32, f32);

void func_L17_003B6F58(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v = D_L17_001DE5DC - D_L17_001DE5E0;
    D_L17_001DE5DC = v;
    if (v <= -8.0f) {
        D_L17_001DE5DC = v + 8.0f;
    }
    func_L17_003B7020(D_L17_002A3270_003B6F58 + *(s32 *)(s + 0x38) * 640, D_L17_001DE5CC_003B6F58, D_L17_001DE5D0,
                      *(s32 *)(s + 0x2C) - 2, D_L17_001DE5EC, D_L17_001DE5F0, D_L17_001DE608);
    func_L17_003B7020(D_L17_002A3270_003B6F58 + 0x140 + *(s32 *)(s + 0x38) * 640, D_L17_001DE5F4, D_L17_001DE5F8,
                      *(s32 *)(s + 0x2C), D_L17_001DE5FC, D_L17_001DE600, D_L17_001DE60C);
}
/* localdecomp:end func_L17_003B6F58 */
