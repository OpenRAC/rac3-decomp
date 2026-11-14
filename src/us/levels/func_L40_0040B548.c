#include "common.h"

/* NTSC-U counterpart of func_L40_0040BC00 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern f32 func_00388770(void *v);
extern f32 func_00388800(void *a, void *b);

/* localdecomp:start func_L40_0040B548 */
extern f32 func_L01_00445168(void *a0, void *a1, f32 t, f32 a, f32 b, f32 c);

void func_L40_0040B548(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 t;

    t = func_00388770(v + 0x110) / 0.10000001f;
    if (t > 1.1f) {
        t = 1.1f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    if (t < 0.7f) {
        t = 0.7f;
    }
    func_L01_00445168(m + 0x48, v + 0x254, t, 0.1f, 0.1f, 0.0f);
    if (*(f32 *)(m + 0x48) == 0.0f) {
        func_00388800(m + 0x10, v + 0x310);
    }
}
/* localdecomp:end func_L40_0040B548 */
