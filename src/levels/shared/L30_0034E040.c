#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_0034E040);

INCLUDE_ASM("asm/levels", func_L30_0034E370);

/* localdecomp:start func_L30_0034E420 */
extern void func_003C2F58(void *, s32, void *);
void func_L30_0034E420(void *a0, void *a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (*(s32 *)(s + 20) == 1) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 4) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 3) {
        func_003C2F58(a0, 1, a1);
    }
    if (*(s32 *)(s + 20) == 2) {
        func_003C2F58(a0, 1, a1);
    }
}
/* localdecomp:end func_L30_0034E420 */

INCLUDE_ASM("asm/levels", func_L30_0034E4D0);

INCLUDE_ASM("asm/levels", func_L30_0034E548);

INCLUDE_ASM("asm/levels", func_L30_0034E710);

INCLUDE_ASM("asm/levels", func_L30_0034E8A8);
