/* functional: high. near-miss (VU/prologue scheduling only) */
/* localdecomp:start func_L07_003BDFB8 */
#include "vu0.h"
void func_L07_003BDFB8(u8 *self, f32 *target) {
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038DB48(f32);
    extern void func_0038D750(float *, s32, float);
    extern void func_0038D688(void *, void *, void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_00448890(f32 *, f32 *, s32, f32, f32, f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_L01_0044E850(void *, void *, s32, f32, f32);
    f32 delta[4] __attribute__((aligned(16)));
    f32 rotation[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(self + 0x68);
    f32 angle;
    u8 *position = self + 0x10;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)delta)
        : "m"(*(vu0_v4 *)(self + 0x10)), "m"(*(vu0_v4 *)target)
        : "vf1", "vf2");
    angle = func_0038DB48(func_0038CE68(delta, self + 0xC0) / 0.3f);
    func_0038D750(rotation, 1, angle);
    func_0038D688(vars + 0x2D0, vars + 0x2D0, rotation);
    if (*(u32 *)(vars + 0x188) & 0x10) {
        if (self[0x42] == 7) {
            if (func_L01_0040E570(target, position) > 0.0001f) {
                angle = func_0038D160(*(f32 *)(self + 0x10) - target[0], *(f32 *)(self + 0x14) - target[1]);
                if (func_0038DBA0(*(f32 *)(self + 0xF8), angle) > 1.5707963705062866f) angle = func_0038DAB8(angle, 3.1415927410125732f);
                func_L01_00448890((f32 *)(self + 0xF8), (f32 *)(vars + 0x204), 0, angle, *(f32 *)(vars + 0x164), *(f32 *)(vars + 0x168), *(f32 *)(vars + 0x16C));
            }
        } else {
            if (func_L01_0040E570(target, position) > 0.0001f) {
                angle = func_0038D160(*(f32 *)(self + 0x10) - target[0], *(f32 *)(self + 0x14) - target[1]);
                if (func_0038DBA0(func_0038D160(*(f32 *)(vars + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(vars + 0x134) - *(f32 *)(self + 0x14)), angle) > 1.5707963705062866f) angle = func_0038DAB8(angle, 3.1415927410125732f);
                func_L01_00448890((f32 *)(self + 0xF8), (f32 *)(vars + 0x204), 0, angle, *(f32 *)(vars + 0x164), *(f32 *)(vars + 0x168), *(f32 *)(vars + 0x16C));
            }
            *(f32 *)(vars + 0x2A8) = func_0038DB00(func_0038D160(*(f32 *)(vars + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(vars + 0x134) - *(f32 *)(self + 0x14)), *(f32 *)(self + 0xF8));
            if (*(f32 *)(vars + 0x2A8) > 1.5707963705062866f) *(f32 *)(vars + 0x2A8) = 1.5707963705062866f;
            else if (*(f32 *)(vars + 0x2A8) < -1.5707963705062866f) *(f32 *)(vars + 0x2A8) = -1.5707963705062866f;
        }
    } else *(s32 *)(vars + 0x2A8) = 0;
    func_L01_0044E850(self, vars + 0x240, 2, 0.014400000683963299f, 0.4320000410079956f);
}
/* localdecomp:end func_L07_003BDFB8 */
