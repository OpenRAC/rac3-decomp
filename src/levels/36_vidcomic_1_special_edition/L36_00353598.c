#include "common.h"

INCLUDE_ASM("asm/levels", func_L36_00353598);

INCLUDE_ASM("asm/levels", func_L36_00353F58);

INCLUDE_ASM("asm/levels", func_L36_003540D8);

INCLUDE_ASM("asm/levels", func_L36_00354288);

INCLUDE_ASM("asm/levels", func_L36_00354648);

INCLUDE_ASM("asm/levels", func_L36_003549F0);

INCLUDE_ASM("asm/levels", func_L36_00354B28);

INCLUDE_ASM("asm/levels", func_L36_00354D88);

/* localdecomp:start func_L36_00355210 */
#include "vu0.h"
extern u8 D_001D66B0[];
extern void func_L36_003553B8(u8 *, u8 *, f32, f32);
void func_L36_00355210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i;
    s32 *q;
    f32 f = *(f32 *)p;
    *(s32 *)(p + 0x80) = 0x3F;
    func_L36_003553B8(a0, D_001D66B0, f, f);
    for (i = 12, q = (s32 *)(p + 0xBC); i >= 0; i--) {
        *q-- = 0;
    }
    *(s32 *)(p + 0x7C) = 0;
    *(s32 *)(p + 0x70) = 1;
    *(s32 *)(p + 0x74) = 0;
    *(s32 *)(p + 0x78) = 0;
    qzero(p + 0x60);
}
/* localdecomp:end func_L36_00355210 */
