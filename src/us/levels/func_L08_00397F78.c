#include "common.h"

/* NTSC-U counterpart of func_L08_00399978 (src/levels/08_aquatos/L08_00399950.c) */
#include "vu0.h"

/* localdecomp:start func_L08_00397F78 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L08_001E13B0_00397F78, 4");
__asm__(".extern D_L08_001E13B4_00397F78, 4");
__asm__(".extern D_L08_001E13B8_00397F78, 4");
__asm__(".extern D_L08_001E13BC_00397F78, 4");
__asm__(".extern D_L08_001DDFF0_00397F78, 4");
__asm__(".extern D_L08_001DE000_00397F78, 8");
__asm__(".extern D_L08_001DE010_00397F78, 8");
__asm__(".extern D_L08_001DE020_00397F78, 1");

extern s32 D_L08_001D6694_00397F78;
extern s32 D_L08_001E13B0_00397F78;
extern s32 D_L08_001E13B4_00397F78;
extern s32 D_L08_001E13B8_00397F78;
extern s32 D_L08_001E13BC_00397F78;
extern f32 D_L08_001DDFF0_00397F78;
extern s32 D_L08_001DE000_00397F78[2];
extern s32 D_L08_001DE010_00397F78[2];
extern u8 D_L08_001DE020_00397F78;
extern u8 *D_L08_001DF21C_00397F78;
extern u8 D_L08_001D9A60[] __attribute__((section(".sdata")));
extern u8 D_L08_001E1D40_00397F78[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 D_00142660[];

extern void func_L08_00399238(u8 *);
extern s32 func_L01_004B6C68(void);
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_L01_00452F18(u8 *);
extern void func_L01_003358F8(u8 *, s32);
extern s32 func_L01_00335880(u8 *, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_004A6DF8(u8 *, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_00442050(u8 *, s32);
extern void func_L01_0044CB08(u8 *, s32, s32, s32);
extern s32 func_L01_004576E8(u8 *);
extern void func_L01_00458A70(f32, f32, f32, f32, u8 *);
extern s32 func_L01_00458F98(f32, f32, f32, u8 *);
extern s32 func_L01_0044AF40(f32, u8 *);
extern f32 func_L01_00445758(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_004539A8(u8 *, s32, f32, f32, void *, s32, s32, s32, f32, s32, s32, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_L03_003B0340(u8 *);
extern s32 func_L08_003C1A00(u8 *);


void func_L08_00397F78(u8 *a) {
    vu0_v4 sp10;
    vu0_v4 sp20;
    u8 *v;
    f32 r;
    s32 s17;
    s32 one;

    func_L08_00399238(a);
    v = (((struct { u8 _p[0x68]; u8 * v; } *)(a))->v);
    if (D_L08_001D6694_00397F78 == 2) {
        (((struct { u8 _p[0x31]; u8 v; } *)(a))->v) = 0;
        (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= 1;
        return;
    }
    if (func_L01_004B6C68() == 0) {
        (((struct { u8 _p[0x31]; u8 v; } *)(a))->v) = 1;
        (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) &= 0xFFFE;
    }
    if (D_L08_001E13B4_00397F78 == 0) {
        D_L08_001E13B4_00397F78 = 1;
        D_L08_001E13B0_00397F78 = (((struct { u8 _p[0x2850]; s32 v; } *)(D_001A4BE0))->v);
    }
    if (D_L08_001E13BC_00397F78 == 0) {
        D_L08_001E13BC_00397F78 = 1;
        D_L08_001E13B8_00397F78 = D_00142660[2];
    }

    switch ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v)) {
    case 0:
        (((struct { u8 _p[0x98]; s32 v; } *)(a))->v) = 0;
        (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) = ((((struct { u8 _p[0x34]; u16 v; } *)(a))->v) | 0x43) & 0xEFFF;
        func_L01_004A6DF8(a, 1);
        func_L01_00441FB8(a, 1, -1);
        break;
    case 2:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 0, 0, 0);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 0, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        (((struct { u8 _p[0x3CC]; s32 v; } *)(v))->v) = 2;
        func_L01_004576E8(a);
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 1, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        (((struct { u8 _p[0x3CC]; s32 v; } *)(v))->v) = 0;
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        func_L01_004576E8(a);
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 2, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        (((struct { u8 _p[0x3CC]; s32 v; } *)(v))->v) = 0;
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        func_L01_004576E8(a);
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 0xC, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        (((struct { u8 _p[0x280]; vu0_q v; } *)(v))->v) = (((struct { u8 _p[0x4A0]; vu0_q v; } *)(v))->v);
        func_L01_004576E8(a);
        if (((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00458A70(0.0019444444915279746f, 0.0416666679084301f, 0.013962634839117527f, 1.6755162477493286f, a);
            func_003BE4F0(a, 3, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        {
            f32 q = (((struct { u8 _p[0x240]; f32 v; } *)(v))->v) / (((struct { u8 _p[0x1B8]; f32 v; } *)(v))->v);
            if (q < 0.7f) {
                q = 0.7f;
            }
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = q;
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00458A70(0.004444444552063942f, 0.10833334177732468f, 0.013962634839117527f, 1.6755162477493286f, a);
            func_003BE4F0(a, 4, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        {
            f32 q = (((struct { u8 _p[0x240]; f32 v; } *)(v))->v) / (((struct { u8 _p[0x1B8]; f32 v; } *)(v))->v);
            if (q < 0.7f) {
                q = 0.7f;
            }
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = q;
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 9:
    case 15: {
        u8 *rot;
        u8 *w;
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00458A70(0.004444444552063942f, 0.10833334177732468f, 0.0034906587097793818f, 0.41887906193733215f, a);
            func_003BE4F0(a, 3, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        rot = a + 0xF8;
        w = (((struct { u8 _p[0x68]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v)))->v);
        r = func_00388A28((((struct { u8 _p[0x4A0]; f32 v; } *)(v))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x4A4]; f32 v; } *)(v))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v));
        func_L01_00445758(rot, r, (((struct { u8 _p[0x1A4]; f32 v; } *)(v))->v), (((struct { u8 _p[0x1A8]; f32 v; } *)(v))->v), (((struct { u8 _p[0x1AC]; f32 v; } *)(v))->v), w + 0x74, 0);
        (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = (((struct { u8 _p[0x74]; f32 v; } *)(w))->v) / (((struct { u8 _p[0x1AC]; f32 v; } *)(v))->v) * D_L08_001DDFF0_00397F78;
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        (((struct { u8 _p[0x280]; vu0_q v; } *)(v))->v) = (((struct { u8 _p[0x4A0]; vu0_q v; } *)(v))->v);
        if ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v) == 9 && (((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
            break;
        }
        if ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v) == 0xF) {
            r = func_00388A28((((struct { u8 _p[0x4A0]; f32 v; } *)(v))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x4A4]; f32 v; } *)(v))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v));
            if (func_00389468((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), r) <= 0.034906585f) {
                func_L01_00441FB8(a, 0x10, -1);
            }
        }
        break;
    }
    case 10:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00458A70(0.004444444552063942f, 0.10833334177732468f, 0.013962634839117527f, 1.6755162477493286f, a);
            func_003BE4F0(a, 0xE, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
            func_003886E8(v + 0x230, a + 0xC0, 0.13333334028720856f);
            (((struct { u8 _p[0x268]; s32 v; } *)(v))->v) = -1;
            qzero(v + 0x1E0);
            (((struct { u8 _p[0x238]; f32 v; } *)(v))->v) = 0.8000000715255737f;
            (((struct { u8 _p[0x220]; s32 v; } *)(v))->v) = 0;
            (((struct { u8 _p[0x218]; s32 v; } *)(v))->v) = 0;
            (((struct { u8 _p[0x21C]; s32 v; } *)(v))->v) = 0;
        }
        r = (((struct { u8 _p[0x238]; f32 v; } *)(v))->v) - 0.013333333656191826f;
        (((struct { u8 _p[0x230]; f32 v; } *)(v))->v) = (((struct { u8 _p[0x230]; f32 v; } *)(v))->v) * 0.99000001f;
        (((struct { u8 _p[0x234]; f32 v; } *)(v))->v) = (((struct { u8 _p[0x234]; f32 v; } *)(v))->v) * 0.99000001f;
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
        (((struct { u8 _p[0x3CC]; s32 v; } *)(v))->v) = 1;
        (((struct { u8 _p[0x238]; f32 v; } *)(v))->v) = r;
        if (r < -0.6666666865348816f) {
            (((struct { u8 _p[0x238]; f32 v; } *)(v))->v) = -0.6666666865348816f;
        }
        if (func_L01_00458F98(11.0f, 18.0f, 28.0f, a) != 0) {
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = 1.0f;
            func_L01_004576E8(a);
            if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0) {
                func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
            }
        }
        break;
    case 11:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00458A70(0.004444444552063942f, 0.10833334177732468f, 0.0034906587097793818f, 0.41887906193733215f, a);
            D_L08_001DE020_00397F78 = 0;
            func_L01_00442050(a, 0);
        }
        func_L01_004539A8(a, -1, 10.0f, 10.0f, 0, 0, 1, 1, 1.0f, 3, 0, 0, 0);
        func_L01_004576E8(a);
        s17 = (((struct { u8 _p[0xBC]; u8 v; } *)(a))->v);
        if (s17 == 0) {
            if (func_L01_00452F18(a) != 0 || ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
                if (func_0037E1D8(5) != 0) {
                    func_003BE4F0(a, 0, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
                } else {
                    func_003BE4F0(a, 1, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
                }
            }
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 1;
            (((struct { u8 _p[0x3CC]; s32 v; } *)(v))->v) = 2;
            if ((((struct { u8 _p[0xC4]; s16 v; } *)(v))->v) == 1) {
                func_L01_00442050(a, 2);
            } else {
                r = func_00388A28((((struct { u8 _p[0x80]; f32 v; } *)(D_001A4BE0))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x84]; f32 v; } *)(D_001A4BE0))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v));
                if (1.3089969f < func_00389468((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), r)) {
                    func_L01_00442050(a, 1);
                }
            }
            if (func_00388800(a + 0x10, D_001A4C60) < 10.0f) {
                if (D_L08_001DE020_00397F78 == 0) {
                    u8 *h = v + 0x5EC;
                    func_L01_00335880(a, *(s32 *)(h + func_0037E1D8(5) * 4));
                    D_L08_001DE020_00397F78 = 1;
                }
            }
            if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0) {
                func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
            }
        } else if (one = 1, s17 == one) {
            u8 *u = (((struct { u8 _p[0x68]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v)))->v);
            u8 *hero;
            u8 *rot;
            if (func_L01_00452F18(a) != 0) {
                func_003BE4F0(a, 3, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
            }
            hero = D_001A4BE0;
            rot = a + 0xF8;
            r = func_00388A28((((struct { u8 _p[0x80]; f32 v; } *)(hero))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x84]; f32 v; } *)(hero))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v));
            func_L01_00445758(rot, r, (((struct { u8 _p[0x1A4]; f32 v; } *)(v))->v), (((struct { u8 _p[0x1A8]; f32 v; } *)(v))->v), (((struct { u8 _p[0x1AC]; f32 v; } *)(v))->v), u + 0x74, 0);
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = (((struct { u8 _p[0x74]; f32 v; } *)(u))->v) / (((struct { u8 _p[0x1AC]; f32 v; } *)(v))->v) * D_L08_001DDFF0_00397F78;
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = s17;
            (((struct { u8 _p[0x280]; vu0_q v; } *)(v))->v) = (((struct { u8 _p[0x80]; vu0_q v; } *)(hero))->v);
            if ((((struct { u8 _p[0xC4]; s16 v; } *)(v))->v) == s17) {
                func_L01_00442050(a, 2);
            } else {
                r = func_00388A28((((struct { u8 _p[0x80]; f32 v; } *)(hero))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x84]; f32 v; } *)(hero))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v));
                if (func_00389468((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), r) <= 0.034906585f) {
                    func_L01_00442050(a, 0);
                }
            }
            if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0) {
                func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
            }
        } else if (s17 == 2) {
            if (func_L01_00452F18(a) != 0) {
                func_003BE4F0(a, 5, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
            }
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
            if (((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
                func_L01_00442050(a, 3);
            }
        } else if (s17 == 3) {
            if (func_L01_00452F18(a) != 0) {
                (((struct { u8 _p[0x5D4]; s16 v; } *)(v))->v) = 0x3C;
                func_003BE4F0(a, 6, 0, 0);
            }
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
            if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 || ((((struct { u8 _p[0xC4]; s16 v; } *)(v))->v) != one && func_003883C8(v + 0x5D4) != 0)) {
                func_L01_00442050(a, 4);
            } else if ((((struct { u8 _p[0xC4]; s16 v; } *)(v))->v) == one) {
                (((struct { u8 _p[0x5D4]; s16 v; } *)(v))->v) = 0x3C;
            }
        } else if (s17 == 4) {
            if (func_L01_00452F18(a) != 0) {
                func_003BE4F0(a, 7, 0, 0);
            }
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
            if (func_L01_0044AF40(28.0f, a) != 0) {
                if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0) {
                    func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
                } else {
                    func_L01_00442050(a, 0);
                }
            }
        }
        break;
    case 12:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 5, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if (((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            func_L01_00441FB8(a, 0xD, -1);
        }
        break;
    case 13:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 6, 0, 0);
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0) {
            func_L01_00441FB8(a, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 7, 0, 0);
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if ((((struct { u8 _p[0x490]; u8 v; } *)(v))->v) != 0 && func_L01_0044AF40(28.0f, a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    case 16: {
        u8 *w;
        f32 f20;
        s32 idx;
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_L01_00335880((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), func_0037E1D8(2) == 0 ? (((struct { u8 _p[0x5E8]; s32 v; } *)(v))->v) : (((struct { u8 _p[0x5E4]; s32 v; } *)(v))->v));
            (((struct { u8 _p[0x5D4]; s16 v; } *)(v))->v) = (((struct { u8 _p[0x47C]; u16 v; } *)(v))->v);
            (((struct { u8 _p[0x5D8]; f32 v; } *)(v))->v) = 1.0f / (f32)(((struct { u8 _p[0x47C]; s16 v; } *)(v))->v);
            func_003BE4F0(a, 9, 0, (((struct { u8 _p[0x47C]; s32 v; } *)(v))->v));
        }
        idx = (((struct { u8 _p[0x60]; s32 v; } *)((((struct { u8 _p[0x68]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v)))->v)))->v)))->v);
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        (((struct { u8 _p[0x530]; vu0_q v; } *)(v))->v) = *(vu0_q *)D_L08_001DE000_00397F78;
        w = D_L08_001DF21C_00397F78 + (idx << 8);
        if (func_003883C8(v + 0x5D4) == 0) {
            f20 = (f32)(((struct { u8 _p[0x5D4]; s16 v; } *)(v))->v) * (((struct { u8 _p[0x5D8]; f32 v; } *)(v))->v);
            func_00389158(&sp10, D_L08_001DE010_00397F78, D_L08_001D9A60, (((struct { u8 _p[0xF8]; f32 v; } *)(w))->v));
            vec_add_ba(&sp10, w + 0x10, &sp10);
            *(vu0_q *)&sp20 = (((struct { u8 _p[0x10]; vu0_q v; } *)(a))->v);
            func_003BEB58(a + 0x10, &sp10, &sp20, f20);
            (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v) = func_003BEB48(func_00389380((((struct { u8 _p[0xF8]; f32 v; } *)(w))->v), 3.1415927f), (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), f20);
        } else {
            func_00389158(&sp10, D_L08_001DE010_00397F78, D_L08_001D9A60, (((struct { u8 _p[0xF8]; f32 v; } *)(w))->v));
            vec_add_ab(&sp10, w + 0x10, &sp10);
            (((struct { u8 _p[0x10]; vu0_q v; } *)(a))->v) = *(vu0_q *)&sp10;
            (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v) = func_00389380((((struct { u8 _p[0xF8]; f32 v; } *)(w))->v), 3.1415927f);
        }
        if (((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) != 0) {
            s32 j = (((struct { u8 _p[0x60]; s32 v; } *)((((struct { u8 _p[0x68]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v)))->v)))->v)))->v);
            if (j != -1) {
                func_L03_003B0340(D_L08_001DF21C_00397F78 + (j << 8));
            }
            func_L01_00441FB8(a, 0x11, -1);
        }
        break;
    }
    case 17: {
        s32 idx;
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 0xA, 0, 0);
        }
        {
            u8 *m = (((struct { u8 _p[0x68]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v)))->v)))->v);
            (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
            (((struct { u8 _p[0x530]; vu0_q v; } *)(v))->v) = *(vu0_q *)D_L08_001DE000_00397F78;
            idx = (((struct { u8 _p[0x60]; s32 v; } *)(m))->v);
        }
        if (idx != -1) {
            if (func_L08_003C1A00(D_L08_001DF21C_00397F78 + (idx << 8)) != 0) {
                func_L01_00441FB8(a, 0x12, -1);
            }
        }
        break;
    }
    case 18:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 0);
            func_003BE4F0(a, 0xB, 0, 3);
        }
        (((struct { u8 _p[0x3AC]; s32 v; } *)(v))->v) = 0;
        if (func_L01_0044AF40(26.0f, a) != 0) {
            func_L01_003358F8((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), 1);
        }
        break;
    }

    if ((((struct { u8 _p[0x31]; u8 v; } *)(a))->v) != 0) {
        if (func_L01_0040C018(D_L08_001E1D40_00397F78, a + 0x10) < 576.0f) {
            func_L01_00444188(a);
            (((struct { u8 _p[0x6F]; u8 v; } *)(a))->v) = 0x16;
        }
    }
    if ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v) >= 2) {
        if (func_003883C8(v + 0x5D6) != 0) {
            if (D_L08_001E13B8_00397F78 == D_00142660[2]) {
                if ((f32)D_L08_001E13B8_00397F78 * 0.1f <= (f32)(D_L08_001E13B0_00397F78 - (((struct { u8 _p[0x2850]; s32 v; } *)(D_001A4BE0))->v))) {
                    func_L01_00335880((((struct { u8 _p[0xB8]; u8 * v; } *)(a))->v), func_0037E1D8(2) == 0 ? (((struct { u8 _p[0x5DC]; s32 v; } *)(v))->v) : (((struct { u8 _p[0x5E0]; s32 v; } *)(v))->v));
                    (((struct { u8 _p[0x5D6]; s16 v; } *)(v))->v) = 0x708;
                }
            }
        }
    }
    D_L08_001E13B0_00397F78 = (((struct { u8 _p[0x2850]; s32 v; } *)(D_001A4BE0))->v);
    D_L08_001E13B8_00397F78 = D_00142660[2];
    (((struct { u8 _p[0xF0]; s32 v; } *)(a))->v) = 0;
    (((struct { u8 _p[0xF4]; s32 v; } *)(a))->v) = 0;
    if ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v) >= 2) {
        func_L01_0044CB08(a, (((struct { u8 _p[0x5D0]; s32 v; } *)(v))->v), 0, 2);
    }
}
/* localdecomp:end func_L08_00397F78 */
