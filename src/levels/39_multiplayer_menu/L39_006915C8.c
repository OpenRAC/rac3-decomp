#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006915C8);

INCLUDE_ASM("asm/levels", func_L39_006918A8);

INCLUDE_ASM("asm/levels", func_L39_00691900);

LINKER_REMNANT("asm/levels", func_L39_00691E48);

INCLUDE_ASM("asm/levels", func_L39_00691E60);

LINKER_REMNANT("asm/levels", func_L39_006921B0);

INCLUDE_ASM("asm/levels", func_L39_006921B8);

INCLUDE_ASM("asm/levels", func_L39_006921E0);

/* localdecomp:start func_L39_006923F0 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006923F0(void *);

extern void func_L39_0067F168();
void func_L39_006923F0(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006923F0 */

INCLUDE_ASM("asm/levels", func_L39_00692420);
