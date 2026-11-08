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

INCLUDE_ASM("asm/levels", func_L39_00519058);

INCLUDE_ASM("asm/levels", func_L39_005190C8);

INCLUDE_ASM("asm/levels", func_L39_005190E8);

INCLUDE_ASM("asm/levels", func_L39_005192A8);

INCLUDE_ASM("asm/levels", func_L39_005192F8);

INCLUDE_ASM("asm/levels", func_L39_00519340);

INCLUDE_ASM("asm/levels", func_L39_00519388);

INCLUDE_ASM("asm/levels", func_L39_005193C0);

INCLUDE_ASM("asm/levels", func_L39_00519408);

/* localdecomp:start func_L39_00519438 */
extern s32 func_L39_00518A60(u32);

/* from rac4-decomp's func_L00_00566D30, renamed */
s32 func_L39_00519438(u32 arg0) {
    if (arg0 != 0) {
        return func_L39_00518A60(arg0 & 0xFFFF);
    }
    return -1;
}
/* localdecomp:end func_L39_00519438 */
