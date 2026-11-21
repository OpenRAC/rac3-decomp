#include "common.h"

/* NTSC-U counterpart of func_L39_005E31D8 (src/levels/shared/L39_005E31D8.c) */
/* localdecomp:start func_L39_005E0C70 */
extern s32 D_L39_00240578;
typedef struct { s32 w; s32 h; s32 x; s32 y; } Scr_005E31D8;
extern Scr_005E31D8 D_L39_00240480 __attribute__((section(".sdata")));
extern u8 D_L39_00242B2C;
extern u8 D_L39_0024BF70_005E0C70;
extern char D_L39_00243B38[];
extern char D_L39_00243B40[];
extern char D_L39_00243B50[];
extern char D_L39_00243B68[];
extern char D_L39_002B5D70[];
extern u8 D_L39_00242B2D;
extern char *func_0037DF98(s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_00389FB8(f32, f32, unsigned long, char *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_L39_005E0C70(void) {
    char *a = D_L39_00243B38;
    char *b = 0;
    s32 ok = 1;
    char *c = 0;
    switch (D_L39_00240578) {
    case 8:
        b = func_0037DF98(0x8E3);
        c = func_0037DF98(0x8DF);
        a = func_0037DF98(0x1A3);
        break;
    case 14:
        if (D_L39_0024BF70_005E0C70 != 0) {
            a = func_0037DF98(0x195);
            b = func_0037DF98(0x11E8);
            break;
        }
    case 15:
        b = func_0037DF98(0x8E3);
        c = func_0037DF98(0x8DF);
        a = func_0037DF98(0x19F);
        break;
    case 12: case 13: case 31: case 32:
        a = func_0037DF98(0x1AF);
        break;
    case 9: case 10:
        a = func_0037DF98(0x1AD);
        break;
    case 16: case 17:
        a = func_0037DF98(0x1AE);
        break;
    case 25: case 29:
        a = func_0037DF98(0x1AB);
        break;
    case 23: case 30:
        a = func_0037DF98(0x1AC);
        break;
    case 19:
        a = func_0037DF98(0x1B0);
        b = func_0037DF98(0x8DE);
        break;
    case 20:
        a = func_0037DF98(0x1B2);
        b = func_0037DF98(0x8DE);
        break;
    case 3:
        a = func_0037DF98(0x194);
        break;
    case 21:
        if (D_L39_0024BF70_005E0C70 != 0) {
            a = func_0037DF98(0x195);
            b = func_0037DF98(0x11E8);
            break;
        }
        if (D_L39_00242B2C != 0) {
            func_00120048(D_L39_002B5D70, D_L39_00243B40, D_L39_00243B50, 1, 1, func_0037DF98(0x19A));
            a = D_L39_002B5D70;
            b = func_0037DF98(0x8E2);
            c = func_0037DF98(0x8DF);
        } else {
            a = func_0037DF98(0x198);
            b = func_0037DF98(0x11E8);
        }
        break;
    case 24:
        a = func_0037DF98(0x1B2);
        b = func_0037DF98(0x8DE);
        break;
    case 22:
        a = func_0037DF98(0x1B1);
        b = func_0037DF98(0x8DE);
        break;
    case 27:
        b = func_0037DF98(0x8E2);
        c = func_0037DF98(0x8DF);
        func_00120048(D_L39_002B5D70, D_L39_00243B40, D_L39_00243B68, 1, 1, func_0037DF98(0x11E8));
        a = D_L39_002B5D70;
        break;
    case 26:
        b = func_0037DF98(0x8E2);
        c = func_0037DF98(0x8DF);
        a = func_0037DF98(0x1A5);
        break;
    case 4: case 5: case 6:
        if (D_L39_00242B2C != 0 && D_L39_0024BF70_005E0C70 == 0) {
            b = func_0037DF98(0x8E2);
            c = func_0037DF98(0x8DF);
            a = func_0037DF98(0x19B);
        } else if (D_L39_00242B2D != 0) {
            b = func_0037DF98(0x8E2);
            a = func_0037DF98(0x19B);
        } else {
            if (D_L39_0024BF70_005E0C70 != 0) {
                a = func_0037DF98(0x195);
            } else {
                a = func_0037DF98(0x19D);
            }
            b = func_0037DF98(0x11E8);
        }
        break;
    case 7:
        a = func_0037DF98(0x195);
        b = func_0037DF98(0x11E8);
        break;
    default:
        ok = 0;
        break;
    }
    if (ok) {
        if (a != 0) func_00389FB8((f32)D_L39_00240480.x, (f32)D_L39_00240480.y, 0x8066CCFF, a, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        if (b != 0) func_00389FB8((f32)(D_L39_00240480.x - 100), (f32)(D_L39_00240480.y + 70), 0x8066CCFF, b, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        if (c != 0) func_00389FB8((f32)(D_L39_00240480.x + 100), (f32)(D_L39_00240480.y + 70), 0x8066CCFF, c, -1, 1.0f, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_005E0C70 */
