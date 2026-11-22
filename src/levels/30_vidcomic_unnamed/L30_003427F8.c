#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L30_00341D88.c, which this file was cut from */
extern void func_L30_003427F8(u8 *);
extern s32 func_L30_00342980(u8 *);

/* localdecomp:start func_L30_003427F8 */
#include "vu0.h"
/* vu0_s: a 128-bit struct with TImode, so its "m" operands are TImode MEMs. gcc then tracks stack
 * dependences by offset; vu0_v4's BLKmode MEMs conflict with every stack store. */
typedef struct { vu0_q q; } vu0_s;

/* vec_load(): lqc2 into a "j" register, the value left for vec_sub_r() / vec_store2() */
static __inline__ vu0_q vec_load(void *s) {
    vu0_q q;
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_s *)s));
    return q;
}

/* vec_sub_r(): vsub.xyz of two loaded values, result left in a register */
static __inline__ vu0_q vec_sub_r(vu0_q a, vu0_q b) {
    vu0_q r;
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    return r;
}

/* vec_store2(): two sqc2 in one statement (retail stores a copy and an op's result back to back) */
static __inline__ void vec_store2(void *d1, vu0_q q1, void *d2, vu0_q q2) {
    __asm__("sqc2 %2, %0\n\tsqc2 %3, %1" : "=m"(*(vu0_s *)d1), "=m"(*(vu0_s *)d2) : "j"(q1), "j"(q2));
}

/* vec_add_l1(): d = a + b; a loaded alone, b loaded and added in one statement, then sqc2 */
static __inline__ void vec_add_l1(void *d, void *a, void *b) {
    vu0_q x, t;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_s *)a));
    __asm__("lqc2 %1, %2\n\tvadd.xyz %0, %0, %1" : "+j"(x), "=&j"(t) : "m"(*(vu0_s *)b));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(x));
}
extern f32 D_L30_001DCE28;
extern f32 D_L30_001DCE3C;
extern f32 D_L30_001DCE40;
__asm__(".extern D_L30_001DCE28, 4");
__asm__(".extern D_L30_001DCE3C, 4");
__asm__(".extern D_L30_001DCE40, 4");
extern vu0_v4 D_L30_001E9020;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L30_003427F8(u8 *self) {
    vu0_v4 target, start, diff, t30, c40;
    u8 *m = *(u8 **)(self + 0x68);

    if (func_L30_00342980(self) && *(f32 *)(m + 0x68) < 0.0f) {
        *(f32 *)(m + 0x68) = 0.0f;
    } else {
        *(f32 *)(m + 0x68) += D_L30_001DCE28;
    }
    if (*(f32 *)(m + 0x60) > D_L30_001DCE3C) {
        *(f32 *)(m + 0x60) = D_L30_001DCE3C;
    } else if (*(f32 *)(m + 0x60) < -D_L30_001DCE3C) {
        *(f32 *)(m + 0x60) = -D_L30_001DCE3C;
    }
    if (*(f32 *)(m + 0x68) > D_L30_001DCE40) {
        *(f32 *)(m + 0x68) = D_L30_001DCE40;
    } else if (*(f32 *)(m + 0x68) < -D_L30_001DCE40) {
        *(f32 *)(m + 0x68) = -D_L30_001DCE40;
    }
    *(u128_t *)&start = *(u128_t *)(self + 0x10);
    start.z += *(f32 *)(m + 0x70);
    vec_add_ab(&target, &start, m + 0x60);
    if (func_L01_003FB640(&target, 2, self, *(f32 *)(m + 0x70))) {
        vec_sub_ab(&t30, &target, &D_L30_001E9020);
        func_0038CF68(&t30, &t30, 1.0f);
        func_0038CF68(&t30, &t30, *(f32 *)(m + 0x70));
        vec_add_ab(&target, &t30, &D_L30_001E9020);
    }
    {
        vu0_q qb = vec_load(&start);
        vu0_q qa = vec_load(&target);
        vu0_q q;
        qa = vec_sub_r(qa, qb);
        q = vec_load(self + 0x10);
        vec_store2(&c40, q, &diff, qa);
    }
    vec_add_l1(self + 0x10, &diff, &c40);
}
/* localdecomp:end func_L30_003427F8 */
