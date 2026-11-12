#include "common.h"

/* localdecomp:start func_L21_003BE250 */
extern void func_003C2880(void *);

void func_L21_003BE250(u8 *p) {
    u8 *a = *(u8 **)(p + 0x68);

    if (a == 0) {
        func_003C2880(p);
        return;
    }
    if (p[0x20] == 0) {
        *(u32 *)(a + 0x6C) |= 1;
        p[0x20] = 1;
    }
}
/* localdecomp:end func_L21_003BE250 */
