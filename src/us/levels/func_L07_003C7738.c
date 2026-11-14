#include "common.h"

/* NTSC-U counterpart of func_L07_003C90F8 (src/levels/07_annihilation_nation/L07_003C7468.c): 0.0628319 -> 0.0523599 */
/* localdecomp:start func_L07_003C7738 */
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);

void func_L07_003C7738(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 t = func_00389380(*(f32 *)(p + 0x4C8), 0.0523598827f);

    *(f32 *)(p + 0x4C8) = t;
    t = func_003893C8(t, *(f32 *)(a0 + 0xF8));
    *(f32 *)(p + 0x288) = t;
    *(f32 *)(p + 0x2A8) = t;
}
/* localdecomp:end func_L07_003C7738 */
