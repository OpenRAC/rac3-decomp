#include "common.h"

/* localdecomp:start func_L07_003B6DA0 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003B6DA0(u8 *a0, s32 id) {
    switch (id) {
    case 1:
        break;
    case 2:
        if (a0[0x43] != 0xC) {
            func_003BE4F0(a0, 0xC, 0, 0);
        }
        break;
    case 3:
    case 4:
        break;
    case 5:
        if (a0[0x43] != 9) {
            func_003BE4F0(a0, 9, 0, 4);
        }
        break;
    case 6:
        if (a0[0x43] != 6) {
            func_003BE4F0(a0, 6, 0, 4);
        }
        break;
    case 7:
        if (a0[0x43] != 0xA) {
            func_003BE4F0(a0, 0xA, 0, 4);
        }
        break;
    case 8:
        if (a0[0x43] != 4) {
            func_003BE4F0(a0, 4, 0, 4);
        }
        break;
    case 9:
        if (a0[0x43] != 5) {
            func_003BE4F0(a0, 5, 0, 4);
        }
        break;
    case 10:
        if (a0[0x43] != 1) {
            func_003BE4F0(a0, 1, 0, 4);
        }
        break;
    case 11:
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 4);
        }
        break;
    case 12:
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 4);
        }
        break;
    case 13:
        if (a0[0x43] != 0xF) {
            func_003BE4F0(a0, 0xF, 0, 4);
        }
        break;
    case 14:
        if (a0[0x43] != 0xC) {
            func_003BE4F0(a0, 0xC, 0, 4);
        }
        break;
    case 15:
        if (a0[0x43] != 0xE) {
            func_003BE4F0(a0, 0xE, 0, 4);
        }
        break;
    case 16:
        if (a0[0x43] != 0xD) {
            func_003BE4F0(a0, 0xD, 0, 4);
        }
        break;
    case 17:
        if (a0[0x43] != 0x10) {
            func_003BE4F0(a0, 0x10, 0, 4);
        }
        break;
    }
    func_L01_00441FB8(a0, id, -1);
}
/* localdecomp:end func_L07_003B6DA0 */
