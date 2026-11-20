#include "common.h"

/* NTSC-U counterpart of func_003A7328 (src/boot_elf/text/3A6C90.c): func_U_0038A5C0(5) -> (6), data shifted */
/* localdecomp:start func_U_003A71B0 */
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_003A71B0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_003A71B0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_003A71B0 r[1]; } S_160C40_003A71B0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_003A71B0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_003A71B0;
extern S_225780_003A71B0 D_U_00225780;
extern S_160C40_003A71B0 D_00160C40_003A71B0;
extern S_1CCFD0_003A71B0 D_001CCFD0_003A71B0;
extern S_143950_003A71B0 D_00143950_003A71B0;
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
extern s32 D_U_001D9C5C;
extern s32 D_U_001D9C60;
extern f32 D_U_001D9C50[1];
extern s32 D_U_001D9C58[1];
extern void func_U_0038CEA0(void *, s32, s32);
extern s32 func_U_003A7180(s32);
extern void func_U_0038A5C0(s32);
extern s32 func_U_003A6A90(s32);
extern void func_U_003A6F50(void);
extern void func_U_003A82A0(void);
extern void func_U_003A2E28(s32, s32);
extern s32 func_12C908(s32);
extern s32 func_U_003A1A58(void);
extern s32 func_U_003A2858(s32, s32, s32);
extern s32 func_U_003A2A10(s32);
extern s32 func_U_003A4548(void);
__asm__(".extern D_U_001D9C60, 4");
s32 func_U_003A71B0(s32 lvl) {
    s32 slot;
    s32 b;
    s32 i;
    s32 dst;
    s32 n;
    s32 off;
    S_143950_003A71B0 *p;
    if (lvl >= 0) { u32 *w = &D_142BA0[(u32)lvl >> 2]; *w |= 1 << (lvl & 0x1F); }
    slot = func_U_003A7180(lvl);
    if (slot < 0) return 0;
    func_U_0038CEA0(D_1A5DC0, 0, 0x230);
    func_U_0038CEA0(&D_U_00225780, 0, 0x1E0);
    func_U_0038CEA0(D_U_001D99E0, 0, 0x40);
    func_U_0038CEA0(D_U_001D9920, 0, 0x40);
    func_U_0038CEA0(D_U_001E22C0, 0, 0x40);
    func_U_0038CEA0(D_U_001E22C0 + 0x40, 0, 0x40);
    func_U_0038CEA0(D_U_001D9960, 0, 0x40);
    func_U_0038CEA0(D_U_001D99A0, 0, 0x40);
    b = D_U_0022766C[0];
    D_U_00225780.f30 = slot;
    D_U_00225780.f68 = b - 0x82000;
    D_U_00225780.f6C = b - 0x102000;
    D_U_001D5BC8 = 1.0f;
    D_U_001D5BCC = 0;
    D_U_00225780.f34 = 0;
    D_U_00225780.f3C = 0;
    D_U_00225780.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_U_001D9C50[j] = 1.0f; D_U_001D9C58[j] = 0; } }
    D_U_001D5B94 = 2;
    D_U_001D9C5C = 1;
    D_U_001D9C60 = 0x34;
    p = &D_00143950_003A71B0;
    if (p->f6 != 0) {
        D_U_00225780.f4C = 0;
        dst = D_U_00225780.f58 + 0x8E000;
        n = D_00160C40_003A71B0.r[D_U_00225780.f30].fC;
        off = D_00160C40_003A71B0.r[D_U_00225780.f30].f8;
        if (n > 0) {
            func_U_003A2858(dst, off + D_00160C40_003A71B0.f1284, n);
            func_U_003A2A10(1);
            D_U_00225780.f4C = dst;
        }
    }
    if (D_001CCFD0_003A71B0.f4 != 0) {
        func_U_0038A5C0(6);
        func_U_003A2A10(1);
        func_U_003A6A90(0);
    } else {
        func_U_003A6A90(0);
        func_U_0038A5C0(6);
    }
    if (D_001CCFD0_003A71B0.f4 != 0) func_U_003A2A10(1);
    func_U_003A6F50();
    func_U_003A82A0();
    func_U_003A2E28(D_U_00225780.f30 + 4000, 0);
    while (D_001CCFD0_003A71B0.f76 != 0 || D_001CCFD0_003A71B0.f9E != 3 || D_001CCFD0_003A71B0.f98 >= 7000) {
        func_U_003A4548();
        func_12C908(0);
    }
    D_U_00225780.f48 = -3;
    func_U_003A1A58();
    func_U_003A6A90(1);
    for (i = 0; D_U_00225780.f48 < i; i--) func_12C908(0);
    return 1;
}
/* localdecomp:end func_U_003A71B0 */
