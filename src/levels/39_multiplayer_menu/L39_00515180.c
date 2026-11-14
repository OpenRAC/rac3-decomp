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

INCLUDE_ASM("asm/levels", func_L39_00515438);

INCLUDE_ASM("asm/levels", func_L39_005155E8);

INCLUDE_ASM("asm/levels", func_L39_005156F4);

INCLUDE_ASM("asm/levels", func_L39_00515708);

INCLUDE_ASM("asm/levels", func_L39_00515778);

/* localdecomp:start func_L39_00515A70 */
/* best: 82 diff (mostly shifted by 1). Retail keeps the call result live in $v0 along the fall-through (bnez, lw $a0 for the src reload, no move $v0,$zero); this C lets gcc know res==0 after the test, so it uses $v0 as a temp and adds move $v0,$zero. Tried: early returns, nested ifs, single-exit res=0x20F, return 0. */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; s32 *f1C; s32 *f20; s32 *f24; } S_00515A70;
extern u8 D_L39_0046F468[];
extern s32 func_L39_005084A8(s32, S_00515A70 **, u8 *);
extern s32 func_L39_004F6060(s32, s32 **, s32);

s32 func_L39_00515A70(s32 **arg0, s32 arg1) {
    S_00515A70 *src;
    s32 res;
    s32 *dst;

    res = func_L39_005084A8(arg1, &src, D_L39_0046F468);
    if (res != 0) {
        return res;
    }
    if (src->f18 != 2) {
        return 0x20F;
    }
    res = func_L39_004F6060(arg1, arg0, 0x40);
    if (res != 0) {
        return res;
    }
    dst = *arg0;
    dst[0] = src->f0;
    dst[1] = src->f4;
    dst[2] = src->f8;
    dst[3] = src->fC;
    dst[4] = src->f10;
    dst[5] = src->f14;
    dst[6] = src->f1C[0];
    dst[7] = src->f1C[1];
    dst[8] = src->f1C[2];
    dst[9] = src->f1C[3];
    dst[10] = src->f20[0];
    dst[11] = src->f20[1];
    dst[12] = src->f20[2];
    dst[13] = src->f20[3];
    dst[14] = src->f24[0];
    dst[15] = src->f24[1];
    return res;
}
/* localdecomp:end func_L39_00515A70 */
