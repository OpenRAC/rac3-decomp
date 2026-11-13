#include "common.h"

/* localdecomp:start func_L39_0062D0C8 */
/* log:
 * v1: vec_add_ab + qzero from vu0.h
 */
#include "vu0.h"

extern f32 func_L39_006325D8(void *, void *);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);

void func_L39_0062D0C8(u8 *self, f32 a) {
    u8 *v = self + 0x190;
    f32 len = func_L39_006325D8(self, v);
    f32 d;

    if (0.001f < len) {
        func_L39_00632558(self, v, v, 0.0f);
        d = len - a;
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_L39_00632298(self, v, v, d);
        vec_add_ab(self + 0x120, self + 0x120, v);
    } else {
        qzero(v);
    }
}
/* localdecomp:end func_L39_0062D0C8 */

INCLUDE_ASM("asm/levels", func_L39_0062D190);
