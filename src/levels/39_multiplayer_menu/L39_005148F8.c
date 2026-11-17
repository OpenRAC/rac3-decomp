#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);

/* localdecomp:start func_L39_005148F8 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_005148F8;
extern s32 func_L39_00512948(s32, void *);
extern void func_L39_004F74E8(void *, s32, s32);
s32 func_L39_005148F8(S_005148F8 *a, S_005148F8 *r) {
    unsigned long *out;
    unsigned long *src;
    unsigned long sum;
    unsigned long t;
    unsigned long u;
    unsigned long carry;
    s32 i;
    s32 e;

    if (r->n < a->n) {
        i = a->n;
        if (r->cap < i) {
            e = func_L39_00512948(i + 1, r);
            if (e != 0) {
                return e;
            }
        }
        func_L39_004F74E8(r->d + r->n, 0, (i - r->n) * 8);
        r->n = i;
    }
    out = r->d;
    src = a->d;
    carry = 0;
    for (i = 0; i < a->n; i++) {
        sum = *out + *src;
        t = sum + carry;
        carry = 0;
        *out++ = t;
        if (sum < *src++ || t < sum) {
            carry = 1;
        }
    }
    if (carry == 0) {
        return 0;
    }
    for (; i < r->n; i++) {
        u = *out + carry;
        carry = u == 0;
        *out = u;
        if (carry == 0) {
            break;
        }
        out++;
    }
    if (carry == 0) {
        return 0;
    }
    i = r->n + 1;
    if (r->cap < i) {
        e = func_L39_00512948(i, r);
        if (e != 0) {
            return e;
        }
    }
    r->d[i - 1] = 1;
    r->n = i;
    return 0;
}
/* localdecomp:end func_L39_005148F8 */

/* localdecomp:start func_L39_00514AA0 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00514AA0;

s32 func_L39_00514AA0(S_00514AA0 *a, S_00514AA0 *b) {
    s32 bn = b->n;
    unsigned long *bd = b->d;
    unsigned long *ad = a->d;
    s32 an = a->n;
    s32 borrow = 0;
    s32 i;
    s32 j;

    if (bn < an) {
        return 0x109;
    }
    for (i = 0; i < an; i++) {
        unsigned long x = bd[i];
        unsigned long y;
        bd[i] = x - ad[i];
        borrow = x < bd[i];
        if (borrow) {
            for (j = i + 1; j < bn; j++) {
                x = bd[j];
                y = x - 1;
                bd[j] = y;
                borrow = x < y;
                if (!borrow) {
                    break;
                }
            }
        }
    }
    if (borrow) {
        return 0x109;
    }
    while (b->d[b->n - 1] == 0 && b->n >= 2) {
        b->n--;
    }
    return 0;
}
/* localdecomp:end func_L39_00514AA0 */
