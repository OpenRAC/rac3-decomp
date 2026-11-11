#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_00338DF8);

INCLUDE_ASM("asm/levels", func_L21_00339088);

/* localdecomp:start func_L21_00339148 */
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);

void func_L21_00339148(void) {
    func_L01_003E8BD0(0, 0, 7.0f, 0.003f);
    func_L01_003E8D48(0, 0.34906584f);
}
/* localdecomp:end func_L21_00339148 */

INCLUDE_ASM("asm/levels", func_L21_00339190);

/* localdecomp:start func_L21_00339248 */
s32 func_L21_00339248(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 6;
}
/* localdecomp:end func_L21_00339248 */

INCLUDE_ASM("asm/levels", func_L21_00339258);

INCLUDE_ASM("asm/levels", func_L21_003392E0);

INCLUDE_ASM("asm/levels", func_L21_003393C0);
