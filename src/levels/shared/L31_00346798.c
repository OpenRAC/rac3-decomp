#include "common.h"

/* localdecomp:start func_L31_00346798 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0xF8 - 0x14];
    f32 fF8;
} S_345C88;

extern f32 D_001A4C60[];
extern f32 func_0038DB00(f32 a, f32 b);

s32 func_L31_00346798(S_345C88 *a0, f32 a, f32 b, f32 c) {
    f32 x = a;
    if (a0->f10 < D_001A4C60[0]) {
        x = b;
    }
    if (c < __builtin_fabsf(func_0038DB00(a0->fF8, x))) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L31_00346798 */

INCLUDE_ASM("asm/levels", func_L31_00346800);

INCLUDE_ASM("asm/levels", func_L31_00346838);

INCLUDE_ASM("asm/levels", func_L31_00346998);
