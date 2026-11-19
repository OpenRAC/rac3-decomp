#include "common.h"

/* declared by functions of L39_00510EF0.c, which this file was cut from */
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;
extern s32 func_L39_00512A40(s32, S_00510EF0 *);

/* localdecomp:start func_L39_00510FF0 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00510FF0;
extern s32 func_L39_00512948(s32, void *);

s32 func_L39_00510FF0(S_00510FF0 *a, S_00510FF0 *b, S_00510FF0 *r) {
    unsigned long *big;
    unsigned long *small;
    unsigned long *out;
    unsigned long sum;
    s32 max;
    s32 min;
    s32 i;
    unsigned long carry;
    s32 e;
    unsigned long t;

    if (a->n >= b->n) {
        big = a->d;
        max = a->n;
        small = b->d;
        min = b->n;
    } else {
        big = b->d;
        max = b->n;
        small = a->d;
        min = a->n;
    }
    if (r->cap >= max || (e = func_L39_00512A40(max + 1, (S_00510EF0 *)r)) == 0) {
        out = r->d;
        carry = 0;
        for (i = 0; i < min; i++) {
            sum = *small + *big++;
            t = sum + carry;
            carry = 0;
            *out++ = t;
            if (sum < *small++ || t < sum) {
                carry = 1;
            }
        }
        for (; i < max; i++) {
            *out = *big + carry;
            carry = *out++ < *big++;
        }
        r->n = i;
        if (carry == 0) {
            return 0;
        }
        i++;
        if (r->cap >= i || (e = func_L39_00512948(i, r)) == 0) {
            r->n = i;
            r->d[max] = 1;
            return 0;
        }
    }
    return e;
}
/* localdecomp:end func_L39_00510FF0 */
