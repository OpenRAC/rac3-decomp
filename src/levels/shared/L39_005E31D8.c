#include "common.h"

/* localdecomp:start func_L39_005E31D8 */
extern s32 D_L39_002403F8;
typedef struct { s32 w; s32 h; s32 x; s32 y; } Scr_005E31D8;
extern Scr_005E31D8 D_L39_00240300 __attribute__((section(".sdata")));
extern u8 D_L39_002429AC;
extern u8 D_L39_0024BE70;
extern char D_L39_00243A00[];
extern char D_L39_00243A08[];
extern char D_L39_002B5C70[];
extern u8 D_L39_002429AD;
extern char *func_00381FF0(s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_0038E7E8(f32, f32, unsigned long, char *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_L39_005E31D8(void) {
    char *a = D_L39_00243A00;
    char *b = 0;
    s32 ok = 1;
    char *c = 0;
    switch (D_L39_002403F8) {
    case 8:
        b = func_00381FF0(0x8E3);
        c = func_00381FF0(0x8DF);
        a = func_00381FF0(0x1A3);
        break;
    case 14:
        if (D_L39_0024BE70 != 0) {
            a = func_00381FF0(0x196);
            b = func_00381FF0(0x11E8);
            break;
        }
    case 15:
        b = func_00381FF0(0x8E3);
        c = func_00381FF0(0x8DF);
        a = func_00381FF0(0x1A0);
        break;
    case 12: case 13: case 31: case 32:
        a = func_00381FF0(0x1AF);
        break;
    case 9: case 10:
        a = func_00381FF0(0x1AD);
        break;
    case 16: case 17:
        a = func_00381FF0(0x1AE);
        break;
    case 25: case 29:
        a = func_00381FF0(0x1AB);
        break;
    case 23: case 30:
        a = func_00381FF0(0x1AC);
        break;
    case 19:
        a = func_00381FF0(0x1B0);
        b = func_00381FF0(0x8DE);
        break;
    case 20:
        a = func_00381FF0(0x1B2);
        b = func_00381FF0(0x8DE);
        break;
    case 3:
        a = func_00381FF0(0x194);
        break;
    case 21:
        if (D_L39_0024BE70 != 0) {
            a = func_00381FF0(0x196);
            b = func_00381FF0(0x11E8);
            break;
        }
        if (D_L39_002429AC != 0) {
            func_00120048(D_L39_002B5C70, D_L39_00243A08, func_00381FF0(0x199), 1, 1, func_00381FF0(0x19A));
            a = D_L39_002B5C70;
            b = func_00381FF0(0x8E2);
            c = func_00381FF0(0x8DF);
        } else {
            a = func_00381FF0(0x199);
            b = func_00381FF0(0x11E8);
        }
        break;
    case 24:
        a = func_00381FF0(0x1B2);
        b = func_00381FF0(0x8DE);
        break;
    case 22:
        a = func_00381FF0(0x1B1);
        b = func_00381FF0(0x8DE);
        break;
    case 27:
        b = func_00381FF0(0x8E2);
        c = func_00381FF0(0x8DF);
        func_00120048(D_L39_002B5C70, D_L39_00243A08, func_00381FF0(0x1A2), 1, 1, func_00381FF0(0x11E8));
        a = D_L39_002B5C70;
        break;
    case 26:
        b = func_00381FF0(0x8E2);
        c = func_00381FF0(0x8DF);
        a = func_00381FF0(0x1A5);
        break;
    case 4: case 5: case 6:
        if (D_L39_002429AC != 0 && D_L39_0024BE70 == 0) {
            b = func_00381FF0(0x8E2);
            c = func_00381FF0(0x8DF);
            a = func_00381FF0(0x19C);
        } else if (D_L39_002429AD != 0) {
            b = func_00381FF0(0x8E2);
            a = func_00381FF0(0x19C);
        } else {
            if (D_L39_0024BE70 != 0) {
                a = func_00381FF0(0x196);
            } else {
                a = func_00381FF0(0x19E);
            }
            b = func_00381FF0(0x11E8);
        }
        break;
    case 7:
        a = func_00381FF0(0x196);
        b = func_00381FF0(0x11E8);
        break;
    default:
        ok = 0;
        break;
    }
    if (ok) {
        if (a != 0) func_0038E7E8((f32)D_L39_00240300.x, (f32)D_L39_00240300.y, 0x8066CCFF, a, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        if (b != 0) func_0038E7E8((f32)(D_L39_00240300.x - 100), (f32)(D_L39_00240300.y + 70), 0x8066CCFF, b, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        if (c != 0) func_0038E7E8((f32)(D_L39_00240300.x + 100), (f32)(D_L39_00240300.y + 70), 0x8066CCFF, c, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_005E31D8 */

/* localdecomp:start func_L39_005E3618 */
/* from frontbin's func_003B3E60 (src/frontbin/3B3E60.c) */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_005E3618;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_005E3618;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_005E3618;
extern s32 D_L39_002403F8;
extern F_005E3618 D_L39_002403FC;
extern s32 D_001D82DC_sda;
extern u8 D_L39_002429AC;
extern u8 D_L39_002429AD;
extern u8 D_L39_0024BE70;
extern P_005E3618 *D_L39_00241164;
extern S_005E3618 D_001A43E0;
extern void func_L39_005BF840(s32, s32);
extern void func_L39_005A5D48(s32, s32);
extern void func_L01_003F19B0_005E3618(void);
extern void func_L39_005FBDA0(void);
__asm__(".extern D_001D82DC_sda, 4");
void func_L39_005E3618(void) {
    u32 p;
    switch (D_L39_002403F8) {
    case 3:
        if (D_L39_00241164->f1A4 & 0x40) {
            D_L39_002403FC.b0 = 0;
            D_001D82DC_sda++;
        }
        break;
    case 8:
        p = D_L39_00241164->f1A4;
        if (p & 0x20) {
            D_L39_002403FC.b3 = 1;
        } else if (p & 0x10) {
            if (D_L39_002429AD) { func_L39_005FBDA0(); break; }
            D_L39_002403FC.b5 = 1;
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            if (D_L39_002429AC == 0) func_L39_005BF840(6, 0);
        }
        break;
    case 15:
        p = D_L39_00241164->f1A4;
        if (p & 0x20) {
            func_L39_005A5D48(0, 0);
        } else if (p & 0x10) {
            if (D_L39_002429AD) { func_L39_005FBDA0(); break; }
            D_L39_002403FC.b5 = 1;
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            if (D_L39_002429AC == 0) D_001D82DC_sda++;
        }
        break;
    case 22:
        if (D_L39_00241164->f1A4 & 0x40) {
            D_L39_002403FC.b6 = 0;
            D_L39_002403FC.b10 = 0;
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            if (D_L39_002429AC == 0) D_001D82DC_sda++; else D_001D82DC_sda++;
        }
        break;
    case 19: case 20: case 24: {
        S_005E3618 *e = &D_001A43E0;
        if (e->f8 != 2) { func_L39_005FBDA0(); break; }
        if (e->f10 == 0) D_L39_002403F8 = 11;
        else if (e->f10 == -1) { e->f10 = 0; D_L39_002403F8 = 11; }
        else if (e->f10 == -2) D_L39_002403F8 = 7;
        else D_L39_002403F8 = 14;
        D_001D82DC_sda++;
        break;
    }
    case 14:
        if (D_L39_0024BE70 == 0) break;
    case 4: case 5: case 7:
        if (D_L39_00241164->f1A4 & 0x40) {
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            D_001D82DC_sda++;
        }
        break;
    case 21:
        if (D_L39_002429AC != 0 && D_L39_0024BE70 == 0) {
            if (D_L39_00241164->f1A4 & 0x40) {
                func_L01_003F19B0_005E3618();
                D_L39_002403FC.b1 = 0;
                D_L39_002403FC.b2 = 0;
                D_L39_002403FC.b5 = 1;
                func_L39_005FBDA0();
            }
        } else if (D_L39_002429AD) {
            if (D_L39_00241164->f1A4 & 0x40) func_L39_005FBDA0();
        } else if (D_L39_00241164->f1A4 & 0x40) {
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            D_001D82DC_sda++;
        }
        break;
    case 26: case 27:
        p = D_L39_00241164->f1A4;
        if (p & 0x40) {
            func_L01_003F19B0_005E3618();
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            D_L39_002403FC.b5 = 1;
            func_L39_005FBDA0();
        } else if (p & 0x10) {
            D_L39_002403FC.b5 = 1;
            D_001D82DC_sda++;
        }
        break;
    case 6:
        if (D_L39_002429AC != 0) {
            if (D_L39_0024BE70 == 0) {
                if (D_L39_00241164->f1A4 & 0x40) {
                    func_L01_003F19B0_005E3618();
                    D_L39_002403FC.b1 = 0;
                    D_L39_002403FC.b2 = 0;
                    func_L39_005FBDA0();
                }
                if (D_L39_00241164->f1A4 & 0x10) {
                    D_L39_002403FC.b5 = 1;
                    D_L39_002403FC.b1 = 0;
                    D_L39_002403FC.b2 = 0;
                    D_001D82DC_sda++;
                }
            } else if (D_L39_00241164->f1A4 & 0x40) {
                D_L39_002403FC.b5 = 1;
                D_L39_002403FC.b1 = 0;
                D_L39_002403FC.b2 = 0;
                D_001D82DC_sda++;
            }
        } else if (D_L39_002429AD) {
            if (D_L39_00241164->f1A4 & 0x20) func_L39_005FBDA0();
        } else if (D_L39_00241164->f1A4 & 0x40) {
            D_L39_002403FC.b5 = 1;
            D_L39_002403FC.b1 = 0;
            D_L39_002403FC.b2 = 0;
            D_001D82DC_sda++;
        }
        break;
    case 1: case 11: case 18:
        if (!D_L39_002403FC.b1 && !D_L39_002403FC.b2) D_001D82DC_sda++;
        break;
    case 2: case 9: case 10: case 12: case 13: case 16: case 17: case 23: case 25:
    case 28: case 29: case 30: case 31: case 32:
        break;
    }
}
/* localdecomp:end func_L39_005E3618 */
