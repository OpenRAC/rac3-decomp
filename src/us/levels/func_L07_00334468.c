#include "common.h"

/* localdecomp:start func_L07_00334468 */
extern s32 func_0037E208(s32, s32);
extern void func_L07_003A0BC0(s32, s32, s32, s32);

/* Calls func_L07_003A0BC0 with a random 0x47..0x49 value, the given value, 0 and 0x78. */
void func_L07_00334468(s32 value) {
    func_L07_003A0BC0(func_0037E208(0x47, 0x49) & 0xFF, value, 0, 0x78);
}
/* localdecomp:end func_L07_00334468 */
