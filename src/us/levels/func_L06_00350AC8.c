#include "common.h"

/* NTSC-U counterpart of func_L06_003517C0 (src/levels/shared/L06_00350D60.c) */
#include "vu0.h"

/* localdecomp:start func_L06_00350AC8 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L06_00350D70(u8 *, u8 *, s32);
extern void func_L06_00350CA8(u8 *, u8 *, s32, s32, s32);
void func_L06_00350AC8(u8 *a0, u8 *a1, s32 st) {
    if (a0[0x43] == st) {
        return;
    }
    switch (st) {
    case 5:
        func_L01_00458A70(a0, 0.004166667f, 0.16666667f, 0.0069813174f, 0.20943953f);
        func_L06_00350D70(a0, a1, 5);
        break;
    case 0x14:
        func_L01_00458A70(a0, 0.003888889f, 0.083333336f, 0.0069813174f, 0.20943953f);
        func_L06_00350CA8(a0, a1, 0x14, 0, 10);
        break;
    case 0x15:
        func_L01_00458A70(a0, 0.003888889f, -0.083333336f, 0.0069813174f, 0.20943953f);
        func_L06_00350CA8(a0, a1, 0x15, 0, 10);
        break;
    }
}
/* localdecomp:end func_L06_00350AC8 */
