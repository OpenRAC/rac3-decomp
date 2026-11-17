#include "common.h"

/* localdecomp:start func_L06_0042B660 */
#include "vu0.h"
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

f32 func_L06_0042B660(f32 max, u8 *a0, u8 *a1) {
    struct {
        vu0_q d;
        vu0_q t;
    } v;
    vu0_q qa, qb;
    f32 len;
    f32 c;
    vec_sub_ab(&v.t, a1, a0);
    v.d = v.t;
    c = func_0038CEA8(&v.d);
    len = c;
    if (max < c) {
        c = max;
    } else if (c < -max) {
        c = -max;
    }
    func_0038CF68(&v.d, &v.d, c);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a0));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v.d));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)a0) : "j"(qa));
    v.t = qa;
    return len - c;
}
/* localdecomp:end func_L06_0042B660 */
