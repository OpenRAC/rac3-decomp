#include "common.h"

INCLUDE_ASM("asm/levels", func_L33_003AEF48);

INCLUDE_ASM("asm/levels", func_L33_003AF098);

INCLUDE_ASM("asm/levels", func_L33_003AF2B8);

INCLUDE_ASM("asm/levels", func_L33_003AF340);

INCLUDE_ASM("asm/levels", func_L33_003AF430);

/* localdecomp:start func_L33_003AF628 */
__asm__(".extern D_L33_001E2190, 16");
extern void func_L33_003AF098(void *);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_0040C948(void *, void *);
extern char D_L33_001E2190;

void func_L33_003AF628(char *obj) {
    char *q = *(char **)(obj + 0x68);
    func_L33_003AF098(obj);
    q += 0x30;
    func_L01_0040C8A0(q, &D_L33_001E2190);
    func_L01_0040C948(q, &D_L33_001E2190);
}
/* localdecomp:end func_L33_003AF628 */
