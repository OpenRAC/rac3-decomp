#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_00316710);

/* localdecomp:start func_L09_00317588 */
void func_L09_00317588(void *arg0) {
    u8 *temp_v1;

    temp_v1 = *(u8 **)((u8 *)arg0 + 0x68);
    *temp_v1 += 1;
}
/* localdecomp:end func_L09_00317588 */

/* localdecomp:start func_L09_003175A0 */
s32 func_L09_003175A0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    *(s8 *)((u8 *)temp_v1 + 1) = 1;
    *(s32 *)((u8 *)temp_v1 + 0x70) = arg1;
    *(s32 *)((u8 *)temp_v1 + 0x6C) = arg2;
    *(s32 *)((u8 *)temp_v1 + 0x74) = arg3;
    return 4 - (*(u8 *)temp_v1);
}
/* localdecomp:end func_L09_003175A0 */

INCLUDE_ASM("asm/levels", func_L09_003175C8);

/* localdecomp:start func_L09_00317798 */
s32 func_L01_00517918(s32);

void func_L09_00317798(void) {
    func_L01_00517918(0x15);
}
/* localdecomp:end func_L09_00317798 */

INCLUDE_ASM("asm/levels", func_L09_003177B8);

INCLUDE_ASM("asm/levels", func_L09_00317890);

INCLUDE_ASM("asm/levels", func_L09_00317B20);

INCLUDE_ASM("asm/levels", func_L09_00317D00);
