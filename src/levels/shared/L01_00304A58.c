#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));


/* localdecomp:start func_L01_00304A58 */
s32 func_L01_00304A58(s32 x) {
    s32 d = 16;
    if (x % d) {
        x = ((s32)((f32)x / (f32)d) + 1) << 4;
    }
    return x;
}
/* localdecomp:end func_L01_00304A58 */
