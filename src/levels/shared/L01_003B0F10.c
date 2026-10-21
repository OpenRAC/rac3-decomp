#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_003B0F10);

/* localdecomp:start func_L01_003B0F18 */
extern void func_L01_003B1040(void *);
extern void func_L01_003B0F18(void *);

extern void func_L01_003B0F48();
void func_L01_003B0F18(void *p) {
    func_L01_003B0F48(p);
    func_L01_003B1040(p);
}
/* localdecomp:end func_L01_003B0F18 */
