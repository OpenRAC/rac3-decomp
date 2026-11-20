#include "common.h"

typedef struct {
    f32 value;
    s32 pad;
} Item_408D28;

/* declared by functions of L01_0040A8B8.c, which this file was cut from */
extern void func_0038CE20(f32 *, f32 *, f32);

/* localdecomp:start func_L01_0040BE10 */
#include "vu0.h"

extern void func_0038CE20(f32 *, f32 *, f32);

void func_L01_0040BE10(f32 *a, f32 *b) {
    s32 i;
    f32 m;
    f32 t;
    f32 *pa;
    f32 *pb;

    if (b[0] > 0.0f && b[1] > 0.0f && b[2] > 0.0f) {
        return;
    }
    m = 1.0f;
    pa = a;
    pb = b;
    i = 0;
    while (i < 3) {
        if (*pb <= 0.0f) {
            t = 1.0f - *pb / (*pb - *pa);
            if (t < m) {
                m = t;
            }
        }
        i++;
        pa++;
        pb++;
    }
    vec_sub_ab(b, b, a);
    func_0038CE20(b, b, m - 0.01f);
    vec_add_ba(b, b, a);
}
/* localdecomp:end func_L01_0040BE10 */
