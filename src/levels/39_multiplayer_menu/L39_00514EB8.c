#include "common.h"

/* localdecomp:start func_L39_00514EB8 */
typedef struct S_00514EB8 {
    s32 cap;
    s32 n;
    u64 *d;
} S_00514EB8;
extern s32 func_L39_00514CF8(s32, S_00514EB8 *);
extern s32 func_L39_00512948(s32, S_00514EB8 *);

s32 func_L39_00514EB8(s32 bits, S_00514EB8 *s) {
    s32 r;
    s32 n;
    s32 rs;
    u64 carry;
    u64 *d;

    if (bits <= 0) {
        return 0;
    }
    if (bits >= 64) {
        n = bits / 64;
        r = func_L39_00514CF8(n, s);
        if (r != 0) {
            return r;
        }
        bits -= n * 64;
        if (bits == 0) {
            return 0;
        }
    }
    n = s->n;
    rs = 64 - bits;
    carry = s->d[n - 1] >> rs;
    if (carry != 0) {
        if (s->cap < n + 1) {
            r = func_L39_00512948(n + 2, s);
            if (r != 0) {
                return r;
            }
        }
        s->d[n] = carry;
        s->n++;
    }
    d = s->d;
    n--;
    if (n == 0) {
        d[0] <<= bits;
        return 0;
    }
    d[n] <<= bits;
    while (n-- > 0) {
        d[n + 1] |= d[n] >> rs;
        d[n] <<= bits;
    }
    return 0;
}
/* localdecomp:end func_L39_00514EB8 */
