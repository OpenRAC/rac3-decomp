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

INCLUDE_ASM("asm/levels", func_L39_0050A8D8);

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
