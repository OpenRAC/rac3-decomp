#include "common.h"

/* NTSC-U counterpart of func_L36_0031D5F0 (src/levels/36_vidcomic_1_special_edition/L36_0031D5F0.c): 0.0418879 -> 0.0349066; 0.15708 -> 0.1309 */
/* localdecomp:start func_L36_0031D0A0 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_L36_001DC804, 4");
extern f32 D_L36_001DC804;
extern f32 func_0038DAB8(f32, f32);
extern void func_L36_0031D218(u8 *);
extern void func_L01_0031F768(u8 *);

void func_L36_0031D0A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(p + 0x24) * D_L36_001DC804;
    if (*(u8 *)(a0 + 0x20) == 0) {
        func_L36_0031D218(a0);
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 0.0349065885f);
        *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), 0.130899698f);
        func_L01_0031F768(a0);
    }
}
/* localdecomp:end func_L36_0031D0A0 */
