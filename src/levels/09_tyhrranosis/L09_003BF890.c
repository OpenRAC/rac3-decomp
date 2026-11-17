#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BF890 */
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 D_001A4C60[];
void func_L09_003BF890(u8 *a0)
{
    f32 d = func_0038CF38(a0 + 0x10, D_001A4C60);
    f32 lo = 0.0275000017f;

    if (d >= 40.0f) {
        func_L01_0045BD78(a0, 0.0072000003f, 0.120000005f, 0.0050265486f, 0.041887905f);
    } else if (d <= 20.0f) {
        func_L01_0045BD78(a0, 0.007f, lo, 0.0050265486f, 0.041887905f);
    } else {
        func_L01_0045BD78(a0, 0.0072000003f, (d - 20.0f) / 20.0f * 5.9725f + lo, 0.0050265486f, 0.041887905f);
    }
}
/* localdecomp:end func_L09_003BF890 */
