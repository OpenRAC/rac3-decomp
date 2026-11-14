#include "common.h"

/* localdecomp:start func_L07_003B2DF8 */
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L07_003B2FF8(f32, f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_00389018(void *, s32, f32);

void func_L07_003B2DF8(u8 *a0) {
    u8 *p;
    f32 x;
    s32 i;

    p = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(p + 0xD8) & 0x10) {
        *(f32 *)(p + 0x638) = func_003893C8(func_00388A28(*(f32 *)(p + 0x80) - *(f32 *)(a0 + 0x10), *(f32 *)(p + 0x84) - *(f32 *)(a0 + 0x14)), *(f32 *)(a0 + 0xF8));
        if (a0[0x20] == 7) {
            x = *(f32 *)(p + 0x658);
            if (x > 1.0f) {
                x = 2.0f - x;
            }
            *(f32 *)(p + 0x638) = func_00389380(*(f32 *)(p + 0x638), func_003BE6A8(-0.34906584f, 0.34906584f, x));
        }
        *(f32 *)(p + 0x638) = func_L07_003B2FF8(*(f32 *)(p + 0x638), -1.0471976f, 1.0471976f);
    } else {
        *(s32 *)(p + 0x638) = 0;
    }
    func_L01_0044B5C8(a0, p + 0x5D0, 0xC, 0.01f, 0.3f);
    for (i = 0; i < 2; i++) {
        func_L01_0044B5C8(a0, p + 0x3D0 + i * 0x80, 6 + i * 3, 0.03f, 0.3f);
        func_L01_0044B5C8(a0, p + 0x4D0 + i * 0x80, 7 + i * 3, 0.03f, 0.3f);
    }
    *(f32 *)(p + 0x654) = func_00389380(*(f32 *)(p + 0x654), 0.20943953f);
    func_00389018(p + 0x3A0, 1, *(f32 *)(p + 0x654));
}
/* localdecomp:end func_L07_003B2DF8 */
