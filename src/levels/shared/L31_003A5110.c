#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A5110 */
typedef int u128_3A3890 __attribute__((mode(TI)));
extern f32 func_0038CF00(void *, void *);
void func_L31_003A5110(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 d = func_0038CF00(s1 + 384, s1 + 400);
    if (d < func_0038CF00(s1 + 384, s1 + 416)) {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 416);
    } else {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 400);
    }
}
/* localdecomp:end func_L31_003A5110 */

/* localdecomp:start func_L31_003A5178 */
/* func_L31_003A5178: from the staged near miss. The fabs is include/vu0.h's fabs_asm: retail loads
   the gp float before abs.s, which __builtin_fabsf schedules first. */
extern f32 D_L31_001DE960;
extern f32 func_L31_003A5B00(void *, f32 *);
extern f32 func_0038DB00(f32, f32);

int func_L31_003A5178(void *m, f32 *pos) {
    f32 r = func_L31_003A5B00(m, pos);
    f32 d = func_0038DB00(*(f32 *)((u8 *)m + 0xF8), r);

    if (fabs_asm(d) > D_L31_001DE960) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L31_003A5178 */
