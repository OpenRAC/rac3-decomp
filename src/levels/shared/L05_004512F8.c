#include "common.h"

/* localdecomp:start func_L05_004512F8 */
extern u8 *D_L05_001DFC80[];
extern void func_L05_00451228(u8 *a0, u8 *a1, s32 a2, s32 a3, u8 *t0, u8 *t1);
void func_L05_004512F8(u8 *a0, s32 a1, s32 a2, s32 a3) {
    if (a3 != -1) {
        u8 *t = D_L05_001DFC80[0] + (a3 << 7);
        func_L05_00451228(a0 + 16, a0 + 240, a1, a2, t + 48, t + 112);
    }
}
/* localdecomp:end func_L05_004512F8 */
