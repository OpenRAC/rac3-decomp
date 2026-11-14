#include "common.h"

/* localdecomp:start func_L39_004BECC0 */
__asm__(".extern D_L39_00464818, 16");
extern s32 (*D_L39_00464818[])(void);

s32 func_L39_004BECC0(void) {
    s32 (*fn)(void) = D_L39_00464818[0];
    s32 ret;

    do {
        ret = 1;
        if (fn == 0) {
            break;
        }
        ret = fn();
    } while (0);
    return ret;
}
/* localdecomp:end func_L39_004BECC0 */

INCLUDE_ASM("asm/levels", func_L39_004BECF0);

LINKER_REMNANT("asm/levels", func_L39_004BEDA8);

INCLUDE_ASM("asm/levels", func_L39_004BEDB0);

INCLUDE_ASM("asm/levels", func_L39_004BEDE8);

INCLUDE_ASM("asm/levels", func_L39_004BEE70);

LINKER_REMNANT("asm/levels", func_L39_004BEEC8);

/* localdecomp:start func_L39_004BEED8 */
extern char *(*D_L39_004648A4)(void) __attribute__((section(".data")));

/* from rac2-decomp's func_00120420 */
char *func_L39_004BEED8(void) {
    return D_L39_004648A4();
}
/* localdecomp:end func_L39_004BEED8 */

/* localdecomp:start func_L39_004BEF00 */
extern char *(*D_L39_004648A8[4])(void);
/* from rac2-decomp's func_00120420 */
char *func_L39_004BEF00(void) {
    return D_L39_004648A8[0]();
}
/* localdecomp:end func_L39_004BEF00 */

INCLUDE_ASM("asm/levels", func_L39_004BEF28);

LINKER_REMNANT("asm/levels", func_L39_004BEF50);

INCLUDE_ASM("asm/levels", func_L39_004BEF58);

INCLUDE_ASM("asm/levels", func_L39_004BEFB8);

INCLUDE_ASM("asm/levels", func_L39_004BF110);
