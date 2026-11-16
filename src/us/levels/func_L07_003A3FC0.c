#include "common.h"

/* NTSC-U counterpart of PAL func_L07_003A5780. */
/* localdecomp:start func_L07_003A3FC0 */
void func_L07_003A3FC0(void *arg, s32 state)
{
    extern void func_003BE4F0(void *, s32, s32, s32);
    extern void func_L01_00441FB8(void *, s32, s32);
    extern void func_L07_003A48E8(void *, f32, f32);
    extern void func_L07_003DA3A0(s32, s32);
    extern void func_L07_003A4C18(void *);
    extern f32 func_0037E250(f32, f32);
    u8 *obj = arg;
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: case 5: break;
    case 2:
        if (obj[0x43]) func_003BE4F0(obj, 0, 0, 0);
        break;
    case 4:
        *(u16 *)(obj + 0x34) |= 0x5000;
        func_L07_003A48E8(obj, 0.100000009f, 0.0025f);
        if (obj[0x43] != 5) func_003BE4F0(obj, 5, 0, 4);
        break;
    case 6:
        *(s32 *)(p + 0x188) &= ~0x10;
        if (obj[0x43]) func_003BE4F0(obj, 0, 0, 8);
        func_L07_003DA3A0(*(s32 *)(p + 0x498), 0);
        break;
    case 7:
        func_L07_003A48E8(obj, 0.100000009f, 0.0025f);
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0025f;
        *(f32 *)(p + 0x178) = 0.100000009f;
        if (obj[0x43] != 5) func_003BE4F0(obj, 5, 0, 8);
        break;
    case 8:
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 0.036666669f, 0.0013888889f);
        if (obj[0x43] != 4) func_003BE4F0(obj, 4, 0, 8);
        break;
    case 9:
        *(s16 *)(p + 0x492) = 20;
        if (obj[0x43] != 3) func_003BE4F0(obj, 3, 0, 12);
        break;
    case 10:
        *(s32 *)(p + 0x188) |= 0x10;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0055555557f;
        *(f32 *)(p + 0x178) = 0.033333335f;
        if (obj[0x43] != 7) func_003BE4F0(obj, 7, 0, 6);
        break;
    case 11:
        *(s32 *)(p + 0x188) |= 0x10;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0055555557f;
        *(f32 *)(p + 0x178) = 0.033333335f;
        if (obj[0x43] != 6) func_003BE4F0(obj, 6, 0, 6);
        break;
    case 12:
        if (obj[0x43] != 12) func_003BE4F0(obj, 12, 0, 5);
        break;
    case 13:
        *(s16 *)(p + 0x492) = 5;
        if (obj[0x43] != 13) func_003BE4F0(obj, 13, 0, 3);
        break;
    case 14:
        func_L07_003A48E8(obj, 0.012500001f, 0.00027777778f);
        *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        func_L07_003DA3A0(*(s32 *)(p + 0x498), 1);
        if (obj[0x43] != 15) func_003BE4F0(obj, 15, 0, 3);
        *(f32 *)(obj + 0x48) = 0.75f;
        break;
    case 15:
        if (obj[0x43] != 8) func_003BE4F0(obj, 8, 0, 5);
        break;
    case 16:
        *(s16 *)(p + 0x492) = 5;
        if (obj[0x43] != 9) func_003BE4F0(obj, 9, 0, 3);
        break;
    case 17:
        func_L07_003A48E8(obj, 0.012500001f, 0.00027777778f);
        *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        func_L07_003A4C18(obj);
        if (obj[0x43] != 10) func_003BE4F0(obj, 10, 0, 3);
        break;
    case 18:
        *(f32 *)(p + 0x49C) = func_0037E250(6.0f, 7.5f);
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 0.036666669f, 0.0013888889f);
        if (obj[0x43] != 4) func_003BE4F0(obj, 4, 0, 6);
        break;
    case 19:
        *(f32 *)(p + 0x49C) = func_0037E250(6.0f, 7.5f);
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 0.100000009f, 0.0025f);
        if (obj[0x43] != 5) func_003BE4F0(obj, 5, 0, 8);
        break;
    case 20:
        *(s32 *)(p + 0x188) |= 0x10;
        func_L07_003A48E8(obj, 0.033333335f, 0.0055555557f);
        if (obj[0x43] != 7) func_003BE4F0(obj, 7, 0, 6);
        break;
    case 21:
        *(s32 *)(p + 0x188) |= 0x10;
        func_L07_003A48E8(obj, 0.033333335f, 0.0055555557f);
        if (obj[0x43] != 6) func_003BE4F0(obj, 6, 0, 6);
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003A3FC0 */
