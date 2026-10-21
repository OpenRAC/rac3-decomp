#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00412BB0);

/* localdecomp:start func_L01_00412BC0 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);

void func_L01_00412BC0(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_0038E7E8(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_L01_00412BC0 */

LINKER_REMNANT("asm/levels", func_L01_00412BF8);
