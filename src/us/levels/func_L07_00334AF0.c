#include "common.h"

/* localdecomp:start func_L07_00334AF0 */
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L07_003A0BC0(s32, s32, s32, s32);

void func_L07_00334AF0(s32 value) {
    s32 result = func_0037E1D8(4);
    switch (result) {
    case 0:
        func_L07_003A0BC0(0x4F, value, 0, 0x78);
        break;
    case 1:
        func_L07_003A0BC0(0x50, value, 0, 0x78);
        break;
    default:
        func_L07_003A0BC0(func_0037E208(0x67, 0x69) & 0xFF, value, 0, 0x78);
        break;
    }
}
/* localdecomp:end func_L07_00334AF0 */
