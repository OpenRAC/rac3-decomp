#include "common.h"

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    u8 pad40[8];
    s16 h48;
    u8 pad4A[0xE];
    s32 w58;
    u8 pad5C[2];
    s16 h5E;
    u8 pad60[8];
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s16 h7C;
    s16 h7E;
    f32 f80;
    f32 f84;
    f32 f88;
    f32 f8C;
} G_004B5C78;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x21];
    u8 b25E5;
} A_004B5C78;
typedef struct {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
} H_004B5C78;
typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x70];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} K_004B5C78;

/* localdecomp:start func_L01_004B8EC8 */
s32 func_L01_004B8EC8(void) {
    return 0;
}
/* localdecomp:end func_L01_004B8EC8 */

INCLUDE_ASM("asm/levels", func_L01_004B8ED0);

INCLUDE_ASM("asm/levels", func_L01_004B96E8);

INCLUDE_ASM("asm/levels", func_L01_004B9798);

/* localdecomp:start func_L01_004B9810 */




extern u32 D_00142BA0[];
extern s32 D_L01_001EA7C0[];
extern G_004B5C78 D_L01_001E6D80;
extern s32 D_L01_001E14A0;
extern s32 D_L01_001E13E0;
extern u8 D_L01_00251400[][64];
extern s32 D_L01_001E1420;
extern s32 D_L01_001E1460;
extern u8 D_L01_00244500[][64];
extern s32 D_L01_001E1070;
extern H_004B5C78 D_L01_001EA940;
extern f32 D_L01_001D6718;
extern s32 D_L01_001D671C;
extern f32 D_L01_001DF950[1];
extern s32 D_L01_001DF958[1];
extern A_004B5C78 D_001A4BE0;
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6720;
extern u8 *D_L01_001DFC18;
extern K_004B5C78 D_001CCFD0;
extern s32 D_L01_001DF95C;
extern s32 D_L01_001DF960;
extern u8 D_00143950[];
extern s32 D_001D545C;

extern void func_00392BB8(s32 *);
extern s32 func_003A8770(s32);
extern void func_L01_0045F328(s32);
extern void func_003A2750(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0041A6E0(void);
extern s32 func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004AC840(void);
extern void func_L01_0042C3C0(s32, s32);
extern s32 func_L01_0042C1F8(s32, s32);
extern s32 func_L01_0042C458(s32);
extern void func_L01_0042C278(void);
extern void func_L01_004B9798(s32);
extern void func_0039A438(void);
extern void func_L01_0040E2B0(s32, s32, s32);
extern void func_003A1F30(void);
extern void func_003A2B68(s32, s32);
extern void func_L01_00460228(void);
extern void func_003A4288(void);
extern s32 func_0012C908(s32);
extern void func_L01_00460200_004B9810(f32);
extern void func_003A1798(void);

void func_L01_004B9810(s32 a0) {
    s32 id;
    s32 i;
    s32 j;
    s32 k;
    f32 *pf;
    s32 *pi;
    s32 v;
    s32 w;
    s32 lo;
    s32 hi;
    s32 r;

    if (a0 >= 0) {
        u32 *bits = &D_00142BA0[(u32)a0 >> 2];
        *bits |= 1 << (a0 & 0x1F);
    }
    func_00392BB8(D_L01_001EA7C0);
    id = func_003A8770(a0);
    if (id < 0) {
        return;
    }
    if (D_L01_001E6D80.h5E == 0) {
        func_L01_0045F328(0);
        func_003A2750(0);
    }
    func_0038CB78(&D_L01_001E6D80, 0, 480);
    func_0038CB78(&D_L01_001E14A0, 0, 64);
    func_0038CB78(&D_L01_001E13E0, 0, 64);
    func_0038CB78(D_L01_00251400[0], 0, 64);
    func_0038CB78(D_L01_00251400[1], 0, 64);
    func_0038CB78(&D_L01_001E1420, 0, 64);
    func_0038CB78(&D_L01_001E1460, 0, 64);
    for (j = 0; j < 7; j++) {
        func_0038CB78(D_L01_00244500[j], 0, 64);
    }
    D_L01_001D6718 = 1.0f;
    D_L01_001D671C = 0;
    D_L01_001E6D80.w30 = id;
    D_L01_001E6D80.w34 = 0;
    D_L01_001E6D80.w3C = 0;
    D_L01_001E1070 -= 0x90000;
    D_L01_001E6D80.w68 = D_L01_001EA940.wC + D_L01_001E1070;
    D_L01_001E6D80.w6C = D_L01_001E6D80.w68 + 0x60000;
    D_L01_001E6D80.w58 = D_L01_001EA940.w10 + D_L01_001E1070;
    func_L01_0041A6E0();
    pi = D_L01_001DF958;
    pf = D_L01_001DF950;
    for (k = 0; k < 1; k++) {
        *pf++ = 1.0f;
        *pi++ = 0;
    }
    D_L01_001D6694 = 2;
    D_L01_001E6D80.w70 = D_L01_001DF9E4;
    D_L01_001E6D80.w74 = D_L01_001DF9E5;
    D_L01_001E6D80.w78 = D_L01_001DF9E6;
    D_L01_001E6D80.f80 = D_L01_001DF9E8;
    D_L01_001E6D80.f84 = D_L01_001DF9EC;
    D_L01_001E6D80.f88 = D_L01_001DF9F0;
    D_L01_001E6D80.f8C = D_L01_001DF9F4;
    D_L01_001D6720 = 0;
    if (D_001A4BE0.w25C0 != 0) {
        func_L01_005003D0(101, 2);
        D_001A4BE0.b25E5 = 1;
        func_L01_005108C0(0);
    }
    func_L01_004AC840();
    if (D_L01_001DFC18 != 0) {
        *(u16 *)(D_L01_001DFC18 + 0x34) |= 1;
    }
    D_L01_001DF95C = 1;
    D_L01_001DF960 = 52;
    if (D_001CCFD0.h4 != 0) {
        func_003A2750(1);
    }
    if (D_00143950[6] != 0) {
        func_L01_0042C3C0(D_001D545C, id);
    }
    r = func_L01_0042C1F8(D_001D545C, id);
    func_L01_0042C458(0);
    if (r != 0) {
        func_L01_0042C278();
    }
    func_L01_004B9798(1);
    if (D_001CCFD0.h4 != 0) {
        func_003A2750(1);
    }
    func_0039A438();
    if (D_L01_001E6D80.h7E != 0 && D_L01_001E6D80.h7C != 0) {
        lo = D_L01_001E6D80.h7E << 11;
        hi = D_L01_001E6D80.h7C << 11;
        if (lo <= 0x2FFFF) {
            if (hi <= 0x5FFFF) {
                v = D_L01_001EA940.wC + D_L01_001E1070 + 0x90000;
                v -= lo;
                func_L01_0040E2B0(v, D_L01_001E6D80.w6C, lo);
                D_L01_001E6D80.w6C = v;
                D_L01_001E6D80.w68 = v - hi;
                func_0039A438();
                D_L01_001E1070 = D_L01_001E6D80.w68 - D_L01_001EA940.wC;
                w = D_L01_001E6D80.w58 - D_L01_001EA940.w10;
                if (w < D_L01_001E1070) {
                    D_L01_001E1070 = w;
                }
            }
        }
    }
    if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) {
        D_001CCFD0.h76 = 5;
    }
    if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) {
        D_001CCFD0.h9E = 5;
    }
    func_003A1F30();
    func_003A2B68(D_L01_001E6D80.w30, 0);
    func_L01_00460228();
    i = 0;
    for (;;) {
        func_003A4288();
        func_0012C908(0);
        if (i > 300) {
            break;
        }
        i++;
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 7000) {
            break;
        }
    }
    func_L01_00460200_004B9810(0.82f);
    i = 0;
    D_L01_001E6D80.h48 = -3;
    func_003A1798();
    func_L01_0042C458(1);
    while (D_L01_001E6D80.h48 < i) {
        func_0012C908(0);
        i--;
    }
}
/* localdecomp:end func_L01_004B9810 */

INCLUDE_ASM("asm/levels", func_L01_004B9D20);

LINKER_REMNANT("asm/levels", func_L01_004BA0A0);
