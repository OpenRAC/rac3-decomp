#include "common.h"

/* NTSC-U counterpart of func_L34_0034F718 (src/levels/34_vidcomic_3/L34_0034F718.c) */
/* localdecomp:start func_L34_0034EA20 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034F718;

extern u8 D_001A4BE0[];
extern f32 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern u8 D_L34_001D66B0_0034EA20;
extern u8 *D_L34_0021F298[];
extern u8 *D_L34_0021F2A8[];
extern u8 *D_L34_0021F36C[];
extern u8 *D_L34_0021F404[];
extern f32 D_L34_001DD764;
extern s32 D_L34_001DD768_0034EA20;
extern f32 D_L34_001DD76C_0034EA20;
extern s32 D_L34_001DD770_0034EA20;
extern f32 D_L34_001DD774_0034EA20;
extern f32 D_L34_001DD778_0034EA20;
extern f32 D_L34_001DD77C_0034EA20;
extern f32 D_L34_001DD780_0034EA20;
extern f32 D_L34_001DD784_0034EA20;
extern f32 D_L34_001DD788;
__asm__(".extern D_L34_001DD764, 4");
__asm__(".extern D_L34_001DD768_0034EA20, 4");
__asm__(".extern D_L34_001DD76C_0034EA20, 4");
__asm__(".extern D_L34_001DD770_0034EA20, 4");
__asm__(".extern D_L34_001DD774_0034EA20, 4");
__asm__(".extern D_L34_001DD778_0034EA20, 4");
__asm__(".extern D_L34_001DD77C_0034EA20, 4");
__asm__(".extern D_L34_001DD780_0034EA20, 4");
__asm__(".extern D_L34_001DD784_0034EA20, 4");
__asm__(".extern D_L34_001DD788, 4");

extern f32 func_00388800(void *, void *);
extern void func_L34_0034F640(u8 *);
extern void func_00388BD0(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L34_0034FB88(u8 *);
extern s32 func_00388398(void *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L34_0034F9F0(u8 *);
extern s32 func_L34_0034F5A8(u8 *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L03_00445EB8(void *, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00457440(void *, void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L34_0034FA48(u8 *);
extern s32 func_L01_00451078(void *, void *);
extern void func_003BD360(void *);
extern f32 fabsf(f32);

void func_L34_0034EA20(u8 *a0) {
    u8 *p;
    u8 *g;
    f32 d;
    f32 t;
    u8 a;
    s32 c;
    s32 c2;
    s32 i;
    u8 *e;
    V4_0034F718 tmp;
    V4_0034F718 v;
    V4_0034F718 w;
    s32 s;

    p = *(u8 **)(a0 + 0x68);
    d = func_00388800(a0 + 0x10, D_001A4C60);
    func_L34_0034F640(a0);
    func_00388BD0(a0 + 0xC0, a0 + 0xF0);
    func_00388830(a0 + 0xD0, a0 + 0xD0, D_L34_001DD76C_0034EA20);
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        func_L34_0034FB88(a0);
        break;
    case 1:
        if (*(s32 *)(p + 0x270) != 0 && func_00388398(p + 0x274)) {
            *(u16 *)(a0 + 0x34) &= ~0x41;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        if (*(s32 *)(p + 0x260) != -1) {
            func_L01_00441FB8(a0, 3, -1);
            return;
        }
        if (func_L01_00452EC8(a0)) {
            *(s32 *)(p + 0x250) = D_L34_001DD768_0034EA20;
            if (*(s32 *)(p + 0x254) != 0) {
                if (*(u8 *)(a0 + 0x43) != 2) {
                    func_003BE4F0(a0, 2, 0, 11);
                }
            } else {
                if (*(u8 *)(a0 + 0x43) != 0) {
                    func_003BE4F0(a0, 0, 0, 11);
                }
            }
        }
        func_L34_0034F9F0(a0);
        if (func_L34_0034F5A8(a0)) {
            func_L01_00441FB8(a0, 5, -1);
        }
        break;
    case 3:
        func_L01_00458A70(a0, D_L34_001DD788 * 0.0002777777845f, D_L34_001DD780_0034EA20 * 0.0166666675f,
                          D_L34_001DD778_0034EA20 * 0.017453292f * 0.0002777777845f,
                          D_L34_001DD77C_0034EA20 * 0.017453292f * 0.0166666675f);
        func_L03_00445EB8(a0, *(s32 *)(p + 0x260));
        if (*(u8 *)(a0 + 0x43) != 0xC) {
            func_003BE4F0(a0, 0xC, 0, 8);
        }
        *(f32 *)(a0 + 0x48) = 0.92f;
        if (func_L34_0034F5A8(a0)) {
            func_L01_00441FB8(a0, 5, -1);
        }
        break;
    case 10:
        if (*(u8 *)(a0 + 0x43) != 0xE) {
            func_003BE4F0(a0, 0xE, 2, 7);
        }
        if (*(u8 *)(a0 + 0x60) & 2) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 5:
        if (*(f32 *)(p + 0x268) + 1.5f < d) {
            func_L01_00441FB8(a0, 4, -1);
            break;
        }
        if (*(s32 *)(p + 0x27C) != 0) {
            u8 *g = D_001A4BE0;
            if (func_00389468(*(f32 *)(a0 + 0xF8),
                              func_00388A28(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
                if (*(u8 *)(a0 + 0x43) != 0xF) {
                    func_003BE4F0(a0, 0xF, 8, 11);
                }
                func_L01_00441FB8(a0, 9, -1);
                *(s32 *)(p + 0x27C) = 0;
                break;
            }
        }
        *(s32 *)(p + 0x254) = 1;
        if (*(u8 *)(a0 + 0x43) != 9) {
            func_003BE4F0(a0, 9, 0, 9);
        }
        {
            s32 prev = *(s32 *)(p + 0x278);
            *(s32 *)(p + 0x278) = D_L34_001DD770_0034EA20;
            *(s32 *)(p + 0x250) = prev;
        }
        func_L01_00441FB8(a0, 6, -1);
        break;
    case 4:
        t = D_L34_001DD784_0034EA20;
        if (*(f32 *)(p + 0x280) != 0.0f) {
            t = *(f32 *)(p + 0x280);
        }
        func_L01_00458A70(a0, D_L34_001DD788 * 0.0002777777845f, t * 0.0166666675f,
                          D_L34_001DD778_0034EA20 * 0.017453292f * 0.0002777777845f,
                          D_L34_001DD77C_0034EA20 * 0.017453292f * 0.0166666675f);
        func_L01_00457440(a0, D_001A4C60);
        if (d < *(f32 *)(p + 0x268)) {
            func_L01_00441FB8(a0, 5, -1);
        }
        if (*(u8 *)(a0 + 0x43) != 0xD) {
            func_003BE4F0(a0, 0xD, 0, 7);
        }
        break;
    case 6:
        func_L34_0034F9F0(a0);
        if (func_L01_00452EC8(a0)) {
            func_0039FE80(6, 0, a0);
        }
        func_003BDA38(a0, 0, &tmp);
        v = tmp;
        v.x += -*(f32 *)(a0 + 0xC0) * 0.6f;
        v.y -= 0.24f;
        v.z += 0.15f;
        a = 0x7F - *(s32 *)(p + 0x250) * 4;
        c = func_003894A0(0x95227E, 0xFF45DA, (f32)a / 127.0f) | (a << 24);
        e = func_L01_00472438(&v, &D_L34_001D66B0_0034EA20, 2, 1, c, c, 315000.0f, 315000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F36C[0];
            e[3] = func_0037E1D8(2) ? 0x44 : 0x48;
        }
        v = tmp;
        v.x += *(f32 *)(a0 + 0xC0) * 0.2f;
        func_003886E8(&w, a0 + 0xC0, 0.0500000045f);
        e = func_L01_00472438(&v, &w, 0xE, 1, 0x7F00B4FF, 0xB4FF, 147000.0f, 42000.0f, -5.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F2A8[0];
            e[3] = func_0037E1D8(2) ? 0x44 : 0x48;
        }
        e = func_L01_00472438(&v, &w, 7, 1, 0x50007EFF, 0x7EFF, 63000.004f, 21000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F404[0];
            e[3] = 0x48;
        }
        for (i = 0; i < 2; i++) {
            c = func_0037E1D8(4) ? 0x504A5053 : 0x40111111;
            c2 = c & 0xFFFFFF;
            func_003886E8(&w, a0 + 0xC0, func_0037E250(0.6f, 3.0f) * 0.0166666675f);
            s = func_0037E208(0x19, 0x23);
            e = func_L01_00472438(&v, &w, s, 1, c, c2, 105000.0f, 262500.0f, func_0037E250(-5.0f, -10.0f), 0);
            if (e != 0) {
                e[2] = *D_L34_0021F298[4];
                e[3] = func_0037E1D8(2) ? 0x44 : 0x48;
            }
        }
        if (func_00388398(p + 0x250)) {
            u8 *g = D_001A4BE0;
            if (func_00389468(*(f32 *)(a0 + 0xF8),
                              func_00388A28(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
                if (*(s32 *)(p + 0x254) != 0) {
                    if (*(u8 *)(a0 + 0x43) != 0xA) {
                        func_003BE4F0(a0, 0xA, 1, 4);
                    }
                } else {
                    if (*(u8 *)(a0 + 0x43) != 6) {
                        func_003BE4F0(a0, 6, 1, 4);
                    }
                }
                func_L01_00441FB8(a0, 7, -1);
            }
        }
        break;
    case 7:
        func_L34_0034F9F0(a0);
        *(f32 *)(a0 + 0x48) = 0.57f;
        if (func_L01_0044AF40(a0, *(s32 *)(p + 0x254) != 0 ? D_L34_001DD764 : D_L34_001DD774_0034EA20)) {
            func_L34_0034FA48(a0);
            g = D_001A4BE0;
            if (func_00389468(*(f32 *)(a0 + 0xF8),
                              func_00388A28(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) > 1.5707964f
                || fabsf(*(f32 *)(g + 0x88) - *(f32 *)(a0 + 0x18)) > 2.0f) {
                *(s32 *)(p + 0x250) = 0x32;
                if (*(s32 *)(p + 0x254) != 0) {
                    if (*(u8 *)(a0 + 0x43) != 9) {
                        func_003BE4F0(a0, 9, 0, 9);
                    }
                } else {
                    if (*(u8 *)(a0 + 0x43) != 5) {
                        func_003BE4F0(a0, 5, 0, 9);
                    }
                }
                func_L01_00441FB8(a0, 6, -1);
                break;
            }
        }
        if (*(u8 *)(a0 + 0x60) & 2) {
            if (*(u8 *)(a0 + 0x43) != 2) {
                func_003BE4F0(a0, 2, 0, 11);
            }
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 9:
        *(f32 *)(a0 + 0x48) = 0.8f;
        if (func_L01_0044AF40(a0, 28.0f) || (*(u8 *)(a0 + 0x60) & 2)) {
            if (*(u8 *)(a0 + 0x43) != 5) {
                func_003BE4F0(a0, 5, 0, 9);
            }
            func_L01_00441FB8(a0, 6, -1);
        }
        break;
    case 8:
        func_L01_00451078(a0, p + 0x190);
        if (func_L01_0044AF40(a0, 13.0f)) {
            if (*(s32 *)(p + 0x254) != 0) {
                if (*(u8 *)(a0 + 0x43) != 9) {
                    func_003BE4F0(a0, 9, 0, 9);
                }
            } else {
                if (*(u8 *)(a0 + 0x43) != 5) {
                    func_003BE4F0(a0, 5, 0, 9);
                }
            }
            *(s32 *)(p + 0x250) = 0xF;
            func_L01_00441FB8(a0, 6, -1);
        }
        break;
    case 0x42:
        if (func_L01_00452EC8(a0)) {
            func_003BD360(a0);
            return;
        }
        break;
    }
    {
        u8 *h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0x9E && *(s32 *)(h + 0x1B8) < 0x25
            && func_00388800(a0 + 0x10, h + 0x80) < 10.0f) {
            u8 st = *(u8 *)(a0 + 0x20);
            if (st != 0x42 && st != 1 && st != 10 && !func_0037E1D8(9)) {
                func_L01_00441FB8(a0, 10, -1);
            }
        }
    }
}
/* localdecomp:end func_L34_0034EA20 */
