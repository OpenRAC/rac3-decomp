#include "common.h"

/* localdecomp:start func_L30_00346080 */
#include "vu0.h"
__asm__(".extern D_L30_001DCF2C, 4");
__asm__(".extern D_L30_001DCF30, 4");
__asm__(".extern D_L30_001DCF34, 4");
extern f32 D_L30_001DCF2C;
extern f32 D_L30_001DCF30;
extern f32 D_L30_001DCF34;
extern void func_00389478(void *, f32 *, f32 *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
void func_L30_00346080(void *a0, void *a1, f32 *x, f32 *y, f32 a, f32 b, f32 c, f32 d) {
    f32 t;
    f32 s;
    f32 k;
    f32 u;
    func_00389478(a1, x, y);
    t = D_L30_001DCF34 * b;
    k = 1.0f - d;
    t = t - cvtsw_asm(cvtws_asm(t));
    s = t + D_L30_001DCF30 * d;
    s = func_0038D0B0(func_0038DB48(s * 6.2831855f));
    s *= k * D_L30_001DCF2C * c;
    *x += s;
    u = D_L30_001DCF34 * a;
    u = u - cvtsw_asm(cvtws_asm(u));
    s = u + D_L30_001DCF30 * d;
    s = func_0038D0B0(func_0038DB48(s * 6.2831855f));
    s *= k * D_L30_001DCF2C * c;
    *y += s;
    if (1.0f < *x) {
        *x = 1.0f;
    } else if (*x < 0.0f) {
        *x = 0.0f;
    }
    if (1.0f < *y) {
        *y = 1.0f;
    } else if (*y < 0.0f) {
        *y = 0.0f;
    }
}
/* localdecomp:end func_L30_00346080 */
