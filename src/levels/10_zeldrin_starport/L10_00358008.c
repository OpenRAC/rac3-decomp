#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_00358008 */
extern u8 D_001A4C60[];
extern u8 *D_L10_001DF380[] __attribute__((section(".sdata")));
extern f32 func_0038CF00(void *, void *);

s32 func_L10_00358008(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 d;
    f32 z;
    f32 h;
    f32 a;
    f32 b;
    s32 r;

    if (*(s32 *)(v + 0x90) != -1) {
        d = func_0038CF00(D_001A4C60, v + 0x70);
        b = func_0038CF00(D_001A4C60, D_L10_001DF380[0] + *(s32 *)(v + 0x90) * 0x80 + 0x30);
        a = d;
        r = 0;
        if (!(b < a)) {
            r = 1;
        }
        return r;
    }
    if (*(f32 *)(v + 0xA0) == 0.0f) {
        return 2;
    }
    z = *(f32 *)(m + 0x18);
    h = *(f32 *)(D_001A4C60 + 8);
    a = fabs_asm(h - z);
    b = fabs_asm(h - (z + *(f32 *)(v + 0xA0)));
    r = 0;
    if (!(b < a)) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L10_00358008 */

INCLUDE_ASM("asm/levels", func_L10_003580D8);
