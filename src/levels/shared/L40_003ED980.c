#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_003ED980);

INCLUDE_ASM("asm/levels", func_L40_003EDA10);

INCLUDE_ASM("asm/levels", func_L40_003EDAB8);

LINKER_REMNANT("asm/levels", func_L40_003EDB28);

/* localdecomp:start func_L40_003EDB38 */
extern s32 D_001A5DF8[];
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);

void func_L40_003EDB38(void *a0, void *a1, u8 *a2) {
    u8 *state = *(u8 **)(a2 + 0x68);
    u8 *p = func_L39_0066C2B8();
    u8 *q;
    s32 off;

    if (p != 0) {
        off = func_L39_0066C280(4, a0, D_001A5DF8[0] + 0x1F4, a1, p);
        q = p + off;
        *(s32 *)q = *(s32 *)(state + 0x26C);
        q += 4;
        *(s32 *)p = (s32)q - (s32)p;
    }
}
/* localdecomp:end func_L40_003EDB38 */

INCLUDE_ASM("asm/levels", func_L40_003EDBC0);

INCLUDE_ASM("asm/levels", func_L40_003EDC68);

INCLUDE_ASM("asm/levels", func_L40_003EE008);

INCLUDE_ASM("asm/levels", func_L40_003EE130);

INCLUDE_ASM("asm/levels", func_L40_003EEC40);

INCLUDE_ASM("asm/levels", func_L40_003EEE80);

INCLUDE_ASM("asm/levels", func_L40_003EFC00);

INCLUDE_ASM("asm/levels", func_L40_003EFD50);
