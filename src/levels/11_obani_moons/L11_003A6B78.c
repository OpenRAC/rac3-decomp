#include "common.h"

/* localdecomp:start func_L11_003A6B78 */
__asm__(".extern D_L11_001DEA54, 16");
extern f32 D_L11_001DEA54;
extern void func_L01_004AA7E8(void *, s32);

void func_L11_003A6B78(u8 *a0)
{
    u8 *p;

    if (D_L11_001DEA54 != 200.0f) {
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    } else {
        p = *(u8 **)(a0 + 0x24);
        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L11_003A6B78 */

INCLUDE_ASM("asm/levels", func_L11_003A6BF8);

INCLUDE_ASM("asm/levels", func_L11_003A6CE0);
