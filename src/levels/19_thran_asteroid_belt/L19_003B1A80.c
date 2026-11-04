#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003B1A80);

INCLUDE_ASM("asm/levels", func_L19_003B1E08);

INCLUDE_ASM("asm/levels", func_L19_003B2190);

INCLUDE_ASM("asm/levels", func_L19_003B2290);

INCLUDE_ASM("asm/levels", func_L19_003B2370);

INCLUDE_ASM("asm/levels", func_L19_003B2538);

INCLUDE_ASM("asm/levels", func_L19_003B2748);

INCLUDE_ASM("asm/levels", func_L19_003B2880);

INCLUDE_ASM("asm/levels", func_L19_003B2968);

/* localdecomp:start func_L19_003B2AC8 */
extern void func_L19_003B2968(u8 *a0, s32 a1);

void func_L19_003B2AC8(u8 *a0)
{
    s32 i;
    u16 flags;

    flags = *(u16 *)(a0 + 0x7C);
    if (flags & 2) {
        *(u16 *)(a0 + 0x7C) = flags | 0x100;
    }
    for (i = 0; i < 16; i++) {
        func_L19_003B2968(a0, i);
    }
}
/* localdecomp:end func_L19_003B2AC8 */

INCLUDE_ASM("asm/levels", func_L19_003B2B28);

INCLUDE_ASM("asm/levels", func_L19_003B2B90);

INCLUDE_ASM("asm/levels", func_L19_003B2C48);

INCLUDE_ASM("asm/levels", func_L19_003B2D00);

INCLUDE_ASM("asm/levels", func_L19_003B2EA8);
