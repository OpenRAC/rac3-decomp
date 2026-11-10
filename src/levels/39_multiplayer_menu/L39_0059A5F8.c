#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_0059A5F8);

/* localdecomp:start func_L39_0059A638 */
extern void *D_L39_00241444 __attribute__((section(".data")));
void func_L39_0059A660(void *, s32);

void func_L39_0059A638(s32 arg0) {
    func_L39_0059A660(D_L39_00241444, arg0);
}
/* localdecomp:end func_L39_0059A638 */

INCLUDE_ASM("asm/levels", func_L39_0059A660);
