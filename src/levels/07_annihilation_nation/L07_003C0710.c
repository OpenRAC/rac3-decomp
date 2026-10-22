#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003C0710);

INCLUDE_ASM("asm/levels", func_L07_003C0BE8);

/* localdecomp:start func_L07_003C0D00 */
void func_L01_003EB5E0(s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_005003D0(s32, s32);

void func_L07_003C0D00(s32 arg0) {
    func_L01_005003D0(0, 1);
    func_L01_003EB5E0(0, 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003C0D00 */

INCLUDE_ASM("asm/levels", func_L07_003C0D48);

INCLUDE_ASM("asm/levels", func_L07_003C0E08);

INCLUDE_ASM("asm/levels", func_L07_003C0E58);

INCLUDE_ASM("asm/levels", func_L07_003C0ED8);

INCLUDE_ASM("asm/levels", func_L07_003C0F40);

INCLUDE_ASM("asm/levels", func_L07_003C0FC8);

INCLUDE_ASM("asm/levels", func_L07_003C1120);

INCLUDE_ASM("asm/levels", func_L07_003C1138);

INCLUDE_ASM("asm/levels", func_L07_003C12A8);

INCLUDE_ASM("asm/levels", func_L07_003C1360);

/* localdecomp:start func_L07_003C1430 */
extern u8 D_001D5551[];

u8 func_L07_003C1430(s32 arg0) {
    u8 var_v0;

    var_v0 = 1;
    if (arg0 == 0) {
        var_v0 = D_001D5551[0];
    }
    return var_v0;
}
/* localdecomp:end func_L07_003C1430 */

INCLUDE_ASM("asm/levels", func_L07_003C1448);

INCLUDE_ASM("asm/levels", func_L07_003C1528);

INCLUDE_ASM("asm/levels", func_L07_003C17C0);

INCLUDE_ASM("asm/levels", func_L07_003C19C8);

INCLUDE_ASM("asm/levels", func_L07_003C1AF8);

INCLUDE_ASM("asm/levels", func_L07_003C1B40);

INCLUDE_ASM("asm/levels", func_L07_003C1B88);

INCLUDE_ASM("asm/levels", func_L07_003C1C08);

INCLUDE_ASM("asm/levels", func_L07_003C1C88);

INCLUDE_ASM("asm/levels", func_L07_003C1D58);

INCLUDE_ASM("asm/levels", func_L07_003C1DC8);

INCLUDE_ASM("asm/levels", func_L07_003C1E48);

INCLUDE_ASM("asm/levels", func_L07_003C1E80);

INCLUDE_ASM("asm/levels", func_L07_003C1EB8);
