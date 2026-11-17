/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003BE010, the NTSC-U twin of func_L09_003BF890, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L09_003BE010 */
extern u8 D_001A4C60[];
extern f32 func_00388800(void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);

void func_L09_003BE010(u8 *self) {
    f32 lo = 0.022916667f;
    f32 k = 20.0f;
    f32 d = func_00388800(self + 0x10, D_001A4C60);
    f32 a;
    f32 b;
    if (d >= 40.0f) {
        a = 0.005f;
        b = 0.10000001f;
    } else if (d <= k) {
        a = 0.004861111f;
        b = lo;
    } else {
        func_L01_00458A70(self, 0.005f, (d - k) / k * 5.9770832f + lo, 0.0034906587f, 0.034906588f);
        return;
    }
    func_L01_00458A70(self, a, b, 0.0034906587f, 0.034906588f);
}
/* localdecomp:end func_L09_003BE010 */
