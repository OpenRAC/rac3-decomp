#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004ECE38);

INCLUDE_ASM("asm/levels", func_L39_004EEEF0);

INCLUDE_ASM("asm/levels", func_L39_004EEFF0);

INCLUDE_ASM("asm/levels", func_L39_004EF078);

/* localdecomp:start func_L39_004EF240 */
extern s32 func_L39_004EF078(s32, u8 *, s32, s32, s32, u8 *, s32);

s32 func_L39_004EF240(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8) {
    s32 len = a5 / 2;
    u8 *b = a4 + len;
    s32 i;

    len += a5 & 1;

    if (!func_L39_004EF078(a0, a4, len, a2, a3, a6, a8)) {
        return 0;
    }
    if (!func_L39_004EF078(a1, b, len, a2, a3, a7, a8)) {
        return 0;
    }
    for (i = 0; i < a8; i++) {
        a6[i] ^= a7[i];
    }
    return 1;
}
/* localdecomp:end func_L39_004EF240 */

INCLUDE_ASM("asm/levels", func_L39_004EF350);

INCLUDE_ASM("asm/levels", func_L39_004F01D8);

INCLUDE_ASM("asm/levels", func_L39_004F02A0);

INCLUDE_ASM("asm/levels", func_L39_004F0A78);

INCLUDE_ASM("asm/levels", func_L39_004F1230);

INCLUDE_ASM("asm/levels", func_L39_004F1358);

INCLUDE_ASM("asm/levels", func_L39_004F1498);

INCLUDE_ASM("asm/levels", func_L39_004F1608);
