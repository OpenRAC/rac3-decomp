#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003B8F10);

INCLUDE_ASM("asm/levels", func_L03_003B8FA0);

INCLUDE_ASM("asm/levels", func_L03_003B9130);

INCLUDE_ASM("asm/levels", func_L03_003B92E8);

INCLUDE_ASM("asm/levels", func_L03_003B9688);

INCLUDE_ASM("asm/levels", func_L03_003B9760);

INCLUDE_ASM("asm/levels", func_L03_003B97E0);

INCLUDE_ASM("asm/levels", func_L03_003B9898);

/* localdecomp:start func_L03_003B9938 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32 a, s32 b);

u8 *func_L03_003B9938(u8 *a0) {
    u8 *m = func_003C24B0(7230, 128);
    if (m != 0) {
        *(u8 *)(m + 48) = 255;
        *(u16 *)(m + 52) &= ~0x80;
        *(s16 *)(m + 50) = 64;
        *(u8 *)(m + 49) = 1;
        *(u8 **)(m + 184) = a0;
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
    }
    return m;
}
/* localdecomp:end func_L03_003B9938 */
