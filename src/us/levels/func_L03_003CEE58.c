#include "common.h"

/* localdecomp:start func_L03_003CEE58 */
extern void func_L03_00445E50(u8 *, f32, f32, f32, f32);

void func_L03_003CEE58(u8 *object) {
    u8 *vars = *(u8 **)(object + 0x68);
    s32 flags = *(s32 *)(vars + 0x68);

    flags |= 0x90;
    *(f32 *)(vars + 0x34) = *(f32 *)(vars + 0x30) = 0.3f;
    *(f32 *)(vars + 0x64) = 0.2f;
    *(f32 *)(vars + 0x3C) = *(f32 *)(vars + 0x38) = 0.8f;
    *(f32 *)(vars + 0x40) = 1.48352981f;
    *(f32 *)(vars + 0x60) = 0.0872664626f;
    *(f32 *)(vars + 0x5C) = 0.00272222236f;
    *(s32 *)(vars + 0x68) = flags;
    func_L03_00445E50(object, 0.0444444455f, 0.166666672f, 0.0104719754f, 0.279252708f);
}
/* localdecomp:end func_L03_003CEE58 */
