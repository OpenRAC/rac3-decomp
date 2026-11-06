#include "common.h"

/* localdecomp:start func_L01_003E6E60 */
extern u8 D_L01_001E2AC0[];

void func_L01_003E6E60(s32 index, f32 angle, f32 vertical, f32 horizontal) {
    u8 *entry = D_L01_001E2AC0 + index * 1120;
    u8 *object = *(u8 **)(entry + 80);
    if (*(s16 *)(object + 134) == 0) {
        u8 *parts = *(u8 **)(object + 112) + 32;
        *(f32 *)(parts + 44) = angle;
        *(f32 *)(parts + 52) = vertical * 0.0174532925f * 0.0002777777845f;
        *(f32 *)(parts + 56) = horizontal * 0.0174532925f * 0.0002777777845f;
    }
}
/* localdecomp:end func_L01_003E6E60 */
