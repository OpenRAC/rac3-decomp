#include "common.h"

/* localdecomp:start func_L39_005061D8 */
/* OpenSSL's X509_get_pubkey_parameters (old STACK with num/data fields read directly) */
typedef struct {
    s32 num;
    void **data;
} S_005061D8;
s32 func_L39_004E1060(void *);
void *func_L39_004F18C0(void *);
s32 func_L39_004E0F28(void *, void *);
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
s32 func_L39_005061D8(void *pkey, S_005061D8 *chain) {
    void *ktmp = 0;
    void *ktmp2;
    s32 i, j;

    if (pkey != 0 && !func_L39_004E1060(pkey)) {
        return 1;
    }
    for (i = 0; i < chain->num; i++) {
        ktmp = func_L39_004F18C0(chain->data[i]);
        if (ktmp == 0) {
            func_L39_004BC6C8(0xB, 0xDF, 0xA2, 0, 0);
            return 0;
        }
        if (!func_L39_004E1060(ktmp)) {
            break;
        } else {
            ktmp = 0;
        }
    }
    if (ktmp == 0) {
        func_L39_004BC6C8(0xB, 0xDF, 0xA1, 0, 0);
        return 0;
    }
    for (j = i - 1; j >= 0; j--) {
        ktmp2 = func_L39_004F18C0(chain->data[j]);
        func_L39_004E0F28(ktmp2, ktmp);
    }
    if (pkey != 0) {
        func_L39_004E0F28(pkey, ktmp);
    }
    return 1;
}
/* localdecomp:end func_L39_005061D8 */

/* localdecomp:start func_L39_00506300 */
typedef struct S_00506300 { void *f0; void *f4; } S_00506300;
s32 func_L39_004F97C0(void *, u8 **);
s32 func_L39_004FB050(void *, u8 **);
s32 func_L39_004FA1A0(s32, s32, s32);
void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);

s32 func_L39_00506300(S_00506300 *a, u8 **pp) {
    s32 len;
    s32 ret;
    u8 *p;

    if (a == 0) {
        return 0;
    }
    len = func_L39_004F97C0(a->f0, 0);
    if (a->f4 != 0) {
        len += func_L39_004FB050(a->f4, 0);
    }
    ret = func_L39_004FA1A0(1, len, 16);
    if (pp == 0) {
        return ret;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 1, len, 16, 0);
    func_L39_004F97C0(a->f0, &p);
    if (a->f4 != 0) {
        func_L39_004FB050(a->f4, &p);
    }
    *pp = p;
    return ret;
}
/* localdecomp:end func_L39_00506300 */

/* localdecomp:start func_L39_005063D0 */
/* an OpenSSL d2i_X509_ALGOR built from the M_ASN1_D2I_ macros (see func_L39_004FA7F8) */
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
} ASN1_CTX_005063D0;

typedef struct {
    void *algorithm;
    void *parameter;
} S_005063D0;

extern S_005063D0 *func_L39_005065C8(void);
extern s32 func_L39_004FA2A8(ASN1_CTX_005063D0 *, s64 *);
extern void *func_L39_004F9870(void *, u8 **, s64);
extern s32 func_L39_0050A5A0(u8 **, long);
extern void *func_L39_004FB2A0(void *, u8 **, s64);
extern void func_L39_004FB620(void *);
extern s32 func_L39_004FA228(ASN1_CTX_005063D0 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004FA538(u8 *, s32);
extern void func_L39_00506630(S_005063D0 *);

void *func_L39_005063D0(void *arg0, u8 **pp, s64 length) {
    S_005063D0 **a = arg0;
    ASN1_CTX_005063D0 c;
    S_005063D0 *ret = 0;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a == 0 || *a == 0) {
        if ((ret = func_L39_005065C8()) == 0) {
            c.line = 0x2C;
            goto err;
        }
    } else {
        ret = *a;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + (s32)length;
    if (!func_L39_004FA2A8(&c, &length)) {
        c.line = 0x2F;
        goto err;
    }
    c.q = c.p;
    if (func_L39_004F9870(&ret->algorithm, &c.p, c.slen) == 0) {
        c.line = 0x30;
        goto err;
    }
    c.slen -= (c.p - c.q);
    if (!(((c.inf & 1) == 0) ? (c.slen <= 0) : (c.eos = func_L39_0050A5A0(&c.p, c.slen)))) {
        c.q = c.p;
        if (func_L39_004FB2A0(&ret->parameter, &c.p, c.slen) == 0) {
            c.line = 0x32;
            goto err;
        }
        c.slen -= (c.p - c.q);
    } else {
        func_L39_004FB620(ret->parameter);
        ret->parameter = 0;
    }
    if (!func_L39_004FA228(&c)) {
        c.line = 0x38;
        goto err;
    }
    *pp = c.p;
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004BC6C8(0xD, 0xA0, c.error, 0, 0);
    func_L39_004FA538(*pp, (s32)(c.q - *pp));
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_00506630(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_005063D0 */

INCLUDE_ASM("asm/levels", func_L39_005065C8);

INCLUDE_ASM("asm/levels", func_L39_00506630);

LINKER_REMNANT("asm/levels", func_L39_00506678);
