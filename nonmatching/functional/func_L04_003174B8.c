/* functional: medium. Written from the PAL asm only (no draft); every branch, offset, constant and callee argument followed block by block. Unsure: (1) the call through *(func_L01_0043B548(0x19E1, 0x6C) + 0x4C) is made with no argument, as retail sets none (a0 is whatever the lookup left; the callee is assumed to ignore it, gate must cover); (2) func_L01_00446BC8 argument types (float 10000.0f in f12, ints in a0..a3) inferred from registers. Block with D_001DF940 == 0x28 and the s->f38 search/vtable call were read twice against the asm. */
#include "common.h"

typedef struct S_L04_003174B8 {
    s32 f00;
    s32 pad04[4];
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 pad24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    u8 *f38;
    s32 pad3C[2];
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_L04_003174B8;

extern u8 D_001A4C60[];
extern u8 D_001A7C10[];
extern u8 D_001A7E18[];
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u8 D_001BBC40[];
extern u8 D_001426E0[];
extern u32 D_001A7DD0;
extern s32 D_00143964;
extern s32 D_001D4C38;
__asm__(".extern D_001D4C38, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 *D_001DFD9C;
extern u8 *D_001DFDA8;
extern s32 D_001DFDD8;
extern s32 D_001DF940;
extern s32 D_001F2AC0;
extern u16 *D_0021C9A0[];

extern s32 func_00382380(void *, s32, s32);
extern void func_0039EF28(void);
extern s32 func_003A2B68(s32, s32);
extern void func_003A1798(void);
extern s32 func_L01_00513EF0(void);
extern void func_L01_0041A5B0(s32, s32);
extern s32 *func_L01_0043B568(s32, s32, s32);
extern s32 *func_L01_0043B548(s32, s32);
extern void func_L01_0043B510(s32);
extern s32 func_L01_00456250(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00446BC8(f32, void *, void *, s32, void *);
extern void func_L01_0045F1E8(s32, s32);

void func_L04_003174B8(u8 *a) {
    S_L04_003174B8 *s = *(S_L04_003174B8 **)(a + 0x68);
    s32 r;
    s32 x;
    s32 t;

    if (a[0x20] == 0) {
        a[0x30] = 0xFF;
        a[0x20] = 1;
        s->f18 = D_001426E0[0xF];
        s->f38 = 0;
        s->f1C = D_001426E0[0x11];
        s->f50 = 0;
    } else if (a[0x20] == 1) {
        if (func_00382380(D_001A4C60, s->f00, 0)) {
            x = (D_001D4C38 * 5 + 2) / 6 - (s32)D_001A7DD0;
            if (0x2BF20u < (u32)x) {
                if (func_L01_00513EF0() == 0) {
                    if (*(s32 *)(D_001A7E18 + 0x134) >= 0) func_L01_0041A5B0(0xB76, 0x19);
                }
            }
        }
        if (func_L01_00513EF0() == 0) {
            s32 *o = func_L01_0043B548(0x19E1, 0x6C);
            if (((s32 (*)(void))*(u32 *)((u8 *)o + 0x4C))() != 0) {
                s32 go = 1;
                if (*(u16 *)(D_001A7C10 + 0x1BC) != 0) {
                    x = (D_001D4C38 * 5 + 2) / 6 - *(s32 *)(D_001A7C10 + 0x1C0);
                    if (!(0xEA60u < (u32)x)) go = 0;
                }
                if (go) {
                    s32 idA, idB, arg;
                    if (*(u16 *)(D_001A7E18 + 0x9A08) == 0) {
                        idA = 0xCD6; idB = 0xCD7; arg = 0x7F;
                    } else {
                        idA = 0xCD7; idB = 0xCD6; arg = 0x80;
                    }
                    if (*(s32 *)(D_001A7E18 + idB * 12 + 8) >= 0) {
                        func_L01_0041A5B0(idA, arg);
                        if (*(u16 *)(D_001A7E18 + idA * 12) == 0) *(u16 *)(D_001A7E18 + idA * 12) = 1;
                        *(u16 *)(D_001A7E18 + idB * 12) = 0;
                        if (*(u16 *)(D_001A7C10 + 0x1BC) <= 0xFFFE) {
                            *(u16 *)(D_001A7C10 + 0x1BC) = *(u16 *)(D_001A7C10 + 0x1BC) + 1;
                        }
                        x = (D_001D4C38 * 5 + 2) / 6;
                        if (*(u32 *)(D_001A7C10 + 0x1C0) < (u32)x) *(s32 *)(D_001A7C10 + 0x1C0) = x;
                        *(u32 *)(D_001A7C10 + 0x1C4) |= (1 << D_001D545C) | 0x80000000;
                    }
                }
            }
        }
        if (s->f1C == 0) {
            if (D_001BBC40[s->f14 + D_001D545C * 16] & 0x80) {
                D_001426E0[0x11] = 1;
                func_0039EF28();
                s->f1C = 1;
            }
        }
        if (func_L01_00513EF0() == 0) {
            if (*(u16 *)(D_001A7E18 + 0x97C8) == 0) {
                if (func_L01_00456250(D_001DFD9C + (s->f54 << 8)) != 0) {
                    if (*(u16 *)(D_001A7E18 + 0x97C8) == 0) *(u16 *)(D_001A7E18 + 0x97C8) = 1;
                } else if (func_00382380(D_001A4C60, s->f20, 0)) {
                    x = (D_001D4C38 * 5 + 2) / 6 - *(s32 *)(D_001A7E18 + 0x4F0);
                    if (!((u32)x < 0x5DD) || *(s32 *)(D_001A7E18 + 0x4F0) == 0) func_L01_0041A5B0(0xCA6, 0x69);
                    if (*(s32 *)(D_001A7E18 + 0x4F4) >= 0) func_L01_0041A5B0(0xCA6, 0x69);
                }
            }
        } else {
            if (*(u16 *)(D_001A7E18 + 0x11EC8) == 0) {
                if (func_L01_00456250(D_001DFD9C + (s->f54 << 8)) != 0) {
                    if (*(u16 *)(D_001A7E18 + 0x11EC8) == 0) *(u16 *)(D_001A7E18 + 0x11EC8) = 1;
                } else if (func_00382380(D_001A4C60, s->f20, 0)) {
                    x = (D_001D4C38 * 5 + 2) / 6 - *(s32 *)(D_001A7E18 + 0x100C);
                    if (!((u32)x < 0x5DD) || *(s32 *)(D_001A7E18 + 0x100C) == 0) func_L01_0041A5B0(0x17E6, 0x156);
                    if (*(s32 *)(D_001A7E18 + 0x1010) >= 0) func_L01_0041A5B0(0x17E6, 0x156);
                }
            }
        }
        if (func_L01_00513EF0() == 0) {
            if (*(u16 *)(D_001A7E18 + 0x7B48) == 0) {
                if (func_L01_00456250(D_001DFD9C + (s->f58 << 8)) != 0) {
                    if (*(u16 *)(D_001A7E18 + 0x7B48) == 0) *(u16 *)(D_001A7E18 + 0x7B48) = 1;
                } else if (func_00382380(D_001A4C60, s->f28, 0)) {
                    if (*(s32 *)(D_001A7E18 + 0xC8) >= 0) func_L01_0041A5B0(0xA46, 0x10);
                }
            }
        } else {
            if (*(u16 *)(D_001A7E18 + 0x11ED4) == 0) {
                if (func_L01_00456250(D_001DFD9C + (s->f58 << 8)) != 0) {
                    if (*(u16 *)(D_001A7E18 + 0x11ED4) == 0) *(u16 *)(D_001A7E18 + 0x11ED4) = 1;
                } else if (func_00382380(D_001A4C60, s->f28, 0)) {
                    if (*(s32 *)(D_001A7E18 + 0x101C) >= 0) func_L01_0041A5B0(0x17E7, 0x157);
                }
            }
        }
        if (*(u16 *)(D_001A7E18 + 0x8A90) == 0) {
            if (func_00382380(D_001A4C60, s->f2C, 0)) {
                func_L01_0041A5B0(0xB8C, 0x2F);
                t = D_001D4C38;
                if (*(u16 *)(D_001A7E18 + 0x8A90) == 0) {
                    *(u16 *)(D_001A7E18 + 0x8A90) = 1;
                    t = D_001D4C38;
                }
                x = (t * 5 + 2) / 6;
                if (*(u32 *)(D_001A7E18 + 0xE20) < (u32)x) *(s32 *)(D_001A7E18 + 0xE20) = x;
            }
        }
        t = D_001DF940;
        if (*(u16 *)(D_001A7E18 + 0x10788) == 0) {
            if (func_L01_00456250(D_001DFD9C + (s->f30 << 8)) != 0) {
                if (*(u16 *)(D_001A7E18 + 0x10788) == 0) *(u16 *)(D_001A7E18 + 0x10788) = 1;
                t = D_001DF940;
            } else if (func_00382380(D_001A4C60, s->f2C, 0)) {
                if (*(s32 *)(D_001A4C60 + 0x11A8) == 0x12) {
                    x = (D_001D4C38 * 5 + 2) / 6 - *(s32 *)(D_001A7E18 + 0xE20);
                    if (!((u32)x < 0xBB9) || *(s32 *)(D_001A7E18 + 0xE20) == 0) func_L01_0041A5B0(0x15F6, 0x12D);
                    t = D_001DF940;
                } else {
                    t = D_001DF940;
                }
            } else {
                t = D_001DF940;
            }
        }
        if (D_001DF940 == 0x28) {
            if (*(u16 *)(D_001A7E18 + 0x8A6C) == 0) {
                if (D_00143964 != 0) {
                    func_L01_0041A5B0(0xB89, 0x2C);
                    if (*(u16 *)(D_001A7E18 + 0x8A6C) == 0) *(u16 *)(D_001A7E18 + 0x8A6C) = 1;
                }
            }
        }
        if (*(u16 *)(D_001A7E18 + 0x8A84) == 0) {
            u8 *p = s->f38;
            if (p == 0) {
                if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x37) {
                    p = D_001DFDA8;
                    while (p != 0) {
                        if (func_L01_0043B568(*(s16 *)(p + 0xAA), 6, 4) != 0) {
                            if (func_L01_0040E548(p + 0x10, D_001A4C60) < 9.0f) {
                                s->f38 = p;
                                break;
                            }
                        }
                        p = *(u8 **)(p + 0x28);
                    }
                    p = s->f38;
                }
            }
            if (p != 0) {
                if (*(s32 *)(D_001A4BE0 + 0x25C4) != 0x37) {
                    s32 *q = func_L01_0043B568(*(s16 *)(p + 0xAA), 6, 4);
                    if (q == 0) {
                        s->f38 = 0;
                    } else {
                        f32 res = ((f32 (*)(u8 *))*(u32 *)q)(s->f38);
                        if (res == 1.0f) {
                            s->f38 = 0;
                        } else {
                            s->f34 = s->f34 + 1;
                            if (s->f34 == 3 || s->f34 == 6) func_L01_0041A5B0(0xB8B, 0x2E);
                            s->f38 = 0;
                        }
                    }
                }
            }
        }
        if (s->f44 == -1) {
            if (*(u16 *)(D_001A7E18 + 0x10A28) == 0) {
                if (func_00382380(D_001A4C60, s->f48, 0)) {
                    if (!(*(s32 *)(D_001A7E18 + 0xEC0) & (1 << D_001D545C))) func_L01_0041A5B0(0x162E, 0x13A);
                    if (*(u16 *)(D_001A7E18 + 0x10A28) == 0) *(u16 *)(D_001A7E18 + 0x10A28) = 1;
                }
            }
        } else if (*(u16 *)(D_001A7E18 + 0x10A28) == 0) {
            if (s->f50 != 0) {
                if (*(s16 *)(D_001CCFD0 + 0x76) == 0 && *(s16 *)(D_001CCFD0 + 0x9E) == 3 &&
                    *(s16 *)(D_001CCFD0 + 0x98) < 0x1B58) {
                    func_003A1798();
                    func_L01_0043B510(s->f4C);
                    s->f50 = 0;
                }
            } else if (!(D_001BBC40[s->f4C + D_001D545C * 16] & 0x80) &&
                       *(s32 *)(D_001CCFD0 + 0x6C) == 0 && *(s32 *)(D_001CCFD0 + 0x24) == -1 &&
                       *(s32 *)(D_001CCFD0 + 0x94) == 0) {
                if (func_00382380(D_001A4C60, s->f48, 0)) {
                    func_003A2B68((s->f44 & 0x3FFF) + 0x7D0, 0);
                    s->f50 = 1;
                    if (*(u16 *)(D_001A7E18 + 0x10A28) == 0) *(u16 *)(D_001A7E18 + 0x10A28) = 1;
                }
            }
        }
        if (func_00382380(D_001A4C60, s->f68, 0) == 0) {
            s->f5C = 0;
        } else if (s->f5C == 0) {
            u16 *pp = D_0021C9A0[s->f70];
            for (;;) {
                s32 sel = s->f70;
                u8 *e;
                if ((sel & 0xFF) == 0xFF || D_001DFDD8 < sel || pp == 0) {
                    s->f5C = 1;
                    break;
                }
                if (!(*(s16 *)((u8 *)pp - 2) >= 0 || pp == D_0021C9A0[sel])) {
                    s->f5C = 1;
                    break;
                }
                e = D_001DFD9C + ((*pp & 0x7FFF) << 8);
                if (e == 0) {
                    s->f5C = 1;
                    break;
                }
                if (func_00382380(e + 0x10, s->f6C, 0)) func_L01_00446BC8(10000.0f, e, a, 0x10000, D_001A4C60);
                pp++;
            }
        }
        if (func_00382380(D_001A4C60, s->f74, 0)) {
            if (!(*(u32 *)(D_001A7E18 + 0x974) & (1 << D_001D545C))) func_L01_0041A5B0(0x105A, 0xC9);
        }
    }
    if (a[0xBC] == 0) {
        if (D_001F2AC0 == 1) {
            func_L01_0045F1E8(s->f64, -1);
            a[0xBC] = 1;
        }
    } else if (a[0xBC] == 1) {
        if (D_001F2AC0 != 1) {
            func_L01_0045F1E8(s->f60, -1);
            a[0xBC] = 0;
        }
    }
}
