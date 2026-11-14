#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_003EE7A0 */
extern f32 D_001DB6EC_sda, D_001DB628_sda;
__asm__(".extern D_001DB6EC_sda, 4");
__asm__(".extern D_001DB628_sda, 4");
extern f32 func_00388800(void *, void *);
extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L40_00480398(void *, void *, s32, f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

void func_L40_003EE7A0(u8 *m, vu0_v4 *pos) {
    vu0_v4 delta;
    u8 *d = *(u8 **)(m + 0x68);
    f32 distance, length, amount, angle;
    if (*(s32 *)(d + 0x264) == 0x539) {
        *(vu0_v4 *)(m + 0x10) = *pos;
        return;
    }
    distance = func_00388800(m + 0x10, d + 0x340);
    vec_sub_ab(&delta, d + 0x2E0, m + 0x10);
    length = func_00388770(&delta);
    if (length < D_001DB6EC_sda * 0.01666666753590107f) return;
    func_003886E8(&delta, &delta, 0.04f);
    vec_sub_ab(&delta, &delta, d + 0x110);
    if (distance > D_001DB628_sda) func_003886E8(&delta, &delta, 0.13f);
    else func_003886E8(&delta, &delta, 0.25f);
    delta.z *= 0.9f;
    vec_add_ab(d + 0x110, d + 0x110, &delta);
    if (func_L40_00480398(m, d + 0x110, 0, 0.7f, 0.4f, 0.0f)) {
        if (length > 10.0f) {
            if (++*(s32 *)(d + 0x290) > 20) {
                *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(d + 0x2E0);
                *(s32 *)(d + 0x290) = 0;
            }
        }
    } else *(s32 *)(d + 0x290) = 0;
    if (distance < 1.1f) {
        amount = 1.1f - distance;
        angle = func_00388A28(*(f32 *)(d + 0x340) - *(f32 *)(m + 0x10), *(f32 *)(d + 0x344) - *(f32 *)(m + 0x14));
        *(f32 *)(d + 0x110) -= amount * func_00388960(angle) * 0.1f;
        *(f32 *)(d + 0x114) -= amount * func_00388978(angle) * 0.1f;
    }
}
/* localdecomp:end func_L40_003EE7A0 */
