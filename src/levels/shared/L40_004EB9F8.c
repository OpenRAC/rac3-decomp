#include "common.h"

LINKER_REMNANT("asm/levels", func_L40_004EB9F8);

/* localdecomp:start func_L40_004EBA00 */
void func_L40_004EBA00(u8 *a0, f32 *r) {
    *(f32 *)(a0 + 0x10) = r[0] + (r[2] - r[0]) * 0.5f;
    *(f32 *)(a0 + 0x14) = r[1] + (r[3] - r[1]) * 0.5f;
}
/* localdecomp:end func_L40_004EBA00 */
