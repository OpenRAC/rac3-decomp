#include "common.h"

/* NTSC-U counterpart of func_L01_00366EA8 (src/levels/shared/L01_00363E68.c): 60 Hz steps (0.045, 0.01, 0.006, pi/10 for PAL's x1.2 values) */
/* localdecomp:start func_L01_00366120 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);

void func_L01_00366120(f32 *a, f32 *b, f32 *c, s32 index, s32 active) {
    if (active) {
        *a += 0.045f;
        if (*a > 1.0f) *a = 1.0f;
    } else {
        if (*a < 0.1f) {
            *a += 0.01f;
            if (*a > 0.1f) *a = 0.1f;
        } else {
            *a -= 0.006f;
            if (*a < 0.1f) *a = 0.1f;
        }
    }
    *b = func_00389380(*b, *a * 0.31415927f);
    c[index + 4] = func_00388978(*b * 0.5f);
    c[7] = func_00388960(*b * 0.5f);
}
/* localdecomp:end func_L01_00366120 */
