#include "common.h"

/* localdecomp:start func_L39_004D9CA0 */
typedef struct S_004D9CA0 {
    /* 0x00 */ s32 pad0[3];
    /* 0x0C */ s32 len;
    /* 0x10 */ u8 *data;
} S_004D9CA0;

extern s32 func_L39_004E0C88(S_004D9CA0 *);
extern u8 *func_L39_004E0BC8(s32);
extern u8 *func_L39_004E0B10(s32);
extern long func_00130760(long, long);
extern s32 func_00120048(void *, void *, ...);
extern s32 func_00120884(void *);
extern void func_00120D28(void *, void *, s32);
extern u8 D_L39_00476188[];
extern u8 D_L39_00476190[];

s32 func_L39_004D9CA0(u8 *dst, s32 n, S_004D9CA0 *src) {
    u8 buf[0x30];
    s32 r;
    s32 total;
    s32 i;
    s32 len;
    long x;
    u8 *p;

    if (n <= 0) {
        return 0;
    }
    if (src == 0 || src->data == 0) {
        *dst = 0;
        return 0;
    }
    r = func_L39_004E0C88(src);
    if (r == 0) {
        i = 0;
        len = src->len;
        p = src->data;
        x = 0;
        if (len > 0) {
            x = *p & 0x7F;
            if (*p & 0x80) {
                do {
                    i++;
                    x <<= 7;
                    if (i >= len) {
                        break;
                    }
                    x |= p[i] & 0x7F;
                } while (p[i] & 0x80);
            }
        }
        r = func_00130760(x, 0x28);
        i++;
        if (r > 2) {
            r = 2;
        }
        func_00120048(buf, D_L39_00476188, r, x - r * 0x28);
        x = 0;
        r = func_00120884(buf);
        func_00120D28(dst, buf, n);
        n -= r;
        dst += r;
        total = r;
        if (i < len) {
            do {
                x |= p[i] & 0x7F;
                if ((p[i] & 0x80) == 0) {
                    func_00120048(buf, D_L39_00476190, x);
                    r = func_00120884(buf);
                    if (n > 0) {
                        func_00120D28(dst, buf, n);
                    }
                    n -= r;
                    dst += r;
                    total += r;
                    x = 0;
                }
                i++;
                x <<= 7;
            } while (i < len);
        }
    } else {
        u8 *s = func_L39_004E0BC8(r);
        if (s == 0) {
            s = func_L39_004E0B10(r);
        }
        func_00120D28(dst, s, n);
        total = func_00120884(s);
    }
    dst[n - 1] = 0;
    return total;
}
/* localdecomp:end func_L39_004D9CA0 */

/* localdecomp:start func_L39_004D9ED8 */
extern char D_L39_0046A330[];

void *func_L39_004D9ED8(void) {
    return D_L39_0046A330;
}
/* localdecomp:end func_L39_004D9ED8 */

/* localdecomp:start func_L39_004D9EE8 */
typedef struct B_004D9EE8 {
    /* 0x00 */ s32 size0;
    /* 0x04 */ s32 size1;
    /* 0x08 */ u8 *buf0;
    /* 0x0C */ s32 n0;
    /* 0x10 */ s32 pos0;
    /* 0x14 */ u8 *buf1;
    /* 0x18 */ s32 n1;
    /* 0x1C */ s32 pos1;
} B_004D9EE8;

typedef struct S_004D9EE8 {
    /* 0x00 */ s32 pad0[3];
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 pad18[2];
    /* 0x20 */ B_004D9EE8 *f20;
} S_004D9EE8;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

s32 func_L39_004D9EE8(S_004D9EE8 *arg0) {
    B_004D9EE8 *b;

    b = func_L39_004BEED8(0x20);
    if (b == 0) {
        return 0;
    }
    b->buf0 = func_L39_004BEED8(0x400);
    if (b->buf0 == 0) {
        func_L39_004BEF28(b);
        return 0;
    }
    b->buf1 = func_L39_004BEED8(0x400);
    if (b->buf1 == 0) {
        func_L39_004BEF28(b->buf0);
        func_L39_004BEF28(b);
        return 0;
    }
    b->n0 = 0;
    b->size0 = 0x400;
    b->size1 = 0x400;
    b->pos0 = 0;
    b->n1 = 0;
    b->pos1 = 0;
    arg0->fC = 1;
    arg0->f20 = b;
    arg0->f14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004D9EE8 */

/* localdecomp:start func_L39_004D9F90 */
extern void func_L39_004BEF28(void *);

typedef struct S20_004D9F90 {
    u8 pad0[0x8];
    void *f8;
    u8 padC[0x14 - 0xC];
    void *f14;
} S20_004D9F90;

typedef struct S_004D9F90 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x14 - 0x10];
    s32 f14;
    u8 pad18[0x20 - 0x18];
    S20_004D9F90 *f20;
} S_004D9F90;

s32 func_L39_004D9F90(S_004D9F90 *s) {
    S20_004D9F90 *t;

    if (s == 0) {
        return 0;
    }
    t = s->f20;
    if (t->f8 != 0) {
        func_L39_004BEF28(t->f8);
    }
    if (t->f14 != 0) {
        func_L39_004BEF28(t->f14);
    }
    func_L39_004BEF28(s->f20);
    s->f20 = 0;
    s->fC = 0;
    s->f14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004D9F90 */

/* localdecomp:start func_L39_004DA008 */
/* OpenSSL's buffer_read (crypto/bio/bf_buff.c), BIO_f_buffer's read method */
typedef struct B_004DA008 {
    /* 0x00 */ s32 ibuf_size;
    /* 0x04 */ s32 obuf_size;
    /* 0x08 */ u8 *ibuf;
    /* 0x0C */ s32 ibuf_len;
    /* 0x10 */ s32 ibuf_off;
} B_004DA008;

typedef struct S_004DA008 {
    /* 0x00 */ s32 pad0[8];
    /* 0x20 */ B_004DA008 *ptr;
    /* 0x24 */ s32 next_bio;
} S_004DA008;

extern void *func_0011D380(void *, void *, s32);
extern void func_L39_004BB428(S_004DA008 *);
extern s32 func_L39_004DAB90(s32, u8 *, s32);
extern void func_L39_004DB090(S_004DA008 *);

s32 func_L39_004DA008(S_004DA008 *b, u8 *out, s32 outl) {
    s32 i, num = 0;
    B_004DA008 *ctx;

    if (out == 0) {
        return 0;
    }
    ctx = b->ptr;

    if (ctx == 0 || b->next_bio == 0) {
        return 0;
    }
    num = 0;
    func_L39_004BB428(b);

start:
    i = ctx->ibuf_len;
    if (i != 0) {
        if (i > outl) {
            i = outl;
        }
        func_0011D380(out, &ctx->ibuf[ctx->ibuf_off], i);
        ctx->ibuf_off += i;
        ctx->ibuf_len -= i;
        num += i;
        if (outl == i) {
            return num;
        }
        outl -= i;
        out += i;
    }

    if (outl > ctx->ibuf_size) {
        for (;;) {
            i = func_L39_004DAB90(b->next_bio, out, outl);
            if (i <= 0) {
                func_L39_004DB090(b);
                if (i < 0) {
                    return (num > 0) ? num : i;
                }
                if (i == 0) {
                    return num;
                }
            }
            num += i;
            if (outl == i) {
                return num;
            }
            out += i;
            outl -= i;
        }
    }

    i = func_L39_004DAB90(b->next_bio, ctx->ibuf, ctx->ibuf_size);
    if (i <= 0) {
        func_L39_004DB090(b);
        if (i < 0) {
            return (num > 0) ? num : i;
        }
        if (i == 0) {
            return num;
        }
    }
    ctx->ibuf_off = 0;
    ctx->ibuf_len = i;

    goto start;
}
/* localdecomp:end func_L39_004DA008 */

/* localdecomp:start func_L39_004DA180 */
typedef struct S20_004DA180 {
    /* 0x00 */ s32 ibuf_size;
    /* 0x04 */ s32 obuf_size;
    /* 0x08 */ char *ibuf;
    /* 0x0C */ s32 ibuf_len;
    /* 0x10 */ s32 ibuf_off;
    /* 0x14 */ char *obuf;
    /* 0x18 */ s32 obuf_len;
    /* 0x1C */ s32 obuf_off;
} S20_004DA180;

typedef struct S_004DA180 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ S20_004DA180 *ptr;
    /* 0x24 */ void *next_bio;
} S_004DA180;

extern void func_L39_004BB428(); /* declared in func_L39_004DA008 with its struct type */
extern s32 func_L39_004DACB0(void *, const char *, s32);
extern void func_L39_004DB090(); /* declared in func_L39_004DA008 with its struct type */
extern void *func_0011D380(void *, void *, s32);

/* OpenSSL 0.9.x crypto/bio/bf_buff.c, buffer_write */
s32 func_L39_004DA180(S_004DA180 *b, const char *in, s32 inl) {
    s32 i;
    s32 num = 0;
    S20_004DA180 *ctx;

    if (in == 0 || inl <= 0) {
        return 0;
    }
    ctx = b->ptr;
    if (ctx == 0 || b->next_bio == 0) {
        return 0;
    }

    func_L39_004BB428(b);
start:
    i = ctx->obuf_size - (ctx->obuf_len + ctx->obuf_off);
    if (i >= inl) {
        func_0011D380(&ctx->obuf[ctx->obuf_len], (void *)in, inl);
        ctx->obuf_len += inl;
        return num + inl;
    }
    if (ctx->obuf_len != 0) {
        if (i > 0) {
            func_0011D380(&ctx->obuf[ctx->obuf_len], (void *)in, i);
            in += i;
            inl -= i;
            num += i;
            ctx->obuf_len += i;
        }
        for (;;) {
            i = func_L39_004DACB0(b->next_bio, &ctx->obuf[ctx->obuf_off], ctx->obuf_len);
            if (i <= 0) {
                func_L39_004DB090(b);
                if (i < 0) {
                    return (num > 0) ? num : i;
                }
                if (i == 0) {
                    return num;
                }
            }
            ctx->obuf_off += i;
            ctx->obuf_len -= i;
            if (ctx->obuf_len == 0) {
                break;
            }
        }
    }
    ctx->obuf_off = 0;

    while (inl >= ctx->obuf_size) {
        i = func_L39_004DACB0(b->next_bio, in, inl);
        if (i <= 0) {
            func_L39_004DB090(b);
            if (i < 0) {
                return (num > 0) ? num : i;
            }
            if (i == 0) {
                return num;
            }
        }
        num += i;
        in += i;
        inl -= i;
        if (inl == 0) {
            return num;
        }
    }
    goto start;
}
/* localdecomp:end func_L39_004DA180 */

/* localdecomp:start func_L39_004DA368 */
typedef struct S20_004DA368 {
    /* 0x00 */ s32 ibuf_size;
    /* 0x04 */ s32 obuf_size;
    /* 0x08 */ char *ibuf;
    /* 0x0C */ s32 ibuf_len;
    /* 0x10 */ s32 ibuf_off;
    /* 0x14 */ char *obuf;
    /* 0x18 */ s32 obuf_len;
    /* 0x1C */ s32 obuf_off;
} S20_004DA368;

typedef struct S_004DA368 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ S20_004DA368 *ptr;
    /* 0x24 */ void *next_bio;
} S_004DA368;

extern void func_L39_004BB428(); /* declared in func_L39_004DA008 with its struct type */
extern s32 func_L39_004DACB0(void *, const char *, s32);
extern void func_L39_004DB090(); /* declared in func_L39_004DA008 with its struct type */
extern void *func_0011D380(void *, void *, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern long func_L39_004DAE48(void *, s32, long, void *);
extern s32 func_L39_004DAE28(void *, s32, s32, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* OpenSSL 0.9.x crypto/bio/bf_buff.c, buffer_ctrl */
long func_L39_004DA368(S_004DA368 *b, s32 cmd, long num, void *ptr) {
    void *dbio;
    S20_004DA368 *ctx;
    long ret = 1;
    char *p1;
    char *p2;
    s32 r;
    s32 i;
    s32 *ip;
    s32 ibs;
    s32 obs;

    ctx = b->ptr;

    switch (cmd) {
    case 1:
        ctx->ibuf_off = 0;
        ctx->ibuf_len = 0;
        ctx->obuf_off = 0;
        ctx->obuf_len = 0;
        ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        break;
    case 3:
        ret = ctx->obuf_len;
        break;
    case 0x74:
        ret = 0;
        p1 = ctx->ibuf;
        for (i = ctx->ibuf_off; i < ctx->ibuf_len; i++) {
            if (p1[i] == '\n') {
                ret++;
            }
        }
        break;
    case 13:
        ret = ctx->obuf_len;
        if (ret == 0) {
            ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        }
        break;
    case 10:
        ret = ctx->ibuf_len;
        if (ret == 0) {
            ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        }
        break;
    case 0x7A:
        if (num > ctx->ibuf_size) {
            p1 = func_L39_004BEED8((s32)num);
            if (p1 == 0) {
                goto malloc_error;
            }
            if (ctx->ibuf != 0) {
                func_L39_004BEF28(ctx->ibuf);
            }
            ctx->ibuf = p1;
        }
        ctx->ibuf_off = 0;
        ctx->ibuf_len = (s32)num;
        func_0011D380(ctx->ibuf, ptr, (s32)num);
        ret = 1;
        break;
    case 0x75:
        if (ptr != 0) {
            ip = (s32 *)ptr;
            if (*ip == 0) {
                ibs = (s32)num;
                obs = ctx->obuf_size;
            } else {
                ibs = ctx->ibuf_size;
                obs = (s32)num;
            }
        } else {
            ibs = (s32)num;
            obs = (s32)num;
        }
        p1 = ctx->ibuf;
        p2 = ctx->obuf;
        if (ibs > 0x400 && ibs != ctx->ibuf_size) {
            p1 = func_L39_004BEED8((s32)num);
            if (p1 == 0) {
                goto malloc_error;
            }
        }
        if (obs > 0x400 && obs != ctx->obuf_size) {
            p2 = func_L39_004BEED8((s32)num);
            if (p2 == 0) {
                if (p1 != ctx->ibuf) {
                    func_L39_004BEF28(p1);
                }
                goto malloc_error;
            }
        }
        if (ctx->ibuf != p1) {
            func_L39_004BEF28(ctx->ibuf);
            ctx->ibuf = p1;
            ctx->ibuf_off = 0;
            ctx->ibuf_len = 0;
            ctx->ibuf_size = ibs;
        }
        if (ctx->obuf != p2) {
            func_L39_004BEF28(ctx->obuf);
            ctx->obuf = p2;
            ctx->obuf_off = 0;
            ctx->obuf_len = 0;
            ctx->obuf_size = obs;
        }
        break;
    case 0x65:
        func_L39_004BB428(b);
        ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        func_L39_004DB090(b);
        break;
    case 11:
        if (ctx->obuf_len > 0) {
            for (;;) {
                func_L39_004BB428(b);
                if (ctx->obuf_len > ctx->obuf_off) {
                    r = func_L39_004DACB0(b->next_bio, &ctx->obuf[ctx->obuf_off], ctx->obuf_len - ctx->obuf_off);
                    func_L39_004DB090(b);
                    if (r <= 0) {
                        return r;
                    }
                    ctx->obuf_off += r;
                } else {
                    ctx->obuf_len = 0;
                    ctx->obuf_off = 0;
                    ret = 1;
                    break;
                }
            }
        }
        ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        break;
    case 12:
        dbio = ptr;
        if (!func_L39_004DAE28(dbio, 0x75, ctx->ibuf_size, 0) ||
            !func_L39_004DAE28(dbio, 0x75, ctx->obuf_size, 1)) {
            ret = 0;
        }
        break;
    default:
        ret = func_L39_004DAE48(b->next_bio, cmd, num, ptr);
        break;
    }
    return ret;
malloc_error:
    func_L39_004BC6C8(0x20, 0x6B, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DA368 */

/* localdecomp:start func_L39_004DA7B0 */
typedef struct S20_004DA7B0 {
    /* 0x00 */ s32 size;
    /* 0x04 */ s32 pad4;
    /* 0x08 */ char *buf;
    /* 0x0C */ s32 len;
    /* 0x10 */ s32 off;
} S20_004DA7B0;

typedef struct S_004DA7B0 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ S20_004DA7B0 *b;
    /* 0x24 */ void *next;
} S_004DA7B0;

extern void func_L39_004BB428(); /* declared in func_L39_004DA008 with its struct type */
extern s32 func_L39_004DAB90(); /* declared in func_L39_004DA008 as (s32, u8 *, s32) */
extern void func_L39_004DB090(); /* declared in func_L39_004DA008 with its struct type */

/* OpenSSL 0.9.x crypto/bio/bf_buff.c, buffer_gets */
s32 func_L39_004DA7B0(S_004DA7B0 *a0, char *out, s32 size) {
    S20_004DA7B0 *b = a0->b;
    s32 total = 0;
    s32 rem = size - 1;
    s32 found;
    s32 i;

    char *p;

    func_L39_004BB428(a0);
    for (;;) {
        if (b->len > 0) {
            p = &b->buf[b->off];
            found = 0;
            for (i = 0; i < b->len && i < rem; i++) {
                *(out++) = p[i];
                if (p[i] == '\n') {
                    found = 1;
                    i++;
                    break;
                }
            }
            total += i;
            rem -= i;
            b->len -= i;
            b->off += i;
            if (found || i == rem) {
                *out = 0;
                return total;
            }
        } else {
            i = func_L39_004DAB90(a0->next, b->buf, b->size);
            if (i <= 0) {
                func_L39_004DB090(a0);
                if (i < 0) {
                    return (total > 0) ? total : i;
                }
                if (i == 0) {
                    return total;
                }
            }
            b->len = i;
            b->off = 0;
        }
    }
}
/* localdecomp:end func_L39_004DA7B0 */

/* localdecomp:start func_L39_004DA920 */
extern s32 func_L39_004DACB0(void *, const char *, s32);

s32 func_L39_004DA920(void *arg0, const char *arg1) {
    return func_L39_004DACB0(arg0, arg1, func_00120884(arg1));
}
/* localdecomp:end func_L39_004DA920 */
