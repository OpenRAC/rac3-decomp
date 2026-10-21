#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005F2FF8);

INCLUDE_ASM("asm/levels", func_L39_005F3088);

/* localdecomp:start func_L39_005F30E0 */
typedef struct {
    u8 pad0[80];
    u8 b;
    u8 pad51[47];
} E_5F09E0;
typedef struct {
    u8 pad0[128];
    E_5F09E0 e[52];
} T_5F09E0;
extern T_5F09E0 D_L39_001FE020;
s32 func_L39_005F30E0(s32 a0) {
    s32 n = a0 == 0 ? 42 : 52;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_L39_001FE020.e[i].b == 0) {
            break;
        }
    }
    return i == n ? -1 : i;
}
/* localdecomp:end func_L39_005F30E0 */

INCLUDE_ASM("asm/levels", func_L39_005F3138);

INCLUDE_ASM("asm/levels", func_L39_005F33E0);

INCLUDE_ASM("asm/levels", func_L39_005F3488);

INCLUDE_ASM("asm/levels", func_L39_005F3548);

INCLUDE_ASM("asm/levels", func_L39_005F35D8);

INCLUDE_ASM("asm/levels", func_L39_005F3668);

INCLUDE_ASM("asm/levels", func_L39_005F3718);
