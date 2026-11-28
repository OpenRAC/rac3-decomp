/* Wave 13 (r24, 2026-11-28) replaces the earlier draft of this function (Regional matching study (2026-11-24)). */
/* func_L07_003B3C78 near (wave 13 r24). Against the existing draft (48 under the file's line): the callee
   result reuses the argument variable (v = func_003C3BE8(-7, 7, v)), which puts it in $f0 with retail's
   mov.s $f14, $f0 in the jal delay slot; arm 0 copies the phase into v before the test; the +-2 offset is
   an if/else on v, which restores the full length. Still differs: arm 0's phase shares $f0 with v
   (retail keeps it in $f2, with a then-path mov.s $f0, $f2 behind bc1fl), so the -7.0f lui/mtc1 is
   scheduled above the i test, the +-2 select is bnez/b instead of bnel, and p/i take $s1/$s0 (retail
   $s0/$s1: i outranks p in global allocation). Tried without gain: if/else, ?:, memory re-reads, an
   inline helper, divide-by-peak forms, goto, do-while, sharing a variable with the first part. */
#include "common.h"

/* localdecomp:start func_L07_003B3C78 */
void func_L07_003B3C78(void *self) {
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_L07_003B3DB0(void *, s32, f32);
    u8 *p = *(u8 **)((u8 *)self + 0x68);
    f32 v;
    s32 i;

    *(f32 *)(p + 0x658) += 0.009000001f;
    if (*(f32 *)(p + 0x658) > 1.5f) {
        *(f32 *)(p + 0x658) -= 1.5f;
    }

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            f32 a = *(f32 *)(p + 0x658);
            v = a;
            if (!(a < 1.0f)) {
                v = (1.5f - a) * 2.0f;
            }
        } else {
            f32 b = *(f32 *)(p + 0x658);
            if (b < 0.5f) {
                v = b * 2.0f;
            } else {
                v = 1.5f - b;
            }
        }
        v = func_003C3BE8(-7.0f, 7.0f, v);
        if (i == 0) {
            v += -2.0f;
        } else {
            v += 2.0f;
        }
        func_L07_003B3DB0(self, i, v);
    }
}
/* localdecomp:end func_L07_003B3C78 */
