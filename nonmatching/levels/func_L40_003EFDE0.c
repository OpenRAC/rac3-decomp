/* near miss (levels 40-53): first full draft from retail (c13, 2026-11-14), 168 aligned rows under -mvu0-use-vf0-vf2 -mno-split-addresses @ps2as (the file needs the vu0 flag and @ps2as added). Control flow, constants, gp slots (D_XXXXXXXX_sda with early .extern hints) and calls follow retail; the switch's table jtbl_003A7490 sits in .data. Main open point: our jump2 cross-jumps the identical exit tails (func_L40_0053F6E0 + func_L01_004450F0(g, 0x25, -1) + the 0x98/0x34 tail) of the 0x3E == 2, 0x539/0x2FC and case 28 exits, retail keeps three full copies; with the exits written out (no goto) it still merges. The dead compare after func_L40_003EDA10 is two identical arms around func_L40_003ED980 or a dead flag store. */
#include "common.h"

/* localdecomp:start func_L40_003EFDE0 */
#include "vu0.h"

#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

__asm__(".extern D_001DB708_sda, 4");
extern f32 D_001DB708_sda;
__asm__(".extern D_001DB6FC_sda, 4");
extern f32 D_001DB6FC_sda;
__asm__(".extern D_001DB67C_sda, 4");
extern s32 D_001DB67C_sda;
extern s32 D_001DB714_sda[3] __attribute__((section(".sdata")));
__asm__(".extern D_001DB714_sda, 8");
extern s32 D_001DB720_sda[3] __attribute__((section(".sdata")));
__asm__(".extern D_001DB720_sda, 8");
__asm__(".extern D_001DB72C_sda, 4");
extern f32 D_001DB72C_sda;
__asm__(".extern D_001DB730_sda, 4");
extern f32 D_001DB730_sda;
__asm__(".extern D_001DB68C_sda, 4");
extern f32 D_001DB68C_sda;
__asm__(".extern D_001DB710_sda, 4");
extern f32 D_001DB710_sda;
__asm__(".extern D_001DCD5C_sda, 4");
extern u8 *D_001DCD5C_sda;
extern vu0_v4 D_L40_00242960;
extern f32 D_L40_0025B9A0[];
extern u8 *D_L40_0028FD80[];
extern s32 D_001A5DF8;

extern void func_L40_003F1568(u8 *);
extern void func_L39_0066C470(s32);
extern void func_L40_0053F6E0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L40_003F1858(u8 *);
extern s32 func_L40_003F12A0(u8 *, s32);
extern void func_L40_003EDA10(u8 *, u8 *);
extern void func_L40_003ED980(u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L40_003F1660(u8 *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0044E1B8(f32, u8 *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00565750(u8 *, void *, void *, s32, s32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L40_003EEC40(f32, u8 *, void *);
extern void func_L40_003F1958(u8 *);
extern void func_L01_0045A9F0(u8 *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A898(f32, u8 *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L40_0053F018(u8 *);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, void *);
extern u8 *func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003EFC00(u8 *);
extern void func_L40_003F0E18(u8 *, s32);
extern void func_L40_003F1688(u8 *);
extern void func_L40_003EFD50(u8 *);
extern void func_L39_005F2FF8(u8 *, s32);

void func_L40_003EFDE0(u8 *g) {
    u8 *s;
    s32 id;
    vu0_v4 pos;

    if (g == 0) {
        return;
    }
    s = PTR(g, 0x68);
    id = S32(PTR(g, 0x90), 0);
    S32(PTR(g, 0x90), 0x18) = S32(s, 0x2C0);
    F32(g, 0x2C) = F32(PTR(g, 0x24), 0x24) * D_001DB708_sda;
    if (U8(s, 0x3E) == 2) {
        func_L40_003F1568(g);
        func_L39_0066C470(id);
        func_L40_0053F6E0(g);
        func_L01_004450F0(g, 0x25, -1);
        goto done;
    }
    if (S32(s, 0x264) == 0x539) {
        func_L40_003F1858(g);
        if (S32(s, 0x2FC) == 1) {
            func_L40_003F1568(g);
            func_L40_0053F6E0(g);
            func_L01_004450F0(g, 0x25, -1);
            goto done;
        }
    }
    if (func_L40_003F12A0(g, id) != 0) {
        return;
    }
    if ((u8)(U8(g, 0x20) + 3) < 2 || U8(g, 0x20) == 0x25) {
        return;
    }
    func_L40_003EDA10(g, s);
    {
        s32 neg = 0;
        if (F32(g, 0x10) < 0.0f || F32(g, 0x14) < 0.0f) {
            neg = 1;
        }
    }
    func_L40_003ED980(g, S32(s, 0x2C0));
    U8(g, 0x30) = 0x50;
    S16(g, 0x32) = 0x50;
    pos = *(vu0_v4 *)(g + 0x10);
    switch (U8(g, 0x20)) {
    case 12:
        if (func_L01_004561B8(g)) {
            func_L40_003F1660(g, 6, 0, 8);
        }
        if (S16(s, 0x234) == 1) {
            func_L01_00448728(g + 0xF8, s + 0x274, 0,
                              func_0038D160(F32(s, 0x220) - F32(g, 0x10), F32(s, 0x224) - F32(g, 0x14)),
                              0.010050001f, 0.00083770004f, 0.50265485f);
            if (func_L01_0044E1B8(D_001DB6FC_sda, g)) {
                if (S32(s, 0x264) != 0x539) {
                    vu0_v4 a;
                    vu0_v4 b;
                    vu0_v4 c;
                    vu0_v4 d;
                    s32 x;
                    s32 y;
                    func_003C2F58(g, D_001DB67C_sda, &a);
                    c = *(vu0_v4 *)(s + 0x220);
                    if (S32(s, 0x230) != 0) {
                        u8 *e = func_00382348(S32(s, 0x230));
                        if (e != 0) {
                            func_0038CF68(&d, &D_L40_00242960, F32(e, 0x10));
                            vec_add_ab(&c, &c, &d);
                        }
                    }
                    vec_sub_ab(&b, &c, &a);
                    func_0038CF68(&b, &b, 1.2f);
                    x = D_001DB714_sda[0];
                    y = D_001DB720_sda[0];
                    if (S32(s, 0x2C0) == 0) {
                        x = D_001DB714_sda[1];
                        y = D_001DB720_sda[1];
                    } else if (S32(s, 0x2C0) == 1) {
                        x = D_001DB714_sda[2];
                        y = D_001DB720_sda[2];
                    }
                    func_L39_00565750(g, &a, &b, x, y, 2.0f, D_001DB72C_sda, D_001DB730_sda);
                }
                func_L01_004450F0(g, 0xD, -1);
            }
            if (U8(s, 0x33D) == 1) {
                if (S32(s, 0x2B8) != -1 &&
                    !(func_0038CF38(g + 0x10, D_L40_0028FD80[S32(s, 0x2B8)] + S32(s, 0x280) * 16 + 0x10) > 0.2f) &&
                    U8(g, 0x43) != 6) {
                    func_003C3A10(g, 6, 0, 8);
                }
            }
        } else {
            func_L40_003F1660(g, 0, 0, 8);
        }
        if (U16(g, 0x96) >= 0x33) {
            func_L01_004450F0(g, 0xD, -1);
        }
        if (S32(s, 0x354) == 1) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            func_L40_003F1958(g);
        }
        func_L01_0045A9F0(g);
        break;
    case 13:
        if (func_L01_004561B8(g)) {
            if (S16(s, 0x234) == 1) {
                func_003C3A10(g, 7, 0, 0x11);
            } else {
                func_003C3A10(g, 0, 0, 8);
            }
        } else if (U8(g, 0x60) & 2) {
            if (U8(g, 0x42) == 7) {
                func_003C3A10(g, 5, 0, 0x11);
            } else if (U8(g, 0x42) == 5) {
                func_L01_004450F0(g, 0xC, -1);
            }
        }
        if (U16(g, 0x96) >= 0x3F) {
            func_L01_004450F0(g, 0xC, -1);
        }
        if (U8(s, 0x33D) == 1) {
            if (S32(s, 0x2B8) != -1 &&
                !(func_0038CF38(g + 0x10, D_L40_0028FD80[S32(s, 0x2B8)] + S32(s, 0x280) * 16 + 0x10) > 0.2f) &&
                U8(g, 0x43) != 6) {
                func_003C3A10(g, 6, 0, 8);
            }
        }
        if (S32(s, 0x354) == 1) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            func_L40_003F1958(g);
        }
        break;
    case 23:
        if (func_L01_004561B8(g)) {
            func_003C3A10(g, 0, 0, 0x11);
        }
        S32(s, 0xA8) |= 5;
        if (S32(s, 0x264) == 0x539) {
            if (S32(s, 0x354) != 0 && D_001DB68C_sda < func_0038CF38(g + 0x10, s + 0x2E0)) {
                s32 sv = S32(s, 0xA8);
                S32(s, 0xA8) = sv | 0x10;
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
                S32(s, 0xA8) = sv;
                if (F32(s, 0xA4) + F32(s, 0xA4) < func_0038CF38(g + 0x10, s + 0x2E0)) {
                    func_L01_00448728(g + 0xF8, s + 0x274, 0, F32(s, 0x350), 0.0025132743f, 0.0025132743f, 0.12566371f);
                }
            }
        } else {
            vu0_v4 a = *(vu0_v4 *)(g + 0x10);
            if (S32(s, 0x354) != 0) {
                s32 sv = S32(s, 0xA8);
                S32(s, 0xA8) = sv | 0x10;
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
                S32(s, 0xA8) = sv;
                if (F32(s, 0xA4) + F32(s, 0xA4) < func_0038CF38(g + 0x10, s + 0x2E0)) {
                    func_L01_00448728(g + 0xF8, s + 0x274, 0, F32(s, 0x350), 0.0025132743f, 0.0025132743f, 0.12566371f);
                }
            }
        }
        func_L40_003F1958(g);
        break;
    case 25: {
        vu0_v4 a = *(vu0_v4 *)(g + 0x10);
        if (func_L01_004561B8(g)) {
            func_003C3A10(g, 0, 0, 0x11);
            S32(s, 0x2CC) = 0;
        }
        if (S32(s, 0x264) == 0x539) {
            if (S32(s, 0x354) != 0 && D_001DB68C_sda < func_0038CF38(g + 0x10, s + 0x2E0)) {
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            } else {
                qzero(s + 0x110);
            }
        } else if (S32(s, 0x354) != 0) {
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
        } else {
            qzero(s + 0x110);
        }
        func_L40_003F1958(g);
    }
    case 1:
        if (func_L01_004561B8(g) || (U8(g, 0x42) >= 2 && U8(g, 0x43) >= 2)) {
            func_L40_003F1660(g, 0, 0, 0x11);
        }
        break;
    case 3:
        if (S32(g, 0x28) != 0 || g == D_001DCD5C_sda) {
            vu0_v4 a;
            vu0_v4 b;
            vu0_v4 c;
            s32 sv;
            f32 ang;
            func_L01_0045BD78(g, 0.002f, 0.080000006f, 0.50265485f, 0.50265485f);
            vec_sub_ba(&c, s + 0x390, g + 0x10);
            a = c;
            b = c;
            ang = func_0038D160(F32(s, 0x390) - F32(g, 0x10), F32(s, 0x394) - F32(g, 0x14));
            sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x14;
            func_L01_0045A898(ang, g, s + 0x390);
            if (F32(g, 0x18) < F32(s, 0x100) + 0.5f) {
                F32(g, 0x18) = F32(s, 0x100) + 0.5f;
            }
            func_L01_00448728(g + 0xF8, s + 0x274, 0, ang, 0.010050001f, 0.010050001f, 0.20943952f);
            if (F32(g, 0x18) < F32(s, 0x398)) {
                F32(g, 0x18) = F32(g, 0x18) + 0.20000002f;
            }
            S32(s, 0xA8) = sv;
        }
        break;
    case 22:
        if (func_L01_004561B8(g) && U8(g, 0x43) != 8) {
            func_003C3A10(g, 8, 0, 8);
        }
        if (S32(s, 0x354) != 0 && D_001DB68C_sda < func_0038CF38(g + 0x10, s + 0x2E0)) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            if (F32(s, 0xA4) + F32(s, 0xA4) < func_0038CF38(g + 0x10, s + 0x2E0)) {
                func_L01_00448728(g + 0xF8, s + 0x274, 0, F32(s, 0x350), 0.0025132743f, 0.0025132743f, 0.12566371f);
            }
        }
        if (U8(g, 0x60) & 2) {
            s32 m;
            if ((u32)(S32(s, 0x308) + 1) < 2) {
                if (S32(s, 0x29C) != 0) {
                    m = 0x17;
                } else {
                    m = 1;
                }
            } else {
                m = 0xC;
            }
            func_L01_004450F0(g, m, -1);
        }
        break;
    case 28:
        if (func_L01_004561B8(g)) {
            vu0_v4 a;
            vu0_v4 b;
            if (U8(g, 0x43) != 9) {
                func_003C3A10(g, 9, 0, 8);
            }
            a = *(vu0_v4 *)(g + 0x10);
            b = a;
            b.z += 1.0f;
            a.z -= 4.0f;
            if (func_003D3CB0(&b, &a, 0, g, 0)) {
                F32(s, 0x260) = D_L40_0025B9A0[2];
            } else if (S32(s, 0x2C0) == -1) {
                F32(s, 0x260) = F32(g, 0x18);
            } else {
                F32(s, 0x260) = a.z;
            }
            if (func_L40_0053F018(g)) {
                s32 *r = func_L39_0066C2B8();
                if (r == 0) {
                    return;
                }
                *r = func_L39_0066C280(2, id, D_001A5DF8, id, r);
            }
        }
        if (F32(s, 0x260) < F32(g, 0x18)) {
            f32 d = D_001DB710_sda * 0.020000001f;
            if (d < F32(g, 0x18) - F32(s, 0x260)) {
                F32(g, 0x18) = F32(g, 0x18) - d;
            }
        }
        if (U8(g, 0x60) & 2) {
            u8 *o;
            func_L40_003F1568(g);
            func_L40_0053F6E0(g);
            o = func_L01_003303B8(g + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0,
                                  0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (o != 0) {
                PTR(o, 0xB8) = g;
            }
            func_L01_004450F0(g, 0x25, -1);
            goto done;
        }
        break;
    case 24:
        func_L40_003EFC00(g);
        break;
    }
    if (U8(s, 0x33D) == 1 && S32(s, 0x2B8) == -1) {
        func_L40_003F0E18(g, id);
    }
    func_L40_003F1688(g);
    if ((F32(g, 0x10) < 10.0f || F32(g, 0x14) < 10.0f || F32(g, 0x18) < 10.0f) && U8(g, 0x20) != 0x1C) {
        func_L39_0066C470(id);
    }
    if (S32(s, 0x264) != 0x539) {
        func_L40_003EFD50(g);
        return;
    }
done:
    S32(g, 0x98) = 0;
    U16(g, 0x34) = (U16(g, 0x34) | 0x41) & ~0x1000;
    func_L39_005F2FF8(g, 1);
}
/* localdecomp:end func_L40_003EFDE0 */
