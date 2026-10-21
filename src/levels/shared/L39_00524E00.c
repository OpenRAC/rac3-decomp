#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00524E00);

INCLUDE_ASM("asm/levels", func_L39_00525030);

INCLUDE_ASM("asm/levels", func_L39_00525690);

INCLUDE_ASM("asm/levels", func_L39_00526280);

INCLUDE_ASM("asm/levels", func_L39_00526340);

INCLUDE_ASM("asm/levels", func_L39_00526FC0);

INCLUDE_ASM("asm/levels", func_L39_00527460);

INCLUDE_ASM("asm/levels", func_L39_00527A38);

INCLUDE_ASM("asm/levels", func_L39_00527C88);

INCLUDE_ASM("asm/levels", func_L39_005285A8);

INCLUDE_ASM("asm/levels", func_L39_005287B0);

INCLUDE_ASM("asm/levels", func_L39_00528A88);

/* localdecomp:start func_L39_00528AB8 */
extern s32 D_L39_0024D4A0[];

s32 func_L39_00528AB8(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D4A0[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00528AB8 */

/* localdecomp:start func_L39_00528AF0 */
extern s32 D_L39_0024D4E0[];
extern s32 D_L39_0024D4A0[];
extern s32 D_L39_001E1DD0;
void func_L39_00528AF0(s32 a0) {
    s32 n = D_L39_0024D4E0[0];
    s32 i = 0;
    s32 *p = D_L39_0024D4A0;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_001E1DD0 = n;
}
/* localdecomp:end func_L39_00528AF0 */

INCLUDE_ASM("asm/levels", func_L39_00528B38);

INCLUDE_ASM("asm/levels", func_L39_00528BF0);

INCLUDE_ASM("asm/levels", func_L39_00528D28);

INCLUDE_ASM("asm/levels", func_L39_00528EE8);

INCLUDE_ASM("asm/levels", func_L39_00529130);
