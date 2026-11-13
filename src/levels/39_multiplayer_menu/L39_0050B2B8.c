#include "common.h"

/* localdecomp:start func_L39_0050B2B8 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_0050B2B8;
typedef struct {
    s32 tos;
    BN_0050B2B8 bn[1];
} Ctx_0050B2B8;
typedef struct {
    s32 use_word;
    s32 ri_bits;
    s32 ri;
    BN_0050B2B8 RR;
    BN_0050B2B8 N;
    BN_0050B2B8 Ni;
    unsigned long n0;
} Mont_0050B2B8;

struct BN_0050B748;
extern struct BN_0050B748 *func_L39_004FC4B8(struct BN_0050B748 *, s32);
extern void func_L39_0050BA58(unsigned long *, unsigned long *, s32, unsigned long *);
extern void func_L39_004FD0F8(unsigned long *, unsigned long *, s32, unsigned long *, s32);
extern void func_L39_0050BEE0(unsigned long *, unsigned long *, unsigned long *, s32, unsigned long);
extern void func_L39_004FC318(void *);

/* OpenSSL BN_mod_mul_montgomery (word version) */
s32 func_L39_0050B2B8(BN_0050B2B8 *r, BN_0050B2B8 *a, BN_0050B2B8 *b, Mont_0050B2B8 *mont, Ctx_0050B2B8 *ctx) {
    BN_0050B2B8 *tmp, *tmp2;
    s32 retn;
    s32 i, num, max;

    retn = 0;
    num = mont->ri;
    tmp = &ctx->bn[ctx->tos++];
    tmp2 = &ctx->bn[ctx->tos++];

    max = num * 2;
    if (((max <= tmp->dmax) ? tmp : (BN_0050B2B8 *)func_L39_004FC4B8((struct BN_0050B748 *)tmp, max)) == 0) goto err;
    if (((num * 2 <= r->dmax) ? r : (BN_0050B2B8 *)func_L39_004FC4B8((struct BN_0050B748 *)r, num * 2)) == 0) goto err;

    if (a == b) {
        if (((num * 2 <= tmp2->dmax) ? tmp2 : (BN_0050B2B8 *)func_L39_004FC4B8((struct BN_0050B748 *)tmp2, num * 2)) == 0) goto err;
        func_L39_0050BA58(tmp->d, a->d, a->top, tmp2->d);
    } else {
        func_L39_004FD0F8(tmp->d, a->d, a->top, b->d, b->top);
    }
    for (i = a->top + b->top; i < num * 2; i++) tmp->d[i] = 0;
    tmp->top = max;
    tmp->neg = 0;
    retn = 1;
    func_L39_0050BEE0(r->d, tmp->d, mont->N.d, num, mont->n0);
    r->neg = 0;
    r->top = num;
    func_L39_004FC318(r);
err:
    ctx->tos -= 2;
    return retn;
}
/* localdecomp:end func_L39_0050B2B8 */

/* localdecomp:start func_L39_0050B4C0 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_0050B4C0;
typedef struct {
    s32 tos;
    BN_0050B4C0 bn[1];
} Ctx_0050B4C0;
typedef struct {
    s32 use_word;
    s32 ri_bits;
    s32 ri;
    BN_0050B4C0 RR;
    BN_0050B4C0 N;
    BN_0050B4C0 Ni;
    unsigned long n0;
} Mont_0050B4C0;

extern void *func_L39_004FC5C0(void *, void *);
extern unsigned long func_001306F8(unsigned long, unsigned long);
extern unsigned long func_L39_004FD710(unsigned long *, unsigned long *, s32, unsigned long);
extern void func_L39_004FC318(void *);
extern s32 func_L39_0050B748(struct BN_0050B748 *, struct BN_0050B748 *, s32);
extern s32 func_L39_004FC960(BN_0050B4C0 *, BN_0050B4C0 *);
extern s32 func_L39_004FBBE8(BN_0050B4C0 *, BN_0050B4C0 *, BN_0050B4C0 *);

/* OpenSSL BN_from_montgomery */
s32 func_L39_0050B4C0(BN_0050B4C0 *ret, BN_0050B4C0 *a, Mont_0050B4C0 *mont, Ctx_0050B4C0 *ctx) {
    BN_0050B4C0 *n, *r;
    unsigned long *ap, *np, *rp, *nrp, n0, v, c;
    s32 al, nl, max, i;
    s32 retn;

    retn = 0;
    r = &ctx->bn[ctx->tos];
    if (!func_L39_004FC5C0(r, a)) goto err1;
    n = &mont->N;
    al = mont->ri;
    nl = n->top;
    if ((al == 0) || (nl == 0)) {
        r->top = 0;
        return 1;
    }
    max = nl + al + 1;
    if (((max <= r->dmax) ? r : (BN_0050B4C0 *)func_L39_004FC4B8((struct BN_0050B748 *)r, max)) == 0) goto err1;
    if (((max <= ret->dmax) ? ret : (BN_0050B4C0 *)func_L39_004FC4B8((struct BN_0050B748 *)ret, max)) == 0) goto err1;

    r->neg = a->neg ^ n->neg;
    np = n->d;
    rp = r->d;
    nrp = &r->d[nl];
    for (i = r->top; i < max; i++) r->d[i] = 0;
    r->top = max;

    c = 0;
    n0 = mont->n0;
    for (i = 0; i < nl; i++) {
        v = func_L39_004FD710(rp, np, nl, func_001306F8(rp[0], n0));
        rp++;
        v += c;
        c = v < c;
        *nrp += v;
        c += *nrp < v;
        nrp++;
    }
    *nrp = c;
    func_L39_004FC318(r);
    func_L39_0050B748((struct BN_0050B748 *)ret, (struct BN_0050B748 *)r, mont->ri * 64);
    if (func_L39_004FC960(ret, &mont->N) >= 0) func_L39_004FBBE8(ret, ret, &mont->N);
    retn = 1;
err1:
    return retn;
}
/* localdecomp:end func_L39_0050B4C0 */

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

/* localdecomp:start func_L39_0050B8C8 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_0050B8C8;
typedef struct {
    s32 tos;
    BN_0050B8C8 bn[1];
} Ctx_0050B8C8;

extern void func_L39_0050BA58(unsigned long *, unsigned long *, s32, unsigned long *);
extern void *func_L39_004FC5C0(void *, void *);

/* OpenSSL BN_sqr */
s32 func_L39_0050B8C8(BN_0050B8C8 *r, BN_0050B8C8 *a, Ctx_0050B8C8 *ctx) {
    s32 max, al;
    BN_0050B8C8 *tmp, *rr;
    unsigned long t4[8];
    unsigned long t8[16];

    tmp = &ctx->bn[ctx->tos];
    rr = (a != r) ? r : &ctx->bn[ctx->tos + 1];

    al = a->top;
    if (al <= 0) {
        r->top = 0;
        return 1;
    }
    max = al + al;
    if (((max <= rr->dmax) ? rr : (BN_0050B8C8 *)func_L39_004FC4B8((void *)rr, max)) == 0) return 0;
    rr->top = max;
    rr->neg = 0;

    if (al == 4) {
        func_L39_0050BA58(rr->d, a->d, 4, t4);
    } else if (al == 8) {
        func_L39_0050BA58(rr->d, a->d, 8, t8);
    } else {
        if (((max <= tmp->dmax) ? tmp : (BN_0050B8C8 *)func_L39_004FC4B8((void *)tmp, max)) == 0) return 0;
        func_L39_0050BA58(rr->d, a->d, al, tmp->d);
    }

    if ((max > 0) && (rr->d[max - 1] == 0)) rr->top--;
    if (rr != r) func_L39_004FC5C0(r, rr);
    return 1;
}
/* localdecomp:end func_L39_0050B8C8 */

INCLUDE_ASM("asm/levels", func_L39_0050BA58);

/* localdecomp:start func_L39_0050BB88 */
typedef struct BN_0050BB88 {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_0050BB88;
typedef struct CTX_0050BB88 {
    s32 tos;
    BN_0050BB88 bn[1];
} CTX_0050BB88;
extern s32 func_L39_0050BD10();
extern u8 D_L39_00479810[];
extern u8 D_L39_00479820[];
extern u8 D_L39_00479830[];

s32 func_L39_0050BB88(BN_0050BB88 *a, u8 **out, s32 arg2, CTX_0050BB88 *ctx) {
    BN_0050BB88 *tmp;
    u8 *p;
    s32 top;
    s32 b, c;
    s32 i;
    s32 len;
    s32 n;

    tmp = &ctx->bn[ctx->tos];
    p = 0;
    top = a->top;
    i = top * 64;
    if (top == 0) {
        return 0;
    }
    if (top == 1) {
        if (a->d[0] == 0x10001) {
            p = D_L39_00479830;
        } else if (a->d[0] == 17) {
            p = D_L39_00479820;
        } else if (a->d[0] == 3) {
            p = D_L39_00479810;
        }
        b = 1;
        c = 1;
        i = 64;
    } else if (i >= 256) {
        b = 5;
        c = 16;
        i = 13;
    } else if (i >= 128) {
        b = 4;
        c = 8;
        i = 16;
    } else {
        b = 3;
        c = 4;
        i = 22;
    }
    n = (top * i + 5) / 4;
    if (p == 0) {
        if (tmp->dmax < n) {
            func_L39_004FC4B8((BN_0050B748 *)tmp, n);
        }
        p = (u8 *)tmp->d;
        len = func_L39_0050BD10(p + 4, a, b) + 2;
        p[2] = b;
        p[3] = c;
        p[0] = len >> 8;
        p[1] = len;
    } else {
        len = 8;
    }
    *out = p;
    return len + 2;
}
/* localdecomp:end func_L39_0050BB88 */

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
