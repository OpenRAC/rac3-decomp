#include "common.h"

/* localdecomp:start func_L39_004FACB0 */
typedef struct {
    s32 num;
    u8 **data;
} S_004FACB0;

extern s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag);
extern void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);

/* OpenSSL i2d_ASN1_SET */
s32 func_L39_004FACB0(S_004FACB0 *a, u8 **pp, s32 (*func)(u8 *, u8 **), s32 ex_tag, s32 ex_class) {
    s32 ret = 0, r;
    s32 i;
    u8 *p;

    if (a == 0) {
        return 0;
    }
    for (i = a->num - 1; i >= 0; i--) {
        ret += func(a->data[i], 0);
    }
    r = func_L39_004FA1A0(1, ret, ex_tag);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 1, ret, ex_tag, ex_class);
    for (i = 0; i < a->num; i++) {
        func(a->data[i], &p);
    }
    *pp = p;
    return r;
}
/* localdecomp:end func_L39_004FACB0 */

/* localdecomp:start func_L39_004FADD8 */
/* OpenSSL d2i_ASN1_SET */
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
} ASN1_CTX_004FADD8;

extern void *func_L39_004CC228(void *);
extern s32 func_L39_004F9E08(u8 **, long *, s32 *, s32 *, long);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_0050A5A0(u8 **, long);
extern void func_L39_004FA538(u8 *, s32);
extern s32 func_L39_004CC3E0(void *, void *);
extern void func_L39_004CC510(void *, void *);
extern void func_L39_004CC538(void *);

void *func_L39_004FADD8(void **a, u8 **pp, long length, void *(*func)(), void (*free_func)(void *), s32 ex_tag, s32 ex_class) {
    ASN1_CTX_004FADD8 c;
    void *ret = 0;
    void *s;

    if (a == 0 || *a == 0) {
        ret = func_L39_004CC228(0);
        if (ret == 0) {
            goto err;
        }
    } else {
        ret = *a;
    }

    c.p = *pp;
    c.max = (length == 0) ? 0 : (c.p + length);

    c.inf = func_L39_004F9E08(&c.p, &c.slen, &c.tag, &c.xclass, c.max - c.p);
    if (c.inf & 0x80) {
        goto err;
    }
    if (ex_class != c.xclass) {
        func_L39_004BC6C8(0xD, 0x84, 0x64, 0, 0);
        goto err;
    }
    if (ex_tag != c.tag) {
        func_L39_004BC6C8(0xD, 0x84, 0x69, 0, 0);
        goto err;
    }
    if (c.slen + c.p > c.max) {
        func_L39_004BC6C8(0xD, 0x84, 0x7D, 0, 0);
        goto err;
    }
    if (c.inf == 0x21) {
        c.slen = length + (*pp - c.p);
    }
    c.max = c.p + c.slen;

    while (c.p < c.max) {
        if (((c.inf & 1) == 0) ? (c.slen <= 0) : (c.eos = func_L39_0050A5A0(&c.p, c.slen))) {
            break;
        }
        s = func(0, &c.p, c.slen, c.max - c.p);
        if (s == 0) {
            func_L39_004BC6C8(0xD, 0x84, 0x70, 0, 0);
            func_L39_004FA538(*pp, c.q - *pp);
            goto err;
        }
        if (!func_L39_004CC3E0(ret, s)) {
            goto err;
        }
    }
    if (a != 0) {
        *a = ret;
    }
    *pp = c.p;
    return ret;
err:
    if (ret != 0 && (a == 0 || *a != ret)) {
        if (free_func != 0) {
            func_L39_004CC510(ret, free_func);
        } else {
            func_L39_004CC538(ret);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004FADD8 */

/* localdecomp:start func_L39_004FB050 */
/* OpenSSL i2d_ASN1_TYPE */
typedef struct {
    s32 type;
    void *value;
} S_004FB050;

typedef struct {
    s32 length;
    s32 type;
    u8 *data;
} SetStr_004FB050;

extern s32 func_L39_004F9340(void *, u8 **);
extern s32 func_L39_004F8A78(void *, u8 **);
extern s32 func_L39_004FAC48(void *, u8 **);
extern s32 func_L39_004F97C0(void *, u8 **);
extern s32 func_L39_0050A098(void *, u8 **, s32, s32);
extern s32 func_L39_004F9B38(void *, u8 **);
extern void *func_0011D380(void *, void *, s32);

s32 func_L39_004FB050(S_004FB050 *a, u8 **pp) {
    s32 r = 0;

    if (a == 0) {
        return 0;
    }
    switch (a->type) {
    case 5:
        if (pp != 0) {
            func_L39_004F9FF8(pp, 0, 0, 5, 0);
        }
        r = 2;
        break;
    case 2:
    case 0x102:
        r = func_L39_004F9340(a->value, pp);
        break;
    case 3:
        r = func_L39_004F8A78(a->value, pp);
        break;
    case 4:
        r = func_L39_004FAC48(a->value, pp);
        break;
    case 6:
        r = func_L39_004F97C0(a->value, pp);
        break;
    case 0x13:
        r = func_L39_0050A098(a->value, pp, 0x13, 0);
        break;
    case 0x14:
        r = func_L39_0050A098(a->value, pp, 0x14, 0);
        break;
    case 0x16:
        r = func_L39_0050A098(a->value, pp, 0x16, 0);
        break;
    case 0x1b:
        r = func_L39_0050A098(a->value, pp, 0x1b, 0);
        break;
    case 0x1c:
        r = func_L39_0050A098(a->value, pp, 0x1c, 0);
        break;
    case 0x1e:
        r = func_L39_0050A098(a->value, pp, 0x1e, 0);
        break;
    case 0x17:
        r = func_L39_004F9B38(a->value, pp);
        break;
    case 0x10:
    case 0x11:
        if (a->value == 0) {
            r = 0;
        } else {
            SetStr_004FB050 *s = a->value;
            r = s->length;
            if (pp != 0) {
                func_0011D380(*pp, s->data, r);
                *pp += r;
            }
        }
        break;
    }
    return r;
}
/* localdecomp:end func_L39_004FB050 */

/* localdecomp:start func_L39_004FB2A0 */
/* LOG func_L39_004FB2A0 (matched):
 * 1. OpenSSL d2i_ASN1_TYPE shape with switch(tag), p/q/max locals: 37 diff -> 11 diff after
 *    ASN1_get_object's last param as long, ASN1_TYPE.value as a union (ptr/boolean/set), p = q before value = 0.
 * 2. Remaining 11 diff were the scheduling of ret->value.set->type = tag (retail keeps it before the stack loads).
 * 3. Wrapping ASN1_STRING in a union (typedef union { struct {...} s; s32 any; }) made the store alias everything: MATCH.
 *    Tried without effect: struct c for the locals, declaration order, types of len/tag/p, temp for the string pointer,
 *    reordering the statements, int/long for flags. */
/* OpenSSL d2i_ASN1_TYPE */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} STR_004FB2A0;

typedef struct {
    s32 type;
    union {
        void *ptr;
        s32 boolean;
        STR_004FB2A0 *set;
    } value;
} T_004FB2A0;


extern T_004FB2A0 *func_L39_004FB5C8(void);
extern void func_L39_004FB620(T_004FB2A0 *);
extern void func_L39_004FB668(T_004FB2A0 *);
extern s32 func_L39_004F9E08(u8 **, long *, s32 *, s32 *, long);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004F94F0(void *, u8 **, s32);
extern void *func_L39_004F8B88(void *, u8 **, s32);
extern void *func_L39_004FAC68(void *, u8 **, s32);
extern void *func_L39_004F9870(void *, u8 **, s32);
extern void *func_L39_0050A580(void *, u8 **, s32);
extern void *func_L39_00509EA0(void *, u8 **, s32, s32);
extern void *func_L39_004F9B58(void *, u8 **, s32);
extern STR_004FB2A0 *func_L39_004FA460(void);
extern s32 func_L39_004FA380(STR_004FB2A0 *, u8 *, s32);

T_004FB2A0 *func_L39_004FB2A0(T_004FB2A0 **a, u8 **pp, long length) {
    T_004FB2A0 *ret = 0;
    u8 *p, *q, *max;
    long len;
    s32 tag, xclass;

    if (a == 0 || *a == 0) {
        ret = func_L39_004FB5C8();
        if (ret == 0) {
            goto err;
        }
    } else {
        ret = *a;
    }
    q = p = *pp;
    max = p + length;
    if (func_L39_004F9E08(&q, &len, &tag, &xclass, length) & 0x80) {
        goto err;
    }
    func_L39_004FB668(ret);
    switch (tag) {
    case 5:
        p = q;
        ret->value.ptr = 0;
        break;
    case 2:
        if ((ret->value.ptr = func_L39_004F94F0(0, &p, max - p)) == 0) goto err;
        break;
    case 3:
        if ((ret->value.ptr = func_L39_004F8B88(0, &p, max - p)) == 0) goto err;
        break;
    case 4:
        if ((ret->value.ptr = func_L39_004FAC68(0, &p, max - p)) == 0) goto err;
        break;
    case 6:
        if ((ret->value.ptr = func_L39_004F9870(0, &p, max - p)) == 0) goto err;
        break;
    case 0x13:
        if ((ret->value.ptr = func_L39_0050A580(0, &p, max - p)) == 0) goto err;
        break;
    case 0x14:
        if ((ret->value.ptr = func_L39_00509EA0(0, &p, max - p, 4)) == 0) goto err;
        break;
    case 0x16:
        if ((ret->value.ptr = func_L39_00509EA0(0, &p, max - p, 0x10)) == 0) goto err;
        break;
    case 0x1b:
        if ((ret->value.ptr = func_L39_00509EA0(0, &p, max - p, 0x80)) == 0) goto err;
        break;
    case 0x1c:
        if ((ret->value.ptr = func_L39_00509EA0(0, &p, max - p, 0x100)) == 0) goto err;
        break;
    case 0x1e:
        if ((ret->value.ptr = func_L39_00509EA0(0, &p, max - p, 0x800)) == 0) goto err;
        break;
    case 0x17:
        if ((ret->value.ptr = func_L39_004F9B58(0, &p, max - p)) == 0) goto err;
        break;
    case 0x10:
    case 0x11:
        if (max - p < len) {
            func_L39_004BC6C8(0xD, 0x85, 0x89, 0, 0);
            goto err;
        }
        if ((ret->value.ptr = func_L39_004FA460()) == 0) goto err;
        ret->value.set->type = tag;
        len += q - p;
        if (!func_L39_004FA380(ret->value.set, p, len)) goto err;
        p += len;
        break;
    default:
        func_L39_004BC6C8(0xD, 0x85, 0x6A, 0, 0);
        goto err;
    }
    ret->type = tag;
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FB620(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004FB2A0 */
