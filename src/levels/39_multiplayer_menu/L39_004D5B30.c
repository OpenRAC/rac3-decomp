#include "common.h"

/* localdecomp:start func_L39_004D5B30 */
extern s32 D_L39_004646A0[];

s32 func_L39_004D5B30(void) {
    return D_L39_004646A0[0] > 0;
}
/* localdecomp:end func_L39_004D5B30 */

/* localdecomp:start func_L39_004D5B40 */
extern s32 D_L39_004646A4[];

s32 func_L39_004D5B40(void) {
    return D_L39_004646A4[0] > 0;
}
/* localdecomp:end func_L39_004D5B40 */

INCLUDE_ASM("asm/levels", func_L39_004D5B50);

INCLUDE_ASM("asm/levels", func_L39_004D5BE8);

INCLUDE_ASM("asm/levels", func_L39_004D6488);

INCLUDE_ASM("asm/levels", func_L39_004D6E78);

INCLUDE_ASM("asm/levels", func_L39_004D73E0);
