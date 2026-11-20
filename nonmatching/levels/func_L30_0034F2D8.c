/* func_L30_0034F2D8 (near miss, kmomoney agents (2026-11-19, second pass))
 * 16 diff at all 7 places and on NTSC-U (76 after the first pass), with the file's flags and the divs_nops
 * row `func_L30_0034F2D8 1 0` (add it only with the matched C). What fixed most: the second register for
 * &p40 is a GCSE copy, made by an inline helper with two returns (`c = shalf_34F2D8(&p80, &p40)`: its
 * return label ends the first CSE block, so &p40 at steps 7/8 is a fresh expression GCSE turns into a copy
 * of the first call's pointer; `y = slen_34F2D8(&p60, &p40)` makes both steps use it), giving retail's
 * $s1/$s4, $s2 for p60 and the 0x120 frame; every float use its own temporary, `z = func_0038CEA8(&p40);`
 * its own statement, the first-half zero a variable `f32 tmin = 0.0f;` (cse2 folds slen's literal zero into
 * it: retail's single $f22 zero), vec_sub_ab. Differs: (1) the GCSE copies of &p30/&p50/&p70 get
 * $s7/$s5/$s6, retail $s5/$s6/$s7 (allocation by live length, 152/150/152 here; retail needs p30 <= p50 <
 * p70; the order dir.y; qzero; vsub; e.z fixes them but flips $vf1/$vf2 and moves `sq $0`: 17); (2) in the
 * y, x2 and y2 sign blocks retail puts `mov.s fN, $f0` in the dot call's delay slot after the $a0/$a1
 * moves, ours first (sched2 ties at priority 6 broken by insn order, so retail's RTL differs there); tried
 * !(dot >= 0), a ternary, an else arm, 0 > dot, helper forms, const parameters. `-fsched-verbose-N` works
 * with SN cc1 (not `=N`): check.py --flags="-dS -fsched-verbose-9".
 */
#include "common.h"

/* localdecomp:start func_L30_0034F2D8 */
__asm__(".extern D_L30_001DD5F8, 4");
__asm__(".extern D_L30_001DD720, 4");
__asm__(".extern D_L30_001DD724, 4");
__asm__(".extern D_L30_001DD728, 4");
extern f32 D_L30_001DD5F8;
extern f32 D_L30_001DD720;
extern f32 D_L30_001DD724;
extern f32 D_L30_001DD728;
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
static __inline__ f32 shalf_34F2D8(void *a, void *b) {
    f32 h = func_0038CEA8(a) * 0.5f;
    if (func_0038CE68(a, b) < 0.0f) {
        return -h;
    }
    return h;
}
static __inline__ f32 slen_34F2D8(void *a, void *b) {
    f32 l = func_0038CEA8(a);
    if (func_0038CE68(a, b) < 0.0f) {
        l = -l;
    }
    return l;
}

void func_L30_0034F2D8(u8 *a, u8 *b) {
    u8 *v = *(u8 **)(a + 0x68);
    vu0_v4 dir;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 p30;
    vu0_v4 p40;
    vu0_v4 p50;
    vu0_v4 p60;
    vu0_v4 p70;
    vu0_v4 p80;
    f32 r[2];
    f32 lim = *(s16 *)(b + 0xAA) == 0x1C83 ? D_L30_001DD720 : *(s16 *)(b + 0xAA) == 0x1974 ? D_L30_001DD724 : D_L30_001DD728;
    f32 tmin = 0.0f;
    f32 c;
    f32 y;
    f32 z;
    f32 t;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 acc;
    s32 n;

    dir.x = func_0038D098(*(f32 *)(v + 0x14));
    dir.z = func_0038D0B0(*(f32 *)(v + 0x14));
    dir.y = 0.0f;
    vec_sub_ab(&d, b + 0x10, a + 0x10);
    qzero(&e);
    e.z = -D_L30_001DD5F8;
    func_L02_003BA9F8(&d, &dir, &p30, &p40);
    func_L02_003BA9F8(v, &dir, &p50, &p60);
    func_L02_003BA9F8(&e, &dir, &p70, &p80);
    c = shalf_34F2D8(&p80, &p40);
    y = slen_34F2D8(&p60, &p40);
    z = func_0038CEA8(&p40);
    n = func_L01_004461B8(&r[0], &r[1], c, y, -z);
    if (n == 0) {
        return;
    }
    if (n == 1) {
        if (!(tmin < r[0])) {
            return;
        }
        t = r[0];
    }
    if (n == 2) {
        if (tmin < r[1]) {
            t = r[1];
        } else if (tmin < r[0]) {
            t = r[0];
        } else {
            return;
        }
    }
    x2 = func_0038CEA8(&p30);
    if (func_0038CE68(&p30, &dir) < 0.0f) {
        x2 = -x2;
    }
    y2 = func_0038CEA8(&p50);
    if (func_0038CE68(&p50, &dir) < 0.0f) {
        y2 = -y2;
    }
    z2 = func_0038CEA8(&p70);
    if (func_0038CE68(&p70, &dir) < 0.0f) {
        z2 = -z2;
    }
    acc = (x2 / (t * t) - y2 / t) * 2.0f - z2;
    if (lim < acc) {
        acc = lim;
    } else if (acc < -lim) {
        acc = -lim;
    }
    func_0038CE20(&dir, &dir, acc);
    vec_add_ab(v, v, &dir);
}
/* localdecomp:end func_L30_0034F2D8 */
