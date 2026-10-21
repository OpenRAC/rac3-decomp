#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004CCDA0);

/* localdecomp:start func_L01_004CCDA8 */
extern void func_003AB168();
extern u8 D_L01_001DB1D8[];

void func_L01_004CCDA8(u8 *p) {
    *(void **)(p + 0x24) = D_L01_001DB1D8;
    func_003AB168(p);
}
/* localdecomp:end func_L01_004CCDA8 */
