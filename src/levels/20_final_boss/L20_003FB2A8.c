#include "common.h"

/* localdecomp:start func_L20_003FB2A8 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L20_003FB2A8(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (a0[0x43] != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(v + 0x2EC), a1, a2, a3);
    }
}
/* localdecomp:end func_L20_003FB2A8 */
