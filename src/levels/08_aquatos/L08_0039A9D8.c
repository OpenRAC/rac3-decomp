#include "common.h"

/* localdecomp:start func_L08_0039A9D8 */
void func_L01_004450F0(s32, s32, s32);
void func_003C2880(s32);
void func_L01_003361D8(void *);
void func_L01_0044EA78(void *, s32);

void func_L08_0039A9D8(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004450F0((s32) arg0, 1, -1);
    func_L01_0044EA78(arg0, temp_s0 + 0x4D0);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x5D0);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
    }
    func_L01_003361D8(arg0);
}
/* localdecomp:end func_L08_0039A9D8 */

INCLUDE_ASM("asm/levels", func_L08_0039AA38);

INCLUDE_ASM("asm/levels", func_L08_0039AC38);

INCLUDE_ASM("asm/levels", func_L08_0039ACD0);

INCLUDE_ASM("asm/levels", func_L08_0039AD20);

INCLUDE_ASM("asm/levels", func_L08_0039AD70);

INCLUDE_ASM("asm/levels", func_L08_0039ADC0);

INCLUDE_ASM("asm/levels", func_L08_0039AE10);

INCLUDE_ASM("asm/levels", func_L08_0039AE60);

INCLUDE_ASM("asm/levels", func_L08_0039AEB0);

INCLUDE_ASM("asm/levels", func_L08_0039AF00);

INCLUDE_ASM("asm/levels", func_L08_0039AF50);

INCLUDE_ASM("asm/levels", func_L08_0039AFA0);
