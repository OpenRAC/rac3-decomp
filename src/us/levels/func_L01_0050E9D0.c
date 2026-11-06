#include "common.h"

/* localdecomp:start func_L01_0050E9D0 */
extern u8 D_001A4BE0[];
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);

void func_L01_0050E9D0(char *object) {
    u8 *state = D_001A4BE0;
    f32 value;
    f32 factor;
    s32 color;
    u8 *linked;

    value = func_00389380(*(f32 *)(state + 0x2810), 0.061086528f);
    *(f32 *)(state + 0x2810) = value;
    factor = func_00388978(value) * 0.5f + 0.5f;
    color = func_003894A0(0x808C8C8C, 0x80464646, factor);
    *(s32 *)(object + 0x78) = color;
    linked = *(u8 **)(state + 0x12A0);
    if (linked != 0) {
        *(s32 *)(linked + 0x78) = color;
    }
}
/* localdecomp:end func_L01_0050E9D0 */
