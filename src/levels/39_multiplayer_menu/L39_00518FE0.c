#include "common.h"

/* localdecomp:start func_L39_00518FE0 */
extern s32 D_L39_00453DD0[];
extern void func_0011C7B8(void);

/* from rac4-decomp's func_L00_005668D8, renamed */
void func_L39_00518FE0(void) {
    void (*handler)(void) = (void (*)(void))D_L39_00453DD0[0];
    if (handler != 0) {
        handler();
        return;
    }
    func_0011C7B8();
}
/* localdecomp:end func_L39_00518FE0 */

INCLUDE_ASM("asm/levels", func_L39_00519018);

LINKER_REMNANT("asm/levels", func_L39_00519050);
