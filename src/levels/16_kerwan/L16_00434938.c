#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_00434938);

/* localdecomp:start func_L16_00434A00 */
void func_L01_0040C948(s32, void *);
extern s32 D_L16_001D6C48;
extern u8 D_L16_001EF3D0[];

void func_L16_00434A00(void) {
    void *var_s0;

    var_s0 = D_L16_001EF3D0;
    do {
        func_L01_0040C948((s32) var_s0, &D_L16_001D6C48);
        var_s0 += 0xB0;
    } while ((s32) var_s0 < (s32) (D_L16_001EF3D0 + 0x6E0));
}
/* localdecomp:end func_L16_00434A00 */

INCLUDE_ASM("asm/levels", func_L16_00434A50);

INCLUDE_ASM("asm/levels", func_L16_00434A78);
