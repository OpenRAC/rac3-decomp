#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D7048);

INCLUDE_ASM("asm/levels", func_L07_003D7350);

INCLUDE_ASM("asm/levels", func_L07_003D74A0);

INCLUDE_ASM("asm/levels", func_L07_003D7520);

/* localdecomp:start func_L07_003D7628 */
extern void func_L07_003D7680(void *, f32, f32, s32);

void func_L07_003D7628(void *arg0) {
    func_L07_003D7680(arg0, 2.5f, 0.0f, 8);
    func_L07_003D7680(arg0, 1.2f, 0.5235988f, 6);
}
/* localdecomp:end func_L07_003D7628 */

INCLUDE_ASM("asm/levels", func_L07_003D7680);
