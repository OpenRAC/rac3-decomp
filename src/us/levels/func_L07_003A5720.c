#include "common.h"

/* NTSC-U timing counterpart of func_L07_003A6EF8. */
/* localdecomp:start func_L07_003A5720 */
extern f32 D_L07_001DEF50;
extern void func_L01_00440A18(void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0046F808(void *, void *, s32, f32);

void func_L07_003A5720(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68) + 0xA0;
    f32 v[4];
    f32 t = 0.95f;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (D_L07_001DEF50 < t) {
            func_L01_00440A18(v, 0.0025000002f);
            v[2] = func_0037E250(0.004166667f, 0.016666668f);
            func_L01_0046F808(p, v, 0x44, func_0037E250(0.05f, 0.1f));
        }
        p += 0x10;
    }
}
/* localdecomp:end func_L07_003A5720 */
