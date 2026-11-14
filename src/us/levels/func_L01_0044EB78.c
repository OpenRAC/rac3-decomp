#include "common.h"

/* localdecomp:start func_L01_0044EB78 */
extern u8 D_001D5473;
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L01_0044EB78(void *a0, u8 *obj, s32 a2, s32 flag, f32 value) {
    if (D_001D5473 != 0) {
        *(f32 *)(obj + 0x70) = value;
    } else {
        *(f32 *)(obj + 0x70) = 1.0f;
    }
    if (flag != 0) {
        if (*(f32 *)(obj + 0x70) != *(f32 *)(obj + 0x20)) {
            func_L01_0044B5C8(a0, obj, a2, 0.0299999993f, 0.300000012f);
        }
    }
}
/* localdecomp:end func_L01_0044EB78 */
