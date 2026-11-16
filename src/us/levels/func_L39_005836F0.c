#include "common.h"

/* NTSC-U counterpart of func_L39_00584698 (src/levels/shared/L39_00584698.c) */
/* localdecomp:start func_L39_005836F0 */
/* Log:
 */
typedef struct {
    s32 w[2];
    s32 w8;
    u8 padC[0x1C - 0xC];
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    s16 f28;
    u8 pad2A[2];
    s32 f2C;
    u8 pad30[0x370 - 0x30];
    s32 f370;
    s32 f374;
    f32 f378;
    f32 f37C;
    s32 f380;
    f32 f384;
    s32 f388;
} S_00584698;

typedef struct { s32 a; s32 b; } E_00584698;
typedef struct {
    u8 pad0[0x694];
    s32 base;
    u8 pad698[0xC50 - 0x698];
    E_00584698 t0[6];
    E_00584698 t1[13];
} G_00584698;
typedef struct { u8 pad0[0x1A0]; unsigned long f1A0; } P_00584698;

extern S_00584698 D_L39_0025C700;
extern G_00584698 D_L39_001F0B80;
extern P_00584698 *D_L39_002412E4;
__asm__(".extern D_L39_002412E4, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern s32 D_L39_00240480;
__asm__(".extern D_L39_00240480, 16");
extern s16 D_L39_002257E4[];
extern s32 D_L39_0025CF90[];
extern u8 D_L39_0025F600[];
extern f32 D_L39_0024BAD0;
extern u8 D_001A5A47[];
extern u32 D_001A4CEC[];
extern u8 D_001D6D84_sda_005836F0;
__asm__(".extern D_001D6D84_sda_005836F0, 1");

extern s32 func_L39_005BD7D8(int, int, int, int, int);
extern void func_L01_003FD578(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004573E8(void);
extern s32 func_L39_005C0958(s32, s32, s32);
extern void func_L01_003FE190(void);
extern s32 func_00388398(void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern s32 func_L01_0032C5E8(void);
extern void func_L01_003FE278(void);
extern s32 func_L39_005BD880(s32, s32);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_L39_005991D8(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L39_005EF018(void);

void func_L39_005836F0(void) {
    s32 n;
    D_001D6D84_sda_005836F0 = 0;
    if (D_L39_0024057C & 1) {
        D_001D6D84_sda_005836F0 = 1;
        func_L39_005BD7D8(4, 1, 1, 0, 0);
        return;
    }
    if (D_L39_0025C700.f28 >= 1 && D_L39_0025C700.f28 <= 4) {
        if (D_L39_002412E4->f1A0 & 0xF000000000UL) {
            D_L39_0025C700.f28 = 5;
        }
    }
    switch (D_L39_0025C700.f28) {
    case 0:
        if (D_L39_002257E4[0] == 0) {
            n = 0;
            func_L01_003FD578(0x1EC1, 0x1EC2, 0x1F3B, 0x1, 0x28, 0x50, 0x1, 0xA, 0x20, 0, n++);
            func_L01_003FD578(0x1F9E, 0x1F9F, 0x1FA0, 0x2, 0x28, 0x50, 0, 0x2, 0x82, 0x2, n++);
            func_L01_003FD578(0, 0x1F3C, 0x1F3C, 0x3, 0, 0xA0, 0, 0x1, 0x64, 0x1, n++);
            func_L01_003FD578(0x1F3D, 0x1F3E, 0x1F41, 0x4, 0x28, 0x50, 0, 0x4, 0x50, 0x5, n++);
            func_L01_003FD578(0x1F42, 0x1F43, 0x1F45, 0x5, 0x28, 0x50, 0, 0x3, 0x68, 0x4, n++);
            func_L01_003FD578(0x1F42, 0x1F46, 0x1F46, 0x6, 0x28, 0x50, 0, 0x1, 0xC8, 0x5, n++);
            func_L01_003FD578(0x1F47, 0x1F48, 0x1F49, 0x7, 0x28, 0x50, 0, 0x2, 0x54, 0x2, n++);
            func_L01_003FD578(0x1F4A, 0x1F4B, 0x1F4F, 0x8, 0x28, 0x50, 0, 0x2, 0xA0, 0x1, n++);
            func_L01_003FD578(0x1F50, 0x1F51, 0x1F55, 0x9, 0x28, 0x50, 0, 0x5, 0x40, 0x6, n++);
            func_L01_003FD578(0x1F50, 0x1F56, 0x1F57, 0xA, 0x28, 0x50, 0, 0x2, 0xA0, 0x6, n++);
            func_L01_003FD578(0x1F50, 0x1F58, 0x1F5A, 0xB, 0x28, 0x50, 0, 0x1, 0x12C, 0xA, n++);
            func_L01_003FD578(0x1F5B, 0x1F5C, 0x1F60, 0xC, 0x28, 0x50, 0, 0x5, 0x38, 0x6, n++);
            func_L01_003FD578(0x1F5B, 0x1F61, 0x1F61, 0xD, 0x28, 0x50, 0, 0x1, 0xC8, 0x9, n++);
            func_L01_003FD578(0x1F5B, 0x1F62, 0x1F65, 0xE, 0x28, 0x50, 0, 0x4, 0x38, 0x4, n++);
            func_L01_003FD578(0x1F5B, 0x1F66, 0x1F66, 0xF, 0x28, 0x50, 0, 0x1, 0xC8, 0x6, n++);
            func_L01_003FD578(0x1F5B, 0x1F67, 0x1F69, 0x10, 0x28, 0x50, 0, 0x3, 0x54, 0x3, n++);
            func_L01_003FD578(0x1F5B, 0x1F6A, 0x1F6A, 0x11, 0x28, 0x50, 0, 0x1, 0xC8, 0x4, n++);
            func_L01_003FD578(0x1F5B, 0x1F6B, 0x1F6E, 0x12, 0x28, 0x50, 0, 0x4, 0x38, 0x4, n++);
            func_L01_003FD578(0x1FA7, 0x1FA8, 0x1FB5, 0x13, 0x28, 0x50, 0, 0x2, 0x96, 0x5, n++);
            func_L01_003FD578(0x1FA1, 0x1FA2, 0x1FA6, 0x14, 0x28, 0x50, 0, 0x5, 0x38, 0x5, n++);
            func_L01_003FD578(0, 0x1F70, 0x1F70, 0x15, 0, 0xA0, 0, 0x1, 0x64, 0x1, n++);
            func_L01_003FD578(0, 0x1FCC, 0x1FCC, 0x16, 0, 0xA0, 0, 0x1, 0x64, 0x1, n++);
            func_L01_003FD578(0, 0x1F6F, 0x1F6F, 0x17, 0, 0xA0, 0, 0x1, 0x64, 0x1, n++);
            func_L01_003FD578(0, 0x1FB6, 0x1FB6, 0x18, 0, 0xA0, 0, 0x1, 0x64, 0x1, n++);
            func_L01_003FD578(0, 0x1FB8, 0x1FB8, 0x19, 0, 0x50, 0, 0x1, 0xC8, 0x6, n++);
            func_L01_003FD578(0x1FB9, 0x1FBA, 0x1FC9, 0x1A, 0x28, 0x50, 0, 0x5, 0x38, 0x5, n++);
            func_L01_003FD578(0x1FB9, 0x1FCA, 0x1FCB, 0x1B, 0x28, 0x50, 0, 0x2, 0x96, 0x9, n++);
            func_L01_003FD578(0, 0x1FCD, 0x1FCD, 0x1C, 0, 0x50, 0, 0x1, 0xC8, 0x6, n++);
            D_L39_0025C700.f1E = 0;
            D_L39_0025CF90[0] = n;
            D_L39_0025C700.f1C = 0;
            D_L39_0025C700.f26 = 0;
            if (func_L01_004573E8() == 3) {
                D_L39_0025C700.f2C = 0;
            } else {
                D_L39_0025C700.f2C = 120;
            }
            D_L39_0025C700.f22 = -1;
            D_L39_0025C700.f24 = -1;
            D_L39_0025C700.f370 = 10;
            D_L39_0025C700.f374 = 0x1CC;
            D_L39_0025C700.f378 = (f32)D_L39_00240480 * 2.2f;
            D_L39_0025C700.f37C = 0.10869564861059189f;
            D_L39_0025C700.f380 = 5;
            D_L39_0025C700.f384 = 0.03f;
            D_L39_0025C700.f388 = 0x12;
            func_L39_005C0958(D_L39_0025C700.w8,
                              D_L39_001F0B80.t0[D_001A5A47[0]].a + D_L39_001F0B80.base,
                              D_L39_001F0B80.t0[D_001A5A47[0]].b);
            D_L39_0025C700.f28 = 1;
        }
        break;
    case 1:
        if (D_L39_002257E4[0] == 0) {
            func_L01_003FE190();
            D_L39_0025C700.f28 = 2;
        }
        break;
    case 2:
        func_L39_005C0958(D_L39_0025C700.w[D_L39_0025C700.f1C],
                          D_L39_001F0B80.t1[D_L39_0025C700.f1E].a + D_L39_001F0B80.base,
                          D_L39_001F0B80.t1[D_L39_0025C700.f1E].b);
        D_L39_0025C700.f28 = 3;
        break;
    case 3:
        if (D_L39_002257E4[0] == 0) {
            if (func_00388398(&D_L39_0025C700.f2C)) {
                D_L39_0025C700.f26 = 1;
                D_L39_0025C700.f1C ^= 1;
                D_L39_0025C700.f1E++;
                if (D_L39_0025C700.f1E >= 0xD) {
                    D_L39_0025C700.f1E -= 0xD;
                }
                func_L39_005C0958(D_L39_0025C700.w[D_L39_0025C700.f1C],
                                  D_L39_001F0B80.t1[D_L39_0025C700.f1E].a + D_L39_001F0B80.base,
                                  D_L39_001F0B80.t1[D_L39_0025C700.f1E].b);
                D_L39_0025C700.f28 = 4;
            }
        }
        break;
    case 4:
        func_003BEBF8(&D_L39_0024BAD0, 0.0f, 0.06666667f);
        if (func_L01_0032C5E8()) {
            func_L01_003FE278();
            if (D_L39_0025C700.f28 != 5) {
                D_L39_0025C700.f20++;
                if (D_L39_0025C700.f20 >= 5) {
                    D_L39_0025C700.f20 = 0;
                    D_L39_0025C700.f28 = 3;
                }
            }
        }
        break;
    case 5:
        if (func_L01_004573E8() == 3) {
            func_L39_005BD880(0, 0);
            D_L39_0025C700.f28 = 0;
        } else if (func_0038E2E8(D_L39_0025F600, 0x1C)) {
            func_L39_005991D8(D_L39_0025F600);
            D_L39_0025C700.f28 = 6;
        }
        break;
    case 6:
        if (D_001A4CEC[0] & 0x10000000) {
            if (func_L01_004B6C68() == 0) {
                func_L39_005BD7D8(3, 1, 7, 0, 0);
                D_L39_0025C700.f28 = 0;
            }
        }
        break;
    }
    func_L39_005EF018();
}
/* localdecomp:end func_L39_005836F0 */
