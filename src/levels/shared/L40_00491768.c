#include "common.h"

/* localdecomp:start func_L40_00491768 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0, v1, v2, v3;
    s32 w40, w44, w48, w4C;
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C;
    long d70, d78, d80, d88;
} Box_00491768;
extern long func_L39_00589890(s32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L40_00491768(vu0_v4 *p, vu0_v4 *q, s32 a, f32 sz) {
    Box_00491768 b[3];
    vu0_v4 dir, side, up;
    s32 i;

    for (i = 0; i < 3; i++) {
        Box_00491768 *e = &b[i];
        e->d78 = func_L39_00589890(6);
        e->d80 = 0xFF9000000260LL;
        e->d70 = 5;
        e->d88 = 0x8000000044LL;
        e->f50 = 0.0f;
        e->f54 = 0.0f;
        e->f58 = 0.0f;
        e->f5C = 1.0f;
        e->f60 = 1.0f;
        e->f64 = 0.0f;
        e->f68 = 1.0f;
        e->f6C = 1.0f;
        e->w4C = a;
        e->w48 = a;
        e->w44 = a;
        e->w40 = a;
    }
    b[0].f50 = 0.5f;
    b[0].f58 = 0.5f;
    b[1].f50 = 0.5f;
    b[1].f58 = 0.5f;
    b[1].f60 = 0.5f;
    b[1].f68 = 0.5f;
    b[2].f50 = 0.5f;
    b[2].f58 = 0.5f;
    *(vu0_q *)&up = 0;
    up.z = 1.0f;
    vec_sub_ba(&dir, p, q);
    func_0038CF68(&dir, &dir, sz);
    func_0038CE90(&side, &dir, &up);
    func_0038CF68(&side, &side, sz);
    vec_add_ba(&b[0].v0, p, &side);
    vec_sub_ba(&b[0].v1, p, &side);
    vec_add_ba(&b[0].v2, &b[0].v0, &dir);
    vec_add_ba(&b[0].v3, &b[0].v1, &dir);
    vec_add_ba(&b[1].v0, p, &side);
    vec_sub_ba(&b[1].v1, p, &side);
    vec_add_ba(&b[1].v2, q, &side);
    vec_sub_ba(&b[1].v3, q, &side);
    vec_add_ba(&b[2].v0, q, &side);
    vec_sub_ba(&b[2].v1, q, &side);
    vec_sub_ba(&b[2].v2, &b[2].v0, &dir);
    vec_sub_ab(&b[2].v3, &b[2].v1, &dir);
    func_003D2DA0(&b[0], 0, 0);
    func_003D2DA0(&b[1], 0, 0);
    func_003D2DA0(&b[2], 0, 0);
}
/* localdecomp:end func_L40_00491768 */

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
