#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003B2668);

INCLUDE_ASM("asm/levels", func_L05_003B27F8);

INCLUDE_ASM("asm/levels", func_L05_003B29D0);

/* localdecomp:start func_L05_003B2E40 */
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L05_003B2E40(u8 *p) {
    s32 r;
    s32 a;

    a = 0;
    if (*(u8 *)(*(u8 **)(p + 0x68) + 0x2B8) < 3) {
        a = 3 - *(u8 *)(*(u8 **)(p + 0x68) + 0x2B8);
    }
    r = func_00382498(a, 2);
    switch (r) {
    case 0:
        func_L01_004450F0((s32) p, 9, -1);
        return;
    case 1:
        func_L01_004450F0((s32) p, 0xC, -1);
        return;
    case 2:
        func_L01_004450F0((s32) p, 0xF, -1);
        return;
    }
}
/* localdecomp:end func_L05_003B2E40 */

INCLUDE_ASM("asm/levels", func_L05_003B2EF0);
