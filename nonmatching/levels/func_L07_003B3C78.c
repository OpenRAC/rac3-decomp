/* Level 7 near miss: 36 differences. The loop body differs only in one window:
   $s0/$s1 swap (p in $s1, i in $s0), the -7.0f lui/mtc1 stays at the loop head
   instead of next to the jal, the i==0 arm uses lwc1 $f14 + bc1t instead of
   retail's lwc1 $f2 + bc1fl with sub.s in the slot, and the result lands in
   $f14 instead of $f0 + mov.s $f14,$f0 in the jal slot. v is pseudo 118 and
   regalloc gives it $f14 (priority 3.818) behind a block-local pseudo at 6.0.
   Registered class (branch-likely tied to a local allocation). Not linked. */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_L07_003B3DB0(void *, s32, f32);

void func_L07_003B3C78(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 v, r;
    s32 i;

    *(f32 *)(p + 0x658) += 0.009000001f;
    if (*(f32 *)(p + 0x658) > 1.5f) {
        *(f32 *)(p + 0x658) -= 1.5f;
    }

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            f32 a = *(f32 *)(p + 0x658);
            v = a;
            if (a < 1.0f) {
            } else {
                v = (1.5f - a) * 2.0f;
            }
        } else {
            f32 a = *(f32 *)(p + 0x658);
            if (a < 0.5f) {
                v = a * 2.0f;
            } else {
                v = 1.5f - a;
            }
        }
        r = func_003C3BE8(-7.0f, 7.0f, v);
        func_L07_003B3DB0(arg0, i, r + (i == 0 ? -2.0f : 2.0f));
    }
}
