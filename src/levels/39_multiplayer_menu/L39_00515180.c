#include "common.h"

/* localdecomp:start func_L39_00515180 */
typedef struct { s32 cap; s32 n; long *d; } S_00515180;

s32 func_L39_00515180(s32 i, S_00515180 *s) {
    long *d = s->d;
    while (d[i] == 0 && i > 0) i--;
    s->n = i + 1;
    return 0;
}
/* localdecomp:end func_L39_00515180 */

/* localdecomp:start func_L39_005151E8 */
typedef struct { s32 cap; s32 n; long *d; } S_005151E8;
s32 func_L39_005151E8(S_005151E8 *s, s32 *out) {
    long v = s->d[s->n - 1];
    s32 c = 0;
    if (v != 0) {
        if (v >= 0) {
            do {
                v <<= 1;
                c++;
            } while (!(v & 0x8000000000000000L));
        }
        *out = c;
        return 0;
    }
    *out = 0x40;
    return 0;
}
/* localdecomp:end func_L39_005151E8 */

LINKER_REMNANT("asm/levels", func_L39_00515250);

/* localdecomp:start func_L39_00515258 */
typedef struct {
    s32 cap;
    s32 size;
    unsigned long *data;
} S_00515258;

extern unsigned long func_1306F8(unsigned long, unsigned long);

void func_L39_00515258(unsigned long x, void *a, s32 aoff, s32 n, void *r, s32 roff) {
    unsigned long *ap;
    unsigned long *rp;
    unsigned long carry;
    unsigned long xl;
    unsigned long xh;
    unsigned long yl;
    unsigned long yh;
    unsigned long hh;
    unsigned long lh;
    unsigned long mid;
    unsigned long lo;
    unsigned long v;
    s32 i;

    carry = 0;
    ap = ((S_00515258 *)a)->data + aoff;
    rp = ((S_00515258 *)r)->data + roff;
    for (i = 0; i < n; i++) {
        xl = x & 0xFFFFFFFF;
        xh = x >> 32;
        yl = ap[i] & 0xFFFFFFFF;
        yh = ap[i] >> 32;
        lo = func_1306F8(xl, yl);
        hh = func_1306F8(xh, yh);
        lh = func_1306F8(xl, yh);
        mid = lh + func_1306F8(yl, xh);
        if (mid < lh) {
            hh += 0x100000000;
        }
        hh += mid >> 32;
        mid <<= 32;
        lo = lo + mid;
        if (lo < mid) {
            hh++;
        }
        v = rp[i];
        lo += v;
        if (lo < v) {
            hh++;
        }
        lo += carry;
        if (lo < carry) {
            hh++;
        }
        rp[i] = lo;
        carry = hh;
    }
    rp[i] += carry;
    if (rp[i] < carry) {
        i++;
        while (rp[i] == 0xFFFFFFFFFFFFFFFF) {
            rp[i] = 0;
            i++;
        }
        rp[i]++;
    }
}
/* localdecomp:end func_L39_00515258 */
