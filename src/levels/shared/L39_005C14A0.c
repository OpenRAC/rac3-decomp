#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005C14A0);

INCLUDE_ASM("asm/levels", func_L39_005C1700);

INCLUDE_ASM("asm/levels", func_L39_005C18C8);

INCLUDE_ASM("asm/levels", func_L39_005C1968);

/* localdecomp:start func_L39_005C1A60 */
extern s32 D_L39_001D7D68;
extern s32 D_L39_001D7D6C;
extern s16 D_L39_002256AE[];
extern s32 func_L39_005B43C8(s32 a0, s32 a1);
extern void func_L01_0045F1E8(s32 a0, s32 a1);
extern void func_L39_005C1AC0(s32 a0, s32 a1, s32 a2);

void func_L39_005C1A60(s32 a0, s32 a1) {
    s32 x;
    D_L39_001D7D68 = a0;
    D_L39_001D7D6C = a1 - a0 + 1;
    x = func_L39_005B43C8(a0, a1) * 2;
    if (D_L39_002256AE[0] == 4) {
        func_L01_0045F1E8(x, -1);
    } else {
        func_L39_005C1AC0(x, 1, 1024);
    }
}
/* localdecomp:end func_L39_005C1A60 */

INCLUDE_ASM("asm/levels", func_L39_005C1AC0);

INCLUDE_ASM("asm/levels", func_L39_005C1BB8);

INCLUDE_ASM("asm/levels", func_L39_005C1CB8);
