/* func_L05_0035AFB8: near miss (file L05_00355DD8.c). 9 differences with the file's flags (tools/check.py, levels 05, 10,
 * 14 and 17, in the file's context and with --no-context), down from 13 with the include/vu0.h helpers (2026-11-23, task
 * #2966). PROVISIONAL, VU0 j-constraint form: the add, the copy and the sub are written as one asm statement per VU0
 * instruction ("j" operands, docs/wiki/Matching-Patterns.md "VU0 j-form"), because the helpers cannot put the sub's
 * load of p between the add's sqc2 and the copy. In this statement order every VU0 register equals retail's (q in $vf1,
 * p in $vf2, `vadd.xyz vf2, vf2, vf1`; the copy in $vf1; `vsub.xyz vf1, vf2, vf1`), with fresh result variables.
 * What still differs is only the order: retail does the copy (lui, lqc2 vf1, sqc2 t) between the vadd and the add's
 * sqc2, then loads p before t for the sub; here the add's sqc2 and the sub's p load come before the copy.
 * Why (gcc -da dumps): sched1 hoists the copy's lqc2 into the vadd's latency stall whenever the copy is written before
 * the add's sqc2, so three VU values are live and one is spilled (88 to 90 differences); written after the sqc2, the
 * copy is never placed between the vadd and the sqc2. A search over all 112 orders of the ten VU statements, each with
 * three choices of result variable for the add and for the sub (1,008 compiles), found nothing below 9.
 * The helper form (13) was: vec_copy(&t, &D_L05_001E2680); vec_add_ba(&p, &p, &q); vec_sub_ba(&d, &t, &p); */
#include "common.h"
#include "vu0.h"

extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD670, 8");
extern u8 D_L05_001DD670[8];
__asm__(".extern D_L05_001DD650, 8");
extern u8 D_L05_001DD650[8];

void func_L05_0035AFB8(u8 *arg0)
{
    u8 *v;
    s32 i;
    s32 j;
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 m[4];
    vu0_v4 q;
    vu0_v4 d;
    vu0_v4 t;

    v = *(u8 **)(arg0 + 0x68);
    *(vu0_q *)&r = 0;
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), 2, &p);
        func_003C2EC0(*(void **)(v + 0x3EC), 2, m);
        func_0038D028(&q, D_L05_001DD670 + i * 0x10, m);
        {
            vu0_q x, y, a, c, w, u, s;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p) : "j"(a));
            __asm__("lqc2 %0, %1" : "=j"(u) : "m"(p));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(D_L05_001E2680));
            __asm__("sqc2 %1, %0" : "=m"(t) : "j"(c));
            __asm__("lqc2 %0, %1" : "=j"(w) : "m"(t));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(s) : "j"(w), "j"(u));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(s));
        }
        func_0038CF68(&d, &d, 0.0f);
        vec_add_ab(&p, &p, &d);
        for (j = 0; j < 5; j++) {
            func_003C4C18(&p, 0.0f);
            r.x = func_003824E0(0.0f, 0.0f) * 0.020000001f;
            r.y = func_003824E0(0.0f, 0.0f) * 0.020000001f;
            r.z = func_003824E0(-15.0f, -16.0f) * 0.020000001f;
            func_0038D000(&r, &r, arg0 + 0xC0);
            func_L05_00468EA8(&p, &r, D_L05_001DD650, func_00382468(2), func_00382468(3) - 1);
        }
    }
}
