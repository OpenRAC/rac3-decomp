/* Level 06 shared (src/levels/shared/L06_00354F18.c) draft, 2026-11-15. 1 difference with the file's flags (-mvu0-use-vf0-vf2 @ps2as) once config/levels/divs_nops.txt has the row `func_L06_003551E8 2` (retail has two nops before its div.s; without the row there are 34 differences). Left: retail's range test of +0x20 is `andi` + `sltiu`, this C's is `andi` + `slti`. Every unsigned spelling (u8/u32 casts, u8/s8/u32/u16 variables, range tests, Moby's s8 state) drops the `andi` instead (44-53). The prototype order (void *, f32, f32, f32, s32) and the `(idx << 4) + table + 0x1C` address give retail's argument order and addu. */
#include "common.h"
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern s32 func_L06_00351390(u8 *a0, u8 *a1);
extern f32 func_L01_00477F20(void *, f32, f32, f32, s32);
typedef struct { f32 x, y, z, w; } E16;
s32 func_L06_003551E8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 state;
    s32 idx;

    if (*(s32 *)(v + 0x350) == 0 && func_L06_00351390(a0, v)) {
        func_L01_004450F0(a0, 1, 1);
        return 1;
    }
    state = a0[0x20];
    if ((state & 0xFF) == 15) {
        func_L01_004450F0(a0, 16, -1);
        return 1;
    }
    if ((state & 0xFF) == 1 || ((state - 4) & 0xFF) < 11) {
        idx = *(s32 *)(v + 0x344);
        *(f32 *)(v + 0x34C) = func_L01_00477F20(*(E16 **)(v + 0x358), 0.0f,
                              idx + *(f32 *)(v + 0x348) / *(f32 *)((idx << 4) + *(u8 **)(v + 0x358) + 0x1C), 20.0f, *(s32 *)(v + 0x27C))
                          * *(s32 *)(v + 0x27C);
        if ((u32)(a0[0x20] - 4) >= 11) {
            func_L01_004450F0(a0, 3, -1);
            return 1;
        }
    }
    return 0;
}
