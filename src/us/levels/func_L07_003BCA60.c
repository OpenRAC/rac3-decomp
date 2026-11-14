#include "common.h"

/* NTSC-U counterpart of func_L07_003BE3A8 (src/levels/07_annihilation_nation/L07_003BCDD0.c) */
extern void func_L07_003BCA60(void *, int);

/* localdecomp:start func_L07_003BCA60 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003BCA60(void *arg0, s32 kind) {
    u8 *obj = (u8 *)arg0;

    switch (kind) {
    case 1:
    case 2:
    case 3:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 0);
        }
        break;
    case 4:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 5:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 10:
        if (obj[0x43] != 2) {
            func_003BE4F0(obj, 2, 0, 8);
        }
        break;
    case 6:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 7:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 9:
        if (obj[0x43] != 1) {
            func_003BE4F0(obj, 1, 0, 8);
        }
        break;
    case 11:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 8);
        }
        break;
    case 12:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 8);
        }
        break;
    case 13:
        if (obj[0x43] != 5) {
            func_003BE4F0(obj, 5, 0, 8);
        }
        break;
    case 14:
        if (obj[0x43] != 6) {
            func_003BE4F0(obj, 6, 0, 8);
        }
        break;
    case 15:
        if (obj[0x43] != 8) {
            func_003BE4F0(obj, 8, 0, 8);
        }
        break;
    case 16:
        if (obj[0x43] != 7) {
            func_003BE4F0(obj, 7, 0, 8);
        }
        break;
    case 17:
        if (obj[0x43] != 7) {
            func_003BE4F0(obj, 7, 0, 8);
        }
        break;
    }
    func_L01_00441FB8(obj, kind, -1);
}
/* localdecomp:end func_L07_003BCA60 */
