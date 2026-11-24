/* func_L05_00362F30 (PAL): 76 differences, measured with -mvu0-use-vf0-vf2 added (check.py --flags), which its
 * file (src/levels/shared/L05_003629B8.c, `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`) does not have:
 * without it no j-constraint VU0 code compiles. The file's line would need the flag first, and its three
 * matched functions re-checked with it. Promises, 2026-11-20.
 * Right: frame (0x130, every local at retail's offset), the dead copy of the by-value second argument, the
 * calls, the $gp slots D_L05_001DDA64/6C/74 (with .extern sizes), the packet fields.
 * Still differs: (1) the vf1/vf2 roles of two of the three differences at the top (retail gives the first-loaded
 * operand vf1 in c = p0 - p1 and b = p1 - copy2) and the order of the two copies' sqc2 against the argument copy;
 * (2) the float-pair copy loop: retail walks the source with two pointers (D_L05_001DDA80 and D_L05_001DDA84),
 * this C with one pointer and offsets 0/4 (tried: a struct array, f32[4][2], f32[] with i * 2 and i * 2 + 1).
 * A j-form block with the result in the minuend's variable did not change (1).
 * 2026-11-21 (Promises, t2786): the copy loop walks a source and a destination pointer (was s.p[i] = D[i] by
 * fields: 77 -> 76); struct assignment s.p[i] = D[i] gives ldl/ldr pairs, two float pointers 85. The VU0 roles of
 * (1) did not change with vec_sub_ba or vec_sub_ab for c, nor with the copies placed before the argument copy or
 * after c, nor with p loaded before the argument copy. */
/* RT-B retry (2026-11-22, rac3-w1, upstream b7be60ac): the copy loop reads its second column through its own
 * symbol, D_L05_001DDA84 (`s.p[i].a = D_L05_001DDA80[i * 2]; s.p[i].b = D_L05_001DDA84[i * 2];`): retail's loop
 * shape now comes out (four pointers, counter 3 down to -1). 76 -> 39 differences (tools/check.py) at levels 05
 * and 10 with `-mvu0-use-vf0-vf2` added to L05_003629B8.c's line. Left: the loop's register choice and the
 * order of the stores before it, and the VU0 roles at the top. Four explicit pointers 84; a struct-typed
 * D_L05_001DDA80 for the first column 39; scalar temporaries 39; a `dst` pointer to s.p 77. */
/* NM-R22 retry (2026-11-23, rac3-w1, upstream 1dbb16a7): still 39 differences (tools/check.py) at levels 05 and 10
 * with -mvu0-use-vf0-vf2 added. The inline j-form block for c (lqc2 p + 0x10, lqc2 p, vsub, sqc2) is replaced by
 * vu0.h's vec_sub_ba(&c, p, p + 0x10), which gives the same bytes (check.py's listing is identical), so the draft
 * no longer needs the j-form (r3-34). Other orders of the c, a and b differences: acb 41, bca 41, abc 42, cba 42.
 * The loop body's two stores swapped: 39 (it only rotates which pointer gets which register). D_L05_001DDA74 in a
 * scoped local for the four stores: 39 (the same bytes). The operands declared `vu0_q y, x;` in the old block: 39. */
/* P10 retry (2026-11-23, rac3-w1, upstream c162f99b): the vec_sub_ab/vec_sub_ba swap (FACT #47976, which matched
 * func_L05_0035DA38) at all seven helper sites (c, a, b and the four e sites, vec_add included), all 128
 * combinations: 39 differences (tools/check.py) at levels 05 and 10 in every one, with -mvu0-use-vf0-vf2 on the file's
 * line; spot checks give byte-identical listings, so the helper's lqc2 order does not reach the code here.
 * Retail's c and b have the first-loaded operand in $vf1 and the result in $vf2 (vsub.xyz $vf2, $vf2, $vf1); a
 * already matches. The swap did not move the count, so #47975 and #47941 were not tried (the task's bound). */
/* CLOSEOUT attempt 1 of 2 (2026-11-24, rac3-w2, upstream 3e4df279): 37 differences (tools/check.py --no-context) at
 * levels 05 and 10 with -mvu0-use-vf0-vf2 on L05_003629B8.c's line (was 39). The load of p now follows the two
 * vec_copy calls: the `move $a0, $s0` after c's vsub is now in retail's place. All 24 orders of the first four
 * statements: best 37 (arg, f, g, p; or arg, g, f, p). All 720 orders of the units after the calls (the
 * func_00389598 call, s.k, s.m, the four s.c stores, s.z, the loop) and all 120 orders of the five stores: none
 * below 37. The loop as a do-while, or with two source pointers stepped by 2: 37; a `q = &s.p[i]` pointer 75; a
 * counter stepping by 2 78; both columns through D_L05_001DDA80 75. The vf roles: the -da dumps show cc1's
 * local-alloc giving vf1 to the vsub's minuend (sched1 always puts the p + 0x10 load first, whichever helper
 * order is used); retail gives it vf2 in c and b. A j-form vsub with the minuend tied to the result ("+j" or
 * "0") gives the same 37 bytes. Left: the vf1/vf2 roles of c and b (8 words), the order of the three stores at
 * the top (sqc2 f and g before the argument's sq: 4 words), the loop's registers and the order of the stores
 * before it (25 words). */
#include "common.h"

/* localdecomp:start func_L05_00362F30 */
#include "vu0.h"
typedef struct { f32 a; f32 b; } P_00362F30;
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    P_00362F30 p[4];
    long z;
    long r;
    long k;
    long m;
} S_00362F30;
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001E2680, 16");
extern f32 D_L05_001DDA80[];
extern f32 D_L05_001DDA84[];
extern f32 D_L05_001DDA64;
__asm__(".extern D_L05_001DDA64, 4");
extern s32 D_L05_001DDA6C;
__asm__(".extern D_L05_001DDA6C, 4");
extern s32 D_L05_001DDA74;
__asm__(".extern D_L05_001DDA74, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L05_00362F30(u8 *a0, u128_361BA8 *a1) {
    vu0_v4 arg;
    S_00362F30 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    u8 *p;
    s32 i;

    arg = *(vu0_v4 *)a1;
    vec_copy(&f, &D_L05_001E2680);
    vec_copy(&g, &D_L05_001E2680);
    p = *(u8 **)(a0 + 0x68);
    vec_sub_ba(&c, p, p + 0x10);
    vec_sub_ba(&a, p, &f);
    vec_sub_ba(&b, p + 0x10, &g);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, D_L05_001DDA64);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, D_L05_001DDA64);
    s.r = func_00389598(0xE);
    s.k = 0x0000FF9000000260;
    s.m = ((long)D_L05_001DDA6C << 32) | 0x48;
    s.c[0] = D_L05_001DDA74;
    s.z = 0;
    s.c[3] = D_L05_001DDA74;
    s.c[2] = D_L05_001DDA74;
    s.c[1] = D_L05_001DDA74;
    for (i = 0; i < 4; i++) {
        s.p[i].a = D_L05_001DDA80[i * 2];
        s.p[i].b = D_L05_001DDA84[i * 2];
    }
    vec_sub_ba(&e, p, &a);
    d = e;
    s.v[0] = d;
    vec_add_ba(&e, p, &a);
    d = e;
    s.v[1] = d;
    vec_sub_ba(&e, p + 0x10, &b);
    d = e;
    s.v[2] = d;
    vec_add_ab(&e, p + 0x10, &b);
    d = e;
    s.v[3] = d;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L05_00362F30 */
