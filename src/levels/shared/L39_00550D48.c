#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00550D48);

INCLUDE_ASM("asm/levels", func_L39_005510B0);

INCLUDE_ASM("asm/levels", func_L39_005514A0);

/* localdecomp:start func_L39_005515E8 */
extern char func_L39_00551660[];
extern s32 func_L39_00551918(u8 *);
extern s32 func_L39_00552070(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00404A10(char *, u8 *);

void func_L39_005515E8(u8 *a0) {
    s32 a = func_L39_00551918(a0);
    s32 b = func_L39_00552070(a0);
    if (a == 0 && b == 0) {
        if (a0[32] == 2) {
            func_003C2880(a0);
        }
    } else {
        func_L01_00404A10(func_L39_00551660, a0);
    }
}
/* localdecomp:end func_L39_005515E8 */

INCLUDE_ASM("asm/levels", func_L39_00551660);

INCLUDE_ASM("asm/levels", func_L39_005516B0);

INCLUDE_ASM("asm/levels", func_L39_005517C8);

INCLUDE_ASM("asm/levels", func_L39_00551918);

INCLUDE_ASM("asm/levels", func_L39_00551A38);

INCLUDE_ASM("asm/levels", func_L39_00551F68);

INCLUDE_ASM("asm/levels", func_L39_00552070);

INCLUDE_ASM("asm/levels", func_L39_005521F8);

INCLUDE_ASM("asm/levels", func_L39_00552750);

INCLUDE_ASM("asm/levels", func_L39_00552920);

INCLUDE_ASM("asm/levels", func_L39_00553148);

INCLUDE_ASM("asm/levels", func_L39_005537B8);

INCLUDE_ASM("asm/levels", func_L39_00553C30);
