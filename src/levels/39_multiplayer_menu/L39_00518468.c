#include "common.h"

/* localdecomp:start func_L39_00518468 */
typedef struct {
    unsigned long f0;
    u8 *f8;
    s32 fC;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 f16;
} T_00518468;

s32 func_L39_00518468(T_00518468 *o, u8 *p, unsigned long len) {
    u32 i;
    u32 b, c;
    u32 tag;
    unsigned long v;
    u32 n;

    if (len < 2) {
        return 2;
    }
    b = p[0];
    i = 1;
    o->f14 = b & 0xE0;
    tag = b & 0x1F;
    if (tag == 0x1F) {
        tag = 0;
        n = 0;
        for (;;) {
            tag <<= 7;
            if (i >= len) {
                return 2;
            }
            c = p[i++];
            tag |= c & 0x7F;
            if (c & 0x80) {
                break;
            }
            n += 7;
            if (n > 32) {
                return 1;
            }
        }
    }
    o->f10 = tag;
    if (i >= len) {
        return 2;
    }
    v = p[i++];
    if (v & 0x80) {
        v &= 0x7F;
        if (!v) {
            o->f14 |= 2;
            o->f16 |= 8;
        } else {
            if (v > 8) {
                return 3;
            }
            if (i + v >= len) {
                return 2;
            }
            n = v;
            v = p[i++];
            n--;
            while (n != 0) {
                v = (v << 8) | p[i++];
                n--;
            }
        }
    }
    o->f0 = v;
    o->f8 = p + i;
    o->f15 = i;
    return 0;
}
/* localdecomp:end func_L39_00518468 */

LINKER_REMNANT("asm/levels", func_L39_005185C8);
