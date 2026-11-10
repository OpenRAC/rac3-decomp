#include "common.h"

/* localdecomp:start func_L39_006AC438 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006AC438(void *);

extern void func_L39_0067F168();
void func_L39_006AC438(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006AC438 */

INCLUDE_ASM("asm/levels", func_L39_006AC468);
