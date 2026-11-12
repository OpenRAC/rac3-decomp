#include "common.h"

/* localdecomp:start func_L04_003CD2C0 */
#include "vu0.h"

extern s32 func_L04_003CE120(u8 *a0);
extern void func_L04_003CE5A8(u8 *arg0, s32 arg1);
extern void func_L04_003CE660(u8 *);
extern void func_L04_003CE760(u8 *, s32, s32, s32);
extern void func_L04_003CEF60(u8 *, u8 *);
extern void func_L04_003CF2B8();
extern void func_L02_003516A8(void *a0);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_0045BD10(u8 *, f32);
extern void func_L01_0045BD78(u8 *, f32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern u8 *func_L01_003B1750(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_00454370(u8 *, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0045A898(u8 *, void *, f32);
extern f32 func_L01_004395E0(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_003CC808(u8 *, u8 *);
extern void func_L01_0045A9F0(u8 *);
extern u8 D_001A4C60[];
extern s32 D_001A71A0[];
extern u8 D_L01_001D66B0[8];
extern f32 D_L04_001DE9F0;
extern f32 D_L04_001DE9F4;
__asm__(".extern D_L04_001DE9F0, 4");
__asm__(".extern D_L04_001DE9F4, 4");

void func_L04_003CD2C0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    f32 f;
    s32 r;

    if (func_L04_003CE120(a0) != 0) {
        func_L04_003CE5A8(a0, 1);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (a0[0x20] != 0xC) {
            if ((func_L01_004561E0(a0) != 0) || ((a0[0x20] == 2) && (a0[0x94] == 9))) {
                if ((a0[0x94] != 9) && (func_0038CF38(a0 + 0x10, D_001A4C60) < *(f32 *)(s + 0x2E4))) {
                    func_L01_004450F0(a0, 9, -1);
                } else {
                    *(s32 *)(s + 0x2F4) = func_00382498(0, 0x2D);
                    func_L01_004450F0(a0, 3, -1);
                }
            }
            if ((*(s16 *)(s + 0x234) == 1) && (func_0038CAD0(s + 0x2F4) != 0)) {
                if (func_00382468(5) != 0) {
                    func_L01_004450F0(a0, 1, 1);
                } else {
                    func_L01_004450F0(a0, 1, 2);
                }
            }
        }
        break;
    case 1:
        if (a0[0x20] != 0xC) {
            if ((func_L01_004561E0(a0) != 0) || ((a0[0x20] == 2) && (a0[0x94] == 0xA) && (*(s32 *)(s + 0x2FC) <= 0))) {
                *(s32 *)(s + 0x2F4) = func_00382498(0x3C, 0x78);
                *(s32 *)(s + 0x2F0) = func_00382498(0x12C, 0x258);
                *(s32 *)(s + 0x2FC) = func_00382498(2, 4);
                func_L01_004450F0(a0, 5, -1);
            }
            if (a0[0x20] == 4) {
                if (*(s16 *)(s + 0x234) == 1) {
                    if (func_0038CAD0(s + 0x2F4) != 0) {
                        func_L01_004450F0(a0, 6, -1);
                    }
                } else {
                    if (func_0038CAD0(s + 0x2F0) != 0) {
                        func_L01_004450F0(a0, 1, 0);
                    }
                }
            } else if (a0[0x20] == 2) {
                if ((a0[0x94] == 4) || (a0[0x94] == 5)) {
                    func_L01_004450F0(a0, 4, -1);
                } else if (a0[0x94] == 6) {
                    func_L01_004450F0(a0, 7, -1);
                } else if (a0[0x94] == 7) {
                    func_L01_004450F0(a0, 0xA, -1);
                } else if (a0[0x94] == 0xA) {
                    if (*(s16 *)(s + 0x234) == 1) {
                        *(s32 *)(s + 0x2FC) = *(s32 *)(s + 0x2FC) - 1;
                        func_L01_004450F0(a0, 7, -1);
                    } else {
                        func_L01_004450F0(a0, 1, 1);
                    }
                }
            }
        }
        break;
    case 2:
        if (a0[0x20] != 0xC) {
            if (func_L01_004561E0(a0) != 0) {
                func_L01_004450F0(a0, 7, -1);
            }
            if (a0[0x20] == 2) {
                if (a0[0x94] == 7) {
                    func_L01_004450F0(a0, 8, -1);
                } else {
                    func_L01_004450F0(a0, 1, 1);
                }
            }
        }
        break;
    }

    switch (a0[0x20]) {
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 0, 0, 8);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 0xC, 0, 2);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 0xB, 0, 2);
        }
        if (a0[0x60] & 2) {
            func_L04_003CE760(a0, 0xC, 0, 2);
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 0xD, 0, 2);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 6, 0, 7);
        }
        f = func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14));
        func_L01_0045BD10(a0, f);
        f = func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14));
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), f) < 0.05235988f) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 4, 0, 7);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 9:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 5, 0, 7);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 10:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_003CE760(a0, 2, 0, 2);
        }
        if ((func_L01_0044E1B8(*(u8 **)(s + 0x300), 0.5f) != 0) && (*(s32 *)(s + 0x230) != D_001A71A0[0])) {
            func_003C2F58(*(u8 **)(s + 0x300), 0, &v90);
            vec_sub_ab(&vA0, s + 0x220, &v90);
            if ((*(s16 *)(s + 0x30C) != 0) && (func_00382468(0x64) < 0x1A)) {
                vec_sub_ab(&vA0, s + 0x220, &v90);
                func_L01_003B1750(a0, &v90, &vA0, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, (f32)s[0x44], 0.65f);
            } else {
                vB0 = *(vu0_v4 *)(s + 0x220);
                vB0.x += func_L01_00443A18(0.0f, 0.5f);
                vB0.y += func_L01_00443A18(0.0f, 0.5f);
                vB0.z += 1.0f;
                vec_sub_ab(&vA0, &vB0, &v90);
                func_L01_003B1750(a0, &v90, &vA0, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
            f = func_003824E0(8.0f, 10.0f);
            func_L01_0046A610(&v90, D_L01_001D66B0, 0x11, 0x50, 0xDD0040, 0, f * 0.25f * 210000.0f, 600.0f, 0.95f, 0.0f, 0.0f);
            f = f * 0.15f;
            func_L01_0046A610(&v90, D_L01_001D66B0, 0x11, 0x50, 0xDDDDDD, 0, f * 210000.0f, 600.0f, 0.95f, 0.0f, 0.0f);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 12:
        r = func_L01_00454370(a0, s + 0x160);
        if (*(s16 *)(s + 0x30E) == 0) {
            *(f32 *)(s + 0x30) = *(s16 *)(s + 0x34);
        }
        if ((r & 1) || (*(f32 *)(s + 0x30) <= 0.0f)) {
            func_L01_00451FE0(a0, 0xF, D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L01_00451FE0(*(u8 **)(s + 0x300), 0xF, D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L02_003516A8(a0);
            func_L01_003303B8(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L04_003CE5A8(a0, 1);
            return;
        }
        if (r & 2) {
            a0[0xBE] &= 0xFD;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 13:
        if ((*(s32 *)(s + 0x2F4) != 0) && (func_0038CAD0(s + 0x2F4) != 0)) {
            func_L01_004450F0(a0, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, D_L04_001DE9F4 * 0.00040000002f, D_L04_001DE9F0 * 0.020000001f, 0.010053097f, 0.25132743f);
            *(s32 *)(s + 0xA8) |= 1;
            func_L04_003CE760(a0, 7, func_00382498(0, 6), 8);
        }
        vA0.x = func_0038D098(*(f32 *)(s + 0x314));
        vA0.y = func_0038D0B0(*(f32 *)(s + 0x314));
        vA0.z = 0.0f;
        func_0038CE20(&v90, &vA0, 10.0f);
        vec_add_ab(&v90, &v90, a0 + 0x10);
        func_L01_0045A898(a0, &v90, *(f32 *)(s + 0x314));
        if (*(f32 *)(s + 0x310) < vA0.x * *(f32 *)(a0 + 0x10) + vA0.y * *(f32 *)(a0 + 0x14)) {
            if (30.0f < *(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100)) {
                func_L01_004450F0(a0, 0xF, -1);
            }
        }
        break;
    case 15:
        if (func_L01_004561B8(a0) != 0) {
            *(f32 *)(s + 0x314) += func_003824E0(-0.08726646f, 0.08726646f);
            *(f32 *)(s + 0x110) = func_0038D098(*(f32 *)(s + 0x314)) * 0.20000002f;
            *(f32 *)(s + 0x114) = func_0038D0B0(*(f32 *)(s + 0x314)) * 0.20000002f;
            *(f32 *)(s + 0x118) = 0.16000001f;
            *(s32 *)(s + 0x100) = 0;
            *(s32 *)(s + 0xF8) = 0;
            qzero(s + 0xC0);
            *(s32 *)(s + 0xFC) = 0;
            *(s32 *)(s + 0x148) = -1;
            func_L04_003CE760(a0, 0xE, 2, 8);
        }
        func_L04_003CEF60(a0, s);
        if (a0[0x60] & 2) {
            *(s32 *)(s + 0x2F4) = 0;
            func_L04_003CE760(a0, 0xF, 0, 4);
            func_L01_004450F0(a0, 0x10, -1);
        }
        break;
    case 16:
        func_L04_003CEF60(a0, s);
        if (*(s32 *)(s + 0x2F4) != 0) {
            if (func_0038CAD0(s + 0x2F4) != 0) {
                func_L01_004450F0(a0, 0x11, -1);
            }
        } else {
            if (*(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100) < 32.0f) {
                *(s32 *)(s + 0x2F4) = func_00382498(1, 0x1E);
            }
        }
        break;
    case 17:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(s + 0x2F4) = 0;
            func_L04_003CE760(a0, 0x10, 0, 4);
        }
        func_L04_003CEF60(a0, s);
        if (a0[0x43] == 0x10) {
            if (8.0f < func_L01_004395E0(a0)) {
                func_L01_00404A10(func_L04_003CF2B8, a0);
                *(s32 *)(s + 0x2F4) += 1;
            }
        }
        func_L01_003CC808(a0, s);
        if (a0[0x60] & 2) {
            func_L04_003CE760(a0, 0x11, 0, 4);
            func_L01_004450F0(a0, 0x12, -1);
        }
        break;
    case 18:
        func_L04_003CEF60(a0, s);
        func_L01_00404A10(func_L04_003CF2B8, a0);
        func_L01_003CC808(a0, s);
        if (*(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x100) < 0.5f) {
            func_L01_004450F0(a0, 0x13, -1);
        }
        break;
    case 19:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(s + 0x2F4) = 0;
            *(s32 *)(s + 0xA8) &= ~1;
            func_L04_003CE760(a0, 0x12, 0, 4);
        }
        func_L01_0045A9F0(a0);
        func_L01_00404A10(func_L04_003CF2B8, a0);
        *(s32 *)(s + 0x2F4) += 1;
        func_L01_003CC808(a0, s);
        if (a0[0x60] & 2) {
            func_L04_003CE760(a0, 0, 0, 1);
            func_L01_004450F0(a0, 3, 0);
        }
        break;
    }
    func_L04_003CE660(a0);
}
/* localdecomp:end func_L04_003CD2C0 */

/* localdecomp:start func_L04_003CE120 */
extern s32 func_L04_003CE348(u8 *a0);
extern s32 func_L04_003CE7C8(u8 *a0, u8 *a1, s32 a2);
extern void func_L02_0034FD58(void *a0);
extern void func_L02_003516A8(void *a0);
extern void func_L01_0044FD88(void *a0, void *a1, s32 a2, s32 a3);
extern f32 func_L01_0040E548(void *a0, void *a1);
extern void func_L01_004472C0(void *a0);
extern s32 func_00382380(void *a0, s32 a1, s32 a2);
extern void func_L01_00456BD0(void *a0, s32 a1);
extern void func_L01_00456C98(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, f32 f1, f32 f2, f32 f3);
extern u8 D_L04_001E2840[];
__asm__(".extern D_L04_001E2840, 16");
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");

s32 func_L04_003CE120(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *w;
    f32 f;

    if (a0[0x20] == 0) {
        if (func_L04_003CE348(a0) != 0) {
            return 1;
        }
    }
    if (func_L04_003CE7C8(a0, s + 0x160, 0) != 0) {
        func_L02_0034FD58(a0);
    }
    if (s[0x5E] != 0) {
        func_L02_003516A8(a0);
        return 1;
    }
    if (*(u8 **)(s + 0x300) != 0) {
        w = *(u8 **)(s + 0x300);
        *(long *)(w + 0x38) = *(long *)(a0 + 0x38);
        func_L01_0044FD88(a0, *(u8 **)(s + 0x300), 0, 0);
        w = *(u8 **)(s + 0x300);
        if (w[0x31] != 0) {
            f = func_L01_0040E548(D_L04_001E2840, w + 0x10);
            if (f < 576.0f) {
                func_L01_004472C0(*(u8 **)(s + 0x300));
                (*(u8 **)(s + 0x300))[0x6F] = 0x16;
            }
        }
    }
    if (a0[0x31] != 0) {
        f = func_L01_0040E548(D_L04_001E2840, a0 + 0x10);
        if (f < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    *(s16 *)(s + 0x30C) = (*(s32 *)(s + 0x304) != -1) && (func_00382380(D_001A4C60, *(s32 *)(s + 0x304), 0) != 0);
    *(s16 *)(s + 0x30E) = (*(s32 *)(s + 0x308) != -1) && (func_00382380(D_001A4C60, *(s32 *)(s + 0x308), 0) != 0);
    func_L01_00456BD0(a0, 1);
    if (a0[0x20] == 0) {
        func_L01_00456C98(a0, *(s32 *)(s + 0x2E8), 0, 0, 1, 1, 3, 0, 0, 0, *(f32 *)(s + 0x2EC), 10.0f, 1.0f);
    } else {
        func_L01_00456C98(a0, *(s32 *)(s + 0x2E0), 0, 0, 1, 1, 3, 0, 0, 0, *(f32 *)(s + 0x2E4), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L04_003CE120 */

/* localdecomp:start func_L04_003CE348 */
typedef int u128_3CE348 __attribute__((mode(TI)));

typedef struct S_3CE348 {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    u8 pad36[0x2];
    u8 f38;
    u8 f39;
    u8 pad3A[0x6];
    f32 f40;
    u8 f44;
    u8 pad45[0x13];
    u8 f58;
    u8 pad59[0x1];
    u8 f5A;
    u8 pad5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    u8 padA4[0xCC];
    u8 f170;
    u8 f171;
    u8 f172;
    u8 pad173[0x3];
    u8 f176;
    u8 pad177[0x19];
    f32 f190;
    f32 f194;
    s16 f198;
    u8 pad19A[0x2];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 f1A8;
    u8 pad1A9[0x2E];
    u8 f1D7;
    u8 f1D8;
    u8 f1D9;
    u8 f1DA;
    u8 f1DB;
    u8 pad1DC[0x64];
    s32 f240;
    u8 pad244[0xA];
    u8 f24E;
    u8 f24F;
    u8 pad250[0x80];
    u128_3CE348 f2D0;
    u8 pad2E0[0x10];
    s32 f2F0;
    s32 f2F4;
    s32 f2F8;
    u8 pad2FC[0x4];
    void * f300;
    s32 f304;
    s32 f308;
    s16 f30C;
    s16 f30E;
} S_3CE348;

extern void *func_003C24B0(s32 a0, s32 a1);
extern s32 func_L01_00456160(void *a0, u8 *a1);
extern void (**func_L01_0043B548(s32 a0, s32 a1))(u8 *);
extern void func_003C2880(u8 *a0);
extern void func_L04_003CE760(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

s32 func_L04_003CE348(u8 *a0) {
    S_3CE348 *s1 = *(S_3CE348 **)(a0 + 0x68);
    s16 h34;
    u128_3CE348 position;
    void *p;
    void (**t)(u8 *);

    position = *(u128_3CE348 *)(a0 + 0x10);
    s1->f198 = 0;
    s1->f2D0 = position;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    h34 = s1->f34;
    s1->f1A8 = 255;
    s1->f190 = 0.5f;
    s1->f1D8 = 2;
    s1->f1DA = 0;
    s1->f1DB = 255;
    s1->f176 = 255;
    s1->f171 = 255;
    s1->f170 = 12;
    s1->f194 = 0.5f;
    s1->f19C = 0.15f;
    s1->f1D7 = 1;
    s1->f1D9 = 2;
    s1->f172 = 255;
    s1->f70 = 0.75f;
    s1->f74 = 0.2f;
    s1->f78 = 1.0f;
    s1->f7C = 1.75f;
    s1->f80 = 1.3089969f;
    s1->fA0 = 0.34906584f;
    s1->f9C = 0.00392f;
    s1->f58 = 20;
    s1->f5A = 14;

    if (h34 == 0 || s1->f30 <= 0.0f) {
        s1->f34 = 10;
        s1->f30 = 10.0f;
    }
    if (s1->f44 == 0) {
        s1->f44 = 1;
    }
    s1->f40 = 2.0f;
    s1->f38 = 1;
    s1->f39 = 1;
    if (s1->f300 == 0) {
        p = func_003C24B0(0x19C1, 0x80);
        s1->f300 = p;
        func_L01_00456160(p, a0);
    }

    s1->f30C = (s1->f304 == -1);
    s1->f30E = (s1->f308 == -1);
    s1->f2F0 = 0;
    s1->f2F4 = 0;
    s1->f2F8 = 0;
    if (s1->f240 > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        s1->f240 = -1;
        func_L04_003CE760(a0, 0, 0, 1);
        s1->f24E = 11;
        s1->f24F = 4;
        (*t)(a0);
        if (s1->f300 != 0) {
            func_003C2880(s1->f300);
            s1->f300 = 0;
        }
    } else {
        func_L01_004450F0(a0, 3, 0);
        func_L04_003CE760(a0, 0, 0, 1);
    }
    return 0;
}
/* localdecomp:end func_L04_003CE348 */

/* localdecomp:start func_L04_003CE5A8 */
extern void func_003C2880(u8 *a0);
extern void (**func_L01_0043B548(s32 a0, s32 a1))(u8 *);

void func_L04_003CE5A8(u8 *arg0, s32 arg1) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    void (**t)(u8 *);

    if (*(u32 *)(s2 + 0x300) != 0) {
        func_003C2880(*(u8 **)(s2 + 0x300));
        *(u32 *)(s2 + 0x300) = 0;
    }
    if (*(u32 *)(s2 + 0x240) != 0) {
        t = func_L01_0043B548(6625, 108);
        (*t)(arg0);
        if (arg1 != 0) {
            t[1](arg0);
        }
    } else {
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L04_003CE5A8 */
