#include "common.h"

/* localdecomp:start func_L02_003519F0 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L02_001D66B0_3519F0[2];

void func_L02_003519F0(u8 *a0) {
    u8 *p = *(u8 **)(*(u8 **)(a0 + 0xB8) + 0x68);
    u128_t *src;
    s32 i;
    src = (u128_t *)D_L02_001D66B0_3519F0;
    for (i = 0x1D; i >= 0; i--) {
        *(u128_t *)(p + 0x310 + *(s32 *)(p + 0x914) * 16) = *src;
        *(s32 *)(p + 0x914) = 0;
        *(s32 *)(p + 0x918) = 0;
        *(s32 *)(p + 0x910) = 0;
    }
}
/* localdecomp:end func_L02_003519F0 */
