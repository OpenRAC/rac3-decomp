/* NTSC-U draft (Claude wave C4): C of func_L07_003CB8D0, the NTSC-U twin of func_L07_003CD2E8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L07_003CB8D0", whose code is not the PAL one).
 * Worker's note: flags: MATCH with '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (jump table 23 entries checked equal to the disc's, case 1..23, states 1/2/4 default); the PAL file L07_003CC2B0.c has no @ps2as but the PAL twin func_L07_003CD2E8 has the same ...
 */
#include "common.h"

/* localdecomp:start func_L07_003CB8D0 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L07_003CC908(void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003CB8D0(u8 *a0, s32 state) {
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
        *(f32 *)(p + 0x170) = 0.0022222223f;
        *(f32 *)(p + 0x178) = 0.041666668f;
        *(f32 *)(p + 0x174) = 0.0022222223f;
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 3);
        }
        break;
    case 8:
        *(f32 *)(p + 0x170) = 0.0055555557f;
        *(f32 *)(p + 0x178) = 0.083333336f;
        *(f32 *)(p + 0x174) = 0.0055555557f;
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 3);
        }
        break;
    case 9:
        *(f32 *)(p + 0x170) = 0.005f;
        *(f32 *)(p + 0x178) = 0.13333334f;
        *(f32 *)(p + 0x174) = 0.005f;
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
