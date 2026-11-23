#include "common.h"

/* localdecomp:start func_L39_00511188 */
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00511188_Big;

extern s32 func_L39_00512948(s32, S_00511188_Big *);

s32 func_L39_00511188(unsigned long w, S_00511188_Big *b) {
    unsigned long *words = b->words;
    s32 i;
    s32 n;
    s32 ret;

    words[0] += w;
    if (words[0] >= w) {
        return 0;
    }
    n = b->count;
    for (i = 1; i < n; i++) {
        if (++words[i] != 0) {
            return 0;
        }
    }
    n++;
    if (b->cap < n) {
        ret = func_L39_00512948(n + 1, b);
        if (ret != 0) {
            return ret;
        }
    }
    b->words[i] = 1;
    b->count = n;
    return 0;
}
/* localdecomp:end func_L39_00511188 */

/* localdecomp:start func_L39_00511268 */
typedef struct {
    s32 cap;
    s32 n;
    unsigned long *d;
} S_00511268;

extern s32 func_L39_00512A40(s32, S_00511268 *);
extern s32 func_L39_00515180(s32, S_00511268 *);
extern void func_L39_004F7510(void *, void *, s32);

s32 func_L39_00511268(S_00511268 *a, S_00511268 *b, S_00511268 *r)
{
    s32 max, min, i, j, carry, ret;
    unsigned long *ap, *bp, *rp;
    unsigned long t1, t2, t3;

    min = b->n;
    max = a->n;
    bp = b->d;
    ap = a->d;
    if (max < min) {
        return 0x109;
    }
    if (r->cap < max) {
        ret = func_L39_00512A40(max + 1, r);
        if (ret != 0) {
            return ret;
        }
    }
    rp = r->d;
    t1 = ap[0] - bp[0];
    rp[0] = t1;
    carry = ap[0] < t1;
    for (i = 1; i < min; i++) {
        t1 = ap[i] - bp[i];
        rp[i] = t1;
        if (!carry) {
            carry = ap[i] < t1;
        } else {
            t2 = t1 - 1;
            rp[i] = t2;
            carry = ap[i] <= t2;
        }
    }
    if (i == max) {
        if (carry) {
            return 0x109;
        }
        return func_L39_00515180(max - 1, r);
    }
    if (!carry) {
        func_L39_004F7510(rp + i, ap + i, (max - i) * 8);
        r->n = max;
        return 0;
    }
    for (j = i; j < max; j++) {
        t3 = ap[j] - carry;
        rp[j] = t3;
        carry = ap[j] < t3;
    }
    if (carry) {
        return 0x109;
    }
    while (r->d[max - 1] == 0 && max >= 2) {
        max--;
    }
    r->n = max;
    return 0;
}
/* localdecomp:end func_L39_00511268 */

/* localdecomp:start func_L39_00511480 */
typedef struct {
    s32 unk0;
    s32 count;
    unsigned long *words;
} S_00511480_Big;

s32 func_L39_00511480(unsigned long arg0, S_00511480_Big *arg1) {
    unsigned long *words = arg1->words;
    s32 i;
    s32 n;

    if (words[0] >= arg0) {
        words[0] -= arg0;
        return 0;
    }
    words[0] -= arg0;
    n = arg1->count - 1;
    i = 1;
    if (i <= n) {
        if (--words[i] == (unsigned long)-1) {
            while (++i <= n) {
                if (--words[i] != (unsigned long)-1) {
                    break;
                }
            }
        }
    }
    if (i < n) {
        return 0;
    }
    if (i > n) {
        return 0x109;
    }
    if (words[i] == 0) {
        arg1->count--;
    }
    return 0;
}
/* localdecomp:end func_L39_00511480 */
