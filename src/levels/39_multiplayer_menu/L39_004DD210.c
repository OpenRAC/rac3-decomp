#include "common.h"

/* localdecomp:start func_L39_004DD210 */
extern void *(*D_L39_0046B638[])(void);
extern void func_L39_005042F8(void *);

void func_L39_004DD210(void) {
    func_L39_005042F8(D_L39_0046B638[0]());
}
/* localdecomp:end func_L39_004DD210 */

INCLUDE_ASM("asm/levels", func_L39_004DD240);

INCLUDE_ASM("asm/levels", func_L39_004DD250);

INCLUDE_ASM("asm/levels", func_L39_004DD2D8);

INCLUDE_ASM("asm/levels", func_L39_004DD340);
