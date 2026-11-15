#include "common.h"

/* localdecomp:start func_L39_004E3060 */
extern void func_L39_004FC228(void *);
extern void func_L39_004FCD30(void *);
extern void func_L39_004BEF28(void *);

typedef struct E_004E3060 {
    char a[0x14];
} E_004E3060;

typedef struct S_004E3060 {
    char _p0[0x4];
    char f4[0x14];
    char f18[0x14];
    char f2C[0x14];
    s32 f40;
    E_004E3060 *f44;
    char _p48[0x8];
    void **f50;
    void *f54;
} S_004E3060;

typedef struct O_004E3060 {
    char _p0[0x8];
    S_004E3060 *f8;
} O_004E3060;

s32 func_L39_004E3060(O_004E3060 *arg0) {
    S_004E3060 *p = arg0->f8;
    s32 n;
    s32 i;

    if (p == 0) {
        return 0;
    }
    n = p->f40;
    func_L39_004FC228(p->f4);
    func_L39_004FC228(p->f18);
    func_L39_004FC228(p->f2C);
    for (i = 0; i < n; i++) {
        func_L39_004FC228(&p->f44[i * 3]);
        func_L39_004FC228(&p->f44[i * 3 + 1]);
        func_L39_004FC228(&p->f44[i * 3 + 2]);
        if (p->f50[i] != 0) {
            func_L39_004FCD30(p->f50[i]);
        }
    }
    if (p->f44 != 0) {
        func_L39_004BEF28(p->f44);
    }
    if (p->f50 != 0) {
        func_L39_004BEF28(p->f50);
    }
    if (p->f54 != 0) {
        func_L39_004FCD30(p->f54);
    }
    func_L39_004BEF28(p);
    return 0;
}
/* localdecomp:end func_L39_004E3060 */

/* localdecomp:start func_L39_004E3178 */
typedef struct BN_004E3178 {
    s32 f[5];
} BN_004E3178;

typedef struct K_004E3178 {
    s32 f0;
    BN_004E3178 n;
    BN_004E3178 e;
    BN_004E3178 d;
    s32 count;
    BN_004E3178 *primes;
    s32 f48;
    s32 f4C;
    void **monts;
    void *mont;
    s32 f58;
} K_004E3178;

typedef struct V_004E3178 {
    s32 _p0[7];
    s32 f1C;
} V_004E3178;

typedef struct S_004E3178 {
    V_004E3178 *f0;
    s32 f4;
    K_004E3178 *key;
    s32 flags;
} S_004E3178;

typedef struct A_004E3178 {
    s32 _p0[3];
    s32 data;
    s32 len;
} A_004E3178;

extern void *func_L39_004BEED8(s32);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004E4BE0(void *, s32, void *);
extern s32 func_L39_004E4AE8(void *, s32, s32, s32 *, A_004E3178 **, s32);
extern void *func_L39_004FC3C8(void);
extern void func_L39_004FC448(void *);
extern void func_L39_004FC370(BN_004E3178 *);
extern s32 func_L39_004FCCC8(s32, void **);
extern void *func_L39_004FC780(s32, s32, BN_004E3178 *);
extern s32 func_L39_004FCD58(void *, BN_004E3178 *, s32, s32, void *);
extern u8 D_L39_0046D300[];
extern u8 D_L39_0046D320[];

s32 func_L39_004E3178(S_004E3178 *ctx, void *attrs) {
    s32 i;
    A_004E3178 *attr;
    s32 j;
    s32 ret;
    K_004E3178 *key;
    void *bnctx;
    s32 n;
    BN_004E3178 *primes;
    void **monts;

    ret = 1;
    j = 0;
    key = ctx->key;
    if (key != 0) {
        func_L39_004E3060((O_004E3060 *)ctx);
    }
    key = func_L39_004BEED8(0x5C);
    if (key == 0) {
        return 1;
    }
    func_0011D534(key, 0, 0x5C);
    ctx->key = key;
    ctx->flags &= ~5;
    i = 0;
    if (func_L39_004E4BE0(attrs, 0x10, D_L39_0046D300) == 0) {
        ctx->flags |= 4;
        i = 1;
    }
    if (func_L39_004E4BE0(attrs, 0x10, D_L39_0046D320) == 0) {
        ctx->flags |= 1;
        i = 1;
    }
    if (i == 0) {
        return 4;
    }
    key->f58 = ctx->f0->f1C;
    i = 0;
    func_L39_004E4AE8(attrs, 1, 2, &i, &attr, 4);
    key->f48 = attr != 0 ? attr->data : 0;
    func_L39_004E4AE8(attrs, 1, 3, &i, &attr, 4);
    key->f4C = attr != 0 ? attr->data : 0;
    bnctx = func_L39_004FC3C8();
    if (bnctx == 0) {
        goto out;
    }
    *(s32 *)((u8 *)bnctx + 0x10C) = key->f4C;
    if (ctx->flags & 4) {
        i = 0;
        func_L39_004E4AE8(attrs, 0x10, 1, &i, &attr, 4);
        if (attr == 0) {
            ret = 2;
            goto out;
        }
        n = attr->len;
        key->count = n;
        primes = func_L39_004BEED8(n * 0x3C);
        if (primes == 0) {
            goto out;
        }
        for (i = 0; i < n * 3; i++) {
            func_L39_004FC370(&primes[i]);
        }
        monts = func_L39_004BEED8(n * 4);
        if (monts == 0) {
            goto out;
        }
        key->monts = monts;
        for (i = 0; i < n; i++) {
            func_L39_004FCCC8(0, &monts[i]);
        }
        key->primes = primes;
        func_L39_004E4AE8(attrs, 0x10, 0x12, &i, &attr, 4);
        func_L39_004FC780(attr->data, attr->len, &key->d);
        for (i = 0; i < n; i++) {
            func_L39_004E4AE8(attrs, 0x10, i * 3 + 0x13, &j, &attr, 4);
            func_L39_004FC780(attr->data, attr->len, &primes[i * 3]);
            func_L39_004E4AE8(attrs, 0x10, i * 3 + 0x14, &j, &attr, 4);
            if (attr == 0) {
                goto out;
            }
            func_L39_004FC780(attr->data, attr->len, &primes[i * 3 + 1]);
            if (i != 0) {
                func_L39_004E4AE8(attrs, 0x10, i * 3 + 0x15, &j, &attr, 4);
                if (attr == 0) {
                    goto out;
                }
                func_L39_004FC780(attr->data, attr->len, &primes[i * 3 + 2]);
            }
            if (func_L39_004FCD58(monts[i], &primes[i * 3], 1, 0, bnctx) != 0) {
                goto out;
            }
            if (func_L39_004FCD58(monts[i], &primes[i * 3 + 1], 3, 0, bnctx) != 0) {
                goto out;
            }
        }
    }
    i = 0;
    func_L39_004E4AE8(attrs, 0x10, 0x10, &i, &attr, 4);
    func_L39_004FC780(attr->data, attr->len, &key->n);
    if (ctx->flags & 1) {
        func_L39_004E4AE8(attrs, 0x10, 0x11, &i, &attr, 4);
        if (attr == 0) {
            goto out;
        }
        func_L39_004FC780(attr->data, attr->len, &key->e);
        func_L39_004FCCC8(0, &key->mont);
        if (func_L39_004FCD58(key->mont, &key->n, 1, 0, bnctx) != 0) {
            goto out;
        }
        if (func_L39_004FCD58(key->mont, &key->e, 3, 0, bnctx) != 0) {
            goto out;
        }
    }
    ret = 0;
out:
    if (bnctx != 0) {
        func_L39_004FC448(bnctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004E3178 */
