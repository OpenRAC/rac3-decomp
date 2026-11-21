/* func_L05_00362F30 (PAL): 77 differences, measured with -mvu0-use-vf0-vf2 added (check.py --flags), which its
 * file (src/levels/shared/L05_003629B8.c, `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`) does not have:
 * without it no j-constraint VU0 code compiles. The file's line would need the flag first, and its three
 * matched functions re-checked with it. Promises, 2026-11-20.
 * Right: frame (0x130, every local at retail's offset), the dead copy of the by-value second argument, the
 * calls, the $gp slots D_L05_001DDA64/6C/74 (with .extern sizes), the packet fields.
 * Still differs: (1) the vf1/vf2 roles of two of the three differences at the top (retail gives the first-loaded
 * operand vf1 in c = p0 - p1 and b = p1 - copy2) and the order of the two copies' sqc2 against the argument copy;
 * (2) the float-pair copy loop: retail walks the source with two pointers (D_L05_001DDA80 and D_L05_001DDA84),
 * this C with one pointer and offsets 0/4 (tried: a struct array, f32[4][2], f32[] with i * 2 and i * 2 + 1).
 * A j-form block with the result in the minuend's variable did not change (1). */
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
extern P_00362F30 D_L05_001DDA80[4];
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
    p = *(u8 **)(a0 + 0x68);
    vec_copy(&f, &D_L05_001E2680);
    vec_copy(&g, &D_L05_001E2680);
    {
        vu0_q x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(p + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)p));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(y));
    }
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
        s.p[i].a = D_L05_001DDA80[i].a;
        s.p[i].b = D_L05_001DDA80[i].b;
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
