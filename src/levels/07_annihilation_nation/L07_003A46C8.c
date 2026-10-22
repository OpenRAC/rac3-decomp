#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A46C8);

INCLUDE_ASM("asm/levels", func_L07_003A5078);

INCLUDE_ASM("asm/levels", func_L07_003A52F0);

/* localdecomp:start func_L07_003A55D8 */
void func_003C2880(s32);
void func_L07_00334740(void *);
void func_L07_003A5780(void *, s32);

void func_L07_003A55D8(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x498);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x498) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x264) = 0;
    }
    temp_a0_2 = *(s32 *)((u8 *)temp_s0 + 0x494);
    if (temp_a0_2 != 0) {
        func_003C2880(temp_a0_2);
        *(s32 *)((u8 *)temp_s0 + 0x494) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x260) = 0;
    }
    *(s16 *)((u8 *)arg0 + 0x7C) = 0x1F;
    *(f32 *)((u8 *)temp_s0 + 0x250) = (f32) (*(s16 *)((u8 *)temp_s0 + 0x34));
    func_L07_00334740(arg0);
    func_L07_003A5780(arg0, 1);
}
/* localdecomp:end func_L07_003A55D8 */

INCLUDE_ASM("asm/levels", func_L07_003A5670);

INCLUDE_ASM("asm/levels", func_L07_003A5780);

INCLUDE_ASM("asm/levels", func_L07_003A5CA8);

INCLUDE_ASM("asm/levels", func_L07_003A5D80);

INCLUDE_ASM("asm/levels", func_L07_003A5ED0);

INCLUDE_ASM("asm/levels", func_L07_003A5FA0);

INCLUDE_ASM("asm/levels", func_L07_003A5FE0);

INCLUDE_ASM("asm/levels", func_L07_003A60A8);

INCLUDE_ASM("asm/levels", func_L07_003A6110);

INCLUDE_ASM("asm/levels", func_L07_003A61E8);

INCLUDE_ASM("asm/levels", func_L07_003A63D8);

INCLUDE_ASM("asm/levels", func_L07_003A63E8);

INCLUDE_ASM("asm/levels", func_L07_003A6460);

INCLUDE_ASM("asm/levels", func_L07_003A6498);

INCLUDE_ASM("asm/levels", func_L07_003A66E8);

INCLUDE_ASM("asm/levels", func_L07_003A6C90);

INCLUDE_ASM("asm/levels", func_L07_003A6EA8);

INCLUDE_ASM("asm/levels", func_L07_003A6EF8);

INCLUDE_ASM("asm/levels", func_L07_003A6FC8);
