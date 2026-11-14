#include "common.h"

/* localdecomp:start func_L39_004CA2E8 */
typedef struct { u8 pad[8]; unsigned long key; } S_004CA2E8;

s32 func_L39_004CA2E8(S_004CA2E8 **a, S_004CA2E8 **b) {
    unsigned long mask = 0xFFFFFF;
    unsigned long x = (*a)->key;
    unsigned long y = (*b)->key;
    x &= mask;
    y &= mask;
    if (x == y) {
        return 0;
    }
    return (y < x) ? 1 : -1;
}
/* localdecomp:end func_L39_004CA2E8 */
