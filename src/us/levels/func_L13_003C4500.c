#include "common.h"

/* NTSC-U counterpart of func_L13_003C66C8 (src/levels/shared/L13_003C66C8.c): 25 -> 30; 75 -> 90; 0.07 -> 0.0583333 */
/* localdecomp:start func_L13_003C4500 */
/* PAL version of the NTSC-U draft of func_L13_003C4500 (nonmatching/levels/func_L13_003C4500.c) */
typedef int u128_003C66C8 __attribute__((mode(TI)));

extern u128_003C66C8 D_L13_001DEC00[];
extern u8 D_L13_001D66E0_003C4500[] __attribute__((section(".sdata")));
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L13_003C4500(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    u128_003C66C8 p[2];
    u16 t;
    f32 f;

    t = *(u16 *)(a0 + 0x96);
    if (t == 0) {
        p[0] = D_L13_001DEC00[0];
        p[1] = D_L13_001DEC00[1];
        *(u16 *)(a0 + 0x96) = func_0037E208(30, 90);
        f = 0.0583333373f;
        func_003886E8(v, D_L13_001D66E0_003C4500, f);
        func_L02_003E0520(a0, &p[func_0037E1D8(2)], 3.0f, v, 10, 0, f, 1.0f, 10.0f, 1.0f, 0);
    } else {
        *(u16 *)(a0 + 0x96) = t - 1;
    }
}
/* localdecomp:end func_L13_003C4500 */
