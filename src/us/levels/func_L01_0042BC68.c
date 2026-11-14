#include "common.h"

/* NTSC-U counterpart of func_L01_0042EA78 (src/levels/shared/L01_0042DB28.c): 0.025 -> 0.03 */
#include "vu0.h"

/* localdecomp:start func_L01_0042BC68 */
extern f32 D_L01_001D7148_0042BC68;
extern f32 D_L01_001D714C_0042BC68;
extern s32 D_L01_001D7150_0042BC68;
__asm__(".extern D_L01_001D7148_0042BC68, 4");
__asm__(".extern D_L01_001D714C_0042BC68, 4");
__asm__(".extern D_L01_001D7150_0042BC68, 4");
extern f32 func_L01_00442070(f32 f12);
extern s32 func_003894A0(s32, s32, f32);

void func_L01_0042BC68(void) {
    f32 d;

    D_L01_001D7148_0042BC68 += D_L01_001D714C_0042BC68 * 0.0299999993f;
    d = D_L01_001D714C_0042BC68;
    if (D_L01_001D7148_0042BC68 < 0.0f || 1.0f < D_L01_001D7148_0042BC68) {
        d = -d;
    }
    D_L01_001D714C_0042BC68 = d;
    D_L01_001D7150_0042BC68 = func_003894A0(0x20, 0x2020FF, func_L01_00442070(D_L01_001D7148_0042BC68));
}
/* localdecomp:end func_L01_0042BC68 */
