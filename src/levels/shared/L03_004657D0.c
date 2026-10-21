#include "common.h"

/* localdecomp:start func_L03_004657D0 */
extern s32 D_L03_0021D8C0[];
extern void func_L01_00477998(s32);
s32 func_L03_004657D0(s32 i) {
    if (i != -1 && D_L03_0021D8C0[i] != 0) {
        func_L01_00477998(D_L03_0021D8C0[i]);
        return 0;
    }
    return -1;
}
/* localdecomp:end func_L03_004657D0 */
