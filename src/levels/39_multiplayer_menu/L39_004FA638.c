#include "common.h"

/* localdecomp:start func_L39_004FA638 */
typedef struct {
    s32 num;
    void **data;
} S_STACK_004FA638;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 set;
    s32 size;
} S_ENTRY_004FA638;

typedef struct {
    s32 length;
    u8 *data;
} S_BUF_004FA638;

typedef struct {
    s32 f0;
    S_STACK_004FA638 *entries;
    s32 modified;
    S_BUF_004FA638 *bytes;
} S_NAME_004FA638;

extern s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag);
extern void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);
extern s32 func_L39_0050A648(S_ENTRY_004FA638 *, u8 **);
extern s32 func_L39_004DB1C0(S_BUF_004FA638 *, s32);

/* OpenSSL i2d_X509_NAME_entries */
s32 func_L39_004FA638(S_NAME_004FA638 *a) {
    S_ENTRY_004FA638 *ne, *fe = 0;
    S_STACK_004FA638 *sk;
    S_BUF_004FA638 *buf;
    s32 set = 0, r, ret = 0;
    s32 i;
    u8 *p;
    s32 size = 0;

    sk = a->entries;
    for (i = 0; i < sk->num; i++) {
        ne = sk->data[i];
        if (fe == 0) {
            fe = ne;
            size = 0;
        }
        if (ne->set != set) {
            ret += func_L39_004FA1A0(1, size, 0x11);
            fe->size = size;
            fe = ne;
            size = 0;
            set = ne->set;
        }
        size += func_L39_0050A648(ne, 0);
    }
    ret += func_L39_004FA1A0(1, size, 0x11);
    if (fe != 0) {
        fe->size = size;
    }
    r = func_L39_004FA1A0(1, ret, 0x10);
    buf = a->bytes;
    if (!func_L39_004DB1C0(buf, r)) {
        goto err;
    }
    p = buf->data;
    func_L39_004F9FF8(&p, 1, ret, 0x10, 0);
    set = -1;
    for (i = 0; i < sk->num; i++) {
        ne = sk->data[i];
        if (set != ne->set) {
            set = ne->set;
            func_L39_004F9FF8(&p, 1, ne->size, 0x11, 0);
        }
        func_L39_0050A648(ne, &p);
    }
    a->modified = 0;
    return r;
err:
    return -1;
}
/* localdecomp:end func_L39_004FA638 */

/* localdecomp:start func_L39_004FA7F8 */
/* OpenSSL d2i_X509_NAME, built from the M_ASN1_D2I_ macros (see func_L39_004F2DF8) */
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
} ASN1_CTX_004FA7F8;

extern S_NAME_004FA638 *func_L39_004FAAB0_004FA7F8(void);
extern void *func_L39_004CC408(S_STACK_004FA638 *);
extern void func_L39_004FAC00(void *);
extern s32 func_L39_004FA2A8(ASN1_CTX_004FA7F8 *, s64 *);
extern void *func_L39_004FADD8(void *, u8 **, s64, void *, void *, s32, s32);
extern s32 func_L39_0050A5A0(u8 **, long);
extern void *func_0011D380(void *, void *, s32);
extern s32 func_L39_004FA228(ASN1_CTX_004FA7F8 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_004FAB48(S_NAME_004FA638 *);
extern u8 D_L39_0050A710[];

void *func_L39_004FA7F8(void *arg0, u8 **pp, s64 length) {
    S_NAME_004FA638 **a = arg0;
    s32 set = 0, i;
    s32 idx = 0;
    u8 *orig;
    ASN1_CTX_004FA7F8 c;
    S_NAME_004FA638 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004FAAB0_004FA7F8()) == 0) {
            c.line = 0xB0;
            goto err;
        }
    } else {
        ret = *a;
    }
    orig = *pp;
    if (ret->entries->num > 0) {
        while (ret->entries->num > 0) {
            func_L39_004FAC00(func_L39_004CC408(ret->entries));
        }
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + (s32)length;
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0xBB;
        goto err;
    }
    for (;;) {
        if (((c.inf & 1) == 0) ? (c.slen <= 0) : (c.eos = func_L39_0050A5A0(&c.p, c.slen))) {
            break;
        }
        c.q = c.p;
        if (func_L39_004FADD8(&ret->entries, &c.p, c.slen, D_L39_0050A710, func_L39_004FAC00, 0x11, 0) == 0) {
            c.line = 0xC0;
            goto err;
        }
        c.slen -= (c.p - c.q);
        for (; idx < ret->entries->num; idx++) {
            ((S_ENTRY_004FA638 *)ret->entries->data[idx])->set = set;
        }
        set++;
    }
    i = (s32)(c.p - orig);
    if (!func_L39_004DB1C0(ret->bytes, i)) {
        goto err;
    }
    func_0011D380(ret->bytes->data, orig, i);
    ret->bytes->length = i;
    ret->modified = 0;
    if (!func_L39_004FA228(&c)) {
        c.line = 0xCF;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(0xD, 0xA7, c.error, 0, 0);
    func_L39_004FA538(*pp, (s32)(c.q - *pp));
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FAB48(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004FA7F8 */

/* localdecomp:start func_L39_004FAAB0 */
typedef struct { s32 a; s32 b; s32 ok; s32 c; } S_004FAAB0;
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004CC228(s32);
extern s32 func_L39_004DB110(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
/* same error-record shape as func_L39_004FB5C8 */
S_004FAAB0 *func_L39_004FAAB0(void) {
    S_004FAAB0 *p;
    s32 err[12];

    p = func_L39_004BEED8(0x18);
    if (p == 0) {
        err[11] = 0xDB;
        goto fail;
    }
    p->a = 0;
    p->b = func_L39_004CC228(0);
    if (p->b == 0) {
        err[11] = 0xDE;
        goto fail;
    }
    p->c = func_L39_004DB110();
    if (p->c == 0) {
        return 0;
    }
    p->ok = 1;
    return p;
fail:
    func_L39_004BC6C8(0xD, 0xD4, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004FAAB0 */

INCLUDE_ASM("asm/levels", func_L39_004FAB48);

/* localdecomp:start func_L39_004FAB88 */
typedef struct ASN1_CTX_004FAB88 {
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
} ASN1_CTX_004FAB88;

typedef struct S_004FAB88 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004FAB88;
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004FA460(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

S_004FAB88 *func_L39_004FAB88(void)
{
    S_004FAB88 *ret = 0;
    ASN1_CTX_004FAB88 c;

    ret = func_L39_004BEED8(0x14);
    if (ret != 0) {
        ret->f0 = 0;
        ret->f4 = 0;
        ret->fC = 0;
        ret->f8 = func_L39_004FA460();
        return ret->f8 ? ret : 0;
    }
    c.line = 0xEE;
    func_L39_004BC6C8(0xD, 0xD3, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004FAB88 */

INCLUDE_ASM("asm/levels", func_L39_004FAC00);
