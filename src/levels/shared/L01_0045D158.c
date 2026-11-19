#include "common.h"

/* localdecomp:start func_L01_0045D158 */
extern u8 *func_L01_00448FF0(u8 *);
extern f32 func_L01_00451580(u8 *);
extern s32 D_L01_001D673C __attribute__((section(".sdata")));

s32 func_L01_0045D158(u8 *a0, u8 *a1) {
    u8 *s0;
    s32 s2;
    f32 f;
    if (*(f32 *)(a0 + 0x18) <= *(f32 *)(a1 + 0x90)) {
        return 0;
    }
    s0 = func_L01_00448FF0(a0);
    if (s0 == 0) {
        return 0;
    }
    s2 = 0;
    if (D_L01_001D673C != 0) {
        f = func_L01_00451580(a0 + 0x10);
        if (f < *(f32 *)(s0 + 0x40) - 0.5f) {
            s2 = 1;
        }
    } else {
        f = *(f32 *)(a0 + 0x18);
        if (f < *(f32 *)(s0 + 0x40) - 0.5f) {
            s2 = 1;
        }
    }
    return s2;
}
/* localdecomp:end func_L01_0045D158 */
