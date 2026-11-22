/* NTSC-U counterpart of func_L07_003BDFB8: 60 Hz motion constants. */
#include "common.h"
/* localdecomp:start func_L07_003BC670 */
#include "vu0.h"
void func_L07_003BC670(u8 *self, f32 *target) {
    extern f32 func_00388730(void *, void *);
    extern f32 func_00389410(f32);
    extern void func_00389018(float *, s32, float);
    extern void func_00388F50(void *, void *, void *);
    extern f32 func_L01_0040C040(void *, void *);
    extern f32 func_00388A28(f32, f32);
    extern f32 func_00389468(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern void func_L01_00445758(f32 *, f32 *, s32, f32, f32, f32, f32);
    extern f32 func_003893C8(f32, f32);
    extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
    f32 delta[4] __attribute__((aligned(16)));
    f32 rotation[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(self + 0x68);
    f32 angle;
    u8 *position = self + 0x10;
    vec_sub_ba(delta, self + 0x10, target);
    angle = func_00389410(func_00388730(delta, self + 0xC0) / 0.3f);
    func_00389018(rotation, 1, angle);
    func_00388F50(vars + 0x2D0, vars + 0x2D0, rotation);
    if (*(u32 *)(vars + 0x188) & 0x10) {
        if (self[0x42] == 7) {
            if (func_L01_0040C040(target, position) > 0.0001f) {
                angle = func_00388A28(*(f32 *)(self + 0x10) - target[0], *(f32 *)(self + 0x14) - target[1]);
                if (func_00389468(*(f32 *)(self + 0xF8), angle) > 1.5707963705062866f) angle = func_00389380(angle, 3.1415927410125732f);
                func_L01_00445758((f32 *)(self + 0xF8), (f32 *)(vars + 0x204), 0, angle, *(f32 *)(vars + 0x164), *(f32 *)(vars + 0x168), *(f32 *)(vars + 0x16C));
            }
        } else {
            if (func_L01_0040C040(target, position) > 0.0001f) {
                angle = func_00388A28(*(f32 *)(self + 0x10) - target[0], *(f32 *)(self + 0x14) - target[1]);
                if (func_00389468(func_00388A28(*(f32 *)(vars + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(vars + 0x134) - *(f32 *)(self + 0x14)), angle) > 1.5707963705062866f) angle = func_00389380(angle, 3.1415927410125732f);
                func_L01_00445758((f32 *)(self + 0xF8), (f32 *)(vars + 0x204), 0, angle, *(f32 *)(vars + 0x164), *(f32 *)(vars + 0x168), *(f32 *)(vars + 0x16C));
            }
            *(f32 *)(vars + 0x2A8) = func_003893C8(func_00388A28(*(f32 *)(vars + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(vars + 0x134) - *(f32 *)(self + 0x14)), *(f32 *)(self + 0xF8));
            if (*(f32 *)(vars + 0x2A8) > 1.5707963705062866f) *(f32 *)(vars + 0x2A8) = 1.5707963705062866f;
            else if (*(f32 *)(vars + 0x2A8) < -1.5707963705062866f) *(f32 *)(vars + 0x2A8) = -1.5707963705062866f;
        }
    } else *(s32 *)(vars + 0x2A8) = 0;
    func_L01_0044B5C8(self, vars + 0x240, 2, 0.01f, 0.3f);
}
/* localdecomp:end func_L07_003BC670 */
