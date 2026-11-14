#include "common.h"

/* NTSC-U counterpart of func_L03_003A1158 (src/levels/03_starship_phoenix/L03_0039E470.c) */
/* localdecomp:start func_L03_0039F970 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L03_0032D348_0039F970(void *);
extern void func_L03_0032CFF8(void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_0039F970(u8 *self, s32 state) {
    u8 *s = *(u8 **)(self + 0x68);

    switch (state) {
    case 1:
    case 2:
        if (self[0x43] != 0) {
            func_003BE4F0(self, 0, 0, 0);
        }
        break;
    case 3:
        *(u16 *)(self + 0x34) |= 0x5000;
        break;
    case 5:
        func_L03_0032D348_0039F970(self);
        *(s32 *)(s + 0x188) &= ~0x10;
        if (self[0x43] != 0) {
            func_003BE4F0(self, 0, 0, 3);
        }
        break;
    case 6: {
        u8 *g = s + 0x150;
        *(f32 *)(g + 0x20) = 0.013888889f;
        *(f32 *)(g + 0x28) = 0.16666667f;
        *(f32 *)(g + 0x24) = 0.013888889f;
        if (self[0x43] != 2) {
            func_003BE4F0(self, 2, 0, 3);
        }
        break;
    }
    case 7:
        func_L03_0032CFF8(self);
        if (self[0x43] != 3) {
            func_003BE4F0(self, 3, 0, 3);
        }
        break;
    case 8:
        if (self[0x43] != 4) {
            func_003BE4F0(self, 4, 0, 3);
        }
        break;
    case 9: {
        u8 *g = s + 0x150;
        *(f32 *)(g + 0x20) = 0.00083333335f;
        *(s32 *)(g + 0x38) |= 0x10;
        *(f32 *)(g + 0x28) = 0.050000004f;
        *(f32 *)(g + 0x24) = 0.00083333335f;
        func_L03_0032CFF8(self);
        if (self[0x43] != 1) {
            func_003BE4F0(self, 1, 0, 8);
        }
        break;
    }
    case 10:
        self[0xBC] = 0xFF;
        *(s16 *)(s + 0x310) = func_0037E1D8(0x3C) + 0x3C;
        *(s32 *)(s + 0x304) = 0;
        break;
    case 11:
        if (self[0x43] != 5) {
            func_003BE4F0(self, 5, 0, 3);
        }
        break;
    case 12:
        if (self[0x43] != 0) {
            func_003BE4F0(self, 0, 0, 3);
        }
        break;
    case 13:
        if (self[0x43] != 6) {
            func_003BE4F0(self, 6, 5, 3);
        }
        break;
    case 14: {
        u8 *g = s + 0x150;
        *(f32 *)(g + 0x20) = 0.00055555557f;
        *(s32 *)(g + 0x38) |= 0x10;
        *(f32 *)(g + 0x28) = 0.033333335f;
        *(f32 *)(g + 0x24) = 0.00055555557f;
        if (self[0x43] != 1) {
            func_003BE4F0(self, 1, 0, 3);
        }
        break;
    }
    }
    func_L01_00441FB8(self, state, -1);
}
/* localdecomp:end func_L03_0039F970 */
