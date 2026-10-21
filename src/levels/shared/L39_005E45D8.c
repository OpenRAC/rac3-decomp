#include "common.h"

/* localdecomp:start func_L39_005E45D8 */
extern s32 func_L39_005D6458(s32);
extern s32 func_L01_004910C0(s32);
extern s32 func_L39_00610490(s32);
extern void func_L39_005D6468(s32, s32);
extern void func_003E82F8(s32);
extern void func_003E8440(s32);
s32 func_L39_005E45D8(s32 a0) {
    if (func_L39_005D6458(a0) != 0) {
        return 0;
    }
    if (func_L39_00610490(func_L01_004910C0(a0)) != 0) {
        return 0;
    }
    func_L39_005D6468(a0, 1);
    func_003E82F8(a0);
    func_003E8440(func_L01_004910C0(a0));
    return 1;
}
/* localdecomp:end func_L39_005E45D8 */

INCLUDE_ASM("asm/levels", func_L39_005E4648);

INCLUDE_ASM("asm/levels", func_L39_005E4A40);
