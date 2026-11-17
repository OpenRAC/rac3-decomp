#include "common.h"

/* localdecomp:start func_L40_003F5248 */
s32 func_L40_003F5248(f32 *v) {
    if (v[0] < -10.0f) return 0;
    if (v[1] < -10.0f) return 0;
    if (v[2] < -10.0f) return 0;
    if (v[0] > 10.0f) return 0;
    if (v[1] > 10.0f) return 0;
    if (v[2] > 10.0f) return 0;
    return 1;
}
/* localdecomp:end func_L40_003F5248 */
