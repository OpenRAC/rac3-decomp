#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0050B2B8);

INCLUDE_ASM("asm/levels", func_L39_0050B4C0);

INCLUDE_ASM("asm/levels", func_L39_0050B6F0);

/* localdecomp:start func_L39_0050B748 */
typedef struct BN_0050B748 {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
} BN_0050B748;
extern s32 func_L39_004FC6F8(BN_0050B748 *, unsigned long);
extern BN_0050B748 *func_L39_004FC4B8(BN_0050B748 *, s32);
extern void func_L39_004FC318(void *);

/* BN_rshift (OpenSSL 0.9.x bn_shift.c) */
s32 func_L39_0050B748(BN_0050B748 *r, BN_0050B748 *a, s32 n) {
    s32 i, j, nw, lb, rb;
    unsigned long *t, *f;
    unsigned long l, tmp;

    nw = n / 64;
    rb = n % 64;
    lb = 64 - rb;
    if (nw > a->top) {
        func_L39_004FC6F8(r, 0);
        return 1;
    }
    if (r != a) {
        if (((a->top - nw + 2 <= r->dmax) ? r : func_L39_004FC4B8(r, a->top - nw + 2)) == 0) {
            return 0;
        }
        r->neg = a->neg;
    }
    f = &a->d[nw];
    t = r->d;
    j = a->top - nw;
    r->top = j;
    if (rb == 0) {
        for (i = j + 1; i > 0; i--) {
            *(t++) = *(f++);
        }
    } else {
        l = *(f++);
        for (i = 1; i < j; i++) {
            tmp = l >> rb;
            l = *(f++);
            *(t++) = tmp | (l << lb);
        }
        *(t++) = l >> rb;
        *t = 0;
    }
    func_L39_004FC318(r);
    return 1;
}
/* localdecomp:end func_L39_0050B748 */

INCLUDE_ASM("asm/levels", func_L39_0050B8C8);

INCLUDE_ASM("asm/levels", func_L39_0050BA58);

INCLUDE_ASM("asm/levels", func_L39_0050BB88);

/* localdecomp:start func_L39_0050BD10 */
typedef struct {
    unsigned long *d;
    s32 top;
} BN_0050BD10;

extern u8 *D_L39_0046F320[];

s32 func_L39_0050BD10(u8 *out, BN_0050BD10 *a, s32 w) {
    u8 *tab;
    s32 mask;
    u8 *p;
    unsigned long *d;
    s32 top;
    unsigned long cur, next, window;
    s32 last;
    u32 carry, bits;
    s32 v, c;
    s32 ret;
    s32 n;

    if (w > 6) w = 6;
    tab = D_L39_0046F320[w];
    mask = (1 << w) - 1;
    bits = 0;
    next = 0;
    n = ((a->top * 64 + w - 1) / w) * 2 + 2;
    p = &out[n];
    *p = 0;
    p--;
    *p = 0;
    p--;
    d = a->d;
    top = a->top;
    window = *d++;
    cur = window;
    last = top < 2;
    if (!last) next = *d++;
    carry = 0;
    for (;;) {
        for (;;) {
            v = (s32)window & mask;
            if ((c = tab[v]) == 0) break;
            carry += c;
            if (carry >= 256) {
                *p-- = carry;
                carry -= 256;
                *p-- = 0;
            }
            bits += c;
            if (bits >= 64) {
                if (last) break;
                top--;
                last = top < 2;
                cur = next;
                next = last ? 0 : *d++;
                bits -= 64;
            }
            if (bits == 0) window = cur; else window = (cur >> bits) | (next << (64 - bits));
        }
        if (v == 0) break;
        *p-- = carry;
        carry = w;
        *p-- = v;
        bits += carry;
        if (bits >= 64) {
            if (last) break;
            top--;
            last = top < 2;
            cur = next;
            next = last ? 0 : *d++;
            bits -= 64;
        }
        if (bits == 0) window = cur; else window = (cur >> bits) | (next << (64 - bits));
    }
    p++;
    ret = 2;
    while (*p) {
        out[0] = p[0];
        ret += 2;
        out[1] = p[1];
        p += 2;
        out += 2;
    }
    out[0] = 0;
    out[1] = 0;
    return ret;
}
/* localdecomp:end func_L39_0050BD10 */

INCLUDE_ASM("asm/levels", func_L39_0050BEE0);

INCLUDE_ASM("asm/levels", func_L39_0050C0B4);

INCLUDE_ASM("asm/levels", func_L39_0050C110);

INCLUDE_ASM("asm/levels", func_L39_0050C20C);
