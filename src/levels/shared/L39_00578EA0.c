#include "common.h"

/* localdecomp:start func_L39_00578EA0 */
#include "vu0.h"
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_0024111C, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_0024111C;

f32 func_L39_00578EA0(f32 *p, f32 a, f32 b, f32 c, f32 d, f32 e) {
    b = b - a;
    if (*D_L39_00241120 >= 2) {
        if (D_L39_0024111C == 1) {
            c = c * 60.0f / 30.0f;
            if (e != 0.0f) {
                e = e * 60.0f / 30.0f;
            }
        }
    }
    *p = *p + (c * b - d * *p);
    if (e != 0.0f) {
        if (*p > e) {
            *p = e;
        } else if (*p < -e) {
            *p = -e;
        }
    }
    b = fabs_asm(b);
    if (*p > b) {
        *p = b;
    } else if (*p < -b) {
        *p = -b;
    }
    return a + *p;
}
/* localdecomp:end func_L39_00578EA0 */
