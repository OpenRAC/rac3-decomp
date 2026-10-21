#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00354AE8);

INCLUDE_ASM("asm/levels", func_L04_00355058);

INCLUDE_ASM("asm/levels", func_L04_003553F0);

/* localdecomp:start func_L04_00355678 */
extern void func_L04_00355740(void *, s32, s32, void *, f32);

void func_L04_00355678(u8 *a) {
    u8 *v = *(u8 **)(a + 104);
    func_L04_00355740(a + 16, *(s32 *)(v + 64), *(s32 *)(v + 68), a, *(f32 *)(a + 44) * 90.0f);
}
/* localdecomp:end func_L04_00355678 */
