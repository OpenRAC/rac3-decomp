#include "common.h"

/* NTSC-U counterpart of func_L06_00350FD0 (src/levels/shared/L06_00350D60.c): 0.0100531 -> 0.00698132; 0.125664 -> 0.10472; 0.0432 -> 0.03; 0.432 -> 0.3 */
#include "vu0.h"
extern void func_L06_0034FEC0(void *arg0, u8 *arg1);

/* localdecomp:start func_L06_003502D8 */
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_L06_0034FEC0(void *arg0, u8 *arg1);
extern void func_00388830(void *, void *, f32);
extern f32 func_003887A0(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L06_00350130(u8 *, u8 *, void *, s32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern s32 D_L06_001DD318;
__asm__(".extern D_L06_001DD318, 4");
extern s32 D_L06_001DD31C[];

s32 func_L06_003502D8(u8 *a0, u8 *a1, u8 *tgt) {
    vu0_v4 d;
    vu0_v4 dir;
    vu0_v4 p;
    vu0_v4 t;
    f32 yaw;
    f32 dist;
    f32 s;
    s32 n;
    f32 f;

    vec_sub_ab(&d, tgt, a0 + 0x10);
    yaw = func_003893C8(func_00388A28(d.x, d.y), *(f32 *)(a0 + 0xF8));
    func_L01_00445758(a1 + 0x370, yaw, a1 + 0x374, 0.00698131742f,
                      0.00698131742f, 0.104719765f, 0);
    func_L06_0034FEC0(a0, a1);
    if ((u32)((*(u8 **)(a1 + 0x260))[0x43] - 10) < 2) {
        dir = d;
        dir.z = 0.0f;
        func_00388830(&dir, &dir, 1.0f);
        dist = func_003887A0(&d);
        if (dist < 5.5f) {
            s = 0.5f - dist;
        } else {
            s = -5.0f;
        }
        n = *(s32 *)(a1 + 0x35C);
        if (n > 0) {
            f = (f32)n / (f32)*(s32 *)(a1 + 0x38C);
            f = s + (1.0f - f) * 10.0f;
        } else {
            f = s;
        }
        func_003886E8(&t, &dir, f);
        vec_add_ab(&p, &t, tgt);
        func_L06_00350130(a0, a1, &p, 0);
        func_L06_00350130(a0, a1, &p, 1);
    } else {
        qzero(a1 + 0x400);
        func_L01_0044B5C8(*(void **)(a1 + 0x260), a1 + 0x3A0, D_L06_001DD318, 0.0299999993f, 0.300000012f);
        qzero(a1 + 0x480);
        func_L01_0044B5C8(*(void **)(a1 + 0x260), a1 + 0x420, D_L06_001DD31C[0], 0.0299999993f, 0.300000012f);
    }
    return fabs_asm(func_003893C8(*(f32 *)(a1 + 0x370), yaw)) < 0.08726646f;
}
/* localdecomp:end func_L06_003502D8 */
