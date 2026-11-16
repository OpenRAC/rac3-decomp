#include "common.h"

/* NTSC-U counterpart of func_L03_0039D7F8 (src/levels/shared/L03_0039D7F8.c) */
/* localdecomp:start func_L03_0039C098 */
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 D_L03_001D6694_0039C098;

void func_L03_0039C098(u8 *a0) {
    f32 *pv = *(f32 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        pv[0] = 0.0f;
        pv[2] = *(f32 *)(a0 + 0xF4);
        func_L01_00441FB8(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 1:
        if (D_L03_001D6694_0039C098 == 6) {
            func_L01_00441FB8(a0, 2, -1);
        }
        return;
    case 2:
        pv[0] += 0.01f;
        if (pv[0] >= 1.0f) {
            pv[0] = 1.0f;
            func_L01_00441FB8(a0, 3, -1);
        } else if (D_L03_001D6694_0039C098 != 6) {
            func_L01_00441FB8(a0, 4, -1);
        }
        *(f32 *)(a0 + 0xF4) = func_00389380(pv[2], func_003BE6A8(0.0f, -1.5707964f, pv[0]));
        break;
    case 3:
        if (D_L03_001D6694_0039C098 != 6) {
            func_L01_00441FB8(a0, 4, -1);
        }
        return;
    case 4:
        pv[0] -= 0.01f;
        if (pv[0] <= 0.0f) {
            pv[0] = 0.0f;
            func_L01_00441FB8(a0, 1, -1);
        } else if (D_L03_001D6694_0039C098 == 6) {
            func_L01_00441FB8(a0, 2, -1);
        }
        *(f32 *)(a0 + 0xF4) = func_00389380(pv[2], func_003BE6A8(0.0f, -1.5707964f, pv[0]));
        break;
    }
}
/* localdecomp:end func_L03_0039C098 */
