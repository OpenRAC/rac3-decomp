#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L03_003B99B8);

/* localdecomp:start func_L03_003B9D08 */

extern void func_0038D308(u8 *, u8 *);

void func_L03_003B9D08(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (*p != 0) {
            *(f32 *)(*p + 240) = *(f32 *)(a0 + 240);
            *(u128_t *)(*p + 16) = *(u128_t *)(a0 + 16);
            func_0038D308(*p + 192, *p + 240);
        }
        p++;
    }
}
/* localdecomp:end func_L03_003B9D08 */
