/* Level 7 near miss: 32 differences with @ps2as (44 with the file's plain
   flags, where the 1.5f/1.8f li.s loads go to .lit4). The residual is the loop
   counter: this C keeps it in $s1 (mask $s2), retail keeps it in caller-saved
   $a1 with move $s2,$a1 in the jal slot and move $a1,$s2 after; the function is
   one word shorter. -fcaller-saves is a no-op in this compiler build. The owning
   file would need @ps2as and a flag-only build if a later form matches. Not
   linked; flags unchanged. No VU0. */
extern s32 func_00443E68(s32, s32);
extern s32 func_003CDE40(void *, s32, s32, f32);
extern void func_003CD2E8(void *, s32);

/* Level 7 (Annihilation Nation). 32 differences under --as ps2as, 44 with the
   owning file's plain flags: retail materialises the two f32 literals with
   lui/ori + mtc1 (Ps2EeAs's `li.s` expansion), and keeps the loop counter in
   $a1 with a caller-save copy in $s2 around the first call, which this
   compiler does not emit (see the report). */
s32 func_L07_003CDB30(void *arg0) {
    s32 mask;
    s32 i;
    s32 j;
    s32 r;
    s32 a;
    s32 b;
    f32 f;

    mask = 0;
    i = 3;
    do {
        i--;
        r = func_00443E68(0, i);
        for (j = 0; j < 3; j++) {
            if (r < j) {
                continue;
            }
            r += (mask >> j) & 1;
        }
        if (r == 2) {
            f = 1.5f;
            a = 0;
            b = -1;
        } else {
            f = 1.8f;
            a = 1;
            b = (r == 1) ? -1 : 1;
        }
        if (func_003CDE40(arg0, a, b, f) == 0) {
            mask = (mask | (1 << r)) & 0xFF;
        } else {
            func_003CD2E8(arg0, r + 0x12);
            return 1;
        }
    } while (i > 0);
    return 0;
}
