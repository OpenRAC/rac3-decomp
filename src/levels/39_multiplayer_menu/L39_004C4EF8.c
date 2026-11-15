#include "common.h"

/* localdecomp:start func_L39_004C4EF8 */
extern s32 D_L39_00465100[];

s32 func_L39_004C4EF8(void) {
    D_L39_00465100[0] = 0;
    return 1;
}
/* localdecomp:end func_L39_004C4EF8 */

/* localdecomp:start func_L39_004C4F08 */
s32 func_L39_004C4F08(s64 arg0) {
    D_L39_00465100[0] |= arg0;
    return 1;
}
/* localdecomp:end func_L39_004C4F08 */

LINKER_REMNANT("asm/levels", func_L39_004C4F28);

/* localdecomp:start func_L39_004C4F30 */
extern s32 D_L39_00465100[];

s32 func_L39_004C4F30(s64 arg0) {
    return D_L39_00465100[0] & arg0;
}
/* localdecomp:end func_L39_004C4F30 */
