#include "common.h"

/* localdecomp:start func_L39_005185D0 */
typedef struct {
    u64 f0;
    u32 f10;
    u8 f14;
} S_005185D0;

s32 func_L39_005185D0(S_005185D0 *p) {
    s32 n;
    u32 v = p->f10;
    s32 s;
    if (v < 0x1F) {
        n = 1;
    } else if (v < 0x80) {
        n = 2;
    } else {
        if (v <= 0x3FFF) n = 3; else n = 4;
    }
    s = (s32)p->f0;
    if (p->f14 & 2) {
        n += 1;
    } else if ((u32)s < 0x80) {
        n += 1;
    } else if ((u32)s < 0x100) {
        n += 2;
    } else if ((u32)s <= 0xFFFF) {
        n += 3;
    } else if ((u32)s <= 0xFFFFFF) {
        n += 4;
    } else {
        n += 5;
    }
    return n;
}
/* localdecomp:end func_L39_005185D0 */
