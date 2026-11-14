#include "common.h"

/* NTSC-U counterpart of func_L07_003BCB10 (src/levels/07_annihilation_nation/L07_003BB360.c) */
/* localdecomp:start func_L07_003BB200 */
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);

void func_L07_003BB200(u8 *obj, s32 state) {
    switch (state) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        break;
    case 11:
        if (obj[0x43] != 1) {
            func_003BE4F0(obj, 1, 0, 8);
        }
        break;
    case 12:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 8);
        }
        break;
    case 13:
    case 14:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 8);
        }
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003BB200 */
