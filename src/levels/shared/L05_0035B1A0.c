#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_0035B1A0 */
static __inline__ void vec_add_copy_0035B1A0(void *d, void *a, void *b, void *cd, void *cs) {
    vu0_q x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("lqc2 %0, %1" : "+j"(x) : "m"(*(vu0_v4 *)cs));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)cd) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(y));
}
static __inline__ void vec_sub_l_0035B1A0(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vsub.xyz %0, %1, %0" : "+j"(qb) : "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qb));
}
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
    vu0_v4 *dp;

    v = *(u8 **)(arg0 + 0x68);
    dp = &d;
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), D_L05_001DD6D0[i], &p);
        func_003C2EC0(*(void **)(v + 0x3EC), D_L05_001DD6D0[i], m);
        func_0038D028(&q, D_L05_001DD6A0 + i * 0x10, m);
        vec_add_copy_0035B1A0(&p, &p, &q, &t, &D_L05_001E2680);
        vec_sub_l_0035B1A0(&d, &t, &p);
        func_0038CF68(dp, dp, 1.0f);
        n = m[0];
        dot = func_0038CE68(dp, &n);
        if (D_L05_001DD6C0 < dot) {
            dot = dot * dot;
            func_003C5458(&p, func_0038DBD8(D_L05_001DD6C8, D_L05_001DD6C4, dot), D_L05_001DD698[i], D_L05_001DD690[i]);
        }
    }
}
/* localdecomp:end func_L05_0035B1A0 */
