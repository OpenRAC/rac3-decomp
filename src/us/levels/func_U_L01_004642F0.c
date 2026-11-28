#include "common.h"
/* localdecomp:start func_U_L01_004642F0 */
#include "vu0.h"
void func_U_L01_004642F0(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    f32 *p = (f32 *)(self + 0x20);
    if (p[3] > 0.0f) {
        p[1] += p[3] * 0.00700000022f;
    } else if (p[1] > 0.03f) {
        p[1] += p[3] * 0.00700000022f;
    } else {
        p[1] += p[3] * 0.00700000022f * 0.2f;
        *(f32 *)(self + 0xC) += 5460.0f;
    }
    if (p[1] <= 0.024399999529123306f || func_003883C8(self + 0xA)) {
        func_003C7CE0(self);
    } else {
        if (p[1] >= 0.12f) {
            p[3] = -p[3];
            p[1] += p[3] * 0.00700000022f;
        }
        *(f32 *)(self + 0xC) += 5460.0f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] += 0.00200000009f;
        if (p[2] > 1.0f) {
            p[2] -= 1.0f;
        }
        self[8] = (s32)(p[2] * 255.0f);
        vec_add_ba(self + 0x10, self + 0x10, p + 4);
    }
}
/* localdecomp:end func_U_L01_004642F0 */
