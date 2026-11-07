#include "common.h"

/* localdecomp:start func_L03_0032EDE0 */
void func_L03_0032EE30(void *a, int b);
void func_L03_0032EDE0(void *a) {
    int i;
    for (i = 0; i < 3; i++) {
        func_L03_0032EE30(a, i);
    }
}
/* localdecomp:end func_L03_0032EDE0 */

INCLUDE_ASM("asm/levels", func_L03_0032EE30);

INCLUDE_ASM("asm/levels", func_L03_0032EF78);

INCLUDE_ASM("asm/levels", func_L03_0032F038);

INCLUDE_ASM("asm/levels", func_L03_0032F520);
