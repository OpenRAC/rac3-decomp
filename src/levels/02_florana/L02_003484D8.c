#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_003484D8);

INCLUDE_ASM("asm/levels", func_L02_0034BF90);

INCLUDE_ASM("asm/levels", func_L02_0034C308);

/* localdecomp:start func_L02_0034C7B8 */
void func_003C2880(void *);
void func_003C7C38(void *);
void func_L01_004443E8(void *, s32, s32);

void func_L02_0034C7B8(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;
    void *temp_s1;
    void *temp_v0;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_s0 = *(void **)((u8 *)((*(void **)((u8 *)temp_s1 + 0x2E0))) + 0x68);
    temp_a0 = *(void **)((u8 *)temp_s0 + 0x18);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(void **)((u8 *)temp_s0 + 0x18) = 0;
    }
    temp_a0_2 = *(void **)((u8 *)temp_s0 + 0x1C);
    if (temp_a0_2 != 0) {
        func_003C2880(temp_a0_2);
        *(void **)((u8 *)temp_s0 + 0x1C) = 0;
    }
    func_003C2880((*(void **)((u8 *)temp_s1 + 0x2E0)));
    temp_v0 = *(void **)((u8 *)temp_s1 + 0xB14);
    if (temp_v0 != 0) {
        *(s32 *)((u8 *)temp_v0 + 0x98) = 0;
        func_003C7C38((*(void **)((u8 *)temp_s1 + 0xB14)));
    }
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L02_0034C7B8 */

INCLUDE_ASM("asm/levels", func_L02_0034C858);
