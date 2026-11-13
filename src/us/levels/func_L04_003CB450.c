#include "common.h"

/* NTSC-U counterpart of func_L04_003CD2C0 (src/levels/04_marcadia/L04_003CD2C0.c) */
/* localdecomp:start func_L04_003CB450 */
#include "vu0.h"

extern s32 func_L04_003CC2B0(u8 *a0);
extern void func_L04_003CC738(u8 *arg0, s32 arg1);
extern void func_L04_003CC7F0(u8 *);
extern void func_L04_003CC8F0(u8 *, s32, s32, s32);
extern void func_L04_003CD0D8(u8 *, u8 *);
extern void func_L04_003CD430();
extern void func_L02_00350598(void *a0);
extern s32 func_L01_00452EF0(u8 *);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_00388398(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_00458A08(u8 *, f32);
extern void func_L01_00458A70(u8 *, f32, f32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern u8 *func_L01_003AFF80(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_00451078(u8 *, void *);
extern void func_L01_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00457590(u8 *, void *, f32);
extern f32 func_L01_00436500(u8 *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_003CAF70(u8 *, u8 *);
extern void func_L01_004576E8(u8 *);
extern u8 D_001A4C60[];
extern s32 D_001A71A0[];
extern u8 D_L04_001D66B0_003CB450[8];
extern f32 D_L04_001DEA30;
extern f32 D_L04_001DEA34;
__asm__(".extern D_L04_001DEA30, 4");
__asm__(".extern D_L04_001DEA34, 4");

void func_L04_003CB450(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    f32 f;
    s32 r;

    if (func_L04_003CC2B0(a0) != 0) {
        func_L04_003CC738(a0, 1);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (a0[0x20] != 0xC) {
            if ((func_L01_00452EF0(a0) != 0) || ((a0[0x20] == 2) && (a0[0x94] == 9))) {
                if ((a0[0x94] != 9) && (func_00388800(a0 + 0x10, D_001A4C60) < *(f32 *)(s + 0x2E4))) {
                    func_L01_00441FB8(a0, 9, -1);
                } else {
                    *(s32 *)(s + 0x2F4) = func_0037E208(0, 0x2D);
                    func_L01_00441FB8(a0, 3, -1);
                }
            }
            if ((*(s16 *)(s + 0x234) == 1) && (func_00388398(s + 0x2F4) != 0)) {
                if (func_0037E1D8(5) != 0) {
                    func_L01_00441FB8(a0, 1, 1);
                } else {
                    func_L01_00441FB8(a0, 1, 2);
                }
            }
        }
        break;
    case 1:
        if (a0[0x20] != 0xC) {
            if ((func_L01_00452EF0(a0) != 0) || ((a0[0x20] == 2) && (a0[0x94] == 0xA) && (*(s32 *)(s + 0x2FC) <= 0))) {
                *(s32 *)(s + 0x2F4) = func_0037E208(0x3C, 0x78);
                *(s32 *)(s + 0x2F0) = func_0037E208(0x12C, 0x258);
                *(s32 *)(s + 0x2FC) = func_0037E208(2, 4);
                func_L01_00441FB8(a0, 5, -1);
            }
            if (a0[0x20] == 4) {
                if (*(s16 *)(s + 0x234) == 1) {
                    if (func_00388398(s + 0x2F4) != 0) {
                        func_L01_00441FB8(a0, 6, -1);
                    }
                } else {
                    if (func_00388398(s + 0x2F0) != 0) {
                        func_L01_00441FB8(a0, 1, 0);
                    }
                }
            } else if (a0[0x20] == 2) {
                if ((a0[0x94] == 4) || (a0[0x94] == 5)) {
                    func_L01_00441FB8(a0, 4, -1);
                } else if (a0[0x94] == 6) {
                    func_L01_00441FB8(a0, 7, -1);
                } else if (a0[0x94] == 7) {
                    func_L01_00441FB8(a0, 0xA, -1);
                } else if (a0[0x94] == 0xA) {
                    if (*(s16 *)(s + 0x234) == 1) {
                        *(s32 *)(s + 0x2FC) = *(s32 *)(s + 0x2FC) - 1;
                        func_L01_00441FB8(a0, 7, -1);
                    } else {
                        func_L01_00441FB8(a0, 1, 1);
                    }
                }
            }
        }
        break;
    case 2:
        if (a0[0x20] != 0xC) {
            if (func_L01_00452EF0(a0) != 0) {
                func_L01_00441FB8(a0, 7, -1);
            }
            if (a0[0x20] == 2) {
                if (a0[0x94] == 7) {
                    func_L01_00441FB8(a0, 8, -1);
                } else {
                    func_L01_00441FB8(a0, 1, 1);
                }
            }
        }
        break;
    }

    switch (a0[0x20]) {
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 0, 0, 10);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 0xC, 0, 3);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 0xB, 0, 3);
        }
        if (a0[0x60] & 2) {
            func_L04_003CC8F0(a0, 0xC, 0, 3);
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 0xD, 0, 3);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 6, 0, 8);
        }
        f = func_00388A28(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14));
        func_L01_00458A08(a0, f);
        f = func_00388A28(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14));
        if (func_00389468(*(f32 *)(a0 + 0xF8), f) < 0.05235988f) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 4, 0, 8);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 9:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 5, 0, 8);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 10:
        if (func_L01_00452EC8(a0) != 0) {
            func_L04_003CC8F0(a0, 2, 0, 3);
        }
        if ((func_L01_0044AF40(*(u8 **)(s + 0x300), 0.5f) != 0) && (*(s32 *)(s + 0x230) != D_001A71A0[0])) {
            func_003BDA38(*(u8 **)(s + 0x300), 0, &v90);
            vec_sub_ab(&vA0, s + 0x220, &v90);
            if ((*(s16 *)(s + 0x30C) != 0) && (func_0037E1D8(0x64) < 0x1A)) {
                vec_sub_ab(&vA0, s + 0x220, &v90);
                func_L01_003AFF80(a0, &v90, &vA0, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, (f32)s[0x44], 0.65f);
            } else {
                vB0 = *(vu0_v4 *)(s + 0x220);
                vB0.x += func_L01_00440918(0.0f, 0.5f);
                vB0.y += func_L01_00440918(0.0f, 0.5f);
                vB0.z += 1.0f;
                vec_sub_ab(&vA0, &vB0, &v90);
                func_L01_003AFF80(a0, &v90, &vA0, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
            f = func_0037E250(8.0f, 10.0f);
            func_L01_00466F98(&v90, D_L04_001D66B0_003CB450, 0x14, 0x50, 0xDD0040, 0, f * 0.25f * 210000.0f, 600.0f, 0.95f, 0.0f, 0.0f);
            f = f * 0.15f;
            func_L01_00466F98(&v90, D_L04_001D66B0_003CB450, 0x14, 0x50, 0xDDDDDD, 0, f * 210000.0f, 600.0f, 0.95f, 0.0f, 0.0f);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 12:
        r = func_L01_00451078(a0, s + 0x160);
        if (*(s16 *)(s + 0x30E) == 0) {
            *(f32 *)(s + 0x30) = *(s16 *)(s + 0x34);
        }
        if ((r & 1) || (*(f32 *)(s + 0x30) <= 0.0f)) {
            func_L01_0044ED60(a0, 0xF, D_L04_001D66B0_003CB450, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L01_0044ED60(*(u8 **)(s + 0x300), 0xF, D_L04_001D66B0_003CB450, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L02_00350598(a0);
            func_L01_0032FE90(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L04_003CC738(a0, 1);
            return;
        }
        if (r & 2) {
            a0[0xBE] &= 0xFD;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    case 13:
        if ((*(s32 *)(s + 0x2F4) != 0) && (func_00388398(s + 0x2F4) != 0)) {
            func_L01_00441FB8(a0, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, D_L04_001DEA34 * 0.00027777778f, D_L04_001DEA30 * 0.016666668f, 0.0069813174f, 0.20943953f);
            *(s32 *)(s + 0xA8) |= 1;
            func_L04_003CC8F0(a0, 7, func_0037E208(0, 6), 10);
        }
        vA0.x = func_00388960(*(f32 *)(s + 0x314));
        vA0.y = func_00388978(*(f32 *)(s + 0x314));
        vA0.z = 0.0f;
        func_003886E8(&v90, &vA0, 10.0f);
        vec_add_ab(&v90, &v90, a0 + 0x10);
        func_L01_00457590(a0, &v90, *(f32 *)(s + 0x314));
        if (*(f32 *)(s + 0x310) < vA0.x * *(f32 *)(a0 + 0x10) + vA0.y * *(f32 *)(a0 + 0x14)) {
            if (30.0f < *(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100)) {
                func_L01_00441FB8(a0, 0xF, -1);
            }
        }
        break;
    case 15:
        if (func_L01_00452EC8(a0) != 0) {
            *(f32 *)(s + 0x314) += func_0037E250(-0.08726646f, 0.08726646f);
            *(f32 *)(s + 0x110) = func_00388960(*(f32 *)(s + 0x314)) * 0.16666667f;
            *(f32 *)(s + 0x114) = func_00388978(*(f32 *)(s + 0x314)) * 0.16666667f;
            *(f32 *)(s + 0x118) = 0.13333334f;
            *(s32 *)(s + 0x100) = 0;
            *(s32 *)(s + 0xF8) = 0;
            qzero(s + 0xC0);
            *(s32 *)(s + 0xFC) = 0;
            *(s32 *)(s + 0x148) = -1;
            func_L04_003CC8F0(a0, 0xE, 2, 10);
        }
        func_L04_003CD0D8(a0, s);
        if (a0[0x60] & 2) {
            *(s32 *)(s + 0x2F4) = 0;
            func_L04_003CC8F0(a0, 0xF, 0, 5);
            func_L01_00441FB8(a0, 0x10, -1);
        }
        break;
    case 16:
        func_L04_003CD0D8(a0, s);
        if (*(s32 *)(s + 0x2F4) != 0) {
            if (func_00388398(s + 0x2F4) != 0) {
                func_L01_00441FB8(a0, 0x11, -1);
            }
        } else {
            if (*(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100) < 32.0f) {
                *(s32 *)(s + 0x2F4) = func_0037E208(1, 0x1E);
            }
        }
        break;
    case 17:
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(s + 0x2F4) = 0;
            func_L04_003CC8F0(a0, 0x10, 0, 5);
        }
        func_L04_003CD0D8(a0, s);
        if (a0[0x43] == 0x10) {
            if (8.0f < func_L01_00436500(a0)) {
                func_L01_004026A0(func_L04_003CD430, a0);
                *(s32 *)(s + 0x2F4) += 1;
            }
        }
        func_L01_003CAF70(a0, s);
        if (a0[0x60] & 2) {
            func_L04_003CC8F0(a0, 0x11, 0, 5);
            func_L01_00441FB8(a0, 0x12, -1);
        }
        break;
    case 18:
        func_L04_003CD0D8(a0, s);
        func_L01_004026A0(func_L04_003CD430, a0);
        func_L01_003CAF70(a0, s);
        if (*(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100) < 0.5f) {
            func_L01_00441FB8(a0, 0x13, -1);
        }
        break;
    case 19:
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(s + 0x2F4) = 0;
            *(s32 *)(s + 0xA8) &= ~1;
            func_L04_003CC8F0(a0, 0x12, 0, 5);
        }
        func_L01_004576E8(a0);
        func_L01_004026A0(func_L04_003CD430, a0);
        *(s32 *)(s + 0x2F4) += 1;
        func_L01_003CAF70(a0, s);
        if (a0[0x60] & 2) {
            func_L04_003CC8F0(a0, 0, 0, 1);
            func_L01_00441FB8(a0, 3, 0);
        }
        break;
    }
    func_L04_003CC7F0(a0);
}
/* localdecomp:end func_L04_003CB450 */
