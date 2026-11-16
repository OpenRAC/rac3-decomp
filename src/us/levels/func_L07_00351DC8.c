#include "common.h"

/* NTSC-U counterpart of PAL func_L07_00352AC8. */
/* localdecomp:start func_L07_00351DC8 */
void func_L07_00351DC8(s32 arg, s32 state)
{
    extern void func_003BE4F0(void *, s32, s32, s32);
    extern void func_L01_00441FB8(void *, s32, s32);
    extern void func_00388830(void *, void *, f32);
    extern void func_L07_00353088();
    u8 *obj = (u8 *)arg;
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: case 5: break;
    case 2:
        if (obj[0x43]) func_003BE4F0(obj, 0, 0, 0);
        break;
    case 4:
        *(u16 *)(obj + 0x34) |= 0x5000;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0033333334f;
        *(f32 *)(p + 0x178) = 0.083333336f;
        if (obj[0x43] != 3) func_003BE4F0(obj, 3, 0, 8);
        break;
    case 6: case 7:
        if (obj[0x43]) func_003BE4F0(obj, 0, 0, 5);
        break;
    case 8: case 24:
        *(f32 *)(p + 0x178) = 0.041666668f;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0022222223f;
        if (*(f32 *)(p + 0x200) > *(f32 *)(p + 0x178)) {
            func_00388830(p + 0x1F0, p + 0x1F0, *(f32 *)(p + 0x178));
            *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        }
        if (obj[0x43] != 2) func_003BE4F0(obj, 2, 0, 3);
        break;
    case 9:
        *(f32 *)(p + 0x178) = 0.083333336f;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0033333334f;
        if (*(f32 *)(p + 0x200) > *(f32 *)(p + 0x178)) {
            func_00388830(p + 0x1F0, p + 0x1F0, *(f32 *)(p + 0x178));
            *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        }
        if (obj[0x43] != 3) func_003BE4F0(obj, 3, 0, 3);
        break;
    case 10:
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.005f;
        *(f32 *)(p + 0x178) = 0.13333334f;
        if (obj[0x43] != 4) func_003BE4F0(obj, 4, 0, 3);
        break;
    case 11:
        if (obj[0x43] != 5) func_003BE4F0(obj, 5, 0, 3);
        break;
    case 12:
        if (obj[0x43] != 6) func_003BE4F0(obj, 6, 0, 8);
        break;
    case 13:
        if (obj[0x43] != 10) func_003BE4F0(obj, 10, 8, 8);
        break;
    case 14:
        if (obj[0x43] != 11) func_003BE4F0(obj, 11, 8, 8);
        break;
    case 15:
        func_L07_00353088(obj);
        p[0x467] = 1;
        if (obj[0x43] != 12) func_003BE4F0(obj, 12, 10, 8);
        break;
    case 16:
        func_L07_00353088(obj);
        p[0x467] = 1;
        if (obj[0x43] != 13) func_003BE4F0(obj, 13, 4, 3);
        break;
    case 17:
        if (obj[0x43] != 14) func_003BE4F0(obj, 14, 0, 3);
        break;
    case 18:
        if (obj[0x43] != 8) func_003BE4F0(obj, 8, 0, 3);
        break;
    case 19:
        if (obj[0x43] != 7) func_003BE4F0(obj, 7, 0, 3);
        break;
    case 20:
        if (obj[0x43] != 9) func_003BE4F0(obj, 9, 5, 6);
        break;
    case 21:
        func_L07_00353088(obj);
        p[0x467] = 1;
        if (obj[0x43] != 15) func_003BE4F0(obj, 15, 10, 6);
        break;
    case 22:
        if (obj[0x43] != 16) func_003BE4F0(obj, 16, 9, 7);
        break;
    case 23:
        if (obj[0x43] != 17) func_003BE4F0(obj, 17, 0, 2);
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_00351DC8 */
