#include "common.h"

/* localdecomp:start func_L39_00518A38 */
u32 func_L39_00518A38(u32 x) {
    u32 t;
    u32 r;
    do { r = x << 24; } while (0);
    t = x & 0xFF00;
    t = t << 8;
    r = r | t;
    t = x >> 8;
    t = t & 0xFF00;
    r = r | t;
    t = x >> 24;
    return r | t;
}
/* localdecomp:end func_L39_00518A38 */

INCLUDE_ASM("asm/levels", func_L39_00518A60);
