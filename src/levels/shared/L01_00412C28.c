#include "common.h"

/* localdecomp:start func_L01_00412C28 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);

void func_L01_00412C28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FA18(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_L01_00412C28 */

LINKER_REMNANT("asm/levels", func_L01_00412C58);
