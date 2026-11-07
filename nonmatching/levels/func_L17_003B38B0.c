/* Near miss of func_L17_003B38B0: tools/check.py reports 4 diff.
   What differs: `abs.s $f1` is
   scheduled after `sub.s $f0, $f0, $f2` instead of before it, and the compare branches with
   `bc1tl` where retail has `bc1fl`; the first branch is 4 bytes longer as a result. All 16
   orders of the sub/abs/add statements give the same 4. */
#include "common.h"
typedef struct { u8 p0[0x68]; u8 *f68; } S_38B0_O;
extern u8 D_001A4C60[];
extern f32 D_001A4C68_c[];
extern u8 *D_L17_001DF180_b;
__asm__(".extern D_L17_001DF180_b, 16");
extern f32 func_0038CF00(void *, void *);
extern f32 fabsf(f32);
s32 func_L17_003B38B0(S_38B0_O *a0) {
    u8 *d = a0->f68;
    s32 v;
    if (*(s32 *)(d + 0xC0) != -1) {
        f32 a = func_0038CF00(D_001A4C60, d + 0x70);
        f32 b = func_0038CF00(D_001A4C60, D_L17_001DF180_b + (*(s32 *)(d + 0xC0) << 7) + 0x30);
        v = 0;
        if (b < a) v = 1;
        return v;
    } else {
        f32 f = *(f32 *)(d + 0xA4);
        f32 x, d1, d2;
        if (f == 0.0f) return 2;
        x = *(f32 *)((u8 *)a0 + 0x18);
        d1 = fabsf(D_001A4C68_c[0] - x);
        d2 = fabsf(D_001A4C68_c[0] - (x + f));
        v = 0;
        if (d2 < d1) v = 1;
        return v;
    }
}
