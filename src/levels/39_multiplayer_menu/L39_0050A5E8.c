#include "common.h"

/* localdecomp:start func_L39_0050A5E8 */
typedef struct S_0050A5E8 {
    s32 len;
    s32 f4;
    void *data;
} S_0050A5E8;

extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_0050A5E8(S_0050A5E8 *a, S_0050A5E8 *b) {
    s32 r;

    r = a->len - b->len;
    if (r == 0) {
        r = func_0011D2EC(a->data, b->data, a->len);
        if (r == 0) {
            r = a->f4 - b->f4;
        }
    }
    return r;
}
/* localdecomp:end func_L39_0050A5E8 */

/* localdecomp:start func_L39_0050A648 */
/* log: i2d of a two-field SEQUENCE (OpenSSL ASN1 style) */
extern s32 func_L39_004F97C0(void *, u8 **);
extern s32 func_L39_00515FC0(void *, u8 **);
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);

typedef struct {
    void *f0;
    void *f4;
    void *f8;
} S_0050A648;

s32 func_L39_0050A648(S_0050A648 *a, u8 **pp) {
    s32 len;
    s32 ret;
    u8 *p;

    if (a == 0) {
        return 0;
    }
    len = func_L39_004F97C0(a->f4, 0);
    len += func_L39_00515FC0(a->f8, 0);
    ret = func_L39_004FA1A0(1, len, 16);
    if (pp == 0) {
        return ret;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 1, len, 16, 0);
    func_L39_004F97C0(a->f4, &p);
    func_L39_00515FC0(a->f8, &p);
    *pp = p;
    return ret;
}
/* localdecomp:end func_L39_0050A648 */

/* localdecomp:start func_L39_0050A710 */
/* OpenSSL 0.9.6 d2i_X509_NAME_ENTRY (x_name.c), built from the M_ASN1_D2I_ macros */
typedef struct {
    s32 f0;
    void *object;
    void *value;
    s32 set;
} S_0050A710;
typedef struct {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    s64 slen;
    u8 *max;
    u8 *q;
    u8 **pp;
    s32 line;
} ASN1_CTX_0050A710;

extern S_0050A710 *func_L39_004FAB88(void);
extern s32 func_L39_004FA2A8(ASN1_CTX_0050A710 *, s64 *);
extern void *func_L39_004F9870(void **, u8 **, s64);
extern void *func_L39_00515FE0(void **, u8 **, s64);
extern s32 func_L39_004FA228(ASN1_CTX_0050A710 *);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_004FAC00(S_0050A710 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

S_0050A710 *func_L39_0050A710(S_0050A710 **a, u8 **pp, s64 length) {
    ASN1_CTX_0050A710 c;
    S_0050A710 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004FAB88()) == 0) {
            c.line = 0x3E;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : (c.p + length);
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x41;
        goto err;
    }
    c.q = c.p;
    if (func_L39_004F9870(&ret->object, &c.p, c.slen) == 0) {
        c.line = 0x42;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_00515FE0(&ret->value, &c.p, c.slen) == 0) {
        c.line = 0x43;
        goto err;
    }
    c.slen -= (c.p - c.q);
    ret->set = 0;
    if (!func_L39_004FA228(&c)) {
        c.line = 0x45;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(13, 0xA8, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FAC00(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_0050A710 */

LINKER_REMNANT("asm/levels", func_L39_0050A8D0);

/* localdecomp:start func_L39_0050A8D8 */
typedef struct BN_0050A8D8 {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_0050A8D8;

typedef struct {
    s32 tos;
    BN_0050A8D8 bn[16];
} CTX_0050A8D8;

extern s32 func_L39_004FC960(BN_0050A8D8 *, BN_0050A8D8 *);
extern BN_0050A8D8 *func_L39_004FC5C0(BN_0050A8D8 *, BN_0050A8D8 *);
extern s32 func_L39_004FC6F8(BN_0050A8D8 *, unsigned long);
extern s32 func_L39_004FC158(BN_0050A8D8 *);
extern void *func_L39_004FCB28(BN_0050A8D8 *, BN_0050A8D8 *, s32);
extern void func_L39_004FC370(BN_0050A8D8 *);
extern BN_0050A8D8 *func_L39_004FC4B8(BN_0050A8D8 *, s32);
extern s32 func_L39_004FBBE8(BN_0050A8D8 *, BN_0050A8D8 *, BN_0050A8D8 *);
extern unsigned long func_L39_004FFEE0(unsigned long, unsigned long, unsigned long);
extern unsigned long func_L39_004FDA88(unsigned long *, unsigned long *, s32, unsigned long);
extern s32 func_L39_004FBDA0(BN_0050A8D8 *, BN_0050A8D8 *, BN_0050A8D8 *);
extern s32 func_L39_004FB9A0(BN_0050A8D8 *, BN_0050A8D8 *, BN_0050A8D8 *);
extern void func_L39_004FC318(BN_0050A8D8 *);
extern s32 func_L39_0050B748(BN_0050A8D8 *, BN_0050A8D8 *, s32);

/* OpenSSL BN_div (0.9.x, 64-bit BN_ULONG without BN_LLONG) */
s32 func_L39_0050A8D8(BN_0050A8D8 *dv, BN_0050A8D8 *rm, BN_0050A8D8 *num, BN_0050A8D8 *divisor,
                      CTX_0050A8D8 *ctx) {
    s32 norm_shift = 0, i = 0, j = 0, loop = 0;
    BN_0050A8D8 *tmp, wnum, *snum, *sdiv, *res;
    unsigned long *resp, *wnump;
    unsigned long d0 = 0, d1 = 0;
    s32 num_n = 0, div_n = 0;

    if (divisor->top == 0 || (divisor->top == 1 && divisor->d[0] == 0)) {
        return 0;
    }

    if (func_L39_004FC960(num, divisor) < 0) {
        if (rm != 0) {
            if (func_L39_004FC5C0(rm, num) == 0) return 0;
        }
        if (dv != 0) func_L39_004FC6F8(dv, 0);
        return 1;
    }

    tmp = &ctx->bn[ctx->tos];
    tmp->neg = 0;
    snum = &ctx->bn[ctx->tos + 1];
    sdiv = &ctx->bn[ctx->tos + 2];
    if (dv == 0)
        res = &ctx->bn[ctx->tos + 3];
    else
        res = dv;

    norm_shift = 64 - (func_L39_004FC158(divisor) % 64);
    func_L39_004FCB28(sdiv, divisor, norm_shift);
    sdiv->neg = 0;
    norm_shift += 64;
    func_L39_004FCB28(snum, num, norm_shift);
    snum->neg = 0;
    div_n = sdiv->top;
    num_n = snum->top;
    loop = num_n - div_n;

    func_L39_004FC370(&wnum);
    wnum.d = &snum->d[loop];
    wnum.top = div_n;
    wnum.dmax = snum->dmax + 1;

    d0 = sdiv->d[div_n - 1];
    d1 = (div_n == 1) ? 0 : sdiv->d[div_n - 2];

    wnump = &snum->d[num_n - 1];

    if (!(((loop + 1) <= res->dmax) ? res : func_L39_004FC4B8(res, loop + 1))) goto err;
    res->neg = num->neg ^ divisor->neg;
    res->top = loop;
    resp = &res->d[loop - 1];

    if (!(((div_n + 1) <= tmp->dmax) ? tmp : func_L39_004FC4B8(tmp, div_n + 1))) goto err;

    if (func_L39_004FC960(&wnum, sdiv) >= 0) {
        if (!func_L39_004FBBE8(&wnum, &wnum, sdiv)) goto err;
        *resp = 1;
        res->d[res->top - 1] = 1;
    } else
        res->top--;
    resp--;

    for (i = 0; i < loop - 1; i++) {
        unsigned long q = 0, n0 = 0, n1 = 0;
        unsigned long l0 = 0;

        wnum.d--;
        wnum.top++;
        n0 = wnump[0];
        n1 = wnump[-1];
        if (n0 == d0)
            q = 0xFFFFFFFFFFFFFFFFUL;
        else
            q = func_L39_004FFEE0(n0, n1, d0);
        {
            unsigned long t1l = 0, t1h = 0, t2l = 0, t2h = 0, t3l = 0, t3h = 0, t3t = 0, ql = 0, qh = 0;

            t1h = n0;
            t1l = n1;
            for (;;) {
                t2l = d1 & 0xffffffffUL;
                t2h = (d1 >> 32) & 0xffffffffUL;
                ql = q & 0xffffffffUL;
                qh = (q >> 32) & 0xffffffffUL;
                {
                    unsigned long m, m1, lt, ht;
                    lt = t2l;
                    ht = t2h;
                    m = qh * lt;
                    lt = ql * lt;
                    m1 = ql * ht;
                    ht = qh * ht;
                    m = m + m1;
                    if (m < m1) ht += (unsigned long)1 << 32;
                    ht += (m >> 32) & 0xffffffffUL;
                    m1 = (m & 0xffffffffUL) << 32;
                    lt = lt + m1;
                    if (lt < m1) ht++;
                    t2l = lt;
                    t2h = ht;
                }

                t3t = d0 & 0xffffffffUL;
                t3h = (d0 >> 32) & 0xffffffffUL;
                {
                    unsigned long m, m1, lt, ht;
                    lt = t3t;
                    ht = t3h;
                    m = qh * lt;
                    lt = ql * lt;
                    m1 = ql * ht;
                    ht = qh * ht;
                    m = m + m1;
                    if (m < m1) ht += (unsigned long)1 << 32;
                    ht += (m >> 32) & 0xffffffffUL;
                    m1 = (m & 0xffffffffUL) << 32;
                    lt = lt + m1;
                    if (lt < m1) ht++;
                    t3t = lt;
                    t3h = ht;
                }
                t3l = t1l - t3t;
                if (t3l > t1l) t3h++;
                t3h = t1h - t3h;

                if (t3h) break;
                if (t2h < t3l) break;
                if ((t2h == t3l) && (t2l <= wnump[-2])) break;

                q--;
            }
        }
        l0 = func_L39_004FDA88(tmp->d, sdiv->d, div_n, q);
        tmp->d[div_n] = l0;
        for (j = div_n + 1; j > 0; j--)
            if (tmp->d[j - 1]) break;
        tmp->top = j;

        j = wnum.top;
        func_L39_004FBDA0(&wnum, &wnum, tmp);

        snum->top = snum->top + wnum.top - j;

        if (wnum.neg) {
            q--;
            j = wnum.top;
            func_L39_004FB9A0(&wnum, &wnum, sdiv);
            snum->top += wnum.top - j;
        }
        *(resp--) = q;
        wnump--;
    }
    func_L39_004FC318(snum);
    if (rm != 0) {
        s32 neg = num->neg;
        func_L39_0050B748(rm, snum, norm_shift);
        rm->neg = neg;
    }
    return 1;
err:
    return 0;
}
/* localdecomp:end func_L39_0050A8D8 */

/* localdecomp:start func_L39_0050AF60 */
u64 func_L39_0050AF60(u64 n) {
    u64 A, B, X, Y, D, M, T;
    s32 sign;

    Y = 0;
    A = n;
    X = 1;
    B = (0 - n) % n;
    sign = -1;
    while (B != 0) {
        sign = -sign;
        D = A / B;
        M = A % B;
        A = B;
        T = D * X + Y;
        B = M;
        Y = X;
        X = T;
    }
    if (sign < 0) {
        Y = n - Y;
    }
    if (A == 1) {
        return Y % n;
    }
    return 0;
}
/* localdecomp:end func_L39_0050AF60 */
