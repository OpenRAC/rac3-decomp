#include "common.h"

/* localdecomp:start func_L40_0041D448 */
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
extern void func_L39_00662AA0(s32, s32 *, s32);
void func_L40_0041D448(s32 a0, s32 a1, s32 a2) {
    s32 buf[2];
    s32 h = func_L39_0066DCC8(a0, 0, 0, 250);
    buf[0] = a1;
    func_L39_00662AA0(h, &buf[0], 4);
    buf[1] = a2;
    func_L39_00662AA0(h, &buf[1], 4);
}
/* localdecomp:end func_L40_0041D448 */

INCLUDE_ASM("asm/levels", func_L40_0041D4B8);

INCLUDE_ASM("asm/levels", func_L40_0041D5A8);
