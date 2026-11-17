#include "common.h"

/* localdecomp:start func_L39_004B5910 */
u32 func_L39_004B5910(u32 x) {
    u32 r;
    u32 t;
    do { r = x << 24; } while (0);
    t = x & 0xFF00;
    t <<= 8;
    r |= t;
    t = x >> 8;
    t &= 0xFF00;
    r |= t;
    t = x >> 24;
    r |= t;
    return r;
}
/* localdecomp:end func_L39_004B5910 */

INCLUDE_ASM("asm/levels", func_L39_004B5938);
