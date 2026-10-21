#include "common.h"

/* localdecomp:start func_L01_004CD2C8 */
extern u8 *func_003AB020(u8 *);

extern u8 D_L01_001DB1F0[];
u8 *func_L01_004CD2C8(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_L01_001DB1F0;
    return p;
}
/* localdecomp:end func_L01_004CD2C8 */

LINKER_REMNANT("asm/levels", func_L01_004CD300);
