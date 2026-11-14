#include "common.h"

/* localdecomp:start func_L07_003B4BE0 */
typedef struct {
    u8 p0[0x43];
    u8 b43;
    u8 p44[4];
    f32 f48;
    u8 p4C[0x1C];
    u8 *f68;
} R_B4BE0;
extern f32 func_L07_003B54D8(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003B4BE0(R_B4BE0 *a0, s32 a1) {
    u8 *p = a0->f68;

    switch (a1) {
    case 1:
        break;
    case 2:
        if (a0->b43 != 0x16) func_003BE4F0(a0, 0x16, 0, 0);
        break;
    case 4:
        if (a0->b43 != 1) func_003BE4F0(a0, 1, 0, 8);
        break;
    case 5:
        if (a0->b43 != 0) func_003BE4F0(a0, 0, 0, 10);
        break;
    case 6:
        if (a0->b43 != 0x11) func_003BE4F0(a0, 0x11, 0, 8);
        break;
    case 7:
        if (a0->b43 != 5) func_003BE4F0(a0, 5, 0, 4);
        break;
    case 8:
        if (func_L07_003B54D8(a0, p + 0x80) > 0.0f) {
            if (a0->b43 != 7) func_003BE4F0(a0, 7, 0, 3);
        } else {
            if (a0->b43 != 8) func_003BE4F0(a0, 8, 0, 3);
        }
        break;
    case 9:
        if (a0->b43 != 9) func_003BE4F0(a0, 9, 0, 4);
        break;
    case 10:
        if (a0->b43 != 10) func_003BE4F0(a0, 10, 0, 4);
        break;
    case 11:
        if (a0->b43 != 0x13) func_003BE4F0(a0, 0x13, 0, 4);
        break;
    case 12:
        if (a0->b43 != 0xB) func_003BE4F0(a0, 0xB, 0, 4);
        break;
    case 13:
        if (a0->b43 != 0xC) func_003BE4F0(a0, 0xC, 0, 4);
        break;
    case 14:
        if (a0->b43 != 0xD) func_003BE4F0(a0, 0xD, 0, 4);
        break;
    case 15:
        if (a0->b43 != 0x12) func_003BE4F0(a0, 0x12, 0, 4);
        break;
    case 17:
        if (a0->b43 != 0xE) func_003BE4F0(a0, 0xE, 0, 0x1E);
        break;
    case 18:
        if (a0->b43 != 0x18) func_003BE4F0(a0, 0x18, 0, 4);
        break;
    case 19:
        if (a0->b43 != 2) func_003BE4F0(a0, 2, 0, 4);
        a0->f48 = 0.5f;
        break;
    case 20:
        if (a0->b43 != 3) func_003BE4F0(a0, 3, 0, 4);
        break;
    case 21:
        if (a0->b43 != 4) func_003BE4F0(a0, 4, 0, 4);
        a0->f48 = 0.5f;
        break;
    case 22:
        if (a0->b43 != 0x16) func_003BE4F0(a0, 0x16, 0, 4);
        break;
    case 23:
        if (a0->b43 != 0x17) func_003BE4F0(a0, 0x17, 0, 4);
        break;
    case 24:
        if (a0->b43 != 0x14) func_003BE4F0(a0, 0x14, 0, 4);
        break;
    case 25:
        if (a0->b43 != 0x19) func_003BE4F0(a0, 0x19, 0, 4);
        break;
    }
    func_L01_00441FB8(a0, a1, -1);
}
/* localdecomp:end func_L07_003B4BE0 */
