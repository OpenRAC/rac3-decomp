#include "common.h"

/* NTSC-U version of func_003A6F28 (frontbin): 5 -> 6; 5 -> 6 */
#include "common.h"





typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x34 - 0x21]; u16 f34; u8 pad36[0xAA - 0x36]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3A1438;
typedef struct {
    u8 pad[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x60 - 0x4A]; s8 f60; u8 pad61[0x1A0 - 0x61]; O_3A1438 *f1A0[1];
} S_225780_3A1438;
typedef struct { u8 pad[0x1A0]; unsigned long f1A0; } Pad_3A1438;
typedef struct { u8 pad[0x25C0]; O_3A1438 *f25C0; } S_1A4BE0_3A1438;
extern s32 func_U_0039C710(void);
extern void func_U_003A1870(void);
extern s32 func_U_0039D6C8(s32);
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870 *f1A0[1];
} S_225780_3A1870;
extern void func_11F0A0(s32);
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_3A1AD0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_3A1AD0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_3A1AD0 r[1]; } S_160C40_3A1AD0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_3A1AD0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_3A1AD0;
extern S_225780_3A1AD0 D_U_00225780_003A6F28;
extern S_160C40_3A1AD0 D_160C40_003A6F28;
extern S_1CCFD0_3A1AD0 D_1CCFD0_003A6F28;
extern S_143950_3A1AD0 D_00143950_003A6F28;
extern u32 D_142BA0[];
extern s32 D_U_0022766C[];
extern u8 D_1A5DC0[];
extern u8 D_U_001D99E0[8];
extern u8 D_U_001D9920[8];
extern u8 D_U_001E22C0[];
extern u8 D_U_001D9960[8];
extern u8 D_U_001D99A0[8];
extern f32 D_U_001D5BC8;
extern s32 D_U_001D5BCC;
extern s32 D_U_001D5B94;
extern s32 D_U_001D9C5C_003A6F28;
extern s32 D_U_001D9C60_003A6F28;
extern f32 D_U_001D9C50_003A6F28[1];
extern s32 D_U_001D9C58_003A6F28[1];
extern void func_U_00388440(void *, s32, s32);
extern void func_U_00385B60(s32);
extern void func_U_003A1870(void);
extern void func_U_0039DAE0(s32, s32);
extern s32 func_12C908(s32);
extern s32 func_U_0039C710(void);
/* localdecomp:start func_U_003A1AD0 */
extern s32 func_U_003A13B0(s32);
extern void func_U_003A2BC0(void);
extern void func_U_0039EE68(void);
extern s32 func_U_0039D510(s32, s32, s32);
s32 func_U_003A1AD0(s32 lvl) {
    s32 slot;
    s32 b;
    s32 i;
    s32 dst;
    s32 n;
    s32 off;
    S_143950_3A1AD0 *p;
    if (lvl >= 0) { u32 *w = &D_142BA0[(u32)lvl >> 2]; *w |= 1 << (lvl & 0x1F); }
    slot = func_U_003A1AA0(lvl);
    if (slot < 0) return 0;
    func_U_00388440(D_1A5DC0, 0, 0x230);
    func_U_00388440(&D_U_00225780_003A6F28, 0, 0x1E0);
    func_U_00388440(D_U_001D99E0, 0, 0x40);
    func_U_00388440(D_U_001D9920, 0, 0x40);
    func_U_00388440(D_U_001E22C0, 0, 0x40);
    func_U_00388440(D_U_001E22C0 + 0x40, 0, 0x40);
    func_U_00388440(D_U_001D9960, 0, 0x40);
    func_U_00388440(D_U_001D99A0, 0, 0x40);
    b = D_U_0022766C[0];
    D_U_00225780_003A6F28.f30 = slot;
    D_U_00225780_003A6F28.f68 = b - 0x82000;
    D_U_00225780_003A6F28.f6C = b - 0x102000;
    D_U_001D5BC8 = 1.0f;
    D_U_001D5BCC = 0;
    D_U_00225780_003A6F28.f34 = 0;
    D_U_00225780_003A6F28.f3C = 0;
    D_U_00225780_003A6F28.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_U_001D9C50_003A6F28[j] = 1.0f; D_U_001D9C58_003A6F28[j] = 0; } }
    D_U_001D5B94 = 2;
    D_U_001D9C5C_003A6F28 = 1;
    D_U_001D9C60_003A6F28 = 0x34;
    p = &D_00143950_003A6F28;
    if (p->f6 != 0) {
        D_U_00225780_003A6F28.f4C = 0;
        dst = D_U_00225780_003A6F28.f58 + 0x8E000;
        n = D_160C40_003A6F28.r[D_U_00225780_003A6F28.f30].fC;
        off = D_160C40_003A6F28.r[D_U_00225780_003A6F28.f30].f8;
        if (n > 0) {
            func_U_0039D510(dst, off + D_160C40_003A6F28.f1284, n);
            func_U_0039D6C8(1);
            D_U_00225780_003A6F28.f4C = dst;
        }
    }
    if (D_1CCFD0_003A6F28.f4 != 0) {
        func_U_00385B60(6);
        func_U_0039D6C8(1);
        func_U_003A13B0(0);
    } else {
        func_U_003A13B0(0);
        func_U_00385B60(6);
    }
    if (D_1CCFD0_003A6F28.f4 != 0) func_U_0039D6C8(1);
    func_U_003A1870();
    func_U_003A2BC0();
    func_U_0039DAE0(D_U_00225780_003A6F28.f30 + 4000, 0);
    while (D_1CCFD0_003A6F28.f76 != 0 || D_1CCFD0_003A6F28.f9E != 3 || D_1CCFD0_003A6F28.f98 >= 7000) {
        func_U_0039EE68();
        func_12C908(0);
    }
    D_U_00225780_003A6F28.f48 = -3;
    func_U_0039C710();
    func_U_003A13B0(1);
    for (i = 0; D_U_00225780_003A6F28.f48 < i; i--) func_12C908(0);
    return 1;
}
/* localdecomp:end func_U_003A1AD0 */
