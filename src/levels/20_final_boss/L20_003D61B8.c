#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003D61B8);

INCLUDE_ASM("asm/levels", func_L20_003D65D0);

/* localdecomp:start func_L20_003D6AE0 */
extern s32 func_L01_0044E1B8(void *, f32);

s32 func_L20_003D6AE0(void *arg0) {
    if (func_L01_0044E1B8(arg0, 112.0f) || func_L01_0044E1B8(arg0, 120.0f) ||
        func_L01_0044E1B8(arg0, 128.0f) || func_L01_0044E1B8(arg0, 136.0f) ||
        func_L01_0044E1B8(arg0, 144.0f)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L20_003D6AE0 */

INCLUDE_ASM("asm/levels", func_L20_003D6B78);

INCLUDE_ASM("asm/levels", func_L20_003D6BF8);

INCLUDE_ASM("asm/levels", func_L20_003D6D18);
