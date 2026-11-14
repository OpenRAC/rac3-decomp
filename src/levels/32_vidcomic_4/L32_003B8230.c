#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
void func_L32_003B8230(void *);

/* localdecomp:start func_L32_003B8230 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);

void func_L32_003B8230(void *arg0) {
    vu0_v4 sum;
    vu0_v4 v10;
    vu0_v4 d;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    u8 **slot;
    u8 *q;
    s32 i;
    f32 f;

    qzero(&sum);
    for (i = 0; i < 32; i++) {
        if (((u8 **)p)[i] != 0) {
            vec_add_ba(&sum, &sum, ((u8 **)p)[i] + 0x10);
        }
    }
    func_0038CE20(&sum, &sum, 1.0f / (f32)*(s32 *)(p + 0x8C));
    for (i = 0; i < 32; i++) {
        slot = &((u8 **)p)[i];
        if (*slot == 0) {
            continue;
        }
        q = *(u8 **)(*slot + 0x68);
        if (q == 0) {
            return;
        }
        f = func_0038CF00(*slot + 0x10, &sum) / *(f32 *)(p + 0x84);
        if (f > 1.0f) {
            f = 1.0f;
        }
        f *= *(f32 *)(p + 0x80);
        vec_sub_ab(&d, &sum, *slot + 0x10);
        func_0038CF68(&d, &d, f);
        vec_add_ab(q, q, &d);
        func_0038CF68(&v10, &d, 2.0f);
        vec_add_ab(&v10, &v10, *slot + 0x10);
    }
}
/* localdecomp:end func_L32_003B8230 */
