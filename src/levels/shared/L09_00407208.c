#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_00407208);

/* localdecomp:start func_L09_00407618 */
extern void func_L09_00407208(void *);
void func_L09_00407618(u8 *p) {
    func_L09_00407208(p);
    *(s16 *)(p + 0x7E) = 0;
}
/* localdecomp:end func_L09_00407618 */
