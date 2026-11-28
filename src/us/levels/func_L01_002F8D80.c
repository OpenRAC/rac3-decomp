#include "common.h"
/* localdecomp:start func_L01_002F8D80 */
#include "vu0.h"
s32 func_L01_002F8D80(u8 *m, u8 *target, s32 directed, f32 angle, f32 speed) {
    extern f32 func_0037E250(f32, f32);
    extern void func_00388830(void *, void *, f32);
    extern void func_00388758(void *, void *, void *);
    extern void func_003BF2F8(void *, void *, f32);
    extern void func_L01_00441FB8(void *, s32, s32);
    vu0_v4 delta, toward;
    u8 *data = *(u8 **)(m + 0x68);
    if (m[0x20] == 4) {
        return 0;
    }
    if (angle == 0.0f) {
        angle = func_0037E250(-0.5235988f, 0.5235988f);
    }
    if (speed == 0.0f) {
        speed = func_0037E250(0.0f, 0.5235988f);
    }
    if (directed) {
        data[0x6D] |= 8;
    }
    if ((u32)(m[0x20] - 2) < 2) {
        if (directed) {
            vec_sub_ab(&delta, target + 0x10, m + 0x10);
            func_00388830(data + 0x30, &delta, 0.333333343f);
        } else {
            func_00388830(data + 0x30, data + 0x40, 0.13333334f);
        }
    }
    *(f32 *)(data + 0x74) = angle;
    *(f32 *)(data + 0x70) = speed;
    *(s32 *)(data + 0x60) = 0;
    *(u8 **)(data + 0x68) = target;
    vec_sub_ba(&toward, target + 0x10, m + 0x10);
    func_00388758(&delta, data + 0x30, &toward);
    func_00388830(data + 0x20, &delta, 1.0f);
    func_003BF2F8(data + 0x20, data + 0x20, 0.209439531f);
    func_L01_00441FB8(m, 4, -1);
    return 1;
}
/* localdecomp:end func_L01_002F8D80 */
