#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003CD2C0);

INCLUDE_ASM("asm/levels", func_L04_003CE120);

INCLUDE_ASM("asm/levels", func_L04_003CE348);

/* localdecomp:start func_L04_003CE5A8 */
extern void func_003C2880(u8 *a0);
extern void (**func_L01_0043B548(s32 a0, s32 a1))(u8 *);

void func_L04_003CE5A8(u8 *arg0, s32 arg1) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    void (**t)(u8 *);

    if (*(u32 *)(s2 + 0x300) != 0) {
        func_003C2880(*(u8 **)(s2 + 0x300));
        *(u32 *)(s2 + 0x300) = 0;
    }
    if (*(u32 *)(s2 + 0x240) != 0) {
        t = func_L01_0043B548(6625, 108);
        (*t)(arg0);
        if (arg1 != 0) {
            t[1](arg0);
        }
    } else {
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L04_003CE5A8 */
