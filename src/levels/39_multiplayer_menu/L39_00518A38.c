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

/* localdecomp:start func_L39_00518A60 */
u32 func_L39_00518A60(u32 x) {
    u32 t;
    u32 r;
    do { r = x << 8; } while (0);
    r &= 0xFF00;
    t = x >> 8;
    if ((s32)x < 0) {
        t &= 0xFF;
    } else {
        t &= 0xFF;
    }
    return r | t;
}
/* localdecomp:end func_L39_00518A60 */
