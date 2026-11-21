#include "common.h"

/* localdecomp:start func_L13_003C66C8 */
/* PAL version of the NTSC-U draft of func_L13_003C4500 (nonmatching/levels/func_L13_003C66C8.c) */
typedef int u128_003C66C8 __attribute__((mode(TI)));

extern u128_003C66C8 D_L13_001DEBD0[];
extern u8 D_L13_001D66E0[] __attribute__((section(".sdata")));
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L13_003C66C8(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    u128_003C66C8 p[2];
    u16 t;
    f32 f;

    t = *(u16 *)(a0 + 0x96);
    if (t == 0) {
        p[0] = D_L13_001DEBD0[0];
        p[1] = D_L13_001DEBD0[1];
        *(u16 *)(a0 + 0x96) = func_00382498(25, 75);
        f = 0.07000001f;
        func_0038CE20(v, D_L13_001D66E0, f);
        func_L02_003E2E38(a0, &p[func_00382468(2)], 3.0f, v, 10, 0, f, 1.0f, 10.0f, 1.0f, 0);
    } else {
        *(u16 *)(a0 + 0x96) = t - 1;
    }
}
/* localdecomp:end func_L13_003C66C8 */
