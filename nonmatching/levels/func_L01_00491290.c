#include "common.h"
/* localdecomp:start func_L01_00491290 */
extern u8 D_00143950[];
extern void func_003A5348(s32, s32, s32);
extern s32 func_0013BFE0(s32);
void func_L01_00491290(s32 a0) {
    if (a0 & 0xA040) {
        s32 *p;
        func_003A5348(4, 0, 0);
        p = (s32 *)D_00143950;
        p[2] = p[2] == 0;
        func_0013BFE0(p[2] ^ 1);
    }
}
/* localdecomp:end func_L01_00491290 */
