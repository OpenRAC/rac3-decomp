#include "common.h"

/* localdecomp:start func_L39_004F8A78 */
typedef struct S_004F8A78 { s32 length; s32 type; u8 *data; long flags; } S_004F8A78;
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);
extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004F8A78(S_004F8A78 *a, u8 **pp) {
    s32 ret, r, bits, len;
    u8 *p, *d;

    if (a == 0) {
        return 0;
    }
    len = a->length;
    if (len > 0) {
        if (a->flags & 8) {
            bits = (s32)a->flags & 7;
        } else {
            bits = 0;
        }
    } else {
        bits = 0;
    }
    ret = 1 + len;
    r = func_L39_004FA1A0(0, ret, 3);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 0, ret, 3, 0);
    *(p++) = (u8)bits;
    d = a->data;
    func_0011D380(p, d, len);
    p += len;
    if (len > 0) {
        p[-1] &= (0xFF << bits);
    }
    *pp = p;
    return r;
}
/* localdecomp:end func_L39_004F8A78 */

/* localdecomp:start func_L39_004F8B88 */
typedef struct S_004F8B88 { s32 length; s32 type; u8 *data; s32 pad; s64 flags; } S_004F8B88;

extern S_004F8B88 *func_L39_004FA480(s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004FA4E8(S_004F8B88 *);

/* follows OpenSSL's d2i_ASN1_BIT_STRING */
S_004F8B88 *func_L39_004F8B88(S_004F8B88 **a, u8 **pp, s64 length) {
    S_004F8B88 *ret;
    u8 *p;
    u8 *s;
    s64 len;
    s32 inf;
    s32 tag;
    s32 xclass;
    s32 i;

    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004FA480(3)) == 0) {
            return 0;
        }
    } else {
        ret = *a;
    }

    p = *pp;
    inf = func_L39_004F9E08(&p, (long *)&len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (len > length - (p - *pp)) {
        i = 0x65;
        goto err;
    }
    if (tag != 3) {
        i = 0x74;
        goto err;
    }
    if (len < 1) {
        i = 0x86;
        goto err;
    }

    i = *p++;
    ret->flags &= ~0xF;
    ret->flags |= 8 | (i & 7);

    if (len-- > 1) {
        s = func_L39_004BEED8(len);
        if (s == 0) {
            i = 0x21;
            goto err;
        }
        func_0011D380(s, p, len);
        s[len - 1] &= 0xFF << i;
        p += len;
    } else {
        s = 0;
    }

    ret->length = len;
    if (ret->data != 0) {
        func_L39_004BEF28(ret->data);
    }
    ret->data = s;
    ret->type = 3;
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    func_L39_004BC6C8(0xD, 0x7B, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FA4E8(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004F8B88 */

/* localdecomp:start func_L39_004F8D78 */
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);

s32 func_L39_004F8D78(s32 a, u8 **pp) {
    s32 r;
    u8 *p;

    r = func_L39_004FA1A0(0, 1, 1);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 0, 1, 1, 0);
    *(p++) = (u8)a;
    *pp = p;
    return r;
}
/* localdecomp:end func_L39_004F8D78 */

/* localdecomp:start func_L39_004F8E00 */
extern s32 func_L39_004F9E08(u8 **, long *, s32 *, s32 *, long);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004F8E00(s32 *a, u8 **pp, long length) {
    s32 ret = -1;
    u8 *p;
    long len;
    s32 inf, tag, xclass;
    s32 i = 0;

    p = *pp;
    inf = func_L39_004F9E08(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (tag != 1) {
        i = 0x75;
        goto err;
    }
    if (len != 1) {
        i = 0x6C;
        goto err;
    }
    ret = (s32)*(p++);
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    func_L39_004BC6C8(13, 0x7D, i, 0, 0);
    return ret;
}
/* localdecomp:end func_L39_004F8E00 */

/* localdecomp:start func_L39_004F8EB8 */
typedef struct S_004F8EB8_buf { s32 length; char *data; s32 max; } S_004F8EB8_buf;
typedef struct S_004F8EB8_ctx {
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
} S_004F8EB8_ctx;

extern S_004F8EB8_buf *func_L39_004DB110(void);
extern void func_L39_004DE0C8(void);
extern s32 func_L39_004DB1C0(S_004F8EB8_buf *, s32);
extern s32 func_L39_004DAB90(void *, char *, s32);
extern long func_L39_004DE120(void);
extern long func_L39_004DE0F0(void);
extern void func_L39_004DB168(S_004F8EB8_buf *);

/* follows SSLeay's ASN1_d2i_bio */
char *func_L39_004F8EB8(char *(*xnew)(), char *(*d2i)(), void *in, u8 **x) {
    S_004F8EB8_buf *b;
    u8 *p;
    s32 i;
    char *ret = 0;
    S_004F8EB8_ctx c;
    s32 want = 8;
    s32 eos = 0;
    s32 off = 0;
    s32 len = 0;

    b = func_L39_004DB110();
    if (b == 0) {
        func_L39_004BC6C8(13, 0x68, 0x21, 0, 0);
        return 0;
    }

    func_L39_004DE0C8();
    for (;;) {
        if (want >= (len - off)) {
            want -= (len - off);
            if (!func_L39_004DB1C0(b, len + want)) {
                func_L39_004BC6C8(13, 0x68, 0x21, 0, 0);
                goto err;
            }
            i = func_L39_004DAB90(in, &b->data[len], want);
            if ((i < 0) && ((len - off) == 0)) {
                func_L39_004BC6C8(13, 0x68, 0x80, 0, 0);
                goto err;
            }
            if (i > 0) {
                len += i;
            }
        }

        p = (u8 *)&b->data[off];
        c.p = p;
        c.inf = func_L39_004F9E08(&c.p, &c.slen, &c.tag, &c.xclass, len - off);
        if (c.inf & 0x80) {
            unsigned long e;

            e = (int)(func_L39_004DE120() & 0xFFF);
            if (e != 0x89) {
                goto err;
            } else {
                func_L39_004DE0F0();
            }
        }
        i = c.p - p;
        off += i;

        if (c.inf & 1) {
            eos++;
            want = 8;
        } else if (eos && (c.slen == 0) && (c.tag == 0)) {
            eos--;
            if (eos <= 0) {
                break;
            } else {
                want = 8;
            }
        } else {
            want = (s32)c.slen;
            if (want > (len - off)) {
                want -= (len - off);
                if (!func_L39_004DB1C0(b, len + want)) {
                    func_L39_004BC6C8(13, 0x68, 0x21, 0, 0);
                    goto err;
                }
                while (want > 0) {
                    i = func_L39_004DAB90(in, &b->data[len], want);
                    if (i <= 0) {
                        func_L39_004BC6C8(13, 0x68, 0x80, 0, 0);
                        goto err;
                    }
                    len += i;
                    want -= i;
                }
            }
            off += (s32)c.slen;
            if (eos <= 0) {
                break;
            } else {
                want = 8;
            }
        }
    }

    p = (u8 *)b->data;
    ret = d2i(x, &p, off);
err:
    if (b != 0) {
        func_L39_004DB168(b);
    }
    return ret;
}
/* localdecomp:end func_L39_004F8EB8 */

/* localdecomp:start func_L39_004F9158 */
extern void *func_L39_004DE940(void);
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004DD690(void *, s32);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004DE9B8(void *);

s32 func_L39_004F9158(s32 (*fn)(s32, void **), s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *h;
    void *buf;
    s32 size;
    s32 ret;
    void *local;

    ret = 0;
    buf = 0;
    h = func_L39_004DE940();
    if (h != 0) {
        size = fn(arg2, 0);
        if (size > 0) {
            buf = func_L39_004BEED8(size);
            if (buf == 0) {
                goto close;
            }
        }
        local = buf;
        fn(arg2, &local);
        if (func_L39_004DD690(h, arg1) != 0) {
            ret = 1;
            func_L39_004DD778(h, buf, size);
            func_L39_004DD7A8(h, arg3, arg4);
        }
    }
    if (buf != 0) {
        func_L39_004BEF28(buf);
    }
close:
    if (h != 0) {
        func_L39_004DE9B8(h);
    }
    return ret;
}
/* localdecomp:end func_L39_004F9158 */

/* localdecomp:start func_L39_004F9278 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

char *func_L39_004F9278(s32 (*i2d)(), char *(*d2i)(), char *x) {
    u8 *b, *p;
    long i;
    char *ret;

    if (x == 0) {
        return 0;
    }
    i = (long)i2d(x, 0);
    b = (u8 *)func_L39_004BEED8((u32)i + 10);
    if (b == 0) {
        func_L39_004BC6C8(13, 106, 33, 0, 0);
        return 0;
    }
    p = b;
    i = i2d(x, &p);
    p = b;
    ret = d2i(0, &p, i);
    func_L39_004BEF28(b);
    return ret;
}
/* localdecomp:end func_L39_004F9278 */

/* localdecomp:start func_L39_004F9340 */
typedef struct S_004F9340 { s32 len; s32 type; u8 *data; } S_004F9340;


s32 func_L39_004F9340(S_004F9340 *p, u8 **pp) {
    s32 c;
    s32 pad;
    s32 padbyte;
    s32 total;
    s32 type;
    s32 ret;
    u8 *q;
    u8 *s;
    u8 *start;

    pad = 0;
    padbyte = 0;
    if (p == 0 || p->data == 0) {
        return 0;
    }
    type = p->type;
    total = 1;
    if (p->len != 0) {
        c = p->data[0];
        if (type == 2 && c >= 0x80) {
            pad = 1;
        } else if (type == 0x102 && c > 0x80) {
            pad = 1;
            padbyte = 0xFF;
        }
        total = p->len + pad;
    }
    ret = func_L39_004FA1A0(0, total, 2);
    if (pp == 0) {
        return ret;
    }
    q = *pp;
    func_L39_004F9FF8(&q, 0, total, 2, 0);
    if (pad) {
        *q++ = padbyte;
    }
    if (p->len == 0) {
        *q++ = 0;
    } else if (type == 2) {
        func_0011D380(q, p->data, p->len);
        q += p->len;
    } else {
        start = q;
        s = p->data;
        for (c = p->len; c > 0; c--) {
            *q++ = ~*s++ + 1;
        }
        if (!pad) {
            *start |= 0x80;
        }
    }
    *pp = q;
    return ret;
}
/* localdecomp:end func_L39_004F9340 */

/* localdecomp:start func_L39_004F94F0 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* follows OpenSSL's d2i_ASN1_INTEGER */
S_004F8B88 *func_L39_004F94F0(S_004F8B88 **a, u8 **pp, long length) {
    S_004F8B88 *ret;
    u8 *p;
    u8 *to;
    u8 *s;
    long len;
    s32 inf;
    s32 tag;
    s32 xclass;
    s32 i;

    if (a == 0 || *a == 0) {
        if ((ret = func_L39_004FA480(2)) == 0) {
            return 0;
        }
        ret->type = 2;
    } else {
        ret = *a;
    }

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
    if (tag != 2) {
        i = 0x71;
        goto err;
    }

    s = func_L39_004BEED8((s32)len + 1);
    if (s == 0) {
        i = 0x21;
        goto err;
    }
    to = s;
    if (*p & 0x80) {
        ret->type = 0x102;
        if (*p == 0xFF) {
            p++;
            len--;
        }
        for (i = len; i > 0; i--) {
            *to++ = ~*p++ + 1;
        }
    } else {
        ret->type = 2;
        if (*p == 0 && len != 1) {
            p++;
            len--;
        }
        func_0011D380(s, p, len);
        p += len;
    }
    if (ret->data != 0) {
        func_L39_004BEF28(ret->data);
    }
    ret->data = s;
    ret->length = len;
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    func_L39_004BC6C8(0xD, 0x80, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_L39_004FA4E8(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_004F94F0 */

INCLUDE_ASM("asm/levels", func_L39_004F9728);

/* localdecomp:start func_L39_004F97C0 */
typedef struct S_004F97C0 { const char *sn; const char *ln; s32 nid; s32 length; u8 *data; } S_004F97C0;
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);
extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004F97C0(S_004F97C0 *a, s32 *pp) {
    u8 *p;

    if (a == 0 || a->data == 0) {
        return 0;
    }
    if (pp == 0) {
        return func_L39_004FA1A0(0, a->length, 6);
    }
    p = (u8 *)*pp;
    func_L39_004F9FF8(&p, 0, a->length, 6, 0);
    func_0011D380(p, a->data, a->length);
    p += a->length;
    *pp = (s32)p;
    return a->length;
}
/* localdecomp:end func_L39_004F97C0 */
