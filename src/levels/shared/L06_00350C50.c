#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;
extern void func_003C2EC0(void *, s32, Mtx4 *);

/* localdecomp:start func_L06_00350C50 */
extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L06_001DD2D0, 8");
extern s32 D_L06_001DD2D0[2];
void func_L06_00350C50(u8 *a0, u8 *a1, s32 a2, u8 *a3, u8 *t0, u8 *t1) {
    vu0_v4 tmp;

    func_003C2EC0(*(void **)(a1 + 0x260), D_L06_001DD2D0[a2], (Mtx4 *)a3);
    if (a2 == 0) {
        vec_neg(a3 + 0x10, a3 + 0x10);
        vec_neg(a3, a3);
    }
    func_0038CE20(&tmp, a3 + 0x10, 0.5f);
    vec_add_ba(t0, &tmp, a3 + 0x30);
    func_0038CE20(&tmp, a3 + 0x20, 0.775f);
    vec_add_ba(t0, &tmp, t0);
    if (a2 == 0) {
        func_0038CE20(&tmp, a3, -0.3f);
        vec_add_ba(t0, &tmp, t0);
    } else {
        func_0038CE20(&tmp, a3, 0.3f);
        vec_add_ba(t0, &tmp, t0);
    }
    *(vu0_q *)t1 = *(vu0_q *)(a3 + 0x10);
}
/* localdecomp:end func_L06_00350C50 */
