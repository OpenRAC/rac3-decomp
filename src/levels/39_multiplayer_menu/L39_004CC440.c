#include "common.h"

/* localdecomp:start func_L39_004CC440 */
typedef struct { s32 n; void *p; } S_004CC440;
extern void *func_0011D534(void *, s32, u32);

void func_L39_004CC440(S_004CC440 *arg0) {
    if (arg0 != 0 && arg0->n > 0) {
        func_0011D534(arg0->p, 0, arg0->n * 4);
        arg0->n = 0;
    }
}
/* localdecomp:end func_L39_004CC440 */

INCLUDE_ASM("asm/levels", func_L39_004CC480);

INCLUDE_ASM("asm/levels", func_L39_004CC510);

INCLUDE_ASM("asm/levels", func_L39_004CC538);

INCLUDE_ASM("asm/levels", func_L39_004CC5B8);

INCLUDE_ASM("asm/levels", func_L39_004CC718);

INCLUDE_ASM("asm/levels", func_L39_004CC7A8);

INCLUDE_ASM("asm/levels", func_L39_004CC800);

INCLUDE_ASM("asm/levels", func_L39_004CC810);

INCLUDE_ASM("asm/levels", func_L39_004CCBD8);

INCLUDE_ASM("asm/levels", func_L39_004CCD18);
