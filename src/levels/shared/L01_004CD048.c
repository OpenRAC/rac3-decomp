#include "common.h"

/* localdecomp:start func_L01_004CD048 */
extern u8 *func_003AB020(u8 *);

extern u8 D_L01_001DB208[];
u8 *func_L01_004CD048(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_L01_001DB208;
    return p;
}
/* localdecomp:end func_L01_004CD048 */

LINKER_REMNANT("asm/levels", func_L01_004CD080);
