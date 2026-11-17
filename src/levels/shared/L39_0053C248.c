#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0053C248 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L39_0053C248(u8 *self, void *base) {
    vu0_v4 d;
    vu0_v4 tmp;
    vu0_q qa, qb;
    u8 *p = *(u8 **)(self + 0x68);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)base));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(self + 0x10)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
    func_0038CF68(&tmp, p + 0x20, 1.0f);
    return func_0038CE68(&d, &tmp);
}
/* localdecomp:end func_L39_0053C248 */
