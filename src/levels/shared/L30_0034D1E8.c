#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_0034D1E8);

/* localdecomp:start func_L30_0034D808 */
#include "vu0.h"
extern f32 func_0038CEA8(void *v);                       /* length of a vector */
extern void func_0038CE20(void *d, void *s, f32 k);      /* scale a vector */
extern void func_0038CF68(void *d, void *s, f32 len);    /* a vector of that length */

/* Slow a velocity faster than `max`: scale it by 1 - `damp`, then shorten it by `drop` (to zero
   when it is shorter). */
void func_L30_0034D808(void *vel, f32 max, f32 damp, f32 drop) {
    if (max < func_0038CEA8(vel)) {
        if (0.0f < damp) {
            func_0038CE20(vel, vel, 1.0f - damp);
        }
        if (0.0f < drop) {
            if (func_0038CEA8(vel) < drop) {
                qzero(vel);
            } else {
                func_0038CF68(vel, vel, func_0038CEA8(vel) - drop);
            }
        }
    }
}
/* localdecomp:end func_L30_0034D808 */
