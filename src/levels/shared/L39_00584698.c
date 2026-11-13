#include "common.h"

/* localdecomp:start func_L39_00584698 */
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

extern S_00584698 D_L39_0025C600;
extern G_00584698 D_L39_001F0A00;
extern P_00584698 *D_L39_00241164;
__asm__(".extern D_L39_00241164, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_L39_00240300;
__asm__(".extern D_L39_00240300, 16");
extern s16 D_L39_00225664[];
extern s32 D_L39_0025CE90[];
extern u8 D_L39_0025F500[];
extern f32 D_L39_0024B9D0;
extern u8 D_001A58C7[];
extern u32 D_001A4B6C[];
extern u8 D_001D6D84_sda;
__asm__(".extern D_001D6D84_sda, 1");

extern s32 func_L39_005BF798(int, int, int, int, int);
extern void func_L01_003FF4E8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_0045A6F0(void);
extern s32 func_L39_005C29A0(s32, s32, s32);
extern void func_L01_00400100(void);
extern s32 func_0038CAD0(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_0032CA80(void);
extern void func_L01_004001E8(void);
extern s32 func_L39_005BF840(s32, s32);
extern s32 func_00392B20(void *, s32);
extern s32 func_L39_0059A4A8(void *);
extern s32 func_L01_004BA800(void);
extern void func_L39_005F1718(void);

void func_L39_00584698(void) {
    s32 n;
    D_001D6D84_sda = 0;
    if (D_L39_002403FC & 1) {
        D_001D6D84_sda = 1;
        func_L39_005BF798(4, 1, 1, 0, 0);
        return;
    }
    if (D_L39_0025C600.f28 >= 1 && D_L39_0025C600.f28 <= 4) {
        if (D_L39_00241164->f1A0 & 0xF000000000UL) {
            D_L39_0025C600.f28 = 5;
        }
    }
    switch (D_L39_0025C600.f28) {
    case 0:
        if (D_L39_00225664[0] == 0) {
            n = 0;
            func_L01_003FF4E8(0x1FDC, 0x1FDD, 0x2056, 1, 0x28, 0x50, 1, 0xA, 0x20, 0, n++);
            func_L01_003FF4E8(0x20B9, 0x20BA, 0x20BB, 2, 0x28, 0x50, 0, 2, 0x82, 2, n++);
            func_L01_003FF4E8(0x2090, 0x2091, 0x2096, 3, 0x28, 0x50, 0, 6, 0x38, 6, n++);
            func_L01_003FF4E8(0x2097, 0x2098, 0x2099, 4, 0x28, 0x50, 0, 2, 0x50, 2, n++);
            func_L01_003FF4E8(0x209A, 0x209B, 0x20A4, 5, 0x28, 0x50, 0, 0xA, 0x20, 0xA, n++);
            func_L01_003FF4E8(0x2090, 0x20A5, 0x20B4, 6, 0x28, 0x50, 0, 2, 0xA0, 6, n++);
            func_L01_003FF4E8(0x20B5, 0x20B6, 0x20B8, 7, 0x28, 0x50, 0, 2, 0xA0, 6, n++);
            func_L01_003FF4E8(0x20C2, 0x20C3, 0x20D0, 8, 0x28, 0x50, 0, 2, 0x96, 5, n++);
            func_L01_003FF4E8(0x20BC, 0x20BD, 0x20C1, 9, 0x28, 0x50, 0, 5, 0x38, 5, n++);
            func_L01_003FF4E8(0, 0x208B, 0x208B, 0xA, 0, 0xA0, 0, 1, 0x64, 1, n++);
            func_L01_003FF4E8(0, 0x20E8, 0x20E8, 0xB, 0, 0xA0, 0, 1, 0x64, 1, n++);
            func_L01_003FF4E8(0, 0x208A, 0x208A, 0xC, 0, 0xA0, 0, 1, 0x64, 1, n++);
            func_L01_003FF4E8(0, 0x20D2, 0x20D2, 0xD, 0, 0xA0, 0, 1, 0x64, 1, n++);
            func_L01_003FF4E8(0, 0x20D4, 0x20D4, 0xE, 0, 0x50, 0, 1, 0xC8, 6, n++);
            func_L01_003FF4E8(0x20D5, 0x20D6, 0x20E5, 0xF, 0x28, 0x50, 0, 5, 0x38, 5, n++);
            func_L01_003FF4E8(0x20D5, 0x20E6, 0x20E7, 0x10, 0x28, 0x50, 0, 2, 0x96, 9, n++);
            func_L01_003FF4E8(0, 0x20E9, 0x20E9, 0x11, 0, 0x50, 0, 1, 0xC8, 6, n++);
            D_L39_0025C600.f1E = 0;
            D_L39_0025CE90[0] = n;
            D_L39_0025C600.f1C = 0;
            D_L39_0025C600.f26 = 0;
            if (func_L01_0045A6F0() == 3) {
                D_L39_0025C600.f2C = 0;
            } else {
                D_L39_0025C600.f2C = 100;
            }
            D_L39_0025C600.f22 = -1;
            D_L39_0025C600.f24 = -1;
            D_L39_0025C600.f370 = 8;
            D_L39_0025C600.f374 = 0x17F;
            D_L39_0025C600.f378 = (f32)D_L39_00240300 * 2.2f * 1.2f;
            D_L39_0025C600.f37C = 0.1305483f;
            D_L39_0025C600.f380 = 5;
            D_L39_0025C600.f384 = 0.03f;
            D_L39_0025C600.f388 = 0x12;
            func_L39_005C29A0(D_L39_0025C600.w8,
                              D_L39_001F0A00.t0[D_001A58C7[0]].a + D_L39_001F0A00.base,
                              D_L39_001F0A00.t0[D_001A58C7[0]].b);
            D_L39_0025C600.f28 = 1;
        }
        break;
    case 1:
        if (D_L39_00225664[0] == 0) {
            func_L01_00400100();
            D_L39_0025C600.f28 = 2;
        }
        break;
    case 2:
        func_L39_005C29A0(D_L39_0025C600.w[D_L39_0025C600.f1C],
                          D_L39_001F0A00.t1[D_L39_0025C600.f1E].a + D_L39_001F0A00.base,
                          D_L39_001F0A00.t1[D_L39_0025C600.f1E].b);
        D_L39_0025C600.f28 = 3;
        break;
    case 3:
        if (D_L39_00225664[0] == 0) {
            if (func_0038CAD0(&D_L39_0025C600.f2C)) {
                D_L39_0025C600.f26 = 1;
                D_L39_0025C600.f1C ^= 1;
                D_L39_0025C600.f1E++;
                if (D_L39_0025C600.f1E >= 0xD) {
                    D_L39_0025C600.f1E -= 0xD;
                }
                func_L39_005C29A0(D_L39_0025C600.w[D_L39_0025C600.f1C],
                                  D_L39_001F0A00.t1[D_L39_0025C600.f1E].a + D_L39_001F0A00.base,
                                  D_L39_001F0A00.t1[D_L39_0025C600.f1E].b);
                D_L39_0025C600.f28 = 4;
            }
        }
        break;
    case 4:
        func_003C4138(&D_L39_0024B9D0, 0.0f, 0.080000006f);
        if (func_L01_0032CA80()) {
            func_L01_004001E8();
            if (D_L39_0025C600.f28 != 5) {
                D_L39_0025C600.f20++;
                if (D_L39_0025C600.f20 >= 5) {
                    D_L39_0025C600.f20 = 0;
                    D_L39_0025C600.f28 = 3;
                }
            }
        }
        break;
    case 5:
        if (func_L01_0045A6F0() == 3) {
            func_L39_005BF840(0, 0);
            D_L39_0025C600.f28 = 0;
        } else if (func_00392B20(D_L39_0025F500, 0x1C)) {
            func_L39_0059A4A8(D_L39_0025F500);
            D_L39_0025C600.f28 = 6;
        }
        break;
    case 6:
        if (D_001A4B6C[0] & 0x10000000) {
            if (func_L01_004BA800() == 0) {
                func_L39_005BF798(3, 1, 7, 0, 0);
                D_L39_0025C600.f28 = 0;
            }
        }
        break;
    }
    func_L39_005F1718();
}
/* localdecomp:end func_L39_00584698 */

INCLUDE_ASM("asm/levels", func_L39_00584E70);
