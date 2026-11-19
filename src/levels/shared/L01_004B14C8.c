#include "common.h"

/* localdecomp:start func_L01_004B14C8 */
extern f32 D_L01_001E7630_004B14C8[];
extern f32 D_L01_001E0E9C;
__asm__(".extern D_L01_001E0E9C, 16");
extern f32 D_L01_001E0EA0[];
extern void func_003CEDF8(s32);

void func_L01_004B14C8(s32 a0) {
    f32 v = 0.62f / D_L01_001E7630_004B14C8[0];
    f32 b;

    if (v < 1.0f) {
        v = 1.0f;
    }
    if (4.0f < v) {
        v = 4.0f;
    }
    if (a0 != 0) {
        v = 1.0f;
    }
    b = D_L01_001E0E9C;
    D_L01_001E0EA0[1] = b * 4.0f * v;
    D_L01_001E0EA0[0] = b * 6.0f * v;
    D_L01_001E0EA0[2] = (b + b) * v;
    func_003CEDF8(a0);
}
/* localdecomp:end func_L01_004B14C8 */
