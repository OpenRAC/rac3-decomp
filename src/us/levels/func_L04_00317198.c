#include "common.h"

/* NTSC-U counterpart of func_L04_003174B8 (src/levels/04_marcadia/L04_003174B8.c) */
/* localdecomp:start func_L04_00317198 */
typedef struct {
    s32 w00;
    s32 w04, w08, w0C, w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    u8 *w38;
    s32 w3C, w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    s32 w60;
    s32 w64;
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
} S_003174B8;

typedef struct {
    u16 h0;
    u16 h2;
    u32 w4;
    u32 w8;
} H_003174B8;

typedef struct {
    u8 pad0[0x1BC];
    u16 h1BC;
    u8 pad1BE[2];
    u32 w1C0;
    u32 w1C4;
} T7C10_003174B8;

typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x6C - 0x28];
    s32 w6C;
    u8 pad70[0x76 - 0x70];
    s16 h76;
    u8 pad78[0x94 - 0x78];
    s32 w94;
    s16 h98;
    u8 pad9A[0x9E - 0x9A];
    s16 h9E;
} TCFD0_003174B8;

extern u8 D_001426E0[];
extern s32 D_00143964 __attribute__((section(".data")));
typedef struct {
    u8 pad0[0x25C4];
    s32 w25C4;
} T4BE0_003174B8;
extern T4BE0_003174B8 D_001A4BE0;
extern u8 D_001A4C60[];
extern T7C10_003174B8 D_001A7C10;
typedef struct { H_003174B8 s[0x1800]; } HS_003174B8;
extern HS_003174B8 D_001A7E18;
extern u8 D_001BBC40[];
extern TCFD0_003174B8 D_001CCFD0;
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern s32 D_L04_001DF9C0;
extern u8 *D_L04_001DFE1C;
extern u8 *D_L04_001DFE28;
extern s32 D_L04_001DFE58;
extern s32 D_L04_001F2B40 __attribute__((section(".data")));
extern u16 *D_L04_0021CA20[];

extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_0050FF18(void);
extern s32 func_L01_00417F60(s32, s32);
extern void *func_L01_00438468(s32, s32);
extern s32 func_L01_00452F60(void *);
extern s32 func_00399F90(void);
extern s32 func_L01_00438488(s32, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_0039C710(void);
extern void func_L01_00438430(s32);
extern void func_0039DAE0(s32, s32);
extern void func_L01_00443A90(void *, void *, s32, void *, f32);
extern void func_L01_0045BE58(s32, s32);

void func_L04_00317198(u8 *a0) {
    S_003174B8 *s;
    s32 t;
    s32 a, b, c;
    u8 *m;
    u16 *p;
    s32 n;
    s32 r;

    s = *(S_003174B8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        a0[0x20] = 1;
        s->w18 = D_001426E0[0xF];
        s->w1C = D_001426E0[0x11];
        s->w38 = 0;
        s->w50 = 0;
        break;
    case 1:
        if (func_0037E0F0(D_001A4C60, s->w00, 0)) {
            if ((u32)(D_001D4C38 - D_001A7C10.w1C0) > 0x34BC0 && func_L01_0050FF18() == 0) {
                if (!(D_001A7E18.s[0x19].w8 & 0x80000000)) {
                    func_L01_00417F60(0xB76, 0x19);
                }
            }
        }
        if (func_L01_0050FF18() == 0) {
            if ((*(s32 (**)(void))((u8 *)func_L01_00438468(0x19E1, 0x6C) + 0x4C))()) {
                if (D_001A7C10.h1BC == 0 || (u32)(D_001D4C38 - D_001A7C10.w1C0) > 0x11940) {
                    if (D_001A7E18.s[0xCD6].h0 == 0) {
                        a = 0xCD6;
                        b = 0x7F;
                        c = 0xCD7;
                    } else {
                        a = 0xCD7;
                        b = 0x80;
                        c = 0xCD6;
                    }
                    if (!(D_001A7E18.s[c].w8 & 0x80000000)) {
                        func_L01_00417F60(a, b);
                        if (D_001A7E18.s[a].h0 == 0) {
                            D_001A7E18.s[a].h0 = 1;
                        }
                        D_001A7E18.s[c].h0 = 0;
                        if (D_001A7C10.h1BC < 0xFFFF) {
                            D_001A7C10.h1BC++;
                        }
                        t = D_001D4C38;
                        if (D_001A7C10.w1C0 < t) {
                            D_001A7C10.w1C0 = t;
                        }
                        D_001A7C10.w1C4 = D_001A7C10.w1C4 | (1 << D_001D545C) | 0x80000000;
                    }
                }
            }
        }
        if (s->w1C == 0) {
            if (D_001BBC40[s->w14 + D_001D545C * 16] & 0x80) {
                D_001426E0[0x11] = 1;
                func_00399F90();
                s->w1C = 1;
            }
        }
        if (func_L01_0050FF18() == 0) {
            if (D_001A7E18.s[0xCA6].h0 == 0) {
                if (func_L01_00452F60(D_L04_001DFE1C + (s->w54 << 8))) {
                    if (D_001A7E18.s[0xCA6].h0 == 0) {
                        D_001A7E18.s[0xCA6].h0 = 1;
                    }
                } else if (func_0037E0F0(D_001A4C60, s->w20, 0)) {
                    if ((u32)(D_001D4C38 - D_001A7E18.s[0x69].w4) > 0x708 || D_001A7E18.s[0x69].w4 == 0) {
                        func_L01_00417F60(0xCA6, 0x69);
                    }
                    if (!(D_001A7E18.s[0x69].w8 & 0x80000000)) {
                        func_L01_00417F60(0xCA6, 0x69);
                    }
                }
            }
        } else {
            if (D_001A7E18.s[0x17E6].h0 == 0) {
                if (func_L01_00452F60(D_L04_001DFE1C + (s->w54 << 8))) {
                    if (D_001A7E18.s[0x17E6].h0 == 0) {
                        D_001A7E18.s[0x17E6].h0 = 1;
                    }
                } else if (func_0037E0F0(D_001A4C60, s->w20, 0)) {
                    if ((u32)(D_001D4C38 - D_001A7E18.s[0x156].w4) > 0x708 || D_001A7E18.s[0x156].w4 == 0) {
                        func_L01_00417F60(0x17E6, 0x156);
                    }
                    if (!(D_001A7E18.s[0x156].w8 & 0x80000000)) {
                        func_L01_00417F60(0x17E6, 0x156);
                    }
                }
            }
        }
        if (func_L01_0050FF18() == 0) {
            if (D_001A7E18.s[0xA46].h0 == 0) {
                if (func_L01_00452F60(D_L04_001DFE1C + (s->w58 << 8))) {
                    if (D_001A7E18.s[0xA46].h0 == 0) {
                        D_001A7E18.s[0xA46].h0 = 1;
                    }
                } else if (func_0037E0F0(D_001A4C60, s->w28, 0)) {
                    if (!(D_001A7E18.s[0x10].w8 & 0x80000000)) {
                        func_L01_00417F60(0xA46, 0x10);
                    }
                }
            }
        } else {
            if (D_001A7E18.s[0x17E7].h0 == 0) {
                if (func_L01_00452F60(D_L04_001DFE1C + (s->w58 << 8))) {
                    if (D_001A7E18.s[0x17E7].h0 == 0) {
                        D_001A7E18.s[0x17E7].h0 = 1;
                    }
                } else if (func_0037E0F0(D_001A4C60, s->w28, 0)) {
                    if (!(D_001A7E18.s[0x157].w8 & 0x80000000)) {
                        func_L01_00417F60(0x17E7, 0x157);
                    }
                }
            }
        }
        if (D_001A7E18.s[0xB8C].h0 == 0) {
            if (func_0037E0F0(D_001A4C60, s->w2C, 0)) {
                func_L01_00417F60(0xB8C, 0x2F);
                if (D_001A7E18.s[0xB8C].h0 == 0) {
                    D_001A7E18.s[0xB8C].h0 = 1;
                }
                t = D_001D4C38;
                if (D_001A7E18.s[0x12D].w4 < t) {
                    D_001A7E18.s[0x12D].w4 = t;
                }
            }
        }
        if (D_001A7E18.s[0x15F6].h0 == 0) {
            if (func_L01_00452F60(D_L04_001DFE1C + (s->w30 << 8))) {
                if (D_001A7E18.s[0x15F6].h0 == 0) {
                    D_001A7E18.s[0x15F6].h0 = 1;
                }
            } else if (func_0037E0F0(D_001A4C60, s->w2C, 0)) {
                if (*(s32 *)(D_001A4C60 + 0x11A8) == 0x12) {
                    if ((u32)(D_001D4C38 - D_001A7E18.s[0x12D].w4) > 0xE10 || D_001A7E18.s[0x12D].w4 == 0) {
                        func_L01_00417F60(0x15F6, 0x12D);
                    }
                }
            }
        }
        if (D_L04_001DF9C0 == 0x28) {
            if (D_001A7E18.s[0xB89].h0 == 0) {
                if (D_00143964 != 0) {
                    func_L01_00417F60(0xB89, 0x2C);
                    if (D_001A7E18.s[0xB89].h0 == 0) {
                        D_001A7E18.s[0xB89].h0 = 1;
                    }
                }
            }
        }
        if (D_001A7E18.s[0xB8B].h0 == 0) {
            if (s->w38 == 0 && D_001A4BE0.w25C4 == 0x37) {
                for (m = D_L04_001DFE28; m != 0; m = *(u8 **)(m + 0x28)) {
                    if (func_L01_00438488(*(s16 *)(m + 0xAA), 6, 4) &&
                        func_L01_0040C018(m + 0x10, D_001A4C60) < 9.0f) {
                        s->w38 = m;
                        break;
                    }
                }
            }
            if (s->w38 != 0 && D_001A4BE0.w25C4 != 0x37) {
                r = func_L01_00438488(*(s16 *)(s->w38 + 0xAA), 6, 4);
                if (r != 0 && (**(f32 (**)(void *))r)(s->w38) != 1.0f) {
                    n = ++s->w34;
                    if (n == 3 || n == 6) {
                        func_L01_00417F60(0xB8B, 0x2E);
                    }
                }
                s->w38 = 0;
            }
        }
        if (s->w44 != -1) {
            if (D_001A7E18.s[0x162E].h0 == 0) {
                if (s->w50 != 0) {
                    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                        func_0039C710();
                        func_L01_00438430(s->w4C);
                        s->w50 = 0;
                    }
                } else if (!(D_001BBC40[s->w4C + D_001D545C * 16] & 0x80) && D_001CCFD0.w6C == 0 &&
                           D_001CCFD0.w24 == -1 && D_001CCFD0.w94 == 0 &&
                           func_0037E0F0(D_001A4C60, s->w48, 0)) {
                    func_0039DAE0((s->w44 & 0x3FFF) + 0x7D0, 0);
                    s->w50 = 1;
                    if (D_001A7E18.s[0x162E].h0 == 0) {
                        D_001A7E18.s[0x162E].h0 = 1;
                    }
                }
            }
        } else {
            if (D_001A7E18.s[0x162E].h0 == 0) {
                if (func_0037E0F0(D_001A4C60, s->w48, 0)) {
                    if (!(D_001A7E18.s[0x13A].w8 & (1 << D_001D545C))) {
                        func_L01_00417F60(0x162E, 0x13A);
                    }
                    if (D_001A7E18.s[0x162E].h0 == 0) {
                        D_001A7E18.s[0x162E].h0 = 1;
                    }
                }
            }
        }
        if (func_0037E0F0(D_001A4C60, s->w68, 0)) {
            if (s->w5C == 0) {
            for (p = D_L04_0021CA20[s->w70];
                 (s->w70 & 0xFF) != 0xFF && D_L04_001DFE58 >= s->w70 && p != 0 &&
                 (*(s16 *)(p - 1) >= 0 || p == D_L04_0021CA20[s->w70]);
                 p++) {
                m = D_L04_001DFE1C + ((p[0] & 0x7FFF) << 8);
                if (m == 0) {
                    break;
                }
                if (func_0037E0F0(m + 0x10, s->w6C, 0)) {
                    func_L01_00443A90(m, a0, 0x10000, D_001A4C60, 9999.0f);
                }
            }
            s->w5C = 1;
            }
        } else {
            s->w5C = 0;
        }
        if (func_0037E0F0(D_001A4C60, s->w74, 0)) {
            if (!(D_001A7E18.s[0xC9].w8 & (1 << D_001D545C))) {
                func_L01_00417F60(0x105A, 0xC9);
            }
        }
        break;
    }
    switch (a0[0xBC]) {
    case 0:
        if (D_L04_001F2B40 == 1) {
            func_L01_0045BE58(s->w64, -1);
            a0[0xBC] = 1;
        }
        break;
    case 1:
        if (D_L04_001F2B40 != 1) {
            func_L01_0045BE58(s->w60, -1);
            a0[0xBC] = 0;
        }
        break;
    }
}
/* localdecomp:end func_L04_00317198 */
