#include "common.h"

/* NTSC-U counterpart of func_L07_003AEAA0 (src/levels/07_annihilation_nation/L07_003ADF68.c) */
void func_L07_003AD248(s32, s32);

/* localdecomp:start func_L07_003AD248 */
typedef int Quad_003AEAA0 __attribute__((mode(TI)));
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L07_003AD9C8(void *);
extern void func_L01_00441FB8(u8 *, s32, s32);

void func_L07_003AD248(s32 arg0, s32 state) {
    u8 *obj = (u8 *)arg0;
    u8 *p = *(u8 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 0);
        }
        break;
    case 3:
        break;
    case 4:
        *(s32 *)(p + 0x68) |= 0x404;
        *(f32 *)(p + 0x50) = 0.0033333334f;
        *(f32 *)(p + 0x54) = 0.0033333334f;
        *(f32 *)(p + 0x58) = 0.20000002f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        *(Quad_003AEAA0 *)(p + 0x260) = *(Quad_003AEAA0 *)(*(u8 **)(p + 0x240) + 0x10);
        *(f32 *)(p + 0x268) = *(f32 *)(obj + 0x18);
        break;
    case 5:
        break;
    case 6:
        *(s32 *)(p + 0x68) |= 0x414;
        *(f32 *)(p + 0x50) = 0.0033333334f;
        *(f32 *)(p + 0x54) = 0.0033333334f;
        *(f32 *)(p + 0x58) = 0.20000002f;
        func_L07_003AD9C8(obj);
        break;
    case 7:
        *(s32 *)(p + 0x68) = (*(s32 *)(p + 0x68) | 0x404) & ~0x10;
        *(f32 *)(p + 0x50) = 0.016666668f;
        *(f32 *)(p + 0x58) = 0.5f;
        *(f32 *)(p + 0x54) = 0.016666668f;
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 3);
        }
        break;
    case 8:
        if (obj[0x43] != 1) {
            func_003BE4F0(obj, 1, 0, 3);
        }
        break;
    case 9:
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 3);
        }
        *(s16 *)(p + 0x284) = 50;
        break;
    case 10:
        *(f32 *)(p + 0x50) = 0.0011111111f;
        *(f32 *)(p + 0x58) = 0.050000004f;
        *(f32 *)(p + 0x54) = 0.0011111111f;
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 3);
        }
        break;
    case 11:
    case 12:
    case 13:
        break;
    case 14:
        *(s16 *)(p + 0x284) = 30;
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003AD248 */
