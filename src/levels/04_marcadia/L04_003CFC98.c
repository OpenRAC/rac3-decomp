#include "common.h"

/* localdecomp:start func_L04_003CFC98 */
void func_L01_004450F0(s32, s32, s32);
void func_L04_003CE760(void *, s32, s32, s32);

void func_L04_003CFC98(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2F4) = 0;
    func_L01_004450F0((s32) arg0, 0xD, 3);
    func_L04_003CE760(arg0, 1, 0, 1);
    func_L04_003CE760(arg0, 0, 0, 1);
}
/* localdecomp:end func_L04_003CFC98 */

INCLUDE_ASM("asm/levels", func_L04_003CFCF8);

INCLUDE_ASM("asm/levels", func_L04_003CFDA8);

INCLUDE_ASM("asm/levels", func_L04_003CFDB8);

/* localdecomp:start func_L04_003CFE28 */
f32 func_L04_003CFE28(void) {
    return 0.75f;
}
/* localdecomp:end func_L04_003CFE28 */
