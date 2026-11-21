#include "common.h"

/* NTSC-U counterpart of func_L13_003AEDD8 (src/levels/shared/L13_003AEB48.c): 0.02 -> 0.0166667 */
#include "vu0.h"
extern f32 D_L13_001DE70C, D_L13_001DE710, D_L13_001DE6EC_003ACFF0;
extern f32 D_L13_001DE70C;
extern f32 D_L13_001DE710;
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L13_003AD0C8(u8 *, u8 *, f32);
extern f32 func_00388A28(f32, f32);

/* localdecomp:start func_L13_003ACFF0 */
extern s32 func_L01_00458AE0(void *, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L13_003AD0C8(u8 *, u8 *, f32);
extern f32 D_L13_001DE710;
__asm__(".extern D_L13_001DE710, 4");
extern f32 D_L13_001DE70C;
__asm__(".extern D_L13_001DE70C, 4");

s32 func_L13_003ACFF0(u8 *obj, s32 arg1) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 result;
    f32 a;

    *(f32 *)(obj + 0x18) -= *(f32 *)(sub + 0x3B4);
    result = func_L01_00458AE0(obj, arg1);
    a = func_00389380(*(f32 *)(sub + 0x3B0), D_L13_001DE710 * 0.017453292f * 0.0166666675f);
    *(f32 *)(sub + 0x3B0) = a;
    *(f32 *)(sub + 0x3B4) = func_00388978(a) * D_L13_001DE70C;
    *(f32 *)(obj + 0x18) += *(f32 *)(sub + 0x3B4);
    func_L13_003AD0C8(obj, sub + 0x1F0, *(f32 *)(sub + 0x204));
    func_L01_00458A08(obj, func_00388A28(*(f32 *)(sub + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(sub + 0x134) - *(f32 *)(obj + 0x14)));
    return result;
}
/* localdecomp:end func_L13_003ACFF0 */
