#include "common.h"

/* NTSC-U counterpart of func_L07_003B6870 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003B4F80 */
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L07_003B4F80(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);

    func_L01_0044B5C8(a0, p + 0x1B0, 0, 0.03f, 0.3f);
    func_L01_0044B5C8(a0, p + 0x230, 1, 0.03f, 0.3f);
}
/* localdecomp:end func_L07_003B4F80 */
