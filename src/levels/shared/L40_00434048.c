#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00434048);

/* localdecomp:start func_L40_004341E8 */
extern s32 func_L40_00449788(s32 a0, u8 *a1);
extern s32 func_L40_0044A4C8(s32 a0, u8 *a1);
s32 func_L40_004341E8(u8 *a0) {
    s32 r;
    if (*(s32 *)(a0 + 4) != 0) {
        if (a0[10] == 0) {
            r = func_L40_00449788(*(s16 *)(a0 + 8), a0);
        } else {
            r = func_L40_0044A4C8(*(s16 *)(a0 + 8), a0);
        }
        if (r != 0) {
            *(s32 *)(a0 + 4) = 0;
        }
    }
    return *(s32 *)(a0 + 4) == 0;
}
/* localdecomp:end func_L40_004341E8 */

/* localdecomp:start func_L40_00434248 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00434248(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00434248 */

INCLUDE_ASM("asm/levels", func_L40_00434270);

INCLUDE_ASM("asm/levels", func_L40_00434398);

/* localdecomp:start func_L40_004343F0 */
extern void func_L39_0066DCC8(int, int, int, int);

void func_L40_004343F0(int a0)
{
    func_L39_0066DCC8(a0, 2, 0, 0);
}
/* localdecomp:end func_L40_004343F0 */

INCLUDE_ASM("asm/levels", func_L40_00434418);

INCLUDE_ASM("asm/levels", func_L40_004349A0);
