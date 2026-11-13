/* func_L05_0035B1A0: near miss (file L05_00355DD8.c). 51 differences with the file's flags: logic, frame and calls right; retail increments the loop pointers and counter at the loop end (both paths of the threshold test), gcc moves them into the call delay slots, and retail gives the vec_add_ba/vec_sub_ba operands the other VU registers (first-loaded in $vf1); for/while/do-while/continue and explicit pointer forms tried */
#include "common.h"
#include "vu0.h"

extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C5458(void *, s32, f32, f32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD6D0, 8");
extern s32 D_L05_001DD6D0[2];
__asm__(".extern D_L05_001DD6A0, 8");
extern u8 D_L05_001DD6A0[8];
__asm__(".extern D_L05_001DD698, 8");
extern f32 D_L05_001DD698[2];
__asm__(".extern D_L05_001DD690, 8");
extern f32 D_L05_001DD690[2];
__asm__(".extern D_L05_001DD6C0, 4");
extern f32 D_L05_001DD6C0;
__asm__(".extern D_L05_001DD6C8, 4");
extern s32 D_L05_001DD6C8;
__asm__(".extern D_L05_001DD6C4, 4");
extern s32 D_L05_001DD6C4;

void func_L05_0035B1A0(u8 *arg0)
{
    u8 *v;
    s32 i;
    vu0_v4 p;
    vu0_v4 m[4];
    vu0_v4 q;
    vu0_v4 d;
    vu0_v4 n;
    vu0_v4 t;
    f32 dot;

    v = *(u8 **)(arg0 + 0x68);
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), D_L05_001DD6D0[i], &p);
        func_003C2EC0(*(void **)(v + 0x3EC), D_L05_001DD6D0[i], m);
        func_0038D028(&q, D_L05_001DD6A0 + i * 0x10, m);
        vec_add_ba(&p, &p, &q);
        vec_copy(&t, &D_L05_001E2680);
        vec_sub_ba(&d, &t, &p);
        func_0038CF68(&d, &d, 1.0f);
        n = m[0];
        dot = func_0038CE68(&d, &n);
        if (D_L05_001DD6C0 < dot) {
            func_003C5458(&p, func_0038DBD8(D_L05_001DD6C8, D_L05_001DD6C4, dot * dot), D_L05_001DD698[i], D_L05_001DD690[i]);
        }
    }
}
