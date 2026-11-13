#include "common.h"

/* NTSC-U counterpart of func_L30_0034B980 (src/levels/30_vidcomic_unnamed/L30_00349390.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
extern f32 func_0038D0B0(f32);

/* localdecomp:start func_L30_0034AAA0 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_0044B5C8(f32, f32, void *, void *, s32);
__asm__(".extern D_L30_001DD4A0, 4");
extern f32 D_L30_001DD4A0;
__asm__(".extern D_L30_001DD49C, 4");
extern f32 D_L30_001DD49C;

s32 func_L30_0034AAA0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f20;
    s32 ret = 1;
    f32 r2;

    f20 = *(f32 *)(p + 0x210) + *(f32 *)(a0 + 0xF4);
    if (func_0038D0B0(f20) < D_L30_001DD4A0) {
        r2 = func_0038D098(f20);
        f20 = (r2 < 0.0f) ? 3.1415927f : 0.0f;
        ret = 0;
    }
    if (func_0038D098(f20) < 0.0f) {
        *(f32 *)(p + 0x1F8) = -D_L30_001DD49C;
        *(f32 *)(p + 0x1F0) = f20 - 3.1415927f;
    } else {
        *(f32 *)(p + 0x1F8) = D_L30_001DD49C;
        *(f32 *)(p + 0x1F0) = -f20;
    }
    func_L01_0044B5C8(0.0299999993f, 0.300000012f, a0, p + 0x190, 1);
    return ret;
}
/* localdecomp:end func_L30_0034AAA0 */
