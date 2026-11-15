#include "common.h"

/* localdecomp:start func_L39_00519018 */
/* follows func_L39_00518FE0 (from rac4-decomp's func_L00_005668D8) */
extern s32 D_L39_00453DD4[];
extern void func_0011C810(void);

void func_L39_00519018(void) {
    void (*handler)(void) = (void (*)(void))D_L39_00453DD4[0];
    if (handler != 0) {
        handler();
        return;
    }
    func_0011C810();
}
/* localdecomp:end func_L39_00519018 */

LINKER_REMNANT("asm/levels", func_L39_00519050);
