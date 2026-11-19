/* functional: high. 33 diff words regalloc/scheduling; asm constants checked */
#include "common.h"

/* localdecomp:start func_L01_004CE758 */
extern s32 func_0011BB58(void *, s32, s32);
extern void func_L01_004CDC38(void *, s32, s32, f32, f32);

void func_L01_004CE758(u8 *o, s32 i, s32 a, s32 b)
{
    s32 v = 0x96;
    if (b != -1) {
        v = b;
    }
    func_0011BB58(o + i * 0x230 + 0x4698, a, 0xFE);
    func_L01_004CDC38(o + (i * 0x230 + 0x4610), 1, v, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CE758 */
