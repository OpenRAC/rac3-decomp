#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_00350528 */
extern void func_L06_003505D8(s32, u8 *);
extern f32 func_L06_00428E58(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_L06_003F1AE0(f32, f32);
s32 func_L06_00350528(s32 a0, u8 *a1) {
    func_L06_003505D8(a0, a1);
    if (*(f32 *)(a1 + 0x370) == 0.0f) {
        return 1;
    }
    func_L06_00428E58(a1 + 0x370, 0.0f, a1 + 0x374, 0.00698131742f, 0.00698131742f, 0.104719765f, 0);
    if (fabs_asm(func_L06_003F1AE0(*(f32 *)(a1 + 0x370), 0.0f)) < 0.08726646f) {
        *(f32 *)(a1 + 0x370) = 0.0f;
        *(f32 *)(a1 + 0x374) = 0.0f;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00350528 */
