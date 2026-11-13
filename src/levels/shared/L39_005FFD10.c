#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005FFD10);

/* localdecomp:start func_L39_005FFD20 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);

s32 func_L39_005FFD20(f32 dt, f32 *a, s32 *cnt, s32 flag) {
    s32 r;
    u32 c, c0, c1;
    *cnt += 1;
    if (*cnt > 20) {
        *cnt = 20;
    }
    *a = func_0038DAB8(*a, dt * 0.017453292f * 0.0200000014f);
    c = (*cnt * 5) << 24;
    c0 = c | 0xFF0F;
    c1 = c | 0xFFFFFF;
    r = func_0038DBD8(func_0038D0B0(*a) * 0.5f + 0.5f, c0, c1);
    if (flag) {
        r = 0x600000FF;
    }
    return r;
}
/* localdecomp:end func_L39_005FFD20 */

INCLUDE_ASM("asm/levels", func_L39_005FFDF8);
