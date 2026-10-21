#include "common.h"

/* localdecomp:start func_L14_003CF8A0 */
extern s32 D_L14_001D6694;
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

void func_L14_003CF8A0(u8 *a0) {
    if (D_L14_001D6694 == 2) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & ~0x1000;
        func_L01_004AA7E8(a0, 1);
    } else {
        u8 *o = *(u8 **)(a0 + 36);
        *(u16 *)(a0 + 52) &= ~0x41;
        *(u16 *)(a0 + 52) |= *(u16 *)(o + 68) & 0x1000;
        *(s32 *)(a0 + 152) = *(s32 *)(o + 16);
    }
}
/* localdecomp:end func_L14_003CF8A0 */
