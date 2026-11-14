#include "common.h"

/* NTSC-U counterpart of func_L39_00677FD8 (src/levels/shared/L39_00677F28.c) */
void func_L39_00608730(s32, s32);

/* localdecomp:start func_L39_006755F0 */
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
    char s240[0x20];
    char s260[0x20];
    char s280[0x20];
    char s2A0[0x20];
    char s2C0[0x20];
    char s2E0[0x20];
    char s300[0x20];
    char s320[0x20];
    char s340[0x20];
    char s360[0x20];
    char s380[0x20];
    char s3A0[0x20];
    char s3C0[0x20];
    char s3E0[0x20];
    char s400[0x20];
    char s420[0x20];
    u8 pad440[0x160];
    char s5A0[0x20];
    u8 pad5C0[0xE0];
    s32 f6A0;
    s32 f6A4;
    u8 f6A8;
    u8 f6A9;
    u8 f6AA;
    u8 f6AB;
    u8 f6AC;
    u8 f6AD;
    u8 f6AE;
    u8 f6AF;
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

extern G_00677FD8 D_L39_00352DE0;
extern P_00677FD8 *D_001D5F30_sda_006755F0;
extern R_00677FD8 D_001A5E50;
extern s32 D_L39_002407AC[2];
extern char D_L39_002467A8[];
extern char D_L39_002467B0[];
extern char D_L39_002467B8[];
extern char D_L39_002467C0[];
extern s32 func_0037DF98(s32);
extern s32 func_001206F4(char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_L39_00675DC8(void);
extern s32 func_L39_006773A8(void);
extern s32 func_L39_00677D50();

s32 func_L39_006755F0(void) {
    G_00677FD8 *g;
    func_L39_00608730(0, 0);
    g = &D_L39_00352DE0;
    g->f24 = 0.0f;
    g->f10 = 0xF;
    g->f20 = -4.0f;
    g->f38 = g->f24;
    g->f34 = g->f24;
    g->f30 = g->f24;
    g->f28 = 0;
    g->f14 = 0;
    g->f6A4 = 0;
    g->f0C = D_001D5F30_sda_006755F0->f17C % 10;
    func_001206F4(g->s40, func_0037DF98(0xBB1));
    func_001206F4(g->s60, func_0037DF98(0xBB2));
    func_001206F4(g->s80, func_0037DF98(0xDA));
    func_001206F4(g->sA0, func_0037DF98(0xBB4));
    func_001206F4(g->sC0, func_0037DF98(0xD8));
    func_001206F4(g->sE0, func_0037DF98(0xD4));
    func_001206F4(g->s100, func_0037DF98(0x18C4));
    func_001206F4(g->s120, func_0037DF98(0x18C5));
    func_001206F4(g->s140, func_0037DF98(0x18C6));
    func_001206F4(g->s160, func_0037DF98(0x18C7));
    func_001206F4(g->s2C0, func_0037DF98(0x116D));
    func_001206F4(g->s2E0, func_0037DF98(0xFE9));
    func_001206F4(g->s300, func_0037DF98(0xFEA));
    if (D_001D5F30_sda_006755F0->f180 == 1) {
        func_001206F4(g->s320, func_0037DF98(0x1656));
    } else {
        func_001206F4(g->s320, func_0037DF98(0xF52));
    }
    func_001206F4(D_L39_00352DE0.s340, func_0037DF98(0x10E7));
    func_001206F4(D_L39_00352DE0.s360, func_0037DF98(0x1642));
    func_001206F4(D_L39_00352DE0.s380, func_0037DF98(0x1673));
    func_001206F4(D_L39_00352DE0.s3A0, func_0037DF98(0xF37));
    func_001206F4(D_L39_00352DE0.s3C0, func_0037DF98(0x17F0));
    func_001206F4(D_L39_00352DE0.s3E0, func_0037DF98(0x17F1));
    func_001206F4(D_L39_00352DE0.s400, func_0037DF98(0x1931));
    func_001206F4(D_L39_00352DE0.s420, func_0037DF98(0x17F2));
    switch (D_001D5F30_sda_006755F0->f180) {
    case 0:
        if (D_001D5F30_sda_006755F0->f196 == 0) {
            func_00120048(D_L39_00352DE0.s180, D_L39_002467A8, func_0037DF98(0x1024), func_0037DF98(0x1658));
        } else {
            func_00120048(D_L39_00352DE0.s180, D_L39_002467A8, func_0037DF98(0x1024), func_0037DF98(0x18B6));
        }
        break;
    case 1:
        if (D_001D5F30_sda_006755F0->f196 == 0) {
            func_00120048(D_L39_00352DE0.s180, D_L39_002467A8, func_0037DF98(0x10E2), func_0037DF98(0x1658));
        } else {
            func_00120048(D_L39_00352DE0.s180, D_L39_002467A8, func_0037DF98(0x10E2), func_0037DF98(0x1659));
        }
        if (D_001D5F30_sda_006755F0->f198 == 0) {
            func_00120048(D_L39_00352DE0.s1C0, D_L39_002467B8, func_0037DF98(0x1657));
        } else {
            func_00120048(D_L39_00352DE0.s1C0, D_L39_002467B0, D_001D5F30_sda_006755F0->f198);
        }
        break;
    case 2:
        func_001206F4(D_L39_00352DE0.s180, func_0037DF98(0x1026));
        if (D_001D5F30_sda_006755F0->f197 != 0) {
            func_00120048(D_L39_00352DE0.s1C0, D_L39_002467B0, D_001D5F30_sda_006755F0->f197);
        } else {
            func_001206F4(D_L39_00352DE0.s1C0, func_0037DF98(0x1328));
        }
        break;
    }
    if (D_001D5F30_sda_006755F0->f19F != 0) {
        func_00120048(D_L39_00352DE0.s1E0, D_L39_002467C0, func_0037DF98(0x1642), func_0037DF98(0xF3E));
    } else {
        func_00120048(D_L39_00352DE0.s1E0, D_L39_002467C0, func_0037DF98(0x1642), func_0037DF98(0xF3F));
    }
    if (D_001D5F30_sda_006755F0->f188 != 0) {
        func_00120048(D_L39_00352DE0.s200, func_0037DF98(0x1673));
    } else {
        func_00120048(D_L39_00352DE0.s200, func_0037DF98(0x1674));
    }
    if (D_001D5F30_sda_006755F0->f18F != 0) {
        func_00120048(D_L39_00352DE0.s220, func_0037DF98(0x192E));
    } else {
        func_00120048(D_L39_00352DE0.s220, func_0037DF98(0x192D));
    }
    if (D_001D5F30_sda_006755F0->f194 != 0) {
        func_00120048(D_L39_00352DE0.s240, func_0037DF98(0x1933));
    } else {
        func_00120048(D_L39_00352DE0.s240, func_0037DF98(0x1934));
    }
    if (D_001D5F30_sda_006755F0->f19B != 0) {
        func_00120048(D_L39_00352DE0.s260, func_0037DF98(0x17F1));
    }
    if (D_001D5F30_sda_006755F0->f19A != 0) {
        func_00120048(D_L39_00352DE0.s280, func_0037DF98(0x1931));
    }
    if (D_001D5F30_sda_006755F0->f19C != 0) {
        func_00120048(D_L39_00352DE0.s2A0, func_0037DF98(0x192F));
    }
    D_L39_00352DE0.f6A4 = 0;
    if (D_001A5E50.f170 == 0) {
        D_L39_00352DE0.f6A4 = (D_001A5E50.f604 & 7) * 5;
    } else {
        D_L39_00352DE0.f6A4 = D_L39_002407AC[1];
    }
    if (D_L39_00352DE0.f6A4 != 0) {
        func_00120048(D_L39_00352DE0.s1A0, func_0037DF98(0x116B), D_L39_00352DE0.f6A4);
    } else {
        func_00120048(D_L39_00352DE0.s1A0, func_0037DF98(0xF3F));
    }
    func_L39_00675DC8();
    D_L39_00352DE0.f6A0 = func_L39_006773A8();
    func_001206F4(D_L39_00352DE0.s5A0, func_0037DF98(D_L39_00352DE0.f6A0));
    D_L39_00352DE0.f6A8 = func_L39_00677D50(3);
    D_L39_00352DE0.f6A9 = func_L39_00677D50(1);
    D_L39_00352DE0.f6AA = func_L39_00677D50(2);
    D_L39_00352DE0.f6AB = func_L39_00677D50(4);
    D_L39_00352DE0.f6AC = func_L39_00677D50(5);
    D_L39_00352DE0.f6AD = func_L39_00677D50(6);
    D_L39_00352DE0.f6AE = func_L39_00677D50(9);
    D_L39_00352DE0.f6AF = func_L39_00677D50(7);
    return 1;
}
/* localdecomp:end func_L39_006755F0 */
