/* functional: high. checked from the NTSC-U draft re-translated to PAL names and constants (particle id 0x11 not 0x14, extra w=0 store); needs -mvu0-use-vf0-vf2 for vec_add_ab; not byte exact (loop counter register,  symbol offset shows differently with --no-context); D_L40_001DDF30 is the gp-relative current-object pointer */
#include "common.h"
#include "vu0.h"

extern u8 *D_L40_001DDF30;
__asm__(".extern D_L40_001DDF30, 4");
extern s32 func_L40_003DA350(void *, f32);
extern void func_L40_003DA2D0(void);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L40_003D9E78(void *, void *);
extern s32 func_L39_005B4398(s32);
extern void func_L40_003D9D28(void *, void *);
extern s32 func_0038CB00(void *);
extern void func_L40_003DB068(void *);
extern void func_003CD250(void *);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern u8 *func_L01_0046CA28(void *, s32, s32, s32);

void func_L40_003DA390(u8 *self) {
    vu0_v4 vB;
    vu0_v4 vA;
    vu0_v4 v20;
    vu0_v4 vC;
    vu0_v4 v40;
    u8 *m;
    u8 *t;
    u8 *c;
    u8 **slot;
    u8 *p;
    s32 i;
    f32 ratio;

    m = *(u8 **)(self + 0x68);
    t = *(u8 **)(m + 0x4C);
    if (t == 0) {
        return;
    }
    if (func_L40_003DA350(t + 0xA0, 48.0f) == 0) {
        return;
    }
    if (D_L40_001DDF30 == self) {
        func_L40_003DA2D0();
    }
    if (m[0x42] != 0) {
        func_0038CE20(self + 0x10, t + 0x250, -0.75f);
        vec_add_ab(self + 0x10, t + 0xA0, self + 0x10);
        *(f32 *)(self + 0xFC) = 0.5235988f;
        if (func_L40_003D9E78(self, t) != 0) {
            if (func_L39_005B4398(5) == 0) {
                func_L40_003D9D28(self, t);
            }
        }
    }
    if (func_0038CB00(m + 0x40) != 0) {
        func_L40_003DB068(self);
        return;
    }
    func_0038CE20(&v20, t + 0x250, -0.75f);
    vec_add_ab(&v20, t + 0xA0, &v20);
    for (i = 3, slot = (u8 **)(m + 0x30); i >= 0; i--, slot++) {
        c = *slot;
        if (c == 0) {
            continue;
        }
        if (func_0038CB00(c + 0x3E) != 0) {
            if (m[0x42] == 0 && D_L40_001DDF30 != 0) {
                m[0x42] = 1;
            }
            func_003CD250(c);
            *slot = 0;
            continue;
        }
        vA.x = *(f32 *)(c + 0x30);
        vA.y = *(f32 *)(c + 0x34);
        vA.z = *(f32 *)(c + 0x38);
        vA.w = 0.0f;
        ratio = 1.0f - (f32) * (s16 *)(c + 0x3E) / (f32) * (s16 *)(c + 0x3C);
        vB.x = vA.x - *(f32 *)(c + 0x24);
        vB.y = vA.y - *(f32 *)(c + 0x28);
        vB.z = vA.z - *(f32 *)(c + 0x2C);
        vC.x = v20.x - *(f32 *)(c + 0x24);
        vC.y = v20.y - *(f32 *)(c + 0x28);
        vC.z = v20.z - *(f32 *)(c + 0x2C);
        *(f32 *)(c + 0x10) = func_L01_004451D0(vB.x, vA.x, v20.x, vC.x, ratio);
        *(f32 *)(c + 0x14) = func_L01_004451D0(vB.y, vA.y, v20.y, vC.y, ratio);
        *(f32 *)(c + 0x18) = func_L01_004451D0(vB.z, vA.z, v20.z, vC.z, ratio);
        v40.x = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x10);
        v40.y = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x14);
        v40.z = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x18);
        p = func_L01_0046CA28(&v40, 0x11, 0, 0);
        if (p != 0) {
            *(f32 *)(p + 0xC) = 10000.0f;
            *(s32 *)(p + 4) = 0x7F7F4040;
        }
    }
}
