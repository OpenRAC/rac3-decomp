#include "common.h"

/* localdecomp:start func_L20_00443310 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_0043FFF0.c */
extern s32 D_L20_001E71F4[];
extern void func_0038CF68(u8 *, u8 *, f32);

void func_L20_00443310(u8 *a0, s32 a1, s32 a2) {
    s32 cur = D_L20_001E71F4[0];
    f32 t;
    u8 *p;
    u8 *q;
    s32 i;

    if (cur < (a1 * 5 + 2) / 6) {
        return;
    }
    if ((a2 * 5 + 2) / 6 < cur) {
        return;
    }
    t = (f32)(cur - (a1 * 5 + 2) / 6) / (f32)(((a2 - a1) * 5 + 2) / 6);
    if (a0 != 0) {
        q = a0 + 0xE0;
        p = a0 + 0xC0;
        for (i = 1; i >= 0; i--) {
            func_0038CF68(p, p, t);
            p += 0x10;
        }
        func_0038CF68(q, q, (1.0f - t) + 1.0f);
    }
}
/* localdecomp:end func_L20_00443310 */
