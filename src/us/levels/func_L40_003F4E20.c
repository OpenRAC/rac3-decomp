#include "common.h"

/* NTSC-U counterpart of func_L40_003F52E0 (src/levels/shared/L40_003F52E0.c) */
/* localdecomp:start func_L40_003F4E20 */
#include "vu0.h"
extern f32 func_00388770(void *v);
extern void func_00388830(void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern s32 func_L40_003F4D88(f32 *v);
extern vu0_v4 D_L40_0025BB30;

void func_L40_003F4E20(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 tmp;
    f32 len;
    f32 z;

    len = func_00388770(v + 0x2B0) - 0.00166666671f;
    if (len > 0.1333333403f) {
        len = 0.1333333403f;
    } else if (len < 0.0f) {
        len = 0.0f;
    }
    func_00388830(v + 0x2B0, v + 0x2B0, len);
    vec_add_ba(m + 0x10, m + 0x10, v + 0x2B0);
    *(f32 *)(v + 0x234) = func_00389380(*(f32 *)(v + 0x234), *(f32 *)(v + 0x23C));
    z = *(f32 *)(v + 0x1F8) + *(f32 *)(v + 0x238) * func_00388978(*(f32 *)(v + 0x234));
    if (*(s16 *)(v + 0x246) != 0) {
        z += *(f32 *)(v + 0x230);
    }
    z -= *(f32 *)(m + 0x18);
    if (z > 0.05000000447f) {
        z = 0.05000000447f;
    } else if (z < -0.05000000447f) {
        z = -0.05000000447f;
    }
    *(f32 *)(v + 0x2B8) = z;
    tmp = *(vu0_v4 *)(m + 0x10);
    tmp.z += 0.8f;
    if (func_L01_003F9498(&tmp, 0, m, 0.8f) != 0) {
        vec_sub_ba(&tmp, &D_L40_0025BB30, m + 0x10);
        if (func_L40_003F4D88(&tmp.x) != 0) {
            if (tmp.z > 0.05000000447f) {
                tmp.z = 0.05000000447f;
            } else if (tmp.z < -0.05000000447f) {
                tmp.z = -0.05000000447f;
            }
            vec_add_ab(m + 0x10, m + 0x10, &tmp);
        }
    }
}
/* localdecomp:end func_L40_003F4E20 */
