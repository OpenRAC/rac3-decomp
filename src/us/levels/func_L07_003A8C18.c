#include "common.h"

/* NTSC-U counterpart of func_L07_003AA458 (src/levels/07_annihilation_nation/L07_003A9DB0.c) */
/* localdecomp:start func_L07_003A8C18 */
#include "vu0.h"

extern u8 D_L07_001D66B0_003A8C18[8];
__asm__(".extern D_L07_001D66B0_003A8C18, 16");
extern u8 D_L07_001E1EC0_003A8C18[];
extern s32 func_L01_0032FE90_003A8C18(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L07_00330E70(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L07_00332CB8(s32, f32, f32);
extern void func_L07_00333E48(void *);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern void func_L07_00330A18(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389410(f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388800(void *, void *);
extern void func_L07_0044F0E8(void *, s32, void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_00443648(void *, f32, void *, s32, f32, f32, s32, s32, s32);

void func_L07_003A8C18(u8 *obj) {
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
        func_L01_0032FE90_003A8C18(v90, 0, 10, 5, 4, 10, 15, 0, 0.5f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_0044ED60(obj, 0x3FF, D_L07_001D66B0_003A8C18, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L07_00330E70(obj);
        func_0039FE80(8, 0, obj);
        return;
    }
    if (func_L01_0044FCD0(obj, p + 0x70, 0, 0, 0) != 0) {
        func_L07_00332CB8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x30));
        *(s32 *)(p + 0x188) = *(s32 *)(p + 0x188) & ~0x10;
        func_L07_00333E48(obj);
    }
    if (*(s32 *)(p + 0x228) == 1) {
        qzero(v90);
        func_L01_00443938(obj, obj, 0x10000, v90, v90, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] != 0 || p[0x60] != 0 || p[0x3E] == 2) {
        func_L07_00330E70(obj);
        return;
    }
    func_L07_00330A18(obj);
    if ((*(s32 *)(p + 0x188) & 0x10) != 0) {
        if (obj[0x20] == 0xB) {
            yaw = func_00388A28(*(f32 *)(p + 0x520) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x524) - *(f32 *)(obj + 0x14));
        } else {
            yaw = func_00388A28(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
        }
        g = func_003893C8(yaw, *(f32 *)(obj + 0xF8));
        *(f32 *)(p + 0x2C8) = g;
        if (g > 1.5707964f) {
            *(f32 *)(p + 0x2C8) = 1.5707964f;
        } else if (g < -1.5707964f) {
            *(f32 *)(p + 0x2C8) = -1.5707964f;
        }
    }
    func_L01_0044B5C8(obj, p + 0x260, 2, 0.01f, 0.3f);
    *(f32 *)(p + 0x344) = *(f32 *)(p + 0x53C);
    func_L01_0044B5C8(obj, p + 0x2E0, 5, 0.03f, 0.3f);
    func_L01_0044B5C8(obj, p + 0x360, 3, 0.03f, 0.3f);
    func_L01_0044B5C8(obj, p + 0x3E0, 4, 0.03f, 0.3f);
    if (*(s16 *)(p + 0x144) == 1) {
        func_003BDA38(obj, 7, v90);
        t = *(u8 **)(p + 0x140);
        yaw = func_00388A28(*(f32 *)(t + 0x10) - v90[0], *(f32 *)(t + 0x14) - v90[1]);
        g = func_00389410(yaw - *(f32 *)(p + 0x2A8) - *(f32 *)(obj + 0xF8));
        *(f32 *)(p + 0x4C8) = g;
        if (g > 0.7853982f) {
            *(f32 *)(p + 0x4C8) = 0.7853982f;
        } else if (g < -0.7853982f) {
            *(f32 *)(p + 0x4C8) = -0.7853982f;
        }
        pos_d = func_00388800(v90, *(u8 **)(p + 0x140) + 0x10);
        t = *(u8 **)(p + 0x140);
        g = -func_00388A28(pos_d, *(f32 *)(t + 0x18) - v90[2]);
        *(f32 *)(p + 0x4C4) = g;
        if (g > 0.2617994f) {
            *(f32 *)(p + 0x4C4) = 0.2617994f;
        } else if (g < -0.2617994f) {
            *(f32 *)(p + 0x4C4) = -0.2617994f;
        }
    }
    func_L01_0044B5C8(obj, p + 0x460, 7, 0.03f, 0.3f);
    func_L07_0044F0E8(obj, 8, p + 0x4E0, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0_003A8C18, obj + 0x10) < 576.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x16;
        }
    }
    func_L01_00443648(obj, 1.2f, obj + 0x10, 0x8000000, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_003A8C18 */
