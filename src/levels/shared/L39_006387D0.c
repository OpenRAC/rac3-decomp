#include "common.h"

/* localdecomp:start func_L39_006387D0 */
extern void func_0038CE20(void *, void *, f32);

void func_L39_006387D0(u8 *a0, f32 s) {
    func_0038CE20(a0 + 320, a0 + 320, s);
    func_0038CE20(a0 + 336, a0 + 336, s);
    func_0038CE20(a0 + 288, a0 + 288, s);
    func_0038CE20(a0 + 400, a0 + 400, s);
    *(f32 *)(a0 + 4020) *= s;
}
/* localdecomp:end func_L39_006387D0 */
