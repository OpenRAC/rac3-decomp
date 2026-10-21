#include "common.h"

/* localdecomp:start func_L40_00422A78 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00422A78(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00422A78 */

/* localdecomp:start func_L40_00422AA0 */
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
extern void func_L39_00662AA0(s32, s32 *, s32);

void func_L40_00422AA0(s32 a, s32 b) {
    s32 buf[4];
    s32 h = func_L39_0066DCC8(a, 1, 0, 250);
    buf[0] = b;
    func_L39_00662AA0(h, buf, 4);
}
/* localdecomp:end func_L40_00422AA0 */

INCLUDE_ASM("asm/levels", func_L40_00422AE8);

INCLUDE_ASM("asm/levels", func_L40_00422B60);

INCLUDE_ASM("asm/levels", func_L40_00422BC8);

INCLUDE_ASM("asm/levels", func_L40_00422C30);

/* localdecomp:start func_L40_00422D58 */
extern s32 func_L40_00422AE8(s32);
extern void func_L39_00672118(s32);
void func_L40_00422D58(u8 *p) {
    func_L39_00672118(func_L40_00422AE8(*(s16 *)(p + 0xAA)));
}
/* localdecomp:end func_L40_00422D58 */

INCLUDE_ASM("asm/levels", func_L40_00422D80);

INCLUDE_ASM("asm/levels", func_L40_00423120);

INCLUDE_ASM("asm/levels", func_L40_00423310);

INCLUDE_ASM("asm/levels", func_L40_00423510);
