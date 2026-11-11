#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_003F7C70);

INCLUDE_ASM("asm/levels", func_L14_003F7EB8);

INCLUDE_ASM("asm/levels", func_L14_003F8060);

/* localdecomp:start func_L14_003F8170 */
extern void func_003D3A24(s32, s32, s32, s32, s32);
void func_L14_003F8170(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i = a0;
    s32 k = i - 3;
    func_003D3A24(a1 - k, i * 12 + a2, a3 + i * 4, a4 + i * 8, 1);
}
/* localdecomp:end func_L14_003F8170 */

INCLUDE_ASM("asm/levels", func_L14_003F81B8);

INCLUDE_ASM("asm/levels", func_L14_003F8550);
