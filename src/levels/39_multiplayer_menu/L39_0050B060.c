#include "common.h"

/* localdecomp:start func_L39_0050B060 */
/* log: BN_num_bits_word (64-bit BN_ULONG) with a 16-entry nibble table */
extern s8 D_L39_00479800[];

s32 func_L39_0050B060(u64 l) {
    s32 n;

    if (l & 0xFFFFFFFF00000000ULL) {
        if (l & 0xFFFF000000000000ULL) {
            n = (l & 0xFF00000000000000ULL) ? 56 : 48;
        } else {
            n = (l & 0x0000FF0000000000ULL) ? 40 : 32;
        }
    } else {
        if (l & 0xFFFF0000ULL) {
            n = (l & 0xFF000000ULL) ? 24 : 16;
        } else {
            n = (l & 0xFF00ULL) ? 8 : 0;
        }
    }
    l >>= n;
    if (l & 0xF0) {
        return D_L39_00479800[(s32)(l >> 4)] + n + 4;
    }
    return D_L39_00479800[(s32)l] + n;
}
/* localdecomp:end func_L39_0050B060 */

/* localdecomp:start func_L39_0050B140 */
/* log: BN_set_bit (64-bit words), bn_wexpand inlined as a macro would leave it */
typedef struct {
    u64 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} S_0050B140;

extern S_0050B140 *func_L39_004FC4B8(S_0050B140 *, s32);

s32 func_L39_0050B140(S_0050B140 *a, s32 n) {
    s32 i, j, k;

    i = n / 64;
    j = n % 64;
    if (a->top <= i) {
        if (((i + 1 <= a->dmax) ? a : func_L39_004FC4B8(a, i + 1)) == 0) {
            return 0;
        }
        for (k = a->top; k < i + 1; k++) {
            a->d[k] = 0;
        }
        a->top = i + 1;
    }
    a->d[i] |= ((u64)1) << j;
    return 1;
}
/* localdecomp:end func_L39_0050B140 */

/* localdecomp:start func_L39_0050B258 */
typedef struct S_0050B258 {
    u64 *bits;
    s32 count;
} S_0050B258;

s32 func_L39_0050B258(S_0050B258 *s, s32 n) {
    s32 w;
    s32 b;

    if (n < 0) {
        return 0;
    }
    w = n / 64;
    b = n % 64;
    if (w >= s->count) {
        return 0;
    }
    return (s->bits[w] & ((u64)1 << b)) ? 1 : 0;
}
/* localdecomp:end func_L39_0050B258 */
