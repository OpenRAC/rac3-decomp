#include "common.h"

/* NTSC-U counterpart of func_L07_003BCE68 (src/levels/07_annihilation_nation/L07_003BCDD0.c): 0.125664 -> 0.10472 */
/* localdecomp:start func_L07_003BB558 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L07_003BB5D8(void *, void *, f32);
void func_L07_003BB558(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t = func_0038DAB8(*(f32 *)(s + 0x2A8), 0.104719765f);
    f32 v;
    *(f32 *)(s + 0x2A8) = t;
    v = func_0038D0B0(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
    func_L07_003BB5D8(a0, s + 0xD0, *(f32 *)(s + 0xE4));
}
/* localdecomp:end func_L07_003BB558 */
