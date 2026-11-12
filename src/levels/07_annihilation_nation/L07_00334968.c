#include "common.h"

/* localdecomp:start func_L07_00334968 */
extern s32 func_00382468(s32);

void func_L07_00334968(u8 *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        u8 j = func_00382468(arg1);

        if (j != i) {
            u8 a = arg0[i];
            u8 b = arg0[j];

            arg0[j] = a;
            arg0[i] = b;
        }
    }
}
/* localdecomp:end func_L07_00334968 */

/* localdecomp:start func_L07_003349E8 */
extern u8 D_001426E0[];

s32 func_L07_003349E8(s32 arg0) {
    u32 bit = arg0 & 7;
    s32 idx = arg0 >> 3;

    return (bit < 8) ? (D_001426E0[idx + 0xAD] & (1 << bit)) : 0;
}
/* localdecomp:end func_L07_003349E8 */

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
