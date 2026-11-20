#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B39E0(void);

/* localdecomp:start func_003B39E0 */
extern s32 D_001D4CE8_003B39E0;
extern u8 D_001D9FA0_003B39E0;
extern u8 D_001D5BDC_003B39E0;
extern u8 D_001D5BDD;
extern u8 D_001D88A0[];
extern u8 D_001D88A8[];
extern u8 D_00240820[];
extern s32 D_001D4BC0_003B39E0[4] __attribute__((section(".sdata")));
extern s32 func_00381FF0(s32);
extern void func_11B2E8();
extern void func_0038E7E8_003B39E0(f32, f32, f32, unsigned long, u8 *, s32, f32, s32, s32, unsigned long, f32, f32);

void func_003B39E0(void) {
    u8 *text;
    s32 left = 0, show = 1, right = 0;

    text = D_001D88A0;
    switch (D_001D4CE8_003B39E0) {
    case 8:
        left = func_00381FF0(0x8e3); right = func_00381FF0(0x8df);
        text = (u8 *)func_00381FF0(0x1a3); break;
    case 14:
        if (D_001D9FA0_003B39E0) goto msg196;
    case 15:
        left = func_00381FF0(0x8e3); right = func_00381FF0(0x8df);
        text = (u8 *)func_00381FF0(0x1a0); break;
    case 12: case 13: case 31: case 32: text = (u8 *)func_00381FF0(0x1af); break;
    case 9: case 10: text = (u8 *)func_00381FF0(0x1ad); break;
    case 16: case 17: text = (u8 *)func_00381FF0(0x1ae); break;
    case 25: case 29: text = (u8 *)func_00381FF0(0x1ab); break;
    case 23: case 30: text = (u8 *)func_00381FF0(0x1ac); break;
    case 19: text = (u8 *)func_00381FF0(0x1b0); left = func_00381FF0(0x8de); break;
    case 20: text = (u8 *)func_00381FF0(0x1b2); left = func_00381FF0(0x8de); break;
    case 3: text = (u8 *)func_00381FF0(0x194); break;
    case 21: {
        if (D_001D9FA0_003B39E0) goto msg196;
        if (D_001D5BDC_003B39E0) {
            u8 *dst = D_00240820, *fmt = D_001D88A8;
            func_11B2E8(dst, fmt, func_00381FF0(0x199), 1, 1, func_00381FF0(0x19a));
            text = dst;
            left = func_00381FF0(0x8e2); right = func_00381FF0(0x8df);
        } else {
            u8 *dst = D_00240820, *fmt = D_001D88A8;
            func_11B2E8(dst, fmt, func_00381FF0(0x199), 1, 1, func_00381FF0(0x19a));
            text = dst;
            left = func_00381FF0(0x8e2);
        }
        break;
    }
    case 24:
        text = (u8 *)func_00381FF0(0x1b3);
        left = func_00381FF0(0x8de); break;
    case 22: text = (u8 *)func_00381FF0(0x1b1); left = func_00381FF0(0x8de); break;
    case 27: {
        u8 *dst, *fmt;
        left = func_00381FF0(0x8e2); right = func_00381FF0(0x8df);
        dst = D_00240820; fmt = D_001D88A8;
        func_11B2E8(dst, fmt, func_00381FF0(0x1a2), 1, 1, func_00381FF0(0x11e8));
        text = dst; break;
    }
    case 26:
        left = func_00381FF0(0x8e2); right = func_00381FF0(0x8df);
        text = (u8 *)func_00381FF0(0x1a5); break;
    case 4: case 5: case 6:
        if (D_001D5BDC_003B39E0 && !D_001D9FA0_003B39E0) {
            left = func_00381FF0(0x8e2); right = func_00381FF0(0x8df);
            text = (u8 *)func_00381FF0(0x19c);
        } else if (D_001D5BDD) {
            left = func_00381FF0(0x8e2); text = (u8 *)func_00381FF0(0x19c);
        } else {
            if (D_001D9FA0_003B39E0) text = (u8 *)func_00381FF0(0x196);
            else text = (u8 *)func_00381FF0(0x19e);
            left = func_00381FF0(0x197);
        }
        break;
    case 7:
    msg196: text = (u8 *)func_00381FF0(0x196); left = func_00381FF0(0x197); break;
    default: show = 0; break;
    }
    if (show) {
        if (text) {
            func_0038E7E8_003B39E0((f32)D_001D4BC0_003B39E0[2], (f32)D_001D4BC0_003B39E0[3], 1.0f, 0x8066ccff, text, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
        if (left) {
            func_0038E7E8_003B39E0((f32)(D_001D4BC0_003B39E0[2] - 100), (f32)(D_001D4BC0_003B39E0[3] + 70), 1.0f, 0x8066ccff, (u8 *)left, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
        if (right) {
            func_0038E7E8_003B39E0((f32)(D_001D4BC0_003B39E0[2] + 100), (f32)(D_001D4BC0_003B39E0[3] + 70), 1.0f, 0x8066ccff, (u8 *)right, -1, 1.0f, 1, 0, 0x80000000, 0.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_003B39E0 */
