#include "common.h"

/* localdecomp:start func_L09_003EA810 */
extern s32 D_L09_001F2EC0[];
extern void func_L01_004450F0(void *, s32, s32);

void func_L09_003EA810(u8 *a0) {
    u8 *v;
    if (a0[0x20] != 0) return;
    v = *(u8 **)(a0 + 0x68);
    a0[0x30] = 0xFF;
    *(f32 *)(v + 0x7C) = *(f32 *)(a0 + 0x18);
    if (*(s16 *)(v + 0x76) == 0) {
        s32 m = D_L09_001F2EC0[0];
        if (m == 0 || m == 2) {
            func_L01_004450F0(a0, 1, -1);
        } else {
            *(f32 *)(a0 + 0x18) += 10.0f;
            func_L01_004450F0(a0, 3, -1);
        }
    } else {
        if (D_L09_001F2EC0[0] == 1) {
            func_L01_004450F0(a0, 7, -1);
        } else {
            *(f32 *)(a0 + 0x18) -= 10.0f;
            func_L01_004450F0(a0, 5, -1);
        }
    }
}
/* localdecomp:end func_L09_003EA810 */
