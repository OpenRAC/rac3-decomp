#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DB1C0);

INCLUDE_ASM("asm/levels", func_L05_003DB2D0);

/* localdecomp:start func_L05_003DB580 */
s32 func_L01_00447490(s32, s32, s32);
void func_L05_003DB2D0(s32);

void func_L05_003DB580(s32 arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L05_003DB2D0(arg0);
    }
}
/* localdecomp:end func_L05_003DB580 */

INCLUDE_ASM("asm/levels", func_L05_003DB5C0);
