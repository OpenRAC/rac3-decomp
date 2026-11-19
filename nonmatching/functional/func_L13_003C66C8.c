/* functional: high. PAL near miss (9 diff): only the order of the 0.07 constant load and the a0/a1 setup differs; callees, constants and args verified against the PAL assembly. */
#include "common.h"

/* localdecomp:start func_L13_003C66C8 */
typedef int u128_t __attribute__((mode(TI)));
extern u128_t D_L13_001DEBD0[];
extern u8 D_L13_001D66E0[];
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, void *, s32, s32, f32, f32, f32, f32, f32, s32);

void func_L13_003C66C8(u8 *a0)
{
    f32 v0[4] __attribute__((aligned(16)));
    u128_t p[2];
    u16 t;
    f32 f;

    t = *(u16 *)(a0 + 0x96);
    if (t == 0) {
        f = 0.070000008f;
        p[0] = D_L13_001DEBD0[0];
        p[1] = D_L13_001DEBD0[1];
        *(u16 *)(a0 + 0x96) = func_00382498(25, 75);
        func_0038CE20(v0, D_L13_001D66E0, f);
        func_L02_003E2E38(a0, &p[func_00382468(2)], v0, 10, 0, 3.0f, f, 1.0f, 10.0f, 1.0f, 0);
    } else {
        *(u16 *)(a0 + 0x96) = t - 1;
    }
}
/* localdecomp:end func_L13_003C66C8 */
