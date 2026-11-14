#include "common.h"

/* declared by functions of L39_00677D08.c, which this file was cut from */
void func_L39_0060AE30(s32, s32);
extern void func_L39_00677F28(void);

/* localdecomp:start func_L39_00677F28 */
extern void func_L39_00594BA0(s32, s32, s32, s32, s32, f32);
extern s32 D_L39_00246618;
__asm__(".extern D_L39_00246618, 4");
extern s32 D_L39_0024661C;
__asm__(".extern D_L39_0024661C, 4");
extern f32 D_L39_00246620;
__asm__(".extern D_L39_00246620, 4");
extern s32 D_L39_00246600[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246600, 4");
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern u8 D_001A58C7[];

void func_L39_00677F28(void) {
    s32 col = (D_L39_00246618 << 24) | 0x66CCFF;
    s32 half = D_L39_00240300 >> 1;
    D_L39_00246618 += D_L39_0024661C * 2;
    if (D_L39_00246618 < 32) { D_L39_0024661C = 1; } else if (D_L39_00246618 > 128) { D_L39_0024661C = -1; }
    func_L39_00594BA0(half, (s32)(D_L39_00246620 * (f32)D_L39_00240304), col, D_L39_00246600[D_001A58C7[0]], -1, 1.2f);
}
/* localdecomp:end func_L39_00677F28 */

/* localdecomp:start func_L39_00677FD8 */
typedef struct {
    u8 pad0[0xC];
    s32 f0C;
    s32 f10;
    s32 f14;
    u8 pad18[8];
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3C[4];
    char s40[0x20];
    char s60[0x20];
    char s80[0x20];
    char sA0[0x20];
    char sC0[0x20];
    char sE0[0x20];
    char s100[0x20];
    char s120[0x20];
    char s140[0x20];
    char s160[0x20];
    char s180[0x20];
    char s1A0[0x20];
    char s1C0[0x20];
    char s1E0[0x20];
    char s200[0x20];
    char s220[0x20];
    char s240[0x21];
    char s261[0x20];
    char s281[0x20];
    char s2A1[0x20];
    char s2C1[0x20];
    char s2E1[0x20];
    char s301[0x20];
    char s321[0x20];
    char s341[0x20];
    char s361[0x20];
    char s381[0x20];
    char s3A1[0x20];
    char s3C1[0x20];
    char s3E1[0x20];
    char s401[0x20];
    char s421[0x20];
    u8 pad441[0x160];
    char s5A1[0x20];
    u8 pad5C1[0xE3];
    s32 f6A4;
    s32 f6A8;
    u8 f6AC;
    u8 f6AD;
    u8 f6AE;
    u8 f6AF;
    u8 f6B0;
    u8 f6B1;
    u8 f6B2;
    u8 f6B3;
} G_00677FD8;

typedef struct {
    u8 pad0[0x17C];
    s16 f17C;
    u8 pad17E[2];
    s32 f180;
    u8 pad184[4];
    s8 f188;
    u8 pad189[6];
    s8 f18F;
    u8 pad190[4];
    s8 f194;
    u8 pad195[1];
    s8 f196;
    s8 f197;
    s8 f198;
    u8 pad199[1];
    s8 f19A;
    s8 f19B;
    s8 f19C;
    u8 pad19D[2];
    u8 f19F;
} P_00677FD8;

typedef struct {
    u8 pad0[0x170];
    s32 f170;
    u8 pad174[0x604 - 0x174];
    s32 f604;
} R_00677FD8;

extern G_00677FD8 D_L39_00352CE0;
extern P_00677FD8 *D_001D5F30_sda;
extern R_00677FD8 D_001A5CD0;
extern s32 D_L39_0024062C[2];
extern char D_L39_00246628[];
extern char D_L39_00246630[];
extern char D_L39_00246638[];
extern char D_L39_00246640[];
extern s32 func_00381FF0(s32);
extern s32 func_001206F4(char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_L39_006787B0(void);
extern s32 func_L39_00679DA0(void);
extern s32 func_L39_0067A748();

s32 func_L39_00677FD8(void) {
    G_00677FD8 *g;
    func_L39_0060AE30(0, 0);
    g = &D_L39_00352CE0;
    g->f24 = 0.0f;
    g->f10 = 0xC;
    g->f20 = -4.0f;
    g->f38 = g->f24;
    g->f34 = g->f24;
    g->f30 = g->f24;
    g->f28 = 0;
    g->f14 = 0;
    g->f6A8 = 0;
    g->f0C = D_001D5F30_sda->f17C % 10;
    func_001206F4(g->s40, func_00381FF0(0xBB1));
    func_001206F4(g->s60, func_00381FF0(0xBB2));
    func_001206F4(g->s80, func_00381FF0(0xDA));
    func_001206F4(g->sA0, func_00381FF0(0xBB4));
    func_001206F4(g->sC0, func_00381FF0(0xD8));
    func_001206F4(g->sE0, func_00381FF0(0xD4));
    func_001206F4(g->s100, func_00381FF0(0x18C4));
    func_001206F4(g->s120, func_00381FF0(0x18C5));
    func_001206F4(g->s140, func_00381FF0(0x18C6));
    func_001206F4(g->s160, func_00381FF0(0x18C7));
    func_001206F4(g->s2C1, func_00381FF0(0x116D));
    func_001206F4(g->s2E1, func_00381FF0(0xFE9));
    func_001206F4(g->s301, func_00381FF0(0xFEA));
    if (D_001D5F30_sda->f180 == 1) {
        func_001206F4(g->s321, func_00381FF0(0x1656));
    } else {
        func_001206F4(g->s321, func_00381FF0(0xF52));
    }
    func_001206F4(D_L39_00352CE0.s341, func_00381FF0(0x10E7));
    func_001206F4(D_L39_00352CE0.s361, func_00381FF0(0x1642));
    func_001206F4(D_L39_00352CE0.s381, func_00381FF0(0x1673));
    func_001206F4(D_L39_00352CE0.s3A1, func_00381FF0(0xF37));
    func_001206F4(D_L39_00352CE0.s3C1, func_00381FF0(0x17F0));
    func_001206F4(D_L39_00352CE0.s3E1, func_00381FF0(0x17F1));
    func_001206F4(D_L39_00352CE0.s401, func_00381FF0(0x1931));
    func_001206F4(D_L39_00352CE0.s421, func_00381FF0(0x17F2));
    switch (D_001D5F30_sda->f180) {
    case 0:
        if (D_001D5F30_sda->f196 == 0) {
            func_00120048(D_L39_00352CE0.s180, D_L39_00246628, func_00381FF0(0x1024), func_00381FF0(0x1658));
        } else {
            func_00120048(D_L39_00352CE0.s180, D_L39_00246628, func_00381FF0(0x1024), func_00381FF0(0x18B6));
        }
        break;
    case 1:
        if (D_001D5F30_sda->f196 == 0) {
            func_00120048(D_L39_00352CE0.s180, D_L39_00246628, func_00381FF0(0x10E2), func_00381FF0(0x1658));
        } else {
            func_00120048(D_L39_00352CE0.s180, D_L39_00246628, func_00381FF0(0x10E2), func_00381FF0(0x1659));
        }
        if (D_001D5F30_sda->f198 == 0) {
            func_00120048(D_L39_00352CE0.s1C0, D_L39_00246638, func_00381FF0(0x1657));
        } else {
            func_00120048(D_L39_00352CE0.s1C0, D_L39_00246630, D_001D5F30_sda->f198);
        }
        break;
    case 2:
        func_001206F4(D_L39_00352CE0.s180, func_00381FF0(0x1026));
        if (D_001D5F30_sda->f197 != 0) {
            func_00120048(D_L39_00352CE0.s1C0, D_L39_00246630, D_001D5F30_sda->f197);
        } else {
            func_001206F4(D_L39_00352CE0.s1C0, func_00381FF0(0x1328));
        }
        break;
    }
    if (D_001D5F30_sda->f19F != 0) {
        func_00120048(D_L39_00352CE0.s1E0, D_L39_00246640, func_00381FF0(0x1642), func_00381FF0(0xF3E));
    } else {
        func_00120048(D_L39_00352CE0.s1E0, D_L39_00246640, func_00381FF0(0x1642), func_00381FF0(0xF3F));
    }
    if (D_001D5F30_sda->f188 != 0) {
        func_00120048(D_L39_00352CE0.s200, func_00381FF0(0x1673));
    } else {
        func_00120048(D_L39_00352CE0.s200, func_00381FF0(0x1674));
    }
    if (D_001D5F30_sda->f18F != 0) {
        func_00120048(D_L39_00352CE0.s220, func_00381FF0(0x192E));
    } else {
        func_00120048(D_L39_00352CE0.s220, func_00381FF0(0x192D));
    }
    if (D_001D5F30_sda->f194 != 0) {
        func_00120048(D_L39_00352CE0.s240, func_00381FF0(0x1933));
    } else {
        func_00120048(D_L39_00352CE0.s240, func_00381FF0(0x1934));
    }
    if (D_001D5F30_sda->f19B != 0) {
        func_00120048(D_L39_00352CE0.s261, func_00381FF0(0x17F1));
    }
    if (D_001D5F30_sda->f19A != 0) {
        func_00120048(D_L39_00352CE0.s281, func_00381FF0(0x1931));
    }
    if (D_001D5F30_sda->f19C != 0) {
        func_00120048(D_L39_00352CE0.s2A1, func_00381FF0(0x192F));
    }
    D_L39_00352CE0.f6A8 = 0;
    if (D_001A5CD0.f170 == 0) {
        D_L39_00352CE0.f6A8 = (D_001A5CD0.f604 & 7) * 5;
    } else {
        D_L39_00352CE0.f6A8 = D_L39_0024062C[1];
    }
    if (D_L39_00352CE0.f6A8 != 0) {
        func_00120048(D_L39_00352CE0.s1A0, func_00381FF0(0x116B), D_L39_00352CE0.f6A8);
    } else {
        func_00120048(D_L39_00352CE0.s1A0, func_00381FF0(0xF3F));
    }
    func_L39_006787B0();
    D_L39_00352CE0.f6A4 = func_L39_00679DA0();
    func_001206F4(D_L39_00352CE0.s5A1, func_00381FF0(D_L39_00352CE0.f6A4));
    D_L39_00352CE0.f6AC = func_L39_0067A748(3);
    D_L39_00352CE0.f6AD = func_L39_0067A748(1);
    D_L39_00352CE0.f6AE = func_L39_0067A748(2);
    D_L39_00352CE0.f6AF = func_L39_0067A748(4);
    D_L39_00352CE0.f6B0 = func_L39_0067A748(5);
    D_L39_00352CE0.f6B1 = func_L39_0067A748(6);
    D_L39_00352CE0.f6B2 = func_L39_0067A748(9);
    D_L39_00352CE0.f6B3 = func_L39_0067A748(7);
    return 1;
}
/* localdecomp:end func_L39_00677FD8 */

INCLUDE_ASM("asm/levels", func_L39_006787B0);

/* localdecomp:start func_L39_006788F8 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
} S_006788F8;
extern s32 func_0038CAD0(void *);
extern void func_003BE008(f32);
extern S_006788F8 D_L39_00352CE0_006788F8;

s32 func_L39_006788F8(s32 a0) {
    S_006788F8 *d = &D_L39_00352CE0_006788F8;
    s32 r = 0;
    switch (d->f14) {
    case 0:
        if (func_0038CAD0(&d->f10)) {
            d->f14 = 1;
            d->f10 = 25;
        }
        func_003BE008(1.0f);
        break;
    case 1:
        if (func_0038CAD0(&d->f10)) {
            d->f14 = 2;
            d->f10 = 250;
        }
        func_003BE008((f32)d->f10 / 25.0f);
        break;
    case 2:
        if (func_0038CAD0(&d->f10)) {
            d->f14 = 3;
            d->f10 = 25;
        }
        func_003BE008(0.0f);
        break;
    case 3:
        if (a0 != 0) {
            if (func_0038CAD0(&d->f10)) {
                r = 1;
            }
        }
        func_003BE008(1.0f - (f32)d->f10 / 25.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_L39_006788F8 */

INCLUDE_ASM("asm/levels", func_L39_00678A50);

/* localdecomp:start func_L39_006792F8 */
extern s32 func_00120884(char *);
extern void func_L39_005948D0(s32, s32, s32, s32, unsigned long, char *, s32);
extern f32 D_L39_00246664;
__asm__(".extern D_L39_00246664, 4");
extern f32 D_L39_00246668;
__asm__(".extern D_L39_00246668, 4");
extern f32 D_L39_0024666C;
__asm__(".extern D_L39_0024666C, 4");
extern f32 D_L39_00246670;
__asm__(".extern D_L39_00246670, 4");
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern u8 D_L39_00242854;
extern char D_L39_00353281[];

void func_L39_006792F8(void) {
    f32 w = (f32)D_L39_00240300;
    f32 h = (f32)D_L39_00240304;
    s32 x = (s32)(D_L39_00246664 * w);
    s32 y = (s32)(D_L39_00246668 * h);
    s32 ww = (s32)(D_L39_0024666C * w);
    s32 hh = (s32)(D_L39_00246670 * h);
    D_L39_00242854 = 1;
    func_L39_005948D0(x, y, ww, hh, 0x8066CCFF, D_L39_00353281, func_00120884(D_L39_00353281));
    D_L39_00242854 = 0;
}
/* localdecomp:end func_L39_006792F8 */

INCLUDE_ASM("asm/levels", func_L39_006793D8);

/* localdecomp:start func_L39_00679630 */
__asm__(".extern D_L39_0024667C, 4");
__asm__(".extern D_L39_00246680, 4");
__asm__(".extern D_L39_00246684, 4");
__asm__(".extern D_L39_00246688, 4");
__asm__(".extern D_L39_0024668C, 4");
__asm__(".extern D_L39_00246690_00679630, 4");
__asm__(".extern D_L39_00246694, 4");
__asm__(".extern D_L39_00246698, 4");
__asm__(".extern D_L39_0024669C, 4");
__asm__(".extern D_L39_0024D010, 4");
__asm__(".extern D_L39_0024D014, 4");
__asm__(".extern D_L39_0024B9C8, 16");
extern f32 D_L39_0024667C;
extern f32 D_L39_00246680;
extern f32 D_L39_00246684;
extern f32 D_L39_00246688;
extern f32 D_L39_0024668C;
extern f32 D_L39_00246690_00679630;
extern f32 D_L39_00246694;
extern f32 D_L39_00246698;
extern f32 D_L39_0024669C;
extern f32 D_L39_0024D010;
extern s32 D_L39_0024D014;
extern s32 D_L39_0024B9C8;
__asm__(".extern D_L39_0024D03C, 16");
extern f32 D_L39_0024D03C;
extern void func_003A9440(s32, unsigned long);
extern s32 func_L39_00589890(s32);
extern void func_L39_0058B9F8(f32, f32, f32, f32, s32, s32, s32, s32, long, s32);
extern void func_L39_0058B1B8(s32, s32, s32, s32);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, s32);

void func_L39_00679630(void) {
    f32 w = (f32)D_L39_00240300;
    f32 h = (f32)D_L39_00240304 * 0.5f;
    f32 w2 = w + w;
    double d;
    f32 ang;
    f32 x, y, ww, hh;
    if (D_L39_0024D014 == 0) {
        D_L39_0024D010 = w2;
        D_L39_0024D014 = 1;
    }
    D_L39_0024667C += D_L39_00246680;
    D_L39_0024D010 += D_L39_00246680;
    d = D_L39_0024667C;
    if (d < 0.0) d = -d;
    if (d > w2) D_L39_0024667C = D_L39_0024D010 + w2;
    d = D_L39_0024D010;
    if (d < 0.0) d = -d;
    if (d > w2) D_L39_0024D010 = D_L39_0024667C + w2;
    func_003A9440(8, 5);
    func_003A9440(0x42, 0x8000000044UL);
    func_003A9440(0x47, 0x3004B);
    func_L39_0058B9F8(D_L39_0024667C, 0.0f, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2D));
    func_L39_0058B9F8(D_L39_0024667C + w, 0.0f, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2C));
    func_L39_0058B9F8(D_L39_0024667C, h, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2F));
    func_L39_0058B9F8(D_L39_0024667C + w, h, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2E));
    func_L39_0058B9F8(D_L39_0024D010, 0.0f, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2D));
    func_L39_0058B9F8(D_L39_0024D010 + w, 0.0f, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2C));
    func_L39_0058B9F8(D_L39_0024D010, h, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2F));
    func_L39_0058B9F8(D_L39_0024D010 + w, h, w, h, 0, 0, 0x100, 0x100, 0x69696969, func_L39_00589890(0x2E));
    func_L39_0058B1B8(0, 0, 0, (s32)((D_L39_0024D03C * 0.5f + 0.5f) * 128.0f));
    x = D_L39_00246684 * (f32)D_L39_00240300;
    y = D_L39_00246688 * (f32)D_L39_00240304;
    ww = D_L39_0024668C * (f32)D_L39_00240300;
    hh = D_L39_00246690_00679630 * (f32)D_L39_00240304;
    func_L39_0058B9F8(x, y, ww, hh, 0, 0, 0x100, 0x100, 0x8066CCFFL, func_L39_00589890(0x30));
    x = D_L39_00246694 * (f32)D_L39_00240300 * 16.0f;
    y = D_L39_00246698 * (f32)D_L39_00240304 * 16.0f;
    ww = D_L39_0024669C * (f32)D_L39_00240300 * 16.0f;
    ang = (f32)(D_L39_0024B9C8 % 120) * -6.2831855f / 120.0f;
    func_00397638(x, y, ww, ww, ang, 0x80, 0x80, func_L39_00589890(0x31));
}
/* localdecomp:end func_L39_00679630 */

/* localdecomp:start func_L39_00679AE0 */
extern void func_L39_00594BA0(s32, s32, s32, s32, s32, f32);
extern s32 D_L39_00246600[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246600, 4");
extern s32 D_L39_00240304;
extern u8 D_001A58C7[];
extern s32 D_L39_002466A0;
__asm__(".extern D_L39_002466A0, 4");
extern s32 D_L39_002466A4;
__asm__(".extern D_L39_002466A4, 4");
extern f32 D_L39_002466A8;
__asm__(".extern D_L39_002466A8, 4");

void func_L39_00679AE0(s32 *p) {
    s32 col = (D_L39_002466A0 << 24) | 0x66CCFF;
    D_L39_002466A0 += D_L39_002466A4 * 2;
    if (D_L39_002466A0 < 32) { D_L39_002466A4 = 1; } else if (D_L39_002466A0 > 128) { D_L39_002466A4 = -1; }
    func_L39_00594BA0(*p, (s32)(D_L39_002466A8 * (f32)D_L39_00240304), col, D_L39_00246600[D_001A58C7[0]], -1, 1.2f);
}
/* localdecomp:end func_L39_00679AE0 */

/* localdecomp:start func_L39_00679B88 */
extern void func_L39_0058B2C8(s32, s32, s32, s32, unsigned long);
extern void func_L01_00412A98(s32, s32, s32, s32, s32, f32);
extern f32 D_L39_002466B8;
__asm__(".extern D_L39_002466B8, 4");
extern f32 D_L39_002466B4;
__asm__(".extern D_L39_002466B4, 4");
extern f32 D_L39_002466BC;
__asm__(".extern D_L39_002466BC, 4");
extern f32 D_L39_002466C0;
__asm__(".extern D_L39_002466C0, 4");
extern f32 D_L39_002466C4;
__asm__(".extern D_L39_002466C4, 4");
extern f32 D_L39_002466CC;
__asm__(".extern D_L39_002466CC, 4");
extern f32 D_L39_002466C8;
__asm__(".extern D_L39_002466C8, 4");
extern f32 D_L39_002466D4;
__asm__(".extern D_L39_002466D4, 4");
extern f32 D_L39_002466D0;
__asm__(".extern D_L39_002466D0, 4");
extern f32 D_L39_002466D8;
__asm__(".extern D_L39_002466D8, 4");
extern f32 D_L39_002466DC;
__asm__(".extern D_L39_002466DC, 4");
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;

void func_L39_00679B88(s32 n) {
    s32 i;
    s32 j;
    s32 x;
    s32 w;
    s32 y;
    for (i = 0; i < n; i++) {
        x = (s32)(D_L39_002466BC * (f32)D_L39_00240300);
        w = (s32)(D_L39_002466C0 * (f32)D_L39_00240300);
        y = (s32)((D_L39_002466B4 + (f32)i * D_L39_002466B8) * (f32)D_L39_00240304);
        func_L39_0058B2C8(y, y + 2, x, x + w, 0x332299DE);
    }
    x = (s32)(D_L39_002466C4 * (f32)D_L39_00240300);
    func_L39_0058B2C8((s32)(D_L39_002466C8 * (f32)D_L39_00240304), (s32)(D_L39_002466CC * (f32)D_L39_00240304), x, x + 2, 0x80808080);
    x = (s32)(D_L39_002466D0 * (f32)D_L39_00240300);
    w = (s32)(D_L39_002466D4 * (f32)D_L39_00240300);
    for (j = 0; j < 4; j++) {
        y = (s32)((D_L39_002466C8 + D_L39_002466D8 * (f32)j) * (f32)D_L39_00240304);
        func_L39_0058B2C8(y, y + 2, x, w, 0x80808080);
    }
    ((void (*)(s32, s32, unsigned long, char *, s32, f32))func_L01_00412A98)((s32)(D_L39_002466C4 * (f32)D_L39_00240300), (s32)(D_L39_002466DC * (f32)D_L39_00240304), 0x8066CCFF, D_L39_00352CE0.s2C1, -1, 0.9f);
}
/* localdecomp:end func_L39_00679B88 */

/* localdecomp:start func_L39_00679DA0 */
typedef struct {
    u8 pad0[0x174];
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
    s32 f184;
    s32 f188;
} S_00679DA0;
extern void func_00139328(u8 *);
extern void func_0019D500(s32);
extern s32 func_L39_005B4398(s32);
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern S_00679DA0 D_001FC6B0;

s32 func_L39_00679DA0(void) {
    u8 buf[8];
    u8 *p;
    func_00139328(buf);
    func_0019D500((buf[1] << 24 | buf[2] << 16 | buf[3] << 8 | buf[5]) ^ *(volatile s32 *)0x10000800 /* T0_COUNT */);
    p = D_L39_00241640;
    switch (*(s32 *)(p + 0x180)) {
    case 0:
        if (*(s8 *)(p + 0x196) == 0) {
            if (D_001FC6B0.f174 == 0) {
                D_001FC6B0.f174 = 1;
                return 0x18DE;
            }
        } else {
            if (D_001FC6B0.f178 == 0) {
                D_001FC6B0.f178 = 1;
                return 0x18DF;
            }
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x196) == 0) {
            if (D_001FC6B0.f17C == 0) {
                D_001FC6B0.f17C = 1;
                return 0x18E0;
            }
        } else {
            if (D_001FC6B0.f180 == 0) {
                D_001FC6B0.f180 = 1;
                return 0x18E1;
            }
        }
        break;
    case 2:
        if (*(s8 *)(p + 0x197) != 0) {
            if (D_001FC6B0.f184 == 0) {
                D_001FC6B0.f184 = 1;
                return 0x18E2;
            }
        } else {
            if (D_001FC6B0.f188 == 0) {
                D_001FC6B0.f188 = 1;
                return 0x18E3;
            }
        }
        break;
    }
    return func_L39_005B4398(0x24) + 0x18E4;
}
/* localdecomp:end func_L39_00679DA0 */

INCLUDE_ASM("asm/levels", func_L39_00679F08);
