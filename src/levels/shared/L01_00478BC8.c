#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00478BC8);

INCLUDE_ASM("asm/levels", func_L01_00478BD0);

/* localdecomp:start func_L01_00479200 */
extern u8 D_L01_001D8058;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00479578(s32);
extern s32 func_L01_00516010(s32);
s32 func_L01_00479200(void) {
    if (D_L01_001D8058 != 0) {
        func_L01_00516AA0(0x10000, 1, 0);
        return func_L01_00516010(func_L01_00479578(0));
    }
    return 0;
}
/* localdecomp:end func_L01_00479200 */

/* localdecomp:start func_L01_00479248 */
extern u8 D_L01_001D8058;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00479248(void) {
    if (D_L01_001D8058 != 0) {
        func_L01_00516AA0(0x10000, 1, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00479248 */

/* localdecomp:start func_L01_00479280 */
extern s32 func_L01_00479578_00479280(s32);
extern void func_L01_00516050(s32);
void func_L01_00479280(void) {
    func_L01_00516050(func_L01_00479578_00479280(0));
}
/* localdecomp:end func_L01_00479280 */
