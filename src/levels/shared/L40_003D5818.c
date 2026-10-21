#include "common.h"

/* localdecomp:start func_L40_003D5818 */
extern void func_L39_0066DCC8(s32, s32, s32, s32);

void func_L40_003D5818(s32 a0) {
    func_L39_0066DCC8(a0, 1, 0, 250);
}
/* localdecomp:end func_L40_003D5818 */

INCLUDE_ASM("asm/levels", func_L40_003D5840);

INCLUDE_ASM("asm/levels", func_L40_003D59B0);

INCLUDE_ASM("asm/levels", func_L40_003D6070);

/* localdecomp:start func_L40_003D61B8 */
s32 func_L40_003D61B8(u8 *p, s32 *a1, s32 *a2) {
    s32 v = *(s32 *)(p + 104);
    *a2 = 12;
    *a1 = v;
    return 0;
}
/* localdecomp:end func_L40_003D61B8 */
