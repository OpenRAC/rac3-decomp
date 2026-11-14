#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00509078);

INCLUDE_ASM("asm/levels", func_L39_005090B4);

INCLUDE_ASM("asm/levels", func_L39_005091E8);

INCLUDE_ASM("asm/levels", func_L39_00509388);

INCLUDE_ASM("asm/levels", func_L39_005093A8);

INCLUDE_ASM("asm/levels", func_L39_005094F8);

INCLUDE_ASM("asm/levels", func_L39_00509558);

INCLUDE_ASM("asm/levels", func_L39_00509DF8);

INCLUDE_ASM("asm/levels", func_L39_00509E38);

/* localdecomp:start func_L39_00509EA0 */
/* OpenSSL's d2i_ASN1_type_bytes (crypto/asn1/a_bytes.c) */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} ASN1_STRING_00509EA0;

extern s32 func_L39_004F9E08(u8 **, long *, s32 *, s32 *, long);
extern void *func_L39_004F8B88(void *, u8 **, long);
extern void *func_L39_004FA460(void);
extern void *func_L39_004BEED8(s32);
extern void *func_0011D380(void *, const void *, unsigned int);
extern void func_L39_004BEF28(void *);
extern void func_L39_004FA4E8(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern unsigned long D_L39_0046F218[];

s32 func_L39_00509EA0(s32 arg0, s32 arg1, s32 arg2, s32 type) {
    ASN1_STRING_00509EA0 **a = (ASN1_STRING_00509EA0 **)arg0;
    u8 **pp = (u8 **)arg1;
    long length = arg2;
    ASN1_STRING_00509EA0 *ret = 0;
    u8 *p, *s;
    long len;
    s32 inf, tag, xclass;
    s32 i = 0;

    p = *pp;
    inf = func_L39_004F9E08(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (len > length - (p - *pp)) {
        i = 0x65;
        goto err;
    }

    if (tag >= 32) {
        i = 0x87;
        goto err;
    }
    if (!(D_L39_0046F218[tag] & type)) {
        i = 0x96;
        goto err;
    }

    if (tag == 3) {
        return (s32)func_L39_004F8B88(a, pp, length);
    }

    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004FA460()) == 0) {
            return 0;
        }
    } else {
        ret = *a;
    }

    if (len != 0) {
        s = func_L39_004BEED8((s32)len + 1);
        if (s == 0) {
            i = 0x21;
            goto err;
        }
        func_0011D380(s, p, (s32)len);
        s[len] = '\0';
        p += len;
    } else {
        s = 0;
    }

    if (ret->data != 0) {
        func_L39_004BEF28(ret->data);
    }
    ret->length = (s32)len;
    ret->data = s;
    ret->type = tag;
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return (s32)ret;
err:
    func_L39_004BC6C8(13, 0x86, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FA4E8(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_00509EA0 */

INCLUDE_ASM("asm/levels", func_L39_0050A098);

INCLUDE_ASM("asm/levels", func_L39_0050A178);

/* localdecomp:start func_L39_0050A3C8 */
/* OpenSSL's asn1_collate_primitive (crypto/asn1/asn1_lib.c) */
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
} ASN1_CTX_0050A3C8;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} ASN1_STRING_0050A3C8;

typedef struct {
    s32 length;
    u8 *data;
    s32 max;
} BUF_MEM_0050A3C8;

extern s32 func_L39_0050A178(s32, s32, s32, s32, s32);
extern s32 func_L39_0050A5A0(void **, s32);
extern s32 func_L39_004DB1C0(void *, s32);
extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 func_L39_004FA228(void *);
extern void func_L39_004BEF28(void *);
extern void func_L39_004FA4E8(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_0050A3C8(void *arg0, void *arg1) {
    ASN1_STRING_0050A3C8 *a = arg0;
    ASN1_CTX_0050A3C8 *c = arg1;
    ASN1_STRING_0050A3C8 *os = 0;
    BUF_MEM_0050A3C8 b;
    s32 num;

    b.length = 0;
    b.max = 0;
    b.data = 0;

    if (a == 0) {
        c->error = 0x23;
        goto err;
    }

    num = 0;
    for (;;) {
        if (c->inf & 1) {
            c->eos = func_L39_0050A5A0((void **)&c->p, c->max - c->p);
            if (c->eos) {
                break;
            }
        } else {
            if (c->slen <= 0) {
                break;
            }
        }

        c->q = c->p;
        if (func_L39_0050A178((s32)&os, (s32)&c->p, c->max - c->p, c->tag, c->xclass) == 0) {
            c->error = 0x80D;
            goto err;
        }

        if (!func_L39_004DB1C0(&b, num + os->length)) {
            c->error = 0x807;
            goto err;
        }
        func_0011D380(&b.data[num], os->data, os->length);
        if (!(c->inf & 1)) {
            c->slen -= c->p - c->q;
        }
        num += os->length;
    }

    if (!func_L39_004FA228(c)) {
        goto err;
    }

    a->length = num;
    if (a->data != 0) {
        func_L39_004BEF28(a->data);
    }
    a->data = b.data;
    if (os != 0) {
        func_L39_004FA4E8(os);
    }
    return 1;
err:
    func_L39_004BC6C8(13, 0x67, c->error, 0, 0);
    if (os != 0) {
        func_L39_004FA4E8(os);
    }
    if (b.data != 0) {
        func_L39_004BEF28(b.data);
    }
    return 0;
}
/* localdecomp:end func_L39_0050A3C8 */
