#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003A9348 */
void func_L05_003A9348(vu0_v4 *a, s32 n) {
    vu0_v4 d;
    vec_sub_ab(&d, &a[n - 2], &a[n - 3]);
    vec_add_ab(&a[n - 1], &a[n - 2], &d);
}
/* localdecomp:end func_L05_003A9348 */
