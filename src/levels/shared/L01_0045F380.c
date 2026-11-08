#include "common.h"

/* localdecomp:start func_L01_0045F380 */
extern s16 D_001CCFD0[];

/* from rac4-decomp's func_00489498, renamed */
void func_L01_0045F380(s32 value)
{
    if (D_001CCFD0[0x28] & 0x8000) {
        D_001CCFD0[0x29] = value;
    }
    if (D_001CCFD0[0x64] & 0x8000) {
        D_001CCFD0[0x65] = value;
    }
    if (D_001CCFD0[0x3C] & 0x8000) {
        D_001CCFD0[0x3D] = value;
    }
}
/* localdecomp:end func_L01_0045F380 */
