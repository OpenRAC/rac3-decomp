#include "common.h"

/* localdecomp:start func_L39_004F3390 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} S_004F3390;
extern S_004F3390 *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004FA480(s32);
extern s32 func_L39_005065C8(void);
extern s32 func_L39_004FAAB0(void);
extern s32 func_L39_004F4390(void);
extern s32 func_L39_004F3BC0(void);

S_004F3390 *func_L39_004F3390(void) {
    S_004F3390 *o = func_L39_004BEED8(0x28);
    if (o == 0) {
        s32 err[12];
        err[11] = 0x76;
        func_L39_004BC6C8(13, 204, 33, 0, 0);
        return 0;
    }
    o->f0 = 0;
    if (!(o->f4 = func_L39_004FA480(2))) return 0;
    if (!(o->f8 = func_L39_005065C8())) return 0;
    if (!(o->fC = func_L39_004FAAB0())) return 0;
    if (!(o->f10 = func_L39_004F4390())) return 0;
    if (!(o->f14 = func_L39_004FAAB0())) return 0;
    if (!(o->f18 = func_L39_004F3BC0())) return 0;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 0;
    return o;
}
/* localdecomp:end func_L39_004F3390 */

/* localdecomp:start func_L39_004F3458 */
/* log: v1 natural C (the shape of the file's other _free functions), against the corrected 0x90-byte entry.
   Callees defined later in the file with struct types not yet defined here are declared unprototyped. */
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
} S_004F3458;
extern void func_L39_004FA4E8(void *);
extern void func_L39_00506630(void *);
extern void func_L39_004FAB48(void *);
extern void func_L39_004F4410();
extern void func_L39_004F3C40();
extern void func_L39_004F38C0();
extern void func_L39_004CC510(void *, void (*)());
extern void func_L39_004BEF28(void *);

void func_L39_004F3458(S_004F3458 *a) {
    if (a == 0) {
        return;
    }
    func_L39_004FA4E8(a->f0);
    func_L39_004FA4E8(a->f4);
    func_L39_00506630(a->f8);
    func_L39_004FAB48(a->fC);
    func_L39_004F4410(a->f10);
    func_L39_004FAB48(a->f14);
    func_L39_004F3C40(a->f18);
    func_L39_004FA4E8(a->f1C);
    func_L39_004FA4E8(a->f20);
    func_L39_004CC510(a->f24, func_L39_004F38C0);
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004F3458 */

/* localdecomp:start func_L39_004F34E8 */
/* X509_EXTENSION, laid out as func_L39_004F3830 (X509_EXTENSION_new) builds it: 0x20 bytes, a long at 0x10 */
typedef struct {
    void *object;
    s16 critical;
    s16 netscape_hack;
    s32 *value;
    s32 pad_c;
    long f10;
    s32 f18;
    s32 f1c;
} S_004F34E8;
extern s32 func_L39_004F97C0(void *, s32 *);
extern s32 func_L39_004F8D78(s32, s32 *);
extern s32 func_L39_004FAC48(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

/* OpenSSL i2d_X509_EXTENSION (a is the X509_EXTENSION that func_L39_004F3830 allocates) */
s32 func_L39_004F34E8(S_004F34E8 *a, s32 *pp) {
    s32 k = 0;
    s32 r = 0, ret = 0;
    s32 *p = 0;

    if (a == 0) return 0;

    p = 0;
    for (;;) {
        if (k) {
            r = (s32)func_L39_004FA1A0(1, ret, 16);
            if (pp == 0) return r;
            p = pp;
            func_L39_004F9FF8(p, 1, ret, 16, 0);
        }
        ret += func_L39_004F97C0(a->object, p);
        if (a->critical || a->netscape_hack)
            ret += func_L39_004F8D78(a->critical, p);
        ret += func_L39_004FAC48(a->value, p);
        if (++k != 1) return r;
    }
}
/* localdecomp:end func_L39_004F34E8 */

INCLUDE_ASM("asm/levels", func_L39_004F35E0);

/* localdecomp:start func_L39_004F3830 */
typedef struct {
    s32 f0;
    s16 f4;
    s16 f6;
    s32 f8;
    s32 pad_c;
    long f10;
    s32 f18;
    s32 f1c;
} S_004F3830;

extern s32 func_L39_004E0A58(s32);

S_004F3830 *func_L39_004F3830(void) {
    S_004F3830 *p = (S_004F3830 *)func_L39_004BEED8(32);
    if (p == 0) {
        s32 err[12];
        err[11] = 0x56;
        func_L39_004BC6C8(13, 208, 33, 0, 0);
        return 0;
    }
    p->f0 = func_L39_004E0A58(0);
    p->f8 = func_L39_004FA480(4);
    if (p->f8 == 0) {
        return 0;
    }
    p->f4 = 0;
    p->f6 = 0;
    p->f10 = 0;
    p->f18 = 0;
    p->f1c = 0;
    return p;
}
/* localdecomp:end func_L39_004F3830 */

/* localdecomp:start func_L39_004F38C0 */
typedef struct {
    void *f0;
    s32 f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    void (*f1C)(void *);
} S_004F38C0;
extern void func_L39_004F9A88(void *);
extern void func_L39_004FA4E8(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004F38C0(S_004F38C0 *a) {
    if (a == 0) {
        return;
    }
    if (a->f18 != 0 && a->f1C != 0) {
        a->f1C(a);
    }
    func_L39_004F9A88(a->f0);
    func_L39_004FA4E8(a->f8);
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004F38C0 */

/* localdecomp:start func_L39_004F3928 */
typedef struct { s32 *f0; s32 *f4; } S_004F3928;
extern s32 func_L39_00506300(s32 *, s32 *);
extern s32 func_L39_004F8A78(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

void *func_L39_004F3928(S_004F3928 *arg0, s32 *arg1) {
    s32 tmp;
    s32 size;
    void *result;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_00506300(arg0->f0, 0);
    size += func_L39_004F8A78(arg0->f4, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_00506300(arg0->f0, &tmp);
    func_L39_004F8A78(arg0->f4, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F3928 */

/* localdecomp:start func_L39_004F39F0 */
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
} ASN1_CTX_004F39F0;
typedef struct {
    void *f0;
    void *f4;
    void *f8;
} S_004F39F0;
struct ASN1_CTX_004F3E90;
extern s32 func_L39_004FA2A8(struct ASN1_CTX_004F3E90 *, s64 *);
extern void *func_L39_005063D0(void **, u8 **, s64);
extern void *func_L39_004F8B88(void **, u8 **, s64);
extern void func_L39_004E1200(); /* prototyped later in the file (func_L39_004F3CA8's block) with its own struct type */
extern s32 func_L39_004FA228(struct ASN1_CTX_004F3E90 *);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_004F3C40(S_004F39F0 *);

/* OpenSSL M_ASN1_D2I_* d2i function */
S_004F39F0 *func_L39_004F39F0(S_004F39F0 **a, u8 **pp, s64 length) {
    ASN1_CTX_004F39F0 c;
    S_004F39F0 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = (S_004F39F0 *)func_L39_004F3BC0()) == 0) {
            c.line = 0x2F;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : (c.p + length);
    if (!func_L39_004FA2A8((struct ASN1_CTX_004F3E90 *)&c, &length)) {
        c.line = 0x32;
        goto err;
    }
    c.q = c.p;
    if (func_L39_005063D0(&ret->f0, &c.p, c.slen) == 0) {
        c.line = 0x33;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004F8B88(&ret->f4, &c.p, c.slen) == 0) {
        c.line = 0x34;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (ret->f8 != 0) {
        func_L39_004E1200(ret->f8);
        ret->f8 = 0;
    }
    if (!func_L39_004FA228((struct ASN1_CTX_004F3E90 *)&c)) {
        c.line = 0x3A;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(13, 0xAA, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004F3C40(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004F39F0 */

/* localdecomp:start func_L39_004F3BC0 */
typedef struct ASN1_CTX_004F3BC0 {
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
} ASN1_CTX_004F3BC0;

typedef struct S_004F3BC0 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_004F3BC0;

s32 func_L39_004F3BC0(void) {
    S_004F3BC0 *ret = 0;
    ASN1_CTX_004F3BC0 c;

    ret = (S_004F3BC0 *)func_L39_004BEED8(12);
    if (ret == 0) {
        c.line = 0x42;
        func_L39_004BC6C8(13, 215, 33, 0, 0);
        return 0;
    }
    if (!(ret->f0 = func_L39_005065C8())) {
        return 0;
    }
    if (!(ret->f4 = func_L39_004FA480(3))) {
        return 0;
    }
    ret->f8 = 0;
    return (s32)ret;
}
/* localdecomp:end func_L39_004F3BC0 */

/* localdecomp:start func_L39_004F3C40 */
extern void func_L39_00506630(void *);

void func_L39_004F3C40(S_004F39F0 *a) {
    if (a == 0) {
        return;
    }
    func_L39_00506630(a->f0);
    func_L39_004FA4E8(a->f4);
    if (a->f8 != 0) {
        func_L39_004E1200(a->f8);
    }
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004F3C40 */

LINKER_REMNANT("asm/levels", func_L39_004F3CA0);

/* localdecomp:start func_L39_004F3CA8 */
typedef struct N_004F3CA8 { u32 f0; struct N_004F3CA8 *f4; struct N_004F3CA8 *f8; } N_004F3CA8;
typedef struct { s32 f0; s32 f4; s32 f8; N_004F3CA8 *fC; s32 f10; } S3_004F3CA8;
typedef struct { N_004F3CA8 *f0; N_004F3CA8 *f4; S3_004F3CA8 *f8; } S4_004F3CA8;
extern s32 func_L39_004E0C88(u32);
extern S3_004F3CA8 *func_L39_00501658(s32, s32, N_004F3CA8 **, u64);
extern s32 func_L39_005013E0(N_004F3CA8 **, N_004F3CA8 **, u64);
extern void func_L39_004E1200(S3_004F3CA8 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

S3_004F3CA8 *func_L39_004F3CA8(S4_004F3CA8 *a0) {
    S3_004F3CA8 *r = 0;
    N_004F3CA8 *p;
    N_004F3CA8 *tmp;
    s32 v;

    if (a0 == 0) {
        goto fail;
    }
    if (a0->f8 != 0) {
        return a0->f8;
    }
    if (a0->f4 == 0) {
        goto fail;
    }
    v = func_L39_004E0C88(a0->f0->f0);
    tmp = a0->f4->f8;
    r = func_L39_00501658(v, 0, &tmp, a0->f4->f0);
    if (r == 0) {
        func_L39_004BC6C8(11, 0xD1, 0x98, 0, 0);
        goto fail;
    }
    r->f10 = 0;
    p = a0->f0;
    if (r->f0 == 0x74) {
        if (p->f4->f0 == 0x10) {
            r->fC->f8 = 0;
            tmp = p->f4->f4->f8;
            if (!func_L39_005013E0(&r->fC, &tmp, p->f4->f4->f0)) {
                goto fail;
            }
        }
        r->f10 = 1;
    }
    a0->f8 = r;
    return r;
fail:
    if (r != 0) {
        func_L39_004E1200(r);
    }
    return 0;
}
/* localdecomp:end func_L39_004F3CA8 */

/* localdecomp:start func_L39_004F3DC8 */
typedef struct { s32 *f0; s32 *f4; } S_004F3DC8;
extern s32 func_L39_00506300(s32 *, s32 *);
extern s32 func_L39_004FAC48(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

void *func_L39_004F3DC8(S_004F3DC8 *arg0, s32 *arg1) {
    void *result;
    s32 size;
    s32 tmp;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_00506300(arg0->f0, 0);
    size += func_L39_004FAC48(arg0->f4, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_00506300(arg0->f0, &tmp);
    func_L39_004FAC48(arg0->f4, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F3DC8 */

/* localdecomp:start func_L39_004F3E90 */
typedef struct ASN1_CTX_004F3E90 {
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
} ASN1_CTX_004F3E90;

typedef struct S_004F3E90 {
    void *f0;
    void *f4;
} S_004F3E90;

extern S_004F3E90 *func_L39_004F4048(void);
extern s32 func_L39_004FA2A8(ASN1_CTX_004F3E90 *, s64 *);
extern void *func_L39_005063D0(void **, u8 **, s64);
extern void *func_L39_004FAC68(void **, u8 **, s64);
extern s32 func_L39_004FA228(ASN1_CTX_004F3E90 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_004F40C8(S_004F3E90 *);

/* an OpenSSL d2i_ function built from the M_ASN1_D2I_ macros */
S_004F3E90 *func_L39_004F3E90(S_004F3E90 **a, u8 **pp, s64 length) {
    S_004F3E90 *ret = 0;
    ASN1_CTX_004F3E90 c;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004F4048()) == 0) {
            c.line = 0x29;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + length;
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x2C;
        goto err;
    }
    c.q = c.p;
    if (func_L39_005063D0(&ret->f0, &c.p, c.slen) == 0) {
        c.line = 0x2D;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004FAC68(&ret->f4, &c.p, c.slen) == 0) {
        c.line = 0x2E;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (!func_L39_004FA228(&c)) {
        c.line = 0x2F;
        goto err;
    }
    *pp = c.p;
    if (a != 0) *a = ret;
    return ret;
err:
    func_L39_004BC6C8(0xD, 0xAE, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) func_L39_004F40C8(ret);
    return 0;
}
/* localdecomp:end func_L39_004F3E90 */

/* localdecomp:start func_L39_004F4048 */
S_004F3E90 *func_L39_004F4048(void) {
    S_004F3E90 *p = (S_004F3E90 *)func_L39_004BEED8(8);
    if (p == 0) {
        ASN1_CTX_004F3E90 c;
        c.line = 0x37;
        func_L39_004BC6C8(13, 219, 33, 0, 0);
        return 0;
    }
    if (!(p->f0 = (void *)func_L39_005065C8())) return 0;
    p->f4 = (void *)func_L39_004FA480(4);
    if (p->f4 == 0) {
        p = 0;
    }
    return p;
}
/* localdecomp:end func_L39_004F4048 */

/* localdecomp:start func_L39_004F40C8 */
extern void func_L39_00506630(void *);
extern void func_L39_004FA4E8(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004F40C8(S_004F3E90 *a) {
    if (a == 0) return;
    func_L39_00506630(a->f0);
    func_L39_004FA4E8(a->f4);
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004F40C8 */

/* localdecomp:start func_L39_004F4110 */
typedef struct { s32 *f0; s32 *f4; } S_004F4110;
extern s32 func_L39_004F9B38(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

void *func_L39_004F4110(S_004F4110 *arg0, s32 *arg1) {
    void *result;
    s32 size;
    s32 tmp;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_004F9B38(arg0->f0, 0);
    size += func_L39_004F9B38(arg0->f4, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_004F9B38(arg0->f0, &tmp);
    func_L39_004F9B38(arg0->f4, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F4110 */

/* localdecomp:start func_L39_004F41D8 */
typedef struct {
    void *f0;
    void *f4;
} S_004F41D8;
extern void *func_L39_004F9B58(void **, u8 **, s64);
extern void func_L39_004F4410(S_004F41D8 *);

/* OpenSSL M_ASN1_D2I_* d2i function */
S_004F41D8 *func_L39_004F41D8(S_004F41D8 **a, u8 **pp, s64 length) {
    ASN1_CTX_004F3E90 c;
    S_004F41D8 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = (S_004F41D8 *)func_L39_004F4390()) == 0) {
            c.line = 0x29;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : (c.p + length);
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x2C;
        goto err;
    }
    c.q = c.p;
    if (func_L39_004F9B58(&ret->f0, &c.p, c.slen) == 0) {
        c.line = 0x2D;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004F9B58(&ret->f4, &c.p, c.slen) == 0) {
        c.line = 0x2E;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (!func_L39_004FA228(&c)) {
        c.line = 0x2F;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(13, 0xAF, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004F4410(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004F41D8 */

/* localdecomp:start func_L39_004F4390 */
typedef struct {
    s32 f0;
    s32 f4;
} S_004F4390;

s32 func_L39_004F4390(void) {
    S_004F4390 *p = (S_004F4390 *)func_L39_004BEED8(8);
    if (p == 0) {
        ASN1_CTX_004F3E90 c;
        c.line = 0x37;
        func_L39_004BC6C8(13, 221, 33, 0, 0);
        return 0;
    }
    if (!(p->f0 = func_L39_004FA480(23))) return 0;
    p->f4 = func_L39_004FA480(23);
    if (p->f4 == 0) {
        p = 0;
    }
    return (s32)p;
}
/* localdecomp:end func_L39_004F4390 */

/* localdecomp:start func_L39_004F4410 */
/* log: v1 natural C (the file's S_004F41D8, shape of the file's other _free functions), against the corrected
   0x48-byte entry. */
extern void func_L39_004FA4E8(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004F4410(S_004F41D8 *a) {
    if (a == 0) {
        return;
    }
    func_L39_004FA4E8(a->f0);
    func_L39_004FA4E8(a->f4);
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004F4410 */

LINKER_REMNANT("asm/levels", func_L39_004F4458);

/* localdecomp:start func_L39_004F4460 */
typedef struct { s32 f0; s32 *f4; s32 *f8; s32 *fC; } S_004F4460;
extern s32 func_L39_004F2B50(s32 *, s32 *);

void *func_L39_004F4460(S_004F4460 *arg0, s32 *arg1) {
    void *result;
    s32 size;
    s32 tmp;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_004F2B50(arg0->f4, 0);
    size += func_L39_00506300(arg0->f8, 0);
    size += func_L39_004F8A78(arg0->fC, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_004F2B50(arg0->f4, &tmp);
    func_L39_00506300(arg0->f8, &tmp);
    func_L39_004F8A78(arg0->fC, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F4460 */

/* localdecomp:start func_L39_004F4540 */
typedef struct {
    void *f14_pad[5];
    void *subject;
} S_CINF_004F4540;
typedef struct {
    s32 f0;
    S_CINF_004F4540 *cert_info;
    void *sig_alg;
    void *signature;
    s32 f10;
    s32 f14;
    char *name;
} S_004F4540;
/* X509_new; an alias, as func_L39_004F4760 is defined later in the file under a type not yet declared here */
extern void *func_L39_004F4760_004F4540(void);
extern void *func_L39_004F2DF8(void *, u8 **, s64);
extern char *func_L39_004CC810(void *, char *, s32);
extern void func_L39_004F4818(void *);

/* OpenSSL d2i_X509, built from the M_ASN1_D2I_ macros */
S_004F4540 *func_L39_004F4540(S_004F4540 **a, u8 **pp, s64 length) {
    ASN1_CTX_004F3E90 c;
    S_004F4540 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = (S_004F4540 *)func_L39_004F4760_004F4540()) == 0) {
            c.line = 0x3D;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : (c.p + length);
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x40;
        goto err;
    }
    c.q = c.p;
    if (func_L39_004F2DF8(&ret->cert_info, &c.p, c.slen) == 0) {
        c.line = 0x41;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_005063D0(&ret->sig_alg, &c.p, c.slen) == 0) {
        c.line = 0x42;
        goto err;
    }
    c.slen -= (c.p - c.q);
    c.q = c.p;
    if (func_L39_004F8B88(&ret->signature, &c.p, c.slen) == 0) {
        c.line = 0x43;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (ret->name != 0) {
        func_L39_004BEF28(ret->name);
    }
    ret->name = func_L39_004CC810(ret->cert_info->subject, 0, 0);
    if (!func_L39_004FA228(&c)) {
        c.line = 0x48;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(13, 0x9F, c.error, 0, 0);
    func_L39_004FA538(*pp, c.q - *pp);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004F4818(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004F4540 */

/* localdecomp:start func_L39_004F4760 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} S_004F4760;

S_004F4760 *func_L39_004F4760(void) {
    S_004F4760 *p = (S_004F4760 *)func_L39_004BEED8(0x1C);
    if (p == 0) {
        ASN1_CTX_004F3E90 c;
        c.line = 0x52;
        func_L39_004BC6C8(13, 213, 33, 0, 0);
        return 0;
    }
    p->f0 = 0;
    p->f10 = 0;
    p->f18 = 0;
    p->f14 = 1;
    if (!(p->f4 = (s32)func_L39_004F3390())) return 0;
    if (!(p->f8 = func_L39_005065C8())) return 0;
    p->fC = func_L39_004FA480(3);
    if (p->fC == 0) {
        p = 0;
    }
    return p;
}
/* localdecomp:end func_L39_004F4760 */

INCLUDE_ASM("asm/levels", func_L39_004F47F8);

INCLUDE_ASM("asm/levels", func_L39_004F4818);

/* localdecomp:start func_L39_004F48A0 */
extern s32 D_L39_0046D6B8[];

s32 func_L39_004F48A0(s32 *out) {
    *out = (s32)D_L39_0046D6B8;
    return 0;
}
/* localdecomp:end func_L39_004F48A0 */

INCLUDE_ASM("asm/levels", func_L39_004F48B8);

INCLUDE_ASM("asm/levels", func_L39_004F4AE8);

LINKER_REMNANT("asm/levels", func_L39_004F4B50);

LINKER_REMNANT("asm/levels", func_L39_004F4B58);

LINKER_REMNANT("asm/levels", func_L39_004F4B60);

INCLUDE_ASM("asm/levels", func_L39_004F4B68);

LINKER_REMNANT("asm/levels", func_L39_004F4BD8);

LINKER_REMNANT("asm/levels", func_L39_004F4BE0);

INCLUDE_ASM("asm/levels", func_L39_004F4BE8);

LINKER_REMNANT("asm/levels", func_L39_004F4C68);

/* localdecomp:start func_L39_004F4C70 */
s32 func_L39_004F4C70(void) {
    return 0x21D;
}
/* localdecomp:end func_L39_004F4C70 */

LINKER_REMNANT("asm/levels", func_L39_004F4C78);

LINKER_REMNANT("asm/levels", func_L39_004F4C80);

LINKER_REMNANT("asm/levels", func_L39_004F4C88);

LINKER_REMNANT("asm/levels", func_L39_004F4C90);

INCLUDE_ASM("asm/levels", func_L39_004F4C98);

LINKER_REMNANT("asm/levels", func_L39_004F4D18);

INCLUDE_ASM("asm/levels", func_L39_004F4D20);

LINKER_REMNANT("asm/levels", func_L39_004F4DD8);

INCLUDE_ASM("asm/levels", func_L39_004F4DE0);
