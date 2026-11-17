#include "common.h"

/* declared by functions of L39_00510BA8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;

/* localdecomp:start func_L39_00512778 */
s32 func_L39_00512778(s32 arg0)
{
    if (arg0 >= 0x3FC) {
        return 6;
    }
    if (arg0 >= 0x17E) {
        return 5;
    }
    if (arg0 >= 0x50) {
        return 4;
    }
    if (arg0 >= 0x13) {
        return 3;
    }
    return 2;
}
/* localdecomp:end func_L39_00512778 */

/* localdecomp:start func_L39_005127B8 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_005127B8;

s32 func_L39_005127B8(S_005127B8 *a, s32 i, s32 w, s32 *skip, s32 *val) {
    unsigned long *d = a->d;
    unsigned long v;
    s32 k = i / 64;
    s32 j = i - k * 64;
    s32 zeros = 0;

    v = d[k];
    v <<= 63 - j;
    k--;
    while (!(v & 0x8000000000000000)) {
        i--;
        j--;
        zeros++;
        if (i < 0) {
            *skip = zeros;
            *val = v >> 63;
            return 0;
        }
        if (j < 0) {
            v = d[k];
            k--;
            j = 63;
        } else {
            v <<= 1;
        }
    }
    if (j + 1 < w) {
        if (k >= 0) {
            v |= d[k] >> (j + 1);
        } else {
            w = j + 1;
        }
    }
    v >>= 64 - w;
    while (!(v & 1)) {
        v >>= 1;
        w--;
    }
    *skip = zeros + w;
    *val = v;
    return 0;
}
/* localdecomp:end func_L39_005127B8 */
