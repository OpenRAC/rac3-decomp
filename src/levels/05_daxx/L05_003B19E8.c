#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003B19E8 */
extern f32 func_0038DAB8(f32, f32);

void func_L05_003B19E8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x = *(f32 *)(p + 0x27C);

    *(f32 *)(p + 0x280) = *(f32 *)(p + 0x284);
    *(f32 *)(p + 0x28C) = *(f32 *)(p + 0x290);
    *(f32 *)(p + 0x278) = x;
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(x, 3.14159274f);
}
/* localdecomp:end func_L05_003B19E8 */
