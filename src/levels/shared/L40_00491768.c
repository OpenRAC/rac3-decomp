#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00491768);

/* localdecomp:start func_L40_00491A38 */
#include "vu0.h"
typedef struct { vu0_q q; } vu0_s_00491A38;
static __inline__ void gp_sub_ab_s_00491A38(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qb) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qb));
}
typedef struct {
    vu0_v4 v0, v1, v2, v3;
    s32 w40, w44, w48, w4C;
    s32 w50, w54, w58;
    f32 f5C, f60;
    s32 w64;
    f32 f68, f6C;
    long d70, d78, d80, d88;
    vu0_v4 l1, l2, l3, l4, pp;
} Box_00491A38;
extern long func_L39_00589890(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L40_00491A38(vu0_v4 *p, s32 a, f32 sz) {
    Box_00491A38 b;
    b.d78 = func_L39_00589890(6);
    b.w4C = a;
    b.w48 = a;
    b.w44 = a;
    b.w50 = 0;
    b.w54 = 0;
    b.w58 = 0;
    b.f5C = 1.0f;
    b.f60 = 1.0f;
    b.w64 = 0;
    b.f68 = 1.0f;
    *(vu0_q *)&b.l4 = 0;
    *(vu0_q *)&b.l1 = 0;
    *(vu0_q *)&b.l2 = 0;
    b.d80 = 0xFF9000000260LL;
    b.d70 = 5;
    b.d88 = 0x8000000044LL;
    b.w40 = a;
    b.f6C = 1.0f;
    b.l1.x = sz;
    b.l2.y = sz;
    b.l4.y = sz + sz;
    b.l3 = b.l4;
    {
        vu0_q qa, qb, qr, qc;
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*(vu0_s_00491A38 *)p));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*p));
        __asm__("sqc2 %1, %0" : "=m"(b.pp) : "j"(qc), "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b.l1));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(b.v0) : "j"(qr));
    }
    vec_add_ba(&b.v0, &b.v0, &b.l2);
    vec_sub_ab(&b.v1, &b.v0, &b.l3);
    gp_sub_ab_s_00491A38(&b.v2, &b.pp, &b.l1);
    vec_add_ba(&b.v2, &b.v2, &b.l2);
    vec_sub_ab(&b.v3, &b.v2, &b.l3);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L40_00491A38 */
