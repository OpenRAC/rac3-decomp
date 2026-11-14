#include "common.h"

/* NTSC-U counterpart of func_L39_005FFD20 (src/levels/shared/L39_005FFD10.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L39_005FD580 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(f32, s32, s32);

s32 func_L39_005FD580(f32 dt, f32 *a, s32 *cnt, s32 flag) {
    s32 r;
    u32 c, c0, c1;
    *cnt += 1;
    if (*cnt > 20) {
        *cnt = 20;
    }
    *a = func_00389380(*a, dt * 0.017453292f * 0.0166666675f);
    c = (*cnt * 5) << 24;
    c0 = c | 0xFF0F;
    c1 = c | 0xFFFFFF;
    r = func_003894A0(func_00388978(*a) * 0.5f + 0.5f, c0, c1);
    if (flag) {
        r = 0x600000FF;
    }
    return r;
}
/* localdecomp:end func_L39_005FD580 */
