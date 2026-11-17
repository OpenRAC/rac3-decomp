#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A5818 */
extern void func_003C4360(void *, f32, f32, f32, f32);

void func_L31_003A5818(u8 *a0, f32 a, f32 b, f32 c, f32 d)
{
    u8 *o = *(u8 **)(a0 + 0x68);
    f32 cur = *(f32 *)(o + 0x180);

    if (*(f32 *)(a0 + 0x10) < cur) {
        cur += a * 0.9f;
    } else {
        cur += a * -0.9f;
    }
    func_003C4360(o + 0x160, cur - *(f32 *)(a0 + 0x10), c, d, b);
}
/* localdecomp:end func_L31_003A5818 */
