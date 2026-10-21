#include "common.h"

/* localdecomp:start func_L01_0042CD88 */
extern void func_003A2750(s32);
extern void func_0039A9B0(s32, s32);

void func_L01_0042CD88(s32 a0, s32 a1) {
    func_003A2750(1);
    func_0039A9B0(a0, a1);
    func_003A2750(1);
}
/* localdecomp:end func_L01_0042CD88 */

LINKER_REMNANT("asm/levels", func_L01_0042CDD0);
