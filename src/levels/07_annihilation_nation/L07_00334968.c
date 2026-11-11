#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00334968);

INCLUDE_ASM("asm/levels", func_L07_003349E8);

/* localdecomp:start func_L07_00334A20 */
extern u8 D_001426E0[];
extern void func_0039EF28(void);
void func_L07_00334A20(s32 arg0) {
    s32 idx = arg0 >> 3;
    u32 bit = arg0 & 7;
    if (bit < 8) {
        D_001426E0[idx + 0xAD] |= 1 << bit;
    }
    func_0039EF28();
}
/* localdecomp:end func_L07_00334A20 */

/* localdecomp:start func_L07_00334A70 */
s32 func_L07_00333460(s32, s32);
s32 func_L07_00334A70(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_L07_00333460(arg0, -1);
    if (temp_v0 == 0) {
        return -1;
    }
    return (*(s32 *)((u8 *)temp_v0 + 8));
}
/* localdecomp:end func_L07_00334A70 */

INCLUDE_ASM("asm/levels", func_L07_00334A98);
