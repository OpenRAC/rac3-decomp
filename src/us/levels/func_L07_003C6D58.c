#include "common.h"

/* NTSC-U counterpart of func_L07_003C8718 (src/levels/07_annihilation_nation/L07_003C7468.c) */
extern void func_L07_003C6D58(void *, s32);

/* localdecomp:start func_L07_003C6D58 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003C6D58(void *arg0, s32 kind) {
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
    case 6:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 9:
        if (obj[0x43] != 1) {
            func_003BE4F0(obj, 1, 0, 8);
        }
        break;
    case 13:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 14:
        if (obj[0x43] != 5) {
            func_003BE4F0(obj, 5, 0, 8);
        }
        break;
    case 15:
        if (obj[0x43] != 6) {
            func_003BE4F0(obj, 6, 0, 8);
        }
        break;
    case 16:
        if (obj[0x43] != 7) {
            func_003BE4F0(obj, 7, 0, 8);
        }
        break;
    case 17:
        if (obj[0x43] != 8) {
            func_003BE4F0(obj, 8, 0, 8);
        }
        break;
    case 18:
        if (obj[0x43] != 9) {
            func_003BE4F0(obj, 9, 0, 8);
        }
        break;
    case 19:
        if (obj[0x43] != 10) {
            func_003BE4F0(obj, 10, 0, 8);
        }
        break;
    case 20:
        if (obj[0x43] != 11) {
            func_003BE4F0(obj, 11, 0, 8);
        }
        break;
    case 21:
        if (obj[0x43] != 12) {
            func_003BE4F0(obj, 12, 0, 8);
        }
        break;
    case 22:
        if (obj[0x43] != 14) {
            func_003BE4F0(obj, 14, 0, 8);
        }
        break;
    case 7:
    case 10:
    case 11:
    case 12:
    case 23:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 8);
        }
        break;
    case 24:
    case 25:
        if (obj[0x43] != 0xD) {
            func_003BE4F0(obj, 0xD, 0, 8);
        }
        *(f32 *)(obj + 0x48) = 0.15f;
        break;
    case 26:
        if (obj[0x43] != 0xB) {
            func_003BE4F0(obj, 0xB, 0, 0x1E);
        }
        break;
    }
    func_L01_00441FB8(obj, kind, -1);
}
/* localdecomp:end func_L07_003C6D58 */
