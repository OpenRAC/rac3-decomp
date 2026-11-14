#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L09_003B8580);

INCLUDE_ASM("asm/levels", func_L09_003BBB58);

INCLUDE_ASM("asm/levels", func_L09_003BBF10);

INCLUDE_ASM("asm/levels", func_L09_003BC288);

INCLUDE_ASM("asm/levels", func_L09_003BC450);

/* localdecomp:start func_L09_003BC790 */
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L09_003BC790(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    func_L09_003BC450(a0, a1, a2, a3, 0);
    *(s16 *)(p + 0xD38) = (f32)func_00382498(5, 10) * 50.0f;
}
/* localdecomp:end func_L09_003BC790 */

INCLUDE_ASM("asm/levels", func_L09_003BC7F0);

INCLUDE_ASM("asm/levels", func_L09_003BCE10);
