#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00348868);

INCLUDE_ASM("asm/levels", func_L30_00348C30);

INCLUDE_ASM("asm/levels", func_L30_00348EE0);

INCLUDE_ASM("asm/levels", func_L30_00349098);

/* localdecomp:start func_L30_00349280 */
__asm__(".extern D_001DF71C, 16");
extern u8 *D_001DF71C;
extern s32 func_0038CAD0(void *);
extern void func_L30_0034BC90(void *, f32, s32, s32);

void func_L30_00349280(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_0038CAD0(s0 + 0x110)) {
        func_L30_0034BC90(D_001DF71C + (*(s32 *)(s0 + 0x104) << 8), -0.77f, 4, 0x3C);
        func_L30_0034BC90(D_001DF71C + (*(s32 *)(s0 + 0x108) << 8), -0.77f, 4, 0x3C);
    }
    if (func_0038CAD0(s0 + 0x120)) {
        func_L30_0034BC90(D_001DF71C + (*(s32 *)(s0 + 0x114) << 8), -0.77f, 4, 0x3C);
        func_L30_0034BC90(D_001DF71C + (*(s32 *)(s0 + 0x118) << 8), -0.77f, 4, 0x3C);
    }
}
/* localdecomp:end func_L30_00349280 */
