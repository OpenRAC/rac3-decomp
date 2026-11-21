#include "common.h"

/* NTSC-U counterpart of func_L07_003AE618 (src/levels/07_annihilation_nation/L07_003ADF68.c) */
/* localdecomp:start func_L07_003ACDC0 */
extern u8 D_L07_001D66B0_003ACDC0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0_003ACDC0[];
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L07_00332CB8(s32, f32, f32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_0032FE90_003ACDC0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_00330E70(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L07_00330A18(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
void func_L07_003AD248(s32, s32);

void func_L07_003ACDC0(u8 *obj) {
    u8 *p;
    u8 *t;
    f32 f;
    f32 g;
    f32 yaw;
    f32 lim;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1 || obj[0x20] == 0xE) {
        return;
    }
    f = *(f32 *)(p + 0x120);
    t = (u8 *)func_L01_00444358(obj, 0x10000, 0);
    if (func_L01_0044FCD0(obj, p + 0x160, 0, 0, 0) != 0) {
        func_L07_00332CB8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x120));
    }
    if (*(s32 *)(p + 0x108) == 1) {
        func_L01_0044ED60(obj, 0x1F, D_L07_001D66B0_003ACDC0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0032FE90_003ACDC0(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L07_00330E70(obj);
    } else {
        if (*(f32 *)(p + 0x120) <= 0.0f) {
            if (t != 0 && 0.0f < func_00388730(t + 0x10, t + 0x10)) {
                g = -func_00388A28(func_003887A0(t + 0x10), *(f32 *)(t + 0x18));
                lim = 0.34906584f;
                if (lim < g) {
                    g = lim;
                } else if (g < 0.0f) {
                    g = 0.0f;
                }
                yaw = func_00388A28(*(f32 *)(t + 0x10), *(f32 *)(t + 0x14));
                func_0037E4B8(p + 0xD0, 1.0f, yaw, g);
                func_L07_003AD248((s32)obj, 0xE);
                return;
            }
            func_L01_0032FE90_003ACDC0(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004A72A8(2, 0, obj, 0x19D2);
            func_L07_00330E70(obj);
            return;
        }
        if (p[0x14E] != 0 || p[0x150] != 0 || p[0x12E] == 2) {
            func_L07_00330E70(obj);
            return;
        }
    }
    func_L07_00330A18(obj);
    if ((u8)(obj[0x20] - 8) < 3) {
        if (*(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f < *(f32 *)(obj + 0x18)) {
            *(f32 *)(p + 0x280) = *(f32 *)(p + 0x280) + 0.0027222223579883575f;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - *(f32 *)(p + 0x280);
            if (*(f32 *)(obj + 0x18) < *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f;
            }
        } else {
            *(s32 *)(p + 0x280) = 0;
        }
    } else {
        *(s32 *)(p + 0x280) = 0;
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0_003ACDC0, obj + 0x10) < 576.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003ACDC0 */
