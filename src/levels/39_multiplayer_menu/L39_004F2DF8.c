#include "common.h"

/* localdecomp:start func_L39_004F2DF8 */
/* an OpenSSL d2i_X509_CINF built from the M_ASN1_D2I_ macros (see func_L39_004F3E90) */
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
} ASN1_CTX_004F2DF8;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} S_ASN1_INT_004F2DF8;

typedef struct {
    s32 num;
} S_STACK_004F2DF8;

typedef struct {
    S_ASN1_INT_004F2DF8 *version;
    void *serialNumber;
    void *signature;
    void *issuer;
    void *validity;
    void *subject;
    void *key;
    void *issuerUID;
    void *subjectUID;
    S_STACK_004F2DF8 *extensions;
} S_004F2DF8;

extern S_004F2DF8 *func_L39_004F3390(void);
extern s32 func_L39_004FA2A8(ASN1_CTX_004F2DF8 *, s64 *);
extern s32 func_L39_004F9E08(u8 **, s64 *, s32 *, s32 *, s64);
extern void *func_L39_004F94F0(void *, u8 **, s64);
extern void func_L39_004FA4E8(void *);
extern void *func_L39_005063D0(void *, u8 **, s64);
extern void *func_L39_004FA7F8(void *, u8 **, s64);
extern void *func_L39_004F41D8(void *, u8 **, s64);
extern void *func_L39_004F39F0(void *, u8 **, s64);
extern void *func_L39_004F8B88(void *, u8 **, s64);
extern void *func_L39_004CC408(S_STACK_004F2DF8 *);
extern void func_L39_004F38C0(void *);
extern u8 D_L39_004F35E0[];
extern void *func_L39_004FADD8(void *, u8 **, s64, void *, void *, s32, s32);
extern s32 func_L39_004FA228(ASN1_CTX_004F2DF8 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_004F3458(S_004F2DF8 *);

S_004F2DF8 *func_L39_004F2DF8(S_004F2DF8 **a, u8 **pp, s64 length) {
    S_004F2DF8 *ret = 0;
    ASN1_CTX_004F2DF8 c;
    s32 ver = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004F3390()) == 0) {
            c.line = 0x3B;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + (s32)length;
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x3E;
        goto err;
    }
    if (*c.p == 0xA0) {
        if (c.slen != 0) {
            s32 Tinf, Ttag, Tclass;
            s64 Tlen;

            c.q = c.p;
            Tinf = func_L39_004F9E08(&c.p, &Tlen, &Ttag, &Tclass, c.slen);
            if ((Tinf & 0x80) || Tlen > c.slen - (c.p - c.q)) {
                c.error = 5;
                c.line = 0x42;
                goto err;
            }
            if (func_L39_004F94F0(&ret->version, &c.p, Tlen) == 0) {
                c.line = 0x42;
                goto err;
            }
            c.slen -= (c.p - c.q);
        }
        if (ret->version->data != 0) {
            ver = ret->version->data[0];
        }
    } else {
        if (ret->version != 0) {
            func_L39_004FA4E8(ret->version);
            ret->version = 0;
        }
    }
    c.q = c.p;
    if (func_L39_004F94F0(&ret->serialNumber, &c.p, c.slen) == 0) {
        c.line = 0x4E;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_005063D0(&ret->signature, &c.p, c.slen) == 0) {
        c.line = 0x4F;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004FA7F8(&ret->issuer, &c.p, c.slen) == 0) {
        c.line = 0x50;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004F41D8(&ret->validity, &c.p, c.slen) == 0) {
        c.line = 0x51;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004FA7F8(&ret->subject, &c.p, c.slen) == 0) {
        c.line = 0x52;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004F39F0(&ret->key, &c.p, c.slen) == 0) {
        c.line = 0x53;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (ver > 0) {
        s32 _tmp;

        if (ret->issuerUID != 0) {
            func_L39_004FA4E8(ret->issuerUID);
            ret->issuerUID = 0;
        }
        if (ret->subjectUID != 0) {
            func_L39_004FA4E8(ret->subjectUID);
            ret->subjectUID = 0;
        }
        if (c.slen != 0) {
            _tmp = *c.p;
            if ((_tmp & 0xDF) == 0x81) {
                *c.p = (_tmp & 0xE0) | 3;
                c.q = c.p;
                if (func_L39_004F8B88(&ret->issuerUID, &c.p, c.slen) == 0) {
                    c.line = 0x61;
                    goto err;
                }
                c.slen -= (c.p - c.q);
                *c.q = _tmp;
            }
        }
        if (c.slen != 0) {
            _tmp = *c.p;
            if ((_tmp & 0xDF) == 0x82) {
                *c.p = (_tmp & 0xE0) | 3;
                c.q = c.p;
                if (func_L39_004F8B88(&ret->subjectUID, &c.p, c.slen) == 0) {
                    c.line = 0x63;
                    goto err;
                }
                c.slen -= (c.p - c.q);
                *c.q = _tmp;
            }
        }
    }
    if (ver >= 2) {
        if (ret->extensions != 0 && ret->extensions->num != 0) {
            do {
                func_L39_004F38C0(func_L39_004CC408(ret->extensions));
            } while (ret->extensions->num != 0);
        }
        if (c.slen != 0 && *c.p == 0xA3) {
            s32 Tinf, Ttag, Tclass;
            s64 Tlen;

            c.q = c.p;
            Tinf = func_L39_004F9E08(&c.p, &Tlen, &Ttag, &Tclass, c.slen);
            if ((Tinf & 0x80) || Tlen > c.slen - (c.p - c.q)) {
                c.error = 5;
                c.line = 0x6C;
                goto err;
            }
            if (func_L39_004FADD8(&ret->extensions, &c.p, Tlen, D_L39_004F35E0, func_L39_004F38C0, 0x10, 0) == 0) {
                c.line = 0x6C;
                goto err;
            }
            c.slen -= (c.p - c.q);
        }
    }
    if (!func_L39_004FA228(&c)) {
        c.line = 0x6E;
        goto err;
    }
    *pp = c.p;
    if (a != 0) *a = ret;
    return ret;
err:
    func_L39_004BC6C8(0xD, 0xA2, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) func_L39_004F3458(ret);
    return 0;
}
/* localdecomp:end func_L39_004F2DF8 */
