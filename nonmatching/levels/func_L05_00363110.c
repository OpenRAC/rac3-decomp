/* func_L05_00363110 (PAL): 92 differences, measured with -mvu0-use-vf0-vf2 added (see func_L05_00362F30, its
 * twin: same frame, same open problems, $gp slots D_L05_001DDA68/70/78, a fourth vec_add_ba and a second packet
 * sent with func_00389598(0x17) and 0x0000008000000048). Written from func_L05_00362F30's draft, not tuned.
 * Promises, 2026-11-20.
 * 2026-11-21 (Promises, t2786): the copy loop walks a source and a destination pointer (was s.p[i] = D[i] by
 * fields: 93 -> 92), as in func_L05_00362F30, where the other wordings tried for both open problems are listed. */
/* RT-B retry (2026-11-22, rac3-w1, upstream b7be60ac): the copy loop reads its second column through its own
 * symbol, D_L05_001DDA84 (`s.p[i].a = D_L05_001DDA80[i * 2]; s.p[i].b = D_L05_001DDA84[i * 2];`): retail's loop
 * shape now comes out (four pointers, counter 3 down to -1). 92 -> 38 differences (tools/check.py) at levels 05
 * and 10 with `-mvu0-use-vf0-vf2` added to L05_003629B8.c's line. Left: the loop's register choice and the
 * order of the stores before it, and the VU0 roles at the top. Four explicit pointers 84; a struct-typed
 * D_L05_001DDA80 for the first column 39; scalar temporaries 39; a `dst` pointer to s.p 77. */
/* NM-R22 retry (2026-11-23, rac3-w1, upstream 1dbb16a7): still 38 differences (tools/check.py) at levels 05 and 10
 * with -mvu0-use-vf0-vf2 added. The inline j-form block for c (lqc2 p + 0x10, lqc2 p, vsub, sqc2) is replaced by
 * vu0.h's vec_sub_ba(&c, p, p + 0x10), which gives the same bytes (check.py's listing is identical), so the draft
 * no longer needs the j-form (r3-34). */
/* P10 retry (2026-11-23, rac3-w1, upstream c162f99b): the vec_sub_ab/vec_sub_ba swap (FACT #47976, which matched
 * func_L05_0035DA38) at all seven helper sites (c, a, b and the four e sites, vec_add included), all 128
 * combinations: 38 differences (tools/check.py) at levels 05 and 10 in every one, with -mvu0-use-vf0-vf2 on the file's
 * line; spot checks give byte-identical listings, so the helper's lqc2 order does not reach the code here.
 * Retail's c and b have the first-loaded operand in $vf1 and the result in $vf2 (vsub.xyz $vf2, $vf2, $vf1); a
 * already matches. The swap did not move the count, so #47975 and #47941 were not tried (the task's bound). */
/* CLOSEOUT attempt 1 of 2 (2026-11-24, rac3-w2, upstream 3e4df279): 36 differences (tools/check.py --no-context) at
 * levels 05 and 10 with -mvu0-use-vf0-vf2 on L05_003629B8.c's line (was 38): the load of p after the two vec_copy
 * calls, as in func_L05_00362F30, where the other wordings tried are listed. Left: the same three problems as
 * func_L05_00362F30 (the vf1/vf2 roles of c and b, the order of the stores at the top, the loop's registers
 * and the store order before it). */
#include "common.h"

/* localdecomp:start func_L05_00363110 */
/* PROVISIONAL, VU0 j-constraint form. */
#include "vu0.h"
typedef struct { f32 a; f32 b; } P_00363110;
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    P_00363110 p[4];
    long z;
    long r;
    long k;
    long m;
} S_00363110;
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001E2680, 16");
extern f32 D_L05_001DDA80[];
extern f32 D_L05_001DDA84[];
extern f32 D_L05_001DDA68;
__asm__(".extern D_L05_001DDA68, 4");
extern s32 D_L05_001DDA70;
__asm__(".extern D_L05_001DDA70, 4");
extern s32 D_L05_001DDA78;
__asm__(".extern D_L05_001DDA78, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L05_00363110(u8 *a0, u128_361BA8 *a1) {
    vu0_v4 arg;
    S_00363110 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    u8 *p;
    s32 i;
    u128_361BA8 tu;
    vu0_q M;
    vu0_q T;
    vu0_q cs;

    tu = *a1;
    vec_copy(&f, &D_L05_001E2680);
    vec_copy(&g, &D_L05_001E2680);
    *(u128_361BA8 *)&arg = tu;
    p = *(u8 **)(a0 + 0x68);
    __asm__("lqc2 %0, %1" : "=j"(cs) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(cs));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(M));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(f));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(T) : "j"(T), "j"(M));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(T));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(g));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(T));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(M));
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, D_L05_001DDA68);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, D_L05_001DDA68);
    s.r = func_00389598(0x13);
    s.k = 0x0000FF9000000260;
    s.m = ((long)D_L05_001DDA70 << 32) | 0x48;
    s.c[0] = D_L05_001DDA78;
    s.z = 0;
    s.c[3] = D_L05_001DDA78;
    s.c[2] = D_L05_001DDA78;
    s.c[1] = D_L05_001DDA78;
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
    vec_add_ba(&e, p + 0x10, &b);
    d = e;
    s.v[3] = d;
    func_003D2DA0(&s, 0, 0);
    s.r = func_00389598(0x17);
    s.k = 0x0000FF9000000260;
    s.m = 0x0000008000000048;
    s.z = 0;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L05_00363110 */
