#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003BEAC0 */
extern void func_L07_003BEB50(void *, void *, s32, s32, s32);

void func_L07_003BEAC0(u8 *arg0) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *p = s2 + 0x4F2;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s2[0x4FB] >> i) & 1) {
            func_L07_003BEB50(arg0, s2 + 0x3B0 + i * 0xA0, p[i - 2], p[i], s2[0x4FC] + 0x64);
        }
    }
}
/* localdecomp:end func_L07_003BEAC0 */

INCLUDE_ASM("asm/levels", func_L07_003BEB50);
