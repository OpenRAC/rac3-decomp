#include "common.h"

/* localdecomp:start func_L39_004C6098 */
s32 func_L39_004C6098(s32 arg0) {
    switch (arg0) {
    case 1: return 0xCB;
    case 2: return 0xCA;
    case 4: return 0xC9;
    case 6: return 0xCC;
    }
    return 0xFD;
}
/* localdecomp:end func_L39_004C6098 */

INCLUDE_ASM("asm/levels", func_L39_004C6100);

INCLUDE_ASM("asm/levels", func_L39_004C6120);

INCLUDE_ASM("asm/levels", func_L39_004C6250);
