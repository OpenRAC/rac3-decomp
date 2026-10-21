#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003C0EA8);

INCLUDE_ASM("asm/levels", func_L05_003C24F0);

INCLUDE_ASM("asm/levels", func_L05_003C2618);

INCLUDE_ASM("asm/levels", func_L05_003C28C8);

INCLUDE_ASM("asm/levels", func_L05_003C2B50);

/* localdecomp:start func_L05_003C2C90 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038D308(u8 *a0, u8 *a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
void func_L05_003C2C90(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s16 *)(p + 408) = 0;
    *(f32 *)(p + 48) = *(s16 *)(p + 52);
    a0[127] = 0;
    *(u128_t *)(a0 + 16) = *(u128_t *)(p + 832);
    *(u128_t *)(a0 + 240) = *(u128_t *)(p + 816);
    func_0038D308(a0 + 192, p + 816);
    *(s32 *)(a0 + 152) = *(s32 *)(*(u8 **)(a0 + 36) + 16);
    func_L01_004450F0(a0, 0, 0);
}
/* localdecomp:end func_L05_003C2C90 */

INCLUDE_ASM("asm/levels", func_L05_003C2D08);
