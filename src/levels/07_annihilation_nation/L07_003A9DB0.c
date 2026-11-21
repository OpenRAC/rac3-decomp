#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A9DB0);

/* localdecomp:start func_L07_003AA228 */
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
void func_L07_003AA9C0(void *);
void func_L07_003AAA08(void *);

void func_L07_003AA228(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 mode = func_L07_003C1AF8();
    u8 *p = v + 0x30;
    f32 factor = func_L07_003C1B40(mode);
    *(s16 *)(p + 4) = *(s16 *)(v + 0x34) * factor;
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = v[0x44] * factor;
    p[0x15] = v[0x45] * factor;
    p[0x16] = v[0x46] * factor;
    if (mode == 1 || mode == 3) func_L01_00446058(self, 0x1D8A, 0x19BD);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.0f;
    p[0xF] = 0;
    p[9] = 0;
    *(f32 *)(v + 0xA0) = 1.0f;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x158) = 0.5f;
    v[0xB8] = 255;
    v[0x80] = 5;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.9749999642372131f;
    *(f32 *)(v + 0x154) = 0.15f;
    *(f32 *)(v + 0x15C) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.7853982f;
    *(f32 *)(v + 0x17C) = 0.003920000046491623f;
    *(s32 *)(v + 0x23C) = 0;
    *(void (**)(void *))(v + 0x244) = func_L07_003AAA08;
    *(void (**)(void *))(v + 0x248) = func_L07_003AA9C0;
    v[0x25D] = 1;
    *(s16 *)(v + 0x24C) = -1;
    v[0x25F] = 7;
    func_L01_0045BD78(self, 0.0014000000664964318f, 0.07000000774860382f, 0.005026548635214567f, 0.12566371262073517f);
    func_L07_003AA9C0(self);
}
/* localdecomp:end func_L07_003AA228 */

/* localdecomp:start func_L07_003AA458 */
#include "vu0.h"

extern u8 D_L07_001D66B0[8];
__asm__(".extern D_L07_001D66B0, 16");
extern u8 D_L07_001E1EC0[];
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L07_003315B0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L07_003333F8(s32, f32, f32);
extern void func_L07_00334588(void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern void func_L07_00331158(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_00446780(void *, f32, void *, s32, f32, f32, s32, s32, s32);

void func_L07_003AA458(u8 *obj) {
    f32 v90[4] __attribute__((aligned(16)));
    u8 *p;
    u8 *t;
    f32 f;
    f32 g;
    f32 yaw;
    f32 pos_d;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1) {
        return;
    }
    f = *(f32 *)(p + 0x30);
    if (f <= 0.0f) {
        *(vu0_q *)v90 = *(vu0_q *)(obj + 0x10);
        v90[2] = v90[2] + *(f32 *)(p + 0x40);
        func_L01_003303B8(v90, 0, 10, 5, 4, 10, 15, 0, 0.5f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(obj, 0x3FF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L07_003315B0(obj);
        func_003A52A0(8, 0, obj);
        return;
    }
    if (func_L01_00452FB0(obj, p + 0x70, 0, 0, 0) != 0) {
        func_L07_003333F8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x30));
        *(s32 *)(p + 0x188) = *(s32 *)(p + 0x188) & ~0x10;
        func_L07_00334588(obj);
    }
    if (*(s32 *)(p + 0x228) == 1) {
        qzero(v90);
        func_L01_00446A70(obj, obj, 0x10000, v90, v90, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] != 0 || p[0x60] != 0 || p[0x3E] == 2) {
        func_L07_003315B0(obj);
        return;
    }
    func_L07_00331158(obj);
    if ((*(s32 *)(p + 0x188) & 0x10) != 0) {
        if (obj[0x20] == 0xB) {
            yaw = func_0038D160(*(f32 *)(p + 0x520) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x524) - *(f32 *)(obj + 0x14));
        } else {
            yaw = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
        }
        g = func_0038DB00(yaw, *(f32 *)(obj + 0xF8));
        *(f32 *)(p + 0x2C8) = g;
        if (g > 1.5707964f) {
            *(f32 *)(p + 0x2C8) = 1.5707964f;
        } else if (g < -1.5707964f) {
            *(f32 *)(p + 0x2C8) = -1.5707964f;
        }
    }
    func_L01_0044E850(obj, p + 0x260, 2, 0.01f * 1.44f, 0.3f * 1.44f);
    *(f32 *)(p + 0x344) = *(f32 *)(p + 0x53C);
    func_L01_0044E850(obj, p + 0x2E0, 5, 0.03f * 1.44f, 0.3f * 1.44f);
    func_L01_0044E850(obj, p + 0x360, 3, 0.03f * 1.44f, 0.3f * 1.44f);
    func_L01_0044E850(obj, p + 0x3E0, 4, 0.03f * 1.44f, 0.3f * 1.44f);
    if (*(s16 *)(p + 0x144) == 1) {
        func_003C2F58(obj, 7, v90);
        t = *(u8 **)(p + 0x140);
        yaw = func_0038D160(*(f32 *)(t + 0x10) - v90[0], *(f32 *)(t + 0x14) - v90[1]);
        g = func_0038DB48(yaw - *(f32 *)(p + 0x2A8) - *(f32 *)(obj + 0xF8));
        *(f32 *)(p + 0x4C8) = g;
        if (g > 0.7853982f) {
            *(f32 *)(p + 0x4C8) = 0.7853982f;
        } else if (g < -0.7853982f) {
            *(f32 *)(p + 0x4C8) = -0.7853982f;
        }
        pos_d = func_0038CF38(v90, *(u8 **)(p + 0x140) + 0x10);
        t = *(u8 **)(p + 0x140);
        g = -func_0038D160(pos_d, *(f32 *)(t + 0x18) - v90[2]);
        *(f32 *)(p + 0x4C4) = g;
        if (g > 0.2617994f) {
            *(f32 *)(p + 0x4C4) = 0.2617994f;
        } else if (g < -0.2617994f) {
            *(f32 *)(p + 0x4C4) = -0.2617994f;
        }
    }
    func_L01_0044E850(obj, p + 0x460, 7, 0.03f * 1.44f, 0.3f * 1.44f);
    func_L07_004522E8(obj, 8, p + 0x4E0, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
    func_L01_00446780(obj, 1.2f, obj + 0x10, 0x8000000, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_003AA458 */
