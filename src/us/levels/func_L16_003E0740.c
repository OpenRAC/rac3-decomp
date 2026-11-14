#include "common.h"

/* NTSC-U counterpart of func_L16_003E2518 (src/levels/16_kerwan/L16_003E2518.c) */
/* localdecomp:start func_L16_003E0740 */
extern int func_L01_003D41E8(s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, s32);

void func_L16_003E0740(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u8 a5, u8 a6, f32 f12, f32 f13) {
    func_L01_003D41E8(a0, a1, a4, a6, a2, a3, 1.0f, 0.3f, 0.010833333f, f12, f13, a5);
}
/* localdecomp:end func_L16_003E0740 */
