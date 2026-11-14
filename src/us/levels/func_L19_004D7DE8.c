#include "common.h"

/* NTSC-U counterpart of func_L19_004DC2E8 (src/levels/19_thran_asteroid_belt/L19_004DC2E8.c): 75 -> 90 */
/* localdecomp:start func_L19_004D7DE8 */
typedef struct B_4DC2E8 { char p0[0x1A8]; s32 x1A8; } B_4DC2E8;
typedef struct A_4DC2E8 { char p0[0x24]; B_4DC2E8 *x24; } A_4DC2E8;
typedef struct S_4DC2E8 {
    char p0[0x88]; f32 x88;
    char p1[0x118 - 0x8C]; f32 x118;
    char p2[0x1DC - 0x11C]; s16 x1DC; s16 x1DE;
    char p3[0x338 - 0x1E0]; f32 x338; f32 x33C;
    char p4[0x350 - 0x340]; f32 x350; f32 x354;
    char p5[0x360 - 0x358]; s32 x360;
    char p6[4]; s16 x368;
    char p7[2]; s16 x36C;
    char p8[0x46E - 0x36E]; u8 x46E;
    char p9[0x1470 - 0x46F]; s16 x1470;
    char p10[0x1474 - 0x1472]; u8 x1474; u8 x1475; u8 x1476; u8 x1477; u8 x1478; u8 x1479;
    u8 x147A; u8 x147B; u8 x147C; u8 x147D; u8 x147E; u8 x147F;
    char p11[0x25C0 - 0x1480]; A_4DC2E8 *x25C0; s32 x25C4;
    char p12[4]; s32 x25CC;
    char p13[0x25E4 - 0x25D0]; u8 x25E4;
    char p14[0x25EA - 0x25E5]; u8 x25EA;
    char p15[3]; u8 x25EE;
    char p16[0x2848 - 0x25EF]; f32 x2848;
    char p17[4]; s32 x2850;
} S_4DC2E8;

extern S_4DC2E8 D_001A4BE0;
extern u8 D_00142CAD[];
extern s32 D_00142668[];
extern void func_00388468(void *, s32);
extern void func_L01_004DC1C0(s32);
extern void func_L01_004E3EC0(void);
extern s32 func_L19_004EECE0(s32, s32);

void func_L19_004D7DE8(void) {
    s16 id;
    u8 sv;
    s32 t;
    id = D_001A4BE0.x1470;
    sv = D_001A4BE0.x147F;
    func_00388468(&D_001A4BE0.x1470, 0x10);
    D_001A4BE0.x147F = sv;
    D_001A4BE0.x1470 = id;
    D_001A4BE0.x25EA = 0;
    D_001A4BE0.x368 = 0;
    if (D_001A4BE0.x25EE != 0) return;
    t = 0;
    if (D_001A4BE0.x360 != 0 || (D_001A4BE0.x25C4 == 0x80 && D_001A4BE0.x33C < 0.4f)) t = 1;
    if (id == -1) return;
    if (id == 2 || id == 0x11 || id == 0x12) {
        if (D_001A4BE0.x1DE == 0 && (D_001A4BE0.x36C == 0 || D_001A4BE0.x33C < 2.5f)) {
            D_001A4BE0.x1479 = 1;
            if (D_001A4BE0.x25E4 == 0 && D_00142CAD[0] != 0) D_001A4BE0.x368 = 1;
        }
    }
    if (id == 0x11) {
        if (D_001A4BE0.x1DC == 0 && D_001A4BE0.x36C == 0 && D_001A4BE0.x25CC != 7) {
            func_L01_004DC1C0(D_00142668[0] / 8);
            D_001A4BE0.x1DC = 0x5A;
            func_L19_004EECE0(0xB1, 1);
        }
    }
    if (id == 0xE) {
        D_001A4BE0.x1476 = 1;
        D_001A4BE0.x2848 = 0.2f;
        D_001A4BE0.x350 = D_001A4BE0.x338 + 0.2f;
    }
    if (id == 0) {
        f32 d = D_001A4BE0.x350 - D_001A4BE0.x338;
        D_001A4BE0.x2848 = d;
        if (d < 0.85f && 0.25f < d) D_001A4BE0.x25EA = 1;
        D_001A4BE0.x1476 = 1;
    }
    if (id == 0xB) D_001A4BE0.x147D = 1;
    if (id == 4) D_001A4BE0.x1475 = 1;
    if (id == 7) D_001A4BE0.x1474 = 1;
    if (id == 0xD) D_001A4BE0.x147E = 1;
    if (id == 1) D_001A4BE0.x1477 = id;
    if (id == 8 || id == 0x12) D_001A4BE0.x147C = 1;
    if (id == 0xC) D_001A4BE0.x147C = 1;
    if (D_001A4BE0.x1475 != 0 && t != 0 && D_001A4BE0.x25CC != 0x10 && D_001A4BE0.x25CC != 0x14 && D_001A4BE0.x25CC != 7) {
        func_L19_004EECE0(0x30, 1); return;
    }
    if (D_001A4BE0.x1477 != 0 && t != 0 && D_001A4BE0.x25E4 == 1 && D_001A4BE0.x25C4 != 0x7F) {
        func_L19_004EECE0(0x7F, 1); return;
    }
    if (D_001A4BE0.x1477 != 0 && t != 0 && (D_001A4BE0.x25C4 != 0x38 || D_001A4BE0.x46E != 0)) {
        func_L01_004E3EC0();
        if (D_001A4BE0.x2850 != 0) { func_L19_004EECE0(0x38, 1); return; }
        if (D_001A4BE0.x25C0->x24->x1A8 != 0) { func_L19_004EECE0(0x7E, 1); return; }
        func_L19_004EECE0(0x39, 1); return;
    }
    if (D_001A4BE0.x25E4 == 1) {
        if (D_001A4BE0.x147E != 0 && D_001A4BE0.x25C4 != 0x50) {
            f32 a = D_001A4BE0.x88; f32 b = D_001A4BE0.x350;
            f32 e = __builtin_fabsf(b - (a + 0.15f));
            if (e < 0.5f && 0.0f < b - a && (D_001A4BE0.x118 < 0.0f || D_001A4BE0.x25C4 == 0x80)) {
                func_L19_004EECE0(0x50, 1); return;
            }
        }
    } else if (D_001A4BE0.x147E != 0 && D_001A4BE0.x25C4 != 0x81) {
        f32 a = D_001A4BE0.x88; f32 b = D_001A4BE0.x350;
        f32 e = __builtin_fabsf(b - (a + 0.25f));
        if (e < 1.0f && 0.0f < b - a && (D_001A4BE0.x118 < 0.0f || D_001A4BE0.x25C4 == 0x80)) {
            func_L01_004E3EC0();
            func_L19_004EECE0(0x81, 1); return;
        }
    }
}
/* localdecomp:end func_L19_004D7DE8 */
