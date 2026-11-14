#include "common.h"

/* NTSC-U counterpart of func_L02_003A2320 (src/levels/02_florana/L02_003A0EE8.c) */
/* localdecomp:start func_L02_003A0540 */
extern f32 func_0037E250(f32, f32);

void func_L02_003A0540(u8 *self) {
    u8 *s;

    if (self[0x20] == 0) {
        s = *(u8 **)(self + 0x68);
        *(f32 *)(s + 0x28) = func_0037E250(0.026179941f, 0.104719765f);
        *(s32 *)(s + 0x20) = 0x78;
        *(f32 *)(s + 0x24) = 0.65f;
        *(s16 *)(s + 0x2C) = 0x3C;
        *(f32 *)(s + 8) = 0.0027222224f;
        *(s16 *)(s + 0x2E) = 7;
        self[0x20] = 1;
        *(u16 *)(self + 0x34) |= 0x808;
    }
}
/* localdecomp:end func_L02_003A0540 */
