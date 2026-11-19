#include "common.h"

/* localdecomp:start func_L39_00510EF0 */
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;
extern s32 func_L39_00512A40(s32, S_00510EF0 *);
extern void func_L39_004F7510(void *, void *, s32);
s32 func_L39_00510EF0(S_00510EF0 *a, S_00510EF0 *b) {
    s32 n = a->n;
    s32 r;
    if (b->cap < n) {
        r = func_L39_00512A40(n, b);
        if (r != 0) return r;
    }
    func_L39_004F7510(b->d, a->d, n * 8);
    b->n = n;
    return 0;
}
/* localdecomp:end func_L39_00510EF0 */

/* localdecomp:start func_L39_00510F60 */
typedef struct {
    s32 f0;
    s32 top;
    u64 *d;
} BN_00510F60;

s32 func_L39_00510F60(void *va, void *vb) {
    BN_00510F60 *a = va;
    BN_00510F60 *b = vb;
    s32 na = a->top;
    s32 nb = b->top;
    u64 *ad = a->d;
    u64 *bd = b->d;
    s32 i;
    s32 ret;

    ret = (nb < na) ? 1 : -1;
    if (na == nb) {
        for (i = na - 1; i >= 0; i--) {
            if (ad[i] != bd[i]) {
                break;
            }
        }
        if (i < 0) {
            return 0;
        }
        return (ad[i] > bd[i]) ? 1 : -1;
    }
    return ret;
}
/* localdecomp:end func_L39_00510F60 */
