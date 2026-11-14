#include "common.h"

/* NTSC-U counterpart of func_L07_003BCDD0 (src/levels/07_annihilation_nation/L07_003BCDD0.c): 0.125664 -> 0.10472 */
/* localdecomp:start func_L07_003BB4C0 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);

void func_L07_003BB4C0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t;
    f32 v;

    *(f32 *)(a0 + 0x18) -= *(f32 *)(s + 0x2AC);
    t = func_00389380(*(f32 *)(s + 0x2A8), 0.104719765f);
    *(f32 *)(s + 0x2A8) = t;
    v = func_00388978(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
}
/* localdecomp:end func_L07_003BB4C0 */
