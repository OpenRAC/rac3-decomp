/* func_L05_0035AFB8: near miss (file L05_00355DD8.c). 13 differences with the file's flags (vec_copy before vec_add_ba; 20 in source order): only the VU register roles of the vec_add_ba/vec_sub_ba pair (retail puts the first-loaded operand in $vf1, the C in $vf2), as in func_L05_0035B1A0 */
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
        vec_copy(&t, &D_L05_001E2680);
        vec_add_ba(&p, &p, &q);
        vec_sub_ba(&d, &t, &p);
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
