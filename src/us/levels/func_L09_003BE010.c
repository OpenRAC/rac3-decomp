#include "common.h"

/* NTSC-U counterpart of func_L09_003BF890 (src/levels/09_tyhrranosis/L09_003BF890.c) */
#include "vu0.h"

/* localdecomp:start func_L09_003BE010 */
extern f32 func_00388800(void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern u8 D_001A4C60[];
void func_L09_003BE010(u8 *a0)
{
    f32 d = func_00388800(a0 + 0x10, D_001A4C60);
    f32 lo = 0.02291666716337204f;

    if (d >= 40.0f) {
        func_L01_00458A70(a0, 0.004999999888241291f, 0.10000000894069672f, 0.0034906587097793818f, 0.03490658849477768f);
    } else if (d <= 20.0f) {
        func_L01_00458A70(a0, 0.004861111287027597f, lo, 0.0034906587097793818f, 0.03490658849477768f);
    } else {
        func_L01_00458A70(a0, 0.004999999888241291f, (d - 20.0f) / 20.0f * 5.977083206176758f + lo, 0.0034906587097793818f, 0.03490658849477768f);
    }
}
/* localdecomp:end func_L09_003BE010 */
