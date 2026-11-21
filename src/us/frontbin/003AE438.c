#include "common.h"

/* NTSC-U counterpart of func_003B39E0 (frontbin). */
extern void func_U_003AE438(void);

/* localdecomp:start func_U_003AE438 */
extern s32 D_001D4CE8_003AE438;
extern u8 D_U_001DA020_003AE438;
extern u8 D_U_001D5BDC_003AE438;
extern u8 D_U_001D5BDD;
extern u8 D_U_001D88A0[];
extern u8 D_U_001D88A8[];
extern u8 D_U_001D88B8[];
extern u8 D_U_001D88D0[];
extern u8 D_U_0023C8A0[];
extern s32 D_001D4BC0_003AE438[4] __attribute__((section(".sdata")));
extern s32 func_U_0037DF98(s32);
extern void func_0011B2E8();
extern void func_U_00389FB8_003AE438(f32, f32, f32, unsigned long, u8 *, s32, f32, s32, s32, unsigned long, f32, f32);

void func_U_003AE438(void) {
    u8 *text;
    s32 left = 0, show = 1, right = 0;

    text = D_U_001D88A0;
    switch (D_001D4CE8_003AE438) {
    case 8:
        left = func_U_0037DF98(0x8e3); right = func_U_0037DF98(0x8df);
        text = (u8 *)func_U_0037DF98(0x1a3); break;
    case 14:
        if (D_U_001DA020_003AE438) goto msg196;
    case 15:
        left = func_U_0037DF98(0x8e3); right = func_U_0037DF98(0x8df);
        text = (u8 *)func_U_0037DF98(0x19f); break;
    case 12: case 13: case 31: case 32: text = (u8 *)func_U_0037DF98(0x1af); break;
    case 9: case 10: text = (u8 *)func_U_0037DF98(0x1ad); break;
    case 16: case 17: text = (u8 *)func_U_0037DF98(0x1ae); break;
    case 25: case 29: text = (u8 *)func_U_0037DF98(0x1ab); break;
    case 23: case 30: text = (u8 *)func_U_0037DF98(0x1ac); break;
    case 19: text = (u8 *)func_U_0037DF98(0x1b0); left = func_U_0037DF98(0x8de); break;
    case 20: text = (u8 *)func_U_0037DF98(0x1b2); left = func_U_0037DF98(0x8de); break;
    case 3: text = (u8 *)func_U_0037DF98(0x194); break;
    case 21: {
        if (D_U_001DA020_003AE438) goto msg196;
        if (D_U_001D5BDC_003AE438) {
            u8 *dst = D_U_0023C8A0, *fmt = D_U_001D88A8;
            func_0011B2E8(dst, fmt, D_U_001D88B8, 1, 1, func_U_0037DF98(0x19a));
            text = dst;
            left = func_U_0037DF98(0x8e2); right = func_U_0037DF98(0x8df);
        } else {
            u8 *dst = D_U_0023C8A0, *fmt = D_U_001D88A8;
            func_0011B2E8(dst, fmt, D_U_001D88B8, 1, 1, func_U_0037DF98(0x19a));
            text = dst;
            left = func_U_0037DF98(0x8e2);
        }
        break;
    }
    case 24:
        text = (u8 *)func_U_0037DF98(0x1b3);
        left = func_U_0037DF98(0x8de); break;
    case 22: text = (u8 *)func_U_0037DF98(0x1b1); left = func_U_0037DF98(0x8de); break;
    case 27: {
        u8 *dst, *fmt;
        left = func_U_0037DF98(0x8e2); right = func_U_0037DF98(0x8df);
        dst = D_U_0023C8A0; fmt = D_U_001D88A8;
        func_0011B2E8(dst, fmt, D_U_001D88D0, 1, 1, func_U_0037DF98(0x11e8));
        text = dst; break;
    }
    case 26:
        left = func_U_0037DF98(0x8e2); right = func_U_0037DF98(0x8df);
        text = (u8 *)func_U_0037DF98(0x1a5); break;
    case 4: case 5: case 6:
        if (D_U_001D5BDC_003AE438 && !D_U_001DA020_003AE438) {
            left = func_U_0037DF98(0x8e2); right = func_U_0037DF98(0x8df);
            text = (u8 *)func_U_0037DF98(0x19b);
        } else if (D_U_001D5BDD) {
            left = func_U_0037DF98(0x8e2); text = (u8 *)func_U_0037DF98(0x19b);
        } else {
            if (D_U_001DA020_003AE438) text = (u8 *)func_U_0037DF98(0x195);
            else text = (u8 *)func_U_0037DF98(0x19d);
            left = func_U_0037DF98(0x197);
        }
        break;
    case 7:
    msg196: text = (u8 *)func_U_0037DF98(0x195); left = func_U_0037DF98(0x197); break;
    default: show = 0; break;
    }
    if (show) {
        if (text) {
            func_U_00389FB8_003AE438((f32)D_001D4BC0_003AE438[2], (f32)D_001D4BC0_003AE438[3], 1.0f, 0x8066ccff, text, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
        if (left) {
            func_U_00389FB8_003AE438((f32)(D_001D4BC0_003AE438[2] - 100), (f32)(D_001D4BC0_003AE438[3] + 70), 1.0f, 0x8066ccff, (u8 *)left, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
        if (right) {
            func_U_00389FB8_003AE438((f32)(D_001D4BC0_003AE438[2] + 100), (f32)(D_001D4BC0_003AE438[3] + 70), 1.0f, 0x8066ccff, (u8 *)right, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_U_003AE438 */
