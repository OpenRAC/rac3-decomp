#include "common.h"

/* localdecomp:start func_L39_00518020 */
typedef struct S_00518020 {
    u64 value;
    u8 pad8[0x10 - 0x8];
    u32 tag;
    u8 flags;
} S_00518020;

s32 func_L39_00518020(u8 *buf, S_00518020 *s) {
    u32 tag = s->tag;
    u8 cls = s->flags & 0xE0;
    u8 *p;
    u8 *lp;
    u64 v;
    s32 n;

    if (tag < 0x1F) {
        *buf = cls | tag;
        p = buf + 1;
    } else {
        cls |= 0x1F;
        *buf = cls;
        p = buf + 1;
        if (tag >= 0x4000) {
            *p++ = (tag >> 14) & 0x7F;
        }
        if (tag >= 0x80) {
            *p++ = (tag >> 7) & 0x7F;
        }
        *p++ = tag & 0x7F;
    }
    v = s->value;
    if (s->flags & 2) {
        *p = 0x50;
    } else if (v < 0x80) {
        *p = v;
    } else {
        lp = p++;
        n = 1;
        if (v > 0xFFFFFF) {
            *p++ = v >> 24;
            n = 2;
        }
        if (v > 0xFFFF) {
            *p++ = v >> 16;
            n++;
        }
        if (v >= 0x100) {
            *p++ = v >> 8;
            n++;
        }
        *p = v;
        *lp = n | 0x80;
    }
    p++;
    return p - buf;
}
/* localdecomp:end func_L39_00518020 */

