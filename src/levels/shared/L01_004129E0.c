#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004129E0);

LINKER_REMNANT("asm/levels", func_L01_00412A88);

/* localdecomp:start func_L01_00412A98 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);

void func_L01_00412A98(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0038E7E8((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_L01_00412A98 */
