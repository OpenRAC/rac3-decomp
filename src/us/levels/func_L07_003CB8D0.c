#include "common.h"

/* NTSC-U counterpart of func_L07_003CD2E8 (src/levels/07_annihilation_nation/L07_003CD2E8.c) */
void func_L07_003CB8D0(void *, s32);

/* localdecomp:start func_L07_003CB8D0 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L07_003CC908(void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003CB8D0(void *arg0, s32 state) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (state) {
    case 1:
    case 2:
    case 4:
        break;
    case 3:
        if (a0[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 0);
        }
        break;
    case 5:
    case 6:
        if (a0[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 5);
        }
        break;
    case 7:
        *(f32 *)(p + 0x170) = 0.002222222276031971f;
        *(f32 *)(p + 0x178) = 0.0416666679084301f;
        *(f32 *)(p + 0x174) = 0.002222222276031971f;
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 3);
        }
        break;
    case 8:
        *(f32 *)(p + 0x170) = 0.0055555556900799274f;
        *(f32 *)(p + 0x178) = 0.0833333358168602f;
        *(f32 *)(p + 0x174) = 0.0055555556900799274f;
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 3);
        }
        break;
    case 9:
        *(f32 *)(p + 0x170) = 0.004999999888241291f;
        *(f32 *)(p + 0x178) = 0.13333334028720856f;
        *(f32 *)(p + 0x174) = 0.004999999888241291f;
        if (a0[0x43] != 4) {
            func_003BE4F0(a0, 4, 0, 3);
        }
        break;
    case 10:
        if (a0[0x43] != 5) {
            func_003BE4F0(a0, 5, 0, 3);
        }
        break;
    case 11:
        if (a0[0x43] != 6) {
            func_003BE4F0(a0, 6, 0, 8);
        }
        break;
    case 12:
        if (a0[0x43] != 0xA) {
            func_003BE4F0(a0, 0xA, 0, 3);
        }
        break;
    case 13:
        if (a0[0x43] != 0xB) {
            func_003BE4F0(a0, 0xB, 0, 3);
        }
        break;
    case 14:
        func_L07_003CC908(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xC) {
            func_003BE4F0(a0, 0xC, 0, 3);
        }
        break;
    case 15:
        func_L07_003CC908(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xD) {
            func_003BE4F0(a0, 0xD, 0, 3);
        }
        break;
    case 16:
        func_L07_003CC908(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xD) {
            func_003BE4F0(a0, 0xD, 0, 3);
        }
        break;
    case 17:
        if (a0[0x43] != 0xE) {
            func_003BE4F0(a0, 0xE, 0, 3);
        }
        break;
    case 18:
        if (a0[0x43] != 8) {
            func_003BE4F0(a0, 8, 0, 3);
        }
        break;
    case 19:
        if (a0[0x43] != 7) {
            func_003BE4F0(a0, 7, 0, 3);
        }
        break;
    case 20:
        if (a0[0x43] != 9) {
            func_003BE4F0(a0, 9, 0, 3);
        }
        break;
    case 21:
        func_L07_003CC908(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xF) {
            func_003BE4F0(a0, 0xF, 0, 3);
        }
        break;
    case 22:
        if (a0[0x43] != 0x10) {
            func_003BE4F0(a0, 0x10, 0, 3);
        }
        break;
    case 23:
        if (a0[0x43] != 0x11) {
            func_003BE4F0(a0, 0x11, 0, 3);
        }
        break;
    }
    func_L01_00441FB8(a0, state, -1);
}
/* localdecomp:end func_L07_003CB8D0 */
