#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
extern u8 D_1A4C60[];

/* localdecomp:start func_L32_003A3E70 */
void func_L32_003A3038(void *);
void func_L32_003A3888(void *, s32);
extern s32 D_L32_001DE6E0;
extern s32 D_L32_001DE6E4;

void func_L32_003A3E70(void *arg0) {
    if ((D_L32_001DE6E4 - (*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x78))) < D_L32_001DE6E0) {
        func_L32_003A3888(arg0, D_L32_001DE6E0);
    }
    func_L32_003A3038(arg0);
}
/* localdecomp:end func_L32_003A3E70 */

INCLUDE_ASM("asm/levels", func_L32_003A3EC8);

INCLUDE_ASM("asm/levels", func_L32_003A40B0);

INCLUDE_ASM("asm/levels", func_L32_003A4270);

INCLUDE_ASM("asm/levels", func_L32_003A4360);
