// NEAR MISS: body matches word for word; retail's 60-byte window starts with 8 bytes of the previous function's tail (movn $v0,$v1,$a0; nop), so size-60 check always shows 15 diffs.
#include "common.h"
typedef struct { char _p[8]; s64 f8; } E_004C4128;
s32 func_L39_004C4128(E_004C4128 **a, E_004C4128 **b) {
    s64 d = (*a)->f8 - (*b)->f8;
    if (d == 0) return 0;
    return d > 0 ? 1 : -1;
}
