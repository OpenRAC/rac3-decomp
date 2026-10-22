#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0035F9B0);

/* localdecomp:start func_L14_0035FA00 */
void func_003C3A10(void *, s32, s32, s32);

void func_L14_0035FA00(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2D0) = 2;
    if ((*(u8 *)((u8 *)arg0 + 0x43)) != 0) {
        func_003C3A10(arg0, 0, 0, 0);
    }
}
/* localdecomp:end func_L14_0035FA00 */
