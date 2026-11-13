#include "common.h"

/* NTSC-U counterpart of func_L39_0053D1C0 (src/levels/shared/L39_00537998.c): 0.4 -> 0.333333 */
extern void func_0038CF68_0053CA28(void *, void *, f32);

/* localdecomp:start func_L39_0053CA28 */
extern f32 func_0038CEA8_0053CA28(void *);
extern void func_0038CF68_0053CA28(void *, void *, f32);

void func_L39_0053CA28(u8 *a0, u8 *b) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q = *(u8 **)(p + 80);
    s32 d;
    s32 e;
    f32 *v;
    f32 *dst;

    if (q != 0 && q[0x1A14] != 0) {
        e = q[0x44EE];
        d = q[0x44ED];
        if (e == 3) {
            d += 2;
        } else {
            d += 1;
        }
        d = d % 256;
        e = (e + 1) % 4;
        *(s32 *)(b + 8) = (d << 8) | e;
        if (b[3] == 8) {
            v = (f32 *)(p + 32);
            if (0.333333343f < func_0038CEA8_0053CA28(v)) {
                func_0038CF68_0053CA28(v, v, 0.333333343f);
            }
            dst = (f32 *)(b + 24);
            dst[0] = *(f32 *)(p + 32);
            dst[1] = v[1];
            dst[2] = v[2];
        }
    }
}
/* localdecomp:end func_L39_0053CA28 */
