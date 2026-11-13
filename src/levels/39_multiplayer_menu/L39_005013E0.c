#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* localdecomp:start func_L39_005013E0 */
typedef struct ASN1_CTX_005013E0 {
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
} ASN1_CTX_005013E0;

typedef struct ASN1_STRING_005013E0 {
    s32 length;
    s32 type;
    u8 *data;
} ASN1_STRING_005013E0;

typedef struct DSA_005013E0 {
    s32 pad0;
    s32 version;
    s32 write_params;
    void *p;
    void *q;
    void *g;
} DSA_005013E0;

extern DSA_005013E0 *func_L39_004DD808(void);
extern s32 func_L39_004FA2A8(ASN1_CTX_005013E0 *, s64 *);
extern void *func_L39_004F94F0(ASN1_STRING_005013E0 **, u8 **, s64);
extern void *func_L39_004FC780(u8 *, s32, void *);
extern void func_L39_004FA4E8(ASN1_STRING_005013E0 *);
extern s32 func_L39_004FA228(ASN1_CTX_005013E0 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004DDA88(DSA_005013E0 *);

/* OpenSSL's d2i_DSAparams */
DSA_005013E0 *func_L39_005013E0(DSA_005013E0 **a, u8 **pp, s64 length) {
    s32 i = 4;
    ASN1_STRING_005013E0 *bs = 0;
    DSA_005013E0 *ret = 0;
    ASN1_CTX_005013E0 c;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004DD808()) == 0) {
            c.line = 0x25;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + length;
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x28;
        goto err;
    }
    c.q = c.p;
    if (func_L39_004F94F0(&bs, &c.p, c.slen) == 0) {
        c.line = 0x29;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if ((ret->p = func_L39_004FC780(bs->data, bs->length, ret->p)) == 0) goto err_bn;
    c.q = c.p;
    if (func_L39_004F94F0(&bs, &c.p, c.slen) == 0) {
        c.line = 0x2B;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if ((ret->q = func_L39_004FC780(bs->data, bs->length, ret->q)) == 0) goto err_bn;
    c.q = c.p;
    if (func_L39_004F94F0(&bs, &c.p, c.slen) == 0) {
        c.line = 0x2D;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if ((ret->g = func_L39_004FC780(bs->data, bs->length, ret->g)) == 0) goto err_bn;
    func_L39_004FA4E8(bs);
    if (!func_L39_004FA228(&c)) {
        c.line = 0x32;
        goto err;
    }
    *pp = c.p;
    if (a != 0) *a = ret;
    return ret;
err_bn:
    i = 0x803;
err:
    func_L39_004BC6C8(0xD, 0x89, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret)) func_L39_004DDA88(ret);
    if (bs != 0) func_L39_004FA4E8(bs);
    return 0;
}
/* localdecomp:end func_L39_005013E0 */

/* localdecomp:start func_L39_00501658 */
typedef struct S_00501658 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_00501658;

extern S_00501658 *func_L39_004E10B0(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004E1160(s32);
extern s32 func_L39_00505AE8(s32, s32, s32);
extern s32 func_L39_005017A0(s32, s32, s32);
extern void func_L39_004E1200(S_00501658 *);

S_00501658 *func_L39_00501658(s32 arg0, S_00501658 **arg1, s32 arg2, s32 arg3) {
    S_00501658 *p;
    s32 r;

    if (arg1 != 0 && *arg1 != 0) {
        p = *arg1;
    } else {
        p = func_L39_004E10B0();
        if (p == 0) {
            func_L39_004BC6C8(0xD, 0x9C, 0x806, 0, 0);
            return 0;
        }
    }
    p->f4 = arg0;
    p->f0 = func_L39_004E1160(arg0);
    switch (p->f0) {
    case 6:
        r = func_L39_00505AE8(0, arg2, arg3);
        p->fC = r;
        break;
    case 0x74:
        r = func_L39_005017A0(0, arg2, arg3);
        p->fC = r;
        break;
    default:
        func_L39_004BC6C8(0xD, 0x9C, 0x8F, 0, 0);
        goto fail;
    }
    if (r == 0) {
        func_L39_004BC6C8(0xD, 0x9C, 0x80D, 0, 0);
        goto fail;
    }
    if (arg1 != 0) {
        *arg1 = p;
    }
    return p;
fail:
    if (arg1 == 0 || *arg1 != p) {
        func_L39_004E1200(p);
    }
    return 0;
}
/* localdecomp:end func_L39_00501658 */

INCLUDE_ASM("asm/levels", func_L39_005017A0);

/* localdecomp:start func_L39_00501B08 */
typedef struct S_00501B08 {
    u8 pad[0x240];
    u64 sp[8][64];
} S_00501B08;

extern S_00501B08 *func_L39_004DBA08(void);

/* OpenSSL's DES_encrypt1 (DES_LONG is 64-bit here) */
void func_L39_00501B08(u64 *data, u64 *ks, s32 enc) {
    u64 l, r, tt, u, t;
    u64 *s;
    s32 i;

    l = data[0];
    r = data[1];
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    l = ((l >> 29) + (l << 3)) & 0xFFFFFFFF;
    r = ((r >> 29) + (r << 3)) & 0xFFFFFFFF;
    if (enc) {
        s = ks;
        for (i = 0; i < 32; i += 8) {
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = l ^ s[0];
        t = l ^ s[1];
        t = (t >> 4) + (t << 28);
        r ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = r ^ s[2];
        t = r ^ s[3];
        t = (t >> 4) + (t << 28);
        l ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = l ^ s[4];
        t = l ^ s[5];
        t = (t >> 4) + (t << 28);
        r ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = r ^ s[6];
        t = r ^ s[7];
        t = (t >> 4) + (t << 28);
        l ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
            s += 8;
        }
    } else {
        s = ks + 30;
        for (i = 30; i > 0; i -= 8) {
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = l ^ s[0];
        t = l ^ s[1];
        t = (t >> 4) + (t << 28);
        r ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = r ^ s[-2];
        t = r ^ s[-1];
        t = (t >> 4) + (t << 28);
        l ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = l ^ s[-4];
        t = l ^ s[-3];
        t = (t >> 4) + (t << 28);
        r ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
        {
        S_00501B08 *sp = func_L39_004DBA08();
        u = r ^ s[-6];
        t = r ^ s[-5];
        t = (t >> 4) + (t << 28);
        l ^= sp->sp[0][(s32)((u >> 2) & 0x3F)] ^ sp->sp[2][(s32)((u >> 10) & 0x3F)] ^ sp->sp[4][(s32)((u >> 18) & 0x3F)] ^ sp->sp[6][(s32)((u >> 26) & 0x3F)]
            ^ sp->sp[1][(s32)((t >> 2) & 0x3F)] ^ sp->sp[3][(s32)((t >> 10) & 0x3F)] ^ sp->sp[5][(s32)((t >> 18) & 0x3F)] ^ sp->sp[7][(s32)((t >> 26) & 0x3F)];
        }
            s -= 8;
        }
    }
    r = ((r >> 3) + (r << 29)) & 0xFFFFFFFF;
    l = ((l >> 3) + (l << 29)) & 0xFFFFFFFF;
    tt = ((l >> 1) ^ r) & 0x55555555; r ^= tt; l ^= tt << 1;
    tt = ((r >> 8) ^ l) & 0x00FF00FF; l ^= tt; r ^= tt << 8;
    tt = ((l >> 2) ^ r) & 0x33333333; r ^= tt; l ^= tt << 2;
    tt = ((r >> 16) ^ l) & 0x0000FFFF; l ^= tt; r ^= tt << 16;
    tt = ((l >> 4) ^ r) & 0x0F0F0F0F; r ^= tt; l ^= tt << 4;
    data[0] = r;
    data[1] = l;
}
/* localdecomp:end func_L39_00501B08 */

/* localdecomp:start func_L39_00502618 */
/* OpenSSL's DES_encrypt1 (DES_LONG is 64-bit here, SP tables via a global accessor) */
/* uses the file's S_00501B08 (same layout) and its func_L39_004DBA08 declaration */
void func_L39_00502618(u64 *data, void *ks, s32 enc) {
    u64 l, r, u, t;
    s32 i;
    u64 *s = ks;

    r = data[0];
    l = data[1];
    r = ((r >> 29) + (r << 3)) & 0xffffffffL;
    l = ((l >> 29) + (l << 3)) & 0xffffffffL;
    if (enc) {
        for (i = 0; i < 32; i += 8) {
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = r ^ s[i + 0];
                t = r ^ s[i + 0 + 1];
                t = (t >> 4) + (t << 28);
                l ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = l ^ s[i + 2];
                t = l ^ s[i + 2 + 1];
                t = (t >> 4) + (t << 28);
                r ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = r ^ s[i + 4];
                t = r ^ s[i + 4 + 1];
                t = (t >> 4) + (t << 28);
                l ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = l ^ s[i + 6];
                t = l ^ s[i + 6 + 1];
                t = (t >> 4) + (t << 28);
                r ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
        }
    } else {
        for (i = 30; i > 0; i -= 8) {
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = r ^ s[i - 0];
                t = r ^ s[i - 0 + 1];
                t = (t >> 4) + (t << 28);
                l ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = l ^ s[i - 2];
                t = l ^ s[i - 2 + 1];
                t = (t >> 4) + (t << 28);
                r ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = r ^ s[i - 4];
                t = r ^ s[i - 4 + 1];
                t = (t >> 4) + (t << 28);
                l ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
            {
                S_00501B08 *g = func_L39_004DBA08();
                u = l ^ s[i - 6];
                t = l ^ s[i - 6 + 1];
                t = (t >> 4) + (t << 28);
                r ^= g->sp[0][(u >> 2) & 0x3f] ^ g->sp[2][(u >> 10) & 0x3f] ^ g->sp[4][(u >> 18) & 0x3f] ^ g->sp[6][(u >> 26) & 0x3f]
                    ^ g->sp[1][(t >> 2) & 0x3f] ^ g->sp[3][(t >> 10) & 0x3f] ^ g->sp[5][(t >> 18) & 0x3f] ^ g->sp[7][(t >> 26) & 0x3f];
            }
        }
    }
    data[0] = ((l >> 3) + (l << 29)) & 0xffffffffL;
    data[1] = ((r >> 3) + (r << 29)) & 0xffffffffL;
}
/* localdecomp:end func_L39_00502618 */

/* localdecomp:start func_L39_00502FF8 */
extern void func_L39_00502618(u64 *, void *, s32);

/* OpenSSL's DES_encrypt3 (DES_LONG is 64-bit here) */
void func_L39_00502FF8(u64 *data, void *ks1, void *ks2, void *ks3) {
    u64 l, r, tt;

    l = data[0];
    r = data[1];
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    data[0] = l;
    data[1] = r;
    func_L39_00502618(data, ks1, 1);
    func_L39_00502618(data, ks2, 0);
    func_L39_00502618(data, ks3, 1);
    l = data[0];
    r = data[1];
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    data[0] = l;
    data[1] = r;
}
/* localdecomp:end func_L39_00502FF8 */

/* localdecomp:start func_L39_005031A8 */
extern void func_L39_00502618(u64 *, void *, s32);

/* OpenSSL's DES_decrypt3 (DES_LONG is 64-bit here) */
void func_L39_005031A8(u64 *data, void *ks1, void *ks2, void *ks3) {
    u64 l, r, tt;

    l = data[0];
    r = data[1];
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    data[0] = l;
    data[1] = r;
    func_L39_00502618(data, ks3, 0);
    func_L39_00502618(data, ks2, 1);
    func_L39_00502618(data, ks1, 0);
    l = data[0];
    r = data[1];
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    data[0] = l;
    data[1] = r;
}
/* localdecomp:end func_L39_005031A8 */

/* localdecomp:start func_L39_00503360 */
/* Log: DES_ncbc_encrypt, from OpenSSL/libdes (DES_LONG is u64 here).
 * First draft (in/out as params): 119 diff. Local in/out copied from input/output
 * params (libdes style) -> 12 diff (only $t5/$t6 temp swap). Declaration order of the
 * locals (in,out first, then tin, xor, tout) -> MATCH. ee29 file: permuter unavailable. */
extern void func_L39_00501B08(u64 *, u64 *, s32);

/* OpenSSL's DES_ncbc_encrypt (DES_LONG is 64-bit here) */
void func_L39_00503360(u8 *input, u8 *output, long length, void *schedule, u8 *ivec, s32 enc) {
    u8 *in, *out;
    u64 tin0, tin1;
    u64 xor0, xor1;
    u64 tout0, tout1;
    long l = length;
    u64 tin[2];
    u8 *iv;

    in = input;
    out = output;
    iv = ivec;
    if (enc) {
        tout0 = *iv++;
        tout0 |= (u64)*iv++ << 8;
        tout0 |= (u64)*iv++ << 16;
        tout0 |= (u64)*iv++ << 24;
        tout1 = *iv++;
        tout1 |= (u64)*iv++ << 8;
        tout1 |= (u64)*iv++ << 16;
        tout1 |= (u64)*iv++ << 24;
        for (l -= 8; l >= 0; l -= 8) {
            tin0 = *in++;
            tin0 |= (u64)*in++ << 8;
            tin0 |= (u64)*in++ << 16;
            tin0 |= (u64)*in++ << 24;
            tin1 = *in++;
            tin1 |= (u64)*in++ << 8;
            tin1 |= (u64)*in++ << 16;
            tin1 |= (u64)*in++ << 24;
            tin0 ^= tout0;
            tin[0] = tin0;
            tin1 ^= tout1;
            tin[1] = tin1;
            func_L39_00501B08(tin, schedule, 1);
            tout0 = tin[0];
            *out++ = (u8)(tout0 & 0xff);
            *out++ = (u8)((tout0 >> 8) & 0xff);
            *out++ = (u8)((tout0 >> 16) & 0xff);
            *out++ = (u8)((tout0 >> 24) & 0xff);
            tout1 = tin[1];
            *out++ = (u8)(tout1 & 0xff);
            *out++ = (u8)((tout1 >> 8) & 0xff);
            *out++ = (u8)((tout1 >> 16) & 0xff);
            *out++ = (u8)((tout1 >> 24) & 0xff);
        }
        if (l != -8) {
            in += l + 8;
            tin0 = tin1 = 0;
            switch (l + 8) {
            case 8: tin1 = (u64)*(--in) << 24;
            case 7: tin1 |= (u64)*(--in) << 16;
            case 6: tin1 |= (u64)*(--in) << 8;
            case 5: tin1 |= (u64)*(--in);
            case 4: tin0 = (u64)*(--in) << 24;
            case 3: tin0 |= (u64)*(--in) << 16;
            case 2: tin0 |= (u64)*(--in) << 8;
            case 1: tin0 |= (u64)*(--in);
            }
            tin0 ^= tout0;
            tin[0] = tin0;
            tin1 ^= tout1;
            tin[1] = tin1;
            func_L39_00501B08(tin, schedule, 1);
            tout0 = tin[0];
            *out++ = (u8)(tout0 & 0xff);
            *out++ = (u8)((tout0 >> 8) & 0xff);
            *out++ = (u8)((tout0 >> 16) & 0xff);
            *out++ = (u8)((tout0 >> 24) & 0xff);
            tout1 = tin[1];
            *out++ = (u8)(tout1 & 0xff);
            *out++ = (u8)((tout1 >> 8) & 0xff);
            *out++ = (u8)((tout1 >> 16) & 0xff);
            *out++ = (u8)((tout1 >> 24) & 0xff);
        }
        iv = ivec;
        *iv++ = (u8)(tout0 & 0xff);
        *iv++ = (u8)((tout0 >> 8) & 0xff);
        *iv++ = (u8)((tout0 >> 16) & 0xff);
        *iv++ = (u8)((tout0 >> 24) & 0xff);
        *iv++ = (u8)(tout1 & 0xff);
        *iv++ = (u8)((tout1 >> 8) & 0xff);
        *iv++ = (u8)((tout1 >> 16) & 0xff);
        *iv++ = (u8)((tout1 >> 24) & 0xff);
    } else {
        xor0 = *iv++;
        xor0 |= (u64)*iv++ << 8;
        xor0 |= (u64)*iv++ << 16;
        xor0 |= (u64)*iv++ << 24;
        xor1 = *iv++;
        xor1 |= (u64)*iv++ << 8;
        xor1 |= (u64)*iv++ << 16;
        xor1 |= (u64)*iv++ << 24;
        for (l -= 8; l >= 0; l -= 8) {
            tin0 = *in++;
            tin0 |= (u64)*in++ << 8;
            tin0 |= (u64)*in++ << 16;
            tin0 |= (u64)*in++ << 24;
            tin[0] = tin0;
            tin1 = *in++;
            tin1 |= (u64)*in++ << 8;
            tin1 |= (u64)*in++ << 16;
            tin1 |= (u64)*in++ << 24;
            tin[1] = tin1;
            func_L39_00501B08(tin, schedule, 0);
            tout0 = tin[0] ^ xor0;
            tout1 = tin[1] ^ xor1;
            *out++ = (u8)(tout0 & 0xff);
            *out++ = (u8)((tout0 >> 8) & 0xff);
            *out++ = (u8)((tout0 >> 16) & 0xff);
            *out++ = (u8)((tout0 >> 24) & 0xff);
            *out++ = (u8)(tout1 & 0xff);
            *out++ = (u8)((tout1 >> 8) & 0xff);
            *out++ = (u8)((tout1 >> 16) & 0xff);
            *out++ = (u8)((tout1 >> 24) & 0xff);
            xor0 = tin0;
            xor1 = tin1;
        }
        if (l != -8) {
            tin0 = *in++;
            tin0 |= (u64)*in++ << 8;
            tin0 |= (u64)*in++ << 16;
            tin0 |= (u64)*in++ << 24;
            tin[0] = tin0;
            tin1 = *in++;
            tin1 |= (u64)*in++ << 8;
            tin1 |= (u64)*in++ << 16;
            tin1 |= (u64)*in++ << 24;
            tin[1] = tin1;
            func_L39_00501B08(tin, schedule, 0);
            tout0 = tin[0] ^ xor0;
            tout1 = tin[1] ^ xor1;
            out += l + 8;
            switch (l + 8) {
            case 8: *(--out) = (u8)((tout1 >> 24) & 0xff);
            case 7: *(--out) = (u8)((tout1 >> 16) & 0xff);
            case 6: *(--out) = (u8)((tout1 >> 8) & 0xff);
            case 5: *(--out) = (u8)(tout1 & 0xff);
            case 4: *(--out) = (u8)((tout0 >> 24) & 0xff);
            case 3: *(--out) = (u8)((tout0 >> 16) & 0xff);
            case 2: *(--out) = (u8)((tout0 >> 8) & 0xff);
            case 1: *(--out) = (u8)(tout0 & 0xff);
            }
            xor0 = tin0;
            xor1 = tin1;
        }
        iv = ivec;
        *iv++ = (u8)(xor0 & 0xff);
        *iv++ = (u8)((xor0 >> 8) & 0xff);
        *iv++ = (u8)((xor0 >> 16) & 0xff);
        *iv++ = (u8)((xor0 >> 24) & 0xff);
        *iv++ = (u8)(xor1 & 0xff);
        *iv++ = (u8)((xor1 >> 8) & 0xff);
        *iv++ = (u8)((xor1 >> 16) & 0xff);
        *iv++ = (u8)((xor1 >> 24) & 0xff);
    }
    tin0 = tin1 = tout0 = tout1 = xor0 = xor1 = 0;
    tin[0] = tin[1] = 0;
}
/* localdecomp:end func_L39_00503360 */

/* localdecomp:start func_L39_00503B20 */
extern void func_L39_00502FF8(u64 *data, void *ks1, void *ks2, void *ks3);
extern void func_L39_005031A8(u64 *data, void *ks1, void *ks2, void *ks3);

/* OpenSSL's DES_ede3_cbc_encrypt (DES_LONG is 64-bit here) */
void func_L39_00503B20(u8 *input, u8 *output, long length, void *ks1, void *ks2, void *ks3, u8 *ivec, s32 enc) {
    u64 tin0, tin1, tout0, tout1, xor0, xor1;
    u8 *in;
    u8 *out;
    u64 tin[2];
    u8 *iv;

    in = input;
    out = output;
    iv = ivec;

    if (enc) {
        tout0 = *(iv++);
        tout0 |= (u64)*(iv++) << 8;
        tout0 |= (u64)*(iv++) << 16;
        tout0 |= (u64)*(iv++) << 24;
        tout1 = *(iv++);
        tout1 |= (u64)*(iv++) << 8;
        tout1 |= (u64)*(iv++) << 16;
        tout1 |= (u64)*(iv++) << 24;
        for (length -= 8; length >= 0; length -= 8) {
            tin0 = *(in++);
            tin0 |= (u64)*(in++) << 8;
            tin0 |= (u64)*(in++) << 16;
            tin0 |= (u64)*(in++) << 24;
            tin1 = *(in++);
            tin1 |= (u64)*(in++) << 8;
            tin1 |= (u64)*(in++) << 16;
            tin1 |= (u64)*(in++) << 24;
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L39_00502FF8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            *(out++) = (u8)(tout0 & 0xff);
            *(out++) = (u8)((tout0 >> 8) & 0xff);
            *(out++) = (u8)((tout0 >> 16) & 0xff);
            *(out++) = (u8)((tout0 >> 24) & 0xff);
            *(out++) = (u8)(tout1 & 0xff);
            *(out++) = (u8)((tout1 >> 8) & 0xff);
            *(out++) = (u8)((tout1 >> 16) & 0xff);
            *(out++) = (u8)((tout1 >> 24) & 0xff);
        }
        if (length != -8) {
            in += length + 8;
            tin0 = tin1 = 0;
            switch (length + 8) {
            case 8: tin1 = (u64)*(--in) << 24;
            case 7: tin1 |= (u64)*(--in) << 16;
            case 6: tin1 |= (u64)*(--in) << 8;
            case 5: tin1 |= *(--in);
            case 4: tin0 = (u64)*(--in) << 24;
            case 3: tin0 |= (u64)*(--in) << 16;
            case 2: tin0 |= (u64)*(--in) << 8;
            case 1: tin0 |= *(--in);
            }
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L39_00502FF8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            *(out++) = (u8)(tout0 & 0xff);
            *(out++) = (u8)((tout0 >> 8) & 0xff);
            *(out++) = (u8)((tout0 >> 16) & 0xff);
            *(out++) = (u8)((tout0 >> 24) & 0xff);
            *(out++) = (u8)(tout1 & 0xff);
            *(out++) = (u8)((tout1 >> 8) & 0xff);
            *(out++) = (u8)((tout1 >> 16) & 0xff);
            *(out++) = (u8)((tout1 >> 24) & 0xff);
        }
        iv = ivec;
        *(iv++) = (u8)(tout0 & 0xff);
        *(iv++) = (u8)((tout0 >> 8) & 0xff);
        *(iv++) = (u8)((tout0 >> 16) & 0xff);
        *(iv++) = (u8)((tout0 >> 24) & 0xff);
        *(iv++) = (u8)(tout1 & 0xff);
        *(iv++) = (u8)((tout1 >> 8) & 0xff);
        *(iv++) = (u8)((tout1 >> 16) & 0xff);
        *(iv++) = (u8)((tout1 >> 24) & 0xff);
    } else {
        u64 t0, t1;

        xor0 = *(iv++);
        xor0 |= (u64)*(iv++) << 8;
        xor0 |= (u64)*(iv++) << 16;
        xor0 |= (u64)*(iv++) << 24;
        xor1 = *(iv++);
        xor1 |= (u64)*(iv++) << 8;
        xor1 |= (u64)*(iv++) << 16;
        xor1 |= (u64)*(iv++) << 24;
        for (length -= 8; length >= 0; length -= 8) {
            tin0 = *(in++);
            tin0 |= (u64)*(in++) << 8;
            tin0 |= (u64)*(in++) << 16;
            tin0 |= (u64)*(in++) << 24;
            tin1 = *(in++);
            tin1 |= (u64)*(in++) << 8;
            tin1 |= (u64)*(in++) << 16;
            tin1 |= (u64)*(in++) << 24;
            t0 = tin0;
            t1 = tin1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L39_005031A8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            tout0 ^= xor0;
            tout1 ^= xor1;
            *(out++) = (u8)(tout0 & 0xff);
            *(out++) = (u8)((tout0 >> 8) & 0xff);
            *(out++) = (u8)((tout0 >> 16) & 0xff);
            *(out++) = (u8)((tout0 >> 24) & 0xff);
            *(out++) = (u8)(tout1 & 0xff);
            *(out++) = (u8)((tout1 >> 8) & 0xff);
            *(out++) = (u8)((tout1 >> 16) & 0xff);
            *(out++) = (u8)((tout1 >> 24) & 0xff);
            xor0 = t0;
            xor1 = t1;
        }
        if (length != -8) {
            tin0 = *(in++);
            tin0 |= (u64)*(in++) << 8;
            tin0 |= (u64)*(in++) << 16;
            tin0 |= (u64)*(in++) << 24;
            tin1 = *(in++);
            tin1 |= (u64)*(in++) << 8;
            tin1 |= (u64)*(in++) << 16;
            tin1 |= (u64)*(in++) << 24;
            t0 = tin0;
            t1 = tin1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L39_005031A8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            tout0 ^= xor0;
            tout1 ^= xor1;
            out += length + 8;
            switch (length + 8) {
            case 8: *(--out) = (u8)((tout1 >> 24) & 0xff);
            case 7: *(--out) = (u8)((tout1 >> 16) & 0xff);
            case 6: *(--out) = (u8)((tout1 >> 8) & 0xff);
            case 5: *(--out) = (u8)(tout1 & 0xff);
            case 4: *(--out) = (u8)((tout0 >> 24) & 0xff);
            case 3: *(--out) = (u8)((tout0 >> 16) & 0xff);
            case 2: *(--out) = (u8)((tout0 >> 8) & 0xff);
            case 1: *(--out) = (u8)(tout0 & 0xff);
            }
            xor0 = t0;
            xor1 = t1;
        }
        iv = ivec;
        *(iv++) = (u8)(xor0 & 0xff);
        *(iv++) = (u8)((xor0 >> 8) & 0xff);
        *(iv++) = (u8)((xor0 >> 16) & 0xff);
        *(iv++) = (u8)((xor0 >> 24) & 0xff);
        *(iv++) = (u8)(xor1 & 0xff);
        *(iv++) = (u8)((xor1 >> 8) & 0xff);
        *(iv++) = (u8)((xor1 >> 16) & 0xff);
        *(iv++) = (u8)((xor1 >> 24) & 0xff);
    }
    tin[0] = tin[1] = 0;
}
/* localdecomp:end func_L39_00503B20 */

/* localdecomp:start func_L39_005042F8 */
typedef struct S_005042F8 {
    s32 f0;
    s32 f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
} S_005042F8;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void *func_L39_004E2D20(void);
extern s32 func_L39_004E47A8(void);
extern s32 func_L39_004E5090(void);
extern s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_004E2D68(void *);
extern void func_L39_004E47F8(s32);
extern void func_L39_004BEF28(void *);

S_005042F8 *func_L39_005042F8(s32 arg0) {
    S_005042F8 *ret = 0;
    S_005042F8 *p;

    if (arg0 == 0) {
        func_L39_004BC6C8(5, 0x69, 0xE, 0, 0);
        return 0;
    }
    p = func_L39_004BEED8(0x18);
    if (p == 0) {
        func_L39_004BC6C8(5, 0x69, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x18);
    p->f8 = arg0;
    if ((p->fC = func_L39_004E2D20()) != 0) {
        if ((p->f4 = func_L39_004E47A8()) != 0) {
            p->f10 = 1;
            func_L39_004E48A8(p->f4, 1, 2, 0, func_L39_004E5090(), 0, 0);
            ret = p;
            p = 0;
        }
    }
    if (p != 0) {
        if (p->fC != 0) {
            func_L39_004E2D68(p->fC);
        }
        if (p->f4 != 0) {
            func_L39_004E47F8(p->f4);
        }
        func_L39_004BEF28(p);
    }
    return ret;
}
/* localdecomp:end func_L39_005042F8 */
