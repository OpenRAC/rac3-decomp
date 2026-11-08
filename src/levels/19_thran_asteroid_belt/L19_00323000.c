#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_00323000);

/* localdecomp:start func_L19_00323398 */
extern int func_L01_0040C948(void *, void *);
extern char D_L19_001D64E0[] __attribute__((section(".sdata")));
int func_L19_00323398(char *a)
{
    return func_L01_0040C948(*(char **)(a + 0x68) + 0x70, D_L19_001D64E0);
}
/* localdecomp:end func_L19_00323398 */
