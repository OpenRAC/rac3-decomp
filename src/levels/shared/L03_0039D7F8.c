#include "common.h"

/* localdecomp:start func_L03_0039D7F8 */
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 D_001D6694;

void func_L03_0039D7F8(u8 *a0) {
    f32 *pv = *(f32 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        pv[0] = 0.0f;
        pv[2] = *(f32 *)(a0 + 0xF4);
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 1:
        if (D_001D6694 == 6) {
            func_L01_004450F0(a0, 2, -1);
        }
        return;
    case 2:
        pv[0] += 0.012f;
        if (pv[0] >= 1.0f) {
            pv[0] = 1.0f;
            func_L01_004450F0(a0, 3, -1);
        } else if (D_001D6694 != 6) {
            func_L01_004450F0(a0, 4, -1);
        }
        *(f32 *)(a0 + 0xF4) = func_0038DAB8(pv[2], func_003C3BE8(0.0f, -1.5707964f, pv[0]));
        break;
    case 3:
        if (D_001D6694 != 6) {
            func_L01_004450F0(a0, 4, -1);
        }
        return;
    case 4:
        pv[0] -= 0.012f;
        if (pv[0] <= 0.0f) {
            pv[0] = 0.0f;
            func_L01_004450F0(a0, 1, -1);
        } else if (D_001D6694 == 6) {
            func_L01_004450F0(a0, 2, -1);
        }
        *(f32 *)(a0 + 0xF4) = func_0038DAB8(pv[2], func_003C3BE8(0.0f, -1.5707964f, pv[0]));
        break;
    }
}
/* localdecomp:end func_L03_0039D7F8 */
