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

INCLUDE_ASM("asm/levels", func_L39_004DF408);

INCLUDE_ASM("asm/levels", func_L39_004DF410);

INCLUDE_ASM("asm/levels", func_L39_004DF668);

INCLUDE_ASM("asm/levels", func_L39_004DF678);

INCLUDE_ASM("asm/levels", func_L39_004DF688);

INCLUDE_ASM("asm/levels", func_L39_004DF698);

INCLUDE_ASM("asm/levels", func_L39_004DF6A8);

INCLUDE_ASM("asm/levels", func_L39_004DF6B8);

INCLUDE_ASM("asm/levels", func_L39_004DF820);

INCLUDE_ASM("asm/levels", func_L39_004DFB38);

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

INCLUDE_ASM("asm/levels", func_L39_004E0280);

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

INCLUDE_ASM("asm/levels", func_L39_004E0490);

INCLUDE_ASM("asm/levels", func_L39_004E0698);

INCLUDE_ASM("asm/levels", func_L39_004E09E0);

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

INCLUDE_ASM("asm/levels", func_L39_004E0C88);

INCLUDE_ASM("asm/levels", func_L39_004E0D60);

INCLUDE_ASM("asm/levels", func_L39_004E0E98);
