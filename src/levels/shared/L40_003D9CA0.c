#include "common.h"

/* localdecomp:start func_L40_003D9CA0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32 a0, s32 a1);
u8 *func_L40_003D9CA0(u8 *a0, s32 a1) {
    u8 *m;
    u8 *pv;
    if (*(s8 *)(a0 + 32) < 0) {
        return 0;
    }
    m = func_003C24B0(6899, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        m[48] = 64;
        m[32] = 0;
        *(u8 **)(m + 184) = a0;
        pv[67] = a1;
        *(s32 *)(m + 152) = 0;
        *(u16 *)(m + 52) |= 0x41;
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
    }
    return m;
}
/* localdecomp:end func_L40_003D9CA0 */

INCLUDE_ASM("asm/levels", func_L40_003D9D28);

INCLUDE_ASM("asm/levels", func_L40_003D9E78);
