#include "common.h"

/* localdecomp:start func_L07_0035CA80 */
extern s32 D_001E0F90;

void func_L07_0035CA80(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_001E0F90)[i] == arg0) {
            (&D_001E0F90)[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L07_0035CA80 */

INCLUDE_ASM("asm/levels", func_L07_0035CAB8);

INCLUDE_ASM("asm/levels", func_L07_0035CC10);

INCLUDE_ASM("asm/levels", func_L07_0035D080);
