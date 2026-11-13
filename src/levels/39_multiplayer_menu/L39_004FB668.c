#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FB668 */
typedef struct {
    s32 f0;
    void *f4;
} S_004FB668;

extern void func_L39_004F9A88(void *);
extern void func_L39_004FA4E8(void *);

void func_L39_004FB668(S_004FB668 *p) {
    void *h;
    if (p != 0) {
        h = p->f4;
        if (h != 0) {
            switch (p->f0) {
            case 6:
                func_L39_004F9A88(h);
                break;
            case 2: case 3: case 4:
            case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
            case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C:
            case 0x1E:
            case 0x102:
                func_L39_004FA4E8(p->f4);
                break;
            }
            p->f0 = 0;
            p->f4 = 0;
        }
    }
}
/* localdecomp:end func_L39_004FB668 */

/* localdecomp:start func_L39_004FB710 */
typedef struct {
    s32 length;
    s32 type;
    unsigned char *data;
} AStr_004FB710;

typedef struct {
    void *algorithm;
} Alg_004FB710;

extern void *func_L01_0047F3B0(void *obj);
extern void *func_L39_004DE940(void);
extern void *func_L39_004BEED8(s32 n);
extern void func_L39_004BC6C8(s32 lib, s32 func, s32 reason, char *file, s32 line);
extern s32 func_L39_004DD690(void *ctx, void *type);
extern void func_L39_004DD778(void *ctx, void *buf, s32 n);
extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004E1478(void *ctx, unsigned char *sig, s32 siglen, void *pkey);
extern void func_L39_004BEF28(void *p);
extern void func_L39_004DE9B8(void *ctx);

/* ASN1_verify */
s32 func_L39_004FB710(s32 (*i2d)(void *, unsigned char **), Alg_004FB710 *a, AStr_004FB710 *signature,
                      void *data, void *pkey) {
    void *ctx = 0;
    void *type;
    unsigned char *p, *buf_in = 0;
    s32 ret = -1, inl;

    type = func_L01_0047F3B0(a->algorithm);
    if (type == 0) {
        func_L39_004BC6C8(13, 121, 141, 0, 0);
        goto err;
    }
    ctx = func_L39_004DE940();
    if (ctx == 0) {
        goto err;
    }
    inl = i2d(data, 0);
    buf_in = func_L39_004BEED8(inl);
    if (buf_in == 0) {
        func_L39_004BC6C8(13, 121, 33, 0, 0);
        goto err;
    }
    p = buf_in;
    i2d(data, &p);
    if (!func_L39_004DD690(ctx, type)) {
        goto err;
    }
    func_L39_004DD778(ctx, buf_in, inl);
    func_0011D534(buf_in, 0, inl);
    if (func_L39_004E1478(ctx, signature->data, signature->length, pkey) <= 0) {
        func_L39_004BC6C8(13, 121, 0x806, 0, 0);
        ret = 0;
        goto err;
    }
    ret = 1;
err:
    if (buf_in != 0) {
        func_L39_004BEF28(buf_in);
    }
    if (ctx != 0) {
        func_L39_004DE9B8(ctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004FB710 */

/* localdecomp:start func_L39_004FB898 */
typedef struct BIO_004FB898 BIO_004FB898;
typedef struct {
    char _p0[0x14];
    s32 (*bgets)(BIO_004FB898 *, char *, s32);
} BIOMethod_004FB898;
struct BIO_004FB898 {
    BIOMethod_004FB898 *method;
    long (*callback)(BIO_004FB898 *, s32, const char *, s32, long, long);
    s32 f8;
    s32 init;
};


/* OpenSSL BIO_gets */
s32 func_L39_004FB898(BIO_004FB898 *b, char *buf, s32 size) {
    long (*cb)(BIO_004FB898 *, s32, const char *, s32, long, long);
    s32 i;

    if (b == 0 || b->method == 0 || b->method->bgets == 0) {
        func_L39_004BC6C8(32, 0x66, 0x6F, 0, 0);
        return -2;
    }
    cb = b->callback;
    if (cb != 0 && (i = (s32)cb(b, 5, buf, size, 0, 1)) <= 0) {
        return i;
    }
    if (!b->init) {
        func_L39_004BC6C8(32, 0x66, 0x6E, 0, 0);
        return -2;
    }
    i = b->method->bgets(b, buf, size);
    if (cb != 0) {
        i = (s32)cb(b, 0x85, buf, size, 0, (long)i);
    }
    return i;
}
/* localdecomp:end func_L39_004FB898 */

/* localdecomp:start func_L39_004FB9A0 */
typedef struct { u8 pad0[0xC]; s32 fC; } S_004FB9A0;
extern s32 func_L39_004FC960(S_004FB9A0 *, S_004FB9A0 *);
extern s32 func_L39_004FBBE8(S_004FB9A0 *, S_004FB9A0 *, S_004FB9A0 *);
extern s32 func_L39_004FBA78(S_004FB9A0 *, S_004FB9A0 *, S_004FB9A0 *);

s32 func_L39_004FB9A0(S_004FB9A0 *arg0, S_004FB9A0 *a, S_004FB9A0 *b) {
    S_004FB9A0 *t;

    if (a->fC != b->fC) {
        if (a->fC != 0) {
            t = a;
            a = b;
            b = t;
        }
        if (func_L39_004FC960(a, b) < 0) {
            if (!func_L39_004FBBE8(arg0, b, a)) {
                return 0;
            }
            arg0->fC = 1;
        } else {
            if (!func_L39_004FBBE8(arg0, a, b)) {
                return 0;
            }
            arg0->fC = 0;
        }
        return 1;
    }
    if (a->fC != 0) {
        arg0->fC = 1;
    } else {
        arg0->fC = 0;
    }
    return func_L39_004FBA78(arg0, a, b) != 0;
}
/* localdecomp:end func_L39_004FB9A0 */

/* localdecomp:start func_L39_004FBA78 */
typedef struct 
{
  unsigned long *d;
  s32 top;
  s32 dmax;
  s32 neg;
} BN_004FBA78;
extern BN_004FBA78 *func_L39_004FC4B8_004FBA78(BN_004FBA78 *a, s32 words);
extern unsigned long func_L39_004FE020(unsigned long *rp, unsigned long *ap, unsigned long *bp, s32 n);
s32 func_L39_004FBA78(S_004FB9A0 *r_, S_004FB9A0 *a_, S_004FB9A0 *b_)
{
  BN_004FBA78 *r = (BN_004FBA78 *) r_;
  BN_004FBA78 *a = (BN_004FBA78 *) a_;
  BN_004FBA78 *b = (BN_004FBA78 *) b_;
  s32 i;
  s32 max;
  s32 min;
  unsigned long *ap;
  unsigned long *bp;
  unsigned long *rp;
  unsigned long carry;
  unsigned long t1;
  BN_004FBA78 *tmp;
  max = a->top;
  min = b->top;
  if (max < min)
  {
    tmp = a;
    a = b;
    b = tmp;
    max = a->top;
    min = b->top;
  }
  if ((((max + 1) <= r->dmax) ? (r) : (func_L39_004FC4B8_004FBA78(r, max + 1))) == 0)
  {
    return 0;
  }
  tmp = b;
  r->top = max;
  ap = a->d;
  bp = tmp->d;
  rp = r->d;
  carry = 0;
  carry = func_L39_004FE020(rp, ap, bp, min);
  rp += min;
  ap += min;
  bp += min;
  i = min;
  if (carry)
  {
    while (i < max)
    {
      i++;
      t1 = *(ap++);
      if ((*(rp++) = t1 + 1) >= t1)
      {
        carry = 0;
        break;
      }
    }

    if ((i >= max) && carry)
    {
      *(rp++) = 1;
      r->top++;
    }
  }
  if (rp != ap)
  {
    for (; i < max; i++)
    {
      *(rp++) = *(ap++);
    }

  }
  return 1;
}
/* localdecomp:end func_L39_004FBA78 */

/* localdecomp:start func_L39_004FBBE8 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
} BN_004FBBE8;
extern BN_004FBBE8 *func_L39_004FC4B8(BN_004FBBE8 *, s32);
extern void func_L39_004FC318(BN_004FBBE8 *);

/* OpenSSL BN_usub */
s32 func_L39_004FBBE8(S_004FB9A0 *r_, S_004FB9A0 *a_, S_004FB9A0 *b_) {
    BN_004FBBE8 *r = (BN_004FBBE8 *)r_;
    BN_004FBBE8 *a = (BN_004FBBE8 *)a_;
    BN_004FBBE8 *b = (BN_004FBBE8 *)b_;
    s32 max, min;
    register unsigned long t1, t2, *ap, *bp, *rp;
    s32 i, carry;

    max = a->top;
    min = b->top;
    if (max < min) {
        return 0;
    }
    if (((max <= r->dmax) ? r : func_L39_004FC4B8(r, max)) == 0) {
        return 0;
    }
    ap = a->d;
    bp = b->d;
    rp = r->d;
    carry = 0;
    for (i = 0; i < min; i++) {
        t1 = *(ap++);
        t2 = *(bp++);
        if (carry) {
            carry = (t1 <= t2);
            t1 = t1 - t2 - 1;
        } else {
            carry = (t1 < t2);
            t1 = t1 - t2;
        }
        *(rp++) = t1;
    }
    if (carry) {
        while (i < max) {
            i++;
            t1 = *(ap++);
            t2 = t1 - 1;
            *(rp++) = t2;
            if (t1 > t2) break;
        }
    }
    if (rp != ap) {
        for (;;) {
            if (i++ >= max) break;
            rp[0] = ap[0];
            if (i++ >= max) break;
            rp[1] = ap[1];
            if (i++ >= max) break;
            rp[2] = ap[2];
            if (i++ >= max) break;
            rp[3] = ap[3];
            rp += 4;
            ap += 4;
        }
    }
    r->top = max;
    func_L39_004FC318(r);
    return 1;
}
/* localdecomp:end func_L39_004FBBE8 */

/* localdecomp:start func_L39_004FBDA0 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004FBDA0;

/* OpenSSL BN_sub */
s32 func_L39_004FBDA0(BN_004FBDA0 *r, BN_004FBDA0 *a, BN_004FBDA0 *b) {
    s32 max;
    s32 add = 0, neg = 0;
    BN_004FBDA0 *tmp;

    if (a->neg) {
        if (b->neg) {
            tmp = a;
            a = b;
            b = tmp;
        } else {
            add = 1;
            neg = 1;
        }
    } else {
        if (b->neg) {
            add = 1;
            neg = 0;
        }
    }
    if (add) {
        if (!func_L39_004FBA78((S_004FB9A0 *)r, (S_004FB9A0 *)a, (S_004FB9A0 *)b)) return 0;
        r->neg = neg;
        return 1;
    }
    max = (a->top > b->top) ? a->top : b->top;
    if (((max <= r->dmax) ? r : (BN_004FBDA0 *)func_L39_004FC4B8((BN_004FBBE8 *)r, max)) == 0) return 0;
    if (func_L39_004FC960((S_004FB9A0 *)a, (S_004FB9A0 *)b) < 0) {
        if (!func_L39_004FBBE8((S_004FB9A0 *)r, (S_004FB9A0 *)b, (S_004FB9A0 *)a)) return 0;
        r->neg = 1;
    } else {
        if (!func_L39_004FBBE8((S_004FB9A0 *)r, (S_004FB9A0 *)a, (S_004FB9A0 *)b)) return 0;
        r->neg = 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004FBDA0 */

/* localdecomp:start func_L39_004FBED8 */
typedef struct BN_004FBED8 BN_004FBED8;
extern s32 func_L39_0050A8D8(BN_004FBED8 *, BN_004FBED8 *, const BN_004FBED8 *, const BN_004FBED8 *, void *);

s32 func_L39_004FBED8(BN_004FBED8 *rem, const BN_004FBED8 *m, const BN_004FBED8 *d, void *ctx) {
    return func_L39_0050A8D8(0, rem, m, d, ctx);
}
/* localdecomp:end func_L39_004FBED8 */

/* localdecomp:start func_L39_004FBF10 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004FBF10;

typedef struct {
    s32 tos;
    BN_004FBF10 bn[16];
} BN_CTX_004FBF10;

extern BN_004FBF10 *func_L39_004FC380(void);
extern s32 func_L39_004FC6F8(BN_004FBF10 *, s32);
extern s32 func_L39_004FC5C0(BN_004FBF10 *, BN_004FBF10 *);
extern s32 func_L39_004FCFD0(BN_004FBF10 *, BN_004FBF10 *, BN_004FBF10 *, BN_CTX_004FBF10 *);
extern void func_L39_004FC228(void *);

/* OpenSSL BN_mod_inverse (0.9.5 style, BN_CTX with an inline bn[] array) */
BN_004FBF10 *func_L39_004FBF10(BN_004FBF10 *in, BN_004FBF10 *a, BN_004FBF10 *n, BN_CTX_004FBF10 *ctx) {
    BN_004FBF10 *A, *B, *X, *Y, *M, *D, *R = 0;
    BN_004FBF10 *T, *ret = 0;
    s32 sign;

    A = &ctx->bn[ctx->tos];
    B = &ctx->bn[ctx->tos + 1];
    X = &ctx->bn[ctx->tos + 2];
    D = &ctx->bn[ctx->tos + 3];
    M = &ctx->bn[ctx->tos + 4];
    Y = &ctx->bn[ctx->tos + 5];
    ctx->tos += 6;
    if (in == 0) {
        R = func_L39_004FC380();
    } else {
        R = in;
    }
    if (R == 0) goto err;

    func_L39_004FC6F8(X, 0);
    func_L39_004FC6F8(Y, 1);
    if (func_L39_004FC5C0(A, a) == 0) goto err;
    if (func_L39_004FC5C0(B, n) == 0) goto err;
    sign = 1;

    while (!(B->top == 0 || (B->top == 1 && B->d[0] == 0))) {
        if (!func_L39_0050A8D8((void *)D, (void *)M, (void *)A, (void *)B, ctx)) goto err;
        T = A;
        A = B;
        B = M;
        if (!func_L39_004FCFD0(T, D, X, ctx)) goto err;
        if (!func_L39_004FB9A0((void *)T, (void *)T, (void *)Y)) goto err;
        M = Y;
        Y = X;
        X = T;
        sign = -sign;
    }
    if (sign < 0) {
        if (!func_L39_004FBDA0((void *)Y, (void *)n, (void *)Y)) goto err;
    }
    if (A->top == 1 && A->d[0] == 1) {
        ret = func_L39_004FBED8((void *)R, (void *)Y, (void *)n, ctx) ? R : 0;
    }
err:
    if (ret == 0 && in == 0) func_L39_004FC228(R);
    ctx->tos -= 6;
    return ret;
}
/* localdecomp:end func_L39_004FBF10 */

/* localdecomp:start func_L39_004FC158 */
extern s32 func_L39_0050B060(unsigned long);

s32 func_L39_004FC158(BitSet_004FCA98 *a0) {
    s32 n = a0->f4;
    s32 r = 0;
    if (n != 0) {
        s32 off = (n - 1) << 6;
        r = off + func_L39_0050B060(a0->f0[n - 1]);
    }
    return r;
}
/* localdecomp:end func_L39_004FC158 */

/* localdecomp:start func_L39_004FC1A0 */
typedef struct {
    void *buf;
    int pad4;
    int count;
    int padC;
    unsigned int flags;
} S_004FC1A0;
extern void func_0011D534(void *, int, int);
extern void func_L39_004BEF28(void *);

void func_L39_004FC1A0(S_004FC1A0 *p)
{
    unsigned int own;
    if (p == 0)
        return;
    if (p->buf != 0) {
        func_0011D534(p->buf, 0, p->count << 3);
        if (!(p->flags & 2))
            func_L39_004BEF28(p->buf);
    }
    own = p->flags & 1;
    func_0011D534(p, 0, 0x14);
    if (own)
        func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004FC1A0 */

/* localdecomp:start func_L39_004FC228 */
extern void func_L39_004BEF28(void *p);

typedef struct S_004FC228 {
    void *f0;
    char _p4[0xC];
    s32 f10;
} S_004FC228;

void func_L39_004FC228(void *arg0) {
    S_004FC228 *s = (S_004FC228 *)arg0;

    if (s == 0) {
        return;
    }
    if (s->f0 != 0 && !(s->f10 & 2)) {
        func_L39_004BEF28(s->f0);
    }
    s->f10 |= 0x8000;
    if (s->f10 & 1) {
        func_L39_004BEF28(s);
    }
}
/* localdecomp:end func_L39_004FC228 */

/* localdecomp:start func_L39_004FC288 */
void func_L39_004FC288(BN_004FBBE8 *a, s32 n) {
    s32 i;
    if (a->top < n) {
        if (a->dmax < n) {
            func_L39_004FC4B8(a, n);
        }
        for (i = a->top; i < n; i++) {
            a->d[i] = 0;
        }
    }
}
/* localdecomp:end func_L39_004FC288 */
