#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005BA3A0);

INCLUDE_ASM("asm/levels", func_L39_005BA418);

/* localdecomp:start func_L39_005BA488 */
void func_L39_005BA488(f32 *v, u32 *out) {
    *out = ((s32)(v[0] + v[0]) << 21) | (((s32)(v[1] + v[1]) & 0x7FF) << 10) | ((s32)v[2] & 0x3FF);
}
/* localdecomp:end func_L39_005BA488 */
