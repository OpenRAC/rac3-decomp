#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_003DA8D8);

INCLUDE_ASM("asm/levels", func_L40_003DA9A0);

INCLUDE_ASM("asm/levels", func_L40_003DAE50);

/* localdecomp:start func_L40_003DB068 */
extern void *D_L40_00249640[];
extern void func_003CD250(void *);
extern void func_003C2880(void *);

void func_L40_003DB068(u8 *m) {
    void **p = (void **)(*(u8 **)(m + 0x68) + 0x30);
    s32 i;

    for (i = 3; i >= 0; i--, p++) {
        if (*p != 0) {
            func_003CD250(*p);
            *p = 0;
        }
    }
    if (D_L40_00249640[0] == m) {
        m[0x20] = 4;
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L40_003DB068 */
