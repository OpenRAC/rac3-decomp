#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B9A90);

INCLUDE_ASM("asm/levels", func_L07_003B9C28);

INCLUDE_ASM("asm/levels", func_L07_003B9DF8);

INCLUDE_ASM("asm/levels", func_L07_003BA000);

/* localdecomp:start func_L07_003BA098 */
typedef int Q_003BA098 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003BA098(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003BA098 *)(arg0 + 0x10) = *(Q_003BA098 *)(p + 0x80);
        *(Q_003BA098 *)(p + 0x80) = *(Q_003BA098 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003BA098 */

INCLUDE_ASM("asm/levels", func_L07_003BA0E8);

INCLUDE_ASM("asm/levels", func_L07_003BA500);

INCLUDE_ASM("asm/levels", func_L07_003BA970);
