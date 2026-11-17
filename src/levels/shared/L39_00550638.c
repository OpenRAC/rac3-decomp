#include "common.h"

/* localdecomp:start func_L39_00550638 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 *D_001D5A10_sda;
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern u8 *func_L39_0061BF38(s32);

s32 func_L39_00550638(u8 *a0, f32 *a1)
{
    u128_t tmp;
    s32 i;

    if (a0[0x31] == 0)
        return 0;
    tmp = *(u128_t *)a1;
    a1[3] = 0.5f;
    if (func_L39_005BE900(&tmp, 0, 36.0f) == 0)
        return 0;
    for (i = 0; i < *D_001D5A10_sda; i++) {
        if (func_L01_0040E548(func_L39_0061BF38(i) + 0xA0, a1) < 36.0f)
            return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00550638 */

INCLUDE_ASM("asm/levels", func_L39_00550700);

INCLUDE_ASM("asm/levels", func_L39_00550A28);
