#include "common.h"

/* localdecomp:start func_L39_004ECE38 */
extern void *func_L39_004DBA08(void);
extern s32 func_L39_004ECD80(u8 *);
extern s32 func_L39_004ECDC8(void *);
extern const s32 D_L39_0046D4B0[16];
extern const unsigned long D_L39_004778B0[8][64];

/* from OpenSSL's set_key.c des_set_key */
s32 func_L39_004ECE38(u8 *key, unsigned long *schedule) {
    unsigned long c, d, t, s, t2;
    u8 *in;
    unsigned long *k;
    s32 i;

    if (*(s32 *)((u8 *)func_L39_004DBA08() + 0x1C)) {
        if (!func_L39_004ECD80(key))
            return -1;
        if (func_L39_004ECDC8(key))
            return -2;
    }

    k = schedule;
    in = key;

    c = (unsigned long)(*(in++));
    c |= ((unsigned long)(*(in++))) << 8;
    c |= ((unsigned long)(*(in++))) << 16;
    c |= ((unsigned long)(*(in++))) << 24;
    d = (unsigned long)(*(in++));
    d |= ((unsigned long)(*(in++))) << 8;
    d |= ((unsigned long)(*(in++))) << 16;
    d |= ((unsigned long)(*(in++))) << 24;

    t = ((d >> 4) ^ c) & 0x0f0f0f0fL; c ^= t; d ^= (t << 4);
    t = ((c << 18) ^ c) & 0xcccc0000L; c = c ^ t ^ (t >> 18);
    t = ((d << 18) ^ d) & 0xcccc0000L; d = d ^ t ^ (t >> 18);
    t = ((d >> 1) ^ c) & 0x55555555L; c ^= t; d ^= (t << 1);
    t = ((c >> 8) ^ d) & 0x00ff00ffL; d ^= t; c ^= (t << 8);
    t = ((d >> 1) ^ c) & 0x55555555L; c ^= t; d ^= (t << 1);
    d = (((d & 0x000000ffL) << 16) | (d & 0x0000ff00L) |
         ((d & 0x00ff0000L) >> 16) | ((c & 0xf0000000L) >> 4));
    c &= 0x0fffffffL;

    for (i = 0; i < 16; i++) {
        if (D_L39_0046D4B0[i]) {
            c = ((c >> 2) | (c << 26)); d = ((d >> 2) | (d << 26));
        } else {
            c = ((c >> 1) | (c << 27)); d = ((d >> 1) | (d << 27));
        }
        c &= 0x0fffffffL;
        d &= 0x0fffffffL;
        s = D_L39_004778B0[0][(c) & 0x3f] |
            D_L39_004778B0[1][((c >> 6) & 0x03) | ((c >> 7) & 0x3c)] |
            D_L39_004778B0[2][((c >> 13) & 0x0f) | ((c >> 14) & 0x30)] |
            D_L39_004778B0[3][((c >> 20) & 0x01) | ((c >> 21) & 0x06) | ((c >> 22) & 0x38)];
        t = D_L39_004778B0[4][(d) & 0x3f] |
            D_L39_004778B0[5][((d >> 7) & 0x03) | ((d >> 8) & 0x3c)] |
            D_L39_004778B0[6][(d >> 15) & 0x3f] |
            D_L39_004778B0[7][((d >> 21) & 0x0f) | ((d >> 22) & 0x30)];

        t2 = ((t << 16) | (s & 0x0000ffffL)) & 0xffffffffL;
        *(k++) = (((t2) >> (30)) + ((t2) << (32 - (30)))) & 0xffffffffL;

        t2 = ((s >> 16) | (t & 0xffff0000L));
        *(k++) = (((t2) >> (26)) + ((t2) << (32 - (26)))) & 0xffffffffL;
    }
    return 0;
}
/* localdecomp:end func_L39_004ECE38 */

LINKER_REMNANT("asm/levels", func_L39_004ED220);

/* localdecomp:start func_L39_004ED228 */
/* OpenSSL 0.9.4's DSA_verify (dsa_vrf.c, public source) */
typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004ED228;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} AS_004ED228;

typedef struct {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    long slen;
    u8 *max;
    u8 *q;
    u8 **pp;
    s32 line;
} AC_004ED228;

typedef struct {
    s32 pad;
    s32 version;
    s32 write_params;
    BN_004ED228 *p;
    BN_004ED228 *q;
    BN_004ED228 *g;
    BN_004ED228 *pub_key;
    BN_004ED228 *priv_key;
    BN_004ED228 *kinv;
    BN_004ED228 *r;
    s32 flags;
    void *method_mont_p;
} DSA_004ED228;

extern void *func_L39_004FC3C8(void);
extern void func_L39_004FC370_004ED228(BN_004ED228 *);
extern s32 func_L39_004FA2A8_004ED228(AC_004ED228 *, long *);
extern void *func_L39_004F94F0_004ED228(AS_004ED228 **, u8 **, long);
extern BN_004ED228 *func_L39_004FC780_004ED228(u8 *, s32, BN_004ED228 *);
extern s32 func_L39_004FA228_004ED228(AC_004ED228 *);
extern void *func_L39_004FCF40(void);
extern s32 func_L39_004FFBB0_004ED228(void *, BN_004ED228 *, void *);
extern BN_004ED228 *func_L39_004FBF10_004ED228(BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, void *);
extern s32 func_L39_004FFAF0_004ED228(BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, void *);
extern s32 func_L39_004FE728_004ED228(BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, void *, void *);
extern s32 func_L39_004FBED8_004ED228(BN_004ED228 *, BN_004ED228 *, BN_004ED228 *, void *);
extern s32 func_L39_004FC960_004ED228(BN_004ED228 *, BN_004ED228 *);
extern void func_L39_004FA4E8(void *);
extern void func_L39_004FC228_004ED228(BN_004ED228 *);
extern void func_L39_004FC448(void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004ED228(s32 type, u8 *dgst, s32 dgst_len, u8 *sigbuf, s32 siglen, DSA_004ED228 *dsa) {
    long length = siglen;
    AC_004ED228 c;
    void *ctx;
    BN_004ED228 u1, u2, r, t1;
    AS_004ED228 *bs = 0;
    void *mont;
    s32 ret = 0;

    ctx = func_L39_004FC3C8();
    if (ctx == 0) goto err;

    func_L39_004FC370_004ED228(&u1);
    func_L39_004FC370_004ED228(&u2);
    func_L39_004FC370_004ED228(&r);
    func_L39_004FC370_004ED228(&t1);

    c.p = sigbuf;
    c.max = (length == 0) ? 0 : (c.p + length);
    if (!func_L39_004FA2A8_004ED228(&c, &length)) { c.line = 57; goto err; }
    c.q = c.p;
    if (func_L39_004F94F0_004ED228(&bs, &c.p, c.slen) == 0) { c.line = 58; goto err; }
    c.slen -= (c.p - c.q);
    if (func_L39_004FC780_004ED228(bs->data, bs->length, &r) == 0) goto err_bn;
    c.q = c.p;
    if (func_L39_004F94F0_004ED228(&bs, &c.p, c.slen) == 0) { c.line = 61; goto err; }
    c.slen -= (c.p - c.q);
    if (func_L39_004FC780_004ED228(bs->data, bs->length, &u1) == 0) goto err_bn;
    if (!func_L39_004FA228_004ED228(&c)) goto err;

    if (dsa->method_mont_p == 0 && (dsa->flags & 1)) {
        if ((dsa->method_mont_p = func_L39_004FCF40()) != 0)
            if (!func_L39_004FFBB0_004ED228(dsa->method_mont_p, dsa->p, ctx)) goto err;
    }
    mont = dsa->method_mont_p;

    if (func_L39_004FBF10_004ED228(&u2, &u1, dsa->q, ctx) == 0) goto err_bn;
    if (func_L39_004FC780_004ED228(dgst, dgst_len, &u1) == 0) goto err_bn;
    if (!func_L39_004FFAF0_004ED228(&u1, &u1, &u2, dsa->q, ctx)) goto err_bn;
    if (!func_L39_004FFAF0_004ED228(&u2, &r, &u2, dsa->q, ctx)) goto err_bn;
    if (!func_L39_004FE728_004ED228(&t1, dsa->g, &u1, dsa->pub_key, &u2, dsa->p, ctx, mont)) goto err_bn;
    if (!func_L39_004FBED8_004ED228(&u1, &t1, dsa->q, ctx)) goto err_bn;
    ret = func_L39_004FC960_004ED228(&u1, &r) == 0;
    if (0) {
err:
        func_L39_004BC6C8(10, 0x6C, c.error, 0, 0);
    }
    if (0) {
err_bn:
        func_L39_004BC6C8(10, 0x6C, 0x803, 0, 0);
    }
    if (bs != 0) func_L39_004FA4E8(bs);
    func_L39_004FC228_004ED228(&r);
    func_L39_004FC228_004ED228(&u1);
    func_L39_004FC228_004ED228(&u2);
    func_L39_004FC228_004ED228(&t1);
    if (ctx != 0) func_L39_004FC448(ctx);
    return ret;
}
/* localdecomp:end func_L39_004ED228 */

/* localdecomp:start func_L39_004ED578 */
/* OpenSSL's RSA_sign_ASN1_OCTET_STRING (rsa_saos.c, public source) */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} OS_004ED578;

extern s32 func_L39_004FAC48(OS_004ED578 *, u8 **);
extern s32 func_L39_004EA5A8(void *);
extern s32 func_L39_004EA938(s32, u8 *, u8 *, void *, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_004ED578(s32 type, u8 *m, u32 m_len, u8 *sigret, u32 *siglen, void *rsa) {
    OS_004ED578 sig;
    s32 i, j, ret = 0;
    u8 *p, *s;

    sig.type = 4;
    sig.length = m_len;
    sig.data = m;

    i = func_L39_004FAC48(&sig, 0);
    j = func_L39_004EA5A8(rsa);
    if ((i - 1) > j) {
        func_L39_004BC6C8(4, 0x80, 0x6F, 0, 0);
        return 0;
    }
    s = func_L39_004BEED8((u32)j + 1);
    if (s == 0) {
        func_L39_004BC6C8(4, 0x80, 0x21, 0, 0);
        return 0;
    }
    p = s;
    func_L39_004FAC48(&sig, &p);
    i = func_L39_004EA938(i, s, sigret, rsa, 1);
    if (i > 0) {
        *siglen = i;
        ret = 1;
    }
    func_0011D534(s, 0, (u32)j + 1);
    func_L39_004BEF28(s);
    return ret;
}
/* localdecomp:end func_L39_004ED578 */

/* localdecomp:start func_L39_004ED6A8 */
/* OpenSSL's RSA_verify_ASN1_OCTET_STRING */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} OS_004ED6A8;

extern s32 func_L39_004EA5A8(void *);
extern s32 func_L39_004EA9D0(s32, u8 *, u8 *, void *, s32);
extern void *func_L39_004FAC68(void *, u8 **, s32);
extern void func_L39_004FA4E8(void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_004ED6A8(s32 dtype, u8 *m, u32 m_len, u8 *sigbuf, u32 siglen, void *rsa) {
    s32 i;
    s32 ret = 0;
    u8 *p;
    u8 *s;
    OS_004ED6A8 *sig = 0;

    if (siglen != func_L39_004EA5A8(rsa)) {
        func_L39_004BC6C8(4, 0x81, 0x75, 0, 0);
        return 0;
    }

    s = func_L39_004BEED8(siglen);
    if (s == 0) {
        func_L39_004BC6C8(4, 0x81, 0x21, 0, 0);
        goto err;
    }
    i = func_L39_004EA9D0(siglen, sigbuf, s, rsa, 1);

    if (i <= 0) {
        goto err;
    }

    p = s;
    sig = func_L39_004FAC68(0, &p, i);
    if (sig == 0) {
        goto err;
    }

    if ((u32)sig->length != m_len || func_0011D2EC(m, sig->data, m_len) != 0) {
        func_L39_004BC6C8(4, 0x81, 0x67, 0, 0);
    } else {
        ret = 1;
    }
err:
    if (sig != 0) {
        func_L39_004FA4E8(sig);
    }
    func_0011D534(s, 0, siglen);
    func_L39_004BEF28(s);
    return ret;
}
/* localdecomp:end func_L39_004ED6A8 */

/* localdecomp:start func_L39_004ED810 */
s32 func_L39_004ED810(u8 *ctx, s32 v) {
    *(s32 *)(ctx + 0xBC) = v;
    return 0;
}
/* localdecomp:end func_L39_004ED810 */

/* localdecomp:start func_L39_004ED820 */
extern s32 func_L39_004EDE58();

typedef struct {
    u64 h[5];
    u64 n0;
    u64 n1;
    u8 pad[0xB8 - 0x38];
    s32 num;
    s32 (*block)();
} S_004ED820;

void func_L39_004ED820(S_004ED820 *c) {
    c->h[0] = 0x67452301;
    c->h[1] = 0xEFCDAB89;
    c->h[2] = 0x98BADCFE;
    c->h[3] = 0x10325476;
    c->h[4] = 0xC3D2E1F0;
    c->n0 = 0;
    c->n1 = 0;
    c->num = 0;
    c->block = func_L39_004EDE58;
}
/* localdecomp:end func_L39_004ED820 */

INCLUDE_ASM("asm/levels", func_L39_004ED888);

LINKER_REMNANT("asm/levels", func_L39_004EDE50);

/* localdecomp:start func_L39_004EDE58 */
/* OpenSSL 0.9.x sha1_block (sha1dgst.c), rolled into loops; ULONG is u64,
 * ROTATE(a, n) written out as ((a << n) | ((a & 0xffffffff) >> (32 - n))) */
typedef struct {
    u64 h0, h1, h2, h3, h4;
} SHA_004EDE58;

s32 func_L39_004EDE58(SHA_004EDE58 *ctx, u64 *W, s32 num) {
    u64 A, B, C, D, E, T;
    u64 a, b, c, d, e;
    u64 X[16];
    u64 *ia, *ib, *ic;
    s32 i;

    A = a = ctx->h0;
    B = b = ctx->h1;
    C = c = ctx->h2;
    D = d = ctx->h3;
    E = e = ctx->h4;

    for (;;) {
        for (i = 0; i < 16; i++) {
            T = W[i] + e + 0x5A827999 + ((a << 5) | ((a & 0xffffffff) >> 27)) + (((c ^ d) & b) ^ d);
            b = ((b << 30) | ((b & 0xffffffff) >> 2)); e = d; d = c; c = b; b = a; a = T;
        }
        ia = W;
        for (i = 16; i < 20; i++) {
            if (i == 19) ia = X;
            T = W[i & 15] ^ W[(i + 2) & 15] ^ W[(i + 8) & 15] ^ ia[(i + 13) & 15];
            X[i & 15] = T = ((T << 1) | ((T & 0xffffffff) >> 31));
            T += e + 0x5A827999 + ((a << 5) | ((a & 0xffffffff) >> 27)) + (((c ^ d) & b) ^ d);
            b = ((b << 30) | ((b & 0xffffffff) >> 2)); e = d; d = c; c = b; b = a; a = T;
        }
        ia = ib = ic = W;
        for (i = 20; i < 40; i++) {
            if (i == 24) ic = X;
            if (i == 30) ib = X;
            if (i == 32) ia = X;
            T = ia[i & 15] ^ ib[(i + 2) & 15] ^ ic[(i + 8) & 15] ^ X[(i + 13) & 15];
            X[i & 15] = T = ((T << 1) | ((T & 0xffffffff) >> 31));
            T += e + 0x6ED9EBA1 + ((a << 5) | ((a & 0xffffffff) >> 27)) + (b ^ c ^ d);
            b = ((b << 30) | ((b & 0xffffffff) >> 2)); e = d; d = c; c = b; b = a; a = T;
        }
        for (i = 40; i < 60; i++) {
            T = X[i & 15] ^ X[(i + 2) & 15] ^ X[(i + 8) & 15] ^ X[(i + 13) & 15];
            X[i & 15] = T = ((T << 1) | ((T & 0xffffffff) >> 31));
            T += e + 0x8F1BBCDC + ((a << 5) | ((a & 0xffffffff) >> 27)) + ((b & c) | ((b | c) & d));
            b = ((b << 30) | ((b & 0xffffffff) >> 2)); e = d; d = c; c = b; b = a; a = T;
        }
        for (i = 60; i < 80; i++) {
            T = X[i & 15] ^ X[(i + 2) & 15] ^ X[(i + 8) & 15] ^ X[(i + 13) & 15];
            X[i & 15] = T = ((T << 1) | ((T & 0xffffffff) >> 31));
            T = X[i & 15] + e + 0xCA62C1D6 + ((a << 5) | ((a & 0xffffffff) >> 27)) + (b ^ c ^ d);
            b = ((b << 30) | ((b & 0xffffffff) >> 2)); e = d; d = c; c = b; b = a; a = T;
        }

        ctx->h0 = (A + a) & 0xffffffff;
        ctx->h1 = (B + b) & 0xffffffff;
        ctx->h2 = (C + c) & 0xffffffff;
        ctx->h3 = (D + d) & 0xffffffff;
        ctx->h4 = (E + e) & 0xffffffff;
        num -= 64;
        if (num <= 0) break;
        A = a = ctx->h0;
        B = b = ctx->h1;
        C = c = ctx->h2;
        D = d = ctx->h3;
        E = e = ctx->h4;
        W += 16;
    }
}
/* localdecomp:end func_L39_004EDE58 */

/* localdecomp:start func_L39_004EE378 */
/* OpenSSL 0.9.x SHA1_Final (sha_dgst.c, public source) */
typedef struct {
    u64 h0, h1, h2, h3, h4;
    u64 Nl, Nh;
    u64 data[16];
    s32 num;
    void (*block)();
} S_004EE378;

extern u8 D_L39_0046D4F8[];

void func_L39_004EE378(u8 *md, S_004EE378 *c) {
    s32 i, j;
    u64 l;
    u64 *p;
    u8 *cp = D_L39_0046D4F8;

    p = c->data;
    j = c->num;
    i = j >> 2;
    l = p[i];
    switch (j & 3) {
    case 0: l = ((u64)(*(cp++))) << 24;
    case 1: l |= ((u64)(*(cp++))) << 16;
    case 2: l |= ((u64)(*(cp++))) << 8;
    case 3: l |= ((u64)(*(cp++)));
    }
    p[i] = l;
    i++;
    if (c->num >= 56) {
        for (; i < 16; i++)
            p[i] = 0;
        c->block(c, p, 64);
        i = 0;
    }
    for (; i < 14; i++)
        p[i] = 0;
    p[14] = c->Nh;
    p[15] = c->Nl;
    c->block(c, p, 64);
    cp = md;
    l = c->h0; *(cp++) = (u8)((l >> 24) & 0xff); *(cp++) = (u8)((l >> 16) & 0xff); *(cp++) = (u8)((l >> 8) & 0xff); *(cp++) = (u8)(l & 0xff);
    l = c->h1; *(cp++) = (u8)((l >> 24) & 0xff); *(cp++) = (u8)((l >> 16) & 0xff); *(cp++) = (u8)((l >> 8) & 0xff); *(cp++) = (u8)(l & 0xff);
    l = c->h2; *(cp++) = (u8)((l >> 24) & 0xff); *(cp++) = (u8)((l >> 16) & 0xff); *(cp++) = (u8)((l >> 8) & 0xff); *(cp++) = (u8)(l & 0xff);
    l = c->h3; *(cp++) = (u8)((l >> 24) & 0xff); *(cp++) = (u8)((l >> 16) & 0xff); *(cp++) = (u8)((l >> 8) & 0xff); *(cp++) = (u8)(l & 0xff);
    l = c->h4; *(cp++) = (u8)((l >> 24) & 0xff); *(cp++) = (u8)((l >> 16) & 0xff); *(cp++) = (u8)((l >> 8) & 0xff); *(cp++) = (u8)(l & 0xff);
    c->num = 0;
}
/* localdecomp:end func_L39_004EE378 */

/* localdecomp:start func_L39_004EE670 */
/* SSLeay's DSA_sign (dsa_sign.c, public source), with the BIGNUMs and the BN_CTX on the stack */
typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004EE670;

typedef struct {
    u8 pad[0x110];
} CTX_004EE670;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} AI_004EE670;

typedef struct {
    u8 pad0[0x10];
    BN_004EE670 *q;
    u8 pad14[0x1C - 0x14];
    BN_004EE670 *priv_key;
    BN_004EE670 *kinv;
    BN_004EE670 *r;
} DSA_004EE670;

extern void func_L39_004FC410(CTX_004EE670 *);
extern void func_L39_004FC370_004EE670(BN_004EE670 *);
extern s32 func_L39_004FC158_004EE670(BN_004EE670 *);
extern s32 func_L39_004DD8B0(DSA_004EE670 *, CTX_004EE670 *, BN_004EE670 **, BN_004EE670 **);
extern BN_004EE670 *func_L39_004FC780(u8 *, s32, BN_004EE670 *);
extern s32 func_L39_004FFAF0(BN_004EE670 *, BN_004EE670 *, BN_004EE670 *, BN_004EE670 *, CTX_004EE670 *);
extern s32 func_L39_004FB9A0_004EE670(BN_004EE670 *, BN_004EE670 *, BN_004EE670 *);
extern s32 func_L39_004FC9D0(void *, void *);
extern s32 func_L39_004FBDA0_004EE670(BN_004EE670 *, BN_004EE670 *, BN_004EE670 *);
extern s32 func_L39_004FC8C0_004EE670(BN_004EE670 *, u8 *);
extern s32 func_L39_004F9340(AI_004EE670 *, u8 **);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);
extern void func_L39_004FC448(void *);
extern void func_L39_004FC1A0(void *);

s32 func_L39_004EE670(s32 type, u8 *dgst, s32 dlen, u8 *sig, u32 *siglen, DSA_004EE670 *dsa) {
    CTX_004EE670 ctx;
    BN_004EE670 m;
    BN_004EE670 xr;
    BN_004EE670 s;
    u8 rbuf[64];
    u8 sbuf[64];
    AI_004EE670 rbs;
    AI_004EE670 sbs;
    BN_004EE670 *kinv;
    BN_004EE670 *r;
    u8 *p;
    s32 i, ret = 0, reason = 0x803;
    long len;

    r = 0;
    kinv = 0;
    func_L39_004FC410(&ctx);
    func_L39_004FC370_004EE670(&m);
    func_L39_004FC370_004EE670(&xr);
    func_L39_004FC370_004EE670(&s);

    i = (func_L39_004FC158_004EE670(dsa->q) + 7) / 8;
    if (dlen > i || dlen > 52) {
        reason = 100;
        goto err;
    }

    if (dsa->kinv == 0 || dsa->r == 0) {
        if (!func_L39_004DD8B0(dsa, &ctx, &kinv, &r)) {
            goto err;
        }
    } else {
        kinv = dsa->kinv;
        dsa->kinv = 0;
        r = dsa->r;
        dsa->r = 0;
    }

    if (func_L39_004FC780(dgst, dlen, &m) == 0) goto err;
    if (!func_L39_004FFAF0(&xr, dsa->priv_key, r, dsa->q, &ctx)) goto err;
    if (!func_L39_004FB9A0_004EE670(&s, &xr, &m)) goto err;
    if (func_L39_004FC9D0(&s, dsa->q) > 0) {
        func_L39_004FBDA0_004EE670(&s, &s, dsa->q);
    }
    if (!func_L39_004FFAF0(&s, &s, kinv, dsa->q, &ctx)) goto err;

    rbs.data = rbuf;
    rbs.type = 2;
    rbs.length = func_L39_004FC8C0_004EE670(r, rbs.data);
    sbs.data = sbuf;
    sbs.type = 2;
    sbs.length = func_L39_004FC8C0_004EE670(&s, sbs.data);

    len = func_L39_004F9340(&rbs, 0);
    len += func_L39_004F9340(&sbs, 0);

    p = sig;
    func_L39_004F9FF8(&p, 1, len, 16, 0);
    func_L39_004F9340(&rbs, &p);
    func_L39_004F9340(&sbs, &p);
    *siglen = p - sig;
    ret = 1;
    goto done;
err:
    func_L39_004BC6C8(10, 0x69, reason, 0, 0);
done:
    func_L39_004FC448(&ctx);
    if (kinv != 0) func_L39_004FC1A0(kinv);
    if (r != 0) func_L39_004FC1A0(r);
    func_L39_004FC1A0(&m);
    func_L39_004FC1A0(&xr);
    func_L39_004FC1A0(&s);
    return ret;
}
/* localdecomp:end func_L39_004EE670 */

/* localdecomp:start func_L39_004EE958 */
typedef struct {
    u64 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004EE958;

typedef struct {
    u8 _p0[0xC];
    BN_004EE958 *p;
    BN_004EE958 *q;
    BN_004EE958 *g;
    u8 _p18[0x28 - 0x18];
    s32 flags;
    void *method_mont_p;
} DSA_004EE958;

extern void *func_L39_004FC3C8(void);
extern void *func_L39_004FCF40(void);
extern s32 func_L39_004FFBB0(void *, BN_004EE958 *, void *);
extern void func_L39_004FC370_004EE958(BN_004EE958 *);
extern BN_004EE958 *func_L39_004FC380_004EE958(void);
extern void *func_L39_004E5090(void);
extern s32 func_L39_004FC158_004EE958(BN_004EE958 *);
extern s32 func_L39_004FFD58(void *, void *, s32, s32, s32);
extern s32 func_L39_004FC9D0(void *, void *);
extern s32 func_L39_004FBDA0_004EE958(BN_004EE958 *, BN_004EE958 *, BN_004EE958 *);
extern s32 func_L39_004FECA0(BN_004EE958 *, BN_004EE958 *, BN_004EE958 *, BN_004EE958 *, void *, void *);
extern s32 func_L39_004FBED8(void *, void *, s32, void *);
extern BN_004EE958 *func_L39_004FBF10(BN_004EE958 *, BN_004EE958 *, BN_004EE958 *, void *);
extern void func_L39_004FC1A0(void *);
extern void func_L39_004FC448(void *);

s32 func_L39_004EE958(DSA_004EE958 *dsa, void *ctx_in, BN_004EE958 **kinvp, BN_004EE958 **rp) {
    void *ctx;
    BN_004EE958 k, *kinv = 0, *r = 0;
    s32 ret = 0;

    if (ctx_in == 0) {
        if ((ctx = func_L39_004FC3C8()) == 0) {
            goto err;
        }
    } else {
        ctx = ctx_in;
    }

    if (dsa->method_mont_p == 0 && (dsa->flags & 1)) {
        if ((dsa->method_mont_p = func_L39_004FCF40()) != 0) {
            if (!func_L39_004FFBB0(dsa->method_mont_p, dsa->p, ctx)) {
                goto err;
            }
        }
    }

    func_L39_004FC370_004EE958(&k);
    kinv = 0;
    if ((r = func_L39_004FC380_004EE958()) == 0) {
        goto err;
    }

    for (;;) {
        if (!func_L39_004FFD58(&k, func_L39_004E5090(), func_L39_004FC158_004EE958(dsa->q), 1, 0)) {
            goto err;
        }
        if (func_L39_004FC9D0(&k, dsa->q) >= 0) {
            func_L39_004FBDA0_004EE958(&k, &k, dsa->q);
        }
        if (!(k.top == 0 || (k.top == 1 && k.d[0] == 0))) {
            break;
        }
    }

    if (!func_L39_004FECA0(r, dsa->g, &k, dsa->p, ctx, dsa->method_mont_p)) {
        goto err;
    }
    if (!func_L39_004FBED8(r, r, (s32)dsa->q, ctx)) {
        goto err;
    }
    if ((kinv = func_L39_004FBF10(0, &k, dsa->q, ctx)) == 0) {
        goto err;
    }

    if (*rp != 0) {
        func_L39_004FC1A0(*rp);
    }
    if (*kinvp != 0) {
        func_L39_004FC1A0(*kinvp);
    }
    *rp = r;
    r = 0;
    ret = 1;
    *kinvp = kinv;
    kinv = 0;
    goto done;
err:
    func_L39_004BC6C8(10, 106, 0x803, 0, 0);
done:
    if (ctx_in == 0) {
        func_L39_004FC448(ctx);
    }
    if (kinv != 0) {
        func_L39_004FC1A0(kinv);
    }
    if (r != 0) {
        func_L39_004FC1A0(r);
    }
    func_L39_004FC1A0(&k);
    return ret;
}
/* localdecomp:end func_L39_004EE958 */

/* localdecomp:start func_L39_004EEBC0 */
/* OpenSSL's RSA_sign */
typedef struct {
    u8 *sn;
    u8 *ln;
    s32 nid;
    s32 length;
} OBJ_004EEBC0;

typedef struct {
    s32 type;
    void *ptr;
} TYPE_004EEBC0;

typedef struct {
    OBJ_004EEBC0 *algorithm;
    TYPE_004EEBC0 *parameter;
} ALGOR_004EEBC0;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} OS_004EEBC0;

typedef struct {
    ALGOR_004EEBC0 *algor;
    OS_004EEBC0 *digest;
} SIG_004EEBC0;

extern void *func_L39_004E0A58(s32);
extern s32 func_L39_004F3DC8(SIG_004EEBC0 *, u8 **);
extern s32 func_L39_004EA5A8(void *);
extern s32 func_L39_004EA938(s32, u8 *, u8 *, void *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

s32 func_L39_004EEBC0(s32 type, u8 *m, u32 m_len, u8 *sigret, u32 *siglen, void *rsa) {
    SIG_004EEBC0 sig;
    TYPE_004EEBC0 parameter;
    s32 i, j, ret = 1;
    u8 *p, *s;
    ALGOR_004EEBC0 algor;
    OS_004EEBC0 digest;

    sig.algor = &algor;
    sig.algor->algorithm = func_L39_004E0A58(type);
    if (sig.algor->algorithm == 0) {
        func_L39_004BC6C8(4, 0x7E, 0x78, 0, 0);
        return 0;
    }
    if (sig.algor->algorithm->length == 0) {
        func_L39_004BC6C8(4, 0x7E, 0x77, 0, 0);
        return 0;
    }
    parameter.type = 5;
    parameter.ptr = 0;
    sig.algor->parameter = &parameter;

    sig.digest = &digest;
    sig.digest->data = m;
    sig.digest->length = m_len;

    i = func_L39_004F3DC8(&sig, 0);
    j = func_L39_004EA5A8(rsa);
    if (i - 1 > j) {
        func_L39_004BC6C8(4, 0x7E, 0x6F, 0, 0);
        return 0;
    }
    s = func_L39_004BEED8(j + 1);
    if (s == 0) {
        func_L39_004BC6C8(4, 0x7E, 0x21, 0, 0);
        return 0;
    }
    p = s;
    func_L39_004F3DC8(&sig, &p);
    i = func_L39_004EA938(i, s, sigret, rsa, 1);
    if (i <= 0) {
        ret = 0;
    } else {
        *siglen = i;
    }

    func_0011D534(s, 0, j + 1);
    func_L39_004BEF28(s);
    return ret;
}
/* localdecomp:end func_L39_004EEBC0 */

/* localdecomp:start func_L39_004EED58 */
/* OpenSSL's RSA_verify */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} OS_004EED58;

typedef struct {
    void *algorithm;
    void *parameter;
} ALGOR_004EED58;

typedef struct {
    ALGOR_004EED58 *algor;
    OS_004EED58 *digest;
} SIG_004EED58;

extern s32 func_L39_004EA5A8(void *);
extern s32 func_L39_004EA9D0(s32, u8 *, u8 *, void *, s32);
extern SIG_004EED58 *func_L39_004F3E90(SIG_004EED58 **, u8 **, s32);
extern s32 func_L39_004E0C88(void *);
extern void func_L39_004F40C8(SIG_004EED58 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_004EED58(s32 dtype, u8 *m, u32 m_len, u8 *sigbuf, u32 siglen, void *rsa) {
    s32 i;
    s32 ret = 0;
    s32 sigtype;
    u8 *p;
    u8 *s;
    SIG_004EED58 *sig = 0;

    if (siglen != func_L39_004EA5A8(rsa)) {
        func_L39_004BC6C8(4, 0x7F, 0x75, 0, 0);
        return 0;
    }

    s = func_L39_004BEED8(siglen);
    if (s == 0) {
        func_L39_004BC6C8(4, 0x7F, 0x21, 0, 0);
        goto err;
    }
    i = func_L39_004EA9D0(siglen, sigbuf, s, rsa, 1);

    if (i <= 0) {
        goto err;
    }

    p = s;
    sig = func_L39_004F3E90(0, &p, i);
    if (sig == 0) {
        goto err;
    }
    sigtype = func_L39_004E0C88(sig->algor->algorithm);
    if (sigtype != dtype) {
        func_L39_004BC6C8(4, 0x7F, 0x76, 0, 0);
        goto err;
    }

    if ((u32)sig->digest->length != m_len || func_0011D2EC(m, sig->digest->data, m_len) != 0) {
        func_L39_004BC6C8(4, 0x7F, 0x67, 0, 0);
    } else {
        ret = 1;
    }
err:
    if (sig != 0) {
        func_L39_004F40C8(sig);
    }
    func_0011D534(s, 0, siglen);
    func_L39_004BEF28(s);
    return ret;
}
/* localdecomp:end func_L39_004EED58 */

/* localdecomp:start func_L39_004EEEF0 */
extern void *func_L39_004BEF00(void *, s32, s32);
typedef struct {
    s32 num;
    char **data;
    s32 sorted;
    s32 num_alloc;
} S_004EEEF0;

/* OpenSSL's sk_insert */
s32 func_L39_004EEEF0(S_004EEEF0 *st, char *data, s32 loc)
{
    char **s;
    s32 i;
    char **f, **t;

    if (st->num_alloc <= st->num + 1) {
        s = func_L39_004BEF00(st->data, sizeof(char *) * st->num_alloc * 2, sizeof(char *) * st->num_alloc);
        if (s == 0) {
            return 0;
        }
        st->data = s;
        st->num_alloc *= 2;
    }
    if (loc >= st->num || loc < 0) {
        st->data[st->num] = data;
    } else {
        f = &st->data[-1];
        t = st->data;
        for (i = st->num; i > loc; i--) {
            t[i] = f[i];
        }
        st->data[loc] = data;
    }
    st->num++;
    st->sorted = 0;
    return st->num;
}
/* localdecomp:end func_L39_004EEEF0 */

/* localdecomp:start func_L39_004EEFF0 */
/* OpenSSL's sk_delete */
typedef struct {
    s32 num;
    s32 *data;
} S_004EEFF0;

s32 func_L39_004EEFF0(S_004EEFF0 *st, s32 loc) {
    s32 ret;
    s32 i, j;

    if (st->num == 0 || loc < 0 || loc >= st->num) {
        return 0;
    }
    ret = st->data[loc];
    if (loc != st->num - 1) {
        j = st->num - 1;
        for (i = loc; i < j; i++) {
            st->data[i] = st->data[i + 1];
        }
    }
    st->num--;
    return ret;
}
/* localdecomp:end func_L39_004EEFF0 */

/* localdecomp:start func_L39_004EF078 */
extern s32 func_L01_00494120(s32);
extern void *func_L39_004DF010(void);
extern void func_L39_004DF0E0(void *);
extern s32 func_L39_004DF158(void *, void *);
extern s32 func_L39_004DF260(void *, u8 *, s32, s32);
extern void func_L39_004DF408(void *, void *, s32);
extern s32 func_L39_004DF410(void *, u8 *, s32 *);
extern void func_0011D380(void *, void *, s32);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_004EF078(s32 md, u8 *sec, s32 sec_len, s32 seed, s32 seed_len, u8 *out, s32 olen) {
    s32 chunk;
    s32 j;
    void *ctx;
    void *ctx_tmp;
    u8 A1[0x40];
    s32 A1_len;
    s32 ret = 0;

    chunk = func_L01_00494120(md);
    ctx = func_L39_004DF010();
    ctx_tmp = func_L39_004DF010();
    if (ctx == 0 || ctx_tmp == 0) {
        goto err;
    }
    if (!func_L39_004DF260(ctx, sec, sec_len, md)) {
        goto err;
    }
    func_L39_004DF408(ctx, (void *)seed, seed_len);
    if (!func_L39_004DF410(ctx, A1, &A1_len)) {
        goto err;
    }
    for (;;) {
        if (!func_L39_004DF260(ctx, 0, 0, 0)) {
            goto err;
        }
        func_L39_004DF408(ctx, A1, A1_len);
        if (!func_L39_004DF158(ctx_tmp, ctx)) {
            goto err;
        }
        func_L39_004DF408(ctx, (void *)seed, seed_len);
        if (olen > chunk) {
            if (!func_L39_004DF410(ctx, out, &j)) {
                goto err;
            }
            out += j;
            olen -= j;
            if (!func_L39_004DF410(ctx_tmp, A1, &A1_len)) {
                goto err;
            }
        } else {
            if (!func_L39_004DF410(ctx, A1, &A1_len)) {
                goto err;
            }
            func_0011D380(out, A1, olen);
            break;
        }
    }
    ret = 1;
err:
    if (ctx != 0) {
        func_L39_004DF0E0(ctx);
    }
    if (ctx_tmp != 0) {
        func_L39_004DF0E0(ctx_tmp);
    }
    func_0011D534(A1, 0, 0x40);
    return ret;
}
/* localdecomp:end func_L39_004EF078 */

/* localdecomp:start func_L39_004EF240 */
extern s32 func_L39_004EF078(s32, u8 *, s32, s32, s32, u8 *, s32);

s32 func_L39_004EF240(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8) {
    s32 len = a5 / 2;
    u8 *b = a4 + len;
    s32 i;

    len += a5 & 1;

    if (!func_L39_004EF078(a0, a4, len, a2, a3, a6, a8)) {
        return 0;
    }
    if (!func_L39_004EF078(a1, b, len, a2, a3, a7, a8)) {
        return 0;
    }
    for (i = 0; i < a8; i++) {
        a6[i] ^= a7[i];
    }
    return 1;
}
/* localdecomp:end func_L39_004EF240 */

INCLUDE_ASM("asm/levels", func_L39_004EF350);

/* localdecomp:start func_L39_004EF448 */
/* OpenSSL tls1_change_cipher_state (t1_enc.c), DNAS variant with an HMAC context per direction */
typedef struct {
    u8 pad0[0x10];
    unsigned long algorithms;
    unsigned long algo_strength;
} CIPH_004EF448;

typedef struct {
    u8 pad0[0xC];
    u8 read_sequence[8];
    u8 read_mac_secret[0x14];
    u8 write_sequence[8];
    u8 write_mac_secret[0x14];
    u8 server_random[0x20];
    u8 client_random[0x20];
    u8 pad84[0x15C - 0x84];
    CIPH_004EF448 *new_cipher;
    u8 pad160[0x184 - 0x160];
    s32 key_block_length;
    u8 *key_block;
    void *new_sym_enc;
    void *new_hash;
} S3_004EF448;

typedef struct {
    s32 mac_size;
    void *hmac;
    void *cipher;
} DIR_004EF448;

typedef struct {
    u8 pad0[4];
    s32 key_arg_length;
} SESS_004EF448;

typedef struct {
    u8 pad0[0x104];
    s32 md5;
    s32 sha1;
} CTX_004EF448;

typedef struct {
    u8 pad0[0x54];
    S3_004EF448 *s3;
    u8 pad58[0x68 - 0x58];
    DIR_004EF448 rd;
    DIR_004EF448 wr;
    void (*hmac_free)(void *);
    u8 pad84[0xB0 - 0x84];
    SESS_004EF448 *session;
    u8 padB4[0xDC - 0xB4];
    CTX_004EF448 *ctx;
} SSL_004EF448;

/* memcpy and memset under their real return type (the file declares them void) */
extern void *func_0011D380_004EF448(void *, const void *, u32);
extern void *func_0011D534_004EF448(void *, s32, u32);
extern char D_L39_004789F0[];
extern char D_L39_00478A08[];
extern char D_L39_00478A20[];
extern char D_L39_00478A30[];
extern void *func_L39_004DE550(void);
extern s32 func_L39_004DE458(void *);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L01_004CC758(void *);
extern s32 func_L39_00504B50(void *, void *, u8 *, u8 *, s32);

s32 func_L39_004EF448(SSL_004EF448 *s, s32 which) {
    u8 *p, *key_block, *mac_secret;
    u8 *exp_label;
    u8 buf[20 + 32 * 2];
    u8 tmp1[0x20];
    u8 tmp2[0x20];
    u8 iv1[0x40];
    u8 iv2[0x40];
    u8 *ms, *key, *iv;
    s32 client_write;
    DIR_004EF448 *d;
    void *dd;
    void *c;
    void *m;
    s32 _exp, n, i, j, k, exp_label_len;

    _exp = (s->s3->new_cipher->algorithms & 0x100000) != 0;
    c = s->s3->new_sym_enc;
    m = s->s3->new_hash;

    if (which & 1) {
        d = &s->rd;
        func_0011D534_004EF448(s->s3->read_sequence, 0, 8);
        mac_secret = s->s3->read_mac_secret;
    } else {
        d = &s->wr;
        func_0011D534_004EF448(s->s3->write_sequence, 0, 8);
        mac_secret = s->s3->write_mac_secret;
    }

    if (d->cipher == 0 && (d->cipher = func_L39_004DE550()) == 0) {
        goto err;
    }
    if (d->hmac == 0 && (d->hmac = func_L39_004DF010()) == 0) {
        goto err;
    }
    s->hmac_free = func_L39_004DF0E0;
    if (!func_L39_004DF260(d->hmac, 0, 0, (s32)m)) {
        goto err;
    }
    d->mac_size = func_L01_00494120((s32)m);
    dd = d->cipher;
    if (!func_L39_004DE458(dd)) {
        goto err;
    }

    p = s->s3->key_block;
    i = func_L01_00494120((s32)m);
    j = (s32)(s->s3->new_cipher->algo_strength & 0xFF);
    if (j == 0) {
        j = func_L39_004DE8F8(c);
    }
    k = func_L01_004CC758(c);
    if (which == 0x12 || which == 0x21) {
        ms = &p[0];
        n = i + i;
        key = &p[n];
        n += j + j;
        iv = &p[n];
        n += k + k;
        exp_label = (u8 *)D_L39_004789F0;
        exp_label_len = 16;
        client_write = 1;
    } else {
        n = i;
        ms = &p[n];
        n += i + j;
        key = &p[n];
        n += j + k;
        iv = &p[n];
        n += k;
        exp_label = (u8 *)D_L39_00478A08;
        exp_label_len = 16;
        client_write = 0;
    }

    if (n > s->s3->key_block_length) {
        func_L39_004BC6C8(20, 0xD2, 0x9D, 0, 0);
        goto err2;
    }

    func_0011D380_004EF448(mac_secret, ms, i);
    if (_exp) {
        p = buf;
        func_0011D380_004EF448(p, exp_label, exp_label_len);
        p += exp_label_len;
        __builtin_memcpy(p, s->s3->client_random, 32);
        p += 32;
        __builtin_memcpy(p, s->s3->server_random, 32);
        p += 32;
        if (!func_L39_004EF240(s->ctx->md5, s->ctx->sha1, (s32)buf, p - buf, key, j,
                               tmp1, tmp2, func_L39_004DE8F8(c))) {
            return 0;
        }
        key = tmp1;

        if (k > 0) {
            p = buf;
            __builtin_memcpy(p, D_L39_00478A20, 8);
            p += 8;
            __builtin_memcpy(p, s->s3->client_random, 32);
            p += 32;
            __builtin_memcpy(p, s->s3->server_random, 32);
            p += 32;
            if (!func_L39_004EF240(s->ctx->md5, s->ctx->sha1, (s32)buf, p - buf,
                                   (u8 *)D_L39_00478A30, 0, iv1, iv2, k * 2)) {
                return 0;
            }
            if (client_write) {
                iv = iv1;
            } else {
                iv = &iv1[k];
            }
        }
    }

    s->session->key_arg_length = 0;

    if (!func_L39_00504B50(dd, c, key, iv, which & 2)) {
        return 0;
    }
    func_0011D534_004EF448(tmp1, 0, sizeof(tmp1));
    func_0011D534_004EF448(tmp2, 0, sizeof(tmp2));
    func_0011D534_004EF448(iv1, 0, sizeof(iv1));
    func_0011D534_004EF448(iv2, 0, sizeof(iv2));
    return 1;
err:
    func_L39_004BC6C8(20, 0xD2, 0x21, 0, 0);
err2:
    return 0;
}
/* localdecomp:end func_L39_004EF448 */

/* localdecomp:start func_L39_004EF8F8 */
/* OpenSSL's tls1_setup_key_block */
typedef struct {
    u8 pad[0x184];
    s32 key_block_length;
    u8 *key_block;
    void *new_sym_enc;
    void *new_hash;
} S3_004EF8F8;

typedef struct {
    u8 pad[0xAC];
    s32 cipher;
} SESS_004EF8F8;

typedef struct {
    u8 pad[0x54];
    S3_004EF8F8 *s3;
    u8 pad2[0xB0 - 0x58];
    SESS_004EF8F8 *session;
} SSL_004EF8F8;

extern s32 func_L39_004CA3D0(s32, void **, void **);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L01_004CC758(void *);
extern void func_L39_004EBF88(SSL_004EF8F8 *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004EF350(SSL_004EF8F8 *, u8 *, u8 *, s32);

s32 func_L39_004EF8F8(SSL_004EF8F8 *s) {
    u8 *p1;
    u8 *p2;
    void *c;
    void *hash;
    s32 num;

    if (s->s3->key_block_length != 0) {
        return 1;
    }

    if (!func_L39_004CA3D0(s->session->cipher, &c, &hash)) {
        func_L39_004BC6C8(0x14, 0xD4, 0x8A, 0, 0);
        return 0;
    }

    s->s3->new_sym_enc = c;
    s->s3->new_hash = hash;

    num = func_L39_004DE8F8(c) + func_L01_00494120((s32)hash) + func_L01_004CC758(c);
    num = num * 2 + 1;

    func_L39_004EBF88(s);

    if ((p1 = func_L39_004BEED8(num)) == 0) {
        goto err;
    }
    if ((p2 = func_L39_004BEED8(num)) == 0) {
        goto err;
    }

    s->s3->key_block_length = num;
    s->s3->key_block = p1;

    if (!func_L39_004EF350(s, p1, p2, num)) {
        goto end;
    }
    func_0011D534(p2, 0, num);
    func_L39_004BEF28(p2);
    return 1;
err:
    func_L39_004BC6C8(0x14, 0xD4, 0x21, 0, 0);
end:
    return 0;
}
/* localdecomp:end func_L39_004EF8F8 */

/* localdecomp:start func_L39_004EFA50 */
/* OpenSSL's tls1_enc (t1_enc.c, public source) */
typedef struct {
    s32 type;
    u32 length;
    u32 off;
    u8 *data;
    u8 *input;
} Rec_004EFA50;

typedef struct {
    unsigned long flags;
    u8 pad8[4];
    u8 read_sequence[8];
} S3_004EFA50;

typedef struct {
    void *pad0;
    void *pad4;
    void *enc_ctx;
} Dir_004EFA50;

typedef struct {
    u8 pad0[0x54];
    S3_004EFA50 *s3;
    u8 pad58[0x68 - 0x58];
    Dir_004EFA50 rd;
    Dir_004EFA50 wr;
    u8 pad80[0xB0 - 0x80];
    void *session;
    u8 padB4[0x100 - 0xB4];
    unsigned long options;
} SSL_004EFA50;

extern void *func_L39_00505060(void *);
extern s32 func_L39_004DE908(void *);
extern void func_L39_00504A30(void *, u8 *, u8 *, u32);
extern s32 func_11D2EC(void *, void *, s32);
extern s32 func_L39_004C9F50(void *, s32, s32);
extern char D_L39_00478A38[];

s32 func_L39_004EFA50(SSL_004EFA50 *s, s32 send) {
    Rec_004EFA50 *rec;
    void *ds;
    unsigned long l;
    s32 bs, i, ii, j, k;
    void *enc;
    Dir_004EFA50 *dir;

    if (send) {
        rec = (Rec_004EFA50 *)((u8 *)s->s3 + 0xCC);
        dir = &s->wr;
    } else {
        rec = (Rec_004EFA50 *)((u8 *)s->s3 + 0xB4);
        dir = &s->rd;
    }
    ds = dir->enc_ctx;
    if (ds == 0) {
        enc = 0;
    } else {
        enc = func_L39_00505060(ds);
    }

    if (s->session == 0 || ds == 0 || enc == 0) {
        ((void *(*)(void *, void *, s32))func_0011D380)(rec->data, rec->input, rec->length);
        rec->input = rec->data;
    } else {
        l = rec->length;
        bs = func_L39_004DE908(ds);

        if (bs != 1 && send) {
            i = bs - ((s32)l % bs);
            j = i - 1;
            if (s->options & 0x200) {
                if (s->s3->flags & 8) {
                    j++;
                }
            }
            for (k = (s32)l; k < (s32)(l + i); k++) {
                rec->input[k] = j;
            }
            l += i;
            rec->length += i;
        }

        func_L39_00504A30(ds, rec->data, rec->input, l);

        if (bs != 1 && !send) {
            ii = i = rec->data[l - 1];
            i++;
            if (s->options & 0x200) {
                if (func_11D2EC(s->s3->read_sequence, D_L39_00478A38, 8) == 0 && !(ii & 1)) {
                    s->s3->flags |= 8;
                }
                if (s->s3->flags & 8) {
                    i--;
                }
            }
            if (i > (s32)rec->length) {
                func_L39_004BC6C8(20, 0xD3, 0x81, 0, 0);
                func_L39_004C9F50(s, 2, 21);
                return 0;
            }
            for (j = (s32)(l - i); j < (s32)l; j++) {
                if (rec->data[j] != ii) {
                    func_L39_004BC6C8(20, 0xD3, 0x93, 0, 0);
                    func_L39_004C9F50(s, 2, 21);
                    return 0;
                }
            }
            rec->length -= i;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004EFA50 */

/* localdecomp:start func_L39_004EFD20 */
extern s32 func_L39_00505120(void *, void *);
extern void func_L39_004DD7A8(void *, void *, s32 *);

s32 func_L39_004EFD20(u8 *ctx, void *src, void *md) {
    s32 n;

    if (!func_L39_00505120(*(void **)(ctx + 0x128), src)) {
        return 0;
    }
    func_L39_004DD7A8(*(void **)(ctx + 0x128), md, &n);
    return n;
}
/* localdecomp:end func_L39_004EFD20 */

/* localdecomp:start func_L39_004EFD78 */
s32 func_L39_004EFD78(u8 *s, void *in1, void *in2, void *str, s32 slen, u8 *out)
{
    u8 buf[0x40];
    u8 buf2[12];
    s32 i;
    u8 *q;

    q = buf;
    func_0011D380(q, str, slen);
    q += slen;

    if (!func_L39_00505120(*(void **)(s + 0x128), in1)) {
        return 0;
    }
    func_L39_004DD7A8(*(void **)(s + 0x128), q, &i);
    q += i;
    if (!func_L39_00505120(*(void **)(s + 0x128), in2)) {
        return 0;
    }
    func_L39_004DD7A8(*(void **)(s + 0x128), q, &i);
    q += i;

    if (!func_L39_004EF240(*(s32 *)(*(u8 **)(s + 0xDC) + 0x104), *(s32 *)(*(u8 **)(s + 0xDC) + 0x108),
                           (s32)buf, q - buf,
                           *(u8 **)(s + 0xB0) + 0x14, *(s32 *)(*(u8 **)(s + 0xB0) + 0x10),
                           out, buf2, 12)) {
        return 0;
    }
    return 12;
}
/* localdecomp:end func_L39_004EFD78 */

/* localdecomp:start func_L39_004EFE90 */
/* OpenSSL's tls1_mac */
typedef struct {
    s32 type;
    u32 length;
    s32 off;
    s32 data;
    u8 *input;
} R_004EFE90;

extern s32 func_L01_004CC748(void *);

s32 func_L39_004EFE90(u8 *s, u8 *md, s32 send) {
    R_004EFE90 *rec;
    u8 *mac_sec;
    u8 *seq;
    void *hash;
    s32 md_size;
    s32 i;
    u8 buf[5];

    if (send) {
        rec = (R_004EFE90 *)(*(u8 **)(s + 0x54) + 0xCC);
        mac_sec = *(u8 **)(s + 0x54) + 0x30;
        seq = *(u8 **)(s + 0x54) + 0x28;
        hash = *(void **)(s + 0x78);
    } else {
        rec = (R_004EFE90 *)(*(u8 **)(s + 0x54) + 0xB4);
        mac_sec = *(u8 **)(s + 0x54) + 0x14;
        seq = *(u8 **)(s + 0x54) + 0xC;
        hash = *(void **)(s + 0x6C);
    }

    md_size = func_L01_00494120(func_L01_004CC748(hash));

    buf[0] = rec->type;
    buf[1] = 3;
    buf[2] = 1;
    buf[3] = rec->length >> 8;
    buf[4] = rec->length;

    if (!func_L39_004DF260(hash, mac_sec, md_size, 0)) {
        return 0;
    }
    func_L39_004DF408(hash, seq, 8);
    func_L39_004DF408(hash, buf, 5);
    func_L39_004DF408(hash, rec->input, rec->length);
    if (!func_L39_004DF410(hash, md, &md_size)) {
        return 0;
    }

    for (i = 7; i >= 0; i--) {
        if (++seq[i] != 0) {
            break;
        }
    }
    return md_size;
}
/* localdecomp:end func_L39_004EFE90 */

/* localdecomp:start func_L39_004EFFE8 */
extern char D_L39_00478A48[] __attribute__((aligned(8)));
typedef struct S3_004EFFE8 { u8 pad[0x44]; u8 server_random[32]; u8 client_random[32]; } S3_004EFFE8;
typedef struct C_004EFFE8 { u8 pad[0x104]; s32 md5; s32 sha1; } C_004EFFE8;
typedef struct Sess_004EFFE8 { u8 pad[0x14]; u8 master_key[48]; } Sess_004EFFE8;
typedef struct S_004EFFE8 {
    u8 pad[0x54];
    S3_004EFFE8 *s3;
    u8 pad58[0xB0 - 0x58];
    Sess_004EFFE8 *session;
    u8 padB4[0xDC - 0xB4];
    C_004EFFE8 *ctx;
} S_004EFFE8;

/* OpenSSL's tls1_generate_master_secret */
s32 func_L39_004EFFE8(S_004EFFE8 *s, u8 *out, u8 *p, s32 len)
{
    u8 buf[13 + 32 * 2] __attribute__((aligned(8)));
    u8 buff[48];

    __builtin_memcpy(buf, D_L39_00478A48, 13);
    __builtin_memcpy(&buf[13], s->s3->client_random, 32);
    __builtin_memcpy(&buf[13 + 32], s->s3->server_random, 32);
    if (!func_L39_004EF240(s->ctx->md5, s->ctx->sha1, (s32)buf, 13 + 32 * 2, p, len,
                           s->session->master_key, buff, 48)) {
        return 0;
    }
    return 48;
}
/* localdecomp:end func_L39_004EFFE8 */

/* localdecomp:start func_L39_004F00E8 */
s32 func_L39_004F00E8(u32 code) {
    switch (code) {
    case 0: return 0;
    case 10: return 10;
    case 20: return 20;
    case 21: return 21;
    case 22: return 22;
    case 30: return 30;
    case 40: return 40;
    case 41: return -1;
    case 42: return 42;
    case 43: return 43;
    case 44: return 44;
    case 45: return 45;
    case 46: return 46;
    case 47: return 47;
    case 48: return 48;
    case 49: return 49;
    case 50: return 50;
    case 51: return 51;
    case 60: return 60;
    case 70: return 70;
    case 71: return 71;
    case 80: return 80;
    case 90: return 90;
    case 100: return 100;
    default: return -1;
    }
}
/* localdecomp:end func_L39_004F00E8 */

/* localdecomp:start func_L39_004F01D8 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F01D8;

typedef struct {
    s32 f0;
    s32 f4;
    V_004F01D8 t;
} T_004F01D8;

s32 func_L39_004F01D8(T_004F01D8 *a, T_004F01D8 *b, s32 *out) {
    V_004F01D8 zero;
    V_004F01D8 *pa;
    V_004F01D8 *pb;
    s32 r;

    func_0011D534(&zero, 0, sizeof(zero));
    pa = (a == 0) ? &zero : &a->t;
    pb = (b == 0) ? &zero : &b->t;
    if (pa->hi > pb->hi) {
        r = 1;
    } else if (pa->hi < pb->hi) {
        r = -1;
    } else if (pa->lo > pb->lo) {
        r = 1;
    } else if (pa->lo < pb->lo) {
        r = -1;
    } else if (pa->ns > pb->ns) {
        r = 1;
    } else if (pa->ns < pb->ns) {
        r = -1;
    } else {
        r = 0;
    }
    *out = r;
    return 0;
}
/* localdecomp:end func_L39_004F01D8 */

/* localdecomp:start func_L39_004F02A0 */
/* LOG
 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F02A0;

typedef struct {
    s32 f0;
    s32 f4;
    V_004F02A0 v;
} T_004F02A0;

typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004F02A0;

typedef struct {
    u8 pad[0x1C8];
    s32 days[2][13];
} C_004F02A0;

extern u8 D_L39_00478BF8[];
extern u8 D_L39_00478C18[];
extern u8 D_L39_00478C40[];

extern void *func_L39_004DBA08(void);
extern BN_004F02A0 *func_L39_004FC380_004F02A0(void);
extern s32 func_L39_004FC6F8_004F02A0(BN_004F02A0 *, unsigned long);
extern unsigned long func_L39_004FD228_004F02A0(BN_004F02A0 *, unsigned long);
extern BN_004F02A0 *func_L39_004FC580_004F02A0(BN_004F02A0 *);
extern s32 func_L39_004FD500_004F02A0(BN_004F02A0 *, unsigned long);
extern s32 func_L39_004FD678_004F02A0(BN_004F02A0 *, unsigned long);
extern unsigned long func_L39_004FD2D0_004F02A0(BN_004F02A0 *, unsigned long);
extern s32 func_L39_004FB9A0_004F02A0(BN_004F02A0 *, BN_004F02A0 *, BN_004F02A0 *);
extern s32 func_L39_004FBDA0_004F02A0(BN_004F02A0 *, BN_004F02A0 *, BN_004F02A0 *);
extern s32 func_L39_004FD3B0_004F02A0(BN_004F02A0 *, unsigned long);
extern void func_L39_004FC228_004F02A0(BN_004F02A0 *);
extern s32 func_L39_004FCB28_004F02A0(BN_004F02A0 *, BN_004F02A0 *, s32);
extern unsigned long func_L39_004FC668_004F02A0(BN_004F02A0 *);
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);

s32 func_L39_004F02A0(T_004F02A0 *out, s32 type, u8 *buf, s32 *plen, s32 buflen) {
    C_004F02A0 *ctx;
    s32 ret;
    V_004F02A0 *t;

    ctx = func_L39_004DBA08();
    ret = 0;

    if (buf == 0 || out == 0) {
        ret = 0x2721;
        goto end;
    }
    t = &out->v;
    if (type == 1 || type == 2 || type == 6) {
        s32 day = -1;
        s32 year, yday, m, leap;

        s32 hour, min, sec;
        V_004F02A0 tmp;
        BN_004F02A0 *bn3;
        s32 neg = 0;
        BN_004F02A0 *bn4;
        BN_004F02A0 *bn;
        BN_004F02A0 *bn2;
        bn = func_L39_004FC380_004F02A0();
        if (bn == 0) {
            ret = 0x2715;
            goto end;
        }
        if (out->v.hi < 0) {
            tmp.hi = ~out->v.hi;
            tmp.lo = ~t->lo;
            tmp.ns = t->ns;
            t = &tmp;
            t->lo++;
            if (t->lo == 0) {
                t->hi++;
            }
            neg = 1;
        }
        func_L39_004FC6F8_004F02A0(bn, t->hi);
        func_L39_004FCB28_004F02A0(bn, bn, 32);
        func_L39_004FD3B0_004F02A0(bn, t->lo);
        if (neg) {
            bn->neg = 1;
        }
        sec = (s32)func_L39_004FD2D0_004F02A0(bn, 60);
        min = (s32)func_L39_004FD2D0_004F02A0(bn, 60);
        hour = (s32)func_L39_004FD2D0_004F02A0(bn, 24);
        bn2 = func_L39_004FC580_004F02A0(bn);
        if (bn2 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD678_004F02A0(bn2, 400);
        func_L39_004FD2D0_004F02A0(bn2, 146097);
        bn3 = func_L39_004FC580_004F02A0(bn2);
        if (bn3 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD3B0_004F02A0(bn2, 1970);
        bn4 = func_L39_004FC580_004F02A0(bn2);
        if (bn4 == 0) {
            ret = 0x2715;
            goto end;
        }
        if (bn->neg == 0) {
            func_L39_004FD500_004F02A0(bn4, 1);
        }
        func_L39_004FD678_004F02A0(bn3, 365);
        func_L39_004FD2D0_004F02A0(bn4, 4);
        func_L39_004FB9A0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD2D0_004F02A0(bn4, 25);
        func_L39_004FBDA0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD2D0_004F02A0(bn4, 4);
        func_L39_004FB9A0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD500_004F02A0(bn3, 477);
        if (bn->neg != 0 && bn2->neg == 0 &&
            !(func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0))) {
            func_L39_004FD3B0_004F02A0(bn3, 1);
        }
        func_L39_004FBDA0_004F02A0(bn, bn, bn3);
        if (bn->neg != 0) {
            func_L39_004FD500_004F02A0(bn2, 1);
            func_L39_004FD3B0_004F02A0(bn, (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) ? 366 : 365);
        }
        leap = 0;
        yday = (s32)func_L39_004FC668_004F02A0(bn);
        if (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) {
            if (yday < 366) {
                leap = 1;
            } else {
                func_L39_004FD3B0_004F02A0(bn2, 1);
                yday -= 366;
            }
        } else if (yday >= 365) {
            func_L39_004FD3B0_004F02A0(bn2, 1);
            yday -= 365;
            if (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) {
                leap = 1;
            }
        }
        for (m = 1; m < 13; m++) {
            if (yday < ctx->days[leap][m]) {
                day = yday - ctx->days[leap][m - 1];
                break;
            }
        }
        day++;
        if (type == 1) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 0x801 || year < 0x79E) {
                ret = 0x2723;
                goto end;
            }
            *plen = 14;
            if (buflen < 14) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478BF8, year % 100, m, day, hour, min, sec);
        } else if (type == 2) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 9999) {
                ret = 0x2723;
                goto end;
            }
            *plen = 17;
            if (buflen < 17) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478C18, year, m, day, hour, min, sec, t->ns / 100000000);
        } else if (type == 6) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 9999) {
                ret = 0x2723;
                goto end;
            }
            *plen = 20;
            if (buflen < 20) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478C40, year, m, day, hour, min, sec);
        }
        func_L39_004FC228_004F02A0(bn);
        func_L39_004FC228_004F02A0(bn2);
        func_L39_004FC228_004F02A0(bn3);
        func_L39_004FC228_004F02A0(bn4);
    } else if (type == 3) {
        s32 n = 8;
        s32 fill = 0;
        s32 sign = 1;
        s32 found = 0;
        u32 i;
        s32 v;
        u8 *p;
        u8 *q;

        if (t->hi < 0) {
            sign = -1;
            fill = -1;
        }
        v = sign * t->hi;
        for (i = 3; (s32)i >= 0; i--) {
            if (((v >> (i * 8)) & 0xFF) != 0) {
                found = 1;
                break;
            }
            n--;
        }
        if (!found) {
            v = sign * t->lo;
            for (i = 3; (s32)i >= 0; i--) {
                if (((v >> (i * 8)) & 0xFF) != 0) {
                    break;
                }
                n--;
            }
        }
        if (buflen < n) {
            *plen = n;
            ret = 0x2720;
            goto end;
        }
        func_0011D534(buf, fill, buflen - n);
        *plen = buflen;
        p = buf + buflen - 1;
        q = (u8 *)&t->lo;
        i = 0;
        *p-- = *q++;
        if (n != 0) {
            do {
                if (++i >= 4) {
                    break;
                }
                *p-- = *q++;
            } while (i != n);
            if (i != n) {
                q = (u8 *)&t->hi;
                *p-- = *q++;
                i = 0;
                if (n != 4) {
                    do {
                        if (++i >= 4) {
                            break;
                        }
                        *p-- = *q++;
                    } while (i + 4 != n);
                }
            }
        }
    } else {
        goto err;
    }
    goto end;
    do {
err:
        ret = 0x2724;
    } while (0);
end:
    return ret;
}
/* localdecomp:end func_L39_004F02A0 */

/* localdecomp:start func_L39_004F0A78 */
typedef struct {
    s32 val;
    s32 width;
    s8 sep;
} F_004F0A78;

typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004F0A78;

typedef struct {
    u8 pad[0x1C8];
    s32 days[2][13];
} C_004F0A78;

typedef struct {
    s32 f0;
    s32 f4;
    u32 hi;
    u32 lo;
    s32 ns;
} T_004F0A78;

typedef struct {
    F_004F0A78 f[10];
} FA_004F0A78;

extern FA_004F0A78 D_L39_00478C68;
extern u8 D_001B3331[];

extern void *func_L39_004DBA08(void);
extern BN_004F0A78 *func_L39_004FC380(void);
extern s32 func_L39_004F1230(u8 *, u32, F_004F0A78 *, s32);
extern s32 func_L39_004FC6F8(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD228(BN_004F0A78 *, unsigned long);
extern BN_004F0A78 *func_L39_004FC580(BN_004F0A78 *);
extern s32 func_L39_004FD500(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FD678(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD2D0(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FB9A0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FBDA0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FD3B0(BN_004F0A78 *, unsigned long);
extern void func_L39_004FC370(BN_004F0A78 *);
extern BN_004F0A78 *func_L39_004FC5C0(BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FCA98(BN_004F0A78 *, s32);
extern s32 func_L39_004FC158(BN_004F0A78 *);
extern s32 func_L39_004FC8C0(BN_004F0A78 *, u8 *);
extern void func_L39_004FC228(BN_004F0A78 *);
extern s32 func_L39_004F1498(T_004F0A78 *, T_004F0A78 *, long);

s32 func_L39_004F0A78(T_004F0A78 *out, s32 type, u8 *data, u32 len) {
    s32 ret;
    s32 frac;
    s32 tzh;
    s32 tzm;
    s32 tzs;
    C_004F0A78 *ctx;
    u32 *t;

    frac = 0;
    ctx = func_L39_004DBA08();
    ret = 0;
    tzh = 0;
    tzm = 0;
    tzs = 0;

    if (data == 0 || out == 0) {
        ret = 0x2721;
        goto end;
    }
    t = &out->hi;
    if (type == 1 || type == 2 || type == 6) {
        s32 notleap = 0;
        FA_004F0A78 fa = D_L39_00478C68;
        BN_004F0A78 *bn;
        BN_004F0A78 *bn2;
        BN_004F0A78 tmp;
        u8 buf[8];
        s32 n;
        s32 year, month, day, hour, min, sec;
        s32 c;
        s32 leap;

        bn = func_L39_004FC380();
        if (bn == 0) {
            ret = 0x2715;
            goto end;
        }
        if (type == 2) {
            fa.f[0].width = 4;
            fa.f[6].width = 1;
        } else if (type == 6) {
            fa.f[0].width = 4;
            fa.f[1].sep = fa.f[2].sep = fa.f[3].sep = fa.f[4].sep = fa.f[5].sep = ':';
        }
        n = func_L39_004F1230(data, len, fa.f, 10);
        year = fa.f[0].val;
        month = fa.f[1].val;
        day = fa.f[2].val;
        hour = fa.f[3].val;
        min = fa.f[4].val;
        sec = fa.f[5].val;
        c = fa.f[6].sep;
        if (type == 1) {
            if (n < 5) {
                ret = 0x2726;
                goto end;
            }
            if (year < 50) {
                year += 100;
            }
            year += 1900;
            if (n == 5) {
                sec = 0;
                c = fa.f[5].sep;
            } else if (n == 7) {
                tzs = fa.f[5].sep;
                tzh = sec;
                tzm = fa.f[6].val;
            } else if (n == 8) {
                tzh = fa.f[6].val;
                tzs = c;
                tzm = fa.f[7].val;
            }
            func_L39_004FC6F8(bn, year);
        } else if (type == 6) {
            if (n != 6) {
                ret = 0x2724;
                goto end;
            }
            c = 'Z';
            func_L39_004FC6F8(bn, year);
        } else {
            if (n < 7) {
                ret = 0x2724;
                goto end;
            }
            frac = fa.f[6].val;
            c = fa.f[7].sep;
            if (n == 9) {
                tzh = fa.f[7].val;
                tzs = c;
                tzm = fa.f[8].val;
            }
            func_L39_004FC6F8(bn, year);
        }
        leap = 0;
        if (func_L39_004FD228(bn, 400) == 0 || (func_L39_004FD228(bn, 4) == 0 && func_L39_004FD228(bn, 100) != 0)) {
            leap = 1;
        } else {
            notleap = bn->neg == 0;
        }
        if (month > 12) {
            ret = 0x2726;
            goto end;
        }
        if (ctx->days[leap][month] < ctx->days[leap][month - 1] + day) {
            ret = 0x2726;
            goto end;
        }
        if (hour > 23 || min > 59 || sec > 60 || tzh > 12 || tzm > 59) {
            ret = 0x2726;
            goto end;
        }
        if (tzs != '+' && tzs != '-') {
            s32 u = (D_001B3331[c] & 2) ? c - 0x20 : c;
            if (u != 'Z') {
                ret = 0x2726;
                goto end;
            }
        }
        if (sec == 60) {
            sec = 59;
        }
        bn2 = func_L39_004FC580(bn);
        if (bn2 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD500(bn, 1970);
        if (bn->neg == 0) {
            func_L39_004FD500(bn2, 1);
        }
        func_L39_004FD678(bn, 365);
        func_L39_004FD2D0(bn2, 4);
        func_L39_004FB9A0(bn, bn, bn2);
        func_L39_004FD2D0(bn2, 25);
        func_L39_004FBDA0(bn, bn, bn2);
        func_L39_004FD2D0(bn2, 4);
        func_L39_004FB9A0(bn, bn, bn2);
        func_L39_004FD500(bn, 477);
        if (notleap && bn->neg != 0) {
            func_L39_004FD3B0(bn, 1);
        }
        func_L39_004FD3B0(bn, ctx->days[leap][month - 1]);
        func_L39_004FD3B0(bn, day - 1);
        func_L39_004FD678(bn, 24);
        func_L39_004FD3B0(bn, hour);
        func_L39_004FD678(bn, 60);
        func_L39_004FD3B0(bn, min);
        func_L39_004FD678(bn, 60);
        func_L39_004FD3B0(bn, sec);
        func_L39_004FC370(&tmp);
        func_L39_004FC5C0(&tmp, bn);
        func_L39_004FCA98(&tmp, 0x40);
        buf[0] = buf[1] = buf[2] = buf[3] = 0;
        buf[4] = buf[5] = buf[6] = buf[7] = 0;
        func_L39_004FC8C0(&tmp, &buf[8 - (func_L39_004FC158(&tmp) + 7) / 8]);
        func_L39_004FC228(&tmp);
        t[1] = (unsigned long)buf[7] | ((unsigned long)buf[6] << 8) | ((unsigned long)buf[5] << 16) | ((unsigned long)buf[4] << 24);
        t[0] = (unsigned long)buf[3] | ((unsigned long)buf[2] << 8) | ((unsigned long)buf[1] << 16) | ((unsigned long)buf[0] << 24);
        if (bn->neg != 0) {
            t[0] = ~t[0];
            t[1] = ~t[1] + 1;
            if (t[1] == 0) {
                t[0]++;
            }
        }
        t[2] = frac * 100000000;
        func_L39_004FC228(bn);
        func_L39_004FC228(bn2);
        {
            s32 off = (tzh * 60 + tzm) * 60;
            if (tzs == '+') {
                off = -off;
            }
            func_L39_004F1498(out, out, off * 1000);
        }
    } else if (type == 3) {
        u8 *p;
        u8 *q;
        u32 i;

        if (len > 8) {
            ret = 0x2726;
            goto end;
        }
        t[2] = 0;
        t[1] = 0;
        t[0] = 0;
        p = data + len - 1;
        q = (u8 *)&t[1];
        *q++ = *p--;
        i = 0;
        if (p >= data) {
            do {
                if (++i >= 4) {
                    break;
                }
                *q++ = *p--;
            } while (p >= data);
        }
        if (p >= data) {
            q = (u8 *)&t[0];
            *q++ = *p--;
            i = 0;
            if (p >= data) {
                do {
                    if (++i >= 4) {
                        break;
                    }
                    *q++ = *p--;
                } while (p >= data);
            }
        }
    } else {
        ret = 0x2724;
        goto end;
    }
end:
    return ret;
}
/* localdecomp:end func_L39_004F0A78 */

/* localdecomp:start func_L39_004F1230 */
s32 func_L39_004F1230(u8 *data, u32 len, F_004F0A78 *f, s32 n) {
    s32 i;
    s32 pos;
    s32 c;
    s32 k;

    pos = 0;
    for (i = 0; i < n && pos < (s32)len && (c = (s8)data[pos++]) != 0; i++) {
        if (!(D_001B3331[c] & 4)) {
            if (f[i].sep != 0 && f[i].sep != c) {
                goto end;
            }
            f[i].sep = c;
            k = 0;
            f[i].val = 0;
        } else {
            f[i].val = c - '0';
            k = 1;
        }
        while (k < f[i].width) {
            if (pos >= (s32)len) {
                goto end;
            }
            c = (s8)data[pos++];
            if (c == 0) {
                goto end;
            }
            if (!(D_001B3331[c] & 4)) {
                goto end;
            }
            k++;
            f[i].val = f[i].val * 10 + (c - '0');
        }
    }
end:
    return i;
}
/* localdecomp:end func_L39_004F1230 */

/* localdecomp:start func_L39_004F1358 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F1358;

extern void *func_L39_004DBA08(void);

s32 func_L39_004F1358(T_004F0A78 *dst, T_004F0A78 *src, s32 nsec, s32 secs) {
    s32 r = 0;
    s32 carry = 0;
    void *ctx = func_L39_004DBA08();
    V_004F1358 *s;
    V_004F1358 *d;
    s32 ns;
    s32 sec;
    u32 n;
    u32 os;
    s32 adj;

    if (dst == 0) {
        r = 0x2721;
    } else {
        s = (src == 0) ? (V_004F1358 *)((u8 *)ctx + 0x230) : (V_004F1358 *)&src->hi;
        d = (V_004F1358 *)&dst->hi;
        ns = nsec;
        sec = secs;
        if (s->hi < 0) {
            ns = -ns;
        }
        if (ns < 0 && s->ns < (u32)-ns) {
            sec--;
            adj = ns + 1000000000;
            d->ns = s->ns + adj;
        } else {
            n = s->ns + ns;
            d->ns = n;
            if (n > 999999999) {
                sec++;
                d->ns = n - 1000000000;
            }
        }
        os = s->lo;
        d->lo = os + sec;
        if (sec > 0 && d->lo < os) {
            carry = 1;
        } else if (sec < 0) {
            carry = (os < d->lo) ? -1 : 0;
        }
        d->hi = s->hi + carry;
    }
    return r;
}
/* localdecomp:end func_L39_004F1358 */

/* localdecomp:start func_L39_004F1498 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F1498;

extern void *func_L39_004DBA08(void);
extern long func_00130090(long, long);
extern long func_0012E840(long, long);

s32 func_L39_004F1498(T_004F0A78 *dst, T_004F0A78 *src, long ms) {
    s32 r = 0;
    s32 carry = 0;
    void *ctx = func_L39_004DBA08();
    V_004F1498 *s;
    V_004F1498 *d;
    s32 ns, sec;
    u32 n;
    u32 os;
    s32 adj;

    if (dst == 0) {
        r = 0x2721;
    } else {
        s = (src == 0) ? (V_004F1498 *)((u8 *)ctx + 0x230) : (V_004F1498 *)&src->hi;
        d = (V_004F1498 *)&dst->hi;
        ns = func_00130090(ms, 1000) * 1000000;
        sec = func_0012E840(ms, 1000);
        if (s->hi < 0) {
            ns = -ns;
        }
        if (ns < 0 && s->ns < (u32)-ns) {
            sec--;
            adj = ns + 1000000000;
            d->ns = s->ns + adj;
        } else {
            n = s->ns + ns;
            d->ns = n;
            if (n > 999999999) {
                sec++;
                d->ns = n - 1000000000;
            }
        }
        os = s->lo;
        d->lo = os + sec;
        if (sec > 0 && d->lo < os) {
            carry = 1;
        } else if (sec < 0) {
            carry = (os < d->lo) ? -1 : 0;
        }
        d->hi = s->hi + carry;
    }
    return r;
}
/* localdecomp:end func_L39_004F1498 */

/* localdecomp:start func_L39_004F1608 */
extern s32 func_L39_004ECA10(void);

s32 func_L39_004F1608(T_004F0A78 *t) {
    s32 r = 0;
    long now;

    if (t == 0) {
        r = 0x2721;
    } else {
        now = func_L39_004ECA10();
        if (now == -1) {
            r = 0x2723;
        } else {
            t->lo = now;
            t->ns = 0;
            t->hi = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_004F1608 */
