#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0069D2D8);

LINKER_REMNANT("asm/levels", func_L39_0069DA30);

INCLUDE_ASM("asm/levels", func_L39_0069DA38);

INCLUDE_ASM("asm/levels", func_L39_0069DA60);

/* localdecomp:start func_L39_0069DE00 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069DE00(void *);

extern void func_L39_0067F168();
void func_L39_0069DE00(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069DE00 */

INCLUDE_ASM("asm/levels", func_L39_0069DE30);
