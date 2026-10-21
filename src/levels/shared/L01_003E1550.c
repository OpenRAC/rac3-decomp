#include "common.h"

/* localdecomp:start func_L01_003E1550 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_003E1550(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 40));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_003E1550 */

INCLUDE_ASM("asm/levels", func_L01_003E1590);

INCLUDE_ASM("asm/levels", func_L01_003E1990);
