/* PAL port of the NTSC-U draft (round 8): PAL port of the NTSC-U draft: 9 diff with the file line plus `@ps2as` (the file is one function, so the flag could simply be added): callees func_00382498/func_00382468/func_0038CE20/func_L02_003E2E38, D_L13_001DEBD0, 25/75, 0.070000008f all match; left: retail sets f20 (li.s 0.07) before the jal of func_00382498 with the second `sq` in its delay slot and loads a0=25 before a1=75, gcc loads a1 first and sets f20 after the call; literal f, temp for the result, copy order, pointer copy, prototype types (u32, s16, K&R, u16/s16 return) and f declared first did not change it */
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
