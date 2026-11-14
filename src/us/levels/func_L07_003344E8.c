#include "common.h"

/* localdecomp:start func_L07_003344E8 */
typedef struct { u8 pad[8]; s32 w8; } S_G2660;
typedef struct { u8 pad0[0x2808]; u8 *target; u8 pad1[0x44]; s32 w2850; } S_G4BE0;
extern S_G2660 D_00142660;
extern S_G4BE0 D_001A4BE0;
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L07_003A0BC0(s32, s32, s32, s32);

s32 func_L07_003344E8(u8 *a0) {
    u8 *p;
    u8 *t;
    s32 r;

    p = *(u8 **)(a0 + 0x68);
    if ((D_00142660.w8 >> 3) >= D_001A4BE0.w2850) {
        switch (func_0037E1D8(3)) {
        case 0:
            if (!(*(s32 *)(p + 0xE0) & 0x40)) {
                r = func_L07_003A0BC0(0x59, (s32)a0, 0, 0x78);
                *(s32 *)(p + 0xE0) |= 0x40;
                return r;
            }
        case 1:
            if (!(*(s32 *)(p + 0xE0) & 0x80)) {
                r = func_L07_003A0BC0(0x5A, (s32)a0, 0, 0x78);
                *(s32 *)(p + 0xE0) |= 0x80;
                return r;
            }
            break;
        }
    }
    if ((D_00142660.w8 >> 2) >= D_001A4BE0.w2850) {
        switch (func_0037E1D8(3)) {
        case 0:
            if (!(*(s32 *)(p + 0xE0) & 0x100)) {
                r = func_L07_003A0BC0(0x57, (s32)a0, 0, 0x78);
                *(s32 *)(p + 0xE0) |= 0x100;
                return r;
            }
        case 1:
            if (!(*(s32 *)(p + 0xE0) & 0x200)) {
                r = func_L07_003A0BC0(0x58, (s32)a0, 0, 0x78);
                *(s32 *)(p + 0xE0) |= 0x200;
                return r;
            }
            break;
        }
    }
    t = D_001A4BE0.target;
    if (t != 0) {
        switch (*(s16 *)(t + 0xAA)) {
        case 0x1A18:
            if (func_0037E1D8(5) == 0) {
                func_L07_003A0BC0(0x5B, (s32)a0, 0, 0x78);
                return;
            }
            func_L07_003A0BC0((u8)func_0037E208(0x54, 0x56), (s32)a0, 0, 0x78);
            return;
        case 0x1769:
        case 0x195E:
        case 0x19BE:
        case 0x19D2:
        case 0x1D88:
        case 0x1D89:
        case 0x1D8B:
        case 0x1D8C:
            func_L07_003A0BC0((u8)func_0037E208(0x54, 0x56), (s32)a0, 0, 0x78);
            return;
        }
    }
    func_L07_003A0BC0((u8)func_0037E208(0x52, 0x53), (s32)a0, 0, 0x78);
}
/* localdecomp:end func_L07_003344E8 */
