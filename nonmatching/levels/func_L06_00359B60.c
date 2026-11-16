/* Level 06 shared (src/levels/shared/L06_00356C80.c) draft, 2026-11-15. 10 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as), register allocation only: retail builds the two table pointers with lui/addiu straight into $a1/$a0 and counts in $v1; this C gets the lui in $v0/$v1 and the counter in $a0. A struct or [4][2] table, indexed forms, forward and down-counting loops and declaration orders gave 10 or more. */
#include "vu0.h"
#include "common.h"
extern f32 func_003F33B8(f32);
extern f32 func_003F33D0(f32);
extern f32 D_001DD400[];
extern f32 D_001DD404[];

void func_L06_00359B60(u8 *a0, u8 *a1, f32 scale, f32 angle) {
    f32 s = func_003F33B8(angle);
    f32 c = func_003F33D0(angle);
    f32 *q = D_001DD404;
    f32 *p = D_001DD400;
    s32 i;

    for (i = 3; i >= 0; i--) {
        f32 x = *p;
        f32 y = *q;
        p += 2;
        q += 2;
        *(vu0_q *)a1 = *(vu0_q *)(a0 + 0x20);
        ((f32 *)a1)[0] += (x * s - y * c) * scale;
        ((f32 *)a1)[1] += (y * s + x * c) * scale;
        a1 += 0x10;
    }
}
