/* near miss (level 3, Starship Phoenix): 28 differences with the file's flags (check.py --no-context; the draft this replaces measured 43). Round 14 (Sonnet b24-u1): `n = 4` before the `continue` test puts retail's `addiu $a2, $zero, 4` before the lbu; the inner loop as `for (j = 0; j < n; j++)` gives retail's guard `beqz $a2` with `move $s2, $a2` after it and the constant loads in retail's order (the preheader is exact now); the sign as one nested ?: is the same code as the old goto version. Left: ALL of it is interblock scheduling. With `-fno-sched-interblock` (a flag the build does not use: diagnostic only) this C has 5 diffs: sched1 moves `addiu $a0, $zero, 2`, the shared `sg = 1` and the loop's `j--` up into the loop's top block (spec motion of the blocks it dominates), where retail keeps them in their own blocks (retail's first jal has `addiu $a0, 2` and the func_003824E0 jal has the decrement in its delay slot, bne tests ix with `move $s0, $s4` in the slot). Separate `sg = 1`/`sg = -1` assignments per branch (4 blocks) become movn/movz instead (95-114 diffs); reordering the sg and c computations changes the call order (87). The last 5 (also without interblock): `mov.s $f15, $f21` of the func_L01_00474078 call sits after the integer argument moves here, before them in retail (the real prototype of that callee, (pos, dir, f32 width, life, color, end, spin, texture, f32 scale, drag, tail), gives the same bytes). */
#include "common.h"

/* localdecomp:start func_L03_00330EC8 */
#include "vu0.h"
typedef struct { u8 pad0[0xF7]; u8 bF7; f32 fF8; } S_00330EC8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00330EC8 *p68; } A_00330EC8;
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_00474078(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L03_00330EC8(void *arg) {
    A_00330EC8 *a = arg;
    S_00330EC8 *s = a->p68;
    f32 k, t;
    int i, j;
    t = 2.0f - s->fF8;
    k = t > 1.0f ? 1.0f : t;
    for (i = 0; i < 5; i++) {
        int n;
        int ix, iy;
        f32 lo, hi;
        n = 4;
        if (!((s->bF7 >> i) & 1)) continue;
        if (i == 4) {
            n = 8;
            lo = 0.0f;
            hi = 10.5f;
            ix = -1;
            iy = -1;
        } else {
            lo = 10.5f;
            hi = 22.83f;
            ix = i % 2;
            iy = 1 - i / 2;
        }
        for (j = 0; j < n; j++) {
            vu0_v4 off;
            vu0_v4 pos;
            vu0_v4 rot;
            int c, sg;
            f32 ang;
            f32 *dst;
            c = ix;
            if (ix == -1) c = func_00382468(2);
            sg = (iy == -1 ? func_00382468(2) != 0 : iy != 0) ? 1 : -1;
            qzero(&off);
            dst = &off.x + c;
            *dst = func_003824E0(lo, hi) * (f32)sg;
            vec_add_ab(&pos, &a->pos, &off);
            ang = func_00382538();
            func_00382760(&rot, 0.40000004f, ang, func_003824E0(1.0f, k) * 1.5707964f);
            func_L01_00474078(&pos, &rot, 0x11, 0x80FF2020, 0x80404040, 0xA, 0, 0.08f, 2.0f, 1.5f, 1.0f);
        }
    }
}
/* localdecomp:end func_L03_00330EC8 */
