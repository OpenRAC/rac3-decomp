#include "common.h"

typedef void (*fn_3A2780)(u8 *);

/* localdecomp:start func_L01_003A0710 */
extern s32 D_L01_001DE278;
extern s32 D_L01_001DE298;
extern s32 D_L01_001DE2A8;

s32 *func_L01_003A0710(s32 a0, s32 a1, s32 *out) {
    switch (a1) {
    case 5:
        *out = 0xC;
        return &D_L01_001DE2A8;
    case 1:
        *out = 0x1C;
        return &D_L01_001DE278;
    case 2:
        *out = 0xC;
        return &D_L01_001DE298;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_003A0710 */

INCLUDE_ASM("asm/levels", func_L01_003A0778);

INCLUDE_ASM("asm/levels", func_L01_003A33C0);
