#include "common.h"

/* localdecomp:start func_L39_004DF158 */
typedef struct { u8 b[64]; } S_004DF158_blob;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    S_004DF158_blob f18;
} S_004DF158_rec;
s32 func_L39_00505120(s32, s32);

s32 func_L39_004DF158(S_004DF158_rec *arg0, S_004DF158_rec *arg1) {
    arg0->f0 = arg1->f0;
    if (func_L39_00505120(arg0->f4, arg1->f4) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->f8, arg1->f8) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->fC, arg1->fC) == 0) {
        return 0;
    }
    arg0->f10 = arg1->f10;
    arg0->f14 = arg1->f14;
    arg0->f18 = arg1->f18;
    return 1;
}
/* localdecomp:end func_L39_004DF158 */

/* localdecomp:start func_L39_004DF260 */
extern s32 func_L39_00505048(void *);
extern s32 func_L39_004DD690(s32, s32);
extern void func_L39_004DD778(s32, void *, u32);
extern void func_L39_004DD7A8(s32, void *, void *);
extern void func_11D380(void *, void *, s32);
extern void func_11D534(void *, s32, s32);

/* OpenSSL's HMAC_Init, with the digest contexts as pointers */
s32 func_L39_004DF260(S_004DF158_rec *ctx, u8 *key, s32 len, s32 md)
{
    s32 i;
    s32 reset = 0;
    u8 pad[64];

    if (md != 0) {
        reset = 1;
        ctx->f0 = md;
    } else {
        md = ctx->f0;
    }
    if (key != 0) {
        reset = 1;
        if (func_L39_00505048((void *)md) < len) {
            if (!func_L39_004DD690(ctx->f4, md)) {
                return 0;
            }
            func_L39_004DD778(ctx->f4, key, len);
            func_L39_004DD7A8(ctx->f4, ctx->f18.b, &ctx->f14);
        } else {
            func_11D380(ctx->f18.b, key, len);
            { s32 n = 64 - len; func_11D534(&ctx->f18.b[len], 0, n); }
            ctx->f14 = len;
        }
    }
    if (reset) {
        for (i = 0; i < 64; i++) {
            pad[i] = 0x36 ^ ctx->f18.b[i];
        }
        if (!func_L39_004DD690(ctx->f8, md)) {
            return 0;
        }
        func_L39_004DD778(ctx->f8, pad, func_L39_00505048((void *)md));
        for (i = 0; i < 64; i++) {
            pad[i] = 0x5C ^ ctx->f18.b[i];
        }
        func_L39_004DD690(ctx->fC, md);
        func_L39_004DD778(ctx->fC, pad, func_L39_00505048((void *)md));
    }
    return func_L39_00505120(ctx->f4, ctx->f8) != 0;
}
/* localdecomp:end func_L39_004DF260 */

/* localdecomp:start func_L39_004DF408 */
/* OpenSSL's HMAC_Update, with the digest contexts as pointers */
void func_L39_004DF408(S_004DF158_rec *ctx, void *data, u32 len) {
    func_L39_004DD778(ctx->f4, data, len);
}
/* localdecomp:end func_L39_004DF408 */

INCLUDE_ASM("asm/levels", func_L39_004DF410);

LINKER_REMNANT("asm/levels", func_L39_004DF4A0);

INCLUDE_ASM("asm/levels", func_L39_004DF4A8);

/* localdecomp:start func_L39_004DF668 */
extern u8 D_L39_0046B7F0[];
void *func_L39_004DF668(void) {
    return D_L39_0046B7F0;
}
/* localdecomp:end func_L39_004DF668 */

/* localdecomp:start func_L39_004DF678 */
extern u8 D_L39_0046B838[];
void *func_L39_004DF678(void) {
    return D_L39_0046B838;
}
/* localdecomp:end func_L39_004DF678 */

/* localdecomp:start func_L39_004DF688 */
extern u8 D_L39_0046B880[];
void *func_L39_004DF688(void) {
    return D_L39_0046B880;
}
/* localdecomp:end func_L39_004DF688 */

/* localdecomp:start func_L39_004DF698 */
extern u8 D_L39_0046B8C8[];
void *func_L39_004DF698(void) {
    return D_L39_0046B8C8;
}
/* localdecomp:end func_L39_004DF698 */

/* localdecomp:start func_L39_004DF6A8 */
extern u8 D_L39_0046B910[];
void *func_L39_004DF6A8(void) {
    return D_L39_0046B910;
}
/* localdecomp:end func_L39_004DF6A8 */

/* localdecomp:start func_L39_004DF6B8 */
extern char D_L39_0046B958[];

void *func_L39_004DF6B8(void) {
    return D_L39_0046B958;
}
/* localdecomp:end func_L39_004DF6B8 */

LINKER_REMNANT("asm/levels", func_L39_004DF6C8);

INCLUDE_ASM("asm/levels", func_L39_004DF6D0);

/* localdecomp:start func_L39_004DF720 */
/* OpenSSL MD2_Update (md2_dgst.c) */
typedef struct {
    s32 num;
    u8 data[16];
    u32 cksm[16];
    u32 state[16];
} MD2_004DF720;

extern void *func_0011D380(void *, const void *, unsigned int);
extern void func_L39_004DF820(void *, u8 *);

void func_L39_004DF720(MD2_004DF720 *c, u8 *data, u64 len) {
    u8 *p;

    if (len == 0)
        return;

    p = c->data;
    if (c->num != 0) {
        if ((c->num + len) >= 16) {
            func_0011D380(&p[c->num], data, 16 - c->num);
            func_L39_004DF820(c, c->data);
            data += 16 - c->num;
            len -= 16 - c->num;
            c->num = 0;
        } else {
            func_0011D380(&p[c->num], data, (s32)len);
            c->num += (s32)len;
            return;
        }
    }
    while (len >= 16) {
        func_L39_004DF820(c, data);
        data += 16;
        len -= 16;
    }
    func_0011D380(p, data, (s32)len);
    c->num = (s32)len;
}
/* localdecomp:end func_L39_004DF720 */

INCLUDE_ASM("asm/levels", func_L39_004DF820);

/* localdecomp:start func_L39_004DFA48 */
/* OpenSSL MD2_Final (md2_dgst.c) */
typedef struct {
    s32 num;
    u8 data[16];
    u32 cksm[16];
    u32 state[16];
} MD2_004DFA48;

extern void func_L39_004DF820(void *, u8 *);

void func_L39_004DFA48(u8 *md, MD2_004DFA48 *c) {
    s32 i, v;
    u8 *cp;
    u32 *p1, *p2;

    cp = c->data;
    p1 = c->state;
    p2 = c->cksm;
    v = 16 - c->num;
    for (i = c->num; i < 16; i++)
        cp[i] = (u8)v;

    func_L39_004DF820(c, cp);

    for (i = 0; i < 16; i++)
        cp[i] = (u8)p2[i];
    func_L39_004DF820(c, cp);

    for (i = 0; i < 16; i++)
        md[i] = (u8)(p1[i] & 0xff);
}
/* localdecomp:end func_L39_004DFA48 */

/* localdecomp:start func_L39_004DFB38 */
typedef struct S_004DFB38 {
    u32 A;
    u32 B;
    u32 C;
    u32 D;
    u32 Nl;
    u32 Nh;
    u32 data[16];
    s32 num;
} S_004DFB38;

/* MD5 context initialisation: the four chaining words, counts cleared, block buffer zeroed */
void func_L39_004DFB38(S_004DFB38 *c) {
    c->A = 0x67452301;
    c->B = 0xEFCDAB89;
    c->C = 0x98BADCFE;
    c->D = 0x10325476;
    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;
    func_11D534(c->data, 0, sizeof(c->data));
}
/* localdecomp:end func_L39_004DFB38 */

/* localdecomp:start func_L39_004DFB88 */
typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buf[64];
    s32 len;
} S_004DFB88;
typedef struct { u8 b[64]; } __attribute__((packed)) S_004DFB88_blk;
extern void func_L39_004DFD50();
extern void *func_0011D380(void *, const void *, unsigned int);
void func_L39_004DFB88(S_004DFB88 *c, u8 *data, u64 len) {
    u8 *buf = c->buf;
    u64 old;
    u64 new;
    s32 n;

    if (len == 0)
        return;
    old = c->count[0];
    new = (old + (len << 3)) & 0xFFFFFFFF;
    if (new < old)
        c->count[1]++;
    c->count[1] += len >> 29;
    c->count[0] = new;
    if (c->len != 0) {
                if (c->len + len < 64) {
            n = len;
            func_0011D380(buf + c->len, data, n);
            c->len += n;
            return;
        }
        n = 64;
        n -= c->len;
        func_0011D380(buf + c->len, data, n);
        func_L39_004DFD50(c, buf);
        len -= n;
        data += n;
        c->len = 0;
    }
    while (len >= 64) {
        len -= 64;
        *(S_004DFB88_blk *)buf = *(S_004DFB88_blk *)data;
        func_L39_004DFD50(c, buf);
        data += 64;
    }
    c->len = len;
    if (len != 0)
        func_0011D380(buf, data, len);
}
/* localdecomp:end func_L39_004DFB88 */

INCLUDE_ASM("asm/levels", func_L39_004DFD50);

/* localdecomp:start func_L39_004E00C8 */
typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buf[64];
    s32 len;
} S_004E00C8;
extern void func_L39_004DFD50(S_004E00C8 *, u8 *);
extern void func_0011D534(void *, s32, s32);
void func_L39_004E00C8(u8 *out, S_004E00C8 *c) {
    u8 *buf = c->buf;
    s32 n = c->len;
    u32 w;

    buf[n++] = 0x80;
    if (c->len >= 0x38) {
        while (n < 64)
            buf[n++] = 0;
        func_L39_004DFD50(c, buf);
        n = 0;
    }
    func_0011D534(buf + n, 0, 0x38 - n);
    w = c->count[0];
    buf[0x38] = w;
    buf[0x39] = w >> 8;
    buf[0x3A] = w >> 16;
    buf[0x3B] = w >> 24;
    w = c->count[1];
    buf[0x3C] = w;
    buf[0x3D] = w >> 8;
    buf[0x3E] = w >> 16;
    buf[0x3F] = w >> 24;
    func_L39_004DFD50(c, buf);
    buf = out;
    w = c->state[0];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[1];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[2];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[3];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    c->len = 0;
}
/* localdecomp:end func_L39_004E00C8 */

/* localdecomp:start func_L39_004E0280 */
/* OpenSSL OBJ_NAME_init (o_names.c) */
extern void *D_L39_0046BDAC __attribute__((section(".data")));
extern void *func_L39_004BCA88(void *, void *);
extern unsigned long func_L39_004E0340();
extern s32 func_L39_004E02C8();

s32 func_L39_004E0280(void) {
    if (D_L39_0046BDAC != 0)
        return 1;
    D_L39_0046BDAC = func_L39_004BCA88(func_L39_004E0340, func_L39_004E02C8);
    return D_L39_0046BDAC != 0;
}
/* localdecomp:end func_L39_004E0280 */

/* localdecomp:start func_L39_004E02C8 */
/* OpenSSL obj_name_cmp (o_names.c) */
typedef struct {
    s32 type;
    s32 alias;
    const char *name;
    const char *data;
} ON_004E02C8;
typedef struct {
    s32 num;
    s32 (**data)(const char *, const char *);
} STK_004E02C8;
extern void *D_L39_0046BDB4 __attribute__((section(".data")));
extern s32 func_1205B0(const char *, const char *);

s32 func_L39_004E02C8(ON_004E02C8 *a, ON_004E02C8 *b) {
    s32 ret;

    ret = a->type - b->type;
    if (ret == 0) {
        if (D_L39_0046BDB4 != 0 && ((STK_004E02C8 *)D_L39_0046BDB4)->num > a->type) {
            ret = ((STK_004E02C8 *)D_L39_0046BDB4)->data[a->type](a->name, b->name);
        } else {
            ret = func_1205B0(a->name, b->name);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004E02C8 */

/* localdecomp:start func_L39_004E0340 */
/* OpenSSL obj_name_hash (o_names.c) */
typedef struct {
    s32 type;
    s32 alias;
    const char *name;
    const char *data;
} ON_004E0340;
typedef struct {
    s32 num;
    unsigned long (**data)(const char *);
} STK_004E0340;
extern void *D_L39_0046BDB8 __attribute__((section(".data")));
extern unsigned long func_L39_004BD280(const char *);

unsigned long func_L39_004E0340(ON_004E0340 *a) {
    unsigned long ret;

    if (D_L39_0046BDB8 != 0 && ((STK_004E0340 *)D_L39_0046BDB8)->num > a->type) {
        ret = ((STK_004E0340 *)D_L39_0046BDB8)->data[a->type](a->name);
    } else {
        ret = func_L39_004BD280(a->name);
    }
    ret ^= a->type;
    return ret;
}
/* localdecomp:end func_L39_004E0340 */

/* localdecomp:start func_L39_004E03B8 */
/* OpenSSL OBJ_NAME_get */
typedef struct {
    s32 type;
    s32 alias;
    const char *name;
    const char *data;
} OBJ_NAME_004E03B8;
extern void *D_L39_0046BDAC __attribute__((section(".data")));
extern s32 func_L39_004E0280(void);
extern OBJ_NAME_004E03B8 *func_L39_004BCDE0(void *, OBJ_NAME_004E03B8 *);

const char *func_L39_004E03B8(const char *name, s32 type) {
    OBJ_NAME_004E03B8 on, *ret;
    s32 num = 0;
    s32 alias;

    if (name == 0) {
        return 0;
    }
    if (D_L39_0046BDAC == 0 && !func_L39_004E0280()) {
        return 0;
    }
    alias = type & 0x8000;
    type &= ~0x8000;
    on.name = name;
    on.type = type;
    for (;;) {
        ret = func_L39_004BCDE0(D_L39_0046BDAC, &on);
        if (ret == 0) {
            return 0;
        }
        if (ret->alias && !alias) {
            if (++num > 10) {
                return 0;
            }
            on.name = ret->data;
        } else {
            return ret->data;
        }
    }
}
/* localdecomp:end func_L39_004E03B8 */

/* localdecomp:start func_L39_004E0490 */
/* OpenSSL OBJ_NAME_add */
typedef struct {
    s32 num;
    void (**data)(const char *, s32, const char *);
} STK_004E0490;
typedef struct {
    char _p0[0xA0];
    s32 error;
} LH_004E0490;
extern void *D_L39_0046BDBC __attribute__((section(".data")));
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BCC38(void *, void *);

s32 func_L39_004E0490(void *name, s32 type, void *data) {
    OBJ_NAME_004E03B8 *onp, *ret;
    s32 alias;

    if (D_L39_0046BDAC == 0 && !func_L39_004E0280()) {
        return 0;
    }
    alias = type & 0x8000;
    type &= ~0x8000;
    onp = func_L39_004BEED8(sizeof(OBJ_NAME_004E03B8));
    if (onp == 0) {
        return 0;
    }
    onp->type = type;
    onp->name = name;
    onp->alias = alias;
    onp->data = data;
    ret = func_L39_004BCC38(D_L39_0046BDAC, onp);
    if (ret != 0) {
        if (D_L39_0046BDBC != 0 && ((STK_004E0490 *)D_L39_0046BDBC)->num > ret->type) {
            ((STK_004E0490 *)D_L39_0046BDBC)->data[ret->type](ret->name, ret->type, ret->data);
        }
        func_L39_004BEF28(ret);
    } else {
        if (((LH_004E0490 *)D_L39_0046BDAC)->error) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004E0490 */

/* localdecomp:start func_L39_004E05B0 */
/* OpenSSL OBJ_NAME_remove (o_names.c) */
typedef struct {
    s32 type;
    s32 alias;
    const char *name;
    const char *data;
} ON_004E05B0;
typedef struct {
    s32 num;
    void (**data)(const char *, s32, const char *);
} STK_004E05B0;
extern void *D_L39_0046BDAC __attribute__((section(".data")));
extern void *D_L39_0046BDBC __attribute__((section(".data")));
extern ON_004E05B0 *func_L39_004BCD28(void *, void *);
extern void func_L39_004BEF28(void *);

s32 func_L39_004E05B0(const char *name, s32 type) {
    ON_004E05B0 on, *ret;

    if (D_L39_0046BDAC == 0) {
        return 0;
    }
    type &= ~0x8000;
    on.name = name;
    on.type = type;
    ret = func_L39_004BCD28(D_L39_0046BDAC, &on);
    if (ret != 0) {
        if (D_L39_0046BDBC != 0 && ((STK_004E05B0 *)D_L39_0046BDBC)->num > type) {
            ((STK_004E05B0 *)D_L39_0046BDBC)->data[type](ret->name, ret->type, ret->data);
        }
        func_L39_004BEF28(ret);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004E05B0 */

INCLUDE_ASM("asm/levels", func_L39_004E0668);

/* localdecomp:start func_L39_004E0698 */
/* OpenSSL OBJ_NAME_cleanup */
typedef struct {
    char _p0[0x28];
    u64 down_load;
} LH_004E0698;
extern s32 D_L39_00453B3C __attribute__((section(".data")));
extern void *D_L39_0046BDB4 __attribute__((section(".data")));
extern void *D_L39_0046BDB8 __attribute__((section(".data")));
extern void *D_L39_0046BDBC __attribute__((section(".data")));
extern void func_L39_004E0668(void *);
extern void func_L39_004BCE38(void *, void (*)(void *, void *));
extern void func_L39_004BCBB0(void *);
extern void func_L39_004CC538(void *);

void func_L39_004E0698(s32 type) {
    u64 down_load;

    if (D_L39_0046BDAC == 0) {
        return;
    }
    D_L39_00453B3C = type;
    down_load = ((LH_004E0698 *)D_L39_0046BDAC)->down_load;
    ((LH_004E0698 *)D_L39_0046BDAC)->down_load = 0;
    func_L39_004BCE38(D_L39_0046BDAC, (void (*)(void *, void *))func_L39_004E0668);
    if (type < 0) {
        func_L39_004BCBB0(D_L39_0046BDAC);
        func_L39_004CC538(D_L39_0046BDB8);
        func_L39_004CC538(D_L39_0046BDB4);
        func_L39_004CC538(D_L39_0046BDBC);
        D_L39_0046BDAC = 0;
        D_L39_0046BDB8 = 0;
        D_L39_0046BDB4 = 0;
        D_L39_0046BDBC = 0;
    } else {
        ((LH_004E0698 *)D_L39_0046BDAC)->down_load = down_load;
    }
}
/* localdecomp:end func_L39_004E0698 */

/* localdecomp:start func_L39_004E0748 */
/* OpenSSL add_hash (obj_dat.c) */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0748;

typedef struct {
    s32 type;
    O_004E0748 *obj;
} A_004E0748;

extern unsigned long func_L39_004BD280(const char *);

unsigned long func_L39_004E0748(void *pa) {
    A_004E0748 *ca = pa;
    O_004E0748 *a;
    s32 i;
    unsigned long ret = 0;
    u8 *p;

    a = ca->obj;
    switch (ca->type) {
    case 0:
        ret = a->length << 20;
        p = a->data;
        for (i = 0; i < a->length; i++)
            ret ^= p[i] << ((i * 3) % 24);
        break;
    case 1:
        ret = func_L39_004BD280(a->sn);
        break;
    case 2:
        ret = func_L39_004BD280(a->ln);
        break;
    case 3:
        ret = a->nid;
        break;
    }
    ret &= 0x3fffffff;
    ret |= ca->type << 30;
    return ret;
}
/* localdecomp:end func_L39_004E0748 */

/* localdecomp:start func_L39_004E0840 */
/* OpenSSL add_cmp (obj_dat.c) */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0840;

typedef struct {
    s32 type;
    O_004E0840 *obj;
} A_004E0840;

extern s32 func_11D2EC(void *, void *, s32);
extern s32 func_1205B0(const char *, const char *);

s32 func_L39_004E0840(void *pa, void *pb) {
    A_004E0840 *ca = pa;
    A_004E0840 *cb = pb;
    O_004E0840 *a, *b;
    s32 i;

    i = ca->type - cb->type;
    if (i)
        return i;
    a = ca->obj;
    b = cb->obj;
    switch (ca->type) {
    case 0:
        i = a->length - b->length;
        if (i)
            return i;
        return func_11D2EC(a->data, b->data, a->length);
    case 1:
        if (a->sn == 0)
            return -1;
        else if (b->sn == 0)
            return 1;
        else
            return func_1205B0(a->sn, b->sn);
    case 2:
        if (a->ln == 0)
            return -1;
        else if (b->ln == 0)
            return 1;
        else
            return func_1205B0(a->ln, b->ln);
    case 3:
        return a->nid - b->nid;
    }
    return 1;
}
/* localdecomp:end func_L39_004E0840 */

/* localdecomp:start func_L39_004E0920 */
/* OpenSSL init_added (obj_dat.c) */
extern void *D_L39_0046D288 __attribute__((section(".data")));
extern void *func_L39_004BCA88(void *, void *);
extern unsigned long func_L39_004E0748(void *);
extern s32 func_L39_004E0840(void *, void *);

s32 func_L39_004E0920(void) {
    if (D_L39_0046D288 != 0) {
        return 1;
    }
    D_L39_0046D288 = func_L39_004BCA88(func_L39_004E0748, func_L39_004E0840);
    return D_L39_0046D288 != 0;
}
/* localdecomp:end func_L39_004E0920 */

/* localdecomp:start func_L39_004E0968 */
typedef struct {
    u8 pad0[0x8];
    s32 f8;
    u8 padC[0x8];
    s32 f14;
} S_004E0968_inner;

typedef struct {
    s32 f0;
    S_004E0968_inner *f4;
} S_004E0968;

void func_L39_004E0968(S_004E0968 *arg0) {
    arg0->f4->f8 = 0;
    arg0->f4->f14 |= 0xD;
}
/* localdecomp:end func_L39_004E0968 */

/* localdecomp:start func_L39_004E0988 */
typedef struct S2_004E0988 { u8 pad[8]; s32 count; } S2_004E0988;
typedef struct S_004E0988 { s32 f0; S2_004E0988 *p; } S_004E0988;
void func_L39_004E0988(S_004E0988 *a) {
    a->p->count++;
}
/* localdecomp:end func_L39_004E0988 */

INCLUDE_ASM("asm/levels", func_L39_004E09A0);

/* localdecomp:start func_L39_004E09E0 */
typedef struct {
    char _p0[0x28];
    u64 down_load;
} LH_004E09E0;
extern void *D_L39_0046D288 __attribute__((section(".data")));
extern void func_L39_004BCE38(void *, void (*)(void *, void *));
extern void func_L39_004BCBB0(void *);
extern void func_L39_004E0968(S_004E0968 *);
extern void func_L39_004E0988(S_004E0988 *);
extern void func_L39_004E09A0(void *);

void func_L39_004E09E0(void) {
    if (D_L39_0046D288 == 0) {
        return;
    }
    ((LH_004E09E0 *)D_L39_0046D288)->down_load = 0;
    func_L39_004BCE38(D_L39_0046D288, (void (*)(void *, void *))func_L39_004E0968);
    func_L39_004BCE38(D_L39_0046D288, (void (*)(void *, void *))func_L39_004E0988);
    func_L39_004BCE38(D_L39_0046D288, (void (*)(void *, void *))func_L39_004E09A0);
    func_L39_004BCBB0(D_L39_0046D288);
    D_L39_0046D288 = 0;
}
/* localdecomp:end func_L39_004E09E0 */

LINKER_REMNANT("asm/levels", func_L39_004E0A48);

/* localdecomp:start func_L39_004E0A58 */
typedef struct S_004E0A58_E {
    u8 pad0[8];
    s32 f8;
    u8 pad1[0xC];
} S_004E0A58_E;

typedef struct S_004E0A58_Q {
    s32 f0;
    void *f4;
    u8 pad8[8];
    u8 f10[8];
    u32 f18;
    u8 pad1C[0x14];
} S_004E0A58_Q;

typedef struct S_004E0A58_R {
    s32 f0;
    void *f4;
} S_004E0A58_R;

extern S_004E0A58_E D_L39_0046C040_004E0A58[];
extern s32 D_L39_0046D288_004E0A58[];
extern S_004E0A58_R *func_L39_004BCDE0_004E0A58(s32, void *);
extern void func_L39_004BC6C8_004E0A58(s32, s32, s32, s32, s32);

void *func_L39_004E0A58(u32 arg0) {
    S_004E0A58_Q q;
    S_004E0A58_R *r;

    if (arg0 < 0x8C) {
        if (arg0 != 0 && D_L39_0046C040_004E0A58[arg0].f8 == 0) {
            func_L39_004BC6C8_004E0A58(8, 0x67, 0x65, 0, 0);
            return 0;
        }
        return &D_L39_0046C040_004E0A58[arg0];
    }
    if (D_L39_0046D288_004E0A58[0] == 0) {
        return 0;
    }
    q.f0 = 3;
    q.f4 = q.f10;
    q.f18 = arg0;
    r = func_L39_004BCDE0_004E0A58(D_L39_0046D288_004E0A58[0], &q);
    if (r != 0) {
        return r->f4;
    }
    func_L39_004BC6C8_004E0A58(8, 0x67, 0x65, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004E0A58 */

/* localdecomp:start func_L39_004E0B10 */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0B10;

typedef struct {
    s32 type;
    O_004E0B10 *obj;
} A_004E0B10;

extern O_004E0B10 D_L39_0046C040[];
extern void *D_L39_0046D288 __attribute__((section(".data")));
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

const char *func_L39_004E0B10(int n) {
    A_004E0B10 ad;
    O_004E0B10 ob;
    A_004E0B10 *adp;

    if (n >= 0 && n < 140) {
        if (n != 0 && D_L39_0046C040[n].nid == 0) {
            func_L39_004BC6C8(8, 0x68, 0x65, 0, 0);
            return 0;
        }
        return D_L39_0046C040[n].sn;
    }
    if (D_L39_0046D288 == 0)
        return 0;
    ad.type = 3;
    ad.obj = &ob;
    ob.nid = n;
    adp = ((A_004E0B10 *(*)(void *, A_004E0B10 *))func_L39_004BCDE0)(D_L39_0046D288, &ad);
    if (adp != 0)
        return adp->obj->sn;
    func_L39_004BC6C8(8, 0x68, 0x65, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004E0B10 */

/* localdecomp:start func_L39_004E0BC8 */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0BC8;

typedef struct {
    s32 type;
    O_004E0BC8 *obj;
} A_004E0BC8;

extern O_004E0BC8 D_L39_0046C040_004E0BC8[];
extern void *D_L39_0046D288 __attribute__((section(".data")));
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

const char *func_L39_004E0BC8(int n) {
    A_004E0BC8 ad;
    O_004E0BC8 ob;
    A_004E0BC8 *adp;

    if (n >= 0 && n < 140) {
        if (n != 0 && D_L39_0046C040_004E0BC8[n].nid == 0) {
            func_L39_004BC6C8(8, 0x66, 0x65, 0, 0);
            return 0;
        }
        return D_L39_0046C040_004E0BC8[n].ln;
    }
    if (D_L39_0046D288 == 0)
        return 0;
    ad.type = 3;
    ad.obj = &ob;
    ob.nid = n;
    adp = ((A_004E0BC8 *(*)(void *, A_004E0BC8 *))func_L39_004BCDE0)(D_L39_0046D288, &ad);
    if (adp != 0)
        return adp->obj->ln;
    func_L39_004BC6C8(8, 0x66, 0x65, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004E0BC8 */

/* localdecomp:start func_L39_004E0C88 */
/* OpenSSL OBJ_obj2nid (obj_dat.c) */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0C88;

typedef struct {
    s32 type;
    O_004E0C88 *obj;
} A_004E0C88;

extern O_004E0C88 *D_L39_0046D0F0[];
extern s32 func_L39_004E0D20(void *, void *);
extern void *func_L39_004E0D60(void *, void *, s32, s32, s32 (*)(void *, void *));

s32 func_L39_004E0C88(O_004E0C88 *a) {
    O_004E0C88 **op;
    A_004E0C88 ad, *adp;

    if (a == 0)
        return 0;
    if (a->nid != 0)
        return a->nid;
    if (D_L39_0046D288 != 0) {
        ad.type = 0;
        ad.obj = a;
        adp = ((A_004E0C88 *(*)(void *, A_004E0C88 *))func_L39_004BCDE0)(D_L39_0046D288, &ad);
        if (adp != 0)
            return adp->obj->nid;
    }
    op = func_L39_004E0D60(&a, D_L39_0046D0F0, 0x65, 4, func_L39_004E0D20);
    if (op == 0)
        return 0;
    return (*op)->nid;
}
/* localdecomp:end func_L39_004E0C88 */

LINKER_REMNANT("asm/levels", func_L39_004E0D18);

/* localdecomp:start func_L39_004E0D20 */
/* OpenSSL obj_cmp (obj_dat.c) */
typedef struct {
    const char *sn;
    const char *ln;
    s32 nid;
    s32 length;
    u8 *data;
    s32 flags;
} O_004E0D20;
extern s32 func_11D2EC(void *, void *, s32);

s32 func_L39_004E0D20(void *ap, void *bp) {
    O_004E0D20 *a = *(O_004E0D20 **)ap;
    O_004E0D20 *b = *(O_004E0D20 **)bp;
    s32 j;

    j = a->length - b->length;
    if (j) {
        return j;
    }
    return func_11D2EC(a->data, b->data, a->length);
}
/* localdecomp:end func_L39_004E0D20 */

INCLUDE_ASM("asm/levels", func_L39_004E0D60);

LINKER_REMNANT("asm/levels", func_L39_004E0E38);

/* localdecomp:start func_L39_004E0E48 */
/* OpenSSL obj_dat.c's sn_cmp: qsort comparator of two ASN1_OBJECT pointers by short name */
extern s32 func_1205B0(const char *, const char *);

s32 func_L39_004E0E48(const void *a, const void *b) {
    O_004E0BC8 *const *ap = (O_004E0BC8 *const *)a;
    O_004E0BC8 *const *bp = (O_004E0BC8 *const *)b;

    return func_1205B0((*ap)->sn, (*bp)->sn);
}
/* localdecomp:end func_L39_004E0E48 */

/* localdecomp:start func_L39_004E0E70 */
/* OpenSSL obj_dat.c's ln_cmp: qsort comparator of two ASN1_OBJECT pointers by long name */
extern s32 func_1205B0(const char *, const char *);

s32 func_L39_004E0E70(const void *a, const void *b) {
    O_004E0BC8 *const *ap = (O_004E0BC8 *const *)a;
    O_004E0BC8 *const *bp = (O_004E0BC8 *const *)b;

    return func_1205B0((*ap)->ln, (*bp)->ln);
}
/* localdecomp:end func_L39_004E0E70 */

/* localdecomp:start func_L39_004E0E98 */
typedef struct S_004E0E98 {
    char _p0[0xC];
    s32 len;
    void *data;
} S_004E0E98;
extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_004E0E98(S_004E0E98 *a, S_004E0E98 *b) {
    s32 d = a->len - b->len;
    if (d != 0) {
        return d;
    }
    return func_0011D2EC(a->data, b->data, a->len);
}
/* localdecomp:end func_L39_004E0E98 */
